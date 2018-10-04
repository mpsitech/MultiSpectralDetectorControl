#!/bin/bash
# file makeall.sh
# make script for Msdc database access library, release dbsmsdc_jack
# author Alexander Wirthmueller
# date created: 4 Oct 2018
# modified: 4 Oct 2018

make DbsMsdc.h.gch
if [ $? -ne 0 ]; then
	exit
fi

make -j16
if [ $? -ne 0 ]; then
	exit
fi

make install

