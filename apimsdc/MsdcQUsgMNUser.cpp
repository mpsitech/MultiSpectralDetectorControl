/**
  * \file MsdcQUsgMNUser.cpp
  * API code for table TblMsdcQUsgMNUser (implementation)
  * \author Alexander Wirthmueller
  * \date created: 12 Sep 2018
  * \date modified: 12 Sep 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "MsdcQUsgMNUser.h"

/******************************************************************************
 class MsdcQUsgMNUser
 ******************************************************************************/

MsdcQUsgMNUser::MsdcQUsgMNUser(
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

bool MsdcQUsgMNUser::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "MsdcQUsgMNUser");
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
 class ListMsdcQUsgMNUser
 ******************************************************************************/

ListMsdcQUsgMNUser::ListMsdcQUsgMNUser() {
};

ListMsdcQUsgMNUser::ListMsdcQUsgMNUser(
			const ListMsdcQUsgMNUser& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new MsdcQUsgMNUser(*(src.nodes[i]));
};

ListMsdcQUsgMNUser& ListMsdcQUsgMNUser::operator=(
			const ListMsdcQUsgMNUser& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new MsdcQUsgMNUser(*(src.nodes[i]));

	return *this;
};

ListMsdcQUsgMNUser::~ListMsdcQUsgMNUser() {
	clear();
};

void ListMsdcQUsgMNUser::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListMsdcQUsgMNUser::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	MsdcQUsgMNUser* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListMsdcQUsgMNUser");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "MsdcQUsgMNUser", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new MsdcQUsgMNUser(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/MsdcQUsgMNUser[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

