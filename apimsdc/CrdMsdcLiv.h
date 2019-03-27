/**
  * \file CrdMsdcLiv.h
  * API code for job CrdMsdcLiv (declarations)
  * \author Alexander Wirthmueller
  * \date created: 18 Dec 2018
  * \date modified: 18 Dec 2018
  */

#ifndef CRDMSDCLIV_H
#define CRDMSDCLIV_H

#include "ApiMsdc_blks.h"

#define VecVMsdcLivDo CrdMsdcLiv::VecVDo
#define VecVMsdcLivSge CrdMsdcLiv::VecVSge

#define ContInfMsdcLiv CrdMsdcLiv::ContInf
#define StatAppMsdcLiv CrdMsdcLiv::StatApp
#define StatShrMsdcLiv CrdMsdcLiv::StatShr
#define TagMsdcLiv CrdMsdcLiv::Tag

#define DpchAppMsdcLivDo CrdMsdcLiv::DpchAppDo
#define DpchEngMsdcLivData CrdMsdcLiv::DpchEngData

/**
  * CrdMsdcLiv
  */
namespace CrdMsdcLiv {
	/**
		* VecVDo (full: VecVMsdcLivDo)
		*/
	class VecVDo {

	public:
		static const uint CLOSE = 1;
		static const uint MITAPPABTCLICK = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
		* VecVSge (full: VecVMsdcLivSge)
		*/
	class VecVSge {

	public:
		static const uint IDLE = 1;
		static const uint ALRMSDCABT = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContInf (full: ContInfMsdcLiv)
	  */
	class ContInf : public Block {

	public:
		static const uint NUMFSGE = 1;
		static const uint MRLAPPHLP = 2;

	public:
		ContInf(const uint numFSge = 1, const string& MrlAppHlp = "");

	public:
		uint numFSge;
		string MrlAppHlp;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppMsdcLiv)
	  */
	class StatApp : public Block {

	public:
		static const uint IXMSDCVREQITMODE = 1;
		static const uint LATENCY = 2;
		static const uint SHORTMENU = 3;
		static const uint WIDTHMENU = 4;
		static const uint INITDONEVIDEO = 5;
		static const uint INITDONEALIGN = 6;
		static const uint INITDONESCILL = 7;
		static const uint INITDONETRACK = 8;
		static const uint INITDONEHEADBAR = 9;

	public:
		StatApp(const uint ixMsdcVReqitmode = VecMsdcVReqitmode::IDLE, const usmallint latency = 5, const string& shortMenu = "", const uint widthMenu = 0, const bool initdoneVideo = false, const bool initdoneAlign = false, const bool initdoneScill = false, const bool initdoneTrack = false, const bool initdoneHeadbar = false);

	public:
		uint ixMsdcVReqitmode;
		usmallint latency;
		string shortMenu;
		uint widthMenu;
		bool initdoneVideo;
		bool initdoneAlign;
		bool initdoneScill;
		bool initdoneTrack;
		bool initdoneHeadbar;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatApp* comp);
		set<uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrMsdcLiv)
	  */
	class StatShr : public Block {

	public:
		static const uint SCRJREFVIDEO = 1;
		static const uint SCRJREFALIGN = 2;
		static const uint SCRJREFSCILL = 3;
		static const uint SCRJREFTRACK = 4;
		static const uint SCRJREFHEADBAR = 5;

	public:
		StatShr(const string& scrJrefVideo = "", const string& scrJrefAlign = "", const string& scrJrefScill = "", const string& scrJrefTrack = "", const string& scrJrefHeadbar = "");

	public:
		string scrJrefVideo;
		string scrJrefAlign;
		string scrJrefScill;
		string scrJrefTrack;
		string scrJrefHeadbar;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagMsdcLiv)
	  */
	class Tag : public Block {

	public:
		static const uint MITAPPABT = 1;
		static const uint MRLAPPHLP = 2;

	public:
		Tag(const string& MitAppAbt = "", const string& MrlAppHlp = "");

	public:
		string MitAppAbt;
		string MrlAppHlp;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppMsdcLivDo)
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
		* DpchEngData (full: DpchEngMsdcLivData)
		*/
	class DpchEngData : public DpchEngMsdc {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTINF = 2;
		static const uint FEEDFSGE = 3;
		static const uint STATAPP = 4;
		static const uint STATSHR = 5;
		static const uint TAG = 6;

	public:
		DpchEngData();

	public:
		ContInf continf;
		Feed feedFSge;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		string getSrefsMask();

		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

