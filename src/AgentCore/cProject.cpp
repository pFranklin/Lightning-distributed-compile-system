#include <fstream>

#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>

#include "cProject.h"

//----------------------------------------------------------------------------

sSrcInfo::sSrcInfo()
: m_AppendMacro(false)
, m_AppendInclude(false) {
}

//----------------------------------------------------------------------------

cProject::cProject() {
}

//----------------------------------------------------------------------------

cProject::~cProject() {
}

//----------------------------------------------------------------------------

void cProject::Reset() {
    m_GlobalMacro.clear();
    m_GlobalInclude.clear();
    m_AllSrcInfo.clear();
}

//----------------------------------------------------------------------------

void cProject::AddGlobalMacro(std::string &macro) {
    m_GlobalMacro.push_back(macro);
}

//----------------------------------------------------------------------------

void cProject::AddGlobalInclude(std::string &includePath) {
    m_GlobalInclude.push_back(includePath);
}

//----------------------------------------------------------------------------

void cProject::AddGlobalMacro(const char *macro) {
    std::string sMacro(macro);
    m_GlobalMacro.push_back(sMacro);
}

//----------------------------------------------------------------------------

void cProject::AddGlobalInclude(const char *includePath) {
    std::string sIncludePath(includePath);
    m_GlobalInclude.push_back(sIncludePath);
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
