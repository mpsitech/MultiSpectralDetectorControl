/**
  * \file QryMsdcDatList.h
  * API code for job QryMsdcDatList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 15 Aug 2018
  * \date modified: 15 Aug 2018
  */

#ifndef QRYMSDCDATLIST_H
#define QRYMSDCDATLIST_H

#include "ApiMsdc_blks.h"

#define VecVQryMsdcDatListOrd QryMsdcDatList::VecVOrd

#define StatAppQryMsdcDatList QryMsdcDatList::StatApp
#define StatShrQryMsdcDatList QryMsdcDatList::StatShr
#define StgIacQryMsdcDatList QryMsdcDatList::StgIac

/**
  * QryMsdcDatList
  */
namespace QryMsdcDatList {
	/**
		* VecVOrd (full: VecVQryMsdcDatListOrd)
		*/
	class VecVOrd {

	public:
		static const uint AFT = 1;
		static const uint PRD = 2;
		static const uint STA = 3;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * StatApp (full: StatAppQryMsdcDatList)
	  */
	class StatApp : public Block {

	public:
		static const uint FIRSTCOL = 1;
		static const uint JNUMFIRSTDISP = 2;
		static const uint NCOL = 3;
		static const uint NDISP = 4;

	public:
		StatApp(const uint firstcol = 1, const uint jnumFirstdisp = 1, const uint ncol = 5, const uint ndisp = 25);

	public:
		uint firstcol;
		uint jnumFirstdisp;
		uint ncol;
		uint ndisp;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatApp* comp);
		set<uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrQryMsdcDatList)
	  */
	class StatShr : public Block {

	public:
		static const uint NTOT = 1;
		static const uint JNUMFIRSTLOAD = 2;
		static const uint NLOAD = 3;

	public:
		StatShr(const uint ntot = 0, const uint jnumFirstload = 0, const uint nload = 0);

	public:
		uint ntot;
		uint jnumFirstload;
		uint nload;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * StgIac (full: StgIacQryMsdcDatList)
	  */
	class StgIac : public Block {

	public:
		static const uint JNUM = 1;
		static const uint JNUMFIRSTLOAD = 2;
		static const uint NLOAD = 3;

	public:
		StgIac(const uint jnum = 0, const uint jnumFirstload = 1, const uint nload = 100);

	public:
		uint jnum;
		uint jnumFirstload;
		uint nload;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StgIac* comp);
		set<uint> diff(const StgIac* comp);
	};

};

#endif

