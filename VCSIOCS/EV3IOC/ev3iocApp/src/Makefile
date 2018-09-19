TOP=../..

include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS BELOW HERE

# xxxRecord.h will be created from xxxRecord.dbd

# Build an IOC support library
LIBRARY_IOC += ev3iocSupport

# Build the IOC application
PROD_IOC = ev3ioc

# ev3ioc.dbd will be created and installed
DBD += ev3ioc.dbd

# ev3ioc.dbd will include these files:
ev3ioc_DBD += base.dbd 


# ev3ioc_registerRecordDeviceDriver.cpp derives from ev3ioc.dbd
ev3ioc_SRCS += ev3ioc_registerRecordDeviceDriver.cpp

# Build the main IOC entry point where needed
ev3ioc_SRCS_DEFAULT += ev3iocMain.cpp
ev3ioc_SRCS_vxWorks += -nil-

# Add support from base/src/vxWorks if needed
#ev3ioc_OBJS_vxWorks += $(EPICS_BASE_BIN)/vxComLibrary

# Link in the code from our support library
ev3ioc_LIBS += ev3iocSupport asyn 

# To build SNL programs, SNCSEQ must be defined
# in the <top>/configure/RELEASE file
ifneq ($(SNCSEQ),)
    # Build sncExample into ev3iocSupport
    ev3ClearanceSNC_SNCFLAGS += +r
    ev3ioc_DBD += ev3_snc.dbd
    ev3iocSupport_SRCS += ev3ClearanceSNC.stt 
    ev3iocSupport_LIBS += seq pv
    ev3ioc_LIBS += seq pv

    # Build sncProgram as a standalone program
    PROD_HOST += sncProgram
    sncProgram_SNCFLAGS += +m
    sncProgram_SRCS += sncProgram.st
    sncProgram_LIBS += seq pv
    sncProgram_LIBS += $(EPICS_BASE_HOST_LIBS)
endif

# Finally link IOC to the EPICS Base libraries
ev3ioc_LIBS += $(EPICS_BASE_IOC_LIBS)

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD EXTRA GNUMAKE RULES BELOW HERE

