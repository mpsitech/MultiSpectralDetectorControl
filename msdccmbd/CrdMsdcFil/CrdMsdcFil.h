/**
  * \file CrdMsdcFil.h
  * job handler for job CrdMsdcFil (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Oct 2018
  * \date modified: 4 Oct 2018
  */

#ifndef CRDMSDCFIL_H
#define CRDMSDCFIL_H

// IP custInclude --- INSERT

#include "DlgMsdcFilDownload.h"
#include "PnlMsdcFilRec.h"
#include "PnlMsdcFilHeadbar.h"
#include "PnlMsdcFilList.h"

#define VecVMsdcFilDo CrdMsdcFil::VecVDo
#define VecVMsdcFilSge CrdMsdcFil::VecVSge

#define ContInfMsdcFil CrdMsdcFil::ContInf
#define StatAppMsdcFil CrdMsdcFil::StatApp
#define StatShrMsdcFil CrdMsdcFil::StatShr
#define TagMsdcFil CrdMsdcFil::Tag

#define DpchAppMsdcFilDo CrdMsdcFil::DpchAppDo
#define DpchEngMsdcFilData CrdMsdcFil::DpchEngData

/**
  * CrdMsdcFil
  */
class CrdMsdcFil : public JobMsdc {

public:
	/**
		* VecVDo (full: VecVMsdcFilDo)
		*/
	class VecVDo {

	public:
		static const uint CLOSE = 1;
		static const uint MITAPPABTCLICK = 2;
		static const uint MITCRDDLDCLICK = 3;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
		* VecVSge (full: VecVMsdcFilSge)
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
	  * ContInf (full: ContInfMsdcFil)
	  */
	class ContInf : public Block {

	public:
		static const uint NUMFSGE = 1;
		static const uint MRLAPPHLP = 2;
		static const uint MTXCRDFIL = 3;

	public:
		ContInf(const uint numFSge = 1, const string& MrlAppHlp = "", const string& MtxCrdFil = "");

	public:
		uint numFSge;
		string MrlAppHlp;
		string MtxCrdFil;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppMsdcFil)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const uint ixMsdcVReqitmode = VecMsdcVReqitmode::IDLE, const usmallint latency = 5, const string& shortMenu = "", const uint widthMenu = 0, const bool initdoneHeadbar = false, const bool initdoneList = false, const bool initdoneRec = false);
	};

	/**
		* StatShr (full: StatShrMsdcFil)
		*/
	class StatShr : public Block {

	public:
		static const uint JREFDLGDOWNLOAD = 1;
		static const uint JREFHEADBAR = 2;
		static const uint JREFLIST = 3;
		static const uint JREFREC = 4;
		static const uint MITCRDDLDAVAIL = 5;
		static const uint MITCRDDLDACTIVE = 6;

	public:
		StatShr(const ubigint jrefDlgdownload = 0, const ubigint jrefHeadbar = 0, const ubigint jrefList = 0, const ubigint jrefRec = 0, const bool MitCrdDldAvail = true, const bool MitCrdDldActive = true);

	public:
		ubigint jrefDlgdownload;
		ubigint jrefHeadbar;
		ubigint jrefList;
		ubigint jrefRec;
		bool MitCrdDldAvail;
		bool MitCrdDldActive;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagMsdcFil)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixMsdcVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppDo (full: DpchAppMsdcFilDo)
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

		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngData (full: DpchEngMsdcFilData)
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

		void writeXML(const uint ixMsdcVLocale, xmlTextWriter* wr);
	};

	bool evalMitCrdDldAvail(DbsMsdc* dbsmsdc);
	bool evalMitCrdDldActive(DbsMsdc* dbsmsdc);

public:
	CrdMsdcFil(XchgMsdc* xchg, DbsMsdc* dbsmsdc, const ubigint jrefSup, const uint ixMsdcVLocale, const ubigint ref = 0, const uint ixMsdcVPreset = VecMsdcVPreset::VOID, const ubigint preUref = 0);
	~CrdMsdcFil();

public:
	ContInf continf;
	StatShr statshr;

	Feed feedFMcbAlert;
	Feed feedFSge;

	DlgMsdcFilDownload* dlgdownload;
	PnlMsdcFilRec* pnlrec;
	PnlMsdcFilHeadbar* pnlheadbar;
	PnlMsdcFilList* pnllist;

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
	void handleDpchAppDoMitCrdDldClick(DbsMsdc* dbsmsdc, DpchEngMsdc** dpcheng);
	void handleDpchAppMsdcAlert(DbsMsdc* dbsmsdc, DpchAppMsdcAlert* dpchappmsdcalert, DpchEngMsdc** dpcheng);

	void handleCall(DbsMsdc* dbsmsdc, Call* call);

	bool handleCallMsdcDlgClose(DbsMsdc* dbsmsdc, const ubigint jrefTrig);
	bool handleCallMsdcStatChg(DbsMsdc* dbsmsdc, const ubigint jrefTrig);
	bool handleCallMsdcRefPreSet(DbsMsdc* dbsmsdc, const ubigint jrefTrig, const uint ixInv, const ubigint refInv);
};

#endif

