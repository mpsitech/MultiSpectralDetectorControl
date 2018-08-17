/**
  * \file JobMsdcSrcMsdd_blks.cpp
  * job handler for job JobMsdcSrcMsdd (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 15 Aug 2018
  * \date modified: 15 Aug 2018
  */

/******************************************************************************
 class JobMsdcSrcMsdd::VecVSge
 ******************************************************************************/

uint JobMsdcSrcMsdd::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "nc") return NC;
	if (s == "ready") return READY;

	return(0);
};

string JobMsdcSrcMsdd::VecVSge::getSref(
			const uint ix
		) {
	if (ix == NC) return("nc");
	if (ix == READY) return("ready");

	return("");
};

void JobMsdcSrcMsdd::VecVSge::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=2;i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
};

/******************************************************************************
 class JobMsdcSrcMsdd::Stg
 ******************************************************************************/

JobMsdcSrcMsdd::Stg::Stg(
			const string& path
			, const float adxlA
			, const float adxlAlpha0
			, const float adxlBeta0
			, const utinyint alignMax
			, const float servoA
			, const float servoTheta0
			, const float servoPhi0
		) : Block() {
	this->path = path;
	this->adxlA = adxlA;
	this->adxlAlpha0 = adxlAlpha0;
	this->adxlBeta0 = adxlBeta0;
	this->alignMax = alignMax;
	this->servoA = servoA;
	this->servoTheta0 = servoTheta0;
	this->servoPhi0 = servoPhi0;
	mask = {PATH, ADXLA, ADXLALPHA0, ADXLBETA0, ALIGNMAX, SERVOA, SERVOTHETA0, SERVOPHI0};
};

bool JobMsdcSrcMsdd::Stg::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgJobMsdcSrcMsdd");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemJobMsdcSrcMsdd";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "path", path)) add(PATH);
		if (extractFloatAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "adxlA", adxlA)) add(ADXLA);
		if (extractFloatAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "adxlAlpha0", adxlAlpha0)) add(ADXLALPHA0);
		if (extractFloatAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "adxlBeta0", adxlBeta0)) add(ADXLBETA0);
		if (extractUtinyintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "alignMax", alignMax)) add(ALIGNMAX);
		if (extractFloatAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "servoA", servoA)) add(SERVOA);
		if (extractFloatAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "servoTheta0", servoTheta0)) add(SERVOTHETA0);
		if (extractFloatAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "servoPhi0", servoPhi0)) add(SERVOPHI0);
	};

	return basefound;
};

void JobMsdcSrcMsdd::Stg::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgJobMsdcSrcMsdd";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemJobMsdcSrcMsdd";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "path", path);
		writeFloatAttr(wr, itemtag, "sref", "adxlA", adxlA);
		writeFloatAttr(wr, itemtag, "sref", "adxlAlpha0", adxlAlpha0);
		writeFloatAttr(wr, itemtag, "sref", "adxlBeta0", adxlBeta0);
		writeUtinyintAttr(wr, itemtag, "sref", "alignMax", alignMax);
		writeFloatAttr(wr, itemtag, "sref", "servoA", servoA);
		writeFloatAttr(wr, itemtag, "sref", "servoTheta0", servoTheta0);
		writeFloatAttr(wr, itemtag, "sref", "servoPhi0", servoPhi0);
	xmlTextWriterEndElement(wr);
};

set<uint> JobMsdcSrcMsdd::Stg::comm(
			const Stg* comp
		) {
	set<uint> items;

	if (path == comp->path) insert(items, PATH);
	if (compareFloat(adxlA, comp->adxlA) < 1.0e-4) insert(items, ADXLA);
	if (compareFloat(adxlAlpha0, comp->adxlAlpha0) < 1.0e-4) insert(items, ADXLALPHA0);
	if (compareFloat(adxlBeta0, comp->adxlBeta0) < 1.0e-4) insert(items, ADXLBETA0);
	if (alignMax == comp->alignMax) insert(items, ALIGNMAX);
	if (compareFloat(servoA, comp->servoA) < 1.0e-4) insert(items, SERVOA);
	if (compareFloat(servoTheta0, comp->servoTheta0) < 1.0e-4) insert(items, SERVOTHETA0);
	if (compareFloat(servoPhi0, comp->servoPhi0) < 1.0e-4) insert(items, SERVOPHI0);

	return(items);
};

set<uint> JobMsdcSrcMsdd::Stg::diff(
			const Stg* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {PATH, ADXLA, ADXLALPHA0, ADXLBETA0, ALIGNMAX, SERVOA, SERVOTHETA0, SERVOPHI0};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

