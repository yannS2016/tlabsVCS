#! /bin/bash
query_base()
{
  if(whiptail --title "EPICS base" --yesno "Is EPICS Base already installed on your system?" 8 78); then
  		EPICS_BASE=$(whiptail --inputbox "Enter EPICS base location" 8 78 /epics/base --title "EPICS Base Location" 3>&1 1>&2 2>&3)
      exitstatus=$?
      echo $EPICS_BASE
      if [[ $exitstatus = 0 ]]; then
          echo "User selected Ok and entered " $EPICS_BASE
          while [ -z $EPICS_BASE ]; do
  			    EPICS_BASE=$(whiptail --inputbox "Enter EPICS base location" 8 78 /epics/base --title "EPICS Base Location" 3>&1 1>&2 2>&3)
            exitstatus=$?
            if [[ $exitstatus = 0 ]]; then
              echo "User selected Ok and entered " $EPICS_BASE
            else
              echo "User selected Cancel."
              break
            fi
  		    done
  		  update_build_configs "EPICS_BASE_SET" 'y'
  		  update_build_configs "EPICS_BASE" "$EPICS_BASE"
        update_build_configs "EPICS_BASE_RELEASE_SET" "y"
        update_build_configs "EPICS_BASE_RELEASE" "$(cat /epics/base/configure/$ROOT/CONFIG_BASE_VERSION | grep YES | cut -d "=" -f 1 | sed 's/BASE/Release/')"
        source $BUILD_SCRIPTS/base.sh "y" "$EPICS_BASE"
      else
          echo "User selected Cancel."
      fi
  else
    whiptail --title "EPICS BASE INSTALL LOCATION" --msgbox "EPICS base will be installed to /epics/base. You must hit OK to continue." 8 78
    exitstatus=$?
    if [[ $exitstatus = 0 ]]; then
  
        RELEASE=$(whiptail --title "EPICS Base Release" --radiolist \
        "\nSpecify the EPICS base release to be installed?\n\nHint:To use features that are only available in the latest release series then use latest release. But if fairly new to EPICS it might be better to avoid the newest releases because tutorials and/or support software such as Asyn or other driver or device support might not have been updated yet to build on that series" 20 85 7 \
        "EPICS_7_0" "(2017-present) – current release series" OFF \
        "Release_3_16" "(2016-2018) – closed" OFF \
        "Release_3_15" "(2014-present) – stable release series" ON \
        "Release_3_14" "(2002-2018) – closed" OFF \
        "Release_3_13" "(1996-2003) – closed, deep-frozen" OFF \
        "Release_3_12" "(1995) – closed, historic" OFF \
        "Release_3_11" "(1991-1994) – closed, fossilized" OFF \
        3>&1 1>&2 2>&3)
        exitstatus=$?
        if [[ $exitstatus = 0 ]]; then
          update_build_configs "EPICS_BASE_RELEASE_SET" "y"
          update_build_configs "EPICS_BASE_RELEASE" "$RELEASE"
          update_build_configs "EPICS_BASE_SET" "y"
          update_build_configs "EPICS_BASE" "/epics/base"
        fi
  
    else
      exit
    fi
    whiptail --title "EPICS BASE RELEASE" --msgbox "EPICS base $RELEASE will be installed. press Ok to continue." 8 78    
    source $BUILD_SCRIPTS/base.sh "n" "/epics/base"
  fi
}


## This method expect two argument: config name and config value
update_build_configs()
{
  ### check if the user supplied a location for EPICS base ##
  sed -i 's|^\('$1'=\)\(.*$\)|\1'$2'|'  $ROOT/CONFIG

}

query_support(){
  if(whiptail --title "EPICS Support" --yesno "Is EPICS support configure and installed ?" 8 78); then
    EPICS_SUPPORT=$(whiptail --inputbox "Enter EPICS support location" 8 78 /epics/support --title "EPICS Support Location" 3>&1 1>&2 2>&3)
    exitstatus=$?
    echo $EPICS_SUPPORT
    if [[ $exitstatus = 0 ]]; then
      while [ -z $EPICS_SUPPORT ]; do
        EPICS_SUPPORT=$(whiptail --inputbox "Enter EPICS support location" 8 78 /epics/support --title "EPICS Support Location" 3>&1 1>&2 2>&3)
        exitstatus=$?
        if [[ $exitstatus = 0 ]]; then
          echo "User selected Ok and entered " $EPICS_SUPPORT
        else
          echo "User selected Cancel."
          break
        fi
      done
      update_build_configs "EPICS_SUPPORT_SET" 'y'
      update_build_configs "EPICS_SUPPORT" "$EPICS_SUPPORT" 
      source $BUILD_SCRIPTS/support.sh "y" "$EPICS_SUPPORT"
    fi
  else
    echo "EPICS support from synapps will be installed\n\nNote: synApps is a collection of EPICS software intended to support
      most of the common requirements of an x-ray laboratory or 
      synchrotron-radiation beamline. Because it is EPICS software, 
      synApps is extensible by developers and end users, to support 
      new devices and experimental techniques\n\nModule needed: asyn, autosave, stream, CALC, std, seq.\n\n#info: https://www.aps.anl.gov/BCDA/synApps\n#info: https://epics.anl.gov/bcda/synApps/synApps.html" > $BUILD_ROOT/synapps_msg
    whiptail --textbox  $BUILD_ROOT/synapps_msg 18 78
    if [[ $exitstatus = 0 ]]; then
      update_build_configs "EPICS_SUPPORT_SET" 'y'
      update_build_configs "EPICS_SUPPORT" "/epics/support" 
      # Run the support install script here
      # step 1: Downloads synApps extract and mv support to epics
      # step 2: open up the editing interface
      # step 3: build support
      #source ./editing_interface.sh
      # display enviroment variable.
      source $BUILD_SCRIPTS/support.sh "n" "/epics/support"
      whiptail --title "EPICS environment" --msgbox "EPICS Support has been Installed under "/epics/support"
your environment has been update as below:
      $(tail -n 15 /home/$EPICSECAT_USER/.bashrc)" 22 78
    fi
  fi
}

query_drivers(){
  	INSTALLED=""
  	ETHERCAT_HOME=""
  	DRIVERS=""
  	PREEMPT_RT=""
  	if(whiptail --title "EtherCAT Drivers" --yesno "is IgH EtherCAT Master installed on your system?" 8 78); then
    	ETHERCAT_HOME=$(whiptail --inputbox "Enter the EtherCAT master drivers location" 8 78 /epics/drivers/ethercat/etherlabmaster-code --title "EtherCAT drivers Location" 3>&1 1>&2 2>&3)
    	exitstatus=$?
    	echo $ETHERCAT_HOME
    	if [[ $exitstatus = 0 ]]; then
      		while [ -z $ETHERCAT_HOME ]; do
        		ETHERCAT_HOME=$(whiptail --inputbox "Enter IgH EtherCAT Master location" 8 78 /epics/drivers/ethercat/etherlabmaster-code --title "EtherCAT drivers Location" 3>&1 1>&2 2>&3)
        		exitstatus=$?
        		if [[ $exitstatus = 0 ]]; then
          			echo "User selected Ok and entered " $ETHERCAT_HOME
        		else
          			echo "User selected Cancel."
          			break
        		fi
      		done
      	DRIVERS=$(cat $ROOT/CONFIG | grep -e "NETWORK_DRIVERS" | cut -d "=" -f 2)
      	update_build_configs "ETHERCAT_HOME_SET" 'y'
      	update_build_configs "ETHERCAT_HOME" "$ETHERCAT_HOME" 
      	update_build_configs "NETWORK_DRIVERS" "$DRIVERS" 
      	INSTALLED="y"
      	# call install script
      	source $BUILD_SCRIPTS/drivers.sh "$INSTALLED" "$ETHERCAT_HOME" "$DRIVERS"
      	sleep 4
    	fi
  	else 
  		INSTALLED="n"
    	whiptail \
    		--title "EtherCAT Master Drivers" \
     		--msgbox "IgH EtherCAT Master will be downloaded and installed under
     	/epics/drivers/ethercat/etherlabmaster-code\n\nNote: IgH EtherCAT Master for Linux is an Etherlab open source bundle enabling EtherCAT fieldbus control system under Linux distributions 
     	\nMore info: https://etherlab.org/en/ethercat/" 14 78
    	if [[ $exitstatus = 0 ]]; then
      		ETHERCAT_HOME="/epics/drivers/ethercat/etherlabmaster-code"
      		update_build_configs "ETHERCAT_HOME_SET" 'y'
      		update_build_configs "ETHERCAT_HOME" "$ETHERCAT_HOME"

      		if(whiptail --title "Network Drivers" --yesno "Are you running a PREEMPT_RT kernel?"  8 78); then 
        		DRIVERS=$(whiptail --title "Native Ethernet Drivers" --radiolist \
        		"\nSpecify the Master driver's network?\n\nHint:Natively supported drivers(these are lastly patched on kernel 3.2)\nFor more info: https://www.etherlab.org/en/ethercat/hardware.php" 18 85 7 \
        		"8139too" "RealTek 8139C (or compatible)" OFF \
        		"e1000" "Intel PRO/1000 Gigabit-Ethernet" OFF \
        		"e100" "Intel PRO/100 Fast-Ethernet chipsets" ON \
        		"r8169" "RealTek 8169/8168/8101 Gigabit-Ethernet chipsets" OFF \
        		"e1000e" "Intel PRO/1000 Gigabit-Ethernet chipsets (PCI Express)" OFF \
        		3>&1 1>&2 2>&3)
        		exitstatus=$?
        		if [[ $exitstatus = 0 ]]; then
           			update_build_configs "NETWORK_DRIVERS" "$DRIVERS" 
           			PREEMPT_RT="y"
           			update_build_configs "PREEMPT_RT" "$PREEMPT_RT"
        		fi
      		else
        		DRIVERS=$(whiptail --title "Native Ethernet Drivers" --radiolist \
        		"\nSpecify the Master Network Driver's ?\n\nNote:Since version 1.5, there is a generic Ethernet driver among the native ones,\nthat spans all Ethernet devices supported by the Linux kernel. Although it is not usable with realtime patches like RTAI (because it uses the lower network stack layers), it runs perfectly with realtime preemption\nFor more info: https://www.etherlab.org/en/ethercat/hardware.php" 20 85 6 \
        		"r8169" "RealTek 8169/8168/8101 Gigabit-Ethernet chipsets" OFF \
        		"e1000e" "Intel PRO/1000 Gigabit-Ethernet chipsets (PCI Express)" OFF \
        		"generic" "Default drivers for all Ethernet devices" ON \
        		3>&1 1>&2 2>&3) 
        		exitstatus=$? 
        		if [[ $exitstatus = 0 ]]; then
           			update_build_configs "NETWORK_DRIVERS" "$DRIVERS" 
           			PREEMPT_RT="n"
           			update_build_configs "PREEMPT_RT" "$PREEMPT_RT"
        		fi  
      		fi
      		# call install script
      		source $BUILD_SCRIPTS/drivers.sh "$INSTALLED" "$ETHERCAT_HOME" "$DRIVERS"
      		sleep 4
      		whiptail \
      		--title "Master Module configuration" \
       		--msgbox "Configure ethercat master\n
      			1) Create 99-EtherCAT.rules file for udev 
      			2) Add EtherCAT Master binary to /usr/bin
      			3) Add EtherCAT Master startup script to /etc/init.d
      			4) Add EtherCAT Master configs to /etc/sysconfig
      			5) Add EtherCAT Master Libraries to /usr/lib" 12 80
      		source $BUILD_SCRIPTS/editing_interface.sh "/etc/udev/rules.d/99-EtherCAT.rules" "$ROOT/README.md"
    	fi
			update-rc.d ethercat defaults			
			depmod	
			whiptail --title "Igh EtherCAT Master Installation Completed" --msgbox "You have successfully installed IgH EtherCAT Master\nRun this command to get started : sudo /bin/ethercat help\nRun  the following to control your master module sudo /etc/init.d/ethercat [start|stop|status]" 12 100
  		sleep  5
  	fi
}

query_epics_ethercat(){
  if(whiptail --title "EPICS EtherCAT Module" --yesno "Is Diamond EtherCAT-EPICS Module installed on your system?" 8 78); then
    EPICS_ETHERCAT=$(whiptail --inputbox "Enter EPICS EtherCAT Module location" 8 78 /epics/ethercat-4-7 --title "EPICS EtherCAT Module location" 3>&1 1>&2 2>&3)
    exitstatus=$?
    echo $EPICS_ETHERCAT
    if [[ $exitstatus = 0 ]]; then
      while [ -z $EPICS_ETHERCAT ]; do
        EPICS_ETHERCAT=$(whiptail --inputbox "Enter EPICS EtherCAT Module location" 8 78 /epics/ethercat-4-7 --title "EPICS EtherCAT Module location" 3>&1 1>&2 2>&3)
        exitstatus=$?
        if [[ $exitstatus = 0 ]]; then
          echo "User selected Ok and entered " $EPICS_ETHERCAT
        else
          echo "User selected Cancel."
          break
        fi
      done
      update_build_configs "EPICS_ETHERCAT_SET" 'y'
      update_build_configs "EPICS_ETHERCAT" "$EPICS_ETHERCAT" 
    fi
    echo -----------------------------------------------------------------------------
		printf '%b  Installing Diamond EPICS EtherCAT Master... %b\n' "$HEADING" "$DEF_OUT"
		echo -----------------------------------------------------------------------------
		cd $EPICS_ETHERCAT
		make clean
		make
		sleep 4		
  else
    echo "EPICS EtherCAT module from Diamond will be installed\n\nNote: DLS-ethercat is an EPICS support module to interface an Ethercat
bus to EPICS. It uses a scanner process that serves as a server to communicate with EPICS iocs as clients info: 
http://controls.diamond.ac.uk/downloads/support/ethercat/4-7/documentation\nPrerequisites: IgH EtherCAT Master for Linux" > $BUILD_ROOT/epics_ethercat_msg
    whiptail --textbox  $BUILD_ROOT/epics_ethercat_msg 12 80
    exitstatus=$?
    if [[ $exitstatus = 0 ]]; then
      whiptail --title "Beckhoff xml files" --msgbox "EtherCAT-EPICS modules require device configuration xml files.\n
These will be downloaded and install under /epics/ethercat-4-7/etc/xml Hint:\nwget https://download.beckhoff.com/download/Config/EtherCAT/XML_Device_Description/Beckhoff_EtherCAT_XML.zip" 10 115
    fi

    exitstatus=$?
    if [[ $exitstatus = 0 ]]; then
      # Get Diamond EtherCAT EPICS modules
      # Get Beckhoff xml
      source $BUILD_SCRIPTS/ethercat_epics.sh

      whiptail --title "update config scripts" --msgbox "Diamond EPICS EtherCAT module expand device xml as well create device tempalte for EPICS databases via a collection of python scripts under /epics/ethercat-4-7/scripts
you are require to update those scripts with your python installation details.\nyour system python binary is at: $(which python)
Script 1: /epics/ethercat-4-7/etc/scripts/expandChain.py
Script 2: /epics/ethercat-4-7/etc/scripts/maketemplate.py
Script 3: /epics/ethercat-4-7/etc/scripts/diamond_types.py" 12 90
      # call interactive scripts
      source $BUILD_SCRIPTS/editing_interface.sh "/epics/ethercat-4-7/etc/scripts/expandChain.py" "$ROOT/README.md"
    fi 
    exitstatus=$?
    if [[ $exitstatus = 0 ]]; then
      whiptail --title "update build files" --msgbox "The build files need to be updated under as follow\n
      RELEASE Makefile: /epics/ethercat-4-7/configure/
			App Makefile:     /epics/ethercat-4-7/ethercatApp
      Scanner Makefile: /epics/ethercat-4-7/scannerSrc
			Src Makefile:     /epics/ethercat-4-7/ethercatApp/src
			etc Makefile:     /epics/ethercat-4-7/etc" 14 74
			
      # call interactive scripts
      source $BUILD_SCRIPTS/editing_interface.sh "/epics/ethercat-4-7/configure/RELEASE" "$ROOT/README.md"
    fi
    exitstatus=$?
    if [[ $exitstatus = 0 ]]; then
      whiptail --title "Patching Sources" --msgbox "EtherCAT-4-7 sources need patching depending on system arch architecture
      Debian 8 user should not require any patching.
      Debian 9 and Ubuntu(from 14.04 at least) would need patching to:\n
      Source file: /epics/ethercat-4-7/ethercatApp/scannerSrc/scanner.c
      Source file: /epics/ethercat-4-7/ethercatApp/scannerSrc/parsertest.c" 12 78
      # call interactive scripts
      source $BUILD_SCRIPTS/editing_interface.sh "/epics/ethercat-4-7/ethercatApp/scannerSrc/scanner.c" "$ROOT/README.md"
      source $BUILD_SCRIPTS/editing_interface.sh "/epics/ethercat-4-7/ethercatApp/scannerSrc/parsertest.c" "$ROOT/README.md"
			echo -----------------------------------------------------------------------------
			printf '%b  Installing Diamond EPICS EtherCAT Master... %b\n' "$HEADING" "$DEF_OUT"
			echo -----------------------------------------------------------------------------
			cd /epics/ethercat-4-7
			make clean
			make
			sleep 4	
		fi
    update_build_configs "EPICS_ETHERCAT_SET" 'y'
    update_build_configs "EPICS_ETHERCAT" "/epics/ethercat-4-7"
  fi
}

init_install()
{
  ### check if the user supplied a location for EPICS base ##
  BASE_SET=$(cat $ROOT/CONFIG | grep -e "BASE_SET" | cut -d "=" -f 2)
  # step 1
  while [ $BASE_SET = "n" ]; do
    query_base
    BASE_SET=$(cat $ROOT/CONFIG | grep -e "BASE_SET" | cut -d "=" -f 2)
  done
  # step 2
  SUPPORT_SET=$(cat $ROOT/CONFIG | grep -e "SUPPORT_SET" | cut -d "=" -f 2)
  while [ $SUPPORT_SET = "n" ]; do
    query_support
    SUPPORT_SET=$(cat $ROOT/CONFIG | grep -e "SUPPORT_SET" | cut -d "=" -f 2)
  done
  #step 3
  HOME_SET=$(cat $ROOT/CONFIG | grep -e "HOME_SET" | cut -d "=" -f 2)
  while [ $HOME_SET = "n" ]; do
    query_drivers
    HOME_SET=$(cat $ROOT/CONFIG | grep -e "HOME_SET" | cut -d "=" -f 2)
  done
  #step 4
  ETHERCAT_SET=$(cat $ROOT/CONFIG | grep -e "ETHERCAT_SET" | cut -d "=" -f 2)
  while [ $ETHERCAT_SET = "n" ]; do
    query_epics_ethercat
    ETHERCAT_SET=$(cat $ROOT/CONFIG | grep -e "ETHERCAT_SET" | cut -d "=" -f 2)
  done
}

init_install