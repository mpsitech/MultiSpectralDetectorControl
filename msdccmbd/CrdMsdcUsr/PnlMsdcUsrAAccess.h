/**
  * \file PnlMsdcUsrAAccess.h
  * job handler for job PnlMsdcUsrAAccess (declarations)
  * \author Alexander Wirthmueller
  * \date created: 29 Aug 2018
  * \date modified: 29 Aug 2018
  */

#ifndef PNLMSDCUSRAACCESS_H
#define PNLMSDCUSRAACCESS_H

// IP custInclude --- INSERT

#include "QryMsdcUsrAAccess.h"

#define VecVMsdcUsrAAccessDo PnlMsdcUsrAAccess::VecVDo

#define ContInfMsdcUsrAAccess PnlMsdcUsrAAccess::ContInf
#define StatAppMsdcUsrAAccess PnlMsdcUsrAAccess::StatApp
#define StatShrMsdcUsrAAccess PnlMsdcUsrAAccess::StatShr
#define StgIacMsdcUsrAAccess PnlMsdcUsrAAccess::StgIac
#define TagMsdcUsrAAccess PnlMsdcUsrAAccess::Tag

#define DpchAppMsdcUsrAAccessData PnlMsdcUsrAAccess::DpchAppData
#define DpchAppMsdcUsrAAccessDo PnlMsdcUsrAAccess::DpchAppDo
#define DpchEngMsdcUsrAAccessData PnlMsdcUsrAAccess::DpchEngData

/**
  * PnlMsdcUsrAAccess
  */
class PnlMsdcUsrAAccess : public JobMsdc {

public:
	/**
		* VecVDo (full: VecVMsdcUsrAAccessDo)
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
	  * ContInf (full: ContInfMsdcUsrAAccess)
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
		* StatApp (full: StatAppMsdcUsrAAccess)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const uint ixMsdcVExpstate = VecMsdcVExpstate::MIND);
	};

	/**
		* StatShr (full: StatShrMsdcUsrAAccess)
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
		* StgIac (full: StgIacMsdcUsrAAccess)
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
		* Tag (full: TagMsdcUsrAAccess)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixMsdcVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppMsdcUsrAAccessData)
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
		QryMsdcUsrAAccess::StgIac stgiacqry;

	public:
		string getSrefsMask();

		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppMsdcUsrAAccessDo)
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
		* DpchEngData (full: DpchEngMsdcUsrAAccessData)
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
		DpchEngData(const ubigint jref = 0, ContInf* continf = NULL, Feed* feedFCsiQst = NULL, StatShr* statshr = NULL, StgIac* stgiac = NULL, ListMsdcQUsrAAccess* rst = NULL, QryMsdcUsrAAccess::StatShr* statshrqry = NULL, QryMsdcUsrAAccess::StgIac* stgiacqry = NULL, const set<uint>& mask = {NONE});

	public:
		ContInf continf;
		Feed feedFCsiQst;
		StatShr statshr;
		StgIac stgiac;
		ListMsdcQUsrAAccess rst;
		QryMsdcUsrAAccess::StatShr statshrqry;
		QryMsdcUsrAAccess::StgIac stgiacqry;

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
	PnlMsdcUsrAAccess(XchgMsdc* xchg, DbsMsdc* dbsmsdc, const ubigint jrefSup, const uint ixMsdcVLocale);
	~PnlMsdcUsrAAccess();

public:
	ContInf continf;
	StatShr statshr;
	StgIac stgiac;

	Feed feedFCsiQst;

	QryMsdcUsrAAccess* qry;

	MsdcAMUserAccess recUsrAacc;

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
	void handleDpchAppDataStgiacqry(DbsMsdc* dbsmsdc, QryMsdcUsrAAccess::StgIac* _stgiacqry, DpchEngMsdc** dpcheng);

	void handleDpchAppDoButNewClick(DbsMsdc* dbsmsdc, DpchEngMsdc** dpcheng);
	void handleDpchAppDoButDuplicateClick(DbsMsdc* dbsmsdc, DpchEngMsdc** dpcheng);
	void handleDpchAppDoButDeleteClick(DbsMsdc* dbsmsdc, DpchEngMsdc** dpcheng);
	void handleDpchAppDoButRefreshClick(DbsMsdc* dbsmsdc, DpchEngMsdc** dpcheng);

	void handleCall(DbsMsdc* dbsmsdc, Call* call);

	bool handleCallMsdcStatChg(DbsMsdc* dbsmsdc, const ubigint jrefTrig);
};

#endif

