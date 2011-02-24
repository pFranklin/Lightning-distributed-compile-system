/*============================================================================
  Lightning - Cross Platform Distributed Building System
  Copyright 2010-2011 Paul Franklin

  Distributed under the GNU General Public License v2.0 License or later;
  see accompanying file license for details.

  This software is distributed WITHOUT ANY WARRANTY; without even the
  implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the License for more information.
============================================================================*/

#ifndef cBuildTree_tcl_h
#define cBuildTree_tcl_h

#include <Tree.h>
#include "iBuildTree.h"

/* cBuildTree_tcl
 * Building system source file dependency tree implementation.
 *
 * This class is responsible for building the source file
 * tcl version build tree of the building system.
 */

class cBuildTree_tcl {
public:

    /** Constructor of the class. */
    cBuildTree_tcl();

    /** Virtual destructor to cleanup subclasses properly.  */
    virtual ~cBuildTree_tcl();

    /** Create the build tree.  */
    virtual void createBuildTree(const std::vector<sSrcInfo> &compileSrc);

    /** Get the source file building queue, if there is no building queue, return 0.  */
    virtual int getBuildQueue(std::vector<std::vector<sSrcInfo*> > &compileSrc);

protected:
    tcl::tree<sSrcInfo*> m_BuildTree;

private:
    cBuildTree_tcl(cBuildTree_tcl const&); // Purposely not implemented.
    void operator=(cBuildTree_tcl const&); // Purposely not implemented.
};

#endif

