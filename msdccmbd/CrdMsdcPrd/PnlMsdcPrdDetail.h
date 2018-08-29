/**
  * \file PnlMsdcPrdDetail.h
  * job handler for job PnlMsdcPrdDetail (declarations)
  * \author Alexander Wirthmueller
  * \date created: 29 Aug 2018
  * \date modified: 29 Aug 2018
  */

#ifndef PNLMSDCPRDDETAIL_H
#define PNLMSDCPRDDETAIL_H

// IP custInclude --- INSERT

#define VecVMsdcPrdDetailDo PnlMsdcPrdDetail::VecVDo

#define ContIacMsdcPrdDetail PnlMsdcPrdDetail::ContIac
#define StatAppMsdcPrdDetail PnlMsdcPrdDetail::StatApp
#define StatShrMsdcPrdDetail PnlMsdcPrdDetail::StatShr
#define TagMsdcPrdDetail PnlMsdcPrdDetail::Tag

#define DpchAppMsdcPrdDetailData PnlMsdcPrdDetail::DpchAppData
#define DpchAppMsdcPrdDetailDo PnlMsdcPrdDetail::DpchAppDo
#define DpchEngMsdcPrdDetailData PnlMsdcPrdDetail::DpchEngData

/**
  * PnlMsdcPrdDetail
  */
class PnlMsdcPrdDetail : public JobMsdc {

public:
	/**
		* VecVDo (full: VecVMsdcPrdDetailDo)
		*/
	class VecVDo {

	public:
		static const uint BUTSAVECLICK = 1;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacMsdcPrdDetail)
	  */
	class ContIac : public Block {

	public:
		static const uint TXFSTA = 1;
		static const uint TXFSTO = 2;

	public:
		ContIac(const string& TxfSta = "", const string& TxfSto = "");

	public:
		string TxfSta;
		string TxfSto;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
		* StatApp (full: StatAppMsdcPrdDetail)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const uint ixMsdcVExpstate = VecMsdcVExpstate::MIND);
	};

	/**
		* StatShr (full: StatShrMsdcPrdDetail)
		*/
	class StatShr : public Block {

	public:
		static const uint BUTSAVEAVAIL = 1;
		static const uint BUTSAVEACTIVE = 2;
		static const uint TXFSTAACTIVE = 3;
		static const uint TXFSTOACTIVE = 4;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxfStaActive = true, const bool TxfStoActive = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxfStaActive;
		bool TxfStoActive;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagMsdcPrdDetail)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixMsdcVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppMsdcPrdDetailData)
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
		* DpchAppDo (full: DpchAppMsdcPrdDetailDo)
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
		* DpchEngData (full: DpchEngMsdcPrdDetailData)
		*/
	class DpchEngData : public DpchEngMsdc {

	public:
		static const uint JREF = 1;
		static const uint CONTIAC = 2;
		static const uint STATAPP = 3;
		static const uint STATSHR = 4;
		static const uint TAG = 5;
		static const uint ALL = 6;

	public:
		DpchEngData(const ubigint jref = 0, ContIac* contiac = NULL, StatShr* statshr = NULL, const set<uint>& mask = {NONE});

	public:
		ContIac contiac;
		StatShr statshr;

	public:
		string getSrefsMask();
		void merge(DpchEngMsdc* dpcheng);

		void writeXML(const uint ixMsdcVLocale, xmlTextWriter* wr);
	};

	bool evalButSaveAvail(DbsMsdc* dbsmsdc);
	bool evalButSaveActive(DbsMsdc* dbsmsdc);
	bool evalTxfStaActive(DbsMsdc* dbsmsdc);
	bool evalTxfStoActive(DbsMsdc* dbsmsdc);

public:
	PnlMsdcPrdDetail(XchgMsdc* xchg, DbsMsdc* dbsmsdc, const ubigint jrefSup, const uint ixMsdcVLocale);
	~PnlMsdcPrdDetail();

public:
	ContIac contiac;
	StatShr statshr;

	MsdcMPeriod recPrd;

	bool dirty;

	// IP custVar --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngMsdc* getNewDpchEng(set<uint> items);

	void refreshRecPrd(DbsMsdc* dbsmsdc, set<uint>& moditems);

	void refresh(DbsMsdc* dbsmsdc, set<uint>& moditems);

	void updatePreset(DbsMsdc* dbsmsdc, const uint ixMsdcVPreset, const ubigint jrefTrig, const bool notif = false);

public:

	void handleRequest(DbsMsdc* dbsmsdc, ReqMsdc* req);

	void handleDpchAppMsdcInit(DbsMsdc* dbsmsdc, DpchAppMsdcInit* dpchappmsdcinit, DpchEngMsdc** dpcheng);
	void handleDpchAppDataContiac(DbsMsdc* dbsmsdc, ContIac* _contiac, DpchEngMsdc** dpcheng);

	void handleDpchAppDoButSaveClick(DbsMsdc* dbsmsdc, DpchEngMsdc** dpcheng);

	void handleCall(DbsMsdc* dbsmsdc, Call* call);

	bool handleCallMsdcPrdUpd_refEq(DbsMsdc* dbsmsdc, const ubigint jrefTrig, const ubigint refInv);
};

#endif

