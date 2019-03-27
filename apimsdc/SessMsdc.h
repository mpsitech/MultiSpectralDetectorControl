/**
  * \file SessMsdc.h
  * API code for job SessMsdc (declarations)
  * \author Alexander Wirthmueller
  * \date created: 18 Dec 2018
  * \date modified: 18 Dec 2018
  */

#ifndef SESSMSDC_H
#define SESSMSDC_H

#include "ApiMsdc_blks.h"

#define StatShrSessMsdc SessMsdc::StatShr

#define DpchEngSessMsdcData SessMsdc::DpchEngData

/**
  * SessMsdc
  */
namespace SessMsdc {
	/**
	  * StatShr (full: StatShrSessMsdc)
	  */
	class StatShr : public Block {

	public:
		static const uint SCRJREFCRDNAV = 1;

	public:
		StatShr(const string& scrJrefCrdnav = "");

	public:
		string scrJrefCrdnav;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* DpchEngData (full: DpchEngSessMsdcData)
		*/
	class DpchEngData : public DpchEngMsdc {

	public:
		static const uint SCRJREF = 1;
		static const uint FEEDFENSSEC = 2;
		static const uint STATSHR = 3;

	public:
		DpchEngData();

	public:
		Feed feedFEnsSec;
		StatShr statshr;

	public:
		string getSrefsMask();

		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

