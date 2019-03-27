/**
  * \file MsdcQUsr1NSession.h
  * API code for table TblMsdcQUsr1NSession (declarations)
  * \author Alexander Wirthmueller
  * \date created: 18 Dec 2018
  * \date modified: 18 Dec 2018
  */

#ifndef MSDCQUSR1NSESSION_H
#define MSDCQUSR1NSESSION_H

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * MsdcQUsr1NSession
  */
class MsdcQUsr1NSession {

public:
	MsdcQUsr1NSession(const uint jnum = 0, const string stubRef = "");

public:
	uint jnum;
	string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListMsdcQUsr1NSession
  */
class ListMsdcQUsr1NSession {

public:
	ListMsdcQUsr1NSession();
	ListMsdcQUsr1NSession(const ListMsdcQUsr1NSession& src);
	ListMsdcQUsr1NSession& operator=(const ListMsdcQUsr1NSession& src);
	~ListMsdcQUsr1NSession();

	void clear();

public:
	vector<MsdcQUsr1NSession*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

