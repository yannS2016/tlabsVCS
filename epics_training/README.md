########################################
	EPICS Support Configurations 
########################################
## Change line 1 to: SUPPORT=/epics/support
## Change line 2 to: EPICS_BASE=/epics/base

## comment out all line from line 8 but these:

ASYN=$(SUPPORT)/asyn-R4-33
AUTOSAVE=$(SUPPORT)/autosave-R5-9
BUSY=$(SUPPORT)/busy-R1-7
CALC=$(SUPPORT)/calc-R3-7-1
IPAC=$(SUPPORT)/ipac-2-15
SSCAN=$(SUPPORT)/sscan-R2-11-1
STD=$(SUPPORT)/std-R3-5
STREAM=$(SUPPORT)/stream-R2-7-7c
SNCSEQ=$(SUPPORT)/seq-2-2-5

############################################################
	EtherCAT Master configurations 
############################################################
### Create udev rules file
cd /etc/udev/rules.d
sudo gedit 99-EtherCAT.rules
Add to line 1:  KERNEL==\"EtherCAT[0-9]*\", MODE=\"0664\"

##### First add device configuration in ethercat.conf ####
cd /epics/driver/ethercat/etherlabmaster-code/sysroot/etc
nano ethercat.conf

### Step 1: Add your Network card MAC address for your Master ###
## Change line 27 as to: 
## Hint: use intel card for it is known to be stable and performs well.
## Note: Find out about your network cards: run this in pane C: sudo lshw -class network
MASTER0_DEVICE="YOUR NETWORK CARD MAC ADDRESS HERE"

### Step 2: Specify what type of network driver EtherCAT Master will use ###
### Note: if you build for generic drivers enter generic otherwise choose from the list below ###
## change line 60 as below
DEVICE_MODULES="my network module"
## Save the file ethercat.conf: CTRL-x + y (for yes) ##

#### Secondly  add device configuration in file ethercat #### 
   cd driver/ethercat/etherlabmaster-code/sysroot/etc/sysconfig
   nano ethercat
### Step 1: Add your Network card MAC address for your Master ###
## Change line 27 as to: 
## Hint: use intel card for it is known to be stable and performs well.
## Note: Find out about your network cards: run this in pane C: sudo lshw -class network
MASTER0_DEVICE="YOUR NETWORK CARD MAC ADDRESS HERE"

### Step 2: Specify what type of network driver EtherCAT Master will use ###
### Note: if you build for generic drivers enter generic otherwise choose from the list below ###
## change line 60 as below
DEVICE_MODULES="my network module"
## Save the file ethercat.conf: CTRL-x + y (for yes) ##

# Copy some files
1) sudo ln -s /epics/drivers/ethercat/etherlabmaster-code/sysroot/bin/ethercat /bin/ethercat
2) sudo mkdir /etc/sysconfig/
3) sudo ln -s /epics/drivers/ethercat/etherlabmaster-code/sysroot/etc/sysconfig/ethercat /etc/sysconfig/ethercat
4) sudo ln -s /epics/drivers/ethercat/etherlabmaster-code/sysroot/lib/libethercat.so.1 /usr/lib/

######################################################
#	Configuration for Diamond EPICS EtherCAT module 
######################################################
## Update python Script to your system python path ##
## get your python binary path : run this in pane "C" : which python

## Step 1: Change line 1 in  /epics/ethercat-4-7/etc/scripts/expandChain.py to
#!/usr/bin/python 

## Step 2: Change line 1 in /epics/ethercat-4-7/etc/scripts/maketemplate.py to
#!/usr/bin/python

## Step 3: Change line 1 in /epics/ethercat-4-7/etc/scripts/diamond_types.py to
#!/usr/bin/python

############################################################## 
#		Update Module configure/RELEASE 
##############################################################
## change line 3: SUPPORT = /epics/support
## change line 4: ASYN=$(SUPPORT)/asyn-R4-33

## change line 5: BUSY=$(SUPPORT)/busy-R1-7
## change line 8:EPICS_BASE=/epics/base
###################################################
#	   Update the system Makefiles as below 
###################################################

App Makefile: /epics/ethercat-4-7/ethercatApp/Makefile
## Change line 8 to: 
#DIRS := $(DIRS) $(filter-out $(DIRS), $(wildcard protocol))

Scanner Makefile: /epics/ethercat-4-7/scannerSrc/Makefile	 
## Change line 12 to: #VERSION=1-5-2dls5

## Change line 13 to: ETHERLAB=/epics/drivers/ethercat/etherlabmaster-code

## Change line 14 to: ETHERLABPREFIX=$(ETHERLAB)/sysroot

## Change line 30 to
scanner_INCLUDES += -I$(ETHERLAB)/lib

## Change line 37 to:
serialtool_INCLUDES += -I$(ETHERLAB)/master

## Change line 40 to:
get-slave-revisions_INCLUDES += -I$(ETHERLAB)/master

src Makefile: ethercat-4-7/ethercatApp/src/Makefile

## change line 10: #VERSION=1-5-2dls7
## change line 11 to: ETHERLAB=/epics/drivers/ethercat/etherlabmaster-code

## change line 15 to:
ecAsyn_INCLUDES += -I$(ETHERLAB)/include

## change line 16:
gadc_INCLUDES += -I$(ETHERLAB)/include

etc Makefile: ethercat-4-7/etc/Makefile
## change line 3 to: #DIRS := $(DIRS) makeDocumentation

#################################################
#	Update Scanner sources
# Note: this is only required on Debian 9 
#################################################
Source file: /epics/ethercat-4-7/ethercatApp/scannerSrc/scanner.c
## Steps
# replace all instance of FALSE to false 
# replace all instance of TRUE to true
# Press Ctrl+\: type the FALSE press Enter;
# key in  the replacement string; press Enter;
# press shift+ a ( for all instance replacement)
repeat the steps above for the next file
Source file: /epics/ethercat-4-7/ethercatApp/scannerSrc/parsertest.c

####################################
# Building an example IOC
####################################

############################################################## 
#		Update iocDemo configure/RELEASE 
# Specify dependency  module location
##############################################################
## add this after line 28: SUPPORT=/epics/support
## change line 25: SNCSEQ=$(SUPPORT)/seq-2-2-5
## change line 28: ECASYN=/epics/ethercat-4-7
## change line 29: EPICS_BASE=/epics/base
## change line 33: ASYN=$(SUPPORT)/asyn-R4-33
## add after line 33: CALC=$(SUPPORT)/calc-R3-7-1
## add after line 34: STD=$(SUPPORT)/std-R3-5
## add after line 35: STREAM=$(SUPPORT)/stream-R2-7-7c
## add after line 36: AUTOSAVE=$(SUPPORT)/autosave-R5-9

#######################################################################
# 				Creating slave chain
#######################################################################

1) Check all slaves present
  sudo ./ethercat -m 0 slaves
2) Put all slaves into OP mode
  sudo ./ethercat -m 0 states OP
3) Generate new chain.xml and scanner.xml

	### Get a example ioc from: /epics/ethercat-4-7/iocs ###
	3.1)mkdir  -p /epics/training
			cp -r /epics/ethercat-4-7/iocs/scanTest  /epics/training/iocDemo 
   		rename files accordingly:
   		find ./ -execdir rename 's/scantest/iocdemo/' '{}' \+
   		find ./ -type f  -exec sed -i 's/scantest/iocdemo/g' {} +;

	3.2) Browse to /epics/training/iocDemo/etc folder
  		cd /epics/ethercat-4-7/iocs/iocDemo/etc/
	3.3) Generate new chain.xml file and check it
			cp ~/trainig_builds/slaves_types.txt ./
  		sudo ../../../ethercat-4-7/bin/linux-x86_64/slaveinfo -s slave_types.txt > chain.xml
  		cat chain.xml
	3.4) Edit Makefile
  		sudo nano Makefile
			comment out line 7
			change line 10 as : -rm scanner.xml 
			save the file
	3.6) Run make and check new scanner.xml
  		make
  		cat scanner.xml
	3.7) comment out line 4: #DIRS := $(DIRS) $(filter-out $(DIRS), etc)
#################################################
# Generating a new template files for your slaves
#################################################
1) Check revision number of module
  sudo ethercat -m 0 -p 4 slaves -v
2) Generate new template
	Browse to scripts folder
  /epics/ethercat-4-7/etc/scripts/
3) Generate template using maketemplate.py file, sample command:
  ./maketemplate.py -b ../xml -d EK1100 -r 0x00120000 -o ../../db/EK1100.template
	./maketemplate.py -b ../xml -d EL2008 -r 0x00120000 -o ../../db/EL2008.template
	./maketemplate.py -b ../xml -d EL1808 -r 0x00120000 -o ../../db/EL1808.template
	./maketemplate.py -b ../xml -d EL3104 -r 0x00140000 -o ../../db/EL3104.template
	./maketemplate.py -b ../xml -d EL4004 -r 0x00140000 -o ../../db/EL4004.template

#################################################
# Updating startup scripts
#################################################
## create scanner script:
cd iocDemo
echo "/epics/ethercat-4-7/bin/linux-x86_64/scanner -m 0 -q /epics/training/iocDemo/etc/scanner.xml "/tmp/scan1" > start_scanner.sh
sudo chmod -R 777 /epics
## update startup script:
change line 1: to #!bin/linux-x86_64/iocdemo
## replace "#" with your host number
dbLoadRecords("../../ethercat-4-7/db/MASTER.template", "DEVICE=ETG#:MASTER:0,PORT=MASTER0,SCAN=I/O Intr")
dbLoadRecords("../../ethercat-4-7/db/EK1100.template", "DEVICE=ETG#:COUPLER,PORT=ERIO.0,SCAN=I/O Intr")
dbLoadRecords("../../ethercat-4-7/db/EL2008.template", "DEVICE=ETG#:DOM,PORT=ERIO.1,SCAN=I/O Intr")
dbLoadRecords("../../ethercat-4-7/db/EL1808.template", "DEVICE=ETG#:DIM,PORT=ERIO.2,SCAN=I/O Intr")
dbLoadRecords("../../ethercat-4-7/db/EL3104.template", "DEVICE=ETG#:AIM,PORT=ERIO.3,SCAN=I/O Intr")
dbLoadRecords("../../ethercat-4-7/db/EL4004.template", "DEVICE=ETG#:AOM,PORT=ERIO.4,SCAN=I/O Intr")

sudo chmod -R 777 /epics

IMPORTANT: WHEN DONE CONFIGURING BOTH FILES, NAVIGATE TO PANE C
# close the file: CTRL-x + n(no changes must be save) 
# enter: exit, this will take you to pane A
# enter: exit, this will take you to pane B
#enter : exit, this will close the tmux context

### Navigation under tmux ###

# ---------------------------------------------------------
#|	   pane A		|       pane B		   |
#|  Edit your conf files here	| Help is display here     |
#|  CTRL-b + right --> pane B	| CTRL-b + left --> pane A |
#|  CTRL-b + down --> pane C	| CTRL-b + down --> pane C |
#----------------------------------------------------------
#|	                     Pane C                        |
#|			Navigation info			   |
#|               CTRL-B + arrow up --> pane A		   |
# ---------------------------------------------------------

