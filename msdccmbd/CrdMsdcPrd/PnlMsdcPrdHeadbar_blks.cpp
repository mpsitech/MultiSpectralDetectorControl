/**
  * \file PnlMsdcPrdHeadbar_blks.cpp
  * job handler for job PnlMsdcPrdHeadbar (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 12 Sep 2018
  * \date modified: 12 Sep 2018
  */

/******************************************************************************
 class PnlMsdcPrdHeadbar::StgInf
 ******************************************************************************/

void PnlMsdcPrdHeadbar::StgInf::writeXML(
			const uint ixMsdcVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgInfMsdcPrdHeadbar";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemInfMsdcPrdHeadbar";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixMsdcVLocale == VecMsdcVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "MenAppCptwidth", "290");
			writeStringAttr(wr, itemtag, "sref", "MenAppWidth", "309");
			writeStringAttr(wr, itemtag, "sref", "MenCrdCptwidth", "172");
			writeStringAttr(wr, itemtag, "sref", "MenCrdWidth", "323");
		} else if (ixMsdcVLocale == VecMsdcVLocale::DECH) {
			writeStringAttr(wr, itemtag, "sref", "MenAppCptwidth", "290");
			writeStringAttr(wr, itemtag, "sref", "MenAppWidth", "309");
			writeStringAttr(wr, itemtag, "sref", "MenCrdCptwidth", "190");
			writeStringAttr(wr, itemtag, "sref", "MenCrdWidth", "323");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlMsdcPrdHeadbar::Tag
 ******************************************************************************/

void PnlMsdcPrdHeadbar::Tag::writeXML(
			const uint ixMsdcVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagMsdcPrdHeadbar";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemMsdcPrdHeadbar";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixMsdcVLocale == VecMsdcVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "MenApp", "MultispectralDetectorControl");
			writeStringAttr(wr, itemtag, "sref", "MenCrd", "Acquisition period");
		} else if (ixMsdcVLocale == VecMsdcVLocale::DECH) {
			writeStringAttr(wr, itemtag, "sref", "MenApp", "MultispectralDetectorControl");
			writeStringAttr(wr, itemtag, "sref", "MenCrd", "Aufzeichnungsperiode");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlMsdcPrdHeadbar::DpchEngData
 ******************************************************************************/

PnlMsdcPrdHeadbar::DpchEngData::DpchEngData(
			const ubigint jref
			, const set<uint>& mask
		) :
			DpchEngMsdc(VecMsdcVDpch::DPCHENGMSDCPRDHEADBARDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, STGINF, TAG};
	else this->mask = mask;

};

string PnlMsdcPrdHeadbar::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(STGINF)) ss.push_back("stginf");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlMsdcPrdHeadbar::DpchEngData::merge(
			DpchEngMsdc* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(STGINF)) add(STGINF);
	if (src->has(TAG)) add(TAG);
};

void PnlMsdcPrdHeadbar::DpchEngData::writeXML(
			const uint ixMsdcVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngMsdcPrdHeadbarData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/msdc");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(STGINF)) StgInf::writeXML(ixMsdcVLocale, wr);
		if (has(TAG)) Tag::writeXML(ixMsdcVLocale, wr);
	xmlTextWriterEndElement(wr);
};

