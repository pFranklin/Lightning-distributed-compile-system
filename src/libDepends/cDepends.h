#ifndef cDepends_h
#define cDepends_h

#include <vector>
#include <string>
#include "iDepends.h"

/* enum_DependsFile_Type
 *
 * enum for include file type
 */
enum enum_DependsFile_Type {
    enum_SysIncludeFile,
    enum_IncludeFile,
    enum_PreprocessedFile,

    enum_DependsFile_Type_Num
};

/* sDependsFile
 * Depneds file struct
 *
 * FileAbsPath: depends file absolute path.
 * FileRelativePath: depends file path in source file.
 * FileData: file data for preprocessed file.
 * FileType: depends file type
 */
struct sDependsFile {
    std::string FileAbsPath;
    std::string FileRelativePath;
    std::string FileData;
    enum_DependsFile_Type FileType;

    sDependsFile()
    : FileType(enum_SysIncludeFile) {
    }

    void clear() {
        FileAbsPath.clear();
        FileRelativePath.clear();
        FileData.clear();
        FileType = enum_SysIncludeFile;
    }

    bool operator ==(const sDependsFile & ds) const;
};

/* cDepends
 * Dependency scanner baseclass.
 *
 * This class is responsible for supporting a base class
 * for generate dependency.
 */

class cDepends : public iDepends {
public:
    /** Instances need to know the build directory name and the relative
            path from the build directory to the target file.  */
    cDepends();

    /** Virtual destructor to cleanup subclasses properly.  */
    virtual ~cDepends();

    /** Release the pointer.  */
    virtual void Release();

    /** Reset the class to default state.  */
    virtual void Reset();

    /** Clear dependencies for the target file so they will be regenerated.  */
    virtual void Clear();

    /** Set the project file abs path for calculating relative search directory.  */
    virtual int SetProjectFileAbsPath(const char *projectPath);

    /** Add macro.	*/
    virtual int AddMacro(const char *macro);

    /** Add a stand search directory.	*/
    virtual int AddStandSearchPath(const char *searchPath);

    /** Add a additional search directory.	*/
    virtual int AddExtraSearchPath(const char *searchPath);

    /** Check dependencies for the target file.  Returns true if
            dependencies are okay and false if they must be generated.  If
            they must be generated Clear has already been called to wipe out
            the old dependencies.
            Dependencies which are still valid will be stored in validDeps. */
    virtual bool CheckDependencies(const char *sourceFile) = 0;

    /** Write dependencies for the target file.  */
    virtual bool WriteDependencies(sDependsInfo **dependsInfo, uint32_t &infoNum);

protected:
    /** Set File Path.  */
    int SetSourceFilePath(const char *FullSourceName);

protected:
    // All macro.
    std::vector<std::string> m_Macro;

    // The include file search path.
    std::vector<std::string> m_StandSearchPath;

    // The include file search path.
    std::vector<std::string> m_ExtraSearchPath;

    // Full path of the dependency include file.
    std::vector<sDependsFile> m_IncludeFile;

    // Full path of the source file
    std::string m_SourceFilePath;

    // Full path of the project file
    std::string m_ProjectFilePath;

    // Output depends info
    std::vector<sDependsInfo> m_DependsInfo;

private:
    cDepends(cDepends const&); // Purposely not implemented.
    void operator=(cDepends const&); // Purposely not implemented.
};

#endif
