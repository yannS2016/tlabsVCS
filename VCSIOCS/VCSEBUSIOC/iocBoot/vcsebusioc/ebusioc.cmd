#!../../bin/linux-x86_64/vcsebusioc

## You may have to change iocvcs to something else
## everywhere it appears in this file

< envPaths

cd "${TOP}"

## Register all support components
dbLoadDatabase "dbd/vcsebusioc.dbd"
vcsebusioc_registerRecordDeviceDriver pdbbase

## Load record instances
ecAsynInit("/tmp/scan1", 1000000)


dbLoadTemplate "db/vcs_ebus.substitutions"


## Set this to see messages from mySub
#var mySubDebug 1

## Run this to trace the stages of iocInit
#traceIocInit

cd "${TOP}/iocBoot/${IOC}"
iocInit
#iocInit "db/resource.def"

## Start any sequence programs


