/**
  * \file PnlMsdcLivHeadbar.h
  * job handler for job PnlMsdcLivHeadbar (declarations)
  * \author Alexander Wirthmueller
  * \date created: 12 Sep 2018
  * \date modified: 12 Sep 2018
  */

#ifndef PNLMSDCLIVHEADBAR_H
#define PNLMSDCLIVHEADBAR_H

// IP custInclude --- INSERT

#define StgInfMsdcLivHeadbar PnlMsdcLivHeadbar::StgInf
#define TagMsdcLivHeadbar PnlMsdcLivHeadbar::Tag

#define DpchEngMsdcLivHeadbarData PnlMsdcLivHeadbar::DpchEngData

/**
  * PnlMsdcLivHeadbar
  */
class PnlMsdcLivHeadbar : public JobMsdc {

public:
	/**
		* StgInf (full: StgInfMsdcLivHeadbar)
		*/
	class StgInf {

	public:
		static void writeXML(const uint ixMsdcVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* Tag (full: TagMsdcLivHeadbar)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixMsdcVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchEngData (full: DpchEngMsdcLivHeadbarData)
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

		void writeXML(const uint ixMsdcVLocale, xmlTextWriter* wr);
	};

public:
	PnlMsdcLivHeadbar(XchgMsdc* xchg, DbsMsdc* dbsmsdc, const ubigint jrefSup, const uint ixMsdcVLocale);
	~PnlMsdcLivHeadbar();

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

