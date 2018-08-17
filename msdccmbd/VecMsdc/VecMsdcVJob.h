/**
  * \file VecMsdcVJob.h
  * vector VecMsdcVJob (declarations)
  * \author Alexander Wirthmueller
  * \date created: 15 Aug 2018
  * \date modified: 15 Aug 2018
  */

#ifndef VECMSDCVJOB_H
#define VECMSDCVJOB_H

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
	* VecMsdcVJob
	*/
namespace VecMsdcVJob {
	const uint CRDMSDCDAT = 1;
	const uint CRDMSDCFIL = 2;
	const uint CRDMSDCLIV = 3;
	const uint CRDMSDCNAV = 4;
	const uint CRDMSDCPRD = 5;
	const uint CRDMSDCPRS = 6;
	const uint CRDMSDCSCF = 7;
	const uint CRDMSDCUSG = 8;
	const uint CRDMSDCUSR = 9;
	const uint DLGMSDCFILDOWNLOAD = 10;
	const uint DLGMSDCNAVLOAINI = 11;
	const uint IEXMSDCINI = 12;
	const uint JOBMSDCACQADXL = 13;
	const uint JOBMSDCACQLWIR = 14;
	const uint JOBMSDCACQVISL = 15;
	const uint JOBMSDCACQVISR = 16;
	const uint JOBMSDCACTALIGN = 17;
	const uint JOBMSDCACTLED = 18;
	const uint JOBMSDCACTSERVO = 19;
	const uint JOBMSDCPRCSPOTFIND = 20;
	const uint JOBMSDCPRCSTEREO = 21;
	const uint JOBMSDCPRCTRACK = 22;
	const uint JOBMSDCSRCMSDD = 23;
	const uint JOBMSDCSRCTRIGGER = 24;
	const uint M2MSESSMSDC = 25;
	const uint PNLMSDCDATAPAR = 26;
	const uint PNLMSDCDATDETAIL = 27;
	const uint PNLMSDCDATHEADBAR = 28;
	const uint PNLMSDCDATLIST = 29;
	const uint PNLMSDCDATREC = 30;
	const uint PNLMSDCDATREF1NFILE = 31;
	const uint PNLMSDCFILDETAIL = 32;
	const uint PNLMSDCFILHEADBAR = 33;
	const uint PNLMSDCFILLIST = 34;
	const uint PNLMSDCFILREC = 35;
	const uint PNLMSDCLIVALIGN = 36;
	const uint PNLMSDCLIVHEADBAR = 37;
	const uint PNLMSDCLIVSCILL = 38;
	const uint PNLMSDCLIVTRACK = 39;
	const uint PNLMSDCLIVVIDEO = 40;
	const uint PNLMSDCNAVADMIN = 41;
	const uint PNLMSDCNAVHEADBAR = 42;
	const uint PNLMSDCNAVOPR = 43;
	const uint PNLMSDCNAVPRE = 44;
	const uint PNLMSDCPRD1NDATA = 45;
	const uint PNLMSDCPRDDETAIL = 46;
	const uint PNLMSDCPRDHEADBAR = 47;
	const uint PNLMSDCPRDLIST = 48;
	const uint PNLMSDCPRDREC = 49;
	const uint PNLMSDCPRSDETAIL = 50;
	const uint PNLMSDCPRSHEADBAR = 51;
	const uint PNLMSDCPRSLIST = 52;
	const uint PNLMSDCPRSREC = 53;
	const uint PNLMSDCSCFACQUIS = 54;
	const uint PNLMSDCSCFACTU = 55;
	const uint PNLMSDCSCFHEADBAR = 56;
	const uint PNLMSDCSCFPRCCTL = 57;
	const uint PNLMSDCSCFSOURCE = 58;
	const uint PNLMSDCUSGAACCESS = 59;
	const uint PNLMSDCUSGDETAIL = 60;
	const uint PNLMSDCUSGHEADBAR = 61;
	const uint PNLMSDCUSGLIST = 62;
	const uint PNLMSDCUSGMNUSER = 63;
	const uint PNLMSDCUSGREC = 64;
	const uint PNLMSDCUSR1NSESSION = 65;
	const uint PNLMSDCUSRAACCESS = 66;
	const uint PNLMSDCUSRDETAIL = 67;
	const uint PNLMSDCUSRHEADBAR = 68;
	const uint PNLMSDCUSRLIST = 69;
	const uint PNLMSDCUSRMNUSERGROUP = 70;
	const uint PNLMSDCUSRREC = 71;
	const uint QRYMSDCDATAPAR = 72;
	const uint QRYMSDCDATLIST = 73;
	const uint QRYMSDCDATREF1NFILE = 74;
	const uint QRYMSDCFILLIST = 75;
	const uint QRYMSDCPRD1NDATA = 76;
	const uint QRYMSDCPRDLIST = 77;
	const uint QRYMSDCPRSLIST = 78;
	const uint QRYMSDCUSGAACCESS = 79;
	const uint QRYMSDCUSGLIST = 80;
	const uint QRYMSDCUSGMNUSER = 81;
	const uint QRYMSDCUSR1NSESSION = 82;
	const uint QRYMSDCUSRAACCESS = 83;
	const uint QRYMSDCUSRLIST = 84;
	const uint QRYMSDCUSRMNUSERGROUP = 85;
	const uint ROOTMSDC = 86;
	const uint SESSMSDC = 87;

	uint getIx(const string& sref);
	string getSref(const uint ix);
};

#endif

