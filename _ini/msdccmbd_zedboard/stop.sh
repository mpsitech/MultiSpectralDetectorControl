#!/bin/bash
# file stop.sh
# stop script for Msdc combined daemon, release msdccmbd_zedboard
# author Alexander Wirthmueller
# date created: 29 Aug 2018
# modified: 29 Aug 2018

pid=$(pgrep Msdccmbd)
kill -15 $pid

