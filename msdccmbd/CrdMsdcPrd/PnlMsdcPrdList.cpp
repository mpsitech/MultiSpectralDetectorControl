/**
  * \file PnlMsdcPrdList.cpp
  * job handler for job PnlMsdcPrdList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 29 Aug 2018
  * \date modified: 29 Aug 2018
  */

#ifdef MSDCCMBD
	#include <Msdccmbd.h>
#else
	#include <Msdcd.h>
#endif

#include "PnlMsdcPrdList.h"

#include "PnlMsdcPrdList_blks.cpp"
#include "PnlMsdcPrdList_evals.cpp"

/******************************************************************************
 class PnlMsdcPrdList
 ******************************************************************************/

PnlMsdcPrdList::PnlMsdcPrdList(
			XchgMsdc* xchg
			, DbsMsdc* dbsmsdc
			, const ubigint jrefSup
			, const uint ixMsdcVLocale
		) :
			JobMsdc(xchg, VecMsdcVJob::PNLMSDCPRDLIST, jrefSup, ixMsdcVLocale)
		{

	jref = xchg->addJob(this);

	feedFCsiQst.tag = "FeedFCsiQst";
	feedFCsiQst.appendIxSrefTitles(VecMsdcVQrystate::MNR, "ong", VecMsdcVQrystate::getTitle(VecMsdcVQrystate::MNR, ixMsdcVLocale));
	feedFCsiQst.appendIxSrefTitles(VecMsdcVQrystate::OOD, "red", VecMsdcVQrystate::getTitle(VecMsdcVQrystate::OOD, ixMsdcVLocale));
	feedFCsiQst.appendIxSrefTitles(VecMsdcVQrystate::SLM, "yel", VecMsdcVQrystate::getTitle(VecMsdcVQrystate::SLM, ixMsdcVLocale));
	feedFCsiQst.appendIxSrefTitles(VecMsdcVQrystate::UTD, "grn", VecMsdcVQrystate::getTitle(VecMsdcVQrystate::UTD, ixMsdcVLocale));
	feedFTos.tag = "FeedFTos";
	QryMsdcPrdList::VecVOrd::fillFeed(feedFTos);

	qry = NULL;

	// IP constructor.cust1 --- INSERT

	xchg->addRefPreset(VecMsdcVPreset::PREMSDCREFSEL, jref, xchg->getRefPreset(VecMsdcVPreset::PREMSDCREFPRD, jref));

	qry = new QryMsdcPrdList(xchg, dbsmsdc, jref, ixMsdcVLocale);

	// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	statshr.ixMsdcVExpstate = ((xchg->getRefPreset(VecMsdcVPreset::PREMSDCREFPRD, jref)) ? VecMsdcVExpstate::MIND : VecMsdcVExpstate::REGD);
	refresh(dbsmsdc, moditems);

	xchg->addClstn(VecMsdcVCall::CALLMSDCSTATCHG, jref, Clstn::VecVJobmask::IMM, 0, Arg(), Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	
};

PnlMsdcPrdList::~PnlMsdcPrdList() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngMsdc* PnlMsdcPrdList::getNewDpchEng(
			set<uint> items
		) {
	DpchEngMsdc* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngMsdcConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &feedFCsiQst, &feedFTos, &statshr, &stgiac, &(qry->rst), &(qry->statshr), &(qry->stgiac), items);
	};

	return dpcheng;
};

void PnlMsdcPrdList::refresh(
			DbsMsdc* dbsmsdc
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);
	ContIac oldContiac(contiac);

	// IP refresh --- BEGIN
	// continf
	continf.numFCsiQst = feedFCsiQst.getNumByIx(qry->ixMsdcVQrystate);

	// contiac
	contiac.numFTos = xchg->getIxPreset(VecMsdcVPreset::PREMSDCIXORD, jref);

	// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
};

void PnlMsdcPrdList::updatePreset(
			DbsMsdc* dbsmsdc
			, const uint ixMsdcVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixMsdcVPreset == VecMsdcVPreset::PREMSDCREFPRD) {
		xchg->addRefPreset(VecMsdcVPreset::PREMSDCREFSEL, jref, xchg->getRefPreset(VecMsdcVPreset::PREMSDCREFPRD, jref));
		qry->refreshJnum();
		refresh(dbsmsdc, moditems);

		insert(moditems, DpchEngData::STGIACQRY);

		if ((jrefTrig != jref) && notif) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlMsdcPrdList::minimize(
			DbsMsdc* dbsmsdc
			, const bool notif
			, DpchEngMsdc** dpcheng
		) {
	set<uint> moditems;

	if (statshr.ixMsdcVExpstate != VecMsdcVExpstate::MIND) {
		statshr.ixMsdcVExpstate = VecMsdcVExpstate::MIND;
		insert(moditems, DpchEngData::STATSHR);
	};

	if (notif) {
		if (dpcheng) *dpcheng = getNewDpchEng(moditems);
		else if (!moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
};

void PnlMsdcPrdList::regularize(
			DbsMsdc* dbsmsdc
			, const bool notif
			, DpchEngMsdc** dpcheng
		) {
	set<uint> moditems;

	if (statshr.ixMsdcVExpstate != VecMsdcVExpstate::REGD) {
		statshr.ixMsdcVExpstate = VecMsdcVExpstate::REGD;
		insert(moditems, DpchEngData::STATSHR);
	};

	if (notif) {
		if (dpcheng) *dpcheng = getNewDpchEng(moditems);
		else if (!moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
};

void PnlMsdcPrdList::handleRequest(
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

		} else if (req->dpchapp->ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCPRDLISTDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbsmsdc, &(dpchappdata->contiac), &(req->dpcheng));
			} else if (dpchappdata->has(DpchAppData::STGIAC)) {
				handleDpchAppDataStgiac(dbsmsdc, &(dpchappdata->stgiac), &(req->dpcheng));
			} else if (dpchappdata->has(DpchAppData::STGIACQRY)) {
				handleDpchAppDataStgiacqry(dbsmsdc, &(dpchappdata->stgiacqry), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCPRDLISTDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTMINIMIZECLICK) {
					handleDpchAppDoButMinimizeClick(dbsmsdc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTREGULARIZECLICK) {
					handleDpchAppDoButRegularizeClick(dbsmsdc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTNEWCLICK) {
					handleDpchAppDoButNewClick(dbsmsdc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTDELETECLICK) {
					handleDpchAppDoButDeleteClick(dbsmsdc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTFILTERCLICK) {
					handleDpchAppDoButFilterClick(dbsmsdc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTREFRESHCLICK) {
					handleDpchAppDoButRefreshClick(dbsmsdc, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlMsdcPrdList::handleDpchAppMsdcInit(
			DbsMsdc* dbsmsdc
			, DpchAppMsdcInit* dpchappmsdcinit
			, DpchEngMsdc** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlMsdcPrdList::handleDpchAppDataContiac(
			DbsMsdc* dbsmsdc
			, ContIac* _contiac
			, DpchEngMsdc** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	muteRefresh = true;

	if (has(diffitems, ContIac::NUMFTOS)) {
		if ((_contiac->numFTos >= QryMsdcPrdList::VecVOrd::STA) && (_contiac->numFTos <= QryMsdcPrdList::VecVOrd::STA)) {
			xchg->addIxPreset(VecMsdcVPreset::PREMSDCIXORD, jref, _contiac->numFTos);

			qry->rerun(dbsmsdc);
			refresh(dbsmsdc, moditems);
			insert(moditems, {DpchEngData::STATSHRQRY, DpchEngData::STGIACQRY, DpchEngData::RST});
		};
	};

	muteRefresh = false;

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlMsdcPrdList::handleDpchAppDataStgiac(
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

void PnlMsdcPrdList::handleDpchAppDataStgiacqry(
			DbsMsdc* dbsmsdc
			, QryMsdcPrdList::StgIac* _stgiacqry
			, DpchEngMsdc** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _stgiacqry->diff(&(qry->stgiac));

	ubigint refSelNew = 0;

	muteRefresh = true;

	if (!diffitems.empty()) {
		qry->stgiac = *_stgiacqry;

		if (has(diffitems, QryMsdcPrdList::StgIac::JNUM)) refSelNew = qry->getRefByJnum(_stgiacqry->jnum);

		if (!has(diffitems, QryMsdcPrdList::StgIac::JNUM) || (diffitems.size() > 1)) {
			qry->rerun(dbsmsdc);
			refresh(dbsmsdc, moditems);
			insert(moditems, {DpchEngData::STATSHRQRY, DpchEngData::RST});
		};

		if (has(diffitems, QryMsdcPrdList::StgIac::JNUM)) {
			if (refSelNew == 0) refSelNew = qry->getRefByJnum(_stgiacqry->jnum);
			xchg->triggerIxRefCall(dbsmsdc, VecMsdcVCall::CALLMSDCREFPRESET, jref, VecMsdcVPreset::PREMSDCREFPRD, refSelNew);
		};
	};

	muteRefresh = false;

	insert(moditems, DpchEngData::STGIACQRY);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlMsdcPrdList::handleDpchAppDoButMinimizeClick(
			DbsMsdc* dbsmsdc
			, DpchEngMsdc** dpcheng
		) {
	minimize(dbsmsdc, true, dpcheng);
};

void PnlMsdcPrdList::handleDpchAppDoButRegularizeClick(
			DbsMsdc* dbsmsdc
			, DpchEngMsdc** dpcheng
		) {
	regularize(dbsmsdc, true, dpcheng);
};

void PnlMsdcPrdList::handleDpchAppDoButNewClick(
			DbsMsdc* dbsmsdc
			, DpchEngMsdc** dpcheng
		) {
	// IP handleDpchAppDoButNewClick --- INSERT
};

void PnlMsdcPrdList::handleDpchAppDoButDeleteClick(
			DbsMsdc* dbsmsdc
			, DpchEngMsdc** dpcheng
		) {
	// IP handleDpchAppDoButDeleteClick --- INSERT
};

void PnlMsdcPrdList::handleDpchAppDoButFilterClick(
			DbsMsdc* dbsmsdc
			, DpchEngMsdc** dpcheng
		) {
	// IP handleDpchAppDoButFilterClick --- INSERT
};

void PnlMsdcPrdList::handleDpchAppDoButRefreshClick(
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

void PnlMsdcPrdList::handleCall(
			DbsMsdc* dbsmsdc
			, Call* call
		) {
	if (call->ixVCall == VecMsdcVCall::CALLMSDCSTATCHG) {
		call->abort = handleCallMsdcStatChg(dbsmsdc, call->jref);
	};
};

bool PnlMsdcPrdList::handleCallMsdcStatChg(
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

