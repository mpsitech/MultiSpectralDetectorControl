/**
  * \file VecMsdcVOpengtype.h
  * vector VecMsdcVOpengtype (declarations)
  * \author Alexander Wirthmueller
  * \date created: 29 Aug 2018
  * \date modified: 29 Aug 2018
  */

#ifndef VECMSDCVOPENGTYPE_H
#define VECMSDCVOPENGTYPE_H

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
	* VecMsdcVOpengtype
	*/
namespace VecMsdcVOpengtype {

	uint getIx(const string& sref);
	string getSref(const uint ix);

	string getTitle(const uint ix, const uint ixMsdcVLocale);

	void appendToFeed(const uint ix, const uint ixMsdcVLocale, Feed& feed);
	void fillFeed(const uint ixMsdcVLocale, Feed& feed);
};

#endif

