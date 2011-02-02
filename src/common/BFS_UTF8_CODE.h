/*============================================================================
  Lightning - Cross Platform Distributed Building System
  Copyright 2010-2011 Paul Franklin

  Distributed under the GNU General Public License v2.0 License or later;
  see accompanying file license for details.

  This software is distributed WITHOUT ANY WARRANTY; without even the
  implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the License for more information.
============================================================================*/


#ifndef BFS_UTF8_CODE
#define BFS_UTF8_CODE

/* This header file covert boost file system
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

#define BFS_UTF8_CVT utf8_codecvt_facet()
#define BFS_UTF8_STRING(s)  s,utf8_codecvt_facet()

#else

// under posix system, the defult code page is utf-8
#define BFS_UTF8_CVT
#define BFS_UTF8_STRING(s) s

#endif

#endif