/**
  * \file PnlMsdcUsgRec.cpp
  * job handler for job PnlMsdcUsgRec (implementation)
  * \author Alexander Wirthmueller
  * \date created: 29 Aug 2018
  * \date modified: 29 Aug 2018
  */

#ifdef MSDCCMBD
	#include <Msdccmbd.h>
#else
	#include <Msdcd.h>
#endif

#include "PnlMsdcUsgRec.h"

#include "PnlMsdcUsgRec_blks.cpp"
#include "PnlMsdcUsgRec_evals.cpp"

/******************************************************************************
 class PnlMsdcUsgRec
 ******************************************************************************/

PnlMsdcUsgRec::PnlMsdcUsgRec(
			XchgMsdc* xchg
			, DbsMsdc* dbsmsdc
			, const ubigint jrefSup
			, const uint ixMsdcVLocale
		) :
			JobMsdc(xchg, VecMsdcVJob::PNLMSDCUSGREC, jrefSup, ixMsdcVLocale)
		{

	jref = xchg->addJob(this);

	pnldetail = NULL;
	pnlaaccess = NULL;
	pnlmnuser = NULL;

	// IP constructor.cust1 --- INSERT

	// IP constructor.cust2 --- INSERT

	// IP constructor.cust3 --- INSERT

	updatePreset(dbsmsdc, VecMsdcVPreset::PREMSDCREFUSG, jref);
	
};

PnlMsdcUsgRec::~PnlMsdcUsgRec() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngMsdc* PnlMsdcUsgRec::getNewDpchEng(
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

void PnlMsdcUsgRec::refresh(
			DbsMsdc* dbsmsdc
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	// IP refresh --- BEGIN
	// continf
	continf.TxtRef = StubMsdc::getStubUsgStd(dbsmsdc, recUsg.ref, ixMsdcVLocale, Stub::VecVNonetype::FULL);

	// statshr
	if (recUsg.ref == 0) statshr.ixMsdcVExpstate = VecMsdcVExpstate::MIND;

	statshr.ButRegularizeActive = evalButRegularizeActive(dbsmsdc);

	if (statshr.ixMsdcVExpstate == VecMsdcVExpstate::MIND) {
		if (pnldetail) {delete pnldetail; pnldetail = NULL;};
		if (pnlaaccess) {delete pnlaaccess; pnlaaccess = NULL;};
		if (pnlmnuser) {delete pnlmnuser; pnlmnuser = NULL;};
	} else {
		if (!pnldetail) pnldetail = new PnlMsdcUsgDetail(xchg, dbsmsdc, jref, ixMsdcVLocale);
		if (!pnlaaccess) pnlaaccess = new PnlMsdcUsgAAccess(xchg, dbsmsdc, jref, ixMsdcVLocale);
		if (!pnlmnuser) pnlmnuser = new PnlMsdcUsgMNUser(xchg, dbsmsdc, jref, ixMsdcVLocale);
	};

	statshr.jrefDetail = ((pnldetail) ? pnldetail->jref : 0);
	statshr.jrefAAccess = ((pnlaaccess) ? pnlaaccess->jref : 0);
	statshr.jrefMNUser = ((pnlmnuser) ? pnlmnuser->jref : 0);

	// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlMsdcUsgRec::updatePreset(
			DbsMsdc* dbsmsdc
			, const uint ixMsdcVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixMsdcVPreset == VecMsdcVPreset::PREMSDCREFUSG) {
		MsdcMUsergroup* _recUsg = NULL;

		if (dbsmsdc->tblmsdcmusergroup->loadRecByRef(xchg->getRefPreset(VecMsdcVPreset::PREMSDCREFUSG, jref), &_recUsg)) {
			recUsg = *_recUsg;
			delete _recUsg;
		} else recUsg = MsdcMUsergroup();

		if (recUsg.ref != 0) {
			if (pnldetail) pnldetail->updatePreset(dbsmsdc, ixMsdcVPreset, jrefTrig, notif);
			if (pnlaaccess) pnlaaccess->updatePreset(dbsmsdc, ixMsdcVPreset, jrefTrig, notif);
			if (pnlmnuser) pnlmnuser->updatePreset(dbsmsdc, ixMsdcVPreset, jrefTrig, notif);
		};

		refresh(dbsmsdc, moditems);
		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlMsdcUsgRec::minimize(
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

void PnlMsdcUsgRec::regularize(
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

void PnlMsdcUsgRec::handleRequest(
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

		} else if (req->dpchapp->ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCUSGRECDO) {
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

void PnlMsdcUsgRec::handleDpchAppMsdcInit(
			DbsMsdc* dbsmsdc
			, DpchAppMsdcInit* dpchappmsdcinit
			, DpchEngMsdc** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlMsdcUsgRec::handleDpchAppDoButMinimizeClick(
			DbsMsdc* dbsmsdc
			, DpchEngMsdc** dpcheng
		) {
	minimize(dbsmsdc, true, dpcheng);
};

void PnlMsdcUsgRec::handleDpchAppDoButRegularizeClick(
			DbsMsdc* dbsmsdc
			, DpchEngMsdc** dpcheng
		) {
	regularize(dbsmsdc, true, dpcheng);
};

void PnlMsdcUsgRec::handleCall(
			DbsMsdc* dbsmsdc
			, Call* call
		) {
	if (call->ixVCall == VecMsdcVCall::CALLMSDCUSGUPD_REFEQ) {
		call->abort = handleCallMsdcUsgUpd_refEq(dbsmsdc, call->jref, call->argInv.ref);
	};
};

bool PnlMsdcUsgRec::handleCallMsdcUsgUpd_refEq(
			DbsMsdc* dbsmsdc
			, const ubigint jrefTrig
			, const ubigint refInv
		) {
	bool retval = false;
	// IP handleCallMsdcUsgUpd_refEq --- INSERT
	return retval;
};

