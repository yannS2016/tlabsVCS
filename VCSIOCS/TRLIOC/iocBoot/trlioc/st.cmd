#!../../bin/linux-x86_64/trlioc

## You may have to change iocvcs to something else
## everywhere it appears in this file

< envPaths

cd "${TOP}"

## Register all support components
dbLoadDatabase "dbd/trlioc.dbd"
trlioc_registerRecordDeviceDriver pdbbase

## Load record instances
dbLoadTemplate "db/trl.substitutions"

## Set this to see messages from mySub
#var mySubDebug 1

## Run this to trace the stages of iocInit
#traceIocInit

cd "${TOP}/iocBoot/${IOC}"
iocInit 

## Start any sequence programs
seq trlClearanceSNC, "SYS=VCS"

