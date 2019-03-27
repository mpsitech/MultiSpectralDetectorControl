/**
  * \file VecMsdcVSqrgrp.cpp
  * vector VecMsdcVSqrgrp (implementation)
  * \author Alexander Wirthmueller
  * \date created: 18 Dec 2018
  * \date modified: 18 Dec 2018
  */

#include "VecMsdcVSqrgrp.h"

/******************************************************************************
 namespace VecMsdcVSqrgrp
 ******************************************************************************/

uint VecMsdcVSqrgrp::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "r0") return R0;
	if (s == "r1") return R1;
	if (s == "r2") return R2;
	if (s == "r3") return R3;
	if (s == "s0") return S0;
	if (s == "s1") return S1;
	if (s == "s2") return S2;
	if (s == "s3") return S3;

	return(0);
};

string VecMsdcVSqrgrp::getSref(
			const uint ix
		) {
	if (ix == R0) return("r0");
	if (ix == R1) return("r1");
	if (ix == R2) return("r2");
	if (ix == R3) return("r3");
	if (ix == S0) return("s0");
	if (ix == S1) return("s1");
	if (ix == S2) return("s2");
	if (ix == S3) return("s3");

	return("");
};

void VecMsdcVSqrgrp::appendToFeed(
			const uint ix
			, Feed& feed
		) {
	feed.appendIxSrefTitles(ix, getSref(ix), getSref(ix));
};

void VecMsdcVSqrgrp::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=8;i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
};

