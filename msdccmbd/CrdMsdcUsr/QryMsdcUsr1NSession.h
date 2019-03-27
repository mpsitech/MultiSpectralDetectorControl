/**
  * \file QryMsdcUsr1NSession.h
  * job handler for job QryMsdcUsr1NSession (declarations)
  * \author Alexander Wirthmueller
  * \date created: 18 Dec 2018
  * \date modified: 18 Dec 2018
  */

#ifndef QRYMSDCUSR1NSESSION_H
#define QRYMSDCUSR1NSESSION_H

// IP custInclude --- INSERT

#define StatAppQryMsdcUsr1NSession QryMsdcUsr1NSession::StatApp
#define StatShrQryMsdcUsr1NSession QryMsdcUsr1NSession::StatShr
#define StgIacQryMsdcUsr1NSession QryMsdcUsr1NSession::StgIac

/**
  * QryMsdcUsr1NSession
  */
class QryMsdcUsr1NSession : public JobMsdc {

public:
	/**
		* StatApp (full: StatAppQryMsdcUsr1NSession)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const uint firstcol = 1, const uint jnumFirstdisp = 1, const uint ncol = 1, const uint ndisp = 10);
	};

	/**
		* StatShr (full: StatShrQryMsdcUsr1NSession)
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
		* StgIac (full: StgIacQryMsdcUsr1NSession)
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
	QryMsdcUsr1NSession(XchgMsdc* xchg, DbsMsdc* dbsmsdc, const ubigint jrefSup, const uint ixMsdcVLocale);
	~QryMsdcUsr1NSession();

public:
	StatShr statshr;
	StgIac stgiac;

	ListMsdcQUsr1NSession rst;

	uint ixMsdcVQrystate;

	// IP custVar --- INSERT

public:
	// IP cust --- INSERT

public:
	void refreshJnum();

	void rerun(DbsMsdc* dbsmsdc, const bool call = false);

	void fetch(DbsMsdc* dbsmsdc);

	uint getJnumByRef(const ubigint ref);
	ubigint getRefByJnum(const uint jnum);
	MsdcQUsr1NSession* getRecByJnum(const uint jnum);

public:

	void handleRequest(DbsMsdc* dbsmsdc, ReqMsdc* req);

	bool handleRerun(DbsMsdc* dbsmsdc);
	bool handleShow(DbsMsdc* dbsmsdc);

	void handleCall(DbsMsdc* dbsmsdc, Call* call);

	bool handleCallMsdcStubChg(DbsMsdc* dbsmsdc, const ubigint jrefTrig);
	bool handleCallMsdcSesMod_usrEq(DbsMsdc* dbsmsdc, const ubigint jrefTrig, const ubigint refInv);
};

#endif

