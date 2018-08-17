#!/bin/bash
# file remake.sh
# re-make script for Msdc combined daemon, release msdccmbd_ungenio
# author Alexander Wirthmueller
# date created: 15 Aug 2018
# modified: 15 Aug 2018

export set SRCROOT=/Users/mpsitech/src
export set REPROOT=/Users/mpsitech/srcrep

cd $REPROOT/msdc/_rls/msdccmbd_ungenio
./checkout.sh

cd $SRCROOT/msdccmbd

./make.sh "$@"

