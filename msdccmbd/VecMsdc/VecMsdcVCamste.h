/**
  * \file VecMsdcVCamste.h
  * vector VecMsdcVCamste (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Oct 2018
  * \date modified: 4 Oct 2018
  */

#ifndef VECMSDCVCAMSTE_H
#define VECMSDCVCAMSTE_H

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
	* VecMsdcVCamste
	*/
namespace VecMsdcVCamste {
	const uint NC = 1;
	const uint READY = 2;
	const uint ACTIVE = 3;

	uint getIx(const string& sref);
	string getSref(const uint ix);

	string getTitle(const uint ix, const uint ixMsdcVLocale);

	void appendToFeed(const uint ix, const uint ixMsdcVLocale, Feed& feed);
	void fillFeed(const uint ixMsdcVLocale, Feed& feed);
};

#endif

