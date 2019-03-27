/**
  * \file VecMsdcVOppack.cpp
  * vector VecMsdcVOppack (implementation)
  * \author Alexander Wirthmueller
  * \date created: 18 Dec 2018
  * \date modified: 18 Dec 2018
  */

#include "VecMsdcVOppack.h"

/******************************************************************************
 namespace VecMsdcVOppack
 ******************************************************************************/

uint VecMsdcVOppack::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	return(0);
};

string VecMsdcVOppack::getSref(
			const uint ix
		) {

	return("");
};

string VecMsdcVOppack::getTitle(
			const uint ix
		) {
	return(getSref(ix));

	return("");
};

string VecMsdcVOppack::getComment(
			const uint ix
		) {

	return("");
};

void VecMsdcVOppack::appendToFeed(
			const uint ix
			, Feed& feed
		) {
	feed.appendIxSrefTitles(ix, getSref(ix), getTitle(ix));
};

void VecMsdcVOppack::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=0;i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i));
};

