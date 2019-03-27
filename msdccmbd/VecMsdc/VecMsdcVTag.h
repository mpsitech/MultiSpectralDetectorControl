/**
  * \file VecMsdcVTag.h
  * vector VecMsdcVTag (declarations)
  * \author Alexander Wirthmueller
  * \date created: 18 Dec 2018
  * \date modified: 18 Dec 2018
  */

#ifndef VECMSDCVTAG_H
#define VECMSDCVTAG_H

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
	* VecMsdcVTag
	*/
namespace VecMsdcVTag {
	const uint ABOUT = 1;
	const uint ALWAYS = 2;
	const uint CANCEL = 3;
	const uint CLOSE = 4;
	const uint CLSESS = 5;
	const uint CLUST = 6;
	const uint DETAIL = 7;
	const uint DONE = 8;
	const uint DOWNLOAD = 9;
	const uint EMPLONG = 10;
	const uint EMPSHORT = 11;
	const uint ERROR = 12;
	const uint FILENAME = 13;
	const uint FLS = 14;
	const uint FOR = 15;
	const uint GENERAL = 16;
	const uint GOTO = 17;
	const uint GRP = 18;
	const uint HELP = 19;
	const uint IMPORT = 20;
	const uint LOAINI = 21;
	const uint NAV = 22;
	const uint NO = 23;
	const uint OK = 24;
	const uint OPSCPLLAST = 25;
	const uint OPSPREP = 26;
	const uint OWN = 27;
	const uint PROGRESS = 28;
	const uint QUEST = 29;
	const uint RUN = 30;
	const uint SESS = 31;
	const uint SHOWLONG = 32;
	const uint SHOWSHORT = 33;
	const uint STOP = 34;
	const uint SUSPSESS = 35;
	const uint TRU = 36;
	const uint UPLOAD = 37;
	const uint YES = 38;

	uint getIx(const string& sref);
	string getSref(const uint ix);

	string getTitle(const uint ix, const uint ixMsdcVLocale);

	void appendToFeed(const uint ix, const uint ixMsdcVLocale, Feed& feed);
};

#endif

