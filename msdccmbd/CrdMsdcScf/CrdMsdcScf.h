/**
  * \file CrdMsdcScf.h
  * job handler for job CrdMsdcScf (declarations)
  * \author Alexander Wirthmueller
  * \date created: 15 Aug 2018
  * \date modified: 15 Aug 2018
  */

#ifndef CRDMSDCSCF_H
#define CRDMSDCSCF_H

// IP custInclude --- INSERT

#include "PnlMsdcScfSource.h"
#include "PnlMsdcScfAcquis.h"
#include "PnlMsdcScfActu.h"
#include "PnlMsdcScfPrcctl.h"
#include "PnlMsdcScfHeadbar.h"

#define VecVMsdcScfDo CrdMsdcScf::VecVDo
#define VecVMsdcScfSge CrdMsdcScf::VecVSge

#define ContInfMsdcScf CrdMsdcScf::ContInf
#define StatAppMsdcScf CrdMsdcScf::StatApp
#define StatShrMsdcScf CrdMsdcScf::StatShr
#define TagMsdcScf CrdMsdcScf::Tag

#define DpchAppMsdcScfDo CrdMsdcScf::DpchAppDo
#define DpchEngMsdcScfData CrdMsdcScf::DpchEngData

/**
  * CrdMsdcScf
  */
class CrdMsdcScf : public JobMsdc {

public:
	/**
		* VecVDo (full: VecVMsdcScfDo)
		*/
	class VecVDo {

	public:
		static const uint CLOSE = 1;
		static const uint MITAPPABTCLICK = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
		* VecVSge (full: VecVMsdcScfSge)
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
	  * ContInf (full: ContInfMsdcScf)
	  */
	class ContInf : public Block {

	public:
		static const uint NUMFSGE = 1;
		static const uint MRLAPPHLP = 2;

	public:
		ContInf(const uint numFSge = 1, const string& MrlAppHlp = "");

	public:
		uint numFSge;
		string MrlAppHlp;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppMsdcScf)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const uint ixMsdcVReqitmode = VecMsdcVReqitmode::IDLE, const usmallint latency = 5, const string& shortMenu = "", const uint widthMenu = 0, const bool initdoneSource = false, const bool initdoneAcquis = false, const bool initdoneActu = false, const bool initdonePrcctl = false, const bool initdoneHeadbar = false);
	};

	/**
		* StatShr (full: StatShrMsdcScf)
		*/
	class StatShr : public Block {

	public:
		static const uint JREFSOURCE = 1;
		static const uint JREFACQUIS = 2;
		static const uint JREFACTU = 3;
		static const uint JREFPRCCTL = 4;
		static const uint JREFHEADBAR = 5;

	public:
		StatShr(const ubigint jrefSource = 0, const ubigint jrefAcquis = 0, const ubigint jrefActu = 0, const ubigint jrefPrcctl = 0, const ubigint jrefHeadbar = 0);

	public:
		ubigint jrefSource;
		ubigint jrefAcquis;
		ubigint jrefActu;
		ubigint jrefPrcctl;
		ubigint jrefHeadbar;

	public:
		void writeXML(pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagMsdcScf)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixMsdcVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppDo (full: DpchAppMsdcScfDo)
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
		* DpchEngData (full: DpchEngMsdcScfData)
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
	CrdMsdcScf(XchgMsdc* xchg, DbsMsdc* dbsmsdc, const ubigint jrefSup, const uint ixMsdcVLocale);
	~CrdMsdcScf();

public:
	ContInf continf;
	StatShr statshr;

	Feed feedFMcbAlert;
	Feed feedFSge;

	PnlMsdcScfSource* pnlsource;
	PnlMsdcScfAcquis* pnlacquis;
	PnlMsdcScfActu* pnlactu;
	PnlMsdcScfPrcctl* pnlprcctl;
	PnlMsdcScfHeadbar* pnlheadbar;

	// IP custVar --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngMsdc* getNewDpchEng(set<uint> items);
	void refresh(DbsMsdc* dbsmsdc, set<uint>& moditems);
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
};

#endif

