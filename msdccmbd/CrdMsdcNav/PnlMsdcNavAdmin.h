/**
  * \file PnlMsdcNavAdmin.h
  * job handler for job PnlMsdcNavAdmin (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Oct 2018
  * \date modified: 4 Oct 2018
  */

#ifndef PNLMSDCNAVADMIN_H
#define PNLMSDCNAVADMIN_H

// IP custInclude --- INSERT

#define VecVMsdcNavAdminDo PnlMsdcNavAdmin::VecVDo

#define ContIacMsdcNavAdmin PnlMsdcNavAdmin::ContIac
#define StatAppMsdcNavAdmin PnlMsdcNavAdmin::StatApp
#define StatShrMsdcNavAdmin PnlMsdcNavAdmin::StatShr
#define TagMsdcNavAdmin PnlMsdcNavAdmin::Tag

#define DpchAppMsdcNavAdminData PnlMsdcNavAdmin::DpchAppData
#define DpchAppMsdcNavAdminDo PnlMsdcNavAdmin::DpchAppDo
#define DpchEngMsdcNavAdminData PnlMsdcNavAdmin::DpchEngData

/**
  * PnlMsdcNavAdmin
  */
class PnlMsdcNavAdmin : public JobMsdc {

public:
	/**
		* VecVDo (full: VecVMsdcNavAdminDo)
		*/
	class VecVDo {

	public:
		static const uint BUTUSGVIEWCLICK = 1;
		static const uint BUTUSGNEWCRDCLICK = 2;
		static const uint BUTUSRVIEWCLICK = 3;
		static const uint BUTUSRNEWCRDCLICK = 4;
		static const uint BUTPRSVIEWCLICK = 5;
		static const uint BUTPRSNEWCRDCLICK = 6;
		static const uint BUTSCFNEWCRDCLICK = 7;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacMsdcNavAdmin)
	  */
	class ContIac : public Block {

	public:
		static const uint NUMFLSTUSG = 1;
		static const uint NUMFLSTUSR = 2;
		static const uint NUMFLSTPRS = 3;

	public:
		ContIac(const uint numFLstUsg = 1, const uint numFLstUsr = 1, const uint numFLstPrs = 1);

	public:
		uint numFLstUsg;
		uint numFLstUsr;
		uint numFLstPrs;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
		* StatApp (full: StatAppMsdcNavAdmin)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const uint ixMsdcVExpstate = VecMsdcVExpstate::MIND, const bool LstUsgAlt = true, const bool LstUsrAlt = true, const bool LstPrsAlt = true, const uint LstUsgNumFirstdisp = 1, const uint LstUsrNumFirstdisp = 1, const uint LstPrsNumFirstdisp = 1);
	};

	/**
		* StatShr (full: StatShrMsdcNavAdmin)
		*/
	class StatShr : public Block {

	public:
		static const uint LSTUSGAVAIL = 1;
		static const uint BUTUSGVIEWACTIVE = 2;
		static const uint LSTUSRAVAIL = 3;
		static const uint BUTUSRVIEWACTIVE = 4;
		static const uint LSTPRSAVAIL = 5;
		static const uint BUTPRSVIEWACTIVE = 6;
		static const uint BUTSCFNEWCRDAVAIL = 7;

	public:
		StatShr(const bool LstUsgAvail = true, const bool ButUsgViewActive = true, const bool LstUsrAvail = true, const bool ButUsrViewActive = true, const bool LstPrsAvail = true, const bool ButPrsViewActive = true, const bool ButScfNewcrdAvail = true);

	public:
		bool LstUsgAvail;
		bool ButUsgViewActive;
		bool LstUsrAvail;
		bool ButUsrViewActive;
		bool LstPrsAvail;
		bool ButPrsViewActive;
		bool ButScfNewcrdAvail;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagMsdcNavAdmin)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixMsdcVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppMsdcNavAdminData)
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
		* DpchAppDo (full: DpchAppMsdcNavAdminDo)
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
		* DpchEngData (full: DpchEngMsdcNavAdminData)
		*/
	class DpchEngData : public DpchEngMsdc {

	public:
		static const uint JREF = 1;
		static const uint CONTIAC = 2;
		static const uint FEEDFLSTPRS = 3;
		static const uint FEEDFLSTUSG = 4;
		static const uint FEEDFLSTUSR = 5;
		static const uint STATAPP = 6;
		static const uint STATSHR = 7;
		static const uint TAG = 8;
		static const uint ALL = 9;

	public:
		DpchEngData(const ubigint jref = 0, ContIac* contiac = NULL, Feed* feedFLstPrs = NULL, Feed* feedFLstUsg = NULL, Feed* feedFLstUsr = NULL, StatShr* statshr = NULL, const set<uint>& mask = {NONE});

	public:
		ContIac contiac;
		Feed feedFLstPrs;
		Feed feedFLstUsg;
		Feed feedFLstUsr;
		StatShr statshr;

	public:
		string getSrefsMask();
		void merge(DpchEngMsdc* dpcheng);

		void writeXML(const uint ixMsdcVLocale, xmlTextWriter* wr);
	};

	bool evalLstUsgAvail(DbsMsdc* dbsmsdc);
	bool evalButUsgViewActive(DbsMsdc* dbsmsdc);
	bool evalLstUsrAvail(DbsMsdc* dbsmsdc);
	bool evalButUsrViewActive(DbsMsdc* dbsmsdc);
	bool evalLstPrsAvail(DbsMsdc* dbsmsdc);
	bool evalButPrsViewActive(DbsMsdc* dbsmsdc);
	bool evalButScfNewcrdAvail(DbsMsdc* dbsmsdc);

public:
	PnlMsdcNavAdmin(XchgMsdc* xchg, DbsMsdc* dbsmsdc, const ubigint jrefSup, const uint ixMsdcVLocale);
	~PnlMsdcNavAdmin();

public:
	ContIac contiac;
	StatShr statshr;

	Feed feedFLstPrs;
	Feed feedFLstUsg;
	Feed feedFLstUsr;

	// IP custVar --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngMsdc* getNewDpchEng(set<uint> items);

	void refreshLstUsg(DbsMsdc* dbsmsdc, set<uint>& moditems);
	void refreshUsg(DbsMsdc* dbsmsdc, set<uint>& moditems);
	void refreshLstUsr(DbsMsdc* dbsmsdc, set<uint>& moditems);
	void refreshUsr(DbsMsdc* dbsmsdc, set<uint>& moditems);
	void refreshLstPrs(DbsMsdc* dbsmsdc, set<uint>& moditems);
	void refreshPrs(DbsMsdc* dbsmsdc, set<uint>& moditems);
	void refresh(DbsMsdc* dbsmsdc, set<uint>& moditems);

	void updatePreset(DbsMsdc* dbsmsdc, const uint ixMsdcVPreset, const ubigint jrefTrig, const bool notif = false);

public:

	void handleRequest(DbsMsdc* dbsmsdc, ReqMsdc* req);

	void handleDpchAppMsdcInit(DbsMsdc* dbsmsdc, DpchAppMsdcInit* dpchappmsdcinit, DpchEngMsdc** dpcheng);
	void handleDpchAppDataContiac(DbsMsdc* dbsmsdc, ContIac* _contiac, DpchEngMsdc** dpcheng);

	void handleDpchAppDoButUsgViewClick(DbsMsdc* dbsmsdc, DpchEngMsdc** dpcheng);
	void handleDpchAppDoButUsgNewcrdClick(DbsMsdc* dbsmsdc, DpchEngMsdc** dpcheng);
	void handleDpchAppDoButUsrViewClick(DbsMsdc* dbsmsdc, DpchEngMsdc** dpcheng);
	void handleDpchAppDoButUsrNewcrdClick(DbsMsdc* dbsmsdc, DpchEngMsdc** dpcheng);
	void handleDpchAppDoButPrsViewClick(DbsMsdc* dbsmsdc, DpchEngMsdc** dpcheng);
	void handleDpchAppDoButPrsNewcrdClick(DbsMsdc* dbsmsdc, DpchEngMsdc** dpcheng);
	void handleDpchAppDoButScfNewcrdClick(DbsMsdc* dbsmsdc, DpchEngMsdc** dpcheng);

	void handleCall(DbsMsdc* dbsmsdc, Call* call);

	bool handleCallMsdcHusrRunvMod_crdUsrEq(DbsMsdc* dbsmsdc, const ubigint jrefTrig, const uint ixInv, const ubigint refInv);
};

#endif

