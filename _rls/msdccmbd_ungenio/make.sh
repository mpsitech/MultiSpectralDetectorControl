#!/bin/bash
# file make.sh
# make script for Msdc combined daemon, release msdccmbd_ungenio
# author Alexander Wirthmueller
# date created: 12 Sep 2018
# modified: 12 Sep 2018

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
	make -j2
	if [ $? -ne 0 ]; then
		exit
	fi
	make install
	cd ..
done

make -j2
if [ $? -ne 0 ]; then
	exit
fi

make install

rm Msdccmbd.h.gch

