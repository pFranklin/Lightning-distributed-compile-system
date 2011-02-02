/*============================================================================
  Lightning - Cross Platform Distributed Building System
  Copyright 2010-2011 Paul Franklin

  Distributed under the GNU General Public License v2.0 License or later;
  see accompanying file license for details.

  This software is distributed WITHOUT ANY WARRANTY; without even the
  implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the License for more information.
============================================================================*/


#include <cstdio>
#include "cProject.h"
#include "common/ioSerialize.h"

int main(int argc, char **argv) {
    cProject p;
    sSrcInfo sourceFile;
    sourceFile.m_SrcFileName = "123123123";
    sourceFile.m_Macro.push_back("abcdef");
    sourceFile.m_Macro.push_back("ddddef");
    p.AddGlobalMacro("base");
    p.AddSourceFile(sourceFile);
    ioSerialize::Output(p, "f:/t.t");

    return 1;

}