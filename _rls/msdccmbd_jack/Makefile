# file Makefile
# make file for Msdc combined daemon, release msdccmbd_jack
# author Alexander Wirthmueller
# date created: 29 Aug 2018
# modified: 29 Aug 2018

include Makefile.inc

CPP = g++
CPPFLAGS = -std=c++11 -g -Wall -Os -pthread -DMSDCCMBD -DRTI_64BIT -DRTI_LINUX -DRTI_UNIX -Wno-unknown-pragmas -m64

LINK = g++
LINKFLAGS =

INCPATH = -I$(SRCROOT)/dbsmsdc -I$(SRCROOT)/msdccmbd/VecMsdc -I$(SRCROOT)/msdccmbd/IexMsdc -I$(SRCROOT)/msdccmbd
INCPATH += -I$(SRCROOT)/msdccmbd/CrdMsdcNav -I$(SRCROOT)/msdccmbd/CrdMsdcUsg -I$(SRCROOT)/msdccmbd/CrdMsdcUsr -I$(SRCROOT)/msdccmbd/CrdMsdcPrs -I$(SRCROOT)/msdccmbd/CrdMsdcScf -I$(SRCROOT)/msdccmbd/CrdMsdcLiv -I$(SRCROOT)/msdccmbd/CrdMsdcPrd -I$(SRCROOT)/msdccmbd/CrdMsdcDat -I$(SRCROOT)/msdccmbd/CrdMsdcFil
INCPATH += -I$(NDDSHOME)/include -I$(NDDSHOME)/include/ndds -I$(NDDSHOME)/include/ndds/hpp -I$(UASDKROOT)/SDK_Source/interface/common/platform_specific/atomic/any_platform_st -I$(UASDKROOT)/SDK_Source/interface/common/platform_specific/file/linux_windows -I$(UASDKROOT)/SDK_Source/interface/common/platform_specific/library/linux_windows -I$(UASDKROOT)/SDK_Source/interface/common/platform_specific/locks/any_platform_st -I$(UASDKROOT)/SDK_Source/interface/common/platform_specific/ref_count/any_platform_st -I$(UASDKROOT)/SDK_Source/interface/common/platform_specific/tcpip/windows_linux_sockets_select_st -I$(UASDKROOT)/SDK_Source/interface/common/platform_specific/thread_pool/any_platform_st -I$(UASDKROOT)/SDK_Source/interface/common/platform_specific/timers/any_platform_polled -I$(UASDKROOT)/SDK_Source/interface/common/portable/address_space -I$(UASDKROOT)/SDK_Source/interface/common/portable/address_space/helpers -I$(UASDKROOT)/SDK_Source/interface/common/portable/data_types -I$(UASDKROOT)/SDK_Source/interface/common/portable/data_types/helper -I$(UASDKROOT)/SDK_Source/interface/common/portable/miscellaneous -I$(UASDKROOT)/SDK_Source/interface/common/portable/smart_pointers -I$(UASDKROOT)/SDK_Source/interface/common/portable/ua_messages -I$(UASDKROOT)/SDK_Source/interface/server/platform_specific/server_class/windows_linux_st -I$(UASDKROOT)/SDK_Source/interface/server/portable -I$(UASDKROOT)/SDK_Source/internals -I/home/mpsitech/src/devmsdd -I/usr/include -I/usr/include/libxml2 -I/usr/include/spinnaker -I/usr/local/include

PCHS = Msdccmbd.h.gch

OBJS = Msdc.o MsdccmbdAppsrv.o MsdccmbdJobprc.o MsdccmbdOpprc.o Msdccmbd.o
OBJS += DdsMsdcPlugin.o DdsMsdc.o MsdccmbdDdspub.o
OBJS += MsdccmbdUasrv.o
OBJS += RootMsdc.o M2msessMsdc.o SessMsdc.o JobMsdcAcqAdxl.o JobMsdcAcqLwir.o JobMsdcAcqVisl.o JobMsdcAcqVisr.o JobMsdcActAlign.o JobMsdcActLed.o JobMsdcActServo.o JobMsdcPrcStereo.o JobMsdcPrcTrack.o JobMsdcSrcMsdd.o JobMsdcSrcTrigger.o
OBJS += Msdccmbd_exe.o

LIBPATH = -L$(LIBROOT)
LIBPATH += -L$(LIBROOT)/msdccmbd
LIBPATH += -L$(NDDSHOME)/lib/x64Linux3gcc5.4.0 -L/home/mpsitech/lib -L/usr/lib -L/usr/lib/x86_64-linux-gnu -L/usr/local/lib
LIBPATH += -L/lib/x86_64-linux-gnu

LIBS = -lcrdmsdcnav -lcrdmsdcusg -lcrdmsdcusr -lcrdmsdcprs -lcrdmsdcscf -lcrdmsdcliv -lcrdmsdcprd -lcrdmsdcdat -lcrdmsdcfil
LIBS += -liexmsdc -lvecmsdc -ldbsmsdc
LIBS += -lSpinnaker -ldevmsdd -ljpeg -lmicrohttpd -lopcua -lpng -lrticonnextmsgcpp2 -lsbecore_lite -lsbecore_mon
LIBS += -ldbecore -lnddscpp2 -lsqlite3
LIBS += -lnddsc -lsbecore
LIBS += -lnddscore -lxml2
LIBS += -lz
LIBS += -lpthread

EXE = Msdccmbd

.SUFFIXES:	.h .h.gch .cpp

.h.h.gch :
	$(CPP) $(CPPFLAGS) $(INCPATH) -o $@ -c $<

.cpp.o :
	$(CPP) $(CPPFLAGS) $(INCPATH) -o $@ -c $<

all:	$(PCHS) $(EXE)

$(EXE):	$(OBJS)
	$(LINK) $(LINKFLAGS) $(OBJS) $(LIBPATH) $(LIBS) -o $(EXE)
	rm -f *.o

pch:	$(PCHS)

install:
	mv $(EXE) $(BINROOT)/msdccmbd/

clean:
	rm -f *.gch
	rm -f *.o

