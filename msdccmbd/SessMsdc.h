/**
  * \file SessMsdc.h
  * job handler for job SessMsdc (declarations)
  * \author Alexander Wirthmueller
  * \date created: 15 Aug 2018
  * \date modified: 15 Aug 2018
  */

#ifndef SESSMSDC_H
#define SESSMSDC_H

// IP custInclude --- INSERT

#include "CrdMsdcNav.h"
#include "CrdMsdcUsg.h"
#include "CrdMsdcUsr.h"
#include "CrdMsdcPrs.h"
#include "CrdMsdcScf.h"
#include "CrdMsdcLiv.h"
#include "CrdMsdcPrd.h"
#include "CrdMsdcDat.h"
#include "CrdMsdcFil.h"

#define StatShrSessMsdc SessMsdc::StatShr

#define DpchEngSessMsdcData SessMsdc::DpchEngData

/**
  * SessMsdc
  */
class SessMsdc : public JobMsdc {

public:
	/**
		* StatShr (full: StatShrSessMsdc)
		*/
	class StatShr : public Block {

	public:
		static const uint JREFCRDNAV = 1;

	public:
		StatShr(const ubigint jrefCrdnav = 0);

	public:
		ubigint jrefCrdnav;

	public:
		void writeXML(pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* DpchEngData (full: DpchEngSessMsdcData)
		*/
	class DpchEngData : public DpchEngMsdc {

	public:
		static const uint JREF = 1;
		static const uint FEEDFENSSEC = 2;
		static const uint STATSHR = 3;
		static const uint ALL = 4;

	public:
		DpchEngData(const ubigint jref = 0, Feed* feedFEnsSec = NULL, StatShr* statshr = NULL, const set<uint>& mask = {NONE});

	public:
		Feed feedFEnsSec;
		StatShr statshr;

	public:
		string getSrefsMask();
		void merge(DpchEngMsdc* dpcheng);

		void writeXML(const uint ixMsdcVLocale, pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
	};

public:
	SessMsdc(XchgMsdc* xchg, DbsMsdc* dbsmsdc, const ubigint jrefSup, const ubigint refMsdcMUser, const string& ip);
	~SessMsdc();

public:
	StatShr statshr;

	CrdMsdcNav* crdnav;
	list<CrdMsdcUsg*> crdusgs;
	list<CrdMsdcUsr*> crdusrs;
	list<CrdMsdcPrs*> crdprss;
	list<CrdMsdcScf*> crdscfs;
	list<CrdMsdcLiv*> crdlivs;
	list<CrdMsdcPrd*> crdprds;
	list<CrdMsdcDat*> crddats;
	list<CrdMsdcFil*> crdfils;

	map<ubigint,uint> usgaccs;

	map<ubigint,string> scr;
	map<string,ubigint> descr;

	// IP custVar --- INSERT

public:
	// IP cust --- INSERT

public:
	void term(DbsMsdc* dbsmsdc);

	uint checkCrdActive(const uint ixMsdcVCard);
	uint evalCrddatActive();
	uint evalCrdfilActive();

	uint checkCrdaccess(const uint ixMsdcVCard);
	void getIxCrdacc(DbsMsdc* dbsmsdc, const uint ixMsdcVCard, const bool adm, ListMsdcRMUserMUsergroup& urus, const ubigint refMsdcMUser, uint& ixMsdcWAccess);

	uint checkRecaccess(DbsMsdc* dbsmsdc, const uint ixMsdcVCard, const ubigint ref);
	void logRecaccess(DbsMsdc* dbsmsdc, const uint ixMsdcVPreset, const ubigint preUref, const uint ixMsdcVCard, const ubigint unvUref);

	uint crdToMtb(const uint ixMsdcVCard);
	uint preToMtb(const uint ixMsdcVPreset);
	bool hasActive(const uint ixMsdcVCard);
	bool hasGrpown(const uint ixMsdcVMaintable);

public:

	void handleRequest(DbsMsdc* dbsmsdc, ReqMsdc* req);

	bool handleCreateCrddat(DbsMsdc* dbsmsdc);
	bool handleCreateCrdfil(DbsMsdc* dbsmsdc);
	bool handleCreateCrdliv(DbsMsdc* dbsmsdc);
	bool handleCreateCrdprd(DbsMsdc* dbsmsdc);
	bool handleCreateCrdprs(DbsMsdc* dbsmsdc);
	bool handleCreateCrdscf(DbsMsdc* dbsmsdc);
	bool handleCreateCrdusg(DbsMsdc* dbsmsdc);
	bool handleCreateCrdusr(DbsMsdc* dbsmsdc);
	bool handleEraseCrddat(DbsMsdc* dbsmsdc);
	bool handleEraseCrdfil(DbsMsdc* dbsmsdc);
	bool handleEraseCrdliv(DbsMsdc* dbsmsdc);
	bool handleEraseCrdprd(DbsMsdc* dbsmsdc);
	bool handleEraseCrdprs(DbsMsdc* dbsmsdc);
	bool handleEraseCrdscf(DbsMsdc* dbsmsdc);
	bool handleEraseCrdusg(DbsMsdc* dbsmsdc);
	bool handleEraseCrdusr(DbsMsdc* dbsmsdc);

	void handleDpchAppMsdcInit(DbsMsdc* dbsmsdc, DpchAppMsdcInit* dpchappmsdcinit, DpchEngMsdc** dpcheng);

	void handleCall(DbsMsdc* dbsmsdc, Call* call);

	bool handleCallMsdcCrdActive(DbsMsdc* dbsmsdc, const ubigint jrefTrig, const uint ixInv, uint& ixRet);
	bool handleCallMsdcCrdClose(DbsMsdc* dbsmsdc, const ubigint jrefTrig, const uint ixInv);
	bool handleCallMsdcCrdOpen(DbsMsdc* dbsmsdc, const ubigint jrefTrig, const uint ixInv, const ubigint refInv, const string& srefInv, const int intvalInv, ubigint& refRet);
	bool handleCallMsdcLog(DbsMsdc* dbsmsdc, const ubigint jrefTrig, const uint ixInv, const ubigint refInv, const string& srefInv, const int intvalInv);
	bool handleCallMsdcRecaccess(DbsMsdc* dbsmsdc, const ubigint jrefTrig, const uint ixInv, const ubigint refInv, uint& ixRet);
	bool handleCallMsdcRefPreSet(DbsMsdc* dbsmsdc, const ubigint jrefTrig, const uint ixInv, const ubigint refInv);
};

#endif

