# file Makefile
# make file for Msdc database access library, release dbsmsdc_jack
# author Alexander Wirthmueller
# date created: 18 Dec 2018
# modified: 18 Dec 2018

LIBROOT = /home/mpsitech/lib

CPP = g++
CPPFLAGS = -std=c++11 -g -Wall -Os -pthread -fpic

STATLIB = ar
STATLIBFLAGS = rcs

DYNLIB = g++
DYNLIBFLAGS = -shared
DYNLIBEXT = so

INCPATH = -I/usr/include -I/usr/include/libxml2 -I/usr/local/include

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
	$(DYNLIB) $(DYNLIBFLAGS) $(OBJS) -o $(LIB).$(DYNLIBEXT)
	rm -f *.o

install:
	mv $(LIB).a $(LIBROOT)/
	mv $(LIB).$(DYNLIBEXT) $(LIBROOT)/

clean:
	rm -f *.gch
	rm -f *.o

