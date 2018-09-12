#!/bin/bash
# file checkout.sh
# checkout script for Msdc web-based UI, release webappmsdc_zedboard
# author Alexander Wirthmueller
# date created: 12 Sep 2018
# modified: 12 Sep 2018

export set WEBROOT=/home/mpsitech/emb/zedboard/avnet-digilent-zedboard-2017.2/build/tmp/sysroots/plnx_arm/home/root/web

mkdir $WEBROOT/appmsdc

cp checkin.sh $WEBROOT/appmsdc/

cp -r ../../webappmsdc/* $WEBROOT/appmsdc/

