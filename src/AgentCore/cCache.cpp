#include "cCache.h"

#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>


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

