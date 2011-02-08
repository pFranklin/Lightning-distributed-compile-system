/*============================================================================
  Lightning - Cross Platform Distributed Building System
  Copyright 2010-2011 Paul Franklin

  Distributed under the GNU General Public License v2.0 License or later;
  see accompanying file license for details.

  This software is distributed WITHOUT ANY WARRANTY; without even the
  implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the License for more information.
============================================================================*/


#include <boost/bind.hpp>
#include <boost/tokenizer.hpp>
#include <boost/token_functions.hpp>
#include <glog/logging.h>
#include "cCmdHandler.h"
#include "common/version.h"
#include "common/ioSerialize.h"

namespace po = boost::program_options;
using namespace std;

//----------------------------------------------------------------------------

cCmdHandler::cCmdHandler()
: m_SrcIndex(-1) {
    InitOpcodeHandler();
    RegisterCommandLine();
}

//----------------------------------------------------------------------------

cCmdHandler::~cCmdHandler() {
}

//----------------------------------------------------------------------------

void cCmdHandler::InitCommandLine(int argc, char **argv) {
    // init google log
    google::InitGoogleLogging(argv[0]);

    // input-file have no option name
    try {
        po::positional_options_description p;
        p.add("input-file", -1);
        po::store(po::command_line_parser(argc, argv).
                options(m_Cmdline_Options).positional(p).run(), m_VarMap);
        po::notify(m_VarMap);
    } catch (exception &e) {
        LOG(ERROR) << e.what();
    }

    if (m_VarMap.count("help")) {
        cout << m_Cmdline_Options << endl;
    } else if (m_VarMap.count("version")) {
        cout << "Lightning distributed building system "
                << LIGHTNING_VERSION << endl;
    } else if (m_Operator.find(m_Opcode) != m_Operator.end()) {
        m_Operator[m_Opcode](this);
    }
}

//----------------------------------------------------------------------------

void cCmdHandler::RegisterCommandLine() {
    // add generic options including --help, --opcode and --version
    po::options_description generic("Generic options");
    generic.add_options()
            ("version", "print version string")
            ("help", "produce help message");

    // src config
    po::options_description src_config("Source file config");
    src_config.add_options()
            ("input-file", po::value<vector<string> > (&m_SrcFileInfo.m_SrcFileName),
            "input source file name")
            ("output-file", po::value<vector<string> > (&m_SrcFileInfo.m_OutFileName),
            "output obj file name")
            ("entry-name", po::value<string > (&m_SrcFileInfo.m_EntryName),
            "source code enctry function name")
            ("options", po::value<string > (&m_SrcFileInfo.m_Options),
            "compile options")
            ("depend-module", po::value<string > (&m_SrcFileInfo.m_DependsCheckName),
            "depends check module name")
            ("compiler", po::value<string > (&m_SrcFileInfo.m_Compiler),
            "compiler name")
            ("gencmd-module", po::value<string > (&m_SrcFileInfo.m_CompilerCommand),
            "compile command line generate module")
            ("include-path", po::value<vector<string> > (&m_SrcFileInfo.m_Include),
            "include path")
            ("macro", po::value<vector<string> > (&m_SrcFileInfo.m_Macro),
            "include path");

    // project config
    po::options_description project_config("Project file config");
    project_config.add_options()
            ("opcode", po::value<string > (&m_Opcode),
            "project operation code")
            ("project-name", po::value<string > (&m_ProjectFile),
            "project file name")
            ("src-index", po::value<int32_t > (&m_SrcIndex)->default_value(-1),
            "source file index");

    m_Cmdline_Options.add(generic).add(project_config).add(src_config);
}

//----------------------------------------------------------------------------

void cCmdHandler::InitOpcodeHandler() {
    m_Operator["set_source"] = boost::bind(&cCmdHandler::OpcodeHandleSetSource, this);
    m_Operator["remove_source"] = boost::bind(&cCmdHandler::OpcodeHandleRemoveSource, this);
    m_Operator["build"] = boost::bind(&cCmdHandler::OpcodeHandleBuild, this);
}

//----------------------------------------------------------------------------

void cCmdHandler::OpcodeHandleProject(bool bRemove) {
    // import project
    cProject project;
    ioSerialize::Input(project, m_ProjectFile.c_str());

    // check src info
    try {
        if (m_SrcFileInfo.CheckMember() == true) {
            // remove source file
            if (bRemove == true) {
                project.RemoveSourceFile(m_SrcIndex);
            }
            // set source file
            else {
                // append the src file to the end of project
                if (m_SrcIndex == -1) {
                    project.AddSourceFile(m_SrcFileInfo);
                }// change the source file
                else {
                    project.SetSourceFile(m_SrcIndex, m_SrcFileInfo);
                }
            }
            // output the project file
            ioSerialize::Output(project, m_ProjectFile.c_str());
        }
    } catch (exception &e) {
        LOG(ERROR) << e.what() << endl;
    }
}

//----------------------------------------------------------------------------

void cCmdHandler::OpcodeHandleSetSource() {
    OpcodeHandleProject(false);
}

//----------------------------------------------------------------------------

void cCmdHandler::OpcodeHandleRemoveSource() {
    OpcodeHandleProject(true);
}

//----------------------------------------------------------------------------

void cCmdHandler::OpcodeHandleBuild() {
}