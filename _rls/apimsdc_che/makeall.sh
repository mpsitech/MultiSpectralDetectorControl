#!/bin/bash
# file makeall.sh
# make script for Msdc API library, release apimsdc_che
# author Alexander Wirthmueller
# date created: 29 Aug 2018
# modified: 29 Aug 2018

make ApiMsdc.h.gch
if [ $? -ne 0 ]; then
	exit
fi

make -j2
if [ $? -ne 0 ]; then
	exit
fi

make install

