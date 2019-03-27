/**
  * \file VecMsdcVCall.h
  * vector VecMsdcVCall (declarations)
  * \author Alexander Wirthmueller
  * \date created: 18 Dec 2018
  * \date modified: 18 Dec 2018
  */

#ifndef VECMSDCVCALL_H
#define VECMSDCVCALL_H

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
	* VecMsdcVCall
	*/
namespace VecMsdcVCall {
	const uint CALLMSDCACCESS = 1;
	const uint CALLMSDCBOOLVALPRESET = 2;
	const uint CALLMSDCBUFRDY = 3;
	const uint CALLMSDCCRDACTIVE = 4;
	const uint CALLMSDCCRDCLOSE = 5;
	const uint CALLMSDCCRDOPEN = 6;
	const uint CALLMSDCCTLAPARMOD_USREQ = 7;
	const uint CALLMSDCDAT_PRDEQ = 8;
	const uint CALLMSDCDATAPARMOD_DATEQ = 9;
	const uint CALLMSDCDATMOD = 10;
	const uint CALLMSDCDATMOD_PRDEQ = 11;
	const uint CALLMSDCDATUPD_REFEQ = 12;
	const uint CALLMSDCDBLVALPRESET = 13;
	const uint CALLMSDCDLGCLOSE = 14;
	const uint CALLMSDCFIL_CLUEQ = 15;
	const uint CALLMSDCFIL_RETEQ = 16;
	const uint CALLMSDCFIL_REUEQ = 17;
	const uint CALLMSDCFILMOD = 18;
	const uint CALLMSDCFILMOD_CLUEQ = 19;
	const uint CALLMSDCFILMOD_RETREUEQ = 20;
	const uint CALLMSDCFILUPD_REFEQ = 21;
	const uint CALLMSDCHUSRRUNVMOD_CRDUSREQ = 22;
	const uint CALLMSDCIBITRDY = 23;
	const uint CALLMSDCIMGRDY = 24;
	const uint CALLMSDCINTVALPRESET = 25;
	const uint CALLMSDCIXPRESET = 26;
	const uint CALLMSDCKAKJKEYMOD_KLSAKEYEQ = 27;
	const uint CALLMSDCKLSAKEYMOD_KLSEQ = 28;
	const uint CALLMSDCKLSAKEYMOD_KLSMTBURFEQ = 29;
	const uint CALLMSDCLOG = 30;
	const uint CALLMSDCLOGOUT = 31;
	const uint CALLMSDCMASTSGECHG = 32;
	const uint CALLMSDCMASTSLVCHG = 33;
	const uint CALLMSDCMASTSRDCHG = 34;
	const uint CALLMSDCMONSTATCHG = 35;
	const uint CALLMSDCNODECHG = 36;
	const uint CALLMSDCPRDMOD = 37;
	const uint CALLMSDCPRDUPD_REFEQ = 38;
	const uint CALLMSDCPRSJLNMMOD_PRSEQ = 39;
	const uint CALLMSDCPRSMOD = 40;
	const uint CALLMSDCPRSUPD_REFEQ = 41;
	const uint CALLMSDCRECACCESS = 42;
	const uint CALLMSDCREFPRESET = 43;
	const uint CALLMSDCREFSPRESET = 44;
	const uint CALLMSDCSESMOD = 45;
	const uint CALLMSDCSESMOD_USREQ = 46;
	const uint CALLMSDCSESUPD_REFEQ = 47;
	const uint CALLMSDCSGECHG = 48;
	const uint CALLMSDCSHRDATCHG = 49;
	const uint CALLMSDCSREFPRESET = 50;
	const uint CALLMSDCSTATCHG = 51;
	const uint CALLMSDCSTGCHG = 52;
	const uint CALLMSDCSTUBCHG = 53;
	const uint CALLMSDCSUSPSESS = 54;
	const uint CALLMSDCTRIG = 55;
	const uint CALLMSDCTXTVALPRESET = 56;
	const uint CALLMSDCUSGAACCMOD_USGEQ = 57;
	const uint CALLMSDCUSGMOD = 58;
	const uint CALLMSDCUSGUPD_REFEQ = 59;
	const uint CALLMSDCUSR_PRSEQ = 60;
	const uint CALLMSDCUSR_USGEQ = 61;
	const uint CALLMSDCUSRAACCMOD_USREQ = 62;
	const uint CALLMSDCUSRJSTEMOD_USREQ = 63;
	const uint CALLMSDCUSRMOD = 64;
	const uint CALLMSDCUSRRUSGMOD_USGEQ = 65;
	const uint CALLMSDCUSRRUSGMOD_USREQ = 66;
	const uint CALLMSDCUSRUPD_REFEQ = 67;

	uint getIx(const string& sref);
	string getSref(const uint ix);
};

#endif

