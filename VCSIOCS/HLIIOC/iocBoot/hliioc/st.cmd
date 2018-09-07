#!../../bin/linux-x86_64/hliioc

## You may have to change iocvcs to something else
## everywhere it appears in this file

< envPaths

cd "${TOP}"

## Register all support components
dbLoadDatabase "dbd/hliioc.dbd"
hliioc_registerRecordDeviceDriver pdbbase

## Load record instances
dbLoadTemplate "db/hli.substitutions"

## Set this to see messages from mySub
#var mySubDebug 1

## Run this to trace the stages of iocInit
#traceIocInit

cd "${TOP}/iocBoot/${IOC}"
iocInit 

## Start any sequence programs
seq hliClearanceSNC, "SYS=VCS"
