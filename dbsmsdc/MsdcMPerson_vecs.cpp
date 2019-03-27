/**
  * \file MsdcMPerson_vecs.cpp
  * database access for table TblMsdcMPerson (implementation of vectors)
  * \author Alexander Wirthmueller
  * \date created: 18 Dec 2018
  * \date modified: 18 Dec 2018
  */

/******************************************************************************
 class TblMsdcMPerson::VecVSex
 ******************************************************************************/

uint TblMsdcMPerson::VecVSex::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "f") return F;
	if (s == "m") return M;

	return(0);
};

string TblMsdcMPerson::VecVSex::getSref(
			const uint ix
		) {
	if (ix == F) return("f");
	if (ix == M) return("m");

	return("");
};

string TblMsdcMPerson::VecVSex::getTitle(
			const uint ix
			, const uint ixMsdcVLocale
		) {
	if (ixMsdcVLocale == 1) {
		if (ix == F) return("female");
		if (ix == M) return("male");
		return(getSref(ix));
	} else if (ixMsdcVLocale == 2) {
		if (ix == F) return("weiblich");
		if (ix == M) return("m\\u00e4nnlich");
		return(getTitle(ix, 1));
	};

	return("");
};

void TblMsdcMPerson::VecVSex::fillFeed(
			const uint ixMsdcVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=2;i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixMsdcVLocale));
};

/******************************************************************************
 class TblMsdcMPerson::VecWDerivate
 ******************************************************************************/

uint TblMsdcMPerson::VecWDerivate::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i=0;i<ss.size();i++) {
		if (ss[i] == "usr") ix |= USR;
	};

	return(ix);
};

void TblMsdcMPerson::VecWDerivate::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*USR);i*=2) if (ix & i) ics.insert(i);
};

string TblMsdcMPerson::VecWDerivate::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & USR) ss.push_back("usr");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

string TblMsdcMPerson::VecWDerivate::getTitle(
			const uint ix
			, const uint ixMsdcVLocale
		) {
	if (ixMsdcVLocale == 1) {
		if (ix == USR) return("user");
		return(getSrefs(ix));
	} else if (ixMsdcVLocale == 2) {
		if (ix == USR) return("Benutzer");
		return(getTitle(ix, 1));
	};

	return("");
};

void TblMsdcMPerson::VecWDerivate::fillFeed(
			const uint ixMsdcVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=USR;i*=2) feed.appendIxSrefTitles(i, getSrefs(i), getTitle(i, ixMsdcVLocale));
};

