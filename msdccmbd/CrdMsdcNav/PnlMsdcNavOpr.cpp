/**
  * \file PnlMsdcNavOpr.cpp
  * job handler for job PnlMsdcNavOpr (implementation)
  * \author Alexander Wirthmueller
  * \date created: 18 Dec 2018
  * \date modified: 18 Dec 2018
  */

#ifdef MSDCCMBD
	#include <Msdccmbd.h>
#else
	#include <Msdcd.h>
#endif

#include "PnlMsdcNavOpr.h"

#include "PnlMsdcNavOpr_blks.cpp"
#include "PnlMsdcNavOpr_evals.cpp"

/******************************************************************************
 class PnlMsdcNavOpr
 ******************************************************************************/

PnlMsdcNavOpr::PnlMsdcNavOpr(
			XchgMsdc* xchg
			, DbsMsdc* dbsmsdc
			, const ubigint jrefSup
			, const uint ixMsdcVLocale
		) :
			JobMsdc(xchg, VecMsdcVJob::PNLMSDCNAVOPR, jrefSup, ixMsdcVLocale)
		{

	jref = xchg->addJob(this);

	feedFLstDat.tag = "FeedFLstDat";
	feedFLstFil.tag = "FeedFLstFil";
	feedFLstPrd.tag = "FeedFLstPrd";

	// IP constructor.cust1 --- INSERT

	// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	refreshPrd(dbsmsdc, moditems);
	refreshDat(dbsmsdc, moditems);
	refreshFil(dbsmsdc, moditems);
	refresh(dbsmsdc, moditems);

	// IP constructor.cust3 --- INSERT

	xchg->addIxRefClstn(VecMsdcVCall::CALLMSDCHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, VecMsdcVCard::CRDMSDCPRD, xchg->getRefPreset(VecMsdcVPreset::PREMSDCOWN, jref), Clstn::VecVJactype::LOCK);
	xchg->addIxRefClstn(VecMsdcVCall::CALLMSDCHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, VecMsdcVCard::CRDMSDCDAT, xchg->getRefPreset(VecMsdcVPreset::PREMSDCOWN, jref), Clstn::VecVJactype::LOCK);
	xchg->addIxRefClstn(VecMsdcVCall::CALLMSDCHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, VecMsdcVCard::CRDMSDCFIL, xchg->getRefPreset(VecMsdcVPreset::PREMSDCOWN, jref), Clstn::VecVJactype::LOCK);
	
};

PnlMsdcNavOpr::~PnlMsdcNavOpr() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngMsdc* PnlMsdcNavOpr::getNewDpchEng(
			set<uint> items
		) {
	DpchEngMsdc* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngMsdcConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &feedFLstDat, &feedFLstFil, &feedFLstPrd, &statshr, items);
	};

	return dpcheng;
};

void PnlMsdcNavOpr::refreshLstPrd(
			DbsMsdc* dbsmsdc
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstPrdAvail = evalLstPrdAvail(dbsmsdc);
	statshr.ButPrdViewActive = evalButPrdViewActive(dbsmsdc);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlMsdcNavOpr::refreshPrd(
			DbsMsdc* dbsmsdc
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListMsdcHistRMUserUniversal rst;
	MsdcHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstPrd = 0;

	// feedFLstPrd
	feedFLstPrd.clear();

	dbsmsdc->tblmsdchistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecMsdcVPreset::PREMSDCOWN, jref), VecMsdcVCard::CRDMSDCPRD, false, rst);

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];
		feedFLstPrd.appendRefTitles(rec->ref, StubMsdc::getStubPrdStd(dbsmsdc, rec->unvUref, ixMsdcVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTPRD);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstPrd(dbsmsdc, moditems);
};

void PnlMsdcNavOpr::refreshLstDat(
			DbsMsdc* dbsmsdc
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstDatAvail = evalLstDatAvail(dbsmsdc);
	statshr.ButDatViewActive = evalButDatViewActive(dbsmsdc);
	statshr.ButDatNewcrdActive = evalButDatNewcrdActive(dbsmsdc);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlMsdcNavOpr::refreshDat(
			DbsMsdc* dbsmsdc
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListMsdcHistRMUserUniversal rst;
	MsdcHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstDat = 0;

	// feedFLstDat
	feedFLstDat.clear();

	dbsmsdc->tblmsdchistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecMsdcVPreset::PREMSDCOWN, jref), VecMsdcVCard::CRDMSDCDAT, false, rst);

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];
		feedFLstDat.appendRefTitles(rec->ref, StubMsdc::getStubDatStd(dbsmsdc, rec->unvUref, ixMsdcVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTDAT);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstDat(dbsmsdc, moditems);
};

void PnlMsdcNavOpr::refreshLstFil(
			DbsMsdc* dbsmsdc
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstFilAvail = evalLstFilAvail(dbsmsdc);
	statshr.ButFilViewActive = evalButFilViewActive(dbsmsdc);
	statshr.ButFilNewcrdActive = evalButFilNewcrdActive(dbsmsdc);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlMsdcNavOpr::refreshFil(
			DbsMsdc* dbsmsdc
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListMsdcHistRMUserUniversal rst;
	MsdcHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstFil = 0;

	// feedFLstFil
	feedFLstFil.clear();

	dbsmsdc->tblmsdchistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecMsdcVPreset::PREMSDCOWN, jref), VecMsdcVCard::CRDMSDCFIL, false, rst);

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];
		feedFLstFil.appendRefTitles(rec->ref, StubMsdc::getStubFilStd(dbsmsdc, rec->unvUref, ixMsdcVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTFIL);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstFil(dbsmsdc, moditems);
};

void PnlMsdcNavOpr::refresh(
			DbsMsdc* dbsmsdc
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	// IP refresh --- BEGIN
	// statshr
	statshr.ButLivNewcrdAvail = evalButLivNewcrdAvail(dbsmsdc);
	// IP refresh --- END

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlMsdcNavOpr::updatePreset(
			DbsMsdc* dbsmsdc
			, const uint ixMsdcVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	refresh(dbsmsdc, moditems);

	refreshLstPrd(dbsmsdc, moditems);
	refreshLstDat(dbsmsdc, moditems);
	refreshLstFil(dbsmsdc, moditems);
	if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	// IP updatePreset --- END
};

void PnlMsdcNavOpr::handleRequest(
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

		} else if (req->dpchapp->ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCNAVOPRDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbsmsdc, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCNAVOPRDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTLIVNEWCRDCLICK) {
					handleDpchAppDoButLivNewcrdClick(dbsmsdc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTPRDVIEWCLICK) {
					handleDpchAppDoButPrdViewClick(dbsmsdc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTPRDNEWCRDCLICK) {
					handleDpchAppDoButPrdNewcrdClick(dbsmsdc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTDATVIEWCLICK) {
					handleDpchAppDoButDatViewClick(dbsmsdc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTDATNEWCRDCLICK) {
					handleDpchAppDoButDatNewcrdClick(dbsmsdc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTFILVIEWCLICK) {
					handleDpchAppDoButFilViewClick(dbsmsdc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTFILNEWCRDCLICK) {
					handleDpchAppDoButFilNewcrdClick(dbsmsdc, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlMsdcNavOpr::handleDpchAppMsdcInit(
			DbsMsdc* dbsmsdc
			, DpchAppMsdcInit* dpchappmsdcinit
			, DpchEngMsdc** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlMsdcNavOpr::handleDpchAppDataContiac(
			DbsMsdc* dbsmsdc
			, ContIac* _contiac
			, DpchEngMsdc** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	ubigint ref;

	if (has(diffitems, ContIac::NUMFLSTPRD)) {
		contiac.numFLstPrd = _contiac->numFLstPrd;
		if (dbsmsdc->tblmsdchistrmuseruniversal->loadUnuByRef(feedFLstPrd.getRefByNum(contiac.numFLstPrd), ref)) xchg->triggerIxRefCall(dbsmsdc, VecMsdcVCall::CALLMSDCREFPRESET, jref, VecMsdcVPreset::PREMSDCREFPRD, ref);
		refreshLstPrd(dbsmsdc, moditems);
	};

	if (has(diffitems, ContIac::NUMFLSTDAT)) {
		contiac.numFLstDat = _contiac->numFLstDat;
		if (dbsmsdc->tblmsdchistrmuseruniversal->loadUnuByRef(feedFLstDat.getRefByNum(contiac.numFLstDat), ref)) xchg->triggerIxRefCall(dbsmsdc, VecMsdcVCall::CALLMSDCREFPRESET, jref, VecMsdcVPreset::PREMSDCREFDAT, ref);
		refreshLstDat(dbsmsdc, moditems);
	};

	if (has(diffitems, ContIac::NUMFLSTFIL)) {
		contiac.numFLstFil = _contiac->numFLstFil;
		refreshLstFil(dbsmsdc, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlMsdcNavOpr::handleDpchAppDoButLivNewcrdClick(
			DbsMsdc* dbsmsdc
			, DpchEngMsdc** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbsmsdc, VecMsdcVCall::CALLMSDCCRDOPEN, jref, 0, 0, "CrdMsdcLiv", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngMsdcConfirm(false, 0, "");
	else *dpcheng = new DpchEngMsdcConfirm(true, jrefNew, "CrdMsdcLiv");
};

void PnlMsdcNavOpr::handleDpchAppDoButPrdViewClick(
			DbsMsdc* dbsmsdc
			, DpchEngMsdc** dpcheng
		) {
	MsdcHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstPrdAvail && statshr.ButPrdViewActive) {
		if (dbsmsdc->tblmsdchistrmuseruniversal->loadRecByRef(feedFLstPrd.getRefByNum(contiac.numFLstPrd), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbsmsdc, VecMsdcVCall::CALLMSDCCRDOPEN, jref, husrRunv->ixMsdcVPreset, husrRunv->preUref, "CrdMsdcPrd", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngMsdcConfirm(false, 0, "");
		else *dpcheng = new DpchEngMsdcConfirm(true, jrefNew, "CrdMsdcPrd");
	};
};

void PnlMsdcNavOpr::handleDpchAppDoButPrdNewcrdClick(
			DbsMsdc* dbsmsdc
			, DpchEngMsdc** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbsmsdc, VecMsdcVCall::CALLMSDCCRDOPEN, jref, 0, 0, "CrdMsdcPrd", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngMsdcConfirm(false, 0, "");
	else *dpcheng = new DpchEngMsdcConfirm(true, jrefNew, "CrdMsdcPrd");
};

void PnlMsdcNavOpr::handleDpchAppDoButDatViewClick(
			DbsMsdc* dbsmsdc
			, DpchEngMsdc** dpcheng
		) {
	MsdcHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstDatAvail && statshr.ButDatViewActive) {
		if (dbsmsdc->tblmsdchistrmuseruniversal->loadRecByRef(feedFLstDat.getRefByNum(contiac.numFLstDat), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbsmsdc, VecMsdcVCall::CALLMSDCCRDOPEN, jref, husrRunv->ixMsdcVPreset, husrRunv->preUref, "CrdMsdcDat", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngMsdcConfirm(false, 0, "");
		else *dpcheng = new DpchEngMsdcConfirm(true, jrefNew, "CrdMsdcDat");
	};
};

void PnlMsdcNavOpr::handleDpchAppDoButDatNewcrdClick(
			DbsMsdc* dbsmsdc
			, DpchEngMsdc** dpcheng
		) {
	ubigint jrefNew = 0;

	if (statshr.ButDatNewcrdActive) {
		xchg->triggerIxRefSrefIntvalToRefCall(dbsmsdc, VecMsdcVCall::CALLMSDCCRDOPEN, jref, 0, 0, "CrdMsdcDat", 0, jrefNew);

		if (jrefNew == 0) *dpcheng = new DpchEngMsdcConfirm(false, 0, "");
		else *dpcheng = new DpchEngMsdcConfirm(true, jrefNew, "CrdMsdcDat");
	};
};

void PnlMsdcNavOpr::handleDpchAppDoButFilViewClick(
			DbsMsdc* dbsmsdc
			, DpchEngMsdc** dpcheng
		) {
	MsdcHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstFilAvail && statshr.ButFilViewActive) {
		if (dbsmsdc->tblmsdchistrmuseruniversal->loadRecByRef(feedFLstFil.getRefByNum(contiac.numFLstFil), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbsmsdc, VecMsdcVCall::CALLMSDCCRDOPEN, jref, husrRunv->ixMsdcVPreset, husrRunv->preUref, "CrdMsdcFil", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngMsdcConfirm(false, 0, "");
		else *dpcheng = new DpchEngMsdcConfirm(true, jrefNew, "CrdMsdcFil");
	};
};

void PnlMsdcNavOpr::handleDpchAppDoButFilNewcrdClick(
			DbsMsdc* dbsmsdc
			, DpchEngMsdc** dpcheng
		) {
	ubigint jrefNew = 0;

	if (statshr.ButFilNewcrdActive) {
		xchg->triggerIxRefSrefIntvalToRefCall(dbsmsdc, VecMsdcVCall::CALLMSDCCRDOPEN, jref, 0, 0, "CrdMsdcFil", 0, jrefNew);

		if (jrefNew == 0) *dpcheng = new DpchEngMsdcConfirm(false, 0, "");
		else *dpcheng = new DpchEngMsdcConfirm(true, jrefNew, "CrdMsdcFil");
	};
};

void PnlMsdcNavOpr::handleCall(
			DbsMsdc* dbsmsdc
			, Call* call
		) {
	if (call->ixVCall == VecMsdcVCall::CALLMSDCHUSRRUNVMOD_CRDUSREQ) {
		call->abort = handleCallMsdcHusrRunvMod_crdUsrEq(dbsmsdc, call->jref, call->argInv.ix, call->argInv.ref);
	};
};

bool PnlMsdcNavOpr::handleCallMsdcHusrRunvMod_crdUsrEq(
			DbsMsdc* dbsmsdc
			, const ubigint jrefTrig
			, const uint ixInv
			, const ubigint refInv
		) {
	bool retval = false;
	set<uint> moditems;

	if (ixInv == VecMsdcVCard::CRDMSDCPRD) {
		refreshPrd(dbsmsdc, moditems);
	} else if (ixInv == VecMsdcVCard::CRDMSDCDAT) {
		refreshDat(dbsmsdc, moditems);
	} else if (ixInv == VecMsdcVCard::CRDMSDCFIL) {
		refreshFil(dbsmsdc, moditems);
	};

	xchg->submitDpch(getNewDpchEng(moditems));
	return retval;
};

