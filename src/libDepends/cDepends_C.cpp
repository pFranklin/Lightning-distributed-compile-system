///////////////////////////////////////////////////////////////////////////////
//  Include Wave itself
#include <boost/wave.hpp>

///////////////////////////////////////////////////////////////////////////////
// Include the lexer stuff
#include <boost/wave/cpplexer/cpp_lex_token.hpp>    // token class
#include <boost/wave/cpplexer/cpp_lex_iterator.hpp> // lexer class

#include "cDepends_C.h"


///////////////////////////////////////////////////////////////////////////////
//  policy class

template <typename TokenT>
struct trace_include_files
: public boost::wave::context_policies::eat_whitespace<TokenT> {

    trace_include_files(std::vector<sDependsFile> &files_)
    : files(files_), include_depth(0) {
    }

    template <typename ContextT>
            void
            opened_include_file(ContextT const& ctx, std::string const& relname,
            std::string const& absfilename, bool is_system_include) {

        file.FileAbsPath = absfilename;
        if (is_system_include) file.FileType = enum_SysIncludeFile;
        else file.FileType = enum_IncludeFile;

        if (std::find(files.begin(), files.end(), file) == files.end()) {
            // insert it into the name table
            files.push_back(file);
        }

        file.clear();
        ++include_depth;
    }

    // new signature

    template <typename ContextT>
            bool
            found_include_directive(ContextT const& ctx, std::string const& filename,
            bool include_next) {
        file.FileRelativePath = filename;
        return false; // ok to include this file
    }

    template <typename ContextT>
            void returning_from_include_file(ContextT const& ctx) {
        --include_depth;
    }

    std::vector<sDependsFile> &files;
    sDependsFile file;
    std::size_t include_depth;
};

///////////////////////////////////////////////////////////////////////////
//
//  load_file_to_string
//
//      Loads a file into a string and returns the iterators pointing to 
//      the beginning and the end of the loaded string and add a '\n'.
//
///////////////////////////////////////////////////////////////////////////

struct load_file_to_string_ext {

    template <typename IterContextT>
    class inner {
    public:

        template <typename PositionT>
        static void init_iterators(IterContextT &iter_ctx,
                PositionT const &act_pos, boost::wave::language_support language) {
            typedef typename IterContextT::iterator_type iterator_type;

            // read in the file
            std::ifstream instream(iter_ctx.filename.c_str());
            if (!instream.is_open()) {
                BOOST_WAVE_THROW_CTX(iter_ctx.ctx, boost::wave::preprocess_exception,
                        bad_include_file, iter_ctx.filename.c_str(), act_pos);
                return;
            }
            instream.unsetf(std::ios::skipws);

            iter_ctx.instring.assign(
                    std::istreambuf_iterator<char>(instream.rdbuf()),
                    std::istreambuf_iterator<char>());
            iter_ctx.instring += '\n';

            iter_ctx.first = iterator_type(
                    iter_ctx.instring.begin(), iter_ctx.instring.end(),
                    PositionT(iter_ctx.filename), language);
            iter_ctx.last = iterator_type();
        }

    private:
        std::string instring;
    };
};


//----------------------------------------------------------------------------

cDepends_C::cDepends_C() {
}

//----------------------------------------------------------------------------

cDepends_C::~cDepends_C() {
}

//----------------------------------------------------------------------------

bool cDepends_C::CheckDependencies(const char *sourceFile) {
    // current file position is saved for exception handling
    boost::wave::util::file_position_type current_position;

    try {
        //  Open and read in the specified input file.
        std::ifstream instream(sourceFile);
        std::string instring;

        if (!instream.is_open()) {
            std::cerr << "Could not open input file: " << sourceFile << std::endl;
            return false;
        }

        instream.unsetf(std::ios::skipws);
        instring = std::string(std::istreambuf_iterator<char>(instream.rdbuf()),
                std::istreambuf_iterator<char>());
        instring += '\n';

        typedef boost::wave::cpplexer::lex_token<> token_type;
        typedef boost::wave::cpplexer::lex_iterator<token_type> lex_iterator_type;
        typedef boost::wave::context<std::string::iterator, lex_iterator_type,
                load_file_to_string_ext,
                trace_include_files<lex_iterator_type::token_type> >
                context_type;

        trace_include_files<lex_iterator_type::token_type> trace(m_IncludeFile);

        //  The preprocessing of the input stream is done on the fly behind the
        //  scenes during iteration over the context_type::iterator_type stream.
        context_type ctx(instring.begin(), instring.end(), sourceFile, trace);
        ctx.set_language(
                boost::wave::language_support(
                boost::wave::support_c99
                | boost::wave::support_option_convert_trigraphs
                | boost::wave::support_option_emit_line_directives
#if BOOST_WAVE_SUPPORT_PRAGMA_ONCE != 0
                | boost::wave::support_option_include_guard_detection
#endif
#if BOOST_WAVE_EMIT_PRAGMA_DIRECTIVES != 0
                | boost::wave::support_option_emit_pragma_directives
#endif
                | boost::wave::support_option_insert_whitespace
                | boost::wave::support_option_long_long
                ));

        std::vector<std::string>::const_iterator cit;
        //  Add sys include
        for (cit = m_StandSearchPath.begin(); cit != m_StandSearchPath.end(); ++cit) {
            ctx.add_sysinclude_path((*cit).c_str());
        }
        //  Add include
        for (cit = m_ExtraSearchPath.begin(); cit != m_ExtraSearchPath.end(); ++cit) {
            ctx.add_include_path((*cit).c_str());
        }

        // Add macro
        for (cit = m_Macro.begin(); cit != m_Macro.end(); ++cit) {
            ctx.add_macro_definition(*cit, true);
        }

        //  Get the preprocessor iterators and use them to generate
        //  the token sequence.
        context_type::iterator_type first = ctx.begin();
        context_type::iterator_type last = ctx.end();

        //  The input stream is preprocessed for you while iterating over the range
        //  [first, last)
        while (first != last) {
            current_position = (*first).get_position();
            ++first;
        }
        //]
    } catch (boost::wave::cpp_exception const& e) {
        // some preprocessing error
        std::cerr
                << e.file_name() << "(" << e.line_no() << "): "
                << e.description() << std::endl;
        return false;
    } catch (std::exception const& e) {
        // use last recognized token to retrieve the error position
        std::cerr
                << current_position.get_file()
                << "(" << current_position.get_line() << "): "
                << "exception caught: " << e.what()
                << std::endl;
        return false;
    } catch (...) {
        // use last recognized token to retrieve the error position
        std::cerr
                << current_position.get_file()
                << "(" << current_position.get_line() << "): "
                << "unexpected exception caught." << std::endl;
        return false;
    }

    return true;
}
