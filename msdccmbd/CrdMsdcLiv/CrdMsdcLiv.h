/**
  * \file CrdMsdcLiv.h
  * job handler for job CrdMsdcLiv (declarations)
  * \author Alexander Wirthmueller
  * \date created: 12 Sep 2018
  * \date modified: 12 Sep 2018
  */

#ifndef CRDMSDCLIV_H
#define CRDMSDCLIV_H

// IP custInclude --- INSERT

#include "PnlMsdcLivVideo.h"
#include "PnlMsdcLivAlign.h"
#include "PnlMsdcLivScill.h"
#include "PnlMsdcLivTrack.h"
#include "PnlMsdcLivHeadbar.h"

#define VecVMsdcLivDo CrdMsdcLiv::VecVDo
#define VecVMsdcLivSge CrdMsdcLiv::VecVSge

#define ContInfMsdcLiv CrdMsdcLiv::ContInf
#define StatAppMsdcLiv CrdMsdcLiv::StatApp
#define StatShrMsdcLiv CrdMsdcLiv::StatShr
#define TagMsdcLiv CrdMsdcLiv::Tag

#define DpchAppMsdcLivDo CrdMsdcLiv::DpchAppDo
#define DpchEngMsdcLivData CrdMsdcLiv::DpchEngData

/**
  * CrdMsdcLiv
  */
class CrdMsdcLiv : public JobMsdc {

public:
	/**
		* VecVDo (full: VecVMsdcLivDo)
		*/
	class VecVDo {

	public:
		static const uint CLOSE = 1;
		static const uint MITAPPABTCLICK = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
		* VecVSge (full: VecVMsdcLivSge)
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
	  * ContInf (full: ContInfMsdcLiv)
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
		* StatApp (full: StatAppMsdcLiv)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const uint ixMsdcVReqitmode = VecMsdcVReqitmode::IDLE, const usmallint latency = 5, const string& shortMenu = "", const uint widthMenu = 0, const bool initdoneVideo = false, const bool initdoneAlign = false, const bool initdoneScill = false, const bool initdoneTrack = false, const bool initdoneHeadbar = false);
	};

	/**
		* StatShr (full: StatShrMsdcLiv)
		*/
	class StatShr : public Block {

	public:
		static const uint JREFVIDEO = 1;
		static const uint JREFALIGN = 2;
		static const uint JREFSCILL = 3;
		static const uint JREFTRACK = 4;
		static const uint JREFHEADBAR = 5;

	public:
		StatShr(const ubigint jrefVideo = 0, const ubigint jrefAlign = 0, const ubigint jrefScill = 0, const ubigint jrefTrack = 0, const ubigint jrefHeadbar = 0);

	public:
		ubigint jrefVideo;
		ubigint jrefAlign;
		ubigint jrefScill;
		ubigint jrefTrack;
		ubigint jrefHeadbar;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagMsdcLiv)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixMsdcVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppDo (full: DpchAppMsdcLivDo)
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
		* DpchEngData (full: DpchEngMsdcLivData)
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

public:
	CrdMsdcLiv(XchgMsdc* xchg, DbsMsdc* dbsmsdc, const ubigint jrefSup, const uint ixMsdcVLocale);
	~CrdMsdcLiv();

public:
	ContInf continf;
	StatShr statshr;

	Feed feedFMcbAlert;
	Feed feedFSge;

	PnlMsdcLivVideo* pnlvideo;
	PnlMsdcLivAlign* pnlalign;
	PnlMsdcLivScill* pnlscill;
	PnlMsdcLivTrack* pnltrack;
	PnlMsdcLivHeadbar* pnlheadbar;

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

