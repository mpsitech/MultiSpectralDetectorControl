/**
  * \file VecMsdcVCamtype.cpp
  * vector VecMsdcVCamtype (implementation)
  * \author Alexander Wirthmueller
  * \date created: 18 Dec 2018
  * \date modified: 18 Dec 2018
  */

#include "VecMsdcVCamtype.h"

/******************************************************************************
 namespace VecMsdcVCamtype
 ******************************************************************************/

uint VecMsdcVCamtype::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "pgbfly") return PGBFLY;
	if (s == "mslife") return MSLIFE;

	return(0);
};

string VecMsdcVCamtype::getSref(
			const uint ix
		) {
	if (ix == PGBFLY) return("pgbfly");
	if (ix == MSLIFE) return("mslife");

	return("");
};

