/**
  * \file MsdcQDatList.h
  * API code for table TblMsdcQDatList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 12 Sep 2018
  * \date modified: 12 Sep 2018
  */

#ifndef MSDCQDATLIST_H
#define MSDCQDATLIST_H

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * MsdcQDatList
  */
class MsdcQDatList {

public:
	MsdcQDatList(const uint jnum = 0, const string srefMsdcKAcqfeat = "", const string titSrefMsdcKAcqfeat = "", const string stubRefMsdcMPeriod = "", const string ftmStart = "", const string ftmStop = "");

public:
	uint jnum;
	string srefMsdcKAcqfeat;
	string titSrefMsdcKAcqfeat;
	string stubRefMsdcMPeriod;
	string ftmStart;
	string ftmStop;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListMsdcQDatList
  */
class ListMsdcQDatList {

public:
	ListMsdcQDatList();
	ListMsdcQDatList(const ListMsdcQDatList& src);
	ListMsdcQDatList& operator=(const ListMsdcQDatList& src);
	~ListMsdcQDatList();

	void clear();

public:
	vector<MsdcQDatList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

