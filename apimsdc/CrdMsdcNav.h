/**
  * \file CrdMsdcNav.h
  * API code for job CrdMsdcNav (declarations)
  * \author Alexander Wirthmueller
  * \date created: 12 Sep 2018
  * \date modified: 12 Sep 2018
  */

#ifndef CRDMSDCNAV_H
#define CRDMSDCNAV_H

#include "ApiMsdc_blks.h"

#define VecVMsdcNavDo CrdMsdcNav::VecVDo
#define VecVMsdcNavSge CrdMsdcNav::VecVSge

#define ContInfMsdcNav CrdMsdcNav::ContInf
#define StatAppMsdcNav CrdMsdcNav::StatApp
#define StatShrMsdcNav CrdMsdcNav::StatShr
#define TagMsdcNav CrdMsdcNav::Tag

#define DpchAppMsdcNavDo CrdMsdcNav::DpchAppDo
#define DpchEngMsdcNavData CrdMsdcNav::DpchEngData

/**
  * CrdMsdcNav
  */
namespace CrdMsdcNav {
	/**
		* VecVDo (full: VecVMsdcNavDo)
		*/
	class VecVDo {

	public:
		static const uint CLOSE = 1;
		static const uint MITAPPABTCLICK = 2;
		static const uint MITSESSPSCLICK = 3;
		static const uint MITSESTRMCLICK = 4;
		static const uint MITCRDUSGCLICK = 5;
		static const uint MITCRDUSRCLICK = 6;
		static const uint MITCRDPRSCLICK = 7;
		static const uint MITCRDSCFCLICK = 8;
		static const uint MITCRDLIVCLICK = 9;
		static const uint MITCRDPRDCLICK = 10;
		static const uint MITCRDDATCLICK = 11;
		static const uint MITCRDFILCLICK = 12;
		static const uint MITAPPLOICLICK = 13;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
		* VecVSge (full: VecVMsdcNavSge)
		*/
	class VecVSge {

	public:
		static const uint IDLE = 1;
		static const uint ALRMSDCABT = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContInf (full: ContInfMsdcNav)
	  */
	class ContInf : public Block {

	public:
		static const uint NUMFSGE = 1;
		static const uint MRLAPPHLP = 2;
		static const uint MTXSESSES1 = 3;
		static const uint MTXSESSES2 = 4;
		static const uint MTXSESSES3 = 5;

	public:
		ContInf(const uint numFSge = 1, const string& MrlAppHlp = "", const string& MtxSesSes1 = "", const string& MtxSesSes2 = "", const string& MtxSesSes3 = "");

	public:
		uint numFSge;
		string MrlAppHlp;
		string MtxSesSes1;
		string MtxSesSes2;
		string MtxSesSes3;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppMsdcNav)
	  */
	class StatApp : public Block {

	public:
		static const uint IXMSDCVREQITMODE = 1;
		static const uint LATENCY = 2;
		static const uint SHORTMENU = 3;
		static const uint WIDTHMENU = 4;
		static const uint INITDONEHEADBAR = 5;
		static const uint INITDONEPRE = 6;
		static const uint INITDONEADMIN = 7;
		static const uint INITDONEOPR = 8;

	public:
		StatApp(const uint ixMsdcVReqitmode = VecMsdcVReqitmode::IDLE, const usmallint latency = 5, const string& shortMenu = "", const uint widthMenu = 0, const bool initdoneHeadbar = false, const bool initdonePre = false, const bool initdoneAdmin = false, const bool initdoneOpr = false);

	public:
		uint ixMsdcVReqitmode;
		usmallint latency;
		string shortMenu;
		uint widthMenu;
		bool initdoneHeadbar;
		bool initdonePre;
		bool initdoneAdmin;
		bool initdoneOpr;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatApp* comp);
		set<uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrMsdcNav)
	  */
	class StatShr : public Block {

	public:
		static const uint SCRJREFDLGLOAINI = 1;
		static const uint SCRJREFHEADBAR = 2;
		static const uint SCRJREFPRE = 3;
		static const uint PNLPREAVAIL = 4;
		static const uint SCRJREFADMIN = 5;
		static const uint PNLADMINAVAIL = 6;
		static const uint SCRJREFOPR = 7;
		static const uint PNLOPRAVAIL = 8;
		static const uint MSPCRD1AVAIL = 9;
		static const uint MITCRDUSGAVAIL = 10;
		static const uint MITCRDUSRAVAIL = 11;
		static const uint MITCRDPRSAVAIL = 12;
		static const uint MITCRDSCFAVAIL = 13;
		static const uint MSPCRD2AVAIL = 14;
		static const uint MITCRDLIVAVAIL = 15;
		static const uint MITCRDPRDAVAIL = 16;
		static const uint MITCRDDATAVAIL = 17;
		static const uint MITCRDDATACTIVE = 18;
		static const uint MITCRDFILAVAIL = 19;
		static const uint MSPAPP2AVAIL = 20;
		static const uint MITAPPLOIAVAIL = 21;

	public:
		StatShr(const string& scrJrefDlgloaini = "", const string& scrJrefHeadbar = "", const string& scrJrefPre = "", const bool pnlpreAvail = false, const string& scrJrefAdmin = "", const bool pnladminAvail = false, const string& scrJrefOpr = "", const bool pnloprAvail = false, const bool MspCrd1Avail = true, const bool MitCrdUsgAvail = true, const bool MitCrdUsrAvail = true, const bool MitCrdPrsAvail = true, const bool MitCrdScfAvail = true, const bool MspCrd2Avail = true, const bool MitCrdLivAvail = true, const bool MitCrdPrdAvail = true, const bool MitCrdDatAvail = true, const bool MitCrdDatActive = true, const bool MitCrdFilAvail = true, const bool MspApp2Avail = true, const bool MitAppLoiAvail = true);

	public:
		ubigint jrefDlgloaini;
		ubigint jrefHeadbar;
		ubigint jrefPre;
		bool pnlpreAvail;
		ubigint jrefAdmin;
		bool pnladminAvail;
		ubigint jrefOpr;
		bool pnloprAvail;
		bool MspCrd1Avail;
		bool MitCrdUsgAvail;
		bool MitCrdUsrAvail;
		bool MitCrdPrsAvail;
		bool MitCrdScfAvail;
		bool MspCrd2Avail;
		bool MitCrdLivAvail;
		bool MitCrdPrdAvail;
		bool MitCrdDatAvail;
		bool MitCrdDatActive;
		bool MitCrdFilAvail;
		bool MspApp2Avail;
		bool MitAppLoiAvail;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagMsdcNav)
	  */
	class Tag : public Block {

	public:
		static const uint MITAPPABT = 1;
		static const uint MRLAPPHLP = 2;
		static const uint MITSESSPS = 3;
		static const uint MITSESTRM = 4;
		static const uint MITCRDUSG = 5;
		static const uint MITCRDUSR = 6;
		static const uint MITCRDPRS = 7;
		static const uint MITCRDSCF = 8;
		static const uint MITCRDLIV = 9;
		static const uint MITCRDPRD = 10;
		static const uint MITCRDDAT = 11;
		static const uint MITCRDFIL = 12;
		static const uint MITAPPLOI = 13;

	public:
		Tag(const string& MitAppAbt = "", const string& MrlAppHlp = "", const string& MitSesSps = "", const string& MitSesTrm = "", const string& MitCrdUsg = "", const string& MitCrdUsr = "", const string& MitCrdPrs = "", const string& MitCrdScf = "", const string& MitCrdLiv = "", const string& MitCrdPrd = "", const string& MitCrdDat = "", const string& MitCrdFil = "", const string& MitAppLoi = "");

	public:
		string MitAppAbt;
		string MrlAppHlp;
		string MitSesSps;
		string MitSesTrm;
		string MitCrdUsg;
		string MitCrdUsr;
		string MitCrdPrs;
		string MitCrdScf;
		string MitCrdLiv;
		string MitCrdPrd;
		string MitCrdDat;
		string MitCrdFil;
		string MitAppLoi;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppMsdcNavDo)
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
		* DpchEngData (full: DpchEngMsdcNavData)
		*/
	class DpchEngData : public DpchEngMsdc {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTINF = 2;
		static const uint FEEDFSGE = 3;
		static const uint STATAPP = 4;
		static const uint STATSHR = 5;
		static const uint TAG = 6;

	public:
		DpchEngData();

	public:
		ContInf continf;
		Feed feedFSge;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		string getSrefsMask();

		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

