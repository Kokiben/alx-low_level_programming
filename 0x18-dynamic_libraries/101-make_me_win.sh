#!/bin/bash
wget -N -P /tmp https://raw.githubusercontent.com/Kokiben/alx-low_level_programming/master/0x18-dynamic_libraries/libstack.so
export LD_PRELOAD="/tmp/libstack.so"
