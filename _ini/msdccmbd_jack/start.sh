#!/bin/bash
# file start.sh
# start script for Msdc combined daemon, release msdccmbd_jack
# author Alexander Wirthmueller
# date created: 15 Aug 2018
# modified: 15 Aug 2018

nohup ./Msdccmbd -nocp &
disown

