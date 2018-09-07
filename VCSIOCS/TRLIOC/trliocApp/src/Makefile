TOP=../..

include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS BELOW HERE

# xxxRecord.h will be created from xxxRecord.dbd

# Build an IOC support library
LIBRARY_IOC += trliocSupport

# Build the IOC application
PROD_IOC = trlioc

# trlioc.dbd will be created and installed
DBD += trlioc.dbd

# trlioc.dbd will include these files:
trlioc_DBD += base.dbd 


# trlioc_registerRecordDeviceDriver.cpp derives from trlioc.dbd
trlioc_SRCS += trlioc_registerRecordDeviceDriver.cpp

# Build the main IOC entry point where needed
trlioc_SRCS_DEFAULT += trliocMain.cpp
trlioc_SRCS_vxWorks += -nil-

# Add support from base/src/vxWorks if needed
#trlioc_OBJS_vxWorks += $(EPICS_BASE_BIN)/vxComLibrary

# Link in the code from our support library
trlioc_LIBS += trliocSupport asyn 

# To build SNL programs, SNCSEQ must be defined
# in the <top>/configure/RELEASE file
ifneq ($(SNCSEQ),)
    # Build sncExample into trliocSupport
    trlClearanceSNC_SNCFLAGS += +r
    trlioc_DBD += trl_snc.dbd
    trliocSupport_SRCS += trlClearanceSNC.stt 
    trliocSupport_LIBS += seq pv
    trlioc_LIBS += seq pv

    # Build sncProgram as a standalone program
    PROD_HOST += sncProgram
    sncProgram_SNCFLAGS += +m
    sncProgram_SRCS += sncProgram.st
    sncProgram_LIBS += seq pv
    sncProgram_LIBS += $(EPICS_BASE_HOST_LIBS)
endif

# Finally link IOC to the EPICS Base libraries
trlioc_LIBS += $(EPICS_BASE_IOC_LIBS)

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD EXTRA GNUMAKE RULES BELOW HERE

