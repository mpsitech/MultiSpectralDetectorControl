/**
  * \file PnlMsdcScfAcquis.cpp
  * job handler for job PnlMsdcScfAcquis (implementation)
  * \author Alexander Wirthmueller
  * \date created: 12 Sep 2018
  * \date modified: 12 Sep 2018
  */

#ifdef MSDCCMBD
	#include <Msdccmbd.h>
#else
	#include <Msdcd.h>
#endif

#include "PnlMsdcScfAcquis.h"

#include "PnlMsdcScfAcquis_blks.cpp"

/******************************************************************************
 class PnlMsdcScfAcquis
 ******************************************************************************/

PnlMsdcScfAcquis::PnlMsdcScfAcquis(
			XchgMsdc* xchg
			, DbsMsdc* dbsmsdc
			, const ubigint jrefSup
			, const uint ixMsdcVLocale
		) :
			JobMsdc(xchg, VecMsdcVJob::PNLMSDCSCFACQUIS, jrefSup, ixMsdcVLocale)
		{

	jref = xchg->addJob(this);

	feedFPupVty.tag = "FeedFPupVty";
	VecMsdcVCamtype::appendToFeed(VecMsdcVCamtype::PGBFLY, feedFPupVty);
	VecMsdcVCamtype::appendToFeed(VecMsdcVCamtype::MSLIFE, feedFPupVty);

	acqadxl = NULL;
	acqlwir = NULL;
	acqvisl = NULL;
	acqvisr = NULL;

	// IP constructor.cust1 --- INSERT

	acqadxl = new JobMsdcAcqAdxl(xchg, dbsmsdc, jref, ixMsdcVLocale, true);
	acqlwir = new JobMsdcAcqLwir(xchg, dbsmsdc, jref, ixMsdcVLocale, true);
	acqvisl = new JobMsdcAcqVisl(xchg, dbsmsdc, jref, ixMsdcVLocale, true);
	acqvisr = new JobMsdcAcqVisr(xchg, dbsmsdc, jref, ixMsdcVLocale, true);

	// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	refresh(dbsmsdc, moditems);

	xchg->addClstn(VecMsdcVCall::CALLMSDCMASTSLVCHG, jref, Clstn::VecVJobmask::IMM, 0, Arg(), Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	
};

PnlMsdcScfAcquis::~PnlMsdcScfAcquis() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngMsdc* PnlMsdcScfAcquis::getNewDpchEng(
			set<uint> items
		) {
	DpchEngMsdc* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngMsdcConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &feedFPupVty, items);
	};

	return dpcheng;
};

void PnlMsdcScfAcquis::refresh(
			DbsMsdc* dbsmsdc
			, set<uint>& moditems
		) {
	// IP refresh --- IBEGIN

	// contiac
	ContIac oldContiac(contiac);

	contiac.numFPupVty = feedFPupVty.getNumByIx(acqvisl->stg.ixMsdcVCamtype);
	contiac.TxfVlp = acqvisl->stg.path;
	contiac.TxfVrp = acqvisr->stg.path;

	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	// continf
	ContInf oldContinf(continf);

	continf.ButMasterOn = (xchg->getMsjobMastNotSlv(acqadxl) && xchg->getMsjobMastNotSlv(acqlwir) && xchg->getMsjobMastNotSlv(acqvisl) && xchg->getMsjobMastNotSlv(acqvisr));

	continf.TxtIsn = acqlwir->stg.serno;
	continf.TxtIps = to_string(acqlwir->stg.hpix);
	continf.TxtIfl = to_string(acqlwir->stg.f);
	continf.TxtIfn = to_string(acqlwir->stg.fn);

	continf.TxtVps = to_string(acqvisl->stg.hpix);
	continf.TxtVfl = to_string(acqvisl->stg.f);
	continf.TxtVfn = to_string(acqvisl->stg.fn);

	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	// IP refresh --- IEND
};

void PnlMsdcScfAcquis::handleRequest(
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

		} else if (req->dpchapp->ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCSCFACQUISDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbsmsdc, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCSCFACQUISDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTMASTERCLICK) {
					handleDpchAppDoButMasterClick(dbsmsdc, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlMsdcScfAcquis::handleDpchAppMsdcInit(
			DbsMsdc* dbsmsdc
			, DpchAppMsdcInit* dpchappmsdcinit
			, DpchEngMsdc** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlMsdcScfAcquis::handleDpchAppDataContiac(
			DbsMsdc* dbsmsdc
			, ContIac* _contiac
			, DpchEngMsdc** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);
	// IP handleDpchAppDataContiac --- INSERT
	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlMsdcScfAcquis::handleDpchAppDoButMasterClick(
			DbsMsdc* dbsmsdc
			, DpchEngMsdc** dpcheng
		) {
	// IP handleDpchAppDoButMasterClick --- IBEGIN
	muteRefresh = true;

	if (!xchg->getMsjobMastNotSlv(acqadxl)) xchg->claimMsjobMaster(dbsmsdc, acqadxl->jref);
	if (!xchg->getMsjobMastNotSlv(acqlwir)) xchg->claimMsjobMaster(dbsmsdc, acqlwir->jref);
	if (!xchg->getMsjobMastNotSlv(acqvisl)) xchg->claimMsjobMaster(dbsmsdc, acqvisl->jref);
	if (!xchg->getMsjobMastNotSlv(acqvisr)) xchg->claimMsjobMaster(dbsmsdc, acqvisr->jref);

	refreshWithDpchEng(dbsmsdc, dpcheng);

	muteRefresh = false;
	// IP handleDpchAppDoButMasterClick --- IEND
};

void PnlMsdcScfAcquis::handleCall(
			DbsMsdc* dbsmsdc
			, Call* call
		) {
	if (call->ixVCall == VecMsdcVCall::CALLMSDCMASTSLVCHG) {
		call->abort = handleCallMsdcMastslvChg(dbsmsdc, call->jref);
	};
};

bool PnlMsdcScfAcquis::handleCallMsdcMastslvChg(
			DbsMsdc* dbsmsdc
			, const ubigint jrefTrig
		) {
	bool retval = false;
	if (!muteRefresh) refreshWithDpchEng(dbsmsdc); // IP handleCallMsdcMastslvChg --- ILINE
	return retval;
};



