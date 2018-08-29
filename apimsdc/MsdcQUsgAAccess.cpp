/**
  * \file MsdcQUsgAAccess.cpp
  * API code for table TblMsdcQUsgAAccess (implementation)
  * \author Alexander Wirthmueller
  * \date created: 29 Aug 2018
  * \date modified: 29 Aug 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "MsdcQUsgAAccess.h"

/******************************************************************************
 class MsdcQUsgAAccess
 ******************************************************************************/

MsdcQUsgAAccess::MsdcQUsgAAccess(
			const uint jnum
			, const string srefX1IxMsdcVFeatgroup
			, const string titX1IxMsdcVFeatgroup
			, const string x2FeaSrefUix
			, const string srefsIxMsdcWAccess
			, const string titsIxMsdcWAccess
		) {
	this->jnum = jnum;
	this->srefX1IxMsdcVFeatgroup = srefX1IxMsdcVFeatgroup;
	this->titX1IxMsdcVFeatgroup = titX1IxMsdcVFeatgroup;
	this->x2FeaSrefUix = x2FeaSrefUix;
	this->srefsIxMsdcWAccess = srefsIxMsdcWAccess;
	this->titsIxMsdcWAccess = titsIxMsdcWAccess;
};

bool MsdcQUsgAAccess::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "MsdcQUsgAAccess");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "srefX1IxMsdcVFeatgroup", "feg", srefX1IxMsdcVFeatgroup);
		extractStringUclc(docctx, basexpath, "titX1IxMsdcVFeatgroup", "feg2", titX1IxMsdcVFeatgroup);
		extractStringUclc(docctx, basexpath, "x2FeaSrefUix", "fea", x2FeaSrefUix);
		extractStringUclc(docctx, basexpath, "srefsIxMsdcWAccess", "acc", srefsIxMsdcWAccess);
		extractStringUclc(docctx, basexpath, "titsIxMsdcWAccess", "acc2", titsIxMsdcWAccess);
	};

	return basefound;
};

/******************************************************************************
 class ListMsdcQUsgAAccess
 ******************************************************************************/

ListMsdcQUsgAAccess::ListMsdcQUsgAAccess() {
};

ListMsdcQUsgAAccess::ListMsdcQUsgAAccess(
			const ListMsdcQUsgAAccess& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new MsdcQUsgAAccess(*(src.nodes[i]));
};

ListMsdcQUsgAAccess& ListMsdcQUsgAAccess::operator=(
			const ListMsdcQUsgAAccess& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new MsdcQUsgAAccess(*(src.nodes[i]));

	return *this;
};

ListMsdcQUsgAAccess::~ListMsdcQUsgAAccess() {
	clear();
};

void ListMsdcQUsgAAccess::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListMsdcQUsgAAccess::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	MsdcQUsgAAccess* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListMsdcQUsgAAccess");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "MsdcQUsgAAccess", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new MsdcQUsgAAccess(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/MsdcQUsgAAccess[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

