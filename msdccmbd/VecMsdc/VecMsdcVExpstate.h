/**
  * \file VecMsdcVExpstate.h
  * vector VecMsdcVExpstate (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Oct 2018
  * \date modified: 4 Oct 2018
  */

#ifndef VECMSDCVEXPSTATE_H
#define VECMSDCVEXPSTATE_H

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
	* VecMsdcVExpstate
	*/
namespace VecMsdcVExpstate {
	const uint DETD = 1;
	const uint MAXD = 2;
	const uint MIND = 3;
	const uint REGD = 4;

	uint getIx(const string& sref);
	string getSref(const uint ix);
};

#endif

