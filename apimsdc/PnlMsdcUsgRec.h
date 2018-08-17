/**
  * \file PnlMsdcUsgRec.h
  * API code for job PnlMsdcUsgRec (declarations)
  * \author Alexander Wirthmueller
  * \date created: 15 Aug 2018
  * \date modified: 15 Aug 2018
  */

#ifndef PNLMSDCUSGREC_H
#define PNLMSDCUSGREC_H

#include "ApiMsdc_blks.h"

#define VecVMsdcUsgRecDo PnlMsdcUsgRec::VecVDo

#define ContInfMsdcUsgRec PnlMsdcUsgRec::ContInf
#define StatAppMsdcUsgRec PnlMsdcUsgRec::StatApp
#define StatShrMsdcUsgRec PnlMsdcUsgRec::StatShr
#define TagMsdcUsgRec PnlMsdcUsgRec::Tag

#define DpchAppMsdcUsgRecDo PnlMsdcUsgRec::DpchAppDo
#define DpchEngMsdcUsgRecData PnlMsdcUsgRec::DpchEngData

/**
  * PnlMsdcUsgRec
  */
namespace PnlMsdcUsgRec {
	/**
		* VecVDo (full: VecVMsdcUsgRecDo)
		*/
	class VecVDo {

	public:
		static const uint BUTMINIMIZECLICK = 1;
		static const uint BUTREGULARIZECLICK = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContInf (full: ContInfMsdcUsgRec)
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
	  * StatApp (full: StatAppMsdcUsgRec)
	  */
	class StatApp : public Block {

	public:
		static const uint INITDONEDETAIL = 1;
		static const uint INITDONEAACCESS = 2;
		static const uint INITDONEMNUSER = 3;

	public:
		StatApp(const bool initdoneDetail = false, const bool initdoneAAccess = false, const bool initdoneMNUser = false);

	public:
		bool initdoneDetail;
		bool initdoneAAccess;
		bool initdoneMNUser;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatApp* comp);
		set<uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrMsdcUsgRec)
	  */
	class StatShr : public Block {

	public:
		static const uint IXMSDCVEXPSTATE = 1;
		static const uint SCRJREFDETAIL = 2;
		static const uint SCRJREFAACCESS = 3;
		static const uint SCRJREFMNUSER = 4;
		static const uint BUTREGULARIZEACTIVE = 5;

	public:
		StatShr(const uint ixMsdcVExpstate = VecMsdcVExpstate::REGD, const string& scrJrefDetail = "", const string& scrJrefAAccess = "", const string& scrJrefMNUser = "", const bool ButRegularizeActive = true);

	public:
		uint ixMsdcVExpstate;
		ubigint jrefDetail;
		ubigint jrefAAccess;
		ubigint jrefMNUser;
		bool ButRegularizeActive;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagMsdcUsgRec)
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
		* DpchAppDo (full: DpchAppMsdcUsgRecDo)
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
		* DpchEngData (full: DpchEngMsdcUsgRecData)
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

