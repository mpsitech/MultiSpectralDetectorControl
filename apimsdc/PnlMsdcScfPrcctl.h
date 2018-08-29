/**
  * \file PnlMsdcScfPrcctl.h
  * API code for job PnlMsdcScfPrcctl (declarations)
  * \author Alexander Wirthmueller
  * \date created: 29 Aug 2018
  * \date modified: 29 Aug 2018
  */

#ifndef PNLMSDCSCFPRCCTL_H
#define PNLMSDCSCFPRCCTL_H

#include "ApiMsdc_blks.h"

#define VecVMsdcScfPrcctlDo PnlMsdcScfPrcctl::VecVDo

#define ContInfMsdcScfPrcctl PnlMsdcScfPrcctl::ContInf
#define StatAppMsdcScfPrcctl PnlMsdcScfPrcctl::StatApp
#define TagMsdcScfPrcctl PnlMsdcScfPrcctl::Tag

#define DpchAppMsdcScfPrcctlDo PnlMsdcScfPrcctl::DpchAppDo
#define DpchEngMsdcScfPrcctlData PnlMsdcScfPrcctl::DpchEngData

/**
  * PnlMsdcScfPrcctl
  */
namespace PnlMsdcScfPrcctl {
	/**
		* VecVDo (full: VecVMsdcScfPrcctlDo)
		*/
	class VecVDo {

	public:
		static const uint BUTMASTERCLICK = 1;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContInf (full: ContInfMsdcScfPrcctl)
	  */
	class ContInf : public Block {

	public:
		static const uint BUTMASTERON = 1;

	public:
		ContInf(const bool ButMasterOn = false);

	public:
		bool ButMasterOn;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppMsdcScfPrcctl)
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
	  * Tag (full: TagMsdcScfPrcctl)
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
		* DpchAppDo (full: DpchAppMsdcScfPrcctlDo)
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
		* DpchEngData (full: DpchEngMsdcScfPrcctlData)
		*/
	class DpchEngData : public DpchEngMsdc {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTINF = 2;
		static const uint STATAPP = 3;
		static const uint TAG = 4;

	public:
		DpchEngData();

	public:
		ContInf continf;
		StatApp statapp;
		Tag tag;

	public:
		string getSrefsMask();

		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

