/**
  * \file JobMsdcPrcSpotfind.cpp
  * job handler for job JobMsdcPrcSpotfind (implementation)
  * \author Alexander Wirthmueller
  * \date created: 29 Aug 2018
  * \date modified: 29 Aug 2018
  */

#ifdef MSDCCMBD
	#include <Msdccmbd.h>
#else
	#include <Msdcd.h>
#endif

#include "JobMsdcPrcSpotfind.h"

#include "JobMsdcPrcSpotfind_blks.cpp"

// IP Shrdat.subs --- INSERT

/******************************************************************************
 class JobMsdcPrcSpotfind::Shrdat
 ******************************************************************************/

JobMsdcPrcSpotfind::Shrdat::Shrdat() :
			ShrdatMsdc("JobMsdcPrcSpotfind", "Shrdat")
		{
};

void JobMsdcPrcSpotfind::Shrdat::init(
			XchgMsdc* xchg
			, DbsMsdc* dbsmsdc
		) {
	// IP Shrdat.init --- INSERT
};

void JobMsdcPrcSpotfind::Shrdat::term() {
	// IP Shrdat.term --- INSERT
};

/******************************************************************************
 class JobMsdcPrcSpotfind
 ******************************************************************************/

JobMsdcPrcSpotfind::JobMsdcPrcSpotfind(
			XchgMsdc* xchg
			, DbsMsdc* dbsmsdc
			, const ubigint jrefSup
			, const uint ixMsdcVLocale
			, const bool prefmast
		) :
			MsjobMsdc(xchg, VecMsdcVJob::JOBMSDCPRCSPOTFIND, jrefSup, ixMsdcVLocale, prefmast)
		{

	jref = xchg->addMsjob(dbsmsdc, this);

	acqvisl = NULL;
	actalign = NULL;

	// IP constructor.cust1 --- INSERT

	// IP constructor.spec1 --- INSERT

	acqvisl = new JobMsdcAcqVisl(xchg, dbsmsdc, jref, ixMsdcVLocale, true);
	actalign = new JobMsdcActAlign(xchg, dbsmsdc, jref, ixMsdcVLocale, true);

	// IP constructor.cust2 --- INSERT

	// IP constructor.spec2 --- INSERT

	xchg->addClstn(VecMsdcVCall::CALLMSDCMASTSGECHG, jref, Clstn::VecVJobmask::MAST, 0, Arg(), Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
	
};

JobMsdcPrcSpotfind::~JobMsdcPrcSpotfind() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeMsjobByJref(jref);
};

// IP cust --- INSERT
// IP spec --- INSERT

void JobMsdcPrcSpotfind::changeStage(
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

uint JobMsdcPrcSpotfind::enterSgeIdle(
			DbsMsdc* dbsmsdc
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;
	nextIxVSge = retval;
	// IP enterSgeIdle --- INSERT
	return retval;
};

void JobMsdcPrcSpotfind::leaveSgeIdle(
			DbsMsdc* dbsmsdc
		) {
	// IP leaveSgeIdle --- INSERT
};

uint JobMsdcPrcSpotfind::enterSgeRun(
			DbsMsdc* dbsmsdc
			, const bool reenter
		) {
	uint retval = VecVSge::RUN;
	nextIxVSge = retval;
	// IP enterSgeRun --- INSERT
	return retval;
};

void JobMsdcPrcSpotfind::leaveSgeRun(
			DbsMsdc* dbsmsdc
		) {
	// IP leaveSgeRun --- INSERT
};

string JobMsdcPrcSpotfind::getSquawk(
			DbsMsdc* dbsmsdc
		) {
	string retval;
	// IP getSquawk --- BEGIN
	retval = VecVSge::getSref(ixVSge);
	// IP getSquawk --- END
	return retval;
};

void JobMsdcPrcSpotfind::giveupMaster(
			DbsMsdc* dbsmsdc
			, Msjobinfo* msji
		) {
	// IP giveupMaster --- INSERT
};

void JobMsdcPrcSpotfind::giveupSlave(
			DbsMsdc* dbsmsdc
			, Msjobinfo* msji
		) {
	// IP giveupSlave --- INSERT
};

void JobMsdcPrcSpotfind::becomeMaster(
			DbsMsdc* dbsmsdc
			, Msjobinfo* msji
		) {
	// IP becomeMaster --- INSERT
};

void JobMsdcPrcSpotfind::becomeSlave(
			DbsMsdc* dbsmsdc
			, Msjobinfo* msji
		) {
	// IP becomeSlave --- INSERT
};

bool JobMsdcPrcSpotfind::handleClaimMaster(
			DbsMsdc* dbsmsdc
			, Msjobinfo* msji
		) {
	bool retval = !prefmast;
	retval = true; // IP handleClaimMaster --- ILINE
	return retval;
};

void JobMsdcPrcSpotfind::handleRequest(
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
	};
};

void JobMsdcPrcSpotfind::handleCall(
			DbsMsdc* dbsmsdc
			, Call* call
		) {
	if (call->ixVCall == VecMsdcVCall::CALLMSDCMASTSGECHG) {
		call->abort = handleCallMsdcMastsgeChg(dbsmsdc, call->jref, call->argInv.ix);
	};
};

bool JobMsdcPrcSpotfind::handleCallMsdcMastsgeChg(
			DbsMsdc* dbsmsdc
			, const ubigint jrefTrig
			, const uint ixInv
		) {
	bool retval = false;
	// IP handleCallMsdcMastsgeChg --- INSERT
	return retval;
};




