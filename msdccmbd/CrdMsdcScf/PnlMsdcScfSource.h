/**
  * \file PnlMsdcScfSource.h
  * job handler for job PnlMsdcScfSource (declarations)
  * \author Alexander Wirthmueller
  * \date created: 18 Dec 2018
  * \date modified: 18 Dec 2018
  */

#ifndef PNLMSDCSCFSOURCE_H
#define PNLMSDCSCFSOURCE_H

// IP custInclude --- INSERT

#include "JobMsdcSrcMsdd.h"
#include "JobMsdcSrcTrigger.h"

#define VecVMsdcScfSourceDo PnlMsdcScfSource::VecVDo

#define ContIacMsdcScfSource PnlMsdcScfSource::ContIac
#define ContInfMsdcScfSource PnlMsdcScfSource::ContInf
#define StatAppMsdcScfSource PnlMsdcScfSource::StatApp
#define StatShrMsdcScfSource PnlMsdcScfSource::StatShr
#define TagMsdcScfSource PnlMsdcScfSource::Tag

#define DpchAppMsdcScfSourceData PnlMsdcScfSource::DpchAppData
#define DpchAppMsdcScfSourceDo PnlMsdcScfSource::DpchAppDo
#define DpchEngMsdcScfSourceData PnlMsdcScfSource::DpchEngData

/**
  * PnlMsdcScfSource
  */
class PnlMsdcScfSource : public JobMsdc {

public:
	/**
		* VecVDo (full: VecVMsdcScfSourceDo)
		*/
	class VecVDo {

	public:
		static const uint BUTMASTERCLICK = 1;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacMsdcScfSource)
	  */
	class ContIac : public Block {

	public:
		static const uint TXFFPP = 1;
		static const uint SLDFXA = 2;
		static const uint SLDFA0 = 3;
		static const uint SLDFB0 = 4;
		static const uint UPDFAM = 5;
		static const uint SLDFSA = 6;
		static const uint SLDFT0 = 7;
		static const uint SLDFP0 = 8;
		static const uint SLDTRP = 9;

	public:
		ContIac(const string& TxfFpp = "", const double SldFxa = 0.0, const double SldFa0 = 0.0, const double SldFb0 = 0.0, const int UpdFam = 0, const double SldFsa = 0.0, const double SldFt0 = 0.0, const double SldFp0 = 0.0, const double SldTrp = 0.0);

	public:
		string TxfFpp;
		double SldFxa;
		double SldFa0;
		double SldFb0;
		int UpdFam;
		double SldFsa;
		double SldFt0;
		double SldFp0;
		double SldTrp;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfMsdcScfSource)
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
		* StatApp (full: StatAppMsdcScfSource)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const uint ixMsdcVExpstate = VecMsdcVExpstate::MIND);
	};

	/**
		* StatShr (full: StatShrMsdcScfSource)
		*/
	class StatShr : public Block {

	public:
		static const uint SLDFXAMIN = 1;
		static const uint SLDFXAMAX = 2;
		static const uint SLDFA0MIN = 3;
		static const uint SLDFA0MAX = 4;
		static const uint SLDFB0MIN = 5;
		static const uint SLDFB0MAX = 6;
		static const uint UPDFAMMIN = 7;
		static const uint UPDFAMMAX = 8;
		static const uint SLDFSAMIN = 9;
		static const uint SLDFSAMAX = 10;
		static const uint SLDFT0MIN = 11;
		static const uint SLDFT0MAX = 12;
		static const uint SLDFP0MIN = 13;
		static const uint SLDFP0MAX = 14;
		static const uint SLDTRPMIN = 15;
		static const uint SLDTRPMAX = 16;
		static const uint SLDTRPRAST = 17;

	public:
		StatShr(const double SldFxaMin = 0.004, const double SldFxaMax = 0.032, const double SldFa0Min = -15.0, const double SldFa0Max = 15.0, const double SldFb0Min = -15.0, const double SldFb0Max = 15.0, const int UpdFamMin = 25, const int UpdFamMax = 255, const double SldFsaMin = 0.0, const double SldFsaMax = 15.0, const double SldFt0Min = -30.0, const double SldFt0Max = 30.0, const double SldFp0Min = -30.0, const double SldFp0Max = 30.0, const double SldTrpMin = 0.25, const double SldTrpMax = 2.0, const double SldTrpRast = 0.25);

	public:
		double SldFxaMin;
		double SldFxaMax;
		double SldFa0Min;
		double SldFa0Max;
		double SldFb0Min;
		double SldFb0Max;
		int UpdFamMin;
		int UpdFamMax;
		double SldFsaMin;
		double SldFsaMax;
		double SldFt0Min;
		double SldFt0Max;
		double SldFp0Min;
		double SldFp0Max;
		double SldTrpMin;
		double SldTrpMax;
		double SldTrpRast;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagMsdcScfSource)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixMsdcVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppMsdcScfSourceData)
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
		* DpchAppDo (full: DpchAppMsdcScfSourceDo)
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
		* DpchEngData (full: DpchEngMsdcScfSourceData)
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
	PnlMsdcScfSource(XchgMsdc* xchg, DbsMsdc* dbsmsdc, const ubigint jrefSup, const uint ixMsdcVLocale);
	~PnlMsdcScfSource();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;

	JobMsdcSrcMsdd* srcmsdd;
	JobMsdcSrcTrigger* srctrigger;

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

