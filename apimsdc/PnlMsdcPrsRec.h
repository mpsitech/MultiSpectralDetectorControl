/**
  * \file PnlMsdcPrsRec.h
  * API code for job PnlMsdcPrsRec (declarations)
  * \author Alexander Wirthmueller
  * \date created: 12 Sep 2018
  * \date modified: 12 Sep 2018
  */

#ifndef PNLMSDCPRSREC_H
#define PNLMSDCPRSREC_H

#include "ApiMsdc_blks.h"

#define VecVMsdcPrsRecDo PnlMsdcPrsRec::VecVDo

#define ContInfMsdcPrsRec PnlMsdcPrsRec::ContInf
#define StatAppMsdcPrsRec PnlMsdcPrsRec::StatApp
#define StatShrMsdcPrsRec PnlMsdcPrsRec::StatShr
#define TagMsdcPrsRec PnlMsdcPrsRec::Tag

#define DpchAppMsdcPrsRecDo PnlMsdcPrsRec::DpchAppDo
#define DpchEngMsdcPrsRecData PnlMsdcPrsRec::DpchEngData

/**
  * PnlMsdcPrsRec
  */
namespace PnlMsdcPrsRec {
	/**
		* VecVDo (full: VecVMsdcPrsRecDo)
		*/
	class VecVDo {

	public:
		static const uint BUTMINIMIZECLICK = 1;
		static const uint BUTREGULARIZECLICK = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContInf (full: ContInfMsdcPrsRec)
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
	  * StatApp (full: StatAppMsdcPrsRec)
	  */
	class StatApp : public Block {

	public:
		static const uint INITDONEDETAIL = 1;

	public:
		StatApp(const bool initdoneDetail = false);

	public:
		bool initdoneDetail;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatApp* comp);
		set<uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrMsdcPrsRec)
	  */
	class StatShr : public Block {

	public:
		static const uint IXMSDCVEXPSTATE = 1;
		static const uint SCRJREFDETAIL = 2;
		static const uint BUTREGULARIZEACTIVE = 3;

	public:
		StatShr(const uint ixMsdcVExpstate = VecMsdcVExpstate::REGD, const string& scrJrefDetail = "", const bool ButRegularizeActive = true);

	public:
		uint ixMsdcVExpstate;
		ubigint jrefDetail;
		bool ButRegularizeActive;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagMsdcPrsRec)
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
		* DpchAppDo (full: DpchAppMsdcPrsRecDo)
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
		* DpchEngData (full: DpchEngMsdcPrsRecData)
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

