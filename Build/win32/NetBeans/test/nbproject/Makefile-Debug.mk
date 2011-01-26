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
	${OBJECTDIR}/_ext/825861859/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-Wfatal-errors -W -Wno-ignored-qualifiers
CXXFLAGS=-Wfatal-errors -W -Wno-ignored-qualifiers

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-Debug.mk ../../../../Bin/win32/test.exe

../../../../Bin/win32/test.exe: ${OBJECTFILES}
	${MKDIR} -p ../../../../Bin/win32
	${LINK.cc} -o ../../../../Bin/win32/test ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/_ext/825861859/main.o: ../../../../src/test/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/825861859
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/825861859/main.o ../../../../src/test/main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/Debug
	${RM} ../../../../Bin/win32/test.exe

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
