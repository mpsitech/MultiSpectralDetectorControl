/**
  * \file MsdcQDatAPar.cpp
  * API code for table TblMsdcQDatAPar (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Oct 2018
  * \date modified: 4 Oct 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "MsdcQDatAPar.h"

/******************************************************************************
 class MsdcQDatAPar
 ******************************************************************************/

MsdcQDatAPar::MsdcQDatAPar(
			const uint jnum
			, const string ftmX1Start
			, const string x2SrefKKey
			, const string titX2SrefKKey
			, const string stubRefMsdcMFile
			, const string Val
			, const string Bindata
		) {
	this->jnum = jnum;
	this->ftmX1Start = ftmX1Start;
	this->x2SrefKKey = x2SrefKKey;
	this->titX2SrefKKey = titX2SrefKKey;
	this->stubRefMsdcMFile = stubRefMsdcMFile;
	this->Val = Val;
	this->Bindata = Bindata;
};

bool MsdcQDatAPar::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "MsdcQDatAPar");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "ftmX1Start", "sta", ftmX1Start);
		extractStringUclc(docctx, basexpath, "x2SrefKKey", "key", x2SrefKKey);
		extractStringUclc(docctx, basexpath, "titX2SrefKKey", "key2", titX2SrefKKey);
		extractStringUclc(docctx, basexpath, "stubRefMsdcMFile", "fil", stubRefMsdcMFile);
		extractStringUclc(docctx, basexpath, "Val", "val", Val);
		extractStringUclc(docctx, basexpath, "Bindata", "bin", Bindata);
	};

	return basefound;
};

/******************************************************************************
 class ListMsdcQDatAPar
 ******************************************************************************/

ListMsdcQDatAPar::ListMsdcQDatAPar() {
};

ListMsdcQDatAPar::ListMsdcQDatAPar(
			const ListMsdcQDatAPar& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new MsdcQDatAPar(*(src.nodes[i]));
};

ListMsdcQDatAPar& ListMsdcQDatAPar::operator=(
			const ListMsdcQDatAPar& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new MsdcQDatAPar(*(src.nodes[i]));

	return *this;
};

ListMsdcQDatAPar::~ListMsdcQDatAPar() {
	clear();
};

void ListMsdcQDatAPar::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListMsdcQDatAPar::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	MsdcQDatAPar* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListMsdcQDatAPar");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "MsdcQDatAPar", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i=0;i<ics.size();i++) {
		rec = new MsdcQDatAPar(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/MsdcQDatAPar[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

