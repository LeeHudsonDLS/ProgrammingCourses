TOP=../..

include $(TOP)/configure/CONFIG

# build a host application

PROD_HOST      += caExample
caExample_SRCS += caExample.c
caExample_LIBS += $(EPICS_BASE_HOST_LIBS)

# ------------------------
# Build an IOC Application
# ------------------------

PROD_IOC = basicIOCTest

# basicIOCTest.dbd will be installed into <top>/dbd
DBD += basicIOCTest.dbd

# basicIOCTest.dbd will be created from these files
basicIOCTest_DBD += base.dbd
basicIOCTest_DBD += genSubRecord.dbd
basicIOCTest_DBD += motorSupport.dbd
basicIOCTest_DBD += devSoftMotor.dbd
basicIOCTest_DBD += utilityLinux.dbd
basicIOCTest_DBD += asyn.dbd
basicIOCTest_DBD += ecAsyn.dbd
basicIOCTest_DBD += exercise7.dbd
#basicIOCTest_DBD += exercise8.dbd

# basicIOCTest_registerRecordDeviceDriver.cpp will be created
# basicIOCTest.dbd
basicIOCTest_SRCS += basicIOCTest_registerRecordDeviceDriver.cpp

# These two lines are needed for non-vxWorks builds, such as Linux
basicIOCTest_SRCS_DEFAULT += basicIOCTestMain.cpp
basicIOCTest_SRCS_vxWorks += -nil-

# Add locally compiled object code
#basicIOCTest_SRCS += exercise6.c
#basicIOCTest_SRCS += exercise7.stt
#basicIOCTest_SRCS += exercise8.c
basicIOCTest_SRCS += myRoutine.c

# The following adds object code from base/src/vxWorks
basicIOCTest_OBJS_vxWorks += $(EPICS_BASE_BIN)/vxComLibrary

# This IOC Application depends on the following support modules
basicIOCTest_LIBS += motor
basicIOCTest_LIBS += softMotor
basicIOCTest_LIBS += asyn
basicIOCTest_LIBS += genSub
basicIOCTest_LIBS += utility
basicIOCTest_LIBS += seq
basicIOCTest_LIBS += pv
basicIOCTest_LIBS += ecAsyn
basicIOCTest_LIBS += $(EPICS_BASE_IOC_LIBS)

# Sequencer flags - re-entrancy
basicIOCTest_SNCFLAGS += +r

#function(myRoutine)

include $(TOP)/configure/RULES
