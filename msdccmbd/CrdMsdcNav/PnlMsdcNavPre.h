/**
  * \file PnlMsdcNavPre.h
  * job handler for job PnlMsdcNavPre (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Oct 2018
  * \date modified: 4 Oct 2018
  */

#ifndef PNLMSDCNAVPRE_H
#define PNLMSDCNAVPRE_H

// IP custInclude --- INSERT

#define VecVMsdcNavPreDo PnlMsdcNavPre::VecVDo

#define ContInfMsdcNavPre PnlMsdcNavPre::ContInf
#define StatShrMsdcNavPre PnlMsdcNavPre::StatShr
#define TagMsdcNavPre PnlMsdcNavPre::Tag

#define DpchAppMsdcNavPreDo PnlMsdcNavPre::DpchAppDo
#define DpchEngMsdcNavPreData PnlMsdcNavPre::DpchEngData

/**
  * PnlMsdcNavPre
  */
class PnlMsdcNavPre : public JobMsdc {

public:
	/**
		* VecVDo (full: VecVMsdcNavPreDo)
		*/
	class VecVDo {

	public:
		static const uint BUTDATREMOVECLICK = 1;
		static const uint BUTPRDREMOVECLICK = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContInf (full: ContInfMsdcNavPre)
	  */
	class ContInf : public Block {

	public:
		static const uint TXTDAT = 1;
		static const uint TXTPRD = 2;

	public:
		ContInf(const string& TxtDat = "", const string& TxtPrd = "");

	public:
		string TxtDat;
		string TxtPrd;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
		* StatShr (full: StatShrMsdcNavPre)
		*/
	class StatShr : public Block {

	public:
		static const uint TXTDATAVAIL = 1;
		static const uint TXTPRDAVAIL = 2;

	public:
		StatShr(const bool TxtDatAvail = true, const bool TxtPrdAvail = true);

	public:
		bool TxtDatAvail;
		bool TxtPrdAvail;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagMsdcNavPre)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixMsdcVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppDo (full: DpchAppMsdcNavPreDo)
		*/
	class DpchAppDo : public DpchAppMsdc {

	public:
		static const uint JREF = 1;
		static const uint IXVDO = 2;

	public:
		DpchAppDo();

	public:
		uint ixVDo;

	public:
		string getSrefsMask();

		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngData (full: DpchEngMsdcNavPreData)
		*/
	class DpchEngData : public DpchEngMsdc {

	public:
		static const uint JREF = 1;
		static const uint CONTINF = 2;
		static const uint STATSHR = 3;
		static const uint TAG = 4;
		static const uint ALL = 5;

	public:
		DpchEngData(const ubigint jref = 0, ContInf* continf = NULL, StatShr* statshr = NULL, const set<uint>& mask = {NONE});

	public:
		ContInf continf;
		StatShr statshr;

	public:
		string getSrefsMask();
		void merge(DpchEngMsdc* dpcheng);

		void writeXML(const uint ixMsdcVLocale, xmlTextWriter* wr);
	};

	bool evalTxtDatAvail(DbsMsdc* dbsmsdc);
	bool evalTxtPrdAvail(DbsMsdc* dbsmsdc);

public:
	PnlMsdcNavPre(XchgMsdc* xchg, DbsMsdc* dbsmsdc, const ubigint jrefSup, const uint ixMsdcVLocale);
	~PnlMsdcNavPre();

public:
	ContInf continf;
	StatShr statshr;

	// IP custVar --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngMsdc* getNewDpchEng(set<uint> items);

	void refresh(DbsMsdc* dbsmsdc, set<uint>& moditems);

	void updatePreset(DbsMsdc* dbsmsdc, const uint ixMsdcVPreset, const ubigint jrefTrig, const bool notif = false);

public:

	void handleRequest(DbsMsdc* dbsmsdc, ReqMsdc* req);

	void handleDpchAppMsdcInit(DbsMsdc* dbsmsdc, DpchAppMsdcInit* dpchappmsdcinit, DpchEngMsdc** dpcheng);

	void handleDpchAppDoButDatRemoveClick(DbsMsdc* dbsmsdc, DpchEngMsdc** dpcheng);
	void handleDpchAppDoButPrdRemoveClick(DbsMsdc* dbsmsdc, DpchEngMsdc** dpcheng);

};

#endif

