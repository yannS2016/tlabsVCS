TOP=../..

include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS BELOW HERE

# xxxRecord.h will be created from xxxRecord.dbd
#DBDINC += xxxRecord

# Install xxxSupport.dbd into <top>/dbd
#DBD += xxxSupport.dbd

# Build an IOC support library
LIBRARY_IOC += iocvcsSupport

# Compile and add the code to the support library
#iocvcsSupport_SRCS += xxxRecord.c
#iocvcsSupport_SRCS += devXxxSoft.c

# Link locally-provided code into the support library,
# rather than directly into the IOC application.
# This is required for Windows DLL builds.
#iocvcsSupport_SRCS += dbSubExample.c
#iocvcsSupport_SRCS += iocvcsHello.c
#iocvcsSupport_SRCS += initTrace.c

iocvcsSupport_LIBS += $(EPICS_BASE_IOC_LIBS)

# Build the IOC application
PROD_IOC = iocvcs

# iocvcs.dbd will be created and installed
#DBD += iocvcs.dbd no need to update it

# iocvcs.dbd will include these files:
iocvcs_DBD += base.dbd
#iocvcs_DBD += xxxSupport.dbd
#iocvcs_DBD += dbSubExample.dbd
#iocvcs_DBD += iocvcsHello.dbd
#iocvcs_DBD += initTrace.dbd

# iocvcs_registerRecordDeviceDriver.cpp derives from iocvcs.dbd
iocvcs_SRCS += iocvcs_registerRecordDeviceDriver.cpp

# Build the main IOC entry point where needed
iocvcs_SRCS_DEFAULT += iocvcsMain.cpp
iocvcs_SRCS_vxWorks += -nil-

# Add support from base/src/vxWorks if needed
#iocvcs_OBJS_vxWorks += $(EPICS_BASE_BIN)/vxComLibrary

# Link in the code from our support library
iocvcs_LIBS += iocvcsSupport

# To build SNL programs, SNCSEQ must be defined
# in the <top>/configure/RELEASE file
ifneq ($(SNCSEQ),)
    # Build sncExample into iocvcsSupport


    iocvcs_SNCFLAGS += +r
    iocvcs_DBD += iocvcs_snc.dbd
    iocvcsSupport_SRCS += ev1ClearanceSNC.stt ev2ClearanceSNC.stt  ev3ClearanceSNC.stt bsvClearanceSNC.stt  hliClearanceSNC.stt  speClearanceSNC.stt  vliClearanceSNC.stt 
    iocvcsSupport_SRCS += a13aClearanceSNC.stt  ssccabClearanceSNC.stt  sscbasClearanceSNC.stt iblClearanceSNC.stt  expClearanceSNC.stt  spc1gfClearanceSNC.stt  spc1basClearanceSNC.stt
    iocvcsSupport_SRCS += spc2basClearanceSNC.stt spc2gfClearanceSNC.stt trlClearanceSNC.stt sscgfa1ClearanceSNC.stt  sscgfa2ClearanceSNC.stt cnaClearanceSNC.stt
    iocvcsSupport_LIBS += seq pv
    iocvcs_LIBS += seq pv

    # Build sncProgram as a standalone program
    #PROD_HOST += sncProgram
    #sncProgram_SNCFLAGS += +m
    #sncProgram_SRCS += sncProgram.st
    #sncProgram_LIBS += seq pv
    sncProgram_LIBS += $(EPICS_BASE_HOST_LIBS)
endif

# Finally link IOC to the EPICS Base libraries
iocvcs_LIBS += $(EPICS_BASE_IOC_LIBS)

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD EXTRA GNUMAKE RULES BELOW HERE

