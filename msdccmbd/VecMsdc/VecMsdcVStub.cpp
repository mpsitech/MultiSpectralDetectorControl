/**
  * \file VecMsdcVStub.cpp
  * vector VecMsdcVStub (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Oct 2018
  * \date modified: 4 Oct 2018
  */

#include "VecMsdcVStub.h"

/******************************************************************************
 namespace VecMsdcVStub
 ******************************************************************************/

uint VecMsdcVStub::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "stubmsdcdatstd") return STUBMSDCDATSTD;
	if (s == "stubmsdcfilstd") return STUBMSDCFILSTD;
	if (s == "stubmsdcprdstd") return STUBMSDCPRDSTD;
	if (s == "stubmsdcprsstd") return STUBMSDCPRSSTD;
	if (s == "stubmsdcsesmenu") return STUBMSDCSESMENU;
	if (s == "stubmsdcsesstd") return STUBMSDCSESSTD;
	if (s == "stubmsdcown") return STUBMSDCOWN;
	if (s == "stubmsdcusrstd") return STUBMSDCUSRSTD;
	if (s == "stubmsdcgrp") return STUBMSDCGRP;
	if (s == "stubmsdcusgstd") return STUBMSDCUSGSTD;

	return(0);
};

string VecMsdcVStub::getSref(
			const uint ix
		) {
	if (ix == STUBMSDCDATSTD) return("StubMsdcDatStd");
	if (ix == STUBMSDCFILSTD) return("StubMsdcFilStd");
	if (ix == STUBMSDCPRDSTD) return("StubMsdcPrdStd");
	if (ix == STUBMSDCPRSSTD) return("StubMsdcPrsStd");
	if (ix == STUBMSDCSESMENU) return("StubMsdcSesMenu");
	if (ix == STUBMSDCSESSTD) return("StubMsdcSesStd");
	if (ix == STUBMSDCOWN) return("StubMsdcOwn");
	if (ix == STUBMSDCUSRSTD) return("StubMsdcUsrStd");
	if (ix == STUBMSDCGRP) return("StubMsdcGrp");
	if (ix == STUBMSDCUSGSTD) return("StubMsdcUsgStd");

	return("");
};

