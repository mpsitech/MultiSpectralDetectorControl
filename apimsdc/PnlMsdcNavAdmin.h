/**
  * \file PnlMsdcNavAdmin.h
  * API code for job PnlMsdcNavAdmin (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Oct 2018
  * \date modified: 4 Oct 2018
  */

#ifndef PNLMSDCNAVADMIN_H
#define PNLMSDCNAVADMIN_H

#include "ApiMsdc_blks.h"

#define VecVMsdcNavAdminDo PnlMsdcNavAdmin::VecVDo

#define ContIacMsdcNavAdmin PnlMsdcNavAdmin::ContIac
#define StatAppMsdcNavAdmin PnlMsdcNavAdmin::StatApp
#define StatShrMsdcNavAdmin PnlMsdcNavAdmin::StatShr
#define TagMsdcNavAdmin PnlMsdcNavAdmin::Tag

#define DpchAppMsdcNavAdminData PnlMsdcNavAdmin::DpchAppData
#define DpchAppMsdcNavAdminDo PnlMsdcNavAdmin::DpchAppDo
#define DpchEngMsdcNavAdminData PnlMsdcNavAdmin::DpchEngData

/**
  * PnlMsdcNavAdmin
  */
namespace PnlMsdcNavAdmin {
	/**
		* VecVDo (full: VecVMsdcNavAdminDo)
		*/
	class VecVDo {

	public:
		static const uint BUTUSGVIEWCLICK = 1;
		static const uint BUTUSGNEWCRDCLICK = 2;
		static const uint BUTUSRVIEWCLICK = 3;
		static const uint BUTUSRNEWCRDCLICK = 4;
		static const uint BUTPRSVIEWCLICK = 5;
		static const uint BUTPRSNEWCRDCLICK = 6;
		static const uint BUTSCFNEWCRDCLICK = 7;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacMsdcNavAdmin)
	  */
	class ContIac : public Block {

	public:
		static const uint NUMFLSTUSG = 1;
		static const uint NUMFLSTUSR = 2;
		static const uint NUMFLSTPRS = 3;

	public:
		ContIac(const uint numFLstUsg = 1, const uint numFLstUsr = 1, const uint numFLstPrs = 1);

	public:
		uint numFLstUsg;
		uint numFLstUsr;
		uint numFLstPrs;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
	  * StatApp (full: StatAppMsdcNavAdmin)
	  */
	class StatApp : public Block {

	public:
		static const uint IXMSDCVEXPSTATE = 1;
		static const uint LSTUSGALT = 2;
		static const uint LSTUSRALT = 3;
		static const uint LSTPRSALT = 4;
		static const uint LSTUSGNUMFIRSTDISP = 5;
		static const uint LSTUSRNUMFIRSTDISP = 6;
		static const uint LSTPRSNUMFIRSTDISP = 7;

	public:
		StatApp(const uint ixMsdcVExpstate = VecMsdcVExpstate::MIND, const bool LstUsgAlt = true, const bool LstUsrAlt = true, const bool LstPrsAlt = true, const uint LstUsgNumFirstdisp = 1, const uint LstUsrNumFirstdisp = 1, const uint LstPrsNumFirstdisp = 1);

	public:
		uint ixMsdcVExpstate;
		bool LstUsgAlt;
		bool LstUsrAlt;
		bool LstPrsAlt;
		uint LstUsgNumFirstdisp;
		uint LstUsrNumFirstdisp;
		uint LstPrsNumFirstdisp;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatApp* comp);
		set<uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrMsdcNavAdmin)
	  */
	class StatShr : public Block {

	public:
		static const uint LSTUSGAVAIL = 1;
		static const uint BUTUSGVIEWACTIVE = 2;
		static const uint LSTUSRAVAIL = 3;
		static const uint BUTUSRVIEWACTIVE = 4;
		static const uint LSTPRSAVAIL = 5;
		static const uint BUTPRSVIEWACTIVE = 6;
		static const uint BUTSCFNEWCRDAVAIL = 7;

	public:
		StatShr(const bool LstUsgAvail = true, const bool ButUsgViewActive = true, const bool LstUsrAvail = true, const bool ButUsrViewActive = true, const bool LstPrsAvail = true, const bool ButPrsViewActive = true, const bool ButScfNewcrdAvail = true);

	public:
		bool LstUsgAvail;
		bool ButUsgViewActive;
		bool LstUsrAvail;
		bool ButUsrViewActive;
		bool LstPrsAvail;
		bool ButPrsViewActive;
		bool ButScfNewcrdAvail;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagMsdcNavAdmin)
	  */
	class Tag : public Block {

	public:
		static const uint CPT = 1;
		static const uint CPTUSG = 2;
		static const uint CPTUSR = 3;
		static const uint CPTPRS = 4;
		static const uint CPTSCF = 5;

	public:
		Tag(const string& Cpt = "", const string& CptUsg = "", const string& CptUsr = "", const string& CptPrs = "", const string& CptScf = "");

	public:
		string Cpt;
		string CptUsg;
		string CptUsr;
		string CptPrs;
		string CptScf;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppMsdcNavAdminData)
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
		* DpchAppDo (full: DpchAppMsdcNavAdminDo)
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
		* DpchEngData (full: DpchEngMsdcNavAdminData)
		*/
	class DpchEngData : public DpchEngMsdc {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTIAC = 2;
		static const uint FEEDFLSTPRS = 3;
		static const uint FEEDFLSTUSG = 4;
		static const uint FEEDFLSTUSR = 5;
		static const uint STATAPP = 6;
		static const uint STATSHR = 7;
		static const uint TAG = 8;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		Feed feedFLstPrs;
		Feed feedFLstUsg;
		Feed feedFLstUsr;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		string getSrefsMask();

		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

