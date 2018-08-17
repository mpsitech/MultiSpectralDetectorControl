/**
  * \file PnlMsdcLivScill.h
  * API code for job PnlMsdcLivScill (declarations)
  * \author Alexander Wirthmueller
  * \date created: 15 Aug 2018
  * \date modified: 15 Aug 2018
  */

#ifndef PNLMSDCLIVSCILL_H
#define PNLMSDCLIVSCILL_H

#include "ApiMsdc_blks.h"

#define VecVMsdcLivScillDo PnlMsdcLivScill::VecVDo

#define ContIacMsdcLivScill PnlMsdcLivScill::ContIac
#define ContInfMsdcLivScill PnlMsdcLivScill::ContInf
#define StatAppMsdcLivScill PnlMsdcLivScill::StatApp
#define StatShrMsdcLivScill PnlMsdcLivScill::StatShr
#define TagMsdcLivScill PnlMsdcLivScill::Tag

#define DpchAppMsdcLivScillData PnlMsdcLivScill::DpchAppData
#define DpchAppMsdcLivScillDo PnlMsdcLivScill::DpchAppDo
#define DpchEngMsdcLivScillData PnlMsdcLivScill::DpchEngData

/**
  * PnlMsdcLivScill
  */
namespace PnlMsdcLivScill {
	/**
		* VecVDo (full: VecVMsdcLivScillDo)
		*/
	class VecVDo {

	public:
		static const uint BUTMASTERCLICK = 1;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacMsdcLivScill)
	  */
	class ContIac : public Block {

	public:
		static const uint SLDFLD = 1;
		static const uint SLDSPT = 2;

	public:
		ContIac(const double SldFld = 0.5, const double SldSpt = 0.5);

	public:
		double SldFld;
		double SldSpt;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfMsdcLivScill)
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
	  * StatApp (full: StatAppMsdcLivScill)
	  */
	class StatApp : public Block {

	public:
		static const uint IXMSDCVEXPSTATE = 1;

	public:
		StatApp(const uint ixMsdcVExpstate = VecMsdcVExpstate::MIND);

	public:
		uint ixMsdcVExpstate;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatApp* comp);
		set<uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrMsdcLivScill)
	  */
	class StatShr : public Block {

	public:
		static const uint SLDFLDACTIVE = 1;
		static const uint SLDFLDMIN = 2;
		static const uint SLDFLDMAX = 3;
		static const uint SLDSPTACTIVE = 4;
		static const uint SLDSPTMIN = 5;
		static const uint SLDSPTMAX = 6;

	public:
		StatShr(const bool SldFldActive = true, const double SldFldMin = 0.0, const double SldFldMax = 1.0, const bool SldSptActive = true, const double SldSptMin = 0.0, const double SldSptMax = 1.0);

	public:
		bool SldFldActive;
		double SldFldMin;
		double SldFldMax;
		bool SldSptActive;
		double SldSptMin;
		double SldSptMax;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagMsdcLivScill)
	  */
	class Tag : public Block {

	public:
		static const uint CPT = 1;
		static const uint CPTFLD = 2;
		static const uint CPTSPT = 3;

	public:
		Tag(const string& Cpt = "", const string& CptFld = "", const string& CptSpt = "");

	public:
		string Cpt;
		string CptFld;
		string CptSpt;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppMsdcLivScillData)
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
		* DpchAppDo (full: DpchAppMsdcLivScillDo)
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
		* DpchEngData (full: DpchEngMsdcLivScillData)
		*/
	class DpchEngData : public DpchEngMsdc {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTIAC = 2;
		static const uint CONTINF = 3;
		static const uint STATAPP = 4;
		static const uint STATSHR = 5;
		static const uint TAG = 6;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		string getSrefsMask();

		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

