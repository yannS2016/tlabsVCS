TOP=../..

include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS BELOW HERE

# xxxRecord.h will be created from xxxRecord.dbd

# Build an IOC support library
LIBRARY_IOC += speiocSupport

# Build the IOC application
PROD_IOC = speioc

# speioc.dbd will be created and installed
DBD += speioc.dbd

# speioc.dbd will include these files:
speioc_DBD += base.dbd 


# speioc_registerRecordDeviceDriver.cpp derives from speioc.dbd
speioc_SRCS += speioc_registerRecordDeviceDriver.cpp

# Build the main IOC entry point where needed
speioc_SRCS_DEFAULT += speiocMain.cpp
speioc_SRCS_vxWorks += -nil-

# Add support from base/src/vxWorks if needed
#speioc_OBJS_vxWorks += $(EPICS_BASE_BIN)/vxComLibrary

# Link in the code from our support library
speioc_LIBS += speiocSupport asyn 

# To build SNL programs, SNCSEQ must be defined
# in the <top>/configure/RELEASE file
ifneq ($(SNCSEQ),)
    # Build sncExample into speiocSupport
    speClearanceSNC_SNCFLAGS += +r
    speioc_DBD += spe_snc.dbd
    speiocSupport_SRCS += speClearanceSNC.stt 
    speiocSupport_LIBS += seq pv
    speioc_LIBS += seq pv

    # Build sncProgram as a standalone program
    PROD_HOST += sncProgram
    sncProgram_SNCFLAGS += +m
    sncProgram_SRCS += sncProgram.st
    sncProgram_LIBS += seq pv
    sncProgram_LIBS += $(EPICS_BASE_HOST_LIBS)
endif

# Finally link IOC to the EPICS Base libraries
speioc_LIBS += $(EPICS_BASE_IOC_LIBS)

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD EXTRA GNUMAKE RULES BELOW HERE

