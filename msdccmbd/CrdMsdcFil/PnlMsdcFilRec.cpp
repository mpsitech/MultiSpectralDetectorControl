/**
  * \file PnlMsdcFilRec.cpp
  * job handler for job PnlMsdcFilRec (implementation)
  * \author Alexander Wirthmueller
  * \date created: 12 Sep 2018
  * \date modified: 12 Sep 2018
  */

#ifdef MSDCCMBD
	#include <Msdccmbd.h>
#else
	#include <Msdcd.h>
#endif

#include "PnlMsdcFilRec.h"

#include "PnlMsdcFilRec_blks.cpp"
#include "PnlMsdcFilRec_evals.cpp"

/******************************************************************************
 class PnlMsdcFilRec
 ******************************************************************************/

PnlMsdcFilRec::PnlMsdcFilRec(
			XchgMsdc* xchg
			, DbsMsdc* dbsmsdc
			, const ubigint jrefSup
			, const uint ixMsdcVLocale
		) :
			JobMsdc(xchg, VecMsdcVJob::PNLMSDCFILREC, jrefSup, ixMsdcVLocale)
		{

	jref = xchg->addJob(this);

	pnldetail = NULL;

	// IP constructor.cust1 --- INSERT

	// IP constructor.cust2 --- INSERT

	// IP constructor.cust3 --- INSERT

	updatePreset(dbsmsdc, VecMsdcVPreset::PREMSDCREFFIL, jref);
	
};

PnlMsdcFilRec::~PnlMsdcFilRec() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngMsdc* PnlMsdcFilRec::getNewDpchEng(
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

void PnlMsdcFilRec::refresh(
			DbsMsdc* dbsmsdc
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	// IP refresh --- BEGIN
	// continf
	continf.TxtRef = StubMsdc::getStubFilStd(dbsmsdc, recFil.ref, ixMsdcVLocale, Stub::VecVNonetype::FULL);

	// statshr
	if (recFil.ref == 0) statshr.ixMsdcVExpstate = VecMsdcVExpstate::MIND;

	statshr.ButRegularizeActive = evalButRegularizeActive(dbsmsdc);

	if (statshr.ixMsdcVExpstate == VecMsdcVExpstate::MIND) {
		if (pnldetail) {delete pnldetail; pnldetail = NULL;};
	} else {
		if (!pnldetail) pnldetail = new PnlMsdcFilDetail(xchg, dbsmsdc, jref, ixMsdcVLocale);
	};

	statshr.jrefDetail = ((pnldetail) ? pnldetail->jref : 0);

	// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlMsdcFilRec::updatePreset(
			DbsMsdc* dbsmsdc
			, const uint ixMsdcVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixMsdcVPreset == VecMsdcVPreset::PREMSDCREFFIL) {
		MsdcMFile* _recFil = NULL;

		if (dbsmsdc->tblmsdcmfile->loadRecByRef(xchg->getRefPreset(VecMsdcVPreset::PREMSDCREFFIL, jref), &_recFil)) {
			recFil = *_recFil;
			delete _recFil;
		} else recFil = MsdcMFile();

		if (recFil.ref != 0) {
			if (pnldetail) pnldetail->updatePreset(dbsmsdc, ixMsdcVPreset, jrefTrig, notif);
		};

		refresh(dbsmsdc, moditems);
		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlMsdcFilRec::minimize(
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

void PnlMsdcFilRec::regularize(
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

void PnlMsdcFilRec::handleRequest(
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

		} else if (req->dpchapp->ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCFILRECDO) {
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

void PnlMsdcFilRec::handleDpchAppMsdcInit(
			DbsMsdc* dbsmsdc
			, DpchAppMsdcInit* dpchappmsdcinit
			, DpchEngMsdc** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlMsdcFilRec::handleDpchAppDoButMinimizeClick(
			DbsMsdc* dbsmsdc
			, DpchEngMsdc** dpcheng
		) {
	minimize(dbsmsdc, true, dpcheng);
};

void PnlMsdcFilRec::handleDpchAppDoButRegularizeClick(
			DbsMsdc* dbsmsdc
			, DpchEngMsdc** dpcheng
		) {
	regularize(dbsmsdc, true, dpcheng);
};

void PnlMsdcFilRec::handleCall(
			DbsMsdc* dbsmsdc
			, Call* call
		) {
	if (call->ixVCall == VecMsdcVCall::CALLMSDCFILUPD_REFEQ) {
		call->abort = handleCallMsdcFilUpd_refEq(dbsmsdc, call->jref, call->argInv.ref);
	};
};

bool PnlMsdcFilRec::handleCallMsdcFilUpd_refEq(
			DbsMsdc* dbsmsdc
			, const ubigint jrefTrig
			, const ubigint refInv
		) {
	bool retval = false;
	// IP handleCallMsdcFilUpd_refEq --- INSERT
	return retval;
};

