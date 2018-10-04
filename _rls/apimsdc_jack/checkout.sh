#!/bin/bash
# file checkout.sh
# checkout script for Msdc API library, release apimsdc_jack
# author Alexander Wirthmueller
# date created: 4 Oct 2018
# modified: 4 Oct 2018

export set SRCROOT=/home/mpsitech/src

mkdir $SRCROOT/apimsdc

cp makeall.sh $SRCROOT/apimsdc/

cp Makefile $SRCROOT/apimsdc/

cp ../../apimsdc/*.h $SRCROOT/apimsdc/
cp ../../apimsdc/*.cpp $SRCROOT/apimsdc/

