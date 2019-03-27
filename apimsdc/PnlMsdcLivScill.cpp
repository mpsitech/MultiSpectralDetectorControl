/**
  * \file PnlMsdcLivScill.cpp
  * API code for job PnlMsdcLivScill (implementation)
  * \author Alexander Wirthmueller
  * \date created: 18 Dec 2018
  * \date modified: 18 Dec 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "PnlMsdcLivScill.h"

/******************************************************************************
 class PnlMsdcLivScill::VecVDo
 ******************************************************************************/

uint PnlMsdcLivScill::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butregularizeclick") return BUTREGULARIZECLICK;
	if (s == "butminimizeclick") return BUTMINIMIZECLICK;
	if (s == "butmasterclick") return BUTMASTERCLICK;

	return(0);
};

string PnlMsdcLivScill::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");
	if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");
	if (ix == BUTMASTERCLICK) return("ButMasterClick");

	return("");
};

/******************************************************************************
 class PnlMsdcLivScill::ContIac
 ******************************************************************************/

PnlMsdcLivScill::ContIac::ContIac(
			const double SldFld
			, const double SldSpt
		) :
			Block()
		{
	this->SldFld = SldFld;
	this->SldSpt = SldSpt;

	mask = {SLDFLD, SLDSPT};
};

bool PnlMsdcLivScill::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacMsdcLivScill");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacMsdcLivScill";

	if (basefound) {
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "SldFld", SldFld)) add(SLDFLD);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "SldSpt", SldSpt)) add(SLDSPT);
	};

	return basefound;
};

void PnlMsdcLivScill::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacMsdcLivScill";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacMsdcLivScill";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeDoubleAttr(wr, itemtag, "sref", "SldFld", SldFld);
		writeDoubleAttr(wr, itemtag, "sref", "SldSpt", SldSpt);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlMsdcLivScill::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (compareDouble(SldFld, comp->SldFld) < 1.0e-4) insert(items, SLDFLD);
	if (compareDouble(SldSpt, comp->SldSpt) < 1.0e-4) insert(items, SLDSPT);

	return(items);
};

set<uint> PnlMsdcLivScill::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {SLDFLD, SLDSPT};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlMsdcLivScill::ContInf
 ******************************************************************************/

PnlMsdcLivScill::ContInf::ContInf(
			const bool ButMasterOn
		) :
			Block()
		{
	this->ButMasterOn = ButMasterOn;

	mask = {BUTMASTERON};
};

bool PnlMsdcLivScill::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfMsdcLivScill");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfMsdcLivScill";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "ButMasterOn", ButMasterOn)) add(BUTMASTERON);
	};

	return basefound;
};

set<uint> PnlMsdcLivScill::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (ButMasterOn == comp->ButMasterOn) insert(items, BUTMASTERON);

	return(items);
};

set<uint> PnlMsdcLivScill::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTMASTERON};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlMsdcLivScill::StatShr
 ******************************************************************************/

PnlMsdcLivScill::StatShr::StatShr(
			const uint ixMsdcVExpstate
			, const bool SldFldActive
			, const double SldFldMin
			, const double SldFldMax
			, const bool SldSptActive
			, const double SldSptMin
			, const double SldSptMax
		) :
			Block()
		{
	this->ixMsdcVExpstate = ixMsdcVExpstate;
	this->SldFldActive = SldFldActive;
	this->SldFldMin = SldFldMin;
	this->SldFldMax = SldFldMax;
	this->SldSptActive = SldSptActive;
	this->SldSptMin = SldSptMin;
	this->SldSptMax = SldSptMax;

	mask = {IXMSDCVEXPSTATE, SLDFLDACTIVE, SLDFLDMIN, SLDFLDMAX, SLDSPTACTIVE, SLDSPTMIN, SLDSPTMAX};
};

bool PnlMsdcLivScill::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxMsdcVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrMsdcLivScill");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrMsdcLivScill";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxMsdcVExpstate", srefIxMsdcVExpstate)) {
			ixMsdcVExpstate = VecMsdcVExpstate::getIx(srefIxMsdcVExpstate);
			add(IXMSDCVEXPSTATE);
		};
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "SldFldActive", SldFldActive)) add(SLDFLDACTIVE);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "SldFldMin", SldFldMin)) add(SLDFLDMIN);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "SldFldMax", SldFldMax)) add(SLDFLDMAX);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "SldSptActive", SldSptActive)) add(SLDSPTACTIVE);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "SldSptMin", SldSptMin)) add(SLDSPTMIN);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "SldSptMax", SldSptMax)) add(SLDSPTMAX);
	};

	return basefound;
};

set<uint> PnlMsdcLivScill::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixMsdcVExpstate == comp->ixMsdcVExpstate) insert(items, IXMSDCVEXPSTATE);
	if (SldFldActive == comp->SldFldActive) insert(items, SLDFLDACTIVE);
	if (compareDouble(SldFldMin, comp->SldFldMin) < 1.0e-4) insert(items, SLDFLDMIN);
	if (compareDouble(SldFldMax, comp->SldFldMax) < 1.0e-4) insert(items, SLDFLDMAX);
	if (SldSptActive == comp->SldSptActive) insert(items, SLDSPTACTIVE);
	if (compareDouble(SldSptMin, comp->SldSptMin) < 1.0e-4) insert(items, SLDSPTMIN);
	if (compareDouble(SldSptMax, comp->SldSptMax) < 1.0e-4) insert(items, SLDSPTMAX);

	return(items);
};

set<uint> PnlMsdcLivScill::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXMSDCVEXPSTATE, SLDFLDACTIVE, SLDFLDMIN, SLDFLDMAX, SLDSPTACTIVE, SLDSPTMIN, SLDSPTMAX};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlMsdcLivScill::Tag
 ******************************************************************************/

PnlMsdcLivScill::Tag::Tag(
			const string& Cpt
			, const string& CptFld
			, const string& CptSpt
		) :
			Block()
		{
	this->Cpt = Cpt;
	this->CptFld = CptFld;
	this->CptSpt = CptSpt;

	mask = {CPT, CPTFLD, CPTSPT};
};

bool PnlMsdcLivScill::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagMsdcLivScill");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemMsdcLivScill";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptFld", CptFld)) add(CPTFLD);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSpt", CptSpt)) add(CPTSPT);
	};

	return basefound;
};

/******************************************************************************
 class PnlMsdcLivScill::DpchAppData
 ******************************************************************************/

PnlMsdcLivScill::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) :
			DpchAppMsdc(VecMsdcVDpch::DPCHAPPMSDCLIVSCILLDATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlMsdcLivScill::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlMsdcLivScill::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppMsdcLivScillData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/msdc");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlMsdcLivScill::DpchAppDo
 ******************************************************************************/

PnlMsdcLivScill::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppMsdc(VecMsdcVDpch::DPCHAPPMSDCLIVSCILLDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlMsdcLivScill::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlMsdcLivScill::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppMsdcLivScillDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/msdc");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlMsdcLivScill::DpchEngData
 ******************************************************************************/

PnlMsdcLivScill::DpchEngData::DpchEngData() :
			DpchEngMsdc(VecMsdcVDpch::DPCHENGMSDCLIVSCILLDATA)
		{
};

string PnlMsdcLivScill::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlMsdcLivScill::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngMsdcLivScillData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		continf = ContInf();
		statshr = StatShr();
		tag = Tag();
	};
};

