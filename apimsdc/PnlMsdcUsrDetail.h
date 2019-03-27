/**
  * \file PnlMsdcUsrDetail.h
  * API code for job PnlMsdcUsrDetail (declarations)
  * \author Alexander Wirthmueller
  * \date created: 18 Dec 2018
  * \date modified: 18 Dec 2018
  */

#ifndef PNLMSDCUSRDETAIL_H
#define PNLMSDCUSRDETAIL_H

#include "ApiMsdc_blks.h"

#define VecVMsdcUsrDetailDo PnlMsdcUsrDetail::VecVDo

#define ContIacMsdcUsrDetail PnlMsdcUsrDetail::ContIac
#define ContInfMsdcUsrDetail PnlMsdcUsrDetail::ContInf
#define StatAppMsdcUsrDetail PnlMsdcUsrDetail::StatApp
#define StatShrMsdcUsrDetail PnlMsdcUsrDetail::StatShr
#define TagMsdcUsrDetail PnlMsdcUsrDetail::Tag

#define DpchAppMsdcUsrDetailData PnlMsdcUsrDetail::DpchAppData
#define DpchAppMsdcUsrDetailDo PnlMsdcUsrDetail::DpchAppDo
#define DpchEngMsdcUsrDetailData PnlMsdcUsrDetail::DpchEngData

/**
  * PnlMsdcUsrDetail
  */
namespace PnlMsdcUsrDetail {
	/**
		* VecVDo (full: VecVMsdcUsrDetailDo)
		*/
	class VecVDo {

	public:
		static const uint BUTSAVECLICK = 1;
		static const uint BUTPRSVIEWCLICK = 2;
		static const uint BUTUSGVIEWCLICK = 3;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacMsdcUsrDetail)
	  */
	class ContIac : public Block {

	public:
		static const uint NUMFPUPSTE = 1;
		static const uint NUMFPUPLCL = 2;
		static const uint NUMFPUPULV = 3;
		static const uint TXFPWD = 4;
		static const uint TXFFKY = 5;
		static const uint TXFCMT = 6;

	public:
		ContIac(const uint numFPupSte = 1, const uint numFPupLcl = 1, const uint numFPupUlv = 1, const string& TxfPwd = "", const string& TxfFky = "", const string& TxfCmt = "");

	public:
		uint numFPupSte;
		uint numFPupLcl;
		uint numFPupUlv;
		string TxfPwd;
		string TxfFky;
		string TxfCmt;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfMsdcUsrDetail)
	  */
	class ContInf : public Block {

	public:
		static const uint TXTPRS = 1;
		static const uint TXTSRF = 2;
		static const uint TXTUSG = 3;

	public:
		ContInf(const string& TxtPrs = "", const string& TxtSrf = "", const string& TxtUsg = "");

	public:
		string TxtPrs;
		string TxtSrf;
		string TxtUsg;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppMsdcUsrDetail)
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
	  * StatShr (full: StatShrMsdcUsrDetail)
	  */
	class StatShr : public Block {

	public:
		static const uint BUTSAVEAVAIL = 1;
		static const uint BUTSAVEACTIVE = 2;
		static const uint TXTPRSACTIVE = 3;
		static const uint BUTPRSVIEWAVAIL = 4;
		static const uint BUTPRSVIEWACTIVE = 5;
		static const uint TXTSRFACTIVE = 6;
		static const uint TXTUSGACTIVE = 7;
		static const uint BUTUSGVIEWAVAIL = 8;
		static const uint BUTUSGVIEWACTIVE = 9;
		static const uint PUPSTEACTIVE = 10;
		static const uint PUPLCLACTIVE = 11;
		static const uint PUPULVACTIVE = 12;
		static const uint TXFPWDACTIVE = 13;
		static const uint TXFFKYACTIVE = 14;
		static const uint TXFCMTACTIVE = 15;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtPrsActive = true, const bool ButPrsViewAvail = true, const bool ButPrsViewActive = true, const bool TxtSrfActive = true, const bool TxtUsgActive = true, const bool ButUsgViewAvail = true, const bool ButUsgViewActive = true, const bool PupSteActive = true, const bool PupLclActive = true, const bool PupUlvActive = true, const bool TxfPwdActive = true, const bool TxfFkyActive = true, const bool TxfCmtActive = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtPrsActive;
		bool ButPrsViewAvail;
		bool ButPrsViewActive;
		bool TxtSrfActive;
		bool TxtUsgActive;
		bool ButUsgViewAvail;
		bool ButUsgViewActive;
		bool PupSteActive;
		bool PupLclActive;
		bool PupUlvActive;
		bool TxfPwdActive;
		bool TxfFkyActive;
		bool TxfCmtActive;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagMsdcUsrDetail)
	  */
	class Tag : public Block {

	public:
		static const uint CPT = 1;
		static const uint CPTPRS = 2;
		static const uint CPTSRF = 3;
		static const uint CPTUSG = 4;
		static const uint CPTSTE = 5;
		static const uint CPTLCL = 6;
		static const uint CPTULV = 7;
		static const uint CPTPWD = 8;
		static const uint CPTFKY = 9;
		static const uint CPTCMT = 10;

	public:
		Tag(const string& Cpt = "", const string& CptPrs = "", const string& CptSrf = "", const string& CptUsg = "", const string& CptSte = "", const string& CptLcl = "", const string& CptUlv = "", const string& CptPwd = "", const string& CptFky = "", const string& CptCmt = "");

	public:
		string Cpt;
		string CptPrs;
		string CptSrf;
		string CptUsg;
		string CptSte;
		string CptLcl;
		string CptUlv;
		string CptPwd;
		string CptFky;
		string CptCmt;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppMsdcUsrDetailData)
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
		* DpchAppDo (full: DpchAppMsdcUsrDetailDo)
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
		* DpchEngData (full: DpchEngMsdcUsrDetailData)
		*/
	class DpchEngData : public DpchEngMsdc {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTIAC = 2;
		static const uint CONTINF = 3;
		static const uint FEEDFPUPLCL = 4;
		static const uint FEEDFPUPSTE = 5;
		static const uint FEEDFPUPULV = 6;
		static const uint STATAPP = 7;
		static const uint STATSHR = 8;
		static const uint TAG = 9;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Feed feedFPupLcl;
		Feed feedFPupSte;
		Feed feedFPupUlv;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		string getSrefsMask();

		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

