/**
  * \file M2msessMsdc.h
  * job handler for job M2msessMsdc (declarations)
  * \author Alexander Wirthmueller
  * \date created: 18 Dec 2018
  * \date modified: 18 Dec 2018
  */

#ifndef M2MSESSMSDC_H
#define M2MSESSMSDC_H

// IP custInclude --- INSERT

#include "JobMsdcAcqAdxl.h"
#include "JobMsdcAcqLwir.h"
#include "JobMsdcAcqVisl.h"
#include "JobMsdcAcqVisr.h"
#include "JobMsdcActAlign.h"
#include "JobMsdcActLed.h"
#include "JobMsdcActServo.h"
#include "JobMsdcPrcStereo.h"

#define StatShrM2msessMsdc M2msessMsdc::StatShr

#define DpchEngM2msessMsdcData M2msessMsdc::DpchEngData

/**
  * M2msessMsdc
  */
class M2msessMsdc : public JobMsdc {

public:
	/**
		* StatShr (full: StatShrM2msessMsdc)
		*/
	class StatShr : public Block {

	public:
		static const uint JREFACQADXL = 1;
		static const uint JREFACQLWIR = 2;
		static const uint JREFACQVISL = 3;
		static const uint JREFACQVISR = 4;
		static const uint JREFACTALIGN = 5;
		static const uint JREFACTLED = 6;
		static const uint JREFACTSERVO = 7;
		static const uint JREFPRCSTEREO = 8;

	public:
		StatShr(const ubigint jrefAcqadxl = 0, const ubigint jrefAcqlwir = 0, const ubigint jrefAcqvisl = 0, const ubigint jrefAcqvisr = 0, const ubigint jrefActalign = 0, const ubigint jrefActled = 0, const ubigint jrefActservo = 0, const ubigint jrefPrcstereo = 0);

	public:
		ubigint jrefAcqadxl;
		ubigint jrefAcqlwir;
		ubigint jrefAcqvisl;
		ubigint jrefAcqvisr;
		ubigint jrefActalign;
		ubigint jrefActled;
		ubigint jrefActservo;
		ubigint jrefPrcstereo;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* DpchEngData (full: DpchEngM2msessMsdcData)
		*/
	class DpchEngData : public DpchEngMsdc {

	public:
		static const uint JREF = 1;
		static const uint STATSHR = 2;
		static const uint ALL = 3;

	public:
		DpchEngData(const ubigint jref = 0, StatShr* statshr = NULL, const set<uint>& mask = {NONE});

	public:
		StatShr statshr;

	public:
		string getSrefsMask();
		void merge(DpchEngMsdc* dpcheng);

		void writeXML(const uint ixMsdcVLocale, xmlTextWriter* wr);
	};

public:
	M2msessMsdc(XchgMsdc* xchg, DbsMsdc* dbsmsdc, const ubigint jrefSup, const ubigint refMsdcMUser, const string& ip);
	~M2msessMsdc();

public:
	StatShr statshr;

	JobMsdcAcqAdxl* acqadxl;
	JobMsdcAcqLwir* acqlwir;
	JobMsdcAcqVisl* acqvisl;
	JobMsdcAcqVisr* acqvisr;
	JobMsdcActAlign* actalign;
	JobMsdcActLed* actled;
	JobMsdcActServo* actservo;
	JobMsdcPrcStereo* prcstereo;

	multimap<featix_t,uint> accs;

	// IP custVar --- INSERT

public:
	// IP cust --- INSERT

public:
	void term(DbsMsdc* dbsmsdc);

	uint addAccBase(DbsMsdc* dbsmsdc, const uint ixMsdcVFeatgroup, const bool adm, ListMsdcRMUserMUsergroup& urus, const ubigint refMsdcMUser);
	void addAcc(DbsMsdc* dbsmsdc, const uint ixMsdcVFeatgroup, const string& srefIxVFeature, ListMsdcRMUserMUsergroup& urus, const ubigint refMsdcMUser, const uint ixMsdcWAccessBase);

	void getIxAcc(DbsMsdc* dbsmsdc, const uint ixMsdcVFeatgroup, const string& srefIxVFeature, const bool adm, ListMsdcRMUserMUsergroup& urus, const ubigint refMsdcMUser, uint& ixMsdcWAccess);

public:

	void handleRequest(DbsMsdc* dbsmsdc, ReqMsdc* req);

	void handleDpchAppMsdcInit(DbsMsdc* dbsmsdc, DpchAppMsdcInit* dpchappmsdcinit, DpchEngMsdc** dpcheng);

	void handleCall(DbsMsdc* dbsmsdc, Call* call);

	bool handleCallMsdcAccess(DbsMsdc* dbsmsdc, const ubigint jrefTrig, const uint ixInv, const string& srefInv, uint& ixRet);
};

#endif

