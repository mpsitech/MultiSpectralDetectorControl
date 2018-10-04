/**
  * \file ApiMsdc.cpp
  * Msdc API library global functionality (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Oct 2018
  * \date modified: 4 Oct 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "ApiMsdc.h"

/******************************************************************************
 class StgMsdcapi
 ******************************************************************************/

StgMsdcapi::StgMsdcapi(
			const string engip
			, const uint engport
			, const string username
			, const string password
		) :
			Block()
		{
	this->engip = engip;
	this->engport = engport;
	this->username = username;
	this->password = password;

	mask = {ENGIP, ENGPORT, USERNAME, PASSWORD};
};

bool StgMsdcapi::all(
			const set<uint>& items
		) {
	if (!find(items, ENGIP)) return false;
	if (!find(items, ENGPORT)) return false;
	if (!find(items, USERNAME)) return false;
	if (!find(items, PASSWORD)) return false;

	return true;
};

bool StgMsdcapi::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgMsdcapi");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemMsdcapi";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "engip", engip)) add(ENGIP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "engport", engport)) add(ENGPORT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "username", username)) add(USERNAME);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "password", password)) add(PASSWORD);
	};

	return basefound;
};

void StgMsdcapi::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgMsdcapi";

	string itemtag;
	if (shorttags)
		itemtag = "Si";
	else
		itemtag = "StgitemMsdcapi";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "engip", engip);
		writeUintAttr(wr, itemtag, "sref", "engport", engport);
		writeStringAttr(wr, itemtag, "sref", "username", username);
		writeStringAttr(wr, itemtag, "sref", "password", password);
	xmlTextWriterEndElement(wr);
};

set<uint> StgMsdcapi::compare(
			const StgMsdcapi* comp
		) {
	set<uint> items;

	if (engip == comp->engip) insert(items, ENGIP);
	if (engport == comp->engport) insert(items, ENGPORT);
	if (username == comp->username) insert(items, USERNAME);
	if (password == comp->password) insert(items, PASSWORD);

	return items;
};

/******************************************************************************
 namespace ApiMsdc
 ******************************************************************************/

uint ApiMsdc::readDpchEng(
			char* buf
			, unsigned long buflen
			, DpchEngMsdc** dpcheng
		) {
	xmlDoc* doc = NULL;
	xmlXPathContext* docctx = NULL;

	parseBuffer(buf, buflen, &doc, &docctx);

	uint ixMsdcVDpch = VecMsdcVDpch::getIx(extractRoot(doc));

	if (ixMsdcVDpch == VecMsdcVDpch::DPCHENGDLGMSDCFILDOWNLOADDATA) {
		*dpcheng = new DlgMsdcFilDownload::DpchEngData();
		((DlgMsdcFilDownload::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHENGDLGMSDCNAVLOAINIDATA) {
		*dpcheng = new DlgMsdcNavLoaini::DpchEngData();
		((DlgMsdcNavLoaini::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHENGM2MSESSMSDCDATA) {
		*dpcheng = new M2msessMsdc::DpchEngData();
		((M2msessMsdc::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHENGMSDCACK) {
		*dpcheng = new DpchEngMsdcAck();
		((DpchEngMsdcAck*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHENGMSDCALERT) {
		*dpcheng = new DpchEngMsdcAlert();
		((DpchEngMsdcAlert*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHENGMSDCCONFIRM) {
		*dpcheng = new DpchEngMsdcConfirm();
		((DpchEngMsdcConfirm*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHENGMSDCDATAPARDATA) {
		*dpcheng = new PnlMsdcDatAPar::DpchEngData();
		((PnlMsdcDatAPar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHENGMSDCDATDATA) {
		*dpcheng = new CrdMsdcDat::DpchEngData();
		((CrdMsdcDat::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHENGMSDCDATDETAILDATA) {
		*dpcheng = new PnlMsdcDatDetail::DpchEngData();
		((PnlMsdcDatDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHENGMSDCDATHEADBARDATA) {
		*dpcheng = new PnlMsdcDatHeadbar::DpchEngData();
		((PnlMsdcDatHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHENGMSDCDATLISTDATA) {
		*dpcheng = new PnlMsdcDatList::DpchEngData();
		((PnlMsdcDatList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHENGMSDCDATRECDATA) {
		*dpcheng = new PnlMsdcDatRec::DpchEngData();
		((PnlMsdcDatRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHENGMSDCDATREF1NFILEDATA) {
		*dpcheng = new PnlMsdcDatRef1NFile::DpchEngData();
		((PnlMsdcDatRef1NFile::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHENGMSDCFILDATA) {
		*dpcheng = new CrdMsdcFil::DpchEngData();
		((CrdMsdcFil::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHENGMSDCFILDETAILDATA) {
		*dpcheng = new PnlMsdcFilDetail::DpchEngData();
		((PnlMsdcFilDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHENGMSDCFILHEADBARDATA) {
		*dpcheng = new PnlMsdcFilHeadbar::DpchEngData();
		((PnlMsdcFilHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHENGMSDCFILLISTDATA) {
		*dpcheng = new PnlMsdcFilList::DpchEngData();
		((PnlMsdcFilList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHENGMSDCFILRECDATA) {
		*dpcheng = new PnlMsdcFilRec::DpchEngData();
		((PnlMsdcFilRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHENGMSDCLIVALIGNDATA) {
		*dpcheng = new PnlMsdcLivAlign::DpchEngData();
		((PnlMsdcLivAlign::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHENGMSDCLIVDATA) {
		*dpcheng = new CrdMsdcLiv::DpchEngData();
		((CrdMsdcLiv::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHENGMSDCLIVHEADBARDATA) {
		*dpcheng = new PnlMsdcLivHeadbar::DpchEngData();
		((PnlMsdcLivHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHENGMSDCLIVSCILLDATA) {
		*dpcheng = new PnlMsdcLivScill::DpchEngData();
		((PnlMsdcLivScill::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHENGMSDCLIVTRACKDATA) {
		*dpcheng = new PnlMsdcLivTrack::DpchEngData();
		((PnlMsdcLivTrack::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHENGMSDCLIVVIDEODATA) {
		*dpcheng = new PnlMsdcLivVideo::DpchEngData();
		((PnlMsdcLivVideo::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHENGMSDCLIVVIDEOLIVE) {
		*dpcheng = new PnlMsdcLivVideo::DpchEngLive();
		((PnlMsdcLivVideo::DpchEngLive*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHENGMSDCNAVADMINDATA) {
		*dpcheng = new PnlMsdcNavAdmin::DpchEngData();
		((PnlMsdcNavAdmin::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHENGMSDCNAVDATA) {
		*dpcheng = new CrdMsdcNav::DpchEngData();
		((CrdMsdcNav::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHENGMSDCNAVHEADBARDATA) {
		*dpcheng = new PnlMsdcNavHeadbar::DpchEngData();
		((PnlMsdcNavHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHENGMSDCNAVOPRDATA) {
		*dpcheng = new PnlMsdcNavOpr::DpchEngData();
		((PnlMsdcNavOpr::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHENGMSDCNAVPREDATA) {
		*dpcheng = new PnlMsdcNavPre::DpchEngData();
		((PnlMsdcNavPre::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHENGMSDCPRD1NDATADATA) {
		*dpcheng = new PnlMsdcPrd1NData::DpchEngData();
		((PnlMsdcPrd1NData::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHENGMSDCPRDDATA) {
		*dpcheng = new CrdMsdcPrd::DpchEngData();
		((CrdMsdcPrd::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHENGMSDCPRDDETAILDATA) {
		*dpcheng = new PnlMsdcPrdDetail::DpchEngData();
		((PnlMsdcPrdDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHENGMSDCPRDHEADBARDATA) {
		*dpcheng = new PnlMsdcPrdHeadbar::DpchEngData();
		((PnlMsdcPrdHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHENGMSDCPRDLISTDATA) {
		*dpcheng = new PnlMsdcPrdList::DpchEngData();
		((PnlMsdcPrdList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHENGMSDCPRDRECDATA) {
		*dpcheng = new PnlMsdcPrdRec::DpchEngData();
		((PnlMsdcPrdRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHENGMSDCPRSDATA) {
		*dpcheng = new CrdMsdcPrs::DpchEngData();
		((CrdMsdcPrs::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHENGMSDCPRSDETAILDATA) {
		*dpcheng = new PnlMsdcPrsDetail::DpchEngData();
		((PnlMsdcPrsDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHENGMSDCPRSHEADBARDATA) {
		*dpcheng = new PnlMsdcPrsHeadbar::DpchEngData();
		((PnlMsdcPrsHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHENGMSDCPRSLISTDATA) {
		*dpcheng = new PnlMsdcPrsList::DpchEngData();
		((PnlMsdcPrsList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHENGMSDCPRSRECDATA) {
		*dpcheng = new PnlMsdcPrsRec::DpchEngData();
		((PnlMsdcPrsRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHENGMSDCSCFACQUISDATA) {
		*dpcheng = new PnlMsdcScfAcquis::DpchEngData();
		((PnlMsdcScfAcquis::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHENGMSDCSCFACTUDATA) {
		*dpcheng = new PnlMsdcScfActu::DpchEngData();
		((PnlMsdcScfActu::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHENGMSDCSCFDATA) {
		*dpcheng = new CrdMsdcScf::DpchEngData();
		((CrdMsdcScf::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHENGMSDCSCFHEADBARDATA) {
		*dpcheng = new PnlMsdcScfHeadbar::DpchEngData();
		((PnlMsdcScfHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHENGMSDCSCFPRCCTLDATA) {
		*dpcheng = new PnlMsdcScfPrcctl::DpchEngData();
		((PnlMsdcScfPrcctl::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHENGMSDCSCFSOURCEDATA) {
		*dpcheng = new PnlMsdcScfSource::DpchEngData();
		((PnlMsdcScfSource::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHENGMSDCSUSPEND) {
		*dpcheng = new DpchEngMsdcSuspend();
		((DpchEngMsdcSuspend*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHENGMSDCUSGAACCESSDATA) {
		*dpcheng = new PnlMsdcUsgAAccess::DpchEngData();
		((PnlMsdcUsgAAccess::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHENGMSDCUSGDATA) {
		*dpcheng = new CrdMsdcUsg::DpchEngData();
		((CrdMsdcUsg::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHENGMSDCUSGDETAILDATA) {
		*dpcheng = new PnlMsdcUsgDetail::DpchEngData();
		((PnlMsdcUsgDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHENGMSDCUSGHEADBARDATA) {
		*dpcheng = new PnlMsdcUsgHeadbar::DpchEngData();
		((PnlMsdcUsgHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHENGMSDCUSGLISTDATA) {
		*dpcheng = new PnlMsdcUsgList::DpchEngData();
		((PnlMsdcUsgList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHENGMSDCUSGMNUSERDATA) {
		*dpcheng = new PnlMsdcUsgMNUser::DpchEngData();
		((PnlMsdcUsgMNUser::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHENGMSDCUSGRECDATA) {
		*dpcheng = new PnlMsdcUsgRec::DpchEngData();
		((PnlMsdcUsgRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHENGMSDCUSR1NSESSIONDATA) {
		*dpcheng = new PnlMsdcUsr1NSession::DpchEngData();
		((PnlMsdcUsr1NSession::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHENGMSDCUSRAACCESSDATA) {
		*dpcheng = new PnlMsdcUsrAAccess::DpchEngData();
		((PnlMsdcUsrAAccess::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHENGMSDCUSRDATA) {
		*dpcheng = new CrdMsdcUsr::DpchEngData();
		((CrdMsdcUsr::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHENGMSDCUSRDETAILDATA) {
		*dpcheng = new PnlMsdcUsrDetail::DpchEngData();
		((PnlMsdcUsrDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHENGMSDCUSRHEADBARDATA) {
		*dpcheng = new PnlMsdcUsrHeadbar::DpchEngData();
		((PnlMsdcUsrHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHENGMSDCUSRLISTDATA) {
		*dpcheng = new PnlMsdcUsrList::DpchEngData();
		((PnlMsdcUsrList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHENGMSDCUSRMNUSERGROUPDATA) {
		*dpcheng = new PnlMsdcUsrMNUsergroup::DpchEngData();
		((PnlMsdcUsrMNUsergroup::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHENGMSDCUSRRECDATA) {
		*dpcheng = new PnlMsdcUsrRec::DpchEngData();
		((PnlMsdcUsrRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHENGROOTMSDCDATA) {
		*dpcheng = new RootMsdc::DpchEngData();
		((RootMsdc::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHENGSESSMSDCDATA) {
		*dpcheng = new SessMsdc::DpchEngData();
		((SessMsdc::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
	};

	if (docctx) xmlXPathFreeContext(docctx);
	if (doc) xmlFreeDoc(doc);
	
	return ixMsdcVDpch;
};

void ApiMsdc::writeDpchApp(
			DpchAppMsdc* dpchapp
			, char** buf
			, unsigned long& buflen
			, unsigned long ofs
		) {
	xmlBuffer* xbuf = NULL;
	xmlTextWriter* wr = NULL;

	startwriteBuffer(&wr, &xbuf);
		dpchapp->writeXML(wr);
	closewriteBuffer(wr);

	buflen = xbuf->use + ofs;
	*buf = new char[buflen];
	memcpy(&((*buf)[ofs]), xbuf->content, buflen-ofs);

	xmlBufferFree(xbuf);
};

