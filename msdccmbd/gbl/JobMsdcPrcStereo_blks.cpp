/**
  * \file JobMsdcPrcStereo_blks.cpp
  * job handler for job JobMsdcPrcStereo (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 29 Aug 2018
  * \date modified: 29 Aug 2018
  */

/******************************************************************************
 class JobMsdcPrcStereo::VecVSge
 ******************************************************************************/

uint JobMsdcPrcStereo::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	if (s == "run") return RUN;

	return(0);
};

string JobMsdcPrcStereo::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	if (ix == RUN) return("run");

	return("");
};

void JobMsdcPrcStereo::VecVSge::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=2;i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
};

