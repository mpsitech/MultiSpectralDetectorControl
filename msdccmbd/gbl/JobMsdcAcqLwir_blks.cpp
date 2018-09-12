/**
  * \file JobMsdcAcqLwir_blks.cpp
  * job handler for job JobMsdcAcqLwir (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 12 Sep 2018
  * \date modified: 12 Sep 2018
  */

/******************************************************************************
 class JobMsdcAcqLwir::VecVMethod
 ******************************************************************************/

uint JobMsdcAcqLwir::VecVMethod::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "setoutput") return SETOUTPUT;
	if (s == "start") return START;
	if (s == "stop") return STOP;

	return(0);
};

string JobMsdcAcqLwir::VecVMethod::getSref(
			const uint ix
		) {
	if (ix == SETOUTPUT) return("setOutput");
	if (ix == START) return("start");
	if (ix == STOP) return("stop");

	return("");
};

void JobMsdcAcqLwir::VecVMethod::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=3;i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
};

/******************************************************************************
 class JobMsdcAcqLwir::VecVSge
 ******************************************************************************/

uint JobMsdcAcqLwir::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	if (s == "ready") return READY;
	if (s == "waitbuf") return WAITBUF;
	if (s == "acq") return ACQ;
	if (s == "prcidle") return PRCIDLE;
	if (s == "prc") return PRC;

	return(0);
};

string JobMsdcAcqLwir::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	if (ix == READY) return("ready");
	if (ix == WAITBUF) return("waitbuf");
	if (ix == ACQ) return("acq");
	if (ix == PRCIDLE) return("prcidle");
	if (ix == PRC) return("prc");

	return("");
};

void JobMsdcAcqLwir::VecVSge::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=6;i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
};

/******************************************************************************
 class JobMsdcAcqLwir::VecVVar
 ******************************************************************************/

uint JobMsdcAcqLwir::VecVVar::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "seqnotgray16") return SEQNOTGRAY16;

	return(0);
};

string JobMsdcAcqLwir::VecVVar::getSref(
			const uint ix
		) {
	if (ix == SEQNOTGRAY16) return("seqnoTGray16");

	return("");
};

void JobMsdcAcqLwir::VecVVar::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=1;i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
};

/******************************************************************************
 class JobMsdcAcqLwir::Stg
 ******************************************************************************/

JobMsdcAcqLwir::Stg::Stg(
			const uint width
			, const uint height
			, const double hpix
			, const string& serno
			, const double a
			, const double b
			, const uint ixMsdcVSqrgrp
			, const double f
			, const double fn
			, const double k1
			, const double k2
			, const double p1
			, const double p2
			, const double k3
			, const double k4
			, const double k5
			, const double k6
		) :
			Block()
		{
	this->width = width;
	this->height = height;
	this->hpix = hpix;
	this->serno = serno;
	this->a = a;
	this->b = b;
	this->ixMsdcVSqrgrp = ixMsdcVSqrgrp;
	this->f = f;
	this->fn = fn;
	this->k1 = k1;
	this->k2 = k2;
	this->p1 = p1;
	this->p2 = p2;
	this->k3 = k3;
	this->k4 = k4;
	this->k5 = k5;
	this->k6 = k6;
	mask = {WIDTH, HEIGHT, HPIX, SERNO, A, B, IXMSDCVSQRGRP, F, FN, K1, K2, P1, P2, K3, K4, K5, K6};
};

bool JobMsdcAcqLwir::Stg::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxMsdcVSqrgrp;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgJobMsdcAcqLwir");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemJobMsdcAcqLwir";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "width", width)) add(WIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "height", height)) add(HEIGHT);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "hpix", hpix)) add(HPIX);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "serno", serno)) add(SERNO);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "a", a)) add(A);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "b", b)) add(B);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxMsdcVSqrgrp", srefIxMsdcVSqrgrp)) {
			ixMsdcVSqrgrp = VecMsdcVSqrgrp::getIx(srefIxMsdcVSqrgrp);
			add(IXMSDCVSQRGRP);
		};
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "f", f)) add(F);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "fn", fn)) add(FN);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "k1", k1)) add(K1);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "k2", k2)) add(K2);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "p1", p1)) add(P1);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "p2", p2)) add(P2);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "k3", k3)) add(K3);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "k4", k4)) add(K4);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "k5", k5)) add(K5);
		if (extractDoubleAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "k6", k6)) add(K6);
	};

	return basefound;
};

void JobMsdcAcqLwir::Stg::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgJobMsdcAcqLwir";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemJobMsdcAcqLwir";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "width", width);
		writeUintAttr(wr, itemtag, "sref", "height", height);
		writeDoubleAttr(wr, itemtag, "sref", "hpix", hpix);
		writeStringAttr(wr, itemtag, "sref", "serno", serno);
		writeDoubleAttr(wr, itemtag, "sref", "a", a);
		writeDoubleAttr(wr, itemtag, "sref", "b", b);
		writeStringAttr(wr, itemtag, "sref", "srefIxMsdcVSqrgrp", VecMsdcVSqrgrp::getSref(ixMsdcVSqrgrp));
		writeDoubleAttr(wr, itemtag, "sref", "f", f);
		writeDoubleAttr(wr, itemtag, "sref", "fn", fn);
		writeDoubleAttr(wr, itemtag, "sref", "k1", k1);
		writeDoubleAttr(wr, itemtag, "sref", "k2", k2);
		writeDoubleAttr(wr, itemtag, "sref", "p1", p1);
		writeDoubleAttr(wr, itemtag, "sref", "p2", p2);
		writeDoubleAttr(wr, itemtag, "sref", "k3", k3);
		writeDoubleAttr(wr, itemtag, "sref", "k4", k4);
		writeDoubleAttr(wr, itemtag, "sref", "k5", k5);
		writeDoubleAttr(wr, itemtag, "sref", "k6", k6);
	xmlTextWriterEndElement(wr);
};

set<uint> JobMsdcAcqLwir::Stg::comm(
			const Stg* comp
		) {
	set<uint> items;

	if (width == comp->width) insert(items, WIDTH);
	if (height == comp->height) insert(items, HEIGHT);
	if (compareDouble(hpix, comp->hpix) < 1.0e-4) insert(items, HPIX);
	if (serno == comp->serno) insert(items, SERNO);
	if (compareDouble(a, comp->a) < 1.0e-4) insert(items, A);
	if (compareDouble(b, comp->b) < 1.0e-4) insert(items, B);
	if (ixMsdcVSqrgrp == comp->ixMsdcVSqrgrp) insert(items, IXMSDCVSQRGRP);
	if (compareDouble(f, comp->f) < 1.0e-4) insert(items, F);
	if (compareDouble(fn, comp->fn) < 1.0e-4) insert(items, FN);
	if (compareDouble(k1, comp->k1) < 1.0e-4) insert(items, K1);
	if (compareDouble(k2, comp->k2) < 1.0e-4) insert(items, K2);
	if (compareDouble(p1, comp->p1) < 1.0e-4) insert(items, P1);
	if (compareDouble(p2, comp->p2) < 1.0e-4) insert(items, P2);
	if (compareDouble(k3, comp->k3) < 1.0e-4) insert(items, K3);
	if (compareDouble(k4, comp->k4) < 1.0e-4) insert(items, K4);
	if (compareDouble(k5, comp->k5) < 1.0e-4) insert(items, K5);
	if (compareDouble(k6, comp->k6) < 1.0e-4) insert(items, K6);

	return(items);
};

set<uint> JobMsdcAcqLwir::Stg::diff(
			const Stg* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {WIDTH, HEIGHT, HPIX, SERNO, A, B, IXMSDCVSQRGRP, F, FN, K1, K2, P1, P2, K3, K4, K5, K6};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

