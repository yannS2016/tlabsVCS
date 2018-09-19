TOP=../..

include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS BELOW HERE
USR_SYS_LIBS += xml2
# xxxRecord.h will be created from xxxRecord.dbd

# Build an IOC support library
LIBRARY_IOC += spc2iocSupport

# Build the IOC application
PROD_IOC = spc2ioc

# spc2ioc.dbd will be created and installed
DBD += spc2ioc.dbd

# spc2ioc.dbd will include these files:
spc2ioc_DBD += base.dbd 


# spc2ioc_registerRecordDeviceDriver.cpp derives from spc2ioc.dbd
spc2ioc_SRCS += spc2ioc_registerRecordDeviceDriver.cpp

# Build the main IOC entry point where needed
spc2ioc_SRCS_DEFAULT += spc2iocMain.cpp
spc2ioc_SRCS_vxWorks += -nil-

# Add support from base/src/vxWorks if needed
#spc2ioc_OBJS_vxWorks += $(EPICS_BASE_BIN)/vxComLibrary

# Link in the code from our support library
spc2ioc_LIBS += spc2iocSupport ecAsyn asyn 

# To build SNL programs, SNCSEQ must be defined
# in the <top>/configure/RELEASE file
ifneq ($(SNCSEQ),)
    # Build sncExample into spc2iocSupport
    spc2ClearanceSNC_SNCFLAGS += +r
    spc2ioc_DBD += spc2_snc.dbd
    spc2iocSupport_SRCS += spc2basClearanceSNC.stt spc2gfClearanceSNC.stt
    spc2iocSupport_LIBS += seq pv
    spc2ioc_LIBS += seq pv

    # Build sncProgram as a standalone program
    PROD_HOST += sncProgram
    sncProgram_SNCFLAGS += +m
    sncProgram_SRCS += sncProgram.st
    sncProgram_LIBS += seq pv
    sncProgram_LIBS += $(EPICS_BASE_HOST_LIBS)
endif

# Finally link IOC to the EPICS Base libraries
spc2ioc_LIBS += $(EPICS_BASE_IOC_LIBS)

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD EXTRA GNUMAKE RULES BELOW HERE

