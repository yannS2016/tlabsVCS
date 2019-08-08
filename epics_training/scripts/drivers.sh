#! /bin/bash
install_dependancies(){
  echo ----------------------------------------
  printf '%b  Installing the required dependancies .. %b\n' "$HEADING" "$DEF_OUT"
  echo ----------------------------------------
  cd $BUILD_ROOT
  apt-get update
  #apt-get source  linux-image-$(uname -r)
  # ./configure fail: no linux source, it actually need haeder to be install( somehow the module.symvers is contained there)
  apt-get install linux-headers-$(uname -r) # module.symvers get build by installing the linux headers

##### Install other epics-ethercat dependancies ##########
  apt-get install dpkg-dev autoconf libtool check patch build-essential libreadline-gplv2-dev re2c libxml2-dev mercurial tmux libncurses5-dev lshw
  echo ----------------------------------------
  printf '%b  Getting Patches for Error and Syslog .. %b\n' "$MESSAGE" "$DEF_OUT"
  echo ----------------------------------------
  cd $BUILD_ROOT
  #wget --no-check-certificate $LIBERRORPATCH
  #wget --no-check-certificate $SYSLOGPATCH
}
## require two argument
#1: wether drivers have been built already
#2: path to drivers
#3: drivers type: genric for non RT and e1000e for RT
install_ethercat_driver()
{
  echo ------------------------------------------------------------------------------------------
  printf '%b  Installing IgH EtherCAT Master... %b\n' "$HEADING" "$DEF_OUT"
  printf '%b  NOTE: A realtime kernel must be installed on a machine before building RT-PREEMPTED driver %b\n' "$HEADING" "$DEF_OUT"
  echo -------------------------------------------------------------------------------------------
  sleep 4
  # update master src: patch generic.c and ethernet.c 
	install_dependancies

  if [ $INSTALLED = "n" ]; then
    mkdir -p /epics/drivers/ethercat
    cd /epics/drivers/ethercat
    hg clone http://hg.code.sf.net/p/etherlabmaster/code etherlabmaster-code
    cd etherlabmaster-code
    hg update stable-1.5
    chmod -R 777 /epics
    echo ----------------------------------------
    printf '%b  Applying Lib error patch .. %b\n' "$MESSAGE" "$DEF_OUT"
    echo ----------------------------------------
    patch -p1 < $BUILD_ROOT/configurable-error-suppression.patch
    sleep 5
    cd master
    echo ----------------------------------------
    printf '%b  Applying syslog patch .. %b\n' "$MESSAGE" "$DEF_OUT"
    echo ----------------------------------------
    patch -p1 < $BUILD_ROOT/avoid-syslog-spam-when-bus-loses-power.patch
    cd ../
    ./bootstrap
    sleep 3
  fi
  #printf "%bDriver's src files haved patched%b\n\n" "$MESSAGE" "$DEF_OUT"
  ##########################################	
  chmod -R 777 /epics
  cd /epics/drivers/ethercat/etherlabmaster-code
  ./configure --enable-$NETDRIVERS  --disable-8139too --prefix=$DRIVERS_PATH/sysroot
  sleep 4
  make clean
  make -j4
  make all modules
  make install
  make modules_install
  chmod -R 777 /epics
}
export INSTALLED=$1
export DRIVERS_PATH=$2
export NETDRIVERS=$3
export PREEMPTED_RT=$4
export LIBERRORPATCH="http://controls.diamond.ac.uk/downloads/support/ethercat/4-7/documentation/doxygen/configurable-error-suppression.patch"
export SYSLOGPATCH="http://controls.diamond.ac.uk/downloads/support/ethercat/4-7/documentation/doxygen/avoid-syslog-spam-when-bus-loses-power.patch"

echo "$INSTALLED $DRIVERS_PATH $NETDRIVERS" "$PREEMPTED_RT"
install_ethercat_driver


