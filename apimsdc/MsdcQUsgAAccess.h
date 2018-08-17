/**
  * \file MsdcQUsgAAccess.h
  * API code for table TblMsdcQUsgAAccess (declarations)
  * \author Alexander Wirthmueller
  * \date created: 15 Aug 2018
  * \date modified: 15 Aug 2018
  */

#ifndef MSDCQUSGAACCESS_H
#define MSDCQUSGAACCESS_H

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * MsdcQUsgAAccess
  */
class MsdcQUsgAAccess {

public:
	MsdcQUsgAAccess(const uint jnum = 0, const string srefX1IxMsdcVFeatgroup = "", const string titX1IxMsdcVFeatgroup = "", const string x2FeaSrefUix = "", const string srefsIxMsdcWAccess = "", const string titsIxMsdcWAccess = "");

public:
	uint jnum;
	string srefX1IxMsdcVFeatgroup;
	string titX1IxMsdcVFeatgroup;
	string x2FeaSrefUix;
	string srefsIxMsdcWAccess;
	string titsIxMsdcWAccess;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListMsdcQUsgAAccess
  */
class ListMsdcQUsgAAccess {

public:
	ListMsdcQUsgAAccess();
	ListMsdcQUsgAAccess(const ListMsdcQUsgAAccess& src);
	ListMsdcQUsgAAccess& operator=(const ListMsdcQUsgAAccess& src);
	~ListMsdcQUsgAAccess();

	void clear();

public:
	vector<MsdcQUsgAAccess*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

