/**
  * \file RootMsdc_blks.cpp
  * job handler for job RootMsdc (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 29 Aug 2018
  * \date modified: 29 Aug 2018
  */

/******************************************************************************
 class RootMsdc::DpchAppLogin
 ******************************************************************************/

RootMsdc::DpchAppLogin::DpchAppLogin() :
			DpchAppMsdc(VecMsdcVDpch::DPCHAPPROOTMSDCLOGIN)
		{
	m2mNotReg = false;
	chksuspsess = false;
};

string RootMsdc::DpchAppLogin::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(USERNAME)) ss.push_back("username");
	if (has(PASSWORD)) ss.push_back("password");
	if (has(M2MNOTREG)) ss.push_back("m2mNotReg");
	if (has(CHKSUSPSESS)) ss.push_back("chksuspsess");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void RootMsdc::DpchAppLogin::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppRootMsdcLogin");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) {
			jref = Scr::descramble(scrJref);
			add(JREF);
		};
		if (extractStringUclc(docctx, basexpath, "username", "", username)) add(USERNAME);
		if (extractStringUclc(docctx, basexpath, "password", "", password)) add(PASSWORD);
		if (extractBoolUclc(docctx, basexpath, "m2mNotReg", "", m2mNotReg)) add(M2MNOTREG);
		if (extractBoolUclc(docctx, basexpath, "chksuspsess", "", chksuspsess)) add(CHKSUSPSESS);
	} else {
	};
};

/******************************************************************************
 class RootMsdc::DpchEngData
 ******************************************************************************/

RootMsdc::DpchEngData::DpchEngData(
			const ubigint jref
			, Feed* feedFEnsSps
			, const set<uint>& mask
		) :
			DpchEngMsdc(VecMsdcVDpch::DPCHENGROOTMSDCDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, FEEDFENSSPS};
	else this->mask = mask;

	if (find(this->mask, FEEDFENSSPS) && feedFEnsSps) this->feedFEnsSps = *feedFEnsSps;
};

string RootMsdc::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(FEEDFENSSPS)) ss.push_back("feedFEnsSps");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void RootMsdc::DpchEngData::merge(
			DpchEngMsdc* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(FEEDFENSSPS)) {feedFEnsSps = src->feedFEnsSps; add(FEEDFENSSPS);};
};

void RootMsdc::DpchEngData::writeXML(
			const uint ixMsdcVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngRootMsdcData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/msdc");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(FEEDFENSSPS)) feedFEnsSps.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

