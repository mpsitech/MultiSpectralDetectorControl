/**
  * \file QryMsdcPrd1NData.h
  * job handler for job QryMsdcPrd1NData (declarations)
  * \author Alexander Wirthmueller
  * \date created: 12 Sep 2018
  * \date modified: 12 Sep 2018
  */

#ifndef QRYMSDCPRD1NDATA_H
#define QRYMSDCPRD1NDATA_H

// IP custInclude --- INSERT

#define StatAppQryMsdcPrd1NData QryMsdcPrd1NData::StatApp
#define StatShrQryMsdcPrd1NData QryMsdcPrd1NData::StatShr
#define StgIacQryMsdcPrd1NData QryMsdcPrd1NData::StgIac

/**
  * QryMsdcPrd1NData
  */
class QryMsdcPrd1NData : public JobMsdc {

public:
	/**
		* StatApp (full: StatAppQryMsdcPrd1NData)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const uint firstcol = 1, const uint jnumFirstdisp = 1, const uint ncol = 1, const uint ndisp = 10);
	};

	/**
		* StatShr (full: StatShrQryMsdcPrd1NData)
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
		* StgIac (full: StgIacQryMsdcPrd1NData)
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
	QryMsdcPrd1NData(XchgMsdc* xchg, DbsMsdc* dbsmsdc, const ubigint jrefSup, const uint ixMsdcVLocale);
	~QryMsdcPrd1NData();

public:
	StatShr statshr;
	StgIac stgiac;

	ListMsdcQPrd1NData rst;

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
	MsdcQPrd1NData* getRecByJnum(const uint jnum);

public:

	void handleRequest(DbsMsdc* dbsmsdc, ReqMsdc* req);

	bool handleRerun(DbsMsdc* dbsmsdc);
	bool handleShow(DbsMsdc* dbsmsdc);

	void handleCall(DbsMsdc* dbsmsdc, Call* call);

	bool handleCallMsdcStubChg(DbsMsdc* dbsmsdc, const ubigint jrefTrig);
	bool handleCallMsdcDatMod_prdEq(DbsMsdc* dbsmsdc, const ubigint jrefTrig, const ubigint refInv);
};

#endif

