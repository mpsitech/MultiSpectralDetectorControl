/**
  * \file VecMsdcVLop.h
  * vector VecMsdcVLop (declarations)
  * \author Alexander Wirthmueller
  * \date created: 15 Aug 2018
  * \date modified: 15 Aug 2018
  */

#ifndef VECMSDCVLOP_H
#define VECMSDCVLOP_H

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
	* VecMsdcVLop
	*/
namespace VecMsdcVLop {
	const uint INS = 1;
	const uint RMV = 2;

	uint getIx(const string& sref);
	string getSref(const uint ix);
};

#endif

