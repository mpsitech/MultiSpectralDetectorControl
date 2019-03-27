# file Makefile
# make file for Msdc API library, release apimsdc_zedboard
# author Alexander Wirthmueller
# date created: 18 Dec 2018
# modified: 18 Dec 2018

LIBROOT = /home/mpsitech/emb/zedboard/avnet-digilent-zedboard-2017.2/build/tmp/sysroots/plnx_arm/home/root/lib

CPP = /opt/Xilinx/petalinux-v2017.2/tools/linux-i386/gcc-arm-linux-gnueabi/bin/arm-linux-gnueabihf-g++
CPPFLAGS = --sysroot=/home/mpsitech/emb/zedboard/avnet-digilent-zedboard-2017.2/build/tmp/sysroots/plnx_arm -std=c++11 -mfloat-abi=hard -g -Wall -Os -pthread

STATLIB = /opt/Xilinx/petalinux-v2017.2/tools/linux-i386/gcc-arm-linux-gnueabi/bin/arm-linux-gnueabihf-ar
STATLIBFLAGS = rcs

INCPATH = -I=/usr/include/libxml2 -I=/usr/local/include

PCHS = ApiMsdc.h.gch

OBJS = ApiMsdc_blks.o ApiMsdc.o
OBJS += VecMsdcVCamres.o VecMsdcVCamste.o VecMsdcVCamtype.o VecMsdcVChannel.o VecMsdcVCorner.o VecMsdcVExpstate.o VecMsdcVReqitmode.o VecMsdcVSqrgrp.o
OBJS += MsdcQDatAPar.o MsdcQDatList.o MsdcQDatRef1NFile.o MsdcQFilList.o MsdcQPrd1NData.o MsdcQPrdList.o MsdcQPrsList.o MsdcQUsgAAccess.o MsdcQUsgList.o MsdcQUsgMNUser.o MsdcQUsr1NSession.o MsdcQUsrAAccess.o MsdcQUsrList.o MsdcQUsrMNUsergroup.o
OBJS += CrdMsdcDat.o CrdMsdcFil.o CrdMsdcLiv.o CrdMsdcNav.o CrdMsdcPrd.o CrdMsdcPrs.o CrdMsdcScf.o CrdMsdcUsg.o CrdMsdcUsr.o DlgMsdcFilDownload.o DlgMsdcNavLoaini.o M2msessMsdc.o PnlMsdcDatAPar.o PnlMsdcDatDetail.o PnlMsdcDatHeadbar.o PnlMsdcDatList.o PnlMsdcDatRec.o PnlMsdcDatRef1NFile.o PnlMsdcFilDetail.o PnlMsdcFilHeadbar.o PnlMsdcFilList.o PnlMsdcFilRec.o PnlMsdcLivAlign.o PnlMsdcLivHeadbar.o PnlMsdcLivScill.o PnlMsdcLivTrack.o PnlMsdcLivVideo.o PnlMsdcNavAdmin.o PnlMsdcNavHeadbar.o PnlMsdcNavOpr.o PnlMsdcNavPre.o PnlMsdcPrd1NData.o PnlMsdcPrdDetail.o PnlMsdcPrdHeadbar.o PnlMsdcPrdList.o PnlMsdcPrdRec.o PnlMsdcPrsDetail.o PnlMsdcPrsHeadbar.o PnlMsdcPrsList.o PnlMsdcPrsRec.o PnlMsdcScfAcquis.o PnlMsdcScfActu.o PnlMsdcScfHeadbar.o PnlMsdcScfPrcctl.o PnlMsdcScfSource.o PnlMsdcUsgAAccess.o PnlMsdcUsgDetail.o PnlMsdcUsgHeadbar.o PnlMsdcUsgList.o PnlMsdcUsgMNUser.o PnlMsdcUsgRec.o PnlMsdcUsr1NSession.o PnlMsdcUsrAAccess.o PnlMsdcUsrDetail.o PnlMsdcUsrHeadbar.o PnlMsdcUsrList.o PnlMsdcUsrMNUsergroup.o PnlMsdcUsrRec.o QryMsdcDatAPar.o QryMsdcDatList.o QryMsdcDatRef1NFile.o QryMsdcFilList.o QryMsdcPrd1NData.o QryMsdcPrdList.o QryMsdcPrsList.o QryMsdcUsgAAccess.o QryMsdcUsgList.o QryMsdcUsgMNUser.o QryMsdcUsr1NSession.o QryMsdcUsrAAccess.o QryMsdcUsrList.o QryMsdcUsrMNUsergroup.o RootMsdc.o SessMsdc.o

LIB = libapimsdc

.SUFFIXES:	.h .h.gch .cpp

.h.h.gch :
	$(CPP) $(CPPFLAGS) $(INCPATH) -o $@ -c $<

.cpp.o :
	$(CPP) $(CPPFLAGS) $(INCPATH) -o $@ -c $<

all:	$(LIB)

$(LIB):	$(PCHS) $(OBJS)
	$(STATLIB) $(STATLIBFLAGS) $(LIB).a $(OBJS)
	rm -f *.o

install:
	mv $(LIB).a $(LIBROOT)/

clean:
	rm -f *.gch
	rm -f *.o

