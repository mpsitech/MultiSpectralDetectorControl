#!/bin/bash
# file checkout.sh
# checkout script for Msdc web-based UI, release webappmsdc_jack
# author Alexander Wirthmueller
# date created: 4 Oct 2018
# modified: 4 Oct 2018

export set WEBROOT=/home/mpsitech/web

mkdir $WEBROOT/appmsdc

cp checkin.sh $WEBROOT/appmsdc/

cp -r ../../webappmsdc/* $WEBROOT/appmsdc/

