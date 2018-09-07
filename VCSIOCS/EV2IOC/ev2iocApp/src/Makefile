TOP=../..

include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS BELOW HERE

# xxxRecord.h will be created from xxxRecord.dbd

# Build an IOC support library
LIBRARY_IOC += ev2iocSupport

# Build the IOC application
PROD_IOC = ev2ioc

# ev2ioc.dbd will be created and installed
DBD += ev2ioc.dbd

# ev2ioc.dbd will include these files:
ev2ioc_DBD += base.dbd 


# ev2ioc_registerRecordDeviceDriver.cpp derives from ev2ioc.dbd
ev2ioc_SRCS += ev2ioc_registerRecordDeviceDriver.cpp

# Build the main IOC entry point where needed
ev2ioc_SRCS_DEFAULT += ev2iocMain.cpp
ev2ioc_SRCS_vxWorks += -nil-

# Add support from base/src/vxWorks if needed
#ev2ioc_OBJS_vxWorks += $(EPICS_BASE_BIN)/vxComLibrary

# Link in the code from our support library
ev2ioc_LIBS += ev2iocSupport asyn 

# To build SNL programs, SNCSEQ must be defined
# in the <top>/configure/RELEASE file
ifneq ($(SNCSEQ),)
    # Build sncExample into ev2iocSupport
    ev2ClearanceSNC_SNCFLAGS += +r
    ev2ioc_DBD += ev2_snc.dbd
    ev2iocSupport_SRCS += ev2ClearanceSNC.stt 
    ev2iocSupport_LIBS += seq pv
    ev2ioc_LIBS += seq pv

    # Build sncProgram as a standalone program
    PROD_HOST += sncProgram
    sncProgram_SNCFLAGS += +m
    sncProgram_SRCS += sncProgram.st
    sncProgram_LIBS += seq pv
    sncProgram_LIBS += $(EPICS_BASE_HOST_LIBS)
endif

# Finally link IOC to the EPICS Base libraries
ev2ioc_LIBS += $(EPICS_BASE_IOC_LIBS)

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD EXTRA GNUMAKE RULES BELOW HERE

