/**
  * \file JobMsdcSrcTrigger.cpp
  * job handler for job JobMsdcSrcTrigger (implementation)
  * \author Alexander Wirthmueller
  * \date created: 12 Sep 2018
  * \date modified: 12 Sep 2018
  */

#ifdef MSDCCMBD
	#include <Msdccmbd.h>
#else
	#include <Msdcd.h>
#endif

#include "JobMsdcSrcTrigger.h"

#include "JobMsdcSrcTrigger_blks.cpp"

// IP Shrdat.subs --- INSERT

/******************************************************************************
 class JobMsdcSrcTrigger::Shrdat
 ******************************************************************************/

JobMsdcSrcTrigger::Shrdat::Shrdat() :
			ShrdatMsdc("JobMsdcSrcTrigger", "Shrdat")
		{
};

void JobMsdcSrcTrigger::Shrdat::init(
			XchgMsdc* xchg
			, DbsMsdc* dbsmsdc
		) {
		// IP Shrdat.init --- IBEGIN
		seqno = 0;
		t = 0.0;
		// IP Shrdat.init --- IEND
};

void JobMsdcSrcTrigger::Shrdat::term() {
	// IP Shrdat.term --- INSERT
};

/******************************************************************************
 class JobMsdcSrcTrigger
 ******************************************************************************/

JobMsdcSrcTrigger::JobMsdcSrcTrigger(
			XchgMsdc* xchg
			, DbsMsdc* dbsmsdc
			, const ubigint jrefSup
			, const uint ixMsdcVLocale
			, const bool prefmast
		) :
			MsjobMsdc(xchg, VecMsdcVJob::JOBMSDCSRCTRIGGER, jrefSup, ixMsdcVLocale, prefmast)
		{

	jref = xchg->addMsjob(dbsmsdc, this);

	// IP constructor.cust1 --- INSERT

	// IP constructor.spec1 --- INSERT

	// IP constructor.cust2 --- INSERT

	// IP constructor.spec2 --- INSERT

	xchg->addClstn(VecMsdcVCall::CALLMSDCTRIG, jref, Clstn::VecVJobmask::MAST, 0, Arg(), Clstn::VecVJactype::TRY);
	xchg->addClstn(VecMsdcVCall::CALLMSDCMASTSGECHG, jref, Clstn::VecVJobmask::MAST, 0, Arg(), Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecMsdcVCall::CALLMSDCMASTSRDCHG, jref, Clstn::VecVJobmask::SELF, 0, Arg(), Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecMsdcVCall::CALLMSDCMASTSRDCHG, jref, Clstn::VecVJobmask::SLV, 0, Arg(), Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
	
	start(dbsmsdc);
};

JobMsdcSrcTrigger::~JobMsdcSrcTrigger() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeMsjobByJref(jref);
};

// IP cust --- INSERT
// IP spec --- INSERT

void JobMsdcSrcTrigger::changeStage(
			DbsMsdc* dbsmsdc
			, uint _ixVSge
		) {
	bool reenter = true;

	do {
		if (ixVSge != _ixVSge) {
			switch (ixVSge) {
				case VecVSge::IDLE: leaveSgeIdle(dbsmsdc); break;
				case VecVSge::RUN: leaveSgeRun(dbsmsdc); break;
			};

			setStage(dbsmsdc, _ixVSge);
			reenter = false;
			// IP changeStage.refresh1 --- INSERT
		};

		switch (_ixVSge) {
			case VecVSge::IDLE: _ixVSge = enterSgeIdle(dbsmsdc, reenter); break;
			case VecVSge::RUN: _ixVSge = enterSgeRun(dbsmsdc, reenter); break;
		};

		// IP changeStage.refresh2 --- INSERT
	} while (ixVSge != _ixVSge);
};

uint JobMsdcSrcTrigger::enterSgeIdle(
			DbsMsdc* dbsmsdc
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;
	nextIxVSge = retval;
	// IP enterSgeIdle --- INSERT
	return retval;
};

void JobMsdcSrcTrigger::leaveSgeIdle(
			DbsMsdc* dbsmsdc
		) {
	// IP leaveSgeIdle --- INSERT
};

uint JobMsdcSrcTrigger::enterSgeRun(
			DbsMsdc* dbsmsdc
			, const bool reenter
		) {
	uint retval = VecVSge::RUN;
	nextIxVSge = retval;
	// IP enterSgeRun --- IBEGIN
	double deltat;

	shrdat.rlockAccess(jref, "enterSgeRun");

	deltat = (shrdat.t + stg.dt) - Msdc::getNow();
	if (deltat < 0.0) deltat = 0.0;
	else if (deltat > stg.dt) deltat = stg.dt;

	shrdat.runlockAccess(jref, "enterSgeRun");

	wrefLast = xchg->addWakeup(jref, "run", lround(1000000.0*deltat));
	// IP enterSgeRun --- IEND
	return retval;
};

void JobMsdcSrcTrigger::leaveSgeRun(
			DbsMsdc* dbsmsdc
		) {
	invalidateWakeups();
	// IP leaveSgeRun --- INSERT
};

string JobMsdcSrcTrigger::getSquawk(
			DbsMsdc* dbsmsdc
		) {
	string retval;
	// IP getSquawk --- BEGIN
	retval = VecVSge::getSref(ixVSge);
	// IP getSquawk --- END
	return retval;
};

void JobMsdcSrcTrigger::giveupMaster(
			DbsMsdc* dbsmsdc
			, Msjobinfo* msji
		) {
	if (ixVSge == VecVSge::RUN) changeStage(dbsmsdc, VecVSge::IDLE); // IP giveupMaster --- ILINE
};

void JobMsdcSrcTrigger::giveupSlave(
			DbsMsdc* dbsmsdc
			, Msjobinfo* msji
		) {
	// IP giveupSlave --- INSERT
};

void JobMsdcSrcTrigger::becomeMaster(
			DbsMsdc* dbsmsdc
			, Msjobinfo* msji
		) {
	if ((ixVSge == VecVSge::IDLE) && !msji->jrefsSrd.empty()) changeStage(dbsmsdc, VecVSge::RUN); // IP becomeMaster --- ILINE
};

void JobMsdcSrcTrigger::becomeSlave(
			DbsMsdc* dbsmsdc
			, Msjobinfo* msji
		) {
	// IP becomeSlave --- INSERT
};

bool JobMsdcSrcTrigger::handleClaimMaster(
			DbsMsdc* dbsmsdc
			, Msjobinfo* msji
		) {
	bool retval = !prefmast;
	retval = true; // IP handleClaimMaster --- ILINE
	return retval;
};

void JobMsdcSrcTrigger::handleRequest(
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

	} else if (req->ixVBasetype == ReqMsdc::VecVBasetype::TIMER) {
		handleTimer(dbsmsdc, req->sref);
	};
};

void JobMsdcSrcTrigger::handleTimer(
			DbsMsdc* dbsmsdc
			, const string& sref
		) {
	if ((ixVSge == VecVSge::RUN) && (sref == "run")) {
		// IP handleTimer.run --- IBEGIN
		shrdat.wlockAccess(jref, "handleTimer");

		shrdat.seqno++;
		shrdat.t = Msdc::getNow();

		xchg->triggerIntvalCall(dbsmsdc, VecMsdcVCall::CALLMSDCTRIG, jref, shrdat.seqno);

		shrdat.wunlockAccess(jref, "handleTimer");

		wrefLast = xchg->addWakeup(jref, "run", lround(1000000.0*stg.dt));
		// IP handleTimer.run --- IEND
	};
};

void JobMsdcSrcTrigger::handleCall(
			DbsMsdc* dbsmsdc
			, Call* call
		) {
	if (call->ixVCall == VecMsdcVCall::CALLMSDCTRIG) {
		call->abort = handleCallMsdcTrig(dbsmsdc, call->jref, call->argInv.intval);
	} else if (call->ixVCall == VecMsdcVCall::CALLMSDCMASTSGECHG) {
		call->abort = handleCallMsdcMastsgeChg(dbsmsdc, call->jref, call->argInv.ix);
	} else if (call->ixVCall == VecMsdcVCall::CALLMSDCMASTSRDCHG) {
		call->abort = handleCallMsdcMastsrdChg(dbsmsdc, call->jref, call->argInv.boolval);
	};
};

bool JobMsdcSrcTrigger::handleCallMsdcTrig(
			DbsMsdc* dbsmsdc
			, const ubigint jrefTrig
			, const int intvalInv
		) {
	bool retval = false;
	// IP handleCallMsdcTrig --- IBEGIN
	xchg->triggerIntvalCall(dbsmsdc, VecMsdcVCall::CALLMSDCTRIG, jref, intvalInv);
	// IP handleCallMsdcTrig --- IEND
	return retval;
};

bool JobMsdcSrcTrigger::handleCallMsdcMastsgeChg(
			DbsMsdc* dbsmsdc
			, const ubigint jrefTrig
			, const uint ixInv
		) {
	bool retval = false;
	// IP handleCallMsdcMastsgeChg --- INSERT
	return retval;
};

bool JobMsdcSrcTrigger::handleCallMsdcMastsrdChg(
			DbsMsdc* dbsmsdc
			, const ubigint jrefTrig
			, const bool boolvalInv
		) {
	bool retval = false;
	// IP handleCallMsdcMastsrdChg --- IBEGIN
	if (getMastNotSlv()) {
		if (boolvalInv && (ixVSge == VecVSge::IDLE)) changeStage(dbsmsdc, VecVSge::RUN);
		else if (!boolvalInv && (ixVSge != VecVSge::IDLE)) changeStage(dbsmsdc, VecVSge::IDLE);
	};
	// IP handleCallMsdcMastsrdChg --- IEND
	return retval;
};



