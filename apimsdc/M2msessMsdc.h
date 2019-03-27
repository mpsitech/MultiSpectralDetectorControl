/**
  * \file M2msessMsdc.h
  * API code for job M2msessMsdc (declarations)
  * \author Alexander Wirthmueller
  * \date created: 18 Dec 2018
  * \date modified: 18 Dec 2018
  */

#ifndef M2MSESSMSDC_H
#define M2MSESSMSDC_H

#include "ApiMsdc_blks.h"

#define StatShrM2msessMsdc M2msessMsdc::StatShr

#define DpchEngM2msessMsdcData M2msessMsdc::DpchEngData

/**
  * M2msessMsdc
  */
namespace M2msessMsdc {
	/**
	  * StatShr (full: StatShrM2msessMsdc)
	  */
	class StatShr : public Block {

	public:
		static const uint SCRJREFACQADXL = 1;
		static const uint SCRJREFACQLWIR = 2;
		static const uint SCRJREFACQVISL = 3;
		static const uint SCRJREFACQVISR = 4;
		static const uint SCRJREFACTALIGN = 5;
		static const uint SCRJREFACTLED = 6;
		static const uint SCRJREFACTSERVO = 7;
		static const uint SCRJREFPRCSTEREO = 8;

	public:
		StatShr(const string& scrJrefAcqadxl = "", const string& scrJrefAcqlwir = "", const string& scrJrefAcqvisl = "", const string& scrJrefAcqvisr = "", const string& scrJrefActalign = "", const string& scrJrefActled = "", const string& scrJrefActservo = "", const string& scrJrefPrcstereo = "");

	public:
		string scrJrefAcqadxl;
		string scrJrefAcqlwir;
		string scrJrefAcqvisl;
		string scrJrefAcqvisr;
		string scrJrefActalign;
		string scrJrefActled;
		string scrJrefActservo;
		string scrJrefPrcstereo;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* DpchEngData (full: DpchEngM2msessMsdcData)
		*/
	class DpchEngData : public DpchEngMsdc {

	public:
		static const uint SCRJREF = 1;
		static const uint STATSHR = 2;

	public:
		DpchEngData();

	public:
		StatShr statshr;

	public:
		string getSrefsMask();

		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

