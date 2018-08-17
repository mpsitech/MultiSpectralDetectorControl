/**
  * \file PnlMsdcFilList.h
  * API code for job PnlMsdcFilList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 15 Aug 2018
  * \date modified: 15 Aug 2018
  */

#ifndef PNLMSDCFILLIST_H
#define PNLMSDCFILLIST_H

#include "ApiMsdc_blks.h"

#include "MsdcQFilList.h"

#include "QryMsdcFilList.h"

#define VecVMsdcFilListDo PnlMsdcFilList::VecVDo

#define ContIacMsdcFilList PnlMsdcFilList::ContIac
#define ContInfMsdcFilList PnlMsdcFilList::ContInf
#define StatShrMsdcFilList PnlMsdcFilList::StatShr
#define StgIacMsdcFilList PnlMsdcFilList::StgIac
#define TagMsdcFilList PnlMsdcFilList::Tag

#define DpchAppMsdcFilListData PnlMsdcFilList::DpchAppData
#define DpchAppMsdcFilListDo PnlMsdcFilList::DpchAppDo
#define DpchEngMsdcFilListData PnlMsdcFilList::DpchEngData

/**
  * PnlMsdcFilList
  */
namespace PnlMsdcFilList {
	/**
		* VecVDo (full: VecVMsdcFilListDo)
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
	  * ContIac (full: ContIacMsdcFilList)
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
	  * ContInf (full: ContInfMsdcFilList)
	  */
	class ContInf : public Block {

	public:
		static const uint TXTFOR = 1;
		static const uint TXTPRE = 2;
		static const uint BUTFILTERON = 3;
		static const uint NUMFCSIQST = 4;

	public:
		ContInf(const string& TxtFor = "", const string& TxtPre = "", const bool ButFilterOn = false, const uint numFCsiQst = 1);

	public:
		string TxtFor;
		string TxtPre;
		bool ButFilterOn;
		uint numFCsiQst;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
	  * StatShr (full: StatShrMsdcFilList)
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
	  * StgIac (full: StgIacMsdcFilList)
	  */
	class StgIac : public Block {

	public:
		static const uint TCOFNMWIDTH = 1;
		static const uint TCORETWIDTH = 2;
		static const uint TCOREUWIDTH = 3;
		static const uint TCOCNTWIDTH = 4;
		static const uint TCOMIMWIDTH = 5;
		static const uint TCOSIZWIDTH = 6;

	public:
		StgIac(const uint TcoFnmWidth = 150, const uint TcoRetWidth = 125, const uint TcoReuWidth = 200, const uint TcoCntWidth = 200, const uint TcoMimWidth = 200, const uint TcoSizWidth = 100);

	public:
		uint TcoFnmWidth;
		uint TcoRetWidth;
		uint TcoReuWidth;
		uint TcoCntWidth;
		uint TcoMimWidth;
		uint TcoSizWidth;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StgIac* comp);
		set<uint> diff(const StgIac* comp);
	};

	/**
	  * Tag (full: TagMsdcFilList)
	  */
	class Tag : public Block {

	public:
		static const uint CPT = 1;
		static const uint TXTFOR = 2;
		static const uint TRS = 3;
		static const uint TXTSHOWING1 = 4;
		static const uint TXTSHOWING2 = 5;
		static const uint TCOFNM = 6;
		static const uint TCORET = 7;
		static const uint TCOREU = 8;
		static const uint TCOCNT = 9;
		static const uint TCOMIM = 10;
		static const uint TCOSIZ = 11;

	public:
		Tag(const string& Cpt = "", const string& TxtFor = "", const string& Trs = "", const string& TxtShowing1 = "", const string& TxtShowing2 = "", const string& TcoFnm = "", const string& TcoRet = "", const string& TcoReu = "", const string& TcoCnt = "", const string& TcoMim = "", const string& TcoSiz = "");

	public:
		string Cpt;
		string TxtFor;
		string Trs;
		string TxtShowing1;
		string TxtShowing2;
		string TcoFnm;
		string TcoRet;
		string TcoReu;
		string TcoCnt;
		string TcoMim;
		string TcoSiz;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppMsdcFilListData)
		*/
	class DpchAppData : public DpchAppMsdc {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTIAC = 2;
		static const uint STGIAC = 3;
		static const uint STGIACQRY = 4;
		static const uint ALL = 5;

	public:
		DpchAppData(const string& scrJref = "", ContIac* contiac = NULL, StgIac* stgiac = NULL, QryMsdcFilList::StgIac* stgiacqry = NULL, const set<uint>& mask = {NONE});

	public:
		ContIac contiac;
		StgIac stgiac;
		QryMsdcFilList::StgIac stgiacqry;

	public:
		string getSrefsMask();

		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchAppDo (full: DpchAppMsdcFilListDo)
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
		* DpchEngData (full: DpchEngMsdcFilListData)
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
		ListMsdcQFilList rst;
		QryMsdcFilList::StatApp statappqry;
		QryMsdcFilList::StatShr statshrqry;
		QryMsdcFilList::StgIac stgiacqry;

	public:
		string getSrefsMask();

		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

