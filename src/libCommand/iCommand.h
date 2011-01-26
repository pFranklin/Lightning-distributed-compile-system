#ifndef iCommand_h
#define iCommand_h

/* iCommand
 * Interface for generating compiler command line.
 *
 * This interface is responsible for generating a command line string for
 * numerous compilers.
 */

class iCommand {
public:

    /** Instances need to know the build directory name and the relative
            path from the build directory to the target file.  */
    iCommand() {
    };

    /** Virtual destructor to cleanup subclasses properly.  */
    virtual ~iCommand() {
    };

    /** Release the pointer.  */
    virtual void Release() = 0;

    /** Reset the class to default state.  */
    virtual void Reset() = 0;

    /** Clear the command line.  */
    virtual void Clear() = 0;

    /** Set the source file name.  */
    virtual int SetSourceFile(const char *SourceName) = 0;

    /** Set the entry name.  */
    virtual int SetEntry(const char *EntryName) = 0;

    /** Set the output file name.  */
    virtual int SetOutputFile(const char *OutputName) = 0;

    /** Set options of compiler.  */
    virtual int SetOptions(const char *Options) = 0;

    /** Add macro.  */
    virtual int AddMacro(const char *macro) = 0;

    /** Add a additional search directory.  */
    virtual int AddExtraSearchPath(const char *searchPath) = 0;

    /** Generate the command line.  */
    virtual bool GenerateCommandLine(const char **commandLine) = 0;

private:
    iCommand(iCommand const&); // Purposely not implemented.
    void operator=(iCommand const&); // Purposely not implemented.
};

// Depends creator interface
typedef iCommand* (*CommandCreator)(const char*);
// Depends creator function name
#define COMMAND_CREATOR_NAME "CreateCommand"


#endif
