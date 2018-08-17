/**
  * \file JobMsdcActAlign.cpp
  * job handler for job JobMsdcActAlign (implementation)
  * \author Alexander Wirthmueller
  * \date created: 15 Aug 2018
  * \date modified: 15 Aug 2018
  */

#ifdef MSDCCMBD
	#include <Msdccmbd.h>
#else
	#include <Msdcd.h>
#endif

#include "JobMsdcActAlign.h"

#include "JobMsdcActAlign_blks.cpp"

// IP Shrdat.subs --- INSERT

/******************************************************************************
 class JobMsdcActAlign::Shrdat
 ******************************************************************************/

JobMsdcActAlign::Shrdat::Shrdat() : ShrdatMsdc("JobMsdcActAlign", "Shrdat", "JobMsdcActAlign::shrdat") {
};

void JobMsdcActAlign::Shrdat::init(
			XchgMsdc* xchg
			, DbsMsdc* dbsmsdc
		) {
	// IP Shrdat.init --- IBEGIN
	size_t lenSeqSine = 16;

	seq.resize(lenSeqSine);

	for (unsigned int i=0;i<lenSeqSine;i++) seq[i] = 0.5 * (1.0+sin(2*pi*((double) i)/((double) lenSeqSine)));
	// IP Shrdat.init --- IEND
};

void JobMsdcActAlign::Shrdat::term() {
	// IP Shrdat.term --- INSERT
};

/******************************************************************************
 class JobMsdcActAlign
 ******************************************************************************/

JobMsdcActAlign::JobMsdcActAlign(
			XchgMsdc* xchg
			, DbsMsdc* dbsmsdc
			, const ubigint jrefSup
			, const uint ixMsdcVLocale
			, const bool prefmast
		) : MsjobMsdc(xchg, VecMsdcVJob::JOBMSDCACTALIGN, jrefSup, ixMsdcVLocale, prefmast) {

	jref = xchg->addMsjob(dbsmsdc, this);

	srcmsdd = NULL;

	// IP constructor.cust1 --- INSERT

	// IP constructor.spec1 --- INSERT

	srcmsdd = new JobMsdcSrcMsdd(xchg, dbsmsdc, jref, ixMsdcVLocale, true);

	// IP constructor.cust2 --- INSERT

	// IP constructor.spec2 --- INSERT

	xchg->addClstn(VecMsdcVCall::CALLMSDCMASTSRDCHG, jref, Clstn::VecVJobmask::SELF, 0, Arg(), Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecMsdcVCall::CALLMSDCMASTSRDCHG, jref, Clstn::VecVJobmask::SLV, 0, Arg(), Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
	
};

JobMsdcActAlign::~JobMsdcActAlign() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeMsjobByJref(jref);
};

// IP cust --- INSERT
// IP spec --- INSERT
bool JobMsdcActAlign::setWave(
			DbsMsdc* dbsmsdc
			, const uint ixVFunction
			, const utinyint N
			, const vector<float>& seq
		) {
	bool retval = true;

	if (getMastNotSlv()) {
		lockAccess("setWave");

		// IP setWave --- INSERT

		unlockAccess("setWave");

	} else {
		JobMsdcActAlign* master = (JobMsdcActAlign*) lockMaster("setWave");

		if (master) {
			master->setWave(dbsmsdc, ixVFunction, N, seq);
			unlockMaster(master, "setWave");
		};
	};

	return retval;
};

void JobMsdcActAlign::changeStage(
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

uint JobMsdcActAlign::enterSgeIdle(
			DbsMsdc* dbsmsdc
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;
	nextIxVSge = retval;
	// IP enterSgeIdle --- IBEGIN
	if (getMastNotSlv()) {
		srcmsdd->trigger_setRng(false, false);
	};
	// IP enterSgeIdle --- IEND
	return retval;
};

void JobMsdcActAlign::leaveSgeIdle(
			DbsMsdc* dbsmsdc
		) {
	// IP leaveSgeIdle --- IBEGIN
	if (getMastNotSlv()) {
		srcmsdd->align_setSeq(shrdat.seq);
		srcmsdd->setTriggerFps(4.0);
		srcmsdd->trigger_setRng(true, false);
	};
	// IP leaveSgeIdle --- IEND
};

uint JobMsdcActAlign::enterSgeRun(
			DbsMsdc* dbsmsdc
			, const bool reenter
		) {
	uint retval = VecVSge::RUN;
	nextIxVSge = retval;
	// IP enterSgeRun --- INSERT
	return retval;
};

void JobMsdcActAlign::leaveSgeRun(
			DbsMsdc* dbsmsdc
		) {
	// IP leaveSgeRun --- INSERT
};

string JobMsdcActAlign::getSquawk(
			DbsMsdc* dbsmsdc
		) {
	string retval;
	// IP getSquawk --- BEGIN
	retval = VecVSge::getSref(ixVSge);
	// IP getSquawk --- END
	return retval;
};

void JobMsdcActAlign::giveupMaster(
			DbsMsdc* dbsmsdc
			, Msjobinfo* msji
		) {
	// IP giveupMaster --- INSERT
};

void JobMsdcActAlign::giveupSlave(
			DbsMsdc* dbsmsdc
			, Msjobinfo* msji
		) {
	// IP giveupSlave --- INSERT
};

void JobMsdcActAlign::becomeMaster(
			DbsMsdc* dbsmsdc
			, Msjobinfo* msji
		) {
	// IP becomeMaster --- INSERT
};

void JobMsdcActAlign::becomeSlave(
			DbsMsdc* dbsmsdc
			, Msjobinfo* msji
		) {
	// IP becomeSlave --- INSERT
};

bool JobMsdcActAlign::handleClaimMaster(
			DbsMsdc* dbsmsdc
			, Msjobinfo* msji
		) {
	bool retval = !prefmast;
	retval = true; // IP handleClaimMaster --- ILINE
	return retval;
};

void JobMsdcActAlign::handleRequest(
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

	} else if ((req->ixVBasetype == ReqMsdc::VecVBasetype::METHOD) && (req->method->ixVFeatgroup == VecMsdcVFeatgroup::VECVJOBMSDCACTALIGNMETHOD)) {
		uint ixVMethod = VecVMethod::getIx(req->method->srefIxVMethod);

		if ((ixVMethod == VecVMethod::SETWAVE) && (req->method->parsInv.size() == 3) && (req->method->parsRet.size() == 1)) {
			*((bool*) (req->method->parsRet[0])) = setWave(dbsmsdc, *((const uint*) (req->method->parsInv[0])), *((const utinyint*) (req->method->parsInv[1])), *((const vector<float>*) (req->method->parsInv[2])));
		} else if ((ixVMethod == VecVMethod::START) && (req->method->parsInv.size() == 0) && (req->method->parsRet.size() == 1)) {
			*((bool*) (req->method->parsRet[0])) = start(dbsmsdc);
		} else if ((ixVMethod == VecVMethod::STOP) && (req->method->parsInv.size() == 0) && (req->method->parsRet.size() == 1)) {
			*((bool*) (req->method->parsRet[0])) = stop(dbsmsdc);
		};
	};
};

void JobMsdcActAlign::handleCall(
			DbsMsdc* dbsmsdc
			, Call* call
		) {
	if (call->ixVCall == VecMsdcVCall::CALLMSDCMASTSRDCHG) {
		call->abort = handleCallMsdcMastsrdChg(dbsmsdc, call->jref, call->argInv.boolval);
	};
};

bool JobMsdcActAlign::handleCallMsdcMastsrdChg(
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




