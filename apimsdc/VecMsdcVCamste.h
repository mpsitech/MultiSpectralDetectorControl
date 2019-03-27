/**
  * \file VecMsdcVCamste.h
  * vector VecMsdcVCamste (declarations)
  * \author Alexander Wirthmueller
  * \date created: 18 Dec 2018
  * \date modified: 18 Dec 2018
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
};

#endif

