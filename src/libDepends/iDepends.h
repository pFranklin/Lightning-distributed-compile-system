/*============================================================================
  Lightning - Cross Platform Distributed Building System
  Copyright 2010-2011 Paul Franklin

  Distributed under the GNU General Public License v2.0 License or later;
  see accompanying file license for details.

  This software is distributed WITHOUT ANY WARRANTY; without even the
  implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the License for more information.
============================================================================*/


#ifndef iDepends_h
#define iDepends_h

#include <stdint.h>

/* iDepends
 * Dependency scanner superclass.
 *
 * This class is responsible for maintaining a .depends.make file in
 * the build tree corresponding to an object file.  Subclasses help it
 * maintain dependencies for particular languages.
 * All the Path string must be UTF-8 code covert.
 */

/** Write out the depends information.  */
struct sDependsInfo {
    /** File abs path.  */
    const char *FileAbsPath;

    /** File relative path which will be contained in
     *  zip file stream, can include './' or '../' .  */
    const char *FileRelativePath;

    /** File data for preprocessed file stream.  */
    const char *FileData;

    /** File data size.  */
    uint32_t FileSize;

    sDependsInfo()
    : FileAbsPath(0)
    , FileRelativePath(0)
    , FileData(0)
    , FileSize(0) {
    }
};

class iDepends {
public:

    /** Instances need to know the build directory name and the relative
            path from the build directory to the target file.  */
    iDepends() {
    };

    /** Virtual destructor to cleanup subclasses properly.  */
    virtual ~iDepends() {
    };

    /** Release the pointer.  */
    virtual void Release() = 0;

    /** Reset the class to default state.  */
    virtual void Reset() = 0;

    /** Clear dependencies for the target file so they can be regenerated.  */
    virtual void Clear() = 0;

    /** Set the project file abs path for calculating relative search directory.  */
    virtual int SetProjectFileAbsPath(const char *projectPath) = 0;

    /** Add macro.	*/
    virtual int AddMacro(const char *macro) = 0;

    /** Add a stand search directory.	*/
    virtual int AddStandSearchPath(const char *searchPath) = 0;

    /** Add a additional search directory.	*/
    virtual int AddExtraSearchPath(const char *searchPath) = 0;

    /** Check dependencies for the target file.  Returns true if
            dependencies are okay and false if they must be generated.  If
            they must be generated Clear has already been called to wipe out
            the old dependencies.
            Dependencies which are still valid will be stored in validDeps. */
    virtual bool CheckDependencies(const char *sourceFile) = 0;

    /** Write dependencies for the target file.  */
    virtual bool WriteDependencies(sDependsInfo **dependsInfo, uint32_t &infoNum) = 0;

private:
    iDepends(iDepends const&); // Purposely not implemented.
    void operator=(iDepends const&); // Purposely not implemented.
};

// Depends creator interface
typedef iDepends* (*DependsCreator)(const char*);
// Depends creator function name
#define DEPENDS_CREATOR_NAME "CreateDenpends"


#endif
