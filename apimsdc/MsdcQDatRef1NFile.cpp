/**
  * \file MsdcQDatRef1NFile.cpp
  * API code for table TblMsdcQDatRef1NFile (implementation)
  * \author Alexander Wirthmueller
  * \date created: 12 Sep 2018
  * \date modified: 12 Sep 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "MsdcQDatRef1NFile.h"

/******************************************************************************
 class MsdcQDatRef1NFile
 ******************************************************************************/

MsdcQDatRef1NFile::MsdcQDatRef1NFile(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool MsdcQDatRef1NFile::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "MsdcQDatRef1NFile");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListMsdcQDatRef1NFile
 ******************************************************************************/

ListMsdcQDatRef1NFile::ListMsdcQDatRef1NFile() {
};

ListMsdcQDatRef1NFile::ListMsdcQDatRef1NFile(
			const ListMsdcQDatRef1NFile& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new MsdcQDatRef1NFile(*(src.nodes[i]));
};

ListMsdcQDatRef1NFile& ListMsdcQDatRef1NFile::operator=(
			const ListMsdcQDatRef1NFile& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new MsdcQDatRef1NFile(*(src.nodes[i]));

	return *this;
};

ListMsdcQDatRef1NFile::~ListMsdcQDatRef1NFile() {
	clear();
};

void ListMsdcQDatRef1NFile::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListMsdcQDatRef1NFile::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	MsdcQDatRef1NFile* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListMsdcQDatRef1NFile");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "MsdcQDatRef1NFile", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new MsdcQDatRef1NFile(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/MsdcQDatRef1NFile[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

