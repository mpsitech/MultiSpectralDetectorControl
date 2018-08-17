/**
  * \file JobMsdcActLed_blks.cpp
  * job handler for job JobMsdcActLed (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 15 Aug 2018
  * \date modified: 15 Aug 2018
  */

/******************************************************************************
 class JobMsdcActLed::VecVMethod
 ******************************************************************************/

uint JobMsdcActLed::VecVMethod::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "setflood") return SETFLOOD;
	if (s == "setspot") return SETSPOT;

	return(0);
};

string JobMsdcActLed::VecVMethod::getSref(
			const uint ix
		) {
	if (ix == SETFLOOD) return("setFlood");
	if (ix == SETSPOT) return("setSpot");

	return("");
};

void JobMsdcActLed::VecVMethod::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=2;i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
};

/******************************************************************************
 class JobMsdcActLed::VecVVar
 ******************************************************************************/

uint JobMsdcActLed::VecVVar::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "floodspot") return FLOODSPOT;

	return(0);
};

string JobMsdcActLed::VecVVar::getSref(
			const uint ix
		) {
	if (ix == FLOODSPOT) return("floodSpot");

	return("");
};

void JobMsdcActLed::VecVVar::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=1;i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
};

