#!/bin/bash
# file start.sh
# start script for Msdc combined daemon, release msdccmbd_jack
# author Alexander Wirthmueller
# date created: 18 Dec 2018
# modified: 18 Dec 2018

nohup ./Msdccmbd -nocp &
disown

