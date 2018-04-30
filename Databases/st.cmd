#!../../bin/linux-x86/vcs

## You may have to change vcs to something else
## everywhere it appears in this file

< envPaths

cd "${TOP}"

## Register all support components
dbLoadDatabase "dbd/vcs.dbd"
vcs_registerRecordDeviceDriver pdbbase

## Load record instances
dbLoadTemplate "db/vcs.substitutions"



## Set this to see messages from mySub
#var mySubDebug 1

## Run this to trace the stages of iocInit
#traceIocInit

cd "${TOP}/iocBoot/${IOC}"
iocInit

## Start any sequence programs

seq spc1gfClearanceSNC, "SYS=VCS"
seq spc1basClearanceSNC, "SYS=VCS"

seq ssccabClearanceSNC, "SYS=VCS"
seq sscbasClearanceSNC, "SYS=VCS"
seq sscgfa1ClearanceSNC, "SYS=VCS"
seq sscgfa2ClearanceSNC, "SYS=VCS"
seq a13aClearanceSNC, "SYS=VCS"
seq iblClearanceSNC, "SYS=VCS"

seq expClearanceSNC, "SYS=VCS"
seq ev1ClearanceSNC, "SYS=VCS"
seq ev2ClearanceSNC, "SYS=VCS"
seq ev3ClearanceSNC, "SYS=VCS"

seq speClearanceSNC, "SYS=VCS"
seq bsvClearanceSNC, "SYS=VCS"
seq cnaClearanceSNC, "SYS=VCS"

seq spc2basClearanceSNC, "SYS=VCS"
seq spc2gfClearanceSNC, "SYS=VCS"

seq hliClearanceSNC, "SYS=VCS"
seq vliClearanceSNC, "SYS=VCS"
seq trlClearanceSNC, "SYS=VCS"

