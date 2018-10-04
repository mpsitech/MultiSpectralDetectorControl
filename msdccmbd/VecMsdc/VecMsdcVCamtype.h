/**
  * \file VecMsdcVCamtype.h
  * vector VecMsdcVCamtype (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Oct 2018
  * \date modified: 4 Oct 2018
  */

#ifndef VECMSDCVCAMTYPE_H
#define VECMSDCVCAMTYPE_H

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
	* VecMsdcVCamtype
	*/
namespace VecMsdcVCamtype {
	const uint PGBFLY = 1;
	const uint MSLIFE = 2;

	uint getIx(const string& sref);
	string getSref(const uint ix);

	string getTitle(const uint ix);

	void appendToFeed(const uint ix, Feed& feed);
	void fillFeed(Feed& feed);
};

#endif

