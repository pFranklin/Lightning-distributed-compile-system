/*============================================================================
  Lightning - Cross Platform Distributed Building System
  Copyright 2010-2011 Paul Franklin

  Distributed under the GNU General Public License v2.0 License or later;
  see accompanying file license for details.

  This software is distributed WITHOUT ANY WARRANTY; without even the
  implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the License for more information.
============================================================================*/


#ifndef cCommand_h
#define cCommand_h

#include <string>
#include <vector>
#include "iCommand.h"

/* cCommand
 * Command generator baseclass.
 *
 * This class is responsible for supporting a base class
 * for generating compile command line.
 */

class cCommand : public iCommand {
public:

    /** Instances need to know the build directory name and the relative
            path from the build directory to the target file.  */
    cCommand();

    /** Virtual destructor to cleanup subclasses properly.  */
    virtual ~cCommand();

    /** Release the pointer.  */
    virtual void Release();

    /** Reset the class to default state.  */
    virtual void Reset();

    /** Clear the command line.  */
    virtual void Clear();

    /** Set the source file name.  */
    virtual int SetSourceFile(const char *SourceName);

    /** Set the entry name.  */
    virtual int SetEntry(const char *EntryName);

    /** Set the output file name.  */
    virtual int SetOutputFile(const char *OutputName);

    /** Set options of compiler.  */
    virtual int SetOptions(const char *Options);

    /** Add macro.	*/
    virtual int AddMacro(const char *macro);

    /** Add a additional search directory.	*/
    virtual int AddExtraSearchPath(const char *searchPath);

    /** Generate the command line.  */
    virtual bool GenerateCommandLine(const char **commandLine) = 0;

protected:
    // All macro.
    std::vector<std::string> m_Macro;

    // The include file search path.
    std::vector<std::string> m_ExtraSearchPath;

    // Source file path
    std::string m_SourceFile;

    // Entry name
    std::string m_EntryName;

    // Output file name
    std::string m_OutputFile;

    // Options
    std::string m_Options;

    // Output command line
    std::string m_CommandLine;

private:
    cCommand(iCommand const&); // Purposely not implemented.
    void operator=(cCommand const&); // Purposely not implemented.  
};

#endif
