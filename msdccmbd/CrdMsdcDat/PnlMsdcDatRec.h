/**
  * \file PnlMsdcDatRec.h
  * job handler for job PnlMsdcDatRec (declarations)
  * \author Alexander Wirthmueller
  * \date created: 12 Sep 2018
  * \date modified: 12 Sep 2018
  */

#ifndef PNLMSDCDATREC_H
#define PNLMSDCDATREC_H

// IP custInclude --- INSERT

#include "PnlMsdcDatDetail.h"
#include "PnlMsdcDatAPar.h"
#include "PnlMsdcDatRef1NFile.h"

#define VecVMsdcDatRecDo PnlMsdcDatRec::VecVDo

#define ContInfMsdcDatRec PnlMsdcDatRec::ContInf
#define StatAppMsdcDatRec PnlMsdcDatRec::StatApp
#define StatShrMsdcDatRec PnlMsdcDatRec::StatShr
#define TagMsdcDatRec PnlMsdcDatRec::Tag

#define DpchAppMsdcDatRecDo PnlMsdcDatRec::DpchAppDo
#define DpchEngMsdcDatRecData PnlMsdcDatRec::DpchEngData

/**
  * PnlMsdcDatRec
  */
class PnlMsdcDatRec : public JobMsdc {

public:
	/**
		* VecVDo (full: VecVMsdcDatRecDo)
		*/
	class VecVDo {

	public:
		static const uint BUTMINIMIZECLICK = 1;
		static const uint BUTREGULARIZECLICK = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContInf (full: ContInfMsdcDatRec)
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
		* StatApp (full: StatAppMsdcDatRec)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const bool initdoneDetail = false, const bool initdoneAPar = false, const bool initdoneRef1NFile = false);
	};

	/**
		* StatShr (full: StatShrMsdcDatRec)
		*/
	class StatShr : public Block {

	public:
		static const uint IXMSDCVEXPSTATE = 1;
		static const uint JREFDETAIL = 2;
		static const uint JREFAPAR = 3;
		static const uint JREFREF1NFILE = 4;
		static const uint BUTREGULARIZEACTIVE = 5;

	public:
		StatShr(const uint ixMsdcVExpstate = VecMsdcVExpstate::REGD, const ubigint jrefDetail = 0, const ubigint jrefAPar = 0, const ubigint jrefRef1NFile = 0, const bool ButRegularizeActive = true);

	public:
		uint ixMsdcVExpstate;
		ubigint jrefDetail;
		ubigint jrefAPar;
		ubigint jrefRef1NFile;
		bool ButRegularizeActive;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagMsdcDatRec)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixMsdcVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppDo (full: DpchAppMsdcDatRecDo)
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
		* DpchEngData (full: DpchEngMsdcDatRecData)
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
	PnlMsdcDatRec(XchgMsdc* xchg, DbsMsdc* dbsmsdc, const ubigint jrefSup, const uint ixMsdcVLocale);
	~PnlMsdcDatRec();

public:
	ContInf continf;
	StatShr statshr;

	PnlMsdcDatDetail* pnldetail;
	PnlMsdcDatAPar* pnlapar;
	PnlMsdcDatRef1NFile* pnlref1nfile;

	MsdcMData recDat;

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

	bool handleCallMsdcDatUpd_refEq(DbsMsdc* dbsmsdc, const ubigint jrefTrig, const ubigint refInv);
};

#endif

