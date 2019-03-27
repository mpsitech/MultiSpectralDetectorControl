/**
  * \file DbsMsdc_vecs.cpp
  * C++ wrapper for database DbsMsdc (implementation of vectors)
  * \author Alexander Wirthmueller
  * \date created: 18 Dec 2018
  * \date modified: 18 Dec 2018
  */

/******************************************************************************
 class DbsMsdc::VecVCard
 ******************************************************************************/

uint DbsMsdc::VecVCard::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "crdmsdcnav") return CRDMSDCNAV;
	if (s == "crdmsdcusg") return CRDMSDCUSG;
	if (s == "crdmsdcusr") return CRDMSDCUSR;
	if (s == "crdmsdcprs") return CRDMSDCPRS;
	if (s == "crdmsdcscf") return CRDMSDCSCF;
	if (s == "crdmsdcliv") return CRDMSDCLIV;
	if (s == "crdmsdcprd") return CRDMSDCPRD;
	if (s == "crdmsdcdat") return CRDMSDCDAT;
	if (s == "crdmsdcfil") return CRDMSDCFIL;

	return(0);
};

string DbsMsdc::VecVCard::getSref(
			const uint ix
		) {
	if (ix == CRDMSDCNAV) return("CrdMsdcNav");
	if (ix == CRDMSDCUSG) return("CrdMsdcUsg");
	if (ix == CRDMSDCUSR) return("CrdMsdcUsr");
	if (ix == CRDMSDCPRS) return("CrdMsdcPrs");
	if (ix == CRDMSDCSCF) return("CrdMsdcScf");
	if (ix == CRDMSDCLIV) return("CrdMsdcLiv");
	if (ix == CRDMSDCPRD) return("CrdMsdcPrd");
	if (ix == CRDMSDCDAT) return("CrdMsdcDat");
	if (ix == CRDMSDCFIL) return("CrdMsdcFil");

	return("");
};

string DbsMsdc::VecVCard::getTitle(
			const uint ix
			, const uint ixMsdcVLocale
		) {
	if (ixMsdcVLocale == 1) {
		if (ix == CRDMSDCUSG) return("user groups");
		if (ix == CRDMSDCUSR) return("users");
		if (ix == CRDMSDCPRS) return("persons");
		if (ix == CRDMSDCSCF) return("system configuration");
		if (ix == CRDMSDCLIV) return("live data");
		if (ix == CRDMSDCPRD) return("acquisition periods");
		if (ix == CRDMSDCDAT) return("raw data");
		if (ix == CRDMSDCFIL) return("files");
		return(getSref(ix));
	} else if (ixMsdcVLocale == 2) {
		if (ix == CRDMSDCUSG) return("Benutzergruppen");
		if (ix == CRDMSDCUSR) return("Benutzer");
		if (ix == CRDMSDCPRS) return("Personen");
		if (ix == CRDMSDCSCF) return("Systemkonfiguration");
		if (ix == CRDMSDCLIV) return("Live-Daten");
		if (ix == CRDMSDCPRD) return("Auszeichnungsperioden");
		if (ix == CRDMSDCDAT) return("Rohdaten");
		if (ix == CRDMSDCFIL) return("Dateien");
		return(getTitle(ix, 1));
	};

	return("");
};

void DbsMsdc::VecVCard::fillFeed(
			const uint ixMsdcVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=9;i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixMsdcVLocale));
};

/******************************************************************************
 class DbsMsdc::VecVControl
 ******************************************************************************/

uint DbsMsdc::VecVControl::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "pnlmsdcusglist.tcosrf") return PNLMSDCUSGLIST_TCOSRF;
	if (s == "pnlmsdcusgaaccess.tcofeg") return PNLMSDCUSGAACCESS_TCOFEG;
	if (s == "pnlmsdcusgaaccess.tcofea") return PNLMSDCUSGAACCESS_TCOFEA;
	if (s == "pnlmsdcusgaaccess.tcoacc") return PNLMSDCUSGAACCESS_TCOACC;
	if (s == "pnlmsdcusgmnuser.tcomref") return PNLMSDCUSGMNUSER_TCOMREF;
	if (s == "pnlmsdcusgmnuser.tcoulv") return PNLMSDCUSGMNUSER_TCOULV;
	if (s == "pnlmsdcusrlist.tcoprs") return PNLMSDCUSRLIST_TCOPRS;
	if (s == "pnlmsdcusrlist.tcosrf") return PNLMSDCUSRLIST_TCOSRF;
	if (s == "pnlmsdcusrlist.tcousg") return PNLMSDCUSRLIST_TCOUSG;
	if (s == "pnlmsdcusrlist.tcoste") return PNLMSDCUSRLIST_TCOSTE;
	if (s == "pnlmsdcusrlist.tcolcl") return PNLMSDCUSRLIST_TCOLCL;
	if (s == "pnlmsdcusrlist.tcoulv") return PNLMSDCUSRLIST_TCOULV;
	if (s == "pnlmsdcusraaccess.tcofeg") return PNLMSDCUSRAACCESS_TCOFEG;
	if (s == "pnlmsdcusraaccess.tcofea") return PNLMSDCUSRAACCESS_TCOFEA;
	if (s == "pnlmsdcusraaccess.tcoacc") return PNLMSDCUSRAACCESS_TCOACC;
	if (s == "pnlmsdcusr1nsession.tcoref") return PNLMSDCUSR1NSESSION_TCOREF;
	if (s == "pnlmsdcusrmnusergroup.tcomref") return PNLMSDCUSRMNUSERGROUP_TCOMREF;
	if (s == "pnlmsdcusrmnusergroup.tcoulv") return PNLMSDCUSRMNUSERGROUP_TCOULV;
	if (s == "pnlmsdcprslist.tcotit") return PNLMSDCPRSLIST_TCOTIT;
	if (s == "pnlmsdcprslist.tcofnm") return PNLMSDCPRSLIST_TCOFNM;
	if (s == "pnlmsdcprslist.tcolnm") return PNLMSDCPRSLIST_TCOLNM;
	if (s == "pnlmsdcprslist.tcogrp") return PNLMSDCPRSLIST_TCOGRP;
	if (s == "pnlmsdcprslist.tcoown") return PNLMSDCPRSLIST_TCOOWN;
	if (s == "pnlmsdcprslist.tcosex") return PNLMSDCPRSLIST_TCOSEX;
	if (s == "pnlmsdcprslist.tcotel") return PNLMSDCPRSLIST_TCOTEL;
	if (s == "pnlmsdcprslist.tcoeml") return PNLMSDCPRSLIST_TCOEML;
	if (s == "pnlmsdcprdlist.tcosta") return PNLMSDCPRDLIST_TCOSTA;
	if (s == "pnlmsdcprdlist.tcosto") return PNLMSDCPRDLIST_TCOSTO;
	if (s == "pnlmsdcprd1ndata.tcoref") return PNLMSDCPRD1NDATA_TCOREF;
	if (s == "pnlmsdcdatlist.tcoaft") return PNLMSDCDATLIST_TCOAFT;
	if (s == "pnlmsdcdatlist.tcoprd") return PNLMSDCDATLIST_TCOPRD;
	if (s == "pnlmsdcdatlist.tcosta") return PNLMSDCDATLIST_TCOSTA;
	if (s == "pnlmsdcdatlist.tcosto") return PNLMSDCDATLIST_TCOSTO;
	if (s == "pnlmsdcdatapar.tcosta") return PNLMSDCDATAPAR_TCOSTA;
	if (s == "pnlmsdcdatapar.tcokey") return PNLMSDCDATAPAR_TCOKEY;
	if (s == "pnlmsdcdatapar.tcofil") return PNLMSDCDATAPAR_TCOFIL;
	if (s == "pnlmsdcdatapar.tcoval") return PNLMSDCDATAPAR_TCOVAL;
	if (s == "pnlmsdcdatapar.tcobin") return PNLMSDCDATAPAR_TCOBIN;
	if (s == "pnlmsdcdatref1nfile.tcoref") return PNLMSDCDATREF1NFILE_TCOREF;
	if (s == "pnlmsdcfillist.tcofnm") return PNLMSDCFILLIST_TCOFNM;
	if (s == "pnlmsdcfillist.tcoret") return PNLMSDCFILLIST_TCORET;
	if (s == "pnlmsdcfillist.tcoreu") return PNLMSDCFILLIST_TCOREU;
	if (s == "pnlmsdcfillist.tcocnt") return PNLMSDCFILLIST_TCOCNT;
	if (s == "pnlmsdcfillist.tcomim") return PNLMSDCFILLIST_TCOMIM;
	if (s == "pnlmsdcfillist.tcosiz") return PNLMSDCFILLIST_TCOSIZ;

	return(0);
};

string DbsMsdc::VecVControl::getSref(
			const uint ix
		) {
	if (ix == PNLMSDCUSGLIST_TCOSRF) return("PnlMsdcUsgList.TcoSrf");
	if (ix == PNLMSDCUSGAACCESS_TCOFEG) return("PnlMsdcUsgAAccess.TcoFeg");
	if (ix == PNLMSDCUSGAACCESS_TCOFEA) return("PnlMsdcUsgAAccess.TcoFea");
	if (ix == PNLMSDCUSGAACCESS_TCOACC) return("PnlMsdcUsgAAccess.TcoAcc");
	if (ix == PNLMSDCUSGMNUSER_TCOMREF) return("PnlMsdcUsgMNUser.TcoMref");
	if (ix == PNLMSDCUSGMNUSER_TCOULV) return("PnlMsdcUsgMNUser.TcoUlv");
	if (ix == PNLMSDCUSRLIST_TCOPRS) return("PnlMsdcUsrList.TcoPrs");
	if (ix == PNLMSDCUSRLIST_TCOSRF) return("PnlMsdcUsrList.TcoSrf");
	if (ix == PNLMSDCUSRLIST_TCOUSG) return("PnlMsdcUsrList.TcoUsg");
	if (ix == PNLMSDCUSRLIST_TCOSTE) return("PnlMsdcUsrList.TcoSte");
	if (ix == PNLMSDCUSRLIST_TCOLCL) return("PnlMsdcUsrList.TcoLcl");
	if (ix == PNLMSDCUSRLIST_TCOULV) return("PnlMsdcUsrList.TcoUlv");
	if (ix == PNLMSDCUSRAACCESS_TCOFEG) return("PnlMsdcUsrAAccess.TcoFeg");
	if (ix == PNLMSDCUSRAACCESS_TCOFEA) return("PnlMsdcUsrAAccess.TcoFea");
	if (ix == PNLMSDCUSRAACCESS_TCOACC) return("PnlMsdcUsrAAccess.TcoAcc");
	if (ix == PNLMSDCUSR1NSESSION_TCOREF) return("PnlMsdcUsr1NSession.TcoRef");
	if (ix == PNLMSDCUSRMNUSERGROUP_TCOMREF) return("PnlMsdcUsrMNUsergroup.TcoMref");
	if (ix == PNLMSDCUSRMNUSERGROUP_TCOULV) return("PnlMsdcUsrMNUsergroup.TcoUlv");
	if (ix == PNLMSDCPRSLIST_TCOTIT) return("PnlMsdcPrsList.TcoTit");
	if (ix == PNLMSDCPRSLIST_TCOFNM) return("PnlMsdcPrsList.TcoFnm");
	if (ix == PNLMSDCPRSLIST_TCOLNM) return("PnlMsdcPrsList.TcoLnm");
	if (ix == PNLMSDCPRSLIST_TCOGRP) return("PnlMsdcPrsList.TcoGrp");
	if (ix == PNLMSDCPRSLIST_TCOOWN) return("PnlMsdcPrsList.TcoOwn");
	if (ix == PNLMSDCPRSLIST_TCOSEX) return("PnlMsdcPrsList.TcoSex");
	if (ix == PNLMSDCPRSLIST_TCOTEL) return("PnlMsdcPrsList.TcoTel");
	if (ix == PNLMSDCPRSLIST_TCOEML) return("PnlMsdcPrsList.TcoEml");
	if (ix == PNLMSDCPRDLIST_TCOSTA) return("PnlMsdcPrdList.TcoSta");
	if (ix == PNLMSDCPRDLIST_TCOSTO) return("PnlMsdcPrdList.TcoSto");
	if (ix == PNLMSDCPRD1NDATA_TCOREF) return("PnlMsdcPrd1NData.TcoRef");
	if (ix == PNLMSDCDATLIST_TCOAFT) return("PnlMsdcDatList.TcoAft");
	if (ix == PNLMSDCDATLIST_TCOPRD) return("PnlMsdcDatList.TcoPrd");
	if (ix == PNLMSDCDATLIST_TCOSTA) return("PnlMsdcDatList.TcoSta");
	if (ix == PNLMSDCDATLIST_TCOSTO) return("PnlMsdcDatList.TcoSto");
	if (ix == PNLMSDCDATAPAR_TCOSTA) return("PnlMsdcDatAPar.TcoSta");
	if (ix == PNLMSDCDATAPAR_TCOKEY) return("PnlMsdcDatAPar.TcoKey");
	if (ix == PNLMSDCDATAPAR_TCOFIL) return("PnlMsdcDatAPar.TcoFil");
	if (ix == PNLMSDCDATAPAR_TCOVAL) return("PnlMsdcDatAPar.TcoVal");
	if (ix == PNLMSDCDATAPAR_TCOBIN) return("PnlMsdcDatAPar.TcoBin");
	if (ix == PNLMSDCDATREF1NFILE_TCOREF) return("PnlMsdcDatRef1NFile.TcoRef");
	if (ix == PNLMSDCFILLIST_TCOFNM) return("PnlMsdcFilList.TcoFnm");
	if (ix == PNLMSDCFILLIST_TCORET) return("PnlMsdcFilList.TcoRet");
	if (ix == PNLMSDCFILLIST_TCOREU) return("PnlMsdcFilList.TcoReu");
	if (ix == PNLMSDCFILLIST_TCOCNT) return("PnlMsdcFilList.TcoCnt");
	if (ix == PNLMSDCFILLIST_TCOMIM) return("PnlMsdcFilList.TcoMim");
	if (ix == PNLMSDCFILLIST_TCOSIZ) return("PnlMsdcFilList.TcoSiz");

	return("");
};

/******************************************************************************
 class DbsMsdc::VecVFeatgroup
 ******************************************************************************/

uint DbsMsdc::VecVFeatgroup::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "vecmsdcvcard") return VECMSDCVCARD;
	if (s == "vecvjobmsdcacqadxlvar") return VECVJOBMSDCACQADXLVAR;
	if (s == "vecvjobmsdcacqlwirmethod") return VECVJOBMSDCACQLWIRMETHOD;
	if (s == "vecvjobmsdcacqlwirvar") return VECVJOBMSDCACQLWIRVAR;
	if (s == "vecvjobmsdcacqvislmethod") return VECVJOBMSDCACQVISLMETHOD;
	if (s == "vecvjobmsdcacqvislvar") return VECVJOBMSDCACQVISLVAR;
	if (s == "vecvjobmsdcacqvisrmethod") return VECVJOBMSDCACQVISRMETHOD;
	if (s == "vecvjobmsdcacqvisrvar") return VECVJOBMSDCACQVISRVAR;
	if (s == "vecvjobmsdcactalignmethod") return VECVJOBMSDCACTALIGNMETHOD;
	if (s == "vecvjobmsdcactledmethod") return VECVJOBMSDCACTLEDMETHOD;
	if (s == "vecvjobmsdcactledvar") return VECVJOBMSDCACTLEDVAR;
	if (s == "vecvjobmsdcactservomethod") return VECVJOBMSDCACTSERVOMETHOD;
	if (s == "vecvjobmsdcactservovar") return VECVJOBMSDCACTSERVOVAR;

	return(0);
};

string DbsMsdc::VecVFeatgroup::getSref(
			const uint ix
		) {
	if (ix == VECMSDCVCARD) return("VecMsdcVCard");
	if (ix == VECVJOBMSDCACQADXLVAR) return("VecVJobMsdcAcqAdxlVar");
	if (ix == VECVJOBMSDCACQLWIRMETHOD) return("VecVJobMsdcAcqLwirMethod");
	if (ix == VECVJOBMSDCACQLWIRVAR) return("VecVJobMsdcAcqLwirVar");
	if (ix == VECVJOBMSDCACQVISLMETHOD) return("VecVJobMsdcAcqVislMethod");
	if (ix == VECVJOBMSDCACQVISLVAR) return("VecVJobMsdcAcqVislVar");
	if (ix == VECVJOBMSDCACQVISRMETHOD) return("VecVJobMsdcAcqVisrMethod");
	if (ix == VECVJOBMSDCACQVISRVAR) return("VecVJobMsdcAcqVisrVar");
	if (ix == VECVJOBMSDCACTALIGNMETHOD) return("VecVJobMsdcActAlignMethod");
	if (ix == VECVJOBMSDCACTLEDMETHOD) return("VecVJobMsdcActLedMethod");
	if (ix == VECVJOBMSDCACTLEDVAR) return("VecVJobMsdcActLedVar");
	if (ix == VECVJOBMSDCACTSERVOMETHOD) return("VecVJobMsdcActServoMethod");
	if (ix == VECVJOBMSDCACTSERVOVAR) return("VecVJobMsdcActServoVar");

	return("");
};

string DbsMsdc::VecVFeatgroup::getTitle(
			const uint ix
			, const uint ixMsdcVLocale
		) {
	if (ixMsdcVLocale == 1) {
		if (ix == VECMSDCVCARD) return("card");
		if (ix == VECVJOBMSDCACQADXLVAR) return("JobMsdcAcqAdxl variable");
		if (ix == VECVJOBMSDCACQLWIRMETHOD) return("JobMsdcAcqLwir method");
		if (ix == VECVJOBMSDCACQLWIRVAR) return("JobMsdcAcqLwir variable");
		if (ix == VECVJOBMSDCACQVISLMETHOD) return("JobMsdcAcqVisl method");
		if (ix == VECVJOBMSDCACQVISLVAR) return("JobMsdcAcqVisl variable");
		if (ix == VECVJOBMSDCACQVISRMETHOD) return("JobMsdcAcqVisr method");
		if (ix == VECVJOBMSDCACQVISRVAR) return("JobMsdcAcqVisr variable");
		if (ix == VECVJOBMSDCACTALIGNMETHOD) return("JobMsdcActAlign method");
		if (ix == VECVJOBMSDCACTLEDMETHOD) return("JobMsdcActLed method");
		if (ix == VECVJOBMSDCACTLEDVAR) return("JobMsdcActLed variable");
		if (ix == VECVJOBMSDCACTSERVOMETHOD) return("JobMsdcActServo method");
		if (ix == VECVJOBMSDCACTSERVOVAR) return("JobMsdcActServo variable");
		return(getSref(ix));
	} else if (ixMsdcVLocale == 2) {
		if (ix == VECMSDCVCARD) return("Karte");
		if (ix == VECVJOBMSDCACQADXLVAR) return("JobMsdcAcqAdxl Variable");
		if (ix == VECVJOBMSDCACQLWIRMETHOD) return("JobMsdcAcqLwir Methode");
		if (ix == VECVJOBMSDCACQLWIRVAR) return("JobMsdcAcqLwir Variable");
		if (ix == VECVJOBMSDCACQVISLMETHOD) return("JobMsdcAcqVisl Methode");
		if (ix == VECVJOBMSDCACQVISLVAR) return("JobMsdcAcqVisl Variable");
		if (ix == VECVJOBMSDCACQVISRMETHOD) return("JobMsdcAcqVisr Methode");
		if (ix == VECVJOBMSDCACQVISRVAR) return("JobMsdcAcqVisr Variable");
		if (ix == VECVJOBMSDCACTALIGNMETHOD) return("JobMsdcActAlign Methode");
		if (ix == VECVJOBMSDCACTLEDMETHOD) return("JobMsdcActLed Methode");
		if (ix == VECVJOBMSDCACTLEDVAR) return("JobMsdcActLed Variable");
		if (ix == VECVJOBMSDCACTSERVOMETHOD) return("JobMsdcActServo Methode");
		if (ix == VECVJOBMSDCACTSERVOVAR) return("JobMsdcActServo Variable");
		return(getTitle(ix, 1));
	};

	return("");
};

void DbsMsdc::VecVFeatgroup::fillFeed(
			const uint ixMsdcVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=13;i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixMsdcVLocale));
};

/******************************************************************************
 class DbsMsdc::VecVKeylist
 ******************************************************************************/

uint DbsMsdc::VecVKeylist::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "klstmsdckacqfeat") return KLSTMSDCKACQFEAT;
	if (s == "klstmsdckamdataparkey") return KLSTMSDCKAMDATAPARKEY;
	if (s == "klstmsdckampersondetailtype") return KLSTMSDCKAMPERSONDETAILTYPE;
	if (s == "klstmsdckmfilecontent") return KLSTMSDCKMFILECONTENT;
	if (s == "klstmsdckmfilemimetype") return KLSTMSDCKMFILEMIMETYPE;

	return(0);
};

string DbsMsdc::VecVKeylist::getSref(
			const uint ix
		) {
	if (ix == KLSTMSDCKACQFEAT) return("KlstMsdcKAcqfeat");
	if (ix == KLSTMSDCKAMDATAPARKEY) return("KlstMsdcKAMDataParKey");
	if (ix == KLSTMSDCKAMPERSONDETAILTYPE) return("KlstMsdcKAMPersonDetailType");
	if (ix == KLSTMSDCKMFILECONTENT) return("KlstMsdcKMFileContent");
	if (ix == KLSTMSDCKMFILEMIMETYPE) return("KlstMsdcKMFileMimetype");

	return("");
};

string DbsMsdc::VecVKeylist::getTitle(
			const uint ix
			, const uint ixMsdcVLocale
		) {
	if (ixMsdcVLocale == 1) {
		if (ix == KLSTMSDCKACQFEAT) return("feature");
		if (ix == KLSTMSDCKAMDATAPARKEY) return("key");
		if (ix == KLSTMSDCKAMPERSONDETAILTYPE) return("type");
		if (ix == KLSTMSDCKMFILECONTENT) return("content");
		if (ix == KLSTMSDCKMFILEMIMETYPE) return("MIME type");
		return(getSref(ix));
	} else if (ixMsdcVLocale == 2) {
		if (ix == KLSTMSDCKACQFEAT) return("Funktion");
		if (ix == KLSTMSDCKAMDATAPARKEY) return("Schl\\u00fcssel");
		if (ix == KLSTMSDCKAMPERSONDETAILTYPE) return("Typ");
		if (ix == KLSTMSDCKMFILECONTENT) return("Inhalt");
		if (ix == KLSTMSDCKMFILEMIMETYPE) return("MIME-Typ");
		return(getTitle(ix, 1));
	};

	return("");
};

/******************************************************************************
 class DbsMsdc::VecVLat
 ******************************************************************************/

uint DbsMsdc::VecVLat::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "dlo") return DLO;
	if (s == "ini") return INI;

	return(0);
};

string DbsMsdc::VecVLat::getSref(
			const uint ix
		) {
	if (ix == DLO) return("dlo");
	if (ix == INI) return("ini");

	return("");
};

/******************************************************************************
 class DbsMsdc::VecVLocale
 ******************************************************************************/

uint DbsMsdc::VecVLocale::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "enus") return ENUS;
	if (s == "dech") return DECH;

	return(0);
};

string DbsMsdc::VecVLocale::getSref(
			const uint ix
		) {
	if (ix == ENUS) return("enus");
	if (ix == DECH) return("dech");

	return("");
};

string DbsMsdc::VecVLocale::getTitle(
			const uint ix
			, const uint ixMsdcVLocale
		) {
	if (ixMsdcVLocale == 1) {
		if (ix == ENUS) return("English (United States)");
		if (ix == DECH) return("German (Switzerland)");
		return(getSref(ix));
	} else if (ixMsdcVLocale == 2) {
		if (ix == ENUS) return("Englisch (Vereinigte Staaten)");
		if (ix == DECH) return("Deutsch (Schweiz)");
		return(getTitle(ix, 1));
	};

	return("");
};

void DbsMsdc::VecVLocale::fillFeed(
			const uint ixMsdcVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=2;i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixMsdcVLocale));
};

/******************************************************************************
 class DbsMsdc::VecVLop
 ******************************************************************************/

uint DbsMsdc::VecVLop::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "ins") return INS;
	if (s == "rmv") return RMV;

	return(0);
};

string DbsMsdc::VecVLop::getSref(
			const uint ix
		) {
	if (ix == INS) return("ins");
	if (ix == RMV) return("rmv");

	return("");
};

/******************************************************************************
 class DbsMsdc::VecVMaintable
 ******************************************************************************/

uint DbsMsdc::VecVMaintable::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "void") return VOID;
	if (s == "tblmsdcmdata") return TBLMSDCMDATA;
	if (s == "tblmsdcmfile") return TBLMSDCMFILE;
	if (s == "tblmsdcmperiod") return TBLMSDCMPERIOD;
	if (s == "tblmsdcmperson") return TBLMSDCMPERSON;
	if (s == "tblmsdcmsession") return TBLMSDCMSESSION;
	if (s == "tblmsdcmuser") return TBLMSDCMUSER;
	if (s == "tblmsdcmusergroup") return TBLMSDCMUSERGROUP;

	return(0);
};

string DbsMsdc::VecVMaintable::getSref(
			const uint ix
		) {
	if (ix == VOID) return("void");
	if (ix == TBLMSDCMDATA) return("TblMsdcMData");
	if (ix == TBLMSDCMFILE) return("TblMsdcMFile");
	if (ix == TBLMSDCMPERIOD) return("TblMsdcMPeriod");
	if (ix == TBLMSDCMPERSON) return("TblMsdcMPerson");
	if (ix == TBLMSDCMSESSION) return("TblMsdcMSession");
	if (ix == TBLMSDCMUSER) return("TblMsdcMUser");
	if (ix == TBLMSDCMUSERGROUP) return("TblMsdcMUsergroup");

	return("");
};

string DbsMsdc::VecVMaintable::getTitle(
			const uint ix
			, const uint ixMsdcVLocale
		) {
	if (ixMsdcVLocale == 1) {
		if (ix == VOID) return("none");
		if (ix == TBLMSDCMDATA) return("raw data");
		if (ix == TBLMSDCMFILE) return("file");
		if (ix == TBLMSDCMPERIOD) return("acquisition period");
		if (ix == TBLMSDCMPERSON) return("person");
		if (ix == TBLMSDCMSESSION) return("session");
		if (ix == TBLMSDCMUSER) return("user");
		if (ix == TBLMSDCMUSERGROUP) return("user group");
		return(getSref(ix));
	} else if (ixMsdcVLocale == 2) {
		if (ix == VOID) return("kein");
		if (ix == TBLMSDCMDATA) return("Rohdaten");
		if (ix == TBLMSDCMFILE) return("Datei");
		if (ix == TBLMSDCMPERIOD) return("Aufzeichnungsperiode");
		if (ix == TBLMSDCMPERSON) return("Person");
		if (ix == TBLMSDCMSESSION) return("Sitzung");
		if (ix == TBLMSDCMUSER) return("Benutzer");
		if (ix == TBLMSDCMUSERGROUP) return("Benutzergruppe");
		return(getTitle(ix, 1));
	};

	return("");
};

void DbsMsdc::VecVMaintable::fillFeed(
			const uint ixMsdcVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=8;i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixMsdcVLocale));
};

/******************************************************************************
 class DbsMsdc::VecVOolop
 ******************************************************************************/

uint DbsMsdc::VecVOolop::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "ina") return INA;
	if (s == "inb") return INB;
	if (s == "rmv") return RMV;
	if (s == "swp") return SWP;
	if (s == "toa") return TOA;
	if (s == "tob") return TOB;

	return(0);
};

string DbsMsdc::VecVOolop::getSref(
			const uint ix
		) {
	if (ix == INA) return("ina");
	if (ix == INB) return("inb");
	if (ix == RMV) return("rmv");
	if (ix == SWP) return("swp");
	if (ix == TOA) return("toa");
	if (ix == TOB) return("tob");

	return("");
};

/******************************************************************************
 class DbsMsdc::VecVPreset
 ******************************************************************************/

uint DbsMsdc::VecVPreset::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "void") return VOID;
	if (s == "premsdcadm") return PREMSDCADM;
	if (s == "premsdcdatapar.x1") return PREMSDCDATAPAR_X1;
	if (s == "premsdcdatapar.x2") return PREMSDCDATAPAR_X2;
	if (s == "premsdcdatlist.aft") return PREMSDCDATLIST_AFT;
	if (s == "premsdcdatlist.prd") return PREMSDCDATLIST_PRD;
	if (s == "premsdcdatlist.sta") return PREMSDCDATLIST_STA;
	if (s == "premsdcfillist.fnm") return PREMSDCFILLIST_FNM;
	if (s == "premsdcfillist.ret") return PREMSDCFILLIST_RET;
	if (s == "premsdcfillist.reu") return PREMSDCFILLIST_REU;
	if (s == "premsdcgrp") return PREMSDCGRP;
	if (s == "premsdcip") return PREMSDCIP;
	if (s == "premsdcixcrdaccdat") return PREMSDCIXCRDACCDAT;
	if (s == "premsdcixcrdaccfil") return PREMSDCIXCRDACCFIL;
	if (s == "premsdcixcrdaccliv") return PREMSDCIXCRDACCLIV;
	if (s == "premsdcixcrdaccprd") return PREMSDCIXCRDACCPRD;
	if (s == "premsdcixcrdaccprs") return PREMSDCIXCRDACCPRS;
	if (s == "premsdcixcrdaccscf") return PREMSDCIXCRDACCSCF;
	if (s == "premsdcixcrdaccusg") return PREMSDCIXCRDACCUSG;
	if (s == "premsdcixcrdaccusr") return PREMSDCIXCRDACCUSR;
	if (s == "premsdcixlcl") return PREMSDCIXLCL;
	if (s == "premsdcixord") return PREMSDCIXORD;
	if (s == "premsdcixpre") return PREMSDCIXPRE;
	if (s == "premsdcixrecacc") return PREMSDCIXRECACC;
	if (s == "premsdcjrefnotify") return PREMSDCJREFNOTIFY;
	if (s == "premsdcjrefsess") return PREMSDCJREFSESS;
	if (s == "premsdcown") return PREMSDCOWN;
	if (s == "premsdcprd") return PREMSDCPRD;
	if (s == "premsdcprdlist.sta") return PREMSDCPRDLIST_STA;
	if (s == "premsdcprslist.grp") return PREMSDCPRSLIST_GRP;
	if (s == "premsdcprslist.lnm") return PREMSDCPRSLIST_LNM;
	if (s == "premsdcprslist.own") return PREMSDCPRSLIST_OWN;
	if (s == "premsdcrefdat") return PREMSDCREFDAT;
	if (s == "premsdcreffil") return PREMSDCREFFIL;
	if (s == "premsdcrefprd") return PREMSDCREFPRD;
	if (s == "premsdcrefprs") return PREMSDCREFPRS;
	if (s == "premsdcrefsel") return PREMSDCREFSEL;
	if (s == "premsdcrefses") return PREMSDCREFSES;
	if (s == "premsdcrefusg") return PREMSDCREFUSG;
	if (s == "premsdcrefusr") return PREMSDCREFUSR;
	if (s == "premsdcsess") return PREMSDCSESS;
	if (s == "premsdcsuspsess") return PREMSDCSUSPSESS;
	if (s == "premsdcsysdate") return PREMSDCSYSDATE;
	if (s == "premsdcsysstamp") return PREMSDCSYSSTAMP;
	if (s == "premsdcsystime") return PREMSDCSYSTIME;
	if (s == "premsdcusgaaccess.x1") return PREMSDCUSGAACCESS_X1;
	if (s == "premsdcusgaaccess.x2") return PREMSDCUSGAACCESS_X2;
	if (s == "premsdcusglist.srf") return PREMSDCUSGLIST_SRF;
	if (s == "premsdcusraaccess.x1") return PREMSDCUSRAACCESS_X1;
	if (s == "premsdcusraaccess.x2") return PREMSDCUSRAACCESS_X2;
	if (s == "premsdcusrlist.prs") return PREMSDCUSRLIST_PRS;
	if (s == "premsdcusrlist.srf") return PREMSDCUSRLIST_SRF;
	if (s == "premsdcusrlist.ste") return PREMSDCUSRLIST_STE;
	if (s == "premsdcusrlist.usg") return PREMSDCUSRLIST_USG;

	return(0);
};

string DbsMsdc::VecVPreset::getSref(
			const uint ix
		) {
	if (ix == VOID) return("void");
	if (ix == PREMSDCADM) return("PreMsdcAdm");
	if (ix == PREMSDCDATAPAR_X1) return("PreMsdcDatAPar.x1");
	if (ix == PREMSDCDATAPAR_X2) return("PreMsdcDatAPar.x2");
	if (ix == PREMSDCDATLIST_AFT) return("PreMsdcDatList.aft");
	if (ix == PREMSDCDATLIST_PRD) return("PreMsdcDatList.prd");
	if (ix == PREMSDCDATLIST_STA) return("PreMsdcDatList.sta");
	if (ix == PREMSDCFILLIST_FNM) return("PreMsdcFilList.fnm");
	if (ix == PREMSDCFILLIST_RET) return("PreMsdcFilList.ret");
	if (ix == PREMSDCFILLIST_REU) return("PreMsdcFilList.reu");
	if (ix == PREMSDCGRP) return("PreMsdcGrp");
	if (ix == PREMSDCIP) return("PreMsdcIp");
	if (ix == PREMSDCIXCRDACCDAT) return("PreMsdcIxCrdaccDat");
	if (ix == PREMSDCIXCRDACCFIL) return("PreMsdcIxCrdaccFil");
	if (ix == PREMSDCIXCRDACCLIV) return("PreMsdcIxCrdaccLiv");
	if (ix == PREMSDCIXCRDACCPRD) return("PreMsdcIxCrdaccPrd");
	if (ix == PREMSDCIXCRDACCPRS) return("PreMsdcIxCrdaccPrs");
	if (ix == PREMSDCIXCRDACCSCF) return("PreMsdcIxCrdaccScf");
	if (ix == PREMSDCIXCRDACCUSG) return("PreMsdcIxCrdaccUsg");
	if (ix == PREMSDCIXCRDACCUSR) return("PreMsdcIxCrdaccUsr");
	if (ix == PREMSDCIXLCL) return("PreMsdcIxLcl");
	if (ix == PREMSDCIXORD) return("PreMsdcIxOrd");
	if (ix == PREMSDCIXPRE) return("PreMsdcIxPre");
	if (ix == PREMSDCIXRECACC) return("PreMsdcIxRecacc");
	if (ix == PREMSDCJREFNOTIFY) return("PreMsdcJrefNotify");
	if (ix == PREMSDCJREFSESS) return("PreMsdcJrefSess");
	if (ix == PREMSDCOWN) return("PreMsdcOwn");
	if (ix == PREMSDCPRD) return("PreMsdcPrd");
	if (ix == PREMSDCPRDLIST_STA) return("PreMsdcPrdList.sta");
	if (ix == PREMSDCPRSLIST_GRP) return("PreMsdcPrsList.grp");
	if (ix == PREMSDCPRSLIST_LNM) return("PreMsdcPrsList.lnm");
	if (ix == PREMSDCPRSLIST_OWN) return("PreMsdcPrsList.own");
	if (ix == PREMSDCREFDAT) return("PreMsdcRefDat");
	if (ix == PREMSDCREFFIL) return("PreMsdcRefFil");
	if (ix == PREMSDCREFPRD) return("PreMsdcRefPrd");
	if (ix == PREMSDCREFPRS) return("PreMsdcRefPrs");
	if (ix == PREMSDCREFSEL) return("PreMsdcRefSel");
	if (ix == PREMSDCREFSES) return("PreMsdcRefSes");
	if (ix == PREMSDCREFUSG) return("PreMsdcRefUsg");
	if (ix == PREMSDCREFUSR) return("PreMsdcRefUsr");
	if (ix == PREMSDCSESS) return("PreMsdcSess");
	if (ix == PREMSDCSUSPSESS) return("PreMsdcSuspsess");
	if (ix == PREMSDCSYSDATE) return("PreMsdcSysdate");
	if (ix == PREMSDCSYSSTAMP) return("PreMsdcSysstamp");
	if (ix == PREMSDCSYSTIME) return("PreMsdcSystime");
	if (ix == PREMSDCUSGAACCESS_X1) return("PreMsdcUsgAAccess.x1");
	if (ix == PREMSDCUSGAACCESS_X2) return("PreMsdcUsgAAccess.x2");
	if (ix == PREMSDCUSGLIST_SRF) return("PreMsdcUsgList.srf");
	if (ix == PREMSDCUSRAACCESS_X1) return("PreMsdcUsrAAccess.x1");
	if (ix == PREMSDCUSRAACCESS_X2) return("PreMsdcUsrAAccess.x2");
	if (ix == PREMSDCUSRLIST_PRS) return("PreMsdcUsrList.prs");
	if (ix == PREMSDCUSRLIST_SRF) return("PreMsdcUsrList.srf");
	if (ix == PREMSDCUSRLIST_STE) return("PreMsdcUsrList.ste");
	if (ix == PREMSDCUSRLIST_USG) return("PreMsdcUsrList.usg");

	return("");
};

string DbsMsdc::VecVPreset::getTitle(
			const uint ix
			, const uint ixMsdcVLocale
		) {
	if (ixMsdcVLocale == 1) {
		if (ix == VOID) return("none");
		if (ix == PREMSDCPRD) return("current acquisition period");
		if (ix == PREMSDCREFDAT) return("raw data");
		if (ix == PREMSDCREFFIL) return("file");
		if (ix == PREMSDCREFPRD) return("acquisition period");
		if (ix == PREMSDCREFPRS) return("person");
		if (ix == PREMSDCREFSES) return("session");
		if (ix == PREMSDCREFUSG) return("user group");
		if (ix == PREMSDCREFUSR) return("user");
		return(getSref(ix));
	} else if (ixMsdcVLocale == 2) {
		if (ix == VOID) return("kein");
		if (ix == PREMSDCPRD) return("aktuelle Aufzeichnungsperiode");
		if (ix == PREMSDCREFDAT) return("Rohdaten");
		if (ix == PREMSDCREFFIL) return("Datei");
		if (ix == PREMSDCREFPRD) return("Aufzeichnungsperiode");
		if (ix == PREMSDCREFPRS) return("Person");
		if (ix == PREMSDCREFSES) return("Sitzung");
		if (ix == PREMSDCREFUSG) return("Benutzergruppe");
		if (ix == PREMSDCREFUSR) return("Benutzer");
		return(getTitle(ix, 1));
	};

	return("");
};

/******************************************************************************
 class DbsMsdc::VecVRecaccess
 ******************************************************************************/

uint DbsMsdc::VecVRecaccess::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "full") return FULL;
	if (s == "none") return NONE;
	if (s == "view") return VIEW;

	return(0);
};

string DbsMsdc::VecVRecaccess::getSref(
			const uint ix
		) {
	if (ix == FULL) return("full");
	if (ix == NONE) return("none");
	if (ix == VIEW) return("view");

	return("");
};

string DbsMsdc::VecVRecaccess::getTitle(
			const uint ix
			, const uint ixMsdcVLocale
		) {
	if (ixMsdcVLocale == 1) {
		if (ix == FULL) return("full");
		if (ix == NONE) return("none");
		if (ix == VIEW) return("view");
		return(getSref(ix));
	} else if (ixMsdcVLocale == 2) {
		if (ix == FULL) return("voll");
		if (ix == NONE) return("kein");
		if (ix == VIEW) return("anschauen");
		return(getTitle(ix, 1));
	};

	return("");
};

void DbsMsdc::VecVRecaccess::fillFeed(
			const uint ixMsdcVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=3;i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixMsdcVLocale));
};

/******************************************************************************
 class DbsMsdc::VecVUserlevel
 ******************************************************************************/

uint DbsMsdc::VecVUserlevel::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "adm") return ADM;
	if (s == "gadm") return GADM;
	if (s == "reg") return REG;
	if (s == "vtor") return VTOR;

	return(0);
};

string DbsMsdc::VecVUserlevel::getSref(
			const uint ix
		) {
	if (ix == ADM) return("adm");
	if (ix == GADM) return("gadm");
	if (ix == REG) return("reg");
	if (ix == VTOR) return("vtor");

	return("");
};

string DbsMsdc::VecVUserlevel::getTitle(
			const uint ix
			, const uint ixMsdcVLocale
		) {
	if (ixMsdcVLocale == 1) {
		if (ix == ADM) return("administrator");
		if (ix == GADM) return("user group administrator");
		if (ix == REG) return("regular user");
		if (ix == VTOR) return("visitor");
		return(getSref(ix));
	} else if (ixMsdcVLocale == 2) {
		if (ix == ADM) return("Administrator");
		if (ix == GADM) return("Gruppenadministrator");
		if (ix == REG) return("regul\\u00e4rer Benutzer");
		if (ix == VTOR) return("Besucher");
		return(getTitle(ix, 1));
	};

	return("");
};

void DbsMsdc::VecVUserlevel::fillFeed(
			const uint ixMsdcVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=4;i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixMsdcVLocale));
};

/******************************************************************************
 class DbsMsdc::VecVValuelist
 ******************************************************************************/

uint DbsMsdc::VecVValuelist::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "vlstmsdcumpersontitle") return VLSTMSDCUMPERSONTITLE;

	return(0);
};

string DbsMsdc::VecVValuelist::getSref(
			const uint ix
		) {
	if (ix == VLSTMSDCUMPERSONTITLE) return("VlstMsdcUMPersonTitle");

	return("");
};

string DbsMsdc::VecVValuelist::getTitle(
			const uint ix
			, const uint ixMsdcVLocale
		) {
	if (ixMsdcVLocale == 1) {
		if (ix == VLSTMSDCUMPERSONTITLE) return("title");
		return(getSref(ix));
	} else if (ixMsdcVLocale == 2) {
		if (ix == VLSTMSDCUMPERSONTITLE) return("Anrede");
		return(getTitle(ix, 1));
	};

	return("");
};

/******************************************************************************
 class DbsMsdc::VecWAccess
 ******************************************************************************/

uint DbsMsdc::VecWAccess::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i=0;i<ss.size();i++) {
		if (ss[i] == "edit") ix |= EDIT;
		else if (ss[i] == "exec") ix |= EXEC;
		else if (ss[i] == "view") ix |= VIEW;
	};

	return(ix);
};

void DbsMsdc::VecWAccess::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*VIEW);i*=2) if (ix & i) ics.insert(i);
};

string DbsMsdc::VecWAccess::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & EDIT) ss.push_back("edit");
	if (ix & EXEC) ss.push_back("exec");
	if (ix & VIEW) ss.push_back("view");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

string DbsMsdc::VecWAccess::getTitle(
			const uint ix
			, const uint ixMsdcVLocale
		) {
	if (ixMsdcVLocale == 1) {
		if (ix == EDIT) return("edit");
		if (ix == EXEC) return("execute");
		if (ix == VIEW) return("view");
		return(getSrefs(ix));
	} else if (ixMsdcVLocale == 2) {
		if (ix == EDIT) return("\\u00e4ndern");
		if (ix == EXEC) return("ausf\\u00fchren");
		if (ix == VIEW) return("anschauen");
		return(getTitle(ix, 1));
	};

	return("");
};

void DbsMsdc::VecWAccess::fillFeed(
			const uint ixMsdcVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=VIEW;i*=2) feed.appendIxSrefTitles(i, getSrefs(i), getTitle(i, ixMsdcVLocale));
};

