#!/bin/bash
# file checkin.sh
# checkin script for Msdc web-based UI, release webappmsdc_jack
# author Alexander Wirthmueller
# date created: 4 Oct 2018
# modified: 4 Oct 2018

export set REPROOT=/home/mpsitech/srcrep

cp -r * $REPROOT/msdc/webappmsdc/

rm $REPROOT/msdc/webappmsdc/checkin.sh

