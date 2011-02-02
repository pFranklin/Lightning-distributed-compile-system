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
#include "cCommand_nv_cg.h"
#include "cCommandFactory.h"


//----------------------------------------------------------------------------

cCommandFactory::cCommandFactory() {
    InitProducts();
}

//----------------------------------------------------------------------------

cCommandFactory::~cCommandFactory() {

}

//----------------------------------------------------------------------------

iCommand *cCommandFactory::CreateCommandProduct(std::string productName) {
    iCommand *ret = 0;
    if (m_factories.find(productName) != m_factories.end()) {
        ret = m_factories[productName]();
    }
    return ret;
}

//----------------------------------------------------------------------------

void cCommandFactory::InitProducts() {
    m_factories["Command_nVIDIA_cg"] = boost::factory<cCommand_nv_cg*>();
}

//----------------------------------------------------------------------------
// export creator

extern "C" __attribute__((dllexport)) iCommand *CreateCommand(const char* name) {
    cCommandFactory factory;

    return factory.CreateCommandProduct(name);
}

