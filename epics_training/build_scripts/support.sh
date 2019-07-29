#! /bin/bash
install_support()
{
  	echo --------------------------------------------
  	printf '%b  About to install support from synApps .. %b\n' "$HEADING" "$DEF_OUT"
  	echo --------------------------------------------
    sleep 4
  	cd $1
  	#make release
  	#make clean
  	#make -j4
    printf "%bEPICS support installation completed%b\n" "$MESSAGE" "$DEF_OUT"
  	sleep 4
  	echo "export EPICS_HOST_ARCH=linux-$(uname -m)
export EPICS_ROOT=/epics
export EPICS_BASE=/epics/base
export EPICS_BASE_LIB=/epics/base/lib/linux-$(uname -m)
export EPICS_BASE_BIN=/epics/base/bin/linux-$(uname -m)

if [ "" = "\$LD_LIBRARY_PATH" ]; then
    export LD_LIBRARY_PATH=\$EPICS_BASE_LIB
else
        export LD_LIBRARY_PATH=\$EPICS_BASE_LIB:\$LD_LIBRARY_PATH
fi

export PATH=\$PATH:\$EPICS_BASE_BIN" >> /home/$EPICSECAT_USER/.bashrc
}

get_support()
{
  echo -----------------------------------------------
  printf '%b  Downloading EPICS support .. %b\n' "$HEADING" "$DEF_OUT"
  echo -----------------------------------------------
  # create base <top>
  cd  $BUILD_ROOT
	#wget https://epics.anl.gov/bcda/synApps/tar/synApps_6_0.tar.gz
	#tar -xzvf synApps_6_0.tar.gz
	#mv synApps/support /epics	
	sudo chmod -R 777 /epics
}

configure_support()
{
  	echo -----------------------------------------------
  	printf '%b  Configuring EPICS support .. %b\n' "$HEADING" "$DEF_OUT"
  	echo -----------------------------------------------
  	# two arguments:
  	# $1: path to file to edit
  	# $2: README file
  	cd  $ROOT/build_scripts
  	source editing_interface.sh "$SUPPORT/configure/RELEASE" "../README"
}
export SUPPORT="$2"
if [[ $1 = "y" ]]; then
	install_support "$SUPPORT" 
else
	get_support
	sleep 5
	configure_support 
	sleep 3
	install_support "$SUPPORT"	
fi