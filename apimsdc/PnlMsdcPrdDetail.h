/**
  * \file PnlMsdcPrdDetail.h
  * API code for job PnlMsdcPrdDetail (declarations)
  * \author Alexander Wirthmueller
  * \date created: 12 Sep 2018
  * \date modified: 12 Sep 2018
  */

#ifndef PNLMSDCPRDDETAIL_H
#define PNLMSDCPRDDETAIL_H

#include "ApiMsdc_blks.h"

#define VecVMsdcPrdDetailDo PnlMsdcPrdDetail::VecVDo

#define ContIacMsdcPrdDetail PnlMsdcPrdDetail::ContIac
#define StatAppMsdcPrdDetail PnlMsdcPrdDetail::StatApp
#define StatShrMsdcPrdDetail PnlMsdcPrdDetail::StatShr
#define TagMsdcPrdDetail PnlMsdcPrdDetail::Tag

#define DpchAppMsdcPrdDetailData PnlMsdcPrdDetail::DpchAppData
#define DpchAppMsdcPrdDetailDo PnlMsdcPrdDetail::DpchAppDo
#define DpchEngMsdcPrdDetailData PnlMsdcPrdDetail::DpchEngData

/**
  * PnlMsdcPrdDetail
  */
namespace PnlMsdcPrdDetail {
	/**
		* VecVDo (full: VecVMsdcPrdDetailDo)
		*/
	class VecVDo {

	public:
		static const uint BUTSAVECLICK = 1;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacMsdcPrdDetail)
	  */
	class ContIac : public Block {

	public:
		static const uint TXFSTA = 1;
		static const uint TXFSTO = 2;

	public:
		ContIac(const string& TxfSta = "", const string& TxfSto = "");

	public:
		string TxfSta;
		string TxfSto;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
	  * StatApp (full: StatAppMsdcPrdDetail)
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
	  * StatShr (full: StatShrMsdcPrdDetail)
	  */
	class StatShr : public Block {

	public:
		static const uint BUTSAVEAVAIL = 1;
		static const uint BUTSAVEACTIVE = 2;
		static const uint TXFSTAACTIVE = 3;
		static const uint TXFSTOACTIVE = 4;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxfStaActive = true, const bool TxfStoActive = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxfStaActive;
		bool TxfStoActive;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagMsdcPrdDetail)
	  */
	class Tag : public Block {

	public:
		static const uint CPT = 1;
		static const uint CPTSTA = 2;
		static const uint CPTSTO = 3;

	public:
		Tag(const string& Cpt = "", const string& CptSta = "", const string& CptSto = "");

	public:
		string Cpt;
		string CptSta;
		string CptSto;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppMsdcPrdDetailData)
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
		* DpchAppDo (full: DpchAppMsdcPrdDetailDo)
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
		* DpchEngData (full: DpchEngMsdcPrdDetailData)
		*/
	class DpchEngData : public DpchEngMsdc {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTIAC = 2;
		static const uint STATAPP = 3;
		static const uint STATSHR = 4;
		static const uint TAG = 5;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		string getSrefsMask();

		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

