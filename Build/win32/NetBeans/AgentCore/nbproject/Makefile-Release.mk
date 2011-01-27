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
	${OBJECTDIR}/_ext/342587783/main.o


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
LDLIBSOPTIONS=-L../../../../Contrib/LIBS/win32/boost

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-Release.mk ../../../../Bin/win32/AgentCore.exe

../../../../Bin/win32/AgentCore.exe: ${OBJECTFILES}
	${MKDIR} -p ../../../../Bin/win32
	${LINK.cc} -o ../../../../Bin/win32/AgentCore -s ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/_ext/342587783/main.o: ../../../../src/AgentCore/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/342587783
	${RM} $@.d
	$(COMPILE.cc) -O3 -Wall -I../../../../Contrib/boost_1_45_0 -I../../../../src -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/342587783/main.o ../../../../src/AgentCore/main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/Release
	${RM} ../../../../Bin/win32/AgentCore.exe

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
