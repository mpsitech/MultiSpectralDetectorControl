/**
  * \file VecMsdcVCall.cpp
  * vector VecMsdcVCall (implementation)
  * \author Alexander Wirthmueller
  * \date created: 29 Aug 2018
  * \date modified: 29 Aug 2018
  */

#include "VecMsdcVCall.h"

/******************************************************************************
 namespace VecMsdcVCall
 ******************************************************************************/

uint VecMsdcVCall::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "callmsdcaccess") return CALLMSDCACCESS;
	if (s == "callmsdcboolvalpreset") return CALLMSDCBOOLVALPRESET;
	if (s == "callmsdcbufrdy") return CALLMSDCBUFRDY;
	if (s == "callmsdccrdactive") return CALLMSDCCRDACTIVE;
	if (s == "callmsdccrdclose") return CALLMSDCCRDCLOSE;
	if (s == "callmsdccrdopen") return CALLMSDCCRDOPEN;
	if (s == "callmsdcctlaparmod.usreq") return CALLMSDCCTLAPARMOD_USREQ;
	if (s == "callmsdcdat.prdeq") return CALLMSDCDAT_PRDEQ;
	if (s == "callmsdcdataparmod.dateq") return CALLMSDCDATAPARMOD_DATEQ;
	if (s == "callmsdcdatmod") return CALLMSDCDATMOD;
	if (s == "callmsdcdatmod.prdeq") return CALLMSDCDATMOD_PRDEQ;
	if (s == "callmsdcdatupd.refeq") return CALLMSDCDATUPD_REFEQ;
	if (s == "callmsdcdblvalpreset") return CALLMSDCDBLVALPRESET;
	if (s == "callmsdcdlgclose") return CALLMSDCDLGCLOSE;
	if (s == "callmsdcfil.clueq") return CALLMSDCFIL_CLUEQ;
	if (s == "callmsdcfil.reteq") return CALLMSDCFIL_RETEQ;
	if (s == "callmsdcfil.reueq") return CALLMSDCFIL_REUEQ;
	if (s == "callmsdcfilmod") return CALLMSDCFILMOD;
	if (s == "callmsdcfilmod.clueq") return CALLMSDCFILMOD_CLUEQ;
	if (s == "callmsdcfilmod.retreueq") return CALLMSDCFILMOD_RETREUEQ;
	if (s == "callmsdcfilupd.refeq") return CALLMSDCFILUPD_REFEQ;
	if (s == "callmsdchusrrunvmod.crdusreq") return CALLMSDCHUSRRUNVMOD_CRDUSREQ;
	if (s == "callmsdcibitrdy") return CALLMSDCIBITRDY;
	if (s == "callmsdcimgrdy") return CALLMSDCIMGRDY;
	if (s == "callmsdcintvalpreset") return CALLMSDCINTVALPRESET;
	if (s == "callmsdcixpreset") return CALLMSDCIXPRESET;
	if (s == "callmsdckakjkeymod.klsakeyeq") return CALLMSDCKAKJKEYMOD_KLSAKEYEQ;
	if (s == "callmsdcklsakeymod.klseq") return CALLMSDCKLSAKEYMOD_KLSEQ;
	if (s == "callmsdcklsakeymod.klsmtburfeq") return CALLMSDCKLSAKEYMOD_KLSMTBURFEQ;
	if (s == "callmsdclog") return CALLMSDCLOG;
	if (s == "callmsdclogout") return CALLMSDCLOGOUT;
	if (s == "callmsdcmastsgechg") return CALLMSDCMASTSGECHG;
	if (s == "callmsdcmastslvchg") return CALLMSDCMASTSLVCHG;
	if (s == "callmsdcmastsrdchg") return CALLMSDCMASTSRDCHG;
	if (s == "callmsdcmonstatchg") return CALLMSDCMONSTATCHG;
	if (s == "callmsdcnodechg") return CALLMSDCNODECHG;
	if (s == "callmsdcprdmod") return CALLMSDCPRDMOD;
	if (s == "callmsdcprdupd.refeq") return CALLMSDCPRDUPD_REFEQ;
	if (s == "callmsdcprsjlnmmod.prseq") return CALLMSDCPRSJLNMMOD_PRSEQ;
	if (s == "callmsdcprsmod") return CALLMSDCPRSMOD;
	if (s == "callmsdcprsupd.refeq") return CALLMSDCPRSUPD_REFEQ;
	if (s == "callmsdcrecaccess") return CALLMSDCRECACCESS;
	if (s == "callmsdcrefpreset") return CALLMSDCREFPRESET;
	if (s == "callmsdcrefspreset") return CALLMSDCREFSPRESET;
	if (s == "callmsdcsesmod") return CALLMSDCSESMOD;
	if (s == "callmsdcsesmod.usreq") return CALLMSDCSESMOD_USREQ;
	if (s == "callmsdcsesupd.refeq") return CALLMSDCSESUPD_REFEQ;
	if (s == "callmsdcsgechg") return CALLMSDCSGECHG;
	if (s == "callmsdcshrdatchg") return CALLMSDCSHRDATCHG;
	if (s == "callmsdcsrefpreset") return CALLMSDCSREFPRESET;
	if (s == "callmsdcstatchg") return CALLMSDCSTATCHG;
	if (s == "callmsdcstgchg") return CALLMSDCSTGCHG;
	if (s == "callmsdcstubchg") return CALLMSDCSTUBCHG;
	if (s == "callmsdcsuspsess") return CALLMSDCSUSPSESS;
	if (s == "callmsdctrig") return CALLMSDCTRIG;
	if (s == "callmsdctxtvalpreset") return CALLMSDCTXTVALPRESET;
	if (s == "callmsdcusgaaccmod.usgeq") return CALLMSDCUSGAACCMOD_USGEQ;
	if (s == "callmsdcusgmod") return CALLMSDCUSGMOD;
	if (s == "callmsdcusgupd.refeq") return CALLMSDCUSGUPD_REFEQ;
	if (s == "callmsdcusr.prseq") return CALLMSDCUSR_PRSEQ;
	if (s == "callmsdcusr.usgeq") return CALLMSDCUSR_USGEQ;
	if (s == "callmsdcusraaccmod.usreq") return CALLMSDCUSRAACCMOD_USREQ;
	if (s == "callmsdcusrjstemod.usreq") return CALLMSDCUSRJSTEMOD_USREQ;
	if (s == "callmsdcusrmod") return CALLMSDCUSRMOD;
	if (s == "callmsdcusrrusgmod.usgeq") return CALLMSDCUSRRUSGMOD_USGEQ;
	if (s == "callmsdcusrrusgmod.usreq") return CALLMSDCUSRRUSGMOD_USREQ;
	if (s == "callmsdcusrupd.refeq") return CALLMSDCUSRUPD_REFEQ;

	return(0);
};

string VecMsdcVCall::getSref(
			const uint ix
		) {
	if (ix == CALLMSDCACCESS) return("CallMsdcAccess");
	if (ix == CALLMSDCBOOLVALPRESET) return("CallMsdcBoolvalPreSet");
	if (ix == CALLMSDCBUFRDY) return("CallMsdcBufrdy");
	if (ix == CALLMSDCCRDACTIVE) return("CallMsdcCrdActive");
	if (ix == CALLMSDCCRDCLOSE) return("CallMsdcCrdClose");
	if (ix == CALLMSDCCRDOPEN) return("CallMsdcCrdOpen");
	if (ix == CALLMSDCCTLAPARMOD_USREQ) return("CallMsdcCtlAparMod.usrEq");
	if (ix == CALLMSDCDAT_PRDEQ) return("CallMsdcDat.prdEq");
	if (ix == CALLMSDCDATAPARMOD_DATEQ) return("CallMsdcDatAparMod.datEq");
	if (ix == CALLMSDCDATMOD) return("CallMsdcDatMod");
	if (ix == CALLMSDCDATMOD_PRDEQ) return("CallMsdcDatMod.prdEq");
	if (ix == CALLMSDCDATUPD_REFEQ) return("CallMsdcDatUpd.refEq");
	if (ix == CALLMSDCDBLVALPRESET) return("CallMsdcDblvalPreSet");
	if (ix == CALLMSDCDLGCLOSE) return("CallMsdcDlgClose");
	if (ix == CALLMSDCFIL_CLUEQ) return("CallMsdcFil.cluEq");
	if (ix == CALLMSDCFIL_RETEQ) return("CallMsdcFil.retEq");
	if (ix == CALLMSDCFIL_REUEQ) return("CallMsdcFil.reuEq");
	if (ix == CALLMSDCFILMOD) return("CallMsdcFilMod");
	if (ix == CALLMSDCFILMOD_CLUEQ) return("CallMsdcFilMod.cluEq");
	if (ix == CALLMSDCFILMOD_RETREUEQ) return("CallMsdcFilMod.retReuEq");
	if (ix == CALLMSDCFILUPD_REFEQ) return("CallMsdcFilUpd.refEq");
	if (ix == CALLMSDCHUSRRUNVMOD_CRDUSREQ) return("CallMsdcHusrRunvMod.crdUsrEq");
	if (ix == CALLMSDCIBITRDY) return("CallMsdcIbitrdy");
	if (ix == CALLMSDCIMGRDY) return("CallMsdcImgrdy");
	if (ix == CALLMSDCINTVALPRESET) return("CallMsdcIntvalPreSet");
	if (ix == CALLMSDCIXPRESET) return("CallMsdcIxPreSet");
	if (ix == CALLMSDCKAKJKEYMOD_KLSAKEYEQ) return("CallMsdcKakJkeyMod.klsAkeyEq");
	if (ix == CALLMSDCKLSAKEYMOD_KLSEQ) return("CallMsdcKlsAkeyMod.klsEq");
	if (ix == CALLMSDCKLSAKEYMOD_KLSMTBURFEQ) return("CallMsdcKlsAkeyMod.klsMtbUrfEq");
	if (ix == CALLMSDCLOG) return("CallMsdcLog");
	if (ix == CALLMSDCLOGOUT) return("CallMsdcLogout");
	if (ix == CALLMSDCMASTSGECHG) return("CallMsdcMastsgeChg");
	if (ix == CALLMSDCMASTSLVCHG) return("CallMsdcMastslvChg");
	if (ix == CALLMSDCMASTSRDCHG) return("CallMsdcMastsrdChg");
	if (ix == CALLMSDCMONSTATCHG) return("CallMsdcMonstatChg");
	if (ix == CALLMSDCNODECHG) return("CallMsdcNodeChg");
	if (ix == CALLMSDCPRDMOD) return("CallMsdcPrdMod");
	if (ix == CALLMSDCPRDUPD_REFEQ) return("CallMsdcPrdUpd.refEq");
	if (ix == CALLMSDCPRSJLNMMOD_PRSEQ) return("CallMsdcPrsJlnmMod.prsEq");
	if (ix == CALLMSDCPRSMOD) return("CallMsdcPrsMod");
	if (ix == CALLMSDCPRSUPD_REFEQ) return("CallMsdcPrsUpd.refEq");
	if (ix == CALLMSDCRECACCESS) return("CallMsdcRecaccess");
	if (ix == CALLMSDCREFPRESET) return("CallMsdcRefPreSet");
	if (ix == CALLMSDCREFSPRESET) return("CallMsdcRefsPreSet");
	if (ix == CALLMSDCSESMOD) return("CallMsdcSesMod");
	if (ix == CALLMSDCSESMOD_USREQ) return("CallMsdcSesMod.usrEq");
	if (ix == CALLMSDCSESUPD_REFEQ) return("CallMsdcSesUpd.refEq");
	if (ix == CALLMSDCSGECHG) return("CallMsdcSgeChg");
	if (ix == CALLMSDCSHRDATCHG) return("CallMsdcShrdatChg");
	if (ix == CALLMSDCSREFPRESET) return("CallMsdcSrefPreSet");
	if (ix == CALLMSDCSTATCHG) return("CallMsdcStatChg");
	if (ix == CALLMSDCSTGCHG) return("CallMsdcStgChg");
	if (ix == CALLMSDCSTUBCHG) return("CallMsdcStubChg");
	if (ix == CALLMSDCSUSPSESS) return("CallMsdcSuspsess");
	if (ix == CALLMSDCTRIG) return("CallMsdcTrig");
	if (ix == CALLMSDCTXTVALPRESET) return("CallMsdcTxtvalPreSet");
	if (ix == CALLMSDCUSGAACCMOD_USGEQ) return("CallMsdcUsgAaccMod.usgEq");
	if (ix == CALLMSDCUSGMOD) return("CallMsdcUsgMod");
	if (ix == CALLMSDCUSGUPD_REFEQ) return("CallMsdcUsgUpd.refEq");
	if (ix == CALLMSDCUSR_PRSEQ) return("CallMsdcUsr.prsEq");
	if (ix == CALLMSDCUSR_USGEQ) return("CallMsdcUsr.usgEq");
	if (ix == CALLMSDCUSRAACCMOD_USREQ) return("CallMsdcUsrAaccMod.usrEq");
	if (ix == CALLMSDCUSRJSTEMOD_USREQ) return("CallMsdcUsrJsteMod.usrEq");
	if (ix == CALLMSDCUSRMOD) return("CallMsdcUsrMod");
	if (ix == CALLMSDCUSRRUSGMOD_USGEQ) return("CallMsdcUsrRusgMod.usgEq");
	if (ix == CALLMSDCUSRRUSGMOD_USREQ) return("CallMsdcUsrRusgMod.usrEq");
	if (ix == CALLMSDCUSRUPD_REFEQ) return("CallMsdcUsrUpd.refEq");

	return("");
};

