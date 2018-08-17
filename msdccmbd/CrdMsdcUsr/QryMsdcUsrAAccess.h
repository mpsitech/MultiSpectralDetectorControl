/**
  * \file QryMsdcUsrAAccess.h
  * job handler for job QryMsdcUsrAAccess (declarations)
  * \author Alexander Wirthmueller
  * \date created: 15 Aug 2018
  * \date modified: 15 Aug 2018
  */

#ifndef QRYMSDCUSRAACCESS_H
#define QRYMSDCUSRAACCESS_H

// IP custInclude --- INSERT

#define StatAppQryMsdcUsrAAccess QryMsdcUsrAAccess::StatApp
#define StatShrQryMsdcUsrAAccess QryMsdcUsrAAccess::StatShr
#define StgIacQryMsdcUsrAAccess QryMsdcUsrAAccess::StgIac

/**
  * QryMsdcUsrAAccess
  */
class QryMsdcUsrAAccess : public JobMsdc {

public:
	/**
		* StatApp (full: StatAppQryMsdcUsrAAccess)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const uint firstcol = 1, const uint jnumFirstdisp = 1, const uint ncol = 5, const uint ndisp = 10);
	};

	/**
		* StatShr (full: StatShrQryMsdcUsrAAccess)
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
		* StgIac (full: StgIacQryMsdcUsrAAccess)
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
	QryMsdcUsrAAccess(XchgMsdc* xchg, DbsMsdc* dbsmsdc, const ubigint jrefSup, const uint ixMsdcVLocale);
	~QryMsdcUsrAAccess();

public:
	StatShr statshr;
	StgIac stgiac;

	ListMsdcQUsrAAccess rst;

	uint ixMsdcVQrystate;

	// IP custVar --- INSERT

public:
	// IP cust --- INSERT

public:
	void refreshJnum();

	void rerun(DbsMsdc* dbsmsdc, const bool call = false);
	void rerun_filtSQL(string& sqlstr, const uint preX1, const string& preX2, const bool addwhere);
	void rerun_filtSQL_append(string& sqlstr, bool& first);

	void fetch(DbsMsdc* dbsmsdc);

	uint getJnumByRef(const ubigint ref);
	ubigint getRefByJnum(const uint jnum);
	MsdcQUsrAAccess* getRecByJnum(const uint jnum);

public:

	void handleRequest(DbsMsdc* dbsmsdc, ReqMsdc* req);

	bool handleRerun(DbsMsdc* dbsmsdc);
	bool handleShow(DbsMsdc* dbsmsdc);

	void handleCall(DbsMsdc* dbsmsdc, Call* call);

	bool handleCallMsdcStubChg(DbsMsdc* dbsmsdc, const ubigint jrefTrig);
	bool handleCallMsdcUsrAaccMod_usrEq(DbsMsdc* dbsmsdc, const ubigint jrefTrig, const ubigint refInv);
};

#endif

