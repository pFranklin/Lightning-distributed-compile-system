/*============================================================================
  Lightning - Cross Platform Distributed Building System
  Copyright 2010-2011 Paul Franklin

  Distributed under the GNU General Public License v2.0 License or later;
  see accompanying file license for details.

  This software is distributed WITHOUT ANY WARRANTY; without even the
  implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the License for more information.
============================================================================*/


#ifndef cCmdHandler_h
#define cCmdHandler_h

#include <stdint.h>
#include <map>
#include <string>
#include <boost/function.hpp>
#include <boost/program_options.hpp>

#include "cProject.h"

/* cCmdHander
 * Building system controller command-line handler.
 *
 * This class is responsible for handling the command
 * line options of AgentControl.
 */


class cCmdHandler {
public:
    /** Constructor of the class. */
    cCmdHandler();

    /** Virtual destructor to cleanup subclasses properly.  */
    virtual ~cCmdHandler();

    /** Init the command-line string.  */
    void InitCommandLine(int argc, char **argv);

protected:
    /** Register the command-line string.  */
    void RegisterCommandLine();

    /** Init the operator code.  */
    void InitOpcodeHandler();

private:
    /** Handle set source file operation.  */
    void OpcodeHandleSetSource();

    /** Handle remove source file operation.  */
    void OpcodeHandleRemoveSource();

    /** Handle view project struct.  */
    void OpcodeHandleViewProject();

    /** Handle the building task.  */
    void OpcodeHandleBuild();

    /** Handle the project file.  */
    void OpcodeHandleProject(bool bRemove);

protected:
    /** opcode map.  */
    std::map< std::string, boost::function<void(cCmdHandler*)> > m_Operator;

    /** options var map.  */
    boost::program_options::variables_map m_VarMap;

    /** options description.  */
    boost::program_options::options_description m_Cmdline_Options;

protected:
    /** program operation code.  */
    std::string m_Opcode;

    /** project file name.  */
    std::string m_ProjectFile;

    /** source file index,
     * m_SrcIndex=-1 means append src to the end of project.  */
    int32_t m_SrcIndex;

    /** one source file info.  */
    sSrcInfo m_SrcFileInfo;
};

#endif
