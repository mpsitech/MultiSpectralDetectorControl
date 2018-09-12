/**
  * \file PnlMsdcScfActu.cpp
  * API code for job PnlMsdcScfActu (implementation)
  * \author Alexander Wirthmueller
  * \date created: 12 Sep 2018
  * \date modified: 12 Sep 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "PnlMsdcScfActu.h"

/******************************************************************************
 class PnlMsdcScfActu::VecVDo
 ******************************************************************************/

uint PnlMsdcScfActu::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butmasterclick") return BUTMASTERCLICK;

	return(0);
};

string PnlMsdcScfActu::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTMASTERCLICK) return("ButMasterClick");

	return("");
};

/******************************************************************************
 class PnlMsdcScfActu::ContIac
 ******************************************************************************/

PnlMsdcScfActu::ContIac::ContIac(
			const double SldStm
			, const double SldStx
			, const double SldSpm
			, const double SldSpx
		) :
			Block()
		{
	this->SldStm = SldStm;
	this->SldStx = SldStx;
	this->SldSpm = SldSpm;
	this->SldSpx = SldSpx;

	mask = {SLDSTM, SLDSTX, SLDSPM, SLDSPX};
};

bool PnlMsdcScfActu::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacMsdcScfActu");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacMsdcScfActu";

	if (basefound) {
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "SldStm", SldStm)) add(SLDSTM);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "SldStx", SldStx)) add(SLDSTX);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "SldSpm", SldSpm)) add(SLDSPM);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "SldSpx", SldSpx)) add(SLDSPX);
	};

	return basefound;
};

void PnlMsdcScfActu::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacMsdcScfActu";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacMsdcScfActu";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeDoubleAttr(wr, itemtag, "sref", "SldStm", SldStm);
		writeDoubleAttr(wr, itemtag, "sref", "SldStx", SldStx);
		writeDoubleAttr(wr, itemtag, "sref", "SldSpm", SldSpm);
		writeDoubleAttr(wr, itemtag, "sref", "SldSpx", SldSpx);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlMsdcScfActu::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (compareDouble(SldStm, comp->SldStm) < 1.0e-4) insert(items, SLDSTM);
	if (compareDouble(SldStx, comp->SldStx) < 1.0e-4) insert(items, SLDSTX);
	if (compareDouble(SldSpm, comp->SldSpm) < 1.0e-4) insert(items, SLDSPM);
	if (compareDouble(SldSpx, comp->SldSpx) < 1.0e-4) insert(items, SLDSPX);

	return(items);
};

set<uint> PnlMsdcScfActu::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {, SLDSTX, SLDSPM, SLDSPX};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlMsdcScfActu::ContInf
 ******************************************************************************/

PnlMsdcScfActu::ContInf::ContInf(
			const bool ButMasterOn
		) :
			Block()
		{
	this->ButMasterOn = ButMasterOn;

	mask = {BUTMASTERON};
};

bool PnlMsdcScfActu::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfMsdcScfActu");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfMsdcScfActu";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "ButMasterOn", ButMasterOn)) add(BUTMASTERON);
	};

	return basefound;
};

set<uint> PnlMsdcScfActu::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (ButMasterOn == comp->ButMasterOn) insert(items, BUTMASTERON);

	return(items);
};

set<uint> PnlMsdcScfActu::ContInf::diff(
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
 class PnlMsdcScfActu::StatApp
 ******************************************************************************/

PnlMsdcScfActu::StatApp::StatApp(
			const uint ixMsdcVExpstate
		) :
			Block()
		{
	this->ixMsdcVExpstate = ixMsdcVExpstate;

	mask = {IXMSDCVEXPSTATE};
};

bool PnlMsdcScfActu::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxMsdcVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppMsdcScfActu");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppMsdcScfActu";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxMsdcVExpstate", srefIxMsdcVExpstate)) {
			ixMsdcVExpstate = VecMsdcVExpstate::getIx(srefIxMsdcVExpstate);
			add(IXMSDCVEXPSTATE);
		};
	};

	return basefound;
};

set<uint> PnlMsdcScfActu::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixMsdcVExpstate == comp->ixMsdcVExpstate) insert(items, IXMSDCVEXPSTATE);

	return(items);
};

set<uint> PnlMsdcScfActu::StatApp::diff(
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
 class PnlMsdcScfActu::StatShr
 ******************************************************************************/

PnlMsdcScfActu::StatShr::StatShr(
			const double SldStmMin
			, const double SldStmMax
			, const double SldStmRast
			, const double SldStxMin
			, const double SldStxMax
			, const double SldStxRast
			, const double SldSpmMin
			, const double SldSpmMax
			, const double SldSpmRast
			, const double SldSpxMin
			, const double SldSpxMax
			, const double SldSpxRast
		) :
			Block()
		{
	this->SldStmMin = SldStmMin;
	this->SldStmMax = SldStmMax;
	this->SldStmRast = SldStmRast;
	this->SldStxMin = SldStxMin;
	this->SldStxMax = SldStxMax;
	this->SldStxRast = SldStxRast;
	this->SldSpmMin = SldSpmMin;
	this->SldSpmMax = SldSpmMax;
	this->SldSpmRast = SldSpmRast;
	this->SldSpxMin = SldSpxMin;
	this->SldSpxMax = SldSpxMax;
	this->SldSpxRast = SldSpxRast;

	mask = {SLDSTMMIN, SLDSTMMAX, SLDSTMRAST, SLDSTXMIN, SLDSTXMAX, SLDSTXRAST, SLDSPMMIN, SLDSPMMAX, SLDSPMRAST, SLDSPXMIN, SLDSPXMAX, SLDSPXRAST};
};

bool PnlMsdcScfActu::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrMsdcScfActu");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrMsdcScfActu";

	if (basefound) {
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "SldStmMin", SldStmMin)) add(SLDSTMMIN);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "SldStmMax", SldStmMax)) add(SLDSTMMAX);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "SldStmRast", SldStmRast)) add(SLDSTMRAST);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "SldStxMin", SldStxMin)) add(SLDSTXMIN);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "SldStxMax", SldStxMax)) add(SLDSTXMAX);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "SldStxRast", SldStxRast)) add(SLDSTXRAST);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "SldSpmMin", SldSpmMin)) add(SLDSPMMIN);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "SldSpmMax", SldSpmMax)) add(SLDSPMMAX);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "SldSpmRast", SldSpmRast)) add(SLDSPMRAST);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "SldSpxMin", SldSpxMin)) add(SLDSPXMIN);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "SldSpxMax", SldSpxMax)) add(SLDSPXMAX);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "SldSpxRast", SldSpxRast)) add(SLDSPXRAST);
	};

	return basefound;
};

set<uint> PnlMsdcScfActu::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (compareDouble(SldStmMin, comp->SldStmMin) < 1.0e-4) insert(items, SLDSTMMIN);
	if (compareDouble(SldStmMax, comp->SldStmMax) < 1.0e-4) insert(items, SLDSTMMAX);
	if (compareDouble(SldStmRast, comp->SldStmRast) < 1.0e-4) insert(items, SLDSTMRAST);
	if (compareDouble(SldStxMin, comp->SldStxMin) < 1.0e-4) insert(items, SLDSTXMIN);
	if (compareDouble(SldStxMax, comp->SldStxMax) < 1.0e-4) insert(items, SLDSTXMAX);
	if (compareDouble(SldStxRast, comp->SldStxRast) < 1.0e-4) insert(items, SLDSTXRAST);
	if (compareDouble(SldSpmMin, comp->SldSpmMin) < 1.0e-4) insert(items, SLDSPMMIN);
	if (compareDouble(SldSpmMax, comp->SldSpmMax) < 1.0e-4) insert(items, SLDSPMMAX);
	if (compareDouble(SldSpmRast, comp->SldSpmRast) < 1.0e-4) insert(items, SLDSPMRAST);
	if (compareDouble(SldSpxMin, comp->SldSpxMin) < 1.0e-4) insert(items, SLDSPXMIN);
	if (compareDouble(SldSpxMax, comp->SldSpxMax) < 1.0e-4) insert(items, SLDSPXMAX);
	if (compareDouble(SldSpxRast, comp->SldSpxRast) < 1.0e-4) insert(items, SLDSPXRAST);

	return(items);
};

set<uint> PnlMsdcScfActu::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {SLDSTMMIN, SLDSTMMAX, SLDSTMRAST, SLDSTXMIN, SLDSTXMAX, SLDSTXRAST, SLDSPMMIN, SLDSPMMAX, SLDSPMRAST, SLDSPXMIN, SLDSPXMAX, SLDSPXRAST};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlMsdcScfActu::Tag
 ******************************************************************************/

PnlMsdcScfActu::Tag::Tag(
			const string& Cpt
			, const string& HdgSrv
			, const string& CptStm
			, const string& CptStx
			, const string& CptSpm
			, const string& CptSpx
		) :
			Block()
		{
	this->Cpt = Cpt;
	this->HdgSrv = HdgSrv;
	this->CptStm = CptStm;
	this->CptStx = CptStx;
	this->CptSpm = CptSpm;
	this->CptSpx = CptSpx;

	mask = {CPT, HDGSRV, CPTSTM, CPTSTX, CPTSPM, CPTSPX};
};

bool PnlMsdcScfActu::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagMsdcScfActu");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemMsdcScfActu";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "HdgSrv", HdgSrv)) add(HDGSRV);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptStm", CptStm)) add(CPTSTM);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptStx", CptStx)) add(CPTSTX);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSpm", CptSpm)) add(CPTSPM);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSpx", CptSpx)) add(CPTSPX);
	};

	return basefound;
};

/******************************************************************************
 class PnlMsdcScfActu::DpchAppData
 ******************************************************************************/

PnlMsdcScfActu::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) :
			DpchAppMsdc(VecMsdcVDpch::DPCHAPPMSDCSCFACTUDATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlMsdcScfActu::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlMsdcScfActu::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppMsdcScfActuData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/msdc");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlMsdcScfActu::DpchAppDo
 ******************************************************************************/

PnlMsdcScfActu::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppMsdc(VecMsdcVDpch::DPCHAPPMSDCSCFACTUDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlMsdcScfActu::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlMsdcScfActu::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppMsdcScfActuDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/msdc");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlMsdcScfActu::DpchEngData
 ******************************************************************************/

PnlMsdcScfActu::DpchEngData::DpchEngData() :
			DpchEngMsdc(VecMsdcVDpch::DPCHENGMSDCSCFACTUDATA)
		{
};

string PnlMsdcScfActu::DpchEngData::getSrefsMask() {
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

void PnlMsdcScfActu::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngMsdcScfActuData");
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

