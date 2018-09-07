#!../../bin/linux-x86_64/cnAioc

## You may have to change iocvcs to something else
## everywhere it appears in this file

< envPaths

cd "${TOP}"

## Register all support components
dbLoadDatabase "dbd/cnAioc.dbd"
cnAioc_registerRecordDeviceDriver pdbbase

## Load record instances
dbLoadTemplate "db/cnA.substitutions"

## Set this to see messages from mySub
#var mySubDebug 1

## Run this to trace the stages of iocInit
#traceIocInit

cd "${TOP}/iocBoot/${IOC}"
iocInit 

## Start any sequence programs
seq cnaClearanceSNC, "SYS=VCS"

