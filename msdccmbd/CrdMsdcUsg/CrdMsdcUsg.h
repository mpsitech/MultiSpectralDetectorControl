/**
  * \file CrdMsdcUsg.h
  * job handler for job CrdMsdcUsg (declarations)
  * \author Alexander Wirthmueller
  * \date created: 15 Aug 2018
  * \date modified: 15 Aug 2018
  */

#ifndef CRDMSDCUSG_H
#define CRDMSDCUSG_H

// IP custInclude --- INSERT

#include "PnlMsdcUsgRec.h"
#include "PnlMsdcUsgHeadbar.h"
#include "PnlMsdcUsgList.h"

#define VecVMsdcUsgDo CrdMsdcUsg::VecVDo
#define VecVMsdcUsgSge CrdMsdcUsg::VecVSge

#define ContInfMsdcUsg CrdMsdcUsg::ContInf
#define StatAppMsdcUsg CrdMsdcUsg::StatApp
#define StatShrMsdcUsg CrdMsdcUsg::StatShr
#define TagMsdcUsg CrdMsdcUsg::Tag

#define DpchAppMsdcUsgDo CrdMsdcUsg::DpchAppDo
#define DpchEngMsdcUsgData CrdMsdcUsg::DpchEngData

/**
  * CrdMsdcUsg
  */
class CrdMsdcUsg : public JobMsdc {

public:
	/**
		* VecVDo (full: VecVMsdcUsgDo)
		*/
	class VecVDo {

	public:
		static const uint CLOSE = 1;
		static const uint MITAPPABTCLICK = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
		* VecVSge (full: VecVMsdcUsgSge)
		*/
	class VecVSge {

	public:
		static const uint IDLE = 1;
		static const uint ALRMSDCABT = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);

		static void fillFeed(Feed& feed);
	};

	/**
	  * ContInf (full: ContInfMsdcUsg)
	  */
	class ContInf : public Block {

	public:
		static const uint NUMFSGE = 1;
		static const uint MRLAPPHLP = 2;
		static const uint MTXCRDUSG = 3;

	public:
		ContInf(const uint numFSge = 1, const string& MrlAppHlp = "", const string& MtxCrdUsg = "");

	public:
		uint numFSge;
		string MrlAppHlp;
		string MtxCrdUsg;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppMsdcUsg)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const uint ixMsdcVReqitmode = VecMsdcVReqitmode::IDLE, const usmallint latency = 5, const string& shortMenu = "", const uint widthMenu = 0, const bool initdoneHeadbar = false, const bool initdoneList = false, const bool initdoneRec = false);
	};

	/**
		* StatShr (full: StatShrMsdcUsg)
		*/
	class StatShr : public Block {

	public:
		static const uint JREFHEADBAR = 1;
		static const uint JREFLIST = 2;
		static const uint JREFREC = 3;

	public:
		StatShr(const ubigint jrefHeadbar = 0, const ubigint jrefList = 0, const ubigint jrefRec = 0);

	public:
		ubigint jrefHeadbar;
		ubigint jrefList;
		ubigint jrefRec;

	public:
		void writeXML(pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagMsdcUsg)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixMsdcVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppDo (full: DpchAppMsdcUsgDo)
		*/
	class DpchAppDo : public DpchAppMsdc {

	public:
		static const uint JREF = 1;
		static const uint IXVDO = 2;

	public:
		DpchAppDo();

	public:
		uint ixVDo;

	public:
		string getSrefsMask();

		void readXML(pthread_mutex_t* mScr, map<string,ubigint>& descr, xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngData (full: DpchEngMsdcUsgData)
		*/
	class DpchEngData : public DpchEngMsdc {

	public:
		static const uint JREF = 1;
		static const uint CONTINF = 2;
		static const uint FEEDFSGE = 3;
		static const uint STATAPP = 4;
		static const uint STATSHR = 5;
		static const uint TAG = 6;
		static const uint ALL = 7;

	public:
		DpchEngData(const ubigint jref = 0, ContInf* continf = NULL, Feed* feedFSge = NULL, StatShr* statshr = NULL, const set<uint>& mask = {NONE});

	public:
		ContInf continf;
		Feed feedFSge;
		StatShr statshr;

	public:
		string getSrefsMask();
		void merge(DpchEngMsdc* dpcheng);

		void writeXML(const uint ixMsdcVLocale, pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
	};

public:
	CrdMsdcUsg(XchgMsdc* xchg, DbsMsdc* dbsmsdc, const ubigint jrefSup, const uint ixMsdcVLocale, const ubigint ref = 0);
	~CrdMsdcUsg();

public:
	ContInf continf;
	StatShr statshr;

	Feed feedFMcbAlert;
	Feed feedFSge;

	PnlMsdcUsgRec* pnlrec;
	PnlMsdcUsgHeadbar* pnlheadbar;
	PnlMsdcUsgList* pnllist;

	// IP custVar --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngMsdc* getNewDpchEng(set<uint> items);
	void refresh(DbsMsdc* dbsmsdc, set<uint>& moditems);
	void changeRef(DbsMsdc* dbsmsdc, const ubigint jrefTrig, const ubigint ref, const bool notif = false);
	void updatePreset(DbsMsdc* dbsmsdc, const uint ixMsdcVPreset, const ubigint jrefTrig, const bool notif = false);

public:
	void changeStage(DbsMsdc* dbsmsdc, uint _ixVSge, DpchEngMsdc** dpcheng = NULL);

	uint enterSgeIdle(DbsMsdc* dbsmsdc, const bool reenter);
	void leaveSgeIdle(DbsMsdc* dbsmsdc);
	uint enterSgeAlrmsdcabt(DbsMsdc* dbsmsdc, const bool reenter);
	void leaveSgeAlrmsdcabt(DbsMsdc* dbsmsdc);

	string getSquawk(DbsMsdc* dbsmsdc);

	void handleRequest(DbsMsdc* dbsmsdc, ReqMsdc* req);

	void handleDpchAppMsdcInit(DbsMsdc* dbsmsdc, DpchAppMsdcInit* dpchappmsdcinit, DpchEngMsdc** dpcheng);

	void handleDpchAppDoClose(DbsMsdc* dbsmsdc, DpchEngMsdc** dpcheng);
	void handleDpchAppDoMitAppAbtClick(DbsMsdc* dbsmsdc, DpchEngMsdc** dpcheng);
	void handleDpchAppMsdcAlert(DbsMsdc* dbsmsdc, DpchAppMsdcAlert* dpchappmsdcalert, DpchEngMsdc** dpcheng);

	void handleCall(DbsMsdc* dbsmsdc, Call* call);

	bool handleCallMsdcDlgClose(DbsMsdc* dbsmsdc, const ubigint jrefTrig);
	bool handleCallMsdcStatChg(DbsMsdc* dbsmsdc, const ubigint jrefTrig);
	bool handleCallMsdcRefPreSet(DbsMsdc* dbsmsdc, const ubigint jrefTrig, const uint ixInv, const ubigint refInv);
};

#endif

