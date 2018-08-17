/**
  * \file PnlMsdcUsgList.h
  * job handler for job PnlMsdcUsgList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 15 Aug 2018
  * \date modified: 15 Aug 2018
  */

#ifndef PNLMSDCUSGLIST_H
#define PNLMSDCUSGLIST_H

// IP custInclude --- INSERT

#include "QryMsdcUsgList.h"

#define VecVMsdcUsgListDo PnlMsdcUsgList::VecVDo

#define ContIacMsdcUsgList PnlMsdcUsgList::ContIac
#define ContInfMsdcUsgList PnlMsdcUsgList::ContInf
#define StatShrMsdcUsgList PnlMsdcUsgList::StatShr
#define StgIacMsdcUsgList PnlMsdcUsgList::StgIac
#define TagMsdcUsgList PnlMsdcUsgList::Tag

#define DpchAppMsdcUsgListData PnlMsdcUsgList::DpchAppData
#define DpchAppMsdcUsgListDo PnlMsdcUsgList::DpchAppDo
#define DpchEngMsdcUsgListData PnlMsdcUsgList::DpchEngData

/**
  * PnlMsdcUsgList
  */
class PnlMsdcUsgList : public JobMsdc {

public:
	/**
		* VecVDo (full: VecVMsdcUsgListDo)
		*/
	class VecVDo {

	public:
		static const uint BUTMINIMIZECLICK = 1;
		static const uint BUTREGULARIZECLICK = 2;
		static const uint BUTNEWCLICK = 3;
		static const uint BUTDELETECLICK = 4;
		static const uint BUTFILTERCLICK = 5;
		static const uint BUTREFRESHCLICK = 6;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacMsdcUsgList)
	  */
	class ContIac : public Block {

	public:
		static const uint NUMFTOS = 1;

	public:
		ContIac(const uint numFTos = 1);

	public:
		uint numFTos;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfMsdcUsgList)
	  */
	class ContInf : public Block {

	public:
		static const uint BUTFILTERON = 1;
		static const uint NUMFCSIQST = 2;

	public:
		ContInf(const bool ButFilterOn = false, const uint numFCsiQst = 1);

	public:
		bool ButFilterOn;
		uint numFCsiQst;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
		* StatShr (full: StatShrMsdcUsgList)
		*/
	class StatShr : public Block {

	public:
		static const uint IXMSDCVEXPSTATE = 1;
		static const uint BUTDELETEACTIVE = 2;

	public:
		StatShr(const uint ixMsdcVExpstate = VecMsdcVExpstate::MIND, const bool ButDeleteActive = true);

	public:
		uint ixMsdcVExpstate;
		bool ButDeleteActive;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* StgIac (full: StgIacMsdcUsgList)
		*/
	class StgIac : public Block {

	public:
		static const uint TCOSRFWIDTH = 1;

	public:
		StgIac(const uint TcoSrfWidth = 100);

	public:
		uint TcoSrfWidth;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StgIac* comp);
		set<uint> diff(const StgIac* comp);
	};

	/**
		* Tag (full: TagMsdcUsgList)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixMsdcVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppMsdcUsgListData)
		*/
	class DpchAppData : public DpchAppMsdc {

	public:
		static const uint JREF = 1;
		static const uint CONTIAC = 2;
		static const uint STGIAC = 3;
		static const uint STGIACQRY = 4;

	public:
		DpchAppData();

	public:
		ContIac contiac;
		StgIac stgiac;
		QryMsdcUsgList::StgIac stgiacqry;

	public:
		string getSrefsMask();

		void readXML(pthread_mutex_t* mScr, map<string,ubigint>& descr, xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppMsdcUsgListDo)
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
		* DpchEngData (full: DpchEngMsdcUsgListData)
		*/
	class DpchEngData : public DpchEngMsdc {

	public:
		static const uint JREF = 1;
		static const uint CONTIAC = 2;
		static const uint CONTINF = 3;
		static const uint FEEDFCSIQST = 4;
		static const uint FEEDFTOS = 5;
		static const uint STATSHR = 6;
		static const uint STGIAC = 7;
		static const uint TAG = 8;
		static const uint RST = 9;
		static const uint STATAPPQRY = 10;
		static const uint STATSHRQRY = 11;
		static const uint STGIACQRY = 12;
		static const uint ALL = 13;

	public:
		DpchEngData(const ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, Feed* feedFCsiQst = NULL, Feed* feedFTos = NULL, StatShr* statshr = NULL, StgIac* stgiac = NULL, ListMsdcQUsgList* rst = NULL, QryMsdcUsgList::StatShr* statshrqry = NULL, QryMsdcUsgList::StgIac* stgiacqry = NULL, const set<uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		Feed feedFCsiQst;
		Feed feedFTos;
		StatShr statshr;
		StgIac stgiac;
		ListMsdcQUsgList rst;
		QryMsdcUsgList::StatShr statshrqry;
		QryMsdcUsgList::StgIac stgiacqry;

	public:
		string getSrefsMask();
		void merge(DpchEngMsdc* dpcheng);

		void writeXML(const uint ixMsdcVLocale, pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
	};

	bool evalButDeleteActive(DbsMsdc* dbsmsdc);

public:
	PnlMsdcUsgList(XchgMsdc* xchg, DbsMsdc* dbsmsdc, const ubigint jrefSup, const uint ixMsdcVLocale);
	~PnlMsdcUsgList();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;
	StgIac stgiac;

	Feed feedFCsiQst;
	Feed feedFTos;

	QryMsdcUsgList* qry;

	// IP custVar --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngMsdc* getNewDpchEng(set<uint> items);

	void refresh(DbsMsdc* dbsmsdc, set<uint>& moditems);

	void updatePreset(DbsMsdc* dbsmsdc, const uint ixMsdcVPreset, const ubigint jrefTrig, const bool notif = false);
	void minimize(DbsMsdc* dbsmsdc, const bool notif = false, DpchEngMsdc** dpcheng = NULL);
	void regularize(DbsMsdc* dbsmsdc, const bool notif = false, DpchEngMsdc** dpcheng = NULL);

public:

	void handleRequest(DbsMsdc* dbsmsdc, ReqMsdc* req);

	void handleDpchAppMsdcInit(DbsMsdc* dbsmsdc, DpchAppMsdcInit* dpchappmsdcinit, DpchEngMsdc** dpcheng);
	void handleDpchAppDataContiac(DbsMsdc* dbsmsdc, ContIac* _contiac, DpchEngMsdc** dpcheng);
	void handleDpchAppDataStgiac(DbsMsdc* dbsmsdc, StgIac* _stgiac, DpchEngMsdc** dpcheng);
	void handleDpchAppDataStgiacqry(DbsMsdc* dbsmsdc, QryMsdcUsgList::StgIac* _stgiacqry, DpchEngMsdc** dpcheng);

	void handleDpchAppDoButMinimizeClick(DbsMsdc* dbsmsdc, DpchEngMsdc** dpcheng);
	void handleDpchAppDoButRegularizeClick(DbsMsdc* dbsmsdc, DpchEngMsdc** dpcheng);
	void handleDpchAppDoButNewClick(DbsMsdc* dbsmsdc, DpchEngMsdc** dpcheng);
	void handleDpchAppDoButDeleteClick(DbsMsdc* dbsmsdc, DpchEngMsdc** dpcheng);
	void handleDpchAppDoButFilterClick(DbsMsdc* dbsmsdc, DpchEngMsdc** dpcheng);
	void handleDpchAppDoButRefreshClick(DbsMsdc* dbsmsdc, DpchEngMsdc** dpcheng);

	void handleCall(DbsMsdc* dbsmsdc, Call* call);

	bool handleCallMsdcStatChg(DbsMsdc* dbsmsdc, const ubigint jrefTrig);
};

#endif

