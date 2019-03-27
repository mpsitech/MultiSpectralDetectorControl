#!/bin/bash
# file makeall.sh
# make script for Msdc database access library, release dbsmsdc_ungenio
# author Alexander Wirthmueller
# date created: 18 Dec 2018
# modified: 18 Dec 2018

make DbsMsdc.h.gch
if [ $? -ne 0 ]; then
	exit
fi

make -j2
if [ $? -ne 0 ]; then
	exit
fi

make install

