/*============================================================================
  Lightning - Cross Platform Distributed Building System
  Copyright 2010-2011 Paul Franklin

  Distributed under the GNU General Public License v2.0 License or later;
  see accompanying file license for details.

  This software is distributed WITHOUT ANY WARRANTY; without even the
  implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the License for more information.
============================================================================*/


#include "cCommand.h"

//----------------------------------------------------------------------------

cCommand::cCommand() {
}

//----------------------------------------------------------------------------

cCommand::~cCommand() {
}

//----------------------------------------------------------------------------

void cCommand::Release() {
    delete this;
}

//----------------------------------------------------------------------------

void cCommand::Reset() {
    m_Macro.clear();
    m_ExtraSearchPath.clear();
    m_SourceFile.clear();
    m_EntryName.clear();
    m_OutputFile.clear();
    m_Options.clear();
    Clear();
}

//----------------------------------------------------------------------------

void cCommand::Clear() {
    m_CommandLine.clear();
}

//----------------------------------------------------------------------------

int cCommand::AddMacro(const char *macro) {
    m_Macro.push_back(macro);
    return 1;
}

//----------------------------------------------------------------------------

int cCommand::AddExtraSearchPath(const char *searchPath) {
    m_ExtraSearchPath.push_back(searchPath);
    return 1;
}

//----------------------------------------------------------------------------

int cCommand::SetSourceFile(const char *SourceName) {
    m_SourceFile = SourceName;
    return 1;
}

//----------------------------------------------------------------------------

int cCommand::SetEntry(const char *EntryName) {
    m_EntryName = EntryName;
    return 1;
}

//----------------------------------------------------------------------------

int cCommand::SetOutputFile(const char *OutputName) {
    m_OutputFile = OutputName;
    return 1;
}

//----------------------------------------------------------------------------

int cCommand::SetOptions(const char *Options) {
    m_Options = Options;
    return 1;
}

