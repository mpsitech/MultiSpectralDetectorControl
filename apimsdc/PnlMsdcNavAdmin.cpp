/**
  * \file PnlMsdcNavAdmin.cpp
  * API code for job PnlMsdcNavAdmin (implementation)
  * \author Alexander Wirthmueller
  * \date created: 15 Aug 2018
  * \date modified: 15 Aug 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "PnlMsdcNavAdmin.h"

/******************************************************************************
 class PnlMsdcNavAdmin::VecVDo
 ******************************************************************************/

uint PnlMsdcNavAdmin::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butusgviewclick") return BUTUSGVIEWCLICK;
	if (s == "butusgnewcrdclick") return BUTUSGNEWCRDCLICK;
	if (s == "butusrviewclick") return BUTUSRVIEWCLICK;
	if (s == "butusrnewcrdclick") return BUTUSRNEWCRDCLICK;
	if (s == "butprsviewclick") return BUTPRSVIEWCLICK;
	if (s == "butprsnewcrdclick") return BUTPRSNEWCRDCLICK;
	if (s == "butscfnewcrdclick") return BUTSCFNEWCRDCLICK;

	return(0);
};

string PnlMsdcNavAdmin::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTUSGVIEWCLICK) return("ButUsgViewClick");
	if (ix == BUTUSGNEWCRDCLICK) return("ButUsgNewcrdClick");
	if (ix == BUTUSRVIEWCLICK) return("ButUsrViewClick");
	if (ix == BUTUSRNEWCRDCLICK) return("ButUsrNewcrdClick");
	if (ix == BUTPRSVIEWCLICK) return("ButPrsViewClick");
	if (ix == BUTPRSNEWCRDCLICK) return("ButPrsNewcrdClick");
	if (ix == BUTSCFNEWCRDCLICK) return("ButScfNewcrdClick");

	return("");
};

/******************************************************************************
 class PnlMsdcNavAdmin::ContIac
 ******************************************************************************/

PnlMsdcNavAdmin::ContIac::ContIac(
			const uint numFLstUsg
			, const uint numFLstUsr
			, const uint numFLstPrs
		) : Block() {
	this->numFLstUsg = numFLstUsg;
	this->numFLstUsr = numFLstUsr;
	this->numFLstPrs = numFLstPrs;

	mask = {NUMFLSTUSG, NUMFLSTUSR, NUMFLSTPRS};
};

bool PnlMsdcNavAdmin::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacMsdcNavAdmin");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacMsdcNavAdmin";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstUsg", numFLstUsg)) add(NUMFLSTUSG);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstUsr", numFLstUsr)) add(NUMFLSTUSR);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstPrs", numFLstPrs)) add(NUMFLSTPRS);
	};

	return basefound;
};

void PnlMsdcNavAdmin::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacMsdcNavAdmin";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacMsdcNavAdmin";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFLstUsg", numFLstUsg);
		writeUintAttr(wr, itemtag, "sref", "numFLstUsr", numFLstUsr);
		writeUintAttr(wr, itemtag, "sref", "numFLstPrs", numFLstPrs);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlMsdcNavAdmin::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFLstUsg == comp->numFLstUsg) insert(items, NUMFLSTUSG);
	if (numFLstUsr == comp->numFLstUsr) insert(items, NUMFLSTUSR);
	if (numFLstPrs == comp->numFLstPrs) insert(items, NUMFLSTPRS);

	return(items);
};

set<uint> PnlMsdcNavAdmin::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {, NUMFLSTUSR, NUMFLSTPRS};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlMsdcNavAdmin::StatApp
 ******************************************************************************/

PnlMsdcNavAdmin::StatApp::StatApp(
			const uint ixMsdcVExpstate
			, const bool LstUsgAlt
			, const bool LstUsrAlt
			, const bool LstPrsAlt
			, const uint LstUsgNumFirstdisp
			, const uint LstUsrNumFirstdisp
			, const uint LstPrsNumFirstdisp
		) : Block() {
	this->ixMsdcVExpstate = ixMsdcVExpstate;
	this->LstUsgAlt = LstUsgAlt;
	this->LstUsrAlt = LstUsrAlt;
	this->LstPrsAlt = LstPrsAlt;
	this->LstUsgNumFirstdisp = LstUsgNumFirstdisp;
	this->LstUsrNumFirstdisp = LstUsrNumFirstdisp;
	this->LstPrsNumFirstdisp = LstPrsNumFirstdisp;

	mask = {IXMSDCVEXPSTATE, LSTUSGALT, LSTUSRALT, LSTPRSALT, LSTUSGNUMFIRSTDISP, LSTUSRNUMFIRSTDISP, LSTPRSNUMFIRSTDISP};
};

bool PnlMsdcNavAdmin::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxMsdcVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppMsdcNavAdmin");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppMsdcNavAdmin";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxMsdcVExpstate", srefIxMsdcVExpstate)) {
			ixMsdcVExpstate = VecMsdcVExpstate::getIx(srefIxMsdcVExpstate);
			add(IXMSDCVEXPSTATE);
		};
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstUsgAlt", LstUsgAlt)) add(LSTUSGALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstUsrAlt", LstUsrAlt)) add(LSTUSRALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstPrsAlt", LstPrsAlt)) add(LSTPRSALT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstUsgNumFirstdisp", LstUsgNumFirstdisp)) add(LSTUSGNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstUsrNumFirstdisp", LstUsrNumFirstdisp)) add(LSTUSRNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstPrsNumFirstdisp", LstPrsNumFirstdisp)) add(LSTPRSNUMFIRSTDISP);
	};

	return basefound;
};

set<uint> PnlMsdcNavAdmin::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixMsdcVExpstate == comp->ixMsdcVExpstate) insert(items, IXMSDCVEXPSTATE);
	if (LstUsgAlt == comp->LstUsgAlt) insert(items, LSTUSGALT);
	if (LstUsrAlt == comp->LstUsrAlt) insert(items, LSTUSRALT);
	if (LstPrsAlt == comp->LstPrsAlt) insert(items, LSTPRSALT);
	if (LstUsgNumFirstdisp == comp->LstUsgNumFirstdisp) insert(items, LSTUSGNUMFIRSTDISP);
	if (LstUsrNumFirstdisp == comp->LstUsrNumFirstdisp) insert(items, LSTUSRNUMFIRSTDISP);
	if (LstPrsNumFirstdisp == comp->LstPrsNumFirstdisp) insert(items, LSTPRSNUMFIRSTDISP);

	return(items);
};

set<uint> PnlMsdcNavAdmin::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXMSDCVEXPSTATE, LSTUSGALT, LSTUSRALT, LSTPRSALT, LSTUSGNUMFIRSTDISP, LSTUSRNUMFIRSTDISP, LSTPRSNUMFIRSTDISP};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlMsdcNavAdmin::StatShr
 ******************************************************************************/

PnlMsdcNavAdmin::StatShr::StatShr(
			const bool LstUsgAvail
			, const bool ButUsgViewActive
			, const bool LstUsrAvail
			, const bool ButUsrViewActive
			, const bool LstPrsAvail
			, const bool ButPrsViewActive
			, const bool ButScfNewcrdAvail
		) : Block() {
	this->LstUsgAvail = LstUsgAvail;
	this->ButUsgViewActive = ButUsgViewActive;
	this->LstUsrAvail = LstUsrAvail;
	this->ButUsrViewActive = ButUsrViewActive;
	this->LstPrsAvail = LstPrsAvail;
	this->ButPrsViewActive = ButPrsViewActive;
	this->ButScfNewcrdAvail = ButScfNewcrdAvail;

	mask = {LSTUSGAVAIL, BUTUSGVIEWACTIVE, LSTUSRAVAIL, BUTUSRVIEWACTIVE, LSTPRSAVAIL, BUTPRSVIEWACTIVE, BUTSCFNEWCRDAVAIL};
};

bool PnlMsdcNavAdmin::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrMsdcNavAdmin");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrMsdcNavAdmin";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstUsgAvail", LstUsgAvail)) add(LSTUSGAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButUsgViewActive", ButUsgViewActive)) add(BUTUSGVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstUsrAvail", LstUsrAvail)) add(LSTUSRAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButUsrViewActive", ButUsrViewActive)) add(BUTUSRVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstPrsAvail", LstPrsAvail)) add(LSTPRSAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButPrsViewActive", ButPrsViewActive)) add(BUTPRSVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButScfNewcrdAvail", ButScfNewcrdAvail)) add(BUTSCFNEWCRDAVAIL);
	};

	return basefound;
};

set<uint> PnlMsdcNavAdmin::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (LstUsgAvail == comp->LstUsgAvail) insert(items, LSTUSGAVAIL);
	if (ButUsgViewActive == comp->ButUsgViewActive) insert(items, BUTUSGVIEWACTIVE);
	if (LstUsrAvail == comp->LstUsrAvail) insert(items, LSTUSRAVAIL);
	if (ButUsrViewActive == comp->ButUsrViewActive) insert(items, BUTUSRVIEWACTIVE);
	if (LstPrsAvail == comp->LstPrsAvail) insert(items, LSTPRSAVAIL);
	if (ButPrsViewActive == comp->ButPrsViewActive) insert(items, BUTPRSVIEWACTIVE);
	if (ButScfNewcrdAvail == comp->ButScfNewcrdAvail) insert(items, BUTSCFNEWCRDAVAIL);

	return(items);
};

set<uint> PnlMsdcNavAdmin::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {LSTUSGAVAIL, BUTUSGVIEWACTIVE, LSTUSRAVAIL, BUTUSRVIEWACTIVE, LSTPRSAVAIL, BUTPRSVIEWACTIVE, BUTSCFNEWCRDAVAIL};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlMsdcNavAdmin::Tag
 ******************************************************************************/

PnlMsdcNavAdmin::Tag::Tag(
			const string& Cpt
			, const string& CptUsg
			, const string& CptUsr
			, const string& CptPrs
			, const string& CptScf
		) : Block() {
	this->Cpt = Cpt;
	this->CptUsg = CptUsg;
	this->CptUsr = CptUsr;
	this->CptPrs = CptPrs;
	this->CptScf = CptScf;

	mask = {CPT, CPTUSG, CPTUSR, CPTPRS, CPTSCF};
};

bool PnlMsdcNavAdmin::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagMsdcNavAdmin");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemMsdcNavAdmin";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptUsg", CptUsg)) add(CPTUSG);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptUsr", CptUsr)) add(CPTUSR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptPrs", CptPrs)) add(CPTPRS);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptScf", CptScf)) add(CPTSCF);
	};

	return basefound;
};

/******************************************************************************
 class PnlMsdcNavAdmin::DpchAppData
 ******************************************************************************/

PnlMsdcNavAdmin::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) : DpchAppMsdc(VecMsdcVDpch::DPCHAPPMSDCNAVADMINDATA, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlMsdcNavAdmin::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlMsdcNavAdmin::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppMsdcNavAdminData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/msdc");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlMsdcNavAdmin::DpchAppDo
 ******************************************************************************/

PnlMsdcNavAdmin::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) : DpchAppMsdc(VecMsdcVDpch::DPCHAPPMSDCNAVADMINDO, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlMsdcNavAdmin::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlMsdcNavAdmin::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppMsdcNavAdminDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/msdc");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlMsdcNavAdmin::DpchEngData
 ******************************************************************************/

PnlMsdcNavAdmin::DpchEngData::DpchEngData() : DpchEngMsdc(VecMsdcVDpch::DPCHENGMSDCNAVADMINDATA) {
	feedFLstPrs.tag = "FeedFLstPrs";
	feedFLstUsg.tag = "FeedFLstUsg";
	feedFLstUsr.tag = "FeedFLstUsr";
};

string PnlMsdcNavAdmin::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(FEEDFLSTPRS)) ss.push_back("feedFLstPrs");
	if (has(FEEDFLSTUSG)) ss.push_back("feedFLstUsg");
	if (has(FEEDFLSTUSR)) ss.push_back("feedFLstUsr");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlMsdcNavAdmin::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngMsdcNavAdminData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (feedFLstPrs.readXML(docctx, basexpath, true)) add(FEEDFLSTPRS);
		if (feedFLstUsg.readXML(docctx, basexpath, true)) add(FEEDFLSTUSG);
		if (feedFLstUsr.readXML(docctx, basexpath, true)) add(FEEDFLSTUSR);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		feedFLstPrs.clear();
		feedFLstUsg.clear();
		feedFLstUsr.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};

