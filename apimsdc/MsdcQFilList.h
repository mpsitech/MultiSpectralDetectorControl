/**
  * \file MsdcQFilList.h
  * API code for table TblMsdcQFilList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 12 Sep 2018
  * \date modified: 12 Sep 2018
  */

#ifndef MSDCQFILLIST_H
#define MSDCQFILLIST_H

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * MsdcQFilList
  */
class MsdcQFilList {

public:
	MsdcQFilList(const uint jnum = 0, const string Filename = "", const string srefRefIxVTbl = "", const string titRefIxVTbl = "", const string stubRefUref = "", const string osrefKContent = "", const string titOsrefKContent = "", const string srefKMimetype = "", const string titSrefKMimetype = "", const usmallint Size = 0);

public:
	uint jnum;
	string Filename;
	string srefRefIxVTbl;
	string titRefIxVTbl;
	string stubRefUref;
	string osrefKContent;
	string titOsrefKContent;
	string srefKMimetype;
	string titSrefKMimetype;
	usmallint Size;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListMsdcQFilList
  */
class ListMsdcQFilList {

public:
	ListMsdcQFilList();
	ListMsdcQFilList(const ListMsdcQFilList& src);
	ListMsdcQFilList& operator=(const ListMsdcQFilList& src);
	~ListMsdcQFilList();

	void clear();

public:
	vector<MsdcQFilList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

