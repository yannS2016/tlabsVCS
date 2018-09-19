TOP=../..

include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS BELOW HERE
USR_SYS_LIBS += xml2
# xxxRecord.h will be created from xxxRecord.dbd

# Build an IOC support library
LIBRARY_IOC += a13aiocSupport

# Build the IOC application
PROD_IOC = a13aioc

# a13aioc.dbd will be created and installed
DBD += a13aioc.dbd

# a13aioc.dbd will include these files:
a13aioc_DBD += base.dbd 


# a13aioc_registerRecordDeviceDriver.cpp derives from a13aioc.dbd
a13aioc_SRCS += a13aioc_registerRecordDeviceDriver.cpp

# Build the main IOC entry point where needed
a13aioc_SRCS_DEFAULT += a13aiocMain.cpp
a13aioc_SRCS_vxWorks += -nil-

# Add support from base/src/vxWorks if needed
#a13aioc_OBJS_vxWorks += $(EPICS_BASE_BIN)/vxComLibrary

# Link in the code from our support library
a13aioc_LIBS += a13aiocSupport ecAsyn asyn 

# To build SNL programs, SNCSEQ must be defined
# in the <top>/configure/RELEASE file
ifneq ($(SNCSEQ),)
    # Build sncExample into a13aiocSupport
    a13aClearanceSNC_SNCFLAGS += +r
    a13aioc_DBD += a13a_snc.dbd
    a13aiocSupport_SRCS += a13aClearanceSNC.stt iblClearanceSNC.stt
    a13aiocSupport_LIBS += seq pv
    a13aioc_LIBS += seq pv

    # Build sncProgram as a standalone program
    PROD_HOST += sncProgram
    sncProgram_SNCFLAGS += +m
    sncProgram_SRCS += sncProgram.st
    sncProgram_LIBS += seq pv
    sncProgram_LIBS += $(EPICS_BASE_HOST_LIBS)
endif

# Finally link IOC to the EPICS Base libraries
a13aioc_LIBS += $(EPICS_BASE_IOC_LIBS)

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD EXTRA GNUMAKE RULES BELOW HERE

