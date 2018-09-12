/**
  * \file VecMsdcVCamtype.cpp
  * vector VecMsdcVCamtype (implementation)
  * \author Alexander Wirthmueller
  * \date created: 12 Sep 2018
  * \date modified: 12 Sep 2018
  */

#include "VecMsdcVCamtype.h"

/******************************************************************************
 namespace VecMsdcVCamtype
 ******************************************************************************/

uint VecMsdcVCamtype::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "pgbfly") return PGBFLY;
	if (s == "mslife") return MSLIFE;

	return(0);
};

string VecMsdcVCamtype::getSref(
			const uint ix
		) {
	if (ix == PGBFLY) return("pgbfly");
	if (ix == MSLIFE) return("mslife");

	return("");
};

string VecMsdcVCamtype::getTitle(
			const uint ix
		) {
	if (ix == PGBFLY) return("PointGrey BlackFly");
	if (ix == MSLIFE) return("Microsoft LifeCam");
	return(getSref(ix));

	return("");
};

void VecMsdcVCamtype::appendToFeed(
			const uint ix
			, Feed& feed
		) {
	feed.appendIxSrefTitles(ix, getSref(ix), getTitle(ix));
};

void VecMsdcVCamtype::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=2;i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i));
};

