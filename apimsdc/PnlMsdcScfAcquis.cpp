/**
  * \file PnlMsdcScfAcquis.cpp
  * API code for job PnlMsdcScfAcquis (implementation)
  * \author Alexander Wirthmueller
  * \date created: 12 Sep 2018
  * \date modified: 12 Sep 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "PnlMsdcScfAcquis.h"

/******************************************************************************
 class PnlMsdcScfAcquis::VecVDo
 ******************************************************************************/

uint PnlMsdcScfAcquis::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butmasterclick") return BUTMASTERCLICK;

	return(0);
};

string PnlMsdcScfAcquis::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTMASTERCLICK) return("ButMasterClick");

	return("");
};

/******************************************************************************
 class PnlMsdcScfAcquis::ContIac
 ******************************************************************************/

PnlMsdcScfAcquis::ContIac::ContIac(
			const uint numFPupVty
			, const string& TxfVlp
			, const string& TxfVrp
		) :
			Block()
		{
	this->numFPupVty = numFPupVty;
	this->TxfVlp = TxfVlp;
	this->TxfVrp = TxfVrp;

	mask = {NUMFPUPVTY, TXFVLP, TXFVRP};
};

bool PnlMsdcScfAcquis::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacMsdcScfAcquis");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacMsdcScfAcquis";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupVty", numFPupVty)) add(NUMFPUPVTY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfVlp", TxfVlp)) add(TXFVLP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfVrp", TxfVrp)) add(TXFVRP);
	};

	return basefound;
};

void PnlMsdcScfAcquis::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacMsdcScfAcquis";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacMsdcScfAcquis";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFPupVty", numFPupVty);
		writeStringAttr(wr, itemtag, "sref", "TxfVlp", TxfVlp);
		writeStringAttr(wr, itemtag, "sref", "TxfVrp", TxfVrp);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlMsdcScfAcquis::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFPupVty == comp->numFPupVty) insert(items, NUMFPUPVTY);
	if (TxfVlp == comp->TxfVlp) insert(items, TXFVLP);
	if (TxfVrp == comp->TxfVrp) insert(items, TXFVRP);

	return(items);
};

set<uint> PnlMsdcScfAcquis::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {, TXFVLP, TXFVRP};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlMsdcScfAcquis::ContInf
 ******************************************************************************/

PnlMsdcScfAcquis::ContInf::ContInf(
			const bool ButMasterOn
			, const string& TxtIsn
			, const string& TxtIps
			, const string& TxtIfl
			, const string& TxtIfn
			, const string& TxtVps
			, const string& TxtVfl
			, const string& TxtVfn
		) :
			Block()
		{
	this->ButMasterOn = ButMasterOn;
	this->TxtIsn = TxtIsn;
	this->TxtIps = TxtIps;
	this->TxtIfl = TxtIfl;
	this->TxtIfn = TxtIfn;
	this->TxtVps = TxtVps;
	this->TxtVfl = TxtVfl;
	this->TxtVfn = TxtVfn;

	mask = {BUTMASTERON, TXTISN, TXTIPS, TXTIFL, TXTIFN, TXTVPS, TXTVFL, TXTVFN};
};

bool PnlMsdcScfAcquis::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfMsdcScfAcquis");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfMsdcScfAcquis";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "ButMasterOn", ButMasterOn)) add(BUTMASTERON);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtIsn", TxtIsn)) add(TXTISN);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtIps", TxtIps)) add(TXTIPS);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtIfl", TxtIfl)) add(TXTIFL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtIfn", TxtIfn)) add(TXTIFN);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtVps", TxtVps)) add(TXTVPS);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtVfl", TxtVfl)) add(TXTVFL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtVfn", TxtVfn)) add(TXTVFN);
	};

	return basefound;
};

set<uint> PnlMsdcScfAcquis::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (ButMasterOn == comp->ButMasterOn) insert(items, BUTMASTERON);
	if (TxtIsn == comp->TxtIsn) insert(items, TXTISN);
	if (TxtIps == comp->TxtIps) insert(items, TXTIPS);
	if (TxtIfl == comp->TxtIfl) insert(items, TXTIFL);
	if (TxtIfn == comp->TxtIfn) insert(items, TXTIFN);
	if (TxtVps == comp->TxtVps) insert(items, TXTVPS);
	if (TxtVfl == comp->TxtVfl) insert(items, TXTVFL);
	if (TxtVfn == comp->TxtVfn) insert(items, TXTVFN);

	return(items);
};

set<uint> PnlMsdcScfAcquis::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {, TXTISN, TXTIPS, TXTIFL, TXTIFN, TXTVPS, TXTVFL, TXTVFN};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlMsdcScfAcquis::StatApp
 ******************************************************************************/

PnlMsdcScfAcquis::StatApp::StatApp(
			const uint ixMsdcVExpstate
		) :
			Block()
		{
	this->ixMsdcVExpstate = ixMsdcVExpstate;

	mask = {IXMSDCVEXPSTATE};
};

bool PnlMsdcScfAcquis::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxMsdcVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppMsdcScfAcquis");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppMsdcScfAcquis";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxMsdcVExpstate", srefIxMsdcVExpstate)) {
			ixMsdcVExpstate = VecMsdcVExpstate::getIx(srefIxMsdcVExpstate);
			add(IXMSDCVEXPSTATE);
		};
	};

	return basefound;
};

set<uint> PnlMsdcScfAcquis::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixMsdcVExpstate == comp->ixMsdcVExpstate) insert(items, IXMSDCVEXPSTATE);

	return(items);
};

set<uint> PnlMsdcScfAcquis::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXMSDCVEXPSTATE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlMsdcScfAcquis::Tag
 ******************************************************************************/

PnlMsdcScfAcquis::Tag::Tag(
			const string& Cpt
			, const string& HdgIwi
			, const string& CptIsn
			, const string& CptIps
			, const string& CptIfl
			, const string& CptIfn
			, const string& HdgVis
			, const string& CptVty
			, const string& CptVlp
			, const string& CptVrp
			, const string& CptVps
			, const string& CptVfl
			, const string& CptVfn
		) :
			Block()
		{
	this->Cpt = Cpt;
	this->HdgIwi = HdgIwi;
	this->CptIsn = CptIsn;
	this->CptIps = CptIps;
	this->CptIfl = CptIfl;
	this->CptIfn = CptIfn;
	this->HdgVis = HdgVis;
	this->CptVty = CptVty;
	this->CptVlp = CptVlp;
	this->CptVrp = CptVrp;
	this->CptVps = CptVps;
	this->CptVfl = CptVfl;
	this->CptVfn = CptVfn;

	mask = {CPT, HDGIWI, CPTISN, CPTIPS, CPTIFL, CPTIFN, HDGVIS, CPTVTY, CPTVLP, CPTVRP, CPTVPS, CPTVFL, CPTVFN};
};

bool PnlMsdcScfAcquis::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagMsdcScfAcquis");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemMsdcScfAcquis";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "HdgIwi", HdgIwi)) add(HDGIWI);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptIsn", CptIsn)) add(CPTISN);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptIps", CptIps)) add(CPTIPS);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptIfl", CptIfl)) add(CPTIFL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptIfn", CptIfn)) add(CPTIFN);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "HdgVis", HdgVis)) add(HDGVIS);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptVty", CptVty)) add(CPTVTY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptVlp", CptVlp)) add(CPTVLP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptVrp", CptVrp)) add(CPTVRP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptVps", CptVps)) add(CPTVPS);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptVfl", CptVfl)) add(CPTVFL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptVfn", CptVfn)) add(CPTVFN);
	};

	return basefound;
};

/******************************************************************************
 class PnlMsdcScfAcquis::DpchAppData
 ******************************************************************************/

PnlMsdcScfAcquis::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) :
			DpchAppMsdc(VecMsdcVDpch::DPCHAPPMSDCSCFACQUISDATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlMsdcScfAcquis::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlMsdcScfAcquis::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppMsdcScfAcquisData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/msdc");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlMsdcScfAcquis::DpchAppDo
 ******************************************************************************/

PnlMsdcScfAcquis::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppMsdc(VecMsdcVDpch::DPCHAPPMSDCSCFACQUISDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlMsdcScfAcquis::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlMsdcScfAcquis::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppMsdcScfAcquisDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/msdc");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlMsdcScfAcquis::DpchEngData
 ******************************************************************************/

PnlMsdcScfAcquis::DpchEngData::DpchEngData() :
			DpchEngMsdc(VecMsdcVDpch::DPCHENGMSDCSCFACQUISDATA)
		{
	feedFPupVty.tag = "FeedFPupVty";
};

string PnlMsdcScfAcquis::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFPUPVTY)) ss.push_back("feedFPupVty");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlMsdcScfAcquis::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngMsdcScfAcquisData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (feedFPupVty.readXML(docctx, basexpath, true)) add(FEEDFPUPVTY);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		continf = ContInf();
		feedFPupVty.clear();
		statapp = StatApp();
		tag = Tag();
	};
};

