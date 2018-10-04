/**
  * \file RootMsdc.h
  * job handler for job RootMsdc (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Oct 2018
  * \date modified: 4 Oct 2018
  */

#ifndef ROOTMSDC_H
#define ROOTMSDC_H

// IP custInclude --- INSERT

#include "SessMsdc.h"
#include "M2msessMsdc.h"
#include "JobMsdcSrcMsdd.h"
#include "JobMsdcSrcTrigger.h"

#define DpchAppRootMsdcLogin RootMsdc::DpchAppLogin
#define DpchEngRootMsdcData RootMsdc::DpchEngData

/**
  * RootMsdc
  */
class RootMsdc : public JobMsdc {

public:
	/**
		* DpchAppLogin (full: DpchAppRootMsdcLogin)
		*/
	class DpchAppLogin : public DpchAppMsdc {

	public:
		static const uint JREF = 1;
		static const uint USERNAME = 2;
		static const uint PASSWORD = 3;
		static const uint M2MNOTREG = 4;
		static const uint CHKSUSPSESS = 5;

	public:
		DpchAppLogin();

	public:
		string username;
		string password;
		bool m2mNotReg;
		bool chksuspsess;

	public:
		string getSrefsMask();

		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngData (full: DpchEngRootMsdcData)
		*/
	class DpchEngData : public DpchEngMsdc {

	public:
		static const uint JREF = 1;
		static const uint FEEDFENSSPS = 2;
		static const uint ALL = 3;

	public:
		DpchEngData(const ubigint jref = 0, Feed* feedFEnsSps = NULL, const set<uint>& mask = {NONE});

	public:
		Feed feedFEnsSps;

	public:
		string getSrefsMask();
		void merge(DpchEngMsdc* dpcheng);

		void writeXML(const uint ixMsdcVLocale, xmlTextWriter* wr);
	};

public:
	RootMsdc(XchgMsdc* xchg, DbsMsdc* dbsmsdc, const bool _clearAll);
	~RootMsdc();

public:

	list<SessMsdc*> sesss;
	list<M2msessMsdc*> m2msesss;
	JobMsdcSrcMsdd* srcmsdd;
	JobMsdcSrcTrigger* srctrigger;

	// IP specVar --- INSERT

	// IP custVar --- INSERT

public:
	// IP cust --- INSERT

public:
	void clearAll(DbsMsdc* dbsmsdc);
	void clearQtb(DbsMsdc* dbsmsdc);

public:

	void handleRequest(DbsMsdc* dbsmsdc, ReqMsdc* req);

	bool handleClearAll(DbsMsdc* dbsmsdc);
	bool handleCreateSess(DbsMsdc* dbsmsdc);
	bool handleEraseSess(DbsMsdc* dbsmsdc);
	bool handleTest(DbsMsdc* dbsmsdc);

	void handleDpchAppLogin(DbsMsdc* dbsmsdc, DpchAppLogin* dpchapplogin, const string ip, DpchEngMsdc** dpcheng);

	void handleCall(DbsMsdc* dbsmsdc, Call* call);

	bool handleCallMsdcLogout(DbsMsdc* dbsmsdc, const ubigint jrefTrig, const bool boolvalInv);
	bool handleCallMsdcSuspsess(DbsMsdc* dbsmsdc, const ubigint jrefTrig);
};

#endif

