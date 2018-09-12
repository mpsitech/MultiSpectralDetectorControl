/**
  * \file PnlMsdcFilRec.h
  * job handler for job PnlMsdcFilRec (declarations)
  * \author Alexander Wirthmueller
  * \date created: 12 Sep 2018
  * \date modified: 12 Sep 2018
  */

#ifndef PNLMSDCFILREC_H
#define PNLMSDCFILREC_H

// IP custInclude --- INSERT

#include "PnlMsdcFilDetail.h"

#define VecVMsdcFilRecDo PnlMsdcFilRec::VecVDo

#define ContInfMsdcFilRec PnlMsdcFilRec::ContInf
#define StatAppMsdcFilRec PnlMsdcFilRec::StatApp
#define StatShrMsdcFilRec PnlMsdcFilRec::StatShr
#define TagMsdcFilRec PnlMsdcFilRec::Tag

#define DpchAppMsdcFilRecDo PnlMsdcFilRec::DpchAppDo
#define DpchEngMsdcFilRecData PnlMsdcFilRec::DpchEngData

/**
  * PnlMsdcFilRec
  */
class PnlMsdcFilRec : public JobMsdc {

public:
	/**
		* VecVDo (full: VecVMsdcFilRecDo)
		*/
	class VecVDo {

	public:
		static const uint BUTMINIMIZECLICK = 1;
		static const uint BUTREGULARIZECLICK = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContInf (full: ContInfMsdcFilRec)
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
		* StatApp (full: StatAppMsdcFilRec)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const bool initdoneDetail = false);
	};

	/**
		* StatShr (full: StatShrMsdcFilRec)
		*/
	class StatShr : public Block {

	public:
		static const uint IXMSDCVEXPSTATE = 1;
		static const uint JREFDETAIL = 2;
		static const uint BUTREGULARIZEACTIVE = 3;

	public:
		StatShr(const uint ixMsdcVExpstate = VecMsdcVExpstate::REGD, const ubigint jrefDetail = 0, const bool ButRegularizeActive = true);

	public:
		uint ixMsdcVExpstate;
		ubigint jrefDetail;
		bool ButRegularizeActive;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagMsdcFilRec)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixMsdcVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppDo (full: DpchAppMsdcFilRecDo)
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
		* DpchEngData (full: DpchEngMsdcFilRecData)
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
	PnlMsdcFilRec(XchgMsdc* xchg, DbsMsdc* dbsmsdc, const ubigint jrefSup, const uint ixMsdcVLocale);
	~PnlMsdcFilRec();

public:
	ContInf continf;
	StatShr statshr;

	PnlMsdcFilDetail* pnldetail;

	MsdcMFile recFil;

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

	bool handleCallMsdcFilUpd_refEq(DbsMsdc* dbsmsdc, const ubigint jrefTrig, const ubigint refInv);
};

#endif

