/**
  * \file PnlMsdcLivScill.h
  * job handler for job PnlMsdcLivScill (declarations)
  * \author Alexander Wirthmueller
  * \date created: 18 Dec 2018
  * \date modified: 18 Dec 2018
  */

#ifndef PNLMSDCLIVSCILL_H
#define PNLMSDCLIVSCILL_H

// IP custInclude --- INSERT

#include "JobMsdcActLed.h"

#define VecVMsdcLivScillDo PnlMsdcLivScill::VecVDo

#define ContIacMsdcLivScill PnlMsdcLivScill::ContIac
#define ContInfMsdcLivScill PnlMsdcLivScill::ContInf
#define StatShrMsdcLivScill PnlMsdcLivScill::StatShr
#define TagMsdcLivScill PnlMsdcLivScill::Tag

#define DpchAppMsdcLivScillData PnlMsdcLivScill::DpchAppData
#define DpchAppMsdcLivScillDo PnlMsdcLivScill::DpchAppDo
#define DpchEngMsdcLivScillData PnlMsdcLivScill::DpchEngData

/**
  * PnlMsdcLivScill
  */
class PnlMsdcLivScill : public JobMsdc {

public:
	/**
		* VecVDo (full: VecVMsdcLivScillDo)
		*/
	class VecVDo {

	public:
		static const uint BUTREGULARIZECLICK = 1;
		static const uint BUTMINIMIZECLICK = 2;
		static const uint BUTMASTERCLICK = 3;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacMsdcLivScill)
	  */
	class ContIac : public Block {

	public:
		static const uint SLDFLD = 1;
		static const uint SLDSPT = 2;

	public:
		ContIac(const double SldFld = 0.5, const double SldSpt = 0.5);

	public:
		double SldFld;
		double SldSpt;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfMsdcLivScill)
	  */
	class ContInf : public Block {

	public:
		static const uint BUTMASTERON = 1;

	public:
		ContInf(const bool ButMasterOn = false);

	public:
		bool ButMasterOn;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
		* StatShr (full: StatShrMsdcLivScill)
		*/
	class StatShr : public Block {

	public:
		static const uint IXMSDCVEXPSTATE = 1;
		static const uint SLDFLDACTIVE = 2;
		static const uint SLDFLDMIN = 3;
		static const uint SLDFLDMAX = 4;
		static const uint SLDSPTACTIVE = 5;
		static const uint SLDSPTMIN = 6;
		static const uint SLDSPTMAX = 7;

	public:
		StatShr(const uint ixMsdcVExpstate = VecMsdcVExpstate::MIND, const bool SldFldActive = true, const double SldFldMin = 0.0, const double SldFldMax = 1.0, const bool SldSptActive = true, const double SldSptMin = 0.0, const double SldSptMax = 1.0);

	public:
		uint ixMsdcVExpstate;
		bool SldFldActive;
		double SldFldMin;
		double SldFldMax;
		bool SldSptActive;
		double SldSptMin;
		double SldSptMax;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagMsdcLivScill)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixMsdcVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppMsdcLivScillData)
		*/
	class DpchAppData : public DpchAppMsdc {

	public:
		static const uint JREF = 1;
		static const uint CONTIAC = 2;

	public:
		DpchAppData();

	public:
		ContIac contiac;

	public:
		string getSrefsMask();

		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppMsdcLivScillDo)
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
		* DpchEngData (full: DpchEngMsdcLivScillData)
		*/
	class DpchEngData : public DpchEngMsdc {

	public:
		static const uint JREF = 1;
		static const uint CONTIAC = 2;
		static const uint CONTINF = 3;
		static const uint STATSHR = 4;
		static const uint TAG = 5;
		static const uint ALL = 6;

	public:
		DpchEngData(const ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, StatShr* statshr = NULL, const set<uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		StatShr statshr;

	public:
		string getSrefsMask();
		void merge(DpchEngMsdc* dpcheng);

		void writeXML(const uint ixMsdcVLocale, xmlTextWriter* wr);
	};

	bool evalSldFldActive(DbsMsdc* dbsmsdc);
	bool evalSldSptActive(DbsMsdc* dbsmsdc);

public:
	PnlMsdcLivScill(XchgMsdc* xchg, DbsMsdc* dbsmsdc, const ubigint jrefSup, const uint ixMsdcVLocale);
	~PnlMsdcLivScill();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;

	JobMsdcActLed* actled;

	// IP custVar --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngMsdc* getNewDpchEng(set<uint> items);

	void refresh(DbsMsdc* dbsmsdc, set<uint>& moditems);

public:

	void handleRequest(DbsMsdc* dbsmsdc, ReqMsdc* req);

	void handleDpchAppMsdcInit(DbsMsdc* dbsmsdc, DpchAppMsdcInit* dpchappmsdcinit, DpchEngMsdc** dpcheng);
	void handleDpchAppDataContiac(DbsMsdc* dbsmsdc, ContIac* _contiac, DpchEngMsdc** dpcheng);

	void handleDpchAppDoButRegularizeClick(DbsMsdc* dbsmsdc, DpchEngMsdc** dpcheng);
	void handleDpchAppDoButMinimizeClick(DbsMsdc* dbsmsdc, DpchEngMsdc** dpcheng);
	void handleDpchAppDoButMasterClick(DbsMsdc* dbsmsdc, DpchEngMsdc** dpcheng);

	void handleCall(DbsMsdc* dbsmsdc, Call* call);

	bool handleCallMsdcMastslvChg(DbsMsdc* dbsmsdc, const ubigint jrefTrig);
	bool handleCallMsdcShrdatChg(DbsMsdc* dbsmsdc, const ubigint jrefTrig, const uint ixInv, const string& srefInv);
};

#endif

