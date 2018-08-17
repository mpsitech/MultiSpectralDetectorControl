/**
  * \file PnlMsdcScfSource.cpp
  * API code for job PnlMsdcScfSource (implementation)
  * \author Alexander Wirthmueller
  * \date created: 15 Aug 2018
  * \date modified: 15 Aug 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "PnlMsdcScfSource.h"

/******************************************************************************
 class PnlMsdcScfSource::VecVDo
 ******************************************************************************/

uint PnlMsdcScfSource::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butmasterclick") return BUTMASTERCLICK;

	return(0);
};

string PnlMsdcScfSource::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTMASTERCLICK) return("ButMasterClick");

	return("");
};

/******************************************************************************
 class PnlMsdcScfSource::ContIac
 ******************************************************************************/

PnlMsdcScfSource::ContIac::ContIac(
			const string& TxfFpp
			, const double SldFxa
			, const double SldFa0
			, const double SldFb0
			, const int UpdFam
			, const double SldFsa
			, const double SldFt0
			, const double SldFp0
			, const double SldTrp
		) : Block() {
	this->TxfFpp = TxfFpp;
	this->SldFxa = SldFxa;
	this->SldFa0 = SldFa0;
	this->SldFb0 = SldFb0;
	this->UpdFam = UpdFam;
	this->SldFsa = SldFsa;
	this->SldFt0 = SldFt0;
	this->SldFp0 = SldFp0;
	this->SldTrp = SldTrp;

	mask = {TXFFPP, SLDFXA, SLDFA0, SLDFB0, UPDFAM, SLDFSA, SLDFT0, SLDFP0, SLDTRP};
};

bool PnlMsdcScfSource::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacMsdcScfSource");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacMsdcScfSource";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfFpp", TxfFpp)) add(TXFFPP);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "SldFxa", SldFxa)) add(SLDFXA);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "SldFa0", SldFa0)) add(SLDFA0);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "SldFb0", SldFb0)) add(SLDFB0);
		if (extractIntAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "UpdFam", UpdFam)) add(UPDFAM);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "SldFsa", SldFsa)) add(SLDFSA);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "SldFt0", SldFt0)) add(SLDFT0);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "SldFp0", SldFp0)) add(SLDFP0);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "SldTrp", SldTrp)) add(SLDTRP);
	};

	return basefound;
};

void PnlMsdcScfSource::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacMsdcScfSource";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacMsdcScfSource";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxfFpp", TxfFpp);
		writeDoubleAttr(wr, itemtag, "sref", "SldFxa", SldFxa);
		writeDoubleAttr(wr, itemtag, "sref", "SldFa0", SldFa0);
		writeDoubleAttr(wr, itemtag, "sref", "SldFb0", SldFb0);
		writeIntAttr(wr, itemtag, "sref", "UpdFam", UpdFam);
		writeDoubleAttr(wr, itemtag, "sref", "SldFsa", SldFsa);
		writeDoubleAttr(wr, itemtag, "sref", "SldFt0", SldFt0);
		writeDoubleAttr(wr, itemtag, "sref", "SldFp0", SldFp0);
		writeDoubleAttr(wr, itemtag, "sref", "SldTrp", SldTrp);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlMsdcScfSource::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (TxfFpp == comp->TxfFpp) insert(items, TXFFPP);
	if (compareDouble(SldFxa, comp->SldFxa) < 1.0e-4) insert(items, SLDFXA);
	if (compareDouble(SldFa0, comp->SldFa0) < 1.0e-4) insert(items, SLDFA0);
	if (compareDouble(SldFb0, comp->SldFb0) < 1.0e-4) insert(items, SLDFB0);
	if (UpdFam == comp->UpdFam) insert(items, UPDFAM);
	if (compareDouble(SldFsa, comp->SldFsa) < 1.0e-4) insert(items, SLDFSA);
	if (compareDouble(SldFt0, comp->SldFt0) < 1.0e-4) insert(items, SLDFT0);
	if (compareDouble(SldFp0, comp->SldFp0) < 1.0e-4) insert(items, SLDFP0);
	if (compareDouble(SldTrp, comp->SldTrp) < 1.0e-4) insert(items, SLDTRP);

	return(items);
};

set<uint> PnlMsdcScfSource::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {, SLDFXA, SLDFA0, SLDFB0, UPDFAM, SLDFSA, SLDFT0, SLDFP0, SLDTRP};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlMsdcScfSource::ContInf
 ******************************************************************************/

PnlMsdcScfSource::ContInf::ContInf(
			const bool ButMasterOn
		) : Block() {
	this->ButMasterOn = ButMasterOn;

	mask = {BUTMASTERON};
};

bool PnlMsdcScfSource::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfMsdcScfSource");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfMsdcScfSource";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "ButMasterOn", ButMasterOn)) add(BUTMASTERON);
	};

	return basefound;
};

set<uint> PnlMsdcScfSource::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (ButMasterOn == comp->ButMasterOn) insert(items, BUTMASTERON);

	return(items);
};

set<uint> PnlMsdcScfSource::ContInf::diff(
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
 class PnlMsdcScfSource::StatApp
 ******************************************************************************/

PnlMsdcScfSource::StatApp::StatApp(
			const uint ixMsdcVExpstate
		) : Block() {
	this->ixMsdcVExpstate = ixMsdcVExpstate;

	mask = {IXMSDCVEXPSTATE};
};

bool PnlMsdcScfSource::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxMsdcVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppMsdcScfSource");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppMsdcScfSource";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxMsdcVExpstate", srefIxMsdcVExpstate)) {
			ixMsdcVExpstate = VecMsdcVExpstate::getIx(srefIxMsdcVExpstate);
			add(IXMSDCVEXPSTATE);
		};
	};

	return basefound;
};

set<uint> PnlMsdcScfSource::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixMsdcVExpstate == comp->ixMsdcVExpstate) insert(items, IXMSDCVEXPSTATE);

	return(items);
};

set<uint> PnlMsdcScfSource::StatApp::diff(
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
 class PnlMsdcScfSource::StatShr
 ******************************************************************************/

PnlMsdcScfSource::StatShr::StatShr(
			const double SldFxaMin
			, const double SldFxaMax
			, const double SldFa0Min
			, const double SldFa0Max
			, const double SldFb0Min
			, const double SldFb0Max
			, const int UpdFamMin
			, const int UpdFamMax
			, const double SldFsaMin
			, const double SldFsaMax
			, const double SldFt0Min
			, const double SldFt0Max
			, const double SldFp0Min
			, const double SldFp0Max
			, const double SldTrpMin
			, const double SldTrpMax
			, const double SldTrpRast
		) : Block() {
	this->SldFxaMin = SldFxaMin;
	this->SldFxaMax = SldFxaMax;
	this->SldFa0Min = SldFa0Min;
	this->SldFa0Max = SldFa0Max;
	this->SldFb0Min = SldFb0Min;
	this->SldFb0Max = SldFb0Max;
	this->UpdFamMin = UpdFamMin;
	this->UpdFamMax = UpdFamMax;
	this->SldFsaMin = SldFsaMin;
	this->SldFsaMax = SldFsaMax;
	this->SldFt0Min = SldFt0Min;
	this->SldFt0Max = SldFt0Max;
	this->SldFp0Min = SldFp0Min;
	this->SldFp0Max = SldFp0Max;
	this->SldTrpMin = SldTrpMin;
	this->SldTrpMax = SldTrpMax;
	this->SldTrpRast = SldTrpRast;

	mask = {SLDFXAMIN, SLDFXAMAX, SLDFA0MIN, SLDFA0MAX, SLDFB0MIN, SLDFB0MAX, UPDFAMMIN, UPDFAMMAX, SLDFSAMIN, SLDFSAMAX, SLDFT0MIN, SLDFT0MAX, SLDFP0MIN, SLDFP0MAX, SLDTRPMIN, SLDTRPMAX, SLDTRPRAST};
};

bool PnlMsdcScfSource::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrMsdcScfSource");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrMsdcScfSource";

	if (basefound) {
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "SldFxaMin", SldFxaMin)) add(SLDFXAMIN);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "SldFxaMax", SldFxaMax)) add(SLDFXAMAX);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "SldFa0Min", SldFa0Min)) add(SLDFA0MIN);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "SldFa0Max", SldFa0Max)) add(SLDFA0MAX);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "SldFb0Min", SldFb0Min)) add(SLDFB0MIN);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "SldFb0Max", SldFb0Max)) add(SLDFB0MAX);
		if (extractIntAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "UpdFamMin", UpdFamMin)) add(UPDFAMMIN);
		if (extractIntAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "UpdFamMax", UpdFamMax)) add(UPDFAMMAX);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "SldFsaMin", SldFsaMin)) add(SLDFSAMIN);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "SldFsaMax", SldFsaMax)) add(SLDFSAMAX);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "SldFt0Min", SldFt0Min)) add(SLDFT0MIN);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "SldFt0Max", SldFt0Max)) add(SLDFT0MAX);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "SldFp0Min", SldFp0Min)) add(SLDFP0MIN);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "SldFp0Max", SldFp0Max)) add(SLDFP0MAX);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "SldTrpMin", SldTrpMin)) add(SLDTRPMIN);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "SldTrpMax", SldTrpMax)) add(SLDTRPMAX);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "SldTrpRast", SldTrpRast)) add(SLDTRPRAST);
	};

	return basefound;
};

set<uint> PnlMsdcScfSource::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (compareDouble(SldFxaMin, comp->SldFxaMin) < 1.0e-4) insert(items, SLDFXAMIN);
	if (compareDouble(SldFxaMax, comp->SldFxaMax) < 1.0e-4) insert(items, SLDFXAMAX);
	if (compareDouble(SldFa0Min, comp->SldFa0Min) < 1.0e-4) insert(items, SLDFA0MIN);
	if (compareDouble(SldFa0Max, comp->SldFa0Max) < 1.0e-4) insert(items, SLDFA0MAX);
	if (compareDouble(SldFb0Min, comp->SldFb0Min) < 1.0e-4) insert(items, SLDFB0MIN);
	if (compareDouble(SldFb0Max, comp->SldFb0Max) < 1.0e-4) insert(items, SLDFB0MAX);
	if (UpdFamMin == comp->UpdFamMin) insert(items, UPDFAMMIN);
	if (UpdFamMax == comp->UpdFamMax) insert(items, UPDFAMMAX);
	if (compareDouble(SldFsaMin, comp->SldFsaMin) < 1.0e-4) insert(items, SLDFSAMIN);
	if (compareDouble(SldFsaMax, comp->SldFsaMax) < 1.0e-4) insert(items, SLDFSAMAX);
	if (compareDouble(SldFt0Min, comp->SldFt0Min) < 1.0e-4) insert(items, SLDFT0MIN);
	if (compareDouble(SldFt0Max, comp->SldFt0Max) < 1.0e-4) insert(items, SLDFT0MAX);
	if (compareDouble(SldFp0Min, comp->SldFp0Min) < 1.0e-4) insert(items, SLDFP0MIN);
	if (compareDouble(SldFp0Max, comp->SldFp0Max) < 1.0e-4) insert(items, SLDFP0MAX);
	if (compareDouble(SldTrpMin, comp->SldTrpMin) < 1.0e-4) insert(items, SLDTRPMIN);
	if (compareDouble(SldTrpMax, comp->SldTrpMax) < 1.0e-4) insert(items, SLDTRPMAX);
	if (compareDouble(SldTrpRast, comp->SldTrpRast) < 1.0e-4) insert(items, SLDTRPRAST);

	return(items);
};

set<uint> PnlMsdcScfSource::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {SLDFXAMIN, SLDFXAMAX, SLDFA0MIN, SLDFA0MAX, SLDFB0MIN, SLDFB0MAX, UPDFAMMIN, UPDFAMMAX, SLDFSAMIN, SLDFSAMAX, SLDFT0MIN, SLDFT0MAX, SLDFP0MIN, SLDFP0MAX, SLDTRPMIN, SLDTRPMAX, SLDTRPRAST};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlMsdcScfSource::Tag
 ******************************************************************************/

PnlMsdcScfSource::Tag::Tag(
			const string& Cpt
			, const string& HdgFpg
			, const string& CptFpp
			, const string& CptFxa
			, const string& CptFa0
			, const string& CptFb0
			, const string& CptFam
			, const string& CptFsa
			, const string& CptFt0
			, const string& CptFp0
			, const string& CptTrp
		) : Block() {
	this->Cpt = Cpt;
	this->HdgFpg = HdgFpg;
	this->CptFpp = CptFpp;
	this->CptFxa = CptFxa;
	this->CptFa0 = CptFa0;
	this->CptFb0 = CptFb0;
	this->CptFam = CptFam;
	this->CptFsa = CptFsa;
	this->CptFt0 = CptFt0;
	this->CptFp0 = CptFp0;
	this->CptTrp = CptTrp;

	mask = {CPT, HDGFPG, CPTFPP, CPTFXA, CPTFA0, CPTFB0, CPTFAM, CPTFSA, CPTFT0, CPTFP0, CPTTRP};
};

bool PnlMsdcScfSource::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagMsdcScfSource");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemMsdcScfSource";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "HdgFpg", HdgFpg)) add(HDGFPG);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptFpp", CptFpp)) add(CPTFPP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptFxa", CptFxa)) add(CPTFXA);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptFa0", CptFa0)) add(CPTFA0);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptFb0", CptFb0)) add(CPTFB0);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptFam", CptFam)) add(CPTFAM);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptFsa", CptFsa)) add(CPTFSA);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptFt0", CptFt0)) add(CPTFT0);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptFp0", CptFp0)) add(CPTFP0);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptTrp", CptTrp)) add(CPTTRP);
	};

	return basefound;
};

/******************************************************************************
 class PnlMsdcScfSource::DpchAppData
 ******************************************************************************/

PnlMsdcScfSource::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) : DpchAppMsdc(VecMsdcVDpch::DPCHAPPMSDCSCFSOURCEDATA, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlMsdcScfSource::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlMsdcScfSource::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppMsdcScfSourceData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/msdc");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlMsdcScfSource::DpchAppDo
 ******************************************************************************/

PnlMsdcScfSource::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) : DpchAppMsdc(VecMsdcVDpch::DPCHAPPMSDCSCFSOURCEDO, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlMsdcScfSource::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlMsdcScfSource::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppMsdcScfSourceDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/msdc");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlMsdcScfSource::DpchEngData
 ******************************************************************************/

PnlMsdcScfSource::DpchEngData::DpchEngData() : DpchEngMsdc(VecMsdcVDpch::DPCHENGMSDCSCFSOURCEDATA) {
};

string PnlMsdcScfSource::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlMsdcScfSource::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngMsdcScfSourceData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		continf = ContInf();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};

