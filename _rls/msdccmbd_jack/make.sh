#!/bin/bash
# file make.sh
# make script for Msdc combined daemon, release msdccmbd_jack
# author Alexander Wirthmueller
# date created: 15 Aug 2018
# modified: 15 Aug 2018

make Msdccmbd.h.gch
if [ $? -ne 0 ]; then
	exit
fi

if [ "$1" = "all" ]; then
	subs=("IexMsdc" "VecMsdc" "CrdMsdcNav" "CrdMsdcUsg" "CrdMsdcUsr" "CrdMsdcPrs" "CrdMsdcScf" "CrdMsdcLiv" "CrdMsdcPrd" "CrdMsdcDat" "CrdMsdcFil")
else
	subs=("$@")
fi

for var in "${subs[@]}"
do
	cd "$var"
	make -j16
	if [ $? -ne 0 ]; then
		exit
	fi
	make install
	cd ..
done

make -j16
if [ $? -ne 0 ]; then
	exit
fi

make install

rm Msdccmbd.h.gch

