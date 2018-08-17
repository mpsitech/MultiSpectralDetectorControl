/**
  * \file MsdcQUsrList.h
  * API code for table TblMsdcQUsrList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 15 Aug 2018
  * \date modified: 15 Aug 2018
  */

#ifndef MSDCQUSRLIST_H
#define MSDCQUSRLIST_H

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * MsdcQUsrList
  */
class MsdcQUsrList {

public:
	MsdcQUsrList(const uint jnum = 0, const string stubRefMsdcMPerson = "", const string sref = "", const string stubRefMsdcMUsergroup = "", const string srefIxVState = "", const string titIxVState = "", const string srefIxMsdcVLocale = "", const string titIxMsdcVLocale = "", const string srefIxMsdcVUserlevel = "", const string titIxMsdcVUserlevel = "");

public:
	uint jnum;
	string stubRefMsdcMPerson;
	string sref;
	string stubRefMsdcMUsergroup;
	string srefIxVState;
	string titIxVState;
	string srefIxMsdcVLocale;
	string titIxMsdcVLocale;
	string srefIxMsdcVUserlevel;
	string titIxMsdcVUserlevel;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListMsdcQUsrList
  */
class ListMsdcQUsrList {

public:
	ListMsdcQUsrList();
	ListMsdcQUsrList(const ListMsdcQUsrList& src);
	ListMsdcQUsrList& operator=(const ListMsdcQUsrList& src);
	~ListMsdcQUsrList();

	void clear();

public:
	vector<MsdcQUsrList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

