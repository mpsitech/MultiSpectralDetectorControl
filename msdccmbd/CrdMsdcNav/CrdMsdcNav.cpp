/**
  * \file CrdMsdcNav.cpp
  * job handler for job CrdMsdcNav (implementation)
  * \author Alexander Wirthmueller
  * \date created: 29 Aug 2018
  * \date modified: 29 Aug 2018
  */

#ifdef MSDCCMBD
	#include <Msdccmbd.h>
#else
	#include <Msdcd.h>
#endif

#include "CrdMsdcNav.h"

#include "CrdMsdcNav_blks.cpp"
#include "CrdMsdcNav_evals.cpp"

/******************************************************************************
 class CrdMsdcNav
 ******************************************************************************/

CrdMsdcNav::CrdMsdcNav(
			XchgMsdc* xchg
			, DbsMsdc* dbsmsdc
			, const ubigint jrefSup
			, const uint ixMsdcVLocale
		) :
			JobMsdc(xchg, VecMsdcVJob::CRDMSDCNAV, jrefSup, ixMsdcVLocale)
		{

	jref = xchg->addJob(this);

	feedFMcbAlert.tag = "FeedFMcbAlert";
	feedFSge.tag = "FeedFSge";
	VecVSge::fillFeed(feedFSge);

	dlgloaini = NULL;
	pnlheadbar = NULL;
	pnlpre = NULL;
	pnladmin = NULL;
	pnlopr = NULL;

	// IP constructor.cust1 --- INSERT

	set<uint> moditems;
	refresh(dbsmsdc, moditems);

	pnlheadbar = new PnlMsdcNavHeadbar(xchg, dbsmsdc, jref, ixMsdcVLocale);
	pnlpre = new PnlMsdcNavPre(xchg, dbsmsdc, jref, ixMsdcVLocale);
	pnladmin = new PnlMsdcNavAdmin(xchg, dbsmsdc, jref, ixMsdcVLocale);
	pnlopr = new PnlMsdcNavOpr(xchg, dbsmsdc, jref, ixMsdcVLocale);

	// IP constructor.cust2 --- INSERT

	statshr.jrefHeadbar = pnlheadbar->jref;
	statshr.jrefPre = pnlpre->jref;
	statshr.jrefAdmin = pnladmin->jref;
	statshr.jrefOpr = pnlopr->jref;

	changeStage(dbsmsdc, VecVSge::IDLE);

	xchg->addClstn(VecMsdcVCall::CALLMSDCDLGCLOSE, jref, Clstn::VecVJobmask::IMM, 0, Arg(), Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
	
};

CrdMsdcNav::~CrdMsdcNav() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngMsdc* CrdMsdcNav::getNewDpchEng(
			set<uint> items
		) {
	DpchEngMsdc* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngMsdcConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &continf, &feedFSge, &statshr, items);
	};

	return dpcheng;
};

void CrdMsdcNav::refresh(
			DbsMsdc* dbsmsdc
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	// IP refresh --- BEGIN
	string s;
	vector<string> ss;

	// continf
	continf.MrlAppHlp = xchg->helpurl + "/CrdMsdcNav/" + VecMsdcVLocale::getSref(ixMsdcVLocale);

	s = StubMsdc::getStubSesMenu(dbsmsdc, xchg->getRefPreset(VecMsdcVPreset::PREMSDCSESS, jref), ixMsdcVLocale, Stub::VecVNonetype::DASH);
	StrMod::stringToVector(s, ss);

	if (ss.size() == 3) {
		continf.MtxSesSes1 = ss[0];
		continf.MtxSesSes2 = ss[1];
		continf.MtxSesSes3 = ss[2];
	};

	// statshr
	statshr.pnlpreAvail = evalPnlpreAvail(dbsmsdc);
	statshr.pnladminAvail = evalPnladminAvail(dbsmsdc);
	statshr.pnloprAvail = evalPnloprAvail(dbsmsdc);
	statshr.MspCrd1Avail = evalMspCrd1Avail(dbsmsdc);
	statshr.MitCrdUsgAvail = evalMitCrdUsgAvail(dbsmsdc);
	statshr.MitCrdUsrAvail = evalMitCrdUsrAvail(dbsmsdc);
	statshr.MitCrdPrsAvail = evalMitCrdPrsAvail(dbsmsdc);
	statshr.MitCrdScfAvail = evalMitCrdScfAvail(dbsmsdc);
	statshr.MspCrd2Avail = evalMspCrd2Avail(dbsmsdc);
	statshr.MitCrdLivAvail = evalMitCrdLivAvail(dbsmsdc);
	statshr.MitCrdPrdAvail = evalMitCrdPrdAvail(dbsmsdc);
	statshr.MitCrdDatAvail = evalMitCrdDatAvail(dbsmsdc);
	statshr.MitCrdDatActive = evalMitCrdDatActive(dbsmsdc);
	statshr.MitCrdFilAvail = evalMitCrdFilAvail(dbsmsdc);
	statshr.MspApp2Avail = evalMspApp2Avail(dbsmsdc);
	statshr.MitAppLoiAvail = evalMitAppLoiAvail(dbsmsdc);

	// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void CrdMsdcNav::updatePreset(
			DbsMsdc* dbsmsdc
			, const uint ixMsdcVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	refresh(dbsmsdc, moditems);
	if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));

	if (pnlpre) if (jrefTrig != pnlpre->jref) pnlpre->updatePreset(dbsmsdc, ixMsdcVPreset, jrefTrig, notif);
	if (pnladmin) pnladmin->updatePreset(dbsmsdc, ixMsdcVPreset, jrefTrig, notif);
	if (pnlopr) pnlopr->updatePreset(dbsmsdc, ixMsdcVPreset, jrefTrig, notif);
	// IP updatePreset --- END
};

void CrdMsdcNav::changeStage(
			DbsMsdc* dbsmsdc
			, uint _ixVSge
			, DpchEngMsdc** dpcheng
		) {
	bool reenter = true;

	do {
		if (ixVSge != _ixVSge) {
			switch (ixVSge) {
				case VecVSge::IDLE: leaveSgeIdle(dbsmsdc); break;
				case VecVSge::ALRMSDCABT: leaveSgeAlrmsdcabt(dbsmsdc); break;
			};

			setStage(dbsmsdc, _ixVSge);
			reenter = false;
			if (!muteRefresh) refreshWithDpchEng(dbsmsdc, dpcheng); // IP changeStage.refresh1 --- LINE
		};

		switch (_ixVSge) {
			case VecVSge::IDLE: _ixVSge = enterSgeIdle(dbsmsdc, reenter); break;
			case VecVSge::ALRMSDCABT: _ixVSge = enterSgeAlrmsdcabt(dbsmsdc, reenter); break;
		};

		// IP changeStage.refresh2 --- INSERT
	} while (ixVSge != _ixVSge);
};

uint CrdMsdcNav::enterSgeIdle(
			DbsMsdc* dbsmsdc
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;
	nextIxVSge = retval;
	// IP enterSgeIdle --- INSERT
	return retval;
};

void CrdMsdcNav::leaveSgeIdle(
			DbsMsdc* dbsmsdc
		) {
	// IP leaveSgeIdle --- INSERT
};

uint CrdMsdcNav::enterSgeAlrmsdcabt(
			DbsMsdc* dbsmsdc
			, const bool reenter
		) {
	uint retval = VecVSge::ALRMSDCABT;
	nextIxVSge = VecVSge::IDLE;
	xchg->submitDpch(AlrMsdc::prepareAlrAbt(jref, ixMsdcVLocale, feedFMcbAlert)); // IP enterSgeAlrmsdcabt --- LINE
	return retval;
};

void CrdMsdcNav::leaveSgeAlrmsdcabt(
			DbsMsdc* dbsmsdc
		) {
	// IP leaveSgeAlrmsdcabt --- INSERT
};

string CrdMsdcNav::getSquawk(
			DbsMsdc* dbsmsdc
		) {
	string retval;
	// IP getSquawk --- BEGIN
	retval = VecVSge::getSref(ixVSge);
	// IP getSquawk --- END
	return retval;
};

void CrdMsdcNav::handleRequest(
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

		} else if (req->dpchapp->ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCNAVDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::CLOSE) {
					handleDpchAppDoClose(dbsmsdc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITAPPABTCLICK) {
					handleDpchAppDoMitAppAbtClick(dbsmsdc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITSESSPSCLICK) {
					handleDpchAppDoMitSesSpsClick(dbsmsdc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITSESTRMCLICK) {
					handleDpchAppDoMitSesTrmClick(dbsmsdc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDUSGCLICK) {
					handleDpchAppDoMitCrdUsgClick(dbsmsdc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDUSRCLICK) {
					handleDpchAppDoMitCrdUsrClick(dbsmsdc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDPRSCLICK) {
					handleDpchAppDoMitCrdPrsClick(dbsmsdc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDSCFCLICK) {
					handleDpchAppDoMitCrdScfClick(dbsmsdc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDLIVCLICK) {
					handleDpchAppDoMitCrdLivClick(dbsmsdc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDPRDCLICK) {
					handleDpchAppDoMitCrdPrdClick(dbsmsdc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDDATCLICK) {
					handleDpchAppDoMitCrdDatClick(dbsmsdc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDFILCLICK) {
					handleDpchAppDoMitCrdFilClick(dbsmsdc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITAPPLOICLICK) {
					handleDpchAppDoMitAppLoiClick(dbsmsdc, &(req->dpcheng));
				};

			};

		} else if (req->dpchapp->ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCALERT) {
			handleDpchAppMsdcAlert(dbsmsdc, (DpchAppMsdcAlert*) (req->dpchapp), &(req->dpcheng));

		};
	};
};

void CrdMsdcNav::handleDpchAppMsdcInit(
			DbsMsdc* dbsmsdc
			, DpchAppMsdcInit* dpchappmsdcinit
			, DpchEngMsdc** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void CrdMsdcNav::handleDpchAppDoClose(
			DbsMsdc* dbsmsdc
			, DpchEngMsdc** dpcheng
		) {
	muteRefresh = true;

	*dpcheng = new DpchEngMsdcConfirm(true, jref, "");

	xchg->triggerCall(dbsmsdc, VecMsdcVCall::CALLMSDCSUSPSESS, xchg->getRefPreset(VecMsdcVPreset::PREMSDCJREFSESS, jref));
};

void CrdMsdcNav::handleDpchAppDoMitAppAbtClick(
			DbsMsdc* dbsmsdc
			, DpchEngMsdc** dpcheng
		) {
	// IP handleDpchAppDoMitAppAbtClick --- BEGIN
	changeStage(dbsmsdc, VecVSge::ALRMSDCABT, dpcheng);
	// IP handleDpchAppDoMitAppAbtClick --- END
};

void CrdMsdcNav::handleDpchAppDoMitSesSpsClick(
			DbsMsdc* dbsmsdc
			, DpchEngMsdc** dpcheng
		) {
	muteRefresh = true;

	*dpcheng = new DpchEngMsdcConfirm(true, jref, "");

	xchg->triggerCall(dbsmsdc, VecMsdcVCall::CALLMSDCSUSPSESS, xchg->getRefPreset(VecMsdcVPreset::PREMSDCJREFSESS, jref));
};

void CrdMsdcNav::handleDpchAppDoMitSesTrmClick(
			DbsMsdc* dbsmsdc
			, DpchEngMsdc** dpcheng
		) {
	muteRefresh = true;

	*dpcheng = new DpchEngMsdcConfirm(true, jref, "");

	xchg->triggerBoolvalCall(dbsmsdc, VecMsdcVCall::CALLMSDCLOGOUT, xchg->getRefPreset(VecMsdcVPreset::PREMSDCJREFSESS, jref), false);
};

void CrdMsdcNav::handleDpchAppDoMitCrdUsgClick(
			DbsMsdc* dbsmsdc
			, DpchEngMsdc** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbsmsdc, VecMsdcVCall::CALLMSDCCRDOPEN, jref, 0, 0, "CrdMsdcUsg", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngMsdcConfirm(false, 0, "");
	else *dpcheng = new DpchEngMsdcConfirm(true, jrefNew, "CrdMsdcUsg");
};

void CrdMsdcNav::handleDpchAppDoMitCrdUsrClick(
			DbsMsdc* dbsmsdc
			, DpchEngMsdc** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbsmsdc, VecMsdcVCall::CALLMSDCCRDOPEN, jref, 0, 0, "CrdMsdcUsr", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngMsdcConfirm(false, 0, "");
	else *dpcheng = new DpchEngMsdcConfirm(true, jrefNew, "CrdMsdcUsr");
};

void CrdMsdcNav::handleDpchAppDoMitCrdPrsClick(
			DbsMsdc* dbsmsdc
			, DpchEngMsdc** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbsmsdc, VecMsdcVCall::CALLMSDCCRDOPEN, jref, 0, 0, "CrdMsdcPrs", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngMsdcConfirm(false, 0, "");
	else *dpcheng = new DpchEngMsdcConfirm(true, jrefNew, "CrdMsdcPrs");
};

void CrdMsdcNav::handleDpchAppDoMitCrdScfClick(
			DbsMsdc* dbsmsdc
			, DpchEngMsdc** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbsmsdc, VecMsdcVCall::CALLMSDCCRDOPEN, jref, 0, 0, "CrdMsdcScf", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngMsdcConfirm(false, 0, "");
	else *dpcheng = new DpchEngMsdcConfirm(true, jrefNew, "CrdMsdcScf");
};

void CrdMsdcNav::handleDpchAppDoMitCrdLivClick(
			DbsMsdc* dbsmsdc
			, DpchEngMsdc** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbsmsdc, VecMsdcVCall::CALLMSDCCRDOPEN, jref, 0, 0, "CrdMsdcLiv", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngMsdcConfirm(false, 0, "");
	else *dpcheng = new DpchEngMsdcConfirm(true, jrefNew, "CrdMsdcLiv");
};

void CrdMsdcNav::handleDpchAppDoMitCrdPrdClick(
			DbsMsdc* dbsmsdc
			, DpchEngMsdc** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbsmsdc, VecMsdcVCall::CALLMSDCCRDOPEN, jref, 0, 0, "CrdMsdcPrd", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngMsdcConfirm(false, 0, "");
	else *dpcheng = new DpchEngMsdcConfirm(true, jrefNew, "CrdMsdcPrd");
};

void CrdMsdcNav::handleDpchAppDoMitCrdDatClick(
			DbsMsdc* dbsmsdc
			, DpchEngMsdc** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbsmsdc, VecMsdcVCall::CALLMSDCCRDOPEN, jref, 0, 0, "CrdMsdcDat", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngMsdcConfirm(false, 0, "");
	else *dpcheng = new DpchEngMsdcConfirm(true, jrefNew, "CrdMsdcDat");
};

void CrdMsdcNav::handleDpchAppDoMitCrdFilClick(
			DbsMsdc* dbsmsdc
			, DpchEngMsdc** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbsmsdc, VecMsdcVCall::CALLMSDCCRDOPEN, jref, 0, 0, "CrdMsdcFil", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngMsdcConfirm(false, 0, "");
	else *dpcheng = new DpchEngMsdcConfirm(true, jrefNew, "CrdMsdcFil");
};

void CrdMsdcNav::handleDpchAppDoMitAppLoiClick(
			DbsMsdc* dbsmsdc
			, DpchEngMsdc** dpcheng
		) {
	if (!dlgloaini) {
		dlgloaini = new DlgMsdcNavLoaini(xchg, dbsmsdc, jref, ixMsdcVLocale);
		statshr.jrefDlgloaini = dlgloaini->jref;

		*dpcheng = getNewDpchEng({DpchEngData::STATSHR});
	};
};

void CrdMsdcNav::handleDpchAppMsdcAlert(
			DbsMsdc* dbsmsdc
			, DpchAppMsdcAlert* dpchappmsdcalert
			, DpchEngMsdc** dpcheng
		) {
	if (ixVSge == VecVSge::ALRMSDCABT) {
		changeStage(dbsmsdc, VecVSge::IDLE);
	};

	*dpcheng = new DpchEngMsdcConfirm(true, jref, "");
};

void CrdMsdcNav::handleCall(
			DbsMsdc* dbsmsdc
			, Call* call
		) {
	if (call->ixVCall == VecMsdcVCall::CALLMSDCDLGCLOSE) {
		call->abort = handleCallMsdcDlgClose(dbsmsdc, call->jref);
	};
};

bool CrdMsdcNav::handleCallMsdcDlgClose(
			DbsMsdc* dbsmsdc
			, const ubigint jrefTrig
		) {
	bool retval = false;

	if (dlgloaini) {
		delete dlgloaini;
		dlgloaini = NULL;
		statshr.jrefDlgloaini = 0;

		xchg->submitDpch(getNewDpchEng({DpchEngData::STATSHR}));
	};

	return retval;
};

