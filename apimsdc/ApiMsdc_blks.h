/**
  * \file ApiMsdc_blks.h
  * Msdc API library global data blocks (declarations)
  * \author Alexander Wirthmueller
  * \date created: 29 Aug 2018
  * \date modified: 29 Aug 2018
  */

#ifndef APIMSDC_BLKS_H
#define APIMSDC_BLKS_H

#include "VecMsdcVDpch.h"
#include "VecMsdcVExpstate.h"
#include "VecMsdcVQrystate.h"
#include "VecMsdcVReqitmode.h"

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
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
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
	* DpchAppMsdc
	*/
class DpchAppMsdc : public DpchMsdc {

public:
	static const uint SCRJREF = 1;

public:
	DpchAppMsdc(const uint ixMsdcVDpch = 0, const string& scrJref = "");
	virtual ~DpchAppMsdc();

public:
	string scrJref;

public:
	static bool all(const set<uint>& items);
	virtual string getSrefsMask();

	virtual void writeXML(xmlTextWriter* wr);
};

/**
	* DpchAppMsdcAlert
	*/
class DpchAppMsdcAlert : public DpchAppMsdc {

public:
	static const uint SCRJREF = 1;
	static const uint NUMFMCB = 2;
	static const uint ALL = 3;

public:
	DpchAppMsdcAlert(const string& scrJref = "", const uint numFMcb = 0, const set<uint>& mask = {NONE});

public:
	uint numFMcb;

public:
	static bool all(const set<uint>& items);
	string getSrefsMask();

	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchAppMsdcInit
	*/
class DpchAppMsdcInit : public DpchAppMsdc {

public:
	DpchAppMsdcInit(const string& scrJref = "");
};

/**
	* DpchAppMsdcResume
	*/
class DpchAppMsdcResume : public DpchAppMsdc {

public:
	DpchAppMsdcResume(const string& scrJref = "");
};

/**
	* DpchEngMsdc
	*/
class DpchEngMsdc : public DpchMsdc {

public:
	static const uint SCRJREF = 1;

public:
	DpchEngMsdc(const uint ixMsdcVDpch = 0);
	virtual ~DpchEngMsdc();

public:
	string scrJref;

public:
	static bool all(const set<uint>& items);
	virtual string getSrefsMask();

	virtual void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
	* DpchEngMsdcAck
	*/
class DpchEngMsdcAck : public DpchEngMsdc {

public:
	DpchEngMsdcAck();
};

/**
	* DpchEngMsdcAlert
	*/
class DpchEngMsdcAlert : public DpchEngMsdc {

public:
	static const uint SCRJREF = 1;
	static const uint CONTINF = 2;
	static const uint FEEDFMCB = 3;

public:
	DpchEngMsdcAlert();

public:
	ContInfMsdcAlert continf;
	Feed feedFMcb;

public:
	static bool all(const set<uint>& items);
	string getSrefsMask();

	void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
	* DpchEngMsdcConfirm
	*/
class DpchEngMsdcConfirm : public DpchEngMsdc {

public:
	static const uint ACCEPTED = 1;
	static const uint SCRJREF = 2;
	static const uint SREF = 3;

public:
	DpchEngMsdcConfirm();

public:
	bool accepted;
	string sref;

public:
	static bool all(const set<uint>& items);
	string getSrefsMask();

	void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
	* DpchEngMsdcSuspend
	*/
class DpchEngMsdcSuspend : public DpchEngMsdc {

public:
	DpchEngMsdcSuspend();
};

#endif

