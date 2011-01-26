#ifndef cUnicode_Convert_h
#define cUnicode_Convert_h

#include <string>

/* cUnicodeConvert
 * Convert the source file of all codepage to UTF-8 string
 *
 * This class is responsible for maintaining a source code file in
 * the build tree to UnicodeString for regex searching.
 */


class cUnicodeConvert {
public:
    /** Constructor */
    cUnicodeConvert();

    /** Virtual destructor to cleanup subclasses properly.  */
    virtual ~cUnicodeConvert();

    /** Convert source file to UTF-8 string automatically.  */
    int32_t Convert(const char *sourceFile);

    /** Convert source file to UTF-8 string according to the given codepage.  */
    int32_t Convert(const char *sourceFile, const char *codepage);

    /** Convert source data to UTF-8 string automatically.  */
    int32_t Convert(const char *codepageData, int32_t dataLength);

    /** Convert source data to UTF-8 string according to the given codepage.  */
    int32_t Convert(const char *codepageData, int32_t dataLength, const char *codepage);

    /** Get the reference of UTF-8 string.  */
    std::string& getUtf8String();

protected:
    std::string getCodePageFromData(const char *codepageData, int32_t dataLength);

protected:
    /** UTF-8 string */
    std::string m_utf8String;
};

#endif