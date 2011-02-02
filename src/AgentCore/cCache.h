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
    virtual void Reset();

protected:
    /** Source file name. */
    std::string m_SourceFileName;

    /** Source file last write time. */
    std::time_t m_SrcLastWriteTime;

    /** Depneds filef name. */
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
