/**
  * \file VecMsdcVCamste.cpp
  * vector VecMsdcVCamste (implementation)
  * \author Alexander Wirthmueller
  * \date created: 18 Dec 2018
  * \date modified: 18 Dec 2018
  */

#include "VecMsdcVCamste.h"

/******************************************************************************
 namespace VecMsdcVCamste
 ******************************************************************************/

uint VecMsdcVCamste::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "nc") return NC;
	if (s == "ready") return READY;
	if (s == "active") return ACTIVE;

	return(0);
};

string VecMsdcVCamste::getSref(
			const uint ix
		) {
	if (ix == NC) return("nc");
	if (ix == READY) return("ready");
	if (ix == ACTIVE) return("active");

	return("");
};

string VecMsdcVCamste::getTitle(
			const uint ix
			, const uint ixMsdcVLocale
		) {
	if (ixMsdcVLocale == 1) {
		if (ix == NC) return("offline");
		if (ix == READY) return("ready");
		if (ix == ACTIVE) return("running");
		return(getSref(ix));
	} else if (ixMsdcVLocale == 2) {
		if (ix == NC) return("nicht verbunden");
		if (ix == READY) return("bereit");
		if (ix == ACTIVE) return("l\\u00e4uft");
		return(getTitle(ix, 1));
	};

	return("");
};

void VecMsdcVCamste::appendToFeed(
			const uint ix
			, const uint ixMsdcVLocale
			, Feed& feed
		) {
	feed.appendIxSrefTitles(ix, getSref(ix), getTitle(ix, ixMsdcVLocale));
};

void VecMsdcVCamste::fillFeed(
			const uint ixMsdcVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=3;i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixMsdcVLocale));
};

