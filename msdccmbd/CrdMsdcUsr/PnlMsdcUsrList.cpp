/**
  * \file PnlMsdcUsrList.cpp
  * job handler for job PnlMsdcUsrList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 29 Aug 2018
  * \date modified: 29 Aug 2018
  */

#ifdef MSDCCMBD
	#include <Msdccmbd.h>
#else
	#include <Msdcd.h>
#endif

#include "PnlMsdcUsrList.h"

#include "PnlMsdcUsrList_blks.cpp"
#include "PnlMsdcUsrList_evals.cpp"

/******************************************************************************
 class PnlMsdcUsrList
 ******************************************************************************/

PnlMsdcUsrList::PnlMsdcUsrList(
			XchgMsdc* xchg
			, DbsMsdc* dbsmsdc
			, const ubigint jrefSup
			, const uint ixMsdcVLocale
		) :
			JobMsdc(xchg, VecMsdcVJob::PNLMSDCUSRLIST, jrefSup, ixMsdcVLocale)
		{

	jref = xchg->addJob(this);

	feedFCsiQst.tag = "FeedFCsiQst";
	feedFCsiQst.appendIxSrefTitles(VecMsdcVQrystate::MNR, "ong", VecMsdcVQrystate::getTitle(VecMsdcVQrystate::MNR, ixMsdcVLocale));
	feedFCsiQst.appendIxSrefTitles(VecMsdcVQrystate::OOD, "red", VecMsdcVQrystate::getTitle(VecMsdcVQrystate::OOD, ixMsdcVLocale));
	feedFCsiQst.appendIxSrefTitles(VecMsdcVQrystate::SLM, "yel", VecMsdcVQrystate::getTitle(VecMsdcVQrystate::SLM, ixMsdcVLocale));
	feedFCsiQst.appendIxSrefTitles(VecMsdcVQrystate::UTD, "grn", VecMsdcVQrystate::getTitle(VecMsdcVQrystate::UTD, ixMsdcVLocale));
	feedFTos.tag = "FeedFTos";
	QryMsdcUsrList::VecVOrd::fillFeed(feedFTos);

	qry = NULL;

	// IP constructor.cust1 --- INSERT

	xchg->addRefPreset(VecMsdcVPreset::PREMSDCREFSEL, jref, xchg->getRefPreset(VecMsdcVPreset::PREMSDCREFUSR, jref));
	xchg->addIxPreset(VecMsdcVPreset::PREMSDCIXORD, jref, QryMsdcUsrList::VecVOrd::SRF);

	qry = new QryMsdcUsrList(xchg, dbsmsdc, jref, ixMsdcVLocale);

	// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	statshr.ixMsdcVExpstate = ((xchg->getRefPreset(VecMsdcVPreset::PREMSDCREFUSR, jref)) ? VecMsdcVExpstate::MIND : VecMsdcVExpstate::REGD);
	refresh(dbsmsdc, moditems);

	xchg->addClstn(VecMsdcVCall::CALLMSDCSTATCHG, jref, Clstn::VecVJobmask::IMM, 0, Arg(), Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	
};

PnlMsdcUsrList::~PnlMsdcUsrList() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngMsdc* PnlMsdcUsrList::getNewDpchEng(
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

void PnlMsdcUsrList::refresh(
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

void PnlMsdcUsrList::updatePreset(
			DbsMsdc* dbsmsdc
			, const uint ixMsdcVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixMsdcVPreset == VecMsdcVPreset::PREMSDCREFUSR) {
		xchg->addRefPreset(VecMsdcVPreset::PREMSDCREFSEL, jref, xchg->getRefPreset(VecMsdcVPreset::PREMSDCREFUSR, jref));
		qry->refreshJnum();
		refresh(dbsmsdc, moditems);

		insert(moditems, DpchEngData::STGIACQRY);

		if ((jrefTrig != jref) && notif) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlMsdcUsrList::minimize(
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

void PnlMsdcUsrList::regularize(
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

void PnlMsdcUsrList::handleRequest(
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

		} else if (req->dpchapp->ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCUSRLISTDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbsmsdc, &(dpchappdata->contiac), &(req->dpcheng));
			} else if (dpchappdata->has(DpchAppData::STGIAC)) {
				handleDpchAppDataStgiac(dbsmsdc, &(dpchappdata->stgiac), &(req->dpcheng));
			} else if (dpchappdata->has(DpchAppData::STGIACQRY)) {
				handleDpchAppDataStgiacqry(dbsmsdc, &(dpchappdata->stgiacqry), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCUSRLISTDO) {
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

void PnlMsdcUsrList::handleDpchAppMsdcInit(
			DbsMsdc* dbsmsdc
			, DpchAppMsdcInit* dpchappmsdcinit
			, DpchEngMsdc** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlMsdcUsrList::handleDpchAppDataContiac(
			DbsMsdc* dbsmsdc
			, ContIac* _contiac
			, DpchEngMsdc** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	muteRefresh = true;

	if (has(diffitems, ContIac::NUMFTOS)) {
		if ((_contiac->numFTos >= QryMsdcUsrList::VecVOrd::PRS) && (_contiac->numFTos <= QryMsdcUsrList::VecVOrd::STE)) {
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

void PnlMsdcUsrList::handleDpchAppDataStgiac(
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

void PnlMsdcUsrList::handleDpchAppDataStgiacqry(
			DbsMsdc* dbsmsdc
			, QryMsdcUsrList::StgIac* _stgiacqry
			, DpchEngMsdc** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _stgiacqry->diff(&(qry->stgiac));

	ubigint refSelNew = 0;

	muteRefresh = true;

	if (!diffitems.empty()) {
		qry->stgiac = *_stgiacqry;

		if (has(diffitems, QryMsdcUsrList::StgIac::JNUM)) refSelNew = qry->getRefByJnum(_stgiacqry->jnum);

		if (!has(diffitems, QryMsdcUsrList::StgIac::JNUM) || (diffitems.size() > 1)) {
			qry->rerun(dbsmsdc);
			refresh(dbsmsdc, moditems);
			insert(moditems, {DpchEngData::STATSHRQRY, DpchEngData::RST});
		};

		if (has(diffitems, QryMsdcUsrList::StgIac::JNUM)) {
			if (refSelNew == 0) refSelNew = qry->getRefByJnum(_stgiacqry->jnum);
			xchg->triggerIxRefCall(dbsmsdc, VecMsdcVCall::CALLMSDCREFPRESET, jref, VecMsdcVPreset::PREMSDCREFUSR, refSelNew);
		};
	};

	muteRefresh = false;

	insert(moditems, DpchEngData::STGIACQRY);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlMsdcUsrList::handleDpchAppDoButMinimizeClick(
			DbsMsdc* dbsmsdc
			, DpchEngMsdc** dpcheng
		) {
	minimize(dbsmsdc, true, dpcheng);
};

void PnlMsdcUsrList::handleDpchAppDoButRegularizeClick(
			DbsMsdc* dbsmsdc
			, DpchEngMsdc** dpcheng
		) {
	regularize(dbsmsdc, true, dpcheng);
};

void PnlMsdcUsrList::handleDpchAppDoButNewClick(
			DbsMsdc* dbsmsdc
			, DpchEngMsdc** dpcheng
		) {
	// IP handleDpchAppDoButNewClick --- INSERT
};

void PnlMsdcUsrList::handleDpchAppDoButDeleteClick(
			DbsMsdc* dbsmsdc
			, DpchEngMsdc** dpcheng
		) {
	// IP handleDpchAppDoButDeleteClick --- INSERT
};

void PnlMsdcUsrList::handleDpchAppDoButFilterClick(
			DbsMsdc* dbsmsdc
			, DpchEngMsdc** dpcheng
		) {
	// IP handleDpchAppDoButFilterClick --- INSERT
};

void PnlMsdcUsrList::handleDpchAppDoButRefreshClick(
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

void PnlMsdcUsrList::handleCall(
			DbsMsdc* dbsmsdc
			, Call* call
		) {
	if (call->ixVCall == VecMsdcVCall::CALLMSDCSTATCHG) {
		call->abort = handleCallMsdcStatChg(dbsmsdc, call->jref);
	};
};

bool PnlMsdcUsrList::handleCallMsdcStatChg(
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

