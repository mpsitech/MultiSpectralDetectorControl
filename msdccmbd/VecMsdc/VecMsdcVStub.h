/**
  * \file VecMsdcVStub.h
  * vector VecMsdcVStub (declarations)
  * \author Alexander Wirthmueller
  * \date created: 15 Aug 2018
  * \date modified: 15 Aug 2018
  */

#ifndef VECMSDCVSTUB_H
#define VECMSDCVSTUB_H

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
	* VecMsdcVStub
	*/
namespace VecMsdcVStub {
	const uint STUBMSDCDATSTD = 1;
	const uint STUBMSDCFILSTD = 2;
	const uint STUBMSDCPRDSTD = 3;
	const uint STUBMSDCPRSSTD = 4;
	const uint STUBMSDCSESMENU = 5;
	const uint STUBMSDCSESSTD = 6;
	const uint STUBMSDCOWN = 7;
	const uint STUBMSDCUSRSTD = 8;
	const uint STUBMSDCGRP = 9;
	const uint STUBMSDCUSGSTD = 10;

	uint getIx(const string& sref);
	string getSref(const uint ix);
};

#endif

