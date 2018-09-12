/**
  * \file DlgMsdcNavLoaini.h
  * API code for job DlgMsdcNavLoaini (declarations)
  * \author Alexander Wirthmueller
  * \date created: 12 Sep 2018
  * \date modified: 12 Sep 2018
  */

#ifndef DLGMSDCNAVLOAINI_H
#define DLGMSDCNAVLOAINI_H

#include "ApiMsdc_blks.h"

#define VecVDlgMsdcNavLoainiDit DlgMsdcNavLoaini::VecVDit
#define VecVDlgMsdcNavLoainiDo DlgMsdcNavLoaini::VecVDo
#define VecVDlgMsdcNavLoainiDoImp DlgMsdcNavLoaini::VecVDoImp
#define VecVDlgMsdcNavLoainiSge DlgMsdcNavLoaini::VecVSge

#define ContIacDlgMsdcNavLoaini DlgMsdcNavLoaini::ContIac
#define ContInfDlgMsdcNavLoaini DlgMsdcNavLoaini::ContInf
#define ContInfDlgMsdcNavLoainiImp DlgMsdcNavLoaini::ContInfImp
#define ContInfDlgMsdcNavLoainiLfi DlgMsdcNavLoaini::ContInfLfi
#define StatAppDlgMsdcNavLoaini DlgMsdcNavLoaini::StatApp
#define StatShrDlgMsdcNavLoaini DlgMsdcNavLoaini::StatShr
#define StatShrDlgMsdcNavLoainiIfi DlgMsdcNavLoaini::StatShrIfi
#define StatShrDlgMsdcNavLoainiImp DlgMsdcNavLoaini::StatShrImp
#define StatShrDlgMsdcNavLoainiLfi DlgMsdcNavLoaini::StatShrLfi
#define TagDlgMsdcNavLoaini DlgMsdcNavLoaini::Tag
#define TagDlgMsdcNavLoainiIfi DlgMsdcNavLoaini::TagIfi
#define TagDlgMsdcNavLoainiImp DlgMsdcNavLoaini::TagImp
#define TagDlgMsdcNavLoainiLfi DlgMsdcNavLoaini::TagLfi

#define DpchAppDlgMsdcNavLoainiData DlgMsdcNavLoaini::DpchAppData
#define DpchAppDlgMsdcNavLoainiDo DlgMsdcNavLoaini::DpchAppDo
#define DpchEngDlgMsdcNavLoainiData DlgMsdcNavLoaini::DpchEngData

/**
  * DlgMsdcNavLoaini
  */
namespace DlgMsdcNavLoaini {
	/**
		* VecVDit (full: VecVDlgMsdcNavLoainiDit)
		*/
	class VecVDit {

	public:
		static const uint IFI = 1;
		static const uint IMP = 2;
		static const uint LFI = 3;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
		* VecVDo (full: VecVDlgMsdcNavLoainiDo)
		*/
	class VecVDo {

	public:
		static const uint BUTDNECLICK = 1;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
		* VecVDoImp (full: VecVDlgMsdcNavLoainiDoImp)
		*/
	class VecVDoImp {

	public:
		static const uint BUTRUNCLICK = 1;
		static const uint BUTSTOCLICK = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
		* VecVSge (full: VecVDlgMsdcNavLoainiSge)
		*/
	class VecVSge {

	public:
		static const uint IDLE = 1;
		static const uint PRSIDLE = 2;
		static const uint PARSE = 3;
		static const uint ALRMSDCPER = 4;
		static const uint PRSDONE = 5;
		static const uint IMPIDLE = 6;
		static const uint IMPORT = 7;
		static const uint DONE = 8;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacDlgMsdcNavLoaini)
	  */
	class ContIac : public Block {

	public:
		static const uint NUMFDSE = 1;

	public:
		ContIac(const uint numFDse = 1);

	public:
		uint numFDse;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfDlgMsdcNavLoaini)
	  */
	class ContInf : public Block {

	public:
		static const uint NUMFSGE = 1;

	public:
		ContInf(const uint numFSge = 1);

	public:
		uint numFSge;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
	  * ContInfImp (full: ContInfDlgMsdcNavLoainiImp)
	  */
	class ContInfImp : public Block {

	public:
		static const uint TXTPRG = 1;

	public:
		ContInfImp(const string& TxtPrg = "");

	public:
		string TxtPrg;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const ContInfImp* comp);
		set<uint> diff(const ContInfImp* comp);
	};

	/**
	  * ContInfLfi (full: ContInfDlgMsdcNavLoainiLfi)
	  */
	class ContInfLfi : public Block {

	public:
		static const uint DLD = 1;

	public:
		ContInfLfi(const string& Dld = "file");

	public:
		string Dld;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const ContInfLfi* comp);
		set<uint> diff(const ContInfLfi* comp);
	};

	/**
	  * StatApp (full: StatAppDlgMsdcNavLoaini)
	  */
	class StatApp : public Block {

	public:
		static const uint INITDONE = 1;
		static const uint SHORTMENU = 2;

	public:
		StatApp(const bool initdone = false, const string& shortMenu = "");

	public:
		bool initdone;
		string shortMenu;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatApp* comp);
		set<uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrDlgMsdcNavLoaini)
	  */
	class StatShr : public Block {

	public:
		static const uint BUTDNEACTIVE = 1;

	public:
		StatShr(const bool ButDneActive = true);

	public:
		bool ButDneActive;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * StatShrIfi (full: StatShrDlgMsdcNavLoainiIfi)
	  */
	class StatShrIfi : public Block {

	public:
		static const uint ULDACTIVE = 1;

	public:
		StatShrIfi(const bool UldActive = true);

	public:
		bool UldActive;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShrIfi* comp);
		set<uint> diff(const StatShrIfi* comp);
	};

	/**
	  * StatShrImp (full: StatShrDlgMsdcNavLoainiImp)
	  */
	class StatShrImp : public Block {

	public:
		static const uint BUTRUNACTIVE = 1;
		static const uint BUTSTOACTIVE = 2;

	public:
		StatShrImp(const bool ButRunActive = true, const bool ButStoActive = true);

	public:
		bool ButRunActive;
		bool ButStoActive;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShrImp* comp);
		set<uint> diff(const StatShrImp* comp);
	};

	/**
	  * StatShrLfi (full: StatShrDlgMsdcNavLoainiLfi)
	  */
	class StatShrLfi : public Block {

	public:
		static const uint DLDACTIVE = 1;

	public:
		StatShrLfi(const bool DldActive = true);

	public:
		bool DldActive;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShrLfi* comp);
		set<uint> diff(const StatShrLfi* comp);
	};

	/**
	  * Tag (full: TagDlgMsdcNavLoaini)
	  */
	class Tag : public Block {

	public:
		static const uint CPT = 1;
		static const uint BUTDNE = 2;

	public:
		Tag(const string& Cpt = "", const string& ButDne = "");

	public:
		string Cpt;
		string ButDne;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
	  * TagIfi (full: TagDlgMsdcNavLoainiIfi)
	  */
	class TagIfi : public Block {

	public:
		static const uint ULD = 1;
		static const uint CPT = 2;

	public:
		TagIfi(const string& Uld = "", const string& Cpt = "");

	public:
		string Uld;
		string Cpt;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
	  * TagImp (full: TagDlgMsdcNavLoainiImp)
	  */
	class TagImp : public Block {

	public:
		static const uint CPTPRG = 1;
		static const uint BUTRUN = 2;
		static const uint BUTSTO = 3;

	public:
		TagImp(const string& CptPrg = "", const string& ButRun = "", const string& ButSto = "");

	public:
		string CptPrg;
		string ButRun;
		string ButSto;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
	  * TagLfi (full: TagDlgMsdcNavLoainiLfi)
	  */
	class TagLfi : public Block {

	public:
		static const uint DLD = 1;

	public:
		TagLfi(const string& Dld = "");

	public:
		string Dld;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppDlgMsdcNavLoainiData)
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
		* DpchAppDo (full: DpchAppDlgMsdcNavLoainiDo)
		*/
	class DpchAppDo : public DpchAppMsdc {

	public:
		static const uint SCRJREF = 1;
		static const uint IXVDO = 2;
		static const uint IXVDOIMP = 3;
		static const uint ALL = 4;

	public:
		DpchAppDo(const string& scrJref = "", const uint ixVDo = 0, const uint ixVDoImp = 0, const set<uint>& mask = {NONE});

	public:
		uint ixVDo;
		uint ixVDoImp;

	public:
		string getSrefsMask();

		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchEngData (full: DpchEngDlgMsdcNavLoainiData)
		*/
	class DpchEngData : public DpchEngMsdc {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTIAC = 2;
		static const uint CONTINF = 3;
		static const uint CONTINFIMP = 4;
		static const uint CONTINFLFI = 5;
		static const uint FEEDFDSE = 6;
		static const uint FEEDFSGE = 7;
		static const uint STATAPP = 8;
		static const uint STATSHR = 9;
		static const uint STATSHRIFI = 10;
		static const uint STATSHRIMP = 11;
		static const uint STATSHRLFI = 12;
		static const uint TAG = 13;
		static const uint TAGIFI = 14;
		static const uint TAGIMP = 15;
		static const uint TAGLFI = 16;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		ContInfImp continfimp;
		ContInfLfi continflfi;
		Feed feedFDse;
		Feed feedFSge;
		StatApp statapp;
		StatShr statshr;
		StatShrIfi statshrifi;
		StatShrImp statshrimp;
		StatShrLfi statshrlfi;
		Tag tag;
		TagIfi tagifi;
		TagImp tagimp;
		TagLfi taglfi;

	public:
		string getSrefsMask();

		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

