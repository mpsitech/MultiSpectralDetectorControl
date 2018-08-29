/**
  * \file VecMsdcVSqrgrp.h
  * vector VecMsdcVSqrgrp (declarations)
  * \author Alexander Wirthmueller
  * \date created: 29 Aug 2018
  * \date modified: 29 Aug 2018
  */

#ifndef VECMSDCVSQRGRP_H
#define VECMSDCVSQRGRP_H

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
	* VecMsdcVSqrgrp
	*/
namespace VecMsdcVSqrgrp {
	const uint R0 = 1;
	const uint R1 = 2;
	const uint R2 = 3;
	const uint R3 = 4;
	const uint S0 = 5;
	const uint S1 = 6;
	const uint S2 = 7;
	const uint S3 = 8;

	uint getIx(const string& sref);
	string getSref(const uint ix);

	void appendToFeed(const uint ix, Feed& feed);
	void fillFeed(Feed& feed);
};

#endif

