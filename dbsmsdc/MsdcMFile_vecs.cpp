/**
  * \file MsdcMFile_vecs.cpp
  * database access for table TblMsdcMFile (implementation of vectors)
  * \author Alexander Wirthmueller
  * \date created: 29 Aug 2018
  * \date modified: 29 Aug 2018
  */

/******************************************************************************
 class TblMsdcMFile::VecVRefTbl
 ******************************************************************************/

uint TblMsdcMFile::VecVRefTbl::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "void") return VOID;
	if (s == "dat") return DAT;

	return(0);
};

string TblMsdcMFile::VecVRefTbl::getSref(
			const uint ix
		) {
	if (ix == VOID) return("void");
	if (ix == DAT) return("dat");

	return("");
};

string TblMsdcMFile::VecVRefTbl::getTitle(
			const uint ix
			, const uint ixMsdcVLocale
		) {
	if (ixMsdcVLocale == 1) {
		if (ix == VOID) return("none");
		if (ix == DAT) return("raw data");
		return(getSref(ix));
	} else if (ixMsdcVLocale == 2) {
		if (ix == VOID) return("kein");
		if (ix == DAT) return("Rohdaten");
		return(getTitle(ix, 1));
	};

	return("");
};

void TblMsdcMFile::VecVRefTbl::fillFeed(
			const uint ixMsdcVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=2;i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixMsdcVLocale));
};

