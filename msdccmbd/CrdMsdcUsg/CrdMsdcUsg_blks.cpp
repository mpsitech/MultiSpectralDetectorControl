/**
  * \file CrdMsdcUsg_blks.cpp
  * job handler for job CrdMsdcUsg (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 29 Aug 2018
  * \date modified: 29 Aug 2018
  */

/******************************************************************************
 class CrdMsdcUsg::VecVDo
 ******************************************************************************/

uint CrdMsdcUsg::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "close") return CLOSE;
	if (s == "mitappabtclick") return MITAPPABTCLICK;

	return(0);
};

string CrdMsdcUsg::VecVDo::getSref(
			const uint ix
		) {
	if (ix == CLOSE) return("close");
	if (ix == MITAPPABTCLICK) return("MitAppAbtClick");

	return("");
};

/******************************************************************************
 class CrdMsdcUsg::VecVSge
 ******************************************************************************/

uint CrdMsdcUsg::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	if (s == "alrmsdcabt") return ALRMSDCABT;

	return(0);
};

string CrdMsdcUsg::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	if (ix == ALRMSDCABT) return("alrmsdcabt");

	return("");
};

void CrdMsdcUsg::VecVSge::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=2;i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
};

/******************************************************************************
 class CrdMsdcUsg::ContInf
 ******************************************************************************/

CrdMsdcUsg::ContInf::ContInf(
			const uint numFSge
			, const string& MrlAppHlp
			, const string& MtxCrdUsg
		) :
			Block()
		{
	this->numFSge = numFSge;
	this->MrlAppHlp = MrlAppHlp;
	this->MtxCrdUsg = MtxCrdUsg;

	mask = {NUMFSGE, MRLAPPHLP, MTXCRDUSG};
};

void CrdMsdcUsg::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfMsdcUsg";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfMsdcUsg";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFSge", numFSge);
		writeStringAttr(wr, itemtag, "sref", "MrlAppHlp", MrlAppHlp);
		writeStringAttr(wr, itemtag, "sref", "MtxCrdUsg", MtxCrdUsg);
	xmlTextWriterEndElement(wr);
};

set<uint> CrdMsdcUsg::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFSge == comp->numFSge) insert(items, NUMFSGE);
	if (MrlAppHlp == comp->MrlAppHlp) insert(items, MRLAPPHLP);
	if (MtxCrdUsg == comp->MtxCrdUsg) insert(items, MTXCRDUSG);

	return(items);
};

set<uint> CrdMsdcUsg::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFSGE, MRLAPPHLP, MTXCRDUSG};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdMsdcUsg::StatApp
 ******************************************************************************/

void CrdMsdcUsg::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixMsdcVReqitmode
			, const usmallint latency
			, const string& shortMenu
			, const uint widthMenu
			, const bool initdoneHeadbar
			, const bool initdoneList
			, const bool initdoneRec
		) {
	if (difftag.length() == 0) difftag = "StatAppMsdcUsg";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppMsdcUsg";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxMsdcVReqitmode", VecMsdcVReqitmode::getSref(ixMsdcVReqitmode));
		writeUsmallintAttr(wr, itemtag, "sref", "latency", latency);
		writeStringAttr(wr, itemtag, "sref", "shortMenu", shortMenu);
		writeUintAttr(wr, itemtag, "sref", "widthMenu", widthMenu);
		writeBoolAttr(wr, itemtag, "sref", "initdoneHeadbar", initdoneHeadbar);
		writeBoolAttr(wr, itemtag, "sref", "initdoneList", initdoneList);
		writeBoolAttr(wr, itemtag, "sref", "initdoneRec", initdoneRec);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class CrdMsdcUsg::StatShr
 ******************************************************************************/

CrdMsdcUsg::StatShr::StatShr(
			const ubigint jrefHeadbar
			, const ubigint jrefList
			, const ubigint jrefRec
		) :
			Block()
		{
	this->jrefHeadbar = jrefHeadbar;
	this->jrefList = jrefList;
	this->jrefRec = jrefRec;

	mask = {JREFHEADBAR, JREFLIST, JREFREC};
};

void CrdMsdcUsg::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrMsdcUsg";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrMsdcUsg";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "scrJrefHeadbar", Scr::scramble(jrefHeadbar));
		writeStringAttr(wr, itemtag, "sref", "scrJrefList", Scr::scramble(jrefList));
		writeStringAttr(wr, itemtag, "sref", "scrJrefRec", Scr::scramble(jrefRec));
	xmlTextWriterEndElement(wr);
};

set<uint> CrdMsdcUsg::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (jrefHeadbar == comp->jrefHeadbar) insert(items, JREFHEADBAR);
	if (jrefList == comp->jrefList) insert(items, JREFLIST);
	if (jrefRec == comp->jrefRec) insert(items, JREFREC);

	return(items);
};

set<uint> CrdMsdcUsg::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {JREFHEADBAR, JREFLIST, JREFREC};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdMsdcUsg::Tag
 ******************************************************************************/

void CrdMsdcUsg::Tag::writeXML(
			const uint ixMsdcVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagMsdcUsg";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemMsdcUsg";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixMsdcVLocale == VecMsdcVLocale::ENUS) {
		} else if (ixMsdcVLocale == VecMsdcVLocale::DECH) {
		};
		writeStringAttr(wr, itemtag, "sref", "MitAppAbt", StrMod::cap(VecMsdcVTag::getTitle(VecMsdcVTag::ABOUT, ixMsdcVLocale)) + " ...");
		writeStringAttr(wr, itemtag, "sref", "MrlAppHlp", StrMod::cap(VecMsdcVTag::getTitle(VecMsdcVTag::HELP, ixMsdcVLocale)) + " ...");
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class CrdMsdcUsg::DpchAppDo
 ******************************************************************************/

CrdMsdcUsg::DpchAppDo::DpchAppDo() :
			DpchAppMsdc(VecMsdcVDpch::DPCHAPPMSDCUSGDO)
		{
	ixVDo = 0;
};

string CrdMsdcUsg::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void CrdMsdcUsg::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppMsdcUsgDo");
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
 class CrdMsdcUsg::DpchEngData
 ******************************************************************************/

CrdMsdcUsg::DpchEngData::DpchEngData(
			const ubigint jref
			, ContInf* continf
			, Feed* feedFSge
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngMsdc(VecMsdcVDpch::DPCHENGMSDCUSGDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTINF, FEEDFSGE, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFSGE) && feedFSge) this->feedFSge = *feedFSge;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string CrdMsdcUsg::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFSGE)) ss.push_back("feedFSge");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void CrdMsdcUsg::DpchEngData::merge(
			DpchEngMsdc* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFSGE)) {feedFSge = src->feedFSge; add(FEEDFSGE);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void CrdMsdcUsg::DpchEngData::writeXML(
			const uint ixMsdcVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngMsdcUsgData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/msdc");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFSGE)) feedFSge.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixMsdcVLocale, wr);
	xmlTextWriterEndElement(wr);
};

