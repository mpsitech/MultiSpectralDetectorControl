/**
  * \file PnlMsdcUsgAAccess.h
  * job handler for job PnlMsdcUsgAAccess (declarations)
  * \author Alexander Wirthmueller
  * \date created: 29 Aug 2018
  * \date modified: 29 Aug 2018
  */

#ifndef PNLMSDCUSGAACCESS_H
#define PNLMSDCUSGAACCESS_H

// IP custInclude --- INSERT

#include "QryMsdcUsgAAccess.h"

#define VecVMsdcUsgAAccessDo PnlMsdcUsgAAccess::VecVDo

#define ContInfMsdcUsgAAccess PnlMsdcUsgAAccess::ContInf
#define StatAppMsdcUsgAAccess PnlMsdcUsgAAccess::StatApp
#define StatShrMsdcUsgAAccess PnlMsdcUsgAAccess::StatShr
#define StgIacMsdcUsgAAccess PnlMsdcUsgAAccess::StgIac
#define TagMsdcUsgAAccess PnlMsdcUsgAAccess::Tag

#define DpchAppMsdcUsgAAccessData PnlMsdcUsgAAccess::DpchAppData
#define DpchAppMsdcUsgAAccessDo PnlMsdcUsgAAccess::DpchAppDo
#define DpchEngMsdcUsgAAccessData PnlMsdcUsgAAccess::DpchEngData

/**
  * PnlMsdcUsgAAccess
  */
class PnlMsdcUsgAAccess : public JobMsdc {

public:
	/**
		* VecVDo (full: VecVMsdcUsgAAccessDo)
		*/
	class VecVDo {

	public:
		static const uint BUTNEWCLICK = 1;
		static const uint BUTDUPLICATECLICK = 2;
		static const uint BUTDELETECLICK = 3;
		static const uint BUTREFRESHCLICK = 4;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContInf (full: ContInfMsdcUsgAAccess)
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
		* StatApp (full: StatAppMsdcUsgAAccess)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const uint ixMsdcVExpstate = VecMsdcVExpstate::MIND);
	};

	/**
		* StatShr (full: StatShrMsdcUsgAAccess)
		*/
	class StatShr : public Block {

	public:
		static const uint BUTNEWAVAIL = 1;
		static const uint BUTDUPLICATEAVAIL = 2;
		static const uint BUTDUPLICATEACTIVE = 3;
		static const uint BUTDELETEAVAIL = 4;
		static const uint BUTDELETEACTIVE = 5;

	public:
		StatShr(const bool ButNewAvail = true, const bool ButDuplicateAvail = true, const bool ButDuplicateActive = true, const bool ButDeleteAvail = true, const bool ButDeleteActive = true);

	public:
		bool ButNewAvail;
		bool ButDuplicateAvail;
		bool ButDuplicateActive;
		bool ButDeleteAvail;
		bool ButDeleteActive;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* StgIac (full: StgIacMsdcUsgAAccess)
		*/
	class StgIac : public Block {

	public:
		static const uint TCOFEGWIDTH = 1;
		static const uint TCOFEAWIDTH = 2;
		static const uint TCOACCWIDTH = 3;

	public:
		StgIac(const uint TcoFegWidth = 100, const uint TcoFeaWidth = 100, const uint TcoAccWidth = 100);

	public:
		uint TcoFegWidth;
		uint TcoFeaWidth;
		uint TcoAccWidth;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StgIac* comp);
		set<uint> diff(const StgIac* comp);
	};

	/**
		* Tag (full: TagMsdcUsgAAccess)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixMsdcVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppMsdcUsgAAccessData)
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
		QryMsdcUsgAAccess::StgIac stgiacqry;

	public:
		string getSrefsMask();

		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppMsdcUsgAAccessDo)
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
		* DpchEngData (full: DpchEngMsdcUsgAAccessData)
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
		DpchEngData(const ubigint jref = 0, ContInf* continf = NULL, Feed* feedFCsiQst = NULL, StatShr* statshr = NULL, StgIac* stgiac = NULL, ListMsdcQUsgAAccess* rst = NULL, QryMsdcUsgAAccess::StatShr* statshrqry = NULL, QryMsdcUsgAAccess::StgIac* stgiacqry = NULL, const set<uint>& mask = {NONE});

	public:
		ContInf continf;
		Feed feedFCsiQst;
		StatShr statshr;
		StgIac stgiac;
		ListMsdcQUsgAAccess rst;
		QryMsdcUsgAAccess::StatShr statshrqry;
		QryMsdcUsgAAccess::StgIac stgiacqry;

	public:
		string getSrefsMask();
		void merge(DpchEngMsdc* dpcheng);

		void writeXML(const uint ixMsdcVLocale, xmlTextWriter* wr);
	};

	bool evalButNewAvail(DbsMsdc* dbsmsdc);
	bool evalButDuplicateAvail(DbsMsdc* dbsmsdc);
	bool evalButDuplicateActive(DbsMsdc* dbsmsdc);
	bool evalButDeleteAvail(DbsMsdc* dbsmsdc);
	bool evalButDeleteActive(DbsMsdc* dbsmsdc);

public:
	PnlMsdcUsgAAccess(XchgMsdc* xchg, DbsMsdc* dbsmsdc, const ubigint jrefSup, const uint ixMsdcVLocale);
	~PnlMsdcUsgAAccess();

public:
	ContInf continf;
	StatShr statshr;
	StgIac stgiac;

	Feed feedFCsiQst;

	QryMsdcUsgAAccess* qry;

	MsdcAMUsergroupAccess recUsgAacc;

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
	void handleDpchAppDataStgiacqry(DbsMsdc* dbsmsdc, QryMsdcUsgAAccess::StgIac* _stgiacqry, DpchEngMsdc** dpcheng);

	void handleDpchAppDoButNewClick(DbsMsdc* dbsmsdc, DpchEngMsdc** dpcheng);
	void handleDpchAppDoButDuplicateClick(DbsMsdc* dbsmsdc, DpchEngMsdc** dpcheng);
	void handleDpchAppDoButDeleteClick(DbsMsdc* dbsmsdc, DpchEngMsdc** dpcheng);
	void handleDpchAppDoButRefreshClick(DbsMsdc* dbsmsdc, DpchEngMsdc** dpcheng);

	void handleCall(DbsMsdc* dbsmsdc, Call* call);

	bool handleCallMsdcStatChg(DbsMsdc* dbsmsdc, const ubigint jrefTrig);
};

#endif

