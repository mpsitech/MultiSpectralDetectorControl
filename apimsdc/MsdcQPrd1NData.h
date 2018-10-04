/**
  * \file MsdcQPrd1NData.h
  * API code for table TblMsdcQPrd1NData (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Oct 2018
  * \date modified: 4 Oct 2018
  */

#ifndef MSDCQPRD1NDATA_H
#define MSDCQPRD1NDATA_H

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * MsdcQPrd1NData
  */
class MsdcQPrd1NData {

public:
	MsdcQPrd1NData(const uint jnum = 0, const string stubRef = "");

public:
	uint jnum;
	string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListMsdcQPrd1NData
  */
class ListMsdcQPrd1NData {

public:
	ListMsdcQPrd1NData();
	ListMsdcQPrd1NData(const ListMsdcQPrd1NData& src);
	ListMsdcQPrd1NData& operator=(const ListMsdcQPrd1NData& src);
	~ListMsdcQPrd1NData();

	void clear();

public:
	vector<MsdcQPrd1NData*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

