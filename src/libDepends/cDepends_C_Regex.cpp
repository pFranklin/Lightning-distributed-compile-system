#define BOOST_FILESYSTEM_VERSION 3

#include <boost/filesystem.hpp>
#include <boost/threadpool.hpp>
#include "cDepends_C_Regex.h"
#include "common/cUnicodeConvert.h"
#include "common/BFS_UTF8_CODE.h"

const static char *checkRegex =
        "^[[:blank:]]*(?://@bcp[[:blank:]]+([^\\n]*)\n)?#[[:blank:]]*include[[:blank:]]*[\"<]([^\">]+)[\">]";

//----------------------------------------------------------------------------

cDepends_C_Regex::cDepends_C_Regex()
:m_regex(boost::make_u32regex(checkRegex)){
}

//----------------------------------------------------------------------------

cDepends_C_Regex::~cDepends_C_Regex() {
}

//----------------------------------------------------------------------------

bool cDepends_C_Regex::SearchDependsFile(const char *FileName, std::vector<std::string> &SearchPath,
        bool sysSearch, std::string &outFullName) {

    bool bOK = false;
    outFullName.clear();
    boost::filesystem3::path filename(BFS_UTF8_STRING(FileName));

    sDependsFile dependsFile;
    if (sysSearch) dependsFile.FileType = enum_SysIncludeFile;
    else dependsFile.FileType = enum_IncludeFile;

    // if it is a absolute file name, you should improve your programming habit!
    if (filename.is_absolute()) {
        outFullName = filename.generic_string(BFS_UTF8_CVT);
        dependsFile.FileAbsPath = filename.generic_string(BFS_UTF8_CVT);
        dependsFile.FileType = enum_IncludeFile;
        bOK = true;
    }// relative file name
    else {
        for (std::vector<std::string>::iterator i = SearchPath.begin(); i != SearchPath.end(); ++i) {
            boost::filesystem3::path includePath(BFS_UTF8_STRING(*i));
            boost::filesystem3::path fullFileName = boost::filesystem3::absolute(filename, includePath);
            // file exists
            if (boost::filesystem3::status(fullFileName).type() == boost::filesystem3::regular_file) {
                fullFileName = boost::filesystem3::system_complete(fullFileName);
                outFullName = fullFileName.generic_string(BFS_UTF8_CVT);
                dependsFile.FileAbsPath = fullFileName.generic_string(BFS_UTF8_CVT);
                dependsFile.FileRelativePath = filename.generic_string(BFS_UTF8_CVT);
                bOK = true;
                break;
            }
        }
    }
    // do not include the same file
    m_AddDependsMutex.lock();
    if (bOK && std::find(m_IncludeFile.begin(), m_IncludeFile.end(), dependsFile) == m_IncludeFile.end()) {
        m_IncludeFile.push_back(dependsFile);
        bOK = true;
    }
    else {
        bOK = false;
    }
    m_AddDependsMutex.unlock();

    return bOK;
}

//----------------------------------------------------------------------------

void cDepends_C_Regex::CheckRootDepends(const char *sourceFile, std::vector<std::string> *leafs,
        std::set<std::string> *allLeafs) {
    // convert source file to UTF-8 string
    cUnicodeConvert u;
    u.Convert(sourceFile);

    // init regex
    boost::utf8regex_token_iterator
    i(boost::make_u32regex_token_iterator(u.getUtf8String().c_str(), m_regex, 2)), j;

    while (i != j) {
        bool b = false;
        std::string leaf;

        // #include <>
        if (*(i->second) == '>') {
            b = SearchDependsFile(i->str().c_str(), m_ExtraSearchPath, false, leaf);
            if (b == false)
                b = SearchDependsFile(i->str().c_str(), m_StandSearchPath, true, leaf);
        }// #include ""
        else if (*(i->second) == '"') {
            std::vector<std::string> searchpath;
            searchpath.push_back(m_SourceFilePath);
            b = SearchDependsFile(i->str().c_str(), searchpath, false, leaf);

            if (b == false)
                b = SearchDependsFile(i->str().c_str(), m_ExtraSearchPath, false, leaf);
            if (b == false)
                b = SearchDependsFile(i->str().c_str(), m_StandSearchPath, true, leaf);
        }

        m_LeafsMutex.lock();
        if (b == true && allLeafs->find(leaf) == allLeafs->end()) {
            leafs->push_back(leaf);
            allLeafs->insert(leaf);
        }
        m_LeafsMutex.unlock();
        ++i;
    }
}

//----------------------------------------------------------------------------

bool cDepends_C_Regex::CheckDependencies(const char *sourceFile) {
    SetSourceFilePath(sourceFile);

    boost::threadpool::pool tp;
    tp.size_controller().resize(10);

    std::vector<std::string> leafs;
    std::vector<std::string> leafs2;
    std::set<std::string> allLeafs;
    leafs.push_back(sourceFile);
    allLeafs.insert(sourceFile);

    // prepare two leaf pointer
    std::vector<std::string> *pleafs1 = &leafs;
    std::vector<std::string> *pleafs2 = &leafs2;

    do {
        std::vector<std::string>::iterator itor=pleafs1->begin();
        for (; itor!=pleafs1->end(); ++itor) {
            boost::threadpool::schedule
                    (tp, boost::bind(&cDepends_C_Regex::CheckRootDepends, this, itor->c_str(), pleafs2, &allLeafs));
        }
        tp.wait();

        pleafs1->clear();
        std::swap(pleafs1, pleafs2);
    } while (pleafs1->size());

    return true;
}