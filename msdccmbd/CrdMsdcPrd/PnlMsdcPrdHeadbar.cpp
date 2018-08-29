/**
  * \file PnlMsdcPrdHeadbar.cpp
  * job handler for job PnlMsdcPrdHeadbar (implementation)
  * \author Alexander Wirthmueller
  * \date created: 29 Aug 2018
  * \date modified: 29 Aug 2018
  */

#ifdef MSDCCMBD
	#include <Msdccmbd.h>
#else
	#include <Msdcd.h>
#endif

#include "PnlMsdcPrdHeadbar.h"

#include "PnlMsdcPrdHeadbar_blks.cpp"

/******************************************************************************
 class PnlMsdcPrdHeadbar
 ******************************************************************************/

PnlMsdcPrdHeadbar::PnlMsdcPrdHeadbar(
			XchgMsdc* xchg
			, DbsMsdc* dbsmsdc
			, const ubigint jrefSup
			, const uint ixMsdcVLocale
		) :
			JobMsdc(xchg, VecMsdcVJob::PNLMSDCPRDHEADBAR, jrefSup, ixMsdcVLocale)
		{

	jref = xchg->addJob(this);

	// IP constructor.cust1 --- INSERT

	// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	refresh(dbsmsdc, moditems);

	// IP constructor.cust3 --- INSERT

	
};

PnlMsdcPrdHeadbar::~PnlMsdcPrdHeadbar() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngMsdc* PnlMsdcPrdHeadbar::getNewDpchEng(
			set<uint> items
		) {
	DpchEngMsdc* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngMsdcConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, items);
	};

	return dpcheng;
};

void PnlMsdcPrdHeadbar::refresh(
			DbsMsdc* dbsmsdc
			, set<uint>& moditems
		) {
};

void PnlMsdcPrdHeadbar::handleRequest(
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

		};
	};
};

void PnlMsdcPrdHeadbar::handleDpchAppMsdcInit(
			DbsMsdc* dbsmsdc
			, DpchAppMsdcInit* dpchappmsdcinit
			, DpchEngMsdc** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

