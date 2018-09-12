/**
  * \file MsdcQUsgList.h
  * API code for table TblMsdcQUsgList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 12 Sep 2018
  * \date modified: 12 Sep 2018
  */

#ifndef MSDCQUSGLIST_H
#define MSDCQUSGLIST_H

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * MsdcQUsgList
  */
class MsdcQUsgList {

public:
	MsdcQUsgList(const uint jnum = 0, const string sref = "");

public:
	uint jnum;
	string sref;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListMsdcQUsgList
  */
class ListMsdcQUsgList {

public:
	ListMsdcQUsgList();
	ListMsdcQUsgList(const ListMsdcQUsgList& src);
	ListMsdcQUsgList& operator=(const ListMsdcQUsgList& src);
	~ListMsdcQUsgList();

	void clear();

public:
	vector<MsdcQUsgList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

