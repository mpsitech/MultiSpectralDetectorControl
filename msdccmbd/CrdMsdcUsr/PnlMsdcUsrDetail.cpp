/**
  * \file PnlMsdcUsrDetail.cpp
  * job handler for job PnlMsdcUsrDetail (implementation)
  * \author Alexander Wirthmueller
  * \date created: 15 Aug 2018
  * \date modified: 15 Aug 2018
  */

#ifdef MSDCCMBD
	#include <Msdccmbd.h>
#else
	#include <Msdcd.h>
#endif

#include "PnlMsdcUsrDetail.h"

#include "PnlMsdcUsrDetail_blks.cpp"
#include "PnlMsdcUsrDetail_evals.cpp"

/******************************************************************************
 class PnlMsdcUsrDetail
 ******************************************************************************/

PnlMsdcUsrDetail::PnlMsdcUsrDetail(
			XchgMsdc* xchg
			, DbsMsdc* dbsmsdc
			, const ubigint jrefSup
			, const uint ixMsdcVLocale
		) : JobMsdc(xchg, VecMsdcVJob::PNLMSDCUSRDETAIL, jrefSup, ixMsdcVLocale) {

	jref = xchg->addJob(this);

	feedFPupLcl.tag = "FeedFPupLcl";
	VecMsdcVLocale::fillFeed(ixMsdcVLocale, feedFPupLcl);
	feedFPupSte.tag = "FeedFPupSte";
	VecMsdcVMUserState::fillFeed(ixMsdcVLocale, feedFPupSte);
	feedFPupUlv.tag = "FeedFPupUlv";
	VecMsdcVUserlevel::fillFeed(ixMsdcVLocale, feedFPupUlv);

	// IP constructor.cust1 --- INSERT

	dirty = false;

	// IP constructor.cust2 --- INSERT

	xchg->addClstn(VecMsdcVCall::CALLMSDCUSR_PRSEQ, jref, Clstn::VecVJobmask::TREE, 0, Arg(), Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecMsdcVCall::CALLMSDCUSR_USGEQ, jref, Clstn::VecVJobmask::TREE, 0, Arg(), Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	updatePreset(dbsmsdc, VecMsdcVPreset::PREMSDCREFUSR, jref);
	
};

PnlMsdcUsrDetail::~PnlMsdcUsrDetail() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngMsdc* PnlMsdcUsrDetail::getNewDpchEng(
			set<uint> items
		) {
	DpchEngMsdc* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngMsdcConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &feedFPupLcl, &feedFPupSte, &feedFPupUlv, &statshr, items);
	};

	return dpcheng;
};

void PnlMsdcUsrDetail::refreshRecUsr(
			DbsMsdc* dbsmsdc
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	MsdcMUser* _recUsr = NULL;

	if (dbsmsdc->tblmsdcmuser->loadRecByRef(recUsr.ref, &_recUsr)) {
		recUsr = *_recUsr;
		delete _recUsr;
	} else recUsr = MsdcMUser();

	dirty = false;

	recUsrJste.ref = recUsr.refJState;
	xchg->removeClstns(VecMsdcVCall::CALLMSDCUSRJSTEMOD_USREQ, jref);
	if (recUsr.ref != 0) xchg->addRefClstn(VecMsdcVCall::CALLMSDCUSRJSTEMOD_USREQ, jref, Clstn::VecVJobmask::ALL, 0, recUsr.ref, Clstn::VecVJactype::LOCK);

	continf.TxtPrs = StubMsdc::getStubPrsStd(dbsmsdc, recUsr.refMsdcMPerson, ixMsdcVLocale, Stub::VecVNonetype::FULL);
	continf.TxtSrf = recUsr.sref;
	continf.TxtUsg = StubMsdc::getStubUsgStd(dbsmsdc, recUsr.refMsdcMUsergroup, ixMsdcVLocale, Stub::VecVNonetype::FULL);
	contiac.numFPupSte = feedFPupSte.getNumByIx(recUsr.ixVState);
	contiac.numFPupLcl = feedFPupLcl.getNumByIx(recUsr.ixMsdcVLocale);
	contiac.numFPupUlv = feedFPupUlv.getNumByIx(recUsr.ixMsdcVUserlevel);
	contiac.TxfPwd = recUsr.Password;
	contiac.TxfFky = recUsr.Fullkey;
	contiac.TxfCmt = recUsr.Comment;

	statshr.TxtPrsActive = evalTxtPrsActive(dbsmsdc);
	statshr.ButPrsViewAvail = evalButPrsViewAvail(dbsmsdc);
	statshr.ButPrsViewActive = evalButPrsViewActive(dbsmsdc);
	statshr.TxtSrfActive = evalTxtSrfActive(dbsmsdc);
	statshr.TxtUsgActive = evalTxtUsgActive(dbsmsdc);
	statshr.ButUsgViewAvail = evalButUsgViewAvail(dbsmsdc);
	statshr.ButUsgViewActive = evalButUsgViewActive(dbsmsdc);
	statshr.PupSteActive = evalPupSteActive(dbsmsdc);
	statshr.PupLclActive = evalPupLclActive(dbsmsdc);
	statshr.PupUlvActive = evalPupUlvActive(dbsmsdc);
	statshr.TxfPwdActive = evalTxfPwdActive(dbsmsdc);
	statshr.TxfFkyActive = evalTxfFkyActive(dbsmsdc);
	statshr.TxfCmtActive = evalTxfCmtActive(dbsmsdc);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlMsdcUsrDetail::refreshRecUsrJste(
			DbsMsdc* dbsmsdc
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	MsdcJMUserState* _recUsrJste = NULL;

	if (dbsmsdc->tblmsdcjmuserstate->loadRecByRef(recUsrJste.ref, &_recUsrJste)) {
		recUsrJste = *_recUsrJste;
		delete _recUsrJste;
	} else recUsrJste = MsdcJMUserState();

	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlMsdcUsrDetail::refresh(
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

void PnlMsdcUsrDetail::updatePreset(
			DbsMsdc* dbsmsdc
			, const uint ixMsdcVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixMsdcVPreset == VecMsdcVPreset::PREMSDCREFUSR) {
		recUsr.ref = xchg->getRefPreset(VecMsdcVPreset::PREMSDCREFUSR, jref);
		refreshRecUsr(dbsmsdc, moditems);

		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlMsdcUsrDetail::handleRequest(
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

		} else if (req->dpchapp->ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCUSRDETAILDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbsmsdc, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCUSRDETAILDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTSAVECLICK) {
					handleDpchAppDoButSaveClick(dbsmsdc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTPRSVIEWCLICK) {
					handleDpchAppDoButPrsViewClick(dbsmsdc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTUSGVIEWCLICK) {
					handleDpchAppDoButUsgViewClick(dbsmsdc, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlMsdcUsrDetail::handleDpchAppMsdcInit(
			DbsMsdc* dbsmsdc
			, DpchAppMsdcInit* dpchappmsdcinit
			, DpchEngMsdc** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlMsdcUsrDetail::handleDpchAppDataContiac(
			DbsMsdc* dbsmsdc
			, ContIac* _contiac
			, DpchEngMsdc** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (hasAny(diffitems, {ContIac::NUMFPUPSTE, ContIac::NUMFPUPLCL, ContIac::NUMFPUPULV, ContIac::TXFPWD, ContIac::TXFFKY, ContIac::TXFCMT})) {
		if (has(diffitems, ContIac::NUMFPUPSTE)) contiac.numFPupSte = _contiac->numFPupSte;
		if (has(diffitems, ContIac::NUMFPUPLCL)) contiac.numFPupLcl = _contiac->numFPupLcl;
		if (has(diffitems, ContIac::NUMFPUPULV)) contiac.numFPupUlv = _contiac->numFPupUlv;
		if (has(diffitems, ContIac::TXFPWD)) contiac.TxfPwd = _contiac->TxfPwd;
		if (has(diffitems, ContIac::TXFFKY)) contiac.TxfFky = _contiac->TxfFky;
		if (has(diffitems, ContIac::TXFCMT)) contiac.TxfCmt = _contiac->TxfCmt;
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlMsdcUsrDetail::handleDpchAppDoButSaveClick(
			DbsMsdc* dbsmsdc
			, DpchEngMsdc** dpcheng
		) {
	// IP handleDpchAppDoButSaveClick --- INSERT
};

void PnlMsdcUsrDetail::handleDpchAppDoButPrsViewClick(
			DbsMsdc* dbsmsdc
			, DpchEngMsdc** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	if (statshr.ButPrsViewAvail && statshr.ButPrsViewActive) {
		if (xchg->getIxPreset(VecMsdcVPreset::PREMSDCIXCRDACCPRS, jref)) {
			sref = "CrdMsdcPrs";
			xchg->triggerIxRefSrefIntvalToRefCall(dbsmsdc, VecMsdcVCall::CALLMSDCCRDOPEN, jref, 0, 0, sref, recUsr.refMsdcMPerson, jrefNew);
		};

		if (jrefNew == 0) *dpcheng = new DpchEngMsdcConfirm(false, 0, "");
		else *dpcheng = new DpchEngMsdcConfirm(true, jrefNew, sref);
	};
};

void PnlMsdcUsrDetail::handleDpchAppDoButUsgViewClick(
			DbsMsdc* dbsmsdc
			, DpchEngMsdc** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	if (statshr.ButUsgViewAvail && statshr.ButUsgViewActive) {
		if (xchg->getIxPreset(VecMsdcVPreset::PREMSDCIXCRDACCUSG, jref)) {
			sref = "CrdMsdcUsg";
			xchg->triggerIxRefSrefIntvalToRefCall(dbsmsdc, VecMsdcVCall::CALLMSDCCRDOPEN, jref, 0, 0, sref, recUsr.refMsdcMUsergroup, jrefNew);
		};

		if (jrefNew == 0) *dpcheng = new DpchEngMsdcConfirm(false, 0, "");
		else *dpcheng = new DpchEngMsdcConfirm(true, jrefNew, sref);
	};
};

void PnlMsdcUsrDetail::handleCall(
			DbsMsdc* dbsmsdc
			, Call* call
		) {
	if (call->ixVCall == VecMsdcVCall::CALLMSDCUSR_PRSEQ) {
		call->abort = handleCallMsdcUsr_prsEq(dbsmsdc, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecMsdcVCall::CALLMSDCUSR_USGEQ) {
		call->abort = handleCallMsdcUsr_usgEq(dbsmsdc, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecMsdcVCall::CALLMSDCUSRUPD_REFEQ) {
		call->abort = handleCallMsdcUsrUpd_refEq(dbsmsdc, call->jref, call->argInv.ref);
	} else if (call->ixVCall == VecMsdcVCall::CALLMSDCUSRJSTEMOD_USREQ) {
		call->abort = handleCallMsdcUsrJsteMod_usrEq(dbsmsdc, call->jref, call->argInv.ref);
	};
};

bool PnlMsdcUsrDetail::handleCallMsdcUsr_prsEq(
			DbsMsdc* dbsmsdc
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	// IP handleCallMsdcUsr_prsEq --- BEGIN
	boolvalRet = (recUsr.refMsdcMPerson == refInv);
	// IP handleCallMsdcUsr_prsEq --- END
	return retval;
};

bool PnlMsdcUsrDetail::handleCallMsdcUsr_usgEq(
			DbsMsdc* dbsmsdc
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	// IP handleCallMsdcUsr_usgEq --- BEGIN
	boolvalRet = (recUsr.refMsdcMUsergroup == refInv);
	// IP handleCallMsdcUsr_usgEq --- END
	return retval;
};

bool PnlMsdcUsrDetail::handleCallMsdcUsrUpd_refEq(
			DbsMsdc* dbsmsdc
			, const ubigint jrefTrig
			, const ubigint refInv
		) {
	bool retval = false;
	// IP handleCallMsdcUsrUpd_refEq --- INSERT
	return retval;
};

bool PnlMsdcUsrDetail::handleCallMsdcUsrJsteMod_usrEq(
			DbsMsdc* dbsmsdc
			, const ubigint jrefTrig
			, const ubigint refInv
		) {
	bool retval = false;
	// IP handleCallMsdcUsrJsteMod_usrEq --- INSERT
	return retval;
};

