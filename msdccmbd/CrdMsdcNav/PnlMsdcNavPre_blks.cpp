/**
  * \file PnlMsdcNavPre_blks.cpp
  * job handler for job PnlMsdcNavPre (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 4 Oct 2018
  * \date modified: 4 Oct 2018
  */

/******************************************************************************
 class PnlMsdcNavPre::VecVDo
 ******************************************************************************/

uint PnlMsdcNavPre::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butdatremoveclick") return BUTDATREMOVECLICK;
	if (s == "butprdremoveclick") return BUTPRDREMOVECLICK;

	return(0);
};

string PnlMsdcNavPre::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTDATREMOVECLICK) return("ButDatRemoveClick");
	if (ix == BUTPRDREMOVECLICK) return("ButPrdRemoveClick");

	return("");
};

/******************************************************************************
 class PnlMsdcNavPre::ContInf
 ******************************************************************************/

PnlMsdcNavPre::ContInf::ContInf(
			const string& TxtDat
			, const string& TxtPrd
		) :
			Block()
		{
	this->TxtDat = TxtDat;
	this->TxtPrd = TxtPrd;

	mask = {TXTDAT, TXTPRD};
};

void PnlMsdcNavPre::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfMsdcNavPre";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfMsdcNavPre";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtDat", TxtDat);
		writeStringAttr(wr, itemtag, "sref", "TxtPrd", TxtPrd);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlMsdcNavPre::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtDat == comp->TxtDat) insert(items, TXTDAT);
	if (TxtPrd == comp->TxtPrd) insert(items, TXTPRD);

	return(items);
};

set<uint> PnlMsdcNavPre::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTDAT, TXTPRD};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlMsdcNavPre::StatShr
 ******************************************************************************/

PnlMsdcNavPre::StatShr::StatShr(
			const bool TxtDatAvail
			, const bool TxtPrdAvail
		) :
			Block()
		{
	this->TxtDatAvail = TxtDatAvail;
	this->TxtPrdAvail = TxtPrdAvail;

	mask = {TXTDATAVAIL, TXTPRDAVAIL};
};

void PnlMsdcNavPre::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrMsdcNavPre";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrMsdcNavPre";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "TxtDatAvail", TxtDatAvail);
		writeBoolAttr(wr, itemtag, "sref", "TxtPrdAvail", TxtPrdAvail);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlMsdcNavPre::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (TxtDatAvail == comp->TxtDatAvail) insert(items, TXTDATAVAIL);
	if (TxtPrdAvail == comp->TxtPrdAvail) insert(items, TXTPRDAVAIL);

	return(items);
};

set<uint> PnlMsdcNavPre::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTDATAVAIL, TXTPRDAVAIL};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlMsdcNavPre::Tag
 ******************************************************************************/

void PnlMsdcNavPre::Tag::writeXML(
			const uint ixMsdcVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagMsdcNavPre";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemMsdcNavPre";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixMsdcVLocale == VecMsdcVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "CptDat", "raw data");
			writeStringAttr(wr, itemtag, "sref", "CptPrd", "acquisition period");
		} else if (ixMsdcVLocale == VecMsdcVLocale::DECH) {
			writeStringAttr(wr, itemtag, "sref", "CptDat", "Rohdaten");
			writeStringAttr(wr, itemtag, "sref", "CptPrd", "Aufzeichnungsperiode");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlMsdcNavPre::DpchAppDo
 ******************************************************************************/

PnlMsdcNavPre::DpchAppDo::DpchAppDo() :
			DpchAppMsdc(VecMsdcVDpch::DPCHAPPMSDCNAVPREDO)
		{
	ixVDo = 0;
};

string PnlMsdcNavPre::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlMsdcNavPre::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppMsdcNavPreDo");
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
 class PnlMsdcNavPre::DpchEngData
 ******************************************************************************/

PnlMsdcNavPre::DpchEngData::DpchEngData(
			const ubigint jref
			, ContInf* continf
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngMsdc(VecMsdcVDpch::DPCHENGMSDCNAVPREDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTINF, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlMsdcNavPre::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlMsdcNavPre::DpchEngData::merge(
			DpchEngMsdc* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlMsdcNavPre::DpchEngData::writeXML(
			const uint ixMsdcVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngMsdcNavPreData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/msdc");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixMsdcVLocale, wr);
	xmlTextWriterEndElement(wr);
};

