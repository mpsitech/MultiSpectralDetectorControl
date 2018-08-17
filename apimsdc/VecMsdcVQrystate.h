/**
  * \file VecMsdcVQrystate.h
  * vector VecMsdcVQrystate (declarations)
  * \author Alexander Wirthmueller
  * \date created: 15 Aug 2018
  * \date modified: 15 Aug 2018
  */

#ifndef VECMSDCVQRYSTATE_H
#define VECMSDCVQRYSTATE_H

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
	* VecMsdcVQrystate
	*/
namespace VecMsdcVQrystate {
	const uint MNR = 1;
	const uint OOD = 2;
	const uint SLM = 3;
	const uint UTD = 4;

	uint getIx(const string& sref);
	string getSref(const uint ix);
};

#endif

