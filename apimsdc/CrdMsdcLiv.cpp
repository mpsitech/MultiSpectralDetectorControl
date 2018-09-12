/**
  * \file CrdMsdcLiv.cpp
  * API code for job CrdMsdcLiv (implementation)
  * \author Alexander Wirthmueller
  * \date created: 12 Sep 2018
  * \date modified: 12 Sep 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "CrdMsdcLiv.h"

/******************************************************************************
 class CrdMsdcLiv::VecVDo
 ******************************************************************************/

uint CrdMsdcLiv::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "close") return CLOSE;
	if (s == "mitappabtclick") return MITAPPABTCLICK;

	return(0);
};

string CrdMsdcLiv::VecVDo::getSref(
			const uint ix
		) {
	if (ix == CLOSE) return("close");
	if (ix == MITAPPABTCLICK) return("MitAppAbtClick");

	return("");
};

/******************************************************************************
 class CrdMsdcLiv::VecVSge
 ******************************************************************************/

uint CrdMsdcLiv::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	if (s == "alrmsdcabt") return ALRMSDCABT;

	return(0);
};

string CrdMsdcLiv::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	if (ix == ALRMSDCABT) return("alrmsdcabt");

	return("");
};

/******************************************************************************
 class CrdMsdcLiv::ContInf
 ******************************************************************************/

CrdMsdcLiv::ContInf::ContInf(
			const uint numFSge
			, const string& MrlAppHlp
		) :
			Block()
		{
	this->numFSge = numFSge;
	this->MrlAppHlp = MrlAppHlp;

	mask = {NUMFSGE, MRLAPPHLP};
};

bool CrdMsdcLiv::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfMsdcLiv");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfMsdcLiv";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFSge", numFSge)) add(NUMFSGE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "MrlAppHlp", MrlAppHlp)) add(MRLAPPHLP);
	};

	return basefound;
};

set<uint> CrdMsdcLiv::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFSge == comp->numFSge) insert(items, NUMFSGE);
	if (MrlAppHlp == comp->MrlAppHlp) insert(items, MRLAPPHLP);

	return(items);
};

set<uint> CrdMsdcLiv::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {, MRLAPPHLP};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdMsdcLiv::StatApp
 ******************************************************************************/

CrdMsdcLiv::StatApp::StatApp(
			const uint ixMsdcVReqitmode
			, const usmallint latency
			, const string& shortMenu
			, const uint widthMenu
			, const bool initdoneVideo
			, const bool initdoneAlign
			, const bool initdoneScill
			, const bool initdoneTrack
			, const bool initdoneHeadbar
		) :
			Block()
		{
	this->ixMsdcVReqitmode = ixMsdcVReqitmode;
	this->latency = latency;
	this->shortMenu = shortMenu;
	this->widthMenu = widthMenu;
	this->initdoneVideo = initdoneVideo;
	this->initdoneAlign = initdoneAlign;
	this->initdoneScill = initdoneScill;
	this->initdoneTrack = initdoneTrack;
	this->initdoneHeadbar = initdoneHeadbar;

	mask = {IXMSDCVREQITMODE, LATENCY, SHORTMENU, WIDTHMENU, INITDONEVIDEO, INITDONEALIGN, INITDONESCILL, INITDONETRACK, INITDONEHEADBAR};
};

bool CrdMsdcLiv::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxMsdcVReqitmode;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppMsdcLiv");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppMsdcLiv";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxMsdcVReqitmode", srefIxMsdcVReqitmode)) {
			ixMsdcVReqitmode = VecMsdcVReqitmode::getIx(srefIxMsdcVReqitmode);
			add(IXMSDCVREQITMODE);
		};
		if (extractUsmallintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "latency", latency)) add(LATENCY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "shortMenu", shortMenu)) add(SHORTMENU);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "widthMenu", widthMenu)) add(WIDTHMENU);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneVideo", initdoneVideo)) add(INITDONEVIDEO);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneAlign", initdoneAlign)) add(INITDONEALIGN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneScill", initdoneScill)) add(INITDONESCILL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneTrack", initdoneTrack)) add(INITDONETRACK);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneHeadbar", initdoneHeadbar)) add(INITDONEHEADBAR);
	};

	return basefound;
};

set<uint> CrdMsdcLiv::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixMsdcVReqitmode == comp->ixMsdcVReqitmode) insert(items, IXMSDCVREQITMODE);
	if (latency == comp->latency) insert(items, LATENCY);
	if (shortMenu == comp->shortMenu) insert(items, SHORTMENU);
	if (widthMenu == comp->widthMenu) insert(items, WIDTHMENU);
	if (initdoneVideo == comp->initdoneVideo) insert(items, INITDONEVIDEO);
	if (initdoneAlign == comp->initdoneAlign) insert(items, INITDONEALIGN);
	if (initdoneScill == comp->initdoneScill) insert(items, INITDONESCILL);
	if (initdoneTrack == comp->initdoneTrack) insert(items, INITDONETRACK);
	if (initdoneHeadbar == comp->initdoneHeadbar) insert(items, INITDONEHEADBAR);

	return(items);
};

set<uint> CrdMsdcLiv::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXMSDCVREQITMODE, LATENCY, SHORTMENU, WIDTHMENU, INITDONEVIDEO, INITDONEALIGN, INITDONESCILL, INITDONETRACK, INITDONEHEADBAR};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdMsdcLiv::StatShr
 ******************************************************************************/

CrdMsdcLiv::StatShr::StatShr(
			const string& scrJrefVideo
			, const string& scrJrefAlign
			, const string& scrJrefScill
			, const string& scrJrefTrack
			, const string& scrJrefHeadbar
		) :
			Block()
		{
	this->scrJrefVideo = scrJrefVideo;
	this->scrJrefAlign = scrJrefAlign;
	this->scrJrefScill = scrJrefScill;
	this->scrJrefTrack = scrJrefTrack;
	this->scrJrefHeadbar = scrJrefHeadbar;

	mask = {SCRJREFVIDEO, SCRJREFALIGN, SCRJREFSCILL, SCRJREFTRACK, SCRJREFHEADBAR};
};

bool CrdMsdcLiv::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrMsdcLiv");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrMsdcLiv";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefVideo", scrJrefVideo)) add(SCRJREFVIDEO);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefAlign", scrJrefAlign)) add(SCRJREFALIGN);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefScill", scrJrefScill)) add(SCRJREFSCILL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefTrack", scrJrefTrack)) add(SCRJREFTRACK);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefHeadbar", scrJrefHeadbar)) add(SCRJREFHEADBAR);
	};

	return basefound;
};

set<uint> CrdMsdcLiv::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (scrJrefVideo == comp->scrJrefVideo) insert(items, SCRJREFVIDEO);
	if (scrJrefAlign == comp->scrJrefAlign) insert(items, SCRJREFALIGN);
	if (scrJrefScill == comp->scrJrefScill) insert(items, SCRJREFSCILL);
	if (scrJrefTrack == comp->scrJrefTrack) insert(items, SCRJREFTRACK);
	if (scrJrefHeadbar == comp->scrJrefHeadbar) insert(items, SCRJREFHEADBAR);

	return(items);
};

set<uint> CrdMsdcLiv::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {SCRJREFVIDEO, SCRJREFALIGN, SCRJREFSCILL, SCRJREFTRACK, SCRJREFHEADBAR};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdMsdcLiv::Tag
 ******************************************************************************/

CrdMsdcLiv::Tag::Tag(
			const string& MitAppAbt
			, const string& MrlAppHlp
		) :
			Block()
		{
	this->MitAppAbt = MitAppAbt;
	this->MrlAppHlp = MrlAppHlp;

	mask = {MITAPPABT, MRLAPPHLP};
};

bool CrdMsdcLiv::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagMsdcLiv");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemMsdcLiv";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitAppAbt", MitAppAbt)) add(MITAPPABT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MrlAppHlp", MrlAppHlp)) add(MRLAPPHLP);
	};

	return basefound;
};

/******************************************************************************
 class CrdMsdcLiv::DpchAppDo
 ******************************************************************************/

CrdMsdcLiv::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppMsdc(VecMsdcVDpch::DPCHAPPMSDCLIVDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string CrdMsdcLiv::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void CrdMsdcLiv::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppMsdcLivDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/msdc");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class CrdMsdcLiv::DpchEngData
 ******************************************************************************/

CrdMsdcLiv::DpchEngData::DpchEngData() :
			DpchEngMsdc(VecMsdcVDpch::DPCHENGMSDCLIVDATA)
		{
	feedFSge.tag = "FeedFSge";
};

string CrdMsdcLiv::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFSGE)) ss.push_back("feedFSge");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void CrdMsdcLiv::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngMsdcLivData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (feedFSge.readXML(docctx, basexpath, true)) add(FEEDFSGE);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		continf = ContInf();
		feedFSge.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};

