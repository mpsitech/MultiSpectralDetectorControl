/**
  * \file VecMsdcVReqitmode.cpp
  * vector VecMsdcVReqitmode (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Oct 2018
  * \date modified: 4 Oct 2018
  */

#include "VecMsdcVReqitmode.h"

/******************************************************************************
 namespace VecMsdcVReqitmode
 ******************************************************************************/

uint VecMsdcVReqitmode::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	if (s == "notify") return NOTIFY;
	if (s == "poll") return POLL;

	return(0);
};

string VecMsdcVReqitmode::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	if (ix == NOTIFY) return("notify");
	if (ix == POLL) return("poll");

	return("");
};

