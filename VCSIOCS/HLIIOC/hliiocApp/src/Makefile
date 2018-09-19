TOP=../..

include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS BELOW HERE

# xxxRecord.h will be created from xxxRecord.dbd

# Build an IOC support library
LIBRARY_IOC += hliiocSupport

# Build the IOC application
PROD_IOC = hliioc

# hliioc.dbd will be created and installed
DBD += hliioc.dbd

# hliioc.dbd will include these files:
hliioc_DBD += base.dbd 


# hliioc_registerRecordDeviceDriver.cpp derives from hliioc.dbd
hliioc_SRCS += hliioc_registerRecordDeviceDriver.cpp

# Build the main IOC entry point where needed
hliioc_SRCS_DEFAULT += hliiocMain.cpp
hliioc_SRCS_vxWorks += -nil-

# Add support from base/src/vxWorks if needed
#hliioc_OBJS_vxWorks += $(EPICS_BASE_BIN)/vxComLibrary

# Link in the code from our support library
hliioc_LIBS += hliiocSupport asyn 

# To build SNL programs, SNCSEQ must be defined
# in the <top>/configure/RELEASE file
ifneq ($(SNCSEQ),)
    # Build sncExample into hliiocSupport
    hliClearanceSNC_SNCFLAGS += +r
    hliioc_DBD += hli_snc.dbd
    hliiocSupport_SRCS += hliClearanceSNC.stt 
    hliiocSupport_LIBS += seq pv
    hliioc_LIBS += seq pv

    # Build sncProgram as a standalone program
    PROD_HOST += sncProgram
    sncProgram_SNCFLAGS += +m
    sncProgram_SRCS += sncProgram.st
    sncProgram_LIBS += seq pv
    sncProgram_LIBS += $(EPICS_BASE_HOST_LIBS)
endif

# Finally link IOC to the EPICS Base libraries
hliioc_LIBS += $(EPICS_BASE_IOC_LIBS)

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD EXTRA GNUMAKE RULES BELOW HERE

