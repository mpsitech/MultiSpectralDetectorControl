/**
  * \file MsdcQPrsList.h
  * API code for table TblMsdcQPrsList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Oct 2018
  * \date modified: 4 Oct 2018
  */

#ifndef MSDCQPRSLIST_H
#define MSDCQPRSLIST_H

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * MsdcQPrsList
  */
class MsdcQPrsList {

public:
	MsdcQPrsList(const uint jnum = 0, const string Title = "", const string Firstname = "", const string Lastname = "", const string stubGrp = "", const string stubOwn = "", const string srefIxVSex = "", const string titIxVSex = "", const string telVal = "", const string emlVal = "");

public:
	uint jnum;
	string Title;
	string Firstname;
	string Lastname;
	string stubGrp;
	string stubOwn;
	string srefIxVSex;
	string titIxVSex;
	string telVal;
	string emlVal;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListMsdcQPrsList
  */
class ListMsdcQPrsList {

public:
	ListMsdcQPrsList();
	ListMsdcQPrsList(const ListMsdcQPrsList& src);
	ListMsdcQPrsList& operator=(const ListMsdcQPrsList& src);
	~ListMsdcQPrsList();

	void clear();

public:
	vector<MsdcQPrsList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

