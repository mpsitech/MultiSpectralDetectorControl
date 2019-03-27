/**
  * \file MsdcQPrdList.cpp
  * API code for table TblMsdcQPrdList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 18 Dec 2018
  * \date modified: 18 Dec 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "MsdcQPrdList.h"

/******************************************************************************
 class MsdcQPrdList
 ******************************************************************************/

MsdcQPrdList::MsdcQPrdList(
			const uint jnum
			, const string ftmStart
			, const string ftmStop
		) {
	this->jnum = jnum;
	this->ftmStart = ftmStart;
	this->ftmStop = ftmStop;
};

bool MsdcQPrdList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "MsdcQPrdList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "ftmStart", "sta", ftmStart);
		extractStringUclc(docctx, basexpath, "ftmStop", "sto", ftmStop);
	};

	return basefound;
};

/******************************************************************************
 class ListMsdcQPrdList
 ******************************************************************************/

ListMsdcQPrdList::ListMsdcQPrdList() {
};

ListMsdcQPrdList::ListMsdcQPrdList(
			const ListMsdcQPrdList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new MsdcQPrdList(*(src.nodes[i]));
};

ListMsdcQPrdList& ListMsdcQPrdList::operator=(
			const ListMsdcQPrdList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new MsdcQPrdList(*(src.nodes[i]));

	return *this;
};

ListMsdcQPrdList::~ListMsdcQPrdList() {
	clear();
};

void ListMsdcQPrdList::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListMsdcQPrdList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	MsdcQPrdList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListMsdcQPrdList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "MsdcQPrdList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new MsdcQPrdList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/MsdcQPrdList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

