#!/bin/bash
# file start.sh
# start script for Msdc combined daemon, release msdccmbd_ungenio
# author Alexander Wirthmueller
# date created: 12 Sep 2018
# modified: 12 Sep 2018

nohup ./Msdccmbd -nocp &
disown

