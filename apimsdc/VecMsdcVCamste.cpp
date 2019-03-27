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

