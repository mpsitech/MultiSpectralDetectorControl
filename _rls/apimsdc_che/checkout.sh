#!/bin/bash
# file checkout.sh
# checkout script for Msdc API library, release apimsdc_che
# author Alexander Wirthmueller
# date created: 12 Sep 2018
# modified: 12 Sep 2018

export set SRCROOT=/home/mpsitech/src

mkdir $SRCROOT/apimsdc

cp makeall.sh $SRCROOT/apimsdc/

cp Makefile $SRCROOT/apimsdc/

cp ../../apimsdc/*.h $SRCROOT/apimsdc/
cp ../../apimsdc/*.cpp $SRCROOT/apimsdc/

