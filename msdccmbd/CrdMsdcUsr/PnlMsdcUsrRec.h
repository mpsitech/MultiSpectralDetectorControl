/**
  * \file PnlMsdcUsrRec.h
  * job handler for job PnlMsdcUsrRec (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Oct 2018
  * \date modified: 4 Oct 2018
  */

#ifndef PNLMSDCUSRREC_H
#define PNLMSDCUSRREC_H

// IP custInclude --- INSERT

#include "PnlMsdcUsrDetail.h"
#include "PnlMsdcUsrAAccess.h"
#include "PnlMsdcUsr1NSession.h"
#include "PnlMsdcUsrMNUsergroup.h"

#define VecVMsdcUsrRecDo PnlMsdcUsrRec::VecVDo

#define ContInfMsdcUsrRec PnlMsdcUsrRec::ContInf
#define StatAppMsdcUsrRec PnlMsdcUsrRec::StatApp
#define StatShrMsdcUsrRec PnlMsdcUsrRec::StatShr
#define TagMsdcUsrRec PnlMsdcUsrRec::Tag

#define DpchAppMsdcUsrRecDo PnlMsdcUsrRec::DpchAppDo
#define DpchEngMsdcUsrRecData PnlMsdcUsrRec::DpchEngData

/**
  * PnlMsdcUsrRec
  */
class PnlMsdcUsrRec : public JobMsdc {

public:
	/**
		* VecVDo (full: VecVMsdcUsrRecDo)
		*/
	class VecVDo {

	public:
		static const uint BUTMINIMIZECLICK = 1;
		static const uint BUTREGULARIZECLICK = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContInf (full: ContInfMsdcUsrRec)
	  */
	class ContInf : public Block {

	public:
		static const uint TXTREF = 1;

	public:
		ContInf(const string& TxtRef = "");

	public:
		string TxtRef;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppMsdcUsrRec)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const bool initdoneDetail = false, const bool initdoneAAccess = false, const bool initdone1NSession = false, const bool initdoneMNUsergroup = false);
	};

	/**
		* StatShr (full: StatShrMsdcUsrRec)
		*/
	class StatShr : public Block {

	public:
		static const uint IXMSDCVEXPSTATE = 1;
		static const uint JREFDETAIL = 2;
		static const uint JREFAACCESS = 3;
		static const uint JREF1NSESSION = 4;
		static const uint JREFMNUSERGROUP = 5;
		static const uint BUTREGULARIZEACTIVE = 6;

	public:
		StatShr(const uint ixMsdcVExpstate = VecMsdcVExpstate::REGD, const ubigint jrefDetail = 0, const ubigint jrefAAccess = 0, const ubigint jref1NSession = 0, const ubigint jrefMNUsergroup = 0, const bool ButRegularizeActive = true);

	public:
		uint ixMsdcVExpstate;
		ubigint jrefDetail;
		ubigint jrefAAccess;
		ubigint jref1NSession;
		ubigint jrefMNUsergroup;
		bool ButRegularizeActive;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagMsdcUsrRec)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixMsdcVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppDo (full: DpchAppMsdcUsrRecDo)
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
		* DpchEngData (full: DpchEngMsdcUsrRecData)
		*/
	class DpchEngData : public DpchEngMsdc {

	public:
		static const uint JREF = 1;
		static const uint CONTINF = 2;
		static const uint STATAPP = 3;
		static const uint STATSHR = 4;
		static const uint TAG = 5;
		static const uint ALL = 6;

	public:
		DpchEngData(const ubigint jref = 0, ContInf* continf = NULL, StatShr* statshr = NULL, const set<uint>& mask = {NONE});

	public:
		ContInf continf;
		StatShr statshr;

	public:
		string getSrefsMask();
		void merge(DpchEngMsdc* dpcheng);

		void writeXML(const uint ixMsdcVLocale, xmlTextWriter* wr);
	};

	bool evalButRegularizeActive(DbsMsdc* dbsmsdc);

public:
	PnlMsdcUsrRec(XchgMsdc* xchg, DbsMsdc* dbsmsdc, const ubigint jrefSup, const uint ixMsdcVLocale);
	~PnlMsdcUsrRec();

public:
	ContInf continf;
	StatShr statshr;

	PnlMsdcUsrDetail* pnldetail;
	PnlMsdcUsrAAccess* pnlaaccess;
	PnlMsdcUsr1NSession* pnl1nsession;
	PnlMsdcUsrMNUsergroup* pnlmnusergroup;

	MsdcMUser recUsr;

	// IP custVar --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngMsdc* getNewDpchEng(set<uint> items);

	void refresh(DbsMsdc* dbsmsdc, set<uint>& moditems);

	void updatePreset(DbsMsdc* dbsmsdc, const uint ixMsdcVPreset, const ubigint jrefTrig, const bool notif = false);
	void minimize(DbsMsdc* dbsmsdc, const bool notif = false, DpchEngMsdc** dpcheng = NULL);
	void regularize(DbsMsdc* dbsmsdc, const bool notif = false, DpchEngMsdc** dpcheng = NULL);

public:

	void handleRequest(DbsMsdc* dbsmsdc, ReqMsdc* req);

	void handleDpchAppMsdcInit(DbsMsdc* dbsmsdc, DpchAppMsdcInit* dpchappmsdcinit, DpchEngMsdc** dpcheng);

	void handleDpchAppDoButMinimizeClick(DbsMsdc* dbsmsdc, DpchEngMsdc** dpcheng);
	void handleDpchAppDoButRegularizeClick(DbsMsdc* dbsmsdc, DpchEngMsdc** dpcheng);

	void handleCall(DbsMsdc* dbsmsdc, Call* call);

	bool handleCallMsdcUsrUpd_refEq(DbsMsdc* dbsmsdc, const ubigint jrefTrig, const ubigint refInv);
};

#endif

