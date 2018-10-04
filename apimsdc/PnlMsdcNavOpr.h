/**
  * \file PnlMsdcNavOpr.h
  * API code for job PnlMsdcNavOpr (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Oct 2018
  * \date modified: 4 Oct 2018
  */

#ifndef PNLMSDCNAVOPR_H
#define PNLMSDCNAVOPR_H

#include "ApiMsdc_blks.h"

#define VecVMsdcNavOprDo PnlMsdcNavOpr::VecVDo

#define ContIacMsdcNavOpr PnlMsdcNavOpr::ContIac
#define StatAppMsdcNavOpr PnlMsdcNavOpr::StatApp
#define StatShrMsdcNavOpr PnlMsdcNavOpr::StatShr
#define TagMsdcNavOpr PnlMsdcNavOpr::Tag

#define DpchAppMsdcNavOprData PnlMsdcNavOpr::DpchAppData
#define DpchAppMsdcNavOprDo PnlMsdcNavOpr::DpchAppDo
#define DpchEngMsdcNavOprData PnlMsdcNavOpr::DpchEngData

/**
  * PnlMsdcNavOpr
  */
namespace PnlMsdcNavOpr {
	/**
		* VecVDo (full: VecVMsdcNavOprDo)
		*/
	class VecVDo {

	public:
		static const uint BUTLIVNEWCRDCLICK = 1;
		static const uint BUTPRDVIEWCLICK = 2;
		static const uint BUTPRDNEWCRDCLICK = 3;
		static const uint BUTDATVIEWCLICK = 4;
		static const uint BUTDATNEWCRDCLICK = 5;
		static const uint BUTFILVIEWCLICK = 6;
		static const uint BUTFILNEWCRDCLICK = 7;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacMsdcNavOpr)
	  */
	class ContIac : public Block {

	public:
		static const uint NUMFLSTPRD = 1;
		static const uint NUMFLSTDAT = 2;
		static const uint NUMFLSTFIL = 3;

	public:
		ContIac(const uint numFLstPrd = 1, const uint numFLstDat = 1, const uint numFLstFil = 1);

	public:
		uint numFLstPrd;
		uint numFLstDat;
		uint numFLstFil;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
	  * StatApp (full: StatAppMsdcNavOpr)
	  */
	class StatApp : public Block {

	public:
		static const uint IXMSDCVEXPSTATE = 1;
		static const uint LSTPRDALT = 2;
		static const uint LSTDATALT = 3;
		static const uint LSTFILALT = 4;
		static const uint LSTPRDNUMFIRSTDISP = 5;
		static const uint LSTDATNUMFIRSTDISP = 6;
		static const uint LSTFILNUMFIRSTDISP = 7;

	public:
		StatApp(const uint ixMsdcVExpstate = VecMsdcVExpstate::MIND, const bool LstPrdAlt = true, const bool LstDatAlt = true, const bool LstFilAlt = true, const uint LstPrdNumFirstdisp = 1, const uint LstDatNumFirstdisp = 1, const uint LstFilNumFirstdisp = 1);

	public:
		uint ixMsdcVExpstate;
		bool LstPrdAlt;
		bool LstDatAlt;
		bool LstFilAlt;
		uint LstPrdNumFirstdisp;
		uint LstDatNumFirstdisp;
		uint LstFilNumFirstdisp;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatApp* comp);
		set<uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrMsdcNavOpr)
	  */
	class StatShr : public Block {

	public:
		static const uint BUTLIVNEWCRDAVAIL = 1;
		static const uint LSTPRDAVAIL = 2;
		static const uint BUTPRDVIEWACTIVE = 3;
		static const uint LSTDATAVAIL = 4;
		static const uint BUTDATVIEWACTIVE = 5;
		static const uint BUTDATNEWCRDACTIVE = 6;
		static const uint LSTFILAVAIL = 7;
		static const uint BUTFILVIEWACTIVE = 8;
		static const uint BUTFILNEWCRDACTIVE = 9;

	public:
		StatShr(const bool ButLivNewcrdAvail = true, const bool LstPrdAvail = true, const bool ButPrdViewActive = true, const bool LstDatAvail = true, const bool ButDatViewActive = true, const bool ButDatNewcrdActive = true, const bool LstFilAvail = true, const bool ButFilViewActive = true, const bool ButFilNewcrdActive = true);

	public:
		bool ButLivNewcrdAvail;
		bool LstPrdAvail;
		bool ButPrdViewActive;
		bool LstDatAvail;
		bool ButDatViewActive;
		bool ButDatNewcrdActive;
		bool LstFilAvail;
		bool ButFilViewActive;
		bool ButFilNewcrdActive;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagMsdcNavOpr)
	  */
	class Tag : public Block {

	public:
		static const uint CPT = 1;
		static const uint CPTLIV = 2;
		static const uint CPTPRD = 3;
		static const uint CPTDAT = 4;
		static const uint CPTFIL = 5;

	public:
		Tag(const string& Cpt = "", const string& CptLiv = "", const string& CptPrd = "", const string& CptDat = "", const string& CptFil = "");

	public:
		string Cpt;
		string CptLiv;
		string CptPrd;
		string CptDat;
		string CptFil;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppMsdcNavOprData)
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
		* DpchAppDo (full: DpchAppMsdcNavOprDo)
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
		* DpchEngData (full: DpchEngMsdcNavOprData)
		*/
	class DpchEngData : public DpchEngMsdc {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTIAC = 2;
		static const uint FEEDFLSTDAT = 3;
		static const uint FEEDFLSTFIL = 4;
		static const uint FEEDFLSTPRD = 5;
		static const uint STATAPP = 6;
		static const uint STATSHR = 7;
		static const uint TAG = 8;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		Feed feedFLstDat;
		Feed feedFLstFil;
		Feed feedFLstPrd;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		string getSrefsMask();

		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

