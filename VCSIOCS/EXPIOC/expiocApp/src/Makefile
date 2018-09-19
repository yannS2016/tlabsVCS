TOP=../..

include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS BELOW HERE

# xxxRecord.h will be created from xxxRecord.dbd

# Build an IOC support library
LIBRARY_IOC += expiocSupport

# Build the IOC application
PROD_IOC = expioc

# expioc.dbd will be created and installed
DBD += expioc.dbd

# expioc.dbd will include these files:
expioc_DBD += base.dbd 


# expioc_registerRecordDeviceDriver.cpp derives from expioc.dbd
expioc_SRCS += expioc_registerRecordDeviceDriver.cpp

# Build the main IOC entry point where needed
expioc_SRCS_DEFAULT += expiocMain.cpp
expioc_SRCS_vxWorks += -nil-

# Add support from base/src/vxWorks if needed
#expioc_OBJS_vxWorks += $(EPICS_BASE_BIN)/vxComLibrary

# Link in the code from our support library
expioc_LIBS += expiocSupport asyn 

# To build SNL programs, SNCSEQ must be defined
# in the <top>/configure/RELEASE file
ifneq ($(SNCSEQ),)
    # Build sncExample into expiocSupport
    expClearanceSNC_SNCFLAGS += +r
    expioc_DBD += exp_snc.dbd
    expiocSupport_SRCS += expClearanceSNC.stt 
    expiocSupport_LIBS += seq pv
    expioc_LIBS += seq pv

    # Build sncProgram as a standalone program
    PROD_HOST += sncProgram
    sncProgram_SNCFLAGS += +m
    sncProgram_SRCS += sncProgram.st
    sncProgram_LIBS += seq pv
    sncProgram_LIBS += $(EPICS_BASE_HOST_LIBS)
endif

# Finally link IOC to the EPICS Base libraries
expioc_LIBS += $(EPICS_BASE_IOC_LIBS)

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD EXTRA GNUMAKE RULES BELOW HERE

