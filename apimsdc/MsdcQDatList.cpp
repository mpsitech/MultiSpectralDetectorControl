/**
  * \file MsdcQDatList.cpp
  * API code for table TblMsdcQDatList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Oct 2018
  * \date modified: 4 Oct 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "MsdcQDatList.h"

/******************************************************************************
 class MsdcQDatList
 ******************************************************************************/

MsdcQDatList::MsdcQDatList(
			const uint jnum
			, const string srefMsdcKAcqfeat
			, const string titSrefMsdcKAcqfeat
			, const string stubRefMsdcMPeriod
			, const string ftmStart
			, const string ftmStop
		) {
	this->jnum = jnum;
	this->srefMsdcKAcqfeat = srefMsdcKAcqfeat;
	this->titSrefMsdcKAcqfeat = titSrefMsdcKAcqfeat;
	this->stubRefMsdcMPeriod = stubRefMsdcMPeriod;
	this->ftmStart = ftmStart;
	this->ftmStop = ftmStop;
};

bool MsdcQDatList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "MsdcQDatList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "srefMsdcKAcqfeat", "aft", srefMsdcKAcqfeat);
		extractStringUclc(docctx, basexpath, "titSrefMsdcKAcqfeat", "aft2", titSrefMsdcKAcqfeat);
		extractStringUclc(docctx, basexpath, "stubRefMsdcMPeriod", "prd", stubRefMsdcMPeriod);
		extractStringUclc(docctx, basexpath, "ftmStart", "sta", ftmStart);
		extractStringUclc(docctx, basexpath, "ftmStop", "sto", ftmStop);
	};

	return basefound;
};

/******************************************************************************
 class ListMsdcQDatList
 ******************************************************************************/

ListMsdcQDatList::ListMsdcQDatList() {
};

ListMsdcQDatList::ListMsdcQDatList(
			const ListMsdcQDatList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new MsdcQDatList(*(src.nodes[i]));
};

ListMsdcQDatList& ListMsdcQDatList::operator=(
			const ListMsdcQDatList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new MsdcQDatList(*(src.nodes[i]));

	return *this;
};

ListMsdcQDatList::~ListMsdcQDatList() {
	clear();
};

void ListMsdcQDatList::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListMsdcQDatList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	MsdcQDatList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListMsdcQDatList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "MsdcQDatList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new MsdcQDatList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/MsdcQDatList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

