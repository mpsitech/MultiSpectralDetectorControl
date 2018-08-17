/**
  * \file CrdMsdcDat.h
  * job handler for job CrdMsdcDat (declarations)
  * \author Alexander Wirthmueller
  * \date created: 15 Aug 2018
  * \date modified: 15 Aug 2018
  */

#ifndef CRDMSDCDAT_H
#define CRDMSDCDAT_H

// IP custInclude --- INSERT

#include "PnlMsdcDatRec.h"
#include "PnlMsdcDatHeadbar.h"
#include "PnlMsdcDatList.h"

#define VecVMsdcDatDo CrdMsdcDat::VecVDo
#define VecVMsdcDatSge CrdMsdcDat::VecVSge

#define ContInfMsdcDat CrdMsdcDat::ContInf
#define StatAppMsdcDat CrdMsdcDat::StatApp
#define StatShrMsdcDat CrdMsdcDat::StatShr
#define TagMsdcDat CrdMsdcDat::Tag

#define DpchAppMsdcDatDo CrdMsdcDat::DpchAppDo
#define DpchEngMsdcDatData CrdMsdcDat::DpchEngData

/**
  * CrdMsdcDat
  */
class CrdMsdcDat : public JobMsdc {

public:
	/**
		* VecVDo (full: VecVMsdcDatDo)
		*/
	class VecVDo {

	public:
		static const uint CLOSE = 1;
		static const uint MITAPPABTCLICK = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
		* VecVSge (full: VecVMsdcDatSge)
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
	  * ContInf (full: ContInfMsdcDat)
	  */
	class ContInf : public Block {

	public:
		static const uint NUMFSGE = 1;
		static const uint MRLAPPHLP = 2;
		static const uint MTXCRDDAT = 3;

	public:
		ContInf(const uint numFSge = 1, const string& MrlAppHlp = "", const string& MtxCrdDat = "");

	public:
		uint numFSge;
		string MrlAppHlp;
		string MtxCrdDat;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppMsdcDat)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const uint ixMsdcVReqitmode = VecMsdcVReqitmode::IDLE, const usmallint latency = 5, const string& shortMenu = "", const uint widthMenu = 0, const bool initdoneHeadbar = false, const bool initdoneList = false, const bool initdoneRec = false);
	};

	/**
		* StatShr (full: StatShrMsdcDat)
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
		* Tag (full: TagMsdcDat)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixMsdcVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppDo (full: DpchAppMsdcDatDo)
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
		* DpchEngData (full: DpchEngMsdcDatData)
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
	CrdMsdcDat(XchgMsdc* xchg, DbsMsdc* dbsmsdc, const ubigint jrefSup, const uint ixMsdcVLocale, const ubigint ref = 0, const uint ixMsdcVPreset = VecMsdcVPreset::VOID, const ubigint preUref = 0);
	~CrdMsdcDat();

public:
	ContInf continf;
	StatShr statshr;

	Feed feedFMcbAlert;
	Feed feedFSge;

	PnlMsdcDatRec* pnlrec;
	PnlMsdcDatHeadbar* pnlheadbar;
	PnlMsdcDatList* pnllist;

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

