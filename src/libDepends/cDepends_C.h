#ifndef cDepends_C_h
#define cDepends_C_h

#include "cDepends.h"

/* cDepends_C
 * Dependency scanner for c and c++ language stand version
 * by using boost wave.
 */

/* C/C++ include search order copy from ibm ILE C/C++ Programmer's Guide - Contents
 *
 * ---------------------------------------------------------------------------------------
 * #include type              |    Directory Search Order                                |
 * ---------------------------+----------------------------------------------------------|
 * #include <file_name>       | 1. If you specify a directory in the                     |
 *                            |    INCDIR parameter, the compiler searches               |
 *                            |    for file_name in that directory first.                |
 *                            |                                                          |
 *                            | 2. If more than one directory is specified,              |
 *                            |    the compiler searches the directories in the          |
 *                            |    order that they appear on the command line.           |
 *                            |                                                          |
 *                            | 3. If the INCLUDE environment variable is defined,       |
 *                            |    the compiler searches the directories in the          |
 *                            |    order they appear in the INCLUDE path.                |
 *                            |                                                          |
 *                            | 4. Searches the directory /QIBM/include.                 |
 *                            |                                                          |
 * ---------------------------+-----------------------------------------------------------
 * #include "file_name"       | 1. Searches the directory where your current             |
 *                            |    source file resides. The current source               |
 *                            |    file is the file that contains the #include           |
 *                            |    "file_name" directive.                                |
 *                            |                                                          |
 *                            | 2. If you specify a directory in the INCDIR              |
 *                            |    parameter, the compiler searches for file_name        |
 *                            |    in that directory.                                    |
 *                            |                                                          |
 *                            | 3. If more than one directory is specified, the          |
 *                            |    compiler searches the directories in the order        |
 *                            |    that they appear on the command line.                 |
 *                            |                                                          |
 *                            | 4. If the INCLUDE environment variable is defined,       |
 *                            |    the compiler searches the directories in the          |
 *                            |    order they appear in the INCLUDE environment          |
 *                            |    variable.                                             |
 *                            |                                                          |
 *                            | 5. Searches the directory /QIBM/include.                 |
 *                            |                                                          |
 * ---------------------------------------------------------------------------------------
 * */

class cDepends_C : public cDepends {
public:
    /** Instances need to know the build directory name and the relative
            path from the build directory to the target file.  */
    cDepends_C();

    /** Virtual destructor to cleanup subclasses properly.  */
    virtual ~cDepends_C();

    /** Check dependencies for the target file.  Returns true if
            dependencies are okay and false if they must be generated.  If
            they must be generated Clear has already been called to wipe out
            the old dependencies.
            Dependencies which are still valid will be stored in validDeps. */
    virtual bool CheckDependencies(const char *sourceFile);

private:
    cDepends_C(cDepends_C const&); // Purposely not implemented.
    void operator=(cDepends_C const&); // Purposely not implemented.
};

#endif