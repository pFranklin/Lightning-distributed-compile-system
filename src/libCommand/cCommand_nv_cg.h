#ifndef cCommand_nv_cg_h
#define cCommand_nv_cg_h

#include "cCommand.h"

/* cCommand_nv_cg
 * Command generator for nvidia cg compiler.
 *
 * This class is responsible for generating command line
 * for nVIDIA cg and cgFX shader language compiler.
 */

class cCommand_nv_cg : public cCommand {
public:
    /** Instances need to know the build directory name and the relative
            path from the build directory to the target file.  */
    cCommand_nv_cg();

    /** Virtual destructor to cleanup subclasses properly.  */
    virtual ~cCommand_nv_cg();

    /** Generate the command line.  */
    virtual bool GenerateCommandLine(const char **commandLine);

private:
    cCommand_nv_cg(cCommand_nv_cg const&); // Purposely not implemented.
    void operator=(cCommand_nv_cg const&); // Purposely not implemented.
};

#endif
