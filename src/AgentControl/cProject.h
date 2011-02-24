/*============================================================================
  Lightning - Cross Platform Distributed Building System
  Copyright 2010-2011 Paul Franklin

  Distributed under the GNU General Public License v2.0 License or later;
  see accompanying file license for details.

  This software is distributed WITHOUT ANY WARRANTY; without even the
  implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the License for more information.
============================================================================*/


#ifndef cProject_h
#define cProject_h

#include <boost/serialization/list.hpp>
#include <boost/serialization/string.hpp>
#include <boost/serialization/vector.hpp>
#include "common/cException.h"

/* sSrcInfo
 * Building system one source file options.
 *
 * This struct is responsible for handling one
 * single src file information of the building system.
 */

struct sSrcInfo {
    /** Source file name, important member. */
    std::vector<std::string> m_SrcFileName;

    /** All output file names, important member. */
    std::vector<std::string> m_OutFileName;

    /** Source file entry function. */
    std::string m_EntryName;

    /** Another options. */
    std::string m_Options;

    /** Name of depends check module, important member. */
    std::string m_DependsCheckName;

    /** Name of compiler, important member. */
    std::string m_Compiler;

    /** Name of Compiler command generator module, important member. */
    std::string m_CompilerCommand;

    /** Self macro. */
    std::vector<std::string> m_Macro;

    /** Self include path. */
    std::vector<std::string> m_Include;

    /** Constructor of the struct. */
    sSrcInfo() {
    }

    /** Check important member. */
    bool CheckMember();

    /** View the src info. */
    void ViewInfo();

protected:
    /** View the string in vector. */
    void ViewVecStr(const char *desc, std::vector<std::string> &vecStr);

private:
    friend class boost::serialization::access;

    template<class Archive>
    void serialize(Archive & ar, const unsigned int version) {
        ar & m_SrcFileName;
        ar & m_OutFileName;
        ar & m_EntryName;
        ar & m_Options;
        ar & m_DependsCheckName;
        ar & m_Compiler;
        ar & m_CompilerCommand;
        ar & m_Macro;
        ar & m_Include;
    }
};

/* cProject
 * Building system project file class.
 *
 * This class is responsible for handling the project
 * information of the building system.
 */

class cProject {
public:

    /** Constructor of the class. */
    cProject();

    /** Virtual destructor to cleanup subclasses properly.  */
    virtual ~cProject();

    /** Reset all members. */
    void Reset();

    /** Add one source file. */
    void AddSourceFile(sSrcInfo &sourceFile);

    /** Set source file. */
    void SetSourceFile(unsigned int index, sSrcInfo &sourceFile);

    /** Remove source file. */
    void RemoveSourceFile(unsigned int index);

    /** View the project file info. */
    void ViewInfo();

protected:
    /** All source files information.  */
    std::list<sSrcInfo> m_AllSrcInfo;

private:
    cProject(cProject const&); // Purposely not implemented.
    void operator=(cProject const&); // Purposely not implemented.

private:
    friend class boost::serialization::access;

    template<class Archive>
    void serialize(Archive & ar, const unsigned int version) {
        ar & m_AllSrcInfo;
    }
};

#endif
