/**
  * \file PnlMsdcLivScill_blks.cpp
  * job handler for job PnlMsdcLivScill (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 29 Aug 2018
  * \date modified: 29 Aug 2018
  */

/******************************************************************************
 class PnlMsdcLivScill::VecVDo
 ******************************************************************************/

uint PnlMsdcLivScill::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butmasterclick") return BUTMASTERCLICK;

	return(0);
};

string PnlMsdcLivScill::VecVDo::getSref(
			const uint ix
		) {
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

void PnlMsdcLivScill::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfMsdcLivScill";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfMsdcLivScill";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButMasterOn", ButMasterOn);
	xmlTextWriterEndElement(wr);
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
 class PnlMsdcLivScill::StatApp
 ******************************************************************************/

void PnlMsdcLivScill::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixMsdcVExpstate
		) {
	if (difftag.length() == 0) difftag = "StatAppMsdcLivScill";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppMsdcLivScill";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxMsdcVExpstate", VecMsdcVExpstate::getSref(ixMsdcVExpstate));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlMsdcLivScill::StatShr
 ******************************************************************************/

PnlMsdcLivScill::StatShr::StatShr(
			const bool SldFldActive
			, const double SldFldMin
			, const double SldFldMax
			, const bool SldSptActive
			, const double SldSptMin
			, const double SldSptMax
		) :
			Block()
		{
	this->SldFldActive = SldFldActive;
	this->SldFldMin = SldFldMin;
	this->SldFldMax = SldFldMax;
	this->SldSptActive = SldSptActive;
	this->SldSptMin = SldSptMin;
	this->SldSptMax = SldSptMax;

	mask = {SLDFLDACTIVE, SLDFLDMIN, SLDFLDMAX, SLDSPTACTIVE, SLDSPTMIN, SLDSPTMAX};
};

void PnlMsdcLivScill::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrMsdcLivScill";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrMsdcLivScill";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "SldFldActive", SldFldActive);
		writeDoubleAttr(wr, itemtag, "sref", "SldFldMin", SldFldMin);
		writeDoubleAttr(wr, itemtag, "sref", "SldFldMax", SldFldMax);
		writeBoolAttr(wr, itemtag, "sref", "SldSptActive", SldSptActive);
		writeDoubleAttr(wr, itemtag, "sref", "SldSptMin", SldSptMin);
		writeDoubleAttr(wr, itemtag, "sref", "SldSptMax", SldSptMax);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlMsdcLivScill::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

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

	diffitems = {SLDFLDACTIVE, SLDFLDMIN, SLDFLDMAX, SLDSPTACTIVE, SLDSPTMIN, SLDSPTMAX};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlMsdcLivScill::Tag
 ******************************************************************************/

void PnlMsdcLivScill::Tag::writeXML(
			const uint ixMsdcVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagMsdcLivScill";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemMsdcLivScill";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixMsdcVLocale == VecMsdcVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Scene illumination");
			writeStringAttr(wr, itemtag, "sref", "CptFld", "floodlight");
			writeStringAttr(wr, itemtag, "sref", "CptSpt", "spotlight");
		} else if (ixMsdcVLocale == VecMsdcVLocale::DECH) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Szenenbeleuchtung");
			writeStringAttr(wr, itemtag, "sref", "CptFld", "Scheinwerfer");
			writeStringAttr(wr, itemtag, "sref", "CptSpt", "Spot");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlMsdcLivScill::DpchAppData
 ******************************************************************************/

PnlMsdcLivScill::DpchAppData::DpchAppData() :
			DpchAppMsdc(VecMsdcVDpch::DPCHAPPMSDCLIVSCILLDATA)
		{
};

string PnlMsdcLivScill::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlMsdcLivScill::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppMsdcLivScillData");
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
 class PnlMsdcLivScill::DpchAppDo
 ******************************************************************************/

PnlMsdcLivScill::DpchAppDo::DpchAppDo() :
			DpchAppMsdc(VecMsdcVDpch::DPCHAPPMSDCLIVSCILLDO)
		{
	ixVDo = 0;
};

string PnlMsdcLivScill::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlMsdcLivScill::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppMsdcLivScillDo");
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
 class PnlMsdcLivScill::DpchEngData
 ******************************************************************************/

PnlMsdcLivScill::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngMsdc(VecMsdcVDpch::DPCHENGMSDCLIVSCILLDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlMsdcLivScill::DpchEngData::getSrefsMask() {
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

void PnlMsdcLivScill::DpchEngData::merge(
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

void PnlMsdcLivScill::DpchEngData::writeXML(
			const uint ixMsdcVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngMsdcLivScillData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/msdc");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixMsdcVLocale, wr);
	xmlTextWriterEndElement(wr);
};

