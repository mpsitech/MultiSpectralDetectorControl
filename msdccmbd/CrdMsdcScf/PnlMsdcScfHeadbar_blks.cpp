/**
  * \file PnlMsdcScfHeadbar_blks.cpp
  * job handler for job PnlMsdcScfHeadbar (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 18 Dec 2018
  * \date modified: 18 Dec 2018
  */

/******************************************************************************
 class PnlMsdcScfHeadbar::StgInf
 ******************************************************************************/

void PnlMsdcScfHeadbar::StgInf::writeXML(
			const uint ixMsdcVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgInfMsdcScfHeadbar";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemInfMsdcScfHeadbar";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixMsdcVLocale == VecMsdcVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "MenAppCptwidth", "290");
			writeStringAttr(wr, itemtag, "sref", "MenAppWidth", "309");
			writeStringAttr(wr, itemtag, "sref", "MenCrdCptwidth", "190");
			writeStringAttr(wr, itemtag, "sref", "MenCrdWidth", "190");
		} else if (ixMsdcVLocale == VecMsdcVLocale::DECH) {
			writeStringAttr(wr, itemtag, "sref", "MenAppCptwidth", "290");
			writeStringAttr(wr, itemtag, "sref", "MenAppWidth", "309");
			writeStringAttr(wr, itemtag, "sref", "MenCrdCptwidth", "250");
			writeStringAttr(wr, itemtag, "sref", "MenCrdWidth", "250");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlMsdcScfHeadbar::Tag
 ******************************************************************************/

void PnlMsdcScfHeadbar::Tag::writeXML(
			const uint ixMsdcVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagMsdcScfHeadbar";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemMsdcScfHeadbar";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixMsdcVLocale == VecMsdcVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "MenApp", "MultispectralDetectorControl");
			writeStringAttr(wr, itemtag, "sref", "MenCrd", "System configuration");
		} else if (ixMsdcVLocale == VecMsdcVLocale::DECH) {
			writeStringAttr(wr, itemtag, "sref", "MenApp", "MultispectralDetectorControl");
			writeStringAttr(wr, itemtag, "sref", "MenCrd", "Systemkonfiguration");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlMsdcScfHeadbar::DpchEngData
 ******************************************************************************/

PnlMsdcScfHeadbar::DpchEngData::DpchEngData(
			const ubigint jref
			, const set<uint>& mask
		) :
			DpchEngMsdc(VecMsdcVDpch::DPCHENGMSDCSCFHEADBARDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, STGINF, TAG};
	else this->mask = mask;

};

string PnlMsdcScfHeadbar::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(STGINF)) ss.push_back("stginf");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlMsdcScfHeadbar::DpchEngData::merge(
			DpchEngMsdc* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(STGINF)) add(STGINF);
	if (src->has(TAG)) add(TAG);
};

void PnlMsdcScfHeadbar::DpchEngData::writeXML(
			const uint ixMsdcVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngMsdcScfHeadbarData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/msdc");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(STGINF)) StgInf::writeXML(ixMsdcVLocale, wr);
		if (has(TAG)) Tag::writeXML(ixMsdcVLocale, wr);
	xmlTextWriterEndElement(wr);
};

