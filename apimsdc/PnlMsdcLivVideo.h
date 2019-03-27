/**
  * \file PnlMsdcLivVideo.h
  * API code for job PnlMsdcLivVideo (declarations)
  * \author Alexander Wirthmueller
  * \date created: 18 Dec 2018
  * \date modified: 18 Dec 2018
  */

#ifndef PNLMSDCLIVVIDEO_H
#define PNLMSDCLIVVIDEO_H

#include "ApiMsdc_blks.h"

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
namespace PnlMsdcLivVideo {
	/**
		* VecVDo (full: VecVMsdcLivVideoDo)
		*/
	class VecVDo {

	public:
		static const uint BUTREGULARIZECLICK = 1;
		static const uint BUTMINIMIZECLICK = 2;
		static const uint BUTMASTERCLICK = 3;
		static const uint BUTPLAYCLICK = 4;
		static const uint BUTSTOPCLICK = 5;

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
	};

	/**
	  * ContIac (full: ContIacMsdcLivVideo)
	  */
	class ContIac : public Block {

	public:
		static const uint NUMFPUPSRC = 1;
		static const uint NUMFPUPRES = 2;
		static const uint CHKGRS = 3;
		static const uint SLDEXT = 4;
		static const uint SLDFCS = 5;
		static const uint CHKTCP = 6;
		static const uint NUMFLSTFST = 7;

	public:
		ContIac(const uint numFPupSrc = 1, const uint numFPupRes = 1, const bool ChkGrs = false, const double SldExt = 0.0, const double SldFcs = 0.0, const bool ChkTcp = false, const uint numFLstFst = 1);

	public:
		uint numFPupSrc;
		uint numFPupRes;
		bool ChkGrs;
		double SldExt;
		double SldFcs;
		bool ChkTcp;
		uint numFLstFst;

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
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppMsdcLivVideo)
	  */
	class StatApp : public Block {

	public:
		static const uint LSTFSTNUMFIRSTDISP = 1;

	public:
		StatApp(const uint LstFstNumFirstdisp = 1);

	public:
		uint LstFstNumFirstdisp;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatApp* comp);
		set<uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrMsdcLivVideo)
	  */
	class StatShr : public Block {

	public:
		static const uint IXMSDCVEXPSTATE = 1;
		static const uint PUPRESAVAIL = 2;
		static const uint CHKGRSAVAIL = 3;
		static const uint BUTPLAYACTIVE = 4;
		static const uint BUTSTOPACTIVE = 5;
		static const uint SLDEXTAVAIL = 6;
		static const uint SLDEXTACTIVE = 7;
		static const uint SLDEXTMIN = 8;
		static const uint SLDEXTMAX = 9;
		static const uint SLDEXTRAST = 10;
		static const uint SLDFCSAVAIL = 11;
		static const uint SLDFCSACTIVE = 12;
		static const uint SLDFCSMIN = 13;
		static const uint SLDFCSMAX = 14;
		static const uint CHKTCPAVAIL = 15;
		static const uint LSTFSTACTIVE = 16;

	public:
		StatShr(const uint ixMsdcVExpstate = VecMsdcVExpstate::MIND, const bool PupResAvail = true, const bool ChkGrsAvail = true, const bool ButPlayActive = true, const bool ButStopActive = true, const bool SldExtAvail = true, const bool SldExtActive = true, const double SldExtMin = 0.01, const double SldExtMax = 1.0, const double SldExtRast = 1.25893, const bool SldFcsAvail = true, const bool SldFcsActive = true, const double SldFcsMin = 0.0, const double SldFcsMax = 1.0, const bool ChkTcpAvail = true, const bool LstFstActive = true);

	public:
		uint ixMsdcVExpstate;
		bool PupResAvail;
		bool ChkGrsAvail;
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
		bool ChkTcpAvail;
		bool LstFstActive;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagMsdcLivVideo)
	  */
	class Tag : public Block {

	public:
		static const uint CPT = 1;
		static const uint CPTSRC = 2;
		static const uint CPTRES = 3;
		static const uint CPTGRS = 4;
		static const uint CPTEXT = 5;
		static const uint CPTFCS = 6;
		static const uint CPTTCP = 7;
		static const uint CPTFST = 8;

	public:
		Tag(const string& Cpt = "", const string& CptSrc = "", const string& CptRes = "", const string& CptGrs = "", const string& CptExt = "", const string& CptFcs = "", const string& CptTcp = "", const string& CptFst = "");

	public:
		string Cpt;
		string CptSrc;
		string CptRes;
		string CptGrs;
		string CptExt;
		string CptFcs;
		string CptTcp;
		string CptFst;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppMsdcLivVideoData)
		*/
	class DpchAppData : public DpchAppMsdc {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTIAC = 2;
		static const uint ALL = 3;

	public:
		DpchAppData(const string& scrJref = "", ContIac* contiac = NULL, const set<uint>& mask = {NONE});

	public:
		ContIac contiac;

	public:
		string getSrefsMask();

		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchAppDo (full: DpchAppMsdcLivVideoDo)
		*/
	class DpchAppDo : public DpchAppMsdc {

	public:
		static const uint SCRJREF = 1;
		static const uint IXVDO = 2;
		static const uint ALL = 3;

	public:
		DpchAppDo(const string& scrJref = "", const uint ixVDo = 0, const set<uint>& mask = {NONE});

	public:
		uint ixVDo;

	public:
		string getSrefsMask();

		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchEngData (full: DpchEngMsdcLivVideoData)
		*/
	class DpchEngData : public DpchEngMsdc {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTIAC = 2;
		static const uint CONTINF = 3;
		static const uint FEEDFLSTFST = 4;
		static const uint FEEDFPUPRES = 5;
		static const uint FEEDFPUPSRC = 6;
		static const uint STATAPP = 7;
		static const uint STATSHR = 8;
		static const uint TAG = 9;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Feed feedFLstFst;
		Feed feedFPupRes;
		Feed feedFPupSrc;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		string getSrefsMask();

		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngLive (full: DpchEngMsdcLivVideoLive)
		*/
	class DpchEngLive : public DpchEngMsdc {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTINF = 2;
		static const uint RGB = 3;
		static const uint RED = 4;
		static const uint GREEN = 5;
		static const uint BLUE = 6;
		static const uint GRAY = 7;

	public:
		DpchEngLive();

	public:
		ContInf continf;
		vector<utinyint> rgb;
		vector<utinyint> red;
		vector<utinyint> green;
		vector<utinyint> blue;
		vector<usmallint> gray;

	public:
		string getSrefsMask();

		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

