/**
  * \file PnlMsdcScfActu_blks.cpp
  * job handler for job PnlMsdcScfActu (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 4 Oct 2018
  * \date modified: 4 Oct 2018
  */

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

	diffitems = {SLDSTM, SLDSTX, SLDSPM, SLDSPX};
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

void PnlMsdcScfActu::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfMsdcScfActu";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfMsdcScfActu";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButMasterOn", ButMasterOn);
	xmlTextWriterEndElement(wr);
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

	diffitems = {BUTMASTERON};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlMsdcScfActu::StatApp
 ******************************************************************************/

void PnlMsdcScfActu::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixMsdcVExpstate
		) {
	if (difftag.length() == 0) difftag = "StatAppMsdcScfActu";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppMsdcScfActu";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxMsdcVExpstate", VecMsdcVExpstate::getSref(ixMsdcVExpstate));
	xmlTextWriterEndElement(wr);
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

void PnlMsdcScfActu::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrMsdcScfActu";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrMsdcScfActu";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeDoubleAttr(wr, itemtag, "sref", "SldStmMin", SldStmMin);
		writeDoubleAttr(wr, itemtag, "sref", "SldStmMax", SldStmMax);
		writeDoubleAttr(wr, itemtag, "sref", "SldStmRast", SldStmRast);
		writeDoubleAttr(wr, itemtag, "sref", "SldStxMin", SldStxMin);
		writeDoubleAttr(wr, itemtag, "sref", "SldStxMax", SldStxMax);
		writeDoubleAttr(wr, itemtag, "sref", "SldStxRast", SldStxRast);
		writeDoubleAttr(wr, itemtag, "sref", "SldSpmMin", SldSpmMin);
		writeDoubleAttr(wr, itemtag, "sref", "SldSpmMax", SldSpmMax);
		writeDoubleAttr(wr, itemtag, "sref", "SldSpmRast", SldSpmRast);
		writeDoubleAttr(wr, itemtag, "sref", "SldSpxMin", SldSpxMin);
		writeDoubleAttr(wr, itemtag, "sref", "SldSpxMax", SldSpxMax);
		writeDoubleAttr(wr, itemtag, "sref", "SldSpxRast", SldSpxRast);
	xmlTextWriterEndElement(wr);
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

void PnlMsdcScfActu::Tag::writeXML(
			const uint ixMsdcVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagMsdcScfActu";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemMsdcScfActu";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixMsdcVLocale == VecMsdcVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Actuation features");
			writeStringAttr(wr, itemtag, "sref", "HdgSrv", "Servos");
			writeStringAttr(wr, itemtag, "sref", "CptStm", "min. \\u03d1 [\\u00b0]");
			writeStringAttr(wr, itemtag, "sref", "CptStx", "max. \\u03d1 [\\u00b0]");
			writeStringAttr(wr, itemtag, "sref", "CptSpm", "min. \\u03c6 [\\u00b0]");
			writeStringAttr(wr, itemtag, "sref", "CptSpx", "max. \\u03c6 [\\u00b0]");
		} else if (ixMsdcVLocale == VecMsdcVLocale::DECH) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Bet\\u00e4tigungs-Features");
			writeStringAttr(wr, itemtag, "sref", "HdgSrv", "Servos");
			writeStringAttr(wr, itemtag, "sref", "CptStm", "min. \\u03d1 [\\u00b0]");
			writeStringAttr(wr, itemtag, "sref", "CptStx", "max. \\u03d1 [\\u00b0]");
			writeStringAttr(wr, itemtag, "sref", "CptSpm", "min. \\u03c6 [\\u00b0]");
			writeStringAttr(wr, itemtag, "sref", "CptSpx", "max. \\u03c6 [\\u00b0]");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlMsdcScfActu::DpchAppData
 ******************************************************************************/

PnlMsdcScfActu::DpchAppData::DpchAppData() :
			DpchAppMsdc(VecMsdcVDpch::DPCHAPPMSDCSCFACTUDATA)
		{
};

string PnlMsdcScfActu::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlMsdcScfActu::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppMsdcScfActuData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) {
			jref = Scr::descramble(scrJref);
			add(JREF);
		};
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
	} else {
		contiac = ContIac();
	};
};

/******************************************************************************
 class PnlMsdcScfActu::DpchAppDo
 ******************************************************************************/

PnlMsdcScfActu::DpchAppDo::DpchAppDo() :
			DpchAppMsdc(VecMsdcVDpch::DPCHAPPMSDCSCFACTUDO)
		{
	ixVDo = 0;
};

string PnlMsdcScfActu::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlMsdcScfActu::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppMsdcScfActuDo");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) {
			jref = Scr::descramble(scrJref);
			add(JREF);
		};
		if (extractStringUclc(docctx, basexpath, "srefIxVDo", "", srefIxVDo)) {
			ixVDo = VecVDo::getIx(srefIxVDo);
			add(IXVDO);
		};
	} else {
	};
};

/******************************************************************************
 class PnlMsdcScfActu::DpchEngData
 ******************************************************************************/

PnlMsdcScfActu::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngMsdc(VecMsdcVDpch::DPCHENGMSDCSCFACTUDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlMsdcScfActu::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlMsdcScfActu::DpchEngData::merge(
			DpchEngMsdc* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlMsdcScfActu::DpchEngData::writeXML(
			const uint ixMsdcVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngMsdcScfActuData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/msdc");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixMsdcVLocale, wr);
	xmlTextWriterEndElement(wr);
};

