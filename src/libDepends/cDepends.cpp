#define BOOST_FILESYSTEM_VERSION 3

#include <iostream>
#include <boost/filesystem.hpp>
#include "common/BFS_UTF8_CODE.h"
#include "cDepends.h"

//----------------------------------------------------------------------------

bool sDependsFile::operator ==(const sDependsFile & ds) const {
    boost::filesystem3::path src(BFS_UTF8_STRING(FileAbsPath));
    boost::filesystem3::path dst(BFS_UTF8_STRING(ds.FileAbsPath));
    bool bret = false;

    try {
        bret = boost::filesystem3::equivalent(src, dst);
    }
    catch (boost::filesystem3::filesystem_error &error) {
        std::cerr << error.what();
        bret = false;
    }
    return bret;
}

//----------------------------------------------------------------------------

cDepends::cDepends() {
}

//----------------------------------------------------------------------------

cDepends::~cDepends() {
}

//----------------------------------------------------------------------------

void cDepends::Release() {
    delete this;
}

//----------------------------------------------------------------------------

void cDepends::Reset() {
    m_Macro.clear();
    m_StandSearchPath.clear();
    m_ExtraSearchPath.clear();
    m_SourceFilePath.clear();
    m_ProjectFilePath.clear();
    Clear();
}

//----------------------------------------------------------------------------

void cDepends::Clear() {
    m_SourceFilePath.clear();
    m_IncludeFile.clear();
    m_DependsInfo.clear();
}

//----------------------------------------------------------------------------

int cDepends::SetProjectFileAbsPath(const char *projectPath) {
    int iRet = 0;
    boost::filesystem3::path project(BFS_UTF8_STRING(projectPath));
    // be sure the path is absolute, and be formatted
    project = boost::filesystem3::absolute(project);
    project = boost::filesystem3::system_complete(project);

    // check
    if (boost::filesystem3::is_directory(project)) {
        m_ProjectFilePath = project.generic_string(BFS_UTF8_CVT).c_str();
        iRet = 1;
    }

    return iRet;
}

//----------------------------------------------------------------------------

int cDepends::AddMacro(const char *macro) {
    m_Macro.push_back(macro);
    return 1;
}

//----------------------------------------------------------------------------

int cDepends::AddStandSearchPath(const char *searchPath) {
    int iRet = 0;
    boost::filesystem3::path search(BFS_UTF8_STRING(searchPath));
    // be sure the path is absolute, and be formatted
    search = boost::filesystem3::absolute(search, m_ProjectFilePath);
    search = boost::filesystem3::system_complete(search);

    // check
    if (boost::filesystem3::is_directory(search)) {
        m_StandSearchPath.push_back(search.generic_string(BFS_UTF8_CVT).c_str());
        iRet = 1;
    }

    return iRet;
}

//----------------------------------------------------------------------------

int cDepends::AddExtraSearchPath(const char *searchPath) {
    int iRet = 0;
    boost::filesystem3::path search(BFS_UTF8_STRING(searchPath));
    // be sure the path is absolute to project path, and be formatted
    search = boost::filesystem3::absolute(search, m_ProjectFilePath);
    search = boost::filesystem3::system_complete(search);

    // check
    if (boost::filesystem3::is_directory(search)) {
        m_ExtraSearchPath.push_back(search.generic_string(BFS_UTF8_CVT).c_str());
        iRet = 1;
    }

    return iRet;
}

//----------------------------------------------------------------------------

int cDepends::SetSourceFilePath(const char *FullSourceName) {
    int iRet = 0;
    boost::filesystem3::path filename(BFS_UTF8_STRING(FullSourceName));
    // be sure the path is absolute
    filename = boost::filesystem3::absolute(filename, m_ProjectFilePath);
    filename = boost::filesystem3::system_complete(filename);

    // check
    if (boost::filesystem3::is_regular_file(filename)) {
        m_SourceFilePath = filename.parent_path().generic_string(BFS_UTF8_CVT);
        iRet = 1;
    }

    return iRet;
}

//----------------------------------------------------------------------------

bool cDepends::WriteDependencies(sDependsInfo **dependsInfo, uint32_t &infoNum) {
    if (!dependsInfo) return false;
    // init m_DependsInfo.
    m_DependsInfo.clear();
    *dependsInfo = 0;
    infoNum = 0;

    std::vector<sDependsFile>::iterator itor = m_IncludeFile.begin();
    for (; itor != m_IncludeFile.end(); ++itor) {
        sDependsInfo file;
        file.FileAbsPath = itor->FileAbsPath.c_str();
        file.FileRelativePath = itor->FileRelativePath.c_str();

        // if it's a preprocessed file, set the file data pointer.
        if (itor->FileType == enum_PreprocessedFile) {
            file.FileData = itor->FileData.c_str();
            file.FileSize = itor->FileData.size();
        }
        m_DependsInfo.push_back(file);
    }

    *dependsInfo = &m_DependsInfo.front();
    infoNum = m_DependsInfo.size();

    return true;
}

