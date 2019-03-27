/**
  * \file MsdcMUser_vecs.cpp
  * database access for table TblMsdcMUser (implementation of vectors)
  * \author Alexander Wirthmueller
  * \date created: 18 Dec 2018
  * \date modified: 18 Dec 2018
  */

/******************************************************************************
 class TblMsdcMUser::VecVState
 ******************************************************************************/

uint TblMsdcMUser::VecVState::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "act") return ACT;
	if (s == "dsg") return DSG;
	if (s == "due") return DUE;
	if (s == "exp") return EXP;

	return(0);
};

string TblMsdcMUser::VecVState::getSref(
			const uint ix
		) {
	if (ix == ACT) return("act");
	if (ix == DSG) return("dsg");
	if (ix == DUE) return("due");
	if (ix == EXP) return("exp");

	return("");
};

string TblMsdcMUser::VecVState::getTitle(
			const uint ix
			, const uint ixMsdcVLocale
		) {
	if (ixMsdcVLocale == 1) {
		if (ix == ACT) return("active");
		if (ix == DSG) return("designated");
		if (ix == DUE) return("due for expiration");
		if (ix == EXP) return("expired");
		return(getSref(ix));
	} else if (ixMsdcVLocale == 2) {
		if (ix == ACT) return("aktiv");
		if (ix == DSG) return("vorgesehen");
		if (ix == DUE) return("l\\u00e4uft ab");
		if (ix == EXP) return("abgelaufen");
		return(getTitle(ix, 1));
	};

	return("");
};

void TblMsdcMUser::VecVState::fillFeed(
			const uint ixMsdcVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=4;i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixMsdcVLocale));
};

