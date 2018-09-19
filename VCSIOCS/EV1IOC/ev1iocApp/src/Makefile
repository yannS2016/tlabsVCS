TOP=../..

include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS BELOW HERE
USR_SYS_LIBS += xml2
# xxxRecord.h will be created from xxxRecord.dbd

# Build an IOC support library
LIBRARY_IOC += ev1iocSupport

# Build the IOC application
PROD_IOC = ev1ioc

# ev1ioc.dbd will be created and installed
DBD += ev1ioc.dbd

# ev1ioc.dbd will include these files:
ev1ioc_DBD += base.dbd 


# ev1ioc_registerRecordDeviceDriver.cpp derives from ev1ioc.dbd
ev1ioc_SRCS += ev1ioc_registerRecordDeviceDriver.cpp

# Build the main IOC entry point where needed
ev1ioc_SRCS_DEFAULT += ev1iocMain.cpp
ev1ioc_SRCS_vxWorks += -nil-

# Add support from base/src/vxWorks if needed
#ev1ioc_OBJS_vxWorks += $(EPICS_BASE_BIN)/vxComLibrary

# Link in the code from our support library
ev1ioc_LIBS += ev1iocSupport ecAsyn asyn 

# To build SNL programs, SNCSEQ must be defined
# in the <top>/configure/RELEASE file
ifneq ($(SNCSEQ),)
    # Build sncExample into ev1iocSupport
    ev1ClearanceSNC_SNCFLAGS += +r
    ev1ioc_DBD += ev1_snc.dbd
    ev1iocSupport_SRCS += ev1ClearanceSNC.stt 
    ev1iocSupport_LIBS += seq pv
    ev1ioc_LIBS += seq pv

    # Build sncProgram as a standalone program
    PROD_HOST += sncProgram
    sncProgram_SNCFLAGS += +m
    sncProgram_SRCS += sncProgram.st
    sncProgram_LIBS += seq pv
    sncProgram_LIBS += $(EPICS_BASE_HOST_LIBS)
endif

# Finally link IOC to the EPICS Base libraries
ev1ioc_LIBS += $(EPICS_BASE_IOC_LIBS)

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD EXTRA GNUMAKE RULES BELOW HERE

