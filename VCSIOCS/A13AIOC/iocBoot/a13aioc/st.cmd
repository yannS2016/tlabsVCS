#!../../bin/linux-x86_64/a13aioc

## You may have to change iocvcs to something else
## everywhere it appears in this file

< envPaths

cd "${TOP}"

## Register all support components
dbLoadDatabase "dbd/a13aioc.dbd"
a13aioc_registerRecordDeviceDriver pdbbase

## Load record instances
dbLoadTemplate "db/a13a.substitutions"
dbLoadTemplate "db/ibl.substitutions"

## Set this to see messages from mySub
#var mySubDebug 1

## Run this to trace the stages of iocInit
#traceIocInit

cd "${TOP}/iocBoot/${IOC}"
iocInit

## Start any sequence programs
seq a13aClearanceSNC, "SYS=VCS"
seq iblClearanceSNC, "SYS=VCS"
