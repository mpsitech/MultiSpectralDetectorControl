/**
  * \file PnlMsdcScfSource.cpp
  * job handler for job PnlMsdcScfSource (implementation)
  * \author Alexander Wirthmueller
  * \date created: 29 Aug 2018
  * \date modified: 29 Aug 2018
  */

#ifdef MSDCCMBD
	#include <Msdccmbd.h>
#else
	#include <Msdcd.h>
#endif

#include "PnlMsdcScfSource.h"

#include "PnlMsdcScfSource_blks.cpp"

/******************************************************************************
 class PnlMsdcScfSource
 ******************************************************************************/

PnlMsdcScfSource::PnlMsdcScfSource(
			XchgMsdc* xchg
			, DbsMsdc* dbsmsdc
			, const ubigint jrefSup
			, const uint ixMsdcVLocale
		) :
			JobMsdc(xchg, VecMsdcVJob::PNLMSDCSCFSOURCE, jrefSup, ixMsdcVLocale)
		{

	jref = xchg->addJob(this);

	srcmsdd = NULL;
	srctrigger = NULL;

	// IP constructor.cust1 --- INSERT

	srcmsdd = new JobMsdcSrcMsdd(xchg, dbsmsdc, jref, ixMsdcVLocale, true);
	srctrigger = new JobMsdcSrcTrigger(xchg, dbsmsdc, jref, ixMsdcVLocale, true);

	// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	refresh(dbsmsdc, moditems);

	xchg->addClstn(VecMsdcVCall::CALLMSDCMASTSLVCHG, jref, Clstn::VecVJobmask::IMM, 0, Arg(), Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	
};

PnlMsdcScfSource::~PnlMsdcScfSource() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngMsdc* PnlMsdcScfSource::getNewDpchEng(
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

void PnlMsdcScfSource::refresh(
			DbsMsdc* dbsmsdc
			, set<uint>& moditems
		) {
	// IP refresh --- IBEGIN

	// contiac
	ContIac oldContiac(contiac);

	contiac.TxfFpp = srcmsdd->stg.path;
	contiac.SldFxa = srcmsdd->stg.adxlA;
	contiac.SldFa0 = srcmsdd->stg.adxlAlpha0;
	contiac.SldFb0 = srcmsdd->stg.adxlBeta0;
	contiac.UpdFam = srcmsdd->stg.alignMax;
	contiac.SldFsa = srcmsdd->stg.servoA;
	contiac.SldFt0 = srcmsdd->stg.servoTheta0;
	contiac.SldFp0 = srcmsdd->stg.servoPhi0;

	contiac.SldTrp = srctrigger->stg.dt;

	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	// continf
	ContInf oldContinf(continf);

	continf.ButMasterOn = (xchg->getMsjobMastNotSlv(srcmsdd) && xchg->getMsjobMastNotSlv(srctrigger));

	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	// IP refresh --- IEND
};

void PnlMsdcScfSource::handleRequest(
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

		} else if (req->dpchapp->ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCSCFSOURCEDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbsmsdc, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCSCFSOURCEDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTMASTERCLICK) {
					handleDpchAppDoButMasterClick(dbsmsdc, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlMsdcScfSource::handleDpchAppMsdcInit(
			DbsMsdc* dbsmsdc
			, DpchAppMsdcInit* dpchappmsdcinit
			, DpchEngMsdc** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlMsdcScfSource::handleDpchAppDataContiac(
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

void PnlMsdcScfSource::handleDpchAppDoButMasterClick(
			DbsMsdc* dbsmsdc
			, DpchEngMsdc** dpcheng
		) {
	// IP handleDpchAppDoButMasterClick --- IBEGIN
	muteRefresh = true;

	if (!xchg->getMsjobMastNotSlv(srcmsdd)) xchg->claimMsjobMaster(dbsmsdc, srcmsdd->jref);
	if (!xchg->getMsjobMastNotSlv(srctrigger)) xchg->claimMsjobMaster(dbsmsdc, srctrigger->jref);

	refreshWithDpchEng(dbsmsdc, dpcheng);

	muteRefresh = false;
	// IP handleDpchAppDoButMasterClick --- IEND
};

void PnlMsdcScfSource::handleCall(
			DbsMsdc* dbsmsdc
			, Call* call
		) {
	if (call->ixVCall == VecMsdcVCall::CALLMSDCMASTSLVCHG) {
		call->abort = handleCallMsdcMastslvChg(dbsmsdc, call->jref);
	};
};

bool PnlMsdcScfSource::handleCallMsdcMastslvChg(
			DbsMsdc* dbsmsdc
			, const ubigint jrefTrig
		) {
	bool retval = false;
	if (!muteRefresh) refreshWithDpchEng(dbsmsdc); // IP handleCallMsdcMastslvChg --- ILINE
	return retval;
};




