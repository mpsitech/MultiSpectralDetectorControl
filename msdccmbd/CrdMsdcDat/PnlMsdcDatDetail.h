/**
  * \file PnlMsdcDatDetail.h
  * job handler for job PnlMsdcDatDetail (declarations)
  * \author Alexander Wirthmueller
  * \date created: 12 Sep 2018
  * \date modified: 12 Sep 2018
  */

#ifndef PNLMSDCDATDETAIL_H
#define PNLMSDCDATDETAIL_H

// IP custInclude --- INSERT

#define VecVMsdcDatDetailDo PnlMsdcDatDetail::VecVDo

#define ContIacMsdcDatDetail PnlMsdcDatDetail::ContIac
#define ContInfMsdcDatDetail PnlMsdcDatDetail::ContInf
#define StatAppMsdcDatDetail PnlMsdcDatDetail::StatApp
#define StatShrMsdcDatDetail PnlMsdcDatDetail::StatShr
#define TagMsdcDatDetail PnlMsdcDatDetail::Tag

#define DpchAppMsdcDatDetailData PnlMsdcDatDetail::DpchAppData
#define DpchAppMsdcDatDetailDo PnlMsdcDatDetail::DpchAppDo
#define DpchEngMsdcDatDetailData PnlMsdcDatDetail::DpchEngData

/**
  * PnlMsdcDatDetail
  */
class PnlMsdcDatDetail : public JobMsdc {

public:
	/**
		* VecVDo (full: VecVMsdcDatDetailDo)
		*/
	class VecVDo {

	public:
		static const uint BUTSAVECLICK = 1;
		static const uint BUTAFTEDITCLICK = 2;
		static const uint BUTPRDVIEWCLICK = 3;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacMsdcDatDetail)
	  */
	class ContIac : public Block {

	public:
		static const uint NUMFPUPAFT = 1;
		static const uint TXFAFT = 2;
		static const uint TXFSTA = 3;
		static const uint TXFSTO = 4;
		static const uint TXFCMT = 5;

	public:
		ContIac(const uint numFPupAft = 1, const string& TxfAft = "", const string& TxfSta = "", const string& TxfSto = "", const string& TxfCmt = "");

	public:
		uint numFPupAft;
		string TxfAft;
		string TxfSta;
		string TxfSto;
		string TxfCmt;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfMsdcDatDetail)
	  */
	class ContInf : public Block {

	public:
		static const uint TXTPRD = 1;

	public:
		ContInf(const string& TxtPrd = "");

	public:
		string TxtPrd;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppMsdcDatDetail)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const uint ixMsdcVExpstate = VecMsdcVExpstate::MIND, const bool PupAftAlt = false);
	};

	/**
		* StatShr (full: StatShrMsdcDatDetail)
		*/
	class StatShr : public Block {

	public:
		static const uint TXFAFTVALID = 1;
		static const uint BUTSAVEAVAIL = 2;
		static const uint BUTSAVEACTIVE = 3;
		static const uint PUPAFTACTIVE = 4;
		static const uint BUTAFTEDITAVAIL = 5;
		static const uint TXTPRDACTIVE = 6;
		static const uint BUTPRDVIEWAVAIL = 7;
		static const uint BUTPRDVIEWACTIVE = 8;
		static const uint TXFSTAACTIVE = 9;
		static const uint TXFSTOACTIVE = 10;
		static const uint TXFCMTACTIVE = 11;

	public:
		StatShr(const bool TxfAftValid = false, const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool PupAftActive = true, const bool ButAftEditAvail = true, const bool TxtPrdActive = true, const bool ButPrdViewAvail = true, const bool ButPrdViewActive = true, const bool TxfStaActive = true, const bool TxfStoActive = true, const bool TxfCmtActive = true);

	public:
		bool TxfAftValid;
		bool ButSaveAvail;
		bool ButSaveActive;
		bool PupAftActive;
		bool ButAftEditAvail;
		bool TxtPrdActive;
		bool ButPrdViewAvail;
		bool ButPrdViewActive;
		bool TxfStaActive;
		bool TxfStoActive;
		bool TxfCmtActive;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagMsdcDatDetail)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixMsdcVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppMsdcDatDetailData)
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
		* DpchAppDo (full: DpchAppMsdcDatDetailDo)
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
		* DpchEngData (full: DpchEngMsdcDatDetailData)
		*/
	class DpchEngData : public DpchEngMsdc {

	public:
		static const uint JREF = 1;
		static const uint CONTIAC = 2;
		static const uint CONTINF = 3;
		static const uint FEEDFPUPAFT = 4;
		static const uint STATAPP = 5;
		static const uint STATSHR = 6;
		static const uint TAG = 7;
		static const uint ALL = 8;

	public:
		DpchEngData(const ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, Feed* feedFPupAft = NULL, StatShr* statshr = NULL, const set<uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		Feed feedFPupAft;
		StatShr statshr;

	public:
		string getSrefsMask();
		void merge(DpchEngMsdc* dpcheng);

		void writeXML(const uint ixMsdcVLocale, xmlTextWriter* wr);
	};

	bool evalButSaveAvail(DbsMsdc* dbsmsdc);
	bool evalButSaveActive(DbsMsdc* dbsmsdc);
	bool evalPupAftActive(DbsMsdc* dbsmsdc);
	bool evalButAftEditAvail(DbsMsdc* dbsmsdc);
	bool evalTxtPrdActive(DbsMsdc* dbsmsdc);
	bool evalButPrdViewAvail(DbsMsdc* dbsmsdc);
	bool evalButPrdViewActive(DbsMsdc* dbsmsdc);
	bool evalTxfStaActive(DbsMsdc* dbsmsdc);
	bool evalTxfStoActive(DbsMsdc* dbsmsdc);
	bool evalTxfCmtActive(DbsMsdc* dbsmsdc);

public:
	PnlMsdcDatDetail(XchgMsdc* xchg, DbsMsdc* dbsmsdc, const ubigint jrefSup, const uint ixMsdcVLocale);
	~PnlMsdcDatDetail();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;

	Feed feedFPupAft;

	MsdcMData recDat;

	bool dirty;

	// IP custVar --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngMsdc* getNewDpchEng(set<uint> items);

	void refreshPupAft(DbsMsdc* dbsmsdc, set<uint>& moditems);
	void refreshTxfAft(DbsMsdc* dbsmsdc, set<uint>& moditems);
	void refreshAft(DbsMsdc* dbsmsdc, set<uint>& moditems);

	void refreshRecDat(DbsMsdc* dbsmsdc, set<uint>& moditems);

	void refresh(DbsMsdc* dbsmsdc, set<uint>& moditems);

	void updatePreset(DbsMsdc* dbsmsdc, const uint ixMsdcVPreset, const ubigint jrefTrig, const bool notif = false);

public:

	void handleRequest(DbsMsdc* dbsmsdc, ReqMsdc* req);

	void handleDpchAppMsdcInit(DbsMsdc* dbsmsdc, DpchAppMsdcInit* dpchappmsdcinit, DpchEngMsdc** dpcheng);
	void handleDpchAppDataContiac(DbsMsdc* dbsmsdc, ContIac* _contiac, DpchEngMsdc** dpcheng);

	void handleDpchAppDoButSaveClick(DbsMsdc* dbsmsdc, DpchEngMsdc** dpcheng);
	void handleDpchAppDoButAftEditClick(DbsMsdc* dbsmsdc, DpchEngMsdc** dpcheng);
	void handleDpchAppDoButPrdViewClick(DbsMsdc* dbsmsdc, DpchEngMsdc** dpcheng);

	void handleCall(DbsMsdc* dbsmsdc, Call* call);

	bool handleCallMsdcDat_prdEq(DbsMsdc* dbsmsdc, const ubigint jrefTrig, const ubigint refInv, bool& boolvalRet);
	bool handleCallMsdcDatUpd_refEq(DbsMsdc* dbsmsdc, const ubigint jrefTrig, const ubigint refInv);
	bool handleCallMsdcKlsAkeyMod_klsEq(DbsMsdc* dbsmsdc, const ubigint jrefTrig, const uint ixInv);
};

#endif

