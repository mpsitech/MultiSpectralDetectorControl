/**
  * \file PnlMsdcLivAlign.cpp
  * API code for job PnlMsdcLivAlign (implementation)
  * \author Alexander Wirthmueller
  * \date created: 18 Dec 2018
  * \date modified: 18 Dec 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "PnlMsdcLivAlign.h"

/******************************************************************************
 class PnlMsdcLivAlign::VecVDo
 ******************************************************************************/

uint PnlMsdcLivAlign::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butregularizeclick") return BUTREGULARIZECLICK;
	if (s == "butminimizeclick") return BUTMINIMIZECLICK;
	if (s == "butmasterclick") return BUTMASTERCLICK;

	return(0);
};

string PnlMsdcLivAlign::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");
	if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");
	if (ix == BUTMASTERCLICK) return("ButMasterClick");

	return("");
};

/******************************************************************************
 class PnlMsdcLivAlign::ContIac
 ******************************************************************************/

PnlMsdcLivAlign::ContIac::ContIac(
			const double SldThe
			, const double SldPhi
		) :
			Block()
		{
	this->SldThe = SldThe;
	this->SldPhi = SldPhi;

	mask = {SLDTHE, SLDPHI};
};

bool PnlMsdcLivAlign::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacMsdcLivAlign");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacMsdcLivAlign";

	if (basefound) {
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "SldThe", SldThe)) add(SLDTHE);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "SldPhi", SldPhi)) add(SLDPHI);
	};

	return basefound;
};

void PnlMsdcLivAlign::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacMsdcLivAlign";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacMsdcLivAlign";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeDoubleAttr(wr, itemtag, "sref", "SldThe", SldThe);
		writeDoubleAttr(wr, itemtag, "sref", "SldPhi", SldPhi);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlMsdcLivAlign::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (compareDouble(SldThe, comp->SldThe) < 1.0e-4) insert(items, SLDTHE);
	if (compareDouble(SldPhi, comp->SldPhi) < 1.0e-4) insert(items, SLDPHI);

	return(items);
};

set<uint> PnlMsdcLivAlign::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {SLDTHE, SLDPHI};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlMsdcLivAlign::ContInf
 ******************************************************************************/

PnlMsdcLivAlign::ContInf::ContInf(
			const bool ButMasterOn
			, const string& TxtAph
			, const string& TxtBta
		) :
			Block()
		{
	this->ButMasterOn = ButMasterOn;
	this->TxtAph = TxtAph;
	this->TxtBta = TxtBta;

	mask = {BUTMASTERON, TXTAPH, TXTBTA};
};

bool PnlMsdcLivAlign::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfMsdcLivAlign");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfMsdcLivAlign";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "ButMasterOn", ButMasterOn)) add(BUTMASTERON);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtAph", TxtAph)) add(TXTAPH);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtBta", TxtBta)) add(TXTBTA);
	};

	return basefound;
};

set<uint> PnlMsdcLivAlign::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (ButMasterOn == comp->ButMasterOn) insert(items, BUTMASTERON);
	if (TxtAph == comp->TxtAph) insert(items, TXTAPH);
	if (TxtBta == comp->TxtBta) insert(items, TXTBTA);

	return(items);
};

set<uint> PnlMsdcLivAlign::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTMASTERON, TXTAPH, TXTBTA};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlMsdcLivAlign::StatShr
 ******************************************************************************/

PnlMsdcLivAlign::StatShr::StatShr(
			const uint ixMsdcVExpstate
			, const bool SldTheActive
			, const double SldTheMin
			, const double SldTheMax
			, const bool SldPhiActive
			, const double SldPhiMin
			, const double SldPhiMax
		) :
			Block()
		{
	this->ixMsdcVExpstate = ixMsdcVExpstate;
	this->SldTheActive = SldTheActive;
	this->SldTheMin = SldTheMin;
	this->SldTheMax = SldTheMax;
	this->SldPhiActive = SldPhiActive;
	this->SldPhiMin = SldPhiMin;
	this->SldPhiMax = SldPhiMax;

	mask = {IXMSDCVEXPSTATE, SLDTHEACTIVE, SLDTHEMIN, SLDTHEMAX, SLDPHIACTIVE, SLDPHIMIN, SLDPHIMAX};
};

bool PnlMsdcLivAlign::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxMsdcVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrMsdcLivAlign");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrMsdcLivAlign";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxMsdcVExpstate", srefIxMsdcVExpstate)) {
			ixMsdcVExpstate = VecMsdcVExpstate::getIx(srefIxMsdcVExpstate);
			add(IXMSDCVEXPSTATE);
		};
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "SldTheActive", SldTheActive)) add(SLDTHEACTIVE);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "SldTheMin", SldTheMin)) add(SLDTHEMIN);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "SldTheMax", SldTheMax)) add(SLDTHEMAX);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "SldPhiActive", SldPhiActive)) add(SLDPHIACTIVE);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "SldPhiMin", SldPhiMin)) add(SLDPHIMIN);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "SldPhiMax", SldPhiMax)) add(SLDPHIMAX);
	};

	return basefound;
};

set<uint> PnlMsdcLivAlign::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixMsdcVExpstate == comp->ixMsdcVExpstate) insert(items, IXMSDCVEXPSTATE);
	if (SldTheActive == comp->SldTheActive) insert(items, SLDTHEACTIVE);
	if (compareDouble(SldTheMin, comp->SldTheMin) < 1.0e-4) insert(items, SLDTHEMIN);
	if (compareDouble(SldTheMax, comp->SldTheMax) < 1.0e-4) insert(items, SLDTHEMAX);
	if (SldPhiActive == comp->SldPhiActive) insert(items, SLDPHIACTIVE);
	if (compareDouble(SldPhiMin, comp->SldPhiMin) < 1.0e-4) insert(items, SLDPHIMIN);
	if (compareDouble(SldPhiMax, comp->SldPhiMax) < 1.0e-4) insert(items, SLDPHIMAX);

	return(items);
};

set<uint> PnlMsdcLivAlign::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXMSDCVEXPSTATE, SLDTHEACTIVE, SLDTHEMIN, SLDTHEMAX, SLDPHIACTIVE, SLDPHIMIN, SLDPHIMAX};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlMsdcLivAlign::Tag
 ******************************************************************************/

PnlMsdcLivAlign::Tag::Tag(
			const string& Cpt
			, const string& CptAph
			, const string& CptBta
			, const string& CptThe
			, const string& CptPhi
		) :
			Block()
		{
	this->Cpt = Cpt;
	this->CptAph = CptAph;
	this->CptBta = CptBta;
	this->CptThe = CptThe;
	this->CptPhi = CptPhi;

	mask = {CPT, CPTAPH, CPTBTA, CPTTHE, CPTPHI};
};

bool PnlMsdcLivAlign::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagMsdcLivAlign");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemMsdcLivAlign";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptAph", CptAph)) add(CPTAPH);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptBta", CptBta)) add(CPTBTA);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptThe", CptThe)) add(CPTTHE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptPhi", CptPhi)) add(CPTPHI);
	};

	return basefound;
};

/******************************************************************************
 class PnlMsdcLivAlign::DpchAppData
 ******************************************************************************/

PnlMsdcLivAlign::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) :
			DpchAppMsdc(VecMsdcVDpch::DPCHAPPMSDCLIVALIGNDATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlMsdcLivAlign::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlMsdcLivAlign::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppMsdcLivAlignData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/msdc");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlMsdcLivAlign::DpchAppDo
 ******************************************************************************/

PnlMsdcLivAlign::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppMsdc(VecMsdcVDpch::DPCHAPPMSDCLIVALIGNDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlMsdcLivAlign::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlMsdcLivAlign::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppMsdcLivAlignDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/msdc");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlMsdcLivAlign::DpchEngData
 ******************************************************************************/

PnlMsdcLivAlign::DpchEngData::DpchEngData() :
			DpchEngMsdc(VecMsdcVDpch::DPCHENGMSDCLIVALIGNDATA)
		{
};

string PnlMsdcLivAlign::DpchEngData::getSrefsMask() {
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

void PnlMsdcLivAlign::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngMsdcLivAlignData");
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

