/**
  * \file PnlMsdcPrsDetail.h
  * API code for job PnlMsdcPrsDetail (declarations)
  * \author Alexander Wirthmueller
  * \date created: 12 Sep 2018
  * \date modified: 12 Sep 2018
  */

#ifndef PNLMSDCPRSDETAIL_H
#define PNLMSDCPRSDETAIL_H

#include "ApiMsdc_blks.h"

#define VecVMsdcPrsDetailDo PnlMsdcPrsDetail::VecVDo

#define ContIacMsdcPrsDetail PnlMsdcPrsDetail::ContIac
#define ContInfMsdcPrsDetail PnlMsdcPrsDetail::ContInf
#define StatAppMsdcPrsDetail PnlMsdcPrsDetail::StatApp
#define StatShrMsdcPrsDetail PnlMsdcPrsDetail::StatShr
#define TagMsdcPrsDetail PnlMsdcPrsDetail::Tag

#define DpchAppMsdcPrsDetailData PnlMsdcPrsDetail::DpchAppData
#define DpchAppMsdcPrsDetailDo PnlMsdcPrsDetail::DpchAppDo
#define DpchEngMsdcPrsDetailData PnlMsdcPrsDetail::DpchEngData

/**
  * PnlMsdcPrsDetail
  */
namespace PnlMsdcPrsDetail {
	/**
		* VecVDo (full: VecVMsdcPrsDetailDo)
		*/
	class VecVDo {

	public:
		static const uint BUTSAVECLICK = 1;
		static const uint BUTJEDITCLICK = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacMsdcPrsDetail)
	  */
	class ContIac : public Block {

	public:
		static const uint TXFTIT = 1;
		static const uint TXFFNM = 2;
		static const uint NUMFPUPJ = 3;
		static const uint NUMSFLSTDRV = 4;
		static const uint NUMFPUPSEX = 5;
		static const uint TXFTEL = 6;
		static const uint TXFEML = 7;
		static const uint TXFSAL = 8;

	public:
		ContIac(const string& TxfTit = "", const string& TxfFnm = "", const uint numFPupJ = 1, const vector<uint>& numsFLstDrv = {}, const uint numFPupSex = 1, const string& TxfTel = "", const string& TxfEml = "", const string& TxfSal = "");

	public:
		string TxfTit;
		string TxfFnm;
		uint numFPupJ;
		vector<uint> numsFLstDrv;
		uint numFPupSex;
		string TxfTel;
		string TxfEml;
		string TxfSal;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfMsdcPrsDetail)
	  */
	class ContInf : public Block {

	public:
		static const uint TXTLNM = 1;
		static const uint TXTDRV = 2;

	public:
		ContInf(const string& TxtLnm = "", const string& TxtDrv = "");

	public:
		string TxtLnm;
		string TxtDrv;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppMsdcPrsDetail)
	  */
	class StatApp : public Block {

	public:
		static const uint IXMSDCVEXPSTATE = 1;
		static const uint LSTDRVALT = 2;
		static const uint LSTDRVNUMFIRSTDISP = 3;

	public:
		StatApp(const uint ixMsdcVExpstate = VecMsdcVExpstate::MIND, const bool LstDrvAlt = true, const uint LstDrvNumFirstdisp = 1);

	public:
		uint ixMsdcVExpstate;
		bool LstDrvAlt;
		uint LstDrvNumFirstdisp;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatApp* comp);
		set<uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrMsdcPrsDetail)
	  */
	class StatShr : public Block {

	public:
		static const uint BUTSAVEAVAIL = 1;
		static const uint BUTSAVEACTIVE = 2;
		static const uint TXFTITACTIVE = 3;
		static const uint TXFFNMACTIVE = 4;
		static const uint PUPJACTIVE = 5;
		static const uint BUTJEDITAVAIL = 6;
		static const uint TXTLNMACTIVE = 7;
		static const uint LSTDRVACTIVE = 8;
		static const uint PUPSEXACTIVE = 9;
		static const uint TXFTELACTIVE = 10;
		static const uint TXFEMLACTIVE = 11;
		static const uint TXFSALACTIVE = 12;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxfTitActive = true, const bool TxfFnmActive = true, const bool PupJActive = true, const bool ButJEditAvail = true, const bool TxtLnmActive = true, const bool LstDrvActive = true, const bool PupSexActive = true, const bool TxfTelActive = true, const bool TxfEmlActive = true, const bool TxfSalActive = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxfTitActive;
		bool TxfFnmActive;
		bool PupJActive;
		bool ButJEditAvail;
		bool TxtLnmActive;
		bool LstDrvActive;
		bool PupSexActive;
		bool TxfTelActive;
		bool TxfEmlActive;
		bool TxfSalActive;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagMsdcPrsDetail)
	  */
	class Tag : public Block {

	public:
		static const uint CPT = 1;
		static const uint CPTTIT = 2;
		static const uint CPTFNM = 3;
		static const uint CPTLNM = 4;
		static const uint CPTDRV = 5;
		static const uint CPTSEX = 6;
		static const uint CPTTEL = 7;
		static const uint CPTEML = 8;
		static const uint CPTSAL = 9;

	public:
		Tag(const string& Cpt = "", const string& CptTit = "", const string& CptFnm = "", const string& CptLnm = "", const string& CptDrv = "", const string& CptSex = "", const string& CptTel = "", const string& CptEml = "", const string& CptSal = "");

	public:
		string Cpt;
		string CptTit;
		string CptFnm;
		string CptLnm;
		string CptDrv;
		string CptSex;
		string CptTel;
		string CptEml;
		string CptSal;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppMsdcPrsDetailData)
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
		* DpchAppDo (full: DpchAppMsdcPrsDetailDo)
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
		* DpchEngData (full: DpchEngMsdcPrsDetailData)
		*/
	class DpchEngData : public DpchEngMsdc {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTIAC = 2;
		static const uint CONTINF = 3;
		static const uint FEEDFLSTDRV = 4;
		static const uint FEEDFPUPJ = 5;
		static const uint FEEDFPUPSEX = 6;
		static const uint STATAPP = 7;
		static const uint STATSHR = 8;
		static const uint TAG = 9;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Feed feedFLstDrv;
		Feed feedFPupJ;
		Feed feedFPupSex;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		string getSrefsMask();

		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

