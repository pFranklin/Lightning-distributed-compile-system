/*============================================================================
  Lightning - Cross Platform Distributed Building System
  Copyright 2010-2011 Paul Franklin

  Distributed under the GNU General Public License v2.0 License or later;
  see accompanying file license for details.

  This software is distributed WITHOUT ANY WARRANTY; without even the
  implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the License for more information.
============================================================================*/


#ifndef cDepends_C_Fast_h
#define cDepends_C_Fast_h

#include <set>
#include <boost/regex/icu.hpp>
#include <boost/thread.hpp>
#include "cDepends.h"


/* cDepends_C_Fast
 * Dependency scanner for c and c++ language regex version
 * by using boost regex.
 * 
 * This class cannot handle header file containing MACRO like this
 * 
 * #define HEADER_FILE "header.h"
 * #include HEADER_FILE
 *
 * This is a simple resolution for searching dependency, it's just
 * suitable for some light c-like language such as nvidia cg or glsl
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

class cDepends_C_Regex : public cDepends {
public:
    /** Instances need to know the build directory name and the relative
            path from the build directory to the target file.  */
    cDepends_C_Regex();

    /** Virtual destructor to cleanup subclasses properly.  */
    virtual ~cDepends_C_Regex();

    /** Check dependencies for the target file.  Returns true if
            dependencies are okay and false if they must be generated.  If
            they must be generated Clear has already been called to wipe out
            the old dependencies.
            Dependencies which are still valid will be stored in validDeps. */
    virtual bool CheckDependencies(const char *sourceFile);

protected:
    /** Check the root file depends.  */
    void CheckRootDepends(const char *sourceFile, std::vector<std::string> *leafs,
            std::set<std::string> *allLeafs);

    /** Search the depends file from the SearchPath.
     *  FileName and SearchPath must be UTF-8 encode, do not convert is.*/
    bool SearchDependsFile(const char *FileName, std::vector<std::string> &SearchPath,
            bool sysSearch, std::string &outFullName);

private:
    cDepends_C_Regex(cDepends_C_Regex const&); // Purposely not implemented.
    void operator=(cDepends_C_Regex const&); // Purposely not implemented.

protected:
    /** Check the include file regex.  */
    const boost::u32regex m_regex;

private:
    /** File leafs read write mutex.  */
    boost::mutex m_LeafsMutex;

    /** Add depends file mutex.  */
    boost::mutex m_AddDependsMutex;
};

#endif