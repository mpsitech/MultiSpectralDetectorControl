/**
  * \file PnlMsdcUsgRec.h
  * job handler for job PnlMsdcUsgRec (declarations)
  * \author Alexander Wirthmueller
  * \date created: 15 Aug 2018
  * \date modified: 15 Aug 2018
  */

#ifndef PNLMSDCUSGREC_H
#define PNLMSDCUSGREC_H

// IP custInclude --- INSERT

#include "PnlMsdcUsgDetail.h"
#include "PnlMsdcUsgAAccess.h"
#include "PnlMsdcUsgMNUser.h"

#define VecVMsdcUsgRecDo PnlMsdcUsgRec::VecVDo

#define ContInfMsdcUsgRec PnlMsdcUsgRec::ContInf
#define StatAppMsdcUsgRec PnlMsdcUsgRec::StatApp
#define StatShrMsdcUsgRec PnlMsdcUsgRec::StatShr
#define TagMsdcUsgRec PnlMsdcUsgRec::Tag

#define DpchAppMsdcUsgRecDo PnlMsdcUsgRec::DpchAppDo
#define DpchEngMsdcUsgRecData PnlMsdcUsgRec::DpchEngData

/**
  * PnlMsdcUsgRec
  */
class PnlMsdcUsgRec : public JobMsdc {

public:
	/**
		* VecVDo (full: VecVMsdcUsgRecDo)
		*/
	class VecVDo {

	public:
		static const uint BUTMINIMIZECLICK = 1;
		static const uint BUTREGULARIZECLICK = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContInf (full: ContInfMsdcUsgRec)
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
		* StatApp (full: StatAppMsdcUsgRec)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const bool initdoneDetail = false, const bool initdoneAAccess = false, const bool initdoneMNUser = false);
	};

	/**
		* StatShr (full: StatShrMsdcUsgRec)
		*/
	class StatShr : public Block {

	public:
		static const uint IXMSDCVEXPSTATE = 1;
		static const uint JREFDETAIL = 2;
		static const uint JREFAACCESS = 3;
		static const uint JREFMNUSER = 4;
		static const uint BUTREGULARIZEACTIVE = 5;

	public:
		StatShr(const uint ixMsdcVExpstate = VecMsdcVExpstate::REGD, const ubigint jrefDetail = 0, const ubigint jrefAAccess = 0, const ubigint jrefMNUser = 0, const bool ButRegularizeActive = true);

	public:
		uint ixMsdcVExpstate;
		ubigint jrefDetail;
		ubigint jrefAAccess;
		ubigint jrefMNUser;
		bool ButRegularizeActive;

	public:
		void writeXML(pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagMsdcUsgRec)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixMsdcVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppDo (full: DpchAppMsdcUsgRecDo)
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
		* DpchEngData (full: DpchEngMsdcUsgRecData)
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

		void writeXML(const uint ixMsdcVLocale, pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
	};

	bool evalButRegularizeActive(DbsMsdc* dbsmsdc);

public:
	PnlMsdcUsgRec(XchgMsdc* xchg, DbsMsdc* dbsmsdc, const ubigint jrefSup, const uint ixMsdcVLocale);
	~PnlMsdcUsgRec();

public:
	ContInf continf;
	StatShr statshr;

	PnlMsdcUsgDetail* pnldetail;
	PnlMsdcUsgAAccess* pnlaaccess;
	PnlMsdcUsgMNUser* pnlmnuser;

	MsdcMUsergroup recUsg;

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

	bool handleCallMsdcUsgUpd_refEq(DbsMsdc* dbsmsdc, const ubigint jrefTrig, const ubigint refInv);
};

#endif

