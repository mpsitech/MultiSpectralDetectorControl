/**
  * \file VecMsdcVLop.cpp
  * vector VecMsdcVLop (implementation)
  * \author Alexander Wirthmueller
  * \date created: 15 Aug 2018
  * \date modified: 15 Aug 2018
  */

#include "VecMsdcVLop.h"

/******************************************************************************
 namespace VecMsdcVLop
 ******************************************************************************/

uint VecMsdcVLop::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "ins") return INS;
	if (s == "rmv") return RMV;

	return(0);
};

string VecMsdcVLop::getSref(
			const uint ix
		) {
	if (ix == INS) return("ins");
	if (ix == RMV) return("rmv");

	return("");
};

