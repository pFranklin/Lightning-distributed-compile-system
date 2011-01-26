#include <dlfcn.h>
#include <stdlib.h>

#include "../libDepends/iDepends.h"

int main(int argc, char **argv) {

    void *dll = dlopen("plugins/libDepends.dll", RTLD_LOCAL);
    DependsCreator fa = (DependsCreator) dlsym(dll, DEPENDS_CREATOR_NAME);
    iDepends *i = fa("Depends_C");

    i->SetProjectFileAbsPath("F:\\Lightning\\Build\\win32\\NetBeans\\libDepends");

    i->AddStandSearchPath("F:\\cygwin\\usr\\lib\\gcc\\i686-pc-cygwin\\4.3.4\\include\\c++");
    i->AddStandSearchPath("F:\\cygwin\\lib\\gcc\\i686-pc-cygwin\\4.3.4\\include\\c++");
    i->AddStandSearchPath("F:\\cygwin\\usr\\include");
    i->AddStandSearchPath("F:\\cygwin\\usr\\include\\w32api");
    i->AddStandSearchPath("F:\\cygwin\\include\\w32api");
    i->AddStandSearchPath("F:\\cygwin\\usr\\lib\\gcc\\i686-pc-cygwin\\4.3.4\\include\\c++\\i686-pc-cygwin");
    i->AddStandSearchPath("F:\\cygwin\\lib\\gcc\\i686-pc-cygwin\\4.3.4\\include\\c++\\i686-pc-cygwin");
    i->AddStandSearchPath("F:\\cygwin\\usr\\lib\\gcc\\i686-pc-cygwin\\4.3.4\\include\\c++\\backward");
    i->AddStandSearchPath("F:\\cygwin\\lib\\gcc\\i686-pc-cygwin\\4.3.4\\include\\c++\\backward");
    i->AddStandSearchPath("F:\\cygwin\\usr\\lib\\gcc\\i686-pc-cygwin\\4.3.4\\include");
    i->AddStandSearchPath("F:\\cygwin\\lib\\gcc\\i686-pc-cygwin\\4.3.4\\include");
    i->AddStandSearchPath("F:\\cygwin\\usr\\lib\\gcc\\i686-pc-cygwin\\4.3.4\\include-fixed");
    i->AddStandSearchPath("F:\\cygwin\\lib\\gcc\\i686-pc-cygwin\\4.3.4\\include-fixed");

    i->AddExtraSearchPath("../../../../Contrib/boost_1_45_0");
    i->AddExtraSearchPath("../../../../src");

    i->AddMacro("__i386__");
    i->AddMacro("__CYGWIN__");

    //i->SearchStandDir(true);

    i->CheckDependencies("F:\\Lightning\\src\\common\\cUnicodeConvert.h");
    sDependsInfo *info = 0;
    uint32_t num;
    i->WriteDependencies(&info, num);
    i->Release();
    dlclose(dll);

    return 0;
}
