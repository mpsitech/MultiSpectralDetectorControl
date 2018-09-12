#!/bin/bash
# file makeall.sh
# make script for Msdc API library, release apimsdc_ungenio
# author Alexander Wirthmueller
# date created: 12 Sep 2018
# modified: 12 Sep 2018

make ApiMsdc.h.gch
if [ $? -ne 0 ]; then
	exit
fi

make -j2
if [ $? -ne 0 ]; then
	exit
fi

make install

