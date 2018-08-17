/**
  * \file MsdcQUsrAAccess.h
  * API code for table TblMsdcQUsrAAccess (declarations)
  * \author Alexander Wirthmueller
  * \date created: 15 Aug 2018
  * \date modified: 15 Aug 2018
  */

#ifndef MSDCQUSRAACCESS_H
#define MSDCQUSRAACCESS_H

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * MsdcQUsrAAccess
  */
class MsdcQUsrAAccess {

public:
	MsdcQUsrAAccess(const uint jnum = 0, const string srefX1IxMsdcVFeatgroup = "", const string titX1IxMsdcVFeatgroup = "", const string x2FeaSrefUix = "", const string srefsIxMsdcWAccess = "", const string titsIxMsdcWAccess = "");

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
  * ListMsdcQUsrAAccess
  */
class ListMsdcQUsrAAccess {

public:
	ListMsdcQUsrAAccess();
	ListMsdcQUsrAAccess(const ListMsdcQUsrAAccess& src);
	ListMsdcQUsrAAccess& operator=(const ListMsdcQUsrAAccess& src);
	~ListMsdcQUsrAAccess();

	void clear();

public:
	vector<MsdcQUsrAAccess*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

