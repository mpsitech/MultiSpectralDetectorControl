/**
  * \file PnlMsdcUsrDetail.h
  * job handler for job PnlMsdcUsrDetail (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Oct 2018
  * \date modified: 4 Oct 2018
  */

#ifndef PNLMSDCUSRDETAIL_H
#define PNLMSDCUSRDETAIL_H

// IP custInclude --- INSERT

#define VecVMsdcUsrDetailDo PnlMsdcUsrDetail::VecVDo

#define ContIacMsdcUsrDetail PnlMsdcUsrDetail::ContIac
#define ContInfMsdcUsrDetail PnlMsdcUsrDetail::ContInf
#define StatAppMsdcUsrDetail PnlMsdcUsrDetail::StatApp
#define StatShrMsdcUsrDetail PnlMsdcUsrDetail::StatShr
#define TagMsdcUsrDetail PnlMsdcUsrDetail::Tag

#define DpchAppMsdcUsrDetailData PnlMsdcUsrDetail::DpchAppData
#define DpchAppMsdcUsrDetailDo PnlMsdcUsrDetail::DpchAppDo
#define DpchEngMsdcUsrDetailData PnlMsdcUsrDetail::DpchEngData

/**
  * PnlMsdcUsrDetail
  */
class PnlMsdcUsrDetail : public JobMsdc {

public:
	/**
		* VecVDo (full: VecVMsdcUsrDetailDo)
		*/
	class VecVDo {

	public:
		static const uint BUTSAVECLICK = 1;
		static const uint BUTPRSVIEWCLICK = 2;
		static const uint BUTUSGVIEWCLICK = 3;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacMsdcUsrDetail)
	  */
	class ContIac : public Block {

	public:
		static const uint NUMFPUPSTE = 1;
		static const uint NUMFPUPLCL = 2;
		static const uint NUMFPUPULV = 3;
		static const uint TXFPWD = 4;
		static const uint TXFFKY = 5;
		static const uint TXFCMT = 6;

	public:
		ContIac(const uint numFPupSte = 1, const uint numFPupLcl = 1, const uint numFPupUlv = 1, const string& TxfPwd = "", const string& TxfFky = "", const string& TxfCmt = "");

	public:
		uint numFPupSte;
		uint numFPupLcl;
		uint numFPupUlv;
		string TxfPwd;
		string TxfFky;
		string TxfCmt;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfMsdcUsrDetail)
	  */
	class ContInf : public Block {

	public:
		static const uint TXTPRS = 1;
		static const uint TXTSRF = 2;
		static const uint TXTUSG = 3;

	public:
		ContInf(const string& TxtPrs = "", const string& TxtSrf = "", const string& TxtUsg = "");

	public:
		string TxtPrs;
		string TxtSrf;
		string TxtUsg;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppMsdcUsrDetail)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const uint ixMsdcVExpstate = VecMsdcVExpstate::MIND);
	};

	/**
		* StatShr (full: StatShrMsdcUsrDetail)
		*/
	class StatShr : public Block {

	public:
		static const uint BUTSAVEAVAIL = 1;
		static const uint BUTSAVEACTIVE = 2;
		static const uint TXTPRSACTIVE = 3;
		static const uint BUTPRSVIEWAVAIL = 4;
		static const uint BUTPRSVIEWACTIVE = 5;
		static const uint TXTSRFACTIVE = 6;
		static const uint TXTUSGACTIVE = 7;
		static const uint BUTUSGVIEWAVAIL = 8;
		static const uint BUTUSGVIEWACTIVE = 9;
		static const uint PUPSTEACTIVE = 10;
		static const uint PUPLCLACTIVE = 11;
		static const uint PUPULVACTIVE = 12;
		static const uint TXFPWDACTIVE = 13;
		static const uint TXFFKYACTIVE = 14;
		static const uint TXFCMTACTIVE = 15;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtPrsActive = true, const bool ButPrsViewAvail = true, const bool ButPrsViewActive = true, const bool TxtSrfActive = true, const bool TxtUsgActive = true, const bool ButUsgViewAvail = true, const bool ButUsgViewActive = true, const bool PupSteActive = true, const bool PupLclActive = true, const bool PupUlvActive = true, const bool TxfPwdActive = true, const bool TxfFkyActive = true, const bool TxfCmtActive = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtPrsActive;
		bool ButPrsViewAvail;
		bool ButPrsViewActive;
		bool TxtSrfActive;
		bool TxtUsgActive;
		bool ButUsgViewAvail;
		bool ButUsgViewActive;
		bool PupSteActive;
		bool PupLclActive;
		bool PupUlvActive;
		bool TxfPwdActive;
		bool TxfFkyActive;
		bool TxfCmtActive;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagMsdcUsrDetail)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixMsdcVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppMsdcUsrDetailData)
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
		* DpchAppDo (full: DpchAppMsdcUsrDetailDo)
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
		* DpchEngData (full: DpchEngMsdcUsrDetailData)
		*/
	class DpchEngData : public DpchEngMsdc {

	public:
		static const uint JREF = 1;
		static const uint CONTIAC = 2;
		static const uint CONTINF = 3;
		static const uint FEEDFPUPLCL = 4;
		static const uint FEEDFPUPSTE = 5;
		static const uint FEEDFPUPULV = 6;
		static const uint STATAPP = 7;
		static const uint STATSHR = 8;
		static const uint TAG = 9;
		static const uint ALL = 10;

	public:
		DpchEngData(const ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, Feed* feedFPupLcl = NULL, Feed* feedFPupSte = NULL, Feed* feedFPupUlv = NULL, StatShr* statshr = NULL, const set<uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		Feed feedFPupLcl;
		Feed feedFPupSte;
		Feed feedFPupUlv;
		StatShr statshr;

	public:
		string getSrefsMask();
		void merge(DpchEngMsdc* dpcheng);

		void writeXML(const uint ixMsdcVLocale, xmlTextWriter* wr);
	};

	bool evalButSaveAvail(DbsMsdc* dbsmsdc);
	bool evalButSaveActive(DbsMsdc* dbsmsdc);
	bool evalTxtPrsActive(DbsMsdc* dbsmsdc);
	bool evalButPrsViewAvail(DbsMsdc* dbsmsdc);
	bool evalButPrsViewActive(DbsMsdc* dbsmsdc);
	bool evalTxtSrfActive(DbsMsdc* dbsmsdc);
	bool evalTxtUsgActive(DbsMsdc* dbsmsdc);
	bool evalButUsgViewAvail(DbsMsdc* dbsmsdc);
	bool evalButUsgViewActive(DbsMsdc* dbsmsdc);
	bool evalPupSteActive(DbsMsdc* dbsmsdc);
	bool evalPupLclActive(DbsMsdc* dbsmsdc);
	bool evalPupUlvActive(DbsMsdc* dbsmsdc);
	bool evalTxfPwdActive(DbsMsdc* dbsmsdc);
	bool evalTxfFkyActive(DbsMsdc* dbsmsdc);
	bool evalTxfCmtActive(DbsMsdc* dbsmsdc);

public:
	PnlMsdcUsrDetail(XchgMsdc* xchg, DbsMsdc* dbsmsdc, const ubigint jrefSup, const uint ixMsdcVLocale);
	~PnlMsdcUsrDetail();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;

	Feed feedFPupLcl;
	Feed feedFPupSte;
	Feed feedFPupUlv;

	MsdcMUser recUsr;

	MsdcJMUserState recUsrJste;

	bool dirty;

	// IP custVar --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngMsdc* getNewDpchEng(set<uint> items);

	void refreshRecUsr(DbsMsdc* dbsmsdc, set<uint>& moditems);
	void refreshRecUsrJste(DbsMsdc* dbsmsdc, set<uint>& moditems);

	void refresh(DbsMsdc* dbsmsdc, set<uint>& moditems);

	void updatePreset(DbsMsdc* dbsmsdc, const uint ixMsdcVPreset, const ubigint jrefTrig, const bool notif = false);

public:

	void handleRequest(DbsMsdc* dbsmsdc, ReqMsdc* req);

	void handleDpchAppMsdcInit(DbsMsdc* dbsmsdc, DpchAppMsdcInit* dpchappmsdcinit, DpchEngMsdc** dpcheng);
	void handleDpchAppDataContiac(DbsMsdc* dbsmsdc, ContIac* _contiac, DpchEngMsdc** dpcheng);

	void handleDpchAppDoButSaveClick(DbsMsdc* dbsmsdc, DpchEngMsdc** dpcheng);
	void handleDpchAppDoButPrsViewClick(DbsMsdc* dbsmsdc, DpchEngMsdc** dpcheng);
	void handleDpchAppDoButUsgViewClick(DbsMsdc* dbsmsdc, DpchEngMsdc** dpcheng);

	void handleCall(DbsMsdc* dbsmsdc, Call* call);

	bool handleCallMsdcUsr_prsEq(DbsMsdc* dbsmsdc, const ubigint jrefTrig, const ubigint refInv, bool& boolvalRet);
	bool handleCallMsdcUsr_usgEq(DbsMsdc* dbsmsdc, const ubigint jrefTrig, const ubigint refInv, bool& boolvalRet);
	bool handleCallMsdcUsrUpd_refEq(DbsMsdc* dbsmsdc, const ubigint jrefTrig, const ubigint refInv);
	bool handleCallMsdcUsrJsteMod_usrEq(DbsMsdc* dbsmsdc, const ubigint jrefTrig, const ubigint refInv);
};

#endif

