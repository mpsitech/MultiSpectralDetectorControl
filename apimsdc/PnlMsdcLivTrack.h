/**
  * \file PnlMsdcLivTrack.h
  * API code for job PnlMsdcLivTrack (declarations)
  * \author Alexander Wirthmueller
  * \date created: 18 Dec 2018
  * \date modified: 18 Dec 2018
  */

#ifndef PNLMSDCLIVTRACK_H
#define PNLMSDCLIVTRACK_H

#include "ApiMsdc_blks.h"

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
namespace PnlMsdcLivTrack {
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
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
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
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagMsdcLivTrack)
	  */
	class Tag : public Block {

	public:
		static const uint CPT = 1;
		static const uint HDGALS = 2;
		static const uint CPTAMF = 3;
		static const uint CPTAPR = 4;
		static const uint HDGVSL = 5;
		static const uint CPTVID = 6;
		static const uint CPTVPX = 7;
		static const uint CPTVPY = 8;
		static const uint HDGWSR = 9;
		static const uint CPTWID = 10;
		static const uint CPTWPX = 11;
		static const uint CPTWPY = 12;
		static const uint CPTDIS = 13;

	public:
		Tag(const string& Cpt = "", const string& HdgAls = "", const string& CptAmf = "", const string& CptApr = "", const string& HdgVsl = "", const string& CptVid = "", const string& CptVpx = "", const string& CptVpy = "", const string& HdgWsr = "", const string& CptWid = "", const string& CptWpx = "", const string& CptWpy = "", const string& CptDis = "");

	public:
		string Cpt;
		string HdgAls;
		string CptAmf;
		string CptApr;
		string HdgVsl;
		string CptVid;
		string CptVpx;
		string CptVpy;
		string HdgWsr;
		string CptWid;
		string CptWpx;
		string CptWpy;
		string CptDis;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppMsdcLivTrackData)
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
		* DpchAppDo (full: DpchAppMsdcLivTrackDo)
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
		* DpchEngData (full: DpchEngMsdcLivTrackData)
		*/
	class DpchEngData : public DpchEngMsdc {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTIAC = 2;
		static const uint CONTINF = 3;
		static const uint FEEDFPUPAMF = 4;
		static const uint STATSHR = 5;
		static const uint TAG = 6;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Feed feedFPupAmf;
		StatShr statshr;
		Tag tag;

	public:
		string getSrefsMask();

		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

