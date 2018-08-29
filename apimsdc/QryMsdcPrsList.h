/**
  * \file QryMsdcPrsList.h
  * API code for job QryMsdcPrsList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 29 Aug 2018
  * \date modified: 29 Aug 2018
  */

#ifndef QRYMSDCPRSLIST_H
#define QRYMSDCPRSLIST_H

#include "ApiMsdc_blks.h"

#define VecVQryMsdcPrsListOrd QryMsdcPrsList::VecVOrd

#define StatAppQryMsdcPrsList QryMsdcPrsList::StatApp
#define StatShrQryMsdcPrsList QryMsdcPrsList::StatShr
#define StgIacQryMsdcPrsList QryMsdcPrsList::StgIac

/**
  * QryMsdcPrsList
  */
namespace QryMsdcPrsList {
	/**
		* VecVOrd (full: VecVQryMsdcPrsListOrd)
		*/
	class VecVOrd {

	public:
		static const uint LNM = 1;
		static const uint GRP = 2;
		static const uint OWN = 3;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * StatApp (full: StatAppQryMsdcPrsList)
	  */
	class StatApp : public Block {

	public:
		static const uint FIRSTCOL = 1;
		static const uint JNUMFIRSTDISP = 2;
		static const uint NCOL = 3;
		static const uint NDISP = 4;

	public:
		StatApp(const uint firstcol = 1, const uint jnumFirstdisp = 1, const uint ncol = 9, const uint ndisp = 25);

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
	  * StatShr (full: StatShrQryMsdcPrsList)
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
	  * StgIac (full: StgIacQryMsdcPrsList)
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

