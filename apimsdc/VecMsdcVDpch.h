/**
  * \file VecMsdcVDpch.h
  * vector VecMsdcVDpch (declarations)
  * \author Alexander Wirthmueller
  * \date created: 15 Aug 2018
  * \date modified: 15 Aug 2018
  */

#ifndef VECMSDCVDPCH_H
#define VECMSDCVDPCH_H

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
	* VecMsdcVDpch
	*/
namespace VecMsdcVDpch {
	const uint DPCHENGDLGMSDCFILDOWNLOADDATA = 1;
	const uint DPCHENGDLGMSDCNAVLOAINIDATA = 2;
	const uint DPCHENGM2MSESSMSDCDATA = 3;
	const uint DPCHENGMSDCACK = 4;
	const uint DPCHENGMSDCALERT = 5;
	const uint DPCHENGMSDCCONFIRM = 6;
	const uint DPCHENGMSDCDATAPARDATA = 7;
	const uint DPCHENGMSDCDATDATA = 8;
	const uint DPCHENGMSDCDATDETAILDATA = 9;
	const uint DPCHENGMSDCDATHEADBARDATA = 10;
	const uint DPCHENGMSDCDATLISTDATA = 11;
	const uint DPCHENGMSDCDATRECDATA = 12;
	const uint DPCHENGMSDCDATREF1NFILEDATA = 13;
	const uint DPCHENGMSDCFILDATA = 14;
	const uint DPCHENGMSDCFILDETAILDATA = 15;
	const uint DPCHENGMSDCFILHEADBARDATA = 16;
	const uint DPCHENGMSDCFILLISTDATA = 17;
	const uint DPCHENGMSDCFILRECDATA = 18;
	const uint DPCHENGMSDCLIVALIGNDATA = 19;
	const uint DPCHENGMSDCLIVDATA = 20;
	const uint DPCHENGMSDCLIVHEADBARDATA = 21;
	const uint DPCHENGMSDCLIVSCILLDATA = 22;
	const uint DPCHENGMSDCLIVTRACKDATA = 23;
	const uint DPCHENGMSDCLIVVIDEODATA = 24;
	const uint DPCHENGMSDCLIVVIDEOLIVE = 25;
	const uint DPCHENGMSDCNAVADMINDATA = 26;
	const uint DPCHENGMSDCNAVDATA = 27;
	const uint DPCHENGMSDCNAVHEADBARDATA = 28;
	const uint DPCHENGMSDCNAVOPRDATA = 29;
	const uint DPCHENGMSDCNAVPREDATA = 30;
	const uint DPCHENGMSDCPRD1NDATADATA = 31;
	const uint DPCHENGMSDCPRDDATA = 32;
	const uint DPCHENGMSDCPRDDETAILDATA = 33;
	const uint DPCHENGMSDCPRDHEADBARDATA = 34;
	const uint DPCHENGMSDCPRDLISTDATA = 35;
	const uint DPCHENGMSDCPRDRECDATA = 36;
	const uint DPCHENGMSDCPRSDATA = 37;
	const uint DPCHENGMSDCPRSDETAILDATA = 38;
	const uint DPCHENGMSDCPRSHEADBARDATA = 39;
	const uint DPCHENGMSDCPRSLISTDATA = 40;
	const uint DPCHENGMSDCPRSRECDATA = 41;
	const uint DPCHENGMSDCSCFACQUISDATA = 42;
	const uint DPCHENGMSDCSCFACTUDATA = 43;
	const uint DPCHENGMSDCSCFDATA = 44;
	const uint DPCHENGMSDCSCFHEADBARDATA = 45;
	const uint DPCHENGMSDCSCFPRCCTLDATA = 46;
	const uint DPCHENGMSDCSCFSOURCEDATA = 47;
	const uint DPCHENGMSDCSUSPEND = 48;
	const uint DPCHENGMSDCUSGAACCESSDATA = 49;
	const uint DPCHENGMSDCUSGDATA = 50;
	const uint DPCHENGMSDCUSGDETAILDATA = 51;
	const uint DPCHENGMSDCUSGHEADBARDATA = 52;
	const uint DPCHENGMSDCUSGLISTDATA = 53;
	const uint DPCHENGMSDCUSGMNUSERDATA = 54;
	const uint DPCHENGMSDCUSGRECDATA = 55;
	const uint DPCHENGMSDCUSR1NSESSIONDATA = 56;
	const uint DPCHENGMSDCUSRAACCESSDATA = 57;
	const uint DPCHENGMSDCUSRDATA = 58;
	const uint DPCHENGMSDCUSRDETAILDATA = 59;
	const uint DPCHENGMSDCUSRHEADBARDATA = 60;
	const uint DPCHENGMSDCUSRLISTDATA = 61;
	const uint DPCHENGMSDCUSRMNUSERGROUPDATA = 62;
	const uint DPCHENGMSDCUSRRECDATA = 63;
	const uint DPCHENGROOTMSDCDATA = 64;
	const uint DPCHENGSESSMSDCDATA = 65;
	const uint DPCHAPPDLGMSDCFILDOWNLOADDO = 66;
	const uint DPCHAPPDLGMSDCNAVLOAINIDATA = 67;
	const uint DPCHAPPDLGMSDCNAVLOAINIDO = 68;
	const uint DPCHAPPMSDCALERT = 69;
	const uint DPCHAPPMSDCDATAPARDATA = 70;
	const uint DPCHAPPMSDCDATAPARDO = 71;
	const uint DPCHAPPMSDCDATDETAILDATA = 72;
	const uint DPCHAPPMSDCDATDETAILDO = 73;
	const uint DPCHAPPMSDCDATDO = 74;
	const uint DPCHAPPMSDCDATLISTDATA = 75;
	const uint DPCHAPPMSDCDATLISTDO = 76;
	const uint DPCHAPPMSDCDATRECDO = 77;
	const uint DPCHAPPMSDCDATREF1NFILEDATA = 78;
	const uint DPCHAPPMSDCDATREF1NFILEDO = 79;
	const uint DPCHAPPMSDCFILDETAILDATA = 80;
	const uint DPCHAPPMSDCFILDETAILDO = 81;
	const uint DPCHAPPMSDCFILDO = 82;
	const uint DPCHAPPMSDCFILLISTDATA = 83;
	const uint DPCHAPPMSDCFILLISTDO = 84;
	const uint DPCHAPPMSDCFILRECDO = 85;
	const uint DPCHAPPMSDCINIT = 86;
	const uint DPCHAPPMSDCLIVALIGNDATA = 87;
	const uint DPCHAPPMSDCLIVALIGNDO = 88;
	const uint DPCHAPPMSDCLIVDO = 89;
	const uint DPCHAPPMSDCLIVSCILLDATA = 90;
	const uint DPCHAPPMSDCLIVSCILLDO = 91;
	const uint DPCHAPPMSDCLIVTRACKDO = 92;
	const uint DPCHAPPMSDCLIVVIDEODATA = 93;
	const uint DPCHAPPMSDCLIVVIDEODO = 94;
	const uint DPCHAPPMSDCNAVADMINDATA = 95;
	const uint DPCHAPPMSDCNAVADMINDO = 96;
	const uint DPCHAPPMSDCNAVDO = 97;
	const uint DPCHAPPMSDCNAVOPRDATA = 98;
	const uint DPCHAPPMSDCNAVOPRDO = 99;
	const uint DPCHAPPMSDCNAVPREDO = 100;
	const uint DPCHAPPMSDCPRD1NDATADATA = 101;
	const uint DPCHAPPMSDCPRD1NDATADO = 102;
	const uint DPCHAPPMSDCPRDDETAILDATA = 103;
	const uint DPCHAPPMSDCPRDDETAILDO = 104;
	const uint DPCHAPPMSDCPRDDO = 105;
	const uint DPCHAPPMSDCPRDLISTDATA = 106;
	const uint DPCHAPPMSDCPRDLISTDO = 107;
	const uint DPCHAPPMSDCPRDRECDO = 108;
	const uint DPCHAPPMSDCPRSDETAILDATA = 109;
	const uint DPCHAPPMSDCPRSDETAILDO = 110;
	const uint DPCHAPPMSDCPRSDO = 111;
	const uint DPCHAPPMSDCPRSLISTDATA = 112;
	const uint DPCHAPPMSDCPRSLISTDO = 113;
	const uint DPCHAPPMSDCPRSRECDO = 114;
	const uint DPCHAPPMSDCRESUME = 115;
	const uint DPCHAPPMSDCSCFACQUISDATA = 116;
	const uint DPCHAPPMSDCSCFACQUISDO = 117;
	const uint DPCHAPPMSDCSCFACTUDATA = 118;
	const uint DPCHAPPMSDCSCFACTUDO = 119;
	const uint DPCHAPPMSDCSCFDO = 120;
	const uint DPCHAPPMSDCSCFPRCCTLDO = 121;
	const uint DPCHAPPMSDCSCFSOURCEDATA = 122;
	const uint DPCHAPPMSDCSCFSOURCEDO = 123;
	const uint DPCHAPPMSDCUSGAACCESSDATA = 124;
	const uint DPCHAPPMSDCUSGAACCESSDO = 125;
	const uint DPCHAPPMSDCUSGDETAILDATA = 126;
	const uint DPCHAPPMSDCUSGDETAILDO = 127;
	const uint DPCHAPPMSDCUSGDO = 128;
	const uint DPCHAPPMSDCUSGLISTDATA = 129;
	const uint DPCHAPPMSDCUSGLISTDO = 130;
	const uint DPCHAPPMSDCUSGMNUSERDATA = 131;
	const uint DPCHAPPMSDCUSGMNUSERDO = 132;
	const uint DPCHAPPMSDCUSGRECDO = 133;
	const uint DPCHAPPMSDCUSR1NSESSIONDATA = 134;
	const uint DPCHAPPMSDCUSR1NSESSIONDO = 135;
	const uint DPCHAPPMSDCUSRAACCESSDATA = 136;
	const uint DPCHAPPMSDCUSRAACCESSDO = 137;
	const uint DPCHAPPMSDCUSRDETAILDATA = 138;
	const uint DPCHAPPMSDCUSRDETAILDO = 139;
	const uint DPCHAPPMSDCUSRDO = 140;
	const uint DPCHAPPMSDCUSRLISTDATA = 141;
	const uint DPCHAPPMSDCUSRLISTDO = 142;
	const uint DPCHAPPMSDCUSRMNUSERGROUPDATA = 143;
	const uint DPCHAPPMSDCUSRMNUSERGROUPDO = 144;
	const uint DPCHAPPMSDCUSRRECDO = 145;
	const uint DPCHAPPROOTMSDCLOGIN = 146;

	uint getIx(const string& sref);
	string getSref(const uint ix);
};

#endif

