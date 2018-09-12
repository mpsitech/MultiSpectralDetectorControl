/**
  * \file DlgMsdcFilDownload.cpp
  * job handler for job DlgMsdcFilDownload (implementation)
  * \author Alexander Wirthmueller
  * \date created: 12 Sep 2018
  * \date modified: 12 Sep 2018
  */

#ifdef MSDCCMBD
	#include <Msdccmbd.h>
#else
	#include <Msdcd.h>
#endif

#include "DlgMsdcFilDownload.h"

#include "DlgMsdcFilDownload_blks.cpp"

/******************************************************************************
 class DlgMsdcFilDownload
 ******************************************************************************/

DlgMsdcFilDownload::DlgMsdcFilDownload(
			XchgMsdc* xchg
			, DbsMsdc* dbsmsdc
			, const ubigint jrefSup
			, const uint ixMsdcVLocale
		) :
			JobMsdc(xchg, VecMsdcVJob::DLGMSDCFILDOWNLOAD, jrefSup, ixMsdcVLocale)
		{

	jref = xchg->addJob(this);

	// IP constructor.cust1 --- INSERT

	// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	refresh(dbsmsdc, moditems);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
	
};

DlgMsdcFilDownload::~DlgMsdcFilDownload() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngMsdc* DlgMsdcFilDownload::getNewDpchEng(
			set<uint> items
		) {
	DpchEngMsdc* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngMsdcConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &continf, items);
	};

	return dpcheng;
};

void DlgMsdcFilDownload::refresh(
			DbsMsdc* dbsmsdc
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);

	// IP refresh --- RBEGIN
	// continf
	continf.Dld = StubMsdc::getStubFilStd(dbsmsdc, xchg->getRefPreset(VecMsdcVPreset::PREMSDCREFFIL, jref));

	// IP refresh --- REND
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
};

void DlgMsdcFilDownload::handleRequest(
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

		} else if (req->dpchapp->ixMsdcVDpch == VecMsdcVDpch::DPCHAPPDLGMSDCFILDOWNLOADDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTDNECLICK) {
					handleDpchAppDoButDneClick(dbsmsdc, &(req->dpcheng));
				};

			};

		};

	} else if (req->ixVBasetype == ReqMsdc::VecVBasetype::DOWNLOAD) {
		req->filename = handleDownload(dbsmsdc);
	};
};

void DlgMsdcFilDownload::handleDpchAppMsdcInit(
			DbsMsdc* dbsmsdc
			, DpchAppMsdcInit* dpchappmsdcinit
			, DpchEngMsdc** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void DlgMsdcFilDownload::handleDpchAppDoButDneClick(
			DbsMsdc* dbsmsdc
			, DpchEngMsdc** dpcheng
		) {
	// IP handleDpchAppDoButDneClick --- IBEGIN
	*dpcheng = new DpchEngMsdcConfirm(true, jref, "");
	xchg->triggerCall(dbsmsdc, VecMsdcVCall::CALLMSDCDLGCLOSE, jref);
	// IP handleDpchAppDoButDneClick --- IEND
};

string DlgMsdcFilDownload::handleDownload(
			DbsMsdc* dbsmsdc
		) {
	// IP handleDownload --- RBEGIN
	string retval;

	retval = Acv::getfile(dbsmsdc, xchg->getRefPreset(VecMsdcVPreset::PREMSDCREFFIL, jref));
	if (retval != "") retval = xchg->acvpath + "/" + retval;

	return retval;
	// IP handleDownload --- REND
};



