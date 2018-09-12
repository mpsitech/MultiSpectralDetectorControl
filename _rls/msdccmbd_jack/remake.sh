#!/bin/bash
# file remake.sh
# re-make script for Msdc combined daemon, release msdccmbd_jack
# author Alexander Wirthmueller
# date created: 12 Sep 2018
# modified: 12 Sep 2018

export set SRCROOT=/home/mpsitech/src
export set REPROOT=/home/mpsitech/srcrep

cd $REPROOT/msdc/_rls/msdccmbd_jack
./checkout.sh

cd $SRCROOT/msdccmbd

./make.sh "$@"

