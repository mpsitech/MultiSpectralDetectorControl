/**
  * \file Msdccmbd.cpp
  * inter-thread exchange object for Msdc combined daemon (implementation)
  * \author Alexander Wirthmueller
  * \date created: 15 Aug 2018
  * \date modified: 15 Aug 2018
  */

#include "Msdccmbd.h"

/******************************************************************************
 class DpchAppMsdc
 ******************************************************************************/

DpchAppMsdc::DpchAppMsdc(
			const uint ixMsdcVDpch
		) : DpchMsdc(ixMsdcVDpch) {
	jref = 0;
};

DpchAppMsdc::~DpchAppMsdc() {
};

bool DpchAppMsdc::all(
			const set<uint>& items
		) {
	if (!find(items, JREF)) return false;

	return true;
};

string DpchAppMsdc::getSrefsMask() {
	if (has(JREF)) return("jref");
	else return("");
};

void DpchAppMsdc::readXML(
			pthread_mutex_t* mScr
			, map<string,ubigint>& descr
			, xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	string scrJref;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, VecMsdcVDpch::getSref(ixMsdcVDpch));
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) {
			jref = Scr::descramble(mScr, descr, scrJref);
			add(JREF);
		};
	};
};

/******************************************************************************
 class DpchAppMsdcAlert
 ******************************************************************************/

DpchAppMsdcAlert::DpchAppMsdcAlert() : DpchAppMsdc(VecMsdcVDpch::DPCHAPPMSDCALERT) {
};

bool DpchAppMsdcAlert::all(
			const set<uint>& items
		) {
	if (!find(items, JREF)) return false;
	if (!find(items, NUMFMCB)) return false;

	return true;
};

string DpchAppMsdcAlert::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(NUMFMCB)) ss.push_back("numFMcb");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DpchAppMsdcAlert::readXML(
			pthread_mutex_t* mScr
			, map<string,ubigint>& descr
			, xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppMsdcAlert");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) {
			jref = Scr::descramble(mScr, descr, scrJref);
			add(JREF);
		};
		if (extractUintUclc(docctx, basexpath, "numFMcb", "", numFMcb)) add(NUMFMCB);
	} else {
	};
};

/******************************************************************************
 class DpchAppMsdcInit
 ******************************************************************************/

DpchAppMsdcInit::DpchAppMsdcInit() : DpchAppMsdc(VecMsdcVDpch::DPCHAPPMSDCINIT) {
};

/******************************************************************************
 class DpchAppMsdcResume
 ******************************************************************************/

DpchAppMsdcResume::DpchAppMsdcResume() : DpchAppMsdc(VecMsdcVDpch::DPCHAPPMSDCRESUME) {
};

/******************************************************************************
 class DpchEngMsdc
 ******************************************************************************/

DpchEngMsdc::DpchEngMsdc(
			const uint ixMsdcVDpch
			, const ubigint jref
		) : DpchMsdc(ixMsdcVDpch) {
	this->jref = jref;

	mask = {JREF};
};

DpchEngMsdc::~DpchEngMsdc() {
};

bool DpchEngMsdc::all(
			const set<uint>& items
		) {
	if (!find(items, JREF)) return false;

	return true;
};

string DpchEngMsdc::getSrefsMask() {
	if (has(JREF)) return("jref");
	else return("");
};

void DpchEngMsdc::merge(
			DpchEngMsdc* dpcheng
		) {
	DpchEngMsdc* src = dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
};

void DpchEngMsdc::writeXML(
			const uint ixMsdcVLocale
			, pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	string tag = VecMsdcVDpch::getSref(ixMsdcVDpch);

	xmlTextWriterStartElement(wr, BAD_CAST tag.c_str());
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/msdc");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchEngMsdcAck
 ******************************************************************************/

DpchEngMsdcAck::DpchEngMsdcAck(
			const ubigint jref
		) : DpchEngMsdc(VecMsdcVDpch::DPCHENGMSDCACK, jref) {
};

/******************************************************************************
 class DpchEngMsdcAlert
 ******************************************************************************/

DpchEngMsdcAlert::DpchEngMsdcAlert(
			const ubigint jref
			, ContInfMsdcAlert* continf
			, Feed* feedFMcb
			, const set<uint>& mask
		) : DpchEngMsdc(VecMsdcVDpch::DPCHENGMSDCALERT, jref) {
	if (continf) this->continf = *continf;
	if (feedFMcb) this->feedFMcb = *feedFMcb;

	if (find(mask, ALL)) this->mask = {JREF, CONTINF, FEEDFMCB};
	else this->mask = mask;
};

bool DpchEngMsdcAlert::all(
			const set<uint>& items
		) {
	if (!find(items, JREF)) return false;
	if (!find(items, CONTINF)) return false;
	if (!find(items, FEEDFMCB)) return false;

	return true;
};

string DpchEngMsdcAlert::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFMCB)) ss.push_back("feedFMcb");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DpchEngMsdcAlert::merge(
			DpchEngMsdc* dpcheng
		) {
	DpchEngMsdcAlert* src = (DpchEngMsdcAlert*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFMCB)) {feedFMcb = src->feedFMcb; add(FEEDFMCB);};
};

void DpchEngMsdcAlert::writeXML(
			const uint ixMsdcVLocale
			, pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngMsdcAlert");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/msdc");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFMCB)) feedFMcb.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchEngMsdcConfirm
 ******************************************************************************/

DpchEngMsdcConfirm::DpchEngMsdcConfirm(
			const bool accepted
			, const ubigint jref
			, const string& sref
			, const set<uint>& mask
		) : DpchEngMsdc(VecMsdcVDpch::DPCHENGMSDCCONFIRM, jref) {
	this->accepted = accepted;
	this->jref = jref;
	this->sref = sref;

	if (find(mask, ALL)) this->mask = {ACCEPTED, JREF, SREF};
	else this->mask = mask;
};

bool DpchEngMsdcConfirm::all(
			const set<uint>& items
		) {
	if (!find(items, ACCEPTED)) return false;
	if (!find(items, JREF)) return false;
	if (!find(items, SREF)) return false;

	return true;
};

string DpchEngMsdcConfirm::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(ACCEPTED)) ss.push_back("accepted");
	if (has(JREF)) ss.push_back("jref");
	if (has(SREF)) ss.push_back("sref");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DpchEngMsdcConfirm::merge(
			DpchEngMsdc* dpcheng
		) {
	DpchEngMsdcConfirm* src = (DpchEngMsdcConfirm*) dpcheng;

	if (src->has(ACCEPTED)) {accepted = src->accepted; add(ACCEPTED);};
	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(SREF)) {sref = src->sref; add(SREF);};
};

void DpchEngMsdcConfirm::writeXML(
			const uint ixMsdcVLocale
			, pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngMsdcConfirm");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/msdc");
		if (has(ACCEPTED)) writeBool(wr, "accepted", accepted);
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		if (has(SREF)) writeString(wr, "sref", sref);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchEngMsdcSuspend
 ******************************************************************************/

DpchEngMsdcSuspend::DpchEngMsdcSuspend(
			const ubigint jref
		) : DpchEngMsdc(VecMsdcVDpch::DPCHENGMSDCSUSPEND, jref) {
};

/******************************************************************************
 class StgMsdccmbd
 ******************************************************************************/

StgMsdccmbd::StgMsdccmbd(
			const usmallint jobprcn
			, const usmallint opprcn
			, const usmallint appsrvport
			, const bool https
			, const bool appsrv
			, const bool ddspub
			, const bool uasrv
			, const usmallint histlength
		) : Block() {
	this->jobprcn = jobprcn;
	this->opprcn = opprcn;
	this->appsrvport = appsrvport;
	this->https = https;
	this->appsrv = appsrv;
	this->ddspub = ddspub;
	this->uasrv = uasrv;
	this->histlength = histlength;
	mask = {JOBPRCN, OPPRCN, APPSRVPORT, HTTPS, APPSRV, DDSPUB, UASRV, HISTLENGTH};
};

bool StgMsdccmbd::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgMsdccmbd");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemMsdccmbd";

	if (basefound) {
		if (extractUsmallintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "jobprcn", jobprcn)) add(JOBPRCN);
		if (extractUsmallintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "opprcn", opprcn)) add(OPPRCN);
		if (extractUsmallintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "appsrvport", appsrvport)) add(APPSRVPORT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "https", https)) add(HTTPS);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "appsrv", appsrv)) add(APPSRV);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ddspub", ddspub)) add(DDSPUB);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "uasrv", uasrv)) add(UASRV);
		if (extractUsmallintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "histlength", histlength)) add(HISTLENGTH);
	};

	return basefound;
};

void StgMsdccmbd::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgMsdccmbd";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemMsdccmbd";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUsmallintAttr(wr, itemtag, "sref", "jobprcn", jobprcn);
		writeUsmallintAttr(wr, itemtag, "sref", "opprcn", opprcn);
		writeUsmallintAttr(wr, itemtag, "sref", "appsrvport", appsrvport);
		writeBoolAttr(wr, itemtag, "sref", "https", https);
		writeBoolAttr(wr, itemtag, "sref", "appsrv", appsrv);
		writeBoolAttr(wr, itemtag, "sref", "ddspub", ddspub);
		writeBoolAttr(wr, itemtag, "sref", "uasrv", uasrv);
		writeUsmallintAttr(wr, itemtag, "sref", "histlength", histlength);
	xmlTextWriterEndElement(wr);
};

set<uint> StgMsdccmbd::comm(
			const StgMsdccmbd* comp
		) {
	set<uint> items;

	if (jobprcn == comp->jobprcn) insert(items, JOBPRCN);
	if (opprcn == comp->opprcn) insert(items, OPPRCN);
	if (appsrvport == comp->appsrvport) insert(items, APPSRVPORT);
	if (https == comp->https) insert(items, HTTPS);
	if (appsrv == comp->appsrv) insert(items, APPSRV);
	if (ddspub == comp->ddspub) insert(items, DDSPUB);
	if (uasrv == comp->uasrv) insert(items, UASRV);
	if (histlength == comp->histlength) insert(items, HISTLENGTH);

	return(items);
};

set<uint> StgMsdccmbd::diff(
			const StgMsdccmbd* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {JOBPRCN, OPPRCN, APPSRVPORT, HTTPS, APPSRV, DDSPUB, UASRV, HISTLENGTH};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class StgMsdcDatabase
 ******************************************************************************/

StgMsdcDatabase::StgMsdcDatabase(
			const uint ixDbsVDbstype
			, const string& dbspath
			, const string& dbsname
			, const string& username
			, const string& password
			, const string& ip
			, const usmallint port
		) : Block() {
	this->ixDbsVDbstype = ixDbsVDbstype;
	this->dbspath = dbspath;
	this->dbsname = dbsname;
	this->username = username;
	this->password = password;
	this->ip = ip;
	this->port = port;
	mask = {IXDBSVDBSTYPE, DBSPATH, DBSNAME, USERNAME, PASSWORD, IP, PORT};
};

bool StgMsdcDatabase::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxDbsVDbstype;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgMsdcDatabase");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemMsdcDatabase";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxDbsVDbstype", srefIxDbsVDbstype)) {
			ixDbsVDbstype = VecDbsVDbstype::getIx(srefIxDbsVDbstype);
			add(IXDBSVDBSTYPE);
		};
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "dbspath", dbspath)) add(DBSPATH);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "dbsname", dbsname)) add(DBSNAME);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "username", username)) add(USERNAME);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "password", password)) add(PASSWORD);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ip", ip)) add(IP);
		if (extractUsmallintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "port", port)) add(PORT);
	};

	return basefound;
};

void StgMsdcDatabase::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgMsdcDatabase";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemMsdcDatabase";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxDbsVDbstype", VecDbsVDbstype::getSref(ixDbsVDbstype));
		writeStringAttr(wr, itemtag, "sref", "dbspath", dbspath);
		writeStringAttr(wr, itemtag, "sref", "dbsname", dbsname);
		writeStringAttr(wr, itemtag, "sref", "username", username);
		writeStringAttr(wr, itemtag, "sref", "password", password);
		writeStringAttr(wr, itemtag, "sref", "ip", ip);
		writeUsmallintAttr(wr, itemtag, "sref", "port", port);
	xmlTextWriterEndElement(wr);
};

set<uint> StgMsdcDatabase::comm(
			const StgMsdcDatabase* comp
		) {
	set<uint> items;

	if (ixDbsVDbstype == comp->ixDbsVDbstype) insert(items, IXDBSVDBSTYPE);
	if (dbspath == comp->dbspath) insert(items, DBSPATH);
	if (dbsname == comp->dbsname) insert(items, DBSNAME);
	if (username == comp->username) insert(items, USERNAME);
	if (password == comp->password) insert(items, PASSWORD);
	if (ip == comp->ip) insert(items, IP);
	if (port == comp->port) insert(items, PORT);

	return(items);
};

set<uint> StgMsdcDatabase::diff(
			const StgMsdcDatabase* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXDBSVDBSTYPE, DBSPATH, DBSNAME, USERNAME, PASSWORD, IP, PORT};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class StgMsdcDdspub
 ******************************************************************************/

StgMsdcDdspub::StgMsdcDdspub(
			const string& username
			, const string& password
		) : Block() {
	this->username = username;
	this->password = password;
	mask = {USERNAME, PASSWORD};
};

bool StgMsdcDdspub::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgMsdcDdspub");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemMsdcDdspub";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "username", username)) add(USERNAME);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "password", password)) add(PASSWORD);
	};

	return basefound;
};

void StgMsdcDdspub::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgMsdcDdspub";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemMsdcDdspub";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "username", username);
		writeStringAttr(wr, itemtag, "sref", "password", password);
	xmlTextWriterEndElement(wr);
};

set<uint> StgMsdcDdspub::comm(
			const StgMsdcDdspub* comp
		) {
	set<uint> items;

	if (username == comp->username) insert(items, USERNAME);
	if (password == comp->password) insert(items, PASSWORD);

	return(items);
};

set<uint> StgMsdcDdspub::diff(
			const StgMsdcDdspub* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {USERNAME, PASSWORD};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class StgMsdcPath
 ******************************************************************************/

StgMsdcPath::StgMsdcPath(
			const string& acvpath
			, const string& keypath
			, const string& monpath
			, const string& tmppath
			, const string& webpath
			, const string& helpurl
		) : Block() {
	this->acvpath = acvpath;
	this->keypath = keypath;
	this->monpath = monpath;
	this->tmppath = tmppath;
	this->webpath = webpath;
	this->helpurl = helpurl;
	mask = {ACVPATH, KEYPATH, MONPATH, TMPPATH, WEBPATH, HELPURL};
};

bool StgMsdcPath::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgMsdcPath");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemMsdcPath";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "acvpath", acvpath)) add(ACVPATH);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "keypath", keypath)) add(KEYPATH);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "monpath", monpath)) add(MONPATH);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "tmppath", tmppath)) add(TMPPATH);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "webpath", webpath)) add(WEBPATH);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "helpurl", helpurl)) add(HELPURL);
	};

	return basefound;
};

void StgMsdcPath::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgMsdcPath";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemMsdcPath";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "acvpath", acvpath);
		writeStringAttr(wr, itemtag, "sref", "keypath", keypath);
		writeStringAttr(wr, itemtag, "sref", "monpath", monpath);
		writeStringAttr(wr, itemtag, "sref", "tmppath", tmppath);
		writeStringAttr(wr, itemtag, "sref", "webpath", webpath);
		writeStringAttr(wr, itemtag, "sref", "helpurl", helpurl);
	xmlTextWriterEndElement(wr);
};

set<uint> StgMsdcPath::comm(
			const StgMsdcPath* comp
		) {
	set<uint> items;

	if (acvpath == comp->acvpath) insert(items, ACVPATH);
	if (keypath == comp->keypath) insert(items, KEYPATH);
	if (monpath == comp->monpath) insert(items, MONPATH);
	if (tmppath == comp->tmppath) insert(items, TMPPATH);
	if (webpath == comp->webpath) insert(items, WEBPATH);
	if (helpurl == comp->helpurl) insert(items, HELPURL);

	return(items);
};

set<uint> StgMsdcPath::diff(
			const StgMsdcPath* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {ACVPATH, KEYPATH, MONPATH, TMPPATH, WEBPATH, HELPURL};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class StgMsdcUasrv
 ******************************************************************************/

StgMsdcUasrv::StgMsdcUasrv(
			const string& profile
			, const usmallint port
			, const usmallint cycle
			, const uint maxbrowse
			, const uint maxmon
		) : Block() {
	this->profile = profile;
	this->port = port;
	this->cycle = cycle;
	this->maxbrowse = maxbrowse;
	this->maxmon = maxmon;
	mask = {PROFILE, PORT, CYCLE, MAXBROWSE, MAXMON};
};

bool StgMsdcUasrv::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgMsdcUasrv");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemMsdcUasrv";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "profile", profile)) add(PROFILE);
		if (extractUsmallintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "port", port)) add(PORT);
		if (extractUsmallintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "cycle", cycle)) add(CYCLE);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "maxbrowse", maxbrowse)) add(MAXBROWSE);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "maxmon", maxmon)) add(MAXMON);
	};

	return basefound;
};

void StgMsdcUasrv::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgMsdcUasrv";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemMsdcUasrv";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "profile", profile);
		writeUsmallintAttr(wr, itemtag, "sref", "port", port);
		writeUsmallintAttr(wr, itemtag, "sref", "cycle", cycle);
		writeUintAttr(wr, itemtag, "sref", "maxbrowse", maxbrowse);
		writeUintAttr(wr, itemtag, "sref", "maxmon", maxmon);
	xmlTextWriterEndElement(wr);
};

set<uint> StgMsdcUasrv::comm(
			const StgMsdcUasrv* comp
		) {
	set<uint> items;

	if (profile == comp->profile) insert(items, PROFILE);
	if (port == comp->port) insert(items, PORT);
	if (cycle == comp->cycle) insert(items, CYCLE);
	if (maxbrowse == comp->maxbrowse) insert(items, MAXBROWSE);
	if (maxmon == comp->maxmon) insert(items, MAXMON);

	return(items);
};

set<uint> StgMsdcUasrv::diff(
			const StgMsdcUasrv* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {PROFILE, PORT, CYCLE, MAXBROWSE, MAXMON};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 namespace AlrMsdc
 ******************************************************************************/

DpchEngMsdcAlert* AlrMsdc::prepareAlrAbt(
			const ubigint jref
			, const uint ixMsdcVLocale
			, Feed& feedFMcbAlert
		) {
	ContInfMsdcAlert continf;
	// IP prepareAlrAbt --- BEGIN
	continf.TxtCpt = VecMsdcVTag::getTitle(VecMsdcVTag::ABOUT, ixMsdcVLocale);
	continf.TxtCpt = StrMod::cap(continf.TxtCpt);

	if (ixMsdcVLocale == VecMsdcVLocale::ENUS) {
		continf.TxtMsg1 = "MultispectralDetectorControl version 0.1.45 released on 15-8-2018";
		continf.TxtMsg2 = "\\u00a9 MPSI Technologies GmbH";
		continf.TxtMsg4 = "contributors: Alexander Wirthmueller";
		continf.TxtMsg6 = "libraries: png 1.5.12, jpeg 8, devmsdd 1.0.0 and spinnaker 1.13";
		continf.TxtMsg8 = "MultispectralDetectorControl provides users and machines with access to the MPSI Technologies Stereo+LWIR detector vision demonstrator.";
	} else if (ixMsdcVLocale == VecMsdcVLocale::DECH) {
		continf.TxtMsg1 = "MultispectralDetectorControl Version 0.1.45 ver\\u00f6ffentlicht am 15-8-2018";
		continf.TxtMsg2 = "\\u00a9 MPSI Technologies GmbH";
		continf.TxtMsg4 = "Mitwirkende: Alexander Wirthmueller";
		continf.TxtMsg6 = "Programmbibliotheken: png 1.5.12, jpeg 8, devmsdd 1.0.0 und spinnaker 1.13";
		continf.TxtMsg8 = "MultispectralDetectorControl erm\\u00f6glicht Benutzern und Ger\\u00e4ten Zugriff auf den MPSI Technologies Stereo+LWIR-Detektor Vision-Demonstrator.";
	};

	feedFMcbAlert.clear();

	VecMsdcVTag::appendToFeed(VecMsdcVTag::CLOSE, ixMsdcVLocale, feedFMcbAlert);
	feedFMcbAlert.cap();
	// IP prepareAlrAbt --- END
	return(new DpchEngMsdcAlert(jref, &continf, &feedFMcbAlert, {DpchEngMsdcAlert::ALL}));
};

DpchEngMsdcAlert* AlrMsdc::prepareAlrPer(
			const ubigint jref
			, const uint ixMsdcVLocale
			, const string& lineno
			, Feed& feedFMcbAlert
		) {
	ContInfMsdcAlert continf;
	// IP prepareAlrPer --- BEGIN
	continf.TxtCpt = VecMsdcVTag::getTitle(VecMsdcVTag::ERROR, ixMsdcVLocale);
	continf.TxtCpt = StrMod::cap(continf.TxtCpt);

	if (ixMsdcVLocale == VecMsdcVLocale::ENUS) {
		continf.TxtMsg1 = "Parse error in line " + lineno + ".";
	} else if (ixMsdcVLocale == VecMsdcVLocale::DECH) {
		continf.TxtMsg1 = "Syntaxfehler in Zeile " + lineno + ".";
	};

	feedFMcbAlert.clear();

	VecMsdcVTag::appendToFeed(VecMsdcVTag::OK, ixMsdcVLocale, feedFMcbAlert);
	feedFMcbAlert.cap();
	// IP prepareAlrPer --- END
	return(new DpchEngMsdcAlert(jref, &continf, &feedFMcbAlert, {DpchEngMsdcAlert::ALL}));
};

DpchEngMsdcAlert* AlrMsdc::prepareAlrSav(
			const ubigint jref
			, const uint ixMsdcVLocale
			, Feed& feedFMcbAlert
		) {
	ContInfMsdcAlert continf;
	// IP prepareAlrSav --- BEGIN
	continf.TxtCpt = VecMsdcVTag::getTitle(VecMsdcVTag::QUEST, ixMsdcVLocale);
	continf.TxtCpt = StrMod::cap(continf.TxtCpt);

	if (ixMsdcVLocale == VecMsdcVLocale::ENUS) {
		continf.TxtMsg1 = "Save changes?";
	} else if (ixMsdcVLocale == VecMsdcVLocale::DECH) {
		continf.TxtMsg1 = "\\u00c4nderungen speichern?";
	};

	feedFMcbAlert.clear();

	VecMsdcVTag::appendToFeed(VecMsdcVTag::CANCEL, ixMsdcVLocale, feedFMcbAlert);
	VecMsdcVTag::appendToFeed(VecMsdcVTag::FLS, ixMsdcVLocale, feedFMcbAlert);
	VecMsdcVTag::appendToFeed(VecMsdcVTag::TRU, ixMsdcVLocale, feedFMcbAlert);
	feedFMcbAlert.cap();
	// IP prepareAlrSav --- END
	return(new DpchEngMsdcAlert(jref, &continf, &feedFMcbAlert, {DpchEngMsdcAlert::ALL}));
};

/******************************************************************************
 class ReqMsdc
 ******************************************************************************/

ReqMsdc::ReqMsdc(
			const uint ixVBasetype
			, const uint ixVState
			, const string& ip
		) {
	this->ixVBasetype = ixVBasetype;
	this->ixVState = ixVState;
	this->ip = ip;

	pp = NULL;

	if ((ixVBasetype == VecVBasetype::CMD) || (ixVBasetype == VecVBasetype::REGULAR) || (ixVBasetype == VecVBasetype::NOTIFY)
					|| (ixVBasetype == VecVBasetype::UPLOAD) || (ixVBasetype == VecVBasetype::DOWNLOAD) || (ixVBasetype == VecVBasetype::METHOD)) {
		retain = false;
		Mutex::init(&mcReady, false, "mcReady", "ReqMsdc", "ReqMsdc");
		Cond::init(&cReady, "cReady", "ReqMsdc", "ReqMsdc");

	} else {
		retain = true;
	};

	file = NULL;
	filelen = 0;

	request = NULL;
	requestlen = 0;

	jref = 0;

	wref = 0;

	call = NULL;

	weak = false;

	dpchapp = NULL;

	dpcheng = NULL;
	ixMsdcVLocale = VecMsdcVLocale::ENUS;

	dpchinv = NULL;
	dpchret = NULL;

	reply = NULL;
	replylen = 0;

	method = NULL;
};

ReqMsdc::~ReqMsdc() {
	if (pp) MHD_destroy_post_processor(pp);

	if ((ixVBasetype == VecVBasetype::CMD) || (ixVBasetype == VecVBasetype::REGULAR) || (ixVBasetype == VecVBasetype::NOTIFY)
					|| (ixVBasetype == VecVBasetype::UPLOAD) || (ixVBasetype == VecVBasetype::DOWNLOAD) || (ixVBasetype == VecVBasetype::METHOD)) {
		Mutex::destroy(&mcReady, false, "mcReady", "ReqMsdc", "~ReqMsdc");
		Cond::destroy(&cReady, "cReady", "ReqMsdc", "~ReqMsdc");
	};

	if (file) {
		if (file->is_open()) file->close();
		delete file;
	};

	if (call) delete call;

	if (request) delete[] request;

	if (dpchapp) delete dpchapp;

	if (dpcheng) delete dpcheng;

	if (dpchinv) delete dpchinv;
	if (dpchret) delete dpchret;

	if (reply) delete[] reply;

	if (method) delete method;
};

void ReqMsdc::setStateReply() {
	Mutex::lock(&mcReady, "mcReady", "ReqMsdc", "setStateReply");
	ixVState = VecVState::REPLY;
	Mutex::unlock(&mcReady, "mcReady", "ReqMsdc", "setStateReply");

	Cond::signal(&cReady, &mcReady, "cReady", "mcReady", "ReqMsdc", "setStateReply");
};

/******************************************************************************
 class DcolMsdc
 ******************************************************************************/

DcolMsdc::DcolMsdc(
			const ubigint jref
			, const uint ixMsdcVLocale
		) {
	this->jref = jref;
	this->ixMsdcVLocale = ixMsdcVLocale;

	Mutex::init(&mAccess, false, "mAccess", "DcolMsdc", "DcolMsdc");

	hot = false;

	req = NULL;
};

DcolMsdc::~DcolMsdc() {
	Mutex::lock(&mAccess, "mAccess", "DcolMsdc", "~DcolMsdc");
	Mutex::unlock(&mAccess, "mAccess", "DcolMsdc", "~DcolMsdc");
	Mutex::destroy(&mAccess, true, "mAccess", "DcolMsdc", "~DcolMsdc");

	for (auto it=dpchs.begin();it!=dpchs.end();it++) delete(*it);

	if (req) Cond::signal(&(req->cReady), &(req->mcReady), "req->cReady", "req->mcReady", "DcolMsdc", "~DcolMsdc");
};

int DcolMsdc::lockAccess(
			const string& srefObject
			, const string& srefMember
		) {
	return Mutex::lock(&mAccess, "dcol(" + to_string(jref) + ")->mAccess", srefObject, srefMember);
};

int DcolMsdc::unlockAccess(
			const string& srefObject
			, const string& srefMember
		) {
	return Mutex::unlock(&mAccess, "dcol(" + to_string(jref) + ")->mAccess", srefObject, srefMember);
};

/******************************************************************************
 class JobMsdc
 ******************************************************************************/

JobMsdc::JobMsdc(
			XchgMsdc* xchg
			, const uint ixMsdcVJob
			, const ubigint jrefSup
			, const uint ixMsdcVLocale
		) {
	this->xchg = xchg;

	jref = 0;

	this->ixMsdcVJob = ixMsdcVJob;

	this->jrefSup = jrefSup;

	this->ixMsdcVLocale = ixMsdcVLocale;

	Mutex::init(&mAccess, true, "mAccess", VecMsdcVJob::getSref(ixMsdcVJob) + "(jrefSup=" + to_string(jrefSup) + ")", VecMsdcVJob::getSref(ixMsdcVJob));

	muteRefresh = false;

	ixVSge = 1;
	nextIxVSge = 1;

	opNdone = 0;
	opN = 0;

	Mutex::init(&mOps, true, "mOps", VecMsdcVJob::getSref(ixMsdcVJob) + "(jrefSup=" + to_string(jrefSup) + ")", VecMsdcVJob::getSref(ixMsdcVJob));

	wrefLast = 0;
	wrefMin = 0;

	reqCmd = NULL;
};

JobMsdc::~JobMsdc() {
	Mutex::lock(&mAccess, "mAccess", VecMsdcVJob::getSref(ixMsdcVJob) + "(" + to_string(jref) + ")", "~" + VecMsdcVJob::getSref(ixMsdcVJob));
	Mutex::unlock(&mAccess, "mAccess", VecMsdcVJob::getSref(ixMsdcVJob) + "(" + to_string(jref) + ")", "~" + VecMsdcVJob::getSref(ixMsdcVJob));
	Mutex::destroy(&mAccess, true, "mAccess", VecMsdcVJob::getSref(ixMsdcVJob) + "(" + to_string(jref) + ")", "~" + VecMsdcVJob::getSref(ixMsdcVJob));

	Mutex::destroy(&mOps, true, "mOps", VecMsdcVJob::getSref(ixMsdcVJob) + "(" + to_string(jref) + ")", "~" + VecMsdcVJob::getSref(ixMsdcVJob));

	if (reqCmd) delete reqCmd;
};

DpchEngMsdc* JobMsdc::getNewDpchEng(
			set<uint> items
		) {
	return new DpchEngMsdcConfirm(true, jref, "");
};

void JobMsdc::refresh(
			DbsMsdc* dbsmsdc
			, set<uint>& moditems
		) {
};

void JobMsdc::refreshWithDpchEng(
			DbsMsdc* dbsmsdc
			, DpchEngMsdc** dpcheng
		) {
	set<uint> moditems;

	DpchEngMsdc* _dpcheng = NULL;

	refresh(dbsmsdc, moditems);

	if (dpcheng) {
		_dpcheng = getNewDpchEng(moditems);

		if (*dpcheng) {
			if (_dpcheng->ixMsdcVDpch == VecMsdcVDpch::DPCHENGMSDCCONFIRM) delete _dpcheng;
			else if (_dpcheng->ixMsdcVDpch == (*dpcheng)->ixMsdcVDpch) {
				(*dpcheng)->merge(_dpcheng);
				delete _dpcheng;

			} else xchg->submitDpch(_dpcheng);

		} else *dpcheng = _dpcheng;

	} else if (!moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
};

string JobMsdc::getSquawk(
			DbsMsdc* dbsmsdc
		) {
	return "";
};

void JobMsdc::handleRequest(
			DbsMsdc* dbsmsdc
			, ReqMsdc* req
		) {
};

void JobMsdc::handleCall(
			DbsMsdc* dbsmsdc
			, Call* call
		) {
};

int JobMsdc::lockAccess(
			const string& srefObject
			, const string& srefMember
		) {
	return Mutex::lock(&mAccess, VecMsdcVJob::getSref(ixMsdcVJob) + "(" + to_string(jref) + ").mAccess", srefObject, srefMember);
};

int JobMsdc::trylockAccess(
			const string& srefObject
			, const string& srefMember
		) {
	return Mutex::trylock(&mAccess, VecMsdcVJob::getSref(ixMsdcVJob) + "(" + to_string(jref) + ").mAccess", srefObject, srefMember);
};

int JobMsdc::unlockAccess(
			const string& srefObject
			, const string& srefMember
		) {
	return Mutex::unlock(&mAccess, VecMsdcVJob::getSref(ixMsdcVJob) + "(" + to_string(jref) + ").mAccess", srefObject, srefMember);
};

int JobMsdc::lockAccess(
			const string& srefMember
		) {
	return Mutex::lock(&mAccess, "mAccess", VecMsdcVJob::getSref(ixMsdcVJob) + "(" + to_string(jref) + ")", srefMember);
};

int JobMsdc::unlockAccess(
			const string& srefMember
		) {
	return Mutex::unlock(&mAccess, "mAccess", VecMsdcVJob::getSref(ixMsdcVJob) + "(" + to_string(jref) + ")", srefMember);
};

void JobMsdc::setStage(
			DbsMsdc* dbsmsdc
			, const uint _ixVSge
		) {
	ixVSge = _ixVSge;

	xchg->triggerIxCall(dbsmsdc, VecMsdcVCall::CALLMSDCSGECHG, jref, ixVSge);
};

void JobMsdc::clearInvs() {
	for (unsigned int i=0;i<invs.size();i++) delete invs[i];
	invs.clear();
};

ubigint JobMsdc::addInv(
			DpchInvMsdc* inv
		) {
	inv->oref = xchg->orefseq->getNewRef();
	inv->jref = jref;

	invs.push_back(inv);

	opN++;

	return(inv->oref);
};

void JobMsdc::addInvs(
			vector<DpchInvMsdc*>& _invs
		) {
	for (unsigned int i=0;i<_invs.size();i++) addInv(_invs[i]);
};

void JobMsdc::submitInvs(
			DbsMsdc* dbsmsdc
			, const uint emptyIxVSge
			, uint& _ixVSge
		) {
	if (opN == 0) {
		_ixVSge = emptyIxVSge;

	} else {
		xchg->addInvs(dbsmsdc, jref, invs);
		invs.clear();
	};
};

void JobMsdc::clearOps() {
	Mutex::lock(&mOps, "mOps", VecMsdcVJob::getSref(ixMsdcVJob) + "(" + to_string(jref) + ")", "clearOps");

	for (auto it=ops.begin();it!=ops.end();it++) delete(*it);
	ops.clear();

	Mutex::unlock(&mOps, "mOps", VecMsdcVJob::getSref(ixMsdcVJob) + "(" + to_string(jref) + ")", "clearOps");
};

void JobMsdc::addOp(
			DbsMsdc* dbsmsdc
			, DpchInvMsdc* inv
		) {
	string squawk;

	Mutex::lock(&mOps, "mOps", VecMsdcVJob::getSref(ixMsdcVJob) + "(" + to_string(jref) + ")", "addOp");

	// generate squawk

	// append to op list
	ops.push_back(new Op(inv->oref, inv->ixMsdcVDpch, squawk));

	Mutex::unlock(&mOps, "mOps", VecMsdcVJob::getSref(ixMsdcVJob) + "(" + to_string(jref) + ")", "addOp");
};

void JobMsdc::removeOp(
			const ubigint oref
		) {
	Op* op = NULL;

	Mutex::lock(&mOps, "mOps", VecMsdcVJob::getSref(ixMsdcVJob) + "(" + to_string(jref) + ")", "removeOp");

	for (auto it=ops.begin();it!=ops.end();it++) {
		op = *it;

		if (op->oref == oref) {
			// found
			ops.erase(it);

			// keep squawk of this op
			opsqkLast = op->squawk;

			delete op;
			
			break;
		};
	};

	Mutex::unlock(&mOps, "mOps", VecMsdcVJob::getSref(ixMsdcVJob) + "(" + to_string(jref) + ")", "removeOp");
};

string JobMsdc::getOpsqkLast() {
	string retval;

	Mutex::lock(&mOps, "mOps", VecMsdcVJob::getSref(ixMsdcVJob) + "(" + to_string(jref) + ")", "getOpsqkLast");

	retval = opsqkLast;

	Mutex::unlock(&mOps, "mOps", VecMsdcVJob::getSref(ixMsdcVJob) + "(" + to_string(jref) + ")", "getOpsqkLast");

	return retval;
};

void JobMsdc::callback(
			const uint _nextIxVSge
		) {
	nextIxVSge = _nextIxVSge;
	wrefLast = xchg->addWakeup(jref, "callback", 0);
};

void JobMsdc::invalidateWakeups() {
	wrefMin = wrefLast + 1;
};

/******************************************************************************
 class MsjobMsdc
 ******************************************************************************/

MsjobMsdc::MsjobMsdc(
			XchgMsdc* xchg
			, const uint ixMsdcVJob
			, const ubigint jrefSup
			, const uint ixMsdcVLocale
			, const bool prefmast
		) : JobMsdc(xchg, ixMsdcVJob, jrefSup, ixMsdcVLocale) {
	this->prefmast = prefmast;

	srd = false;
};

MsjobMsdc::~MsjobMsdc() {
};

void MsjobMsdc::giveupMaster(
			DbsMsdc* dbsmsdc
			, Msjobinfo* msji
		) {
};

void MsjobMsdc::giveupSlave(
			DbsMsdc* dbsmsdc
			, Msjobinfo* msji
		) {
};

void MsjobMsdc::becomeMaster(
			DbsMsdc* dbsmsdc
			, Msjobinfo* msji
		) {
};

void MsjobMsdc::becomeSlave(
			DbsMsdc* dbsmsdc
			, Msjobinfo* msji
		) {
};

bool MsjobMsdc::handleClaimMaster(
			DbsMsdc* dbsmsdc
			, Msjobinfo* msji
		) {
	return false;
};

bool MsjobMsdc::getMastNotSlv() {
	return xchg->getMsjobMastNotSlv(this);
};

MsjobMsdc* MsjobMsdc::lockMaster(
			const string& srefMember
		) {
	return xchg->getMsjobMaster(this, srefMember);
};

void MsjobMsdc::unlockMaster(
			MsjobMsdc* job
			, const string& srefMember
		) {
	job->unlockAccess(srefMember);
};

bool MsjobMsdc::start(
			DbsMsdc* dbsmsdc
		) {
	if (srd) return false;

	srd = true;
	xchg->setMsjobStarted(dbsmsdc, this, srd);

	return true;
};

bool MsjobMsdc::stop(
			DbsMsdc* dbsmsdc
		) {
	if (!srd) return false;

	srd = false;
	xchg->setMsjobStarted(dbsmsdc, this, srd);

	return true;
};

void MsjobMsdc::setStage(
			DbsMsdc* dbsmsdc
			, const uint _ixVSge
		) {
	ixVSge = _ixVSge;

	xchg->setMsjobStage(dbsmsdc, this, ixVSge);

	xchg->triggerIxCall(dbsmsdc, VecMsdcVCall::CALLMSDCSGECHG, jref, ixVSge);
};

/******************************************************************************
 class ShrdatMsdc
 ******************************************************************************/

ShrdatMsdc::ShrdatMsdc(
			const string& srefSupclass
			, const string& srefObject
			, const string& srefMutexsup
		) {
	this->srefSupclass = srefSupclass;
	this->srefObject = srefObject;
	this->srefMutexsup = srefMutexsup;

	Mutex::init(&mAccess, true, "mAccess", srefSupclass + "::" + srefObject, srefObject);
};

ShrdatMsdc::~ShrdatMsdc() {
	Mutex::destroy(&mAccess, true, "mAccess", srefSupclass + "::" + srefObject, "~" + srefObject);
};

void ShrdatMsdc::init(
			XchgMsdc* xchg
			, DbsMsdc* dbsmsdc
		) {
};

void ShrdatMsdc::term() {
};

int ShrdatMsdc::lockAccess(
			const string& srefObject
			, const string& srefMember
		) {
	return Mutex::lock(&mAccess, srefMutexsup + ".mAccess", srefObject, srefMember);
};

int ShrdatMsdc::unlockAccess(
			const string& srefObject
			, const string& srefMember
		) {
	return Mutex::unlock(&mAccess, srefMutexsup + ".mAccess", srefObject, srefMember);
};

int ShrdatMsdc::lockAccess(
			const ubigint jref
			, const string& srefMember
		) {
	return Mutex::lock(&mAccess, "shrdat.mAccess", srefSupclass + "(" + to_string(jref) + ")", srefMember);
};

int ShrdatMsdc::unlockAccess(
			const ubigint jref
			, const string& srefMember
		) {
	return Mutex::unlock(&mAccess, "shrdat.mAccess", srefSupclass + "(" + to_string(jref) + ")", srefMember);
};

/******************************************************************************
 class StmgrMsdc
 ******************************************************************************/

StmgrMsdc::StmgrMsdc(
			XchgMsdc* xchg
			, const ubigint jref
			, const uint ixVNonetype
		) {
	this->xchg = xchg;

	this->jref = jref;
	this->ixVNonetype = ixVNonetype;

	stcch = new Stcch(true);

	Mutex::init(&mAccess, true, "mAccess", "StmgrMsdc(" + to_string(jref) + ")", "StmgrMsdc");
};

StmgrMsdc::~StmgrMsdc() {
	Mutex::lock(&mAccess, "mAccess", "StmgrMsdc(" + to_string(jref) + ")", "~StmgrMsdc");
	Mutex::unlock(&mAccess, "mAccess", "StmgrMsdc(" + to_string(jref) + ")", "~StmgrMsdc");
	Mutex::destroy(&mAccess, true, "mAccess", "StmgrMsdc(" + to_string(jref) + ")", "~StmgrMsdc");

	delete stcch;
};

void StmgrMsdc::handleCall(
			DbsMsdc* dbsmsdc
			, Call* call
		) {
	set<uint> icsMsdcVStub;
	pair<multimap<stcchitemref_t,Stcchitem*>::iterator,multimap<stcchitemref_t,Stcchitem*>::iterator> rng;

	bool notif = false;

	begin();

	if (call->ixVCall == VecMsdcVCall::CALLMSDCDATUPD_REFEQ) {
		insert(icsMsdcVStub, VecMsdcVStub::STUBMSDCDATSTD);
	} else if (call->ixVCall == VecMsdcVCall::CALLMSDCFILUPD_REFEQ) {
		insert(icsMsdcVStub, VecMsdcVStub::STUBMSDCFILSTD);
	} else if (call->ixVCall == VecMsdcVCall::CALLMSDCPRDUPD_REFEQ) {
		insert(icsMsdcVStub, VecMsdcVStub::STUBMSDCPRDSTD);
	} else if (call->ixVCall == VecMsdcVCall::CALLMSDCPRSUPD_REFEQ) {
		insert(icsMsdcVStub, VecMsdcVStub::STUBMSDCPRSSTD);
	} else if (call->ixVCall == VecMsdcVCall::CALLMSDCSESUPD_REFEQ) {
		insert(icsMsdcVStub, VecMsdcVStub::STUBMSDCSESMENU);
		insert(icsMsdcVStub, VecMsdcVStub::STUBMSDCSESSTD);
	} else if (call->ixVCall == VecMsdcVCall::CALLMSDCUSGUPD_REFEQ) {
		insert(icsMsdcVStub, VecMsdcVStub::STUBMSDCGRP);
		insert(icsMsdcVStub, VecMsdcVStub::STUBMSDCUSGSTD);
	} else if (call->ixVCall == VecMsdcVCall::CALLMSDCUSRUPD_REFEQ) {
		insert(icsMsdcVStub, VecMsdcVStub::STUBMSDCUSRSTD);
		insert(icsMsdcVStub, VecMsdcVStub::STUBMSDCOWN);
	};

	for (auto it=icsMsdcVStub.begin();it!=icsMsdcVStub.end();it++) {
		rng = stcch->nodes.equal_range(stcchitemref_t(*it, call->argInv.ref, 0));
		for (auto it2=rng.first;it2!=rng.second;it2++) if (refresh(dbsmsdc, it2->second)) notif = true;
	};

	commit();

	if (notif) xchg->triggerCall(dbsmsdc, VecMsdcVCall::CALLMSDCSTUBCHG, jref);
};

bool StmgrMsdc::refresh(
			DbsMsdc* dbsmsdc
			, Stcchitem* stit
		) {
	set<stcchitemref_t> strefsSub_backup;
	string stub_backup;

	while (!stit->strefsSup.empty()) stcch->unlink(*stit->strefsSup.begin(), stit->stref);

	strefsSub_backup = stit->strefsSub;
	stub_backup = stit->stub;

	StubMsdc::getStub(dbsmsdc, stit->stref.ixVStub, stit->stref.ref, stit->stref.ixVLocale, ixVNonetype, stcch, NULL, true);

	if (stit->stub != stub_backup) {
		for (auto it=strefsSub_backup.begin();it!=strefsSub_backup.end();it++) refresh(dbsmsdc, stcch->getStitByStref(*it));
		return true;
	} else return false;
};

void StmgrMsdc::begin() {
	stcch->begin();
};

void StmgrMsdc::commit() {
	for (auto it=stcch->icsVStubNew.begin();it!=stcch->icsVStubNew.end();it++) {
		if (*it == VecMsdcVStub::STUBMSDCDATSTD) {
			xchg->addClstnStmgr(VecMsdcVCall::CALLMSDCDATUPD_REFEQ, jref);
		} else if (*it == VecMsdcVStub::STUBMSDCFILSTD) {
			xchg->addClstnStmgr(VecMsdcVCall::CALLMSDCFILUPD_REFEQ, jref);
		} else if (*it == VecMsdcVStub::STUBMSDCGRP) {
			xchg->addClstnStmgr(VecMsdcVCall::CALLMSDCUSGUPD_REFEQ, jref);
		} else if (*it == VecMsdcVStub::STUBMSDCOWN) {
			xchg->addClstnStmgr(VecMsdcVCall::CALLMSDCUSRUPD_REFEQ, jref);
		} else if (*it == VecMsdcVStub::STUBMSDCPRDSTD) {
			xchg->addClstnStmgr(VecMsdcVCall::CALLMSDCPRDUPD_REFEQ, jref);
		} else if (*it == VecMsdcVStub::STUBMSDCPRSSTD) {
			xchg->addClstnStmgr(VecMsdcVCall::CALLMSDCPRSUPD_REFEQ, jref);
		} else if (*it == VecMsdcVStub::STUBMSDCSESMENU) {
			xchg->addClstnStmgr(VecMsdcVCall::CALLMSDCSESUPD_REFEQ, jref);
		} else if (*it == VecMsdcVStub::STUBMSDCSESSTD) {
			xchg->addClstnStmgr(VecMsdcVCall::CALLMSDCSESUPD_REFEQ, jref);
		} else if (*it == VecMsdcVStub::STUBMSDCUSGSTD) {
			xchg->addClstnStmgr(VecMsdcVCall::CALLMSDCUSGUPD_REFEQ, jref);
		} else if (*it == VecMsdcVStub::STUBMSDCUSRSTD) {
			xchg->addClstnStmgr(VecMsdcVCall::CALLMSDCUSRUPD_REFEQ, jref);
		};
	};

	stcch->commit();
};

int StmgrMsdc::lockAccess(
			const string& srefObject
			, const string& srefMember
		) {
	return Mutex::lock(&mAccess, "stmgr(" + to_string(jref) + ")->mAccess", srefObject, srefMember);
};

int StmgrMsdc::unlockAccess(
			const string& srefObject
			, const string& srefMember
		) {
	return Mutex::unlock(&mAccess, "stmgr(" + to_string(jref) + ")->mAccess", srefObject, srefMember);
};

/******************************************************************************
 class WakeupMsdc
 ******************************************************************************/

WakeupMsdc::WakeupMsdc(
			XchgMsdc* xchg
			, const ubigint wref
			, const ubigint jref
			, const string sref
			, const unsigned int deltat
			, const bool weak
		) {
	this->xchg = xchg;
	this->wref = wref;
	this->jref = jref;
	this->sref = sref;
	this->deltat = deltat;
	this->weak = weak;
};

/******************************************************************************
 class ExtcallMsdc
 ******************************************************************************/

ExtcallMsdc::ExtcallMsdc(
			XchgMsdc* xchg
			, Call* call
		) {
	this->xchg = xchg;
	this->call = call;
};

// IP ShrdatJobprc.subs --- INSERT

/******************************************************************************
 class XchgMsdccmbd::ShrdatJobprc
 ******************************************************************************/

XchgMsdccmbd::ShrdatJobprc::ShrdatJobprc() : ShrdatMsdc("XchgMsdc", "ShrdatJobprc", "xchg->shrdatJobprc") {
};

void XchgMsdccmbd::ShrdatJobprc::init(
			XchgMsdc* xchg
			, DbsMsdc* dbsmsdc
		) {
	// IP ShrdatJobprc.init --- IBEGIN
	Mt::ixVVerbose = Mt::VecVVerbose::OFF;

#ifdef __linux__
	spinsys = Spinnaker::System::GetInstance();
#endif
	// IP ShrdatJobprc.init --- IEND
};

void XchgMsdccmbd::ShrdatJobprc::term() {
	// IP ShrdatJobprc.term --- IBEGIN
#ifdef __linux__
	spinsys->ReleaseInstance();
#endif
	// IP ShrdatJobprc.term --- IEND
};

// IP ShrdatOpprc.subs --- INSERT

/******************************************************************************
 class XchgMsdccmbd::ShrdatOpprc
 ******************************************************************************/

XchgMsdccmbd::ShrdatOpprc::ShrdatOpprc() : ShrdatMsdc("XchgMsdc", "ShrdatOpprc", "xchg->shrdatOpprc") {
};

void XchgMsdccmbd::ShrdatOpprc::init(
			XchgMsdc* xchg
			, DbsMsdc* dbsmsdc
		) {
	// IP ShrdatOpprc.init --- INSERT
};

void XchgMsdccmbd::ShrdatOpprc::term() {
	// IP ShrdatOpprc.term --- INSERT
};

/******************************************************************************
 class XchgMsdccmbd
 ******************************************************************************/

XchgMsdccmbd::XchgMsdccmbd() {
	// root job
	jrefRoot = 0;

	// job receiving commands
	jrefCmd = 0;

	// scrambled ref codes
	Mutex::init(&mScr, true, "mScr", "XchgMsdccmbd", "XchgMsdccmbd");

	// log file
	Mutex::init(&mLogfile, true, "mLogfile", "XchgMsdccmbd", "XchgMsdccmbd");

	// condition for job processors
	Mutex::init(&mcJobprcs, true, "mcJobprcs", "XchgMsdccmbd", "XchgMsdccmbd");
	Cond::init(&cJobprcs, "cJobprcs", "XchgMsdccmbd", "XchgMsdccmbd");

	// condition for op processors
	Mutex::init(&mcOpprcs, true, "mcOpprcs", "XchgMsdccmbd", "XchgMsdccmbd");
	Cond::init(&cOpprcs, "cOpprcs", "XchgMsdccmbd", "XchgMsdccmbd");

	// condition for DDS publisher
	Mutex::init(&mcDdspub, true, "mcDdspub", "XchgMsdccmbd", "XchgMsdccmbd");
	Cond::init(&cDdspub, "cDdspub", "XchgMsdccmbd", "XchgMsdccmbd");

	// condition for OPC UA server
	Mutex::init(&mcUasrv, true, "mcUasrv", "XchgMsdccmbd", "XchgMsdccmbd");
	Cond::init(&cUasrv, "cUasrv", "XchgMsdccmbd", "XchgMsdccmbd");

	// request list
	Mutex::init(&mReqs, true, "mReqs", "XchgMsdccmbd", "XchgMsdccmbd");

	// operation invocation list
	orefseq = new Refseq("orefseq");
	Mutex::init(&mInvs, true, "mInvs", "XchgMsdccmbd", "XchgMsdccmbd");

	// presetting list
	Mutex::init(&mPresets, true, "mPresets", "XchgMsdccmbd", "XchgMsdccmbd");

	// stub manager list
	Mutex::init(&mStmgrs, true, "mStmgrs", "XchgMsdccmbd", "XchgMsdccmbd");

	// call listener list
	Mutex::init(&mClstns, true, "mClstns", "XchgMsdccmbd", "XchgMsdccmbd");

	// dispatch collector list
	Mutex::init(&mDcols, true, "mDcols", "XchgMsdccmbd", "XchgMsdccmbd");

	// job list
	jrefseq = new Refseq("jrefseq");
	Mutex::init(&mJobs, true, "mJobs", "XchgMsdccmbd", "XchgMsdccmbd");

	// master-slave job information
	Mutex::init(&mMsjobinfos, true, "mMsjobinfos", "XchgMsdccmbd", "XchgMsdccmbd");
	msjobinfos[VecMsdcVJob::JOBMSDCACQADXL] = new Msjobinfo(VecMsdcVJob::JOBMSDCACQADXL);
	msjobinfos[VecMsdcVJob::JOBMSDCACQLWIR] = new Msjobinfo(VecMsdcVJob::JOBMSDCACQLWIR);
	msjobinfos[VecMsdcVJob::JOBMSDCACQVISL] = new Msjobinfo(VecMsdcVJob::JOBMSDCACQVISL);
	msjobinfos[VecMsdcVJob::JOBMSDCACQVISR] = new Msjobinfo(VecMsdcVJob::JOBMSDCACQVISR);
	msjobinfos[VecMsdcVJob::JOBMSDCACTALIGN] = new Msjobinfo(VecMsdcVJob::JOBMSDCACTALIGN);
	msjobinfos[VecMsdcVJob::JOBMSDCACTLED] = new Msjobinfo(VecMsdcVJob::JOBMSDCACTLED);
	msjobinfos[VecMsdcVJob::JOBMSDCACTSERVO] = new Msjobinfo(VecMsdcVJob::JOBMSDCACTSERVO);
	msjobinfos[VecMsdcVJob::JOBMSDCPRCSPOTFIND] = new Msjobinfo(VecMsdcVJob::JOBMSDCPRCSPOTFIND);
	msjobinfos[VecMsdcVJob::JOBMSDCPRCSTEREO] = new Msjobinfo(VecMsdcVJob::JOBMSDCPRCSTEREO);
	msjobinfos[VecMsdcVJob::JOBMSDCPRCTRACK] = new Msjobinfo(VecMsdcVJob::JOBMSDCPRCTRACK);
	msjobinfos[VecMsdcVJob::JOBMSDCSRCMSDD] = new Msjobinfo(VecMsdcVJob::JOBMSDCSRCMSDD);
	msjobinfos[VecMsdcVJob::JOBMSDCSRCTRIGGER] = new Msjobinfo(VecMsdcVJob::JOBMSDCSRCTRIGGER);

	// DDS publisher call
	Mutex::init(&mDdspubcall, true, "mDdspubcall", "XchgMsdccmbd", "XchgMsdccmbd");
	ddspubcall = NULL;

	// OPC UA server call
	Mutex::init(&mUasrvcall, true, "mUasrvcall", "XchgMsdccmbd", "XchgMsdccmbd");
	uasrvcall = NULL;

	// sequence for wakeup references
	wrefseq = new Refseq("wrefseq");
};

XchgMsdccmbd::~XchgMsdccmbd() {
	// empty out lists
	for (auto it=reqs.begin();it!=reqs.end();it++) delete(*it);
	for (auto it=invs.begin();it!=invs.end();it++) delete(*it);
	for (auto it=presets.begin();it!=presets.end();it++) delete(it->second);
	for (auto it=stmgrs.begin();it!=stmgrs.end();it++) delete(it->second);
	for (auto it=clstns.begin();it!=clstns.end();it++) delete(it->second);
	for (auto it=dcols.begin();it!=dcols.end();it++) delete(it->second);
	for (auto it=jobs.begin();it!=jobs.end();it++) delete(it->second);
	for (auto it=msjobinfos.begin();it!=msjobinfos.end();it++) delete(it->second);

	// scrambled ref codes
	Mutex::destroy(&mScr, true, "mScr", "XchgMsdccmbd", "~XchgMsdccmbd");

	// log file
	Mutex::destroy(&mLogfile, true, "mLogfile", "XchgMsdccmbd", "~XchgMsdccmbd");

	// condition for job processors
	Mutex::destroy(&mcJobprcs, true, "mcJobprcs", "XchgMsdccmbd", "~XchgMsdccmbd");
	Cond::destroy(&cJobprcs, "cJobprcs", "XchgMsdccmbd", "~XchgMsdccmbd");

	// condition for op processors
	Mutex::destroy(&mcOpprcs, true, "mcOpprcs", "XchgMsdccmbd", "~XchgMsdccmbd");
	Cond::destroy(&cOpprcs, "cOpprcs", "XchgMsdccmbd", "~XchgMsdccmbd");

	// condition for DDS publisher
	Mutex::destroy(&mcDdspub, true, "mcDdspub", "XchgMsdccmbd", "XchgMsdccmbd");
	Cond::destroy(&cDdspub, "cDdspub", "XchgMsdccmbd", "XchgMsdccmbd");

	// condition for OPC UA server
	Mutex::destroy(&mcUasrv, true, "mcUasrv", "XchgMsdccmbd", "XchgMsdccmbd");
	Cond::destroy(&cUasrv, "cUasrv", "XchgMsdccmbd", "XchgMsdccmbd");

	// request list
	Mutex::destroy(&mReqs, true, "mReqs", "XchgMsdccmbd", "~XchgMsdccmbd");

	// operation invocation list
	delete orefseq;
	Mutex::destroy(&mInvs, true, "mInvs", "XchgMsdccmbd", "~XchgMsdccmbd");

	// presetting list
	Mutex::destroy(&mPresets, true, "mPresets", "XchgMsdccmbd", "~XchgMsdccmbd");

	// stub manager list
	Mutex::destroy(&mStmgrs, true, "mStmgrs", "XchgMsdccmbd", "~XchgMsdccmbd");

	// call listener list
	Mutex::destroy(&mClstns, true, "mClstns", "XchgMsdccmbd", "~XchgMsdccmbd");

	// dispatch collector list
	Mutex::destroy(&mDcols, true, "mDcols", "XchgMsdccmbd", "~XchgMsdccmbd");

	// job list
	delete jrefseq;
	Mutex::destroy(&mJobs, true, "mJobs", "XchgMsdccmbd", "~XchgMsdccmbd");

	// master-slave job information
	Mutex::destroy(&mMsjobinfos, true, "mMsjobinfos", "XchgMsdccmbd", "~XchgMsdccmbd");

	// DDS publisher call
	Mutex::destroy(&mDdspubcall, true, "mDdspubcall", "XchgMsdccmbd", "XchgMsdccmbd");

	// OPC UA server call
	Mutex::destroy(&mUasrvcall, true, "mUasrvcall", "XchgMsdccmbd", "XchgMsdccmbd");

	// sequence for wakeup references
	delete wrefseq;
};

// IP cust --- INSERT

string XchgMsdccmbd::scramble(
			const ubigint ref
		) {
	return Scr::scramble(&mScr, scr, descr, ref);
};

ubigint XchgMsdccmbd::descramble(
			const string& scrRef
		) {
	return Scr::descramble(&mScr, descr, scrRef);
};

void XchgMsdccmbd::startMon() {
	JobMsdc* job = NULL;

	DcolMsdc* dcol = NULL;
	bool Dcol;

	StmgrMsdc* stmgr = NULL;
	bool Stmgr;

	Clstn* clstn = NULL;
	Preset* preset = NULL;

	mon.start("MultispectralDetectorControl 0.1.45", stgmsdcpath.monpath);

	Mutex::lock(&mJobs, "mJobs", "XchgMsdccmbd", "startMon");
	for (auto it=jobs.begin();it!=jobs.end();it++) {
		job = it->second;

		dcol = getDcolByJref(job->jref, false);
		if (dcol) {
			Dcol = true;
			dcol->unlockAccess("XchgMsdccmbd", "startMon");
		} else Dcol = false;

		stmgr = getStmgrByJref(job->jref);
		if (stmgr) {
			Stmgr = true;
			stmgr->unlockAccess("XchgMsdccmbd", "startMon");
		} else Stmgr = false;

		if (getMsjobNotJob(job->ixMsdcVJob)) mon.insertJob(job->jrefSup, VecMsdcVJob::getSref(job->ixMsdcVJob), job->jref, true, getMsjobMastNotSlv((MsjobMsdc*) job), Dcol, Stmgr);
		else mon.insertJob(job->jrefSup, VecMsdcVJob::getSref(job->ixMsdcVJob), job->jref, false, false, Dcol, Stmgr);
	};
	Mutex::unlock(&mJobs, "mJobs", "XchgMsdccmbd", "startMon");

	Mutex::lock(&mClstns, "mClstns", "XchgMsdccmbd", "startMon");
	for (auto it=clstns.begin();it!=clstns.end();it++) {
		clstn = it->second;
		mon.insertClstn(clstn->cref.jref, VecMsdcVCall::getSref(clstn->cref.ixVCall), Clstn::VecVTarget::getSref(clstn->cref.ixVTarget), Clstn::VecVJobmask::getSref(clstn->cref.ixVJobmask), clstn->cref.jrefTrig, clstn->argMask.writeText(), Clstn::VecVJactype::getSref(clstn->ixVJactype));
	};
	Mutex::unlock(&mClstns, "mClstns", "XchgMsdccmbd", "startMon");

	Mutex::lock(&mPresets, "mPresets", "XchgMsdccmbd", "startMon");
	for (auto it=presets.begin();it!=presets.end();it++) {
		preset = it->second;
		mon.insertPreset(preset->pref.jref, VecMsdcVPreset::getSref(preset->pref.ixVPreset), preset->arg.writeText());
	};
	Mutex::unlock(&mPresets, "mPresets", "XchgMsdccmbd", "startMon");

	triggerCall(NULL, VecMsdcVCall::CALLMSDCMONSTATCHG, jrefRoot);
};

void XchgMsdccmbd::stopMon() {
	mon.stop();

	triggerCall(NULL, VecMsdcVCall::CALLMSDCMONSTATCHG, jrefRoot);
};

void XchgMsdccmbd::appendToLogfile(
			const string& str
		) {
	time_t rawtime;
	fstream logfile;

	Mutex::lock(&mLogfile, "mLogfile", "XchgMsdccmbd", "appendToLogfile");

	time(&rawtime);

	logfile.open("./log.txt", ios::out | ios::app);
	logfile << Ftm::stamp(rawtime) << ": " << str << endl;
	logfile.close();

	Mutex::unlock(&mLogfile, "mLogfile", "XchgMsdccmbd", "appendToLogfile");
};

void XchgMsdccmbd::addReq(
			ReqMsdc* req
		) {
	Mutex::lock(&mReqs, "mReqs", "XchgMsdccmbd", "addReq");

	req->ixVState = ReqMsdc::VecVState::WAITPRC;
	reqs.push_back(req);

	Mutex::unlock(&mReqs, "mReqs", "XchgMsdccmbd", "addReq");

	Cond::signal(&cJobprcs, &mcJobprcs, "cJobprcs", "mcJobprcs", "XchgMsdccmbd", "addReq");
};

ReqMsdc* XchgMsdccmbd::pullFirstReq() {
	ReqMsdc* req;

	// get first element from list
	Mutex::lock(&mReqs, "mReqs", "XchgMsdccmbd", "pullFirstReq");

	req = NULL;

	if (!reqs.empty()) {
		req = *(reqs.begin());
		req->ixVState = ReqMsdc::VecVState::PRC;
		reqs.pop_front();
	};

	Mutex::unlock(&mReqs, "mReqs", "XchgMsdccmbd", "pullFirstReq");

	return req;
};

void XchgMsdccmbd::addInvs(
			DbsMsdc* dbsmsdc
			, const ubigint jref
			, vector<DpchInvMsdc*>& dpchinvs
		) {
	JobMsdc* job;

	job = getJobByJref(jref);

	if (job) {
		// append to inv list and signal the news (note the double-lock)
		Mutex::lock(&mInvs, "mInvs", "XchgMsdccmbd", "addInvs");
		Mutex::lock(&(job->mOps), "job->mOps", "XchgMsdccmbd", "addInvs");

		for (unsigned int i=0;i<dpchinvs.size();i++) {
			job->addOp(dbsmsdc, dpchinvs[i]);

			invs.push_back(dpchinvs[i]);

			mon.eventAddInv(jref, VecMsdcVDpch::getSref(dpchinvs[i]->ixMsdcVDpch), "", dpchinvs[i]->oref);
		};

		Mutex::unlock(&(job->mOps), "job->mOps", "XchgMsdccmbd", "addInvs");
		Mutex::unlock(&mInvs, "mInvs", "XchgMsdccmbd", "addInvs");

		Cond::signal(&cOpprcs, &mcOpprcs, "cOpprcs", "mcOpprcs", "XchgMsdccmbd", "addInvs");
	};
};

DpchInvMsdc* XchgMsdccmbd::pullFirstInv() {
	DpchInvMsdc* inv;

	// get first element from list
	Mutex::lock(&mInvs, "mInvs", "XchgMsdccmbd", "pullFirstInv");

	inv = NULL;

	if (!invs.empty()) {
		inv = *(invs.begin());
		invs.pop_front();
	};

	Mutex::unlock(&mInvs, "mInvs", "XchgMsdccmbd", "pullFirstInv");

	return inv;
};

Preset* XchgMsdccmbd::addPreset(
			const uint ixMsdcVPreset
			, const ubigint jref
			, const Arg& arg
		) {
	presetref_t pref(jref, ixMsdcVPreset);
	Preset* preset;

	// create new presetting (override value if exists) and append to presetting list
	Mutex::lock(&mPresets, "mPresets", "XchgMsdccmbd", "addPreset");

	preset = getPresetByPref(pref);

	if (preset) {
		preset->arg = arg;

		mon.eventChangePreset(jref, VecMsdcVPreset::getSref(ixMsdcVPreset), arg.writeText());

	} else {
		preset = new Preset(pref, arg);
		presets.insert(pair<presetref_t,Preset*>(pref, preset));

		mon.eventAddPreset(jref, VecMsdcVPreset::getSref(ixMsdcVPreset), arg.writeText());
	};

	Mutex::unlock(&mPresets, "mPresets", "XchgMsdccmbd", "addPreset");

	return(preset);
};

Preset* XchgMsdccmbd::addIxPreset(
			const uint ixMsdcVPreset
			, const ubigint jref
			, const uint ix
		) {
	return(addPreset(ixMsdcVPreset, jref, Arg(ix, 0, {}, "", 0, 0.0, false, "", Arg::IX)));
};

Preset* XchgMsdccmbd::addRefPreset(
			const uint ixMsdcVPreset
			, const ubigint jref
			, const ubigint ref
		) {
	return(addPreset(ixMsdcVPreset, jref, Arg(0, ref, {}, "", 0, 0.0, false, "", Arg::REF)));
};

Preset* XchgMsdccmbd::addRefsPreset(
			const uint ixMsdcVPreset
			, const ubigint jref
			, const vector<ubigint>& refs
		) {
	Arg arg(0, 0, refs, "", 0, 0.0, false, "", Arg::REFS);

	return(addPreset(ixMsdcVPreset, jref, arg));
};

Preset* XchgMsdccmbd::addSrefPreset(
			const uint ixMsdcVPreset
			, const ubigint jref
			, const string& sref
		) {
	return(addPreset(ixMsdcVPreset, jref, Arg(0, 0, {}, sref, 0, 0.0, false, "", Arg::SREF)));
};

Preset* XchgMsdccmbd::addIntvalPreset(
			const uint ixMsdcVPreset
			, const ubigint jref
			, const int intval
		) {
	return(addPreset(ixMsdcVPreset, jref, Arg(0, 0, {}, "", intval, 0.0, false, "", Arg::INTVAL)));
};

Preset* XchgMsdccmbd::addDblvalPreset(
			const uint ixMsdcVPreset
			, const ubigint jref
			, const double dblval
		) {
	return(addPreset(ixMsdcVPreset, jref, Arg(0, 0, {}, "", 0, dblval, false, "", Arg::DBLVAL)));
};

Preset* XchgMsdccmbd::addBoolvalPreset(
			const uint ixMsdcVPreset
			, const ubigint jref
			, const bool boolval
		) {
	return(addPreset(ixMsdcVPreset, jref, Arg(0, 0, {}, "", 0, 0.0, boolval, "", Arg::BOOLVAL)));
};

Preset* XchgMsdccmbd::addTxtvalPreset(
			const uint ixMsdcVPreset
			, const ubigint jref
			, const string& txtval
		) {
	return(addPreset(ixMsdcVPreset, jref, Arg(0, 0, {}, "", 0, 0.0, false, txtval, Arg::TXTVAL)));
};

Preset* XchgMsdccmbd::getPresetByPref(
			const presetref_t& pref
		) {
	Preset* preset = NULL;

	Mutex::lock(&mPresets, "mPresets", "XchgMsdccmbd", "getPresetByPref");

	auto it = presets.find(pref);
	if (it != presets.end()) preset = it->second;

	Mutex::unlock(&mPresets, "mPresets", "XchgMsdccmbd", "getPresetByPref");

	return preset;
};

Arg XchgMsdccmbd::getPreset(
			const uint ixMsdcVPreset
			, const ubigint jref
		) {
	Arg arg;

	JobMsdc* job = NULL;
	Preset* preset = NULL;

	if ( (ixMsdcVPreset == VecMsdcVPreset::PREMSDCSYSDATE) || (ixMsdcVPreset == VecMsdcVPreset::PREMSDCSYSTIME) || (ixMsdcVPreset == VecMsdcVPreset::PREMSDCSYSSTAMP) ) {
		time_t rawtime;
		time(&rawtime);

		arg.mask = Arg::INTVAL;

		if (ixMsdcVPreset == VecMsdcVPreset::PREMSDCSYSDATE) arg.intval = (rawtime-rawtime%(3600*24))/(3600*24);
		else if (ixMsdcVPreset == VecMsdcVPreset::PREMSDCSYSTIME) arg.intval = rawtime%(3600*24);
		else if (ixMsdcVPreset == VecMsdcVPreset::PREMSDCSYSSTAMP) arg.intval = rawtime;

	} else {
		Mutex::lock(&mJobs, "mJobs", "XchgMsdccmbd", "getPreset");
		Mutex::lock(&mPresets, "mPresets", "XchgMsdccmbd", "getPreset");
		
		job = getJobByJref(jref);

		if ( (job != NULL) && (ixMsdcVPreset == VecMsdcVPreset::PREMSDCIXLCL) ) {
			arg.mask = Arg::IX;
			arg.ix = job->ixMsdcVLocale;

		} else {
			while (job && !preset) {
				preset = getPresetByPref(presetref_t(job->jref, ixMsdcVPreset));

				if (preset) arg = preset->arg;
				else job = getJobByJref(job->jrefSup);
			};
		};

		Mutex::unlock(&mPresets, "mPresets", "XchgMsdccmbd", "getPreset");
		Mutex::unlock(&mJobs, "mJobs", "XchgMsdccmbd", "getPreset");
	};

	return(arg);
};

uint XchgMsdccmbd::getIxPreset(
			const uint ixMsdcVPreset
			, const ubigint jref
		) {
	Arg arg = getPreset(ixMsdcVPreset, jref);

	if (arg.mask & Arg::IX) return(arg.ix);
	else return(0);
};

ubigint XchgMsdccmbd::getRefPreset(
			const uint ixMsdcVPreset
			, const ubigint jref
		) {
	Arg arg = getPreset(ixMsdcVPreset, jref);

	if (arg.mask & Arg::REF) return(arg.ref);
	else return(0);
};

vector<ubigint> XchgMsdccmbd::getRefsPreset(
			const uint ixMsdcVPreset
			, const ubigint jref
		) {
	Arg arg = getPreset(ixMsdcVPreset, jref);
	vector<ubigint> empty;

	if (arg.mask & Arg::REFS) return(arg.refs);
	else return(empty);
};

string XchgMsdccmbd::getSrefPreset(
			const uint ixMsdcVPreset
			, const ubigint jref
		) {
	Arg arg = getPreset(ixMsdcVPreset, jref);

	if (arg.mask & Arg::SREF) return(arg.sref);
	else return("");
};

int XchgMsdccmbd::getIntvalPreset(
			const uint ixMsdcVPreset
			, const ubigint jref
		) {
	Arg arg = getPreset(ixMsdcVPreset, jref);

	if (arg.mask & Arg::INTVAL) return(arg.intval);
	else return(intvalInvalid);
};

double XchgMsdccmbd::getDblvalPreset(
			const uint ixMsdcVPreset
			, const ubigint jref
		) {
	Arg arg = getPreset(ixMsdcVPreset, jref);

	if (arg.mask & Arg::DBLVAL) return(arg.dblval);
	else return(dblvalInvalid);
};

bool XchgMsdccmbd::getBoolvalPreset(
			const uint ixMsdcVPreset
			, const ubigint jref
		) {
	Arg arg = getPreset(ixMsdcVPreset, jref);

	if (arg.mask & Arg::BOOLVAL) return(arg.boolval);
	else return(false);
};

string XchgMsdccmbd::getTxtvalPreset(
			const uint ixMsdcVPreset
			, const ubigint jref
		) {
	Arg arg = getPreset(ixMsdcVPreset, jref);

	if (arg.mask & Arg::TXTVAL) return(arg.txtval);
	else return("");
};

void XchgMsdccmbd::getPresetsByJref(
			const ubigint jref
			, vector<uint>& icsMsdcVPreset
			, vector<Arg>& args
		) {
	Preset* preset = NULL;

	icsMsdcVPreset.clear();
	args.clear();

	Mutex::lock(&mPresets, "mPresets", "XchgMsdccmbd", "getPresetsByJref");

	auto rng = presets.equal_range(presetref_t(jref, 0));
	for (auto it=rng.first;it!=rng.second;it++) {
		preset = it->second;

		icsMsdcVPreset.push_back(preset->pref.ixVPreset);
		args.push_back(preset->arg);
	};

	Mutex::unlock(&mPresets, "mPresets", "XchgMsdccmbd", "getPresetsByJref");
};

void XchgMsdccmbd::removePreset(
			const uint ixMsdcVPreset
			, const ubigint jref
		) {
	Mutex::lock(&mPresets, "mPresets", "XchgMsdccmbd", "removePreset");

	auto it = presets.find(presetref_t(jref, ixMsdcVPreset));
	if (it != presets.end()) {
		delete it->second;
		presets.erase(it);

		mon.eventRemovePreset(jref, VecMsdcVPreset::getSref(ixMsdcVPreset));
	};

	Mutex::unlock(&mPresets, "mPresets", "XchgMsdccmbd", "removePreset");
};

void XchgMsdccmbd::removePresetsByJref(
			const ubigint jref
		) {
	Mutex::lock(&mPresets, "mPresets", "XchgMsdccmbd", "removePresetsByJref");

	uint ixVPreset;

	auto rng = presets.equal_range(presetref_t(jref, 0));
	for (auto it=rng.first;it!=rng.second;it++) {
		ixVPreset = it->second->pref.ixVPreset;
		delete it->second;

		mon.eventRemovePreset(jref, VecMsdcVPreset::getSref(ixVPreset));
	};
	presets.erase(rng.first, rng.second);

	Mutex::unlock(&mPresets, "mPresets", "XchgMsdccmbd", "removePresetsByJref");
};

StmgrMsdc* XchgMsdccmbd::addStmgr(
			const ubigint jref
			, const uint ixVNonetype
		) {
	StmgrMsdc* stmgr = NULL;

	// create new stmgr and append to stmgr list
	Mutex::lock(&mStmgrs, "mStmgrs", "XchgMsdccmbd", "addStmgr");

	stmgr = getStmgrByJref(jref);

	if (!stmgr) {
		stmgr = new StmgrMsdc(this, jref, ixVNonetype);
		stmgrs[jref] = stmgr;

		mon.eventAddStmgr(jref);
	};

	Mutex::unlock(&mStmgrs, "mStmgrs", "XchgMsdccmbd", "addStmgr");

	return(stmgr);
};

StmgrMsdc* XchgMsdccmbd::getStmgrByJref(
			const ubigint jref
		) {
	StmgrMsdc* stmgr = NULL;

	Mutex::lock(&mStmgrs, "mStmgrs", "XchgMsdccmbd", "getStmgrByJref");

	auto it = stmgrs.find(jref);

	if (it != stmgrs.end()) {
		stmgr = it->second;
		stmgr->lockAccess("XchgMsdccmbd", "getStmgrByJref");
	};

	Mutex::unlock(&mStmgrs, "mStmgrs", "XchgMsdccmbd", "getStmgrByJref");

	return(stmgr);
};

void XchgMsdccmbd::removeStmgrByJref(
			const ubigint jref
		) {
	Mutex::lock(&mStmgrs, "mStmgrs", "XchgMsdccmbd", "removeStmgrByJref");

	removeClstnsByJref(jref, Clstn::VecVTarget::STMGR);

	auto it = stmgrs.find(jref);
	if (it != stmgrs.end()) {
		delete it->second;
		stmgrs.erase(it);

		mon.eventRemoveStmgr(jref);
	};

	Mutex::unlock(&mStmgrs, "mStmgrs", "XchgMsdccmbd", "removeStmgrByJref");
};

Clstn* XchgMsdccmbd::addClstn(
			const uint ixMsdcVCall
			, const ubigint jref
			, const uint ixVJobmask
			, const ubigint jrefTrig
			, const Arg& argMask
			, const uint ixVJactype
		) {
	clstnref_t cref(ixMsdcVCall, jref, Clstn::VecVTarget::JOB, ixVJobmask, jrefTrig);
	clstnref2_t cref2(cref);
	Clstn* clstn;

	// create new clstn and append to clstn list
	Mutex::lock(&mClstns, "mClstns", "XchgMsdccmbd", "addClstn");

	clstn = getClstnByCref(cref);

	if (clstn) {
		clstn->argMask = argMask;
		clstn->ixVJactype = ixVJactype;

		mon.eventChangeClstn(jref, VecMsdcVCall::getSref(ixMsdcVCall), "job", Clstn::VecVJobmask::getSref(ixVJobmask), jrefTrig, argMask.writeText(), Clstn::VecVJactype::getSref(ixVJactype));

	} else {
		clstn = new Clstn(cref, argMask, ixVJactype);
		clstns.insert(pair<clstnref_t,Clstn*>(cref, clstn));
		cref2sClstns.insert(pair<clstnref2_t,clstnref_t>(cref2, cref));

		mon.eventAddClstn(jref, VecMsdcVCall::getSref(ixMsdcVCall), "job", Clstn::VecVJobmask::getSref(ixVJobmask), jrefTrig, argMask.writeText(), Clstn::VecVJactype::getSref(ixVJactype));
	};

	Mutex::unlock(&mClstns, "mClstns", "XchgMsdccmbd", "addClstn");

	return(clstn);
};

Clstn* XchgMsdccmbd::addIxClstn(
			const uint ixMsdcVCall
			, const ubigint jref
			, const uint ixVJobmask
			, const ubigint jrefTrig
			, const uint ixMask
			, const uint ixVJactype
		) {
	Arg argMask(ixMask, 0, {}, "", 0, 0.0, false, "", Arg::IX);

	return(addClstn(ixMsdcVCall, jref, ixVJobmask, jrefTrig, argMask, ixVJactype));
};

Clstn* XchgMsdccmbd::addRefClstn(
			const uint ixMsdcVCall
			, const ubigint jref
			, const uint ixVJobmask
			, const ubigint jrefTrig
			, const ubigint refMask
			, const uint ixVJactype
		) {
	Arg argMask(0, refMask, {}, "", 0, 0.0, false, "", Arg::REF);

	return(addClstn(ixMsdcVCall, jref, ixVJobmask, jrefTrig, argMask, ixVJactype));
};

Clstn* XchgMsdccmbd::addIxRefClstn(
			const uint ixMsdcVCall
			, const ubigint jref
			, const uint ixVJobmask
			, const ubigint jrefTrig
			, const uint ixMask
			, const ubigint refMask
			, const uint ixVJactype
		) {
	Arg argMask(ixMask, refMask, {}, "", 0, 0.0, false, "", Arg::IX + Arg::REF);

	return(addClstn(ixMsdcVCall, jref, ixVJobmask, jrefTrig, argMask, ixVJactype));
};

Clstn* XchgMsdccmbd::addIxRefSrefClstn(
			const uint ixMsdcVCall
			, const ubigint jref
			, const uint ixVJobmask
			, const ubigint jrefTrig
			, const uint ixMask
			, const ubigint refMask
			, const string& srefMask
			, const uint ixVJactype
		) {
	Arg argMask(ixMask, refMask, {}, srefMask, 0, 0.0, false, "", Arg::IX + Arg::REF + Arg::SREF);

	return(addClstn(ixMsdcVCall, jref, ixVJobmask, jrefTrig, argMask, ixVJactype));
};

Clstn* XchgMsdccmbd::addClstnStmgr(
			const uint ixMsdcVCall
			, const ubigint jref
		) {
	clstnref_t cref(ixMsdcVCall, jref, Clstn::VecVTarget::STMGR, Clstn::VecVJobmask::ALL, 0);
	clstnref2_t cref2(cref);
	Clstn* clstn;

	// create new clstn and append to clstn list
	Mutex::lock(&mClstns, "mClstns", "XchgMsdccmbd", "addClstnStmgr");

	clstn = getClstnByCref(cref);

	if (!clstn) {
		clstn = new Clstn(cref, Arg(), Clstn::VecVJactype::LOCK);
		clstns.insert(pair<clstnref_t,Clstn*>(cref, clstn));
		cref2sClstns.insert(pair<clstnref2_t,clstnref_t>(cref2, cref));

		mon.eventAddClstn(jref, VecMsdcVCall::getSref(ixMsdcVCall), "stmgr", Clstn::VecVJobmask::getSref(Clstn::VecVJobmask::ALL), 0, "", Clstn::VecVJactype::getSref(Clstn::VecVJactype::LOCK));
	};

	Mutex::unlock(&mClstns, "mClstns", "XchgMsdccmbd", "addClstnStmgr");

	return(clstn);
};

Clstn* XchgMsdccmbd::addClstnDdspub(
			const ubigint jrefTrig
			, const string& srefMask
		) {
	clstnref_t cref(VecMsdcVCall::CALLMSDCSHRDATCHG, 1, Clstn::VecVTarget::DDSPUB, Clstn::VecVJobmask::SPEC, jrefTrig);
	clstnref2_t cref2(cref);
	Clstn* clstn;

	// create new clstn and append to clstn list
	Mutex::lock(&mClstns, "mClstns", "XchgMsdccmbd", "addClstnDdspub");

	clstn = getClstnByCref(cref);

	if (!clstn) {
		clstn = new Clstn(cref, Arg(0, 0, {}, srefMask, 0, 0.0, false, "", Arg::SREF), Clstn::VecVJactype::LOCK);
		clstns.insert(pair<clstnref_t,Clstn*>(cref, clstn));
		cref2sClstns.insert(pair<clstnref2_t,clstnref_t>(cref2, cref));

		mon.eventAddClstn(0, "CallMsdcShrdatChg", "ddspub", Clstn::VecVJobmask::getSref(Clstn::VecVJobmask::SPEC), jrefTrig, "sref='" + srefMask + "'", Clstn::VecVJactype::getSref(Clstn::VecVJactype::LOCK));
	};

	Mutex::unlock(&mClstns, "mClstns", "XchgMsdccmbd", "addClstnDdspub");

	return(clstn);
};

Clstn* XchgMsdccmbd::addClstnUasrv(
			const ubigint jrefTrig
			, const string& srefMask
		) {
	clstnref_t cref(VecMsdcVCall::CALLMSDCSHRDATCHG, 1, Clstn::VecVTarget::UASRV, Clstn::VecVJobmask::SPEC, jrefTrig);
	clstnref2_t cref2(cref);
	Clstn* clstn;

	// create new clstn and append to clstn list
	Mutex::lock(&mClstns, "mClstns", "XchgMsdccmbd", "addClstnUasrv");

	clstn = getClstnByCref(cref);

	if (!clstn) {
		clstn = new Clstn(cref, Arg(0, 0, {}, srefMask, 0, 0.0, false, "", Arg::SREF), Clstn::VecVJactype::LOCK);
		clstns.insert(pair<clstnref_t,Clstn*>(cref, clstn));
		cref2sClstns.insert(pair<clstnref2_t,clstnref_t>(cref2, cref));

		mon.eventAddClstn(0, "CallMsdcShrdatChg", "uasrv", Clstn::VecVJobmask::getSref(Clstn::VecVJobmask::SPEC), jrefTrig, "sref='" + srefMask + "'", Clstn::VecVJactype::getSref(Clstn::VecVJactype::LOCK));
	};

	Mutex::unlock(&mClstns, "mClstns", "XchgMsdccmbd", "addClstnUasrv");

	return(clstn);
};

Clstn* XchgMsdccmbd::getClstnByCref(
			const clstnref_t& cref
		) {
	Clstn* clstn = NULL;

	Mutex::lock(&mClstns, "mClstns", "XchgMsdccmbd", "getClstnByCref");

	auto it = clstns.find(cref);
	if (it != clstns.end()) clstn = it->second;

	Mutex::unlock(&mClstns, "mClstns", "XchgMsdccmbd", "getClstnByCref");

	return clstn;
};

void XchgMsdccmbd::getClstnsByJref(
			const ubigint jref
			, const uint ixVTarget
			, vector<uint>& icsMsdcVCall
			, vector<uint>& icsVJobmask
		) {
	Clstn* clstn = NULL;

	icsMsdcVCall.clear();
	icsVJobmask.clear();

	Mutex::lock(&mClstns, "mClstns", "XchgMsdccmbd", "getClstnsByJref");

	auto rng = cref2sClstns.equal_range(clstnref2_t(jref, ixVTarget, 0));
	for (auto it=rng.first;it!=rng.second;it++) {
		clstn = getClstnByCref(it->second);

		if (clstn) {
			icsMsdcVCall.push_back(clstn->cref.ixVCall);
			icsVJobmask.push_back(clstn->cref.ixVJobmask);
		};
	};

	Mutex::unlock(&mClstns, "mClstns", "XchgMsdccmbd", "getClstnsByJref");
};

void XchgMsdccmbd::removeClstns(
			const uint ixMsdcVCall
			, const ubigint jref
			, const uint ixVTarget
		) {
	Mutex::lock(&mClstns, "mClstns", "XchgMsdccmbd", "removeClstns");

	uint ixVJobmask;
	ubigint jrefTrig;

	auto rng = clstns.equal_range(clstnref_t(ixMsdcVCall, jref, ixVTarget));
	for (auto it=rng.first;it!=rng.second;it++) {
		ixVJobmask = it->second->cref.ixVJobmask;
		jrefTrig = it->second->cref.jrefTrig;

		cref2sClstns.erase(clstnref2_t(it->first));
		delete it->second;

		mon.eventRemoveClstn(jref, VecMsdcVCall::getSref(ixMsdcVCall), Clstn::VecVTarget::getSref(ixVTarget), Clstn::VecVJobmask::getSref(ixVJobmask), jrefTrig);
	};
	clstns.erase(rng.first, rng.second);

	Mutex::unlock(&mClstns, "mClstns", "XchgMsdccmbd", "removeClstns");
};

void XchgMsdccmbd::removeClstnsByJref(
			const ubigint jref
			, const uint ixVTarget
		) {
	Mutex::lock(&mClstns, "mClstns", "XchgMsdccmbd", "removeClstnsByJref");

	uint ixVCall;
	uint ixVJobmask;
	ubigint jrefTrig;

	auto rng = cref2sClstns.equal_range(clstnref2_t(jref, ixVTarget));
	for (auto it=rng.first;it!=rng.second;it++) {
		auto it2 = clstns.find(it->second);

		ixVCall = it2->second->cref.ixVCall;
		ixVJobmask = it2->second->cref.ixVJobmask;
		jrefTrig = it2->second->cref.jrefTrig;

		delete it2->second;
		clstns.erase(it2);

		mon.eventRemoveClstn(jref, VecMsdcVCall::getSref(ixVCall), Clstn::VecVJobmask::getSref(ixVTarget), Clstn::VecVJobmask::getSref(ixVJobmask), jrefTrig);
	};
	cref2sClstns.erase(rng.first, rng.second);

	Mutex::unlock(&mClstns, "mClstns", "XchgMsdccmbd", "removeClstnsByJref");
};

void XchgMsdccmbd::findJrefsByCall(
			Call* call
			, vector<ubigint>& jrefs
			, vector<uint>& icsVTarget
			, vector<uint>& icsVJactype
		) {
	Clstn* clstn = NULL;

	JobMsdc* job = NULL;
	JobMsdc* job2 = NULL;

	bool match;

	Mutex::lock(&mJobs, "mJobs", "XchgMsdccmbd", "findJrefsByCall");
	Mutex::lock(&mClstns, "mClstns", "XchgMsdccmbd", "findJrefsByCall");

	auto rng = clstns.equal_range(clstnref_t(call->ixVCall, 0));
	for (auto it=rng.first;it!=rng.second;it++) {
		clstn = it->second;

		if (clstn->cref.ixVTarget == Clstn::VecVTarget::JOB) {
			match = true;

			if (clstn->argMask.mask & Arg::IX) if (clstn->argMask.ix != call->argInv.ix) match = false;
			if (clstn->argMask.mask & Arg::REF) if (clstn->argMask.ref != call->argInv.ref) match = false;
			if (clstn->argMask.mask & Arg::SREF) if (clstn->argMask.sref != call->argInv.sref) match = false;
			if (clstn->argMask.mask & Arg::INTVAL) if (clstn->argMask.intval != call->argInv.intval) match = false;
			if (clstn->argMask.mask & Arg::DBLVAL) if (clstn->argMask.dblval != call->argInv.dblval) match = false;
			if (clstn->argMask.mask & Arg::BOOLVAL) if (clstn->argMask.boolval != call->argInv.boolval) match = false;
			if (clstn->argMask.mask & Arg::TXTVAL) if (clstn->argMask.txtval != call->argInv.txtval) match = false;

			if (match) {
				match = false;

				if (clstn->cref.ixVJobmask == Clstn::VecVJobmask::ALL) {
					// don't care about call->jref
					match = true;

				} else if (clstn->cref.ixVJobmask == Clstn::VecVJobmask::IMM) {
					// check if trigger job is immediate sub-job to listener job
					if (!job) job = getJobByJref(call->jref);
					if (job) if (job->jrefSup == clstn->cref.jref) match = true;

				} else if (clstn->cref.ixVJobmask == Clstn::VecVJobmask::MAST) {
					// check if trigger job is master job to listener job
					if (call->jref != clstn->cref.jref) {
						if (!job) job = getJobByJref(call->jref);
						job2 = getJobByJref(clstn->cref.jref);

						if (job && job2) if (job->ixMsdcVJob == job2->ixMsdcVJob) if (getMsjobMastNotSlv((MsjobMsdc*) job)) match = true;
					};

				} else if (clstn->cref.ixVJobmask == Clstn::VecVJobmask::SELF) {
					// check if trigger job is equivalent to listener job
					if (call->jref == clstn->cref.jref) match = true;

				} else if (clstn->cref.ixVJobmask == Clstn::VecVJobmask::SLV) {
					// check if listener job is master job to trigger job
					if (call->jref != clstn->cref.jref) {
						if (!job) job = getJobByJref(call->jref);
						job2 = getJobByJref(clstn->cref.jref);

						if (job && job2) if (job->ixMsdcVJob == job2->ixMsdcVJob) if (getMsjobMastNotSlv((MsjobMsdc*) job2)) match = true;
					};

				} else if (clstn->cref.ixVJobmask == Clstn::VecVJobmask::SPEC) {
					// require specific jref
					if (clstn->cref.jrefTrig == call->jref) match = true;

				} else if (clstn->cref.ixVJobmask == Clstn::VecVJobmask::TREE) {
					// check if trigger job is down the tree from listener job ; note that the order in jobs is unordered (unfortunately)
					job2 = getJobByJref(call->jref);

					while (job2 != NULL) {
						if (job2->jref == clstn->cref.jref) {
							// add
							match = true;
							break;
						};

						job2 = getJobByJref(job2->jrefSup);
					};
				};
			};

			if (match) {
				jrefs.push_back(clstn->cref.jref);
				icsVTarget.push_back(clstn->cref.ixVTarget);
				icsVJactype.push_back(clstn->ixVJactype);
			};

		} else if (clstn->cref.ixVTarget == Clstn::VecVTarget::STMGR) {
			jrefs.push_back(clstn->cref.jref);
			icsVTarget.push_back(clstn->cref.ixVTarget);
			icsVJactype.push_back(0);

		} else {
			match = true;

			if (clstn->argMask.mask & Arg::SREF) if (clstn->argMask.sref != call->argInv.sref) match = false;

			if (match) if (clstn->cref.ixVJobmask == Clstn::VecVJobmask::SPEC) if (clstn->cref.jrefTrig != call->jref) match = false;

			if (match) {
				jrefs.push_back(clstn->cref.jref);
				icsVTarget.push_back(clstn->cref.ixVTarget);
				icsVJactype.push_back(0);
			};
		};
	};

	Mutex::unlock(&mClstns, "mClstns", "XchgMsdccmbd", "findJrefsByCall");
	Mutex::unlock(&mJobs, "mJobs", "XchgMsdccmbd", "findJrefsByCall");
};

void XchgMsdccmbd::triggerCall(
			DbsMsdc* dbsmsdc
			, Call* call
		) {
	vector<ubigint> jrefs;
	vector<uint> icsVTarget;
	vector<uint> icsVJactype;

	uint ixVTarget;
	ubigint jref;
	uint ixVJactype;

	JobMsdc* job = NULL;

	StmgrMsdc* stmgr = NULL;

	ubigint eref;

	Arg argRet_old;

	eref = mon.eventTriggerCall(call->jref, VecMsdcVCall::getSref(call->ixVCall), call->argInv.writeText());

	findJrefsByCall(call, jrefs, icsVTarget, icsVJactype);

	for (unsigned int i=0;i<jrefs.size();i++) {
		jref = jrefs[i];
		ixVTarget = icsVTarget[i];
		ixVJactype = icsVJactype[i];

		if (ixVTarget == Clstn::VecVTarget::JOB) {
			job = getJobByJref(jref);
			if (job) {
				if (ixVJactype != Clstn::VecVJactype::WEAK) {
					if (ixVJactype == Clstn::VecVJactype::LOCK) {
						job->lockAccess("XchgMsdccmbd", "triggerCall");

					} else if (ixVJactype == Clstn::VecVJactype::TRY) {
						if (Mutex::trylock(&(job->mAccess), "job(" + to_string(jref) + ")->mAccess", "XchgMsdccmbd", "triggerCall") == EBUSY) continue;
					};
				};

				mon.eventHandleCall(eref, jref);
				argRet_old = call->argRet;

				job->handleCall(dbsmsdc, call);

				if (call->argRet != argRet_old) mon.eventRetCall(eref, jref, call->argRet.writeText());
			};

			if (ixVJactype != Clstn::VecVJactype::WEAK) {
				job = getJobByJref(jref);
				if (job) job->unlockAccess("XchgMsdccmbd", "triggerCall");
			};

		} else if (ixVTarget == Clstn::VecVTarget::STMGR) {
			stmgr = getStmgrByJref(jref);

			if (stmgr) {
				mon.eventHandleCall(eref, jref);
				argRet_old = call->argRet;

				stmgr->handleCall(dbsmsdc, call);

				if (!(call->argRet == argRet_old)) mon.eventRetCall(eref, jref, call->argRet.writeText());

				stmgr->unlockAccess("XchgMsdccmbd", "triggerCall");
			};

		} else if (ixVTarget == Clstn::VecVTarget::DDSPUB) {
			Mutex::lock(&mDdspubcall, "mDdspubcall", "XchgMsdccmbd", "triggerCall");

			Mutex::lock(&mcDdspub, "mcDdspub", "XchgMsdccmbd", "triggerCall[1]");
			ddspubcall = call;
			Mutex::unlock(&mcDdspub, "mcDdspub", "XchgMsdccmbd", "triggerCall[1]");

			mon.eventHandleCall(eref, jref);
			Cond::signal(&cDdspub, &mcDdspub, "cDdspub", "mcDdspub", "XchgMsdccmbd", "triggerCall");

			Mutex::lock(&mcDdspub, "mcDdspub", "XchgMsdccmbd", "triggerCall[2]");
			if (ddspubcall) Cond::wait(&cDdspub, &mcDdspub, "cDdspub", "XchgMsdccmbd", "triggerCall");
			Mutex::unlock(&mcDdspub, "mcDdspub", "XchgMsdccmbd", "triggerCall[2]");

			Mutex::unlock(&mDdspubcall, "mDdspubcall", "XchgMsdccmbd", "triggerCall");

		} else if (ixVTarget == Clstn::VecVTarget::UASRV) {
			Mutex::lock(&mUasrvcall, "mUasrvcall", "XchgMsdccmbd", "triggerCall");

			Mutex::lock(&mcUasrv, "mcUasrv", "XchgMsdccmbd", "triggerCall[1]");
			uasrvcall = call;
			Mutex::unlock(&mcUasrv, "mcUasrv", "XchgMsdccmbd", "triggerCall[1]");

			mon.eventHandleCall(eref, jref);
			
			Mutex::lock(&mcUasrv, "mcUasrv", "XchgMsdccmbd", "triggerCall[2]");
			if (uasrvcall) Cond::wait(&cUasrv, &mcUasrv, "cUasrv", "XchgMsdccmbd", "triggerCall");
			Mutex::unlock(&mcUasrv, "mcUasrv", "XchgMsdccmbd", "triggerCall[2]");

			Mutex::unlock(&mUasrvcall, "mUasrvcall", "XchgMsdccmbd", "triggerCall");
		};

		if (call->abort) break;
	};

	mon.eventFinalizeCall(eref);
};

bool XchgMsdccmbd::triggerArgToArgCall(
			DbsMsdc* dbsmsdc
			, const uint ixMsdcVCall
			, const ubigint jref
			, const Arg& argInv
			, Arg& argRet
		) {
	Call* call;
	ubigint retval;

  call = new Call(ixMsdcVCall, jref, argInv);
	triggerCall(dbsmsdc, call);

	argRet = call->argRet;
	retval = call->abort;

  delete call;
	return retval;
};

bool XchgMsdccmbd::triggerCall(
			DbsMsdc* dbsmsdc
			, const uint ixMsdcVCall
			, const ubigint jref
		) {
	Arg argInv;
	Arg argRet;

	return(triggerArgToArgCall(dbsmsdc, ixMsdcVCall, jref, argInv, argRet));
};

bool XchgMsdccmbd::triggerIxCall(
			DbsMsdc* dbsmsdc
			, const uint ixMsdcVCall
			, const ubigint jref
			, const uint ixInv
		) {
	Arg argInv(ixInv, 0, {}, "", 0, 0.0, false, "", Arg::IX);
	Arg argRet;

	return(triggerArgToArgCall(dbsmsdc, ixMsdcVCall, jref, argInv, argRet));
};

bool XchgMsdccmbd::triggerRefCall(
			DbsMsdc* dbsmsdc
			, const uint ixMsdcVCall
			, const ubigint jref
			, const ubigint refInv
		) {
	Arg argInv(0, refInv, {}, "", 0, 0.0, false, "", Arg::REF);
	Arg argRet;

	return(triggerArgToArgCall(dbsmsdc, ixMsdcVCall, jref, argInv, argRet));
};

bool XchgMsdccmbd::triggerIntvalCall(
			DbsMsdc* dbsmsdc
			, const uint ixMsdcVCall
			, const ubigint jref
			, const int intvalInv
		) {
	Arg argInv(0, 0, {}, "", intvalInv, 0.0, false, "", Arg::INTVAL);
	Arg argRet;

	return(triggerArgToArgCall(dbsmsdc, ixMsdcVCall, jref, argInv, argRet));
};

bool XchgMsdccmbd::triggerBoolvalCall(
			DbsMsdc* dbsmsdc
			, const uint ixMsdcVCall
			, const ubigint jref
			, const bool boolvalInv
		) {
	Arg argInv(0, 0, {}, "", 0, 0.0, boolvalInv, "", Arg::BOOLVAL);
	Arg argRet;

	return(triggerArgToArgCall(dbsmsdc, ixMsdcVCall, jref, argInv, argRet));
};

bool XchgMsdccmbd::triggerIxRefCall(
			DbsMsdc* dbsmsdc
			, const uint ixMsdcVCall
			, const ubigint jref
			, const uint ixInv
			, const ubigint refInv
		) {
	Arg argInv(ixInv, refInv, {}, "", 0, 0.0, false, "", Arg::IX + Arg::REF);
	Arg argRet;

	return(triggerArgToArgCall(dbsmsdc, ixMsdcVCall, jref, argInv, argRet));
};

bool XchgMsdccmbd::triggerIxSrefCall(
			DbsMsdc* dbsmsdc
			, const uint ixMsdcVCall
			, const ubigint jref
			, const uint ixInv
			, const string& srefInv
		) {
	Arg argInv(ixInv, 0, {}, srefInv, 0, 0.0, false, "", Arg::IX + Arg::SREF);
	Arg argRet;

	return(triggerArgToArgCall(dbsmsdc, ixMsdcVCall, jref, argInv, argRet));
};

bool XchgMsdccmbd::triggerIxSrefToIxCall(
			DbsMsdc* dbsmsdc
			, const uint ixMsdcVCall
			, const ubigint jref
			, const uint ixInv
			, const string& srefInv
			, uint& ixRet
		) {
	bool retval;

	Arg argInv(ixInv, 0, {}, srefInv, 0, 0.0, false, "", Arg::IX + Arg::SREF);
	Arg argRet;

	retval = triggerArgToArgCall(dbsmsdc, ixMsdcVCall, jref, argInv, argRet);

	if (!retval) ixRet = argRet.ix;
	
	return retval;
};

bool XchgMsdccmbd::triggerIxIntvalCall(
			DbsMsdc* dbsmsdc
			, const uint ixMsdcVCall
			, const ubigint jref
			, const uint ixInv
			, const int intvalInv
		) {
	Arg argInv(ixInv, 0, {}, "", intvalInv, 0.0, false, "", Arg::IX + Arg::INTVAL);
	Arg argRet;

	return(triggerArgToArgCall(dbsmsdc, ixMsdcVCall, jref, argInv, argRet));
};

bool XchgMsdccmbd::triggerIxDblvalCall(
			DbsMsdc* dbsmsdc
			, const uint ixMsdcVCall
			, const ubigint jref
			, const uint ixInv
			, const double dblvalInv
		) {
	Arg argInv(ixInv, 0, {}, "", 0, dblvalInv, false, "", Arg::IX + Arg::DBLVAL);
	Arg argRet;

	return(triggerArgToArgCall(dbsmsdc, ixMsdcVCall, jref, argInv, argRet));
};

bool XchgMsdccmbd::triggerIxTxtvalCall(
			DbsMsdc* dbsmsdc
			, const uint ixMsdcVCall
			, const ubigint jref
			, const uint ixInv
			, const string& txtvalInv
		) {
	Arg argInv(ixInv, 0, {}, "", 0, 0.0, false, txtvalInv, Arg::IX + Arg::TXTVAL);
	Arg argRet;

	return(triggerArgToArgCall(dbsmsdc, ixMsdcVCall, jref, argInv, argRet));
};

bool XchgMsdccmbd::triggerSrefCall(
			DbsMsdc* dbsmsdc
			, const uint ixMsdcVCall
			, const ubigint jref
			, const string& srefInv
		) {
	Arg argInv(0, 0, {}, srefInv, 0, 0.0, false, "", Arg::SREF);
	Arg argRet;

	return(triggerArgToArgCall(dbsmsdc, ixMsdcVCall, jref, argInv, argRet));
};

bool XchgMsdccmbd::triggerToBoolvalCall(
			DbsMsdc* dbsmsdc
			, const uint ixMsdcVCall
			, const ubigint jref
			, bool& boolvalRet
		) {
	bool retval;

	Arg argInv;
	Arg argRet;

	retval = triggerArgToArgCall(dbsmsdc, ixMsdcVCall, jref, argInv, argRet);

	if (!retval) boolvalRet = argRet.boolval;

	return(retval);
};

bool XchgMsdccmbd::triggerIxToBoolvalCall(
			DbsMsdc* dbsmsdc
			, const uint ixMsdcVCall
			, const ubigint jref
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval;

	Arg argInv(ixInv, 0, {}, "", 0, 0.0, false, "", Arg::IX);
	Arg argRet;

	retval = triggerArgToArgCall(dbsmsdc, ixMsdcVCall, jref, argInv, argRet);

	if (!retval) boolvalRet = argRet.boolval;

	return(retval);
};

bool XchgMsdccmbd::triggerRefToSrefCall(
			DbsMsdc* dbsmsdc
			, const uint ixMsdcVCall
			, const ubigint jref
			, const ubigint refInv
			, string& srefRet
		) {
	bool retval;

	Arg argInv(0, refInv, {}, "", 0, 0.0, false, "", Arg::REF);
	Arg argRet;

	retval = triggerArgToArgCall(dbsmsdc, ixMsdcVCall, jref, argInv, argRet);

	if (!retval) srefRet = argRet.sref;

	return(retval);
};

bool XchgMsdccmbd::triggerRefToBoolvalCall(
			DbsMsdc* dbsmsdc
			, const uint ixMsdcVCall
			, const ubigint jref
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval;

	Arg argInv(0, refInv, {}, "", 0, 0.0, false, "", Arg::REF);
	Arg argRet;

	retval = triggerArgToArgCall(dbsmsdc, ixMsdcVCall, jref, argInv, argRet);

	if (!retval) boolvalRet = argRet.boolval;

	return(retval);
};

bool XchgMsdccmbd::triggerIxRefToIxCall(
			DbsMsdc* dbsmsdc
			, const uint ixMsdcVCall
			, const ubigint jref
			, const uint ixInv
			, const ubigint refInv
			, uint& ixRet
		) {
	bool retval;

	Arg argInv(ixInv, refInv, {}, "", 0, 0.0, false, "", Arg::IX + Arg::REF);
	Arg argRet;

	retval = triggerArgToArgCall(dbsmsdc, ixMsdcVCall, jref, argInv, argRet);

	if (!retval) ixRet = argRet.ix;

	return(retval);
};

bool XchgMsdccmbd::triggerIxRefToRefCall(
			DbsMsdc* dbsmsdc
			, const uint ixMsdcVCall
			, const ubigint jref
			, const uint ixInv
			, const ubigint refInv
			, ubigint& refRet
		) {
	bool retval;

	Arg argInv(ixInv, refInv, {}, "", 0, 0.0, false, "", Arg::IX + Arg::REF);
	Arg argRet;

	retval = triggerArgToArgCall(dbsmsdc, ixMsdcVCall, jref, argInv, argRet);

	if (!retval) refRet = argRet.ref;

	return(retval);
};

bool XchgMsdccmbd::triggerIxRefSrefCall(
			DbsMsdc* dbsmsdc
			, const uint ixMsdcVCall
			, const ubigint jref
			, const uint ixInv
			, const ubigint refInv
			, const string& srefInv
		) {
	bool retval;

	Arg argInv(ixInv, refInv, {}, srefInv, 0, 0.0, false, "", Arg::IX + Arg::REF + Arg::SREF);
	Arg argRet;

	retval = triggerArgToArgCall(dbsmsdc, ixMsdcVCall, jref, argInv, argRet);

	return(retval);
};

bool XchgMsdccmbd::triggerIxRefSrefIntvalCall(
			DbsMsdc* dbsmsdc
			, const uint ixMsdcVCall
			, const ubigint jref
			, const uint ixInv
			, const ubigint refInv
			, const string& srefInv
			, const int intvalInv
		) {
	bool retval;

	Arg argInv(ixInv, refInv, {}, srefInv, intvalInv, 0.0, false, "", Arg::IX + Arg::REF + Arg::SREF + Arg::INTVAL);
	Arg argRet;

	retval = triggerArgToArgCall(dbsmsdc, ixMsdcVCall, jref, argInv, argRet);

	return(retval);
};

bool XchgMsdccmbd::triggerIxRefSrefIntvalToRefCall(
			DbsMsdc* dbsmsdc
			, const uint ixMsdcVCall
			, const ubigint jref
			, const uint ixInv
			, const ubigint refInv
			, const string& srefInv
			, const int intvalInv
			, ubigint& refRet
		) {
	bool retval;

	Arg argInv(ixInv, refInv, {}, srefInv, intvalInv, 0.0, false, "", Arg::IX + Arg::REF + Arg::SREF + Arg::INTVAL);
	Arg argRet;

	retval = triggerArgToArgCall(dbsmsdc, ixMsdcVCall, jref, argInv, argRet);

	if (!retval) refRet = argRet.ref;

	return(retval);
};

bool XchgMsdccmbd::triggerRefToIxCall(
			DbsMsdc* dbsmsdc
			, const uint ixMsdcVCall
			, const ubigint jref
			, const ubigint refInv
			, uint& ixRet
		) {
	bool retval;

	Arg argInv(0, refInv, {}, "", 0, 0.0, false, "", Arg::REF);
	Arg argRet;

	retval = triggerArgToArgCall(dbsmsdc, ixMsdcVCall, jref, argInv, argRet);

	if (!retval) ixRet = argRet.ix;

	return(retval);
};

bool XchgMsdccmbd::triggerSrefToRefCall(
			DbsMsdc* dbsmsdc
			, const uint ixMsdcVCall
			, const ubigint jref
			, const string& srefInv
			, ubigint& refRet
		) {
	bool retval;

	Arg argInv(0, 0, {}, srefInv, 0, 0.0, false, "", Arg::SREF);
	Arg argRet;

	retval = triggerArgToArgCall(dbsmsdc, ixMsdcVCall, jref, argInv, argRet);

	if (!retval) refRet = argRet.ref;

	return(retval);
};

DcolMsdc* XchgMsdccmbd::addDcol(
			const ubigint jref
		) {
	JobMsdc* job = NULL;

	DcolMsdc* dcol = NULL;

	// create new dcol and append to dcol list
	Mutex::lock(&mJobs, "mJobs", "XchgMsdccmbd", "addDcol");
	Mutex::lock(&mDcols, "mDcols", "XchgMsdccmbd", "addDcol");

	job = getJobByJref(jref);

	if (job) {
		dcol = getDcolByJref(jref);

		if (!dcol) {
			dcol = new DcolMsdc(jref, job->ixMsdcVLocale);
			dcols[jref] = dcol;

			mon.eventAddDcol(jref);

			dcol->lockAccess("XchgMsdccmbd", "addDcol");
		};
	};

	Mutex::unlock(&mDcols, "mDcols", "XchgMsdccmbd", "addDcol");
	Mutex::unlock(&mJobs, "mJobs", "XchgMsdccmbd", "addDcol");

	// make dcol the session's active notify dcol
	triggerIxRefCall(NULL, VecMsdcVCall::CALLMSDCREFPRESET, jref, VecMsdcVPreset::PREMSDCJREFNOTIFY, jref);

	return(dcol);
};

DcolMsdc* XchgMsdccmbd::getDcolByJref(
			const ubigint jref
			, const bool tree
		) {
	JobMsdc* job = NULL;

	DcolMsdc* dcol = NULL;

	Mutex::lock(&mJobs, "mJobs", "XchgMsdccmbd", "getDcolByJref");
	Mutex::lock(&mDcols, "mDcols", "XchgMsdccmbd", "getDcolByJref");

	job = getJobByJref(jref);

	while (job != NULL) {
		auto it = dcols.find(job->jref);

		if (it != dcols.end()) {
			dcol = it->second;
			dcol->lockAccess("XchgMsdccmbd", "getDcolByJref");

			break;
		};

		if (!tree) break;

		job = getJobByJref(job->jrefSup);
	};

	Mutex::unlock(&mDcols, "mDcols", "XchgMsdccmbd", "addDcol");
	Mutex::unlock(&mJobs, "mJobs", "XchgMsdccmbd", "addDcol");

	return(dcol);
};

void XchgMsdccmbd::removeDcolByJref(
			const ubigint jref
		) {
	Mutex::lock(&mDcols, "mDcols", "XchgMsdccmbd", "removeDcolByJref");

	auto it = dcols.find(jref);
	if (it != dcols.end()) {
		delete it->second;
		dcols.erase(it);

		mon.eventRemoveDcol(jref);
	};

	Mutex::unlock(&mDcols, "mDcols", "XchgMsdccmbd", "removeDcolByJref");
};

void XchgMsdccmbd::removeDcolsByJref(
			const ubigint jref
		) {
	JobMsdc* job = NULL;

	DcolMsdc* dcol = NULL;

	vector<ubigint> jrefs;

	Mutex::lock(&mJobs, "mJobs", "XchgMsdccmbd", "removeDcolsByJref");
	Mutex::lock(&mDcols, "mDcols", "XchgMsdccmbd", "removeDcolsByJref");

	jrefs.push_back(jref);

	for (unsigned int i=0;i<jrefs.size();i++) {
		job = getJobByJref(jrefs[i]);

		if (job) for (auto it=job->jrefsSub.begin();it!=job->jrefsSub.end();it++) jrefs.push_back(*it);
	};

	for (unsigned int i=0;i<jrefs.size();i++) {
		auto it = dcols.find(jrefs[i]);
		if (it != dcols.end()) {
			delete it->second;
			dcols.erase(it);

			mon.eventRemoveDcol(jrefs[i]);
		};
	};

	Mutex::unlock(&mDcols, "mDcols", "XchgMsdccmbd", "removeDcolsByJref");
	Mutex::unlock(&mJobs, "mJobs", "XchgMsdccmbd", "removeDcolsByJref");
};

void XchgMsdccmbd::submitDpch(
			DpchEngMsdc* dpcheng
		) {
	DcolMsdc* dcol = NULL;

	pthread_cond_t* cReady_backup;
	pthread_mutex_t* mcReady_backup;

	DpchEngMsdc* dpchtest;

	// find dcol in charge
	dcol = getDcolByJref(dpcheng->jref);

	if (dcol) {
		mon.eventSubmitDpch(dpcheng->jref, VecMsdcVDpch::getSref(dpcheng->ixMsdcVDpch), dpcheng->getSrefsMask(), "");

		if (dcol->req != NULL) {
			// a request is waiting
			delete dcol->req->dpcheng;
			dcol->req->dpcheng = dpcheng;

			cReady_backup = &(dcol->req->cReady);
			mcReady_backup = &(dcol->req->mcReady);

			dcol->req = NULL;
			//cout << "XchgMsdccmbd::submitDpch() waiting request for ixMsdcVDpch = " << dpcheng->ixMsdcVDpch << ", jref = " << dpcheng->jref << endl;

			Cond::signal(cReady_backup, mcReady_backup, "dcol(" + to_string(dcol->jref) + ")->req->cReady", "dcol(" + to_string(dcol->jref) + ")->req->mcReady", "XchgMsdccmbd", "submitDpch");

			dcol->unlockAccess("XchgMsdccmbd", "submitDpch");

		} else {
			// merge with similar dispatch if available
			for (auto it=dcol->dpchs.begin();it!=dcol->dpchs.end();) {
				dpchtest = *it;

				if ((dpchtest->ixMsdcVDpch == dpcheng->ixMsdcVDpch) && (dpchtest->jref == dpcheng->jref)) {
					dpchtest->merge(dpcheng);
					//cout << "XchgMsdccmbd::submitDpch() merge for ixMsdcVDpch = " << dpcheng->ixMsdcVDpch << ", jref = " << dpcheng->jref << endl;

					delete dpcheng;
					dpcheng = NULL;

					break;

				} else it++;
			};

			// append to list of dispatches
			if (dpcheng) {
				dcol->dpchs.push_back(dpcheng);
				//cout << "XchgMsdccmbd::submitDpch() append for ixMsdcVDpch = " << dpcheng->ixMsdcVDpch << ", jref = " << dpcheng->jref << endl;
			};

			dcol->unlockAccess("XchgMsdccmbd", "submitDpch");
		};

	} else {
		delete dpcheng;
	};
};

DpchEngMsdc* XchgMsdccmbd::pullFirstDpch(
			DcolMsdc* dcol
		) {
	DpchEngMsdc* dpcheng = NULL;

	// get first element from list ; assume access is locked
	if (!dcol->dpchs.empty()) {
		dpcheng = *(dcol->dpchs.begin());
		dcol->dpchs.pop_front();
	};

	return dpcheng;
};

ubigint XchgMsdccmbd::addJob(
			JobMsdc* job
		) {
	JobMsdc* supjob = NULL;

	// get new jref and append to job list
	Mutex::lock(&mJobs, "mJobs", "XchgMsdccmbd", "addJob");

	job->jref = jrefseq->getNewRef();
	jobs[job->jref] = job;

	if (jobs.size() == 1) {
		// root job
		jrefRoot = job->jref;
		jrefCmd = job->jref;
	};

	supjob = getJobByJref(job->jrefSup);
	if (supjob) supjob->jrefsSub.insert(job->jref);

	mon.eventAddJob(job->jrefSup, VecMsdcVJob::getSref(job->ixMsdcVJob), job->jref);

	Mutex::unlock(&mJobs, "mJobs", "XchgMsdccmbd", "addJob");

	return(job->jref);
};

ubigint XchgMsdccmbd::addMsjob(
			DbsMsdc* dbsmsdc
			, MsjobMsdc* job
			, const bool syncsge
		) {
	JobMsdc* supjob = NULL;

	Msjobinfo* msji = NULL;
	MsjobMsdc* mastjob = NULL;

	// get new jref, append to job list and update master/slave job info
	Mutex::lock(&mJobs, "mJobs", "XchgMsdccmbd", "addMsjob");
	Mutex::lock(&mMsjobinfos, "mMsjobinfos", "XchgMsdccmbd", "addMsjob");

	job->jref = jrefseq->getNewRef();
	jobs[job->jref] = job;

	supjob = getJobByJref(job->jrefSup);
	if (supjob) supjob->jrefsSub.insert(job->jref);

	mon.eventAddJob(job->jrefSup, VecMsdcVJob::getSref(job->ixMsdcVJob), job->jref);

	auto it = msjobinfos.find(job->ixMsdcVJob);
	if (it != msjobinfos.end()) {
		msji = it->second;

		if (syncsge) job->ixVSge = msji->ixVSge;

		if (msji->jrefMast != 0) mastjob = (MsjobMsdc*) getJobByJref(msji->jrefMast);

		if (mastjob) {
			if (job->prefmast) {
				// priority for becoming new master
				msji->jrefsSlv.push_front(job->jref);

				mon.eventBecomeSlave(job->jref);

				job->becomeSlave(dbsmsdc, msji);

				claimMsjobMaster(dbsmsdc, job->jref);

			} else {
				msji->jrefsSlv.push_back(job->jref);

				mon.eventBecomeSlave(job->jref);

				job->becomeSlave(dbsmsdc, msji);
			};

		} else {
			// only job of its type
			msji->jrefMast = job->jref;

			mon.eventBecomeMaster(job->jref);

			job->becomeMaster(dbsmsdc, msji);
		};
	};

	Mutex::unlock(&mMsjobinfos, "mMsjobinfos", "XchgMsdccmbd", "addMsjob");
	Mutex::unlock(&mJobs, "mJobs", "XchgMsdccmbd", "addMsjob");

	return(job->jref);
};

JobMsdc* XchgMsdccmbd::getJobByJref(
			const ubigint jref
		) {
	JobMsdc* job = NULL;

	Mutex::lock(&mJobs, "mJobs", "XchgMsdccmbd", "getJobByJref");

	auto it = jobs.find(jref);
	if (it != jobs.end()) job = it->second;

	Mutex::unlock(&mJobs, "mJobs", "XchgMsdccmbd", "getJobByJref");

	return job;
};

void XchgMsdccmbd::removeJobByJref(
			const ubigint jref
		) {
	JobMsdc* supjob = NULL;
	JobMsdc* job = NULL;
	JobMsdc* subjob = NULL;

	Mutex::lock(&mJobs, "mJobs", "XchgMsdccmbd", "removeJobByJref");

	job = getJobByJref(jref);

	if (job) {
		job->invalidateWakeups();

		removePresetsByJref(jref);
		removeStmgrByJref(jref);
		removeClstnsByJref(jref);
		removeDcolByJref(jref);

		// super-job
		supjob = getJobByJref(job->jrefSup);
		if (supjob) supjob->jrefsSub.erase(jref);

		// sub-jobs
		while (job->jrefsSub.size() > 0) {
			subjob = getJobByJref(*(job->jrefsSub.begin()));
			if (subjob) delete subjob;
		};

		// remove job from list only here otherwise sub-job delete will loop forever
		jobs.erase(jref);

		mon.eventRemoveJob(jref);
	};

	if (jobs.empty()) {
		// root job
		jrefRoot = 0;
		jrefCmd = 0;
	};

	Mutex::unlock(&mJobs, "mJobs", "XchgMsdccmbd", "removeJobByJref");
};

void XchgMsdccmbd::removeMsjobByJref(
			const ubigint jref
		) {
	JobMsdc* supjob = NULL;
	MsjobMsdc* job = NULL;
	JobMsdc* subjob = NULL;

	Msjobinfo* msji = NULL;

	MsjobMsdc* mastjob = NULL;

	Mutex::lock(&mJobs, "mJobs", "XchgMsdccmbd", "removeMsjobByJref");
	Mutex::lock(&mMsjobinfos, "mMsjobinfos", "XchgMsdccmbd", "removeMsjobByJref");

	job = (MsjobMsdc*) getJobByJref(jref);

	if (job) {
		job->invalidateWakeups();

		removePresetsByJref(jref);
		removeStmgrByJref(jref);
		removeClstnsByJref(jref);
		removeDcolByJref(jref);

		// update master/slave job info
		auto it = msjobinfos.find(job->ixMsdcVJob);
		if (it != msjobinfos.end()) {
			msji = it->second;

			setMsjobStarted(NULL, job, false);

			if (job->jref == msji->jrefMast) {
				if (!msji->jrefsSlv.empty()) {
					mon.eventGiveupMaster(job->jref);
					job->giveupMaster(NULL, msji);

					mastjob = (MsjobMsdc*) getJobByJref(msji->jrefsSlv.front());
				};

				if (mastjob) {
					// the new master = mastjob
					mon.eventGiveupSlave(mastjob->jref);
					mastjob->giveupSlave(NULL, msji);

					mon.eventGiveupMaster(job->jref);
					job->giveupMaster(NULL, msji);

					msji->jrefsSlv.pop_front();
					msji->jrefMast = mastjob->jref;

					mon.eventBecomeMaster(mastjob->jref);
					mastjob->becomeMaster(NULL, msji);

				} else {
					mon.eventGiveupMaster(job->jref);
					job->giveupMaster(NULL, msji);

					msji->jrefMast = 0;
				};

			} else {
				mon.eventGiveupSlave(job->jref);
				job->giveupSlave(NULL, msji);

				msji->jrefsSlv.remove(job->jref);
			};
		};

		// super-job
		supjob = getJobByJref(job->jrefSup);
		if (supjob) supjob->jrefsSub.erase(jref);

		// sub-jobs
		while (job->jrefsSub.size() > 0) {
			subjob = getJobByJref(*(job->jrefsSub.begin()));
			if (subjob) delete subjob;
		};

		// remove job from list only here otherwise sub-job delete will loop forever
		jobs.erase(jref);

		mon.eventRemoveJob(jref);
	};

	Mutex::unlock(&mMsjobinfos, "mMsjobinfos", "XchgMsdccmbd", "removeMsjobByJref");
	Mutex::unlock(&mJobs, "mJobs", "XchgMsdccmbd", "removeMsjobByJref");

	if (mastjob) triggerCall(NULL, VecMsdcVCall::CALLMSDCMASTSLVCHG, mastjob->jref);
};

void XchgMsdccmbd::transferMsjobMaster(
			DbsMsdc* dbsmsdc
			, MsjobMsdc* fromjob
			, MsjobMsdc* tojob
			, Msjobinfo* msji
		) {
	// requires mJobs and mMsjobinfos locked and tojob at first position in msji->jrefsSlv
	mon.eventGiveupSlave(tojob->jref);
	tojob->giveupSlave(dbsmsdc, msji);

	mon.eventGiveupMaster(fromjob->jref);
	fromjob->giveupMaster(dbsmsdc, msji);

	msji->jrefsSlv.pop_front();

	if (fromjob->prefmast) msji->jrefsSlv.push_front(fromjob->jref);
	else msji->jrefsSlv.push_back(fromjob->jref);

	msji->jrefMast = tojob->jref;

	mon.eventBecomeMaster(tojob->jref);
	tojob->becomeMaster(dbsmsdc, msji);

	mon.eventBecomeSlave(fromjob->jref);
	fromjob->becomeSlave(dbsmsdc, msji);

	triggerCall(dbsmsdc, VecMsdcVCall::CALLMSDCMASTSLVCHG, tojob->jref);
	triggerCall(dbsmsdc, VecMsdcVCall::CALLMSDCMASTSLVCHG, fromjob->jref);
};

void XchgMsdccmbd::offerMsjobMaster(
			DbsMsdc* dbsmsdc
			, const ubigint jref
		) {
	MsjobMsdc* mastjob = NULL;
	MsjobMsdc* slvjob = NULL;

	Msjobinfo* msji = NULL;

	Mutex::lock(&mJobs, "mJobs", "XchgMsdccmbd", "offerMsjobMaster");
	Mutex::lock(&mMsjobinfos, "mMsjobinfos", "XchgMsdccmbd", "offerMsjobMaster");

	mastjob = (MsjobMsdc*) getJobByJref(jref);

	if (mastjob) {
		auto it = msjobinfos.find(mastjob->ixMsdcVJob);
		if (it != msjobinfos.end()) {
			msji = it->second;

			if (!msji->jrefsSlv.empty()) {
				slvjob = (MsjobMsdc*) getJobByJref(msji->jrefsSlv.front());

				if (slvjob) if (slvjob->prefmast) transferMsjobMaster(dbsmsdc, mastjob, slvjob, msji);
			};
		};
	};

	Mutex::unlock(&mMsjobinfos, "mMsjobinfos", "XchgMsdccmbd", "offerMsjobMaster");
	Mutex::unlock(&mJobs, "mJobs", "XchgMsdccmbd", "offerMsjobMaster");
};

bool XchgMsdccmbd::claimMsjobMaster(
			DbsMsdc* dbsmsdc
			, const ubigint jref
		) {
	bool retval = false;

	MsjobMsdc* mastjob = NULL;
	MsjobMsdc* slvjob = NULL;

	Msjobinfo* msji = NULL;

	Mutex::lock(&mJobs, "mJobs", "XchgMsdccmbd", "claimMsjobMaster");
	Mutex::lock(&mMsjobinfos, "mMsjobinfos", "XchgMsdccmbd", "claimMsjobMaster");

	slvjob = (MsjobMsdc*) getJobByJref(jref);

	if (slvjob) {
		auto it = msjobinfos.find(slvjob->ixMsdcVJob);
		if (it != msjobinfos.end()) {
			msji = it->second;

			if (jref != msji->jrefMast) {
				mastjob = (MsjobMsdc*) getJobByJref(msji->jrefMast);

				for (auto it2=msji->jrefsSlv.begin();it2!=msji->jrefsSlv.end();it2++) {
					// put slvjob first
					if (*it2 == jref) {
						*it2 = msji->jrefsSlv.front();
						msji->jrefsSlv.pop_front();
						msji->jrefsSlv.push_front(jref);

						break;
					};
				};

				if (mastjob->handleClaimMaster(dbsmsdc, msji)) transferMsjobMaster(dbsmsdc, mastjob, slvjob, msji);
			};

			retval = (jref == msji->jrefMast);
		};
	};

	Mutex::unlock(&mMsjobinfos, "mMsjobinfos", "XchgMsdccmbd", "claimMsjobMaster");
	Mutex::unlock(&mJobs, "mJobs", "XchgMsdccmbd", "claimMsjobMaster");

	return retval;
};

bool XchgMsdccmbd::getMsjobNotJob(
			const uint ixMsdcVJob
		) {
	bool retval;

	Mutex::lock(&mMsjobinfos, "mMsjobinfos", "XchgMsdccmbd", "getMsjobNotJob");

	retval = (msjobinfos.find(ixMsdcVJob) != msjobinfos.end());

	Mutex::unlock(&mMsjobinfos, "mMsjobinfos", "XchgMsdccmbd", "getMsjobNotJob");

	return retval;
};

bool XchgMsdccmbd::getMsjobMastNotSlv(
			MsjobMsdc* job
		) {
	bool retval = false;

	if (job) {
		Mutex::lock(&mMsjobinfos, "mMsjobinfos", "XchgMsdccmbd", "getMsjobMastNotSlv");

		auto it = msjobinfos.find(job->ixMsdcVJob);
		if (it != msjobinfos.end()) retval = (it->second->jrefMast == job->jref);

		Mutex::unlock(&mMsjobinfos, "mMsjobinfos", "XchgMsdccmbd", "getMsjobMastNotSlv");
	};

	return retval;
};

MsjobMsdc* XchgMsdccmbd::getMsjobMaster(
			MsjobMsdc* job
			, const string& srefMember
		) {
	MsjobMsdc* retval = NULL;

	if (job) {
		Mutex::lock(&mMsjobinfos, "mMsjobinfos", "XchgMsdccmbd", "getMsjobMaster");

		auto it = msjobinfos.find(job->ixMsdcVJob);
		if (it != msjobinfos.end()) retval = (MsjobMsdc*) getJobByJref(it->second->jrefMast);

		Mutex::unlock(&mMsjobinfos, "mMsjobinfos", "XchgMsdccmbd", "getMsjobMaster");

		if (retval) retval->lockAccess(srefMember);
	};

	return retval;
};

void XchgMsdccmbd::setMsjobStarted(
			DbsMsdc* dbsmsdc
			, MsjobMsdc* job
			, const bool srd
		) {
	Msjobinfo* msjobinfo = NULL;
	bool changed = false;

	Mutex::lock(&mJobs, "mJobs", "XchgMsdccmbd", "setMsjobStarted");
	Mutex::lock(&mMsjobinfos, "mMsjobinfos", "XchgMsdccmbd", "setMsjobStarted");

	auto it = msjobinfos.find(job->ixMsdcVJob);

	if (it != msjobinfos.end()) {
		msjobinfo = it->second;

		auto it2 = msjobinfo->jrefsSrd.find(job->jref);

		if (srd) {
			if (it2 == msjobinfo->jrefsSrd.end()) {
				if (msjobinfo->jrefsSrd.empty()) changed = true;
				msjobinfo->jrefsSrd.insert(job->jref);
			};
		} else {
			if (it2 != msjobinfo->jrefsSrd.end()) {
				msjobinfo->jrefsSrd.erase(it2);
				if (msjobinfo->jrefsSrd.empty()) changed = true;
			};
		};
	};

	Mutex::unlock(&mMsjobinfos, "mMsjobinfos", "XchgMsdccmbd", "setMsjobStarted");
	Mutex::unlock(&mJobs, "mJobs", "XchgMsdccmbd", "setMsjobStarted");

	if (changed) triggerBoolvalCall(dbsmsdc, VecMsdcVCall::CALLMSDCMASTSRDCHG, job->jref, srd);
};

void XchgMsdccmbd::setMsjobStage(
			DbsMsdc* dbsmsdc
			, MsjobMsdc* job
			, const uint ixVSge
		) {
	Msjobinfo* msjobinfo = NULL;

	Mutex::lock(&mJobs, "mJobs", "XchgMsdccmbd", "setMsjobStage");
	Mutex::lock(&mMsjobinfos, "mMsjobinfos", "XchgMsdccmbd", "setMsjobStage");

	auto it = msjobinfos.find(job->ixMsdcVJob);

	if (it != msjobinfos.end()) {
		msjobinfo = it->second;

		if (msjobinfo->jrefMast == job->jref) msjobinfo->ixVSge = ixVSge;
		else msjobinfo = NULL;
	};

	Mutex::unlock(&mMsjobinfos, "mMsjobinfos", "XchgMsdccmbd", "setMsjobStage");
	Mutex::unlock(&mJobs, "mJobs", "XchgMsdccmbd", "setMsjobStage");

	if (msjobinfo) triggerIxCall(dbsmsdc, VecMsdcVCall::CALLMSDCMASTSGECHG, job->jref, ixVSge);
};

ubigint XchgMsdccmbd::addWakeup(
			const ubigint jref
			, const string sref
			, const unsigned int deltat
			, const bool weak
		) {
	int res;

	ubigint wref;

	pthread_t timer;

	wref = wrefseq->getNewRef();

	if (deltat == 0) {
		// immediate callback: generate request to be treated by job processor
		ReqMsdc* req = new ReqMsdc(ReqMsdc::VecVBasetype::TIMER);
		req->jref = jref;
		req->wref = wref;
		req->sref = sref;
		req->weak = false;

		addReq(req);

	} else {
		// delayed callback: generate dedicated wait thread
		WakeupMsdc* wakeup = new WakeupMsdc(this, wref, jref, sref, deltat, weak);

		res = pthread_create(&timer, NULL, &runWakeup, (void*) wakeup);
		if (res != 0) cout << "XchgMsdccmbd::addWakeup() error creating timer thread (" << res << ")" << endl;
		res = pthread_detach(timer);
		if (res != 0) cout << "XchgMsdccmbd::addWakeup() error detaching timer thread (" << res << ")" << endl;
	};

	return(wref);
};

void* XchgMsdccmbd::runWakeup(
			void* arg
		) {
	WakeupMsdc* wakeup = (WakeupMsdc*) arg;

	// wait for time specified in microseconds
	timespec deltat;
	deltat.tv_sec = wakeup->deltat / 1000000;
	deltat.tv_nsec = 1000 * (wakeup->deltat%1000000);
#ifdef _WIN32
	usleep(wakeup->deltat);
#else
	nanosleep(&deltat, NULL);
#endif

	// generate request to be treated by job processor
	ReqMsdc* req = new ReqMsdc(ReqMsdc::VecVBasetype::TIMER);
	req->jref = wakeup->jref;
	req->wref = wakeup->wref;
	req->sref = wakeup->sref;
	req->weak = wakeup->weak;

	wakeup->xchg->addReq(req);

	delete wakeup;

	return(NULL);
};

void XchgMsdccmbd::runExtcall(
			void* arg
		) {
	ExtcallMsdc* extcall = (ExtcallMsdc*) arg;

	// generate request to be treated by job processor
	ReqMsdc* req = new ReqMsdc(ReqMsdc::VecVBasetype::EXTCALL);
	req->call = new Call(*(extcall->call));

	extcall->xchg->addReq(req);
};




