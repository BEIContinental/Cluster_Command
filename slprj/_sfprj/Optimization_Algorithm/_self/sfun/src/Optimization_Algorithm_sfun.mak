# ------------------- Required for MSVC nmake ---------------------------------
# This file should be included at the top of a MAKEFILE as follows:


!include <ntwin32.mak>

MACHINE     = Optimization_Algorithm
TARGET      = sfun
CHART_SRCS 	= c3_Optimization_Algorithm.c
MACHINE_SRC	= Optimization_Algorithm_sfun.c
MACHINE_REG = Optimization_Algorithm_sfun_registry.c
MAKEFILE    = Optimization_Algorithm_sfun.mak
MATLAB_ROOT	= C:\LegacyApp\MATLAB13a\R2013a_32bit
BUILDARGS   =

#--------------------------- Tool Specifications ------------------------------
#
#
MSVC_ROOT1 = $(MSDEVDIR:SharedIDE=vc)
MSVC_ROOT2 = $(MSVC_ROOT1:SHAREDIDE=vc)
MSVC_ROOT  = $(MSVC_ROOT2:sharedide=vc)

# Compiler tool locations, CC, LD, LIBCMD:
CC     = cl.exe
LD     = link.exe
LIBCMD = lib.exe
#------------------------------ Include/Lib Path ------------------------------

USER_INCLUDES   = 
AUX_INCLUDES   = 
ML_INCLUDES     = /I "C:\LegacyApp\MATLAB13a\R2013a_32bit\extern\include"
SL_INCLUDES     = /I "C:\LegacyApp\MATLAB13a\R2013a_32bit\simulink\include"
SF_INCLUDES     = /I "C:\LegacyApp\MATLAB13a\R2013a_32bit\stateflow\c\mex\include" /I "C:\LegacyApp\MATLAB13a\R2013a_32bit\stateflow\c\debugger\include"

COMPILER_INCLUDES = /I "$(MSVC_ROOT)\include"

THIRD_PARTY_INCLUDES   = 
INCLUDE_PATH = $(USER_INCLUDES) $(AUX_INCLUDES) $(ML_INCLUDES)\
 $(SL_INCLUDES) $(SF_INCLUDES) $(THIRD_PARTY_INCLUDES)
LIB_PATH     = "$(MSVC_ROOT)\lib"

CFLAGS = /c /Zp8 /GR /W3 /EHs /D_CRT_SECURE_NO_DEPRECATE /D_SCL_SECURE_NO_DEPRECATE /D_SECURE_SCL=0 /DMATLAB_MEX_FILE /nologo /MD 
LDFLAGS = /nologo /MANIFEST /dll /OPT:NOREF /export:mexFunction  
#----------------------------- Source Files -----------------------------------

REQ_SRCS  =  $(MACHINE_SRC) $(MACHINE_REG) $(CHART_SRCS)

USER_ABS_OBJS =

AUX_ABS_OBJS =

REQ_OBJS = $(REQ_SRCS:.cpp=.obj)
REQ_OBJS2 = $(REQ_OBJS:.c=.obj)
OBJS = $(REQ_OBJS2) $(USER_ABS_OBJS) $(AUX_ABS_OBJS)
OBJLIST_FILE = Optimization_Algorithm_sfun.mol
SFCLIB = "C:\LegacyApp\MATLAB13a\R2013a_32bit\stateflow\c\mex\lib\win32\sfc_mexmsvc80.lib" "C:\LegacyApp\MATLAB13a\R2013a_32bit\stateflow\c\debugger\lib\win32\sfc_debugmsvc80.lib" 
AUX_LNK_OBJS =     
USER_LIBS = 
LINK_MACHINE_LIBS = 
BLAS_LIBS = "C:\LegacyApp\MATLAB13a\R2013a_32bit\extern\lib\win32\microsoft\libmwblas.lib" 
THIRD_PARTY_LIBS = 

#--------------------------------- Rules --------------------------------------

MEX_FILE_NAME_WO_EXT = $(MACHINE)_$(TARGET)
MEX_FILE_NAME = $(MEX_FILE_NAME_WO_EXT).mexw32
MEX_FILE_CSF =
all : $(MEX_FILE_NAME) $(MEX_FILE_CSF)

TMWLIB = "C:\LegacyApp\MATLAB13a\R2013a_32bit\extern\lib\win32\microsoft\libmx.lib" "C:\LegacyApp\MATLAB13a\R2013a_32bit\extern\lib\win32\microsoft\libmex.lib" "C:\LegacyApp\MATLAB13a\R2013a_32bit\extern\lib\win32\microsoft\libmat.lib" "C:\LegacyApp\MATLAB13a\R2013a_32bit\extern\lib\win32\microsoft\libfixedpoint.lib" "C:\LegacyApp\MATLAB13a\R2013a_32bit\extern\lib\win32\microsoft\libut.lib" "C:\LegacyApp\MATLAB13a\R2013a_32bit\extern\lib\win32\microsoft\libmwmathutil.lib" "C:\LegacyApp\MATLAB13a\R2013a_32bit\extern\lib\win32\microsoft\libemlrt.lib" "C:\LegacyApp\MATLAB13a\R2013a_32bit\lib\win32\libippmwipt.lib" 

$(MEX_FILE_NAME) : $(MAKEFILE) $(OBJS) $(SFCLIB) $(AUX_LNK_OBJS) $(USER_LIBS) $(THIRD_PARTY_LIBS)
 @echo ### Linking ...
 $(LD) $(LDFLAGS) /OUT:$(MEX_FILE_NAME) /map:"$(MEX_FILE_NAME_WO_EXT).map"\
  $(USER_LIBS) $(SFCLIB) $(AUX_LNK_OBJS)\
  $(TMWLIB) $(LINK_MACHINE_LIBS) $(DSP_LIBS) $(BLAS_LIBS) $(THIRD_PARTY_LIBS)\
  @$(OBJLIST_FILE)
     mt -outputresource:"$(MEX_FILE_NAME);2" -manifest "$(MEX_FILE_NAME).manifest"
	@echo ### Created $@

.c.obj :
	@echo ### Compiling "$<"
	$(CC) $(CFLAGS) $(INCLUDE_PATH) "$<"

.cpp.obj :
	@echo ### Compiling "$<"
	$(CC) $(CFLAGS) $(INCLUDE_PATH) "$<"

