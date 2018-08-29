#!/bin/bash
# file checkout.sh
# checkout script for Msdc API library, release apimsdc_ungenio
# author Alexander Wirthmueller
# date created: 29 Aug 2018
# modified: 29 Aug 2018

export set SRCROOT=/Users/mpsitech/src

mkdir $SRCROOT/apimsdc

cp makeall.sh $SRCROOT/apimsdc/

cp Makefile $SRCROOT/apimsdc/

cp ../../apimsdc/*.h $SRCROOT/apimsdc/
cp ../../apimsdc/*.cpp $SRCROOT/apimsdc/

