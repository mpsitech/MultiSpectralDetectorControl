/**
  * \file MsdcQDatAPar.h
  * API code for table TblMsdcQDatAPar (declarations)
  * \author Alexander Wirthmueller
  * \date created: 15 Aug 2018
  * \date modified: 15 Aug 2018
  */

#ifndef MSDCQDATAPAR_H
#define MSDCQDATAPAR_H

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * MsdcQDatAPar
  */
class MsdcQDatAPar {

public:
	MsdcQDatAPar(const uint jnum = 0, const string ftmX1Start = "", const string x2SrefKKey = "", const string titX2SrefKKey = "", const string stubRefMsdcMFile = "", const string Val = "", const string Bindata = "");

public:
	uint jnum;
	string ftmX1Start;
	string x2SrefKKey;
	string titX2SrefKKey;
	string stubRefMsdcMFile;
	string Val;
	string Bindata;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListMsdcQDatAPar
  */
class ListMsdcQDatAPar {

public:
	ListMsdcQDatAPar();
	ListMsdcQDatAPar(const ListMsdcQDatAPar& src);
	ListMsdcQDatAPar& operator=(const ListMsdcQDatAPar& src);
	~ListMsdcQDatAPar();

	void clear();

public:
	vector<MsdcQDatAPar*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

