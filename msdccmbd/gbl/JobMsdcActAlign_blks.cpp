/**
  * \file JobMsdcActAlign_blks.cpp
  * job handler for job JobMsdcActAlign (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 29 Aug 2018
  * \date modified: 29 Aug 2018
  */

/******************************************************************************
 class JobMsdcActAlign::VecVFunction
 ******************************************************************************/

uint JobMsdcActAlign::VecVFunction::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "cust") return CUST;
	if (s == "sin") return SIN;
	if (s == "sqr") return SQR;
	if (s == "swt") return SWT;
	if (s == "tri") return TRI;

	return(0);
};

string JobMsdcActAlign::VecVFunction::getSref(
			const uint ix
		) {
	if (ix == CUST) return("cust");
	if (ix == SIN) return("sin");
	if (ix == SQR) return("sqr");
	if (ix == SWT) return("swt");
	if (ix == TRI) return("tri");

	return("");
};

string JobMsdcActAlign::VecVFunction::getTitle(
			const uint ix
			, const uint ixMsdcVLocale
		) {
	if (ixMsdcVLocale == 1) {
		if (ix == CUST) return("custom");
		if (ix == SIN) return("sine");
		if (ix == SQR) return("square");
		if (ix == SWT) return("sawtooth");
		if (ix == TRI) return("triangle");
		return(getSref(ix));
	} else if (ixMsdcVLocale == 2) {
		if (ix == CUST) return("frei konfiguriert");
		if (ix == SIN) return("Sinus");
		if (ix == SQR) return("Rechteck");
		if (ix == SWT) return("S\\u00e4gezahn");
		if (ix == TRI) return("Dreieck");
		return(getTitle(ix, 1));
	};

	return("");
};

void JobMsdcActAlign::VecVFunction::appendToFeed(
			const uint ix
			, const uint ixMsdcVLocale
			, Feed& feed
		) {
	feed.appendIxSrefTitles(ix, getSref(ix), getTitle(ix, ixMsdcVLocale));
};

void JobMsdcActAlign::VecVFunction::fillFeed(
			const uint ixMsdcVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=5;i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixMsdcVLocale));
};

/******************************************************************************
 class JobMsdcActAlign::VecVMethod
 ******************************************************************************/

uint JobMsdcActAlign::VecVMethod::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "setwave") return SETWAVE;
	if (s == "start") return START;
	if (s == "stop") return STOP;

	return(0);
};

string JobMsdcActAlign::VecVMethod::getSref(
			const uint ix
		) {
	if (ix == SETWAVE) return("setWave");
	if (ix == START) return("start");
	if (ix == STOP) return("stop");

	return("");
};

void JobMsdcActAlign::VecVMethod::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=3;i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
};

/******************************************************************************
 class JobMsdcActAlign::VecVSge
 ******************************************************************************/

uint JobMsdcActAlign::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	if (s == "run") return RUN;

	return(0);
};

string JobMsdcActAlign::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	if (ix == RUN) return("run");

	return("");
};

void JobMsdcActAlign::VecVSge::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=2;i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
};

