/**
  * \file PnlMsdcUsrHeadbar.h
  * job handler for job PnlMsdcUsrHeadbar (declarations)
  * \author Alexander Wirthmueller
  * \date created: 15 Aug 2018
  * \date modified: 15 Aug 2018
  */

#ifndef PNLMSDCUSRHEADBAR_H
#define PNLMSDCUSRHEADBAR_H

// IP custInclude --- INSERT

#define StgInfMsdcUsrHeadbar PnlMsdcUsrHeadbar::StgInf
#define TagMsdcUsrHeadbar PnlMsdcUsrHeadbar::Tag

#define DpchEngMsdcUsrHeadbarData PnlMsdcUsrHeadbar::DpchEngData

/**
  * PnlMsdcUsrHeadbar
  */
class PnlMsdcUsrHeadbar : public JobMsdc {

public:
	/**
		* StgInf (full: StgInfMsdcUsrHeadbar)
		*/
	class StgInf {

	public:
		static void writeXML(const uint ixMsdcVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* Tag (full: TagMsdcUsrHeadbar)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixMsdcVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchEngData (full: DpchEngMsdcUsrHeadbarData)
		*/
	class DpchEngData : public DpchEngMsdc {

	public:
		static const uint JREF = 1;
		static const uint STGINF = 2;
		static const uint TAG = 3;
		static const uint ALL = 4;

	public:
		DpchEngData(const ubigint jref = 0, const set<uint>& mask = {NONE});

	public:

	public:
		string getSrefsMask();
		void merge(DpchEngMsdc* dpcheng);

		void writeXML(const uint ixMsdcVLocale, pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
	};

public:
	PnlMsdcUsrHeadbar(XchgMsdc* xchg, DbsMsdc* dbsmsdc, const ubigint jrefSup, const uint ixMsdcVLocale);
	~PnlMsdcUsrHeadbar();

public:

	// IP custVar --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngMsdc* getNewDpchEng(set<uint> items);

	void refresh(DbsMsdc* dbsmsdc, set<uint>& moditems);

public:

	void handleRequest(DbsMsdc* dbsmsdc, ReqMsdc* req);

	void handleDpchAppMsdcInit(DbsMsdc* dbsmsdc, DpchAppMsdcInit* dpchappmsdcinit, DpchEngMsdc** dpcheng);

};

#endif

