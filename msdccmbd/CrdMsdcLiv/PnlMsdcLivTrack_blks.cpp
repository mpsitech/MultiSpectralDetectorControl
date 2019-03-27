/**
  * \file PnlMsdcLivTrack_blks.cpp
  * job handler for job PnlMsdcLivTrack (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 18 Dec 2018
  * \date modified: 18 Dec 2018
  */

/******************************************************************************
 class PnlMsdcLivTrack::VecVDo
 ******************************************************************************/

uint PnlMsdcLivTrack::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butregularizeclick") return BUTREGULARIZECLICK;
	if (s == "butminimizeclick") return BUTMINIMIZECLICK;
	if (s == "butmasterclick") return BUTMASTERCLICK;

	return(0);
};

string PnlMsdcLivTrack::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");
	if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");
	if (ix == BUTMASTERCLICK) return("ButMasterClick");

	return("");
};

/******************************************************************************
 class PnlMsdcLivTrack::ContIac
 ******************************************************************************/

PnlMsdcLivTrack::ContIac::ContIac(
			const uint numFPupAmf
			, const int UpdApr
			, const bool ChkVid
			, const bool ChkWid
		) :
			Block()
		{
	this->numFPupAmf = numFPupAmf;
	this->UpdApr = UpdApr;
	this->ChkVid = ChkVid;
	this->ChkWid = ChkWid;

	mask = {NUMFPUPAMF, UPDAPR, CHKVID, CHKWID};
};

bool PnlMsdcLivTrack::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacMsdcLivTrack");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacMsdcLivTrack";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupAmf", numFPupAmf)) add(NUMFPUPAMF);
		if (extractIntAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "UpdApr", UpdApr)) add(UPDAPR);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "ChkVid", ChkVid)) add(CHKVID);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "ChkWid", ChkWid)) add(CHKWID);
	};

	return basefound;
};

void PnlMsdcLivTrack::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacMsdcLivTrack";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacMsdcLivTrack";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFPupAmf", numFPupAmf);
		writeIntAttr(wr, itemtag, "sref", "UpdApr", UpdApr);
		writeBoolAttr(wr, itemtag, "sref", "ChkVid", ChkVid);
		writeBoolAttr(wr, itemtag, "sref", "ChkWid", ChkWid);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlMsdcLivTrack::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFPupAmf == comp->numFPupAmf) insert(items, NUMFPUPAMF);
	if (UpdApr == comp->UpdApr) insert(items, UPDAPR);
	if (ChkVid == comp->ChkVid) insert(items, CHKVID);
	if (ChkWid == comp->ChkWid) insert(items, CHKWID);

	return(items);
};

set<uint> PnlMsdcLivTrack::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFPUPAMF, UPDAPR, CHKVID, CHKWID};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlMsdcLivTrack::ContInf
 ******************************************************************************/

PnlMsdcLivTrack::ContInf::ContInf(
			const bool ButMasterOn
			, const string& TxtVpx
			, const string& TxtVpy
			, const string& TxtWpx
			, const string& TxtWpy
			, const string& TxtDis
		) :
			Block()
		{
	this->ButMasterOn = ButMasterOn;
	this->TxtVpx = TxtVpx;
	this->TxtVpy = TxtVpy;
	this->TxtWpx = TxtWpx;
	this->TxtWpy = TxtWpy;
	this->TxtDis = TxtDis;

	mask = {BUTMASTERON, TXTVPX, TXTVPY, TXTWPX, TXTWPY, TXTDIS};
};

void PnlMsdcLivTrack::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfMsdcLivTrack";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfMsdcLivTrack";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButMasterOn", ButMasterOn);
		writeStringAttr(wr, itemtag, "sref", "TxtVpx", TxtVpx);
		writeStringAttr(wr, itemtag, "sref", "TxtVpy", TxtVpy);
		writeStringAttr(wr, itemtag, "sref", "TxtWpx", TxtWpx);
		writeStringAttr(wr, itemtag, "sref", "TxtWpy", TxtWpy);
		writeStringAttr(wr, itemtag, "sref", "TxtDis", TxtDis);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlMsdcLivTrack::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (ButMasterOn == comp->ButMasterOn) insert(items, BUTMASTERON);
	if (TxtVpx == comp->TxtVpx) insert(items, TXTVPX);
	if (TxtVpy == comp->TxtVpy) insert(items, TXTVPY);
	if (TxtWpx == comp->TxtWpx) insert(items, TXTWPX);
	if (TxtWpy == comp->TxtWpy) insert(items, TXTWPY);
	if (TxtDis == comp->TxtDis) insert(items, TXTDIS);

	return(items);
};

set<uint> PnlMsdcLivTrack::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTMASTERON, TXTVPX, TXTVPY, TXTWPX, TXTWPY, TXTDIS};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlMsdcLivTrack::StatShr
 ******************************************************************************/

PnlMsdcLivTrack::StatShr::StatShr(
			const uint ixMsdcVExpstate
			, const bool PupAmfActive
			, const bool UpdAprActive
			, const int UpdAprMin
			, const int UpdAprMax
			, const bool ChkVidActive
			, const bool ChkWidActive
		) :
			Block()
		{
	this->ixMsdcVExpstate = ixMsdcVExpstate;
	this->PupAmfActive = PupAmfActive;
	this->UpdAprActive = UpdAprActive;
	this->UpdAprMin = UpdAprMin;
	this->UpdAprMax = UpdAprMax;
	this->ChkVidActive = ChkVidActive;
	this->ChkWidActive = ChkWidActive;

	mask = {IXMSDCVEXPSTATE, PUPAMFACTIVE, UPDAPRACTIVE, UPDAPRMIN, UPDAPRMAX, CHKVIDACTIVE, CHKWIDACTIVE};
};

void PnlMsdcLivTrack::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrMsdcLivTrack";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrMsdcLivTrack";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxMsdcVExpstate", VecMsdcVExpstate::getSref(ixMsdcVExpstate));
		writeBoolAttr(wr, itemtag, "sref", "PupAmfActive", PupAmfActive);
		writeBoolAttr(wr, itemtag, "sref", "UpdAprActive", UpdAprActive);
		writeIntAttr(wr, itemtag, "sref", "UpdAprMin", UpdAprMin);
		writeIntAttr(wr, itemtag, "sref", "UpdAprMax", UpdAprMax);
		writeBoolAttr(wr, itemtag, "sref", "ChkVidActive", ChkVidActive);
		writeBoolAttr(wr, itemtag, "sref", "ChkWidActive", ChkWidActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlMsdcLivTrack::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixMsdcVExpstate == comp->ixMsdcVExpstate) insert(items, IXMSDCVEXPSTATE);
	if (PupAmfActive == comp->PupAmfActive) insert(items, PUPAMFACTIVE);
	if (UpdAprActive == comp->UpdAprActive) insert(items, UPDAPRACTIVE);
	if (UpdAprMin == comp->UpdAprMin) insert(items, UPDAPRMIN);
	if (UpdAprMax == comp->UpdAprMax) insert(items, UPDAPRMAX);
	if (ChkVidActive == comp->ChkVidActive) insert(items, CHKVIDACTIVE);
	if (ChkWidActive == comp->ChkWidActive) insert(items, CHKWIDACTIVE);

	return(items);
};

set<uint> PnlMsdcLivTrack::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXMSDCVEXPSTATE, PUPAMFACTIVE, UPDAPRACTIVE, UPDAPRMIN, UPDAPRMAX, CHKVIDACTIVE, CHKWIDACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlMsdcLivTrack::Tag
 ******************************************************************************/

void PnlMsdcLivTrack::Tag::writeXML(
			const uint ixMsdcVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagMsdcLivTrack";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemMsdcLivTrack";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixMsdcVLocale == VecMsdcVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Contour tracking");
			writeStringAttr(wr, itemtag, "sref", "HdgAls", "Alignment laser");
			writeStringAttr(wr, itemtag, "sref", "CptAmf", "modulation function");
			writeStringAttr(wr, itemtag, "sref", "CptApr", "period");
			writeStringAttr(wr, itemtag, "sref", "HdgVsl", "VIS-L camera");
			writeStringAttr(wr, itemtag, "sref", "CptVid", "identified");
			writeStringAttr(wr, itemtag, "sref", "CptVpx", "x position");
			writeStringAttr(wr, itemtag, "sref", "CptVpy", "y position");
			writeStringAttr(wr, itemtag, "sref", "HdgWsr", "VIS-R camera");
			writeStringAttr(wr, itemtag, "sref", "CptWid", "identified");
			writeStringAttr(wr, itemtag, "sref", "CptWpx", "x position");
			writeStringAttr(wr, itemtag, "sref", "CptWpy", "y position");
			writeStringAttr(wr, itemtag, "sref", "CptDis", "distance [m]");
		} else if (ixMsdcVLocale == VecMsdcVLocale::DECH) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Konturenverfolgung");
			writeStringAttr(wr, itemtag, "sref", "HdgAls", "Ausrichtungslaser");
			writeStringAttr(wr, itemtag, "sref", "CptAmf", "Modulationsfunktion");
			writeStringAttr(wr, itemtag, "sref", "CptApr", "Periode");
			writeStringAttr(wr, itemtag, "sref", "HdgVsl", "VIS-L Kamera");
			writeStringAttr(wr, itemtag, "sref", "CptVid", "identifiziert");
			writeStringAttr(wr, itemtag, "sref", "CptVpx", "x-Position");
			writeStringAttr(wr, itemtag, "sref", "CptVpy", "y-Position");
			writeStringAttr(wr, itemtag, "sref", "HdgWsr", "VIS-R Kamera");
			writeStringAttr(wr, itemtag, "sref", "CptWid", "identifiziert");
			writeStringAttr(wr, itemtag, "sref", "CptWpx", "x-Position");
			writeStringAttr(wr, itemtag, "sref", "CptWpy", "y-Position");
			writeStringAttr(wr, itemtag, "sref", "CptDis", "Distanz [m]");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlMsdcLivTrack::DpchAppData
 ******************************************************************************/

PnlMsdcLivTrack::DpchAppData::DpchAppData() :
			DpchAppMsdc(VecMsdcVDpch::DPCHAPPMSDCLIVTRACKDATA)
		{
};

string PnlMsdcLivTrack::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlMsdcLivTrack::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppMsdcLivTrackData");
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
 class PnlMsdcLivTrack::DpchAppDo
 ******************************************************************************/

PnlMsdcLivTrack::DpchAppDo::DpchAppDo() :
			DpchAppMsdc(VecMsdcVDpch::DPCHAPPMSDCLIVTRACKDO)
		{
	ixVDo = 0;
};

string PnlMsdcLivTrack::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlMsdcLivTrack::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppMsdcLivTrackDo");
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
 class PnlMsdcLivTrack::DpchEngData
 ******************************************************************************/

PnlMsdcLivTrack::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, Feed* feedFPupAmf
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngMsdc(VecMsdcVDpch::DPCHENGMSDCLIVTRACKDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, FEEDFPUPAMF, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFPUPAMF) && feedFPupAmf) this->feedFPupAmf = *feedFPupAmf;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlMsdcLivTrack::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFPUPAMF)) ss.push_back("feedFPupAmf");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlMsdcLivTrack::DpchEngData::merge(
			DpchEngMsdc* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFPUPAMF)) {feedFPupAmf = src->feedFPupAmf; add(FEEDFPUPAMF);};
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlMsdcLivTrack::DpchEngData::writeXML(
			const uint ixMsdcVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngMsdcLivTrackData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/msdc");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFPUPAMF)) feedFPupAmf.writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixMsdcVLocale, wr);
	xmlTextWriterEndElement(wr);
};

