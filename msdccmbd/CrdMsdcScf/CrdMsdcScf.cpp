/**
  * \file CrdMsdcScf.cpp
  * job handler for job CrdMsdcScf (implementation)
  * \author Alexander Wirthmueller
  * \date created: 12 Sep 2018
  * \date modified: 12 Sep 2018
  */

#ifdef MSDCCMBD
	#include <Msdccmbd.h>
#else
	#include <Msdcd.h>
#endif

#include "CrdMsdcScf.h"

#include "CrdMsdcScf_blks.cpp"

/******************************************************************************
 class CrdMsdcScf
 ******************************************************************************/

CrdMsdcScf::CrdMsdcScf(
			XchgMsdc* xchg
			, DbsMsdc* dbsmsdc
			, const ubigint jrefSup
			, const uint ixMsdcVLocale
		) :
			JobMsdc(xchg, VecMsdcVJob::CRDMSDCSCF, jrefSup, ixMsdcVLocale)
		{

	jref = xchg->addJob(this);

	feedFMcbAlert.tag = "FeedFMcbAlert";
	feedFSge.tag = "FeedFSge";
	VecVSge::fillFeed(feedFSge);

	pnlsource = NULL;
	pnlacquis = NULL;
	pnlactu = NULL;
	pnlprcctl = NULL;
	pnlheadbar = NULL;

	// IP constructor.cust1 --- INSERT

	set<uint> moditems;
	refresh(dbsmsdc, moditems);

	pnlsource = new PnlMsdcScfSource(xchg, dbsmsdc, jref, ixMsdcVLocale);
	pnlacquis = new PnlMsdcScfAcquis(xchg, dbsmsdc, jref, ixMsdcVLocale);
	pnlactu = new PnlMsdcScfActu(xchg, dbsmsdc, jref, ixMsdcVLocale);
	pnlprcctl = new PnlMsdcScfPrcctl(xchg, dbsmsdc, jref, ixMsdcVLocale);
	pnlheadbar = new PnlMsdcScfHeadbar(xchg, dbsmsdc, jref, ixMsdcVLocale);

	// IP constructor.cust2 --- INSERT

	statshr.jrefSource = pnlsource->jref;
	statshr.jrefAcquis = pnlacquis->jref;
	statshr.jrefActu = pnlactu->jref;
	statshr.jrefPrcctl = pnlprcctl->jref;
	statshr.jrefHeadbar = pnlheadbar->jref;

	changeStage(dbsmsdc, VecVSge::IDLE);

	xchg->addClstn(VecMsdcVCall::CALLMSDCDLGCLOSE, jref, Clstn::VecVJobmask::IMM, 0, Arg(), Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
	
};

CrdMsdcScf::~CrdMsdcScf() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngMsdc* CrdMsdcScf::getNewDpchEng(
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

void CrdMsdcScf::refresh(
			DbsMsdc* dbsmsdc
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);

	// IP refresh --- BEGIN
	// continf
	continf.MrlAppHlp = xchg->helpurl + "/CrdMsdcScf/" + VecMsdcVLocale::getSref(ixMsdcVLocale);

	// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
};

void CrdMsdcScf::updatePreset(
			DbsMsdc* dbsmsdc
			, const uint ixMsdcVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- INSERT
};

void CrdMsdcScf::changeStage(
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

uint CrdMsdcScf::enterSgeIdle(
			DbsMsdc* dbsmsdc
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;
	nextIxVSge = retval;
	// IP enterSgeIdle --- INSERT
	return retval;
};

void CrdMsdcScf::leaveSgeIdle(
			DbsMsdc* dbsmsdc
		) {
	// IP leaveSgeIdle --- INSERT
};

uint CrdMsdcScf::enterSgeAlrmsdcabt(
			DbsMsdc* dbsmsdc
			, const bool reenter
		) {
	uint retval = VecVSge::ALRMSDCABT;
	nextIxVSge = VecVSge::IDLE;
	xchg->submitDpch(AlrMsdc::prepareAlrAbt(jref, ixMsdcVLocale, feedFMcbAlert)); // IP enterSgeAlrmsdcabt --- LINE
	return retval;
};

void CrdMsdcScf::leaveSgeAlrmsdcabt(
			DbsMsdc* dbsmsdc
		) {
	// IP leaveSgeAlrmsdcabt --- INSERT
};

string CrdMsdcScf::getSquawk(
			DbsMsdc* dbsmsdc
		) {
	string retval;
	// IP getSquawk --- BEGIN
	retval = VecVSge::getSref(ixVSge);
	// IP getSquawk --- END
	return retval;
};

void CrdMsdcScf::handleRequest(
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

		} else if (req->dpchapp->ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCSCFDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::CLOSE) {
					handleDpchAppDoClose(dbsmsdc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITAPPABTCLICK) {
					handleDpchAppDoMitAppAbtClick(dbsmsdc, &(req->dpcheng));
				};

			};

		} else if (req->dpchapp->ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCALERT) {
			handleDpchAppMsdcAlert(dbsmsdc, (DpchAppMsdcAlert*) (req->dpchapp), &(req->dpcheng));

		};
	};
};

void CrdMsdcScf::handleDpchAppMsdcInit(
			DbsMsdc* dbsmsdc
			, DpchAppMsdcInit* dpchappmsdcinit
			, DpchEngMsdc** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void CrdMsdcScf::handleDpchAppDoClose(
			DbsMsdc* dbsmsdc
			, DpchEngMsdc** dpcheng
		) {
	muteRefresh = true;

	*dpcheng = new DpchEngMsdcConfirm(true, jref, "");
	xchg->triggerIxCall(dbsmsdc, VecMsdcVCall::CALLMSDCCRDCLOSE, jref, VecMsdcVCard::CRDMSDCSCF);
};

void CrdMsdcScf::handleDpchAppDoMitAppAbtClick(
			DbsMsdc* dbsmsdc
			, DpchEngMsdc** dpcheng
		) {
	// IP handleDpchAppDoMitAppAbtClick --- BEGIN
	changeStage(dbsmsdc, VecVSge::ALRMSDCABT, dpcheng);
	// IP handleDpchAppDoMitAppAbtClick --- END
};

void CrdMsdcScf::handleDpchAppMsdcAlert(
			DbsMsdc* dbsmsdc
			, DpchAppMsdcAlert* dpchappmsdcalert
			, DpchEngMsdc** dpcheng
		) {
	if (ixVSge == VecVSge::ALRMSDCABT) {
		changeStage(dbsmsdc, VecVSge::IDLE);
	};

	*dpcheng = new DpchEngMsdcConfirm(true, jref, "");
};

void CrdMsdcScf::handleCall(
			DbsMsdc* dbsmsdc
			, Call* call
		) {
	if (call->ixVCall == VecMsdcVCall::CALLMSDCDLGCLOSE) {
		call->abort = handleCallMsdcDlgClose(dbsmsdc, call->jref);
	};
};

bool CrdMsdcScf::handleCallMsdcDlgClose(
			DbsMsdc* dbsmsdc
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallMsdcDlgClose --- INSERT
	return retval;
};

