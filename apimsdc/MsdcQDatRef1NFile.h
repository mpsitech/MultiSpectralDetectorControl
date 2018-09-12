/**
  * \file MsdcQDatRef1NFile.h
  * API code for table TblMsdcQDatRef1NFile (declarations)
  * \author Alexander Wirthmueller
  * \date created: 12 Sep 2018
  * \date modified: 12 Sep 2018
  */

#ifndef MSDCQDATREF1NFILE_H
#define MSDCQDATREF1NFILE_H

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * MsdcQDatRef1NFile
  */
class MsdcQDatRef1NFile {

public:
	MsdcQDatRef1NFile(const uint jnum = 0, const string stubRef = "");

public:
	uint jnum;
	string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListMsdcQDatRef1NFile
  */
class ListMsdcQDatRef1NFile {

public:
	ListMsdcQDatRef1NFile();
	ListMsdcQDatRef1NFile(const ListMsdcQDatRef1NFile& src);
	ListMsdcQDatRef1NFile& operator=(const ListMsdcQDatRef1NFile& src);
	~ListMsdcQDatRef1NFile();

	void clear();

public:
	vector<MsdcQDatRef1NFile*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

