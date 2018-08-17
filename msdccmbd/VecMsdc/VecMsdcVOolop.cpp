/**
  * \file VecMsdcVOolop.cpp
  * vector VecMsdcVOolop (implementation)
  * \author Alexander Wirthmueller
  * \date created: 15 Aug 2018
  * \date modified: 15 Aug 2018
  */

#include "VecMsdcVOolop.h"

/******************************************************************************
 namespace VecMsdcVOolop
 ******************************************************************************/

uint VecMsdcVOolop::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "ina") return INA;
	if (s == "inb") return INB;
	if (s == "rmv") return RMV;
	if (s == "swp") return SWP;
	if (s == "toa") return TOA;
	if (s == "tob") return TOB;

	return(0);
};

string VecMsdcVOolop::getSref(
			const uint ix
		) {
	if (ix == INA) return("ina");
	if (ix == INB) return("inb");
	if (ix == RMV) return("rmv");
	if (ix == SWP) return("swp");
	if (ix == TOA) return("toa");
	if (ix == TOB) return("tob");

	return("");
};

