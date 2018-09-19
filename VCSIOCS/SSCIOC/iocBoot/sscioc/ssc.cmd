#!../../bin/linux-x86_64/sscioc

## You may have to change iocvcs to something else
## everywhere it appears in this file

< envPaths

cd "${TOP}"

## Register all support components
dbLoadDatabase "dbd/sscioc.dbd"
sscioc_registerRecordDeviceDriver pdbbase

## Load record instances
dbLoadTemplate "db/basement/sscl.substitutions"
dbLoadTemplate "db/ground_floor/sscgf.substitutions"
## Set this to see messages from mySub
#var mySubDebug 1

## Run this to trace the stages of iocInit
#traceIocInit

cd "${TOP}/iocBoot/${IOC}"
iocInit

## Start any sequence programs
seq ssccabClearanceSNC, "SYS=VCS"
seq ssclClearanceSNC, "SYS=VCS"
#seq sscgfa1ClearanceSNC, "SYS=VCS"
#seq sscgfa2ClearanceSNC, "SYS=VCS"


