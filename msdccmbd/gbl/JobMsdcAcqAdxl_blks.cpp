/**
  * \file JobMsdcAcqAdxl_blks.cpp
  * job handler for job JobMsdcAcqAdxl (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 18 Dec 2018
  * \date modified: 18 Dec 2018
  */

/******************************************************************************
 class JobMsdcAcqAdxl::VecVSge
 ******************************************************************************/

uint JobMsdcAcqAdxl::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	if (s == "run") return RUN;

	return(0);
};

string JobMsdcAcqAdxl::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	if (ix == RUN) return("run");

	return("");
};

void JobMsdcAcqAdxl::VecVSge::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=2;i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
};

/******************************************************************************
 class JobMsdcAcqAdxl::VecVVar
 ******************************************************************************/

uint JobMsdcAcqAdxl::VecVVar::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "alphabeta") return ALPHABETA;

	return(0);
};

string JobMsdcAcqAdxl::VecVVar::getSref(
			const uint ix
		) {
	if (ix == ALPHABETA) return("alphaBeta");

	return("");
};

void JobMsdcAcqAdxl::VecVVar::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=1;i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
};

