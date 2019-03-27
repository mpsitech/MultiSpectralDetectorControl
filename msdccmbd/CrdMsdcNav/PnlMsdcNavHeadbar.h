/**
  * \file PnlMsdcNavHeadbar.h
  * job handler for job PnlMsdcNavHeadbar (declarations)
  * \author Alexander Wirthmueller
  * \date created: 18 Dec 2018
  * \date modified: 18 Dec 2018
  */

#ifndef PNLMSDCNAVHEADBAR_H
#define PNLMSDCNAVHEADBAR_H

// IP custInclude --- INSERT

#define StatShrMsdcNavHeadbar PnlMsdcNavHeadbar::StatShr
#define StgInfMsdcNavHeadbar PnlMsdcNavHeadbar::StgInf
#define TagMsdcNavHeadbar PnlMsdcNavHeadbar::Tag

#define DpchEngMsdcNavHeadbarData PnlMsdcNavHeadbar::DpchEngData

/**
  * PnlMsdcNavHeadbar
  */
class PnlMsdcNavHeadbar : public JobMsdc {

public:
	/**
		* StatShr (full: StatShrMsdcNavHeadbar)
		*/
	class StatShr : public Block {

	public:
		static const uint MENCRDAVAIL = 1;

	public:
		StatShr(const bool MenCrdAvail = true);

	public:
		bool MenCrdAvail;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* StgInf (full: StgInfMsdcNavHeadbar)
		*/
	class StgInf {

	public:
		static void writeXML(const uint ixMsdcVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* Tag (full: TagMsdcNavHeadbar)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixMsdcVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchEngData (full: DpchEngMsdcNavHeadbarData)
		*/
	class DpchEngData : public DpchEngMsdc {

	public:
		static const uint JREF = 1;
		static const uint STATSHR = 2;
		static const uint STGINF = 3;
		static const uint TAG = 4;
		static const uint ALL = 5;

	public:
		DpchEngData(const ubigint jref = 0, StatShr* statshr = NULL, const set<uint>& mask = {NONE});

	public:
		StatShr statshr;

	public:
		string getSrefsMask();
		void merge(DpchEngMsdc* dpcheng);

		void writeXML(const uint ixMsdcVLocale, xmlTextWriter* wr);
	};

	bool evalMenCrdAvail(DbsMsdc* dbsmsdc);
	bool evalMspCrd1Avail(DbsMsdc* dbsmsdc);
	bool evalMitCrdUsgAvail(DbsMsdc* dbsmsdc);
	bool evalMitCrdUsrAvail(DbsMsdc* dbsmsdc);
	bool evalMitCrdPrsAvail(DbsMsdc* dbsmsdc);
	bool evalMitCrdScfAvail(DbsMsdc* dbsmsdc);
	bool evalMspCrd2Avail(DbsMsdc* dbsmsdc);
	bool evalMitCrdLivAvail(DbsMsdc* dbsmsdc);
	bool evalMitCrdPrdAvail(DbsMsdc* dbsmsdc);
	bool evalMitCrdDatAvail(DbsMsdc* dbsmsdc);
	bool evalMitCrdFilAvail(DbsMsdc* dbsmsdc);

public:
	PnlMsdcNavHeadbar(XchgMsdc* xchg, DbsMsdc* dbsmsdc, const ubigint jrefSup, const uint ixMsdcVLocale);
	~PnlMsdcNavHeadbar();

public:
	StatShr statshr;

	// IP custVar --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngMsdc* getNewDpchEng(set<uint> items);

	void refresh(DbsMsdc* dbsmsdc, set<uint>& moditems);

public:

	void handleRequest(DbsMsdc* dbsmsdc, ReqMsdc* req);

	void handleDpchAppMsdcInit(DbsMsdc* dbsmsdc, DpchAppMsdcInit* dpchappmsdcinit, DpchEngMsdc** dpcheng);

};

#endif

