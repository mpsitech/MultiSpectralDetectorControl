#!/bin/bash
# file remake.sh
# re-make script for Msdc combined daemon, release msdccmbd_zedboard
# author Alexander Wirthmueller
# date created: 12 Sep 2018
# modified: 12 Sep 2018

export set SRCROOT=/home/mpsitech/emb/zedboard/avnet-digilent-zedboard-2017.2/build/tmp/sysroots/plnx_arm/home/root/src
export set REPROOT=/home/mpsitech/srcrep

cd $REPROOT/msdc/_rls/msdccmbd_zedboard
./checkout.sh

cd $SRCROOT/msdccmbd

./make.sh "$@"

