/**
  * \file PnlMsdcScfHeadbar.h
  * job handler for job PnlMsdcScfHeadbar (declarations)
  * \author Alexander Wirthmueller
  * \date created: 18 Dec 2018
  * \date modified: 18 Dec 2018
  */

#ifndef PNLMSDCSCFHEADBAR_H
#define PNLMSDCSCFHEADBAR_H

// IP custInclude --- INSERT

#define StgInfMsdcScfHeadbar PnlMsdcScfHeadbar::StgInf
#define TagMsdcScfHeadbar PnlMsdcScfHeadbar::Tag

#define DpchEngMsdcScfHeadbarData PnlMsdcScfHeadbar::DpchEngData

/**
  * PnlMsdcScfHeadbar
  */
class PnlMsdcScfHeadbar : public JobMsdc {

public:
	/**
		* StgInf (full: StgInfMsdcScfHeadbar)
		*/
	class StgInf {

	public:
		static void writeXML(const uint ixMsdcVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* Tag (full: TagMsdcScfHeadbar)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixMsdcVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchEngData (full: DpchEngMsdcScfHeadbarData)
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
	PnlMsdcScfHeadbar(XchgMsdc* xchg, DbsMsdc* dbsmsdc, const ubigint jrefSup, const uint ixMsdcVLocale);
	~PnlMsdcScfHeadbar();

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

