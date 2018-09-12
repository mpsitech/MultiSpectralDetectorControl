/**
  * \file PnlMsdcNavHeadbar_blks.cpp
  * job handler for job PnlMsdcNavHeadbar (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 12 Sep 2018
  * \date modified: 12 Sep 2018
  */

/******************************************************************************
 class PnlMsdcNavHeadbar::StatShr
 ******************************************************************************/

PnlMsdcNavHeadbar::StatShr::StatShr(
			const bool MenCrdAvail
		) :
			Block()
		{
	this->MenCrdAvail = MenCrdAvail;

	mask = {MENCRDAVAIL};
};

void PnlMsdcNavHeadbar::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrMsdcNavHeadbar";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrMsdcNavHeadbar";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "MenCrdAvail", MenCrdAvail);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlMsdcNavHeadbar::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (MenCrdAvail == comp->MenCrdAvail) insert(items, MENCRDAVAIL);

	return(items);
};

set<uint> PnlMsdcNavHeadbar::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {MENCRDAVAIL};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlMsdcNavHeadbar::StgInf
 ******************************************************************************/

void PnlMsdcNavHeadbar::StgInf::writeXML(
			const uint ixMsdcVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgInfMsdcNavHeadbar";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemInfMsdcNavHeadbar";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixMsdcVLocale == VecMsdcVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "MenAppCptwidth", "290");
			writeStringAttr(wr, itemtag, "sref", "MenAppWidth", "309");
			writeStringAttr(wr, itemtag, "sref", "MenSesCptwidth", "66");
			writeStringAttr(wr, itemtag, "sref", "MenSesWidth", "323");
			writeStringAttr(wr, itemtag, "sref", "MenCrdCptwidth", "100");
			writeStringAttr(wr, itemtag, "sref", "MenCrdWidth", "176");
		} else if (ixMsdcVLocale == VecMsdcVLocale::DECH) {
			writeStringAttr(wr, itemtag, "sref", "MenAppCptwidth", "290");
			writeStringAttr(wr, itemtag, "sref", "MenAppWidth", "309");
			writeStringAttr(wr, itemtag, "sref", "MenSesCptwidth", "66");
			writeStringAttr(wr, itemtag, "sref", "MenSesWidth", "323");
			writeStringAttr(wr, itemtag, "sref", "MenCrdCptwidth", "100");
			writeStringAttr(wr, itemtag, "sref", "MenCrdWidth", "183");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlMsdcNavHeadbar::Tag
 ******************************************************************************/

void PnlMsdcNavHeadbar::Tag::writeXML(
			const uint ixMsdcVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagMsdcNavHeadbar";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemMsdcNavHeadbar";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixMsdcVLocale == VecMsdcVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "MenApp", "MultispectralDetectorControl");
		} else if (ixMsdcVLocale == VecMsdcVLocale::DECH) {
			writeStringAttr(wr, itemtag, "sref", "MenApp", "MultispectralDetectorControl");
		};
		writeStringAttr(wr, itemtag, "sref", "MenSes", StrMod::cap(VecMsdcVTag::getTitle(VecMsdcVTag::SESS, ixMsdcVLocale)));
		writeStringAttr(wr, itemtag, "sref", "MenCrd", StrMod::cap(VecMsdcVTag::getTitle(VecMsdcVTag::NAV, ixMsdcVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlMsdcNavHeadbar::DpchEngData
 ******************************************************************************/

PnlMsdcNavHeadbar::DpchEngData::DpchEngData(
			const ubigint jref
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngMsdc(VecMsdcVDpch::DPCHENGMSDCNAVHEADBARDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, STATSHR, STGINF, TAG};
	else this->mask = mask;

	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlMsdcNavHeadbar::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(STGINF)) ss.push_back("stginf");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlMsdcNavHeadbar::DpchEngData::merge(
			DpchEngMsdc* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(STGINF)) add(STGINF);
	if (src->has(TAG)) add(TAG);
};

void PnlMsdcNavHeadbar::DpchEngData::writeXML(
			const uint ixMsdcVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngMsdcNavHeadbarData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/msdc");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(STGINF)) StgInf::writeXML(ixMsdcVLocale, wr);
		if (has(TAG)) Tag::writeXML(ixMsdcVLocale, wr);
	xmlTextWriterEndElement(wr);
};

