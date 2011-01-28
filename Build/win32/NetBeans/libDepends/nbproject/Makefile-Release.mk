#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc.exe
CCC=g++.exe
CXX=g++.exe
FC=
AS=as.exe

# Macros
CND_PLATFORM=Cygwin_4.x-Windows
CND_CONF=Release
CND_DISTDIR=dist

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=build/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/1152467571/cDepends_C_Regex.o \
	${OBJECTDIR}/_ext/438060982/BFS_UTF8_CODE.o \
	${OBJECTDIR}/_ext/438060982/cUnicodeConvert.o \
	${OBJECTDIR}/_ext/1152467571/cDepends.o \
	${OBJECTDIR}/_ext/1152467571/cDependsFactory.o \
	${OBJECTDIR}/_ext/1152467571/cDepends_C.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-Wno-ignored-qualifiers
CXXFLAGS=-Wno-ignored-qualifiers

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-L../../../../Contrib/LIBS/win32/boost -lboost_filesystem -lboost_regex -lboost_system -lboost_thread -lboost_wave -licuuc45 -licui18n45

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-Release.mk ../../../../Bin/win32/plugins/libDepends.dll

../../../../Bin/win32/plugins/libDepends.dll: ${OBJECTFILES}
	${MKDIR} -p ../../../../Bin/win32/plugins
	${LINK.cc} -shared -o ../../../../Bin/win32/plugins/libDepends.dll -s ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/_ext/1152467571/cDepends_C_Regex.o: ../../../../src/libDepends/cDepends_C_Regex.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1152467571
	${RM} $@.d
	$(COMPILE.cc) -O3 -Wall -I../../../../Contrib/boost_1_45_0 -I../../../../Contrib/threadpool -I../../../../src  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1152467571/cDepends_C_Regex.o ../../../../src/libDepends/cDepends_C_Regex.cpp

${OBJECTDIR}/_ext/438060982/BFS_UTF8_CODE.o: ../../../../src/common/BFS_UTF8_CODE.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/438060982
	${RM} $@.d
	$(COMPILE.cc) -O3 -Wall -I../../../../Contrib/boost_1_45_0 -I../../../../Contrib/threadpool -I../../../../src  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/438060982/BFS_UTF8_CODE.o ../../../../src/common/BFS_UTF8_CODE.cpp

${OBJECTDIR}/_ext/438060982/cUnicodeConvert.o: ../../../../src/common/cUnicodeConvert.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/438060982
	${RM} $@.d
	$(COMPILE.cc) -O3 -Wall -I../../../../Contrib/boost_1_45_0 -I../../../../Contrib/threadpool -I../../../../src  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/438060982/cUnicodeConvert.o ../../../../src/common/cUnicodeConvert.cpp

${OBJECTDIR}/_ext/1152467571/cDepends.o: ../../../../src/libDepends/cDepends.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1152467571
	${RM} $@.d
	$(COMPILE.cc) -O3 -Wall -I../../../../Contrib/boost_1_45_0 -I../../../../Contrib/threadpool -I../../../../src  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1152467571/cDepends.o ../../../../src/libDepends/cDepends.cpp

${OBJECTDIR}/_ext/1152467571/cDependsFactory.o: ../../../../src/libDepends/cDependsFactory.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1152467571
	${RM} $@.d
	$(COMPILE.cc) -O3 -Wall -I../../../../Contrib/boost_1_45_0 -I../../../../Contrib/threadpool -I../../../../src  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1152467571/cDependsFactory.o ../../../../src/libDepends/cDependsFactory.cpp

${OBJECTDIR}/_ext/1152467571/cDepends_C.o: ../../../../src/libDepends/cDepends_C.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1152467571
	${RM} $@.d
	$(COMPILE.cc) -O3 -Wall -I../../../../Contrib/boost_1_45_0 -I../../../../Contrib/threadpool -I../../../../src  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1152467571/cDepends_C.o ../../../../src/libDepends/cDepends_C.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/Release
	${RM} ../../../../Bin/win32/plugins/libDepends.dll

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
