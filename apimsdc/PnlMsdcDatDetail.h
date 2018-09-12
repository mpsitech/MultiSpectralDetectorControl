/**
  * \file PnlMsdcDatDetail.h
  * API code for job PnlMsdcDatDetail (declarations)
  * \author Alexander Wirthmueller
  * \date created: 12 Sep 2018
  * \date modified: 12 Sep 2018
  */

#ifndef PNLMSDCDATDETAIL_H
#define PNLMSDCDATDETAIL_H

#include "ApiMsdc_blks.h"

#define VecVMsdcDatDetailDo PnlMsdcDatDetail::VecVDo

#define ContIacMsdcDatDetail PnlMsdcDatDetail::ContIac
#define ContInfMsdcDatDetail PnlMsdcDatDetail::ContInf
#define StatAppMsdcDatDetail PnlMsdcDatDetail::StatApp
#define StatShrMsdcDatDetail PnlMsdcDatDetail::StatShr
#define TagMsdcDatDetail PnlMsdcDatDetail::Tag

#define DpchAppMsdcDatDetailData PnlMsdcDatDetail::DpchAppData
#define DpchAppMsdcDatDetailDo PnlMsdcDatDetail::DpchAppDo
#define DpchEngMsdcDatDetailData PnlMsdcDatDetail::DpchEngData

/**
  * PnlMsdcDatDetail
  */
namespace PnlMsdcDatDetail {
	/**
		* VecVDo (full: VecVMsdcDatDetailDo)
		*/
	class VecVDo {

	public:
		static const uint BUTSAVECLICK = 1;
		static const uint BUTAFTEDITCLICK = 2;
		static const uint BUTPRDVIEWCLICK = 3;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacMsdcDatDetail)
	  */
	class ContIac : public Block {

	public:
		static const uint NUMFPUPAFT = 1;
		static const uint TXFAFT = 2;
		static const uint TXFSTA = 3;
		static const uint TXFSTO = 4;
		static const uint TXFCMT = 5;

	public:
		ContIac(const uint numFPupAft = 1, const string& TxfAft = "", const string& TxfSta = "", const string& TxfSto = "", const string& TxfCmt = "");

	public:
		uint numFPupAft;
		string TxfAft;
		string TxfSta;
		string TxfSto;
		string TxfCmt;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfMsdcDatDetail)
	  */
	class ContInf : public Block {

	public:
		static const uint TXTPRD = 1;

	public:
		ContInf(const string& TxtPrd = "");

	public:
		string TxtPrd;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppMsdcDatDetail)
	  */
	class StatApp : public Block {

	public:
		static const uint IXMSDCVEXPSTATE = 1;
		static const uint PUPAFTALT = 2;

	public:
		StatApp(const uint ixMsdcVExpstate = VecMsdcVExpstate::MIND, const bool PupAftAlt = false);

	public:
		uint ixMsdcVExpstate;
		bool PupAftAlt;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatApp* comp);
		set<uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrMsdcDatDetail)
	  */
	class StatShr : public Block {

	public:
		static const uint TXFAFTVALID = 1;
		static const uint BUTSAVEAVAIL = 2;
		static const uint BUTSAVEACTIVE = 3;
		static const uint PUPAFTACTIVE = 4;
		static const uint BUTAFTEDITAVAIL = 5;
		static const uint TXTPRDACTIVE = 6;
		static const uint BUTPRDVIEWAVAIL = 7;
		static const uint BUTPRDVIEWACTIVE = 8;
		static const uint TXFSTAACTIVE = 9;
		static const uint TXFSTOACTIVE = 10;
		static const uint TXFCMTACTIVE = 11;

	public:
		StatShr(const bool TxfAftValid = false, const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool PupAftActive = true, const bool ButAftEditAvail = true, const bool TxtPrdActive = true, const bool ButPrdViewAvail = true, const bool ButPrdViewActive = true, const bool TxfStaActive = true, const bool TxfStoActive = true, const bool TxfCmtActive = true);

	public:
		bool TxfAftValid;
		bool ButSaveAvail;
		bool ButSaveActive;
		bool PupAftActive;
		bool ButAftEditAvail;
		bool TxtPrdActive;
		bool ButPrdViewAvail;
		bool ButPrdViewActive;
		bool TxfStaActive;
		bool TxfStoActive;
		bool TxfCmtActive;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagMsdcDatDetail)
	  */
	class Tag : public Block {

	public:
		static const uint CPT = 1;
		static const uint CPTAFT = 2;
		static const uint CPTPRD = 3;
		static const uint CPTSTA = 4;
		static const uint CPTSTO = 5;
		static const uint CPTCMT = 6;

	public:
		Tag(const string& Cpt = "", const string& CptAft = "", const string& CptPrd = "", const string& CptSta = "", const string& CptSto = "", const string& CptCmt = "");

	public:
		string Cpt;
		string CptAft;
		string CptPrd;
		string CptSta;
		string CptSto;
		string CptCmt;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppMsdcDatDetailData)
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
		* DpchAppDo (full: DpchAppMsdcDatDetailDo)
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
		* DpchEngData (full: DpchEngMsdcDatDetailData)
		*/
	class DpchEngData : public DpchEngMsdc {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTIAC = 2;
		static const uint CONTINF = 3;
		static const uint FEEDFPUPAFT = 4;
		static const uint STATAPP = 5;
		static const uint STATSHR = 6;
		static const uint TAG = 7;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Feed feedFPupAft;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		string getSrefsMask();

		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

