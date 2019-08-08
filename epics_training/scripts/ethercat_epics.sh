#! /bin/bash
install_beckhoff_xml(){
  echo ----------------------------------------
  printf '%b  Installing Beckhoff devices Xml files.. %b\n' "$HEADING" "$DEF_OUT"
  echo ----------------------------------------
  apt-get update
  wget https://download.beckhoff.com/download/Config/EtherCAT/XML_Device_Description/Beckhoff_EtherCAT_XML.zip
  unzip -l Beckhoff_EtherCAT_XML.zip -d xml
  rm  Beckhoff_EtherCAT_XML.zip
}

install_ethercat_driver()
{
  echo -----------------------------------------------------------------------------
  printf '%b  Downloading and Configuring Diamond EPICS EtherCAT Master... %b\n' "$HEADING" "$DEF_OUT"
  echo -----------------------------------------------------------------------------
  sleep 4
  # update master src: patch generic.c and ethernet.c 

  sleep 4
  cd /epics
  git clone https://github.com/dls-controls/ethercat.git ethercat-4-7
  cd /epics/ethercat-4-7/etc
  install_beckhoff_xml
  chmod -R 777 /epics
}

install_ethercat_driver
