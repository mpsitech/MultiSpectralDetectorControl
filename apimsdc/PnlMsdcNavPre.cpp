/**
  * \file PnlMsdcNavPre.cpp
  * API code for job PnlMsdcNavPre (implementation)
  * \author Alexander Wirthmueller
  * \date created: 18 Dec 2018
  * \date modified: 18 Dec 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "PnlMsdcNavPre.h"

/******************************************************************************
 class PnlMsdcNavPre::VecVDo
 ******************************************************************************/

uint PnlMsdcNavPre::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butdatremoveclick") return BUTDATREMOVECLICK;
	if (s == "butprdremoveclick") return BUTPRDREMOVECLICK;

	return(0);
};

string PnlMsdcNavPre::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTDATREMOVECLICK) return("ButDatRemoveClick");
	if (ix == BUTPRDREMOVECLICK) return("ButPrdRemoveClick");

	return("");
};

/******************************************************************************
 class PnlMsdcNavPre::ContInf
 ******************************************************************************/

PnlMsdcNavPre::ContInf::ContInf(
			const string& TxtDat
			, const string& TxtPrd
		) :
			Block()
		{
	this->TxtDat = TxtDat;
	this->TxtPrd = TxtPrd;

	mask = {TXTDAT, TXTPRD};
};

bool PnlMsdcNavPre::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfMsdcNavPre");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfMsdcNavPre";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtDat", TxtDat)) add(TXTDAT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtPrd", TxtPrd)) add(TXTPRD);
	};

	return basefound;
};

set<uint> PnlMsdcNavPre::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtDat == comp->TxtDat) insert(items, TXTDAT);
	if (TxtPrd == comp->TxtPrd) insert(items, TXTPRD);

	return(items);
};

set<uint> PnlMsdcNavPre::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTDAT, TXTPRD};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlMsdcNavPre::StatShr
 ******************************************************************************/

PnlMsdcNavPre::StatShr::StatShr(
			const bool TxtDatAvail
			, const bool TxtPrdAvail
		) :
			Block()
		{
	this->TxtDatAvail = TxtDatAvail;
	this->TxtPrdAvail = TxtPrdAvail;

	mask = {TXTDATAVAIL, TXTPRDAVAIL};
};

bool PnlMsdcNavPre::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrMsdcNavPre");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrMsdcNavPre";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtDatAvail", TxtDatAvail)) add(TXTDATAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtPrdAvail", TxtPrdAvail)) add(TXTPRDAVAIL);
	};

	return basefound;
};

set<uint> PnlMsdcNavPre::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (TxtDatAvail == comp->TxtDatAvail) insert(items, TXTDATAVAIL);
	if (TxtPrdAvail == comp->TxtPrdAvail) insert(items, TXTPRDAVAIL);

	return(items);
};

set<uint> PnlMsdcNavPre::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTDATAVAIL, TXTPRDAVAIL};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlMsdcNavPre::Tag
 ******************************************************************************/

PnlMsdcNavPre::Tag::Tag(
			const string& CptDat
			, const string& CptPrd
		) :
			Block()
		{
	this->CptDat = CptDat;
	this->CptPrd = CptPrd;

	mask = {CPTDAT, CPTPRD};
};

bool PnlMsdcNavPre::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagMsdcNavPre");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemMsdcNavPre";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptDat", CptDat)) add(CPTDAT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptPrd", CptPrd)) add(CPTPRD);
	};

	return basefound;
};

/******************************************************************************
 class PnlMsdcNavPre::DpchAppDo
 ******************************************************************************/

PnlMsdcNavPre::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppMsdc(VecMsdcVDpch::DPCHAPPMSDCNAVPREDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlMsdcNavPre::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlMsdcNavPre::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppMsdcNavPreDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/msdc");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlMsdcNavPre::DpchEngData
 ******************************************************************************/

PnlMsdcNavPre::DpchEngData::DpchEngData() :
			DpchEngMsdc(VecMsdcVDpch::DPCHENGMSDCNAVPREDATA)
		{
};

string PnlMsdcNavPre::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlMsdcNavPre::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngMsdcNavPreData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		continf = ContInf();
		statshr = StatShr();
		tag = Tag();
	};
};

