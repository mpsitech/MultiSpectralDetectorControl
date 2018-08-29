/**
  * \file VecMsdcVIop.cpp
  * vector VecMsdcVIop (implementation)
  * \author Alexander Wirthmueller
  * \date created: 29 Aug 2018
  * \date modified: 29 Aug 2018
  */

#include "VecMsdcVIop.h"

/******************************************************************************
 namespace VecMsdcVIop
 ******************************************************************************/

uint VecMsdcVIop::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "ins") return INS;
	if (s == "retr") return RETR;
	if (s == "retrins") return RETRINS;
	if (s == "retrupd") return RETRUPD;
	if (s == "rmv") return RMV;

	return(0);
};

string VecMsdcVIop::getSref(
			const uint ix
		) {
	if (ix == INS) return("ins");
	if (ix == RETR) return("retr");
	if (ix == RETRINS) return("retrins");
	if (ix == RETRUPD) return("retrupd");
	if (ix == RMV) return("rmv");

	return("");
};

string VecMsdcVIop::getTitle(
			const uint ix
			, const uint ixMsdcVLocale
		) {
	if (ixMsdcVLocale == 1) {
		if (ix == INS) return("insert");
		if (ix == RETR) return("retrieve");
		if (ix == RETRINS) return("retrieve, else insert");
		if (ix == RETRUPD) return("retrieve and update");
		if (ix == RMV) return("remove");
		return(getSref(ix));
	} else if (ixMsdcVLocale == 2) {
		if (ix == INS) return("einf\\u00fcgen");
		if (ix == RETR) return("auffinden");
		if (ix == RETRINS) return("auffinden, sonst einf\\u00fcgen");
		if (ix == RETRUPD) return("auffinden und aktualisieren");
		if (ix == RMV) return("entfernen");
		return(getTitle(ix, 1));
	};

	return("");
};

void VecMsdcVIop::fillFeed(
			const uint ixMsdcVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=5;i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixMsdcVLocale));
};

