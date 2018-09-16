TOP=../..

include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS BELOW HERE
#USR_SYS_LIBS += xml2
# xxxRecord.h will be created from xxxRecord.dbd

# Build an IOC support library
LIBRARY_IOC += ssciocSupport

# Build the IOC application
PROD_IOC = sscioc

# sscioc.dbd will be created and installed
DBD += sscioc.dbd

# sscioc.dbd will include these files:
sscioc_DBD += base.dbd 


# sscioc_registerRecordDeviceDriver.cpp derives from sscioc.dbd
sscioc_SRCS += sscioc_registerRecordDeviceDriver.cpp

# Build the main IOC entry point where needed
sscioc_SRCS_DEFAULT += ssciocMain.cpp
sscioc_SRCS_vxWorks += -nil-

# Add support from base/src/vxWorks if needed
#sscioc_OBJS_vxWorks += $(EPICS_BASE_BIN)/vxComLibrary

# Link in the code from our support library
sscioc_LIBS += ssciocSupport asyn 

# To build SNL programs, SNCSEQ must be defined
# in the <top>/configure/RELEASE file
ifneq ($(SNCSEQ),)
    # Build sncExample into ssciocSupport
    sscClearanceSNC_SNCFLAGS += +r
    sscioc_DBD += ssc_snc.dbd
    ssciocSupport_SRCS += ssccabClearanceSNC.stt sscbasClearanceSNC.stt
    ssciocSupport_LIBS += seq pv
    sscioc_LIBS += seq pv

    # Build sncProgram as a standalone program
    PROD_HOST += sncProgram
    sncProgram_SNCFLAGS += +m
    sncProgram_SRCS += sncProgram.st
    sncProgram_LIBS += seq pv
    sncProgram_LIBS += $(EPICS_BASE_HOST_LIBS)
endif

# Finally link IOC to the EPICS Base libraries
sscioc_LIBS += $(EPICS_BASE_IOC_LIBS)

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD EXTRA GNUMAKE RULES BELOW HERE

