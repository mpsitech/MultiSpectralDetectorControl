/**
  * \file PnlMsdcScfAcquis.h
  * API code for job PnlMsdcScfAcquis (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Oct 2018
  * \date modified: 4 Oct 2018
  */

#ifndef PNLMSDCSCFACQUIS_H
#define PNLMSDCSCFACQUIS_H

#include "ApiMsdc_blks.h"

#define VecVMsdcScfAcquisDo PnlMsdcScfAcquis::VecVDo

#define ContIacMsdcScfAcquis PnlMsdcScfAcquis::ContIac
#define ContInfMsdcScfAcquis PnlMsdcScfAcquis::ContInf
#define StatAppMsdcScfAcquis PnlMsdcScfAcquis::StatApp
#define TagMsdcScfAcquis PnlMsdcScfAcquis::Tag

#define DpchAppMsdcScfAcquisData PnlMsdcScfAcquis::DpchAppData
#define DpchAppMsdcScfAcquisDo PnlMsdcScfAcquis::DpchAppDo
#define DpchEngMsdcScfAcquisData PnlMsdcScfAcquis::DpchEngData

/**
  * PnlMsdcScfAcquis
  */
namespace PnlMsdcScfAcquis {
	/**
		* VecVDo (full: VecVMsdcScfAcquisDo)
		*/
	class VecVDo {

	public:
		static const uint BUTMASTERCLICK = 1;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacMsdcScfAcquis)
	  */
	class ContIac : public Block {

	public:
		static const uint NUMFPUPVTY = 1;
		static const uint TXFVLP = 2;
		static const uint TXFVRP = 3;

	public:
		ContIac(const uint numFPupVty = 1, const string& TxfVlp = "", const string& TxfVrp = "");

	public:
		uint numFPupVty;
		string TxfVlp;
		string TxfVrp;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfMsdcScfAcquis)
	  */
	class ContInf : public Block {

	public:
		static const uint BUTMASTERON = 1;
		static const uint TXTISN = 2;
		static const uint TXTIPS = 3;
		static const uint TXTIFL = 4;
		static const uint TXTIFN = 5;
		static const uint TXTVPS = 6;
		static const uint TXTVFL = 7;
		static const uint TXTVFN = 8;

	public:
		ContInf(const bool ButMasterOn = false, const string& TxtIsn = "", const string& TxtIps = "", const string& TxtIfl = "", const string& TxtIfn = "", const string& TxtVps = "", const string& TxtVfl = "", const string& TxtVfn = "");

	public:
		bool ButMasterOn;
		string TxtIsn;
		string TxtIps;
		string TxtIfl;
		string TxtIfn;
		string TxtVps;
		string TxtVfl;
		string TxtVfn;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppMsdcScfAcquis)
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
	  * Tag (full: TagMsdcScfAcquis)
	  */
	class Tag : public Block {

	public:
		static const uint CPT = 1;
		static const uint HDGIWI = 2;
		static const uint CPTISN = 3;
		static const uint CPTIPS = 4;
		static const uint CPTIFL = 5;
		static const uint CPTIFN = 6;
		static const uint HDGVIS = 7;
		static const uint CPTVTY = 8;
		static const uint CPTVLP = 9;
		static const uint CPTVRP = 10;
		static const uint CPTVPS = 11;
		static const uint CPTVFL = 12;
		static const uint CPTVFN = 13;

	public:
		Tag(const string& Cpt = "", const string& HdgIwi = "", const string& CptIsn = "", const string& CptIps = "", const string& CptIfl = "", const string& CptIfn = "", const string& HdgVis = "", const string& CptVty = "", const string& CptVlp = "", const string& CptVrp = "", const string& CptVps = "", const string& CptVfl = "", const string& CptVfn = "");

	public:
		string Cpt;
		string HdgIwi;
		string CptIsn;
		string CptIps;
		string CptIfl;
		string CptIfn;
		string HdgVis;
		string CptVty;
		string CptVlp;
		string CptVrp;
		string CptVps;
		string CptVfl;
		string CptVfn;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppMsdcScfAcquisData)
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
		* DpchAppDo (full: DpchAppMsdcScfAcquisDo)
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
		* DpchEngData (full: DpchEngMsdcScfAcquisData)
		*/
	class DpchEngData : public DpchEngMsdc {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTIAC = 2;
		static const uint CONTINF = 3;
		static const uint FEEDFPUPVTY = 4;
		static const uint STATAPP = 5;
		static const uint TAG = 6;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Feed feedFPupVty;
		StatApp statapp;
		Tag tag;

	public:
		string getSrefsMask();

		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

