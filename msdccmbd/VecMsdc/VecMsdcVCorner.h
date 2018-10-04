/**
  * \file VecMsdcVCorner.h
  * vector VecMsdcVCorner (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Oct 2018
  * \date modified: 4 Oct 2018
  */

#ifndef VECMSDCVCORNER_H
#define VECMSDCVCORNER_H

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
	* VecMsdcVCorner
	*/
namespace VecMsdcVCorner {
	const uint N = 1;
	const uint NE = 2;
	const uint E = 3;
	const uint SE = 4;
	const uint S = 5;
	const uint SW = 6;
	const uint W = 7;
	const uint NW = 8;

	uint getIx(const string& sref);
	string getSref(const uint ix);
};

#endif

