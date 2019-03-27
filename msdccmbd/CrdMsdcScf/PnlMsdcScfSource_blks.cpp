/**
  * \file PnlMsdcScfSource_blks.cpp
  * job handler for job PnlMsdcScfSource (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 18 Dec 2018
  * \date modified: 18 Dec 2018
  */

/******************************************************************************
 class PnlMsdcScfSource::VecVDo
 ******************************************************************************/

uint PnlMsdcScfSource::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butmasterclick") return BUTMASTERCLICK;

	return(0);
};

string PnlMsdcScfSource::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTMASTERCLICK) return("ButMasterClick");

	return("");
};

/******************************************************************************
 class PnlMsdcScfSource::ContIac
 ******************************************************************************/

PnlMsdcScfSource::ContIac::ContIac(
			const string& TxfFpp
			, const double SldFxa
			, const double SldFa0
			, const double SldFb0
			, const int UpdFam
			, const double SldFsa
			, const double SldFt0
			, const double SldFp0
			, const double SldTrp
		) :
			Block()
		{
	this->TxfFpp = TxfFpp;
	this->SldFxa = SldFxa;
	this->SldFa0 = SldFa0;
	this->SldFb0 = SldFb0;
	this->UpdFam = UpdFam;
	this->SldFsa = SldFsa;
	this->SldFt0 = SldFt0;
	this->SldFp0 = SldFp0;
	this->SldTrp = SldTrp;

	mask = {TXFFPP, SLDFXA, SLDFA0, SLDFB0, UPDFAM, SLDFSA, SLDFT0, SLDFP0, SLDTRP};
};

bool PnlMsdcScfSource::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacMsdcScfSource");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacMsdcScfSource";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfFpp", TxfFpp)) add(TXFFPP);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "SldFxa", SldFxa)) add(SLDFXA);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "SldFa0", SldFa0)) add(SLDFA0);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "SldFb0", SldFb0)) add(SLDFB0);
		if (extractIntAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "UpdFam", UpdFam)) add(UPDFAM);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "SldFsa", SldFsa)) add(SLDFSA);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "SldFt0", SldFt0)) add(SLDFT0);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "SldFp0", SldFp0)) add(SLDFP0);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "SldTrp", SldTrp)) add(SLDTRP);
	};

	return basefound;
};

void PnlMsdcScfSource::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacMsdcScfSource";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacMsdcScfSource";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxfFpp", TxfFpp);
		writeDoubleAttr(wr, itemtag, "sref", "SldFxa", SldFxa);
		writeDoubleAttr(wr, itemtag, "sref", "SldFa0", SldFa0);
		writeDoubleAttr(wr, itemtag, "sref", "SldFb0", SldFb0);
		writeIntAttr(wr, itemtag, "sref", "UpdFam", UpdFam);
		writeDoubleAttr(wr, itemtag, "sref", "SldFsa", SldFsa);
		writeDoubleAttr(wr, itemtag, "sref", "SldFt0", SldFt0);
		writeDoubleAttr(wr, itemtag, "sref", "SldFp0", SldFp0);
		writeDoubleAttr(wr, itemtag, "sref", "SldTrp", SldTrp);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlMsdcScfSource::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (TxfFpp == comp->TxfFpp) insert(items, TXFFPP);
	if (compareDouble(SldFxa, comp->SldFxa) < 1.0e-4) insert(items, SLDFXA);
	if (compareDouble(SldFa0, comp->SldFa0) < 1.0e-4) insert(items, SLDFA0);
	if (compareDouble(SldFb0, comp->SldFb0) < 1.0e-4) insert(items, SLDFB0);
	if (UpdFam == comp->UpdFam) insert(items, UPDFAM);
	if (compareDouble(SldFsa, comp->SldFsa) < 1.0e-4) insert(items, SLDFSA);
	if (compareDouble(SldFt0, comp->SldFt0) < 1.0e-4) insert(items, SLDFT0);
	if (compareDouble(SldFp0, comp->SldFp0) < 1.0e-4) insert(items, SLDFP0);
	if (compareDouble(SldTrp, comp->SldTrp) < 1.0e-4) insert(items, SLDTRP);

	return(items);
};

set<uint> PnlMsdcScfSource::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFFPP, SLDFXA, SLDFA0, SLDFB0, UPDFAM, SLDFSA, SLDFT0, SLDFP0, SLDTRP};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlMsdcScfSource::ContInf
 ******************************************************************************/

PnlMsdcScfSource::ContInf::ContInf(
			const bool ButMasterOn
		) :
			Block()
		{
	this->ButMasterOn = ButMasterOn;

	mask = {BUTMASTERON};
};

void PnlMsdcScfSource::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfMsdcScfSource";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfMsdcScfSource";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButMasterOn", ButMasterOn);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlMsdcScfSource::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (ButMasterOn == comp->ButMasterOn) insert(items, BUTMASTERON);

	return(items);
};

set<uint> PnlMsdcScfSource::ContInf::diff(
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
 class PnlMsdcScfSource::StatApp
 ******************************************************************************/

void PnlMsdcScfSource::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixMsdcVExpstate
		) {
	if (difftag.length() == 0) difftag = "StatAppMsdcScfSource";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppMsdcScfSource";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxMsdcVExpstate", VecMsdcVExpstate::getSref(ixMsdcVExpstate));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlMsdcScfSource::StatShr
 ******************************************************************************/

PnlMsdcScfSource::StatShr::StatShr(
			const double SldFxaMin
			, const double SldFxaMax
			, const double SldFa0Min
			, const double SldFa0Max
			, const double SldFb0Min
			, const double SldFb0Max
			, const int UpdFamMin
			, const int UpdFamMax
			, const double SldFsaMin
			, const double SldFsaMax
			, const double SldFt0Min
			, const double SldFt0Max
			, const double SldFp0Min
			, const double SldFp0Max
			, const double SldTrpMin
			, const double SldTrpMax
			, const double SldTrpRast
		) :
			Block()
		{
	this->SldFxaMin = SldFxaMin;
	this->SldFxaMax = SldFxaMax;
	this->SldFa0Min = SldFa0Min;
	this->SldFa0Max = SldFa0Max;
	this->SldFb0Min = SldFb0Min;
	this->SldFb0Max = SldFb0Max;
	this->UpdFamMin = UpdFamMin;
	this->UpdFamMax = UpdFamMax;
	this->SldFsaMin = SldFsaMin;
	this->SldFsaMax = SldFsaMax;
	this->SldFt0Min = SldFt0Min;
	this->SldFt0Max = SldFt0Max;
	this->SldFp0Min = SldFp0Min;
	this->SldFp0Max = SldFp0Max;
	this->SldTrpMin = SldTrpMin;
	this->SldTrpMax = SldTrpMax;
	this->SldTrpRast = SldTrpRast;

	mask = {SLDFXAMIN, SLDFXAMAX, SLDFA0MIN, SLDFA0MAX, SLDFB0MIN, SLDFB0MAX, UPDFAMMIN, UPDFAMMAX, SLDFSAMIN, SLDFSAMAX, SLDFT0MIN, SLDFT0MAX, SLDFP0MIN, SLDFP0MAX, SLDTRPMIN, SLDTRPMAX, SLDTRPRAST};
};

void PnlMsdcScfSource::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrMsdcScfSource";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrMsdcScfSource";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeDoubleAttr(wr, itemtag, "sref", "SldFxaMin", SldFxaMin);
		writeDoubleAttr(wr, itemtag, "sref", "SldFxaMax", SldFxaMax);
		writeDoubleAttr(wr, itemtag, "sref", "SldFa0Min", SldFa0Min);
		writeDoubleAttr(wr, itemtag, "sref", "SldFa0Max", SldFa0Max);
		writeDoubleAttr(wr, itemtag, "sref", "SldFb0Min", SldFb0Min);
		writeDoubleAttr(wr, itemtag, "sref", "SldFb0Max", SldFb0Max);
		writeIntAttr(wr, itemtag, "sref", "UpdFamMin", UpdFamMin);
		writeIntAttr(wr, itemtag, "sref", "UpdFamMax", UpdFamMax);
		writeDoubleAttr(wr, itemtag, "sref", "SldFsaMin", SldFsaMin);
		writeDoubleAttr(wr, itemtag, "sref", "SldFsaMax", SldFsaMax);
		writeDoubleAttr(wr, itemtag, "sref", "SldFt0Min", SldFt0Min);
		writeDoubleAttr(wr, itemtag, "sref", "SldFt0Max", SldFt0Max);
		writeDoubleAttr(wr, itemtag, "sref", "SldFp0Min", SldFp0Min);
		writeDoubleAttr(wr, itemtag, "sref", "SldFp0Max", SldFp0Max);
		writeDoubleAttr(wr, itemtag, "sref", "SldTrpMin", SldTrpMin);
		writeDoubleAttr(wr, itemtag, "sref", "SldTrpMax", SldTrpMax);
		writeDoubleAttr(wr, itemtag, "sref", "SldTrpRast", SldTrpRast);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlMsdcScfSource::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (compareDouble(SldFxaMin, comp->SldFxaMin) < 1.0e-4) insert(items, SLDFXAMIN);
	if (compareDouble(SldFxaMax, comp->SldFxaMax) < 1.0e-4) insert(items, SLDFXAMAX);
	if (compareDouble(SldFa0Min, comp->SldFa0Min) < 1.0e-4) insert(items, SLDFA0MIN);
	if (compareDouble(SldFa0Max, comp->SldFa0Max) < 1.0e-4) insert(items, SLDFA0MAX);
	if (compareDouble(SldFb0Min, comp->SldFb0Min) < 1.0e-4) insert(items, SLDFB0MIN);
	if (compareDouble(SldFb0Max, comp->SldFb0Max) < 1.0e-4) insert(items, SLDFB0MAX);
	if (UpdFamMin == comp->UpdFamMin) insert(items, UPDFAMMIN);
	if (UpdFamMax == comp->UpdFamMax) insert(items, UPDFAMMAX);
	if (compareDouble(SldFsaMin, comp->SldFsaMin) < 1.0e-4) insert(items, SLDFSAMIN);
	if (compareDouble(SldFsaMax, comp->SldFsaMax) < 1.0e-4) insert(items, SLDFSAMAX);
	if (compareDouble(SldFt0Min, comp->SldFt0Min) < 1.0e-4) insert(items, SLDFT0MIN);
	if (compareDouble(SldFt0Max, comp->SldFt0Max) < 1.0e-4) insert(items, SLDFT0MAX);
	if (compareDouble(SldFp0Min, comp->SldFp0Min) < 1.0e-4) insert(items, SLDFP0MIN);
	if (compareDouble(SldFp0Max, comp->SldFp0Max) < 1.0e-4) insert(items, SLDFP0MAX);
	if (compareDouble(SldTrpMin, comp->SldTrpMin) < 1.0e-4) insert(items, SLDTRPMIN);
	if (compareDouble(SldTrpMax, comp->SldTrpMax) < 1.0e-4) insert(items, SLDTRPMAX);
	if (compareDouble(SldTrpRast, comp->SldTrpRast) < 1.0e-4) insert(items, SLDTRPRAST);

	return(items);
};

set<uint> PnlMsdcScfSource::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {SLDFXAMIN, SLDFXAMAX, SLDFA0MIN, SLDFA0MAX, SLDFB0MIN, SLDFB0MAX, UPDFAMMIN, UPDFAMMAX, SLDFSAMIN, SLDFSAMAX, SLDFT0MIN, SLDFT0MAX, SLDFP0MIN, SLDFP0MAX, SLDTRPMIN, SLDTRPMAX, SLDTRPRAST};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlMsdcScfSource::Tag
 ******************************************************************************/

void PnlMsdcScfSource::Tag::writeXML(
			const uint ixMsdcVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagMsdcScfSource";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemMsdcScfSource";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixMsdcVLocale == VecMsdcVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Sources");
			writeStringAttr(wr, itemtag, "sref", "HdgFpg", "FPGA board");
			writeStringAttr(wr, itemtag, "sref", "CptFpp", "character device path");
			writeStringAttr(wr, itemtag, "sref", "CptFxa", "accelerometer a [g/LSB]");
			writeStringAttr(wr, itemtag, "sref", "CptFa0", "accelerometer \\u03b10 [\\u00b0]");
			writeStringAttr(wr, itemtag, "sref", "CptFb0", "accelerometer \\u03b20 [\\u00b0]");
			writeStringAttr(wr, itemtag, "sref", "CptFam", "alignment laser max. DAC value");
			writeStringAttr(wr, itemtag, "sref", "CptFsa", "servos a [ms/\\u00b0]");
			writeStringAttr(wr, itemtag, "sref", "CptFt0", "servo \\u03d10 [\\u00b0]");
			writeStringAttr(wr, itemtag, "sref", "CptFp0", "servo \\u03c60 [\\u00b0]");
			writeStringAttr(wr, itemtag, "sref", "CptTrp", "trigger period [s]");
		} else if (ixMsdcVLocale == VecMsdcVLocale::DECH) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Quellen");
			writeStringAttr(wr, itemtag, "sref", "HdgFpg", "FPGA-Board");
			writeStringAttr(wr, itemtag, "sref", "CptFpp", "Pfad zu Character Device");
			writeStringAttr(wr, itemtag, "sref", "CptFxa", "Beschleunigungssensor a [g/LSB]");
			writeStringAttr(wr, itemtag, "sref", "CptFa0", "Beschleunigungssensor \\u03b10 [\\u00b0]");
			writeStringAttr(wr, itemtag, "sref", "CptFb0", "Beschleunigungssensor \\u03b20 [\\u00b0]");
			writeStringAttr(wr, itemtag, "sref", "CptFam", "Ausrichtungslaser max. DAC Wert");
			writeStringAttr(wr, itemtag, "sref", "CptFsa", "Servos a [ms/\\u00b0]");
			writeStringAttr(wr, itemtag, "sref", "CptFt0", "Servo \\u03d10 [\\u00b0]");
			writeStringAttr(wr, itemtag, "sref", "CptFp0", "Servo \\u03c60 [\\u00b0]");
			writeStringAttr(wr, itemtag, "sref", "CptTrp", "Trigger Periode [s]");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlMsdcScfSource::DpchAppData
 ******************************************************************************/

PnlMsdcScfSource::DpchAppData::DpchAppData() :
			DpchAppMsdc(VecMsdcVDpch::DPCHAPPMSDCSCFSOURCEDATA)
		{
};

string PnlMsdcScfSource::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlMsdcScfSource::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppMsdcScfSourceData");
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
 class PnlMsdcScfSource::DpchAppDo
 ******************************************************************************/

PnlMsdcScfSource::DpchAppDo::DpchAppDo() :
			DpchAppMsdc(VecMsdcVDpch::DPCHAPPMSDCSCFSOURCEDO)
		{
	ixVDo = 0;
};

string PnlMsdcScfSource::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlMsdcScfSource::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppMsdcScfSourceDo");
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
 class PnlMsdcScfSource::DpchEngData
 ******************************************************************************/

PnlMsdcScfSource::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngMsdc(VecMsdcVDpch::DPCHENGMSDCSCFSOURCEDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlMsdcScfSource::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlMsdcScfSource::DpchEngData::merge(
			DpchEngMsdc* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlMsdcScfSource::DpchEngData::writeXML(
			const uint ixMsdcVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngMsdcScfSourceData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/msdc");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixMsdcVLocale, wr);
	xmlTextWriterEndElement(wr);
};

