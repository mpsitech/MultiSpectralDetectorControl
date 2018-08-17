/**
  * \file MsdcQUsrMNUsergroup.h
  * API code for table TblMsdcQUsrMNUsergroup (declarations)
  * \author Alexander Wirthmueller
  * \date created: 15 Aug 2018
  * \date modified: 15 Aug 2018
  */

#ifndef MSDCQUSRMNUSERGROUP_H
#define MSDCQUSRMNUSERGROUP_H

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * MsdcQUsrMNUsergroup
  */
class MsdcQUsrMNUsergroup {

public:
	MsdcQUsrMNUsergroup(const uint jnum = 0, const string stubMref = "", const string srefIxMsdcVUserlevel = "", const string titIxMsdcVUserlevel = "");

public:
	uint jnum;
	string stubMref;
	string srefIxMsdcVUserlevel;
	string titIxMsdcVUserlevel;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListMsdcQUsrMNUsergroup
  */
class ListMsdcQUsrMNUsergroup {

public:
	ListMsdcQUsrMNUsergroup();
	ListMsdcQUsrMNUsergroup(const ListMsdcQUsrMNUsergroup& src);
	ListMsdcQUsrMNUsergroup& operator=(const ListMsdcQUsrMNUsergroup& src);
	~ListMsdcQUsrMNUsergroup();

	void clear();

public:
	vector<MsdcQUsrMNUsergroup*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

