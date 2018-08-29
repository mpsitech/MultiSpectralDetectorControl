/**
  * \file VecMsdcVChannel.cpp
  * vector VecMsdcVChannel (implementation)
  * \author Alexander Wirthmueller
  * \date created: 29 Aug 2018
  * \date modified: 29 Aug 2018
  */

#include "VecMsdcVChannel.h"

/******************************************************************************
 namespace VecMsdcVChannel
 ******************************************************************************/

uint VecMsdcVChannel::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "red8") return RED8;
	if (s == "green8") return GREEN8;
	if (s == "blue8") return BLUE8;
	if (s == "rgbx32") return RGBX32;
	if (s == "gray8") return GRAY8;
	if (s == "gray16") return GRAY16;

	return(0);
};

string VecMsdcVChannel::getSref(
			const uint ix
		) {
	if (ix == RED8) return("red8");
	if (ix == GREEN8) return("green8");
	if (ix == BLUE8) return("blue8");
	if (ix == RGBX32) return("rgbx32");
	if (ix == GRAY8) return("gray8");
	if (ix == GRAY16) return("gray16");

	return("");
};

