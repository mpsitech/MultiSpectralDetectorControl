/**
  * \file VecMsdcVJob.cpp
  * vector VecMsdcVJob (implementation)
  * \author Alexander Wirthmueller
  * \date created: 29 Aug 2018
  * \date modified: 29 Aug 2018
  */

#include "VecMsdcVJob.h"

/******************************************************************************
 namespace VecMsdcVJob
 ******************************************************************************/

uint VecMsdcVJob::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "crdmsdcdat") return CRDMSDCDAT;
	if (s == "crdmsdcfil") return CRDMSDCFIL;
	if (s == "crdmsdcliv") return CRDMSDCLIV;
	if (s == "crdmsdcnav") return CRDMSDCNAV;
	if (s == "crdmsdcprd") return CRDMSDCPRD;
	if (s == "crdmsdcprs") return CRDMSDCPRS;
	if (s == "crdmsdcscf") return CRDMSDCSCF;
	if (s == "crdmsdcusg") return CRDMSDCUSG;
	if (s == "crdmsdcusr") return CRDMSDCUSR;
	if (s == "dlgmsdcfildownload") return DLGMSDCFILDOWNLOAD;
	if (s == "dlgmsdcnavloaini") return DLGMSDCNAVLOAINI;
	if (s == "iexmsdcini") return IEXMSDCINI;
	if (s == "jobmsdcacqadxl") return JOBMSDCACQADXL;
	if (s == "jobmsdcacqlwir") return JOBMSDCACQLWIR;
	if (s == "jobmsdcacqvisl") return JOBMSDCACQVISL;
	if (s == "jobmsdcacqvisr") return JOBMSDCACQVISR;
	if (s == "jobmsdcactalign") return JOBMSDCACTALIGN;
	if (s == "jobmsdcactled") return JOBMSDCACTLED;
	if (s == "jobmsdcactservo") return JOBMSDCACTSERVO;
	if (s == "jobmsdcprcspotfind") return JOBMSDCPRCSPOTFIND;
	if (s == "jobmsdcprcstereo") return JOBMSDCPRCSTEREO;
	if (s == "jobmsdcprctrack") return JOBMSDCPRCTRACK;
	if (s == "jobmsdcsrcmsdd") return JOBMSDCSRCMSDD;
	if (s == "jobmsdcsrctrigger") return JOBMSDCSRCTRIGGER;
	if (s == "m2msessmsdc") return M2MSESSMSDC;
	if (s == "pnlmsdcdatapar") return PNLMSDCDATAPAR;
	if (s == "pnlmsdcdatdetail") return PNLMSDCDATDETAIL;
	if (s == "pnlmsdcdatheadbar") return PNLMSDCDATHEADBAR;
	if (s == "pnlmsdcdatlist") return PNLMSDCDATLIST;
	if (s == "pnlmsdcdatrec") return PNLMSDCDATREC;
	if (s == "pnlmsdcdatref1nfile") return PNLMSDCDATREF1NFILE;
	if (s == "pnlmsdcfildetail") return PNLMSDCFILDETAIL;
	if (s == "pnlmsdcfilheadbar") return PNLMSDCFILHEADBAR;
	if (s == "pnlmsdcfillist") return PNLMSDCFILLIST;
	if (s == "pnlmsdcfilrec") return PNLMSDCFILREC;
	if (s == "pnlmsdclivalign") return PNLMSDCLIVALIGN;
	if (s == "pnlmsdclivheadbar") return PNLMSDCLIVHEADBAR;
	if (s == "pnlmsdclivscill") return PNLMSDCLIVSCILL;
	if (s == "pnlmsdclivtrack") return PNLMSDCLIVTRACK;
	if (s == "pnlmsdclivvideo") return PNLMSDCLIVVIDEO;
	if (s == "pnlmsdcnavadmin") return PNLMSDCNAVADMIN;
	if (s == "pnlmsdcnavheadbar") return PNLMSDCNAVHEADBAR;
	if (s == "pnlmsdcnavopr") return PNLMSDCNAVOPR;
	if (s == "pnlmsdcnavpre") return PNLMSDCNAVPRE;
	if (s == "pnlmsdcprd1ndata") return PNLMSDCPRD1NDATA;
	if (s == "pnlmsdcprddetail") return PNLMSDCPRDDETAIL;
	if (s == "pnlmsdcprdheadbar") return PNLMSDCPRDHEADBAR;
	if (s == "pnlmsdcprdlist") return PNLMSDCPRDLIST;
	if (s == "pnlmsdcprdrec") return PNLMSDCPRDREC;
	if (s == "pnlmsdcprsdetail") return PNLMSDCPRSDETAIL;
	if (s == "pnlmsdcprsheadbar") return PNLMSDCPRSHEADBAR;
	if (s == "pnlmsdcprslist") return PNLMSDCPRSLIST;
	if (s == "pnlmsdcprsrec") return PNLMSDCPRSREC;
	if (s == "pnlmsdcscfacquis") return PNLMSDCSCFACQUIS;
	if (s == "pnlmsdcscfactu") return PNLMSDCSCFACTU;
	if (s == "pnlmsdcscfheadbar") return PNLMSDCSCFHEADBAR;
	if (s == "pnlmsdcscfprcctl") return PNLMSDCSCFPRCCTL;
	if (s == "pnlmsdcscfsource") return PNLMSDCSCFSOURCE;
	if (s == "pnlmsdcusgaaccess") return PNLMSDCUSGAACCESS;
	if (s == "pnlmsdcusgdetail") return PNLMSDCUSGDETAIL;
	if (s == "pnlmsdcusgheadbar") return PNLMSDCUSGHEADBAR;
	if (s == "pnlmsdcusglist") return PNLMSDCUSGLIST;
	if (s == "pnlmsdcusgmnuser") return PNLMSDCUSGMNUSER;
	if (s == "pnlmsdcusgrec") return PNLMSDCUSGREC;
	if (s == "pnlmsdcusr1nsession") return PNLMSDCUSR1NSESSION;
	if (s == "pnlmsdcusraaccess") return PNLMSDCUSRAACCESS;
	if (s == "pnlmsdcusrdetail") return PNLMSDCUSRDETAIL;
	if (s == "pnlmsdcusrheadbar") return PNLMSDCUSRHEADBAR;
	if (s == "pnlmsdcusrlist") return PNLMSDCUSRLIST;
	if (s == "pnlmsdcusrmnusergroup") return PNLMSDCUSRMNUSERGROUP;
	if (s == "pnlmsdcusrrec") return PNLMSDCUSRREC;
	if (s == "qrymsdcdatapar") return QRYMSDCDATAPAR;
	if (s == "qrymsdcdatlist") return QRYMSDCDATLIST;
	if (s == "qrymsdcdatref1nfile") return QRYMSDCDATREF1NFILE;
	if (s == "qrymsdcfillist") return QRYMSDCFILLIST;
	if (s == "qrymsdcprd1ndata") return QRYMSDCPRD1NDATA;
	if (s == "qrymsdcprdlist") return QRYMSDCPRDLIST;
	if (s == "qrymsdcprslist") return QRYMSDCPRSLIST;
	if (s == "qrymsdcusgaaccess") return QRYMSDCUSGAACCESS;
	if (s == "qrymsdcusglist") return QRYMSDCUSGLIST;
	if (s == "qrymsdcusgmnuser") return QRYMSDCUSGMNUSER;
	if (s == "qrymsdcusr1nsession") return QRYMSDCUSR1NSESSION;
	if (s == "qrymsdcusraaccess") return QRYMSDCUSRAACCESS;
	if (s == "qrymsdcusrlist") return QRYMSDCUSRLIST;
	if (s == "qrymsdcusrmnusergroup") return QRYMSDCUSRMNUSERGROUP;
	if (s == "rootmsdc") return ROOTMSDC;
	if (s == "sessmsdc") return SESSMSDC;

	return(0);
};

string VecMsdcVJob::getSref(
			const uint ix
		) {
	if (ix == CRDMSDCDAT) return("CrdMsdcDat");
	if (ix == CRDMSDCFIL) return("CrdMsdcFil");
	if (ix == CRDMSDCLIV) return("CrdMsdcLiv");
	if (ix == CRDMSDCNAV) return("CrdMsdcNav");
	if (ix == CRDMSDCPRD) return("CrdMsdcPrd");
	if (ix == CRDMSDCPRS) return("CrdMsdcPrs");
	if (ix == CRDMSDCSCF) return("CrdMsdcScf");
	if (ix == CRDMSDCUSG) return("CrdMsdcUsg");
	if (ix == CRDMSDCUSR) return("CrdMsdcUsr");
	if (ix == DLGMSDCFILDOWNLOAD) return("DlgMsdcFilDownload");
	if (ix == DLGMSDCNAVLOAINI) return("DlgMsdcNavLoaini");
	if (ix == IEXMSDCINI) return("IexMsdcIni");
	if (ix == JOBMSDCACQADXL) return("JobMsdcAcqAdxl");
	if (ix == JOBMSDCACQLWIR) return("JobMsdcAcqLwir");
	if (ix == JOBMSDCACQVISL) return("JobMsdcAcqVisl");
	if (ix == JOBMSDCACQVISR) return("JobMsdcAcqVisr");
	if (ix == JOBMSDCACTALIGN) return("JobMsdcActAlign");
	if (ix == JOBMSDCACTLED) return("JobMsdcActLed");
	if (ix == JOBMSDCACTSERVO) return("JobMsdcActServo");
	if (ix == JOBMSDCPRCSPOTFIND) return("JobMsdcPrcSpotfind");
	if (ix == JOBMSDCPRCSTEREO) return("JobMsdcPrcStereo");
	if (ix == JOBMSDCPRCTRACK) return("JobMsdcPrcTrack");
	if (ix == JOBMSDCSRCMSDD) return("JobMsdcSrcMsdd");
	if (ix == JOBMSDCSRCTRIGGER) return("JobMsdcSrcTrigger");
	if (ix == M2MSESSMSDC) return("M2msessMsdc");
	if (ix == PNLMSDCDATAPAR) return("PnlMsdcDatAPar");
	if (ix == PNLMSDCDATDETAIL) return("PnlMsdcDatDetail");
	if (ix == PNLMSDCDATHEADBAR) return("PnlMsdcDatHeadbar");
	if (ix == PNLMSDCDATLIST) return("PnlMsdcDatList");
	if (ix == PNLMSDCDATREC) return("PnlMsdcDatRec");
	if (ix == PNLMSDCDATREF1NFILE) return("PnlMsdcDatRef1NFile");
	if (ix == PNLMSDCFILDETAIL) return("PnlMsdcFilDetail");
	if (ix == PNLMSDCFILHEADBAR) return("PnlMsdcFilHeadbar");
	if (ix == PNLMSDCFILLIST) return("PnlMsdcFilList");
	if (ix == PNLMSDCFILREC) return("PnlMsdcFilRec");
	if (ix == PNLMSDCLIVALIGN) return("PnlMsdcLivAlign");
	if (ix == PNLMSDCLIVHEADBAR) return("PnlMsdcLivHeadbar");
	if (ix == PNLMSDCLIVSCILL) return("PnlMsdcLivScill");
	if (ix == PNLMSDCLIVTRACK) return("PnlMsdcLivTrack");
	if (ix == PNLMSDCLIVVIDEO) return("PnlMsdcLivVideo");
	if (ix == PNLMSDCNAVADMIN) return("PnlMsdcNavAdmin");
	if (ix == PNLMSDCNAVHEADBAR) return("PnlMsdcNavHeadbar");
	if (ix == PNLMSDCNAVOPR) return("PnlMsdcNavOpr");
	if (ix == PNLMSDCNAVPRE) return("PnlMsdcNavPre");
	if (ix == PNLMSDCPRD1NDATA) return("PnlMsdcPrd1NData");
	if (ix == PNLMSDCPRDDETAIL) return("PnlMsdcPrdDetail");
	if (ix == PNLMSDCPRDHEADBAR) return("PnlMsdcPrdHeadbar");
	if (ix == PNLMSDCPRDLIST) return("PnlMsdcPrdList");
	if (ix == PNLMSDCPRDREC) return("PnlMsdcPrdRec");
	if (ix == PNLMSDCPRSDETAIL) return("PnlMsdcPrsDetail");
	if (ix == PNLMSDCPRSHEADBAR) return("PnlMsdcPrsHeadbar");
	if (ix == PNLMSDCPRSLIST) return("PnlMsdcPrsList");
	if (ix == PNLMSDCPRSREC) return("PnlMsdcPrsRec");
	if (ix == PNLMSDCSCFACQUIS) return("PnlMsdcScfAcquis");
	if (ix == PNLMSDCSCFACTU) return("PnlMsdcScfActu");
	if (ix == PNLMSDCSCFHEADBAR) return("PnlMsdcScfHeadbar");
	if (ix == PNLMSDCSCFPRCCTL) return("PnlMsdcScfPrcctl");
	if (ix == PNLMSDCSCFSOURCE) return("PnlMsdcScfSource");
	if (ix == PNLMSDCUSGAACCESS) return("PnlMsdcUsgAAccess");
	if (ix == PNLMSDCUSGDETAIL) return("PnlMsdcUsgDetail");
	if (ix == PNLMSDCUSGHEADBAR) return("PnlMsdcUsgHeadbar");
	if (ix == PNLMSDCUSGLIST) return("PnlMsdcUsgList");
	if (ix == PNLMSDCUSGMNUSER) return("PnlMsdcUsgMNUser");
	if (ix == PNLMSDCUSGREC) return("PnlMsdcUsgRec");
	if (ix == PNLMSDCUSR1NSESSION) return("PnlMsdcUsr1NSession");
	if (ix == PNLMSDCUSRAACCESS) return("PnlMsdcUsrAAccess");
	if (ix == PNLMSDCUSRDETAIL) return("PnlMsdcUsrDetail");
	if (ix == PNLMSDCUSRHEADBAR) return("PnlMsdcUsrHeadbar");
	if (ix == PNLMSDCUSRLIST) return("PnlMsdcUsrList");
	if (ix == PNLMSDCUSRMNUSERGROUP) return("PnlMsdcUsrMNUsergroup");
	if (ix == PNLMSDCUSRREC) return("PnlMsdcUsrRec");
	if (ix == QRYMSDCDATAPAR) return("QryMsdcDatAPar");
	if (ix == QRYMSDCDATLIST) return("QryMsdcDatList");
	if (ix == QRYMSDCDATREF1NFILE) return("QryMsdcDatRef1NFile");
	if (ix == QRYMSDCFILLIST) return("QryMsdcFilList");
	if (ix == QRYMSDCPRD1NDATA) return("QryMsdcPrd1NData");
	if (ix == QRYMSDCPRDLIST) return("QryMsdcPrdList");
	if (ix == QRYMSDCPRSLIST) return("QryMsdcPrsList");
	if (ix == QRYMSDCUSGAACCESS) return("QryMsdcUsgAAccess");
	if (ix == QRYMSDCUSGLIST) return("QryMsdcUsgList");
	if (ix == QRYMSDCUSGMNUSER) return("QryMsdcUsgMNUser");
	if (ix == QRYMSDCUSR1NSESSION) return("QryMsdcUsr1NSession");
	if (ix == QRYMSDCUSRAACCESS) return("QryMsdcUsrAAccess");
	if (ix == QRYMSDCUSRLIST) return("QryMsdcUsrList");
	if (ix == QRYMSDCUSRMNUSERGROUP) return("QryMsdcUsrMNUsergroup");
	if (ix == ROOTMSDC) return("RootMsdc");
	if (ix == SESSMSDC) return("SessMsdc");

	return("");
};

