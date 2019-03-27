#!/bin/bash
# file checkout.sh
# checkout script for Msdc API library, release apimsdc_zedboard
# author Alexander Wirthmueller
# date created: 18 Dec 2018
# modified: 18 Dec 2018

export set SRCROOT=/home/mpsitech/emb/zedboard/avnet-digilent-zedboard-2017.2/build/tmp/sysroots/plnx_arm/home/root/src

mkdir $SRCROOT/apimsdc

cp makeall.sh $SRCROOT/apimsdc/

cp Makefile $SRCROOT/apimsdc/

cp ../../apimsdc/*.h $SRCROOT/apimsdc/
cp ../../apimsdc/*.cpp $SRCROOT/apimsdc/

