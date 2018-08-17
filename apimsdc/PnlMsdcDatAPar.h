/**
  * \file PnlMsdcDatAPar.h
  * API code for job PnlMsdcDatAPar (declarations)
  * \author Alexander Wirthmueller
  * \date created: 15 Aug 2018
  * \date modified: 15 Aug 2018
  */

#ifndef PNLMSDCDATAPAR_H
#define PNLMSDCDATAPAR_H

#include "ApiMsdc_blks.h"

#include "MsdcQDatAPar.h"

#include "QryMsdcDatAPar.h"

#define VecVMsdcDatAParDo PnlMsdcDatAPar::VecVDo

#define ContInfMsdcDatAPar PnlMsdcDatAPar::ContInf
#define StatAppMsdcDatAPar PnlMsdcDatAPar::StatApp
#define StatShrMsdcDatAPar PnlMsdcDatAPar::StatShr
#define StgIacMsdcDatAPar PnlMsdcDatAPar::StgIac
#define TagMsdcDatAPar PnlMsdcDatAPar::Tag

#define DpchAppMsdcDatAParData PnlMsdcDatAPar::DpchAppData
#define DpchAppMsdcDatAParDo PnlMsdcDatAPar::DpchAppDo
#define DpchEngMsdcDatAParData PnlMsdcDatAPar::DpchEngData

/**
  * PnlMsdcDatAPar
  */
namespace PnlMsdcDatAPar {
	/**
		* VecVDo (full: VecVMsdcDatAParDo)
		*/
	class VecVDo {

	public:
		static const uint BUTNEWCLICK = 1;
		static const uint BUTDUPLICATECLICK = 2;
		static const uint BUTDELETECLICK = 3;
		static const uint BUTREFRESHCLICK = 4;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContInf (full: ContInfMsdcDatAPar)
	  */
	class ContInf : public Block {

	public:
		static const uint NUMFCSIQST = 1;

	public:
		ContInf(const uint numFCsiQst = 1);

	public:
		uint numFCsiQst;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppMsdcDatAPar)
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
	  * StatShr (full: StatShrMsdcDatAPar)
	  */
	class StatShr : public Block {

	public:
		static const uint BUTNEWAVAIL = 1;
		static const uint BUTDUPLICATEAVAIL = 2;
		static const uint BUTDUPLICATEACTIVE = 3;
		static const uint BUTDELETEAVAIL = 4;
		static const uint BUTDELETEACTIVE = 5;

	public:
		StatShr(const bool ButNewAvail = true, const bool ButDuplicateAvail = true, const bool ButDuplicateActive = true, const bool ButDeleteAvail = true, const bool ButDeleteActive = true);

	public:
		bool ButNewAvail;
		bool ButDuplicateAvail;
		bool ButDuplicateActive;
		bool ButDeleteAvail;
		bool ButDeleteActive;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * StgIac (full: StgIacMsdcDatAPar)
	  */
	class StgIac : public Block {

	public:
		static const uint TCOSTAWIDTH = 1;
		static const uint TCOKEYWIDTH = 2;
		static const uint TCOFILWIDTH = 3;
		static const uint TCOVALWIDTH = 4;
		static const uint TCOBINWIDTH = 5;

	public:
		StgIac(const uint TcoStaWidth = 200, const uint TcoKeyWidth = 100, const uint TcoFilWidth = 100, const uint TcoValWidth = 100, const uint TcoBinWidth = 100);

	public:
		uint TcoStaWidth;
		uint TcoKeyWidth;
		uint TcoFilWidth;
		uint TcoValWidth;
		uint TcoBinWidth;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StgIac* comp);
		set<uint> diff(const StgIac* comp);
	};

	/**
	  * Tag (full: TagMsdcDatAPar)
	  */
	class Tag : public Block {

	public:
		static const uint CPT = 1;
		static const uint TRS = 2;
		static const uint TXTSHOWING1 = 3;
		static const uint TXTSHOWING2 = 4;
		static const uint TCOSTA = 5;
		static const uint TCOKEY = 6;
		static const uint TCOFIL = 7;
		static const uint TCOVAL = 8;
		static const uint TCOBIN = 9;

	public:
		Tag(const string& Cpt = "", const string& Trs = "", const string& TxtShowing1 = "", const string& TxtShowing2 = "", const string& TcoSta = "", const string& TcoKey = "", const string& TcoFil = "", const string& TcoVal = "", const string& TcoBin = "");

	public:
		string Cpt;
		string Trs;
		string TxtShowing1;
		string TxtShowing2;
		string TcoSta;
		string TcoKey;
		string TcoFil;
		string TcoVal;
		string TcoBin;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppMsdcDatAParData)
		*/
	class DpchAppData : public DpchAppMsdc {

	public:
		static const uint SCRJREF = 1;
		static const uint STGIAC = 2;
		static const uint STGIACQRY = 3;
		static const uint ALL = 4;

	public:
		DpchAppData(const string& scrJref = "", StgIac* stgiac = NULL, QryMsdcDatAPar::StgIac* stgiacqry = NULL, const set<uint>& mask = {NONE});

	public:
		StgIac stgiac;
		QryMsdcDatAPar::StgIac stgiacqry;

	public:
		string getSrefsMask();

		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchAppDo (full: DpchAppMsdcDatAParDo)
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
		* DpchEngData (full: DpchEngMsdcDatAParData)
		*/
	class DpchEngData : public DpchEngMsdc {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTINF = 2;
		static const uint FEEDFCSIQST = 3;
		static const uint STATAPP = 4;
		static const uint STATSHR = 5;
		static const uint STGIAC = 6;
		static const uint TAG = 7;
		static const uint RST = 8;
		static const uint STATAPPQRY = 9;
		static const uint STATSHRQRY = 10;
		static const uint STGIACQRY = 11;

	public:
		DpchEngData();

	public:
		ContInf continf;
		Feed feedFCsiQst;
		StatApp statapp;
		StatShr statshr;
		StgIac stgiac;
		Tag tag;
		ListMsdcQDatAPar rst;
		QryMsdcDatAPar::StatApp statappqry;
		QryMsdcDatAPar::StatShr statshrqry;
		QryMsdcDatAPar::StgIac stgiacqry;

	public:
		string getSrefsMask();

		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

