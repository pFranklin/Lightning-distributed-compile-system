#include <cstdio>
#include "cProject.h"
#include "common/ioSerialize.h"

int main(int argc, char **argv) {
    cProject p;
    p.AddGlobalMacro("base");
    ioSerialize::Output(p, "f:/t.t");

    return 1;

}