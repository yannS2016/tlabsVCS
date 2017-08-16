#!/bin/bash

#######################
# Main script
#######################
#comment this out if proxy command does not return succes
set -e   # exit if any command return with status different than 0
if [ "$(id -u)" != "0" ]; then
	echo "Your are not Root.. the scrip will auto acquire root priviledges"
	echo -n "Please confirm for auto execution as SUDO [y/n]: "
	read  autoexc
	if [ "$autoexc" = "y" ]; then
  		exec sudo "$0" "$@" #this command will execute the scrip wth root priviledes as well as all other command
	else
		echo "This script must be run as root eg 'sudo -E $0'"
 		exit 1;
	fi
fi
#######################################################################################
if [ "$#" = "2" ]; then
	if [ -e "$1" ]; then
		export InFilename=$1
	else
		echo "Input file does not exist"
		exit
	fi
	if [ -e "$2" ]; then
		export OutFilename=$2	
	else
		echo "Output file does not exist"
		exit
	fi
else
	echo "i.e: ./scriptname Infilname outFilename"
	exit
fi
########################################################################################

echo  $InFilename
echo  $OutFilename
sed 's/\"[a-zA-Z0-9]*[^[:print:]]/\"/g' $InFilename > $OutFilename
