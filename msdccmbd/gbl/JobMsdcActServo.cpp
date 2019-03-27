/**
  * \file JobMsdcActServo.cpp
  * job handler for job JobMsdcActServo (implementation)
  * \author Alexander Wirthmueller
  * \date created: 18 Dec 2018
  * \date modified: 18 Dec 2018
  */

#ifdef MSDCCMBD
	#include <Msdccmbd.h>
#else
	#include <Msdcd.h>
#endif

#include "JobMsdcActServo.h"

#include "JobMsdcActServo_blks.cpp"

// IP Shrdat.subs --- INSERT

/******************************************************************************
 class JobMsdcActServo::Shrdat
 ******************************************************************************/

JobMsdcActServo::Shrdat::Shrdat() :
			ShrdatMsdc("JobMsdcActServo", "Shrdat")
		{
};

void JobMsdcActServo::Shrdat::init(
			XchgMsdc* xchg
			, DbsMsdc* dbsmsdc
		) {
		// IP Shrdat.init --- IBEGIN
		theta = 0.0;
		phi = 0.0;
		// IP Shrdat.init --- IEND
};

void JobMsdcActServo::Shrdat::term() {
	// IP Shrdat.term --- INSERT
};

/******************************************************************************
 class JobMsdcActServo
 ******************************************************************************/

JobMsdcActServo::JobMsdcActServo(
			XchgMsdc* xchg
			, DbsMsdc* dbsmsdc
			, const ubigint jrefSup
			, const uint ixMsdcVLocale
			, const bool prefmast
		) :
			MsjobMsdc(xchg, VecMsdcVJob::JOBMSDCACTSERVO, jrefSup, ixMsdcVLocale, prefmast)
		{

	jref = xchg->addMsjob(dbsmsdc, this);

	srcmsdd = NULL;

	// IP constructor.cust1 --- INSERT

	// IP constructor.spec1 --- INSERT

	srcmsdd = new JobMsdcSrcMsdd(xchg, dbsmsdc, jref, ixMsdcVLocale, false);

	// IP constructor.cust2 --- INSERT

	// IP constructor.spec2 --- INSERT

	xchg->addClstn(VecMsdcVCall::CALLMSDCMASTSGECHG, jref, Clstn::VecVJobmask::MAST, 0, Arg(), Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecMsdcVCall::CALLMSDCSHRDATCHG, jref, Clstn::VecVJobmask::MAST, 0, Arg(), Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
	
};

JobMsdcActServo::~JobMsdcActServo() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeMsjobByJref(jref);
};

// IP cust --- INSERT
// IP spec --- INSERT
bool JobMsdcActServo::setPhi(
			DbsMsdc* dbsmsdc
			, const float phi
		) {
	bool retval = true;

	if (getMastNotSlv()) {
		lockAccess("setPhi");

		// IP setPhi --- IBEGIN
		if (phi > stg.phimax) shrdat.phi = stg.phimax;
		else if (phi < stg.phimin) shrdat.phi = stg.phimin;
		else shrdat.phi = phi;

		srcmsdd->servo_setPhi(shrdat.phi);

		xchg->triggerSrefCall(dbsmsdc, VecMsdcVCall::CALLMSDCSHRDATCHG, jref, "thetaPhi");
		// IP setPhi --- IEND

		unlockAccess("setPhi");

	} else {
		JobMsdcActServo* master = (JobMsdcActServo*) lockMaster("setPhi");

		if (master) {
			master->setPhi(dbsmsdc, phi);
			unlockMaster(master, "setPhi");
		};
	};

	return retval;
};

bool JobMsdcActServo::setTheta(
			DbsMsdc* dbsmsdc
			, const float theta
		) {
	bool retval = true;

	if (getMastNotSlv()) {
		lockAccess("setTheta");

		// IP setTheta --- IBEGIN
		if (theta > stg.thetamax) shrdat.theta = stg.thetamax;
		else if (theta < stg.thetamin) shrdat.theta = stg.thetamin;
		else shrdat.theta = theta;

		srcmsdd->servo_setTheta(shrdat.theta);

		xchg->triggerSrefCall(dbsmsdc, VecMsdcVCall::CALLMSDCSHRDATCHG, jref, "thetaPhi");
		// IP setTheta --- IEND

		unlockAccess("setTheta");

	} else {
		JobMsdcActServo* master = (JobMsdcActServo*) lockMaster("setTheta");

		if (master) {
			master->setTheta(dbsmsdc, theta);
			unlockMaster(master, "setTheta");
		};
	};

	return retval;
};

void JobMsdcActServo::giveupMaster(
			DbsMsdc* dbsmsdc
			, Msjobinfo* msji
		) {
	// IP giveupMaster --- INSERT
};

void JobMsdcActServo::giveupSlave(
			DbsMsdc* dbsmsdc
			, Msjobinfo* msji
		) {
	// IP giveupSlave --- INSERT
};

void JobMsdcActServo::becomeMaster(
			DbsMsdc* dbsmsdc
			, Msjobinfo* msji
		) {
	// IP becomeMaster --- INSERT
};

void JobMsdcActServo::becomeSlave(
			DbsMsdc* dbsmsdc
			, Msjobinfo* msji
		) {
	// IP becomeSlave --- INSERT
};

bool JobMsdcActServo::handleClaimMaster(
			DbsMsdc* dbsmsdc
			, Msjobinfo* msji
		) {
	bool retval = !prefmast;
	retval = true; // IP handleClaimMaster --- ILINE
	return retval;
};

void JobMsdcActServo::handleRequest(
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

	} else if ((req->ixVBasetype == ReqMsdc::VecVBasetype::METHOD) && (req->method->ixVFeatgroup == VecMsdcVFeatgroup::VECVJOBMSDCACTSERVOMETHOD)) {
		uint ixVMethod = VecVMethod::getIx(req->method->srefIxVMethod);

		if ((ixVMethod == VecVMethod::SETPHI) && (req->method->parsInv.size() == 1) && (req->method->parsRet.size() == 1)) {
			*((bool*) (req->method->parsRet[0])) = setPhi(dbsmsdc, *((const float*) (req->method->parsInv[0])));
		} else if ((ixVMethod == VecVMethod::SETTHETA) && (req->method->parsInv.size() == 1) && (req->method->parsRet.size() == 1)) {
			*((bool*) (req->method->parsRet[0])) = setTheta(dbsmsdc, *((const float*) (req->method->parsInv[0])));
		};
	};
};

void JobMsdcActServo::handleCall(
			DbsMsdc* dbsmsdc
			, Call* call
		) {
	if (call->ixVCall == VecMsdcVCall::CALLMSDCMASTSGECHG) {
		call->abort = handleCallMsdcMastsgeChg(dbsmsdc, call->jref, call->argInv.ix);
	} else if (call->ixVCall == VecMsdcVCall::CALLMSDCSHRDATCHG) {
		call->abort = handleCallMsdcShrdatChg(dbsmsdc, call->jref, call->argInv.ix, call->argInv.sref);
	};
};

bool JobMsdcActServo::handleCallMsdcMastsgeChg(
			DbsMsdc* dbsmsdc
			, const ubigint jrefTrig
			, const uint ixInv
		) {
	bool retval = false;
	// IP handleCallMsdcMastsgeChg --- INSERT
	return retval;
};

bool JobMsdcActServo::handleCallMsdcShrdatChg(
			DbsMsdc* dbsmsdc
			, const ubigint jrefTrig
			, const uint ixInv
			, const string& srefInv
		) {
	bool retval = false;
	// IP handleCallMsdcShrdatChg --- IBEGIN
	xchg->triggerIxSrefCall(dbsmsdc, VecMsdcVCall::CALLMSDCSHRDATCHG, jref, ixInv, srefInv);
	// IP handleCallMsdcShrdatChg --- IEND
	return retval;
};



