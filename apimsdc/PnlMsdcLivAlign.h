/**
  * \file PnlMsdcLivAlign.h
  * API code for job PnlMsdcLivAlign (declarations)
  * \author Alexander Wirthmueller
  * \date created: 18 Dec 2018
  * \date modified: 18 Dec 2018
  */

#ifndef PNLMSDCLIVALIGN_H
#define PNLMSDCLIVALIGN_H

#include "ApiMsdc_blks.h"

#define VecVMsdcLivAlignDo PnlMsdcLivAlign::VecVDo

#define ContIacMsdcLivAlign PnlMsdcLivAlign::ContIac
#define ContInfMsdcLivAlign PnlMsdcLivAlign::ContInf
#define StatShrMsdcLivAlign PnlMsdcLivAlign::StatShr
#define TagMsdcLivAlign PnlMsdcLivAlign::Tag

#define DpchAppMsdcLivAlignData PnlMsdcLivAlign::DpchAppData
#define DpchAppMsdcLivAlignDo PnlMsdcLivAlign::DpchAppDo
#define DpchEngMsdcLivAlignData PnlMsdcLivAlign::DpchEngData

/**
  * PnlMsdcLivAlign
  */
namespace PnlMsdcLivAlign {
	/**
		* VecVDo (full: VecVMsdcLivAlignDo)
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
	  * ContIac (full: ContIacMsdcLivAlign)
	  */
	class ContIac : public Block {

	public:
		static const uint SLDTHE = 1;
		static const uint SLDPHI = 2;

	public:
		ContIac(const double SldThe = 0.0, const double SldPhi = 0.0);

	public:
		double SldThe;
		double SldPhi;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfMsdcLivAlign)
	  */
	class ContInf : public Block {

	public:
		static const uint BUTMASTERON = 1;
		static const uint TXTAPH = 2;
		static const uint TXTBTA = 3;

	public:
		ContInf(const bool ButMasterOn = false, const string& TxtAph = "", const string& TxtBta = "");

	public:
		bool ButMasterOn;
		string TxtAph;
		string TxtBta;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
	  * StatShr (full: StatShrMsdcLivAlign)
	  */
	class StatShr : public Block {

	public:
		static const uint IXMSDCVEXPSTATE = 1;
		static const uint SLDTHEACTIVE = 2;
		static const uint SLDTHEMIN = 3;
		static const uint SLDTHEMAX = 4;
		static const uint SLDPHIACTIVE = 5;
		static const uint SLDPHIMIN = 6;
		static const uint SLDPHIMAX = 7;

	public:
		StatShr(const uint ixMsdcVExpstate = VecMsdcVExpstate::MIND, const bool SldTheActive = true, const double SldTheMin = -40.0, const double SldTheMax = 40.0, const bool SldPhiActive = true, const double SldPhiMin = -40.0, const double SldPhiMax = 40.0);

	public:
		uint ixMsdcVExpstate;
		bool SldTheActive;
		double SldTheMin;
		double SldTheMax;
		bool SldPhiActive;
		double SldPhiMin;
		double SldPhiMax;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagMsdcLivAlign)
	  */
	class Tag : public Block {

	public:
		static const uint CPT = 1;
		static const uint CPTAPH = 2;
		static const uint CPTBTA = 3;
		static const uint CPTTHE = 4;
		static const uint CPTPHI = 5;

	public:
		Tag(const string& Cpt = "", const string& CptAph = "", const string& CptBta = "", const string& CptThe = "", const string& CptPhi = "");

	public:
		string Cpt;
		string CptAph;
		string CptBta;
		string CptThe;
		string CptPhi;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppMsdcLivAlignData)
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
		* DpchAppDo (full: DpchAppMsdcLivAlignDo)
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
		* DpchEngData (full: DpchEngMsdcLivAlignData)
		*/
	class DpchEngData : public DpchEngMsdc {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTIAC = 2;
		static const uint CONTINF = 3;
		static const uint STATSHR = 4;
		static const uint TAG = 5;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		StatShr statshr;
		Tag tag;

	public:
		string getSrefsMask();

		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

