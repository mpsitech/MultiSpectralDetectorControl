/**
  * \file PnlMsdcUsrDetail.cpp
  * API code for job PnlMsdcUsrDetail (implementation)
  * \author Alexander Wirthmueller
  * \date created: 29 Aug 2018
  * \date modified: 29 Aug 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "PnlMsdcUsrDetail.h"

/******************************************************************************
 class PnlMsdcUsrDetail::VecVDo
 ******************************************************************************/

uint PnlMsdcUsrDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	if (s == "butprsviewclick") return BUTPRSVIEWCLICK;
	if (s == "butusgviewclick") return BUTUSGVIEWCLICK;

	return(0);
};

string PnlMsdcUsrDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	if (ix == BUTPRSVIEWCLICK) return("ButPrsViewClick");
	if (ix == BUTUSGVIEWCLICK) return("ButUsgViewClick");

	return("");
};

/******************************************************************************
 class PnlMsdcUsrDetail::ContIac
 ******************************************************************************/

PnlMsdcUsrDetail::ContIac::ContIac(
			const uint numFPupSte
			, const uint numFPupLcl
			, const uint numFPupUlv
			, const string& TxfPwd
			, const string& TxfFky
			, const string& TxfCmt
		) :
			Block()
		{
	this->numFPupSte = numFPupSte;
	this->numFPupLcl = numFPupLcl;
	this->numFPupUlv = numFPupUlv;
	this->TxfPwd = TxfPwd;
	this->TxfFky = TxfFky;
	this->TxfCmt = TxfCmt;

	mask = {NUMFPUPSTE, NUMFPUPLCL, NUMFPUPULV, TXFPWD, TXFFKY, TXFCMT};
};

bool PnlMsdcUsrDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacMsdcUsrDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacMsdcUsrDetail";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupSte", numFPupSte)) add(NUMFPUPSTE);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupLcl", numFPupLcl)) add(NUMFPUPLCL);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupUlv", numFPupUlv)) add(NUMFPUPULV);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfPwd", TxfPwd)) add(TXFPWD);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfFky", TxfFky)) add(TXFFKY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfCmt", TxfCmt)) add(TXFCMT);
	};

	return basefound;
};

void PnlMsdcUsrDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacMsdcUsrDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacMsdcUsrDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFPupSte", numFPupSte);
		writeUintAttr(wr, itemtag, "sref", "numFPupLcl", numFPupLcl);
		writeUintAttr(wr, itemtag, "sref", "numFPupUlv", numFPupUlv);
		writeStringAttr(wr, itemtag, "sref", "TxfPwd", TxfPwd);
		writeStringAttr(wr, itemtag, "sref", "TxfFky", TxfFky);
		writeStringAttr(wr, itemtag, "sref", "TxfCmt", TxfCmt);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlMsdcUsrDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFPupSte == comp->numFPupSte) insert(items, NUMFPUPSTE);
	if (numFPupLcl == comp->numFPupLcl) insert(items, NUMFPUPLCL);
	if (numFPupUlv == comp->numFPupUlv) insert(items, NUMFPUPULV);
	if (TxfPwd == comp->TxfPwd) insert(items, TXFPWD);
	if (TxfFky == comp->TxfFky) insert(items, TXFFKY);
	if (TxfCmt == comp->TxfCmt) insert(items, TXFCMT);

	return(items);
};

set<uint> PnlMsdcUsrDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {, NUMFPUPLCL, NUMFPUPULV, TXFPWD, TXFFKY, TXFCMT};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlMsdcUsrDetail::ContInf
 ******************************************************************************/

PnlMsdcUsrDetail::ContInf::ContInf(
			const string& TxtPrs
			, const string& TxtSrf
			, const string& TxtUsg
		) :
			Block()
		{
	this->TxtPrs = TxtPrs;
	this->TxtSrf = TxtSrf;
	this->TxtUsg = TxtUsg;

	mask = {TXTPRS, TXTSRF, TXTUSG};
};

bool PnlMsdcUsrDetail::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfMsdcUsrDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfMsdcUsrDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtPrs", TxtPrs)) add(TXTPRS);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtSrf", TxtSrf)) add(TXTSRF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtUsg", TxtUsg)) add(TXTUSG);
	};

	return basefound;
};

set<uint> PnlMsdcUsrDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtPrs == comp->TxtPrs) insert(items, TXTPRS);
	if (TxtSrf == comp->TxtSrf) insert(items, TXTSRF);
	if (TxtUsg == comp->TxtUsg) insert(items, TXTUSG);

	return(items);
};

set<uint> PnlMsdcUsrDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {, TXTSRF, TXTUSG};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlMsdcUsrDetail::StatApp
 ******************************************************************************/

PnlMsdcUsrDetail::StatApp::StatApp(
			const uint ixMsdcVExpstate
		) :
			Block()
		{
	this->ixMsdcVExpstate = ixMsdcVExpstate;

	mask = {IXMSDCVEXPSTATE};
};

bool PnlMsdcUsrDetail::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxMsdcVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppMsdcUsrDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppMsdcUsrDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxMsdcVExpstate", srefIxMsdcVExpstate)) {
			ixMsdcVExpstate = VecMsdcVExpstate::getIx(srefIxMsdcVExpstate);
			add(IXMSDCVEXPSTATE);
		};
	};

	return basefound;
};

set<uint> PnlMsdcUsrDetail::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixMsdcVExpstate == comp->ixMsdcVExpstate) insert(items, IXMSDCVEXPSTATE);

	return(items);
};

set<uint> PnlMsdcUsrDetail::StatApp::diff(
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
 class PnlMsdcUsrDetail::StatShr
 ******************************************************************************/

PnlMsdcUsrDetail::StatShr::StatShr(
			const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool TxtPrsActive
			, const bool ButPrsViewAvail
			, const bool ButPrsViewActive
			, const bool TxtSrfActive
			, const bool TxtUsgActive
			, const bool ButUsgViewAvail
			, const bool ButUsgViewActive
			, const bool PupSteActive
			, const bool PupLclActive
			, const bool PupUlvActive
			, const bool TxfPwdActive
			, const bool TxfFkyActive
			, const bool TxfCmtActive
		) :
			Block()
		{
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;
	this->TxtPrsActive = TxtPrsActive;
	this->ButPrsViewAvail = ButPrsViewAvail;
	this->ButPrsViewActive = ButPrsViewActive;
	this->TxtSrfActive = TxtSrfActive;
	this->TxtUsgActive = TxtUsgActive;
	this->ButUsgViewAvail = ButUsgViewAvail;
	this->ButUsgViewActive = ButUsgViewActive;
	this->PupSteActive = PupSteActive;
	this->PupLclActive = PupLclActive;
	this->PupUlvActive = PupUlvActive;
	this->TxfPwdActive = TxfPwdActive;
	this->TxfFkyActive = TxfFkyActive;
	this->TxfCmtActive = TxfCmtActive;

	mask = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXTPRSACTIVE, BUTPRSVIEWAVAIL, BUTPRSVIEWACTIVE, TXTSRFACTIVE, TXTUSGACTIVE, BUTUSGVIEWAVAIL, BUTUSGVIEWACTIVE, PUPSTEACTIVE, PUPLCLACTIVE, PUPULVACTIVE, TXFPWDACTIVE, TXFFKYACTIVE, TXFCMTACTIVE};
};

bool PnlMsdcUsrDetail::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrMsdcUsrDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrMsdcUsrDetail";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveAvail", ButSaveAvail)) add(BUTSAVEAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveActive", ButSaveActive)) add(BUTSAVEACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtPrsActive", TxtPrsActive)) add(TXTPRSACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButPrsViewAvail", ButPrsViewAvail)) add(BUTPRSVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButPrsViewActive", ButPrsViewActive)) add(BUTPRSVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtSrfActive", TxtSrfActive)) add(TXTSRFACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtUsgActive", TxtUsgActive)) add(TXTUSGACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButUsgViewAvail", ButUsgViewAvail)) add(BUTUSGVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButUsgViewActive", ButUsgViewActive)) add(BUTUSGVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "PupSteActive", PupSteActive)) add(PUPSTEACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "PupLclActive", PupLclActive)) add(PUPLCLACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "PupUlvActive", PupUlvActive)) add(PUPULVACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfPwdActive", TxfPwdActive)) add(TXFPWDACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfFkyActive", TxfFkyActive)) add(TXFFKYACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfCmtActive", TxfCmtActive)) add(TXFCMTACTIVE);
	};

	return basefound;
};

set<uint> PnlMsdcUsrDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (TxtPrsActive == comp->TxtPrsActive) insert(items, TXTPRSACTIVE);
	if (ButPrsViewAvail == comp->ButPrsViewAvail) insert(items, BUTPRSVIEWAVAIL);
	if (ButPrsViewActive == comp->ButPrsViewActive) insert(items, BUTPRSVIEWACTIVE);
	if (TxtSrfActive == comp->TxtSrfActive) insert(items, TXTSRFACTIVE);
	if (TxtUsgActive == comp->TxtUsgActive) insert(items, TXTUSGACTIVE);
	if (ButUsgViewAvail == comp->ButUsgViewAvail) insert(items, BUTUSGVIEWAVAIL);
	if (ButUsgViewActive == comp->ButUsgViewActive) insert(items, BUTUSGVIEWACTIVE);
	if (PupSteActive == comp->PupSteActive) insert(items, PUPSTEACTIVE);
	if (PupLclActive == comp->PupLclActive) insert(items, PUPLCLACTIVE);
	if (PupUlvActive == comp->PupUlvActive) insert(items, PUPULVACTIVE);
	if (TxfPwdActive == comp->TxfPwdActive) insert(items, TXFPWDACTIVE);
	if (TxfFkyActive == comp->TxfFkyActive) insert(items, TXFFKYACTIVE);
	if (TxfCmtActive == comp->TxfCmtActive) insert(items, TXFCMTACTIVE);

	return(items);
};

set<uint> PnlMsdcUsrDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXTPRSACTIVE, BUTPRSVIEWAVAIL, BUTPRSVIEWACTIVE, TXTSRFACTIVE, TXTUSGACTIVE, BUTUSGVIEWAVAIL, BUTUSGVIEWACTIVE, PUPSTEACTIVE, PUPLCLACTIVE, PUPULVACTIVE, TXFPWDACTIVE, TXFFKYACTIVE, TXFCMTACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlMsdcUsrDetail::Tag
 ******************************************************************************/

PnlMsdcUsrDetail::Tag::Tag(
			const string& Cpt
			, const string& CptPrs
			, const string& CptSrf
			, const string& CptUsg
			, const string& CptSte
			, const string& CptLcl
			, const string& CptUlv
			, const string& CptPwd
			, const string& CptFky
			, const string& CptCmt
		) :
			Block()
		{
	this->Cpt = Cpt;
	this->CptPrs = CptPrs;
	this->CptSrf = CptSrf;
	this->CptUsg = CptUsg;
	this->CptSte = CptSte;
	this->CptLcl = CptLcl;
	this->CptUlv = CptUlv;
	this->CptPwd = CptPwd;
	this->CptFky = CptFky;
	this->CptCmt = CptCmt;

	mask = {CPT, CPTPRS, CPTSRF, CPTUSG, CPTSTE, CPTLCL, CPTULV, CPTPWD, CPTFKY, CPTCMT};
};

bool PnlMsdcUsrDetail::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagMsdcUsrDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemMsdcUsrDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptPrs", CptPrs)) add(CPTPRS);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSrf", CptSrf)) add(CPTSRF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptUsg", CptUsg)) add(CPTUSG);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSte", CptSte)) add(CPTSTE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptLcl", CptLcl)) add(CPTLCL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptUlv", CptUlv)) add(CPTULV);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptPwd", CptPwd)) add(CPTPWD);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptFky", CptFky)) add(CPTFKY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptCmt", CptCmt)) add(CPTCMT);
	};

	return basefound;
};

/******************************************************************************
 class PnlMsdcUsrDetail::DpchAppData
 ******************************************************************************/

PnlMsdcUsrDetail::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) :
			DpchAppMsdc(VecMsdcVDpch::DPCHAPPMSDCUSRDETAILDATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlMsdcUsrDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlMsdcUsrDetail::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppMsdcUsrDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/msdc");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlMsdcUsrDetail::DpchAppDo
 ******************************************************************************/

PnlMsdcUsrDetail::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppMsdc(VecMsdcVDpch::DPCHAPPMSDCUSRDETAILDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlMsdcUsrDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlMsdcUsrDetail::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppMsdcUsrDetailDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/msdc");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlMsdcUsrDetail::DpchEngData
 ******************************************************************************/

PnlMsdcUsrDetail::DpchEngData::DpchEngData() :
			DpchEngMsdc(VecMsdcVDpch::DPCHENGMSDCUSRDETAILDATA)
		{
	feedFPupLcl.tag = "FeedFPupLcl";
	feedFPupSte.tag = "FeedFPupSte";
	feedFPupUlv.tag = "FeedFPupUlv";
};

string PnlMsdcUsrDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFPUPLCL)) ss.push_back("feedFPupLcl");
	if (has(FEEDFPUPSTE)) ss.push_back("feedFPupSte");
	if (has(FEEDFPUPULV)) ss.push_back("feedFPupUlv");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlMsdcUsrDetail::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngMsdcUsrDetailData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (feedFPupLcl.readXML(docctx, basexpath, true)) add(FEEDFPUPLCL);
		if (feedFPupSte.readXML(docctx, basexpath, true)) add(FEEDFPUPSTE);
		if (feedFPupUlv.readXML(docctx, basexpath, true)) add(FEEDFPUPULV);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		continf = ContInf();
		feedFPupLcl.clear();
		feedFPupSte.clear();
		feedFPupUlv.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};

