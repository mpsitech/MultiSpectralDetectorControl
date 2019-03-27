/**
  * \file PnlMsdcNavOpr.cpp
  * API code for job PnlMsdcNavOpr (implementation)
  * \author Alexander Wirthmueller
  * \date created: 18 Dec 2018
  * \date modified: 18 Dec 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "PnlMsdcNavOpr.h"

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

PnlMsdcNavOpr::StatApp::StatApp(
			const uint ixMsdcVExpstate
			, const bool LstPrdAlt
			, const bool LstDatAlt
			, const bool LstFilAlt
			, const uint LstPrdNumFirstdisp
			, const uint LstDatNumFirstdisp
			, const uint LstFilNumFirstdisp
		) :
			Block()
		{
	this->ixMsdcVExpstate = ixMsdcVExpstate;
	this->LstPrdAlt = LstPrdAlt;
	this->LstDatAlt = LstDatAlt;
	this->LstFilAlt = LstFilAlt;
	this->LstPrdNumFirstdisp = LstPrdNumFirstdisp;
	this->LstDatNumFirstdisp = LstDatNumFirstdisp;
	this->LstFilNumFirstdisp = LstFilNumFirstdisp;

	mask = {IXMSDCVEXPSTATE, LSTPRDALT, LSTDATALT, LSTFILALT, LSTPRDNUMFIRSTDISP, LSTDATNUMFIRSTDISP, LSTFILNUMFIRSTDISP};
};

bool PnlMsdcNavOpr::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxMsdcVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppMsdcNavOpr");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppMsdcNavOpr";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxMsdcVExpstate", srefIxMsdcVExpstate)) {
			ixMsdcVExpstate = VecMsdcVExpstate::getIx(srefIxMsdcVExpstate);
			add(IXMSDCVEXPSTATE);
		};
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstPrdAlt", LstPrdAlt)) add(LSTPRDALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstDatAlt", LstDatAlt)) add(LSTDATALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstFilAlt", LstFilAlt)) add(LSTFILALT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstPrdNumFirstdisp", LstPrdNumFirstdisp)) add(LSTPRDNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstDatNumFirstdisp", LstDatNumFirstdisp)) add(LSTDATNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstFilNumFirstdisp", LstFilNumFirstdisp)) add(LSTFILNUMFIRSTDISP);
	};

	return basefound;
};

set<uint> PnlMsdcNavOpr::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixMsdcVExpstate == comp->ixMsdcVExpstate) insert(items, IXMSDCVEXPSTATE);
	if (LstPrdAlt == comp->LstPrdAlt) insert(items, LSTPRDALT);
	if (LstDatAlt == comp->LstDatAlt) insert(items, LSTDATALT);
	if (LstFilAlt == comp->LstFilAlt) insert(items, LSTFILALT);
	if (LstPrdNumFirstdisp == comp->LstPrdNumFirstdisp) insert(items, LSTPRDNUMFIRSTDISP);
	if (LstDatNumFirstdisp == comp->LstDatNumFirstdisp) insert(items, LSTDATNUMFIRSTDISP);
	if (LstFilNumFirstdisp == comp->LstFilNumFirstdisp) insert(items, LSTFILNUMFIRSTDISP);

	return(items);
};

set<uint> PnlMsdcNavOpr::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXMSDCVEXPSTATE, LSTPRDALT, LSTDATALT, LSTFILALT, LSTPRDNUMFIRSTDISP, LSTDATNUMFIRSTDISP, LSTFILNUMFIRSTDISP};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
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

bool PnlMsdcNavOpr::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrMsdcNavOpr");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrMsdcNavOpr";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButLivNewcrdAvail", ButLivNewcrdAvail)) add(BUTLIVNEWCRDAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstPrdAvail", LstPrdAvail)) add(LSTPRDAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButPrdViewActive", ButPrdViewActive)) add(BUTPRDVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstDatAvail", LstDatAvail)) add(LSTDATAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButDatViewActive", ButDatViewActive)) add(BUTDATVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButDatNewcrdActive", ButDatNewcrdActive)) add(BUTDATNEWCRDACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstFilAvail", LstFilAvail)) add(LSTFILAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButFilViewActive", ButFilViewActive)) add(BUTFILVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButFilNewcrdActive", ButFilNewcrdActive)) add(BUTFILNEWCRDACTIVE);
	};

	return basefound;
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

PnlMsdcNavOpr::Tag::Tag(
			const string& Cpt
			, const string& CptLiv
			, const string& CptPrd
			, const string& CptDat
			, const string& CptFil
		) :
			Block()
		{
	this->Cpt = Cpt;
	this->CptLiv = CptLiv;
	this->CptPrd = CptPrd;
	this->CptDat = CptDat;
	this->CptFil = CptFil;

	mask = {CPT, CPTLIV, CPTPRD, CPTDAT, CPTFIL};
};

bool PnlMsdcNavOpr::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagMsdcNavOpr");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemMsdcNavOpr";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptLiv", CptLiv)) add(CPTLIV);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptPrd", CptPrd)) add(CPTPRD);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptDat", CptDat)) add(CPTDAT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptFil", CptFil)) add(CPTFIL);
	};

	return basefound;
};

/******************************************************************************
 class PnlMsdcNavOpr::DpchAppData
 ******************************************************************************/

PnlMsdcNavOpr::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) :
			DpchAppMsdc(VecMsdcVDpch::DPCHAPPMSDCNAVOPRDATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlMsdcNavOpr::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlMsdcNavOpr::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppMsdcNavOprData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/msdc");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlMsdcNavOpr::DpchAppDo
 ******************************************************************************/

PnlMsdcNavOpr::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppMsdc(VecMsdcVDpch::DPCHAPPMSDCNAVOPRDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlMsdcNavOpr::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlMsdcNavOpr::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppMsdcNavOprDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/msdc");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlMsdcNavOpr::DpchEngData
 ******************************************************************************/

PnlMsdcNavOpr::DpchEngData::DpchEngData() :
			DpchEngMsdc(VecMsdcVDpch::DPCHENGMSDCNAVOPRDATA)
		{
	feedFLstDat.tag = "FeedFLstDat";
	feedFLstFil.tag = "FeedFLstFil";
	feedFLstPrd.tag = "FeedFLstPrd";
};

string PnlMsdcNavOpr::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
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

void PnlMsdcNavOpr::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngMsdcNavOprData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (feedFLstDat.readXML(docctx, basexpath, true)) add(FEEDFLSTDAT);
		if (feedFLstFil.readXML(docctx, basexpath, true)) add(FEEDFLSTFIL);
		if (feedFLstPrd.readXML(docctx, basexpath, true)) add(FEEDFLSTPRD);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		feedFLstDat.clear();
		feedFLstFil.clear();
		feedFLstPrd.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};

