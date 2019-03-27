/**
  * \file RootMsdc.cpp
  * API code for job RootMsdc (implementation)
  * \author Alexander Wirthmueller
  * \date created: 18 Dec 2018
  * \date modified: 18 Dec 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "RootMsdc.h"

/******************************************************************************
 class RootMsdc::DpchAppLogin
 ******************************************************************************/

RootMsdc::DpchAppLogin::DpchAppLogin(
			const string& scrJref
			, const string& username
			, const string& password
			, const bool m2mNotReg
			, const bool chksuspsess
			, const set<uint>& mask
		) :
			DpchAppMsdc(VecMsdcVDpch::DPCHAPPROOTMSDCLOGIN, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, USERNAME, PASSWORD, M2MNOTREG, CHKSUSPSESS};
	else this->mask = mask;

	this->username = username;
	this->password = password;
	this->m2mNotReg = m2mNotReg;
	this->chksuspsess = chksuspsess;
};

string RootMsdc::DpchAppLogin::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(USERNAME)) ss.push_back("username");
	if (has(PASSWORD)) ss.push_back("password");
	if (has(M2MNOTREG)) ss.push_back("m2mNotReg");
	if (has(CHKSUSPSESS)) ss.push_back("chksuspsess");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void RootMsdc::DpchAppLogin::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppRootMsdcLogin");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/msdc");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(USERNAME)) writeString(wr, "username", username);
		if (has(PASSWORD)) writeString(wr, "password", password);
		if (has(M2MNOTREG)) writeBool(wr, "m2mNotReg", m2mNotReg);
		if (has(CHKSUSPSESS)) writeBool(wr, "chksuspsess", chksuspsess);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class RootMsdc::DpchEngData
 ******************************************************************************/

RootMsdc::DpchEngData::DpchEngData() :
			DpchEngMsdc(VecMsdcVDpch::DPCHENGROOTMSDCDATA)
		{
	feedFEnsSps.tag = "FeedFEnsSps";
};

string RootMsdc::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(FEEDFENSSPS)) ss.push_back("feedFEnsSps");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void RootMsdc::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngRootMsdcData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (feedFEnsSps.readXML(docctx, basexpath, true)) add(FEEDFENSSPS);
	} else {
		feedFEnsSps.clear();
	};
};

