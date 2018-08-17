/**
  * \file VecMsdcVQrystate.cpp
  * vector VecMsdcVQrystate (implementation)
  * \author Alexander Wirthmueller
  * \date created: 15 Aug 2018
  * \date modified: 15 Aug 2018
  */

#include "VecMsdcVQrystate.h"

/******************************************************************************
 namespace VecMsdcVQrystate
 ******************************************************************************/

uint VecMsdcVQrystate::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "mnr") return MNR;
	if (s == "ood") return OOD;
	if (s == "slm") return SLM;
	if (s == "utd") return UTD;

	return(0);
};

string VecMsdcVQrystate::getSref(
			const uint ix
		) {
	if (ix == MNR) return("mnr");
	if (ix == OOD) return("ood");
	if (ix == SLM) return("slm");
	if (ix == UTD) return("utd");

	return("");
};

