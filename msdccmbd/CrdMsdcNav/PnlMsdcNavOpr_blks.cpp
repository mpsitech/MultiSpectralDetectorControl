/**
  * \file PnlMsdcNavOpr_blks.cpp
  * job handler for job PnlMsdcNavOpr (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 29 Aug 2018
  * \date modified: 29 Aug 2018
  */

/******************************************************************************
 class PnlMsdcNavOpr::VecVDo
 ******************************************************************************/

uint PnlMsdcNavOpr::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butlivnewcrdclick") return BUTLIVNEWCRDCLICK;
	if (s == "butprdviewclick") return BUTPRDVIEWCLICK;
	if (s == "butprdnewcrdclick") return BUTPRDNEWCRDCLICK;
	if (s == "butdatviewclick") return BUTDATVIEWCLICK;
	if (s == "butdatnewcrdclick") return BUTDATNEWCRDCLICK;
	if (s == "butfilviewclick") return BUTFILVIEWCLICK;
	if (s == "butfilnewcrdclick") return BUTFILNEWCRDCLICK;

	return(0);
};

string PnlMsdcNavOpr::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTLIVNEWCRDCLICK) return("ButLivNewcrdClick");
	if (ix == BUTPRDVIEWCLICK) return("ButPrdViewClick");
	if (ix == BUTPRDNEWCRDCLICK) return("ButPrdNewcrdClick");
	if (ix == BUTDATVIEWCLICK) return("ButDatViewClick");
	if (ix == BUTDATNEWCRDCLICK) return("ButDatNewcrdClick");
	if (ix == BUTFILVIEWCLICK) return("ButFilViewClick");
	if (ix == BUTFILNEWCRDCLICK) return("ButFilNewcrdClick");

	return("");
};

/******************************************************************************
 class PnlMsdcNavOpr::ContIac
 ******************************************************************************/

PnlMsdcNavOpr::ContIac::ContIac(
			const uint numFLstPrd
			, const uint numFLstDat
			, const uint numFLstFil
		) :
			Block()
		{
	this->numFLstPrd = numFLstPrd;
	this->numFLstDat = numFLstDat;
	this->numFLstFil = numFLstFil;

	mask = {NUMFLSTPRD, NUMFLSTDAT, NUMFLSTFIL};
};

bool PnlMsdcNavOpr::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacMsdcNavOpr");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacMsdcNavOpr";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstPrd", numFLstPrd)) add(NUMFLSTPRD);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstDat", numFLstDat)) add(NUMFLSTDAT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstFil", numFLstFil)) add(NUMFLSTFIL);
	};

	return basefound;
};

void PnlMsdcNavOpr::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacMsdcNavOpr";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacMsdcNavOpr";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFLstPrd", numFLstPrd);
		writeUintAttr(wr, itemtag, "sref", "numFLstDat", numFLstDat);
		writeUintAttr(wr, itemtag, "sref", "numFLstFil", numFLstFil);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlMsdcNavOpr::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFLstPrd == comp->numFLstPrd) insert(items, NUMFLSTPRD);
	if (numFLstDat == comp->numFLstDat) insert(items, NUMFLSTDAT);
	if (numFLstFil == comp->numFLstFil) insert(items, NUMFLSTFIL);

	return(items);
};

set<uint> PnlMsdcNavOpr::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFLSTPRD, NUMFLSTDAT, NUMFLSTFIL};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlMsdcNavOpr::StatApp
 ******************************************************************************/

void PnlMsdcNavOpr::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixMsdcVExpstate
			, const bool LstPrdAlt
			, const bool LstDatAlt
			, const bool LstFilAlt
			, const uint LstPrdNumFirstdisp
			, const uint LstDatNumFirstdisp
			, const uint LstFilNumFirstdisp
		) {
	if (difftag.length() == 0) difftag = "StatAppMsdcNavOpr";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppMsdcNavOpr";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxMsdcVExpstate", VecMsdcVExpstate::getSref(ixMsdcVExpstate));
		writeBoolAttr(wr, itemtag, "sref", "LstPrdAlt", LstPrdAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstDatAlt", LstDatAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstFilAlt", LstFilAlt);
		writeUintAttr(wr, itemtag, "sref", "LstPrdNumFirstdisp", LstPrdNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstDatNumFirstdisp", LstDatNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstFilNumFirstdisp", LstFilNumFirstdisp);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlMsdcNavOpr::StatShr
 ******************************************************************************/

PnlMsdcNavOpr::StatShr::StatShr(
			const bool ButLivNewcrdAvail
			, const bool LstPrdAvail
			, const bool ButPrdViewActive
			, const bool LstDatAvail
			, const bool ButDatViewActive
			, const bool ButDatNewcrdActive
			, const bool LstFilAvail
			, const bool ButFilViewActive
			, const bool ButFilNewcrdActive
		) :
			Block()
		{
	this->ButLivNewcrdAvail = ButLivNewcrdAvail;
	this->LstPrdAvail = LstPrdAvail;
	this->ButPrdViewActive = ButPrdViewActive;
	this->LstDatAvail = LstDatAvail;
	this->ButDatViewActive = ButDatViewActive;
	this->ButDatNewcrdActive = ButDatNewcrdActive;
	this->LstFilAvail = LstFilAvail;
	this->ButFilViewActive = ButFilViewActive;
	this->ButFilNewcrdActive = ButFilNewcrdActive;

	mask = {BUTLIVNEWCRDAVAIL, LSTPRDAVAIL, BUTPRDVIEWACTIVE, LSTDATAVAIL, BUTDATVIEWACTIVE, BUTDATNEWCRDACTIVE, LSTFILAVAIL, BUTFILVIEWACTIVE, BUTFILNEWCRDACTIVE};
};

void PnlMsdcNavOpr::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrMsdcNavOpr";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrMsdcNavOpr";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButLivNewcrdAvail", ButLivNewcrdAvail);
		writeBoolAttr(wr, itemtag, "sref", "LstPrdAvail", LstPrdAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButPrdViewActive", ButPrdViewActive);
		writeBoolAttr(wr, itemtag, "sref", "LstDatAvail", LstDatAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButDatViewActive", ButDatViewActive);
		writeBoolAttr(wr, itemtag, "sref", "ButDatNewcrdActive", ButDatNewcrdActive);
		writeBoolAttr(wr, itemtag, "sref", "LstFilAvail", LstFilAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButFilViewActive", ButFilViewActive);
		writeBoolAttr(wr, itemtag, "sref", "ButFilNewcrdActive", ButFilNewcrdActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlMsdcNavOpr::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButLivNewcrdAvail == comp->ButLivNewcrdAvail) insert(items, BUTLIVNEWCRDAVAIL);
	if (LstPrdAvail == comp->LstPrdAvail) insert(items, LSTPRDAVAIL);
	if (ButPrdViewActive == comp->ButPrdViewActive) insert(items, BUTPRDVIEWACTIVE);
	if (LstDatAvail == comp->LstDatAvail) insert(items, LSTDATAVAIL);
	if (ButDatViewActive == comp->ButDatViewActive) insert(items, BUTDATVIEWACTIVE);
	if (ButDatNewcrdActive == comp->ButDatNewcrdActive) insert(items, BUTDATNEWCRDACTIVE);
	if (LstFilAvail == comp->LstFilAvail) insert(items, LSTFILAVAIL);
	if (ButFilViewActive == comp->ButFilViewActive) insert(items, BUTFILVIEWACTIVE);
	if (ButFilNewcrdActive == comp->ButFilNewcrdActive) insert(items, BUTFILNEWCRDACTIVE);

	return(items);
};

set<uint> PnlMsdcNavOpr::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTLIVNEWCRDAVAIL, LSTPRDAVAIL, BUTPRDVIEWACTIVE, LSTDATAVAIL, BUTDATVIEWACTIVE, BUTDATNEWCRDACTIVE, LSTFILAVAIL, BUTFILVIEWACTIVE, BUTFILNEWCRDACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlMsdcNavOpr::Tag
 ******************************************************************************/

void PnlMsdcNavOpr::Tag::writeXML(
			const uint ixMsdcVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagMsdcNavOpr";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemMsdcNavOpr";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixMsdcVLocale == VecMsdcVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Operation module");
			writeStringAttr(wr, itemtag, "sref", "CptLiv", "live data");
			writeStringAttr(wr, itemtag, "sref", "CptPrd", "acquisition periods");
			writeStringAttr(wr, itemtag, "sref", "CptDat", "raw data");
			writeStringAttr(wr, itemtag, "sref", "CptFil", "files");
		} else if (ixMsdcVLocale == VecMsdcVLocale::DECH) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Betrieb");
			writeStringAttr(wr, itemtag, "sref", "CptLiv", "Live-Daten");
			writeStringAttr(wr, itemtag, "sref", "CptPrd", "Auszeichnungsperioden");
			writeStringAttr(wr, itemtag, "sref", "CptDat", "Rohdaten");
			writeStringAttr(wr, itemtag, "sref", "CptFil", "Dateien");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlMsdcNavOpr::DpchAppData
 ******************************************************************************/

PnlMsdcNavOpr::DpchAppData::DpchAppData() :
			DpchAppMsdc(VecMsdcVDpch::DPCHAPPMSDCNAVOPRDATA)
		{
};

string PnlMsdcNavOpr::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlMsdcNavOpr::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppMsdcNavOprData");
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
 class PnlMsdcNavOpr::DpchAppDo
 ******************************************************************************/

PnlMsdcNavOpr::DpchAppDo::DpchAppDo() :
			DpchAppMsdc(VecMsdcVDpch::DPCHAPPMSDCNAVOPRDO)
		{
	ixVDo = 0;
};

string PnlMsdcNavOpr::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlMsdcNavOpr::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppMsdcNavOprDo");
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
 class PnlMsdcNavOpr::DpchEngData
 ******************************************************************************/

PnlMsdcNavOpr::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, Feed* feedFLstDat
			, Feed* feedFLstFil
			, Feed* feedFLstPrd
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngMsdc(VecMsdcVDpch::DPCHENGMSDCNAVOPRDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, FEEDFLSTDAT, FEEDFLSTFIL, FEEDFLSTPRD, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, FEEDFLSTDAT) && feedFLstDat) this->feedFLstDat = *feedFLstDat;
	if (find(this->mask, FEEDFLSTFIL) && feedFLstFil) this->feedFLstFil = *feedFLstFil;
	if (find(this->mask, FEEDFLSTPRD) && feedFLstPrd) this->feedFLstPrd = *feedFLstPrd;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlMsdcNavOpr::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(FEEDFLSTDAT)) ss.push_back("feedFLstDat");
	if (has(FEEDFLSTFIL)) ss.push_back("feedFLstFil");
	if (has(FEEDFLSTPRD)) ss.push_back("feedFLstPrd");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlMsdcNavOpr::DpchEngData::merge(
			DpchEngMsdc* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(FEEDFLSTDAT)) {feedFLstDat = src->feedFLstDat; add(FEEDFLSTDAT);};
	if (src->has(FEEDFLSTFIL)) {feedFLstFil = src->feedFLstFil; add(FEEDFLSTFIL);};
	if (src->has(FEEDFLSTPRD)) {feedFLstPrd = src->feedFLstPrd; add(FEEDFLSTPRD);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlMsdcNavOpr::DpchEngData::writeXML(
			const uint ixMsdcVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngMsdcNavOprData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/msdc");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(FEEDFLSTDAT)) feedFLstDat.writeXML(wr);
		if (has(FEEDFLSTFIL)) feedFLstFil.writeXML(wr);
		if (has(FEEDFLSTPRD)) feedFLstPrd.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixMsdcVLocale, wr);
	xmlTextWriterEndElement(wr);
};

