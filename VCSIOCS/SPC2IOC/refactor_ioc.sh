#!/bin/bash
set -e   # exit if any command return with status different than 0
export ERROR="\033[31;1m"   # red output
export HEADING="\033[32;1m" # greenoutput
export MESSAGE="\033[33;1m" # yellow output
export DEF_OUT="\033[0m"    # white output
############################################################
   printf '%b         \n\nMain script      %b\n' "$HEADING" "$DEF_OUT"
##############################################################
	#comment this out if proxy command does not return succes
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
 
echo ------------------------------------------------------------------------
printf '%b         The IOC MUST be build from this script      %b\n' "$HEADING" "$DEF_OUT"
printf '%bPatch the IOC database definition file "dbd" to add custom scan period%b\n' "$HEADING" "$DEF_OUT"
echo -------------------------------------------------------------------------
sleep 4
make clean
make
printf "%bIOC built completed%b\n\n" "$MESSAGE" "$DEF_OUT"
sleep 4
printf '%bPatching database definition file...%b\n\n' "$HEADING" "$DEF_OUT"
cd ./dbd
patch -p0 -u -b < ./spc2ioc_dbd.patch
cat spc2ioc.dbd | grep "choice(menuScan"
printf "%bIOC Patched completed%b\n\n" "$MESSAGE" "$DEF_OUT"
sleep 2 
exit 0
