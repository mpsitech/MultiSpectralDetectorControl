/**
  * \file JobMsdcActServo_blks.cpp
  * job handler for job JobMsdcActServo (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 4 Oct 2018
  * \date modified: 4 Oct 2018
  */

/******************************************************************************
 class JobMsdcActServo::VecVMethod
 ******************************************************************************/

uint JobMsdcActServo::VecVMethod::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "setphi") return SETPHI;
	if (s == "settheta") return SETTHETA;

	return(0);
};

string JobMsdcActServo::VecVMethod::getSref(
			const uint ix
		) {
	if (ix == SETPHI) return("setPhi");
	if (ix == SETTHETA) return("setTheta");

	return("");
};

void JobMsdcActServo::VecVMethod::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=2;i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
};

/******************************************************************************
 class JobMsdcActServo::VecVVar
 ******************************************************************************/

uint JobMsdcActServo::VecVVar::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "thetaphi") return THETAPHI;

	return(0);
};

string JobMsdcActServo::VecVVar::getSref(
			const uint ix
		) {
	if (ix == THETAPHI) return("thetaPhi");

	return("");
};

void JobMsdcActServo::VecVVar::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=1;i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
};

/******************************************************************************
 class JobMsdcActServo::Stg
 ******************************************************************************/

JobMsdcActServo::Stg::Stg(
			const double phimin
			, const double phimax
			, const double thetamin
			, const double thetamax
		) :
			Block()
		{
	this->phimin = phimin;
	this->phimax = phimax;
	this->thetamin = thetamin;
	this->thetamax = thetamax;
	mask = {PHIMIN, PHIMAX, THETAMIN, THETAMAX};
};

bool JobMsdcActServo::Stg::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgJobMsdcActServo");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemJobMsdcActServo";

	if (basefound) {
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "phimin", phimin)) add(PHIMIN);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "phimax", phimax)) add(PHIMAX);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "thetamin", thetamin)) add(THETAMIN);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "thetamax", thetamax)) add(THETAMAX);
	};

	return basefound;
};

void JobMsdcActServo::Stg::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgJobMsdcActServo";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemJobMsdcActServo";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeDoubleAttr(wr, itemtag, "sref", "phimin", phimin);
		writeDoubleAttr(wr, itemtag, "sref", "phimax", phimax);
		writeDoubleAttr(wr, itemtag, "sref", "thetamin", thetamin);
		writeDoubleAttr(wr, itemtag, "sref", "thetamax", thetamax);
	xmlTextWriterEndElement(wr);
};

set<uint> JobMsdcActServo::Stg::comm(
			const Stg* comp
		) {
	set<uint> items;

	if (compareDouble(phimin, comp->phimin) < 1.0e-4) insert(items, PHIMIN);
	if (compareDouble(phimax, comp->phimax) < 1.0e-4) insert(items, PHIMAX);
	if (compareDouble(thetamin, comp->thetamin) < 1.0e-4) insert(items, THETAMIN);
	if (compareDouble(thetamax, comp->thetamax) < 1.0e-4) insert(items, THETAMAX);

	return(items);
};

set<uint> JobMsdcActServo::Stg::diff(
			const Stg* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {PHIMIN, PHIMAX, THETAMIN, THETAMAX};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

