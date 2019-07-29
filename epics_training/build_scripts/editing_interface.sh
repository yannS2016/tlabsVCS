#!/bin/bash
tmux new-session -d -s ECATCONFIG
tmux split-window -p 20 -t ECATCONFIG
tmux split-window -h -t 0 -p 50

tmux select-pane -t 1
tmux send-keys "cd ./ && nano -v $2" C-m

tmux select-pane -t 0
tmux send-keys "cd ./ && nano $1" C-m
tmux select-pane -t 2

tmux send-keys "cd ./ && tail $2" C-m
sleep 1

tmux a -t ECATCONFIG
echo "tmux terminated with $?"
