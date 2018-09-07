TOP=../..

include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS BELOW HERE
USR_SYS_LIBS += xml2
# xxxRecord.h will be created from xxxRecord.dbd

# Build an IOC support library
LIBRARY_IOC += vcsebusiocSupport

# Build the IOC application
PROD_IOC = vcsebusioc

# vcsebusioc.dbd will be created and installed
DBD += vcsebusioc.dbd

# vcsebusioc.dbd will include these files:
vcsebusioc_DBD += base.dbd ecAsyn.dbd asSupport.dbd


# vcsebusioc_registerRecordDeviceDriver.cpp derives from vcsebusioc.dbd
vcsebusioc_SRCS += vcsebusioc_registerRecordDeviceDriver.cpp

# Build the main IOC entry point where needed
vcsebusioc_SRCS_DEFAULT += vcsebusiocMain.cpp
vcsebusioc_SRCS_vxWorks += -nil-

# Add support from base/src/vxWorks if needed
#vcsebusioc_OBJS_vxWorks += $(EPICS_BASE_BIN)/vxComLibrary

# Link in the code from our support library
vcsebusioc_LIBS += vcsebusiocSupport ecAsyn asyn autosave scannerlib rtutils

# To build SNL programs, SNCSEQ must be defined
# in the <top>/configure/RELEASE file
ifneq ($(SNCSEQ),)
    # Build sncExample into vcsebusiocSupport
    sncExample_SNCFLAGS += +r
    vcsebusioc_DBD += sncExample.dbd
    vcsebusiocSupport_SRCS += sncExample.stt
    vcsebusiocSupport_LIBS += seq pv
    vcsebusioc_LIBS += seq pv

    # Build sncProgram as a standalone program
    PROD_HOST += sncProgram
    sncProgram_SNCFLAGS += +m
    sncProgram_SRCS += sncProgram.st
    sncProgram_LIBS += seq pv
    sncProgram_LIBS += $(EPICS_BASE_HOST_LIBS)
endif

# Finally link IOC to the EPICS Base libraries
vcsebusioc_LIBS += $(EPICS_BASE_IOC_LIBS)

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD EXTRA GNUMAKE RULES BELOW HERE

