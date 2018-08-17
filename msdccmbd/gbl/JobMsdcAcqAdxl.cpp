/**
  * \file JobMsdcAcqAdxl.cpp
  * job handler for job JobMsdcAcqAdxl (implementation)
  * \author Alexander Wirthmueller
  * \date created: 15 Aug 2018
  * \date modified: 15 Aug 2018
  */

#ifdef MSDCCMBD
	#include <Msdccmbd.h>
#else
	#include <Msdcd.h>
#endif

#include "JobMsdcAcqAdxl.h"

#include "JobMsdcAcqAdxl_blks.cpp"

// IP Shrdat.subs --- INSERT

/******************************************************************************
 class JobMsdcAcqAdxl::Shrdat
 ******************************************************************************/

JobMsdcAcqAdxl::Shrdat::Shrdat() : ShrdatMsdc("JobMsdcAcqAdxl", "Shrdat", "JobMsdcAcqAdxl::shrdat") {
};

void JobMsdcAcqAdxl::Shrdat::init(
			XchgMsdc* xchg
			, DbsMsdc* dbsmsdc
		) {
		// IP Shrdat.init --- IBEGIN
		alpha = 0.0;
		beta = 0.0;
		// IP Shrdat.init --- IEND
};

void JobMsdcAcqAdxl::Shrdat::term() {
	// IP Shrdat.term --- INSERT
};

/******************************************************************************
 class JobMsdcAcqAdxl
 ******************************************************************************/

JobMsdcAcqAdxl::JobMsdcAcqAdxl(
			XchgMsdc* xchg
			, DbsMsdc* dbsmsdc
			, const ubigint jrefSup
			, const uint ixMsdcVLocale
			, const bool prefmast
		) : MsjobMsdc(xchg, VecMsdcVJob::JOBMSDCACQADXL, jrefSup, ixMsdcVLocale, prefmast) {

	jref = xchg->addMsjob(dbsmsdc, this);

	srcmsdd = NULL;
	srctrigger = NULL;

	// IP constructor.cust1 --- INSERT

	// IP constructor.spec1 --- INSERT

	srcmsdd = new JobMsdcSrcMsdd(xchg, dbsmsdc, jref, ixMsdcVLocale, true);
	srctrigger = new JobMsdcSrcTrigger(xchg, dbsmsdc, jref, ixMsdcVLocale, true);

	// IP constructor.cust2 --- INSERT

	// IP constructor.spec2 --- INSERT

	xchg->addClstn(VecMsdcVCall::CALLMSDCTRIG, jref, Clstn::VecVJobmask::IMM, 0, Arg(), Clstn::VecVJactype::TRY);
	xchg->addClstn(VecMsdcVCall::CALLMSDCMASTSRDCHG, jref, Clstn::VecVJobmask::SELF, 0, Arg(), Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecMsdcVCall::CALLMSDCMASTSRDCHG, jref, Clstn::VecVJobmask::SLV, 0, Arg(), Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecMsdcVCall::CALLMSDCSHRDATCHG, jref, Clstn::VecVJobmask::MAST, 0, Arg(), Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
	
	start(dbsmsdc);
};

JobMsdcAcqAdxl::~JobMsdcAcqAdxl() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeMsjobByJref(jref);
};

// IP cust --- INSERT
// IP spec --- INSERT

void JobMsdcAcqAdxl::changeStage(
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

uint JobMsdcAcqAdxl::enterSgeIdle(
			DbsMsdc* dbsmsdc
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;
	nextIxVSge = retval;
	// IP enterSgeIdle --- INSERT
	return retval;
};

void JobMsdcAcqAdxl::leaveSgeIdle(
			DbsMsdc* dbsmsdc
		) {
	// IP leaveSgeIdle --- INSERT
};

uint JobMsdcAcqAdxl::enterSgeRun(
			DbsMsdc* dbsmsdc
			, const bool reenter
		) {
	uint retval = VecVSge::RUN;
	nextIxVSge = retval;

	if (!reenter) wrefLast = xchg->addWakeup(jref, "mon", 250000, true);
	// IP enterSgeRun --- IBEGIN

	lockAccess("enterSgeRun");

	srcmsdd->getAdxlAngles(shrdat.alpha, shrdat.beta);

	xchg->triggerSrefCall(dbsmsdc, VecMsdcVCall::CALLMSDCSHRDATCHG, jref, "alphaBeta");

	unlockAccess("enterSgeRun");

	// IP enterSgeRun --- IEND
	return retval;
};

void JobMsdcAcqAdxl::leaveSgeRun(
			DbsMsdc* dbsmsdc
		) {
	invalidateWakeups();
	// IP leaveSgeRun --- INSERT
};

string JobMsdcAcqAdxl::getSquawk(
			DbsMsdc* dbsmsdc
		) {
	string retval;
	// IP getSquawk --- BEGIN
	retval = VecVSge::getSref(ixVSge);
	// IP getSquawk --- END
	return retval;
};

void JobMsdcAcqAdxl::giveupMaster(
			DbsMsdc* dbsmsdc
			, Msjobinfo* msji
		) {
	// IP giveupMaster --- INSERT
};

void JobMsdcAcqAdxl::giveupSlave(
			DbsMsdc* dbsmsdc
			, Msjobinfo* msji
		) {
	// IP giveupSlave --- INSERT
};

void JobMsdcAcqAdxl::becomeMaster(
			DbsMsdc* dbsmsdc
			, Msjobinfo* msji
		) {
	if ((ixVSge == VecVSge::IDLE) && !msji->jrefsSrd.empty()) ixVSge = VecVSge::RUN; // IP becomeMaster --- ILINE
};

void JobMsdcAcqAdxl::becomeSlave(
			DbsMsdc* dbsmsdc
			, Msjobinfo* msji
		) {
	if ((ixVSge != VecVSge::IDLE) && !srd) ixVSge = VecVSge::IDLE; // IP becomeSlave --- ILINE
};

bool JobMsdcAcqAdxl::handleClaimMaster(
			DbsMsdc* dbsmsdc
			, Msjobinfo* msji
		) {
	bool retval = !prefmast;
	retval = true; // IP handleClaimMaster --- ILINE
	return retval;
};

void JobMsdcAcqAdxl::handleRequest(
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

void JobMsdcAcqAdxl::handleTimer(
			DbsMsdc* dbsmsdc
			, const string& sref
		) {
	if ((ixVSge == VecVSge::RUN) && (sref == "run")) {
		// IP handleTimer.run --- INSERT
	} else if ((ixVSge == VecVSge::RUN) && (sref == "mon")) {
		wrefLast = xchg->addWakeup(jref, "mon", 250000, true);
		// IP handleTimer.run.mon --- INSERT
	};
};

void JobMsdcAcqAdxl::handleCall(
			DbsMsdc* dbsmsdc
			, Call* call
		) {
	if (call->ixVCall == VecMsdcVCall::CALLMSDCTRIG) {
		call->abort = handleCallMsdcTrig(dbsmsdc, call->jref, call->argInv.intval);
	} else if (call->ixVCall == VecMsdcVCall::CALLMSDCMASTSRDCHG) {
		call->abort = handleCallMsdcMastsrdChg(dbsmsdc, call->jref, call->argInv.boolval);
	} else if (call->ixVCall == VecMsdcVCall::CALLMSDCSHRDATCHG) {
		call->abort = handleCallMsdcShrdatChg(dbsmsdc, call->jref, call->argInv.ix, call->argInv.sref);
	};
};

bool JobMsdcAcqAdxl::handleCallMsdcTrig(
			DbsMsdc* dbsmsdc
			, const ubigint jrefTrig
			, const int intvalInv
		) {
	bool retval = false;
	// IP handleCallMsdcTrig --- IBEGIN
	if (getMastNotSlv() && (ixVSge == VecVSge::RUN)) {
		changeStage(dbsmsdc, VecVSge::RUN);
	};
	// IP handleCallMsdcTrig --- IEND
	return retval;
};

bool JobMsdcAcqAdxl::handleCallMsdcMastsrdChg(
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

bool JobMsdcAcqAdxl::handleCallMsdcShrdatChg(
			DbsMsdc* dbsmsdc
			, const ubigint jrefTrig
			, const uint ixInv
			, const string& srefInv
		) {
	bool retval = false;
	// IP handleCallMsdcShrdatChg --- IBEGIN
	xchg->triggerSrefCall(dbsmsdc, VecMsdcVCall::CALLMSDCSHRDATCHG, jref, "alphaBeta");
	// IP handleCallMsdcShrdatChg --- IEND
	return retval;
};




