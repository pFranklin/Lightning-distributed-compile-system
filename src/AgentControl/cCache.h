/*============================================================================
  Lightning - Cross Platform Distributed Building System
  Copyright 2010-2011 Paul Franklin

  Distributed under the GNU General Public License v2.0 License or later;
  see accompanying file license for details.

  This software is distributed WITHOUT ANY WARRANTY; without even the
  implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the License for more information.
============================================================================*/


#ifndef cCache_h
#define cCache_h

#include <ctime>
#include <boost/serialization/string.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/serialization/map.hpp>

/* cCache
 * Building system source file caches handler.
 *
 * This class is responsible for caches the output
 * of source file and compile options so that next time,
 * the same compilation can be avoided and the results
 * can be taken from the cache.
 */

class cCache {
public:
    /** Constructor of the class. */
    cCache();

    /** Virtual destructor to cleanup subclasses properly.  */
    virtual ~cCache();

    /** Reset all members. */
    void Reset();

    /** Check the source file which should be recompiled or not. */
    bool CheckFile();

    /** Check compile option. */
    bool CheckOption(std::string &option);

protected:
    /** Source file name. */
    std::string m_SourceFileName;

    /** Source file last write time. */
    std::time_t m_SrcLastWriteTime;

    /** Depneds file name. */
    std::map<std::string, std::time_t> m_DependsInfo;

    /** Options crc. */
    unsigned int m_OptionsCrc;

private:
    friend class boost::serialization::access;

    template<class Archive>
    void serialize(Archive & ar, const unsigned int version) {
        ar & m_SourceFileName;
        ar & m_SrcLastWriteTime;
        ar & m_DependsInfo;
        ar & m_OptionsCrc;
    }
};

#endif
