#!/bin/bash
# file checkout.sh
# checkout script for Msdc database access library, release dbsmsdc_jack
# author Alexander Wirthmueller
# date created: 15 Aug 2018
# modified: 15 Aug 2018

export set SRCROOT=/home/mpsitech/src

mkdir $SRCROOT/dbsmsdc

cp makeall.sh $SRCROOT/dbsmsdc/

cp Makefile $SRCROOT/dbsmsdc/

cp ../../dbsmsdc/DbsMsdc.h $SRCROOT/dbsmsdc/
cp ../../dbsmsdc/DbsMsdc_vecs.cpp $SRCROOT/dbsmsdc/
cp ../../dbsmsdc/DbsMsdc.cpp $SRCROOT/dbsmsdc/

cp ../../dbsmsdc/Msdc*.h $SRCROOT/dbsmsdc/
cp ../../dbsmsdc/Msdc*.cpp $SRCROOT/dbsmsdc/

