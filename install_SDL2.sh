#!/bin/bash

osname=$(uname)

printf "%s\n" "$osname"
if [ "$osname" == 'Linux' ]; then
    printf "Installing SDL2 for Linux\n"
    bash install_SDL2_Linux.sh
fi
