/**
  * \file MsdcQUsgMNUser.h
  * API code for table TblMsdcQUsgMNUser (declarations)
  * \author Alexander Wirthmueller
  * \date created: 29 Aug 2018
  * \date modified: 29 Aug 2018
  */

#ifndef MSDCQUSGMNUSER_H
#define MSDCQUSGMNUSER_H

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * MsdcQUsgMNUser
  */
class MsdcQUsgMNUser {

public:
	MsdcQUsgMNUser(const uint jnum = 0, const string stubMref = "", const string srefIxMsdcVUserlevel = "", const string titIxMsdcVUserlevel = "");

public:
	uint jnum;
	string stubMref;
	string srefIxMsdcVUserlevel;
	string titIxMsdcVUserlevel;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListMsdcQUsgMNUser
  */
class ListMsdcQUsgMNUser {

public:
	ListMsdcQUsgMNUser();
	ListMsdcQUsgMNUser(const ListMsdcQUsgMNUser& src);
	ListMsdcQUsgMNUser& operator=(const ListMsdcQUsgMNUser& src);
	~ListMsdcQUsgMNUser();

	void clear();

public:
	vector<MsdcQUsgMNUser*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

