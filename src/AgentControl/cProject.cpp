/*============================================================================
  Lightning - Cross Platform Distributed Building System
  Copyright 2010-2011 Paul Franklin

  Distributed under the GNU General Public License v2.0 License or later;
  see accompanying file license for details.

  This software is distributed WITHOUT ANY WARRANTY; without even the
  implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the License for more information.
============================================================================*/


#include <fstream>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>

#include "cProject.h"


#define SHOWTAB "    "

//----------------------------------------------------------------------------

bool sSrcInfo::CheckMember() {
    if (m_SrcFileName.empty()) {
        throw cException("unknown input source file");
    }
    if (m_OutFileName.empty()) {
        throw cException("unknown output obj file");
    }
    if (m_DependsCheckName.empty()) {
        throw cException("unknown dependency check module");
    }
    if (m_Compiler.empty()) {
        throw cException("unknown compiler");
    }
    if (m_CompilerCommand.empty()) {
        throw cException("unknown compiler command generator");
    }
    return true;
}

//----------------------------------------------------------------------------

void sSrcInfo::ViewInfo() {
    std::cout << std::endl;

    // view source file
    ViewVecStr("source files:", m_SrcFileName);
    // view output file
    ViewVecStr("output files:", m_OutFileName);

    // view entry name
    std::cout << "entry name:" << std::endl << SHOWTAB << m_EntryName << std::endl;
    // view options
    std::cout << "compile options:" << std::endl << SHOWTAB << m_Options << std::endl;
    // view dependency check name
    std::cout << "dependency checker:" << std::endl << SHOWTAB << m_DependsCheckName << std::endl;
    // view compiler
    std::cout << "compiler name:" << std::endl << SHOWTAB << m_Compiler << std::endl;
    // view compiler command generator
    std::cout << "compiler command generator:" << std::endl << SHOWTAB << m_CompilerCommand << std::endl;

    // view macro
    ViewVecStr("macros:", m_Macro);
    // view include
    ViewVecStr("includes:", m_Include);

    std::cout << std::endl;
}

//----------------------------------------------------------------------------

void sSrcInfo::ViewVecStr(const char *desc, std::vector<std::string> &vecStr) {
    std::vector<std::string>::iterator itor = vecStr.begin();

    // view string
    std::cout << desc << std::endl;
    for (; itor != vecStr.end(); ++itor) {
        std::cout << SHOWTAB << *itor << std::endl;
    }
}

//----------------------------------------------------------------------------

cProject::cProject() {
}

//----------------------------------------------------------------------------

cProject::~cProject() {
}

//----------------------------------------------------------------------------

void cProject::Reset() {
    m_AllSrcInfo.clear();
}

//----------------------------------------------------------------------------

void cProject::AddSourceFile(sSrcInfo &sourceFile) {
    m_AllSrcInfo.push_back(sourceFile);
}

//----------------------------------------------------------------------------

void cProject::SetSourceFile(unsigned int index, sSrcInfo &sourceFile) {
    std::list<sSrcInfo>::iterator itor = m_AllSrcInfo.begin();

    if (index < m_AllSrcInfo.size()) {
        std::advance(itor, index);
        *itor = sourceFile;
    }
}

//----------------------------------------------------------------------------

void cProject::RemoveSourceFile(unsigned int index) {
    std::list<sSrcInfo>::iterator itor = m_AllSrcInfo.begin();

    if (index < m_AllSrcInfo.size()) {
        std::advance(itor, index);
        if (itor != m_AllSrcInfo.end()) {
            m_AllSrcInfo.erase(itor);
        }
    }
}

//----------------------------------------------------------------------------

void cProject::ViewInfo() {
    std::list<sSrcInfo>::iterator itor = m_AllSrcInfo.begin();
    unsigned int index = 0;

    std::cout << std::endl;
    for (; itor != m_AllSrcInfo.end(); ++itor, ++index) {
        std::cout << "index num:  " << index << std::endl;
        itor->ViewInfo();
    }
}