/**
  * \file VecMsdcVLat.cpp
  * vector VecMsdcVLat (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Oct 2018
  * \date modified: 4 Oct 2018
  */

#include "VecMsdcVLat.h"

/******************************************************************************
 namespace VecMsdcVLat
 ******************************************************************************/

uint VecMsdcVLat::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "dlo") return DLO;
	if (s == "ini") return INI;

	return(0);
};

string VecMsdcVLat::getSref(
			const uint ix
		) {
	if (ix == DLO) return("dlo");
	if (ix == INI) return("ini");

	return("");
};

