/**
  * \file PnlMsdcUsr1NSession.h
  * API code for job PnlMsdcUsr1NSession (declarations)
  * \author Alexander Wirthmueller
  * \date created: 15 Aug 2018
  * \date modified: 15 Aug 2018
  */

#ifndef PNLMSDCUSR1NSESSION_H
#define PNLMSDCUSR1NSESSION_H

#include "ApiMsdc_blks.h"

#include "MsdcQUsr1NSession.h"

#include "QryMsdcUsr1NSession.h"

#define VecVMsdcUsr1NSessionDo PnlMsdcUsr1NSession::VecVDo

#define ContInfMsdcUsr1NSession PnlMsdcUsr1NSession::ContInf
#define StatAppMsdcUsr1NSession PnlMsdcUsr1NSession::StatApp
#define StatShrMsdcUsr1NSession PnlMsdcUsr1NSession::StatShr
#define StgIacMsdcUsr1NSession PnlMsdcUsr1NSession::StgIac
#define TagMsdcUsr1NSession PnlMsdcUsr1NSession::Tag

#define DpchAppMsdcUsr1NSessionData PnlMsdcUsr1NSession::DpchAppData
#define DpchAppMsdcUsr1NSessionDo PnlMsdcUsr1NSession::DpchAppDo
#define DpchEngMsdcUsr1NSessionData PnlMsdcUsr1NSession::DpchEngData

/**
  * PnlMsdcUsr1NSession
  */
namespace PnlMsdcUsr1NSession {
	/**
		* VecVDo (full: VecVMsdcUsr1NSessionDo)
		*/
	class VecVDo {

	public:
		static const uint BUTDELETECLICK = 1;
		static const uint BUTREFRESHCLICK = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContInf (full: ContInfMsdcUsr1NSession)
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
	  * StatApp (full: StatAppMsdcUsr1NSession)
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
	  * StatShr (full: StatShrMsdcUsr1NSession)
	  */
	class StatShr : public Block {

	public:
		static const uint BUTDELETEAVAIL = 1;
		static const uint BUTDELETEACTIVE = 2;

	public:
		StatShr(const bool ButDeleteAvail = true, const bool ButDeleteActive = true);

	public:
		bool ButDeleteAvail;
		bool ButDeleteActive;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * StgIac (full: StgIacMsdcUsr1NSession)
	  */
	class StgIac : public Block {

	public:
		static const uint TCOREFWIDTH = 1;

	public:
		StgIac(const uint TcoRefWidth = 100);

	public:
		uint TcoRefWidth;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StgIac* comp);
		set<uint> diff(const StgIac* comp);
	};

	/**
	  * Tag (full: TagMsdcUsr1NSession)
	  */
	class Tag : public Block {

	public:
		static const uint CPT = 1;
		static const uint TRS = 2;
		static const uint TXTSHOWING1 = 3;
		static const uint TXTSHOWING2 = 4;
		static const uint TCOREF = 5;

	public:
		Tag(const string& Cpt = "", const string& Trs = "", const string& TxtShowing1 = "", const string& TxtShowing2 = "", const string& TcoRef = "");

	public:
		string Cpt;
		string Trs;
		string TxtShowing1;
		string TxtShowing2;
		string TcoRef;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppMsdcUsr1NSessionData)
		*/
	class DpchAppData : public DpchAppMsdc {

	public:
		static const uint SCRJREF = 1;
		static const uint STGIAC = 2;
		static const uint STGIACQRY = 3;
		static const uint ALL = 4;

	public:
		DpchAppData(const string& scrJref = "", StgIac* stgiac = NULL, QryMsdcUsr1NSession::StgIac* stgiacqry = NULL, const set<uint>& mask = {NONE});

	public:
		StgIac stgiac;
		QryMsdcUsr1NSession::StgIac stgiacqry;

	public:
		string getSrefsMask();

		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchAppDo (full: DpchAppMsdcUsr1NSessionDo)
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
		* DpchEngData (full: DpchEngMsdcUsr1NSessionData)
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
		ListMsdcQUsr1NSession rst;
		QryMsdcUsr1NSession::StatApp statappqry;
		QryMsdcUsr1NSession::StatShr statshrqry;
		QryMsdcUsr1NSession::StgIac stgiacqry;

	public:
		string getSrefsMask();

		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

