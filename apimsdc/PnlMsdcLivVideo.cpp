/**
  * \file PnlMsdcLivVideo.cpp
  * API code for job PnlMsdcLivVideo (implementation)
  * \author Alexander Wirthmueller
  * \date created: 29 Aug 2018
  * \date modified: 29 Aug 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "PnlMsdcLivVideo.h"

/******************************************************************************
 class PnlMsdcLivVideo::VecVDo
 ******************************************************************************/

uint PnlMsdcLivVideo::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butmasterclick") return BUTMASTERCLICK;
	if (s == "butplayclick") return BUTPLAYCLICK;
	if (s == "butstopclick") return BUTSTOPCLICK;

	return(0);
};

string PnlMsdcLivVideo::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTMASTERCLICK) return("ButMasterClick");
	if (ix == BUTPLAYCLICK) return("ButPlayClick");
	if (ix == BUTSTOPCLICK) return("ButStopClick");

	return("");
};

/******************************************************************************
 class PnlMsdcLivVideo::VecVSource
 ******************************************************************************/

uint PnlMsdcLivVideo::VecVSource::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "void") return VOID;
	if (s == "visl") return VISL;
	if (s == "visr") return VISR;
	if (s == "lwir") return LWIR;

	return(0);
};

string PnlMsdcLivVideo::VecVSource::getSref(
			const uint ix
		) {
	if (ix == VOID) return("void");
	if (ix == VISL) return("visl");
	if (ix == VISR) return("visr");
	if (ix == LWIR) return("lwir");

	return("");
};

/******************************************************************************
 class PnlMsdcLivVideo::ContIac
 ******************************************************************************/

PnlMsdcLivVideo::ContIac::ContIac(
			const uint numFPupSrc
			, const uint numFPupRes
			, const double SldExt
			, const double SldFcs
		) :
			Block()
		{
	this->numFPupSrc = numFPupSrc;
	this->numFPupRes = numFPupRes;
	this->SldExt = SldExt;
	this->SldFcs = SldFcs;

	mask = {NUMFPUPSRC, NUMFPUPRES, SLDEXT, SLDFCS};
};

bool PnlMsdcLivVideo::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacMsdcLivVideo");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacMsdcLivVideo";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupSrc", numFPupSrc)) add(NUMFPUPSRC);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupRes", numFPupRes)) add(NUMFPUPRES);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "SldExt", SldExt)) add(SLDEXT);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "SldFcs", SldFcs)) add(SLDFCS);
	};

	return basefound;
};

void PnlMsdcLivVideo::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacMsdcLivVideo";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacMsdcLivVideo";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFPupSrc", numFPupSrc);
		writeUintAttr(wr, itemtag, "sref", "numFPupRes", numFPupRes);
		writeDoubleAttr(wr, itemtag, "sref", "SldExt", SldExt);
		writeDoubleAttr(wr, itemtag, "sref", "SldFcs", SldFcs);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlMsdcLivVideo::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFPupSrc == comp->numFPupSrc) insert(items, NUMFPUPSRC);
	if (numFPupRes == comp->numFPupRes) insert(items, NUMFPUPRES);
	if (compareDouble(SldExt, comp->SldExt) < 1.0e-4) insert(items, SLDEXT);
	if (compareDouble(SldFcs, comp->SldFcs) < 1.0e-4) insert(items, SLDFCS);

	return(items);
};

set<uint> PnlMsdcLivVideo::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {, NUMFPUPRES, SLDEXT, SLDFCS};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlMsdcLivVideo::ContInf
 ******************************************************************************/

PnlMsdcLivVideo::ContInf::ContInf(
			const bool ButMasterOn
		) :
			Block()
		{
	this->ButMasterOn = ButMasterOn;

	mask = {BUTMASTERON};
};

bool PnlMsdcLivVideo::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfMsdcLivVideo");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfMsdcLivVideo";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "ButMasterOn", ButMasterOn)) add(BUTMASTERON);
	};

	return basefound;
};

set<uint> PnlMsdcLivVideo::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (ButMasterOn == comp->ButMasterOn) insert(items, BUTMASTERON);

	return(items);
};

set<uint> PnlMsdcLivVideo::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlMsdcLivVideo::StatApp
 ******************************************************************************/

PnlMsdcLivVideo::StatApp::StatApp(
			const uint ixMsdcVExpstate
		) :
			Block()
		{
	this->ixMsdcVExpstate = ixMsdcVExpstate;

	mask = {IXMSDCVEXPSTATE};
};

bool PnlMsdcLivVideo::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxMsdcVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppMsdcLivVideo");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppMsdcLivVideo";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxMsdcVExpstate", srefIxMsdcVExpstate)) {
			ixMsdcVExpstate = VecMsdcVExpstate::getIx(srefIxMsdcVExpstate);
			add(IXMSDCVEXPSTATE);
		};
	};

	return basefound;
};

set<uint> PnlMsdcLivVideo::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixMsdcVExpstate == comp->ixMsdcVExpstate) insert(items, IXMSDCVEXPSTATE);

	return(items);
};

set<uint> PnlMsdcLivVideo::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXMSDCVEXPSTATE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlMsdcLivVideo::StatShr
 ******************************************************************************/

PnlMsdcLivVideo::StatShr::StatShr(
			const bool PupResAvail
			, const bool ButPlayActive
			, const bool ButStopActive
			, const bool SldExtAvail
			, const bool SldExtActive
			, const double SldExtMin
			, const double SldExtMax
			, const double SldExtRast
			, const bool SldFcsAvail
			, const bool SldFcsActive
			, const double SldFcsMin
			, const double SldFcsMax
		) :
			Block()
		{
	this->PupResAvail = PupResAvail;
	this->ButPlayActive = ButPlayActive;
	this->ButStopActive = ButStopActive;
	this->SldExtAvail = SldExtAvail;
	this->SldExtActive = SldExtActive;
	this->SldExtMin = SldExtMin;
	this->SldExtMax = SldExtMax;
	this->SldExtRast = SldExtRast;
	this->SldFcsAvail = SldFcsAvail;
	this->SldFcsActive = SldFcsActive;
	this->SldFcsMin = SldFcsMin;
	this->SldFcsMax = SldFcsMax;

	mask = {PUPRESAVAIL, BUTPLAYACTIVE, BUTSTOPACTIVE, SLDEXTAVAIL, SLDEXTACTIVE, SLDEXTMIN, SLDEXTMAX, SLDEXTRAST, SLDFCSAVAIL, SLDFCSACTIVE, SLDFCSMIN, SLDFCSMAX};
};

bool PnlMsdcLivVideo::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrMsdcLivVideo");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrMsdcLivVideo";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "PupResAvail", PupResAvail)) add(PUPRESAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButPlayActive", ButPlayActive)) add(BUTPLAYACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButStopActive", ButStopActive)) add(BUTSTOPACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "SldExtAvail", SldExtAvail)) add(SLDEXTAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "SldExtActive", SldExtActive)) add(SLDEXTACTIVE);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "SldExtMin", SldExtMin)) add(SLDEXTMIN);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "SldExtMax", SldExtMax)) add(SLDEXTMAX);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "SldExtRast", SldExtRast)) add(SLDEXTRAST);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "SldFcsAvail", SldFcsAvail)) add(SLDFCSAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "SldFcsActive", SldFcsActive)) add(SLDFCSACTIVE);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "SldFcsMin", SldFcsMin)) add(SLDFCSMIN);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "SldFcsMax", SldFcsMax)) add(SLDFCSMAX);
	};

	return basefound;
};

set<uint> PnlMsdcLivVideo::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (PupResAvail == comp->PupResAvail) insert(items, PUPRESAVAIL);
	if (ButPlayActive == comp->ButPlayActive) insert(items, BUTPLAYACTIVE);
	if (ButStopActive == comp->ButStopActive) insert(items, BUTSTOPACTIVE);
	if (SldExtAvail == comp->SldExtAvail) insert(items, SLDEXTAVAIL);
	if (SldExtActive == comp->SldExtActive) insert(items, SLDEXTACTIVE);
	if (compareDouble(SldExtMin, comp->SldExtMin) < 1.0e-4) insert(items, SLDEXTMIN);
	if (compareDouble(SldExtMax, comp->SldExtMax) < 1.0e-4) insert(items, SLDEXTMAX);
	if (compareDouble(SldExtRast, comp->SldExtRast) < 1.0e-4) insert(items, SLDEXTRAST);
	if (SldFcsAvail == comp->SldFcsAvail) insert(items, SLDFCSAVAIL);
	if (SldFcsActive == comp->SldFcsActive) insert(items, SLDFCSACTIVE);
	if (compareDouble(SldFcsMin, comp->SldFcsMin) < 1.0e-4) insert(items, SLDFCSMIN);
	if (compareDouble(SldFcsMax, comp->SldFcsMax) < 1.0e-4) insert(items, SLDFCSMAX);

	return(items);
};

set<uint> PnlMsdcLivVideo::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {PUPRESAVAIL, BUTPLAYACTIVE, BUTSTOPACTIVE, SLDEXTAVAIL, SLDEXTACTIVE, SLDEXTMIN, SLDEXTMAX, SLDEXTRAST, SLDFCSAVAIL, SLDFCSACTIVE, SLDFCSMIN, SLDFCSMAX};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlMsdcLivVideo::Tag
 ******************************************************************************/

PnlMsdcLivVideo::Tag::Tag(
			const string& Cpt
			, const string& CptSrc
			, const string& CptRes
			, const string& CptExt
			, const string& CptFcs
		) :
			Block()
		{
	this->Cpt = Cpt;
	this->CptSrc = CptSrc;
	this->CptRes = CptRes;
	this->CptExt = CptExt;
	this->CptFcs = CptFcs;

	mask = {CPT, CPTSRC, CPTRES, CPTEXT, CPTFCS};
};

bool PnlMsdcLivVideo::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagMsdcLivVideo");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemMsdcLivVideo";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSrc", CptSrc)) add(CPTSRC);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptRes", CptRes)) add(CPTRES);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptExt", CptExt)) add(CPTEXT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptFcs", CptFcs)) add(CPTFCS);
	};

	return basefound;
};

/******************************************************************************
 class PnlMsdcLivVideo::DpchAppData
 ******************************************************************************/

PnlMsdcLivVideo::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) :
			DpchAppMsdc(VecMsdcVDpch::DPCHAPPMSDCLIVVIDEODATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlMsdcLivVideo::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlMsdcLivVideo::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppMsdcLivVideoData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/msdc");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlMsdcLivVideo::DpchAppDo
 ******************************************************************************/

PnlMsdcLivVideo::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppMsdc(VecMsdcVDpch::DPCHAPPMSDCLIVVIDEODO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlMsdcLivVideo::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlMsdcLivVideo::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppMsdcLivVideoDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/msdc");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlMsdcLivVideo::DpchEngData
 ******************************************************************************/

PnlMsdcLivVideo::DpchEngData::DpchEngData() :
			DpchEngMsdc(VecMsdcVDpch::DPCHENGMSDCLIVVIDEODATA)
		{
	feedFPupRes.tag = "FeedFPupRes";
	feedFPupSrc.tag = "FeedFPupSrc";
};

string PnlMsdcLivVideo::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFPUPRES)) ss.push_back("feedFPupRes");
	if (has(FEEDFPUPSRC)) ss.push_back("feedFPupSrc");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlMsdcLivVideo::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngMsdcLivVideoData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (feedFPupRes.readXML(docctx, basexpath, true)) add(FEEDFPUPRES);
		if (feedFPupSrc.readXML(docctx, basexpath, true)) add(FEEDFPUPSRC);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		continf = ContInf();
		feedFPupRes.clear();
		feedFPupSrc.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};

/******************************************************************************
 class PnlMsdcLivVideo::DpchEngLive
 ******************************************************************************/

PnlMsdcLivVideo::DpchEngLive::DpchEngLive() :
			DpchEngMsdc(VecMsdcVDpch::DPCHENGMSDCLIVVIDEOLIVE)
		{
};

string PnlMsdcLivVideo::DpchEngLive::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(RGB)) ss.push_back("rgb");
	if (has(RED)) ss.push_back("red");
	if (has(GREEN)) ss.push_back("green");
	if (has(BLUE)) ss.push_back("blue");
	if (has(GRAY)) ss.push_back("gray");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlMsdcLivVideo::DpchEngLive::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngMsdcLivVideoLive");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (extractUtinyintvecUclc(docctx, basexpath, "rgb", "", rgb)) add(RGB);
		if (extractUtinyintvecUclc(docctx, basexpath, "red", "", red)) add(RED);
		if (extractUtinyintvecUclc(docctx, basexpath, "green", "", green)) add(GREEN);
		if (extractUtinyintvecUclc(docctx, basexpath, "blue", "", blue)) add(BLUE);
		if (extractUsmallintvecUclc(docctx, basexpath, "gray", "", gray)) add(GRAY);
	} else {
		continf = ContInf();
	};
};

