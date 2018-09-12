/**
  * \file PnlMsdcScfPrcctl.h
  * job handler for job PnlMsdcScfPrcctl (declarations)
  * \author Alexander Wirthmueller
  * \date created: 12 Sep 2018
  * \date modified: 12 Sep 2018
  */

#ifndef PNLMSDCSCFPRCCTL_H
#define PNLMSDCSCFPRCCTL_H

// IP custInclude --- INSERT

#include "JobMsdcPrcStereo.h"
#include "JobMsdcPrcSpotfind.h"
#include "JobMsdcPrcTrack.h"

#define VecVMsdcScfPrcctlDo PnlMsdcScfPrcctl::VecVDo

#define ContInfMsdcScfPrcctl PnlMsdcScfPrcctl::ContInf
#define StatAppMsdcScfPrcctl PnlMsdcScfPrcctl::StatApp
#define TagMsdcScfPrcctl PnlMsdcScfPrcctl::Tag

#define DpchAppMsdcScfPrcctlDo PnlMsdcScfPrcctl::DpchAppDo
#define DpchEngMsdcScfPrcctlData PnlMsdcScfPrcctl::DpchEngData

/**
  * PnlMsdcScfPrcctl
  */
class PnlMsdcScfPrcctl : public JobMsdc {

public:
	/**
		* VecVDo (full: VecVMsdcScfPrcctlDo)
		*/
	class VecVDo {

	public:
		static const uint BUTMASTERCLICK = 1;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContInf (full: ContInfMsdcScfPrcctl)
	  */
	class ContInf : public Block {

	public:
		static const uint BUTMASTERON = 1;

	public:
		ContInf(const bool ButMasterOn = false);

	public:
		bool ButMasterOn;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppMsdcScfPrcctl)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const uint ixMsdcVExpstate = VecMsdcVExpstate::MIND);
	};

	/**
		* Tag (full: TagMsdcScfPrcctl)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixMsdcVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppDo (full: DpchAppMsdcScfPrcctlDo)
		*/
	class DpchAppDo : public DpchAppMsdc {

	public:
		static const uint JREF = 1;
		static const uint IXVDO = 2;

	public:
		DpchAppDo();

	public:
		uint ixVDo;

	public:
		string getSrefsMask();

		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngData (full: DpchEngMsdcScfPrcctlData)
		*/
	class DpchEngData : public DpchEngMsdc {

	public:
		static const uint JREF = 1;
		static const uint CONTINF = 2;
		static const uint STATAPP = 3;
		static const uint TAG = 4;
		static const uint ALL = 5;

	public:
		DpchEngData(const ubigint jref = 0, ContInf* continf = NULL, const set<uint>& mask = {NONE});

	public:
		ContInf continf;

	public:
		string getSrefsMask();
		void merge(DpchEngMsdc* dpcheng);

		void writeXML(const uint ixMsdcVLocale, xmlTextWriter* wr);
	};

public:
	PnlMsdcScfPrcctl(XchgMsdc* xchg, DbsMsdc* dbsmsdc, const ubigint jrefSup, const uint ixMsdcVLocale);
	~PnlMsdcScfPrcctl();

public:
	ContInf continf;

	JobMsdcPrcStereo* prcstereo;
	JobMsdcPrcSpotfind* prcspotfind;
	JobMsdcPrcTrack* prctrack;

	// IP custVar --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngMsdc* getNewDpchEng(set<uint> items);

	void refresh(DbsMsdc* dbsmsdc, set<uint>& moditems);

public:

	void handleRequest(DbsMsdc* dbsmsdc, ReqMsdc* req);

	void handleDpchAppMsdcInit(DbsMsdc* dbsmsdc, DpchAppMsdcInit* dpchappmsdcinit, DpchEngMsdc** dpcheng);

	void handleDpchAppDoButMasterClick(DbsMsdc* dbsmsdc, DpchEngMsdc** dpcheng);

	void handleCall(DbsMsdc* dbsmsdc, Call* call);

	bool handleCallMsdcMastslvChg(DbsMsdc* dbsmsdc, const ubigint jrefTrig);
};

#endif

