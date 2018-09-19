#!../../bin/linux-x86_64/spc2ioc

## You may have to change iocvcs to something else
## everywhere it appears in this file

< envPaths

cd "${TOP}"

## Register all support components
dbLoadDatabase "dbd/spc2ioc.dbd"
spc2ioc_registerRecordDeviceDriver pdbbase

## Load record instances
dbLoadTemplate "db/spc2bas.substitutions"
dbLoadTemplate "db/spc2gf.substitutions"

## Set this to see messages from mySub
#var mySubDebug 1

## Run this to trace the stages of iocInit
#traceIocInit

cd "${TOP}/iocBoot/${IOC}"
iocInit

## Start any sequence programs
seq spc2basClearanceSNC, "SYS=VCS"
seq spc2gfClearanceSNC, "SYS=VCS"
