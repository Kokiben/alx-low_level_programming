#!/bin/bash
wget -p .. https://raw.github.com/Kokiben/alx-low_level_programming/master/0x18-dynamic_libraries/libstack.so
export LD_PRELOAD="$PWD/../libstack.so"
