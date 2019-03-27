/**
  * \file PnlMsdcPrdRec.h
  * API code for job PnlMsdcPrdRec (declarations)
  * \author Alexander Wirthmueller
  * \date created: 18 Dec 2018
  * \date modified: 18 Dec 2018
  */

#ifndef PNLMSDCPRDREC_H
#define PNLMSDCPRDREC_H

#include "ApiMsdc_blks.h"

#define VecVMsdcPrdRecDo PnlMsdcPrdRec::VecVDo

#define ContInfMsdcPrdRec PnlMsdcPrdRec::ContInf
#define StatAppMsdcPrdRec PnlMsdcPrdRec::StatApp
#define StatShrMsdcPrdRec PnlMsdcPrdRec::StatShr
#define TagMsdcPrdRec PnlMsdcPrdRec::Tag

#define DpchAppMsdcPrdRecDo PnlMsdcPrdRec::DpchAppDo
#define DpchEngMsdcPrdRecData PnlMsdcPrdRec::DpchEngData

/**
  * PnlMsdcPrdRec
  */
namespace PnlMsdcPrdRec {
	/**
		* VecVDo (full: VecVMsdcPrdRecDo)
		*/
	class VecVDo {

	public:
		static const uint BUTMINIMIZECLICK = 1;
		static const uint BUTREGULARIZECLICK = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContInf (full: ContInfMsdcPrdRec)
	  */
	class ContInf : public Block {

	public:
		static const uint TXTREF = 1;

	public:
		ContInf(const string& TxtRef = "");

	public:
		string TxtRef;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppMsdcPrdRec)
	  */
	class StatApp : public Block {

	public:
		static const uint INITDONEDETAIL = 1;
		static const uint INITDONE1NDATA = 2;

	public:
		StatApp(const bool initdoneDetail = false, const bool initdone1NData = false);

	public:
		bool initdoneDetail;
		bool initdone1NData;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatApp* comp);
		set<uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrMsdcPrdRec)
	  */
	class StatShr : public Block {

	public:
		static const uint IXMSDCVEXPSTATE = 1;
		static const uint SCRJREFDETAIL = 2;
		static const uint SCRJREF1NDATA = 3;
		static const uint BUTREGULARIZEACTIVE = 4;

	public:
		StatShr(const uint ixMsdcVExpstate = VecMsdcVExpstate::REGD, const string& scrJrefDetail = "", const string& scrJref1NData = "", const bool ButRegularizeActive = true);

	public:
		uint ixMsdcVExpstate;
		string scrJrefDetail;
		string scrJref1NData;
		bool ButRegularizeActive;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagMsdcPrdRec)
	  */
	class Tag : public Block {

	public:
		static const uint CPT = 1;

	public:
		Tag(const string& Cpt = "");

	public:
		string Cpt;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppMsdcPrdRecDo)
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
		* DpchEngData (full: DpchEngMsdcPrdRecData)
		*/
	class DpchEngData : public DpchEngMsdc {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTINF = 2;
		static const uint STATAPP = 3;
		static const uint STATSHR = 4;
		static const uint TAG = 5;

	public:
		DpchEngData();

	public:
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

