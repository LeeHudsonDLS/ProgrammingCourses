TOP=../..

include $(TOP)/configure/CONFIG

# build a host application

PROD_HOST      += caExample
caExample_SRCS += caExample.c
caExample_LIBS += $(EPICS_BASE_HOST_LIBS)

# ------------------------
# Build an IOC Application
# ------------------------

PROD_IOC = exercise

# exercise.dbd will be installed into <top>/dbd
DBD += exercise.dbd

# exercise.dbd will be created from these files
exercise_DBD += base.dbd
exercise_DBD += genSubRecord.dbd
exercise_DBD += motorSupport.dbd
exercise_DBD += devSoftMotor.dbd
exercise_DBD += utilityLinux.dbd
exercise_DBD += asyn.dbd
exercise_DBD += ecAsyn.dbd
exercise_DBD += drvAsynIPPort.dbd
exercise_DBD += pmacAsynMotor.dbd
exercise_DBD += pmacAsynIPPort.dbd
#exercise_DBD += exercise6.dbd
#exercise_DBD += exercise7.dbd
#exercise_DBD += exercise8.dbd

# exercise_registerRecordDeviceDriver.cpp will be created
# exercise.dbd
exercise_SRCS += exercise_registerRecordDeviceDriver.cpp

# These two lines are needed for non-vxWorks builds, such as Linux
exercise_SRCS_DEFAULT += exerciseMain.cpp
exercise_SRCS_vxWorks += -nil-

# Add locally compiled object code
#exercise_SRCS += exercise6.c
#exercise_SRCS += exercise7.stt
#exercise_SRCS += exercise8.c

# The following adds object code from base/src/vxWorks
exercise_OBJS_vxWorks += $(EPICS_BASE_BIN)/vxComLibrary

# This IOC Application depends on the following support modules
exercise_LIBS += motor
exercise_LIBS += softMotor
exercise_LIBS += asyn
exercise_LIBS += genSub
exercise_LIBS += utility
exercise_LIBS += seq
exercise_LIBS += pv
exercise_LIBS += ecAsyn
exercise_LIBS += pmacAsynMotor
exercise_LIBS += pmacAsynIPPort

exercise_LIBS += $(EPICS_BASE_IOC_LIBS)

# Sequencer flags - re-entrancy
exercise_SNCFLAGS += +r

include $(TOP)/configure/RULES
