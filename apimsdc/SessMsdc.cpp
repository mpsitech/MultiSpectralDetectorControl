/**
  * \file SessMsdc.cpp
  * API code for job SessMsdc (implementation)
  * \author Alexander Wirthmueller
  * \date created: 29 Aug 2018
  * \date modified: 29 Aug 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "SessMsdc.h"

/******************************************************************************
 class SessMsdc::StatShr
 ******************************************************************************/

SessMsdc::StatShr::StatShr(
			const string& scrJrefCrdnav
		) :
			Block()
		{
	this->scrJrefCrdnav = scrJrefCrdnav;

	mask = {SCRJREFCRDNAV};
};

bool SessMsdc::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrSessMsdc");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrSessMsdc";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefCrdnav", scrJrefCrdnav)) add(SCRJREFCRDNAV);
	};

	return basefound;
};

set<uint> SessMsdc::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (scrJrefCrdnav == comp->scrJrefCrdnav) insert(items, SCRJREFCRDNAV);

	return(items);
};

set<uint> SessMsdc::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {SCRJREFCRDNAV};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class SessMsdc::DpchEngData
 ******************************************************************************/

SessMsdc::DpchEngData::DpchEngData() :
			DpchEngMsdc(VecMsdcVDpch::DPCHENGSESSMSDCDATA)
		{
	feedFEnsSec.tag = "FeedFEnsSec";
};

string SessMsdc::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(FEEDFENSSEC)) ss.push_back("feedFEnsSec");
	if (has(STATSHR)) ss.push_back("statshr");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void SessMsdc::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngSessMsdcData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (feedFEnsSec.readXML(docctx, basexpath, true)) add(FEEDFENSSEC);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
	} else {
		feedFEnsSec.clear();
		statshr = StatShr();
	};
};

