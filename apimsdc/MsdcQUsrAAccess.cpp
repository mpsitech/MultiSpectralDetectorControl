/**
  * \file MsdcQUsrAAccess.cpp
  * API code for table TblMsdcQUsrAAccess (implementation)
  * \author Alexander Wirthmueller
  * \date created: 15 Aug 2018
  * \date modified: 15 Aug 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "MsdcQUsrAAccess.h"

/******************************************************************************
 class MsdcQUsrAAccess
 ******************************************************************************/

MsdcQUsrAAccess::MsdcQUsrAAccess(
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

bool MsdcQUsrAAccess::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "MsdcQUsrAAccess");
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
 class ListMsdcQUsrAAccess
 ******************************************************************************/

ListMsdcQUsrAAccess::ListMsdcQUsrAAccess() {
};

ListMsdcQUsrAAccess::ListMsdcQUsrAAccess(
			const ListMsdcQUsrAAccess& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new MsdcQUsrAAccess(*(src.nodes[i]));
};

ListMsdcQUsrAAccess& ListMsdcQUsrAAccess::operator=(
			const ListMsdcQUsrAAccess& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new MsdcQUsrAAccess(*(src.nodes[i]));

	return *this;
};

ListMsdcQUsrAAccess::~ListMsdcQUsrAAccess() {
	clear();
};

void ListMsdcQUsrAAccess::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListMsdcQUsrAAccess::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	MsdcQUsrAAccess* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListMsdcQUsrAAccess");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "MsdcQUsrAAccess", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new MsdcQUsrAAccess(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/MsdcQUsrAAccess[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

