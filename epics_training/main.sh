#! /bin/bash
####################################################
printf '%b  Main Script %b\n' "$HEADING" "$DEF_OUT"
####################################################
	set -e   # exit if any command return with status different than 0
	if [ "$(id -u)" != "0" ]; then
		echo "Your are not Root.. the scrip will auto acquire root priviledges"
		echo -n "Please confirm for auto execution as SUDO [y/n]: "
		read  autoexc
		if [ "$autoexc" = "y" ]; then
	  		exec sudo "$0" "-E $@" #this command will execute the scrip wth root priviledes as well as all other command
		else
			echo "This script must be run as root eg 'sudo -E $0'"
	 		exit 1;
		fi
	fi
	#########################################################################################
	export EPICSECAT_USER=$SUDO_USER
	export EPICSETHER_GROUP=`groups $EPICSECAT_USER | sed 's/^.*\s:\s\(\S*\)\s.*$/\1/'`
	echo $EPICSECAT_USER
	echo $EPICSETHER_GROUP
	export EPICS_ECAT_SERVER="https://github.com/dls-controls/ethercat.git"
	export EPICSECAT_PATCHES_SERVER="https://github.com/yannS2016/tlabsdevs"
	export ECAT_MASTER_SERVER="http://hg.code.sf.net/p/etherlabmaster/code"
	export ERROR="\033[31;1m"   # red output
	export HEADING="\033[32;1m" # greenoutput
	export MESSAGE="\033[33;1m" # yellow output
	export DEF_OUT="\033[0m"    # white output
	# build directory
	mkdir -p /home/$EPICSECAT_USER/training_builds
	export BUILD_ROOT=/home/$EPICSECAT_USER/training_builds
	export ROOT=$PWD
	
	## Execution start here
	cd ./build_scripts
	source welcome.sh
	exitstatus=$?
	if [ $exitstatus = 0 ]; then
     	source interactive_interface.sh
	fi
	
	