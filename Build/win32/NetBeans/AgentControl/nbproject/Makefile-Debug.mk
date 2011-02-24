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
CND_CONF=Debug
CND_DISTDIR=dist

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=build/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/1193482173/main.o \
	${OBJECTDIR}/_ext/438060982/BFS_UTF8_CODE.o \
	${OBJECTDIR}/_ext/1193482173/cProject.o \
	${OBJECTDIR}/_ext/1193482173/cCache.o \
	${OBJECTDIR}/_ext/1193482173/cBuildTree_tcl.o \
	${OBJECTDIR}/_ext/1193482173/cCmdHandler.o


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
LDLIBSOPTIONS=-L../../../../Contrib/LIBS/win32/boost -L../../../../Contrib/LIBS/win32/glog -lboost_filesystem -lboost_program_options -lboost_serialization -lboost_system -lglog

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-Debug.mk ../../../../Bin/win32/AgentControl.exe

../../../../Bin/win32/AgentControl.exe: ${OBJECTFILES}
	${MKDIR} -p ../../../../Bin/win32
	${LINK.cc} -o ../../../../Bin/win32/AgentControl ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/_ext/1193482173/main.o: ../../../../src/AgentControl/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1193482173
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I../../../../Contrib/boost_1_45_0 -I../../../../Contrib/glog -I../../../../Contrib/tcl -I../../../../src -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1193482173/main.o ../../../../src/AgentControl/main.cpp

${OBJECTDIR}/_ext/438060982/BFS_UTF8_CODE.o: ../../../../src/common/BFS_UTF8_CODE.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/438060982
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I../../../../Contrib/boost_1_45_0 -I../../../../Contrib/glog -I../../../../Contrib/tcl -I../../../../src -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/438060982/BFS_UTF8_CODE.o ../../../../src/common/BFS_UTF8_CODE.cpp

${OBJECTDIR}/_ext/1193482173/cProject.o: ../../../../src/AgentControl/cProject.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1193482173
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I../../../../Contrib/boost_1_45_0 -I../../../../Contrib/glog -I../../../../Contrib/tcl -I../../../../src -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1193482173/cProject.o ../../../../src/AgentControl/cProject.cpp

${OBJECTDIR}/_ext/1193482173/cCache.o: ../../../../src/AgentControl/cCache.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1193482173
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I../../../../Contrib/boost_1_45_0 -I../../../../Contrib/glog -I../../../../Contrib/tcl -I../../../../src -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1193482173/cCache.o ../../../../src/AgentControl/cCache.cpp

${OBJECTDIR}/_ext/1193482173/cBuildTree_tcl.o: ../../../../src/AgentControl/cBuildTree_tcl.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1193482173
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I../../../../Contrib/boost_1_45_0 -I../../../../Contrib/glog -I../../../../Contrib/tcl -I../../../../src -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1193482173/cBuildTree_tcl.o ../../../../src/AgentControl/cBuildTree_tcl.cpp

${OBJECTDIR}/_ext/1193482173/cCmdHandler.o: ../../../../src/AgentControl/cCmdHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1193482173
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I../../../../Contrib/boost_1_45_0 -I../../../../Contrib/glog -I../../../../Contrib/tcl -I../../../../src -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1193482173/cCmdHandler.o ../../../../src/AgentControl/cCmdHandler.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/Debug
	${RM} ../../../../Bin/win32/AgentControl.exe

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
