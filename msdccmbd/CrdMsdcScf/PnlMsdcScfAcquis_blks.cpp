/**
  * \file PnlMsdcScfAcquis_blks.cpp
  * job handler for job PnlMsdcScfAcquis (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 29 Aug 2018
  * \date modified: 29 Aug 2018
  */

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

	diffitems = {NUMFPUPVTY, TXFVLP, TXFVRP};
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

void PnlMsdcScfAcquis::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfMsdcScfAcquis";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfMsdcScfAcquis";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButMasterOn", ButMasterOn);
		writeStringAttr(wr, itemtag, "sref", "TxtIsn", TxtIsn);
		writeStringAttr(wr, itemtag, "sref", "TxtIps", TxtIps);
		writeStringAttr(wr, itemtag, "sref", "TxtIfl", TxtIfl);
		writeStringAttr(wr, itemtag, "sref", "TxtIfn", TxtIfn);
		writeStringAttr(wr, itemtag, "sref", "TxtVps", TxtVps);
		writeStringAttr(wr, itemtag, "sref", "TxtVfl", TxtVfl);
		writeStringAttr(wr, itemtag, "sref", "TxtVfn", TxtVfn);
	xmlTextWriterEndElement(wr);
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

	diffitems = {BUTMASTERON, TXTISN, TXTIPS, TXTIFL, TXTIFN, TXTVPS, TXTVFL, TXTVFN};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlMsdcScfAcquis::StatApp
 ******************************************************************************/

void PnlMsdcScfAcquis::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixMsdcVExpstate
		) {
	if (difftag.length() == 0) difftag = "StatAppMsdcScfAcquis";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppMsdcScfAcquis";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxMsdcVExpstate", VecMsdcVExpstate::getSref(ixMsdcVExpstate));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlMsdcScfAcquis::Tag
 ******************************************************************************/

void PnlMsdcScfAcquis::Tag::writeXML(
			const uint ixMsdcVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagMsdcScfAcquis";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemMsdcScfAcquis";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixMsdcVLocale == VecMsdcVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Acquisition features");
			writeStringAttr(wr, itemtag, "sref", "HdgIwi", "LWIR camera");
			writeStringAttr(wr, itemtag, "sref", "CptIsn", "serial number");
			writeStringAttr(wr, itemtag, "sref", "CptIps", "pixel size [\\u03bcm]");
			writeStringAttr(wr, itemtag, "sref", "CptIfl", "focal length [mm]");
			writeStringAttr(wr, itemtag, "sref", "CptIfn", "f-number");
			writeStringAttr(wr, itemtag, "sref", "HdgVis", "VIS cameras");
			writeStringAttr(wr, itemtag, "sref", "CptVty", "type");
			writeStringAttr(wr, itemtag, "sref", "CptVlp", "VIS-L path");
			writeStringAttr(wr, itemtag, "sref", "CptVrp", "VIS-R path");
			writeStringAttr(wr, itemtag, "sref", "CptVps", "pixel size [\\u03bcm]");
			writeStringAttr(wr, itemtag, "sref", "CptVfl", "focal length [mm]");
			writeStringAttr(wr, itemtag, "sref", "CptVfn", "f-number");
		} else if (ixMsdcVLocale == VecMsdcVLocale::DECH) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Aufzeichnungs-Features");
			writeStringAttr(wr, itemtag, "sref", "HdgIwi", "LWIR-Kamera");
			writeStringAttr(wr, itemtag, "sref", "CptIsn", "Seriennummer");
			writeStringAttr(wr, itemtag, "sref", "CptIps", "Pixelgr\\u00f6sse [\\u03bcm]");
			writeStringAttr(wr, itemtag, "sref", "CptIfl", "Brennweite [mm]");
			writeStringAttr(wr, itemtag, "sref", "CptIfn", "Blendenzahl");
			writeStringAttr(wr, itemtag, "sref", "HdgVis", "VIS Kameras");
			writeStringAttr(wr, itemtag, "sref", "CptVty", "Typ");
			writeStringAttr(wr, itemtag, "sref", "CptVlp", "VIS-L Pfad");
			writeStringAttr(wr, itemtag, "sref", "CptVrp", "VIS-R Pfad");
			writeStringAttr(wr, itemtag, "sref", "CptVps", "Pixelgr\\u00f6sse [\\u03bcm]");
			writeStringAttr(wr, itemtag, "sref", "CptVfl", "Brennweite [mm]");
			writeStringAttr(wr, itemtag, "sref", "CptVfn", "Blendenzahl");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlMsdcScfAcquis::DpchAppData
 ******************************************************************************/

PnlMsdcScfAcquis::DpchAppData::DpchAppData() :
			DpchAppMsdc(VecMsdcVDpch::DPCHAPPMSDCSCFACQUISDATA)
		{
};

string PnlMsdcScfAcquis::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlMsdcScfAcquis::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppMsdcScfAcquisData");
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
 class PnlMsdcScfAcquis::DpchAppDo
 ******************************************************************************/

PnlMsdcScfAcquis::DpchAppDo::DpchAppDo() :
			DpchAppMsdc(VecMsdcVDpch::DPCHAPPMSDCSCFACQUISDO)
		{
	ixVDo = 0;
};

string PnlMsdcScfAcquis::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlMsdcScfAcquis::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppMsdcScfAcquisDo");
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
 class PnlMsdcScfAcquis::DpchEngData
 ******************************************************************************/

PnlMsdcScfAcquis::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, Feed* feedFPupVty
			, const set<uint>& mask
		) :
			DpchEngMsdc(VecMsdcVDpch::DPCHENGMSDCSCFACQUISDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, FEEDFPUPVTY, STATAPP, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFPUPVTY) && feedFPupVty) this->feedFPupVty = *feedFPupVty;
};

string PnlMsdcScfAcquis::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFPUPVTY)) ss.push_back("feedFPupVty");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlMsdcScfAcquis::DpchEngData::merge(
			DpchEngMsdc* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFPUPVTY)) {feedFPupVty = src->feedFPupVty; add(FEEDFPUPVTY);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(TAG)) add(TAG);
};

void PnlMsdcScfAcquis::DpchEngData::writeXML(
			const uint ixMsdcVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngMsdcScfAcquisData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/msdc");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFPUPVTY)) feedFPupVty.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixMsdcVLocale, wr);
	xmlTextWriterEndElement(wr);
};

