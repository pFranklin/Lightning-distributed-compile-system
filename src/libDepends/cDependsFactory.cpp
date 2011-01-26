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

