#!/bin/bash 

###################################################################
#Script Name    : install.sh
#Description    : Installs the depencencies of this repo
#Args           : None
##################################################################

# CPU TEST Build

[ ! -d "cpputest" ] && echo "It looks like the cpputest submodule is not installed. Please run git submodule pull."
cd cpputest

# Pulled from http://cpputest.github.io/#using-cpputest-with-makefileworkermk-and-gcc
autoreconf . -i
./configure
make tdd
