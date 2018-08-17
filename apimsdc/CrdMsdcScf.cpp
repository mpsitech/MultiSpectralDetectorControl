/**
  * \file CrdMsdcScf.cpp
  * API code for job CrdMsdcScf (implementation)
  * \author Alexander Wirthmueller
  * \date created: 15 Aug 2018
  * \date modified: 15 Aug 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "CrdMsdcScf.h"

/******************************************************************************
 class CrdMsdcScf::VecVDo
 ******************************************************************************/

uint CrdMsdcScf::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "close") return CLOSE;
	if (s == "mitappabtclick") return MITAPPABTCLICK;

	return(0);
};

string CrdMsdcScf::VecVDo::getSref(
			const uint ix
		) {
	if (ix == CLOSE) return("close");
	if (ix == MITAPPABTCLICK) return("MitAppAbtClick");

	return("");
};

/******************************************************************************
 class CrdMsdcScf::VecVSge
 ******************************************************************************/

uint CrdMsdcScf::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	if (s == "alrmsdcabt") return ALRMSDCABT;

	return(0);
};

string CrdMsdcScf::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	if (ix == ALRMSDCABT) return("alrmsdcabt");

	return("");
};

/******************************************************************************
 class CrdMsdcScf::ContInf
 ******************************************************************************/

CrdMsdcScf::ContInf::ContInf(
			const uint numFSge
			, const string& MrlAppHlp
		) : Block() {
	this->numFSge = numFSge;
	this->MrlAppHlp = MrlAppHlp;

	mask = {NUMFSGE, MRLAPPHLP};
};

bool CrdMsdcScf::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfMsdcScf");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfMsdcScf";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFSge", numFSge)) add(NUMFSGE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "MrlAppHlp", MrlAppHlp)) add(MRLAPPHLP);
	};

	return basefound;
};

set<uint> CrdMsdcScf::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFSge == comp->numFSge) insert(items, NUMFSGE);
	if (MrlAppHlp == comp->MrlAppHlp) insert(items, MRLAPPHLP);

	return(items);
};

set<uint> CrdMsdcScf::ContInf::diff(
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
 class CrdMsdcScf::StatApp
 ******************************************************************************/

CrdMsdcScf::StatApp::StatApp(
			const uint ixMsdcVReqitmode
			, const usmallint latency
			, const string& shortMenu
			, const uint widthMenu
			, const bool initdoneSource
			, const bool initdoneAcquis
			, const bool initdoneActu
			, const bool initdonePrcctl
			, const bool initdoneHeadbar
		) : Block() {
	this->ixMsdcVReqitmode = ixMsdcVReqitmode;
	this->latency = latency;
	this->shortMenu = shortMenu;
	this->widthMenu = widthMenu;
	this->initdoneSource = initdoneSource;
	this->initdoneAcquis = initdoneAcquis;
	this->initdoneActu = initdoneActu;
	this->initdonePrcctl = initdonePrcctl;
	this->initdoneHeadbar = initdoneHeadbar;

	mask = {IXMSDCVREQITMODE, LATENCY, SHORTMENU, WIDTHMENU, INITDONESOURCE, INITDONEACQUIS, INITDONEACTU, INITDONEPRCCTL, INITDONEHEADBAR};
};

bool CrdMsdcScf::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxMsdcVReqitmode;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppMsdcScf");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppMsdcScf";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxMsdcVReqitmode", srefIxMsdcVReqitmode)) {
			ixMsdcVReqitmode = VecMsdcVReqitmode::getIx(srefIxMsdcVReqitmode);
			add(IXMSDCVREQITMODE);
		};
		if (extractUsmallintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "latency", latency)) add(LATENCY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "shortMenu", shortMenu)) add(SHORTMENU);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "widthMenu", widthMenu)) add(WIDTHMENU);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneSource", initdoneSource)) add(INITDONESOURCE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneAcquis", initdoneAcquis)) add(INITDONEACQUIS);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneActu", initdoneActu)) add(INITDONEACTU);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdonePrcctl", initdonePrcctl)) add(INITDONEPRCCTL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneHeadbar", initdoneHeadbar)) add(INITDONEHEADBAR);
	};

	return basefound;
};

set<uint> CrdMsdcScf::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixMsdcVReqitmode == comp->ixMsdcVReqitmode) insert(items, IXMSDCVREQITMODE);
	if (latency == comp->latency) insert(items, LATENCY);
	if (shortMenu == comp->shortMenu) insert(items, SHORTMENU);
	if (widthMenu == comp->widthMenu) insert(items, WIDTHMENU);
	if (initdoneSource == comp->initdoneSource) insert(items, INITDONESOURCE);
	if (initdoneAcquis == comp->initdoneAcquis) insert(items, INITDONEACQUIS);
	if (initdoneActu == comp->initdoneActu) insert(items, INITDONEACTU);
	if (initdonePrcctl == comp->initdonePrcctl) insert(items, INITDONEPRCCTL);
	if (initdoneHeadbar == comp->initdoneHeadbar) insert(items, INITDONEHEADBAR);

	return(items);
};

set<uint> CrdMsdcScf::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXMSDCVREQITMODE, LATENCY, SHORTMENU, WIDTHMENU, INITDONESOURCE, INITDONEACQUIS, INITDONEACTU, INITDONEPRCCTL, INITDONEHEADBAR};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdMsdcScf::StatShr
 ******************************************************************************/

CrdMsdcScf::StatShr::StatShr(
			const string& scrJrefSource
			, const string& scrJrefAcquis
			, const string& scrJrefActu
			, const string& scrJrefPrcctl
			, const string& scrJrefHeadbar
		) : Block() {
	this->scrJrefSource = scrJrefSource;
	this->scrJrefAcquis = scrJrefAcquis;
	this->scrJrefActu = scrJrefActu;
	this->scrJrefPrcctl = scrJrefPrcctl;
	this->scrJrefHeadbar = scrJrefHeadbar;

	mask = {SCRJREFSOURCE, SCRJREFACQUIS, SCRJREFACTU, SCRJREFPRCCTL, SCRJREFHEADBAR};
};

bool CrdMsdcScf::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrMsdcScf");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrMsdcScf";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefSource", scrJrefSource)) add(SCRJREFSOURCE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefAcquis", scrJrefAcquis)) add(SCRJREFACQUIS);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefActu", scrJrefActu)) add(SCRJREFACTU);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefPrcctl", scrJrefPrcctl)) add(SCRJREFPRCCTL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefHeadbar", scrJrefHeadbar)) add(SCRJREFHEADBAR);
	};

	return basefound;
};

set<uint> CrdMsdcScf::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (scrJrefSource == comp->scrJrefSource) insert(items, SCRJREFSOURCE);
	if (scrJrefAcquis == comp->scrJrefAcquis) insert(items, SCRJREFACQUIS);
	if (scrJrefActu == comp->scrJrefActu) insert(items, SCRJREFACTU);
	if (scrJrefPrcctl == comp->scrJrefPrcctl) insert(items, SCRJREFPRCCTL);
	if (scrJrefHeadbar == comp->scrJrefHeadbar) insert(items, SCRJREFHEADBAR);

	return(items);
};

set<uint> CrdMsdcScf::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {SCRJREFSOURCE, SCRJREFACQUIS, SCRJREFACTU, SCRJREFPRCCTL, SCRJREFHEADBAR};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdMsdcScf::Tag
 ******************************************************************************/

CrdMsdcScf::Tag::Tag(
			const string& MitAppAbt
			, const string& MrlAppHlp
		) : Block() {
	this->MitAppAbt = MitAppAbt;
	this->MrlAppHlp = MrlAppHlp;

	mask = {MITAPPABT, MRLAPPHLP};
};

bool CrdMsdcScf::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagMsdcScf");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemMsdcScf";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitAppAbt", MitAppAbt)) add(MITAPPABT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MrlAppHlp", MrlAppHlp)) add(MRLAPPHLP);
	};

	return basefound;
};

/******************************************************************************
 class CrdMsdcScf::DpchAppDo
 ******************************************************************************/

CrdMsdcScf::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) : DpchAppMsdc(VecMsdcVDpch::DPCHAPPMSDCSCFDO, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string CrdMsdcScf::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void CrdMsdcScf::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppMsdcScfDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/msdc");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class CrdMsdcScf::DpchEngData
 ******************************************************************************/

CrdMsdcScf::DpchEngData::DpchEngData() : DpchEngMsdc(VecMsdcVDpch::DPCHENGMSDCSCFDATA) {
	feedFSge.tag = "FeedFSge";
};

string CrdMsdcScf::DpchEngData::getSrefsMask() {
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

void CrdMsdcScf::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngMsdcScfData");
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

