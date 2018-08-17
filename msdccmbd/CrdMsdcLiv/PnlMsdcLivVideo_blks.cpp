/**
  * \file PnlMsdcLivVideo_blks.cpp
  * job handler for job PnlMsdcLivVideo (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 15 Aug 2018
  * \date modified: 15 Aug 2018
  */

/******************************************************************************
 class PnlMsdcLivVideo::VecVDo
 ******************************************************************************/

uint PnlMsdcLivVideo::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butmasterclick") return BUTMASTERCLICK;
	if (s == "butplayclick") return BUTPLAYCLICK;
	if (s == "butstopclick") return BUTSTOPCLICK;

	return(0);
};

string PnlMsdcLivVideo::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTMASTERCLICK) return("ButMasterClick");
	if (ix == BUTPLAYCLICK) return("ButPlayClick");
	if (ix == BUTSTOPCLICK) return("ButStopClick");

	return("");
};

/******************************************************************************
 class PnlMsdcLivVideo::VecVSource
 ******************************************************************************/

uint PnlMsdcLivVideo::VecVSource::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "void") return VOID;
	if (s == "visl") return VISL;
	if (s == "visr") return VISR;
	if (s == "lwir") return LWIR;

	return(0);
};

string PnlMsdcLivVideo::VecVSource::getSref(
			const uint ix
		) {
	if (ix == VOID) return("void");
	if (ix == VISL) return("visl");
	if (ix == VISR) return("visr");
	if (ix == LWIR) return("lwir");

	return("");
};

string PnlMsdcLivVideo::VecVSource::getTitle(
			const uint ix
			, const uint ixMsdcVLocale
		) {
	if (ixMsdcVLocale == 1) {
		if (ix == VOID) return("none");
		if (ix == VISL) return("VIS-L camera");
		if (ix == VISR) return("VIS-R camera");
		if (ix == LWIR) return("LWIR camera");
		return(getSref(ix));
	} else if (ixMsdcVLocale == 2) {
		if (ix == VOID) return("keine");
		if (ix == VISL) return("VIS-L-Kamera");
		if (ix == VISR) return("VIS-R-Kamera");
		if (ix == LWIR) return("LWIR-Kamera");
		return(getTitle(ix, 1));
	};

	return("");
};

void PnlMsdcLivVideo::VecVSource::fillFeed(
			const uint ixMsdcVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=4;i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixMsdcVLocale));
};

/******************************************************************************
 class PnlMsdcLivVideo::ContIac
 ******************************************************************************/

PnlMsdcLivVideo::ContIac::ContIac(
			const uint numFPupSrc
			, const uint numFPupRes
			, const double SldExt
			, const double SldFcs
		) : Block() {
	this->numFPupSrc = numFPupSrc;
	this->numFPupRes = numFPupRes;
	this->SldExt = SldExt;
	this->SldFcs = SldFcs;

	mask = {NUMFPUPSRC, NUMFPUPRES, SLDEXT, SLDFCS};
};

bool PnlMsdcLivVideo::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacMsdcLivVideo");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacMsdcLivVideo";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupSrc", numFPupSrc)) add(NUMFPUPSRC);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupRes", numFPupRes)) add(NUMFPUPRES);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "SldExt", SldExt)) add(SLDEXT);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "SldFcs", SldFcs)) add(SLDFCS);
	};

	return basefound;
};

void PnlMsdcLivVideo::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacMsdcLivVideo";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacMsdcLivVideo";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFPupSrc", numFPupSrc);
		writeUintAttr(wr, itemtag, "sref", "numFPupRes", numFPupRes);
		writeDoubleAttr(wr, itemtag, "sref", "SldExt", SldExt);
		writeDoubleAttr(wr, itemtag, "sref", "SldFcs", SldFcs);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlMsdcLivVideo::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFPupSrc == comp->numFPupSrc) insert(items, NUMFPUPSRC);
	if (numFPupRes == comp->numFPupRes) insert(items, NUMFPUPRES);
	if (compareDouble(SldExt, comp->SldExt) < 1.0e-4) insert(items, SLDEXT);
	if (compareDouble(SldFcs, comp->SldFcs) < 1.0e-4) insert(items, SLDFCS);

	return(items);
};

set<uint> PnlMsdcLivVideo::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFPUPSRC, NUMFPUPRES, SLDEXT, SLDFCS};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlMsdcLivVideo::ContInf
 ******************************************************************************/

PnlMsdcLivVideo::ContInf::ContInf(
			const bool ButMasterOn
		) : Block() {
	this->ButMasterOn = ButMasterOn;

	mask = {BUTMASTERON};
};

void PnlMsdcLivVideo::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfMsdcLivVideo";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfMsdcLivVideo";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButMasterOn", ButMasterOn);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlMsdcLivVideo::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (ButMasterOn == comp->ButMasterOn) insert(items, BUTMASTERON);

	return(items);
};

set<uint> PnlMsdcLivVideo::ContInf::diff(
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
 class PnlMsdcLivVideo::StatApp
 ******************************************************************************/

void PnlMsdcLivVideo::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixMsdcVExpstate
		) {
	if (difftag.length() == 0) difftag = "StatAppMsdcLivVideo";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppMsdcLivVideo";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxMsdcVExpstate", VecMsdcVExpstate::getSref(ixMsdcVExpstate));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlMsdcLivVideo::StatShr
 ******************************************************************************/

PnlMsdcLivVideo::StatShr::StatShr(
			const bool PupResAvail
			, const bool ButPlayActive
			, const bool ButStopActive
			, const bool SldExtAvail
			, const bool SldExtActive
			, const double SldExtMin
			, const double SldExtMax
			, const double SldExtRast
			, const bool SldFcsAvail
			, const bool SldFcsActive
			, const double SldFcsMin
			, const double SldFcsMax
		) : Block() {
	this->PupResAvail = PupResAvail;
	this->ButPlayActive = ButPlayActive;
	this->ButStopActive = ButStopActive;
	this->SldExtAvail = SldExtAvail;
	this->SldExtActive = SldExtActive;
	this->SldExtMin = SldExtMin;
	this->SldExtMax = SldExtMax;
	this->SldExtRast = SldExtRast;
	this->SldFcsAvail = SldFcsAvail;
	this->SldFcsActive = SldFcsActive;
	this->SldFcsMin = SldFcsMin;
	this->SldFcsMax = SldFcsMax;

	mask = {PUPRESAVAIL, BUTPLAYACTIVE, BUTSTOPACTIVE, SLDEXTAVAIL, SLDEXTACTIVE, SLDEXTMIN, SLDEXTMAX, SLDEXTRAST, SLDFCSAVAIL, SLDFCSACTIVE, SLDFCSMIN, SLDFCSMAX};
};

void PnlMsdcLivVideo::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrMsdcLivVideo";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrMsdcLivVideo";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "PupResAvail", PupResAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButPlayActive", ButPlayActive);
		writeBoolAttr(wr, itemtag, "sref", "ButStopActive", ButStopActive);
		writeBoolAttr(wr, itemtag, "sref", "SldExtAvail", SldExtAvail);
		writeBoolAttr(wr, itemtag, "sref", "SldExtActive", SldExtActive);
		writeDoubleAttr(wr, itemtag, "sref", "SldExtMin", SldExtMin);
		writeDoubleAttr(wr, itemtag, "sref", "SldExtMax", SldExtMax);
		writeDoubleAttr(wr, itemtag, "sref", "SldExtRast", SldExtRast);
		writeBoolAttr(wr, itemtag, "sref", "SldFcsAvail", SldFcsAvail);
		writeBoolAttr(wr, itemtag, "sref", "SldFcsActive", SldFcsActive);
		writeDoubleAttr(wr, itemtag, "sref", "SldFcsMin", SldFcsMin);
		writeDoubleAttr(wr, itemtag, "sref", "SldFcsMax", SldFcsMax);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlMsdcLivVideo::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (PupResAvail == comp->PupResAvail) insert(items, PUPRESAVAIL);
	if (ButPlayActive == comp->ButPlayActive) insert(items, BUTPLAYACTIVE);
	if (ButStopActive == comp->ButStopActive) insert(items, BUTSTOPACTIVE);
	if (SldExtAvail == comp->SldExtAvail) insert(items, SLDEXTAVAIL);
	if (SldExtActive == comp->SldExtActive) insert(items, SLDEXTACTIVE);
	if (compareDouble(SldExtMin, comp->SldExtMin) < 1.0e-4) insert(items, SLDEXTMIN);
	if (compareDouble(SldExtMax, comp->SldExtMax) < 1.0e-4) insert(items, SLDEXTMAX);
	if (compareDouble(SldExtRast, comp->SldExtRast) < 1.0e-4) insert(items, SLDEXTRAST);
	if (SldFcsAvail == comp->SldFcsAvail) insert(items, SLDFCSAVAIL);
	if (SldFcsActive == comp->SldFcsActive) insert(items, SLDFCSACTIVE);
	if (compareDouble(SldFcsMin, comp->SldFcsMin) < 1.0e-4) insert(items, SLDFCSMIN);
	if (compareDouble(SldFcsMax, comp->SldFcsMax) < 1.0e-4) insert(items, SLDFCSMAX);

	return(items);
};

set<uint> PnlMsdcLivVideo::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {PUPRESAVAIL, BUTPLAYACTIVE, BUTSTOPACTIVE, SLDEXTAVAIL, SLDEXTACTIVE, SLDEXTMIN, SLDEXTMAX, SLDEXTRAST, SLDFCSAVAIL, SLDFCSACTIVE, SLDFCSMIN, SLDFCSMAX};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlMsdcLivVideo::Tag
 ******************************************************************************/

void PnlMsdcLivVideo::Tag::writeXML(
			const uint ixMsdcVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagMsdcLivVideo";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemMsdcLivVideo";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixMsdcVLocale == VecMsdcVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Video");
			writeStringAttr(wr, itemtag, "sref", "CptSrc", "source");
			writeStringAttr(wr, itemtag, "sref", "CptRes", "resolution");
			writeStringAttr(wr, itemtag, "sref", "CptExt", "exposure time [ms]");
			writeStringAttr(wr, itemtag, "sref", "CptFcs", "focus");
		} else if (ixMsdcVLocale == VecMsdcVLocale::DECH) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Video");
			writeStringAttr(wr, itemtag, "sref", "CptSrc", "Quelle");
			writeStringAttr(wr, itemtag, "sref", "CptRes", "Aufl\\u00f6sung");
			writeStringAttr(wr, itemtag, "sref", "CptExt", "Belichtungszeit [ms]");
			writeStringAttr(wr, itemtag, "sref", "CptFcs", "Fokus");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlMsdcLivVideo::DpchAppData
 ******************************************************************************/

PnlMsdcLivVideo::DpchAppData::DpchAppData() : DpchAppMsdc(VecMsdcVDpch::DPCHAPPMSDCLIVVIDEODATA) {
};

string PnlMsdcLivVideo::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlMsdcLivVideo::DpchAppData::readXML(
			pthread_mutex_t* mScr
			, map<string,ubigint>& descr
			, xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppMsdcLivVideoData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) {
			jref = Scr::descramble(mScr, descr, scrJref);
			add(JREF);
		};
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
	} else {
		contiac = ContIac();
	};
};

/******************************************************************************
 class PnlMsdcLivVideo::DpchAppDo
 ******************************************************************************/

PnlMsdcLivVideo::DpchAppDo::DpchAppDo() : DpchAppMsdc(VecMsdcVDpch::DPCHAPPMSDCLIVVIDEODO) {
	ixVDo = 0;
};

string PnlMsdcLivVideo::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlMsdcLivVideo::DpchAppDo::readXML(
			pthread_mutex_t* mScr
			, map<string,ubigint>& descr
			, xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppMsdcLivVideoDo");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) {
			jref = Scr::descramble(mScr, descr, scrJref);
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
 class PnlMsdcLivVideo::DpchEngData
 ******************************************************************************/

PnlMsdcLivVideo::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, Feed* feedFPupRes
			, Feed* feedFPupSrc
			, StatShr* statshr
			, const set<uint>& mask
		) : DpchEngMsdc(VecMsdcVDpch::DPCHENGMSDCLIVVIDEODATA, jref) {
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, FEEDFPUPRES, FEEDFPUPSRC, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFPUPRES) && feedFPupRes) this->feedFPupRes = *feedFPupRes;
	if (find(this->mask, FEEDFPUPSRC) && feedFPupSrc) this->feedFPupSrc = *feedFPupSrc;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlMsdcLivVideo::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFPUPRES)) ss.push_back("feedFPupRes");
	if (has(FEEDFPUPSRC)) ss.push_back("feedFPupSrc");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlMsdcLivVideo::DpchEngData::merge(
			DpchEngMsdc* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFPUPRES)) {feedFPupRes = src->feedFPupRes; add(FEEDFPUPRES);};
	if (src->has(FEEDFPUPSRC)) {feedFPupSrc = src->feedFPupSrc; add(FEEDFPUPSRC);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlMsdcLivVideo::DpchEngData::writeXML(
			const uint ixMsdcVLocale
			, pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngMsdcLivVideoData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/msdc");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFPUPRES)) feedFPupRes.writeXML(wr);
		if (has(FEEDFPUPSRC)) feedFPupSrc.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixMsdcVLocale, wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlMsdcLivVideo::DpchEngLive
 ******************************************************************************/

PnlMsdcLivVideo::DpchEngLive::DpchEngLive(
			const ubigint jref
			, ContInf* continf
			, const vector<utinyint>& rgb
			, const vector<utinyint>& red
			, const vector<utinyint>& green
			, const vector<utinyint>& blue
			, const vector<usmallint>& gray
			, const set<uint>& mask
		) : DpchEngMsdc(VecMsdcVDpch::DPCHENGMSDCLIVVIDEOLIVE, jref) {
	if (find(mask, ALL)) this->mask = {JREF, CONTINF, RGB, RED, GREEN, BLUE, GRAY};
	else this->mask = mask;

	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	this->rgb = rgb;
	this->red = red;
	this->green = green;
	this->blue = blue;
	this->gray = gray;
};

string PnlMsdcLivVideo::DpchEngLive::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(RGB)) ss.push_back("rgb");
	if (has(RED)) ss.push_back("red");
	if (has(GREEN)) ss.push_back("green");
	if (has(BLUE)) ss.push_back("blue");
	if (has(GRAY)) ss.push_back("gray");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlMsdcLivVideo::DpchEngLive::merge(
			DpchEngMsdc* dpcheng
		) {
	DpchEngLive* src = (DpchEngLive*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(RGB)) {rgb = src->rgb; add(RGB);};
	if (src->has(RED)) {red = src->red; add(RED);};
	if (src->has(GREEN)) {green = src->green; add(GREEN);};
	if (src->has(BLUE)) {blue = src->blue; add(BLUE);};
	if (src->has(GRAY)) {gray = src->gray; add(GRAY);};
};

void PnlMsdcLivVideo::DpchEngLive::writeXML(
			const uint ixMsdcVLocale
			, pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngMsdcLivVideoLive");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/msdc");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(RGB)) writeUtinyintvec(wr, "rgb", rgb);
		if (has(RED)) writeUtinyintvec(wr, "red", red);
		if (has(GREEN)) writeUtinyintvec(wr, "green", green);
		if (has(BLUE)) writeUtinyintvec(wr, "blue", blue);
		if (has(GRAY)) writeUsmallintvec(wr, "gray", gray);
	xmlTextWriterEndElement(wr);
};

