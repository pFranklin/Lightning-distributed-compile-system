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
    std::advance(itor, index);
    m_AllSrcInfo.insert(itor, sourceFile);
}

//----------------------------------------------------------------------------

void cProject::RemoveSourceFile(unsigned int index) {
    std::list<sSrcInfo>::iterator itor = m_AllSrcInfo.begin();
    std::advance(itor, index);

    if (itor != m_AllSrcInfo.end()) {
        m_AllSrcInfo.erase(itor);
    }
}