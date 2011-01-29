#ifndef cProject_h
#define cProject_h

#include <boost/serialization/string.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/serialization/list.hpp>

/* sSrcInfo
 * Building system one source file options.
 *
 * This struct is responsible for handling one
 * single src file information of the building system.
 */

struct sSrcInfo {
    /** Source file name. */
    std::string m_SrcFileName;

    /** All output file names. */
    std::vector<std::string> m_OutFileName;

    /** Source file entry function. */
    std::string m_EntryName;

    /** Another options. */
    std::string m_Options;

    /** Name of depends check module. */
    std::string m_DependsCheckName;

    /** Name of compiler. */
    std::string m_Compiler;

    /** Name of Compiler command generator module. */
    std::string m_CompilerCommand;

    /** Self macro. */
    std::vector<std::string> m_Macro;

    /** Append or replace macro. */
    bool m_AppendMacro;

    /** Self include path. */
    std::vector<std::string> m_Include;

    /** Append or replace include. */
    bool m_AppendInclude;

    /** Constructor of the struct. */
    sSrcInfo();

private:
    friend class boost::serialization::access;

    template<class Archive>
    void serialize(Archive & ar, const unsigned int version);
};

/* cProject
 * Building system project file class.
 *
 * This class is responsible for handling the project
 * information of the building system.
 */

class cProject {
public:

    /** Constructor of the class. */
    cProject();

    /** Virtual destructor to cleanup subclasses properly.  */
    virtual ~cProject();

    /** Reset all members. */
    void Reset();

    /** Input the project file. */
    void InputProject(const char *projectFile);

    /** Output the project file. */
    void OutputProject(const char *projectFile);

    /** Input the project by using iostream. */
    void InputProject(std::istream &is_);

    /** Output the project by using iostream. */
    void OutputProject(std::ostream &os_);

    /** Add global macro. */
    void AddGlobalMacro(std::string &macro);

    /** Add global global include. */
    void AddGlobalInclude(std::string &includePath);

    /** Add one source file. */
    void AddSourceFile(sSrcInfo &sourceFile);

    /** Set source file. */
    void SetSourceFile(unsigned int index, sSrcInfo &sourceFile);

protected:
    /** Global macro.  */
    std::vector<std::string> m_GlobalMacro;

    /** Global include.  */
    std::vector<std::string> m_GlobalInclude;

    /** All source files information.  */
    std::list<sSrcInfo> m_AllSrcInfo;

private:
    cProject(cProject const&); // Purposely not implemented.
    void operator=(cProject const&); // Purposely not implemented.

private:
    friend class boost::serialization::access;

    template<class Archive>
    void serialize(Archive & ar, const unsigned int version);
};

#endif
