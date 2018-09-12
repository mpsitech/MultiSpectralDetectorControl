/**
  * \file MsdcQUsrMNUsergroup.cpp
  * API code for table TblMsdcQUsrMNUsergroup (implementation)
  * \author Alexander Wirthmueller
  * \date created: 12 Sep 2018
  * \date modified: 12 Sep 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "MsdcQUsrMNUsergroup.h"

/******************************************************************************
 class MsdcQUsrMNUsergroup
 ******************************************************************************/

MsdcQUsrMNUsergroup::MsdcQUsrMNUsergroup(
			const uint jnum
			, const string stubMref
			, const string srefIxMsdcVUserlevel
			, const string titIxMsdcVUserlevel
		) {
	this->jnum = jnum;
	this->stubMref = stubMref;
	this->srefIxMsdcVUserlevel = srefIxMsdcVUserlevel;
	this->titIxMsdcVUserlevel = titIxMsdcVUserlevel;
};

bool MsdcQUsrMNUsergroup::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "MsdcQUsrMNUsergroup");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubMref", "mref", stubMref);
		extractStringUclc(docctx, basexpath, "srefIxMsdcVUserlevel", "ulv", srefIxMsdcVUserlevel);
		extractStringUclc(docctx, basexpath, "titIxMsdcVUserlevel", "ulv2", titIxMsdcVUserlevel);
	};

	return basefound;
};

/******************************************************************************
 class ListMsdcQUsrMNUsergroup
 ******************************************************************************/

ListMsdcQUsrMNUsergroup::ListMsdcQUsrMNUsergroup() {
};

ListMsdcQUsrMNUsergroup::ListMsdcQUsrMNUsergroup(
			const ListMsdcQUsrMNUsergroup& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new MsdcQUsrMNUsergroup(*(src.nodes[i]));
};

ListMsdcQUsrMNUsergroup& ListMsdcQUsrMNUsergroup::operator=(
			const ListMsdcQUsrMNUsergroup& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new MsdcQUsrMNUsergroup(*(src.nodes[i]));

	return *this;
};

ListMsdcQUsrMNUsergroup::~ListMsdcQUsrMNUsergroup() {
	clear();
};

void ListMsdcQUsrMNUsergroup::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListMsdcQUsrMNUsergroup::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	MsdcQUsrMNUsergroup* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListMsdcQUsrMNUsergroup");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "MsdcQUsrMNUsergroup", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new MsdcQUsrMNUsergroup(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/MsdcQUsrMNUsergroup[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

