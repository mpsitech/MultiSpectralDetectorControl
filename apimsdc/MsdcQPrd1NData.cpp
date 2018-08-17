/**
  * \file MsdcQPrd1NData.cpp
  * API code for table TblMsdcQPrd1NData (implementation)
  * \author Alexander Wirthmueller
  * \date created: 15 Aug 2018
  * \date modified: 15 Aug 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "MsdcQPrd1NData.h"

/******************************************************************************
 class MsdcQPrd1NData
 ******************************************************************************/

MsdcQPrd1NData::MsdcQPrd1NData(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool MsdcQPrd1NData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "MsdcQPrd1NData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListMsdcQPrd1NData
 ******************************************************************************/

ListMsdcQPrd1NData::ListMsdcQPrd1NData() {
};

ListMsdcQPrd1NData::ListMsdcQPrd1NData(
			const ListMsdcQPrd1NData& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new MsdcQPrd1NData(*(src.nodes[i]));
};

ListMsdcQPrd1NData& ListMsdcQPrd1NData::operator=(
			const ListMsdcQPrd1NData& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new MsdcQPrd1NData(*(src.nodes[i]));

	return *this;
};

ListMsdcQPrd1NData::~ListMsdcQPrd1NData() {
	clear();
};

void ListMsdcQPrd1NData::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListMsdcQPrd1NData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	MsdcQPrd1NData* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListMsdcQPrd1NData");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "MsdcQPrd1NData", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new MsdcQPrd1NData(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/MsdcQPrd1NData[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

