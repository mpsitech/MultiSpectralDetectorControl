/**
  * \file CrdMsdcScf.h
  * API code for job CrdMsdcScf (declarations)
  * \author Alexander Wirthmueller
  * \date created: 18 Dec 2018
  * \date modified: 18 Dec 2018
  */

#ifndef CRDMSDCSCF_H
#define CRDMSDCSCF_H

#include "ApiMsdc_blks.h"

#define VecVMsdcScfDo CrdMsdcScf::VecVDo
#define VecVMsdcScfSge CrdMsdcScf::VecVSge

#define ContInfMsdcScf CrdMsdcScf::ContInf
#define StatAppMsdcScf CrdMsdcScf::StatApp
#define StatShrMsdcScf CrdMsdcScf::StatShr
#define TagMsdcScf CrdMsdcScf::Tag

#define DpchAppMsdcScfDo CrdMsdcScf::DpchAppDo
#define DpchEngMsdcScfData CrdMsdcScf::DpchEngData

/**
  * CrdMsdcScf
  */
namespace CrdMsdcScf {
	/**
		* VecVDo (full: VecVMsdcScfDo)
		*/
	class VecVDo {

	public:
		static const uint CLOSE = 1;
		static const uint MITAPPABTCLICK = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
		* VecVSge (full: VecVMsdcScfSge)
		*/
	class VecVSge {

	public:
		static const uint IDLE = 1;
		static const uint ALRMSDCABT = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContInf (full: ContInfMsdcScf)
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
	  * StatApp (full: StatAppMsdcScf)
	  */
	class StatApp : public Block {

	public:
		static const uint IXMSDCVREQITMODE = 1;
		static const uint LATENCY = 2;
		static const uint SHORTMENU = 3;
		static const uint WIDTHMENU = 4;
		static const uint INITDONESOURCE = 5;
		static const uint INITDONEACQUIS = 6;
		static const uint INITDONEACTU = 7;
		static const uint INITDONEPRCCTL = 8;
		static const uint INITDONEHEADBAR = 9;

	public:
		StatApp(const uint ixMsdcVReqitmode = VecMsdcVReqitmode::IDLE, const usmallint latency = 5, const string& shortMenu = "", const uint widthMenu = 0, const bool initdoneSource = false, const bool initdoneAcquis = false, const bool initdoneActu = false, const bool initdonePrcctl = false, const bool initdoneHeadbar = false);

	public:
		uint ixMsdcVReqitmode;
		usmallint latency;
		string shortMenu;
		uint widthMenu;
		bool initdoneSource;
		bool initdoneAcquis;
		bool initdoneActu;
		bool initdonePrcctl;
		bool initdoneHeadbar;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatApp* comp);
		set<uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrMsdcScf)
	  */
	class StatShr : public Block {

	public:
		static const uint SCRJREFSOURCE = 1;
		static const uint SCRJREFACQUIS = 2;
		static const uint SCRJREFACTU = 3;
		static const uint SCRJREFPRCCTL = 4;
		static const uint SCRJREFHEADBAR = 5;

	public:
		StatShr(const string& scrJrefSource = "", const string& scrJrefAcquis = "", const string& scrJrefActu = "", const string& scrJrefPrcctl = "", const string& scrJrefHeadbar = "");

	public:
		string scrJrefSource;
		string scrJrefAcquis;
		string scrJrefActu;
		string scrJrefPrcctl;
		string scrJrefHeadbar;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagMsdcScf)
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
		* DpchAppDo (full: DpchAppMsdcScfDo)
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
		* DpchEngData (full: DpchEngMsdcScfData)
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

