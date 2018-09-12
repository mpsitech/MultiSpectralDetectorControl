/**
  * \file MsdcQUsrList.cpp
  * API code for table TblMsdcQUsrList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 12 Sep 2018
  * \date modified: 12 Sep 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "MsdcQUsrList.h"

/******************************************************************************
 class MsdcQUsrList
 ******************************************************************************/

MsdcQUsrList::MsdcQUsrList(
			const uint jnum
			, const string stubRefMsdcMPerson
			, const string sref
			, const string stubRefMsdcMUsergroup
			, const string srefIxVState
			, const string titIxVState
			, const string srefIxMsdcVLocale
			, const string titIxMsdcVLocale
			, const string srefIxMsdcVUserlevel
			, const string titIxMsdcVUserlevel
		) {
	this->jnum = jnum;
	this->stubRefMsdcMPerson = stubRefMsdcMPerson;
	this->sref = sref;
	this->stubRefMsdcMUsergroup = stubRefMsdcMUsergroup;
	this->srefIxVState = srefIxVState;
	this->titIxVState = titIxVState;
	this->srefIxMsdcVLocale = srefIxMsdcVLocale;
	this->titIxMsdcVLocale = titIxMsdcVLocale;
	this->srefIxMsdcVUserlevel = srefIxMsdcVUserlevel;
	this->titIxMsdcVUserlevel = titIxMsdcVUserlevel;
};

bool MsdcQUsrList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "MsdcQUsrList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRefMsdcMPerson", "prs", stubRefMsdcMPerson);
		extractStringUclc(docctx, basexpath, "sref", "srf", sref);
		extractStringUclc(docctx, basexpath, "stubRefMsdcMUsergroup", "usg", stubRefMsdcMUsergroup);
		extractStringUclc(docctx, basexpath, "srefIxVState", "ste", srefIxVState);
		extractStringUclc(docctx, basexpath, "titIxVState", "ste2", titIxVState);
		extractStringUclc(docctx, basexpath, "srefIxMsdcVLocale", "lcl", srefIxMsdcVLocale);
		extractStringUclc(docctx, basexpath, "titIxMsdcVLocale", "lcl2", titIxMsdcVLocale);
		extractStringUclc(docctx, basexpath, "srefIxMsdcVUserlevel", "ulv", srefIxMsdcVUserlevel);
		extractStringUclc(docctx, basexpath, "titIxMsdcVUserlevel", "ulv2", titIxMsdcVUserlevel);
	};

	return basefound;
};

/******************************************************************************
 class ListMsdcQUsrList
 ******************************************************************************/

ListMsdcQUsrList::ListMsdcQUsrList() {
};

ListMsdcQUsrList::ListMsdcQUsrList(
			const ListMsdcQUsrList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new MsdcQUsrList(*(src.nodes[i]));
};

ListMsdcQUsrList& ListMsdcQUsrList::operator=(
			const ListMsdcQUsrList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new MsdcQUsrList(*(src.nodes[i]));

	return *this;
};

ListMsdcQUsrList::~ListMsdcQUsrList() {
	clear();
};

void ListMsdcQUsrList::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListMsdcQUsrList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	MsdcQUsrList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListMsdcQUsrList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "MsdcQUsrList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new MsdcQUsrList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/MsdcQUsrList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

