/**
  * \file MsdcQPrdList.h
  * API code for table TblMsdcQPrdList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 12 Sep 2018
  * \date modified: 12 Sep 2018
  */

#ifndef MSDCQPRDLIST_H
#define MSDCQPRDLIST_H

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * MsdcQPrdList
  */
class MsdcQPrdList {

public:
	MsdcQPrdList(const uint jnum = 0, const string ftmStart = "", const string ftmStop = "");

public:
	uint jnum;
	string ftmStart;
	string ftmStop;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListMsdcQPrdList
  */
class ListMsdcQPrdList {

public:
	ListMsdcQPrdList();
	ListMsdcQPrdList(const ListMsdcQPrdList& src);
	ListMsdcQPrdList& operator=(const ListMsdcQPrdList& src);
	~ListMsdcQPrdList();

	void clear();

public:
	vector<MsdcQPrdList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

