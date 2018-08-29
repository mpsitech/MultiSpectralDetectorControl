/**
  * \file PnlMsdcNavOpr.h
  * job handler for job PnlMsdcNavOpr (declarations)
  * \author Alexander Wirthmueller
  * \date created: 29 Aug 2018
  * \date modified: 29 Aug 2018
  */

#ifndef PNLMSDCNAVOPR_H
#define PNLMSDCNAVOPR_H

// IP custInclude --- INSERT

#define VecVMsdcNavOprDo PnlMsdcNavOpr::VecVDo

#define ContIacMsdcNavOpr PnlMsdcNavOpr::ContIac
#define StatAppMsdcNavOpr PnlMsdcNavOpr::StatApp
#define StatShrMsdcNavOpr PnlMsdcNavOpr::StatShr
#define TagMsdcNavOpr PnlMsdcNavOpr::Tag

#define DpchAppMsdcNavOprData PnlMsdcNavOpr::DpchAppData
#define DpchAppMsdcNavOprDo PnlMsdcNavOpr::DpchAppDo
#define DpchEngMsdcNavOprData PnlMsdcNavOpr::DpchEngData

/**
  * PnlMsdcNavOpr
  */
class PnlMsdcNavOpr : public JobMsdc {

public:
	/**
		* VecVDo (full: VecVMsdcNavOprDo)
		*/
	class VecVDo {

	public:
		static const uint BUTLIVNEWCRDCLICK = 1;
		static const uint BUTPRDVIEWCLICK = 2;
		static const uint BUTPRDNEWCRDCLICK = 3;
		static const uint BUTDATVIEWCLICK = 4;
		static const uint BUTDATNEWCRDCLICK = 5;
		static const uint BUTFILVIEWCLICK = 6;
		static const uint BUTFILNEWCRDCLICK = 7;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacMsdcNavOpr)
	  */
	class ContIac : public Block {

	public:
		static const uint NUMFLSTPRD = 1;
		static const uint NUMFLSTDAT = 2;
		static const uint NUMFLSTFIL = 3;

	public:
		ContIac(const uint numFLstPrd = 1, const uint numFLstDat = 1, const uint numFLstFil = 1);

	public:
		uint numFLstPrd;
		uint numFLstDat;
		uint numFLstFil;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
		* StatApp (full: StatAppMsdcNavOpr)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const uint ixMsdcVExpstate = VecMsdcVExpstate::MIND, const bool LstPrdAlt = true, const bool LstDatAlt = true, const bool LstFilAlt = true, const uint LstPrdNumFirstdisp = 1, const uint LstDatNumFirstdisp = 1, const uint LstFilNumFirstdisp = 1);
	};

	/**
		* StatShr (full: StatShrMsdcNavOpr)
		*/
	class StatShr : public Block {

	public:
		static const uint BUTLIVNEWCRDAVAIL = 1;
		static const uint LSTPRDAVAIL = 2;
		static const uint BUTPRDVIEWACTIVE = 3;
		static const uint LSTDATAVAIL = 4;
		static const uint BUTDATVIEWACTIVE = 5;
		static const uint BUTDATNEWCRDACTIVE = 6;
		static const uint LSTFILAVAIL = 7;
		static const uint BUTFILVIEWACTIVE = 8;
		static const uint BUTFILNEWCRDACTIVE = 9;

	public:
		StatShr(const bool ButLivNewcrdAvail = true, const bool LstPrdAvail = true, const bool ButPrdViewActive = true, const bool LstDatAvail = true, const bool ButDatViewActive = true, const bool ButDatNewcrdActive = true, const bool LstFilAvail = true, const bool ButFilViewActive = true, const bool ButFilNewcrdActive = true);

	public:
		bool ButLivNewcrdAvail;
		bool LstPrdAvail;
		bool ButPrdViewActive;
		bool LstDatAvail;
		bool ButDatViewActive;
		bool ButDatNewcrdActive;
		bool LstFilAvail;
		bool ButFilViewActive;
		bool ButFilNewcrdActive;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagMsdcNavOpr)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixMsdcVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppMsdcNavOprData)
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
		* DpchAppDo (full: DpchAppMsdcNavOprDo)
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
		* DpchEngData (full: DpchEngMsdcNavOprData)
		*/
	class DpchEngData : public DpchEngMsdc {

	public:
		static const uint JREF = 1;
		static const uint CONTIAC = 2;
		static const uint FEEDFLSTDAT = 3;
		static const uint FEEDFLSTFIL = 4;
		static const uint FEEDFLSTPRD = 5;
		static const uint STATAPP = 6;
		static const uint STATSHR = 7;
		static const uint TAG = 8;
		static const uint ALL = 9;

	public:
		DpchEngData(const ubigint jref = 0, ContIac* contiac = NULL, Feed* feedFLstDat = NULL, Feed* feedFLstFil = NULL, Feed* feedFLstPrd = NULL, StatShr* statshr = NULL, const set<uint>& mask = {NONE});

	public:
		ContIac contiac;
		Feed feedFLstDat;
		Feed feedFLstFil;
		Feed feedFLstPrd;
		StatShr statshr;

	public:
		string getSrefsMask();
		void merge(DpchEngMsdc* dpcheng);

		void writeXML(const uint ixMsdcVLocale, xmlTextWriter* wr);
	};

	bool evalButLivNewcrdAvail(DbsMsdc* dbsmsdc);
	bool evalLstPrdAvail(DbsMsdc* dbsmsdc);
	bool evalButPrdViewActive(DbsMsdc* dbsmsdc);
	bool evalLstDatAvail(DbsMsdc* dbsmsdc);
	bool evalButDatViewActive(DbsMsdc* dbsmsdc);
	bool evalButDatNewcrdActive(DbsMsdc* dbsmsdc);
	bool evalLstFilAvail(DbsMsdc* dbsmsdc);
	bool evalButFilViewActive(DbsMsdc* dbsmsdc);
	bool evalButFilNewcrdActive(DbsMsdc* dbsmsdc);

public:
	PnlMsdcNavOpr(XchgMsdc* xchg, DbsMsdc* dbsmsdc, const ubigint jrefSup, const uint ixMsdcVLocale);
	~PnlMsdcNavOpr();

public:
	ContIac contiac;
	StatShr statshr;

	Feed feedFLstDat;
	Feed feedFLstFil;
	Feed feedFLstPrd;

	// IP custVar --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngMsdc* getNewDpchEng(set<uint> items);

	void refreshLstPrd(DbsMsdc* dbsmsdc, set<uint>& moditems);
	void refreshPrd(DbsMsdc* dbsmsdc, set<uint>& moditems);
	void refreshLstDat(DbsMsdc* dbsmsdc, set<uint>& moditems);
	void refreshDat(DbsMsdc* dbsmsdc, set<uint>& moditems);
	void refreshLstFil(DbsMsdc* dbsmsdc, set<uint>& moditems);
	void refreshFil(DbsMsdc* dbsmsdc, set<uint>& moditems);
	void refresh(DbsMsdc* dbsmsdc, set<uint>& moditems);

	void updatePreset(DbsMsdc* dbsmsdc, const uint ixMsdcVPreset, const ubigint jrefTrig, const bool notif = false);

public:

	void handleRequest(DbsMsdc* dbsmsdc, ReqMsdc* req);

	void handleDpchAppMsdcInit(DbsMsdc* dbsmsdc, DpchAppMsdcInit* dpchappmsdcinit, DpchEngMsdc** dpcheng);
	void handleDpchAppDataContiac(DbsMsdc* dbsmsdc, ContIac* _contiac, DpchEngMsdc** dpcheng);

	void handleDpchAppDoButLivNewcrdClick(DbsMsdc* dbsmsdc, DpchEngMsdc** dpcheng);
	void handleDpchAppDoButPrdViewClick(DbsMsdc* dbsmsdc, DpchEngMsdc** dpcheng);
	void handleDpchAppDoButPrdNewcrdClick(DbsMsdc* dbsmsdc, DpchEngMsdc** dpcheng);
	void handleDpchAppDoButDatViewClick(DbsMsdc* dbsmsdc, DpchEngMsdc** dpcheng);
	void handleDpchAppDoButDatNewcrdClick(DbsMsdc* dbsmsdc, DpchEngMsdc** dpcheng);
	void handleDpchAppDoButFilViewClick(DbsMsdc* dbsmsdc, DpchEngMsdc** dpcheng);
	void handleDpchAppDoButFilNewcrdClick(DbsMsdc* dbsmsdc, DpchEngMsdc** dpcheng);

	void handleCall(DbsMsdc* dbsmsdc, Call* call);

	bool handleCallMsdcHusrRunvMod_crdUsrEq(DbsMsdc* dbsmsdc, const ubigint jrefTrig, const uint ixInv, const ubigint refInv);
};

#endif

