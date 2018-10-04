/**
  * \file PnlMsdcDatDetail.cpp
  * job handler for job PnlMsdcDatDetail (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Oct 2018
  * \date modified: 4 Oct 2018
  */

#ifdef MSDCCMBD
	#include <Msdccmbd.h>
#else
	#include <Msdcd.h>
#endif

#include "PnlMsdcDatDetail.h"

#include "PnlMsdcDatDetail_blks.cpp"
#include "PnlMsdcDatDetail_evals.cpp"

/******************************************************************************
 class PnlMsdcDatDetail
 ******************************************************************************/

PnlMsdcDatDetail::PnlMsdcDatDetail(
			XchgMsdc* xchg
			, DbsMsdc* dbsmsdc
			, const ubigint jrefSup
			, const uint ixMsdcVLocale
		) :
			JobMsdc(xchg, VecMsdcVJob::PNLMSDCDATDETAIL, jrefSup, ixMsdcVLocale)
		{

	jref = xchg->addJob(this);

	feedFPupAft.tag = "FeedFPupAft";
	dbsmsdc->fillFeedFromKlst(VecMsdcVKeylist::KLSTMSDCKACQFEAT, ixMsdcVLocale, feedFPupAft);

	// IP constructor.cust1 --- INSERT

	dirty = false;

	// IP constructor.cust2 --- INSERT

	xchg->addClstn(VecMsdcVCall::CALLMSDCDAT_PRDEQ, jref, Clstn::VecVJobmask::TREE, 0, Arg(), Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	xchg->addIxClstn(VecMsdcVCall::CALLMSDCKLSAKEYMOD_KLSEQ, jref, Clstn::VecVJobmask::ALL, 0, VecMsdcVKeylist::KLSTMSDCKACQFEAT, Clstn::VecVJactype::LOCK);

	updatePreset(dbsmsdc, VecMsdcVPreset::PREMSDCREFDAT, jref);
	
};

PnlMsdcDatDetail::~PnlMsdcDatDetail() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngMsdc* PnlMsdcDatDetail::getNewDpchEng(
			set<uint> items
		) {
	DpchEngMsdc* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngMsdcConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &feedFPupAft, &statshr, items);
	};

	return dpcheng;
};

void PnlMsdcDatDetail::refreshPupAft(
			DbsMsdc* dbsmsdc
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	StatShr oldStatshr(statshr);

	// contiac
	contiac.numFPupAft = 0;

	for (unsigned int i=0;i<feedFPupAft.size();i++) {
		if (feedFPupAft.getSrefByNum(i+1) == contiac.TxfAft) {
			contiac.numFPupAft = i+1;
			break;
		};
	};

	// statshr
	statshr.TxfAftValid = (contiac.numFPupAft != 0);
	statshr.PupAftActive = evalPupAftActive(dbsmsdc);
	statshr.ButAftEditAvail = evalButAftEditAvail(dbsmsdc);

	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlMsdcDatDetail::refreshTxfAft(
			DbsMsdc* dbsmsdc
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	StatShr oldStatshr(statshr);

	// contiac
	contiac.TxfAft = feedFPupAft.getSrefByNum(contiac.numFPupAft);

	// statshr
	statshr.TxfAftValid = true;

	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlMsdcDatDetail::refreshAft(
			DbsMsdc* dbsmsdc
			, set<uint>& moditems
		) {
	// feedFPupAft
	dbsmsdc->fillFeedFromKlst(VecMsdcVKeylist::KLSTMSDCKACQFEAT, ixMsdcVLocale, feedFPupAft);

	insert(moditems, DpchEngData::FEEDFPUPAFT);

	refreshPupAft(dbsmsdc, moditems);
};

void PnlMsdcDatDetail::refreshRecDat(
			DbsMsdc* dbsmsdc
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	MsdcMData* _recDat = NULL;

	if (dbsmsdc->tblmsdcmdata->loadRecByRef(recDat.ref, &_recDat)) {
		recDat = *_recDat;
		delete _recDat;
	} else recDat = MsdcMData();

	dirty = false;

	contiac.TxfAft = recDat.srefMsdcKAcqfeat;
	continf.TxtPrd = StubMsdc::getStubPrdStd(dbsmsdc, recDat.refMsdcMPeriod, ixMsdcVLocale, Stub::VecVNonetype::FULL);
	contiac.TxfSta = Ftm::stamp(recDat.start);
	contiac.TxfSto = Ftm::stamp(recDat.stop);
	contiac.TxfCmt = recDat.Comment;

	statshr.TxtPrdActive = evalTxtPrdActive(dbsmsdc);
	statshr.ButPrdViewAvail = evalButPrdViewAvail(dbsmsdc);
	statshr.ButPrdViewActive = evalButPrdViewActive(dbsmsdc);
	statshr.TxfStaActive = evalTxfStaActive(dbsmsdc);
	statshr.TxfStoActive = evalTxfStoActive(dbsmsdc);
	statshr.TxfCmtActive = evalTxfCmtActive(dbsmsdc);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	refreshPupAft(dbsmsdc, moditems);

};

void PnlMsdcDatDetail::refresh(
			DbsMsdc* dbsmsdc
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	// IP refresh --- BEGIN
	// statshr
	statshr.ButSaveAvail = evalButSaveAvail(dbsmsdc);
	statshr.ButSaveActive = evalButSaveActive(dbsmsdc);
	// IP refresh --- END

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlMsdcDatDetail::updatePreset(
			DbsMsdc* dbsmsdc
			, const uint ixMsdcVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixMsdcVPreset == VecMsdcVPreset::PREMSDCREFDAT) {
		recDat.ref = xchg->getRefPreset(VecMsdcVPreset::PREMSDCREFDAT, jref);
		refreshRecDat(dbsmsdc, moditems);

		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlMsdcDatDetail::handleRequest(
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

		} else if (req->dpchapp->ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCDATDETAILDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbsmsdc, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCDATDETAILDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTSAVECLICK) {
					handleDpchAppDoButSaveClick(dbsmsdc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTAFTEDITCLICK) {
					handleDpchAppDoButAftEditClick(dbsmsdc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTPRDVIEWCLICK) {
					handleDpchAppDoButPrdViewClick(dbsmsdc, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlMsdcDatDetail::handleDpchAppMsdcInit(
			DbsMsdc* dbsmsdc
			, DpchAppMsdcInit* dpchappmsdcinit
			, DpchEngMsdc** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlMsdcDatDetail::handleDpchAppDataContiac(
			DbsMsdc* dbsmsdc
			, ContIac* _contiac
			, DpchEngMsdc** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (hasAny(diffitems, {ContIac::TXFSTA, ContIac::TXFSTO, ContIac::TXFCMT})) {
		if (has(diffitems, ContIac::TXFSTA)) contiac.TxfSta = _contiac->TxfSta;
		if (has(diffitems, ContIac::TXFSTO)) contiac.TxfSto = _contiac->TxfSto;
		if (has(diffitems, ContIac::TXFCMT)) contiac.TxfCmt = _contiac->TxfCmt;
	};

	if (has(diffitems, ContIac::TXFAFT)) {
		contiac.TxfAft = _contiac->TxfAft;
		refreshPupAft(dbsmsdc, moditems);
	} else if (has(diffitems, ContIac::NUMFPUPAFT)) {
		contiac.numFPupAft = _contiac->numFPupAft;
		refreshTxfAft(dbsmsdc, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlMsdcDatDetail::handleDpchAppDoButSaveClick(
			DbsMsdc* dbsmsdc
			, DpchEngMsdc** dpcheng
		) {
	// IP handleDpchAppDoButSaveClick --- INSERT
};

void PnlMsdcDatDetail::handleDpchAppDoButAftEditClick(
			DbsMsdc* dbsmsdc
			, DpchEngMsdc** dpcheng
		) {
	// IP handleDpchAppDoButAftEditClick --- INSERT
};

void PnlMsdcDatDetail::handleDpchAppDoButPrdViewClick(
			DbsMsdc* dbsmsdc
			, DpchEngMsdc** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	if (statshr.ButPrdViewAvail && statshr.ButPrdViewActive) {
		if (xchg->getIxPreset(VecMsdcVPreset::PREMSDCIXCRDACCPRD, jref)) {
			sref = "CrdMsdcPrd";
			xchg->triggerIxRefSrefIntvalToRefCall(dbsmsdc, VecMsdcVCall::CALLMSDCCRDOPEN, jref, 0, 0, sref, recDat.refMsdcMPeriod, jrefNew);
		};

		if (jrefNew == 0) *dpcheng = new DpchEngMsdcConfirm(false, 0, "");
		else *dpcheng = new DpchEngMsdcConfirm(true, jrefNew, sref);
	};
};

void PnlMsdcDatDetail::handleCall(
			DbsMsdc* dbsmsdc
			, Call* call
		) {
	if (call->ixVCall == VecMsdcVCall::CALLMSDCDAT_PRDEQ) {
		call->abort = handleCallMsdcDat_prdEq(dbsmsdc, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecMsdcVCall::CALLMSDCDATUPD_REFEQ) {
		call->abort = handleCallMsdcDatUpd_refEq(dbsmsdc, call->jref, call->argInv.ref);
	} else if (call->ixVCall == VecMsdcVCall::CALLMSDCKLSAKEYMOD_KLSEQ) {
		call->abort = handleCallMsdcKlsAkeyMod_klsEq(dbsmsdc, call->jref, call->argInv.ix);
	};
};

bool PnlMsdcDatDetail::handleCallMsdcDat_prdEq(
			DbsMsdc* dbsmsdc
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	// IP handleCallMsdcDat_prdEq --- BEGIN
	boolvalRet = (recDat.refMsdcMPeriod == refInv);
	// IP handleCallMsdcDat_prdEq --- END
	return retval;
};

bool PnlMsdcDatDetail::handleCallMsdcDatUpd_refEq(
			DbsMsdc* dbsmsdc
			, const ubigint jrefTrig
			, const ubigint refInv
		) {
	bool retval = false;
	// IP handleCallMsdcDatUpd_refEq --- INSERT
	return retval;
};

bool PnlMsdcDatDetail::handleCallMsdcKlsAkeyMod_klsEq(
			DbsMsdc* dbsmsdc
			, const ubigint jrefTrig
			, const uint ixInv
		) {
	bool retval = false;
	set<uint> moditems;

	if (ixInv == VecMsdcVKeylist::KLSTMSDCKACQFEAT) {
		refreshAft(dbsmsdc, moditems);
	};

	xchg->submitDpch(getNewDpchEng(moditems));
	return retval;
};

