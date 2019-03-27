/**
  * \file PnlMsdcLivTrack.cpp
  * API code for job PnlMsdcLivTrack (implementation)
  * \author Alexander Wirthmueller
  * \date created: 18 Dec 2018
  * \date modified: 18 Dec 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "PnlMsdcLivTrack.h"

/******************************************************************************
 class PnlMsdcLivTrack::VecVDo
 ******************************************************************************/

uint PnlMsdcLivTrack::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butregularizeclick") return BUTREGULARIZECLICK;
	if (s == "butminimizeclick") return BUTMINIMIZECLICK;
	if (s == "butmasterclick") return BUTMASTERCLICK;

	return(0);
};

string PnlMsdcLivTrack::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");
	if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");
	if (ix == BUTMASTERCLICK) return("ButMasterClick");

	return("");
};

/******************************************************************************
 class PnlMsdcLivTrack::ContIac
 ******************************************************************************/

PnlMsdcLivTrack::ContIac::ContIac(
			const uint numFPupAmf
			, const int UpdApr
			, const bool ChkVid
			, const bool ChkWid
		) :
			Block()
		{
	this->numFPupAmf = numFPupAmf;
	this->UpdApr = UpdApr;
	this->ChkVid = ChkVid;
	this->ChkWid = ChkWid;

	mask = {NUMFPUPAMF, UPDAPR, CHKVID, CHKWID};
};

bool PnlMsdcLivTrack::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacMsdcLivTrack");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacMsdcLivTrack";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupAmf", numFPupAmf)) add(NUMFPUPAMF);
		if (extractIntAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "UpdApr", UpdApr)) add(UPDAPR);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "ChkVid", ChkVid)) add(CHKVID);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "ChkWid", ChkWid)) add(CHKWID);
	};

	return basefound;
};

void PnlMsdcLivTrack::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacMsdcLivTrack";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacMsdcLivTrack";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFPupAmf", numFPupAmf);
		writeIntAttr(wr, itemtag, "sref", "UpdApr", UpdApr);
		writeBoolAttr(wr, itemtag, "sref", "ChkVid", ChkVid);
		writeBoolAttr(wr, itemtag, "sref", "ChkWid", ChkWid);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlMsdcLivTrack::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFPupAmf == comp->numFPupAmf) insert(items, NUMFPUPAMF);
	if (UpdApr == comp->UpdApr) insert(items, UPDAPR);
	if (ChkVid == comp->ChkVid) insert(items, CHKVID);
	if (ChkWid == comp->ChkWid) insert(items, CHKWID);

	return(items);
};

set<uint> PnlMsdcLivTrack::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFPUPAMF, UPDAPR, CHKVID, CHKWID};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlMsdcLivTrack::ContInf
 ******************************************************************************/

PnlMsdcLivTrack::ContInf::ContInf(
			const bool ButMasterOn
			, const string& TxtVpx
			, const string& TxtVpy
			, const string& TxtWpx
			, const string& TxtWpy
			, const string& TxtDis
		) :
			Block()
		{
	this->ButMasterOn = ButMasterOn;
	this->TxtVpx = TxtVpx;
	this->TxtVpy = TxtVpy;
	this->TxtWpx = TxtWpx;
	this->TxtWpy = TxtWpy;
	this->TxtDis = TxtDis;

	mask = {BUTMASTERON, TXTVPX, TXTVPY, TXTWPX, TXTWPY, TXTDIS};
};

bool PnlMsdcLivTrack::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfMsdcLivTrack");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfMsdcLivTrack";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "ButMasterOn", ButMasterOn)) add(BUTMASTERON);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtVpx", TxtVpx)) add(TXTVPX);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtVpy", TxtVpy)) add(TXTVPY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtWpx", TxtWpx)) add(TXTWPX);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtWpy", TxtWpy)) add(TXTWPY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtDis", TxtDis)) add(TXTDIS);
	};

	return basefound;
};

set<uint> PnlMsdcLivTrack::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (ButMasterOn == comp->ButMasterOn) insert(items, BUTMASTERON);
	if (TxtVpx == comp->TxtVpx) insert(items, TXTVPX);
	if (TxtVpy == comp->TxtVpy) insert(items, TXTVPY);
	if (TxtWpx == comp->TxtWpx) insert(items, TXTWPX);
	if (TxtWpy == comp->TxtWpy) insert(items, TXTWPY);
	if (TxtDis == comp->TxtDis) insert(items, TXTDIS);

	return(items);
};

set<uint> PnlMsdcLivTrack::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTMASTERON, TXTVPX, TXTVPY, TXTWPX, TXTWPY, TXTDIS};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlMsdcLivTrack::StatShr
 ******************************************************************************/

PnlMsdcLivTrack::StatShr::StatShr(
			const uint ixMsdcVExpstate
			, const bool PupAmfActive
			, const bool UpdAprActive
			, const int UpdAprMin
			, const int UpdAprMax
			, const bool ChkVidActive
			, const bool ChkWidActive
		) :
			Block()
		{
	this->ixMsdcVExpstate = ixMsdcVExpstate;
	this->PupAmfActive = PupAmfActive;
	this->UpdAprActive = UpdAprActive;
	this->UpdAprMin = UpdAprMin;
	this->UpdAprMax = UpdAprMax;
	this->ChkVidActive = ChkVidActive;
	this->ChkWidActive = ChkWidActive;

	mask = {IXMSDCVEXPSTATE, PUPAMFACTIVE, UPDAPRACTIVE, UPDAPRMIN, UPDAPRMAX, CHKVIDACTIVE, CHKWIDACTIVE};
};

bool PnlMsdcLivTrack::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxMsdcVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrMsdcLivTrack");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrMsdcLivTrack";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxMsdcVExpstate", srefIxMsdcVExpstate)) {
			ixMsdcVExpstate = VecMsdcVExpstate::getIx(srefIxMsdcVExpstate);
			add(IXMSDCVEXPSTATE);
		};
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "PupAmfActive", PupAmfActive)) add(PUPAMFACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "UpdAprActive", UpdAprActive)) add(UPDAPRACTIVE);
		if (extractIntAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "UpdAprMin", UpdAprMin)) add(UPDAPRMIN);
		if (extractIntAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "UpdAprMax", UpdAprMax)) add(UPDAPRMAX);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ChkVidActive", ChkVidActive)) add(CHKVIDACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ChkWidActive", ChkWidActive)) add(CHKWIDACTIVE);
	};

	return basefound;
};

set<uint> PnlMsdcLivTrack::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixMsdcVExpstate == comp->ixMsdcVExpstate) insert(items, IXMSDCVEXPSTATE);
	if (PupAmfActive == comp->PupAmfActive) insert(items, PUPAMFACTIVE);
	if (UpdAprActive == comp->UpdAprActive) insert(items, UPDAPRACTIVE);
	if (UpdAprMin == comp->UpdAprMin) insert(items, UPDAPRMIN);
	if (UpdAprMax == comp->UpdAprMax) insert(items, UPDAPRMAX);
	if (ChkVidActive == comp->ChkVidActive) insert(items, CHKVIDACTIVE);
	if (ChkWidActive == comp->ChkWidActive) insert(items, CHKWIDACTIVE);

	return(items);
};

set<uint> PnlMsdcLivTrack::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXMSDCVEXPSTATE, PUPAMFACTIVE, UPDAPRACTIVE, UPDAPRMIN, UPDAPRMAX, CHKVIDACTIVE, CHKWIDACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlMsdcLivTrack::Tag
 ******************************************************************************/

PnlMsdcLivTrack::Tag::Tag(
			const string& Cpt
			, const string& HdgAls
			, const string& CptAmf
			, const string& CptApr
			, const string& HdgVsl
			, const string& CptVid
			, const string& CptVpx
			, const string& CptVpy
			, const string& HdgWsr
			, const string& CptWid
			, const string& CptWpx
			, const string& CptWpy
			, const string& CptDis
		) :
			Block()
		{
	this->Cpt = Cpt;
	this->HdgAls = HdgAls;
	this->CptAmf = CptAmf;
	this->CptApr = CptApr;
	this->HdgVsl = HdgVsl;
	this->CptVid = CptVid;
	this->CptVpx = CptVpx;
	this->CptVpy = CptVpy;
	this->HdgWsr = HdgWsr;
	this->CptWid = CptWid;
	this->CptWpx = CptWpx;
	this->CptWpy = CptWpy;
	this->CptDis = CptDis;

	mask = {CPT, HDGALS, CPTAMF, CPTAPR, HDGVSL, CPTVID, CPTVPX, CPTVPY, HDGWSR, CPTWID, CPTWPX, CPTWPY, CPTDIS};
};

bool PnlMsdcLivTrack::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagMsdcLivTrack");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemMsdcLivTrack";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "HdgAls", HdgAls)) add(HDGALS);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptAmf", CptAmf)) add(CPTAMF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptApr", CptApr)) add(CPTAPR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "HdgVsl", HdgVsl)) add(HDGVSL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptVid", CptVid)) add(CPTVID);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptVpx", CptVpx)) add(CPTVPX);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptVpy", CptVpy)) add(CPTVPY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "HdgWsr", HdgWsr)) add(HDGWSR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptWid", CptWid)) add(CPTWID);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptWpx", CptWpx)) add(CPTWPX);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptWpy", CptWpy)) add(CPTWPY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptDis", CptDis)) add(CPTDIS);
	};

	return basefound;
};

/******************************************************************************
 class PnlMsdcLivTrack::DpchAppData
 ******************************************************************************/

PnlMsdcLivTrack::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) :
			DpchAppMsdc(VecMsdcVDpch::DPCHAPPMSDCLIVTRACKDATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlMsdcLivTrack::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlMsdcLivTrack::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppMsdcLivTrackData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/msdc");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlMsdcLivTrack::DpchAppDo
 ******************************************************************************/

PnlMsdcLivTrack::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppMsdc(VecMsdcVDpch::DPCHAPPMSDCLIVTRACKDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlMsdcLivTrack::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlMsdcLivTrack::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppMsdcLivTrackDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/msdc");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlMsdcLivTrack::DpchEngData
 ******************************************************************************/

PnlMsdcLivTrack::DpchEngData::DpchEngData() :
			DpchEngMsdc(VecMsdcVDpch::DPCHENGMSDCLIVTRACKDATA)
		{
	feedFPupAmf.tag = "FeedFPupAmf";
};

string PnlMsdcLivTrack::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFPUPAMF)) ss.push_back("feedFPupAmf");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlMsdcLivTrack::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngMsdcLivTrackData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (feedFPupAmf.readXML(docctx, basexpath, true)) add(FEEDFPUPAMF);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		continf = ContInf();
		feedFPupAmf.clear();
		statshr = StatShr();
		tag = Tag();
	};
};

