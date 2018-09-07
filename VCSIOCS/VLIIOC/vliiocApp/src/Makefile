TOP=../..

include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS BELOW HERE

# xxxRecord.h will be created from xxxRecord.dbd

# Build an IOC support library
LIBRARY_IOC += vliiocSupport

# Build the IOC application
PROD_IOC = vliioc

# vliioc.dbd will be created and installed
DBD += vliioc.dbd

# vliioc.dbd will include these files:
vliioc_DBD += base.dbd 


# vliioc_registerRecordDeviceDriver.cpp derives from vliioc.dbd
vliioc_SRCS += vliioc_registerRecordDeviceDriver.cpp

# Build the main IOC entry point where needed
vliioc_SRCS_DEFAULT += vliiocMain.cpp
vliioc_SRCS_vxWorks += -nil-

# Add support from base/src/vxWorks if needed
#vliioc_OBJS_vxWorks += $(EPICS_BASE_BIN)/vxComLibrary

# Link in the code from our support library
vliioc_LIBS += vliiocSupport asyn 

# To build SNL programs, SNCSEQ must be defined
# in the <top>/configure/RELEASE file
ifneq ($(SNCSEQ),)
    # Build sncExample into vliiocSupport
    vliClearanceSNC_SNCFLAGS += +r
    vliioc_DBD += vli_snc.dbd
    vliiocSupport_SRCS += vliClearanceSNC.stt 
    vliiocSupport_LIBS += seq pv
    vliioc_LIBS += seq pv

    # Build sncProgram as a standalone program
    PROD_HOST += sncProgram
    sncProgram_SNCFLAGS += +m
    sncProgram_SRCS += sncProgram.st
    sncProgram_LIBS += seq pv
    sncProgram_LIBS += $(EPICS_BASE_HOST_LIBS)
endif

# Finally link IOC to the EPICS Base libraries
vliioc_LIBS += $(EPICS_BASE_IOC_LIBS)

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD EXTRA GNUMAKE RULES BELOW HERE

