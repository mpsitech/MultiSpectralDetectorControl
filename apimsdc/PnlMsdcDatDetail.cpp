/**
  * \file PnlMsdcDatDetail.cpp
  * API code for job PnlMsdcDatDetail (implementation)
  * \author Alexander Wirthmueller
  * \date created: 12 Sep 2018
  * \date modified: 12 Sep 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "PnlMsdcDatDetail.h"

/******************************************************************************
 class PnlMsdcDatDetail::VecVDo
 ******************************************************************************/

uint PnlMsdcDatDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	if (s == "butafteditclick") return BUTAFTEDITCLICK;
	if (s == "butprdviewclick") return BUTPRDVIEWCLICK;

	return(0);
};

string PnlMsdcDatDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	if (ix == BUTAFTEDITCLICK) return("ButAftEditClick");
	if (ix == BUTPRDVIEWCLICK) return("ButPrdViewClick");

	return("");
};

/******************************************************************************
 class PnlMsdcDatDetail::ContIac
 ******************************************************************************/

PnlMsdcDatDetail::ContIac::ContIac(
			const uint numFPupAft
			, const string& TxfAft
			, const string& TxfSta
			, const string& TxfSto
			, const string& TxfCmt
		) :
			Block()
		{
	this->numFPupAft = numFPupAft;
	this->TxfAft = TxfAft;
	this->TxfSta = TxfSta;
	this->TxfSto = TxfSto;
	this->TxfCmt = TxfCmt;

	mask = {NUMFPUPAFT, TXFAFT, TXFSTA, TXFSTO, TXFCMT};
};

bool PnlMsdcDatDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacMsdcDatDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacMsdcDatDetail";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupAft", numFPupAft)) add(NUMFPUPAFT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfAft", TxfAft)) add(TXFAFT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfSta", TxfSta)) add(TXFSTA);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfSto", TxfSto)) add(TXFSTO);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfCmt", TxfCmt)) add(TXFCMT);
	};

	return basefound;
};

void PnlMsdcDatDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacMsdcDatDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacMsdcDatDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFPupAft", numFPupAft);
		writeStringAttr(wr, itemtag, "sref", "TxfAft", TxfAft);
		writeStringAttr(wr, itemtag, "sref", "TxfSta", TxfSta);
		writeStringAttr(wr, itemtag, "sref", "TxfSto", TxfSto);
		writeStringAttr(wr, itemtag, "sref", "TxfCmt", TxfCmt);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlMsdcDatDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFPupAft == comp->numFPupAft) insert(items, NUMFPUPAFT);
	if (TxfAft == comp->TxfAft) insert(items, TXFAFT);
	if (TxfSta == comp->TxfSta) insert(items, TXFSTA);
	if (TxfSto == comp->TxfSto) insert(items, TXFSTO);
	if (TxfCmt == comp->TxfCmt) insert(items, TXFCMT);

	return(items);
};

set<uint> PnlMsdcDatDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {, TXFAFT, TXFSTA, TXFSTO, TXFCMT};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlMsdcDatDetail::ContInf
 ******************************************************************************/

PnlMsdcDatDetail::ContInf::ContInf(
			const string& TxtPrd
		) :
			Block()
		{
	this->TxtPrd = TxtPrd;

	mask = {TXTPRD};
};

bool PnlMsdcDatDetail::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfMsdcDatDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfMsdcDatDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtPrd", TxtPrd)) add(TXTPRD);
	};

	return basefound;
};

set<uint> PnlMsdcDatDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtPrd == comp->TxtPrd) insert(items, TXTPRD);

	return(items);
};

set<uint> PnlMsdcDatDetail::ContInf::diff(
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
 class PnlMsdcDatDetail::StatApp
 ******************************************************************************/

PnlMsdcDatDetail::StatApp::StatApp(
			const uint ixMsdcVExpstate
			, const bool PupAftAlt
		) :
			Block()
		{
	this->ixMsdcVExpstate = ixMsdcVExpstate;
	this->PupAftAlt = PupAftAlt;

	mask = {IXMSDCVEXPSTATE, PUPAFTALT};
};

bool PnlMsdcDatDetail::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxMsdcVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppMsdcDatDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppMsdcDatDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxMsdcVExpstate", srefIxMsdcVExpstate)) {
			ixMsdcVExpstate = VecMsdcVExpstate::getIx(srefIxMsdcVExpstate);
			add(IXMSDCVEXPSTATE);
		};
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "PupAftAlt", PupAftAlt)) add(PUPAFTALT);
	};

	return basefound;
};

set<uint> PnlMsdcDatDetail::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixMsdcVExpstate == comp->ixMsdcVExpstate) insert(items, IXMSDCVEXPSTATE);
	if (PupAftAlt == comp->PupAftAlt) insert(items, PUPAFTALT);

	return(items);
};

set<uint> PnlMsdcDatDetail::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXMSDCVEXPSTATE, PUPAFTALT};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlMsdcDatDetail::StatShr
 ******************************************************************************/

PnlMsdcDatDetail::StatShr::StatShr(
			const bool TxfAftValid
			, const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool PupAftActive
			, const bool ButAftEditAvail
			, const bool TxtPrdActive
			, const bool ButPrdViewAvail
			, const bool ButPrdViewActive
			, const bool TxfStaActive
			, const bool TxfStoActive
			, const bool TxfCmtActive
		) :
			Block()
		{
	this->TxfAftValid = TxfAftValid;
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;
	this->PupAftActive = PupAftActive;
	this->ButAftEditAvail = ButAftEditAvail;
	this->TxtPrdActive = TxtPrdActive;
	this->ButPrdViewAvail = ButPrdViewAvail;
	this->ButPrdViewActive = ButPrdViewActive;
	this->TxfStaActive = TxfStaActive;
	this->TxfStoActive = TxfStoActive;
	this->TxfCmtActive = TxfCmtActive;

	mask = {TXFAFTVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, PUPAFTACTIVE, BUTAFTEDITAVAIL, TXTPRDACTIVE, BUTPRDVIEWAVAIL, BUTPRDVIEWACTIVE, TXFSTAACTIVE, TXFSTOACTIVE, TXFCMTACTIVE};
};

bool PnlMsdcDatDetail::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrMsdcDatDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrMsdcDatDetail";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfAftValid", TxfAftValid)) add(TXFAFTVALID);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveAvail", ButSaveAvail)) add(BUTSAVEAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveActive", ButSaveActive)) add(BUTSAVEACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "PupAftActive", PupAftActive)) add(PUPAFTACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButAftEditAvail", ButAftEditAvail)) add(BUTAFTEDITAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtPrdActive", TxtPrdActive)) add(TXTPRDACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButPrdViewAvail", ButPrdViewAvail)) add(BUTPRDVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButPrdViewActive", ButPrdViewActive)) add(BUTPRDVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfStaActive", TxfStaActive)) add(TXFSTAACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfStoActive", TxfStoActive)) add(TXFSTOACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfCmtActive", TxfCmtActive)) add(TXFCMTACTIVE);
	};

	return basefound;
};

set<uint> PnlMsdcDatDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (TxfAftValid == comp->TxfAftValid) insert(items, TXFAFTVALID);
	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (PupAftActive == comp->PupAftActive) insert(items, PUPAFTACTIVE);
	if (ButAftEditAvail == comp->ButAftEditAvail) insert(items, BUTAFTEDITAVAIL);
	if (TxtPrdActive == comp->TxtPrdActive) insert(items, TXTPRDACTIVE);
	if (ButPrdViewAvail == comp->ButPrdViewAvail) insert(items, BUTPRDVIEWAVAIL);
	if (ButPrdViewActive == comp->ButPrdViewActive) insert(items, BUTPRDVIEWACTIVE);
	if (TxfStaActive == comp->TxfStaActive) insert(items, TXFSTAACTIVE);
	if (TxfStoActive == comp->TxfStoActive) insert(items, TXFSTOACTIVE);
	if (TxfCmtActive == comp->TxfCmtActive) insert(items, TXFCMTACTIVE);

	return(items);
};

set<uint> PnlMsdcDatDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFAFTVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, PUPAFTACTIVE, BUTAFTEDITAVAIL, TXTPRDACTIVE, BUTPRDVIEWAVAIL, BUTPRDVIEWACTIVE, TXFSTAACTIVE, TXFSTOACTIVE, TXFCMTACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlMsdcDatDetail::Tag
 ******************************************************************************/

PnlMsdcDatDetail::Tag::Tag(
			const string& Cpt
			, const string& CptAft
			, const string& CptPrd
			, const string& CptSta
			, const string& CptSto
			, const string& CptCmt
		) :
			Block()
		{
	this->Cpt = Cpt;
	this->CptAft = CptAft;
	this->CptPrd = CptPrd;
	this->CptSta = CptSta;
	this->CptSto = CptSto;
	this->CptCmt = CptCmt;

	mask = {CPT, CPTAFT, CPTPRD, CPTSTA, CPTSTO, CPTCMT};
};

bool PnlMsdcDatDetail::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagMsdcDatDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemMsdcDatDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptAft", CptAft)) add(CPTAFT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptPrd", CptPrd)) add(CPTPRD);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSta", CptSta)) add(CPTSTA);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSto", CptSto)) add(CPTSTO);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptCmt", CptCmt)) add(CPTCMT);
	};

	return basefound;
};

/******************************************************************************
 class PnlMsdcDatDetail::DpchAppData
 ******************************************************************************/

PnlMsdcDatDetail::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) :
			DpchAppMsdc(VecMsdcVDpch::DPCHAPPMSDCDATDETAILDATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlMsdcDatDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlMsdcDatDetail::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppMsdcDatDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/msdc");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlMsdcDatDetail::DpchAppDo
 ******************************************************************************/

PnlMsdcDatDetail::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppMsdc(VecMsdcVDpch::DPCHAPPMSDCDATDETAILDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlMsdcDatDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlMsdcDatDetail::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppMsdcDatDetailDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/msdc");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlMsdcDatDetail::DpchEngData
 ******************************************************************************/

PnlMsdcDatDetail::DpchEngData::DpchEngData() :
			DpchEngMsdc(VecMsdcVDpch::DPCHENGMSDCDATDETAILDATA)
		{
	feedFPupAft.tag = "FeedFPupAft";
};

string PnlMsdcDatDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFPUPAFT)) ss.push_back("feedFPupAft");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlMsdcDatDetail::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngMsdcDatDetailData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (feedFPupAft.readXML(docctx, basexpath, true)) add(FEEDFPUPAFT);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		continf = ContInf();
		feedFPupAft.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};

