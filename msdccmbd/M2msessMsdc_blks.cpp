/**
  * \file M2msessMsdc_blks.cpp
  * job handler for job M2msessMsdc (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 4 Oct 2018
  * \date modified: 4 Oct 2018
  */

/******************************************************************************
 class M2msessMsdc::StatShr
 ******************************************************************************/

M2msessMsdc::StatShr::StatShr(
			const ubigint jrefAcqadxl
			, const ubigint jrefAcqlwir
			, const ubigint jrefAcqvisl
			, const ubigint jrefAcqvisr
			, const ubigint jrefActalign
			, const ubigint jrefActled
			, const ubigint jrefActservo
			, const ubigint jrefPrcstereo
		) :
			Block()
		{
	this->jrefAcqadxl = jrefAcqadxl;
	this->jrefAcqlwir = jrefAcqlwir;
	this->jrefAcqvisl = jrefAcqvisl;
	this->jrefAcqvisr = jrefAcqvisr;
	this->jrefActalign = jrefActalign;
	this->jrefActled = jrefActled;
	this->jrefActservo = jrefActservo;
	this->jrefPrcstereo = jrefPrcstereo;

	mask = {JREFACQADXL, JREFACQLWIR, JREFACQVISL, JREFACQVISR, JREFACTALIGN, JREFACTLED, JREFACTSERVO, JREFPRCSTEREO};
};

void M2msessMsdc::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrM2msessMsdc";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrM2msessMsdc";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "scrJrefAcqadxl", Scr::scramble(jrefAcqadxl));
		writeStringAttr(wr, itemtag, "sref", "scrJrefAcqlwir", Scr::scramble(jrefAcqlwir));
		writeStringAttr(wr, itemtag, "sref", "scrJrefAcqvisl", Scr::scramble(jrefAcqvisl));
		writeStringAttr(wr, itemtag, "sref", "scrJrefAcqvisr", Scr::scramble(jrefAcqvisr));
		writeStringAttr(wr, itemtag, "sref", "scrJrefActalign", Scr::scramble(jrefActalign));
		writeStringAttr(wr, itemtag, "sref", "scrJrefActled", Scr::scramble(jrefActled));
		writeStringAttr(wr, itemtag, "sref", "scrJrefActservo", Scr::scramble(jrefActservo));
		writeStringAttr(wr, itemtag, "sref", "scrJrefPrcstereo", Scr::scramble(jrefPrcstereo));
	xmlTextWriterEndElement(wr);
};

set<uint> M2msessMsdc::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (jrefAcqadxl == comp->jrefAcqadxl) insert(items, JREFACQADXL);
	if (jrefAcqlwir == comp->jrefAcqlwir) insert(items, JREFACQLWIR);
	if (jrefAcqvisl == comp->jrefAcqvisl) insert(items, JREFACQVISL);
	if (jrefAcqvisr == comp->jrefAcqvisr) insert(items, JREFACQVISR);
	if (jrefActalign == comp->jrefActalign) insert(items, JREFACTALIGN);
	if (jrefActled == comp->jrefActled) insert(items, JREFACTLED);
	if (jrefActservo == comp->jrefActservo) insert(items, JREFACTSERVO);
	if (jrefPrcstereo == comp->jrefPrcstereo) insert(items, JREFPRCSTEREO);

	return(items);
};

set<uint> M2msessMsdc::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {JREFACQADXL, JREFACQLWIR, JREFACQVISL, JREFACQVISR, JREFACTALIGN, JREFACTLED, JREFACTSERVO, JREFPRCSTEREO};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class M2msessMsdc::DpchEngData
 ******************************************************************************/

M2msessMsdc::DpchEngData::DpchEngData(
			const ubigint jref
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngMsdc(VecMsdcVDpch::DPCHENGM2MSESSMSDCDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, STATSHR};
	else this->mask = mask;

	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string M2msessMsdc::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(STATSHR)) ss.push_back("statshr");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void M2msessMsdc::DpchEngData::merge(
			DpchEngMsdc* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
};

void M2msessMsdc::DpchEngData::writeXML(
			const uint ixMsdcVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngM2msessMsdcData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/msdc");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(STATSHR)) statshr.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

