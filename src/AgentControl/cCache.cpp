/*============================================================================
  Lightning - Cross Platform Distributed Building System
  Copyright 2010-2011 Paul Franklin

  Distributed under the GNU General Public License v2.0 License or later;
  see accompanying file license for details.

  This software is distributed WITHOUT ANY WARRANTY; without even the
  implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the License for more information.
============================================================================*/


#define BOOST_FILESYSTEM_VERSION 3

#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/filesystem.hpp>
#include <boost/crc.hpp>
#include <glog/logging.h>

#include "common/BFS_UTF8_CODE.h"
#include "cCache.h"


//----------------------------------------------------------------------------

cCache::cCache()
: m_SrcLastWriteTime(0)
, m_OptionsCrc(-1) {
}

//----------------------------------------------------------------------------

cCache::~cCache() {
}

//----------------------------------------------------------------------------

void cCache::Reset() {
    m_SourceFileName.clear();
    m_SrcLastWriteTime = 0;
    m_DependsInfo.clear();
    m_OptionsCrc = -1;
}

//----------------------------------------------------------------------------

bool cCache::CheckFile() {
    bool bOK = false;

    try {
        // check source file
        boost::filesystem3::path pSource(BFS_UTF8_STRING(m_SourceFileName));
        std::time_t now_t = boost::filesystem3::last_write_time(pSource);
        if (now_t != m_SrcLastWriteTime) throw true;

        // check the dependency file
        std::map<std::string, std::time_t>::iterator itor = m_DependsInfo.begin();
        for (; itor != m_DependsInfo.end(); ++itor) {
            boost::filesystem3::path pDepends(BFS_UTF8_STRING(itor->first));
            std::time_t now_t = boost::filesystem3::last_write_time(pDepends);
            if (now_t != itor->second) throw true;
        }

    } catch (bool b) {
        bOK = b;
    } catch (boost::filesystem3::filesystem_error &error) {
        LOG(INFO) << error.what();
        bOK = true;
    }

    return bOK;
}

//----------------------------------------------------------------------------

bool cCache::CheckOption(std::string &option) {
    boost::crc_32_type result;
    result.process_bytes(option.data(), option.size());
    return m_OptionsCrc == result.checksum();
}
