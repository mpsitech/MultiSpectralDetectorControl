#!/bin/bash
# file checkin.sh
# checkin script for Msdc web-based UI, release webappmsdc_jack
# author Alexander Wirthmueller
# date created: 12 Sep 2018
# modified: 12 Sep 2018

export set REPROOT=/home/mpsitech/srcrep

cp -r * $REPROOT/msdc/webappmsdc/

rm $REPROOT/msdc/webappmsdc/checkin.sh

