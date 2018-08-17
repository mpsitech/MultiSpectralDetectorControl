/**
  * \file DlgMsdcNavLoaini.h
  * job handler for job DlgMsdcNavLoaini (declarations)
  * \author Alexander Wirthmueller
  * \date created: 15 Aug 2018
  * \date modified: 15 Aug 2018
  */

#ifndef DLGMSDCNAVLOAINI_H
#define DLGMSDCNAVLOAINI_H

// IP custInclude --- INSERT

#include "IexMsdcIni.h"

#define VecVDlgMsdcNavLoainiDit DlgMsdcNavLoaini::VecVDit
#define VecVDlgMsdcNavLoainiDo DlgMsdcNavLoaini::VecVDo
#define VecVDlgMsdcNavLoainiDoImp DlgMsdcNavLoaini::VecVDoImp
#define VecVDlgMsdcNavLoainiSge DlgMsdcNavLoaini::VecVSge

#define ContIacDlgMsdcNavLoaini DlgMsdcNavLoaini::ContIac
#define ContInfDlgMsdcNavLoaini DlgMsdcNavLoaini::ContInf
#define ContInfDlgMsdcNavLoainiImp DlgMsdcNavLoaini::ContInfImp
#define ContInfDlgMsdcNavLoainiLfi DlgMsdcNavLoaini::ContInfLfi
#define StatAppDlgMsdcNavLoaini DlgMsdcNavLoaini::StatApp
#define StatShrDlgMsdcNavLoaini DlgMsdcNavLoaini::StatShr
#define StatShrDlgMsdcNavLoainiIfi DlgMsdcNavLoaini::StatShrIfi
#define StatShrDlgMsdcNavLoainiImp DlgMsdcNavLoaini::StatShrImp
#define StatShrDlgMsdcNavLoainiLfi DlgMsdcNavLoaini::StatShrLfi
#define TagDlgMsdcNavLoaini DlgMsdcNavLoaini::Tag
#define TagDlgMsdcNavLoainiIfi DlgMsdcNavLoaini::TagIfi
#define TagDlgMsdcNavLoainiImp DlgMsdcNavLoaini::TagImp
#define TagDlgMsdcNavLoainiLfi DlgMsdcNavLoaini::TagLfi

#define DpchAppDlgMsdcNavLoainiData DlgMsdcNavLoaini::DpchAppData
#define DpchAppDlgMsdcNavLoainiDo DlgMsdcNavLoaini::DpchAppDo
#define DpchEngDlgMsdcNavLoainiData DlgMsdcNavLoaini::DpchEngData

/**
  * DlgMsdcNavLoaini
  */
class DlgMsdcNavLoaini : public JobMsdc {

public:
	/**
		* VecVDit (full: VecVDlgMsdcNavLoainiDit)
		*/
	class VecVDit {

	public:
		static const uint IFI = 1;
		static const uint IMP = 2;
		static const uint LFI = 3;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);

		static string getTitle(const uint ix, const uint ixMsdcVLocale);

		static void fillFeed(const uint ixMsdcVLocale, Feed& feed);
	};

	/**
		* VecVDo (full: VecVDlgMsdcNavLoainiDo)
		*/
	class VecVDo {

	public:
		static const uint BUTDNECLICK = 1;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
		* VecVDoImp (full: VecVDlgMsdcNavLoainiDoImp)
		*/
	class VecVDoImp {

	public:
		static const uint BUTRUNCLICK = 1;
		static const uint BUTSTOCLICK = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
		* VecVSge (full: VecVDlgMsdcNavLoainiSge)
		*/
	class VecVSge {

	public:
		static const uint IDLE = 1;
		static const uint PRSIDLE = 2;
		static const uint PARSE = 3;
		static const uint ALRMSDCPER = 4;
		static const uint PRSDONE = 5;
		static const uint IMPIDLE = 6;
		static const uint IMPORT = 7;
		static const uint DONE = 8;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);

		static void fillFeed(Feed& feed);
	};

	/**
	  * ContIac (full: ContIacDlgMsdcNavLoaini)
	  */
	class ContIac : public Block {

	public:
		static const uint NUMFDSE = 1;

	public:
		ContIac(const uint numFDse = 1);

	public:
		uint numFDse;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfDlgMsdcNavLoaini)
	  */
	class ContInf : public Block {

	public:
		static const uint NUMFSGE = 1;

	public:
		ContInf(const uint numFSge = 1);

	public:
		uint numFSge;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
	  * ContInfImp (full: ContInfDlgMsdcNavLoainiImp)
	  */
	class ContInfImp : public Block {

	public:
		static const uint TXTPRG = 1;

	public:
		ContInfImp(const string& TxtPrg = "");

	public:
		string TxtPrg;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContInfImp* comp);
		set<uint> diff(const ContInfImp* comp);
	};

	/**
	  * ContInfLfi (full: ContInfDlgMsdcNavLoainiLfi)
	  */
	class ContInfLfi : public Block {

	public:
		static const uint DLD = 1;

	public:
		ContInfLfi(const string& Dld = "file");

	public:
		string Dld;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContInfLfi* comp);
		set<uint> diff(const ContInfLfi* comp);
	};

	/**
		* StatApp (full: StatAppDlgMsdcNavLoaini)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const bool initdone = false, const string& shortMenu = "");
	};

	/**
		* StatShr (full: StatShrDlgMsdcNavLoaini)
		*/
	class StatShr : public Block {

	public:
		static const uint BUTDNEACTIVE = 1;

	public:
		StatShr(const bool ButDneActive = true);

	public:
		bool ButDneActive;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* StatShrIfi (full: StatShrDlgMsdcNavLoainiIfi)
		*/
	class StatShrIfi : public Block {

	public:
		static const uint ULDACTIVE = 1;

	public:
		StatShrIfi(const bool UldActive = true);

	public:
		bool UldActive;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShrIfi* comp);
		set<uint> diff(const StatShrIfi* comp);
	};

	/**
		* StatShrImp (full: StatShrDlgMsdcNavLoainiImp)
		*/
	class StatShrImp : public Block {

	public:
		static const uint BUTRUNACTIVE = 1;
		static const uint BUTSTOACTIVE = 2;

	public:
		StatShrImp(const bool ButRunActive = true, const bool ButStoActive = true);

	public:
		bool ButRunActive;
		bool ButStoActive;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShrImp* comp);
		set<uint> diff(const StatShrImp* comp);
	};

	/**
		* StatShrLfi (full: StatShrDlgMsdcNavLoainiLfi)
		*/
	class StatShrLfi : public Block {

	public:
		static const uint DLDACTIVE = 1;

	public:
		StatShrLfi(const bool DldActive = true);

	public:
		bool DldActive;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShrLfi* comp);
		set<uint> diff(const StatShrLfi* comp);
	};

	/**
		* Tag (full: TagDlgMsdcNavLoaini)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixMsdcVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* TagIfi (full: TagDlgMsdcNavLoainiIfi)
		*/
	class TagIfi {

	public:
		static void writeXML(const uint ixMsdcVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* TagImp (full: TagDlgMsdcNavLoainiImp)
		*/
	class TagImp {

	public:
		static void writeXML(const uint ixMsdcVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* TagLfi (full: TagDlgMsdcNavLoainiLfi)
		*/
	class TagLfi {

	public:
		static void writeXML(const uint ixMsdcVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppDlgMsdcNavLoainiData)
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

		void readXML(pthread_mutex_t* mScr, map<string,ubigint>& descr, xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppDlgMsdcNavLoainiDo)
		*/
	class DpchAppDo : public DpchAppMsdc {

	public:
		static const uint JREF = 1;
		static const uint IXVDO = 2;
		static const uint IXVDOIMP = 3;

	public:
		DpchAppDo();

	public:
		uint ixVDo;
		uint ixVDoImp;

	public:
		string getSrefsMask();

		void readXML(pthread_mutex_t* mScr, map<string,ubigint>& descr, xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngData (full: DpchEngDlgMsdcNavLoainiData)
		*/
	class DpchEngData : public DpchEngMsdc {

	public:
		static const uint JREF = 1;
		static const uint CONTIAC = 2;
		static const uint CONTINF = 3;
		static const uint CONTINFIMP = 4;
		static const uint CONTINFLFI = 5;
		static const uint FEEDFDSE = 6;
		static const uint FEEDFSGE = 7;
		static const uint STATAPP = 8;
		static const uint STATSHR = 9;
		static const uint STATSHRIFI = 10;
		static const uint STATSHRIMP = 11;
		static const uint STATSHRLFI = 12;
		static const uint TAG = 13;
		static const uint TAGIFI = 14;
		static const uint TAGIMP = 15;
		static const uint TAGLFI = 16;
		static const uint ALL = 17;

	public:
		DpchEngData(const ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, ContInfImp* continfimp = NULL, ContInfLfi* continflfi = NULL, Feed* feedFDse = NULL, Feed* feedFSge = NULL, StatShr* statshr = NULL, StatShrIfi* statshrifi = NULL, StatShrImp* statshrimp = NULL, StatShrLfi* statshrlfi = NULL, const set<uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		ContInfImp continfimp;
		ContInfLfi continflfi;
		Feed feedFDse;
		Feed feedFSge;
		StatShr statshr;
		StatShrIfi statshrifi;
		StatShrImp statshrimp;
		StatShrLfi statshrlfi;

	public:
		string getSrefsMask();
		void merge(DpchEngMsdc* dpcheng);

		void writeXML(const uint ixMsdcVLocale, pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
	};

	bool evalIfiUldActive(DbsMsdc* dbsmsdc);
	bool evalImpButRunActive(DbsMsdc* dbsmsdc);
	bool evalImpButStoActive(DbsMsdc* dbsmsdc);
	bool evalLfiDldActive(DbsMsdc* dbsmsdc);
	bool evalButDneActive(DbsMsdc* dbsmsdc);

public:
	DlgMsdcNavLoaini(XchgMsdc* xchg, DbsMsdc* dbsmsdc, const ubigint jrefSup, const uint ixMsdcVLocale);
	~DlgMsdcNavLoaini();

public:
	ContIac contiac;
	ContInf continf;
	ContInfImp continfimp;
	ContInfLfi continflfi;
	StatShr statshr;
	StatShrIfi statshrifi;
	StatShrImp statshrimp;
	StatShrLfi statshrlfi;

	Feed feedFMcbAlert;
	Feed feedFDse;
	Feed feedFSge;

	IexMsdcIni* iex;

	uint ixVDit;

	string infilename; // IP custVar --- ILINE

public:
	// IP cust --- INSERT

public:
	DpchEngMsdc* getNewDpchEng(set<uint> items);

	void refreshIfi(DbsMsdc* dbsmsdc, set<uint>& moditems);
	void refreshImp(DbsMsdc* dbsmsdc, set<uint>& moditems);
	void refreshLfi(DbsMsdc* dbsmsdc, set<uint>& moditems);

	void refresh(DbsMsdc* dbsmsdc, set<uint>& moditems);

public:
	void changeStage(DbsMsdc* dbsmsdc, uint _ixVSge, DpchEngMsdc** dpcheng = NULL);

	uint enterSgeIdle(DbsMsdc* dbsmsdc, const bool reenter);
	void leaveSgeIdle(DbsMsdc* dbsmsdc);
	uint enterSgePrsidle(DbsMsdc* dbsmsdc, const bool reenter);
	void leaveSgePrsidle(DbsMsdc* dbsmsdc);
	uint enterSgeParse(DbsMsdc* dbsmsdc, const bool reenter);
	void leaveSgeParse(DbsMsdc* dbsmsdc);
	uint enterSgeAlrMsdcper(DbsMsdc* dbsmsdc, const bool reenter);
	void leaveSgeAlrMsdcper(DbsMsdc* dbsmsdc);
	uint enterSgePrsdone(DbsMsdc* dbsmsdc, const bool reenter);
	void leaveSgePrsdone(DbsMsdc* dbsmsdc);
	uint enterSgeImpidle(DbsMsdc* dbsmsdc, const bool reenter);
	void leaveSgeImpidle(DbsMsdc* dbsmsdc);
	uint enterSgeImport(DbsMsdc* dbsmsdc, const bool reenter);
	void leaveSgeImport(DbsMsdc* dbsmsdc);
	uint enterSgeDone(DbsMsdc* dbsmsdc, const bool reenter);
	void leaveSgeDone(DbsMsdc* dbsmsdc);

	string getSquawk(DbsMsdc* dbsmsdc);

	void handleRequest(DbsMsdc* dbsmsdc, ReqMsdc* req);

	void handleDpchAppMsdcInit(DbsMsdc* dbsmsdc, DpchAppMsdcInit* dpchappmsdcinit, DpchEngMsdc** dpcheng);
	void handleDpchAppDataContiac(DbsMsdc* dbsmsdc, ContIac* _contiac, DpchEngMsdc** dpcheng);

	void handleDpchAppDoButDneClick(DbsMsdc* dbsmsdc, DpchEngMsdc** dpcheng);

	void handleDpchAppDoImpButRunClick(DbsMsdc* dbsmsdc, DpchEngMsdc** dpcheng);
	void handleDpchAppDoImpButStoClick(DbsMsdc* dbsmsdc, DpchEngMsdc** dpcheng);
	void handleDpchAppMsdcAlert(DbsMsdc* dbsmsdc, DpchAppMsdcAlert* dpchappmsdcalert, DpchEngMsdc** dpcheng);

	void handleUpload(DbsMsdc* dbsmsdc, const string& filename);
	string handleDownload(DbsMsdc* dbsmsdc);
	void handleTimer(DbsMsdc* dbsmsdc, const string& sref);

};

#endif




