/*============================================================================
  Lightning - Cross Platform Distributed Building System
  Copyright 2010-2011 Paul Franklin

  Distributed under the GNU General Public License v2.0 License or later;
  see accompanying file license for details.

  This software is distributed WITHOUT ANY WARRANTY; without even the
  implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the License for more information.
============================================================================*/


#ifndef ioSerialize_h
#define ioSerialize_h

#include <fstream>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>

/* cSerializeBase
 * Serialize base class.
 *
 * This class is responsible for handling basic
 * interface of serialize.
 */

namespace ioSerialize {

    /** Input from iostream. */
    template <class T>
    void Input(T &type, std::istream &is_) {
        boost::archive::binary_iarchive ia(is_);
        ia >> type;
    }

    /** Output to iostream. */
    template <class T>
    void Output(T &type, std::ostream &os_) {
        boost::archive::binary_oarchive oa(os_);
        oa << type;
    }

    /** Input frome file. */
    template <class T>
    void Input(T &type, const char *projectFile) {
        std::ifstream ifs(projectFile, std::ios::binary);
        Input(type, ifs);
    }

    /** Output to file. */
    template <class T>
    void Output(T &type, const char *projectFile) {
        std::ofstream ofs(projectFile);
        Output(type, ofs);
    }
}

#endif

