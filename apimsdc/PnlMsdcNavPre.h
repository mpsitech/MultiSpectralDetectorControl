/**
  * \file PnlMsdcNavPre.h
  * API code for job PnlMsdcNavPre (declarations)
  * \author Alexander Wirthmueller
  * \date created: 12 Sep 2018
  * \date modified: 12 Sep 2018
  */

#ifndef PNLMSDCNAVPRE_H
#define PNLMSDCNAVPRE_H

#include "ApiMsdc_blks.h"

#define VecVMsdcNavPreDo PnlMsdcNavPre::VecVDo

#define ContInfMsdcNavPre PnlMsdcNavPre::ContInf
#define StatShrMsdcNavPre PnlMsdcNavPre::StatShr
#define TagMsdcNavPre PnlMsdcNavPre::Tag

#define DpchAppMsdcNavPreDo PnlMsdcNavPre::DpchAppDo
#define DpchEngMsdcNavPreData PnlMsdcNavPre::DpchEngData

/**
  * PnlMsdcNavPre
  */
namespace PnlMsdcNavPre {
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
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
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
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagMsdcNavPre)
	  */
	class Tag : public Block {

	public:
		static const uint CPTDAT = 1;
		static const uint CPTPRD = 2;

	public:
		Tag(const string& CptDat = "", const string& CptPrd = "");

	public:
		string CptDat;
		string CptPrd;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppMsdcNavPreDo)
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
		* DpchEngData (full: DpchEngMsdcNavPreData)
		*/
	class DpchEngData : public DpchEngMsdc {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTINF = 2;
		static const uint STATSHR = 3;
		static const uint TAG = 4;

	public:
		DpchEngData();

	public:
		ContInf continf;
		StatShr statshr;
		Tag tag;

	public:
		string getSrefsMask();

		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

