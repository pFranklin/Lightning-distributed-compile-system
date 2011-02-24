/*============================================================================
  Lightning - Cross Platform Distributed Building System
  Copyright 2010-2011 Paul Franklin

  Distributed under the GNU General Public License v2.0 License or later;
  see accompanying file license for details.

  This software is distributed WITHOUT ANY WARRANTY; without even the
  implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the License for more information.
============================================================================*/

#ifndef iBuildTree_h
#define iBuildTree_h

#include <vector>
#include "cProject.h"

/* iBuildTree
 * Building system source file dependency tree structure.
 *
 * This class is responsible for handling the source file
 * build tree interface of the building system.
 */

class iBuildTree {
public:

    /** Constructor of the class. */
    iBuildTree()
    : m_scheduleParam(4096) {
    };

    /** Virtual destructor to cleanup subclasses properly.  */
    virtual ~iBuildTree() {
    };

    /** Create the build tree.  */
    void setScheduleParam(unsigned int param) {
        m_scheduleParam = param;
    }

    /** Create the build tree.  */
    virtual void createBuildTree(const std::vector<sSrcInfo> &compileSrc) = 0;

    /** Get the source file building queue, if there is no building queue, return 0.  */
    virtual int getBuildQueue(std::vector<std::vector<sSrcInfo> > &compileSrc) = 0;

protected:

    /** Build queue schedule parameter.  */
    unsigned int m_scheduleParam;

private:
    iBuildTree(iBuildTree const&); // Purposely not implemented.
    void operator=(iBuildTree const&); // Purposely not implemented.
};

#endif

