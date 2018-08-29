/**
  * \file VecMsdcVOppack.h
  * vector VecMsdcVOppack (declarations)
  * \author Alexander Wirthmueller
  * \date created: 29 Aug 2018
  * \date modified: 29 Aug 2018
  */

#ifndef VECMSDCVOPPACK_H
#define VECMSDCVOPPACK_H

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
	* VecMsdcVOppack
	*/
namespace VecMsdcVOppack {

	uint getIx(const string& sref);
	string getSref(const uint ix);

	string getTitle(const uint ix);
	string getComment(const uint ix);

	void appendToFeed(const uint ix, Feed& feed);
	void fillFeed(Feed& feed);
};

#endif

