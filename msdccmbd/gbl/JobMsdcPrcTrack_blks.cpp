/**
  * \file JobMsdcPrcTrack_blks.cpp
  * job handler for job JobMsdcPrcTrack (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 18 Dec 2018
  * \date modified: 18 Dec 2018
  */

/******************************************************************************
 class JobMsdcPrcTrack::VecVSge
 ******************************************************************************/

uint JobMsdcPrcTrack::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	if (s == "run") return RUN;

	return(0);
};

string JobMsdcPrcTrack::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	if (ix == RUN) return("run");

	return("");
};

void JobMsdcPrcTrack::VecVSge::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=2;i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
};

