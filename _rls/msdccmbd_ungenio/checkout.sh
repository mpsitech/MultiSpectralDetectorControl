#!/bin/bash
# file checkout.sh
# checkout script for Msdc combined daemon, release msdccmbd_ungenio
# author Alexander Wirthmueller
# date created: 15 Aug 2018
# modified: 15 Aug 2018

export set SRCROOT=/Users/mpsitech/src
export set LIBROOT=/Users/mpsitech/lib
export set BINROOT=/Users/mpsitech/bin

mkdir $SRCROOT/msdccmbd
mkdir $SRCROOT/msdccmbd/IexMsdc
mkdir $SRCROOT/msdccmbd/VecMsdc
mkdir $SRCROOT/msdccmbd/CrdMsdcNav
mkdir $SRCROOT/msdccmbd/CrdMsdcUsg
mkdir $SRCROOT/msdccmbd/CrdMsdcUsr
mkdir $SRCROOT/msdccmbd/CrdMsdcPrs
mkdir $SRCROOT/msdccmbd/CrdMsdcScf
mkdir $SRCROOT/msdccmbd/CrdMsdcLiv
mkdir $SRCROOT/msdccmbd/CrdMsdcPrd
mkdir $SRCROOT/msdccmbd/CrdMsdcDat
mkdir $SRCROOT/msdccmbd/CrdMsdcFil

mkdir $LIBROOT/msdccmbd

mkdir $BINROOT/msdccmbd

cp make.sh $SRCROOT/msdccmbd/
cp remake.sh $SRCROOT/msdccmbd/

cp Makefile.inc $SRCROOT/msdccmbd/
cp Makefile $SRCROOT/msdccmbd/

cp ../../msdccmbd/Msdccmbd.h $SRCROOT/msdccmbd/
cp ../../msdccmbd/Msdccmbd.cpp $SRCROOT/msdccmbd/

cp ../../msdccmbd/MsdccmbdAppsrv.h $SRCROOT/msdccmbd/
cp ../../msdccmbd/MsdccmbdAppsrv.cpp $SRCROOT/msdccmbd/

cp ../../msdccmbd/MsdccmbdJobprc.h $SRCROOT/msdccmbd/
cp ../../msdccmbd/MsdccmbdJobprc.cpp $SRCROOT/msdccmbd/

cp ../../msdccmbd/MsdccmbdOpprc.h $SRCROOT/msdccmbd/
cp ../../msdccmbd/MsdccmbdOpprc.cpp $SRCROOT/msdccmbd/

cp ../../msdccmbd/DDS/*.hpp $SRCROOT/msdccmbd/
cp ../../msdccmbd/DDS/*.cpp $SRCROOT/msdccmbd/

cp ../../msdccmbd/MsdccmbdDdspub.h $SRCROOT/msdccmbd/
cp ../../msdccmbd/MsdccmbdDdspub.cpp $SRCROOT/msdccmbd/

cp ../../msdccmbd/SDK_Configuration/*.h $SRCROOT/msdccmbd/

cp ../../msdccmbd/MsdccmbdUasrv.h $SRCROOT/msdccmbd/
cp ../../msdccmbd/MsdccmbdUasrv.cpp $SRCROOT/msdccmbd/

cp ../../msdccmbd/Msdccmbd_exe.h $SRCROOT/msdccmbd/
cp ../../msdccmbd/Msdccmbd_exe.cpp $SRCROOT/msdccmbd/

cp ../../msdccmbd/Msdc.h $SRCROOT/msdccmbd/
cp ../../msdccmbd/Msdc.cpp $SRCROOT/msdccmbd/

cp ../../msdccmbd/Root*.h $SRCROOT/msdccmbd/
cp ../../msdccmbd/Root*.cpp $SRCROOT/msdccmbd/

cp ../../msdccmbd/Sess*.h $SRCROOT/msdccmbd/
cp ../../msdccmbd/Sess*.cpp $SRCROOT/msdccmbd/

cp ../../msdccmbd/M2msess*.h $SRCROOT/msdccmbd/
cp ../../msdccmbd/M2msess*.cpp $SRCROOT/msdccmbd/

cp ../../msdccmbd/gbl/*.h $SRCROOT/msdccmbd/
cp ../../msdccmbd/gbl/*.cpp $SRCROOT/msdccmbd/

cp Makefile_IexMsdc $SRCROOT/msdccmbd/IexMsdc/Makefile

cp ../../msdccmbd/IexMsdc/IexMsdc*.h $SRCROOT/msdccmbd/IexMsdc/
cp ../../msdccmbd/IexMsdc/IexMsdc*.cpp $SRCROOT/msdccmbd/IexMsdc/

cp Makefile_VecMsdc $SRCROOT/msdccmbd/VecMsdc/Makefile

cp ../../msdccmbd/VecMsdc/Vec*.h $SRCROOT/msdccmbd/VecMsdc/
cp ../../msdccmbd/VecMsdc/Vec*.cpp $SRCROOT/msdccmbd/VecMsdc/

cp Makefile_CrdMsdcNav $SRCROOT/msdccmbd/CrdMsdcNav/Makefile

cp ../../msdccmbd/CrdMsdcNav/*.h $SRCROOT/msdccmbd/CrdMsdcNav/
cp ../../msdccmbd/CrdMsdcNav/*.cpp $SRCROOT/msdccmbd/CrdMsdcNav/

cp Makefile_CrdMsdcUsg $SRCROOT/msdccmbd/CrdMsdcUsg/Makefile

cp ../../msdccmbd/CrdMsdcUsg/*.h $SRCROOT/msdccmbd/CrdMsdcUsg/
cp ../../msdccmbd/CrdMsdcUsg/*.cpp $SRCROOT/msdccmbd/CrdMsdcUsg/

cp Makefile_CrdMsdcUsr $SRCROOT/msdccmbd/CrdMsdcUsr/Makefile

cp ../../msdccmbd/CrdMsdcUsr/*.h $SRCROOT/msdccmbd/CrdMsdcUsr/
cp ../../msdccmbd/CrdMsdcUsr/*.cpp $SRCROOT/msdccmbd/CrdMsdcUsr/

cp Makefile_CrdMsdcPrs $SRCROOT/msdccmbd/CrdMsdcPrs/Makefile

cp ../../msdccmbd/CrdMsdcPrs/*.h $SRCROOT/msdccmbd/CrdMsdcPrs/
cp ../../msdccmbd/CrdMsdcPrs/*.cpp $SRCROOT/msdccmbd/CrdMsdcPrs/

cp Makefile_CrdMsdcScf $SRCROOT/msdccmbd/CrdMsdcScf/Makefile

cp ../../msdccmbd/CrdMsdcScf/*.h $SRCROOT/msdccmbd/CrdMsdcScf/
cp ../../msdccmbd/CrdMsdcScf/*.cpp $SRCROOT/msdccmbd/CrdMsdcScf/

cp Makefile_CrdMsdcLiv $SRCROOT/msdccmbd/CrdMsdcLiv/Makefile

cp ../../msdccmbd/CrdMsdcLiv/*.h $SRCROOT/msdccmbd/CrdMsdcLiv/
cp ../../msdccmbd/CrdMsdcLiv/*.cpp $SRCROOT/msdccmbd/CrdMsdcLiv/

cp Makefile_CrdMsdcPrd $SRCROOT/msdccmbd/CrdMsdcPrd/Makefile

cp ../../msdccmbd/CrdMsdcPrd/*.h $SRCROOT/msdccmbd/CrdMsdcPrd/
cp ../../msdccmbd/CrdMsdcPrd/*.cpp $SRCROOT/msdccmbd/CrdMsdcPrd/

cp Makefile_CrdMsdcDat $SRCROOT/msdccmbd/CrdMsdcDat/Makefile

cp ../../msdccmbd/CrdMsdcDat/*.h $SRCROOT/msdccmbd/CrdMsdcDat/
cp ../../msdccmbd/CrdMsdcDat/*.cpp $SRCROOT/msdccmbd/CrdMsdcDat/

cp Makefile_CrdMsdcFil $SRCROOT/msdccmbd/CrdMsdcFil/Makefile

cp ../../msdccmbd/CrdMsdcFil/*.h $SRCROOT/msdccmbd/CrdMsdcFil/
cp ../../msdccmbd/CrdMsdcFil/*.cpp $SRCROOT/msdccmbd/CrdMsdcFil/

