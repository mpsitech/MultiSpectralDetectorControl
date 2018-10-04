/**
  * \file CrdMsdcUsg.cpp
  * job handler for job CrdMsdcUsg (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Oct 2018
  * \date modified: 4 Oct 2018
  */

#ifdef MSDCCMBD
	#include <Msdccmbd.h>
#else
	#include <Msdcd.h>
#endif

#include "CrdMsdcUsg.h"

#include "CrdMsdcUsg_blks.cpp"

/******************************************************************************
 class CrdMsdcUsg
 ******************************************************************************/

CrdMsdcUsg::CrdMsdcUsg(
			XchgMsdc* xchg
			, DbsMsdc* dbsmsdc
			, const ubigint jrefSup
			, const uint ixMsdcVLocale
			, const ubigint ref
		) :
			JobMsdc(xchg, VecMsdcVJob::CRDMSDCUSG, jrefSup, ixMsdcVLocale)
		{

	jref = xchg->addJob(this);

	feedFMcbAlert.tag = "FeedFMcbAlert";
	feedFSge.tag = "FeedFSge";
	VecVSge::fillFeed(feedFSge);

	pnlrec = NULL;
	pnlheadbar = NULL;
	pnllist = NULL;

	// IP constructor.cust1 --- INSERT

	// initialize according to ref
	changeRef(dbsmsdc, jref, ((ref+1) == 0) ? 0 : ref, false);

	pnlrec = new PnlMsdcUsgRec(xchg, dbsmsdc, jref, ixMsdcVLocale);
	pnlheadbar = new PnlMsdcUsgHeadbar(xchg, dbsmsdc, jref, ixMsdcVLocale);
	pnllist = new PnlMsdcUsgList(xchg, dbsmsdc, jref, ixMsdcVLocale);

	// IP constructor.cust2 --- INSERT

	statshr.jrefHeadbar = pnlheadbar->jref;
	statshr.jrefList = pnllist->jref;
	statshr.jrefRec = pnlrec->jref;

	changeStage(dbsmsdc, VecVSge::IDLE);

	xchg->addClstn(VecMsdcVCall::CALLMSDCDLGCLOSE, jref, Clstn::VecVJobmask::IMM, 0, Arg(), Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecMsdcVCall::CALLMSDCSTATCHG, jref, Clstn::VecVJobmask::IMM, 0, Arg(), Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecMsdcVCall::CALLMSDCREFPRESET, jref, Clstn::VecVJobmask::TREE, 0, Arg(), Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
	
};

CrdMsdcUsg::~CrdMsdcUsg() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngMsdc* CrdMsdcUsg::getNewDpchEng(
			set<uint> items
		) {
	DpchEngMsdc* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngMsdcConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &continf, &feedFSge, &statshr, items);
	};

	return dpcheng;
};

void CrdMsdcUsg::refresh(
			DbsMsdc* dbsmsdc
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);

	// IP refresh --- BEGIN
	// continf
	continf.MrlAppHlp = xchg->helpurl + "/CrdMsdcUsg/" + VecMsdcVLocale::getSref(ixMsdcVLocale);
	continf.MtxCrdUsg = StubMsdc::getStubUsgStd(dbsmsdc, xchg->getRefPreset(VecMsdcVPreset::PREMSDCREFUSG, jref), ixMsdcVLocale, Stub::VecVNonetype::FULL);

	// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
};

void CrdMsdcUsg::changeRef(
			DbsMsdc* dbsmsdc
			, const ubigint jrefTrig
			, const ubigint ref
			, const bool notif
		) {
	set<uint> moditems;

	uint ixMsdcVRecaccess;
	xchg->triggerIxRefToIxCall(dbsmsdc, VecMsdcVCall::CALLMSDCRECACCESS, jref, VecMsdcVCard::CRDMSDCUSG, ref, ixMsdcVRecaccess);

	if (ixMsdcVRecaccess != VecMsdcVRecaccess::NONE) {
		xchg->addIxPreset(VecMsdcVPreset::PREMSDCIXRECACC, jref, ixMsdcVRecaccess);

		if (ref != 0) xchg->triggerIxRefSrefIntvalCall(dbsmsdc, VecMsdcVCall::CALLMSDCLOG, jref, VecMsdcVPreset::VOID, 0, "CrdMsdcUsg", ref);
		xchg->addRefPreset(VecMsdcVPreset::PREMSDCREFUSG, jref, ref);

		refresh(dbsmsdc, moditems);
		if (notif) xchg->submitDpch(getNewDpchEng(moditems));

		if (pnllist) pnllist->updatePreset(dbsmsdc, VecMsdcVPreset::PREMSDCREFUSG, jrefTrig, notif);
		if (pnlrec) pnlrec->updatePreset(dbsmsdc, VecMsdcVPreset::PREMSDCREFUSG, jrefTrig, notif);
	};
};

void CrdMsdcUsg::updatePreset(
			DbsMsdc* dbsmsdc
			, const uint ixMsdcVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- INSERT
};

void CrdMsdcUsg::changeStage(
			DbsMsdc* dbsmsdc
			, uint _ixVSge
			, DpchEngMsdc** dpcheng
		) {
	bool reenter = true;

	do {
		if (ixVSge != _ixVSge) {
			switch (ixVSge) {
				case VecVSge::IDLE: leaveSgeIdle(dbsmsdc); break;
				case VecVSge::ALRMSDCABT: leaveSgeAlrmsdcabt(dbsmsdc); break;
			};

			setStage(dbsmsdc, _ixVSge);
			reenter = false;
			if (!muteRefresh) refreshWithDpchEng(dbsmsdc, dpcheng); // IP changeStage.refresh1 --- LINE
		};

		switch (_ixVSge) {
			case VecVSge::IDLE: _ixVSge = enterSgeIdle(dbsmsdc, reenter); break;
			case VecVSge::ALRMSDCABT: _ixVSge = enterSgeAlrmsdcabt(dbsmsdc, reenter); break;
		};

		// IP changeStage.refresh2 --- INSERT
	} while (ixVSge != _ixVSge);
};

uint CrdMsdcUsg::enterSgeIdle(
			DbsMsdc* dbsmsdc
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;
	nextIxVSge = retval;
	// IP enterSgeIdle --- INSERT
	return retval;
};

void CrdMsdcUsg::leaveSgeIdle(
			DbsMsdc* dbsmsdc
		) {
	// IP leaveSgeIdle --- INSERT
};

uint CrdMsdcUsg::enterSgeAlrmsdcabt(
			DbsMsdc* dbsmsdc
			, const bool reenter
		) {
	uint retval = VecVSge::ALRMSDCABT;
	nextIxVSge = VecVSge::IDLE;
	xchg->submitDpch(AlrMsdc::prepareAlrAbt(jref, ixMsdcVLocale, feedFMcbAlert)); // IP enterSgeAlrmsdcabt --- LINE
	return retval;
};

void CrdMsdcUsg::leaveSgeAlrmsdcabt(
			DbsMsdc* dbsmsdc
		) {
	// IP leaveSgeAlrmsdcabt --- INSERT
};

string CrdMsdcUsg::getSquawk(
			DbsMsdc* dbsmsdc
		) {
	string retval;
	// IP getSquawk --- BEGIN
	retval = VecVSge::getSref(ixVSge);
	// IP getSquawk --- END
	return retval;
};

void CrdMsdcUsg::handleRequest(
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

		} else if (req->dpchapp->ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCUSGDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::CLOSE) {
					handleDpchAppDoClose(dbsmsdc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITAPPABTCLICK) {
					handleDpchAppDoMitAppAbtClick(dbsmsdc, &(req->dpcheng));
				};

			};

		} else if (req->dpchapp->ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCALERT) {
			handleDpchAppMsdcAlert(dbsmsdc, (DpchAppMsdcAlert*) (req->dpchapp), &(req->dpcheng));

		};
	};
};

void CrdMsdcUsg::handleDpchAppMsdcInit(
			DbsMsdc* dbsmsdc
			, DpchAppMsdcInit* dpchappmsdcinit
			, DpchEngMsdc** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void CrdMsdcUsg::handleDpchAppDoClose(
			DbsMsdc* dbsmsdc
			, DpchEngMsdc** dpcheng
		) {
	muteRefresh = true;

	*dpcheng = new DpchEngMsdcConfirm(true, jref, "");
	xchg->triggerIxCall(dbsmsdc, VecMsdcVCall::CALLMSDCCRDCLOSE, jref, VecMsdcVCard::CRDMSDCUSG);
};

void CrdMsdcUsg::handleDpchAppDoMitAppAbtClick(
			DbsMsdc* dbsmsdc
			, DpchEngMsdc** dpcheng
		) {
	// IP handleDpchAppDoMitAppAbtClick --- BEGIN
	changeStage(dbsmsdc, VecVSge::ALRMSDCABT, dpcheng);
	// IP handleDpchAppDoMitAppAbtClick --- END
};

void CrdMsdcUsg::handleDpchAppMsdcAlert(
			DbsMsdc* dbsmsdc
			, DpchAppMsdcAlert* dpchappmsdcalert
			, DpchEngMsdc** dpcheng
		) {
	if (ixVSge == VecVSge::ALRMSDCABT) {
		changeStage(dbsmsdc, VecVSge::IDLE);
	};

	*dpcheng = new DpchEngMsdcConfirm(true, jref, "");
};

void CrdMsdcUsg::handleCall(
			DbsMsdc* dbsmsdc
			, Call* call
		) {
	if (call->ixVCall == VecMsdcVCall::CALLMSDCDLGCLOSE) {
		call->abort = handleCallMsdcDlgClose(dbsmsdc, call->jref);
	} else if (call->ixVCall == VecMsdcVCall::CALLMSDCSTATCHG) {
		call->abort = handleCallMsdcStatChg(dbsmsdc, call->jref);
	} else if (call->ixVCall == VecMsdcVCall::CALLMSDCREFPRESET) {
		call->abort = handleCallMsdcRefPreSet(dbsmsdc, call->jref, call->argInv.ix, call->argInv.ref);
	};
};

bool CrdMsdcUsg::handleCallMsdcDlgClose(
			DbsMsdc* dbsmsdc
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallMsdcDlgClose --- INSERT
	return retval;
};

bool CrdMsdcUsg::handleCallMsdcStatChg(
			DbsMsdc* dbsmsdc
			, const ubigint jrefTrig
		) {
	bool retval = false;
	if (jrefTrig == pnlrec->jref) if ((pnllist->statshr.ixMsdcVExpstate == VecMsdcVExpstate::REGD) && (pnlrec->statshr.ixMsdcVExpstate == VecMsdcVExpstate::REGD)) pnllist->minimize(dbsmsdc, true);
	return retval;
};

bool CrdMsdcUsg::handleCallMsdcRefPreSet(
			DbsMsdc* dbsmsdc
			, const ubigint jrefTrig
			, const uint ixInv
			, const ubigint refInv
		) {
	bool retval = false;

	if (ixInv == VecMsdcVPreset::PREMSDCREFUSG) {
		changeRef(dbsmsdc, jrefTrig, refInv, true);

		if (refInv == 0) pnlrec->minimize(dbsmsdc, true);
	};

	return retval;
};

