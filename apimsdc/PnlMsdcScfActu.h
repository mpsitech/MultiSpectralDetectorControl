/**
  * \file PnlMsdcScfActu.h
  * API code for job PnlMsdcScfActu (declarations)
  * \author Alexander Wirthmueller
  * \date created: 12 Sep 2018
  * \date modified: 12 Sep 2018
  */

#ifndef PNLMSDCSCFACTU_H
#define PNLMSDCSCFACTU_H

#include "ApiMsdc_blks.h"

#define VecVMsdcScfActuDo PnlMsdcScfActu::VecVDo

#define ContIacMsdcScfActu PnlMsdcScfActu::ContIac
#define ContInfMsdcScfActu PnlMsdcScfActu::ContInf
#define StatAppMsdcScfActu PnlMsdcScfActu::StatApp
#define StatShrMsdcScfActu PnlMsdcScfActu::StatShr
#define TagMsdcScfActu PnlMsdcScfActu::Tag

#define DpchAppMsdcScfActuData PnlMsdcScfActu::DpchAppData
#define DpchAppMsdcScfActuDo PnlMsdcScfActu::DpchAppDo
#define DpchEngMsdcScfActuData PnlMsdcScfActu::DpchEngData

/**
  * PnlMsdcScfActu
  */
namespace PnlMsdcScfActu {
	/**
		* VecVDo (full: VecVMsdcScfActuDo)
		*/
	class VecVDo {

	public:
		static const uint BUTMASTERCLICK = 1;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacMsdcScfActu)
	  */
	class ContIac : public Block {

	public:
		static const uint SLDSTM = 1;
		static const uint SLDSTX = 2;
		static const uint SLDSPM = 3;
		static const uint SLDSPX = 4;

	public:
		ContIac(const double SldStm = 0.0, const double SldStx = 0.0, const double SldSpm = 0.0, const double SldSpx = 0.0);

	public:
		double SldStm;
		double SldStx;
		double SldSpm;
		double SldSpx;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfMsdcScfActu)
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
	  * StatApp (full: StatAppMsdcScfActu)
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
	  * StatShr (full: StatShrMsdcScfActu)
	  */
	class StatShr : public Block {

	public:
		static const uint SLDSTMMIN = 1;
		static const uint SLDSTMMAX = 2;
		static const uint SLDSTMRAST = 3;
		static const uint SLDSTXMIN = 4;
		static const uint SLDSTXMAX = 5;
		static const uint SLDSTXRAST = 6;
		static const uint SLDSPMMIN = 7;
		static const uint SLDSPMMAX = 8;
		static const uint SLDSPMRAST = 9;
		static const uint SLDSPXMIN = 10;
		static const uint SLDSPXMAX = 11;
		static const uint SLDSPXRAST = 12;

	public:
		StatShr(const double SldStmMin = -60.0, const double SldStmMax = 60.0, const double SldStmRast = 0.1, const double SldStxMin = -60.0, const double SldStxMax = 60.0, const double SldStxRast = 0.1, const double SldSpmMin = -60.0, const double SldSpmMax = 60.0, const double SldSpmRast = 0.1, const double SldSpxMin = -60.0, const double SldSpxMax = 60.0, const double SldSpxRast = 0.1);

	public:
		double SldStmMin;
		double SldStmMax;
		double SldStmRast;
		double SldStxMin;
		double SldStxMax;
		double SldStxRast;
		double SldSpmMin;
		double SldSpmMax;
		double SldSpmRast;
		double SldSpxMin;
		double SldSpxMax;
		double SldSpxRast;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagMsdcScfActu)
	  */
	class Tag : public Block {

	public:
		static const uint CPT = 1;
		static const uint HDGSRV = 2;
		static const uint CPTSTM = 3;
		static const uint CPTSTX = 4;
		static const uint CPTSPM = 5;
		static const uint CPTSPX = 6;

	public:
		Tag(const string& Cpt = "", const string& HdgSrv = "", const string& CptStm = "", const string& CptStx = "", const string& CptSpm = "", const string& CptSpx = "");

	public:
		string Cpt;
		string HdgSrv;
		string CptStm;
		string CptStx;
		string CptSpm;
		string CptSpx;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppMsdcScfActuData)
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
		* DpchAppDo (full: DpchAppMsdcScfActuDo)
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
		* DpchEngData (full: DpchEngMsdcScfActuData)
		*/
	class DpchEngData : public DpchEngMsdc {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTIAC = 2;
		static const uint CONTINF = 3;
		static const uint STATAPP = 4;
		static const uint STATSHR = 5;
		static const uint TAG = 6;

	public:
		DpchEngData();

	public:
		ContIac contiac;
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

