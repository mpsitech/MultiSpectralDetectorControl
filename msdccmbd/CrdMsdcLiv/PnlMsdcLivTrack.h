/**
  * \file PnlMsdcLivTrack.h
  * job handler for job PnlMsdcLivTrack (declarations)
  * \author Alexander Wirthmueller
  * \date created: 18 Dec 2018
  * \date modified: 18 Dec 2018
  */

#ifndef PNLMSDCLIVTRACK_H
#define PNLMSDCLIVTRACK_H

// IP custInclude --- INSERT

#include "JobMsdcPrcTrack.h"

#define VecVMsdcLivTrackDo PnlMsdcLivTrack::VecVDo

#define ContIacMsdcLivTrack PnlMsdcLivTrack::ContIac
#define ContInfMsdcLivTrack PnlMsdcLivTrack::ContInf
#define StatShrMsdcLivTrack PnlMsdcLivTrack::StatShr
#define TagMsdcLivTrack PnlMsdcLivTrack::Tag

#define DpchAppMsdcLivTrackData PnlMsdcLivTrack::DpchAppData
#define DpchAppMsdcLivTrackDo PnlMsdcLivTrack::DpchAppDo
#define DpchEngMsdcLivTrackData PnlMsdcLivTrack::DpchEngData

/**
  * PnlMsdcLivTrack
  */
class PnlMsdcLivTrack : public JobMsdc {

public:
	/**
		* VecVDo (full: VecVMsdcLivTrackDo)
		*/
	class VecVDo {

	public:
		static const uint BUTREGULARIZECLICK = 1;
		static const uint BUTMINIMIZECLICK = 2;
		static const uint BUTMASTERCLICK = 3;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacMsdcLivTrack)
	  */
	class ContIac : public Block {

	public:
		static const uint NUMFPUPAMF = 1;
		static const uint UPDAPR = 2;
		static const uint CHKVID = 3;
		static const uint CHKWID = 4;

	public:
		ContIac(const uint numFPupAmf = 1, const int UpdApr = 0, const bool ChkVid = false, const bool ChkWid = false);

	public:
		uint numFPupAmf;
		int UpdApr;
		bool ChkVid;
		bool ChkWid;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfMsdcLivTrack)
	  */
	class ContInf : public Block {

	public:
		static const uint BUTMASTERON = 1;
		static const uint TXTVPX = 2;
		static const uint TXTVPY = 3;
		static const uint TXTWPX = 4;
		static const uint TXTWPY = 5;
		static const uint TXTDIS = 6;

	public:
		ContInf(const bool ButMasterOn = false, const string& TxtVpx = "", const string& TxtVpy = "", const string& TxtWpx = "", const string& TxtWpy = "", const string& TxtDis = "");

	public:
		bool ButMasterOn;
		string TxtVpx;
		string TxtVpy;
		string TxtWpx;
		string TxtWpy;
		string TxtDis;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
		* StatShr (full: StatShrMsdcLivTrack)
		*/
	class StatShr : public Block {

	public:
		static const uint IXMSDCVEXPSTATE = 1;
		static const uint PUPAMFACTIVE = 2;
		static const uint UPDAPRACTIVE = 3;
		static const uint UPDAPRMIN = 4;
		static const uint UPDAPRMAX = 5;
		static const uint CHKVIDACTIVE = 6;
		static const uint CHKWIDACTIVE = 7;

	public:
		StatShr(const uint ixMsdcVExpstate = VecMsdcVExpstate::MIND, const bool PupAmfActive = true, const bool UpdAprActive = true, const int UpdAprMin = 0, const int UpdAprMax = 100, const bool ChkVidActive = true, const bool ChkWidActive = true);

	public:
		uint ixMsdcVExpstate;
		bool PupAmfActive;
		bool UpdAprActive;
		int UpdAprMin;
		int UpdAprMax;
		bool ChkVidActive;
		bool ChkWidActive;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagMsdcLivTrack)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixMsdcVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppMsdcLivTrackData)
		*/
	class DpchAppData : public DpchAppMsdc {

	public:
		static const uint JREF = 1;
		static const uint CONTIAC = 2;

	public:
		DpchAppData();

	public:
		ContIac contiac;

	public:
		string getSrefsMask();

		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppMsdcLivTrackDo)
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
		* DpchEngData (full: DpchEngMsdcLivTrackData)
		*/
	class DpchEngData : public DpchEngMsdc {

	public:
		static const uint JREF = 1;
		static const uint CONTIAC = 2;
		static const uint CONTINF = 3;
		static const uint FEEDFPUPAMF = 4;
		static const uint STATSHR = 5;
		static const uint TAG = 6;
		static const uint ALL = 7;

	public:
		DpchEngData(const ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, Feed* feedFPupAmf = NULL, StatShr* statshr = NULL, const set<uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		Feed feedFPupAmf;
		StatShr statshr;

	public:
		string getSrefsMask();
		void merge(DpchEngMsdc* dpcheng);

		void writeXML(const uint ixMsdcVLocale, xmlTextWriter* wr);
	};

	bool evalPupAmfActive(DbsMsdc* dbsmsdc);
	bool evalUpdAprActive(DbsMsdc* dbsmsdc);
	bool evalChkVidActive(DbsMsdc* dbsmsdc);
	bool evalChkWidActive(DbsMsdc* dbsmsdc);

public:
	PnlMsdcLivTrack(XchgMsdc* xchg, DbsMsdc* dbsmsdc, const ubigint jrefSup, const uint ixMsdcVLocale);
	~PnlMsdcLivTrack();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;

	Feed feedFPupAmf;

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
	void handleDpchAppDataContiac(DbsMsdc* dbsmsdc, ContIac* _contiac, DpchEngMsdc** dpcheng);

	void handleDpchAppDoButRegularizeClick(DbsMsdc* dbsmsdc, DpchEngMsdc** dpcheng);
	void handleDpchAppDoButMinimizeClick(DbsMsdc* dbsmsdc, DpchEngMsdc** dpcheng);
	void handleDpchAppDoButMasterClick(DbsMsdc* dbsmsdc, DpchEngMsdc** dpcheng);

	void handleCall(DbsMsdc* dbsmsdc, Call* call);

	bool handleCallMsdcMastslvChg(DbsMsdc* dbsmsdc, const ubigint jrefTrig);
	bool handleCallMsdcSgeChg(DbsMsdc* dbsmsdc, const ubigint jrefTrig);
};

#endif

