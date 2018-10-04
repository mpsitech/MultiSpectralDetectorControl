# file Makefile
# make file for Msdc database access library, release dbsmsdc_zedboard
# author Alexander Wirthmueller
# date created: 4 Oct 2018
# modified: 4 Oct 2018

LIBROOT = /home/mpsitech/emb/zedboard/avnet-digilent-zedboard-2017.2/build/tmp/sysroots/plnx_arm/home/root/lib

CPP = /opt/Xilinx/petalinux-v2017.2/tools/linux-i386/gcc-arm-linux-gnueabi/bin/arm-linux-gnueabihf-g++
CPPFLAGS = --sysroot=/home/mpsitech/emb/zedboard/avnet-digilent-zedboard-2017.2/build/tmp/sysroots/plnx_arm -std=c++11 -mfloat-abi=hard -g -Wall -Os -pthread

STATLIB = /opt/Xilinx/petalinux-v2017.2/tools/linux-i386/gcc-arm-linux-gnueabi/bin/arm-linux-gnueabihf-ar
STATLIBFLAGS = rcs

INCPATH = -I=/usr/include -I=/usr/include/libxml2 -I=/usr/local/include

PCHS = DbsMsdc.h.gch

OBJS = DbsMsdc.o
OBJS += MsdcAccRMUserUniversal.o MsdcAMDataPar.o MsdcAMPersonDetail.o MsdcAMUserAccess.o MsdcAMUsergroupAccess.o MsdcAVControlPar.o MsdcAVKeylistKey.o MsdcAVValuelistVal.o MsdcCFile.o MsdcHistRMUserUniversal.o MsdcJAVKeylistKey.o MsdcJMPersonLastname.o MsdcJMUserState.o MsdcMData.o MsdcMFile.o MsdcMPeriod.o MsdcMPerson.o MsdcMSession.o MsdcMUser.o MsdcMUsergroup.o MsdcRMUsergroupUniversal.o MsdcRMUserMUsergroup.o
OBJS += MsdcQDatAPar.o MsdcQDatList.o MsdcQDatRef1NFile.o MsdcQFilList.o MsdcQPrd1NData.o MsdcQPrdList.o MsdcQPreselect.o MsdcQPrsList.o MsdcQSelect.o MsdcQUsgAAccess.o MsdcQUsgList.o MsdcQUsgMNUser.o MsdcQUsr1NSession.o MsdcQUsrAAccess.o MsdcQUsrList.o MsdcQUsrMNUsergroup.o

LIB = libdbsmsdc

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

