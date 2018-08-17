/**
  * \file PnlMsdcUsrRec.cpp
  * job handler for job PnlMsdcUsrRec (implementation)
  * \author Alexander Wirthmueller
  * \date created: 15 Aug 2018
  * \date modified: 15 Aug 2018
  */

#ifdef MSDCCMBD
	#include <Msdccmbd.h>
#else
	#include <Msdcd.h>
#endif

#include "PnlMsdcUsrRec.h"

#include "PnlMsdcUsrRec_blks.cpp"
#include "PnlMsdcUsrRec_evals.cpp"

/******************************************************************************
 class PnlMsdcUsrRec
 ******************************************************************************/

PnlMsdcUsrRec::PnlMsdcUsrRec(
			XchgMsdc* xchg
			, DbsMsdc* dbsmsdc
			, const ubigint jrefSup
			, const uint ixMsdcVLocale
		) : JobMsdc(xchg, VecMsdcVJob::PNLMSDCUSRREC, jrefSup, ixMsdcVLocale) {

	jref = xchg->addJob(this);

	pnldetail = NULL;
	pnlaaccess = NULL;
	pnl1nsession = NULL;
	pnlmnusergroup = NULL;

	// IP constructor.cust1 --- INSERT

	// IP constructor.cust2 --- INSERT

	// IP constructor.cust3 --- INSERT

	updatePreset(dbsmsdc, VecMsdcVPreset::PREMSDCREFUSR, jref);
	
};

PnlMsdcUsrRec::~PnlMsdcUsrRec() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngMsdc* PnlMsdcUsrRec::getNewDpchEng(
			set<uint> items
		) {
	DpchEngMsdc* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngMsdcConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &continf, &statshr, items);
	};

	return dpcheng;
};

void PnlMsdcUsrRec::refresh(
			DbsMsdc* dbsmsdc
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	// IP refresh --- BEGIN
	// continf
	continf.TxtRef = StubMsdc::getStubUsrStd(dbsmsdc, recUsr.ref, ixMsdcVLocale, Stub::VecVNonetype::FULL);

	// statshr
	if (recUsr.ref == 0) statshr.ixMsdcVExpstate = VecMsdcVExpstate::MIND;

	statshr.ButRegularizeActive = evalButRegularizeActive(dbsmsdc);

	if (statshr.ixMsdcVExpstate == VecMsdcVExpstate::MIND) {
		if (pnldetail) {delete pnldetail; pnldetail = NULL;};
		if (pnlaaccess) {delete pnlaaccess; pnlaaccess = NULL;};
		if (pnl1nsession) {delete pnl1nsession; pnl1nsession = NULL;};
		if (pnlmnusergroup) {delete pnlmnusergroup; pnlmnusergroup = NULL;};
	} else {
		if (!pnldetail) pnldetail = new PnlMsdcUsrDetail(xchg, dbsmsdc, jref, ixMsdcVLocale);
		if (!pnlaaccess) pnlaaccess = new PnlMsdcUsrAAccess(xchg, dbsmsdc, jref, ixMsdcVLocale);
		if (!pnl1nsession) pnl1nsession = new PnlMsdcUsr1NSession(xchg, dbsmsdc, jref, ixMsdcVLocale);
		if (!pnlmnusergroup) pnlmnusergroup = new PnlMsdcUsrMNUsergroup(xchg, dbsmsdc, jref, ixMsdcVLocale);
	};

	statshr.jrefDetail = ((pnldetail) ? pnldetail->jref : 0);
	statshr.jrefAAccess = ((pnlaaccess) ? pnlaaccess->jref : 0);
	statshr.jref1NSession = ((pnl1nsession) ? pnl1nsession->jref : 0);
	statshr.jrefMNUsergroup = ((pnlmnusergroup) ? pnlmnusergroup->jref : 0);

	// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlMsdcUsrRec::updatePreset(
			DbsMsdc* dbsmsdc
			, const uint ixMsdcVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixMsdcVPreset == VecMsdcVPreset::PREMSDCREFUSR) {
		MsdcMUser* _recUsr = NULL;

		if (dbsmsdc->tblmsdcmuser->loadRecByRef(xchg->getRefPreset(VecMsdcVPreset::PREMSDCREFUSR, jref), &_recUsr)) {
			recUsr = *_recUsr;
			delete _recUsr;
		} else recUsr = MsdcMUser();

		if (recUsr.ref != 0) {
			if (pnldetail) pnldetail->updatePreset(dbsmsdc, ixMsdcVPreset, jrefTrig, notif);
			if (pnlaaccess) pnlaaccess->updatePreset(dbsmsdc, ixMsdcVPreset, jrefTrig, notif);
			if (pnl1nsession) pnl1nsession->updatePreset(dbsmsdc, ixMsdcVPreset, jrefTrig, notif);
			if (pnlmnusergroup) pnlmnusergroup->updatePreset(dbsmsdc, ixMsdcVPreset, jrefTrig, notif);
		};

		refresh(dbsmsdc, moditems);
		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlMsdcUsrRec::minimize(
			DbsMsdc* dbsmsdc
			, const bool notif
			, DpchEngMsdc** dpcheng
		) {
	set<uint> moditems;

	if (statshr.ixMsdcVExpstate != VecMsdcVExpstate::MIND) {
		statshr.ixMsdcVExpstate = VecMsdcVExpstate::MIND;
		insert(moditems, DpchEngData::STATSHR);

		refresh(dbsmsdc, moditems);
	};

	if (notif) {
		if (dpcheng) *dpcheng = getNewDpchEng(moditems);
		else if (!moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
};

void PnlMsdcUsrRec::regularize(
			DbsMsdc* dbsmsdc
			, const bool notif
			, DpchEngMsdc** dpcheng
		) {
	set<uint> moditems;

	if (statshr.ixMsdcVExpstate != VecMsdcVExpstate::REGD) {
		statshr.ixMsdcVExpstate = VecMsdcVExpstate::REGD;
		insert(moditems, DpchEngData::STATSHR);

		refresh(dbsmsdc, moditems);
	};

	if (notif) {
		if (dpcheng) *dpcheng = getNewDpchEng(moditems);
		else if (!moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
};

void PnlMsdcUsrRec::handleRequest(
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

		} else if (req->dpchapp->ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCUSRRECDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTMINIMIZECLICK) {
					handleDpchAppDoButMinimizeClick(dbsmsdc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTREGULARIZECLICK) {
					handleDpchAppDoButRegularizeClick(dbsmsdc, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlMsdcUsrRec::handleDpchAppMsdcInit(
			DbsMsdc* dbsmsdc
			, DpchAppMsdcInit* dpchappmsdcinit
			, DpchEngMsdc** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlMsdcUsrRec::handleDpchAppDoButMinimizeClick(
			DbsMsdc* dbsmsdc
			, DpchEngMsdc** dpcheng
		) {
	minimize(dbsmsdc, true, dpcheng);
};

void PnlMsdcUsrRec::handleDpchAppDoButRegularizeClick(
			DbsMsdc* dbsmsdc
			, DpchEngMsdc** dpcheng
		) {
	regularize(dbsmsdc, true, dpcheng);
};

void PnlMsdcUsrRec::handleCall(
			DbsMsdc* dbsmsdc
			, Call* call
		) {
	if (call->ixVCall == VecMsdcVCall::CALLMSDCUSRUPD_REFEQ) {
		call->abort = handleCallMsdcUsrUpd_refEq(dbsmsdc, call->jref, call->argInv.ref);
	};
};

bool PnlMsdcUsrRec::handleCallMsdcUsrUpd_refEq(
			DbsMsdc* dbsmsdc
			, const ubigint jrefTrig
			, const ubigint refInv
		) {
	bool retval = false;
	// IP handleCallMsdcUsrUpd_refEq --- INSERT
	return retval;
};

