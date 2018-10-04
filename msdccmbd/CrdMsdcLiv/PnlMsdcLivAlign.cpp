/**
  * \file PnlMsdcLivAlign.cpp
  * job handler for job PnlMsdcLivAlign (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Oct 2018
  * \date modified: 4 Oct 2018
  */

#ifdef MSDCCMBD
	#include <Msdccmbd.h>
#else
	#include <Msdcd.h>
#endif

#include "PnlMsdcLivAlign.h"

#include "PnlMsdcLivAlign_blks.cpp"
#include "PnlMsdcLivAlign_evals.cpp"

/******************************************************************************
 class PnlMsdcLivAlign
 ******************************************************************************/

PnlMsdcLivAlign::PnlMsdcLivAlign(
			XchgMsdc* xchg
			, DbsMsdc* dbsmsdc
			, const ubigint jrefSup
			, const uint ixMsdcVLocale
		) :
			JobMsdc(xchg, VecMsdcVJob::PNLMSDCLIVALIGN, jrefSup, ixMsdcVLocale)
		{

	jref = xchg->addJob(this);

	acqadxl = NULL;
	actservo = NULL;
	actalign = NULL;

	// IP constructor.cust1 --- INSERT

	acqadxl = new JobMsdcAcqAdxl(xchg, dbsmsdc, jref, ixMsdcVLocale, true);
	actservo = new JobMsdcActServo(xchg, dbsmsdc, jref, ixMsdcVLocale, true);
	actalign = new JobMsdcActAlign(xchg, dbsmsdc, jref, ixMsdcVLocale, true);

	// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	refresh(dbsmsdc, moditems);

	xchg->addClstn(VecMsdcVCall::CALLMSDCMASTSLVCHG, jref, Clstn::VecVJobmask::IMM, 0, Arg(), Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecMsdcVCall::CALLMSDCSHRDATCHG, jref, Clstn::VecVJobmask::IMM, 0, Arg(), Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- IBEGIN
//	acqadxl->start(dbsmsdc);
//	actalign->start(dbsmsdc);
	// IP constructor.cust3 --- IEND

	
};

PnlMsdcLivAlign::~PnlMsdcLivAlign() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngMsdc* PnlMsdcLivAlign::getNewDpchEng(
			set<uint> items
		) {
	DpchEngMsdc* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngMsdcConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &statshr, items);
	};

	return dpcheng;
};

void PnlMsdcLivAlign::refresh(
			DbsMsdc* dbsmsdc
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	// IP refresh --- RBEGIN
	// contiac
	ContIac oldContiac(contiac);

	contiac.SldThe = actservo->shrdat.theta;
	contiac.SldPhi = actservo->shrdat.phi;

	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	// continf
	ContInf oldContinf(continf);

	continf.ButMasterOn = (xchg->getMsjobMastNotSlv(actservo) && xchg->getMsjobMastNotSlv(actalign));

	continf.TxtAph = to_string(acqadxl->shrdat.alpha);
	continf.TxtBta = to_string(acqadxl->shrdat.beta);

	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);

	// statshr
	statshr.SldTheActive = evalSldTheActive(dbsmsdc);
	statshr.SldPhiActive = evalSldPhiActive(dbsmsdc);
	// IP refresh --- REND

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlMsdcLivAlign::handleRequest(
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

		} else if (req->dpchapp->ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCLIVALIGNDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbsmsdc, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCLIVALIGNDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTMASTERCLICK) {
					handleDpchAppDoButMasterClick(dbsmsdc, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlMsdcLivAlign::handleDpchAppMsdcInit(
			DbsMsdc* dbsmsdc
			, DpchAppMsdcInit* dpchappmsdcinit
			, DpchEngMsdc** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlMsdcLivAlign::handleDpchAppDataContiac(
			DbsMsdc* dbsmsdc
			, ContIac* _contiac
			, DpchEngMsdc** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);
	// IP handleDpchAppDataContiac --- IBEGIN

	muteRefresh = true;

	if (has(diffitems, ContIac::SLDTHE)) {
		contiac.SldThe = _contiac->SldThe;
		actservo->setTheta(dbsmsdc, contiac.SldThe);
	};

	if (has(diffitems, ContIac::SLDPHI)) {
		contiac.SldPhi = _contiac->SldPhi;
		actservo->setPhi(dbsmsdc, contiac.SldPhi);
	};

	muteRefresh = false;

	refresh(dbsmsdc, moditems);

	// IP handleDpchAppDataContiac --- IEND
	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlMsdcLivAlign::handleDpchAppDoButMasterClick(
			DbsMsdc* dbsmsdc
			, DpchEngMsdc** dpcheng
		) {
	// IP handleDpchAppDoButMasterClick --- IBEGIN
	muteRefresh = true;

	if (!xchg->getMsjobMastNotSlv(actservo)) xchg->claimMsjobMaster(dbsmsdc, actservo->jref);
	if (!xchg->getMsjobMastNotSlv(actalign)) xchg->claimMsjobMaster(dbsmsdc, actalign->jref);

///
	acqadxl->start(dbsmsdc);
	actalign->start(dbsmsdc);

	refreshWithDpchEng(dbsmsdc, dpcheng);

	muteRefresh = false;
	// IP handleDpchAppDoButMasterClick --- IEND
};

void PnlMsdcLivAlign::handleCall(
			DbsMsdc* dbsmsdc
			, Call* call
		) {
	if (call->ixVCall == VecMsdcVCall::CALLMSDCMASTSLVCHG) {
		call->abort = handleCallMsdcMastslvChg(dbsmsdc, call->jref);
	} else if (call->ixVCall == VecMsdcVCall::CALLMSDCSHRDATCHG) {
		call->abort = handleCallMsdcShrdatChg(dbsmsdc, call->jref, call->argInv.ix, call->argInv.sref);
	};
};

bool PnlMsdcLivAlign::handleCallMsdcMastslvChg(
			DbsMsdc* dbsmsdc
			, const ubigint jrefTrig
		) {
	bool retval = false;
	if (!muteRefresh) refreshWithDpchEng(dbsmsdc); // IP handleCallMsdcMastslvChg --- ILINE
	return retval;
};

bool PnlMsdcLivAlign::handleCallMsdcShrdatChg(
			DbsMsdc* dbsmsdc
			, const ubigint jrefTrig
			, const uint ixInv
			, const string& srefInv
		) {
	bool retval = false;
	// IP handleCallMsdcShrdatChg --- IBEGIN
	set<uint> moditems;

	if (!muteRefresh) {
		refresh(dbsmsdc, moditems);
		if (!moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP handleCallMsdcShrdatChg --- IEND
	return retval;
};




