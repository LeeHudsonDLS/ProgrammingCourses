#!/home/jjc62351/ProgrammingCourses/EPICS/course/basicIOCTest/ioc/bin/linux-x86_64/basicIOCTest

## You may have to change basicIOCTest to something else
## everywhere it appears in this file

cd "/home/jjc62351/ProgrammingCourses/EPICS/course/basicIOCTest/ioc"

# Load binaries on architectures that need to do so.
# VXWORKS_ONLY, LINUX_ONLY and RTEMS_ONLY are macros that resolve
# to a comment symbol on architectures that are not the current
# build architecture, so they can be used liberally to do architecture
# specific things. Alternatively, you can include an architecture
# specific file.
# Commented out VxWorks command:ld < bin/linux-x86_64/basicIOCTest.munch

## Register all support components
dbLoadDatabase("dbd/basicIOCTest.dbd")
basicIOCTest_registerRecordDeviceDriver(pdbbase)

# Connect to the EtherCAT scanner
#ecAsynInit("/tmp/scanner", 100000)

## Load record instances
#dbLoadRecords("db/test.db","user=jjc62351")
#dbLoadRecords("db/binaryIOFlat.db","user=jjc62351")
#dbLoadRecords("db/mbboTest.db","user=jjc62351")
dbLoadRecords("db/PLCStat.db","user=jjc62351")
#dbLoadRecords("db/Air.db","prefix=jjc62351, suffix="" ")

iocInit()

## Start any sequence programs
#seq &controlFilter,"user=jjc62351"
