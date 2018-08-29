/**
  * \file PnlMsdcFilDetail.cpp
  * job handler for job PnlMsdcFilDetail (implementation)
  * \author Alexander Wirthmueller
  * \date created: 29 Aug 2018
  * \date modified: 29 Aug 2018
  */

#ifdef MSDCCMBD
	#include <Msdccmbd.h>
#else
	#include <Msdcd.h>
#endif

#include "PnlMsdcFilDetail.h"

#include "PnlMsdcFilDetail_blks.cpp"
#include "PnlMsdcFilDetail_evals.cpp"

/******************************************************************************
 class PnlMsdcFilDetail
 ******************************************************************************/

PnlMsdcFilDetail::PnlMsdcFilDetail(
			XchgMsdc* xchg
			, DbsMsdc* dbsmsdc
			, const ubigint jrefSup
			, const uint ixMsdcVLocale
		) :
			JobMsdc(xchg, VecMsdcVJob::PNLMSDCFILDETAIL, jrefSup, ixMsdcVLocale)
		{

	jref = xchg->addJob(this);

	feedFLstClu.tag = "FeedFLstClu";
	feedFPupCnt.tag = "FeedFPupCnt";
	dbsmsdc->fillFeedFromKlst(VecMsdcVKeylist::KLSTMSDCKMFILECONTENT, ixMsdcVLocale, feedFPupCnt);
	feedFPupMim.tag = "FeedFPupMim";
	dbsmsdc->fillFeedFromKlst(VecMsdcVKeylist::KLSTMSDCKMFILEMIMETYPE, ixMsdcVLocale, feedFPupMim);
	feedFPupRet.tag = "FeedFPupRet";
	VecMsdcVMFileRefTbl::fillFeed(ixMsdcVLocale, feedFPupRet);

	// IP constructor.cust1 --- INSERT

	dirty = false;

	// IP constructor.cust2 --- INSERT

	xchg->addClstn(VecMsdcVCall::CALLMSDCFIL_CLUEQ, jref, Clstn::VecVJobmask::TREE, 0, Arg(), Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecMsdcVCall::CALLMSDCFIL_RETEQ, jref, Clstn::VecVJobmask::TREE, 0, Arg(), Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecMsdcVCall::CALLMSDCFIL_REUEQ, jref, Clstn::VecVJobmask::TREE, 0, Arg(), Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	xchg->addIxClstn(VecMsdcVCall::CALLMSDCKLSAKEYMOD_KLSEQ, jref, Clstn::VecVJobmask::ALL, 0, VecMsdcVKeylist::KLSTMSDCKMFILECONTENT, Clstn::VecVJactype::LOCK);
	xchg->addIxClstn(VecMsdcVCall::CALLMSDCKLSAKEYMOD_KLSEQ, jref, Clstn::VecVJobmask::ALL, 0, VecMsdcVKeylist::KLSTMSDCKMFILEMIMETYPE, Clstn::VecVJactype::LOCK);

	updatePreset(dbsmsdc, VecMsdcVPreset::PREMSDCREFFIL, jref);
	
};

PnlMsdcFilDetail::~PnlMsdcFilDetail() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngMsdc* PnlMsdcFilDetail::getNewDpchEng(
			set<uint> items
		) {
	DpchEngMsdc* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngMsdcConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &feedFLstClu, &feedFPupCnt, &feedFPupMim, &feedFPupRet, &statshr, items);
	};

	return dpcheng;
};

void PnlMsdcFilDetail::refreshLstClu(
			DbsMsdc* dbsmsdc
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstCluActive = evalLstCluActive(dbsmsdc);
	statshr.ButCluViewActive = evalButCluViewActive(dbsmsdc);
	statshr.ButCluClusterAvail = evalButCluClusterAvail(dbsmsdc);
	statshr.ButCluUnclusterAvail = evalButCluUnclusterAvail(dbsmsdc);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlMsdcFilDetail::refreshClu(
			DbsMsdc* dbsmsdc
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);

	vector<ubigint> refs;

	bool first;

	// contiac
	contiac.numFLstClu = 0;

	// feedFLstClu, continf
	feedFLstClu.clear();
	continf.TxtClu = "";

	if (recFil.refMsdcCFile != 0) dbsmsdc->tblmsdcmfile->loadRefsByClu(recFil.refMsdcCFile, false, refs);

	first = true;
	for (unsigned int i=0;i<refs.size();i++) {
		if (refs[i] != recFil.ref) {
			feedFLstClu.appendRefTitles(refs[i], StubMsdc::getStubFilStd(dbsmsdc, refs[i], ixMsdcVLocale));

			if (first) first = false;
			else continf.TxtClu += ";";

			continf.TxtClu += StubMsdc::getStubFilStd(dbsmsdc, refs[i], ixMsdcVLocale);
		};
	};
	if (first) continf.TxtClu = "-";

	insert(moditems, DpchEngData::FEEDFLSTCLU);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);

	refreshLstClu(dbsmsdc, moditems);
};

void PnlMsdcFilDetail::refreshPupCnt(
			DbsMsdc* dbsmsdc
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	StatShr oldStatshr(statshr);

	// contiac
	contiac.numFPupCnt = 0;

	for (unsigned int i=0;i<feedFPupCnt.size();i++) {
		if (feedFPupCnt.getSrefByNum(i+1) == contiac.TxfCnt) {
			contiac.numFPupCnt = i+1;
			break;
		};
	};

	// statshr
	statshr.TxfCntValid = (contiac.numFPupCnt != 0);
	statshr.PupCntActive = evalPupCntActive(dbsmsdc);
	statshr.ButCntEditAvail = evalButCntEditAvail(dbsmsdc);

	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlMsdcFilDetail::refreshTxfCnt(
			DbsMsdc* dbsmsdc
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	StatShr oldStatshr(statshr);

	// contiac
	contiac.TxfCnt = feedFPupCnt.getSrefByNum(contiac.numFPupCnt);

	// statshr
	statshr.TxfCntValid = true;

	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlMsdcFilDetail::refreshCnt(
			DbsMsdc* dbsmsdc
			, set<uint>& moditems
		) {
	// feedFPupCnt
	dbsmsdc->fillFeedFromKlst(VecMsdcVKeylist::KLSTMSDCKMFILECONTENT, ixMsdcVLocale, feedFPupCnt);

	insert(moditems, DpchEngData::FEEDFPUPCNT);

	refreshPupCnt(dbsmsdc, moditems);
};

void PnlMsdcFilDetail::refreshPupMim(
			DbsMsdc* dbsmsdc
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	StatShr oldStatshr(statshr);

	// contiac
	contiac.numFPupMim = 0;

	for (unsigned int i=0;i<feedFPupMim.size();i++) {
		if (feedFPupMim.getSrefByNum(i+1) == contiac.TxfMim) {
			contiac.numFPupMim = i+1;
			break;
		};
	};

	// statshr
	statshr.TxfMimValid = (contiac.numFPupMim != 0);
	statshr.PupMimActive = evalPupMimActive(dbsmsdc);
	statshr.ButMimEditAvail = evalButMimEditAvail(dbsmsdc);

	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlMsdcFilDetail::refreshTxfMim(
			DbsMsdc* dbsmsdc
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	StatShr oldStatshr(statshr);

	// contiac
	contiac.TxfMim = feedFPupMim.getSrefByNum(contiac.numFPupMim);

	// statshr
	statshr.TxfMimValid = true;

	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlMsdcFilDetail::refreshMim(
			DbsMsdc* dbsmsdc
			, set<uint>& moditems
		) {
	// feedFPupMim
	dbsmsdc->fillFeedFromKlst(VecMsdcVKeylist::KLSTMSDCKMFILEMIMETYPE, ixMsdcVLocale, feedFPupMim);

	insert(moditems, DpchEngData::FEEDFPUPMIM);

	refreshPupMim(dbsmsdc, moditems);
};

void PnlMsdcFilDetail::refreshRecFil(
			DbsMsdc* dbsmsdc
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	MsdcMFile* _recFil = NULL;

	if (dbsmsdc->tblmsdcmfile->loadRecByRef(recFil.ref, &_recFil)) {
		recFil = *_recFil;
		delete _recFil;
	} else recFil = MsdcMFile();

	dirty = false;

	xchg->removeClstns(VecMsdcVCall::CALLMSDCFILMOD_CLUEQ, jref);
	if (recFil.refMsdcCFile != 0) xchg->addRefClstn(VecMsdcVCall::CALLMSDCFILMOD_CLUEQ, jref, Clstn::VecVJobmask::ALL, 0, recFil.refMsdcCFile, Clstn::VecVJactype::LOCK);

	contiac.TxfFnm = recFil.Filename;
	contiac.numFPupRet = feedFPupRet.getNumByIx(recFil.refIxVTbl);
	if (recFil.refIxVTbl == VecMsdcVMFileRefTbl::DAT) continf.TxtReu = StubMsdc::getStubDatStd(dbsmsdc, recFil.refUref, ixMsdcVLocale, Stub::VecVNonetype::FULL);
	else continf.TxtReu = "-";
	contiac.TxfCnt = recFil.osrefKContent;
	contiac.TxfAcv = Ftm::stamp(recFil.Archived);
	contiac.TxfAnm = recFil.Archivename;
	contiac.TxfMim = recFil.srefKMimetype;
	contiac.TxfSiz = to_string(recFil.Size);
	contiac.TxfCmt = recFil.Comment;

	statshr.TxfFnmActive = evalTxfFnmActive(dbsmsdc);
	statshr.TxtReuActive = evalTxtReuActive(dbsmsdc);
	statshr.ButReuViewAvail = evalButReuViewAvail(dbsmsdc);
	statshr.ButReuViewActive = evalButReuViewActive(dbsmsdc);
	statshr.TxfAcvActive = evalTxfAcvActive(dbsmsdc);
	statshr.TxfAnmActive = evalTxfAnmActive(dbsmsdc);
	statshr.TxfSizActive = evalTxfSizActive(dbsmsdc);
	statshr.TxfCmtActive = evalTxfCmtActive(dbsmsdc);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	refreshClu(dbsmsdc, moditems);
	refreshPupCnt(dbsmsdc, moditems);
	refreshPupMim(dbsmsdc, moditems);

};

void PnlMsdcFilDetail::refresh(
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

void PnlMsdcFilDetail::updatePreset(
			DbsMsdc* dbsmsdc
			, const uint ixMsdcVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixMsdcVPreset == VecMsdcVPreset::PREMSDCREFFIL) {
		recFil.ref = xchg->getRefPreset(VecMsdcVPreset::PREMSDCREFFIL, jref);
		refreshRecFil(dbsmsdc, moditems);

		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlMsdcFilDetail::handleRequest(
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

		} else if (req->dpchapp->ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCFILDETAILDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbsmsdc, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCFILDETAILDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTSAVECLICK) {
					handleDpchAppDoButSaveClick(dbsmsdc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTCLUVIEWCLICK) {
					handleDpchAppDoButCluViewClick(dbsmsdc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTCLUCLUSTERCLICK) {
					handleDpchAppDoButCluClusterClick(dbsmsdc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTCLUUNCLUSTERCLICK) {
					handleDpchAppDoButCluUnclusterClick(dbsmsdc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTREUVIEWCLICK) {
					handleDpchAppDoButReuViewClick(dbsmsdc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTCNTEDITCLICK) {
					handleDpchAppDoButCntEditClick(dbsmsdc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTMIMEDITCLICK) {
					handleDpchAppDoButMimEditClick(dbsmsdc, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlMsdcFilDetail::handleDpchAppMsdcInit(
			DbsMsdc* dbsmsdc
			, DpchAppMsdcInit* dpchappmsdcinit
			, DpchEngMsdc** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlMsdcFilDetail::handleDpchAppDataContiac(
			DbsMsdc* dbsmsdc
			, ContIac* _contiac
			, DpchEngMsdc** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (hasAny(diffitems, {ContIac::TXFFNM, ContIac::TXFACV, ContIac::TXFANM, ContIac::TXFSIZ, ContIac::TXFCMT})) {
		if (has(diffitems, ContIac::TXFFNM)) contiac.TxfFnm = _contiac->TxfFnm;
		if (has(diffitems, ContIac::TXFACV)) contiac.TxfAcv = _contiac->TxfAcv;
		if (has(diffitems, ContIac::TXFANM)) contiac.TxfAnm = _contiac->TxfAnm;
		if (has(diffitems, ContIac::TXFSIZ)) contiac.TxfSiz = _contiac->TxfSiz;
		if (has(diffitems, ContIac::TXFCMT)) contiac.TxfCmt = _contiac->TxfCmt;
	};

	if (has(diffitems, ContIac::NUMFLSTCLU)) {
		contiac.numFLstClu = _contiac->numFLstClu;
		refreshLstClu(dbsmsdc, moditems);
	};

	if (has(diffitems, ContIac::TXFCNT)) {
		contiac.TxfCnt = _contiac->TxfCnt;
		refreshPupCnt(dbsmsdc, moditems);
	} else if (has(diffitems, ContIac::NUMFPUPCNT)) {
		contiac.numFPupCnt = _contiac->numFPupCnt;
		refreshTxfCnt(dbsmsdc, moditems);
	};

	if (has(diffitems, ContIac::TXFMIM)) {
		contiac.TxfMim = _contiac->TxfMim;
		refreshPupMim(dbsmsdc, moditems);
	} else if (has(diffitems, ContIac::NUMFPUPMIM)) {
		contiac.numFPupMim = _contiac->numFPupMim;
		refreshTxfMim(dbsmsdc, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlMsdcFilDetail::handleDpchAppDoButSaveClick(
			DbsMsdc* dbsmsdc
			, DpchEngMsdc** dpcheng
		) {
	// IP handleDpchAppDoButSaveClick --- INSERT
};

void PnlMsdcFilDetail::handleDpchAppDoButCluViewClick(
			DbsMsdc* dbsmsdc
			, DpchEngMsdc** dpcheng
		) {
	// IP handleDpchAppDoButCluViewClick --- INSERT
};

void PnlMsdcFilDetail::handleDpchAppDoButCluClusterClick(
			DbsMsdc* dbsmsdc
			, DpchEngMsdc** dpcheng
		) {
	// IP handleDpchAppDoButCluClusterClick --- INSERT
};

void PnlMsdcFilDetail::handleDpchAppDoButCluUnclusterClick(
			DbsMsdc* dbsmsdc
			, DpchEngMsdc** dpcheng
		) {
	// IP handleDpchAppDoButCluUnclusterClick --- INSERT
};

void PnlMsdcFilDetail::handleDpchAppDoButReuViewClick(
			DbsMsdc* dbsmsdc
			, DpchEngMsdc** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	uint ixPre = xchg->getIxPreset(VecMsdcVPreset::PREMSDCIXPRE, jref);
	ubigint refPre = ((ixPre) ? xchg->getRefPreset(ixPre, jref) : 0);

	if (statshr.ButReuViewAvail && statshr.ButReuViewActive) {
		if (xchg->getIxPreset(VecMsdcVPreset::PREMSDCIXCRDACCDAT, jref)) if (recFil.refIxVTbl == VecMsdcVMFileRefTbl::DAT) if (ixPre == VecMsdcVPreset::PREMSDCREFPRD) {
			sref = "CrdMsdcDat";
			xchg->triggerIxRefSrefIntvalToRefCall(dbsmsdc, VecMsdcVCall::CALLMSDCCRDOPEN, jref, ixPre, refPre, sref, recFil.refUref, jrefNew);
		};

		if (jrefNew == 0) *dpcheng = new DpchEngMsdcConfirm(false, 0, "");
		else *dpcheng = new DpchEngMsdcConfirm(true, jrefNew, sref);
	};
};

void PnlMsdcFilDetail::handleDpchAppDoButCntEditClick(
			DbsMsdc* dbsmsdc
			, DpchEngMsdc** dpcheng
		) {
	// IP handleDpchAppDoButCntEditClick --- INSERT
};

void PnlMsdcFilDetail::handleDpchAppDoButMimEditClick(
			DbsMsdc* dbsmsdc
			, DpchEngMsdc** dpcheng
		) {
	// IP handleDpchAppDoButMimEditClick --- INSERT
};

void PnlMsdcFilDetail::handleCall(
			DbsMsdc* dbsmsdc
			, Call* call
		) {
	if (call->ixVCall == VecMsdcVCall::CALLMSDCFIL_CLUEQ) {
		call->abort = handleCallMsdcFil_cluEq(dbsmsdc, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecMsdcVCall::CALLMSDCFIL_RETEQ) {
		call->abort = handleCallMsdcFil_retEq(dbsmsdc, call->jref, call->argInv.ix, call->argRet.boolval);
	} else if (call->ixVCall == VecMsdcVCall::CALLMSDCFIL_REUEQ) {
		call->abort = handleCallMsdcFil_reuEq(dbsmsdc, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecMsdcVCall::CALLMSDCFILUPD_REFEQ) {
		call->abort = handleCallMsdcFilUpd_refEq(dbsmsdc, call->jref, call->argInv.ref);
	} else if (call->ixVCall == VecMsdcVCall::CALLMSDCKLSAKEYMOD_KLSEQ) {
		call->abort = handleCallMsdcKlsAkeyMod_klsEq(dbsmsdc, call->jref, call->argInv.ix);
	} else if (call->ixVCall == VecMsdcVCall::CALLMSDCFILMOD_CLUEQ) {
		call->abort = handleCallMsdcFilMod_cluEq(dbsmsdc, call->jref, call->argInv.ref);
	};
};

bool PnlMsdcFilDetail::handleCallMsdcFil_cluEq(
			DbsMsdc* dbsmsdc
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	// IP handleCallMsdcFil_cluEq --- BEGIN
	boolvalRet = (recFil.refMsdcCFile == refInv);
	// IP handleCallMsdcFil_cluEq --- END
	return retval;
};

bool PnlMsdcFilDetail::handleCallMsdcFil_retEq(
			DbsMsdc* dbsmsdc
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
	// IP handleCallMsdcFil_retEq --- BEGIN
	boolvalRet = (recFil.refIxVTbl == ixInv);
	// IP handleCallMsdcFil_retEq --- END
	return retval;
};

bool PnlMsdcFilDetail::handleCallMsdcFil_reuEq(
			DbsMsdc* dbsmsdc
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	// IP handleCallMsdcFil_reuEq --- BEGIN
	boolvalRet = (recFil.refUref == refInv);
	// IP handleCallMsdcFil_reuEq --- END
	return retval;
};

bool PnlMsdcFilDetail::handleCallMsdcFilUpd_refEq(
			DbsMsdc* dbsmsdc
			, const ubigint jrefTrig
			, const ubigint refInv
		) {
	bool retval = false;
	// IP handleCallMsdcFilUpd_refEq --- INSERT
	return retval;
};

bool PnlMsdcFilDetail::handleCallMsdcKlsAkeyMod_klsEq(
			DbsMsdc* dbsmsdc
			, const ubigint jrefTrig
			, const uint ixInv
		) {
	bool retval = false;
	set<uint> moditems;

	if (ixInv == VecMsdcVKeylist::KLSTMSDCKMFILECONTENT) {
		refreshCnt(dbsmsdc, moditems);
	} else if (ixInv == VecMsdcVKeylist::KLSTMSDCKMFILEMIMETYPE) {
		refreshMim(dbsmsdc, moditems);
	};

	xchg->submitDpch(getNewDpchEng(moditems));
	return retval;
};

bool PnlMsdcFilDetail::handleCallMsdcFilMod_cluEq(
			DbsMsdc* dbsmsdc
			, const ubigint jrefTrig
			, const ubigint refInv
		) {
	bool retval = false;
	set<uint> moditems;

	refreshClu(dbsmsdc, moditems);

	xchg->submitDpch(getNewDpchEng(moditems));
	return retval;
};

