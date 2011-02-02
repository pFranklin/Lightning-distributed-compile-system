/*============================================================================
  Lightning - Cross Platform Distributed Building System
  Copyright 2010-2011 Paul Franklin

  Distributed under the GNU General Public License v2.0 License or later;
  see accompanying file license for details.

  This software is distributed WITHOUT ANY WARRANTY; without even the
  implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the License for more information.
============================================================================*/


#include <boost/functional/factory.hpp>
#include "cDepends_C_Regex.h"
#include "cDepends_C.h"
#include "cDependsFactory.h"


//----------------------------------------------------------------------------

cDependsFactory::cDependsFactory() {
    InitProducts();
}

//----------------------------------------------------------------------------

cDependsFactory::~cDependsFactory() {

}

//----------------------------------------------------------------------------

iDepends *cDependsFactory::CreateDependsProduct(std::string productName) {
    iDepends *ret = 0;
    if (m_factories.find(productName) != m_factories.end()) {
        ret = m_factories[productName]();
    }
    return ret;
}

//----------------------------------------------------------------------------

void cDependsFactory::InitProducts() {
    m_factories["Depends_C_Regex"] = boost::factory<cDepends_C_Regex*>();
    m_factories["Depends_C"] = boost::factory<cDepends_C*>();
}

//----------------------------------------------------------------------------
// export creator

extern "C" __attribute__((dllexport)) iDepends *CreateDenpends(const char* name) {
    cDependsFactory factory;

    return factory.CreateDependsProduct(name);
}

