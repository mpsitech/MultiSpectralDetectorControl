/**
  * \file PnlMsdcPrsList.h
  * API code for job PnlMsdcPrsList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 18 Dec 2018
  * \date modified: 18 Dec 2018
  */

#ifndef PNLMSDCPRSLIST_H
#define PNLMSDCPRSLIST_H

#include "ApiMsdc_blks.h"

#include "MsdcQPrsList.h"

#include "QryMsdcPrsList.h"

#define VecVMsdcPrsListDo PnlMsdcPrsList::VecVDo

#define ContIacMsdcPrsList PnlMsdcPrsList::ContIac
#define ContInfMsdcPrsList PnlMsdcPrsList::ContInf
#define StatShrMsdcPrsList PnlMsdcPrsList::StatShr
#define StgIacMsdcPrsList PnlMsdcPrsList::StgIac
#define TagMsdcPrsList PnlMsdcPrsList::Tag

#define DpchAppMsdcPrsListData PnlMsdcPrsList::DpchAppData
#define DpchAppMsdcPrsListDo PnlMsdcPrsList::DpchAppDo
#define DpchEngMsdcPrsListData PnlMsdcPrsList::DpchEngData

/**
  * PnlMsdcPrsList
  */
namespace PnlMsdcPrsList {
	/**
		* VecVDo (full: VecVMsdcPrsListDo)
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
	  * ContIac (full: ContIacMsdcPrsList)
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
	  * ContInf (full: ContInfMsdcPrsList)
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
	  * StatShr (full: StatShrMsdcPrsList)
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
	  * StgIac (full: StgIacMsdcPrsList)
	  */
	class StgIac : public Block {

	public:
		static const uint TCOTITWIDTH = 1;
		static const uint TCOFNMWIDTH = 2;
		static const uint TCOLNMWIDTH = 3;
		static const uint TCOGRPWIDTH = 4;
		static const uint TCOOWNWIDTH = 5;
		static const uint TCOSEXWIDTH = 6;
		static const uint TCOTELWIDTH = 7;
		static const uint TCOEMLWIDTH = 8;

	public:
		StgIac(const uint TcoTitWidth = 100, const uint TcoFnmWidth = 100, const uint TcoLnmWidth = 100, const uint TcoGrpWidth = 100, const uint TcoOwnWidth = 100, const uint TcoSexWidth = 100, const uint TcoTelWidth = 100, const uint TcoEmlWidth = 100);

	public:
		uint TcoTitWidth;
		uint TcoFnmWidth;
		uint TcoLnmWidth;
		uint TcoGrpWidth;
		uint TcoOwnWidth;
		uint TcoSexWidth;
		uint TcoTelWidth;
		uint TcoEmlWidth;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StgIac* comp);
		set<uint> diff(const StgIac* comp);
	};

	/**
	  * Tag (full: TagMsdcPrsList)
	  */
	class Tag : public Block {

	public:
		static const uint CPT = 1;
		static const uint TRS = 2;
		static const uint TXTSHOWING1 = 3;
		static const uint TXTSHOWING2 = 4;
		static const uint TCOTIT = 5;
		static const uint TCOFNM = 6;
		static const uint TCOLNM = 7;
		static const uint TCOGRP = 8;
		static const uint TCOOWN = 9;
		static const uint TCOSEX = 10;
		static const uint TCOTEL = 11;
		static const uint TCOEML = 12;

	public:
		Tag(const string& Cpt = "", const string& Trs = "", const string& TxtShowing1 = "", const string& TxtShowing2 = "", const string& TcoTit = "", const string& TcoFnm = "", const string& TcoLnm = "", const string& TcoGrp = "", const string& TcoOwn = "", const string& TcoSex = "", const string& TcoTel = "", const string& TcoEml = "");

	public:
		string Cpt;
		string Trs;
		string TxtShowing1;
		string TxtShowing2;
		string TcoTit;
		string TcoFnm;
		string TcoLnm;
		string TcoGrp;
		string TcoOwn;
		string TcoSex;
		string TcoTel;
		string TcoEml;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppMsdcPrsListData)
		*/
	class DpchAppData : public DpchAppMsdc {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTIAC = 2;
		static const uint STGIAC = 3;
		static const uint STGIACQRY = 4;
		static const uint ALL = 5;

	public:
		DpchAppData(const string& scrJref = "", ContIac* contiac = NULL, StgIac* stgiac = NULL, QryMsdcPrsList::StgIac* stgiacqry = NULL, const set<uint>& mask = {NONE});

	public:
		ContIac contiac;
		StgIac stgiac;
		QryMsdcPrsList::StgIac stgiacqry;

	public:
		string getSrefsMask();

		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchAppDo (full: DpchAppMsdcPrsListDo)
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
		* DpchEngData (full: DpchEngMsdcPrsListData)
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
		ListMsdcQPrsList rst;
		QryMsdcPrsList::StatApp statappqry;
		QryMsdcPrsList::StatShr statshrqry;
		QryMsdcPrsList::StgIac stgiacqry;

	public:
		string getSrefsMask();

		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

