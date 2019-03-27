/**
  * \file PnlMsdcNavAdmin.cpp
  * job handler for job PnlMsdcNavAdmin (implementation)
  * \author Alexander Wirthmueller
  * \date created: 18 Dec 2018
  * \date modified: 18 Dec 2018
  */

#ifdef MSDCCMBD
	#include <Msdccmbd.h>
#else
	#include <Msdcd.h>
#endif

#include "PnlMsdcNavAdmin.h"

#include "PnlMsdcNavAdmin_blks.cpp"
#include "PnlMsdcNavAdmin_evals.cpp"

/******************************************************************************
 class PnlMsdcNavAdmin
 ******************************************************************************/

PnlMsdcNavAdmin::PnlMsdcNavAdmin(
			XchgMsdc* xchg
			, DbsMsdc* dbsmsdc
			, const ubigint jrefSup
			, const uint ixMsdcVLocale
		) :
			JobMsdc(xchg, VecMsdcVJob::PNLMSDCNAVADMIN, jrefSup, ixMsdcVLocale)
		{

	jref = xchg->addJob(this);

	feedFLstPrs.tag = "FeedFLstPrs";
	feedFLstUsg.tag = "FeedFLstUsg";
	feedFLstUsr.tag = "FeedFLstUsr";

	// IP constructor.cust1 --- INSERT

	// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	refreshUsg(dbsmsdc, moditems);
	refreshUsr(dbsmsdc, moditems);
	refreshPrs(dbsmsdc, moditems);
	refresh(dbsmsdc, moditems);

	// IP constructor.cust3 --- INSERT

	xchg->addIxRefClstn(VecMsdcVCall::CALLMSDCHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, VecMsdcVCard::CRDMSDCUSG, xchg->getRefPreset(VecMsdcVPreset::PREMSDCOWN, jref), Clstn::VecVJactype::LOCK);
	xchg->addIxRefClstn(VecMsdcVCall::CALLMSDCHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, VecMsdcVCard::CRDMSDCUSR, xchg->getRefPreset(VecMsdcVPreset::PREMSDCOWN, jref), Clstn::VecVJactype::LOCK);
	xchg->addIxRefClstn(VecMsdcVCall::CALLMSDCHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, VecMsdcVCard::CRDMSDCPRS, xchg->getRefPreset(VecMsdcVPreset::PREMSDCOWN, jref), Clstn::VecVJactype::LOCK);
	
};

PnlMsdcNavAdmin::~PnlMsdcNavAdmin() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngMsdc* PnlMsdcNavAdmin::getNewDpchEng(
			set<uint> items
		) {
	DpchEngMsdc* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngMsdcConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &feedFLstPrs, &feedFLstUsg, &feedFLstUsr, &statshr, items);
	};

	return dpcheng;
};

void PnlMsdcNavAdmin::refreshLstUsg(
			DbsMsdc* dbsmsdc
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstUsgAvail = evalLstUsgAvail(dbsmsdc);
	statshr.ButUsgViewActive = evalButUsgViewActive(dbsmsdc);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlMsdcNavAdmin::refreshUsg(
			DbsMsdc* dbsmsdc
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListMsdcHistRMUserUniversal rst;
	MsdcHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstUsg = 0;

	// feedFLstUsg
	feedFLstUsg.clear();

	dbsmsdc->tblmsdchistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecMsdcVPreset::PREMSDCOWN, jref), VecMsdcVCard::CRDMSDCUSG, false, rst);

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];
		feedFLstUsg.appendRefTitles(rec->ref, StubMsdc::getStubUsgStd(dbsmsdc, rec->unvUref, ixMsdcVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTUSG);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstUsg(dbsmsdc, moditems);
};

void PnlMsdcNavAdmin::refreshLstUsr(
			DbsMsdc* dbsmsdc
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstUsrAvail = evalLstUsrAvail(dbsmsdc);
	statshr.ButUsrViewActive = evalButUsrViewActive(dbsmsdc);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlMsdcNavAdmin::refreshUsr(
			DbsMsdc* dbsmsdc
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListMsdcHistRMUserUniversal rst;
	MsdcHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstUsr = 0;

	// feedFLstUsr
	feedFLstUsr.clear();

	dbsmsdc->tblmsdchistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecMsdcVPreset::PREMSDCOWN, jref), VecMsdcVCard::CRDMSDCUSR, false, rst);

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];
		feedFLstUsr.appendRefTitles(rec->ref, StubMsdc::getStubUsrStd(dbsmsdc, rec->unvUref, ixMsdcVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTUSR);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstUsr(dbsmsdc, moditems);
};

void PnlMsdcNavAdmin::refreshLstPrs(
			DbsMsdc* dbsmsdc
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstPrsAvail = evalLstPrsAvail(dbsmsdc);
	statshr.ButPrsViewActive = evalButPrsViewActive(dbsmsdc);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlMsdcNavAdmin::refreshPrs(
			DbsMsdc* dbsmsdc
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListMsdcHistRMUserUniversal rst;
	MsdcHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstPrs = 0;

	// feedFLstPrs
	feedFLstPrs.clear();

	dbsmsdc->tblmsdchistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecMsdcVPreset::PREMSDCOWN, jref), VecMsdcVCard::CRDMSDCPRS, false, rst);

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];
		feedFLstPrs.appendRefTitles(rec->ref, StubMsdc::getStubPrsStd(dbsmsdc, rec->unvUref, ixMsdcVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTPRS);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstPrs(dbsmsdc, moditems);
};

void PnlMsdcNavAdmin::refresh(
			DbsMsdc* dbsmsdc
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	// IP refresh --- BEGIN
	// statshr
	statshr.ButScfNewcrdAvail = evalButScfNewcrdAvail(dbsmsdc);
	// IP refresh --- END

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlMsdcNavAdmin::updatePreset(
			DbsMsdc* dbsmsdc
			, const uint ixMsdcVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	refresh(dbsmsdc, moditems);

	refreshLstUsg(dbsmsdc, moditems);
	refreshLstUsr(dbsmsdc, moditems);
	refreshLstPrs(dbsmsdc, moditems);
	if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	// IP updatePreset --- END
};

void PnlMsdcNavAdmin::handleRequest(
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

		} else if (req->dpchapp->ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCNAVADMINDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbsmsdc, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCNAVADMINDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTUSGVIEWCLICK) {
					handleDpchAppDoButUsgViewClick(dbsmsdc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTUSGNEWCRDCLICK) {
					handleDpchAppDoButUsgNewcrdClick(dbsmsdc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTUSRVIEWCLICK) {
					handleDpchAppDoButUsrViewClick(dbsmsdc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTUSRNEWCRDCLICK) {
					handleDpchAppDoButUsrNewcrdClick(dbsmsdc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTPRSVIEWCLICK) {
					handleDpchAppDoButPrsViewClick(dbsmsdc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTPRSNEWCRDCLICK) {
					handleDpchAppDoButPrsNewcrdClick(dbsmsdc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTSCFNEWCRDCLICK) {
					handleDpchAppDoButScfNewcrdClick(dbsmsdc, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlMsdcNavAdmin::handleDpchAppMsdcInit(
			DbsMsdc* dbsmsdc
			, DpchAppMsdcInit* dpchappmsdcinit
			, DpchEngMsdc** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlMsdcNavAdmin::handleDpchAppDataContiac(
			DbsMsdc* dbsmsdc
			, ContIac* _contiac
			, DpchEngMsdc** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (has(diffitems, ContIac::NUMFLSTUSG)) {
		contiac.numFLstUsg = _contiac->numFLstUsg;
		refreshLstUsg(dbsmsdc, moditems);
	};

	if (has(diffitems, ContIac::NUMFLSTUSR)) {
		contiac.numFLstUsr = _contiac->numFLstUsr;
		refreshLstUsr(dbsmsdc, moditems);
	};

	if (has(diffitems, ContIac::NUMFLSTPRS)) {
		contiac.numFLstPrs = _contiac->numFLstPrs;
		refreshLstPrs(dbsmsdc, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlMsdcNavAdmin::handleDpchAppDoButUsgViewClick(
			DbsMsdc* dbsmsdc
			, DpchEngMsdc** dpcheng
		) {
	MsdcHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstUsgAvail && statshr.ButUsgViewActive) {
		if (dbsmsdc->tblmsdchistrmuseruniversal->loadRecByRef(feedFLstUsg.getRefByNum(contiac.numFLstUsg), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbsmsdc, VecMsdcVCall::CALLMSDCCRDOPEN, jref, husrRunv->ixMsdcVPreset, husrRunv->preUref, "CrdMsdcUsg", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngMsdcConfirm(false, 0, "");
		else *dpcheng = new DpchEngMsdcConfirm(true, jrefNew, "CrdMsdcUsg");
	};
};

void PnlMsdcNavAdmin::handleDpchAppDoButUsgNewcrdClick(
			DbsMsdc* dbsmsdc
			, DpchEngMsdc** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbsmsdc, VecMsdcVCall::CALLMSDCCRDOPEN, jref, 0, 0, "CrdMsdcUsg", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngMsdcConfirm(false, 0, "");
	else *dpcheng = new DpchEngMsdcConfirm(true, jrefNew, "CrdMsdcUsg");
};

void PnlMsdcNavAdmin::handleDpchAppDoButUsrViewClick(
			DbsMsdc* dbsmsdc
			, DpchEngMsdc** dpcheng
		) {
	MsdcHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstUsrAvail && statshr.ButUsrViewActive) {
		if (dbsmsdc->tblmsdchistrmuseruniversal->loadRecByRef(feedFLstUsr.getRefByNum(contiac.numFLstUsr), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbsmsdc, VecMsdcVCall::CALLMSDCCRDOPEN, jref, husrRunv->ixMsdcVPreset, husrRunv->preUref, "CrdMsdcUsr", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngMsdcConfirm(false, 0, "");
		else *dpcheng = new DpchEngMsdcConfirm(true, jrefNew, "CrdMsdcUsr");
	};
};

void PnlMsdcNavAdmin::handleDpchAppDoButUsrNewcrdClick(
			DbsMsdc* dbsmsdc
			, DpchEngMsdc** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbsmsdc, VecMsdcVCall::CALLMSDCCRDOPEN, jref, 0, 0, "CrdMsdcUsr", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngMsdcConfirm(false, 0, "");
	else *dpcheng = new DpchEngMsdcConfirm(true, jrefNew, "CrdMsdcUsr");
};

void PnlMsdcNavAdmin::handleDpchAppDoButPrsViewClick(
			DbsMsdc* dbsmsdc
			, DpchEngMsdc** dpcheng
		) {
	MsdcHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstPrsAvail && statshr.ButPrsViewActive) {
		if (dbsmsdc->tblmsdchistrmuseruniversal->loadRecByRef(feedFLstPrs.getRefByNum(contiac.numFLstPrs), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbsmsdc, VecMsdcVCall::CALLMSDCCRDOPEN, jref, husrRunv->ixMsdcVPreset, husrRunv->preUref, "CrdMsdcPrs", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngMsdcConfirm(false, 0, "");
		else *dpcheng = new DpchEngMsdcConfirm(true, jrefNew, "CrdMsdcPrs");
	};
};

void PnlMsdcNavAdmin::handleDpchAppDoButPrsNewcrdClick(
			DbsMsdc* dbsmsdc
			, DpchEngMsdc** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbsmsdc, VecMsdcVCall::CALLMSDCCRDOPEN, jref, 0, 0, "CrdMsdcPrs", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngMsdcConfirm(false, 0, "");
	else *dpcheng = new DpchEngMsdcConfirm(true, jrefNew, "CrdMsdcPrs");
};

void PnlMsdcNavAdmin::handleDpchAppDoButScfNewcrdClick(
			DbsMsdc* dbsmsdc
			, DpchEngMsdc** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbsmsdc, VecMsdcVCall::CALLMSDCCRDOPEN, jref, 0, 0, "CrdMsdcScf", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngMsdcConfirm(false, 0, "");
	else *dpcheng = new DpchEngMsdcConfirm(true, jrefNew, "CrdMsdcScf");
};

void PnlMsdcNavAdmin::handleCall(
			DbsMsdc* dbsmsdc
			, Call* call
		) {
	if (call->ixVCall == VecMsdcVCall::CALLMSDCHUSRRUNVMOD_CRDUSREQ) {
		call->abort = handleCallMsdcHusrRunvMod_crdUsrEq(dbsmsdc, call->jref, call->argInv.ix, call->argInv.ref);
	};
};

bool PnlMsdcNavAdmin::handleCallMsdcHusrRunvMod_crdUsrEq(
			DbsMsdc* dbsmsdc
			, const ubigint jrefTrig
			, const uint ixInv
			, const ubigint refInv
		) {
	bool retval = false;
	set<uint> moditems;

	if (ixInv == VecMsdcVCard::CRDMSDCUSG) {
		refreshUsg(dbsmsdc, moditems);
	} else if (ixInv == VecMsdcVCard::CRDMSDCUSR) {
		refreshUsr(dbsmsdc, moditems);
	} else if (ixInv == VecMsdcVCard::CRDMSDCPRS) {
		refreshPrs(dbsmsdc, moditems);
	};

	xchg->submitDpch(getNewDpchEng(moditems));
	return retval;
};

