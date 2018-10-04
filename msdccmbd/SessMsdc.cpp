/**
  * \file SessMsdc.cpp
  * job handler for job SessMsdc (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Oct 2018
  * \date modified: 4 Oct 2018
  */

#ifdef MSDCCMBD
	#include <Msdccmbd.h>
#else
	#include <Msdcd.h>
#endif

#include "SessMsdc.h"

#include "SessMsdc_blks.cpp"

/******************************************************************************
 class SessMsdc
 ******************************************************************************/

SessMsdc::SessMsdc(
			XchgMsdc* xchg
			, DbsMsdc* dbsmsdc
			, const ubigint jrefSup
			, const ubigint refMsdcMUser
			, const string& ip
		) :
			JobMsdc(xchg, VecMsdcVJob::SESSMSDC, jrefSup)
		{

	jref = xchg->addJob(this);

	crdnav = NULL;

	// IP constructor.cust1 --- INSERT

	vector<ubigint> refs;

	ubigint refSes;

	MsdcMUser* usr = NULL;

	bool adm;

	ListMsdcRMUserMUsergroup urus;
	MsdcRMUserMUsergroup* uru = NULL;

	uint ixMsdcWAccessBase, ixMsdcWAccess;

	// create new session with start time
	time_t rawtime;
	time(&rawtime);

	refSes = dbsmsdc->tblmsdcmsession->insertNewRec(NULL, refMsdcMUser, (uint) rawtime, 0, ip);

	xchg->addRefPreset(VecMsdcVPreset::PREMSDCSESS, jref, refSes);
	xchg->addTxtvalPreset(VecMsdcVPreset::PREMSDCIP, jref, ip);

	// set locale and presetings corresponding to user
	dbsmsdc->tblmsdcmuser->loadRecByRef(refMsdcMUser, &usr);

	ixMsdcVLocale = usr->ixMsdcVLocale;
	adm = (usr->ixMsdcVUserlevel == VecMsdcVUserlevel::ADM);

	xchg->addBoolvalPreset(VecMsdcVPreset::PREMSDCADM, jref, adm);

	xchg->addRefPreset(VecMsdcVPreset::PREMSDCGRP, jref, usr->refMsdcMUsergroup);
	xchg->addRefPreset(VecMsdcVPreset::PREMSDCOWN, jref, refMsdcMUser);

	delete usr;

	// set jrefSess (for access to MsdcQSelect from rst-type panel queries)
	xchg->addRefPreset(VecMsdcVPreset::PREMSDCJREFSESS, jref, jref);

	// fill query in MsdcQSelect with all applicable user groups
	dbsmsdc->tblmsdcqselect->insertNewRec(NULL, jref, 1, 0, 0);

	if (adm) {
		dbsmsdc->loadRefsBySQL("SELECT ref FROM TblMsdcMUsergroup ORDER BY ref ASC", false, refs);

		for (unsigned int i=0;i<refs.size();i++) dbsmsdc->tblmsdcqselect->insertNewRec(NULL, jref, i+2, 0, refs[i]);

	} else {
		dbsmsdc->tblmsdcrmusermusergroup->loadRstByUsr(refMsdcMUser, false, urus);

		for (unsigned int i=0;i<urus.nodes.size();i++) {
			uru = urus.nodes[i];

			usgaccs[uru->refMsdcMUsergroup] = uru->ixMsdcVUserlevel;
			dbsmsdc->tblmsdcqselect->insertNewRec(NULL, jref, i+2, 0, uru->refMsdcMUsergroup);
		};
	};

	// determine access rights for each card
	ixMsdcWAccessBase = 0;
	getIxCrdacc(dbsmsdc, 0, adm, urus, refMsdcMUser, ixMsdcWAccessBase);

	ixMsdcWAccess = ixMsdcWAccessBase; if (!adm) getIxCrdacc(dbsmsdc, VecMsdcVCard::CRDMSDCUSG, adm, urus, refMsdcMUser, ixMsdcWAccess); xchg->addIxPreset(VecMsdcVPreset::PREMSDCIXCRDACCUSG, jref, ixMsdcWAccess);
	ixMsdcWAccess = ixMsdcWAccessBase; if (!adm) getIxCrdacc(dbsmsdc, VecMsdcVCard::CRDMSDCUSR, adm, urus, refMsdcMUser, ixMsdcWAccess); xchg->addIxPreset(VecMsdcVPreset::PREMSDCIXCRDACCUSR, jref, ixMsdcWAccess);
	ixMsdcWAccess = ixMsdcWAccessBase; if (!adm) getIxCrdacc(dbsmsdc, VecMsdcVCard::CRDMSDCPRS, adm, urus, refMsdcMUser, ixMsdcWAccess); xchg->addIxPreset(VecMsdcVPreset::PREMSDCIXCRDACCPRS, jref, ixMsdcWAccess);
	ixMsdcWAccess = ixMsdcWAccessBase; if (!adm) getIxCrdacc(dbsmsdc, VecMsdcVCard::CRDMSDCSCF, adm, urus, refMsdcMUser, ixMsdcWAccess); xchg->addIxPreset(VecMsdcVPreset::PREMSDCIXCRDACCSCF, jref, ixMsdcWAccess);
	ixMsdcWAccess = ixMsdcWAccessBase; if (!adm) getIxCrdacc(dbsmsdc, VecMsdcVCard::CRDMSDCLIV, adm, urus, refMsdcMUser, ixMsdcWAccess); xchg->addIxPreset(VecMsdcVPreset::PREMSDCIXCRDACCLIV, jref, ixMsdcWAccess);
	ixMsdcWAccess = ixMsdcWAccessBase; if (!adm) getIxCrdacc(dbsmsdc, VecMsdcVCard::CRDMSDCPRD, adm, urus, refMsdcMUser, ixMsdcWAccess); xchg->addIxPreset(VecMsdcVPreset::PREMSDCIXCRDACCPRD, jref, ixMsdcWAccess);
	ixMsdcWAccess = ixMsdcWAccessBase; if (!adm) getIxCrdacc(dbsmsdc, VecMsdcVCard::CRDMSDCDAT, adm, urus, refMsdcMUser, ixMsdcWAccess); xchg->addIxPreset(VecMsdcVPreset::PREMSDCIXCRDACCDAT, jref, ixMsdcWAccess);
	ixMsdcWAccess = ixMsdcWAccessBase; if (!adm) getIxCrdacc(dbsmsdc, VecMsdcVCard::CRDMSDCFIL, adm, urus, refMsdcMUser, ixMsdcWAccess); xchg->addIxPreset(VecMsdcVPreset::PREMSDCIXCRDACCFIL, jref, ixMsdcWAccess);

	crdnav = new CrdMsdcNav(xchg, dbsmsdc, jref, ixMsdcVLocale);

	// IP constructor.cust2 --- INSERT

	statshr.jrefCrdnav = crdnav->jref;

	xchg->addClstn(VecMsdcVCall::CALLMSDCCRDACTIVE, jref, Clstn::VecVJobmask::TREE, 0, Arg(), Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecMsdcVCall::CALLMSDCCRDCLOSE, jref, Clstn::VecVJobmask::TREE, 0, Arg(), Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecMsdcVCall::CALLMSDCCRDOPEN, jref, Clstn::VecVJobmask::TREE, 0, Arg(), Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecMsdcVCall::CALLMSDCLOG, jref, Clstn::VecVJobmask::TREE, 0, Arg(), Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecMsdcVCall::CALLMSDCRECACCESS, jref, Clstn::VecVJobmask::TREE, 0, Arg(), Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecMsdcVCall::CALLMSDCREFPRESET, jref, Clstn::VecVJobmask::TREE, 0, Arg(), Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
	
};

SessMsdc::~SessMsdc() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void SessMsdc::term(
			DbsMsdc* dbsmsdc
		) {
	MsdcMSession* ses = NULL;

	time_t rawtime;

	// update session with stop time
	time(&rawtime);

	dbsmsdc->tblmsdcmsession->loadRecByRef(xchg->getRefPreset(VecMsdcVPreset::PREMSDCSESS, jref), &ses);
	ses->stop = rawtime;
	dbsmsdc->tblmsdcmsession->updateRec(ses);

	delete ses;
};

uint SessMsdc::checkCrdActive(
			const uint ixMsdcVCard
		) {
	if (ixMsdcVCard == VecMsdcVCard::CRDMSDCDAT) return evalCrddatActive();
	else if (ixMsdcVCard == VecMsdcVCard::CRDMSDCFIL) return evalCrdfilActive();

	return 0;
};

uint SessMsdc::evalCrddatActive() {
	// pre.refPrd()

	vector<uint> args;

	args.push_back((xchg->getRefPreset(VecMsdcVPreset::PREMSDCREFPRD, jref)) ? VecMsdcVPreset::PREMSDCREFPRD : 0);

	return(args.back());
};

uint SessMsdc::evalCrdfilActive() {
	// pre.refDat() > pre.refPrd() > pre.void()

	vector<uint> args;
	uint a, b;

	args.push_back((xchg->getRefPreset(VecMsdcVPreset::PREMSDCREFDAT, jref)) ? VecMsdcVPreset::PREMSDCREFDAT : 0);
	args.push_back((xchg->getRefPreset(VecMsdcVPreset::PREMSDCREFPRD, jref)) ? VecMsdcVPreset::PREMSDCREFPRD : 0);
	args.push_back([](){uint preVoid = VecMsdcVPreset::VOID; return preVoid;}());
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	if (a != 0) args.push_back(a);
	else args.push_back(b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	if (a != 0) args.push_back(a);
	else args.push_back(b);

	return(args.back());
};

uint SessMsdc::checkCrdaccess(
			const uint ixMsdcVCard
		) {
	if (ixMsdcVCard == VecMsdcVCard::CRDMSDCUSG) return xchg->getIxPreset(VecMsdcVPreset::PREMSDCIXCRDACCUSG, jref);
	else if (ixMsdcVCard == VecMsdcVCard::CRDMSDCUSR) return xchg->getIxPreset(VecMsdcVPreset::PREMSDCIXCRDACCUSR, jref);
	else if (ixMsdcVCard == VecMsdcVCard::CRDMSDCPRS) return xchg->getIxPreset(VecMsdcVPreset::PREMSDCIXCRDACCPRS, jref);
	else if (ixMsdcVCard == VecMsdcVCard::CRDMSDCSCF) return xchg->getIxPreset(VecMsdcVPreset::PREMSDCIXCRDACCSCF, jref);
	else if (ixMsdcVCard == VecMsdcVCard::CRDMSDCLIV) return xchg->getIxPreset(VecMsdcVPreset::PREMSDCIXCRDACCLIV, jref);
	else if (ixMsdcVCard == VecMsdcVCard::CRDMSDCPRD) return xchg->getIxPreset(VecMsdcVPreset::PREMSDCIXCRDACCPRD, jref);
	else if (ixMsdcVCard == VecMsdcVCard::CRDMSDCDAT) return xchg->getIxPreset(VecMsdcVPreset::PREMSDCIXCRDACCDAT, jref);
	else if (ixMsdcVCard == VecMsdcVCard::CRDMSDCFIL) return xchg->getIxPreset(VecMsdcVPreset::PREMSDCIXCRDACCFIL, jref);

	return 0;
};

void SessMsdc::getIxCrdacc(
			DbsMsdc* dbsmsdc
			, const uint ixMsdcVCard
			, const bool adm
			, ListMsdcRMUserMUsergroup& urus
			, const ubigint refMsdcMUser
			, uint& ixMsdcWAccess
		) {
	MsdcRMUserMUsergroup* uru = NULL;
	MsdcAMUsergroupAccess* usgAacc = NULL;
	MsdcAMUserAccess* usrAacc = NULL;

	uint ixCrdacc = 0;

	bool first = true;

	if (adm) {
		ixMsdcWAccess = VecMsdcWAccess::EDIT + VecMsdcWAccess::EXEC + VecMsdcWAccess::VIEW;
		return;
	};

	// check for access rights override by any of the applicable user groups
	for (unsigned int i=0;i<urus.nodes.size();i++) {
		uru = urus.nodes[i];

		if (dbsmsdc->tblmsdcamusergroupaccess->loadRecBySQL("SELECT * FROM TblMsdcAMUsergroupAccess WHERE refMsdcMUsergroup = " + to_string(uru->refMsdcMUsergroup) + " AND x1IxMsdcVFeatgroup = " + to_string(VecMsdcVFeatgroup::VECMSDCVCARD) + " AND x2FeaSrefUix = '" + VecMsdcVCard::getSref(ixMsdcVCard) + "'", &usgAacc)) {
			ixCrdacc |= usgAacc->ixMsdcWAccess;
			first = false;

			delete usgAacc;
			if (ixCrdacc == (VecMsdcWAccess::EDIT + VecMsdcWAccess::EXEC + VecMsdcWAccess::VIEW)) break;
		};
	};

	if (!first) ixMsdcWAccess = ixCrdacc;

	// user access rights override user group access rights
	if (dbsmsdc->tblmsdcamuseraccess->loadRecBySQL("SELECT * FROM TblMsdcAMUserAccess WHERE refMsdcMUser = " + to_string(refMsdcMUser) + " AND x1IxMsdcVFeatgroup = " + to_string(VecMsdcVFeatgroup::VECMSDCVCARD) + " AND x2FeaSrefUix = '" + VecMsdcVCard::getSref(ixMsdcVCard) + "'", &usrAacc)) {
		ixMsdcWAccess = usrAacc->ixMsdcWAccess;
		delete usrAacc;
	};

};

uint SessMsdc::checkRecaccess(
			DbsMsdc* dbsmsdc
			, const uint ixMsdcVCard
			, const ubigint ref
		) {
	uint retval = VecMsdcVRecaccess::NONE;

	ubigint grp;
	ubigint own;

	map<ubigint,uint>::iterator it;

	ubigint refMsdcMUser;
	uint ixMsdcVMaintable;

	MsdcAccRMUserUniversal* ausrRunv = NULL;
	MsdcRMUsergroupUniversal* usgRunv = NULL;

	ixMsdcVMaintable = crdToMtb(ixMsdcVCard);

	if (ixMsdcVMaintable == VecMsdcVMaintable::VOID) {
		retval = VecMsdcVRecaccess::FULL;

	} else if (hasGrpown(ixMsdcVMaintable) && (ref != 0)) {
		// find record's group and owner
		dbsmsdc->loadRefBySQL("SELECT grp FROM " + VecMsdcVMaintable::getSref(ixMsdcVMaintable) + " WHERE ref = " + to_string(ref), grp);
		dbsmsdc->loadRefBySQL("SELECT own FROM " + VecMsdcVMaintable::getSref(ixMsdcVMaintable) + " WHERE ref = " + to_string(ref), own);

		// administrators can edit any record
		if (xchg->getBoolvalPreset(VecMsdcVPreset::PREMSDCADM, jref)) retval = VecMsdcVRecaccess::FULL;

		// all non-administrators can view user group non-specific records but not edit them
		if (retval == VecMsdcVRecaccess::NONE) {
			if (grp == 0) retval = VecMsdcVRecaccess::VIEW;
		};

		if (retval == VecMsdcVRecaccess::NONE) {
			refMsdcMUser = xchg->getRefPreset(VecMsdcVPreset::PREMSDCOWN, jref);

			// a record's owner has full rights on his records
			if (refMsdcMUser == own) retval = VecMsdcVRecaccess::FULL;

			if (retval == VecMsdcVRecaccess::NONE) {
				it = usgaccs.find(grp);
				if (it != usgaccs.end()) {
					if (it->second == VecMsdcVUserlevel::GADM) {
						// group admins have full access to all of the group's records
						retval = VecMsdcVRecaccess::FULL;
					} else {
						// other group members have view access only
						retval = VecMsdcVRecaccess::VIEW;
					};
				};
			};

			if (retval != VecMsdcVRecaccess::FULL) {
				// individual record access right
				if (dbsmsdc->tblmsdcaccrmuseruniversal->loadRecByUsrMtbUnv(refMsdcMUser, ixMsdcVMaintable, ref, &ausrRunv)) {
					retval = ausrRunv->ixMsdcVRecaccess;
					delete ausrRunv;
				};
			};

			if (retval != VecMsdcVRecaccess::FULL) {
				// individual record access right due to group membership
				for (it = usgaccs.begin() ; it != usgaccs.end() ; it++) {

					if (dbsmsdc->tblmsdcrmusergroupuniversal->loadRecByUsgMtbUnv(it->second, ixMsdcVMaintable, ref, &usgRunv)) {
						if (retval == VecMsdcVRecaccess::VIEW) {
							if (usgRunv->ixMsdcVRecaccess == VecMsdcVRecaccess::FULL) retval = VecMsdcVRecaccess::FULL;
						} else {
							retval = usgRunv->ixMsdcVRecaccess;
						};

						delete usgRunv;
					};

					if (retval == VecMsdcVRecaccess::FULL) break;
				};
			};
		};

	} else {
		if (xchg->getBoolvalPreset(VecMsdcVPreset::PREMSDCADM, jref)) retval = VecMsdcVRecaccess::FULL;
		else retval = VecMsdcVRecaccess::VIEW;
	};

	return retval;
};

void SessMsdc::logRecaccess(
			DbsMsdc* dbsmsdc
			, const uint ixMsdcVPreset
			, const ubigint preUref
			, const uint ixMsdcVCard
			, const ubigint unvUref
		) {
	ubigint refMsdcMUser;
	uint unvIxMsdcVMaintable;
	uint preIxMsdcVMaintable;

	MsdcHistRMUserUniversal* husrRunv = NULL;

	refMsdcMUser = xchg->getRefPreset(VecMsdcVPreset::PREMSDCOWN, jref);
	unvIxMsdcVMaintable = crdToMtb(ixMsdcVCard);
	preIxMsdcVMaintable = preToMtb(ixMsdcVPreset);

	if (!dbsmsdc->tblmsdchistrmuseruniversal->loadRecBySQL("SELECT * FROM TblMsdcHistRMUserUniversal WHERE refMsdcMUser = " + to_string(refMsdcMUser)
				+ " AND unvIxMsdcVMaintable = " + to_string(unvIxMsdcVMaintable) + " AND unvUref = " + to_string(unvUref) + " AND ixMsdcVCard = " + to_string(ixMsdcVCard), &husrRunv)) {
		husrRunv = new MsdcHistRMUserUniversal(0, refMsdcMUser, unvIxMsdcVMaintable, unvUref, ixMsdcVCard, ixMsdcVPreset, preIxMsdcVMaintable, preUref, 0);
	};

	husrRunv->start = time(NULL);

	if (husrRunv->ref == 0) dbsmsdc->tblmsdchistrmuseruniversal->insertRec(husrRunv);
	else dbsmsdc->tblmsdchistrmuseruniversal->updateRec(husrRunv);

	xchg->triggerIxRefCall(dbsmsdc, VecMsdcVCall::CALLMSDCHUSRRUNVMOD_CRDUSREQ, jref, ixMsdcVCard, refMsdcMUser);

	delete husrRunv;
};

uint SessMsdc::crdToMtb(
			const uint ixMsdcVCard
		) {
	if (ixMsdcVCard == VecMsdcVCard::CRDMSDCUSG) return VecMsdcVMaintable::TBLMSDCMUSERGROUP;
	else if (ixMsdcVCard == VecMsdcVCard::CRDMSDCUSR) return VecMsdcVMaintable::TBLMSDCMUSER;
	else if (ixMsdcVCard == VecMsdcVCard::CRDMSDCPRS) return VecMsdcVMaintable::TBLMSDCMPERSON;
	else if (ixMsdcVCard == VecMsdcVCard::CRDMSDCPRD) return VecMsdcVMaintable::TBLMSDCMPERIOD;
	else if (ixMsdcVCard == VecMsdcVCard::CRDMSDCDAT) return VecMsdcVMaintable::TBLMSDCMDATA;
	else if (ixMsdcVCard == VecMsdcVCard::CRDMSDCFIL) return VecMsdcVMaintable::TBLMSDCMFILE;

	return VecMsdcVMaintable::VOID;
};

uint SessMsdc::preToMtb(
			const uint ixMsdcVPreset
		) {
	if (ixMsdcVPreset == VecMsdcVPreset::PREMSDCREFDAT) return VecMsdcVMaintable::TBLMSDCMDATA;
	else if (ixMsdcVPreset == VecMsdcVPreset::PREMSDCREFFIL) return VecMsdcVMaintable::TBLMSDCMFILE;
	else if (ixMsdcVPreset == VecMsdcVPreset::PREMSDCREFPRD) return VecMsdcVMaintable::TBLMSDCMPERIOD;
	else if (ixMsdcVPreset == VecMsdcVPreset::PREMSDCREFPRS) return VecMsdcVMaintable::TBLMSDCMPERSON;
	else if (ixMsdcVPreset == VecMsdcVPreset::PREMSDCREFSES) return VecMsdcVMaintable::TBLMSDCMSESSION;
	else if (ixMsdcVPreset == VecMsdcVPreset::PREMSDCREFUSG) return VecMsdcVMaintable::TBLMSDCMUSERGROUP;
	else if (ixMsdcVPreset == VecMsdcVPreset::PREMSDCREFUSR) return VecMsdcVMaintable::TBLMSDCMUSER;

	return VecMsdcVMaintable::VOID;
};

bool SessMsdc::hasActive(
			const uint ixMsdcVCard
		) {
	return((ixMsdcVCard == VecMsdcVCard::CRDMSDCDAT) || (ixMsdcVCard == VecMsdcVCard::CRDMSDCFIL));
};

bool SessMsdc::hasGrpown(
			const uint ixMsdcVMaintable
		) {
	return((ixMsdcVMaintable == VecMsdcVMaintable::TBLMSDCMFILE) || (ixMsdcVMaintable == VecMsdcVMaintable::TBLMSDCMPERSON) || (ixMsdcVMaintable == VecMsdcVMaintable::TBLMSDCMUSER) || (ixMsdcVMaintable == VecMsdcVMaintable::TBLMSDCMUSERGROUP));
};

void SessMsdc::handleRequest(
			DbsMsdc* dbsmsdc
			, ReqMsdc* req
		) {
	if (req->ixVBasetype == ReqMsdc::VecVBasetype::CMD) {
		reqCmd = req;

		if (req->cmd == "cmdset") {
			cout << "\tcreateCrddat" << endl;
			cout << "\tcreateCrdfil" << endl;
			cout << "\tcreateCrdliv" << endl;
			cout << "\tcreateCrdprd" << endl;
			cout << "\tcreateCrdprs" << endl;
			cout << "\tcreateCrdscf" << endl;
			cout << "\tcreateCrdusg" << endl;
			cout << "\tcreateCrdusr" << endl;
			cout << "\teraseCrddat" << endl;
			cout << "\teraseCrdfil" << endl;
			cout << "\teraseCrdliv" << endl;
			cout << "\teraseCrdprd" << endl;
			cout << "\teraseCrdprs" << endl;
			cout << "\teraseCrdscf" << endl;
			cout << "\teraseCrdusg" << endl;
			cout << "\teraseCrdusr" << endl;
		} else if (req->cmd == "createCrddat") {
			req->retain = handleCreateCrddat(dbsmsdc);

		} else if (req->cmd == "createCrdfil") {
			req->retain = handleCreateCrdfil(dbsmsdc);

		} else if (req->cmd == "createCrdliv") {
			req->retain = handleCreateCrdliv(dbsmsdc);

		} else if (req->cmd == "createCrdprd") {
			req->retain = handleCreateCrdprd(dbsmsdc);

		} else if (req->cmd == "createCrdprs") {
			req->retain = handleCreateCrdprs(dbsmsdc);

		} else if (req->cmd == "createCrdscf") {
			req->retain = handleCreateCrdscf(dbsmsdc);

		} else if (req->cmd == "createCrdusg") {
			req->retain = handleCreateCrdusg(dbsmsdc);

		} else if (req->cmd == "createCrdusr") {
			req->retain = handleCreateCrdusr(dbsmsdc);

		} else if (req->cmd == "eraseCrddat") {
			req->retain = handleEraseCrddat(dbsmsdc);

		} else if (req->cmd == "eraseCrdfil") {
			req->retain = handleEraseCrdfil(dbsmsdc);

		} else if (req->cmd == "eraseCrdliv") {
			req->retain = handleEraseCrdliv(dbsmsdc);

		} else if (req->cmd == "eraseCrdprd") {
			req->retain = handleEraseCrdprd(dbsmsdc);

		} else if (req->cmd == "eraseCrdprs") {
			req->retain = handleEraseCrdprs(dbsmsdc);

		} else if (req->cmd == "eraseCrdscf") {
			req->retain = handleEraseCrdscf(dbsmsdc);

		} else if (req->cmd == "eraseCrdusg") {
			req->retain = handleEraseCrdusg(dbsmsdc);

		} else if (req->cmd == "eraseCrdusr") {
			req->retain = handleEraseCrdusr(dbsmsdc);

		} else {
			cout << "\tinvalid command!" << endl;
		};

		if (!req->retain) reqCmd = NULL;

	} else if (req->ixVBasetype == ReqMsdc::VecVBasetype::REGULAR) {
		if (req->dpchapp->ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCINIT) {
			handleDpchAppMsdcInit(dbsmsdc, (DpchAppMsdcInit*) (req->dpchapp), &(req->dpcheng));

		};
	};
};

bool SessMsdc::handleCreateCrddat(
			DbsMsdc* dbsmsdc
		) {
	bool retval = false;
	CrdMsdcDat* crddat = NULL;

	uint ixMsdcVPreset = evalCrddatActive();

	if (ixMsdcVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		crddat = new CrdMsdcDat(xchg, dbsmsdc, jref, ixMsdcVLocale, 0, ixMsdcVPreset, xchg->getRefPreset(ixMsdcVPreset, jref));
		crddats.push_back(crddat);
		cout << "\tjob reference: " << crddat->jref << endl;
		xchg->jrefCmd = crddat->jref;
	};

	return false;
	return retval;
};

bool SessMsdc::handleCreateCrdfil(
			DbsMsdc* dbsmsdc
		) {
	bool retval = false;
	CrdMsdcFil* crdfil = NULL;

	uint ixMsdcVPreset = evalCrdfilActive();

	if (ixMsdcVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		crdfil = new CrdMsdcFil(xchg, dbsmsdc, jref, ixMsdcVLocale, 0, ixMsdcVPreset, xchg->getRefPreset(ixMsdcVPreset, jref));
		crdfils.push_back(crdfil);
		cout << "\tjob reference: " << crdfil->jref << endl;
		xchg->jrefCmd = crdfil->jref;
	};

	return false;
	return retval;
};

bool SessMsdc::handleCreateCrdliv(
			DbsMsdc* dbsmsdc
		) {
	bool retval = false;
	CrdMsdcLiv* crdliv = NULL;

	crdliv = new CrdMsdcLiv(xchg, dbsmsdc, jref, ixMsdcVLocale);
	crdlivs.push_back(crdliv);
	cout << "\tjob reference: " << crdliv->jref << endl;
	xchg->jrefCmd = crdliv->jref;

	return false;
	return retval;
};

bool SessMsdc::handleCreateCrdprd(
			DbsMsdc* dbsmsdc
		) {
	bool retval = false;
	CrdMsdcPrd* crdprd = NULL;

	crdprd = new CrdMsdcPrd(xchg, dbsmsdc, jref, ixMsdcVLocale, 0);
	crdprds.push_back(crdprd);
	cout << "\tjob reference: " << crdprd->jref << endl;
	xchg->jrefCmd = crdprd->jref;

	return false;
	return retval;
};

bool SessMsdc::handleCreateCrdprs(
			DbsMsdc* dbsmsdc
		) {
	bool retval = false;
	CrdMsdcPrs* crdprs = NULL;

	crdprs = new CrdMsdcPrs(xchg, dbsmsdc, jref, ixMsdcVLocale, 0);
	crdprss.push_back(crdprs);
	cout << "\tjob reference: " << crdprs->jref << endl;
	xchg->jrefCmd = crdprs->jref;

	return false;
	return retval;
};

bool SessMsdc::handleCreateCrdscf(
			DbsMsdc* dbsmsdc
		) {
	bool retval = false;
	CrdMsdcScf* crdscf = NULL;

	crdscf = new CrdMsdcScf(xchg, dbsmsdc, jref, ixMsdcVLocale);
	crdscfs.push_back(crdscf);
	cout << "\tjob reference: " << crdscf->jref << endl;
	xchg->jrefCmd = crdscf->jref;

	return false;
	return retval;
};

bool SessMsdc::handleCreateCrdusg(
			DbsMsdc* dbsmsdc
		) {
	bool retval = false;
	CrdMsdcUsg* crdusg = NULL;

	crdusg = new CrdMsdcUsg(xchg, dbsmsdc, jref, ixMsdcVLocale, 0);
	crdusgs.push_back(crdusg);
	cout << "\tjob reference: " << crdusg->jref << endl;
	xchg->jrefCmd = crdusg->jref;

	return false;
	return retval;
};

bool SessMsdc::handleCreateCrdusr(
			DbsMsdc* dbsmsdc
		) {
	bool retval = false;
	CrdMsdcUsr* crdusr = NULL;

	crdusr = new CrdMsdcUsr(xchg, dbsmsdc, jref, ixMsdcVLocale, 0);
	crdusrs.push_back(crdusr);
	cout << "\tjob reference: " << crdusr->jref << endl;
	xchg->jrefCmd = crdusr->jref;

	return false;
	return retval;
};

bool SessMsdc::handleEraseCrddat(
			DbsMsdc* dbsmsdc
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdMsdcDat* crddat = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it=crddats.begin();it!=crddats.end();) {
		crddat = *it;
		if (crddat->jref == iinput) {
			it = crddats.erase(it);
			delete crddat;
			break;
		} else it++;
	};

	return retval;
};

bool SessMsdc::handleEraseCrdfil(
			DbsMsdc* dbsmsdc
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdMsdcFil* crdfil = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it=crdfils.begin();it!=crdfils.end();) {
		crdfil = *it;
		if (crdfil->jref == iinput) {
			it = crdfils.erase(it);
			delete crdfil;
			break;
		} else it++;
	};

	return retval;
};

bool SessMsdc::handleEraseCrdliv(
			DbsMsdc* dbsmsdc
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdMsdcLiv* crdliv = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it=crdlivs.begin();it!=crdlivs.end();) {
		crdliv = *it;
		if (crdliv->jref == iinput) {
			it = crdlivs.erase(it);
			delete crdliv;
			break;
		} else it++;
	};

	return retval;
};

bool SessMsdc::handleEraseCrdprd(
			DbsMsdc* dbsmsdc
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdMsdcPrd* crdprd = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it=crdprds.begin();it!=crdprds.end();) {
		crdprd = *it;
		if (crdprd->jref == iinput) {
			it = crdprds.erase(it);
			delete crdprd;
			break;
		} else it++;
	};

	return retval;
};

bool SessMsdc::handleEraseCrdprs(
			DbsMsdc* dbsmsdc
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdMsdcPrs* crdprs = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it=crdprss.begin();it!=crdprss.end();) {
		crdprs = *it;
		if (crdprs->jref == iinput) {
			it = crdprss.erase(it);
			delete crdprs;
			break;
		} else it++;
	};

	return retval;
};

bool SessMsdc::handleEraseCrdscf(
			DbsMsdc* dbsmsdc
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdMsdcScf* crdscf = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it=crdscfs.begin();it!=crdscfs.end();) {
		crdscf = *it;
		if (crdscf->jref == iinput) {
			it = crdscfs.erase(it);
			delete crdscf;
			break;
		} else it++;
	};

	return retval;
};

bool SessMsdc::handleEraseCrdusg(
			DbsMsdc* dbsmsdc
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdMsdcUsg* crdusg = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it=crdusgs.begin();it!=crdusgs.end();) {
		crdusg = *it;
		if (crdusg->jref == iinput) {
			it = crdusgs.erase(it);
			delete crdusg;
			break;
		} else it++;
	};

	return retval;
};

bool SessMsdc::handleEraseCrdusr(
			DbsMsdc* dbsmsdc
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdMsdcUsr* crdusr = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it=crdusrs.begin();it!=crdusrs.end();) {
		crdusr = *it;
		if (crdusr->jref == iinput) {
			it = crdusrs.erase(it);
			delete crdusr;
			break;
		} else it++;
	};

	return retval;
};

void SessMsdc::handleDpchAppMsdcInit(
			DbsMsdc* dbsmsdc
			, DpchAppMsdcInit* dpchappmsdcinit
			, DpchEngMsdc** dpcheng
		) {
	Feed feedFEnsSec("FeedFEnsSec");

	// resume session
	xchg->removePreset(VecMsdcVPreset::PREMSDCSUSPSESS, jref);

	for (auto it=crdusgs.begin();it!=crdusgs.end();it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble((*it)->jref), "CrdMsdcUsg");
	for (auto it=crdusrs.begin();it!=crdusrs.end();it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble((*it)->jref), "CrdMsdcUsr");
	for (auto it=crdprss.begin();it!=crdprss.end();it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble((*it)->jref), "CrdMsdcPrs");
	for (auto it=crdscfs.begin();it!=crdscfs.end();it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble((*it)->jref), "CrdMsdcScf");
	for (auto it=crdlivs.begin();it!=crdlivs.end();it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble((*it)->jref), "CrdMsdcLiv");
	for (auto it=crdprds.begin();it!=crdprds.end();it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble((*it)->jref), "CrdMsdcPrd");
	for (auto it=crddats.begin();it!=crddats.end();it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble((*it)->jref), "CrdMsdcDat");
	for (auto it=crdfils.begin();it!=crdfils.end();it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble((*it)->jref), "CrdMsdcFil");

	*dpcheng = new DpchEngData(jref, &feedFEnsSec, &statshr, {DpchEngData::ALL});
};

void SessMsdc::handleCall(
			DbsMsdc* dbsmsdc
			, Call* call
		) {
	if (call->ixVCall == VecMsdcVCall::CALLMSDCCRDACTIVE) {
		call->abort = handleCallMsdcCrdActive(dbsmsdc, call->jref, call->argInv.ix, call->argRet.ix);
	} else if (call->ixVCall == VecMsdcVCall::CALLMSDCCRDCLOSE) {
		call->abort = handleCallMsdcCrdClose(dbsmsdc, call->jref, call->argInv.ix);
	} else if (call->ixVCall == VecMsdcVCall::CALLMSDCCRDOPEN) {
		call->abort = handleCallMsdcCrdOpen(dbsmsdc, call->jref, call->argInv.ix, call->argInv.ref, call->argInv.sref, call->argInv.intval, call->argRet.ref);
	} else if (call->ixVCall == VecMsdcVCall::CALLMSDCLOG) {
		call->abort = handleCallMsdcLog(dbsmsdc, call->jref, call->argInv.ix, call->argInv.ref, call->argInv.sref, call->argInv.intval);
	} else if (call->ixVCall == VecMsdcVCall::CALLMSDCRECACCESS) {
		call->abort = handleCallMsdcRecaccess(dbsmsdc, call->jref, call->argInv.ix, call->argInv.ref, call->argRet.ix);
	} else if (call->ixVCall == VecMsdcVCall::CALLMSDCREFPRESET) {
		call->abort = handleCallMsdcRefPreSet(dbsmsdc, call->jref, call->argInv.ix, call->argInv.ref);
	};
};

bool SessMsdc::handleCallMsdcCrdActive(
			DbsMsdc* dbsmsdc
			, const ubigint jrefTrig
			, const uint ixInv
			, uint& ixRet
		) {
	bool retval = false;
	ixRet = checkCrdActive(ixInv);
	return retval;
};

bool SessMsdc::handleCallMsdcCrdClose(
			DbsMsdc* dbsmsdc
			, const ubigint jrefTrig
			, const uint ixInv
		) {
	bool retval = false;
	// delete only if card is not part of a suspended session
	if (xchg->getBoolvalPreset(VecMsdcVPreset::PREMSDCSUSPSESS, jrefTrig)) return retval;

	ubigint jrefNotif = xchg->getRefPreset(VecMsdcVPreset::PREMSDCJREFNOTIFY, jref);
	if (jrefNotif == jrefTrig) xchg->removePreset(VecMsdcVPreset::PREMSDCJREFNOTIFY, jref);

	if (ixInv == VecMsdcVCard::CRDMSDCNAV) {
		if (crdnav) {
			delete crdnav;
			crdnav = NULL;
		};

	} else if (ixInv == VecMsdcVCard::CRDMSDCUSG) {
		CrdMsdcUsg* crdusg = NULL;

		for (auto it=crdusgs.begin();it!=crdusgs.end();) {
			crdusg = *it;
			if (crdusg->jref == jrefTrig) {
				it = crdusgs.erase(it);
				delete crdusg;
				break;
			} else it++;
		};
	} else if (ixInv == VecMsdcVCard::CRDMSDCUSR) {
		CrdMsdcUsr* crdusr = NULL;

		for (auto it=crdusrs.begin();it!=crdusrs.end();) {
			crdusr = *it;
			if (crdusr->jref == jrefTrig) {
				it = crdusrs.erase(it);
				delete crdusr;
				break;
			} else it++;
		};
	} else if (ixInv == VecMsdcVCard::CRDMSDCPRS) {
		CrdMsdcPrs* crdprs = NULL;

		for (auto it=crdprss.begin();it!=crdprss.end();) {
			crdprs = *it;
			if (crdprs->jref == jrefTrig) {
				it = crdprss.erase(it);
				delete crdprs;
				break;
			} else it++;
		};
	} else if (ixInv == VecMsdcVCard::CRDMSDCSCF) {
		CrdMsdcScf* crdscf = NULL;

		for (auto it=crdscfs.begin();it!=crdscfs.end();) {
			crdscf = *it;
			if (crdscf->jref == jrefTrig) {
				it = crdscfs.erase(it);
				delete crdscf;
				break;
			} else it++;
		};
	} else if (ixInv == VecMsdcVCard::CRDMSDCLIV) {
		CrdMsdcLiv* crdliv = NULL;

		for (auto it=crdlivs.begin();it!=crdlivs.end();) {
			crdliv = *it;
			if (crdliv->jref == jrefTrig) {
				it = crdlivs.erase(it);
				delete crdliv;
				break;
			} else it++;
		};
	} else if (ixInv == VecMsdcVCard::CRDMSDCPRD) {
		CrdMsdcPrd* crdprd = NULL;

		for (auto it=crdprds.begin();it!=crdprds.end();) {
			crdprd = *it;
			if (crdprd->jref == jrefTrig) {
				it = crdprds.erase(it);
				delete crdprd;
				break;
			} else it++;
		};
	} else if (ixInv == VecMsdcVCard::CRDMSDCDAT) {
		CrdMsdcDat* crddat = NULL;

		for (auto it=crddats.begin();it!=crddats.end();) {
			crddat = *it;
			if (crddat->jref == jrefTrig) {
				it = crddats.erase(it);
				delete crddat;
				break;
			} else it++;
		};
	} else if (ixInv == VecMsdcVCard::CRDMSDCFIL) {
		CrdMsdcFil* crdfil = NULL;

		for (auto it=crdfils.begin();it!=crdfils.end();) {
			crdfil = *it;
			if (crdfil->jref == jrefTrig) {
				it = crdfils.erase(it);
				delete crdfil;
				break;
			} else it++;
		};
	};
	return retval;
};

bool SessMsdc::handleCallMsdcCrdOpen(
			DbsMsdc* dbsmsdc
			, const ubigint jrefTrig
			, const uint ixInv
			, const ubigint refInv
			, const string& srefInv
			, const int intvalInv
			, ubigint& refRet
		) {
	bool retval = false;
	bool denied = false;

	uint ixMsdcVCard = VecMsdcVCard::getIx(srefInv);

	ubigint ref = (ubigint) intvalInv;
	if (intvalInv == -1) {
		ref = 0;
		ref--;
	};

	uint ixMsdcVPreset;
	ubigint preUref = 0;

	uint ixMsdcWAccess;
	uint ixMsdcVRecaccess;

	if (hasActive(ixMsdcVCard)) {
		if (ixInv == 0) {
			ixMsdcVPreset = checkCrdActive(ixMsdcVCard);
			if (ixMsdcVPreset == 0) {
				denied = true;
			} else {
				preUref = xchg->getRefPreset(ixMsdcVPreset, jref);
			};

		} else {
			ixMsdcVPreset = ixInv;
			preUref = refInv;
		};
	};

	if (!denied) {
		ixMsdcWAccess = checkCrdaccess(ixMsdcVCard);
		denied = (ixMsdcWAccess == 0);
	};

	if (!denied) {
		if (intvalInv == -1) {
			denied = (((ixMsdcWAccess & VecMsdcWAccess::EDIT) == 0) || ((ixMsdcWAccess & VecMsdcWAccess::EXEC) == 0));
		} else if (intvalInv > 0) {
			ixMsdcVRecaccess = checkRecaccess(dbsmsdc, ixMsdcVCard, intvalInv);
			denied = (ixMsdcVRecaccess == VecMsdcVRecaccess::NONE);
		};
	};

	if (denied) {
		refRet = 0;

	} else {
		if (ixMsdcVCard == VecMsdcVCard::CRDMSDCNAV) {
		} else if (ixMsdcVCard == VecMsdcVCard::CRDMSDCUSG) {
			CrdMsdcUsg* crdusg = NULL;

			crdusg = new CrdMsdcUsg(xchg, dbsmsdc, jref, ixMsdcVLocale, ref);
			crdusgs.push_back(crdusg);

			refRet = crdusg->jref;

		} else if (ixMsdcVCard == VecMsdcVCard::CRDMSDCUSR) {
			CrdMsdcUsr* crdusr = NULL;

			crdusr = new CrdMsdcUsr(xchg, dbsmsdc, jref, ixMsdcVLocale, ref);
			crdusrs.push_back(crdusr);

			refRet = crdusr->jref;

		} else if (ixMsdcVCard == VecMsdcVCard::CRDMSDCPRS) {
			CrdMsdcPrs* crdprs = NULL;

			crdprs = new CrdMsdcPrs(xchg, dbsmsdc, jref, ixMsdcVLocale, ref);
			crdprss.push_back(crdprs);

			refRet = crdprs->jref;

		} else if (ixMsdcVCard == VecMsdcVCard::CRDMSDCSCF) {
			CrdMsdcScf* crdscf = NULL;

			crdscf = new CrdMsdcScf(xchg, dbsmsdc, jref, ixMsdcVLocale);
			crdscfs.push_back(crdscf);

			refRet = crdscf->jref;

		} else if (ixMsdcVCard == VecMsdcVCard::CRDMSDCLIV) {
			CrdMsdcLiv* crdliv = NULL;

			crdliv = new CrdMsdcLiv(xchg, dbsmsdc, jref, ixMsdcVLocale);
			crdlivs.push_back(crdliv);

			refRet = crdliv->jref;

		} else if (ixMsdcVCard == VecMsdcVCard::CRDMSDCPRD) {
			CrdMsdcPrd* crdprd = NULL;

			crdprd = new CrdMsdcPrd(xchg, dbsmsdc, jref, ixMsdcVLocale, ref);
			crdprds.push_back(crdprd);

			refRet = crdprd->jref;

		} else if (ixMsdcVCard == VecMsdcVCard::CRDMSDCDAT) {
			CrdMsdcDat* crddat = NULL;

			crddat = new CrdMsdcDat(xchg, dbsmsdc, jref, ixMsdcVLocale, ref, ixMsdcVPreset, preUref);
			crddats.push_back(crddat);

			refRet = crddat->jref;

		} else if (ixMsdcVCard == VecMsdcVCard::CRDMSDCFIL) {
			CrdMsdcFil* crdfil = NULL;

			crdfil = new CrdMsdcFil(xchg, dbsmsdc, jref, ixMsdcVLocale, ref, ixMsdcVPreset, preUref);
			crdfils.push_back(crdfil);

			refRet = crdfil->jref;

		};
	};

	return retval;
};

bool SessMsdc::handleCallMsdcLog(
			DbsMsdc* dbsmsdc
			, const ubigint jrefTrig
			, const uint ixInv
			, const ubigint refInv
			, const string& srefInv
			, const int intvalInv
		) {
	bool retval = false;
	logRecaccess(dbsmsdc, ixInv, refInv, VecMsdcVCard::getIx(srefInv), intvalInv);
	return retval;
};

bool SessMsdc::handleCallMsdcRecaccess(
			DbsMsdc* dbsmsdc
			, const ubigint jrefTrig
			, const uint ixInv
			, const ubigint refInv
			, uint& ixRet
		) {
	bool retval = false;
	ixRet = checkRecaccess(dbsmsdc, ixInv, refInv);
	return retval;
};

bool SessMsdc::handleCallMsdcRefPreSet(
			DbsMsdc* dbsmsdc
			, const ubigint jrefTrig
			, const uint ixInv
			, const ubigint refInv
		) {
	bool retval = false;
	if (ixInv == VecMsdcVPreset::PREMSDCJREFNOTIFY) {
		ubigint jrefNotify_old = xchg->getRefPreset(VecMsdcVPreset::PREMSDCJREFNOTIFY, jref);

		if (refInv != jrefNotify_old) {
			if (jrefNotify_old != 0) xchg->submitDpch(new DpchEngMsdcSuspend(jrefNotify_old));

			if (refInv == 0) xchg->removePreset(ixInv, jref);
			else xchg->addRefPreset(ixInv, jref, refInv);
		};

	} else if ((ixInv == VecMsdcVPreset::PREMSDCREFDAT) || (ixInv == VecMsdcVPreset::PREMSDCREFPRD)) {
		if (refInv == 0) xchg->removePreset(ixInv, jref);
		else xchg->addRefPreset(ixInv, jref, refInv);

		if (crdnav) crdnav->updatePreset(dbsmsdc, ixInv, jrefTrig, true);
	};
	return retval;
};

