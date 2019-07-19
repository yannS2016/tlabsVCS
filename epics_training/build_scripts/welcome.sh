#! /bin/bash
echo "Welcome to the interactive guide for EPICS control system\nconfiguration and installation using EtherCAT bus.\n\nYou will be required to configure your build interactively as well as patch the build sources depending on your machine architecture. for this training material,Debian jessie(8) or Debian stretch(9) will be used." > welcome_msg
whiptail --textbox  welcome_msg 15 78