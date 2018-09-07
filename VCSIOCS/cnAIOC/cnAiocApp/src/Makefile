TOP=../..

include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS BELOW HERE

# xxxRecord.h will be created from xxxRecord.dbd

# Build an IOC support library
LIBRARY_IOC += cnAiocSupport

# Build the IOC application
PROD_IOC = cnAioc

# cnAioc.dbd will be created and installed
DBD += cnAioc.dbd

# cnAioc.dbd will include these files:
cnAioc_DBD += base.dbd 


# cnAioc_registerRecordDeviceDriver.cpp derives from cnAioc.dbd
cnAioc_SRCS += cnAioc_registerRecordDeviceDriver.cpp

# Build the main IOC entry point where needed
cnAioc_SRCS_DEFAULT += cnAiocMain.cpp
cnAioc_SRCS_vxWorks += -nil-

# Add support from base/src/vxWorks if needed
#cnAioc_OBJS_vxWorks += $(EPICS_BASE_BIN)/vxComLibrary

# Link in the code from our support library
cnAioc_LIBS += cnAiocSupport asyn 

# To build SNL programs, SNCSEQ must be defined
# in the <top>/configure/RELEASE file
ifneq ($(SNCSEQ),)
    # Build sncExample into cnAiocSupport
    cnAClearanceSNC_SNCFLAGS += +r
    cnAioc_DBD += cnA_snc.dbd
    cnAiocSupport_SRCS += cnaClearanceSNC.stt 
    cnAiocSupport_LIBS += seq pv
    cnAioc_LIBS += seq pv

    # Build sncProgram as a standalone program
    PROD_HOST += sncProgram
    sncProgram_SNCFLAGS += +m
    sncProgram_SRCS += sncProgram.st
    sncProgram_LIBS += seq pv
    sncProgram_LIBS += $(EPICS_BASE_HOST_LIBS)
endif

# Finally link IOC to the EPICS Base libraries
cnAioc_LIBS += $(EPICS_BASE_IOC_LIBS)

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD EXTRA GNUMAKE RULES BELOW HERE

