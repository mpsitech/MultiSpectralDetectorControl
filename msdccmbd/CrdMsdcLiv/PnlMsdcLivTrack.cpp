/**
  * \file PnlMsdcLivTrack.cpp
  * job handler for job PnlMsdcLivTrack (implementation)
  * \author Alexander Wirthmueller
  * \date created: 15 Aug 2018
  * \date modified: 15 Aug 2018
  */

#ifdef MSDCCMBD
	#include <Msdccmbd.h>
#else
	#include <Msdcd.h>
#endif

#include "PnlMsdcLivTrack.h"

#include "PnlMsdcLivTrack_blks.cpp"

/******************************************************************************
 class PnlMsdcLivTrack
 ******************************************************************************/

PnlMsdcLivTrack::PnlMsdcLivTrack(
			XchgMsdc* xchg
			, DbsMsdc* dbsmsdc
			, const ubigint jrefSup
			, const uint ixMsdcVLocale
		) : JobMsdc(xchg, VecMsdcVJob::PNLMSDCLIVTRACK, jrefSup, ixMsdcVLocale) {

	jref = xchg->addJob(this);

	prctrack = NULL;

	// IP constructor.cust1 --- INSERT

	prctrack = new JobMsdcPrcTrack(xchg, dbsmsdc, jref, ixMsdcVLocale, true);

	// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	refresh(dbsmsdc, moditems);

	xchg->addClstn(VecMsdcVCall::CALLMSDCMASTSLVCHG, jref, Clstn::VecVJobmask::IMM, 0, Arg(), Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecMsdcVCall::CALLMSDCSGECHG, jref, Clstn::VecVJobmask::IMM, 0, Arg(), Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	
};

PnlMsdcLivTrack::~PnlMsdcLivTrack() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngMsdc* PnlMsdcLivTrack::getNewDpchEng(
			set<uint> items
		) {
	DpchEngMsdc* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngMsdcConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &continf, items);
	};

	return dpcheng;
};

void PnlMsdcLivTrack::refresh(
			DbsMsdc* dbsmsdc
			, set<uint>& moditems
		) {
	// IP refresh --- IBEGIN
	// continf
	ContInf oldContinf(continf);

	continf.ButMasterOn = xchg->getMsjobMastNotSlv(prctrack);

	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	// IP refresh --- IEND
};

void PnlMsdcLivTrack::handleRequest(
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

		} else if (req->dpchapp->ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCLIVTRACKDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTMASTERCLICK) {
					handleDpchAppDoButMasterClick(dbsmsdc, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlMsdcLivTrack::handleDpchAppMsdcInit(
			DbsMsdc* dbsmsdc
			, DpchAppMsdcInit* dpchappmsdcinit
			, DpchEngMsdc** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlMsdcLivTrack::handleDpchAppDoButMasterClick(
			DbsMsdc* dbsmsdc
			, DpchEngMsdc** dpcheng
		) {
	// IP handleDpchAppDoButMasterClick --- IBEGIN
	muteRefresh = true;

	if (!xchg->getMsjobMastNotSlv(prctrack)) xchg->claimMsjobMaster(dbsmsdc, prctrack->jref);

	refreshWithDpchEng(dbsmsdc, dpcheng);

	muteRefresh = false;
	// IP handleDpchAppDoButMasterClick --- IEND
};

void PnlMsdcLivTrack::handleCall(
			DbsMsdc* dbsmsdc
			, Call* call
		) {
	if (call->ixVCall == VecMsdcVCall::CALLMSDCMASTSLVCHG) {
		call->abort = handleCallMsdcMastslvChg(dbsmsdc, call->jref);
	} else if (call->ixVCall == VecMsdcVCall::CALLMSDCSGECHG) {
		call->abort = handleCallMsdcSgeChg(dbsmsdc, call->jref);
	};
};

bool PnlMsdcLivTrack::handleCallMsdcMastslvChg(
			DbsMsdc* dbsmsdc
			, const ubigint jrefTrig
		) {
	bool retval = false;
	if (!muteRefresh) refreshWithDpchEng(dbsmsdc); // IP handleCallMsdcMastslvChg --- ILINE
	return retval;
};

bool PnlMsdcLivTrack::handleCallMsdcSgeChg(
			DbsMsdc* dbsmsdc
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallMsdcSgeChg --- IBEGIN
	set<uint> moditems;

	if (!muteRefresh) {
		refresh(dbsmsdc, moditems);
		if (!moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP handleCallMsdcSgeChg --- IEND
	return retval;
};




