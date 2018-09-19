#!/bin/bash

### BEGIN INIT INFO
# provides:          startvbtsiocpt100
# Required-Start:    ethercat
# Required-Stop:     ethercat
# Default-Start:     3 5
# Default-Stop:      0 1 2 6
# Short-Description: Manager script for epics and ethercat services
# Description:       epics-EtherCat starting script
### END INIT INFO


case "$1" in
  start)
    /etc/init.d/ethercat start
    echo "ethercat started "
    sleep 2
    cd /epics/ethercat-4-3/iocs/VCSIOCS/VCSEBUSIOC/iocBoot/vcsebusioc
    #tmux new -s SCANNER -d ./start_scanner &
    tmux new-session -d -s VCSEBUSIOC
    tmux split-window -v -p 50 -t VCSEBUSIOC
    tmux select-pane -t 0
    tmux send-keys "./start_scanner" C-m 
    echo "scanner started "
    sleep 2
    tmux select-pane -t 1
    tmux send-keys "./ebusioc.cmd" C-m 
    #tmux new -s IOC -d ./st.cmd &
    echo "IOC started "
    ;;
  stop)
    #tmux kill-session -t IOC
    #tmux kill-session -t SCANNER
    tmux kill-session -t VCSEBUSIOC
    #echo "IOC stopped"
    echo "Scanner and  ioc Stopped"
    ;;
  *)
    echo "Usage: /etc/init.d/startioc {start|stop}"
    exit 1
    ;;
esac

exit 0

