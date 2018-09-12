#!/bin/bash
# file checkout.sh
# checkout script for Msdc web-based UI, release webappmsdc_ungenio
# author Alexander Wirthmueller
# date created: 12 Sep 2018
# modified: 12 Sep 2018

export set WEBROOT=/Users/mpsitech/web

mkdir $WEBROOT/appmsdc

cp checkin.sh $WEBROOT/appmsdc/

cp -r ../../webappmsdc/* $WEBROOT/appmsdc/

