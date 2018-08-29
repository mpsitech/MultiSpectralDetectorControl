/**
  * \file PnlMsdcUsgAAccess.h
  * API code for job PnlMsdcUsgAAccess (declarations)
  * \author Alexander Wirthmueller
  * \date created: 29 Aug 2018
  * \date modified: 29 Aug 2018
  */

#ifndef PNLMSDCUSGAACCESS_H
#define PNLMSDCUSGAACCESS_H

#include "ApiMsdc_blks.h"

#include "MsdcQUsgAAccess.h"

#include "QryMsdcUsgAAccess.h"

#define VecVMsdcUsgAAccessDo PnlMsdcUsgAAccess::VecVDo

#define ContInfMsdcUsgAAccess PnlMsdcUsgAAccess::ContInf
#define StatAppMsdcUsgAAccess PnlMsdcUsgAAccess::StatApp
#define StatShrMsdcUsgAAccess PnlMsdcUsgAAccess::StatShr
#define StgIacMsdcUsgAAccess PnlMsdcUsgAAccess::StgIac
#define TagMsdcUsgAAccess PnlMsdcUsgAAccess::Tag

#define DpchAppMsdcUsgAAccessData PnlMsdcUsgAAccess::DpchAppData
#define DpchAppMsdcUsgAAccessDo PnlMsdcUsgAAccess::DpchAppDo
#define DpchEngMsdcUsgAAccessData PnlMsdcUsgAAccess::DpchEngData

/**
  * PnlMsdcUsgAAccess
  */
namespace PnlMsdcUsgAAccess {
	/**
		* VecVDo (full: VecVMsdcUsgAAccessDo)
		*/
	class VecVDo {

	public:
		static const uint BUTNEWCLICK = 1;
		static const uint BUTDUPLICATECLICK = 2;
		static const uint BUTDELETECLICK = 3;
		static const uint BUTREFRESHCLICK = 4;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContInf (full: ContInfMsdcUsgAAccess)
	  */
	class ContInf : public Block {

	public:
		static const uint NUMFCSIQST = 1;

	public:
		ContInf(const uint numFCsiQst = 1);

	public:
		uint numFCsiQst;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppMsdcUsgAAccess)
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
	  * StatShr (full: StatShrMsdcUsgAAccess)
	  */
	class StatShr : public Block {

	public:
		static const uint BUTNEWAVAIL = 1;
		static const uint BUTDUPLICATEAVAIL = 2;
		static const uint BUTDUPLICATEACTIVE = 3;
		static const uint BUTDELETEAVAIL = 4;
		static const uint BUTDELETEACTIVE = 5;

	public:
		StatShr(const bool ButNewAvail = true, const bool ButDuplicateAvail = true, const bool ButDuplicateActive = true, const bool ButDeleteAvail = true, const bool ButDeleteActive = true);

	public:
		bool ButNewAvail;
		bool ButDuplicateAvail;
		bool ButDuplicateActive;
		bool ButDeleteAvail;
		bool ButDeleteActive;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * StgIac (full: StgIacMsdcUsgAAccess)
	  */
	class StgIac : public Block {

	public:
		static const uint TCOFEGWIDTH = 1;
		static const uint TCOFEAWIDTH = 2;
		static const uint TCOACCWIDTH = 3;

	public:
		StgIac(const uint TcoFegWidth = 100, const uint TcoFeaWidth = 100, const uint TcoAccWidth = 100);

	public:
		uint TcoFegWidth;
		uint TcoFeaWidth;
		uint TcoAccWidth;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StgIac* comp);
		set<uint> diff(const StgIac* comp);
	};

	/**
	  * Tag (full: TagMsdcUsgAAccess)
	  */
	class Tag : public Block {

	public:
		static const uint CPT = 1;
		static const uint TRS = 2;
		static const uint TXTSHOWING1 = 3;
		static const uint TXTSHOWING2 = 4;
		static const uint TCOFEG = 5;
		static const uint TCOFEA = 6;
		static const uint TCOACC = 7;

	public:
		Tag(const string& Cpt = "", const string& Trs = "", const string& TxtShowing1 = "", const string& TxtShowing2 = "", const string& TcoFeg = "", const string& TcoFea = "", const string& TcoAcc = "");

	public:
		string Cpt;
		string Trs;
		string TxtShowing1;
		string TxtShowing2;
		string TcoFeg;
		string TcoFea;
		string TcoAcc;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppMsdcUsgAAccessData)
		*/
	class DpchAppData : public DpchAppMsdc {

	public:
		static const uint SCRJREF = 1;
		static const uint STGIAC = 2;
		static const uint STGIACQRY = 3;
		static const uint ALL = 4;

	public:
		DpchAppData(const string& scrJref = "", StgIac* stgiac = NULL, QryMsdcUsgAAccess::StgIac* stgiacqry = NULL, const set<uint>& mask = {NONE});

	public:
		StgIac stgiac;
		QryMsdcUsgAAccess::StgIac stgiacqry;

	public:
		string getSrefsMask();

		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchAppDo (full: DpchAppMsdcUsgAAccessDo)
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
		* DpchEngData (full: DpchEngMsdcUsgAAccessData)
		*/
	class DpchEngData : public DpchEngMsdc {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTINF = 2;
		static const uint FEEDFCSIQST = 3;
		static const uint STATAPP = 4;
		static const uint STATSHR = 5;
		static const uint STGIAC = 6;
		static const uint TAG = 7;
		static const uint RST = 8;
		static const uint STATAPPQRY = 9;
		static const uint STATSHRQRY = 10;
		static const uint STGIACQRY = 11;

	public:
		DpchEngData();

	public:
		ContInf continf;
		Feed feedFCsiQst;
		StatApp statapp;
		StatShr statshr;
		StgIac stgiac;
		Tag tag;
		ListMsdcQUsgAAccess rst;
		QryMsdcUsgAAccess::StatApp statappqry;
		QryMsdcUsgAAccess::StatShr statshrqry;
		QryMsdcUsgAAccess::StgIac stgiacqry;

	public:
		string getSrefsMask();

		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

