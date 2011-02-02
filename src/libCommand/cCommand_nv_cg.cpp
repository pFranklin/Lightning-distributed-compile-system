/*============================================================================
  Lightning - Cross Platform Distributed Building System
  Copyright 2010-2011 Paul Franklin

  Distributed under the GNU General Public License v2.0 License or later;
  see accompanying file license for details.

  This software is distributed WITHOUT ANY WARRANTY; without even the
  implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the License for more information.
============================================================================*/


#include <boost/format.hpp>
#include "cCommand_nv_cg.h"


//----------------------------------------------------------------------------

cCommand_nv_cg::cCommand_nv_cg() {
}

//----------------------------------------------------------------------------

cCommand_nv_cg::~cCommand_nv_cg() {
}

//----------------------------------------------------------------------------

bool cCommand_nv_cg::GenerateCommandLine(const char **commandLine) {
    if (!commandLine) return false;
    m_CommandLine.clear();
    std::vector<std::string>::iterator itor;

    // format macro
    for (itor = m_Macro.begin(); itor != m_Macro.end(); ++itor) {
        m_CommandLine += boost::str(boost::format("-D%s ") % *itor);
    }
    // format include path
    for (itor = m_ExtraSearchPath.begin(); itor != m_ExtraSearchPath.end(); ++itor) {
        m_CommandLine += boost::str(boost::format("-I%s ") % *itor);
    }

    // format another commandline
    m_CommandLine += boost::str(boost::format("-entry %s -o %s %s %s")
            % m_EntryName % m_OutputFile % m_Options % m_SourceFile);

    *commandLine = m_CommandLine.c_str();

    return true;
}