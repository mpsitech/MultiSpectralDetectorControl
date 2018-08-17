/**
  * \file Msdc.h
  * Msdc global functionality (declarations)
  * \author Alexander Wirthmueller
  * \date created: 15 Aug 2018
  * \date modified: 15 Aug 2018
  */

#ifndef MSDC_H
#define MSDC_H

#define MSDC_VERSION "0.1.45"
#define MSDC_VERSION_MAJOR 0
#define MSDC_VERSION_MINOR 1
#define MSDC_VERSION_SUB 45

// IP incl --- IBEGIN
#define FPGA_ZEDB
//#define FPGA_BSS3
// IP incl --- IEND

#include <fstream>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

#include "VecMsdcVCall.h"
#include "VecMsdcVCamres.h"
#include "VecMsdcVCamste.h"
#include "VecMsdcVCamtype.h"
#include "VecMsdcVChannel.h"
#include "VecMsdcVCorner.h"
#include "VecMsdcVDpch.h"
#include "VecMsdcVExpstate.h"
#include "VecMsdcVIop.h"
#include "VecMsdcVJob.h"
#include "VecMsdcVLat.h"
#include "VecMsdcVLop.h"
#include "VecMsdcVMimetype.h"
#include "VecMsdcVOolop.h"
#include "VecMsdcVOpengtype.h"
#include "VecMsdcVOppack.h"
#include "VecMsdcVQrystate.h"
#include "VecMsdcVReqitmode.h"
#include "VecMsdcVSqrgrp.h"
#include "VecMsdcVStub.h"
#include "VecMsdcVTag.h"

#include <DbsMsdc.h>

#include <sbecore/Engtypes.h>
#include <sbecore/Stub.h>

/**
  * Acv
  */
namespace Acv {
	ubigint addfile(DbsMsdc* dbsmsdc, const string& acvpath, const string& path, const uint refIxVTbl, const ubigint refUref, const string& osrefKContent, const string& Filename, const string& srefKMimetype, const string& Comment);
	void alterfile(DbsMsdc* dbsmsdc, const string& acvpath, const string& path, const ubigint ref);
	string getfile(DbsMsdc* dbsmsdc, const ubigint refMsdcMFile);
};

/**
  * Lop
  */
namespace Lop {
	void apply(const uint ixMsdcVLop, vector<ubigint>& refsList, vector<ubigint>& refsPool, const ubigint ref);

	void insert(vector<ubigint>& refsList, vector<ubigint>& refsPool, const ubigint ref);
	void remove(vector<ubigint>& refsList, vector<ubigint>& refsPool, const ubigint ref);
};

/**
  * Oolop
  */
namespace Oolop {
	void apply(const uint ixMsdcVOolop, vector<ubigint>& refsList, vector<ubigint>& refsPool, const ubigint ref1, const ubigint ref2);

	void insertBefore(vector<ubigint>& refsList, vector<ubigint>& refsPool, const ubigint ref1, const ubigint ref2);
	void insertAfter(vector<ubigint>& refsList, vector<ubigint>& refsPool, const ubigint ref1, const ubigint ref2);
	void remove(vector<ubigint>& refsList, vector<ubigint>& refsPool, const ubigint ref);
	void toBefore(vector<ubigint>& refsList, const ubigint ref1, const ubigint ref2);
	void toAfter(vector<ubigint>& refsList, const ubigint ref1, const ubigint ref2);
	void swap(vector<ubigint>& refsList, const ubigint ref1, const ubigint ref2);
};

/**
  * Tmp
  */
namespace Tmp {
	string newfile(const string& tmppath, const string& ext);
	string newfolder(const string& tmppath);
	string random();
};

// IP cust --- IBEGIN
/**
  * Imgbufitem
  */
class Imgbufitem {

public:
	Imgbufitem(const unsigned int seqno, const double t, unsigned char* data, const size_t datalen, const ubigint jref);

public:
	unsigned int seqno;
	double t;

	unsigned char* data;
	size_t datalen;

	list<ubigint> jrefsClaim;

public:
	void claim(const ubigint jref);
	void release(const ubigint jref);
};

/**
  * Imgbuf
  */
class Imgbuf {

public:
	Imgbuf();
	~Imgbuf();

	bool initdone;
	void init(const unsigned int N, const unsigned int itemlen);
	void term();

public:
	unsigned char* data;
	unsigned int N;
	unsigned int itemlen;

	pthread_mutex_t mAccess;

	ubigint brefseq;

	vector<ubigint> brefs; // size: N, to identify occupied/empty slots
	map<ubigint, Imgbufitem*> brefsItems;

public:
	ubigint getNewItem(const ubigint jref, const unsigned int seqno, double t); // for master access

	Imgbufitem* getItem(const ubigint bref); // for read or write access

	void claim(const ubigint bref, const ubigint jref);

	void release(const ubigint bref, const ubigint jref);
	void releaseByJref(const ubigint jref);

	unsigned int cleanup(); // see if jrefsClaim is empty ; if yes, free slot in brefs
};

/**
  * Snippet
  */
class Snippet {

public:
	Snippet(const uint ixMsdcVCamres, const uint ixMsdcVChannel, const unsigned int w = 0, const unsigned int h = 0, const unsigned int x0 = 0, const unsigned int y0 = 0);
	~Snippet();

public:
	uint ixMsdcVCamres;
	uint ixMsdcVChannel;

	unsigned int w;
	unsigned int h;

	unsigned int x0;
	unsigned int y0;

	unsigned char* data;

	pthread_mutex_t mAccess;
	ubigint jrefClaim;

public:
	void reposition(const unsigned int _x0, const unsigned int _y0);
	void clear();

	bool claim(const ubigint jref);
	void release();
};
// IP cust --- IEND

/**
  * Msdc
  */
namespace Msdc {
	// IP gbl --- IBEGIN
	void getTimestamp(timespec* timestamp);

	double getNow();

	double invusecstamp(const string& s);

	void getCamresWh(const uint ixMsdcVCamres, unsigned int& w, unsigned int& h, const unsigned int _w = 0, const unsigned int _h = 0);

	void setupIntavg(const unsigned int inN, const unsigned int inMax, const unsigned int outMax, const double outPmin, unsigned int& im, bool* rshs, unsigned int& rshsN);
	unsigned int intavg(const unsigned int in, const unsigned int im, bool* rshs, const unsigned int rshsN);

	void copytrfBuf(unsigned char* src, unsigned char* trg, const unsigned int wlen, const unsigned int w, const unsigned int h, const uint ixMsdcVSqrgrp);

	void addBindataDatAPar(DbsMsdc* dbsmsdc, const ubigint refMsdcMData, const double x1Start, const string& x2SrefKKey, const unsigned char* buf, const size_t buflen);
	// IP gbl --- IEND
};

/**
  * OpengMsdc
  */
namespace OpengMsdc {
	void getIcsMsdcVOppackByIxMsdcVOpengtype(const uint ixMsdcVOpengtype, vector<uint>& icsMsdcVOppack);
	void getIcsMsdcVDpchByIxMsdcVOppack(const uint ixMsdcVOppack, set<uint>& icsMsdcVDpch);
};

/**
  * StubMsdc
  */
namespace StubMsdc {
	string getStub(DbsMsdc* dbsmsdc, const uint ixMsdcVStub, const ubigint ref, const uint ixMsdcVLocale = VecMsdcVLocale::ENUS, const uint ixVNonetype = Stub::VecVNonetype::DASH, Stcch* stcch = NULL, stcchitemref_t* strefSub = NULL, const bool refresh = false);

	string getStubDatStd(DbsMsdc* dbsmsdc, const ubigint ref, const uint ixMsdcVLocale = VecMsdcVLocale::ENUS, const uint ixVNonetype = Stub::VecVNonetype::DASH, Stcch* stcch = NULL, stcchitemref_t* strefSub = NULL, const bool refresh = false);
	string getStubFilStd(DbsMsdc* dbsmsdc, const ubigint ref, const uint ixMsdcVLocale = VecMsdcVLocale::ENUS, const uint ixVNonetype = Stub::VecVNonetype::DASH, Stcch* stcch = NULL, stcchitemref_t* strefSub = NULL, const bool refresh = false);
	string getStubGrp(DbsMsdc* dbsmsdc, const ubigint ref, const uint ixMsdcVLocale = VecMsdcVLocale::ENUS, const uint ixVNonetype = Stub::VecVNonetype::DASH, Stcch* stcch = NULL, stcchitemref_t* strefSub = NULL, const bool refresh = false);
	string getStubOwn(DbsMsdc* dbsmsdc, const ubigint ref, const uint ixMsdcVLocale = VecMsdcVLocale::ENUS, const uint ixVNonetype = Stub::VecVNonetype::DASH, Stcch* stcch = NULL, stcchitemref_t* strefSub = NULL, const bool refresh = false);
	string getStubPrdStd(DbsMsdc* dbsmsdc, const ubigint ref, const uint ixMsdcVLocale = VecMsdcVLocale::ENUS, const uint ixVNonetype = Stub::VecVNonetype::DASH, Stcch* stcch = NULL, stcchitemref_t* strefSub = NULL, const bool refresh = false);
	string getStubPrsStd(DbsMsdc* dbsmsdc, const ubigint ref, const uint ixMsdcVLocale = VecMsdcVLocale::ENUS, const uint ixVNonetype = Stub::VecVNonetype::DASH, Stcch* stcch = NULL, stcchitemref_t* strefSub = NULL, const bool refresh = false);
	string getStubSesMenu(DbsMsdc* dbsmsdc, const ubigint ref, const uint ixMsdcVLocale = VecMsdcVLocale::ENUS, const uint ixVNonetype = Stub::VecVNonetype::DASH, Stcch* stcch = NULL, stcchitemref_t* strefSub = NULL, const bool refresh = false);
	string getStubSesStd(DbsMsdc* dbsmsdc, const ubigint ref, const uint ixMsdcVLocale = VecMsdcVLocale::ENUS, const uint ixVNonetype = Stub::VecVNonetype::DASH, Stcch* stcch = NULL, stcchitemref_t* strefSub = NULL, const bool refresh = false);
	string getStubUsgStd(DbsMsdc* dbsmsdc, const ubigint ref, const uint ixMsdcVLocale = VecMsdcVLocale::ENUS, const uint ixVNonetype = Stub::VecVNonetype::DASH, Stcch* stcch = NULL, stcchitemref_t* strefSub = NULL, const bool refresh = false);
	string getStubUsrStd(DbsMsdc* dbsmsdc, const ubigint ref, const uint ixMsdcVLocale = VecMsdcVLocale::ENUS, const uint ixVNonetype = Stub::VecVNonetype::DASH, Stcch* stcch = NULL, stcchitemref_t* strefSub = NULL, const bool refresh = false);
};

/**
  * MsdcException
  */
struct MsdcException {
	string err;

	MsdcException(string err) {
		this->err = err;
	};
};

/**
	* ContInfMsdcAlert
	*/
class ContInfMsdcAlert : public Block {

public:
	static const uint TXTCPT = 1;
	static const uint TXTMSG1 = 2;
	static const uint TXTMSG2 = 3;
	static const uint TXTMSG3 = 4;
	static const uint TXTMSG4 = 5;
	static const uint TXTMSG5 = 6;
	static const uint TXTMSG6 = 7;
	static const uint TXTMSG7 = 8;
	static const uint TXTMSG8 = 9;
	static const uint TXTMSG9 = 10;
	static const uint TXTMSG10 = 11;
	static const uint TXTMSG11 = 12;
	static const uint TXTMSG12 = 13;

public:
	ContInfMsdcAlert(const string& TxtCpt = "", const string& TxtMsg1 = "", const string& TxtMsg2 = "", const string& TxtMsg3 = "", const string& TxtMsg4 = "", const string& TxtMsg5 = "", const string& TxtMsg6 = "", const string& TxtMsg7 = "", const string& TxtMsg8 = "", const string& TxtMsg9 = "", const string& TxtMsg10 = "", const string& TxtMsg11 = "", const string& TxtMsg12 = "");

public:
	string TxtCpt;
	string TxtMsg1;
	string TxtMsg2;
	string TxtMsg3;
	string TxtMsg4;
	string TxtMsg5;
	string TxtMsg6;
	string TxtMsg7;
	string TxtMsg8;
	string TxtMsg9;
	string TxtMsg10;
	string TxtMsg11;
	string TxtMsg12;

public:
	static bool all(const set<uint>& items);
	void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	set<uint> compare(const ContInfMsdcAlert* comp);
};

/**
  * DpchMsdc
  */
class DpchMsdc : public Block {

public:
	DpchMsdc(const uint ixMsdcVDpch = 0);
	virtual ~DpchMsdc();

public:
	uint ixMsdcVDpch;
};

/**
  * DpchInvMsdc
  */
class DpchInvMsdc : public DpchMsdc {

public:
	static const uint SCROREF = 1;
	static const uint OREF = 1;
	static const uint SCRJREF = 2;
	static const uint JREF = 2;
	static const uint ALL = 3;

public:
	DpchInvMsdc(const uint ixMsdcVDpch = VecMsdcVDpch::DPCHINVMSDC, const ubigint oref = 0, const ubigint jref = 0);
	virtual ~DpchInvMsdc();

public:
	string scrOref;
	ubigint oref;
	string scrJref;
	ubigint jref;

public:
	static bool all(const set<uint>& items);

	virtual void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	virtual void writeXML(pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
};

/**
	* DpchRetMsdc
  */
class DpchRetMsdc : public DpchMsdc {

public:
	static const uint SCROREF = 1;
	static const uint OREF = 1;
	static const uint SCRJREF = 2;
	static const uint JREF = 2;
	static const uint IXOPVOPRES = 3;
	static const uint PDONE = 4;

public:
	DpchRetMsdc(const uint ixMsdcVDpch = VecMsdcVDpch::DPCHRETMSDC, const string& scrOref = "", const string& scrJref = "", const utinyint ixOpVOpres = VecOpVOpres::PROGRESS, const utinyint pdone = 0);
	virtual ~DpchRetMsdc();

public:
	string scrOref;
	ubigint oref;
	string scrJref;
	ubigint jref;
	utinyint ixOpVOpres;
	utinyint pdone;

public:
	virtual void readXML(pthread_mutex_t* mScr, map<string,ubigint>& descr, xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	virtual void writeXML(xmlTextWriter* wr);
};

#endif




