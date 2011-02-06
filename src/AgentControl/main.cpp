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
#include <stdlib.h>
#include <glog/logging.h>
#include "cProject.h"
#include "common/ioSerialize.h"


int main(int argc, char **argv) {


    // Initialize Google's logging library.
    google::InitGoogleLogging(argv[0]);
    google::ParseCommandLineFlags(&argc, &argv, false);

    // ...
    LOG(INFO) << "Found " << 3 << " cookies";


    return 1;

}