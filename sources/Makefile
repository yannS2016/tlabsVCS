TOP=../..

include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS BELOW HERE

# xxxRecord.h will be created from xxxRecord.dbd
#DBDINC += xxxRecord

# Install xxxSupport.dbd into <top>/dbd
#DBD += xxxSupport.dbd

# Build an IOC support library
LIBRARY_IOC += vcsSupport

# Compile and add the code to the support library
#vcsSupport_SRCS += xxxRecord.c
#vcsSupport_SRCS += devXxxSoft.c

# Link locally-provided code into the support library,
# rather than directly into the IOC application.
# This is required for Windows DLL builds.
#vcsSupport_SRCS += dbSubExample.c
#vcsSupport_SRCS += vcsHello.c
#vcsSupport_SRCS += initTrace.c

vcsSupport_LIBS += $(EPICS_BASE_IOC_LIBS)

# Build the IOC application
PROD_IOC = vcs

# vcs.dbd will be created and installed
DBD += vcs.dbd

# vcs.dbd will include these files:
vcs_DBD += base.dbd
#vcs_DBD += xxxSupport.dbd
#vcs_DBD += dbSubExample.dbd
#vcs_DBD += vcsHello.dbd
#vcs_DBD += initTrace.dbd

# vcs_registerRecordDeviceDriver.cpp derives from vcs.dbd
vcs_SRCS += vcs_registerRecordDeviceDriver.cpp

# Build the main IOC entry point where needed
vcs_SRCS_DEFAULT += vcsMain.cpp
vcs_SRCS_vxWorks += -nil-

# Add support from base/src/vxWorks if needed
#vcs_OBJS_vxWorks += $(EPICS_BASE_BIN)/vxComLibrary

# Link in the code from our support library
vcs_LIBS += vcsSupport

# To build SNL programs, SNCSEQ must be defined
# in the <top>/configure/RELEASE file
ifneq ($(SNCSEQ),)
    # Build sncExample into vcsSupport


    vcs_SNCFLAGS += +r
    vcs_DBD += vcs_snc.dbd
    vcsSupport_SRCS += ev1ClearanceSNC.stt ev2ClearanceSNC.stt  ev3ClearanceSNC.stt bsvClearanceSNC.stt  hliClearanceSNC.stt  speClearanceSNC.stt  vliClearanceSNC.stt 
    vcsSupport_SRCS += a13aClearanceSNC.stt  ssccabClearanceSNC.stt  sscbasClearanceSNC.stt iblClearanceSNC.stt  expClearanceSNC.stt  spc1gfClearanceSNC.stt  spc1basClearanceSNC.stt
    vcsSupport_SRCS += spc2basClearanceSNC.stt spc2gfClearanceSNC.stt
    vcsSupport_LIBS += seq pv
    vcs_LIBS += seq pv

    # Build sncProgram as a standalone program
    PROD_HOST += sncProgram
    sncProgram_SNCFLAGS += +m
    sncProgram_SRCS += sncProgram.st
    sncProgram_LIBS += seq pv
    sncProgram_LIBS += $(EPICS_BASE_HOST_LIBS)
endif

# Finally link IOC to the EPICS Base libraries
vcs_LIBS += $(EPICS_BASE_IOC_LIBS)

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD EXTRA GNUMAKE RULES BELOW HERE

