/**
  * \file PnlMsdcLivVideo.h
  * job handler for job PnlMsdcLivVideo (declarations)
  * \author Alexander Wirthmueller
  * \date created: 15 Aug 2018
  * \date modified: 15 Aug 2018
  */

#ifndef PNLMSDCLIVVIDEO_H
#define PNLMSDCLIVVIDEO_H

// IP custInclude --- INSERT

#include "JobMsdcAcqLwir.h"
#include "JobMsdcAcqVisl.h"
#include "JobMsdcAcqVisr.h"
#include "JobMsdcPrcStereo.h"

#define VecVMsdcLivVideoDo PnlMsdcLivVideo::VecVDo
#define VecVMsdcLivVideoSource PnlMsdcLivVideo::VecVSource

#define ContIacMsdcLivVideo PnlMsdcLivVideo::ContIac
#define ContInfMsdcLivVideo PnlMsdcLivVideo::ContInf
#define StatAppMsdcLivVideo PnlMsdcLivVideo::StatApp
#define StatShrMsdcLivVideo PnlMsdcLivVideo::StatShr
#define TagMsdcLivVideo PnlMsdcLivVideo::Tag

#define DpchAppMsdcLivVideoData PnlMsdcLivVideo::DpchAppData
#define DpchAppMsdcLivVideoDo PnlMsdcLivVideo::DpchAppDo
#define DpchEngMsdcLivVideoData PnlMsdcLivVideo::DpchEngData
#define DpchEngMsdcLivVideoLive PnlMsdcLivVideo::DpchEngLive

/**
  * PnlMsdcLivVideo
  */
class PnlMsdcLivVideo : public JobMsdc {

public:
	/**
		* VecVDo (full: VecVMsdcLivVideoDo)
		*/
	class VecVDo {

	public:
		static const uint BUTMASTERCLICK = 1;
		static const uint BUTPLAYCLICK = 2;
		static const uint BUTSTOPCLICK = 3;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
		* VecVSource (full: VecVMsdcLivVideoSource)
		*/
	class VecVSource {

	public:
		static const uint VOID = 1;
		static const uint VISL = 2;
		static const uint VISR = 3;
		static const uint LWIR = 4;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);

		static string getTitle(const uint ix, const uint ixMsdcVLocale);

		static void fillFeed(const uint ixMsdcVLocale, Feed& feed);
	};

	/**
	  * ContIac (full: ContIacMsdcLivVideo)
	  */
	class ContIac : public Block {

	public:
		static const uint NUMFPUPSRC = 1;
		static const uint NUMFPUPRES = 2;
		static const uint SLDEXT = 3;
		static const uint SLDFCS = 4;

	public:
		ContIac(const uint numFPupSrc = 1, const uint numFPupRes = 1, const double SldExt = 0.0, const double SldFcs = 0.0);

	public:
		uint numFPupSrc;
		uint numFPupRes;
		double SldExt;
		double SldFcs;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfMsdcLivVideo)
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
		* StatApp (full: StatAppMsdcLivVideo)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const uint ixMsdcVExpstate = VecMsdcVExpstate::MIND);
	};

	/**
		* StatShr (full: StatShrMsdcLivVideo)
		*/
	class StatShr : public Block {

	public:
		static const uint PUPRESAVAIL = 1;
		static const uint BUTPLAYACTIVE = 2;
		static const uint BUTSTOPACTIVE = 3;
		static const uint SLDEXTAVAIL = 4;
		static const uint SLDEXTACTIVE = 5;
		static const uint SLDEXTMIN = 6;
		static const uint SLDEXTMAX = 7;
		static const uint SLDEXTRAST = 8;
		static const uint SLDFCSAVAIL = 9;
		static const uint SLDFCSACTIVE = 10;
		static const uint SLDFCSMIN = 11;
		static const uint SLDFCSMAX = 12;

	public:
		StatShr(const bool PupResAvail = true, const bool ButPlayActive = true, const bool ButStopActive = true, const bool SldExtAvail = true, const bool SldExtActive = true, const double SldExtMin = 0.01, const double SldExtMax = 1.0, const double SldExtRast = 1.25893, const bool SldFcsAvail = true, const bool SldFcsActive = true, const double SldFcsMin = 0.0, const double SldFcsMax = 1.0);

	public:
		bool PupResAvail;
		bool ButPlayActive;
		bool ButStopActive;
		bool SldExtAvail;
		bool SldExtActive;
		double SldExtMin;
		double SldExtMax;
		double SldExtRast;
		bool SldFcsAvail;
		bool SldFcsActive;
		double SldFcsMin;
		double SldFcsMax;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagMsdcLivVideo)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixMsdcVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppMsdcLivVideoData)
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

		void readXML(pthread_mutex_t* mScr, map<string,ubigint>& descr, xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppMsdcLivVideoDo)
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

		void readXML(pthread_mutex_t* mScr, map<string,ubigint>& descr, xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngData (full: DpchEngMsdcLivVideoData)
		*/
	class DpchEngData : public DpchEngMsdc {

	public:
		static const uint JREF = 1;
		static const uint CONTIAC = 2;
		static const uint CONTINF = 3;
		static const uint FEEDFPUPRES = 4;
		static const uint FEEDFPUPSRC = 5;
		static const uint STATAPP = 6;
		static const uint STATSHR = 7;
		static const uint TAG = 8;
		static const uint ALL = 9;

	public:
		DpchEngData(const ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, Feed* feedFPupRes = NULL, Feed* feedFPupSrc = NULL, StatShr* statshr = NULL, const set<uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		Feed feedFPupRes;
		Feed feedFPupSrc;
		StatShr statshr;

	public:
		string getSrefsMask();
		void merge(DpchEngMsdc* dpcheng);

		void writeXML(const uint ixMsdcVLocale, pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
	};

	/**
		* DpchEngLive (full: DpchEngMsdcLivVideoLive)
		*/
	class DpchEngLive : public DpchEngMsdc {

	public:
		static const uint JREF = 1;
		static const uint CONTINF = 2;
		static const uint RGB = 3;
		static const uint RED = 4;
		static const uint GREEN = 5;
		static const uint BLUE = 6;
		static const uint GRAY = 7;
		static const uint ALL = 8;

	public:
		DpchEngLive(const ubigint jref = 0, ContInf* continf = NULL, const vector<utinyint>& rgb = {}, const vector<utinyint>& red = {}, const vector<utinyint>& green = {}, const vector<utinyint>& blue = {}, const vector<usmallint>& gray = {}, const set<uint>& mask = {NONE});

	public:
		ContInf continf;
		vector<utinyint> rgb;
		vector<utinyint> red;
		vector<utinyint> green;
		vector<utinyint> blue;
		vector<usmallint> gray;

	public:
		string getSrefsMask();
		void merge(DpchEngMsdc* dpcheng);

		void writeXML(const uint ixMsdcVLocale, pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
	};

	bool evalPupResAvail(DbsMsdc* dbsmsdc);
	bool evalButPlayActive(DbsMsdc* dbsmsdc);
	bool evalButStopActive(DbsMsdc* dbsmsdc);
	bool evalSldExtAvail(DbsMsdc* dbsmsdc);
	bool evalSldExtActive(DbsMsdc* dbsmsdc);
	bool evalSldFcsAvail(DbsMsdc* dbsmsdc);
	bool evalSldFcsActive(DbsMsdc* dbsmsdc);

public:
	PnlMsdcLivVideo(XchgMsdc* xchg, DbsMsdc* dbsmsdc, const ubigint jrefSup, const uint ixMsdcVLocale);
	~PnlMsdcLivVideo();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;

	Feed feedFPupRes;
	Feed feedFPupSrc;

	JobMsdcAcqLwir* acqlwir;
	JobMsdcAcqVisl* acqvisl;
	JobMsdcAcqVisr* acqvisr;
	JobMsdcPrcStereo* prcstereo;

	// IP custVar --- IBEGIN
	uint ixVSource;
	
	Snippet* red;
	Snippet* green;
	Snippet* blue;

	Snippet* gray;

	unsigned int fnew;
	double fps;
	// IP custVar --- IEND

public:
	// IP cust --- IBEGIN
	void changeSource(DbsMsdc* dbsmsdc, const uint _ixVSource);

	void refreshLive(DbsMsdc* dbsmsdc, set<uint>& moditems);

	bool started();
	// IP cust --- IEND

public:
	DpchEngMsdc* getNewDpchEng(set<uint> items);

	void refresh(DbsMsdc* dbsmsdc, set<uint>& moditems);

public:

	void handleRequest(DbsMsdc* dbsmsdc, ReqMsdc* req);

	void handleDpchAppMsdcInit(DbsMsdc* dbsmsdc, DpchAppMsdcInit* dpchappmsdcinit, DpchEngMsdc** dpcheng);
	void handleDpchAppDataContiac(DbsMsdc* dbsmsdc, ContIac* _contiac, DpchEngMsdc** dpcheng);

	void handleDpchAppDoButMasterClick(DbsMsdc* dbsmsdc, DpchEngMsdc** dpcheng);
	void handleDpchAppDoButPlayClick(DbsMsdc* dbsmsdc, DpchEngMsdc** dpcheng);
	void handleDpchAppDoButStopClick(DbsMsdc* dbsmsdc, DpchEngMsdc** dpcheng);

	void handleCall(DbsMsdc* dbsmsdc, Call* call);

	bool handleCallMsdcImgrdy(DbsMsdc* dbsmsdc, const ubigint jrefTrig);
	bool handleCallMsdcMastslvChg(DbsMsdc* dbsmsdc, const ubigint jrefTrig);
	bool handleCallMsdcSgeChg(DbsMsdc* dbsmsdc, const ubigint jrefTrig);
};

#endif




