/**
  * \file QryMsdcPrdList.h
  * job handler for job QryMsdcPrdList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 29 Aug 2018
  * \date modified: 29 Aug 2018
  */

#ifndef QRYMSDCPRDLIST_H
#define QRYMSDCPRDLIST_H

// IP custInclude --- INSERT

#define VecVQryMsdcPrdListOrd QryMsdcPrdList::VecVOrd

#define StatAppQryMsdcPrdList QryMsdcPrdList::StatApp
#define StatShrQryMsdcPrdList QryMsdcPrdList::StatShr
#define StgIacQryMsdcPrdList QryMsdcPrdList::StgIac

/**
  * QryMsdcPrdList
  */
class QryMsdcPrdList : public JobMsdc {

public:
	/**
		* VecVOrd (full: VecVQryMsdcPrdListOrd)
		*/
	class VecVOrd {

	public:
		static const uint STA = 1;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);

		static void fillFeed(Feed& feed);
	};

	/**
		* StatApp (full: StatAppQryMsdcPrdList)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const uint firstcol = 1, const uint jnumFirstdisp = 1, const uint ncol = 2, const uint ndisp = 25);
	};

	/**
		* StatShr (full: StatShrQryMsdcPrdList)
		*/
	class StatShr : public Block {

	public:
		static const uint NTOT = 1;
		static const uint JNUMFIRSTLOAD = 2;
		static const uint NLOAD = 3;

	public:
		StatShr(const uint ntot = 0, const uint jnumFirstload = 0, const uint nload = 0);

	public:
		uint ntot;
		uint jnumFirstload;
		uint nload;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* StgIac (full: StgIacQryMsdcPrdList)
		*/
	class StgIac : public Block {

	public:
		static const uint JNUM = 1;
		static const uint JNUMFIRSTLOAD = 2;
		static const uint NLOAD = 3;

	public:
		StgIac(const uint jnum = 0, const uint jnumFirstload = 1, const uint nload = 100);

	public:
		uint jnum;
		uint jnumFirstload;
		uint nload;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StgIac* comp);
		set<uint> diff(const StgIac* comp);
	};

public:
	QryMsdcPrdList(XchgMsdc* xchg, DbsMsdc* dbsmsdc, const ubigint jrefSup, const uint ixMsdcVLocale);
	~QryMsdcPrdList();

public:
	StatShr statshr;
	StgIac stgiac;

	ListMsdcQPrdList rst;

	uint ixMsdcVQrystate;

	// IP custVar --- INSERT

public:
	// IP cust --- INSERT

public:
	void refreshJnum();

	void rerun(DbsMsdc* dbsmsdc, const bool call = false);
	void rerun_filtSQL(string& sqlstr, const int preSta, const bool addwhere);
	void rerun_filtSQL_append(string& sqlstr, bool& first);

	void fetch(DbsMsdc* dbsmsdc);

	uint getJnumByRef(const ubigint ref);
	ubigint getRefByJnum(const uint jnum);
	MsdcQPrdList* getRecByJnum(const uint jnum);

public:

	void handleRequest(DbsMsdc* dbsmsdc, ReqMsdc* req);

	bool handleRerun(DbsMsdc* dbsmsdc);
	bool handleShow(DbsMsdc* dbsmsdc);

	void handleCall(DbsMsdc* dbsmsdc, Call* call);

	bool handleCallMsdcStubChg(DbsMsdc* dbsmsdc, const ubigint jrefTrig);
	bool handleCallMsdcPrdMod(DbsMsdc* dbsmsdc, const ubigint jrefTrig);
	bool handleCallMsdcPrdUpd_refEq(DbsMsdc* dbsmsdc, const ubigint jrefTrig, const ubigint refInv);
};

#endif

