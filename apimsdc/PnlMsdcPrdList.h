/**
  * \file PnlMsdcPrdList.h
  * API code for job PnlMsdcPrdList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 29 Aug 2018
  * \date modified: 29 Aug 2018
  */

#ifndef PNLMSDCPRDLIST_H
#define PNLMSDCPRDLIST_H

#include "ApiMsdc_blks.h"

#include "MsdcQPrdList.h"

#include "QryMsdcPrdList.h"

#define VecVMsdcPrdListDo PnlMsdcPrdList::VecVDo

#define ContIacMsdcPrdList PnlMsdcPrdList::ContIac
#define ContInfMsdcPrdList PnlMsdcPrdList::ContInf
#define StatShrMsdcPrdList PnlMsdcPrdList::StatShr
#define StgIacMsdcPrdList PnlMsdcPrdList::StgIac
#define TagMsdcPrdList PnlMsdcPrdList::Tag

#define DpchAppMsdcPrdListData PnlMsdcPrdList::DpchAppData
#define DpchAppMsdcPrdListDo PnlMsdcPrdList::DpchAppDo
#define DpchEngMsdcPrdListData PnlMsdcPrdList::DpchEngData

/**
  * PnlMsdcPrdList
  */
namespace PnlMsdcPrdList {
	/**
		* VecVDo (full: VecVMsdcPrdListDo)
		*/
	class VecVDo {

	public:
		static const uint BUTMINIMIZECLICK = 1;
		static const uint BUTREGULARIZECLICK = 2;
		static const uint BUTNEWCLICK = 3;
		static const uint BUTDELETECLICK = 4;
		static const uint BUTFILTERCLICK = 5;
		static const uint BUTREFRESHCLICK = 6;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacMsdcPrdList)
	  */
	class ContIac : public Block {

	public:
		static const uint NUMFTOS = 1;

	public:
		ContIac(const uint numFTos = 1);

	public:
		uint numFTos;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfMsdcPrdList)
	  */
	class ContInf : public Block {

	public:
		static const uint BUTFILTERON = 1;
		static const uint NUMFCSIQST = 2;

	public:
		ContInf(const bool ButFilterOn = false, const uint numFCsiQst = 1);

	public:
		bool ButFilterOn;
		uint numFCsiQst;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
	  * StatShr (full: StatShrMsdcPrdList)
	  */
	class StatShr : public Block {

	public:
		static const uint IXMSDCVEXPSTATE = 1;
		static const uint BUTDELETEACTIVE = 2;

	public:
		StatShr(const uint ixMsdcVExpstate = VecMsdcVExpstate::MIND, const bool ButDeleteActive = true);

	public:
		uint ixMsdcVExpstate;
		bool ButDeleteActive;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * StgIac (full: StgIacMsdcPrdList)
	  */
	class StgIac : public Block {

	public:
		static const uint TCOSTAWIDTH = 1;
		static const uint TCOSTOWIDTH = 2;

	public:
		StgIac(const uint TcoStaWidth = 150, const uint TcoStoWidth = 150);

	public:
		uint TcoStaWidth;
		uint TcoStoWidth;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StgIac* comp);
		set<uint> diff(const StgIac* comp);
	};

	/**
	  * Tag (full: TagMsdcPrdList)
	  */
	class Tag : public Block {

	public:
		static const uint CPT = 1;
		static const uint TRS = 2;
		static const uint TXTSHOWING1 = 3;
		static const uint TXTSHOWING2 = 4;
		static const uint TCOSTA = 5;
		static const uint TCOSTO = 6;

	public:
		Tag(const string& Cpt = "", const string& Trs = "", const string& TxtShowing1 = "", const string& TxtShowing2 = "", const string& TcoSta = "", const string& TcoSto = "");

	public:
		string Cpt;
		string Trs;
		string TxtShowing1;
		string TxtShowing2;
		string TcoSta;
		string TcoSto;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppMsdcPrdListData)
		*/
	class DpchAppData : public DpchAppMsdc {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTIAC = 2;
		static const uint STGIAC = 3;
		static const uint STGIACQRY = 4;
		static const uint ALL = 5;

	public:
		DpchAppData(const string& scrJref = "", ContIac* contiac = NULL, StgIac* stgiac = NULL, QryMsdcPrdList::StgIac* stgiacqry = NULL, const set<uint>& mask = {NONE});

	public:
		ContIac contiac;
		StgIac stgiac;
		QryMsdcPrdList::StgIac stgiacqry;

	public:
		string getSrefsMask();

		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchAppDo (full: DpchAppMsdcPrdListDo)
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
		* DpchEngData (full: DpchEngMsdcPrdListData)
		*/
	class DpchEngData : public DpchEngMsdc {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTIAC = 2;
		static const uint CONTINF = 3;
		static const uint FEEDFCSIQST = 4;
		static const uint FEEDFTOS = 5;
		static const uint STATSHR = 6;
		static const uint STGIAC = 7;
		static const uint TAG = 8;
		static const uint RST = 9;
		static const uint STATAPPQRY = 10;
		static const uint STATSHRQRY = 11;
		static const uint STGIACQRY = 12;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Feed feedFCsiQst;
		Feed feedFTos;
		StatShr statshr;
		StgIac stgiac;
		Tag tag;
		ListMsdcQPrdList rst;
		QryMsdcPrdList::StatApp statappqry;
		QryMsdcPrdList::StatShr statshrqry;
		QryMsdcPrdList::StgIac stgiacqry;

	public:
		string getSrefsMask();

		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

