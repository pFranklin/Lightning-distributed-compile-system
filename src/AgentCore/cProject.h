#ifndef cProject_h
#define cProject_h

#include <string>
#include <vector>

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
    sSrcInfo()
    : m_AppendMacro(false)
    , m_AppendInclude(false) {
    }
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

protected:
    /** Global macro.  */
    std::vector<std::string> m_GlobalMacro;

    /** Global include.  */
    std::vector<std::string> m_GlobalInclude;

    /** All source files information.  */
    std::vector<sSrcInfo> m_AllSrcInfo;

private:
    cProject(cProject const&); // Purposely not implemented.
    void operator=(cProject const&); // Purposely not implemented.
};

#endif
