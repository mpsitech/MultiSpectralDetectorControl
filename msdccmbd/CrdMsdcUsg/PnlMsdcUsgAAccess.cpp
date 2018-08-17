/**
  * \file PnlMsdcUsgAAccess.cpp
  * job handler for job PnlMsdcUsgAAccess (implementation)
  * \author Alexander Wirthmueller
  * \date created: 15 Aug 2018
  * \date modified: 15 Aug 2018
  */

#ifdef MSDCCMBD
	#include <Msdccmbd.h>
#else
	#include <Msdcd.h>
#endif

#include "PnlMsdcUsgAAccess.h"

#include "PnlMsdcUsgAAccess_blks.cpp"
#include "PnlMsdcUsgAAccess_evals.cpp"

/******************************************************************************
 class PnlMsdcUsgAAccess
 ******************************************************************************/

PnlMsdcUsgAAccess::PnlMsdcUsgAAccess(
			XchgMsdc* xchg
			, DbsMsdc* dbsmsdc
			, const ubigint jrefSup
			, const uint ixMsdcVLocale
		) : JobMsdc(xchg, VecMsdcVJob::PNLMSDCUSGAACCESS, jrefSup, ixMsdcVLocale) {

	jref = xchg->addJob(this);

	feedFCsiQst.tag = "FeedFCsiQst";
	feedFCsiQst.appendIxSrefTitles(VecMsdcVQrystate::MNR, "ong", VecMsdcVQrystate::getTitle(VecMsdcVQrystate::MNR, ixMsdcVLocale));
	feedFCsiQst.appendIxSrefTitles(VecMsdcVQrystate::OOD, "red", VecMsdcVQrystate::getTitle(VecMsdcVQrystate::OOD, ixMsdcVLocale));
	feedFCsiQst.appendIxSrefTitles(VecMsdcVQrystate::SLM, "yel", VecMsdcVQrystate::getTitle(VecMsdcVQrystate::SLM, ixMsdcVLocale));
	feedFCsiQst.appendIxSrefTitles(VecMsdcVQrystate::UTD, "grn", VecMsdcVQrystate::getTitle(VecMsdcVQrystate::UTD, ixMsdcVLocale));

	qry = NULL;

	// IP constructor.cust1 --- INSERT

	xchg->addRefPreset(VecMsdcVPreset::PREMSDCREFSEL, jref, 0);

	qry = new QryMsdcUsgAAccess(xchg, dbsmsdc, jref, ixMsdcVLocale);

	// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	refresh(dbsmsdc, moditems);

	xchg->addClstn(VecMsdcVCall::CALLMSDCSTATCHG, jref, Clstn::VecVJobmask::IMM, 0, Arg(), Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	
};

PnlMsdcUsgAAccess::~PnlMsdcUsgAAccess() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngMsdc* PnlMsdcUsgAAccess::getNewDpchEng(
			set<uint> items
		) {
	DpchEngMsdc* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngMsdcConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &continf, &feedFCsiQst, &statshr, &stgiac, &(qry->rst), &(qry->statshr), &(qry->stgiac), items);
	};

	return dpcheng;
};

void PnlMsdcUsgAAccess::refresh(
			DbsMsdc* dbsmsdc
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	// IP refresh --- BEGIN
	// continf
	continf.numFCsiQst = feedFCsiQst.getNumByIx(qry->ixMsdcVQrystate);

	// statshr
	statshr.ButNewAvail = evalButNewAvail(dbsmsdc);
	statshr.ButDuplicateAvail = evalButDuplicateAvail(dbsmsdc);
	statshr.ButDuplicateActive = evalButDuplicateActive(dbsmsdc);
	statshr.ButDeleteAvail = evalButDeleteAvail(dbsmsdc);
	statshr.ButDeleteActive = evalButDeleteActive(dbsmsdc);

	// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlMsdcUsgAAccess::updatePreset(
			DbsMsdc* dbsmsdc
			, const uint ixMsdcVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixMsdcVPreset == VecMsdcVPreset::PREMSDCREFUSG) {
		recUsgAacc = MsdcAMUsergroupAccess();

		xchg->addRefPreset(VecMsdcVPreset::PREMSDCREFSEL, jref, 0);

		qry->stgiac.jnumFirstload = 1;

		qry->rerun(dbsmsdc);
		refresh(dbsmsdc, moditems);

		if (notif) {
			insert(moditems, {DpchEngData::STATSHRQRY, DpchEngData::STGIACQRY, DpchEngData::RST});
			xchg->submitDpch(getNewDpchEng(moditems));
		};
	};
	// IP updatePreset --- END
};

void PnlMsdcUsgAAccess::handleRequest(
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

		} else if (req->dpchapp->ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCUSGAACCESSDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::STGIAC)) {
				handleDpchAppDataStgiac(dbsmsdc, &(dpchappdata->stgiac), &(req->dpcheng));
			} else if (dpchappdata->has(DpchAppData::STGIACQRY)) {
				handleDpchAppDataStgiacqry(dbsmsdc, &(dpchappdata->stgiacqry), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCUSGAACCESSDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTNEWCLICK) {
					handleDpchAppDoButNewClick(dbsmsdc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTDUPLICATECLICK) {
					handleDpchAppDoButDuplicateClick(dbsmsdc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTDELETECLICK) {
					handleDpchAppDoButDeleteClick(dbsmsdc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTREFRESHCLICK) {
					handleDpchAppDoButRefreshClick(dbsmsdc, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlMsdcUsgAAccess::handleDpchAppMsdcInit(
			DbsMsdc* dbsmsdc
			, DpchAppMsdcInit* dpchappmsdcinit
			, DpchEngMsdc** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlMsdcUsgAAccess::handleDpchAppDataStgiac(
			DbsMsdc* dbsmsdc
			, StgIac* _stgiac
			, DpchEngMsdc** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _stgiac->diff(&stgiac);
	// IP handleDpchAppDataStgiac --- INSERT
	insert(moditems, DpchEngData::STGIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlMsdcUsgAAccess::handleDpchAppDataStgiacqry(
			DbsMsdc* dbsmsdc
			, QryMsdcUsgAAccess::StgIac* _stgiacqry
			, DpchEngMsdc** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _stgiacqry->diff(&(qry->stgiac));

	MsdcQUsgAAccess* recSelNew = NULL;

	MsdcAMUsergroupAccess* _recUsgAacc = NULL;

	muteRefresh = true;

	if (!diffitems.empty()) {
		qry->stgiac = *_stgiacqry;

		if (has(diffitems, QryMsdcUsgAAccess::StgIac::JNUM)) recSelNew = qry->getRecByJnum(_stgiacqry->jnum);

		if (!has(diffitems, QryMsdcUsgAAccess::StgIac::JNUM) || (diffitems.size() > 1)) {
			qry->rerun(dbsmsdc);
			insert(moditems, {DpchEngData::STATSHRQRY, DpchEngData::RST});
		};

		if (has(diffitems, QryMsdcUsgAAccess::StgIac::JNUM)) {
			if (!recSelNew) recSelNew = qry->getRecByJnum(_stgiacqry->jnum);

			recUsgAacc = MsdcAMUsergroupAccess();

			if (recSelNew) {
				if (dbsmsdc->tblmsdcamusergroupaccess->loadRecByRef(recSelNew->ref, &_recUsgAacc)) {
					recUsgAacc = *_recUsgAacc;
					delete _recUsgAacc;
				};
			};

			xchg->addRefPreset(VecMsdcVPreset::PREMSDCREFSEL, jref, ((recSelNew) ? recSelNew->ref : 0));
			qry->refreshJnum();
		};

		refresh(dbsmsdc, moditems);
	};

	muteRefresh = false;

	insert(moditems, DpchEngData::STGIACQRY);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlMsdcUsgAAccess::handleDpchAppDoButNewClick(
			DbsMsdc* dbsmsdc
			, DpchEngMsdc** dpcheng
		) {
	// IP handleDpchAppDoButNewClick --- INSERT
};

void PnlMsdcUsgAAccess::handleDpchAppDoButDuplicateClick(
			DbsMsdc* dbsmsdc
			, DpchEngMsdc** dpcheng
		) {
	// IP handleDpchAppDoButDuplicateClick --- INSERT
};

void PnlMsdcUsgAAccess::handleDpchAppDoButDeleteClick(
			DbsMsdc* dbsmsdc
			, DpchEngMsdc** dpcheng
		) {
	// IP handleDpchAppDoButDeleteClick --- INSERT
};

void PnlMsdcUsgAAccess::handleDpchAppDoButRefreshClick(
			DbsMsdc* dbsmsdc
			, DpchEngMsdc** dpcheng
		) {
	set<uint> moditems;

	muteRefresh = true;

	qry->rerun(dbsmsdc, false);
	refresh(dbsmsdc, moditems);

	muteRefresh = false;

	insert(moditems, {DpchEngData::STATSHRQRY, DpchEngData::STGIACQRY, DpchEngData::RST});
	*dpcheng = getNewDpchEng(moditems);
};

void PnlMsdcUsgAAccess::handleCall(
			DbsMsdc* dbsmsdc
			, Call* call
		) {
	if (call->ixVCall == VecMsdcVCall::CALLMSDCSTATCHG) {
		call->abort = handleCallMsdcStatChg(dbsmsdc, call->jref);
	};
};

bool PnlMsdcUsgAAccess::handleCallMsdcStatChg(
			DbsMsdc* dbsmsdc
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallMsdcStatChg --- BEGIN

	set<uint> moditems;

	if (jrefTrig == qry->jref) {
		if (!muteRefresh) {
			refresh(dbsmsdc, moditems);
			if (qry->ixMsdcVQrystate == VecMsdcVQrystate::UTD) insert(moditems, {DpchEngData::STATSHRQRY, DpchEngData::STGIACQRY, DpchEngData::RST});
			if (!moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
		};
	};

	// IP handleCallMsdcStatChg --- END
	return retval;
};

