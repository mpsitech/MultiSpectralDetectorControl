/**
  * \file VecMsdcVCorner.cpp
  * vector VecMsdcVCorner (implementation)
  * \author Alexander Wirthmueller
  * \date created: 12 Sep 2018
  * \date modified: 12 Sep 2018
  */

#include "VecMsdcVCorner.h"

/******************************************************************************
 namespace VecMsdcVCorner
 ******************************************************************************/

uint VecMsdcVCorner::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "n") return N;
	if (s == "ne") return NE;
	if (s == "e") return E;
	if (s == "se") return SE;
	if (s == "s") return S;
	if (s == "sw") return SW;
	if (s == "w") return W;
	if (s == "nw") return NW;

	return(0);
};

string VecMsdcVCorner::getSref(
			const uint ix
		) {
	if (ix == N) return("n");
	if (ix == NE) return("ne");
	if (ix == E) return("e");
	if (ix == SE) return("se");
	if (ix == S) return("s");
	if (ix == SW) return("sw");
	if (ix == W) return("w");
	if (ix == NW) return("nw");

	return("");
};

