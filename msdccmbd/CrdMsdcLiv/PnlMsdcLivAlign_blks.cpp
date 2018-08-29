/**
  * \file PnlMsdcLivAlign_blks.cpp
  * job handler for job PnlMsdcLivAlign (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 29 Aug 2018
  * \date modified: 29 Aug 2018
  */

/******************************************************************************
 class PnlMsdcLivAlign::VecVDo
 ******************************************************************************/

uint PnlMsdcLivAlign::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butmasterclick") return BUTMASTERCLICK;

	return(0);
};

string PnlMsdcLivAlign::VecVDo::getSref(
			const uint ix
		) {
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

void PnlMsdcLivAlign::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfMsdcLivAlign";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfMsdcLivAlign";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButMasterOn", ButMasterOn);
		writeStringAttr(wr, itemtag, "sref", "TxtAph", TxtAph);
		writeStringAttr(wr, itemtag, "sref", "TxtBta", TxtBta);
	xmlTextWriterEndElement(wr);
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
 class PnlMsdcLivAlign::StatApp
 ******************************************************************************/

void PnlMsdcLivAlign::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixMsdcVExpstate
		) {
	if (difftag.length() == 0) difftag = "StatAppMsdcLivAlign";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppMsdcLivAlign";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxMsdcVExpstate", VecMsdcVExpstate::getSref(ixMsdcVExpstate));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlMsdcLivAlign::StatShr
 ******************************************************************************/

PnlMsdcLivAlign::StatShr::StatShr(
			const bool SldTheActive
			, const double SldTheMin
			, const double SldTheMax
			, const bool SldPhiActive
			, const double SldPhiMin
			, const double SldPhiMax
		) :
			Block()
		{
	this->SldTheActive = SldTheActive;
	this->SldTheMin = SldTheMin;
	this->SldTheMax = SldTheMax;
	this->SldPhiActive = SldPhiActive;
	this->SldPhiMin = SldPhiMin;
	this->SldPhiMax = SldPhiMax;

	mask = {SLDTHEACTIVE, SLDTHEMIN, SLDTHEMAX, SLDPHIACTIVE, SLDPHIMIN, SLDPHIMAX};
};

void PnlMsdcLivAlign::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrMsdcLivAlign";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrMsdcLivAlign";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "SldTheActive", SldTheActive);
		writeDoubleAttr(wr, itemtag, "sref", "SldTheMin", SldTheMin);
		writeDoubleAttr(wr, itemtag, "sref", "SldTheMax", SldTheMax);
		writeBoolAttr(wr, itemtag, "sref", "SldPhiActive", SldPhiActive);
		writeDoubleAttr(wr, itemtag, "sref", "SldPhiMin", SldPhiMin);
		writeDoubleAttr(wr, itemtag, "sref", "SldPhiMax", SldPhiMax);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlMsdcLivAlign::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

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

	diffitems = {SLDTHEACTIVE, SLDTHEMIN, SLDTHEMAX, SLDPHIACTIVE, SLDPHIMIN, SLDPHIMAX};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlMsdcLivAlign::Tag
 ******************************************************************************/

void PnlMsdcLivAlign::Tag::writeXML(
			const uint ixMsdcVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagMsdcLivAlign";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemMsdcLivAlign";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixMsdcVLocale == VecMsdcVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Alignment");
			writeStringAttr(wr, itemtag, "sref", "CptAph", "tilt angle \\u03b1 [\\u00b0]");
			writeStringAttr(wr, itemtag, "sref", "CptBta", "tilt angle \\u03b2 [\\u00b0]");
			writeStringAttr(wr, itemtag, "sref", "CptThe", "\\u03d1 axis");
			writeStringAttr(wr, itemtag, "sref", "CptPhi", "\\u03c6 axis");
		} else if (ixMsdcVLocale == VecMsdcVLocale::DECH) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Ausrichtung");
			writeStringAttr(wr, itemtag, "sref", "CptAph", "Kippwinkel \\u03b1 [\\u00b0]");
			writeStringAttr(wr, itemtag, "sref", "CptBta", "Kippwinkel \\u03b2 [\\u00b0]");
			writeStringAttr(wr, itemtag, "sref", "CptThe", "\\u03d1-Achse");
			writeStringAttr(wr, itemtag, "sref", "CptPhi", "\\u03c6-Achse");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlMsdcLivAlign::DpchAppData
 ******************************************************************************/

PnlMsdcLivAlign::DpchAppData::DpchAppData() :
			DpchAppMsdc(VecMsdcVDpch::DPCHAPPMSDCLIVALIGNDATA)
		{
};

string PnlMsdcLivAlign::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlMsdcLivAlign::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppMsdcLivAlignData");
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
 class PnlMsdcLivAlign::DpchAppDo
 ******************************************************************************/

PnlMsdcLivAlign::DpchAppDo::DpchAppDo() :
			DpchAppMsdc(VecMsdcVDpch::DPCHAPPMSDCLIVALIGNDO)
		{
	ixVDo = 0;
};

string PnlMsdcLivAlign::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlMsdcLivAlign::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppMsdcLivAlignDo");
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
 class PnlMsdcLivAlign::DpchEngData
 ******************************************************************************/

PnlMsdcLivAlign::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngMsdc(VecMsdcVDpch::DPCHENGMSDCLIVALIGNDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlMsdcLivAlign::DpchEngData::getSrefsMask() {
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

void PnlMsdcLivAlign::DpchEngData::merge(
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

void PnlMsdcLivAlign::DpchEngData::writeXML(
			const uint ixMsdcVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngMsdcLivAlignData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/msdc");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixMsdcVLocale, wr);
	xmlTextWriterEndElement(wr);
};

