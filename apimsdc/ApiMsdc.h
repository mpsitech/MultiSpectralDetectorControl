/**
  * \file ApiMsdc.h
  * Msdc API library global functionality (declarations)
  * \author Alexander Wirthmueller
  * \date created: 12 Sep 2018
  * \date modified: 12 Sep 2018
  */

#ifndef APIMSDC_H
#define APIMSDC_H

#define MSDC_VERSION "0.1.51"
#define MSDC_VERSION_MAJOR 0
#define MSDC_VERSION_MINOR 1
#define MSDC_VERSION_SUB 51

#include "ApiMsdc_blks.h"

#include "MsdcQDatAPar.h"
#include "MsdcQDatList.h"
#include "MsdcQDatRef1NFile.h"
#include "MsdcQFilList.h"
#include "MsdcQPrd1NData.h"
#include "MsdcQPrdList.h"
#include "MsdcQPrsList.h"
#include "MsdcQUsgAAccess.h"
#include "MsdcQUsgList.h"
#include "MsdcQUsgMNUser.h"
#include "MsdcQUsr1NSession.h"
#include "MsdcQUsrAAccess.h"
#include "MsdcQUsrList.h"
#include "MsdcQUsrMNUsergroup.h"

#include "CrdMsdcDat.h"
#include "CrdMsdcFil.h"
#include "CrdMsdcLiv.h"
#include "CrdMsdcNav.h"
#include "CrdMsdcPrd.h"
#include "CrdMsdcPrs.h"
#include "CrdMsdcScf.h"
#include "CrdMsdcUsg.h"
#include "CrdMsdcUsr.h"
#include "DlgMsdcFilDownload.h"
#include "DlgMsdcNavLoaini.h"
#include "JobMsdcAcqLwir.h"
#include "JobMsdcAcqVisl.h"
#include "JobMsdcAcqVisr.h"
#include "JobMsdcActServo.h"
#include "JobMsdcSrcMsdd.h"
#include "JobMsdcSrcTrigger.h"
#include "M2msessMsdc.h"
#include "PnlMsdcDatAPar.h"
#include "PnlMsdcDatDetail.h"
#include "PnlMsdcDatHeadbar.h"
#include "PnlMsdcDatList.h"
#include "PnlMsdcDatRec.h"
#include "PnlMsdcDatRef1NFile.h"
#include "PnlMsdcFilDetail.h"
#include "PnlMsdcFilHeadbar.h"
#include "PnlMsdcFilList.h"
#include "PnlMsdcFilRec.h"
#include "PnlMsdcLivAlign.h"
#include "PnlMsdcLivHeadbar.h"
#include "PnlMsdcLivScill.h"
#include "PnlMsdcLivTrack.h"
#include "PnlMsdcLivVideo.h"
#include "PnlMsdcNavAdmin.h"
#include "PnlMsdcNavHeadbar.h"
#include "PnlMsdcNavOpr.h"
#include "PnlMsdcNavPre.h"
#include "PnlMsdcPrd1NData.h"
#include "PnlMsdcPrdDetail.h"
#include "PnlMsdcPrdHeadbar.h"
#include "PnlMsdcPrdList.h"
#include "PnlMsdcPrdRec.h"
#include "PnlMsdcPrsDetail.h"
#include "PnlMsdcPrsHeadbar.h"
#include "PnlMsdcPrsList.h"
#include "PnlMsdcPrsRec.h"
#include "PnlMsdcScfAcquis.h"
#include "PnlMsdcScfActu.h"
#include "PnlMsdcScfHeadbar.h"
#include "PnlMsdcScfPrcctl.h"
#include "PnlMsdcScfSource.h"
#include "PnlMsdcUsgAAccess.h"
#include "PnlMsdcUsgDetail.h"
#include "PnlMsdcUsgHeadbar.h"
#include "PnlMsdcUsgList.h"
#include "PnlMsdcUsgMNUser.h"
#include "PnlMsdcUsgRec.h"
#include "PnlMsdcUsr1NSession.h"
#include "PnlMsdcUsrAAccess.h"
#include "PnlMsdcUsrDetail.h"
#include "PnlMsdcUsrHeadbar.h"
#include "PnlMsdcUsrList.h"
#include "PnlMsdcUsrMNUsergroup.h"
#include "PnlMsdcUsrRec.h"
#include "QryMsdcDatAPar.h"
#include "QryMsdcDatList.h"
#include "QryMsdcDatRef1NFile.h"
#include "QryMsdcFilList.h"
#include "QryMsdcPrd1NData.h"
#include "QryMsdcPrdList.h"
#include "QryMsdcPrsList.h"
#include "QryMsdcUsgAAccess.h"
#include "QryMsdcUsgList.h"
#include "QryMsdcUsgMNUser.h"
#include "QryMsdcUsr1NSession.h"
#include "QryMsdcUsrAAccess.h"
#include "QryMsdcUsrList.h"
#include "QryMsdcUsrMNUsergroup.h"
#include "RootMsdc.h"
#include "SessMsdc.h"

/**
  * StgMsdcapi
  */
class StgMsdcapi : public Block {

public:
	static const uint ENGIP = 1;
	static const uint ENGPORT = 2;
	static const uint USERNAME = 3;
	static const uint PASSWORD = 4;

public:
	StgMsdcapi(const string engip = "", const uint engport = 0, const string username = "", const string password = "");

public:
	string engip;
	uint engport;
	string username;
	string password;

public:
	static bool all(const set<uint>& items);
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	set<uint> compare(const StgMsdcapi* comp);
};

/**
  * ApiMsdc
  */
namespace ApiMsdc {
	uint readDpchEng(char* buf, unsigned long buflen, DpchEngMsdc** dpcheng);
	void writeDpchApp(DpchAppMsdc* dpchapp, char** buf, unsigned long& buflen, unsigned long ofs = 0);
};

#endif

