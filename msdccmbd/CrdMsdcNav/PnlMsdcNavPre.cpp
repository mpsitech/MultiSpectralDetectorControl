/**
  * \file PnlMsdcNavPre.cpp
  * job handler for job PnlMsdcNavPre (implementation)
  * \author Alexander Wirthmueller
  * \date created: 12 Sep 2018
  * \date modified: 12 Sep 2018
  */

#ifdef MSDCCMBD
	#include <Msdccmbd.h>
#else
	#include <Msdcd.h>
#endif

#include "PnlMsdcNavPre.h"

#include "PnlMsdcNavPre_blks.cpp"
#include "PnlMsdcNavPre_evals.cpp"

/******************************************************************************
 class PnlMsdcNavPre
 ******************************************************************************/

PnlMsdcNavPre::PnlMsdcNavPre(
			XchgMsdc* xchg
			, DbsMsdc* dbsmsdc
			, const ubigint jrefSup
			, const uint ixMsdcVLocale
		) :
			JobMsdc(xchg, VecMsdcVJob::PNLMSDCNAVPRE, jrefSup, ixMsdcVLocale)
		{

	jref = xchg->addJob(this);

	// IP constructor.cust1 --- INSERT

	// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	refresh(dbsmsdc, moditems);

	// IP constructor.cust3 --- INSERT

	
};

PnlMsdcNavPre::~PnlMsdcNavPre() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngMsdc* PnlMsdcNavPre::getNewDpchEng(
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

void PnlMsdcNavPre::refresh(
			DbsMsdc* dbsmsdc
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	// IP refresh --- BEGIN
	// continf
	continf.TxtDat = StubMsdc::getStubDatStd(dbsmsdc, xchg->getRefPreset(VecMsdcVPreset::PREMSDCREFDAT, jref), ixMsdcVLocale);
	continf.TxtPrd = StubMsdc::getStubPrdStd(dbsmsdc, xchg->getRefPreset(VecMsdcVPreset::PREMSDCREFPRD, jref), ixMsdcVLocale);

	// statshr
	statshr.TxtDatAvail = evalTxtDatAvail(dbsmsdc);
	statshr.TxtPrdAvail = evalTxtPrdAvail(dbsmsdc);

	// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlMsdcNavPre::updatePreset(
			DbsMsdc* dbsmsdc
			, const uint ixMsdcVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	refresh(dbsmsdc, moditems);

	if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	// IP updatePreset --- END
};

void PnlMsdcNavPre::handleRequest(
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

		} else if (req->dpchapp->ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCNAVPREDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTDATREMOVECLICK) {
					handleDpchAppDoButDatRemoveClick(dbsmsdc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTPRDREMOVECLICK) {
					handleDpchAppDoButPrdRemoveClick(dbsmsdc, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlMsdcNavPre::handleDpchAppMsdcInit(
			DbsMsdc* dbsmsdc
			, DpchAppMsdcInit* dpchappmsdcinit
			, DpchEngMsdc** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlMsdcNavPre::handleDpchAppDoButDatRemoveClick(
			DbsMsdc* dbsmsdc
			, DpchEngMsdc** dpcheng
		) {
	set<uint> moditems;

	xchg->triggerIxRefCall(dbsmsdc, VecMsdcVCall::CALLMSDCREFPRESET, jref, VecMsdcVPreset::PREMSDCREFDAT, 0);

	refresh(dbsmsdc, moditems);

	*dpcheng = getNewDpchEng(moditems);
};

void PnlMsdcNavPre::handleDpchAppDoButPrdRemoveClick(
			DbsMsdc* dbsmsdc
			, DpchEngMsdc** dpcheng
		) {
	set<uint> moditems;

	xchg->triggerIxRefCall(dbsmsdc, VecMsdcVCall::CALLMSDCREFPRESET, jref, VecMsdcVPreset::PREMSDCREFPRD, 0);

	refresh(dbsmsdc, moditems);

	*dpcheng = getNewDpchEng(moditems);
};

