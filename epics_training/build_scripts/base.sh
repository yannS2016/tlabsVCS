#! /bin/bash
install_dependancies(){
  	echo ----------------------------------------
  	printf '%b  Installing the required dependancies .. %b\n' "$HEADING" "$DEF_OUT"
  	echo ----------------------------------------
	apt-get update
	apt-get install git

##### Install other epics-ethercat dependancies ##########
  apt-get install dpkg-dev autoconf libtool check patch build-essential libreadline-gplv2-dev re2c libxml2-dev mercurial tmux libncurses5-dev lshw
}

install_epics_base()
{
  	echo ----------------------------------------
  	printf '%b  About to install EPICS base .. %b\n' "$HEADING" "$DEF_OUT"
  	echo ----------------------------------------
    sleep 4
  	cd $1
  	echo  "export EPICS_HOST_ARCH=linux-$(uname -m)" >>  /home/$EPICSECAT_USER/.bashrc
  	make clean
  	make -j4
    printf "%bEPICS base installation completed%b\n" "$MESSAGE" "$DEF_OUT"
  	sleep 4
}

get_epics_base()
{
  	echo -----------------------------------------------
  	printf '%b  Downloading and Preparing EPICS base .. %b\n' "$HEADING" "$DEF_OUT"
  	echo -----------------------------------------------
  	# create base <top>
	sudo mkdir /epics
	sudo chmod -R 777 /epics
  	RELEASE=$(cat $BUILD_ROOT/CONFIG | grep -e "BASE_RELEASE=" | cut -d "=" -f 2)
  	cd  /home/$EPICSECAT_USER/Downloads
  	case "$RELEASE" in
  		EPICS_7.0)
			wget https://epics.anl.gov/download/base/base-7.0.2.2.tar.gz
			sleep 3
			tar -xzvf base-7.0.2.2.tar.gz
			mv base-7.0.2.2 base
			;;
		Release_3_16)
			wget https://epics.anl.gov/download/base/base-3.16.2.tar.gz
			sleep 3
			tar -xzvf base-3.16.2.tar.gz
			mv base-3.16.2 base
			;;
		Release_3_15)
			wget https://epics.anl.gov/download/base/base-3.15.6.tar.gz
			sleep 3
			tar -xzvf base-3.15.6.tar.gz
			mv base-3.15.6 base
			;;
		Release_3_14)
			wget https://epics.anl.gov/download/base/baseR3.14.12.8.tar.gz
			sleep 3
			tar -xzvf baseR3.14.12.8.tar.gz
			mv baseR3.14.12.8 base
			;;
		Release_3_13)
			wget https://epics.anl.gov/download/base/baseR3.13.10.tar.gz
			sleep 3
			tar -xzvf baseR3.13.10.tar.gz
			mv baseR3.13.10 base
			;;
		Release_3_12)
			wget https://epics.anl.gov/download/base/baseR3.12.2.patch7.tar.gz
			sleep 3
			tar -xzvf baseR3.12.2.patch7.tar.gz
			mv baseR3.12.2.patch7 base
			;;
		Release_3_11)
			wget https://epics.anl.gov/download/base/baseR3.12.2.patch7.tar.gz
			sleep 3
			tar -xzvf baseR3.12.2.patch7.tar.gz
			mv baseR3.12.2.patch7 base
			;;
		*)
			whet https://epics.anl.gov/download/base/baseR3.14.12.8.tar.gz
			sleep 3
			tar -xzvf baseR3.14.12.8.tar.gz
			mv baseR3.14.12.8 base
			;;
	esac
	mv base /epics	
	sudo chmod -R 777 /epics
}

if [[ $1 = "y" ]]; then
	install_epics_base "$2" 
else
	install_dependancies
	sleep 5
	get_epics_base
	sleep 5
	install_epics_base "$2"	
fi
