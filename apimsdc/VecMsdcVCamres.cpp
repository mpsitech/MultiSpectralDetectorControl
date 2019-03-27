/**
  * \file VecMsdcVCamres.cpp
  * vector VecMsdcVCamres (implementation)
  * \author Alexander Wirthmueller
  * \date created: 18 Dec 2018
  * \date modified: 18 Dec 2018
  */

#include "VecMsdcVCamres.h"

/******************************************************************************
 namespace VecMsdcVCamres
 ******************************************************************************/

uint VecMsdcVCamres::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "off") return OFF;
	if (s == "_160") return _160;
	if (s == "_320") return _320;
	if (s == "_640") return _640;
	if (s == "_800") return _800;
	if (s == "_1024") return _1024;
	if (s == "_1280") return _1280;
	if (s == "_720p") return _720P;
	if (s == "_1080p") return _1080P;
	if (s == "max") return MAX;

	return(0);
};

string VecMsdcVCamres::getSref(
			const uint ix
		) {
	if (ix == OFF) return("off");
	if (ix == _160) return("_160");
	if (ix == _320) return("_320");
	if (ix == _640) return("_640");
	if (ix == _800) return("_800");
	if (ix == _1024) return("_1024");
	if (ix == _1280) return("_1280");
	if (ix == _720P) return("_720p");
	if (ix == _1080P) return("_1080p");
	if (ix == MAX) return("max");

	return("");
};

