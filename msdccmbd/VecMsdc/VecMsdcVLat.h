/**
  * \file VecMsdcVLat.h
  * vector VecMsdcVLat (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Oct 2018
  * \date modified: 4 Oct 2018
  */

#ifndef VECMSDCVLAT_H
#define VECMSDCVLAT_H

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
	* VecMsdcVLat
	*/
namespace VecMsdcVLat {
	const uint DLO = 1;
	const uint INI = 2;

	uint getIx(const string& sref);
	string getSref(const uint ix);
};

#endif

