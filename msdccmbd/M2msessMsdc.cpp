/**
  * \file M2msessMsdc.cpp
  * job handler for job M2msessMsdc (implementation)
  * \author Alexander Wirthmueller
  * \date created: 12 Sep 2018
  * \date modified: 12 Sep 2018
  */

#ifdef MSDCCMBD
	#include <Msdccmbd.h>
#else
	#include <Msdcd.h>
#endif

#include "M2msessMsdc.h"

#include "M2msessMsdc_blks.cpp"

/******************************************************************************
 class M2msessMsdc
 ******************************************************************************/

M2msessMsdc::M2msessMsdc(
			XchgMsdc* xchg
			, DbsMsdc* dbsmsdc
			, const ubigint jrefSup
			, const ubigint refMsdcMUser
			, const string& ip
		) :
			JobMsdc(xchg, VecMsdcVJob::M2MSESSMSDC, jrefSup)
		{

	jref = xchg->addJob(this);

	acqadxl = NULL;
	acqlwir = NULL;
	acqvisl = NULL;
	acqvisr = NULL;
	actalign = NULL;
	actled = NULL;
	actservo = NULL;
	prcstereo = NULL;

	// IP constructor.cust1 --- INSERT

	vector<ubigint> refs;

	ubigint refSes;

	MsdcMUser* usr = NULL;

	bool adm;

	ListMsdcRMUserMUsergroup urus;

	uint ixMsdcWAccessBase;

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

	delete usr;

	if (!adm) dbsmsdc->tblmsdcrmusermusergroup->loadRstByUsr(refMsdcMUser, false, urus);

	// determine access rights for each feature group and feature
	ixMsdcWAccessBase = addAccBase(dbsmsdc, VecMsdcVFeatgroup::VECVJOBMSDCACQADXLVAR, adm, urus, refMsdcMUser);
	if (!adm) {
		addAcc(dbsmsdc, VecMsdcVFeatgroup::VECVJOBMSDCACQADXLVAR, "alphaBeta", urus, refMsdcMUser, ixMsdcWAccessBase);
	};
	ixMsdcWAccessBase = addAccBase(dbsmsdc, VecMsdcVFeatgroup::VECVJOBMSDCACQLWIRMETHOD, adm, urus, refMsdcMUser);
	if (!adm) {
		addAcc(dbsmsdc, VecMsdcVFeatgroup::VECVJOBMSDCACQLWIRMETHOD, "setOutput", urus, refMsdcMUser, ixMsdcWAccessBase);
		addAcc(dbsmsdc, VecMsdcVFeatgroup::VECVJOBMSDCACQLWIRMETHOD, "start", urus, refMsdcMUser, ixMsdcWAccessBase);
		addAcc(dbsmsdc, VecMsdcVFeatgroup::VECVJOBMSDCACQLWIRMETHOD, "stop", urus, refMsdcMUser, ixMsdcWAccessBase);
	};
	ixMsdcWAccessBase = addAccBase(dbsmsdc, VecMsdcVFeatgroup::VECVJOBMSDCACQLWIRVAR, adm, urus, refMsdcMUser);
	if (!adm) {
		addAcc(dbsmsdc, VecMsdcVFeatgroup::VECVJOBMSDCACQLWIRVAR, "seqnoTGray16", urus, refMsdcMUser, ixMsdcWAccessBase);
	};
	ixMsdcWAccessBase = addAccBase(dbsmsdc, VecMsdcVFeatgroup::VECVJOBMSDCACQVISLMETHOD, adm, urus, refMsdcMUser);
	if (!adm) {
		addAcc(dbsmsdc, VecMsdcVFeatgroup::VECVJOBMSDCACQVISLMETHOD, "setFocus", urus, refMsdcMUser, ixMsdcWAccessBase);
		addAcc(dbsmsdc, VecMsdcVFeatgroup::VECVJOBMSDCACQVISLMETHOD, "setOutput", urus, refMsdcMUser, ixMsdcWAccessBase);
		addAcc(dbsmsdc, VecMsdcVFeatgroup::VECVJOBMSDCACQVISLMETHOD, "setTint", urus, refMsdcMUser, ixMsdcWAccessBase);
		addAcc(dbsmsdc, VecMsdcVFeatgroup::VECVJOBMSDCACQVISLMETHOD, "start", urus, refMsdcMUser, ixMsdcWAccessBase);
		addAcc(dbsmsdc, VecMsdcVFeatgroup::VECVJOBMSDCACQVISLMETHOD, "stop", urus, refMsdcMUser, ixMsdcWAccessBase);
	};
	ixMsdcWAccessBase = addAccBase(dbsmsdc, VecMsdcVFeatgroup::VECVJOBMSDCACQVISLVAR, adm, urus, refMsdcMUser);
	if (!adm) {
		addAcc(dbsmsdc, VecMsdcVFeatgroup::VECVJOBMSDCACQVISLVAR, "seqnoTRgbx8Gray8", urus, refMsdcMUser, ixMsdcWAccessBase);
	};
	ixMsdcWAccessBase = addAccBase(dbsmsdc, VecMsdcVFeatgroup::VECVJOBMSDCACQVISRMETHOD, adm, urus, refMsdcMUser);
	if (!adm) {
		addAcc(dbsmsdc, VecMsdcVFeatgroup::VECVJOBMSDCACQVISRMETHOD, "setFocus", urus, refMsdcMUser, ixMsdcWAccessBase);
		addAcc(dbsmsdc, VecMsdcVFeatgroup::VECVJOBMSDCACQVISRMETHOD, "setOutput", urus, refMsdcMUser, ixMsdcWAccessBase);
		addAcc(dbsmsdc, VecMsdcVFeatgroup::VECVJOBMSDCACQVISRMETHOD, "setTint", urus, refMsdcMUser, ixMsdcWAccessBase);
		addAcc(dbsmsdc, VecMsdcVFeatgroup::VECVJOBMSDCACQVISRMETHOD, "start", urus, refMsdcMUser, ixMsdcWAccessBase);
		addAcc(dbsmsdc, VecMsdcVFeatgroup::VECVJOBMSDCACQVISRMETHOD, "stop", urus, refMsdcMUser, ixMsdcWAccessBase);
	};
	ixMsdcWAccessBase = addAccBase(dbsmsdc, VecMsdcVFeatgroup::VECVJOBMSDCACQVISRVAR, adm, urus, refMsdcMUser);
	if (!adm) {
		addAcc(dbsmsdc, VecMsdcVFeatgroup::VECVJOBMSDCACQVISRVAR, "seqnoTRgbx8Gray8", urus, refMsdcMUser, ixMsdcWAccessBase);
	};
	ixMsdcWAccessBase = addAccBase(dbsmsdc, VecMsdcVFeatgroup::VECVJOBMSDCACTALIGNMETHOD, adm, urus, refMsdcMUser);
	if (!adm) {
		addAcc(dbsmsdc, VecMsdcVFeatgroup::VECVJOBMSDCACTALIGNMETHOD, "setWave", urus, refMsdcMUser, ixMsdcWAccessBase);
		addAcc(dbsmsdc, VecMsdcVFeatgroup::VECVJOBMSDCACTALIGNMETHOD, "start", urus, refMsdcMUser, ixMsdcWAccessBase);
		addAcc(dbsmsdc, VecMsdcVFeatgroup::VECVJOBMSDCACTALIGNMETHOD, "stop", urus, refMsdcMUser, ixMsdcWAccessBase);
	};
	ixMsdcWAccessBase = addAccBase(dbsmsdc, VecMsdcVFeatgroup::VECVJOBMSDCACTLEDMETHOD, adm, urus, refMsdcMUser);
	if (!adm) {
		addAcc(dbsmsdc, VecMsdcVFeatgroup::VECVJOBMSDCACTLEDMETHOD, "setFlood", urus, refMsdcMUser, ixMsdcWAccessBase);
		addAcc(dbsmsdc, VecMsdcVFeatgroup::VECVJOBMSDCACTLEDMETHOD, "setSpot", urus, refMsdcMUser, ixMsdcWAccessBase);
	};
	ixMsdcWAccessBase = addAccBase(dbsmsdc, VecMsdcVFeatgroup::VECVJOBMSDCACTLEDVAR, adm, urus, refMsdcMUser);
	if (!adm) {
		addAcc(dbsmsdc, VecMsdcVFeatgroup::VECVJOBMSDCACTLEDVAR, "floodSpot", urus, refMsdcMUser, ixMsdcWAccessBase);
	};
	ixMsdcWAccessBase = addAccBase(dbsmsdc, VecMsdcVFeatgroup::VECVJOBMSDCACTSERVOMETHOD, adm, urus, refMsdcMUser);
	if (!adm) {
		addAcc(dbsmsdc, VecMsdcVFeatgroup::VECVJOBMSDCACTSERVOMETHOD, "setPhi", urus, refMsdcMUser, ixMsdcWAccessBase);
		addAcc(dbsmsdc, VecMsdcVFeatgroup::VECVJOBMSDCACTSERVOMETHOD, "setTheta", urus, refMsdcMUser, ixMsdcWAccessBase);
	};
	ixMsdcWAccessBase = addAccBase(dbsmsdc, VecMsdcVFeatgroup::VECVJOBMSDCACTSERVOVAR, adm, urus, refMsdcMUser);
	if (!adm) {
		addAcc(dbsmsdc, VecMsdcVFeatgroup::VECVJOBMSDCACTSERVOVAR, "thetaPhi", urus, refMsdcMUser, ixMsdcWAccessBase);
	};

	// create jobs according to access rights
	if (accs.find(featix_t(VecMsdcVFeatgroup::VECVJOBMSDCACQADXLVAR, "")) != accs.end()) {
		acqadxl = new JobMsdcAcqAdxl(xchg, dbsmsdc, jref, ixMsdcVLocale, false);
		statshr.jrefAcqadxl = acqadxl->jref;
	};
	if ( (accs.find(featix_t(VecMsdcVFeatgroup::VECVJOBMSDCACQLWIRMETHOD, "")) != accs.end()) || (accs.find(featix_t(VecMsdcVFeatgroup::VECVJOBMSDCACQLWIRVAR, "")) != accs.end()) ) {
		acqlwir = new JobMsdcAcqLwir(xchg, dbsmsdc, jref, ixMsdcVLocale, false);
		statshr.jrefAcqlwir = acqlwir->jref;
	};
	if ( (accs.find(featix_t(VecMsdcVFeatgroup::VECVJOBMSDCACQVISLMETHOD, "")) != accs.end()) || (accs.find(featix_t(VecMsdcVFeatgroup::VECVJOBMSDCACQVISLVAR, "")) != accs.end()) ) {
		acqvisl = new JobMsdcAcqVisl(xchg, dbsmsdc, jref, ixMsdcVLocale, false);
		statshr.jrefAcqvisl = acqvisl->jref;
	};
	if ( (accs.find(featix_t(VecMsdcVFeatgroup::VECVJOBMSDCACQVISRMETHOD, "")) != accs.end()) || (accs.find(featix_t(VecMsdcVFeatgroup::VECVJOBMSDCACQVISRVAR, "")) != accs.end()) ) {
		acqvisr = new JobMsdcAcqVisr(xchg, dbsmsdc, jref, ixMsdcVLocale, false);
		statshr.jrefAcqvisr = acqvisr->jref;
	};
	if (accs.find(featix_t(VecMsdcVFeatgroup::VECVJOBMSDCACTALIGNMETHOD, "")) != accs.end()) {
		actalign = new JobMsdcActAlign(xchg, dbsmsdc, jref, ixMsdcVLocale, false);
		statshr.jrefActalign = actalign->jref;
	};
	if ( (accs.find(featix_t(VecMsdcVFeatgroup::VECVJOBMSDCACTLEDMETHOD, "")) != accs.end()) || (accs.find(featix_t(VecMsdcVFeatgroup::VECVJOBMSDCACTLEDVAR, "")) != accs.end()) ) {
		actled = new JobMsdcActLed(xchg, dbsmsdc, jref, ixMsdcVLocale, false);
		statshr.jrefActled = actled->jref;
	};
	if ( (accs.find(featix_t(VecMsdcVFeatgroup::VECVJOBMSDCACTSERVOMETHOD, "")) != accs.end()) || (accs.find(featix_t(VecMsdcVFeatgroup::VECVJOBMSDCACTSERVOVAR, "")) != accs.end()) ) {
		actservo = new JobMsdcActServo(xchg, dbsmsdc, jref, ixMsdcVLocale, false);
		statshr.jrefActservo = actservo->jref;
	};

	// IP constructor.cust2 --- INSERT

	// IP constructor.spec2 --- INSERT

	xchg->addClstn(VecMsdcVCall::CALLMSDCACCESS, jref, Clstn::VecVJobmask::TREE, 0, Arg(), Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
	
};

M2msessMsdc::~M2msessMsdc() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void M2msessMsdc::term(
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

uint M2msessMsdc::addAccBase(
			DbsMsdc* dbsmsdc
			, const uint ixMsdcVFeatgroup
			, const bool adm
			, ListMsdcRMUserMUsergroup& urus
			, const ubigint refMsdcMUser
		) {
	uint ixMsdcWAccess = 0;

	getIxAcc(dbsmsdc, ixMsdcVFeatgroup, "", adm, urus, refMsdcMUser, ixMsdcWAccess);
	if (ixMsdcWAccess != 0) accs.insert(pair<featix_t,uint>(featix_t(ixMsdcVFeatgroup, ""), ixMsdcWAccess));

	return ixMsdcWAccess;
};

void M2msessMsdc::addAcc(
			DbsMsdc* dbsmsdc
			, const uint ixMsdcVFeatgroup
			, const string& srefIxVFeature
			, ListMsdcRMUserMUsergroup& urus
			, const ubigint refMsdcMUser
			, const uint ixMsdcWAccessBase
		) {
	uint ixMsdcWAccess = ixMsdcWAccessBase;

	getIxAcc(dbsmsdc, ixMsdcVFeatgroup, srefIxVFeature, false, urus, refMsdcMUser, ixMsdcWAccess);
	if (ixMsdcWAccess != ixMsdcWAccessBase) accs.insert(pair<featix_t,uint>(featix_t(ixMsdcVFeatgroup, srefIxVFeature), ixMsdcWAccess));
};

void M2msessMsdc::getIxAcc(
			DbsMsdc* dbsmsdc
			, const uint ixMsdcVFeatgroup
			, const string& srefIxVFeature
			, const bool adm
			, ListMsdcRMUserMUsergroup& urus
			, const ubigint refMsdcMUser
			, uint& ixMsdcWAccess
		) {
	MsdcRMUserMUsergroup* uru = NULL;
	MsdcAMUsergroupAccess* usgAacc = NULL;
	MsdcAMUserAccess* usrAacc = NULL;

	uint ixAcc = 0;

	bool first = true;

	if (adm) {
		ixMsdcWAccess = VecMsdcWAccess::EDIT + VecMsdcWAccess::EXEC + VecMsdcWAccess::VIEW;
		return;
	};

	// check for access rights override by any of the applicable user groups
	for (unsigned int i=0;i<urus.nodes.size();i++) {
		uru = urus.nodes[i];

		if (dbsmsdc->tblmsdcamusergroupaccess->loadRecBySQL("SELECT * FROM TblMsdcAMUsergroupAccess WHERE refMsdcMUsergroup = " + to_string(uru->refMsdcMUsergroup) + " AND x1IxMsdcVFeatgroup = " + to_string(ixMsdcVFeatgroup) + " AND x2FeaSrefUix = '" + srefIxVFeature + "'", &usgAacc)) {
			ixAcc |= usgAacc->ixMsdcWAccess;
			first = false;

			delete usgAacc;
		};

		if (ixAcc == (VecMsdcWAccess::EDIT + VecMsdcWAccess::EXEC + VecMsdcWAccess::VIEW)) break;
	};

	if (!first) ixMsdcWAccess = ixAcc;

	// user access rights override user group access rights
	if (dbsmsdc->tblmsdcamuseraccess->loadRecBySQL("SELECT * FROM TblMsdcAMUserAccess WHERE refMsdcMUser = " + to_string(refMsdcMUser) + " AND x1IxMsdcVFeatgroup = " + to_string(ixMsdcVFeatgroup) + " AND x2FeaSrefUix = '" + srefIxVFeature + "'", &usrAacc)) {
		ixMsdcWAccess = usrAacc->ixMsdcWAccess;
		delete usrAacc;
	};
};

void M2msessMsdc::handleRequest(
			DbsMsdc* dbsmsdc
			, ReqMsdc* req
		) {
	if (req->ixVBasetype == ReqMsdc::VecVBasetype::CMD) {
		reqCmd = req;

		if (req->cmd == "cmdset") {

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

void M2msessMsdc::handleDpchAppMsdcInit(
			DbsMsdc* dbsmsdc
			, DpchAppMsdcInit* dpchappmsdcinit
			, DpchEngMsdc** dpcheng
		) {
	*dpcheng = new DpchEngData(jref, &statshr, {DpchEngData::ALL});
};

void M2msessMsdc::handleCall(
			DbsMsdc* dbsmsdc
			, Call* call
		) {
	if (call->ixVCall == VecMsdcVCall::CALLMSDCACCESS) {
		call->abort = handleCallMsdcAccess(dbsmsdc, call->jref, call->argInv.ix, call->argInv.sref, call->argRet.ix);
	};
};

bool M2msessMsdc::handleCallMsdcAccess(
			DbsMsdc* dbsmsdc
			, const ubigint jrefTrig
			, const uint ixInv
			, const string& srefInv
			, uint& ixRet
		) {
	bool retval = false;
	ixRet = 0;

	auto it = accs.find(featix_t(ixInv, srefInv));
	if (it != accs.end()) ixRet = it->second;
	else {
		it = accs.find(featix_t(ixInv, ""));
		if (it != accs.end()) ixRet = it->second;
	};
	return retval;
};

