/**
  * \file M2msessMsdc.cpp
  * API code for job M2msessMsdc (implementation)
  * \author Alexander Wirthmueller
  * \date created: 15 Aug 2018
  * \date modified: 15 Aug 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "M2msessMsdc.h"

/******************************************************************************
 class M2msessMsdc::StatShr
 ******************************************************************************/

M2msessMsdc::StatShr::StatShr(
			const string& scrJrefAcqadxl
			, const string& scrJrefAcqlwir
			, const string& scrJrefAcqvisl
			, const string& scrJrefAcqvisr
			, const string& scrJrefActalign
			, const string& scrJrefActled
			, const string& scrJrefActservo
			, const string& scrJrefPrcstereo
		) : Block() {
	this->scrJrefAcqadxl = scrJrefAcqadxl;
	this->scrJrefAcqlwir = scrJrefAcqlwir;
	this->scrJrefAcqvisl = scrJrefAcqvisl;
	this->scrJrefAcqvisr = scrJrefAcqvisr;
	this->scrJrefActalign = scrJrefActalign;
	this->scrJrefActled = scrJrefActled;
	this->scrJrefActservo = scrJrefActservo;
	this->scrJrefPrcstereo = scrJrefPrcstereo;

	mask = {SCRJREFACQADXL, SCRJREFACQLWIR, SCRJREFACQVISL, SCRJREFACQVISR, SCRJREFACTALIGN, SCRJREFACTLED, SCRJREFACTSERVO, SCRJREFPRCSTEREO};
};

bool M2msessMsdc::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrM2msessMsdc");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrM2msessMsdc";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefAcqadxl", scrJrefAcqadxl)) add(SCRJREFACQADXL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefAcqlwir", scrJrefAcqlwir)) add(SCRJREFACQLWIR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefAcqvisl", scrJrefAcqvisl)) add(SCRJREFACQVISL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefAcqvisr", scrJrefAcqvisr)) add(SCRJREFACQVISR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefActalign", scrJrefActalign)) add(SCRJREFACTALIGN);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefActled", scrJrefActled)) add(SCRJREFACTLED);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefActservo", scrJrefActservo)) add(SCRJREFACTSERVO);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefPrcstereo", scrJrefPrcstereo)) add(SCRJREFPRCSTEREO);
	};

	return basefound;
};

set<uint> M2msessMsdc::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (scrJrefAcqadxl == comp->scrJrefAcqadxl) insert(items, SCRJREFACQADXL);
	if (scrJrefAcqlwir == comp->scrJrefAcqlwir) insert(items, SCRJREFACQLWIR);
	if (scrJrefAcqvisl == comp->scrJrefAcqvisl) insert(items, SCRJREFACQVISL);
	if (scrJrefAcqvisr == comp->scrJrefAcqvisr) insert(items, SCRJREFACQVISR);
	if (scrJrefActalign == comp->scrJrefActalign) insert(items, SCRJREFACTALIGN);
	if (scrJrefActled == comp->scrJrefActled) insert(items, SCRJREFACTLED);
	if (scrJrefActservo == comp->scrJrefActservo) insert(items, SCRJREFACTSERVO);
	if (scrJrefPrcstereo == comp->scrJrefPrcstereo) insert(items, SCRJREFPRCSTEREO);

	return(items);
};

set<uint> M2msessMsdc::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {SCRJREFACQADXL, SCRJREFACQLWIR, SCRJREFACQVISL, SCRJREFACQVISR, SCRJREFACTALIGN, SCRJREFACTLED, SCRJREFACTSERVO, SCRJREFPRCSTEREO};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class M2msessMsdc::DpchEngData
 ******************************************************************************/

M2msessMsdc::DpchEngData::DpchEngData() : DpchEngMsdc(VecMsdcVDpch::DPCHENGM2MSESSMSDCDATA) {
};

string M2msessMsdc::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(STATSHR)) ss.push_back("statshr");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void M2msessMsdc::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngM2msessMsdcData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
	} else {
		statshr = StatShr();
	};
};

