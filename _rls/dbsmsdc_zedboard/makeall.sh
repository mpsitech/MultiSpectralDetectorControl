#!/bin/bash
# file makeall.sh
# make script for Msdc database access library, release dbsmsdc_zedboard
# author Alexander Wirthmueller
# date created: 29 Aug 2018
# modified: 29 Aug 2018

make DbsMsdc.h.gch
if [ $? -ne 0 ]; then
	exit
fi

make -j2
if [ $? -ne 0 ]; then
	exit
fi

make install

