/**
  * \file JobMsdcSrcTrigger.cpp
  * API code for job JobMsdcSrcTrigger (implementation)
  * \author Alexander Wirthmueller
  * \date created: 12 Sep 2018
  * \date modified: 12 Sep 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "JobMsdcSrcTrigger.h"

/******************************************************************************
 class JobMsdcSrcTrigger::VecVSge
 ******************************************************************************/

uint JobMsdcSrcTrigger::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	if (s == "run") return RUN;

	return(0);
};

string JobMsdcSrcTrigger::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	if (ix == RUN) return("run");

	return("");
};

/******************************************************************************
 class JobMsdcSrcTrigger::Stg
 ******************************************************************************/

JobMsdcSrcTrigger::Stg::Stg(
			const float dt
		) :
			Block()
		{
	this->dt = dt;

	mask = {DT};
};

bool JobMsdcSrcTrigger::Stg::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgJobMsdcSrcTrigger");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemJobMsdcSrcTrigger";

	if (basefound) {
		if (extractFloatAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "dt", dt)) add(DT);
	};

	return basefound;
};

void JobMsdcSrcTrigger::Stg::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgJobMsdcSrcTrigger";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemJobMsdcSrcTrigger";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeFloatAttr(wr, itemtag, "sref", "dt", dt);
	xmlTextWriterEndElement(wr);
};

set<uint> JobMsdcSrcTrigger::Stg::comm(
			const Stg* comp
		) {
	set<uint> items;

	if (compareFloat(dt, comp->dt) < 1.0e-4) insert(items, DT);

	return(items);
};

set<uint> JobMsdcSrcTrigger::Stg::diff(
			const Stg* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

