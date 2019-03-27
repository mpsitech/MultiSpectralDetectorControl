/**
  * \file PnlMsdcDatHeadbar.h
  * job handler for job PnlMsdcDatHeadbar (declarations)
  * \author Alexander Wirthmueller
  * \date created: 18 Dec 2018
  * \date modified: 18 Dec 2018
  */

#ifndef PNLMSDCDATHEADBAR_H
#define PNLMSDCDATHEADBAR_H

// IP custInclude --- INSERT

#define StgInfMsdcDatHeadbar PnlMsdcDatHeadbar::StgInf
#define TagMsdcDatHeadbar PnlMsdcDatHeadbar::Tag

#define DpchEngMsdcDatHeadbarData PnlMsdcDatHeadbar::DpchEngData

/**
  * PnlMsdcDatHeadbar
  */
class PnlMsdcDatHeadbar : public JobMsdc {

public:
	/**
		* StgInf (full: StgInfMsdcDatHeadbar)
		*/
	class StgInf {

	public:
		static void writeXML(const uint ixMsdcVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* Tag (full: TagMsdcDatHeadbar)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixMsdcVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchEngData (full: DpchEngMsdcDatHeadbarData)
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
	PnlMsdcDatHeadbar(XchgMsdc* xchg, DbsMsdc* dbsmsdc, const ubigint jrefSup, const uint ixMsdcVLocale);
	~PnlMsdcDatHeadbar();

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

