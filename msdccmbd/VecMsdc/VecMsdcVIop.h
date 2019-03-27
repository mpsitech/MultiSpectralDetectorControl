/**
  * \file VecMsdcVIop.h
  * vector VecMsdcVIop (declarations)
  * \author Alexander Wirthmueller
  * \date created: 18 Dec 2018
  * \date modified: 18 Dec 2018
  */

#ifndef VECMSDCVIOP_H
#define VECMSDCVIOP_H

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
	* VecMsdcVIop
	*/
namespace VecMsdcVIop {
	const uint INS = 1;
	const uint RETR = 2;
	const uint RETRINS = 3;
	const uint RETRUPD = 4;
	const uint RMV = 5;

	uint getIx(const string& sref);
	string getSref(const uint ix);

	string getTitle(const uint ix, const uint ixMsdcVLocale);

	void fillFeed(const uint ixMsdcVLocale, Feed& feed);
};

#endif

