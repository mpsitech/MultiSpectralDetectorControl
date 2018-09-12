/**
  * \file PnlMsdcPrsDetail.h
  * job handler for job PnlMsdcPrsDetail (declarations)
  * \author Alexander Wirthmueller
  * \date created: 12 Sep 2018
  * \date modified: 12 Sep 2018
  */

#ifndef PNLMSDCPRSDETAIL_H
#define PNLMSDCPRSDETAIL_H

// IP custInclude --- INSERT

#define VecVMsdcPrsDetailDo PnlMsdcPrsDetail::VecVDo

#define ContIacMsdcPrsDetail PnlMsdcPrsDetail::ContIac
#define ContInfMsdcPrsDetail PnlMsdcPrsDetail::ContInf
#define StatAppMsdcPrsDetail PnlMsdcPrsDetail::StatApp
#define StatShrMsdcPrsDetail PnlMsdcPrsDetail::StatShr
#define TagMsdcPrsDetail PnlMsdcPrsDetail::Tag

#define DpchAppMsdcPrsDetailData PnlMsdcPrsDetail::DpchAppData
#define DpchAppMsdcPrsDetailDo PnlMsdcPrsDetail::DpchAppDo
#define DpchEngMsdcPrsDetailData PnlMsdcPrsDetail::DpchEngData

/**
  * PnlMsdcPrsDetail
  */
class PnlMsdcPrsDetail : public JobMsdc {

public:
	/**
		* VecVDo (full: VecVMsdcPrsDetailDo)
		*/
	class VecVDo {

	public:
		static const uint BUTSAVECLICK = 1;
		static const uint BUTJEDITCLICK = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacMsdcPrsDetail)
	  */
	class ContIac : public Block {

	public:
		static const uint TXFTIT = 1;
		static const uint TXFFNM = 2;
		static const uint NUMFPUPJ = 3;
		static const uint NUMSFLSTDRV = 4;
		static const uint NUMFPUPSEX = 5;
		static const uint TXFTEL = 6;
		static const uint TXFEML = 7;
		static const uint TXFSAL = 8;

	public:
		ContIac(const string& TxfTit = "", const string& TxfFnm = "", const uint numFPupJ = 1, const vector<uint>& numsFLstDrv = {}, const uint numFPupSex = 1, const string& TxfTel = "", const string& TxfEml = "", const string& TxfSal = "");

	public:
		string TxfTit;
		string TxfFnm;
		uint numFPupJ;
		vector<uint> numsFLstDrv;
		uint numFPupSex;
		string TxfTel;
		string TxfEml;
		string TxfSal;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfMsdcPrsDetail)
	  */
	class ContInf : public Block {

	public:
		static const uint TXTLNM = 1;
		static const uint TXTDRV = 2;

	public:
		ContInf(const string& TxtLnm = "", const string& TxtDrv = "");

	public:
		string TxtLnm;
		string TxtDrv;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppMsdcPrsDetail)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const uint ixMsdcVExpstate = VecMsdcVExpstate::MIND, const bool LstDrvAlt = true, const uint LstDrvNumFirstdisp = 1);
	};

	/**
		* StatShr (full: StatShrMsdcPrsDetail)
		*/
	class StatShr : public Block {

	public:
		static const uint BUTSAVEAVAIL = 1;
		static const uint BUTSAVEACTIVE = 2;
		static const uint TXFTITACTIVE = 3;
		static const uint TXFFNMACTIVE = 4;
		static const uint PUPJACTIVE = 5;
		static const uint BUTJEDITAVAIL = 6;
		static const uint TXTLNMACTIVE = 7;
		static const uint LSTDRVACTIVE = 8;
		static const uint PUPSEXACTIVE = 9;
		static const uint TXFTELACTIVE = 10;
		static const uint TXFEMLACTIVE = 11;
		static const uint TXFSALACTIVE = 12;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxfTitActive = true, const bool TxfFnmActive = true, const bool PupJActive = true, const bool ButJEditAvail = true, const bool TxtLnmActive = true, const bool LstDrvActive = true, const bool PupSexActive = true, const bool TxfTelActive = true, const bool TxfEmlActive = true, const bool TxfSalActive = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxfTitActive;
		bool TxfFnmActive;
		bool PupJActive;
		bool ButJEditAvail;
		bool TxtLnmActive;
		bool LstDrvActive;
		bool PupSexActive;
		bool TxfTelActive;
		bool TxfEmlActive;
		bool TxfSalActive;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagMsdcPrsDetail)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixMsdcVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppMsdcPrsDetailData)
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
		* DpchAppDo (full: DpchAppMsdcPrsDetailDo)
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
		* DpchEngData (full: DpchEngMsdcPrsDetailData)
		*/
	class DpchEngData : public DpchEngMsdc {

	public:
		static const uint JREF = 1;
		static const uint CONTIAC = 2;
		static const uint CONTINF = 3;
		static const uint FEEDFLSTDRV = 4;
		static const uint FEEDFPUPJ = 5;
		static const uint FEEDFPUPSEX = 6;
		static const uint STATAPP = 7;
		static const uint STATSHR = 8;
		static const uint TAG = 9;
		static const uint ALL = 10;

	public:
		DpchEngData(const ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, Feed* feedFLstDrv = NULL, Feed* feedFPupJ = NULL, Feed* feedFPupSex = NULL, StatShr* statshr = NULL, const set<uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		Feed feedFLstDrv;
		Feed feedFPupJ;
		Feed feedFPupSex;
		StatShr statshr;

	public:
		string getSrefsMask();
		void merge(DpchEngMsdc* dpcheng);

		void writeXML(const uint ixMsdcVLocale, xmlTextWriter* wr);
	};

	bool evalButSaveAvail(DbsMsdc* dbsmsdc);
	bool evalButSaveActive(DbsMsdc* dbsmsdc);
	bool evalTxfTitActive(DbsMsdc* dbsmsdc);
	bool evalTxfFnmActive(DbsMsdc* dbsmsdc);
	bool evalPupJActive(DbsMsdc* dbsmsdc);
	bool evalButJEditAvail(DbsMsdc* dbsmsdc);
	bool evalTxtLnmActive(DbsMsdc* dbsmsdc);
	bool evalLstDrvActive(DbsMsdc* dbsmsdc);
	bool evalPupSexActive(DbsMsdc* dbsmsdc);
	bool evalTxfTelActive(DbsMsdc* dbsmsdc);
	bool evalTxfEmlActive(DbsMsdc* dbsmsdc);
	bool evalTxfSalActive(DbsMsdc* dbsmsdc);

public:
	PnlMsdcPrsDetail(XchgMsdc* xchg, DbsMsdc* dbsmsdc, const ubigint jrefSup, const uint ixMsdcVLocale);
	~PnlMsdcPrsDetail();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;

	Feed feedFLstDrv;
	Feed feedFPupJ;
	Feed feedFPupSex;

	MsdcMPerson recPrs;

	MsdcJMPersonLastname recPrsJlnm;

	bool dirty;

	// IP custVar --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngMsdc* getNewDpchEng(set<uint> items);

	void refreshJ(DbsMsdc* dbsmsdc, set<uint>& moditems);
	void refreshTxtDrv(DbsMsdc* dbsmsdc, set<uint>& moditems);

	void refreshRecPrs(DbsMsdc* dbsmsdc, set<uint>& moditems);
	void refreshRecPrsJlnm(DbsMsdc* dbsmsdc, set<uint>& moditems);

	void refresh(DbsMsdc* dbsmsdc, set<uint>& moditems);

	void updatePreset(DbsMsdc* dbsmsdc, const uint ixMsdcVPreset, const ubigint jrefTrig, const bool notif = false);

public:

	void handleRequest(DbsMsdc* dbsmsdc, ReqMsdc* req);

	void handleDpchAppMsdcInit(DbsMsdc* dbsmsdc, DpchAppMsdcInit* dpchappmsdcinit, DpchEngMsdc** dpcheng);
	void handleDpchAppDataContiac(DbsMsdc* dbsmsdc, ContIac* _contiac, DpchEngMsdc** dpcheng);

	void handleDpchAppDoButSaveClick(DbsMsdc* dbsmsdc, DpchEngMsdc** dpcheng);
	void handleDpchAppDoButJEditClick(DbsMsdc* dbsmsdc, DpchEngMsdc** dpcheng);

	void handleCall(DbsMsdc* dbsmsdc, Call* call);

	bool handleCallMsdcPrsUpd_refEq(DbsMsdc* dbsmsdc, const ubigint jrefTrig, const ubigint refInv);
	bool handleCallMsdcPrsJlnmMod_prsEq(DbsMsdc* dbsmsdc, const ubigint jrefTrig, const ubigint refInv);
};

#endif

