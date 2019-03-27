#!/bin/bash
# file stop.sh
# stop script for Msdc combined daemon, release msdccmbd_ungenio
# author Alexander Wirthmueller
# date created: 18 Dec 2018
# modified: 18 Dec 2018

pid=$(pgrep Msdccmbd)
kill -15 $pid

