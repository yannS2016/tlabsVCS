#!../../bin/linux-x86_64/vcs

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

#seq ev1ClearanceSNC, "SYS=VCS"
#seq ev2ClearanceSNC, "SYS=VCS"
#seq ev3ClearanceSNC, "SYS=VCS"
#seq bsvClearanceSNC, "SYS=VCS"
#seq hliClearanceSNC, "SYS=VCS"
#seq speClearanceSNC, "SYS=VCS"
#seq vliClearanceSNC, "SYS=VCS"
#seq a13aClearanceSNC, "SYS=VCS"
#seq iblClearanceSNC, "SYS=VCS"
#seq ssccabClearanceSNC, "SYS=VCS"
#seq sscbasClearanceSNC, "SYS=VCS"
#seq expClearanceSNC, "SYS=VCS"
seq spc1gfClearanceSNC, "SYS=VCS"
seq spc1basClearanceSNC, "SYS=VCS"
#seq  sncExample ,"SYS=VCS"
#seq expClearanceSNC, "SYS=VCS" 
