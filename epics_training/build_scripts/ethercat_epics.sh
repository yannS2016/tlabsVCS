#! /bin/bash
install_beckhoff_xml(){
  echo ----------------------------------------
  printf '%b  Installing Beckhoff devices Xml files.. %b\n' "$HEADING" "$DEF_OUT"
  echo ----------------------------------------
  apt-get update
  wget https://download.beckhoff.com/download/Config/EtherCAT/XML_Device_Description/Beckhoff_EtherCAT_XML.zip
  unzip Beckhoff_EtherCAT_XML.zip -d xml
  rm -rf Beckhoff_EtherCAT_XML.zip
}

install_ethercat_driver()
{
  echo -----------------------------------------------------------------------------
  printf '%b  Installing Diamond EPICS EtherCAT Maste... %b\n' "$HEADING" "$DEF_OUT"
  echo -----------------------------------------------------------------------------
  sleep 4
  # update master src: patch generic.c and ethernet.c 
	install_beckhoff_xml
  sleep 4
  cd /epics
  git clone https://github.com/dls-controls/ethercat.git ethercat-4-7
  cd /epics/ethercat-4-7/etc
  install_beckhoff_xml
  chmod -R 777 /epics
}
