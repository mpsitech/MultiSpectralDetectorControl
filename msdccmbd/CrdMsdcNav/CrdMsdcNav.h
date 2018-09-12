/**
  * \file CrdMsdcNav.h
  * job handler for job CrdMsdcNav (declarations)
  * \author Alexander Wirthmueller
  * \date created: 12 Sep 2018
  * \date modified: 12 Sep 2018
  */

#ifndef CRDMSDCNAV_H
#define CRDMSDCNAV_H

// IP custInclude --- INSERT

#include "DlgMsdcNavLoaini.h"
#include "PnlMsdcNavHeadbar.h"
#include "PnlMsdcNavPre.h"
#include "PnlMsdcNavAdmin.h"
#include "PnlMsdcNavOpr.h"

#define VecVMsdcNavDo CrdMsdcNav::VecVDo
#define VecVMsdcNavSge CrdMsdcNav::VecVSge

#define ContInfMsdcNav CrdMsdcNav::ContInf
#define StatAppMsdcNav CrdMsdcNav::StatApp
#define StatShrMsdcNav CrdMsdcNav::StatShr
#define TagMsdcNav CrdMsdcNav::Tag

#define DpchAppMsdcNavDo CrdMsdcNav::DpchAppDo
#define DpchEngMsdcNavData CrdMsdcNav::DpchEngData

/**
  * CrdMsdcNav
  */
class CrdMsdcNav : public JobMsdc {

public:
	/**
		* VecVDo (full: VecVMsdcNavDo)
		*/
	class VecVDo {

	public:
		static const uint CLOSE = 1;
		static const uint MITAPPABTCLICK = 2;
		static const uint MITSESSPSCLICK = 3;
		static const uint MITSESTRMCLICK = 4;
		static const uint MITCRDUSGCLICK = 5;
		static const uint MITCRDUSRCLICK = 6;
		static const uint MITCRDPRSCLICK = 7;
		static const uint MITCRDSCFCLICK = 8;
		static const uint MITCRDLIVCLICK = 9;
		static const uint MITCRDPRDCLICK = 10;
		static const uint MITCRDDATCLICK = 11;
		static const uint MITCRDFILCLICK = 12;
		static const uint MITAPPLOICLICK = 13;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
		* VecVSge (full: VecVMsdcNavSge)
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
	  * ContInf (full: ContInfMsdcNav)
	  */
	class ContInf : public Block {

	public:
		static const uint NUMFSGE = 1;
		static const uint MRLAPPHLP = 2;
		static const uint MTXSESSES1 = 3;
		static const uint MTXSESSES2 = 4;
		static const uint MTXSESSES3 = 5;

	public:
		ContInf(const uint numFSge = 1, const string& MrlAppHlp = "", const string& MtxSesSes1 = "", const string& MtxSesSes2 = "", const string& MtxSesSes3 = "");

	public:
		uint numFSge;
		string MrlAppHlp;
		string MtxSesSes1;
		string MtxSesSes2;
		string MtxSesSes3;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppMsdcNav)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const uint ixMsdcVReqitmode = VecMsdcVReqitmode::IDLE, const usmallint latency = 5, const string& shortMenu = "", const uint widthMenu = 0, const bool initdoneHeadbar = false, const bool initdonePre = false, const bool initdoneAdmin = false, const bool initdoneOpr = false);
	};

	/**
		* StatShr (full: StatShrMsdcNav)
		*/
	class StatShr : public Block {

	public:
		static const uint JREFDLGLOAINI = 1;
		static const uint JREFHEADBAR = 2;
		static const uint JREFPRE = 3;
		static const uint PNLPREAVAIL = 4;
		static const uint JREFADMIN = 5;
		static const uint PNLADMINAVAIL = 6;
		static const uint JREFOPR = 7;
		static const uint PNLOPRAVAIL = 8;
		static const uint MSPCRD1AVAIL = 9;
		static const uint MITCRDUSGAVAIL = 10;
		static const uint MITCRDUSRAVAIL = 11;
		static const uint MITCRDPRSAVAIL = 12;
		static const uint MITCRDSCFAVAIL = 13;
		static const uint MSPCRD2AVAIL = 14;
		static const uint MITCRDLIVAVAIL = 15;
		static const uint MITCRDPRDAVAIL = 16;
		static const uint MITCRDDATAVAIL = 17;
		static const uint MITCRDDATACTIVE = 18;
		static const uint MITCRDFILAVAIL = 19;
		static const uint MSPAPP2AVAIL = 20;
		static const uint MITAPPLOIAVAIL = 21;

	public:
		StatShr(const ubigint jrefDlgloaini = 0, const ubigint jrefHeadbar = 0, const ubigint jrefPre = 0, const bool pnlpreAvail = false, const ubigint jrefAdmin = 0, const bool pnladminAvail = false, const ubigint jrefOpr = 0, const bool pnloprAvail = false, const bool MspCrd1Avail = true, const bool MitCrdUsgAvail = true, const bool MitCrdUsrAvail = true, const bool MitCrdPrsAvail = true, const bool MitCrdScfAvail = true, const bool MspCrd2Avail = true, const bool MitCrdLivAvail = true, const bool MitCrdPrdAvail = true, const bool MitCrdDatAvail = true, const bool MitCrdDatActive = true, const bool MitCrdFilAvail = true, const bool MspApp2Avail = true, const bool MitAppLoiAvail = true);

	public:
		ubigint jrefDlgloaini;
		ubigint jrefHeadbar;
		ubigint jrefPre;
		bool pnlpreAvail;
		ubigint jrefAdmin;
		bool pnladminAvail;
		ubigint jrefOpr;
		bool pnloprAvail;
		bool MspCrd1Avail;
		bool MitCrdUsgAvail;
		bool MitCrdUsrAvail;
		bool MitCrdPrsAvail;
		bool MitCrdScfAvail;
		bool MspCrd2Avail;
		bool MitCrdLivAvail;
		bool MitCrdPrdAvail;
		bool MitCrdDatAvail;
		bool MitCrdDatActive;
		bool MitCrdFilAvail;
		bool MspApp2Avail;
		bool MitAppLoiAvail;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagMsdcNav)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixMsdcVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppDo (full: DpchAppMsdcNavDo)
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
		* DpchEngData (full: DpchEngMsdcNavData)
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

	bool evalPnlpreAvail(DbsMsdc* dbsmsdc);
	bool evalPnladminAvail(DbsMsdc* dbsmsdc);
	bool evalPnloprAvail(DbsMsdc* dbsmsdc);
	bool evalMspCrd1Avail(DbsMsdc* dbsmsdc);
	bool evalMitCrdUsgAvail(DbsMsdc* dbsmsdc);
	bool evalMitCrdUsrAvail(DbsMsdc* dbsmsdc);
	bool evalMitCrdPrsAvail(DbsMsdc* dbsmsdc);
	bool evalMitCrdScfAvail(DbsMsdc* dbsmsdc);
	bool evalMspCrd2Avail(DbsMsdc* dbsmsdc);
	bool evalMitCrdLivAvail(DbsMsdc* dbsmsdc);
	bool evalMitCrdPrdAvail(DbsMsdc* dbsmsdc);
	bool evalMitCrdDatAvail(DbsMsdc* dbsmsdc);
	bool evalMitCrdDatActive(DbsMsdc* dbsmsdc);
	bool evalMitCrdFilAvail(DbsMsdc* dbsmsdc);
	bool evalMspApp2Avail(DbsMsdc* dbsmsdc);
	bool evalMitAppLoiAvail(DbsMsdc* dbsmsdc);

public:
	CrdMsdcNav(XchgMsdc* xchg, DbsMsdc* dbsmsdc, const ubigint jrefSup, const uint ixMsdcVLocale);
	~CrdMsdcNav();

public:
	ContInf continf;
	StatShr statshr;

	Feed feedFMcbAlert;
	Feed feedFSge;

	DlgMsdcNavLoaini* dlgloaini;
	PnlMsdcNavHeadbar* pnlheadbar;
	PnlMsdcNavPre* pnlpre;
	PnlMsdcNavAdmin* pnladmin;
	PnlMsdcNavOpr* pnlopr;

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
	void handleDpchAppDoMitSesSpsClick(DbsMsdc* dbsmsdc, DpchEngMsdc** dpcheng);
	void handleDpchAppDoMitSesTrmClick(DbsMsdc* dbsmsdc, DpchEngMsdc** dpcheng);
	void handleDpchAppDoMitCrdUsgClick(DbsMsdc* dbsmsdc, DpchEngMsdc** dpcheng);
	void handleDpchAppDoMitCrdUsrClick(DbsMsdc* dbsmsdc, DpchEngMsdc** dpcheng);
	void handleDpchAppDoMitCrdPrsClick(DbsMsdc* dbsmsdc, DpchEngMsdc** dpcheng);
	void handleDpchAppDoMitCrdScfClick(DbsMsdc* dbsmsdc, DpchEngMsdc** dpcheng);
	void handleDpchAppDoMitCrdLivClick(DbsMsdc* dbsmsdc, DpchEngMsdc** dpcheng);
	void handleDpchAppDoMitCrdPrdClick(DbsMsdc* dbsmsdc, DpchEngMsdc** dpcheng);
	void handleDpchAppDoMitCrdDatClick(DbsMsdc* dbsmsdc, DpchEngMsdc** dpcheng);
	void handleDpchAppDoMitCrdFilClick(DbsMsdc* dbsmsdc, DpchEngMsdc** dpcheng);
	void handleDpchAppDoMitAppLoiClick(DbsMsdc* dbsmsdc, DpchEngMsdc** dpcheng);
	void handleDpchAppMsdcAlert(DbsMsdc* dbsmsdc, DpchAppMsdcAlert* dpchappmsdcalert, DpchEngMsdc** dpcheng);

	void handleCall(DbsMsdc* dbsmsdc, Call* call);

	bool handleCallMsdcDlgClose(DbsMsdc* dbsmsdc, const ubigint jrefTrig);
};

#endif

