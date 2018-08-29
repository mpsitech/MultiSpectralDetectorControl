/**
  * \file JobMsdcActLed.cpp
  * job handler for job JobMsdcActLed (implementation)
  * \author Alexander Wirthmueller
  * \date created: 29 Aug 2018
  * \date modified: 29 Aug 2018
  */

#ifdef MSDCCMBD
	#include <Msdccmbd.h>
#else
	#include <Msdcd.h>
#endif

#include "JobMsdcActLed.h"

#include "JobMsdcActLed_blks.cpp"

// IP Shrdat.subs --- INSERT

/******************************************************************************
 class JobMsdcActLed::Shrdat
 ******************************************************************************/

JobMsdcActLed::Shrdat::Shrdat() :
			ShrdatMsdc("JobMsdcActLed", "Shrdat")
		{
};

void JobMsdcActLed::Shrdat::init(
			XchgMsdc* xchg
			, DbsMsdc* dbsmsdc
		) {
	// IP Shrdat.init --- IBEGIN
	spot = 0.05;
	flood = 0.05;
	// IP Shrdat.init --- IEND
};

void JobMsdcActLed::Shrdat::term() {
	// IP Shrdat.term --- INSERT
};

/******************************************************************************
 class JobMsdcActLed
 ******************************************************************************/

JobMsdcActLed::JobMsdcActLed(
			XchgMsdc* xchg
			, DbsMsdc* dbsmsdc
			, const ubigint jrefSup
			, const uint ixMsdcVLocale
			, const bool prefmast
		) :
			MsjobMsdc(xchg, VecMsdcVJob::JOBMSDCACTLED, jrefSup, ixMsdcVLocale, prefmast)
		{

	jref = xchg->addMsjob(dbsmsdc, this);

	srcmsdd = NULL;

	// IP constructor.cust1 --- INSERT

	// IP constructor.spec1 --- INSERT

	srcmsdd = new JobMsdcSrcMsdd(xchg, dbsmsdc, jref, ixMsdcVLocale, true);

	// IP constructor.cust2 --- INSERT

	// IP constructor.spec2 --- INSERT

	xchg->addClstn(VecMsdcVCall::CALLMSDCMASTSGECHG, jref, Clstn::VecVJobmask::MAST, 0, Arg(), Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecMsdcVCall::CALLMSDCSHRDATCHG, jref, Clstn::VecVJobmask::MAST, 0, Arg(), Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
	
};

JobMsdcActLed::~JobMsdcActLed() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeMsjobByJref(jref);
};

// IP cust --- INSERT
// IP spec --- INSERT
bool JobMsdcActLed::setFlood(
			DbsMsdc* dbsmsdc
			, const float flood
		) {
	bool retval = true;

	if (getMastNotSlv()) {
		lockAccess("setFlood");

		// IP setFlood --- IBEGIN
		shrdat.flood = flood;
		srcmsdd->led_setTon60(flood);

		xchg->triggerSrefCall(dbsmsdc, VecMsdcVCall::CALLMSDCSHRDATCHG, jref, "floodSpot");
		// IP setFlood --- IEND

		unlockAccess("setFlood");

	} else {
		JobMsdcActLed* master = (JobMsdcActLed*) lockMaster("setFlood");

		if (master) {
			master->setFlood(dbsmsdc, flood);
			unlockMaster(master, "setFlood");
		};
	};

	return retval;
};

bool JobMsdcActLed::setSpot(
			DbsMsdc* dbsmsdc
			, const float spot
		) {
	bool retval = true;

	if (getMastNotSlv()) {
		lockAccess("setSpot");

		// IP setSpot --- IBEGIN
		shrdat.spot = spot;
		srcmsdd->led_setTon15(spot);

		xchg->triggerSrefCall(dbsmsdc, VecMsdcVCall::CALLMSDCSHRDATCHG, jref, "floodSpot");
		// IP setSpot --- IEND

		unlockAccess("setSpot");

	} else {
		JobMsdcActLed* master = (JobMsdcActLed*) lockMaster("setSpot");

		if (master) {
			master->setSpot(dbsmsdc, spot);
			unlockMaster(master, "setSpot");
		};
	};

	return retval;
};

void JobMsdcActLed::giveupMaster(
			DbsMsdc* dbsmsdc
			, Msjobinfo* msji
		) {
	// IP giveupMaster --- INSERT
};

void JobMsdcActLed::giveupSlave(
			DbsMsdc* dbsmsdc
			, Msjobinfo* msji
		) {
	// IP giveupSlave --- INSERT
};

void JobMsdcActLed::becomeMaster(
			DbsMsdc* dbsmsdc
			, Msjobinfo* msji
		) {
	// IP becomeMaster --- INSERT
};

void JobMsdcActLed::becomeSlave(
			DbsMsdc* dbsmsdc
			, Msjobinfo* msji
		) {
	// IP becomeSlave --- INSERT
};

bool JobMsdcActLed::handleClaimMaster(
			DbsMsdc* dbsmsdc
			, Msjobinfo* msji
		) {
	bool retval = !prefmast;
	retval = true; // IP handleClaimMaster --- ILINE
	return retval;
};

void JobMsdcActLed::handleRequest(
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

	} else if ((req->ixVBasetype == ReqMsdc::VecVBasetype::METHOD) && (req->method->ixVFeatgroup == VecMsdcVFeatgroup::VECVJOBMSDCACTLEDMETHOD)) {
		uint ixVMethod = VecVMethod::getIx(req->method->srefIxVMethod);

		if ((ixVMethod == VecVMethod::SETFLOOD) && (req->method->parsInv.size() == 1) && (req->method->parsRet.size() == 1)) {
			*((bool*) (req->method->parsRet[0])) = setFlood(dbsmsdc, *((const float*) (req->method->parsInv[0])));
		} else if ((ixVMethod == VecVMethod::SETSPOT) && (req->method->parsInv.size() == 1) && (req->method->parsRet.size() == 1)) {
			*((bool*) (req->method->parsRet[0])) = setSpot(dbsmsdc, *((const float*) (req->method->parsInv[0])));
		};
	};
};

void JobMsdcActLed::handleCall(
			DbsMsdc* dbsmsdc
			, Call* call
		) {
	if (call->ixVCall == VecMsdcVCall::CALLMSDCMASTSGECHG) {
		call->abort = handleCallMsdcMastsgeChg(dbsmsdc, call->jref, call->argInv.ix);
	} else if (call->ixVCall == VecMsdcVCall::CALLMSDCSHRDATCHG) {
		call->abort = handleCallMsdcShrdatChg(dbsmsdc, call->jref, call->argInv.ix, call->argInv.sref);
	};
};

bool JobMsdcActLed::handleCallMsdcMastsgeChg(
			DbsMsdc* dbsmsdc
			, const ubigint jrefTrig
			, const uint ixInv
		) {
	bool retval = false;
	// IP handleCallMsdcMastsgeChg --- IBEGIN
	setStage(dbsmsdc, ixInv);
	// IP handleCallMsdcMastsgeChg --- IEND
	return retval;
};

bool JobMsdcActLed::handleCallMsdcShrdatChg(
			DbsMsdc* dbsmsdc
			, const ubigint jrefTrig
			, const uint ixInv
			, const string& srefInv
		) {
	bool retval = false;
	// IP handleCallMsdcShrdatChg --- IBEGIN
	xchg->triggerSrefCall(dbsmsdc, VecMsdcVCall::CALLMSDCSHRDATCHG, jref, "floodSpot");
	// IP handleCallMsdcShrdatChg --- IEND
	return retval;
};




