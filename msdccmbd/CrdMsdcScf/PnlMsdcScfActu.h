/**
  * \file PnlMsdcScfActu.h
  * job handler for job PnlMsdcScfActu (declarations)
  * \author Alexander Wirthmueller
  * \date created: 18 Dec 2018
  * \date modified: 18 Dec 2018
  */

#ifndef PNLMSDCSCFACTU_H
#define PNLMSDCSCFACTU_H

// IP custInclude --- INSERT

#include "JobMsdcActLed.h"
#include "JobMsdcActServo.h"
#include "JobMsdcActAlign.h"

#define VecVMsdcScfActuDo PnlMsdcScfActu::VecVDo

#define ContIacMsdcScfActu PnlMsdcScfActu::ContIac
#define ContInfMsdcScfActu PnlMsdcScfActu::ContInf
#define StatAppMsdcScfActu PnlMsdcScfActu::StatApp
#define StatShrMsdcScfActu PnlMsdcScfActu::StatShr
#define TagMsdcScfActu PnlMsdcScfActu::Tag

#define DpchAppMsdcScfActuData PnlMsdcScfActu::DpchAppData
#define DpchAppMsdcScfActuDo PnlMsdcScfActu::DpchAppDo
#define DpchEngMsdcScfActuData PnlMsdcScfActu::DpchEngData

/**
  * PnlMsdcScfActu
  */
class PnlMsdcScfActu : public JobMsdc {

public:
	/**
		* VecVDo (full: VecVMsdcScfActuDo)
		*/
	class VecVDo {

	public:
		static const uint BUTMASTERCLICK = 1;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacMsdcScfActu)
	  */
	class ContIac : public Block {

	public:
		static const uint SLDSTM = 1;
		static const uint SLDSTX = 2;
		static const uint SLDSPM = 3;
		static const uint SLDSPX = 4;

	public:
		ContIac(const double SldStm = 0.0, const double SldStx = 0.0, const double SldSpm = 0.0, const double SldSpx = 0.0);

	public:
		double SldStm;
		double SldStx;
		double SldSpm;
		double SldSpx;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfMsdcScfActu)
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
		* StatApp (full: StatAppMsdcScfActu)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const uint ixMsdcVExpstate = VecMsdcVExpstate::MIND);
	};

	/**
		* StatShr (full: StatShrMsdcScfActu)
		*/
	class StatShr : public Block {

	public:
		static const uint SLDSTMMIN = 1;
		static const uint SLDSTMMAX = 2;
		static const uint SLDSTMRAST = 3;
		static const uint SLDSTXMIN = 4;
		static const uint SLDSTXMAX = 5;
		static const uint SLDSTXRAST = 6;
		static const uint SLDSPMMIN = 7;
		static const uint SLDSPMMAX = 8;
		static const uint SLDSPMRAST = 9;
		static const uint SLDSPXMIN = 10;
		static const uint SLDSPXMAX = 11;
		static const uint SLDSPXRAST = 12;

	public:
		StatShr(const double SldStmMin = -60.0, const double SldStmMax = 60.0, const double SldStmRast = 0.1, const double SldStxMin = -60.0, const double SldStxMax = 60.0, const double SldStxRast = 0.1, const double SldSpmMin = -60.0, const double SldSpmMax = 60.0, const double SldSpmRast = 0.1, const double SldSpxMin = -60.0, const double SldSpxMax = 60.0, const double SldSpxRast = 0.1);

	public:
		double SldStmMin;
		double SldStmMax;
		double SldStmRast;
		double SldStxMin;
		double SldStxMax;
		double SldStxRast;
		double SldSpmMin;
		double SldSpmMax;
		double SldSpmRast;
		double SldSpxMin;
		double SldSpxMax;
		double SldSpxRast;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagMsdcScfActu)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixMsdcVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppMsdcScfActuData)
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
		* DpchAppDo (full: DpchAppMsdcScfActuDo)
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
		* DpchEngData (full: DpchEngMsdcScfActuData)
		*/
	class DpchEngData : public DpchEngMsdc {

	public:
		static const uint JREF = 1;
		static const uint CONTIAC = 2;
		static const uint CONTINF = 3;
		static const uint STATAPP = 4;
		static const uint STATSHR = 5;
		static const uint TAG = 6;
		static const uint ALL = 7;

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

public:
	PnlMsdcScfActu(XchgMsdc* xchg, DbsMsdc* dbsmsdc, const ubigint jrefSup, const uint ixMsdcVLocale);
	~PnlMsdcScfActu();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;

	JobMsdcActLed* actled;
	JobMsdcActServo* actservo;
	JobMsdcActAlign* actalign;

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

	void handleDpchAppDoButMasterClick(DbsMsdc* dbsmsdc, DpchEngMsdc** dpcheng);

	void handleCall(DbsMsdc* dbsmsdc, Call* call);

	bool handleCallMsdcMastslvChg(DbsMsdc* dbsmsdc, const ubigint jrefTrig);
};

#endif

