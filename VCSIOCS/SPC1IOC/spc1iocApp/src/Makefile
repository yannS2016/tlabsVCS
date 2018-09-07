TOP=../..

include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS BELOW HERE
USR_SYS_LIBS += xml2
# xxxRecord.h will be created from xxxRecord.dbd

# Build an IOC support library
LIBRARY_IOC += spc1iocSupport

# Build the IOC application
PROD_IOC = spc1ioc

# spc1ioc.dbd will be created and installed
DBD += spc1ioc.dbd

# spc1ioc.dbd will include these files:
spc1ioc_DBD += base.dbd 


# spc1ioc_registerRecordDeviceDriver.cpp derives from spc1ioc.dbd
spc1ioc_SRCS += spc1ioc_registerRecordDeviceDriver.cpp

# Build the main IOC entry point where needed
spc1ioc_SRCS_DEFAULT += spc1iocMain.cpp
spc1ioc_SRCS_vxWorks += -nil-

# Add support from base/src/vxWorks if needed
#spc1ioc_OBJS_vxWorks += $(EPICS_BASE_BIN)/vxComLibrary

# Link in the code from our support library
spc1ioc_LIBS += spc1iocSupport ecAsyn asyn 

# To build SNL programs, SNCSEQ must be defined
# in the <top>/configure/RELEASE file
ifneq ($(SNCSEQ),)
    # Build sncExample into spc1iocSupport
    spc1ClearanceSNC_SNCFLAGS += +r
    spc1ioc_DBD += spc1_snc.dbd
    spc1iocSupport_SRCS += spc1basClearanceSNC.stt spc1gfClearanceSNC.stt
    spc1iocSupport_LIBS += seq pv
    spc1ioc_LIBS += seq pv

    # Build sncProgram as a standalone program
    PROD_HOST += sncProgram
    sncProgram_SNCFLAGS += +m
    sncProgram_SRCS += sncProgram.st
    sncProgram_LIBS += seq pv
    sncProgram_LIBS += $(EPICS_BASE_HOST_LIBS)
endif

# Finally link IOC to the EPICS Base libraries
spc1ioc_LIBS += $(EPICS_BASE_IOC_LIBS)

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD EXTRA GNUMAKE RULES BELOW HERE

