/**
  * \file PnlMsdcDatRef1NFile.cpp
  * job handler for job PnlMsdcDatRef1NFile (implementation)
  * \author Alexander Wirthmueller
  * \date created: 18 Dec 2018
  * \date modified: 18 Dec 2018
  */

#ifdef MSDCCMBD
	#include <Msdccmbd.h>
#else
	#include <Msdcd.h>
#endif

#include "PnlMsdcDatRef1NFile.h"

#include "PnlMsdcDatRef1NFile_blks.cpp"
#include "PnlMsdcDatRef1NFile_evals.cpp"

/******************************************************************************
 class PnlMsdcDatRef1NFile
 ******************************************************************************/

PnlMsdcDatRef1NFile::PnlMsdcDatRef1NFile(
			XchgMsdc* xchg
			, DbsMsdc* dbsmsdc
			, const ubigint jrefSup
			, const uint ixMsdcVLocale
		) :
			JobMsdc(xchg, VecMsdcVJob::PNLMSDCDATREF1NFILE, jrefSup, ixMsdcVLocale)
		{

	jref = xchg->addJob(this);

	feedFCsiQst.tag = "FeedFCsiQst";
	feedFCsiQst.appendIxSrefTitles(VecMsdcVQrystate::MNR, "ong", VecMsdcVQrystate::getTitle(VecMsdcVQrystate::MNR, ixMsdcVLocale));
	feedFCsiQst.appendIxSrefTitles(VecMsdcVQrystate::OOD, "red", VecMsdcVQrystate::getTitle(VecMsdcVQrystate::OOD, ixMsdcVLocale));
	feedFCsiQst.appendIxSrefTitles(VecMsdcVQrystate::SLM, "yel", VecMsdcVQrystate::getTitle(VecMsdcVQrystate::SLM, ixMsdcVLocale));
	feedFCsiQst.appendIxSrefTitles(VecMsdcVQrystate::UTD, "grn", VecMsdcVQrystate::getTitle(VecMsdcVQrystate::UTD, ixMsdcVLocale));

	qry = NULL;

	// IP constructor.cust1 --- INSERT

	xchg->addRefPreset(VecMsdcVPreset::PREMSDCREFSEL, jref, 0);

	qry = new QryMsdcDatRef1NFile(xchg, dbsmsdc, jref, ixMsdcVLocale);

	// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	refresh(dbsmsdc, moditems);

	xchg->addClstn(VecMsdcVCall::CALLMSDCSTATCHG, jref, Clstn::VecVJobmask::IMM, 0, Arg(), Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	
};

PnlMsdcDatRef1NFile::~PnlMsdcDatRef1NFile() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngMsdc* PnlMsdcDatRef1NFile::getNewDpchEng(
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

void PnlMsdcDatRef1NFile::refresh(
			DbsMsdc* dbsmsdc
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	// IP refresh --- BEGIN
	// continf
	continf.numFCsiQst = feedFCsiQst.getNumByIx(qry->ixMsdcVQrystate);

	// statshr
	statshr.ButViewAvail = evalButViewAvail(dbsmsdc);
	statshr.ButViewActive = evalButViewActive(dbsmsdc);
	statshr.ButNewAvail = evalButNewAvail(dbsmsdc);
	statshr.ButDeleteAvail = evalButDeleteAvail(dbsmsdc);
	statshr.ButDeleteActive = evalButDeleteActive(dbsmsdc);

	// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlMsdcDatRef1NFile::updatePreset(
			DbsMsdc* dbsmsdc
			, const uint ixMsdcVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixMsdcVPreset == VecMsdcVPreset::PREMSDCREFDAT) {
		recFil = MsdcMFile();

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

void PnlMsdcDatRef1NFile::handleRequest(
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

		} else if (req->dpchapp->ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCDATREF1NFILEDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::STGIAC)) {
				handleDpchAppDataStgiac(dbsmsdc, &(dpchappdata->stgiac), &(req->dpcheng));
			} else if (dpchappdata->has(DpchAppData::STGIACQRY)) {
				handleDpchAppDataStgiacqry(dbsmsdc, &(dpchappdata->stgiacqry), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCDATREF1NFILEDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTVIEWCLICK) {
					handleDpchAppDoButViewClick(dbsmsdc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTNEWCLICK) {
					handleDpchAppDoButNewClick(dbsmsdc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTDELETECLICK) {
					handleDpchAppDoButDeleteClick(dbsmsdc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTREFRESHCLICK) {
					handleDpchAppDoButRefreshClick(dbsmsdc, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlMsdcDatRef1NFile::handleDpchAppMsdcInit(
			DbsMsdc* dbsmsdc
			, DpchAppMsdcInit* dpchappmsdcinit
			, DpchEngMsdc** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlMsdcDatRef1NFile::handleDpchAppDataStgiac(
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

void PnlMsdcDatRef1NFile::handleDpchAppDataStgiacqry(
			DbsMsdc* dbsmsdc
			, QryMsdcDatRef1NFile::StgIac* _stgiacqry
			, DpchEngMsdc** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _stgiacqry->diff(&(qry->stgiac));

	MsdcQDatRef1NFile* recSelNew = NULL;

	MsdcMFile* _recFil = NULL;

	muteRefresh = true;

	if (!diffitems.empty()) {
		qry->stgiac = *_stgiacqry;

		if (has(diffitems, QryMsdcDatRef1NFile::StgIac::JNUM)) recSelNew = qry->getRecByJnum(_stgiacqry->jnum);

		if (!has(diffitems, QryMsdcDatRef1NFile::StgIac::JNUM) || (diffitems.size() > 1)) {
			qry->rerun(dbsmsdc);
			insert(moditems, {DpchEngData::STATSHRQRY, DpchEngData::RST});
		};

		if (has(diffitems, QryMsdcDatRef1NFile::StgIac::JNUM)) {
			if (!recSelNew) recSelNew = qry->getRecByJnum(_stgiacqry->jnum);

			recFil = MsdcMFile();

			if (recSelNew) {
				if (dbsmsdc->tblmsdcmfile->loadRecByRef(recSelNew->ref, &_recFil)) {
					recFil = *_recFil;
					delete _recFil;
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

void PnlMsdcDatRef1NFile::handleDpchAppDoButViewClick(
			DbsMsdc* dbsmsdc
			, DpchEngMsdc** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	ubigint refDat = xchg->getRefPreset(VecMsdcVPreset::PREMSDCREFDAT, jref);

	if (statshr.ButViewAvail && statshr.ButViewActive) {
		if (xchg->getIxPreset(VecMsdcVPreset::PREMSDCIXCRDACCFIL, jref)) if (refDat != 0) {
			sref = "CrdMsdcFil";
			xchg->triggerIxRefSrefIntvalToRefCall(dbsmsdc, VecMsdcVCall::CALLMSDCCRDOPEN, jref, VecMsdcVPreset::PREMSDCREFDAT, refDat, sref, recFil.ref, jrefNew);
		};

		if (jrefNew == 0) *dpcheng = new DpchEngMsdcConfirm(false, 0, "");
		else *dpcheng = new DpchEngMsdcConfirm(true, jrefNew, sref);
	};
};

void PnlMsdcDatRef1NFile::handleDpchAppDoButNewClick(
			DbsMsdc* dbsmsdc
			, DpchEngMsdc** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	ubigint refDat = xchg->getRefPreset(VecMsdcVPreset::PREMSDCREFDAT, jref);

	if (statshr.ButNewAvail) {
		if ((xchg->getIxPreset(VecMsdcVPreset::PREMSDCIXCRDACCFIL, jref) & VecMsdcWAccess::EDIT) != 0) if (refDat != 0) {
			sref = "CrdMsdcFil";
			xchg->triggerIxRefSrefIntvalToRefCall(dbsmsdc, VecMsdcVCall::CALLMSDCCRDOPEN, jref, VecMsdcVPreset::PREMSDCREFDAT, refDat, sref, -1, jrefNew);
		};

		if (jrefNew == 0) *dpcheng = new DpchEngMsdcConfirm(false, 0, "");
		else *dpcheng = new DpchEngMsdcConfirm(true, jrefNew, sref);
	};
};

void PnlMsdcDatRef1NFile::handleDpchAppDoButDeleteClick(
			DbsMsdc* dbsmsdc
			, DpchEngMsdc** dpcheng
		) {
	// IP handleDpchAppDoButDeleteClick --- INSERT
};

void PnlMsdcDatRef1NFile::handleDpchAppDoButRefreshClick(
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

void PnlMsdcDatRef1NFile::handleCall(
			DbsMsdc* dbsmsdc
			, Call* call
		) {
	if (call->ixVCall == VecMsdcVCall::CALLMSDCSTATCHG) {
		call->abort = handleCallMsdcStatChg(dbsmsdc, call->jref);
	};
};

bool PnlMsdcDatRef1NFile::handleCallMsdcStatChg(
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

