#include <fstream>

#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>

#include "cProject.h"

//----------------------------------------------------------------------------

template<class Archive>
void sSrcInfo::serialize(Archive & ar, const unsigned int version) {
    ar & m_SrcFileName;
    ar & m_OutFileName;
    ar & m_EntryName;
    ar & m_Options;
    ar & m_DependsCheckName;
    ar & m_Compiler;
    ar & m_CompilerCommand;
    ar & m_Macro;
    ar & m_AppendMacro;
    ar & m_Include;
    ar & m_AppendInclude;
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

void cProject::InputProject(const char *projectFile) {
    std::ifstream ifs(projectFile, std::ios::binary);
    InputProject(ifs);
}

//----------------------------------------------------------------------------

void cProject::OutPutProject(const char *projectFile) {
    std::ofstream ofs(projectFile);
    OutPutProject(ofs);
}

//----------------------------------------------------------------------------

void cProject::InputProject(std::istream &is_) {
    this->Reset();
    boost::archive::binary_iarchive ia(is_);
    ia >> (*this);
}

//----------------------------------------------------------------------------

void cProject::OutPutProject(std::ostream &os_) {
    boost::archive::binary_oarchive oa(os_);
    oa << (*this);
}


//----------------------------------------------------------------------------

template<class Archive>
void cProject::serialize(Archive & ar, const unsigned int version) {
    ar & m_GlobalMacro;
    ar & m_GlobalInclude;
    ar & m_AllSrcInfo;
}