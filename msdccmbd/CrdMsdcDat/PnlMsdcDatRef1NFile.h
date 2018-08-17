/**
  * \file PnlMsdcDatRef1NFile.h
  * job handler for job PnlMsdcDatRef1NFile (declarations)
  * \author Alexander Wirthmueller
  * \date created: 15 Aug 2018
  * \date modified: 15 Aug 2018
  */

#ifndef PNLMSDCDATREF1NFILE_H
#define PNLMSDCDATREF1NFILE_H

// IP custInclude --- INSERT

#include "QryMsdcDatRef1NFile.h"

#define VecVMsdcDatRef1NFileDo PnlMsdcDatRef1NFile::VecVDo

#define ContInfMsdcDatRef1NFile PnlMsdcDatRef1NFile::ContInf
#define StatAppMsdcDatRef1NFile PnlMsdcDatRef1NFile::StatApp
#define StatShrMsdcDatRef1NFile PnlMsdcDatRef1NFile::StatShr
#define StgIacMsdcDatRef1NFile PnlMsdcDatRef1NFile::StgIac
#define TagMsdcDatRef1NFile PnlMsdcDatRef1NFile::Tag

#define DpchAppMsdcDatRef1NFileData PnlMsdcDatRef1NFile::DpchAppData
#define DpchAppMsdcDatRef1NFileDo PnlMsdcDatRef1NFile::DpchAppDo
#define DpchEngMsdcDatRef1NFileData PnlMsdcDatRef1NFile::DpchEngData

/**
  * PnlMsdcDatRef1NFile
  */
class PnlMsdcDatRef1NFile : public JobMsdc {

public:
	/**
		* VecVDo (full: VecVMsdcDatRef1NFileDo)
		*/
	class VecVDo {

	public:
		static const uint BUTVIEWCLICK = 1;
		static const uint BUTNEWCLICK = 2;
		static const uint BUTDELETECLICK = 3;
		static const uint BUTREFRESHCLICK = 4;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContInf (full: ContInfMsdcDatRef1NFile)
	  */
	class ContInf : public Block {

	public:
		static const uint NUMFCSIQST = 1;

	public:
		ContInf(const uint numFCsiQst = 1);

	public:
		uint numFCsiQst;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppMsdcDatRef1NFile)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const uint ixMsdcVExpstate = VecMsdcVExpstate::MIND);
	};

	/**
		* StatShr (full: StatShrMsdcDatRef1NFile)
		*/
	class StatShr : public Block {

	public:
		static const uint BUTVIEWAVAIL = 1;
		static const uint BUTVIEWACTIVE = 2;
		static const uint BUTNEWAVAIL = 3;
		static const uint BUTDELETEAVAIL = 4;
		static const uint BUTDELETEACTIVE = 5;

	public:
		StatShr(const bool ButViewAvail = true, const bool ButViewActive = true, const bool ButNewAvail = true, const bool ButDeleteAvail = true, const bool ButDeleteActive = true);

	public:
		bool ButViewAvail;
		bool ButViewActive;
		bool ButNewAvail;
		bool ButDeleteAvail;
		bool ButDeleteActive;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* StgIac (full: StgIacMsdcDatRef1NFile)
		*/
	class StgIac : public Block {

	public:
		static const uint TCOREFWIDTH = 1;

	public:
		StgIac(const uint TcoRefWidth = 100);

	public:
		uint TcoRefWidth;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StgIac* comp);
		set<uint> diff(const StgIac* comp);
	};

	/**
		* Tag (full: TagMsdcDatRef1NFile)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixMsdcVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppMsdcDatRef1NFileData)
		*/
	class DpchAppData : public DpchAppMsdc {

	public:
		static const uint JREF = 1;
		static const uint STGIAC = 2;
		static const uint STGIACQRY = 3;

	public:
		DpchAppData();

	public:
		StgIac stgiac;
		QryMsdcDatRef1NFile::StgIac stgiacqry;

	public:
		string getSrefsMask();

		void readXML(pthread_mutex_t* mScr, map<string,ubigint>& descr, xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppMsdcDatRef1NFileDo)
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

		void readXML(pthread_mutex_t* mScr, map<string,ubigint>& descr, xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngData (full: DpchEngMsdcDatRef1NFileData)
		*/
	class DpchEngData : public DpchEngMsdc {

	public:
		static const uint JREF = 1;
		static const uint CONTINF = 2;
		static const uint FEEDFCSIQST = 3;
		static const uint STATAPP = 4;
		static const uint STATSHR = 5;
		static const uint STGIAC = 6;
		static const uint TAG = 7;
		static const uint RST = 8;
		static const uint STATAPPQRY = 9;
		static const uint STATSHRQRY = 10;
		static const uint STGIACQRY = 11;
		static const uint ALL = 12;

	public:
		DpchEngData(const ubigint jref = 0, ContInf* continf = NULL, Feed* feedFCsiQst = NULL, StatShr* statshr = NULL, StgIac* stgiac = NULL, ListMsdcQDatRef1NFile* rst = NULL, QryMsdcDatRef1NFile::StatShr* statshrqry = NULL, QryMsdcDatRef1NFile::StgIac* stgiacqry = NULL, const set<uint>& mask = {NONE});

	public:
		ContInf continf;
		Feed feedFCsiQst;
		StatShr statshr;
		StgIac stgiac;
		ListMsdcQDatRef1NFile rst;
		QryMsdcDatRef1NFile::StatShr statshrqry;
		QryMsdcDatRef1NFile::StgIac stgiacqry;

	public:
		string getSrefsMask();
		void merge(DpchEngMsdc* dpcheng);

		void writeXML(const uint ixMsdcVLocale, pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
	};

	bool evalButViewAvail(DbsMsdc* dbsmsdc);
	bool evalButViewActive(DbsMsdc* dbsmsdc);
	bool evalButNewAvail(DbsMsdc* dbsmsdc);
	bool evalButDeleteAvail(DbsMsdc* dbsmsdc);
	bool evalButDeleteActive(DbsMsdc* dbsmsdc);

public:
	PnlMsdcDatRef1NFile(XchgMsdc* xchg, DbsMsdc* dbsmsdc, const ubigint jrefSup, const uint ixMsdcVLocale);
	~PnlMsdcDatRef1NFile();

public:
	ContInf continf;
	StatShr statshr;
	StgIac stgiac;

	Feed feedFCsiQst;

	QryMsdcDatRef1NFile* qry;

	MsdcMFile recFil;

	// IP custVar --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngMsdc* getNewDpchEng(set<uint> items);

	void refresh(DbsMsdc* dbsmsdc, set<uint>& moditems);

	void updatePreset(DbsMsdc* dbsmsdc, const uint ixMsdcVPreset, const ubigint jrefTrig, const bool notif = false);

public:

	void handleRequest(DbsMsdc* dbsmsdc, ReqMsdc* req);

	void handleDpchAppMsdcInit(DbsMsdc* dbsmsdc, DpchAppMsdcInit* dpchappmsdcinit, DpchEngMsdc** dpcheng);
	void handleDpchAppDataStgiac(DbsMsdc* dbsmsdc, StgIac* _stgiac, DpchEngMsdc** dpcheng);
	void handleDpchAppDataStgiacqry(DbsMsdc* dbsmsdc, QryMsdcDatRef1NFile::StgIac* _stgiacqry, DpchEngMsdc** dpcheng);

	void handleDpchAppDoButViewClick(DbsMsdc* dbsmsdc, DpchEngMsdc** dpcheng);
	void handleDpchAppDoButNewClick(DbsMsdc* dbsmsdc, DpchEngMsdc** dpcheng);
	void handleDpchAppDoButDeleteClick(DbsMsdc* dbsmsdc, DpchEngMsdc** dpcheng);
	void handleDpchAppDoButRefreshClick(DbsMsdc* dbsmsdc, DpchEngMsdc** dpcheng);

	void handleCall(DbsMsdc* dbsmsdc, Call* call);

	bool handleCallMsdcStatChg(DbsMsdc* dbsmsdc, const ubigint jrefTrig);
};

#endif

