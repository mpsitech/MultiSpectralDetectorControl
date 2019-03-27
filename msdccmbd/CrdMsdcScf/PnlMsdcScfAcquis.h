/**
  * \file PnlMsdcScfAcquis.h
  * job handler for job PnlMsdcScfAcquis (declarations)
  * \author Alexander Wirthmueller
  * \date created: 18 Dec 2018
  * \date modified: 18 Dec 2018
  */

#ifndef PNLMSDCSCFACQUIS_H
#define PNLMSDCSCFACQUIS_H

// IP custInclude --- INSERT

#include "JobMsdcAcqAdxl.h"
#include "JobMsdcAcqLwir.h"
#include "JobMsdcAcqVisl.h"
#include "JobMsdcAcqVisr.h"

#define VecVMsdcScfAcquisDo PnlMsdcScfAcquis::VecVDo

#define ContIacMsdcScfAcquis PnlMsdcScfAcquis::ContIac
#define ContInfMsdcScfAcquis PnlMsdcScfAcquis::ContInf
#define StatAppMsdcScfAcquis PnlMsdcScfAcquis::StatApp
#define TagMsdcScfAcquis PnlMsdcScfAcquis::Tag

#define DpchAppMsdcScfAcquisData PnlMsdcScfAcquis::DpchAppData
#define DpchAppMsdcScfAcquisDo PnlMsdcScfAcquis::DpchAppDo
#define DpchEngMsdcScfAcquisData PnlMsdcScfAcquis::DpchEngData

/**
  * PnlMsdcScfAcquis
  */
class PnlMsdcScfAcquis : public JobMsdc {

public:
	/**
		* VecVDo (full: VecVMsdcScfAcquisDo)
		*/
	class VecVDo {

	public:
		static const uint BUTMASTERCLICK = 1;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacMsdcScfAcquis)
	  */
	class ContIac : public Block {

	public:
		static const uint NUMFPUPVTY = 1;
		static const uint TXFVLP = 2;
		static const uint TXFVRP = 3;

	public:
		ContIac(const uint numFPupVty = 1, const string& TxfVlp = "", const string& TxfVrp = "");

	public:
		uint numFPupVty;
		string TxfVlp;
		string TxfVrp;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfMsdcScfAcquis)
	  */
	class ContInf : public Block {

	public:
		static const uint BUTMASTERON = 1;
		static const uint TXTISN = 2;
		static const uint TXTIPS = 3;
		static const uint TXTIFL = 4;
		static const uint TXTIFN = 5;
		static const uint TXTVPS = 6;
		static const uint TXTVFL = 7;
		static const uint TXTVFN = 8;

	public:
		ContInf(const bool ButMasterOn = false, const string& TxtIsn = "", const string& TxtIps = "", const string& TxtIfl = "", const string& TxtIfn = "", const string& TxtVps = "", const string& TxtVfl = "", const string& TxtVfn = "");

	public:
		bool ButMasterOn;
		string TxtIsn;
		string TxtIps;
		string TxtIfl;
		string TxtIfn;
		string TxtVps;
		string TxtVfl;
		string TxtVfn;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppMsdcScfAcquis)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const uint ixMsdcVExpstate = VecMsdcVExpstate::MIND);
	};

	/**
		* Tag (full: TagMsdcScfAcquis)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixMsdcVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppMsdcScfAcquisData)
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
		* DpchAppDo (full: DpchAppMsdcScfAcquisDo)
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
		* DpchEngData (full: DpchEngMsdcScfAcquisData)
		*/
	class DpchEngData : public DpchEngMsdc {

	public:
		static const uint JREF = 1;
		static const uint CONTIAC = 2;
		static const uint CONTINF = 3;
		static const uint FEEDFPUPVTY = 4;
		static const uint STATAPP = 5;
		static const uint TAG = 6;
		static const uint ALL = 7;

	public:
		DpchEngData(const ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, Feed* feedFPupVty = NULL, const set<uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		Feed feedFPupVty;

	public:
		string getSrefsMask();
		void merge(DpchEngMsdc* dpcheng);

		void writeXML(const uint ixMsdcVLocale, xmlTextWriter* wr);
	};

public:
	PnlMsdcScfAcquis(XchgMsdc* xchg, DbsMsdc* dbsmsdc, const ubigint jrefSup, const uint ixMsdcVLocale);
	~PnlMsdcScfAcquis();

public:
	ContIac contiac;
	ContInf continf;

	Feed feedFPupVty;

	JobMsdcAcqAdxl* acqadxl;
	JobMsdcAcqLwir* acqlwir;
	JobMsdcAcqVisl* acqvisl;
	JobMsdcAcqVisr* acqvisr;

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

