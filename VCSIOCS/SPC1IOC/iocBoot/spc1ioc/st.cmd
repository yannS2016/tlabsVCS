#!../../bin/linux-x86_64/spc1ioc

## You may have to change iocvcs to something else
## everywhere it appears in this file

< envPaths

cd "${TOP}"

## Register all support components
dbLoadDatabase "dbd/spc1ioc.dbd"
spc1ioc_registerRecordDeviceDriver pdbbase

## Load record instances
#dbLoadTemplate "db/testing.substitutions"
dbLoadTemplate "db/spc1gf.substitutions"
dbLoadTemplate "db/spc1bas.substitutions"

## Set this to see messages from mySub
#var mySubDebug 1

## Run this to trace the stages of iocInit
#traceIocInit

cd "${TOP}/iocBoot/${IOC}"
iocInit

## Start any sequence programs
seq spc1gfClearanceSNC, "SYS=VCS"
seq spc1basClearanceSNC, "SYS=VCS"

