/**
  * \file VecMsdcVOpengtype.cpp
  * vector VecMsdcVOpengtype (implementation)
  * \author Alexander Wirthmueller
  * \date created: 29 Aug 2018
  * \date modified: 29 Aug 2018
  */

#include "VecMsdcVOpengtype.h"

/******************************************************************************
 namespace VecMsdcVOpengtype
 ******************************************************************************/

uint VecMsdcVOpengtype::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	return(0);
};

string VecMsdcVOpengtype::getSref(
			const uint ix
		) {

	return("");
};

string VecMsdcVOpengtype::getTitle(
			const uint ix
			, const uint ixMsdcVLocale
		) {
	if (ixMsdcVLocale == 1) {
		return(getSref(ix));
	} else if (ixMsdcVLocale == 2) {
		return(getTitle(ix, 1));
	};

	return("");
};

void VecMsdcVOpengtype::appendToFeed(
			const uint ix
			, const uint ixMsdcVLocale
			, Feed& feed
		) {
	feed.appendIxSrefTitles(ix, getSref(ix), getTitle(ix, ixMsdcVLocale));
};

void VecMsdcVOpengtype::fillFeed(
			const uint ixMsdcVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=0;i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixMsdcVLocale));
};

