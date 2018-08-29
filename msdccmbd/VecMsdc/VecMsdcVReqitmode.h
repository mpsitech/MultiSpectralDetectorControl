/**
  * \file VecMsdcVReqitmode.h
  * vector VecMsdcVReqitmode (declarations)
  * \author Alexander Wirthmueller
  * \date created: 29 Aug 2018
  * \date modified: 29 Aug 2018
  */

#ifndef VECMSDCVREQITMODE_H
#define VECMSDCVREQITMODE_H

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
	* VecMsdcVReqitmode
	*/
namespace VecMsdcVReqitmode {
	const uint IDLE = 1;
	const uint NOTIFY = 2;
	const uint POLL = 3;

	uint getIx(const string& sref);
	string getSref(const uint ix);
};

#endif

