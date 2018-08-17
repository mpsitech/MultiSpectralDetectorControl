/**
  * \file PnlMsdcScfSource.h
  * API code for job PnlMsdcScfSource (declarations)
  * \author Alexander Wirthmueller
  * \date created: 15 Aug 2018
  * \date modified: 15 Aug 2018
  */

#ifndef PNLMSDCSCFSOURCE_H
#define PNLMSDCSCFSOURCE_H

#include "ApiMsdc_blks.h"

#define VecVMsdcScfSourceDo PnlMsdcScfSource::VecVDo

#define ContIacMsdcScfSource PnlMsdcScfSource::ContIac
#define ContInfMsdcScfSource PnlMsdcScfSource::ContInf
#define StatAppMsdcScfSource PnlMsdcScfSource::StatApp
#define StatShrMsdcScfSource PnlMsdcScfSource::StatShr
#define TagMsdcScfSource PnlMsdcScfSource::Tag

#define DpchAppMsdcScfSourceData PnlMsdcScfSource::DpchAppData
#define DpchAppMsdcScfSourceDo PnlMsdcScfSource::DpchAppDo
#define DpchEngMsdcScfSourceData PnlMsdcScfSource::DpchEngData

/**
  * PnlMsdcScfSource
  */
namespace PnlMsdcScfSource {
	/**
		* VecVDo (full: VecVMsdcScfSourceDo)
		*/
	class VecVDo {

	public:
		static const uint BUTMASTERCLICK = 1;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacMsdcScfSource)
	  */
	class ContIac : public Block {

	public:
		static const uint TXFFPP = 1;
		static const uint SLDFXA = 2;
		static const uint SLDFA0 = 3;
		static const uint SLDFB0 = 4;
		static const uint UPDFAM = 5;
		static const uint SLDFSA = 6;
		static const uint SLDFT0 = 7;
		static const uint SLDFP0 = 8;
		static const uint SLDTRP = 9;

	public:
		ContIac(const string& TxfFpp = "", const double SldFxa = 0.0, const double SldFa0 = 0.0, const double SldFb0 = 0.0, const int UpdFam = 0, const double SldFsa = 0.0, const double SldFt0 = 0.0, const double SldFp0 = 0.0, const double SldTrp = 0.0);

	public:
		string TxfFpp;
		double SldFxa;
		double SldFa0;
		double SldFb0;
		int UpdFam;
		double SldFsa;
		double SldFt0;
		double SldFp0;
		double SldTrp;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfMsdcScfSource)
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
	  * StatApp (full: StatAppMsdcScfSource)
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
	  * StatShr (full: StatShrMsdcScfSource)
	  */
	class StatShr : public Block {

	public:
		static const uint SLDFXAMIN = 1;
		static const uint SLDFXAMAX = 2;
		static const uint SLDFA0MIN = 3;
		static const uint SLDFA0MAX = 4;
		static const uint SLDFB0MIN = 5;
		static const uint SLDFB0MAX = 6;
		static const uint UPDFAMMIN = 7;
		static const uint UPDFAMMAX = 8;
		static const uint SLDFSAMIN = 9;
		static const uint SLDFSAMAX = 10;
		static const uint SLDFT0MIN = 11;
		static const uint SLDFT0MAX = 12;
		static const uint SLDFP0MIN = 13;
		static const uint SLDFP0MAX = 14;
		static const uint SLDTRPMIN = 15;
		static const uint SLDTRPMAX = 16;
		static const uint SLDTRPRAST = 17;

	public:
		StatShr(const double SldFxaMin = 0.004, const double SldFxaMax = 0.032, const double SldFa0Min = -15.0, const double SldFa0Max = 15.0, const double SldFb0Min = -15.0, const double SldFb0Max = 15.0, const int UpdFamMin = 25, const int UpdFamMax = 255, const double SldFsaMin = 0.0, const double SldFsaMax = 15.0, const double SldFt0Min = -30.0, const double SldFt0Max = 30.0, const double SldFp0Min = -30.0, const double SldFp0Max = 30.0, const double SldTrpMin = 0.25, const double SldTrpMax = 2.0, const double SldTrpRast = 0.25);

	public:
		double SldFxaMin;
		double SldFxaMax;
		double SldFa0Min;
		double SldFa0Max;
		double SldFb0Min;
		double SldFb0Max;
		int UpdFamMin;
		int UpdFamMax;
		double SldFsaMin;
		double SldFsaMax;
		double SldFt0Min;
		double SldFt0Max;
		double SldFp0Min;
		double SldFp0Max;
		double SldTrpMin;
		double SldTrpMax;
		double SldTrpRast;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagMsdcScfSource)
	  */
	class Tag : public Block {

	public:
		static const uint CPT = 1;
		static const uint HDGFPG = 2;
		static const uint CPTFPP = 3;
		static const uint CPTFXA = 4;
		static const uint CPTFA0 = 5;
		static const uint CPTFB0 = 6;
		static const uint CPTFAM = 7;
		static const uint CPTFSA = 8;
		static const uint CPTFT0 = 9;
		static const uint CPTFP0 = 10;
		static const uint CPTTRP = 11;

	public:
		Tag(const string& Cpt = "", const string& HdgFpg = "", const string& CptFpp = "", const string& CptFxa = "", const string& CptFa0 = "", const string& CptFb0 = "", const string& CptFam = "", const string& CptFsa = "", const string& CptFt0 = "", const string& CptFp0 = "", const string& CptTrp = "");

	public:
		string Cpt;
		string HdgFpg;
		string CptFpp;
		string CptFxa;
		string CptFa0;
		string CptFb0;
		string CptFam;
		string CptFsa;
		string CptFt0;
		string CptFp0;
		string CptTrp;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppMsdcScfSourceData)
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
		* DpchAppDo (full: DpchAppMsdcScfSourceDo)
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
		* DpchEngData (full: DpchEngMsdcScfSourceData)
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

