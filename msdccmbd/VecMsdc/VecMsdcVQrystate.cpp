/**
  * \file VecMsdcVQrystate.cpp
  * vector VecMsdcVQrystate (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Oct 2018
  * \date modified: 4 Oct 2018
  */

#include "VecMsdcVQrystate.h"

/******************************************************************************
 namespace VecMsdcVQrystate
 ******************************************************************************/

uint VecMsdcVQrystate::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "mnr") return MNR;
	if (s == "ood") return OOD;
	if (s == "slm") return SLM;
	if (s == "utd") return UTD;

	return(0);
};

string VecMsdcVQrystate::getSref(
			const uint ix
		) {
	if (ix == MNR) return("mnr");
	if (ix == OOD) return("ood");
	if (ix == SLM) return("slm");
	if (ix == UTD) return("utd");

	return("");
};

string VecMsdcVQrystate::getTitle(
			const uint ix
			, const uint ixMsdcVLocale
		) {
	if (ixMsdcVLocale == 1) {
		if (ix == MNR) return("might need refresh");
		if (ix == OOD) return("out of date");
		if (ix == SLM) return("slightly modified");
		if (ix == UTD) return("up to date");
		return(getSref(ix));
	} else if (ixMsdcVLocale == 2) {
		if (ix == MNR) return("eventuell veraltet");
		if (ix == OOD) return("veraltet");
		if (ix == SLM) return("geringf\\u00fcgig ver\\u00e4ndert");
		if (ix == UTD) return("aktuell");
		return(getTitle(ix, 1));
	};

	return("");
};

void VecMsdcVQrystate::fillFeed(
			const uint ixMsdcVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=4;i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixMsdcVLocale));
};

