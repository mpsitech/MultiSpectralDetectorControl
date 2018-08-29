/**
  * \file JobMsdcPrcTrack.cpp
  * job handler for job JobMsdcPrcTrack (implementation)
  * \author Alexander Wirthmueller
  * \date created: 29 Aug 2018
  * \date modified: 29 Aug 2018
  */

#ifdef MSDCCMBD
	#include <Msdccmbd.h>
#else
	#include <Msdcd.h>
#endif

#include "JobMsdcPrcTrack.h"

#include "JobMsdcPrcTrack_blks.cpp"

// IP Shrdat.subs --- INSERT

/******************************************************************************
 class JobMsdcPrcTrack::Shrdat
 ******************************************************************************/

JobMsdcPrcTrack::Shrdat::Shrdat() :
			ShrdatMsdc("JobMsdcPrcTrack", "Shrdat")
		{
};

void JobMsdcPrcTrack::Shrdat::init(
			XchgMsdc* xchg
			, DbsMsdc* dbsmsdc
		) {
	// IP Shrdat.init --- INSERT
};

void JobMsdcPrcTrack::Shrdat::term() {
	// IP Shrdat.term --- INSERT
};

/******************************************************************************
 class JobMsdcPrcTrack
 ******************************************************************************/

JobMsdcPrcTrack::JobMsdcPrcTrack(
			XchgMsdc* xchg
			, DbsMsdc* dbsmsdc
			, const ubigint jrefSup
			, const uint ixMsdcVLocale
			, const bool prefmast
		) :
			MsjobMsdc(xchg, VecMsdcVJob::JOBMSDCPRCTRACK, jrefSup, ixMsdcVLocale, prefmast)
		{

	jref = xchg->addMsjob(dbsmsdc, this);

	acqvisl = NULL;
	actservo = NULL;
	actalign = NULL;

	// IP constructor.cust1 --- INSERT

	// IP constructor.spec1 --- INSERT

	acqvisl = new JobMsdcAcqVisl(xchg, dbsmsdc, jref, ixMsdcVLocale, true);
	actservo = new JobMsdcActServo(xchg, dbsmsdc, jref, ixMsdcVLocale, true);
	actalign = new JobMsdcActAlign(xchg, dbsmsdc, jref, ixMsdcVLocale, true);

	// IP constructor.cust2 --- INSERT

	// IP constructor.spec2 --- INSERT

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
	
};

JobMsdcPrcTrack::~JobMsdcPrcTrack() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeMsjobByJref(jref);
};

// IP cust --- INSERT
// IP spec --- INSERT

void JobMsdcPrcTrack::changeStage(
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

uint JobMsdcPrcTrack::enterSgeIdle(
			DbsMsdc* dbsmsdc
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;
	nextIxVSge = retval;
	// IP enterSgeIdle --- INSERT
	return retval;
};

void JobMsdcPrcTrack::leaveSgeIdle(
			DbsMsdc* dbsmsdc
		) {
	// IP leaveSgeIdle --- INSERT
};

uint JobMsdcPrcTrack::enterSgeRun(
			DbsMsdc* dbsmsdc
			, const bool reenter
		) {
	uint retval = VecVSge::RUN;
	nextIxVSge = retval;
	// IP enterSgeRun --- INSERT
	return retval;
};

void JobMsdcPrcTrack::leaveSgeRun(
			DbsMsdc* dbsmsdc
		) {
	// IP leaveSgeRun --- INSERT
};

string JobMsdcPrcTrack::getSquawk(
			DbsMsdc* dbsmsdc
		) {
	string retval;
	// IP getSquawk --- BEGIN
	retval = VecVSge::getSref(ixVSge);
	// IP getSquawk --- END
	return retval;
};

void JobMsdcPrcTrack::giveupMaster(
			DbsMsdc* dbsmsdc
			, Msjobinfo* msji
		) {
	// IP giveupMaster --- INSERT
};

void JobMsdcPrcTrack::giveupSlave(
			DbsMsdc* dbsmsdc
			, Msjobinfo* msji
		) {
	// IP giveupSlave --- INSERT
};

void JobMsdcPrcTrack::becomeMaster(
			DbsMsdc* dbsmsdc
			, Msjobinfo* msji
		) {
	// IP becomeMaster --- INSERT
};

void JobMsdcPrcTrack::becomeSlave(
			DbsMsdc* dbsmsdc
			, Msjobinfo* msji
		) {
	// IP becomeSlave --- INSERT
};

bool JobMsdcPrcTrack::handleClaimMaster(
			DbsMsdc* dbsmsdc
			, Msjobinfo* msji
		) {
	bool retval = !prefmast;
	retval = true; // IP handleClaimMaster --- ILINE
	return retval;
};

void JobMsdcPrcTrack::handleRequest(
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




