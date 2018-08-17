#!/bin/bash
# file checkout.sh
# checkout script for Msdc web-based UI, release webappmsdc_ungenio
# author Alexander Wirthmueller
# date created: 15 Aug 2018
# modified: 15 Aug 2018

export set WEBROOT=/Users/mpsitech/web

mkdir $WEBROOT/appmsdc

cp checkin.sh $WEBROOT/appmsdc/

cp -r ../../webappmsdc/* $WEBROOT/appmsdc/

