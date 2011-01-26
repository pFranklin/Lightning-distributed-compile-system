#include <fstream>
#include <unicode/ucsdet.h>
#include <unicode/unistr.h>
#include "cUnicodeConvert.h"

//warning :: length of source file and codepageData
//must not be bigger than 2GB

//----------------------------------------------------------------------------

cUnicodeConvert::cUnicodeConvert() {

}

//----------------------------------------------------------------------------

cUnicodeConvert::~cUnicodeConvert() {

}

//----------------------------------------------------------------------------

std::string cUnicodeConvert::getCodePageFromData(const char *codepageData, int32_t dataLength) {
    std::string codepage;
    UErrorCode status = U_ZERO_ERROR;
    UCharsetDetector* ucsd = ucsdet_open(&status);

    ucsdet_setText(ucsd, codepageData, dataLength, &status);
    const UCharsetMatch *matche = ucsdet_detect(ucsd, &status);
    codepage.append(ucsdet_getName(matche, &status));

    ucsdet_close(ucsd);
    return codepage;
}

//----------------------------------------------------------------------------

int32_t cUnicodeConvert::Convert(const char *codepageData, int32_t dataLength, const char *codepage) {
    m_utf8String.clear();
    U_NAMESPACE_QUALIFIER UnicodeString unicode(codepageData, dataLength, codepage);
    unicode.toUTF8String(m_utf8String);
    return unicode.length();
}

//----------------------------------------------------------------------------

int32_t cUnicodeConvert::Convert(const char *codepageData, int32_t dataLength) {
    std::string codepage = getCodePageFromData(codepageData, dataLength);
    return Convert(codepageData, dataLength, codepage.c_str());
}

//----------------------------------------------------------------------------

int32_t cUnicodeConvert::Convert(const char *sourceFile, const char *codepage) {
    int32_t ret = 0;
    std::ifstream infile(sourceFile);

    if (infile.is_open()) {
        try {
            infile.unsetf(std::ios::skipws);
            std::string codepageData;
            codepageData.assign(
                std::istreambuf_iterator<char>(infile.rdbuf()),
                std::istreambuf_iterator<char>());
            ret = Convert(codepageData.c_str(), codepageData.size(), codepage);
        } catch (...) {
        }
    }
    return ret;
}

//----------------------------------------------------------------------------

int32_t cUnicodeConvert::Convert(const char *sourceFile) {
    int32_t ret = 0;
    std::ifstream infile(sourceFile);

    if (infile.is_open()) {
        try {
            infile.unsetf(std::ios::skipws);
            std::string codepageData;
            codepageData.assign(
                std::istreambuf_iterator<char>(infile.rdbuf()),
                std::istreambuf_iterator<char>());
            std::string codepage = getCodePageFromData(codepageData.c_str(), codepageData.size());
            ret = Convert(codepageData.c_str(), codepageData.size(), codepage.c_str());
        } catch (...) {
        }
    }
    return ret;
}

//----------------------------------------------------------------------------

std::string& cUnicodeConvert::getUtf8String() {
    return m_utf8String;
}
