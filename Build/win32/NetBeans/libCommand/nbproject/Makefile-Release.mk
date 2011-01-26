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
	${OBJECTDIR}/_ext/1756224175/cCommandFactory.o \
	${OBJECTDIR}/_ext/1756224175/cCommand_nv_cg.o \
	${OBJECTDIR}/_ext/1756224175/cCommand.o


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
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-Release.mk ../../../../Bin/win32/plugins/libCommand.dll

../../../../Bin/win32/plugins/libCommand.dll: ${OBJECTFILES}
	${MKDIR} -p ../../../../Bin/win32/plugins
	${LINK.cc} -shared -o ../../../../Bin/win32/plugins/libCommand.dll -s ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/_ext/1756224175/cCommandFactory.o: ../../../../src/libCommand/cCommandFactory.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1756224175
	${RM} $@.d
	$(COMPILE.cc) -O3 -Wall -I../../../../Contrib/boost_1_45_0  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1756224175/cCommandFactory.o ../../../../src/libCommand/cCommandFactory.cpp

${OBJECTDIR}/_ext/1756224175/cCommand_nv_cg.o: ../../../../src/libCommand/cCommand_nv_cg.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1756224175
	${RM} $@.d
	$(COMPILE.cc) -O3 -Wall -I../../../../Contrib/boost_1_45_0  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1756224175/cCommand_nv_cg.o ../../../../src/libCommand/cCommand_nv_cg.cpp

${OBJECTDIR}/_ext/1756224175/cCommand.o: ../../../../src/libCommand/cCommand.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1756224175
	${RM} $@.d
	$(COMPILE.cc) -O3 -Wall -I../../../../Contrib/boost_1_45_0  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1756224175/cCommand.o ../../../../src/libCommand/cCommand.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/Release
	${RM} ../../../../Bin/win32/plugins/libCommand.dll

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
