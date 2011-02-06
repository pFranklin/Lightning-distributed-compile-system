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
	${OBJECTDIR}/_ext/342587783/main.o \
	${OBJECTDIR}/_ext/438060982/BFS_UTF8_CODE.o \
	${OBJECTDIR}/_ext/342587783/cCache.o \
	${OBJECTDIR}/_ext/342587783/cProject.o


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
LDLIBSOPTIONS=-L../../../../Contrib/LIBS/win32/boost -L../../../../Contrib/LIBS/win32/gflags -L../../../../Contrib/LIBS/win32/glog -lboost_filesystem -lboost_serialization -lboost_system -lgflags -lglog

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-Debug.mk ../../../../Bin/win32/AgentCore.exe

../../../../Bin/win32/AgentCore.exe: ${OBJECTFILES}
	${MKDIR} -p ../../../../Bin/win32
	${LINK.cc} -o ../../../../Bin/win32/AgentCore ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/_ext/342587783/main.o: ../../../../src/AgentCore/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/342587783
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I../../../../Contrib/boost_1_45_0 -I../../../../Contrib/gflags -I../../../../Contrib/glog -I../../../../src -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/342587783/main.o ../../../../src/AgentCore/main.cpp

${OBJECTDIR}/_ext/438060982/BFS_UTF8_CODE.o: ../../../../src/common/BFS_UTF8_CODE.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/438060982
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I../../../../Contrib/boost_1_45_0 -I../../../../Contrib/gflags -I../../../../Contrib/glog -I../../../../src -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/438060982/BFS_UTF8_CODE.o ../../../../src/common/BFS_UTF8_CODE.cpp

${OBJECTDIR}/_ext/342587783/cCache.o: ../../../../src/AgentCore/cCache.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/342587783
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I../../../../Contrib/boost_1_45_0 -I../../../../Contrib/gflags -I../../../../Contrib/glog -I../../../../src -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/342587783/cCache.o ../../../../src/AgentCore/cCache.cpp

${OBJECTDIR}/_ext/342587783/cProject.o: ../../../../src/AgentCore/cProject.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/342587783
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I../../../../Contrib/boost_1_45_0 -I../../../../Contrib/gflags -I../../../../Contrib/glog -I../../../../src -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/342587783/cProject.o ../../../../src/AgentCore/cProject.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/Debug
	${RM} ../../../../Bin/win32/AgentCore.exe

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
