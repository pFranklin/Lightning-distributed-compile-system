/* This source file covert boost file system
 * code page in Cygwin to UTF-8 for cross-platform
 * between windows and posix.
 * All the Path string must be UTF-8 code covert.
 */


#ifdef __CYGWIN__

// if compiled under cygwin, using boost utf-8 codecvt
#define BOOST_UTF8_BEGIN_NAMESPACE
#define BOOST_UTF8_END_NAMESPACE
#define BOOST_UTF8_DECL

#include <boost/detail/utf8_codecvt_facet.hpp> 
#include <libs/detail/utf8_codecvt_facet.cpp>

#endif
