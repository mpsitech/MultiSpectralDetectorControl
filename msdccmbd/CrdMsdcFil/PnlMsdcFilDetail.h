/**
  * \file PnlMsdcFilDetail.h
  * job handler for job PnlMsdcFilDetail (declarations)
  * \author Alexander Wirthmueller
  * \date created: 12 Sep 2018
  * \date modified: 12 Sep 2018
  */

#ifndef PNLMSDCFILDETAIL_H
#define PNLMSDCFILDETAIL_H

// IP custInclude --- INSERT

#define VecVMsdcFilDetailDo PnlMsdcFilDetail::VecVDo

#define ContIacMsdcFilDetail PnlMsdcFilDetail::ContIac
#define ContInfMsdcFilDetail PnlMsdcFilDetail::ContInf
#define StatAppMsdcFilDetail PnlMsdcFilDetail::StatApp
#define StatShrMsdcFilDetail PnlMsdcFilDetail::StatShr
#define TagMsdcFilDetail PnlMsdcFilDetail::Tag

#define DpchAppMsdcFilDetailData PnlMsdcFilDetail::DpchAppData
#define DpchAppMsdcFilDetailDo PnlMsdcFilDetail::DpchAppDo
#define DpchEngMsdcFilDetailData PnlMsdcFilDetail::DpchEngData

/**
  * PnlMsdcFilDetail
  */
class PnlMsdcFilDetail : public JobMsdc {

public:
	/**
		* VecVDo (full: VecVMsdcFilDetailDo)
		*/
	class VecVDo {

	public:
		static const uint BUTSAVECLICK = 1;
		static const uint BUTCLUVIEWCLICK = 2;
		static const uint BUTCLUCLUSTERCLICK = 3;
		static const uint BUTCLUUNCLUSTERCLICK = 4;
		static const uint BUTREUVIEWCLICK = 5;
		static const uint BUTCNTEDITCLICK = 6;
		static const uint BUTMIMEDITCLICK = 7;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacMsdcFilDetail)
	  */
	class ContIac : public Block {

	public:
		static const uint TXFFNM = 1;
		static const uint NUMFLSTCLU = 2;
		static const uint NUMFPUPRET = 3;
		static const uint NUMFPUPCNT = 4;
		static const uint TXFCNT = 5;
		static const uint TXFACV = 6;
		static const uint TXFANM = 7;
		static const uint NUMFPUPMIM = 8;
		static const uint TXFMIM = 9;
		static const uint TXFSIZ = 10;
		static const uint TXFCMT = 11;

	public:
		ContIac(const string& TxfFnm = "", const uint numFLstClu = 1, const uint numFPupRet = 1, const uint numFPupCnt = 1, const string& TxfCnt = "", const string& TxfAcv = "", const string& TxfAnm = "", const uint numFPupMim = 1, const string& TxfMim = "", const string& TxfSiz = "", const string& TxfCmt = "");

	public:
		string TxfFnm;
		uint numFLstClu;
		uint numFPupRet;
		uint numFPupCnt;
		string TxfCnt;
		string TxfAcv;
		string TxfAnm;
		uint numFPupMim;
		string TxfMim;
		string TxfSiz;
		string TxfCmt;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfMsdcFilDetail)
	  */
	class ContInf : public Block {

	public:
		static const uint TXTCLU = 1;
		static const uint TXTREU = 2;

	public:
		ContInf(const string& TxtClu = "", const string& TxtReu = "");

	public:
		string TxtClu;
		string TxtReu;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppMsdcFilDetail)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const uint ixMsdcVExpstate = VecMsdcVExpstate::MIND, const bool LstCluAlt = true, const bool PupCntAlt = false, const bool PupMimAlt = false, const uint LstCluNumFirstdisp = 1);
	};

	/**
		* StatShr (full: StatShrMsdcFilDetail)
		*/
	class StatShr : public Block {

	public:
		static const uint TXFCNTVALID = 1;
		static const uint TXFMIMVALID = 2;
		static const uint BUTSAVEAVAIL = 3;
		static const uint BUTSAVEACTIVE = 4;
		static const uint TXFFNMACTIVE = 5;
		static const uint LSTCLUACTIVE = 6;
		static const uint BUTCLUVIEWACTIVE = 7;
		static const uint BUTCLUCLUSTERAVAIL = 8;
		static const uint BUTCLUUNCLUSTERAVAIL = 9;
		static const uint TXTREUACTIVE = 10;
		static const uint BUTREUVIEWAVAIL = 11;
		static const uint BUTREUVIEWACTIVE = 12;
		static const uint PUPCNTACTIVE = 13;
		static const uint BUTCNTEDITAVAIL = 14;
		static const uint TXFACVACTIVE = 15;
		static const uint TXFANMACTIVE = 16;
		static const uint PUPMIMACTIVE = 17;
		static const uint BUTMIMEDITAVAIL = 18;
		static const uint TXFSIZACTIVE = 19;
		static const uint TXFCMTACTIVE = 20;

	public:
		StatShr(const bool TxfCntValid = false, const bool TxfMimValid = false, const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxfFnmActive = true, const bool LstCluActive = true, const bool ButCluViewActive = true, const bool ButCluClusterAvail = true, const bool ButCluUnclusterAvail = true, const bool TxtReuActive = true, const bool ButReuViewAvail = true, const bool ButReuViewActive = true, const bool PupCntActive = true, const bool ButCntEditAvail = true, const bool TxfAcvActive = true, const bool TxfAnmActive = true, const bool PupMimActive = true, const bool ButMimEditAvail = true, const bool TxfSizActive = true, const bool TxfCmtActive = true);

	public:
		bool TxfCntValid;
		bool TxfMimValid;
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxfFnmActive;
		bool LstCluActive;
		bool ButCluViewActive;
		bool ButCluClusterAvail;
		bool ButCluUnclusterAvail;
		bool TxtReuActive;
		bool ButReuViewAvail;
		bool ButReuViewActive;
		bool PupCntActive;
		bool ButCntEditAvail;
		bool TxfAcvActive;
		bool TxfAnmActive;
		bool PupMimActive;
		bool ButMimEditAvail;
		bool TxfSizActive;
		bool TxfCmtActive;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagMsdcFilDetail)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixMsdcVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppMsdcFilDetailData)
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
		* DpchAppDo (full: DpchAppMsdcFilDetailDo)
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
		* DpchEngData (full: DpchEngMsdcFilDetailData)
		*/
	class DpchEngData : public DpchEngMsdc {

	public:
		static const uint JREF = 1;
		static const uint CONTIAC = 2;
		static const uint CONTINF = 3;
		static const uint FEEDFLSTCLU = 4;
		static const uint FEEDFPUPCNT = 5;
		static const uint FEEDFPUPMIM = 6;
		static const uint FEEDFPUPRET = 7;
		static const uint STATAPP = 8;
		static const uint STATSHR = 9;
		static const uint TAG = 10;
		static const uint ALL = 11;

	public:
		DpchEngData(const ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, Feed* feedFLstClu = NULL, Feed* feedFPupCnt = NULL, Feed* feedFPupMim = NULL, Feed* feedFPupRet = NULL, StatShr* statshr = NULL, const set<uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		Feed feedFLstClu;
		Feed feedFPupCnt;
		Feed feedFPupMim;
		Feed feedFPupRet;
		StatShr statshr;

	public:
		string getSrefsMask();
		void merge(DpchEngMsdc* dpcheng);

		void writeXML(const uint ixMsdcVLocale, xmlTextWriter* wr);
	};

	bool evalButSaveAvail(DbsMsdc* dbsmsdc);
	bool evalButSaveActive(DbsMsdc* dbsmsdc);
	bool evalTxfFnmActive(DbsMsdc* dbsmsdc);
	bool evalLstCluActive(DbsMsdc* dbsmsdc);
	bool evalButCluViewActive(DbsMsdc* dbsmsdc);
	bool evalButCluClusterAvail(DbsMsdc* dbsmsdc);
	bool evalButCluUnclusterAvail(DbsMsdc* dbsmsdc);
	bool evalTxtReuActive(DbsMsdc* dbsmsdc);
	bool evalButReuViewAvail(DbsMsdc* dbsmsdc);
	bool evalButReuViewActive(DbsMsdc* dbsmsdc);
	bool evalPupCntActive(DbsMsdc* dbsmsdc);
	bool evalButCntEditAvail(DbsMsdc* dbsmsdc);
	bool evalTxfAcvActive(DbsMsdc* dbsmsdc);
	bool evalTxfAnmActive(DbsMsdc* dbsmsdc);
	bool evalPupMimActive(DbsMsdc* dbsmsdc);
	bool evalButMimEditAvail(DbsMsdc* dbsmsdc);
	bool evalTxfSizActive(DbsMsdc* dbsmsdc);
	bool evalTxfCmtActive(DbsMsdc* dbsmsdc);

public:
	PnlMsdcFilDetail(XchgMsdc* xchg, DbsMsdc* dbsmsdc, const ubigint jrefSup, const uint ixMsdcVLocale);
	~PnlMsdcFilDetail();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;

	Feed feedFLstClu;
	Feed feedFPupCnt;
	Feed feedFPupMim;
	Feed feedFPupRet;

	MsdcMFile recFil;

	bool dirty;

	// IP custVar --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngMsdc* getNewDpchEng(set<uint> items);

	void refreshLstClu(DbsMsdc* dbsmsdc, set<uint>& moditems);
	void refreshClu(DbsMsdc* dbsmsdc, set<uint>& moditems);
	void refreshPupCnt(DbsMsdc* dbsmsdc, set<uint>& moditems);
	void refreshTxfCnt(DbsMsdc* dbsmsdc, set<uint>& moditems);
	void refreshCnt(DbsMsdc* dbsmsdc, set<uint>& moditems);
	void refreshPupMim(DbsMsdc* dbsmsdc, set<uint>& moditems);
	void refreshTxfMim(DbsMsdc* dbsmsdc, set<uint>& moditems);
	void refreshMim(DbsMsdc* dbsmsdc, set<uint>& moditems);

	void refreshRecFil(DbsMsdc* dbsmsdc, set<uint>& moditems);

	void refresh(DbsMsdc* dbsmsdc, set<uint>& moditems);

	void updatePreset(DbsMsdc* dbsmsdc, const uint ixMsdcVPreset, const ubigint jrefTrig, const bool notif = false);

public:

	void handleRequest(DbsMsdc* dbsmsdc, ReqMsdc* req);

	void handleDpchAppMsdcInit(DbsMsdc* dbsmsdc, DpchAppMsdcInit* dpchappmsdcinit, DpchEngMsdc** dpcheng);
	void handleDpchAppDataContiac(DbsMsdc* dbsmsdc, ContIac* _contiac, DpchEngMsdc** dpcheng);

	void handleDpchAppDoButSaveClick(DbsMsdc* dbsmsdc, DpchEngMsdc** dpcheng);
	void handleDpchAppDoButCluViewClick(DbsMsdc* dbsmsdc, DpchEngMsdc** dpcheng);
	void handleDpchAppDoButCluClusterClick(DbsMsdc* dbsmsdc, DpchEngMsdc** dpcheng);
	void handleDpchAppDoButCluUnclusterClick(DbsMsdc* dbsmsdc, DpchEngMsdc** dpcheng);
	void handleDpchAppDoButReuViewClick(DbsMsdc* dbsmsdc, DpchEngMsdc** dpcheng);
	void handleDpchAppDoButCntEditClick(DbsMsdc* dbsmsdc, DpchEngMsdc** dpcheng);
	void handleDpchAppDoButMimEditClick(DbsMsdc* dbsmsdc, DpchEngMsdc** dpcheng);

	void handleCall(DbsMsdc* dbsmsdc, Call* call);

	bool handleCallMsdcFil_cluEq(DbsMsdc* dbsmsdc, const ubigint jrefTrig, const ubigint refInv, bool& boolvalRet);
	bool handleCallMsdcFil_retEq(DbsMsdc* dbsmsdc, const ubigint jrefTrig, const uint ixInv, bool& boolvalRet);
	bool handleCallMsdcFil_reuEq(DbsMsdc* dbsmsdc, const ubigint jrefTrig, const ubigint refInv, bool& boolvalRet);
	bool handleCallMsdcFilUpd_refEq(DbsMsdc* dbsmsdc, const ubigint jrefTrig, const ubigint refInv);
	bool handleCallMsdcKlsAkeyMod_klsEq(DbsMsdc* dbsmsdc, const ubigint jrefTrig, const uint ixInv);
	bool handleCallMsdcFilMod_cluEq(DbsMsdc* dbsmsdc, const ubigint jrefTrig, const ubigint refInv);
};

#endif

