/**
  * \file VecMsdcVOolop.h
  * vector VecMsdcVOolop (declarations)
  * \author Alexander Wirthmueller
  * \date created: 15 Aug 2018
  * \date modified: 15 Aug 2018
  */

#ifndef VECMSDCVOOLOP_H
#define VECMSDCVOOLOP_H

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
	* VecMsdcVOolop
	*/
namespace VecMsdcVOolop {
	const uint INA = 1;
	const uint INB = 2;
	const uint RMV = 3;
	const uint SWP = 4;
	const uint TOA = 5;
	const uint TOB = 6;

	uint getIx(const string& sref);
	string getSref(const uint ix);
};

#endif

