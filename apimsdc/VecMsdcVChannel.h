/**
  * \file VecMsdcVChannel.h
  * vector VecMsdcVChannel (declarations)
  * \author Alexander Wirthmueller
  * \date created: 18 Dec 2018
  * \date modified: 18 Dec 2018
  */

#ifndef VECMSDCVCHANNEL_H
#define VECMSDCVCHANNEL_H

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
	* VecMsdcVChannel
	*/
namespace VecMsdcVChannel {
	const uint RED8 = 1;
	const uint GREEN8 = 2;
	const uint BLUE8 = 3;
	const uint RGBX32 = 4;
	const uint GRAY8 = 5;
	const uint GRAY16 = 6;

	uint getIx(const string& sref);
	string getSref(const uint ix);
};

#endif

