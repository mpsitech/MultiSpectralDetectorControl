/**
  * \file VecMsdcVCamres.h
  * vector VecMsdcVCamres (declarations)
  * \author Alexander Wirthmueller
  * \date created: 18 Dec 2018
  * \date modified: 18 Dec 2018
  */

#ifndef VECMSDCVCAMRES_H
#define VECMSDCVCAMRES_H

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
	* VecMsdcVCamres
	*/
namespace VecMsdcVCamres {
	const uint OFF = 1;
	const uint _160 = 2;
	const uint _320 = 3;
	const uint _640 = 4;
	const uint _800 = 5;
	const uint _1024 = 6;
	const uint _1280 = 7;
	const uint _720P = 8;
	const uint _1080P = 9;
	const uint MAX = 10;

	uint getIx(const string& sref);
	string getSref(const uint ix);
};

#endif

