/**
  * \file PnlMsdcLivVideo.cpp
  * job handler for job PnlMsdcLivVideo (implementation)
  * \author Alexander Wirthmueller
  * \date created: 18 Dec 2018
  * \date modified: 18 Dec 2018
  */

#ifdef MSDCCMBD
	#include <Msdccmbd.h>
#else
	#include <Msdcd.h>
#endif

#include "PnlMsdcLivVideo.h"

#include "PnlMsdcLivVideo_blks.cpp"
#include "PnlMsdcLivVideo_evals.cpp"

/******************************************************************************
 class PnlMsdcLivVideo
 ******************************************************************************/

PnlMsdcLivVideo::PnlMsdcLivVideo(
			XchgMsdc* xchg
			, DbsMsdc* dbsmsdc
			, const ubigint jrefSup
			, const uint ixMsdcVLocale
		) :
			JobMsdc(xchg, VecMsdcVJob::PNLMSDCLIVVIDEO, jrefSup, ixMsdcVLocale)
		{

	jref = xchg->addJob(this);

	feedFLstFst.tag = "FeedFLstFst";
	feedFPupRes.tag = "FeedFPupRes";
	feedFPupSrc.tag = "FeedFPupSrc";
	VecVSource::fillFeed(ixMsdcVLocale, feedFPupSrc);

	acqlwir = NULL;
	acqvisl = NULL;
	acqvisr = NULL;
	prcstereo = NULL;

	// IP constructor.cust1 --- IBEGIN
///
	VecMsdcVCamres::fillFeed(ixMsdcVLocale, feedFPupRes);

	ixVSource = 0;

	red = NULL;
	green = NULL;
	blue = NULL;
	gray = NULL;

	fnew = 0;
	fps = 0.0;
	// IP constructor.cust1 --- IEND

	acqlwir = new JobMsdcAcqLwir(xchg, dbsmsdc, jref, ixMsdcVLocale, false);
	acqvisl = new JobMsdcAcqVisl(xchg, dbsmsdc, jref, ixMsdcVLocale, false);
	acqvisr = new JobMsdcAcqVisr(xchg, dbsmsdc, jref, ixMsdcVLocale, false);
	prcstereo = new JobMsdcPrcStereo(xchg, dbsmsdc, jref, ixMsdcVLocale, false);

	// IP constructor.cust2 --- IBEGIN
	changeSource(dbsmsdc, VecVSource::VOID);
	// IP constructor.cust2 --- IEND

	set<uint> moditems;
	refresh(dbsmsdc, moditems);

	xchg->addClstn(VecMsdcVCall::CALLMSDCIMGRDY, jref, Clstn::VecVJobmask::IMM, 0, Arg(), Clstn::VecVJactype::TRY);
	xchg->addClstn(VecMsdcVCall::CALLMSDCMASTSLVCHG, jref, Clstn::VecVJobmask::IMM, 0, Arg(), Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecMsdcVCall::CALLMSDCSGECHG, jref, Clstn::VecVJobmask::IMM, 0, Arg(), Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	
};

PnlMsdcLivVideo::~PnlMsdcLivVideo() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- IBEGIN
	if (red) delete red;
	if (green) delete green;
	if (blue) delete blue;
	if (gray) delete gray;
	// IP destructor.cust --- IEND

	xchg->removeJobByJref(jref);
};

// IP cust --- IBEGIN
void PnlMsdcLivVideo::changeSource(
			DbsMsdc* dbsmsdc
			, const uint _ixVSource
		) {
	if (_ixVSource != ixVSource) {
		if (ixVSource == VecVSource::VISL) acqvisl->stop(dbsmsdc);
		else if (ixVSource == VecVSource::VISR) acqvisr->stop(dbsmsdc);
		else if (ixVSource == VecVSource::LWIR) acqlwir->stop(dbsmsdc);

		ixVSource = 0;

		if (_ixVSource == VecVSource::VISL) {
			if (red) delete red;
			red = new Snippet(VecMsdcVCamres::_640, VecMsdcVChannel::RED8);
			if (green) delete green;
			green = new Snippet(VecMsdcVCamres::_640, VecMsdcVChannel::GREEN8);
			if (blue) delete blue;
			blue = new Snippet(VecMsdcVCamres::_640, VecMsdcVChannel::BLUE8);

			acqvisl->snippets = {red,green,blue};

		} else if (_ixVSource == VecVSource::VISR) {
			if (red) delete red;
			red = new Snippet(VecMsdcVCamres::_640, VecMsdcVChannel::RED8);
			if (green) delete green;
			green = new Snippet(VecMsdcVCamres::_640, VecMsdcVChannel::GREEN8);
			if (blue) delete blue;
			blue = new Snippet(VecMsdcVCamres::_640, VecMsdcVChannel::BLUE8);

			acqvisr->snippets = {red,green,blue};

		} else if (_ixVSource == VecVSource::LWIR) {
			if (gray) delete gray;
			gray = new Snippet(VecMsdcVCamres::_160, VecMsdcVChannel::GRAY16);

			acqlwir->snippets = {gray};
		};

		ixVSource = _ixVSource;
	};
};

void PnlMsdcLivVideo::refreshLive(
			DbsMsdc* dbsmsdc
			, set<uint>& moditems
		) {
/*
	ostringstream str;

	// continf
	ContInf oldContinf(continf);

	if (started()) {
		str.str("");
		str << VecVSource::getTitle(ixVSource, ixMsdcVLocale);

		if (ixMsdcVLocale == VecMsdcVLocale::ENUS) str << " is running at ";
		else if (ixMsdcVLocale == VecMsdcVLocale::DECH) str << " l\\u00e4uft mit ";

		str.precision(1);
		str << fixed << fps << "fps";

		continf.TxtSte = str.str();

	} else {
		if (ixMsdcVLocale == VecMsdcVLocale::ENUS) continf.TxtSte = "idle";
		else if (ixMsdcVLocale == VecMsdcVLocale::DECH) continf.TxtSte = "bereit";
	};

	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
*/
};

bool PnlMsdcLivVideo::started() {
	bool retval = false;

	if (ixVSource == VecVSource::VISL) retval = acqvisl->srd;
	else if (ixVSource == VecVSource::VISR) retval = acqvisr->srd;
	else if (ixVSource == VecVSource::LWIR) retval = acqlwir->srd;

	return retval;
};

// IP cust --- IEND
DpchEngMsdc* PnlMsdcLivVideo::getNewDpchEng(
			set<uint> items
		) {
	DpchEngMsdc* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngMsdcConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &feedFLstFst, &feedFPupRes, &feedFPupSrc, &statshr, items);
	};

	return dpcheng;
};

void PnlMsdcLivVideo::refresh(
			DbsMsdc* dbsmsdc
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	// IP refresh --- RBEGIN

	// contiac
	ContIac oldContiac(contiac);

	if (ixVSource == VecVSource::VISL) contiac.numFPupRes = feedFPupRes.getNumByIx(VecMsdcVCamres::_640);
	else if (ixVSource == VecVSource::VISR) contiac.numFPupRes = feedFPupRes.getNumByIx(VecMsdcVCamres::_640);
	else if (ixVSource == VecVSource::LWIR) contiac.numFPupRes = feedFPupRes.getNumByIx(VecMsdcVCamres::_160);
	else contiac.numFPupRes = feedFPupRes.getNumByIx(VecMsdcVCamres::OFF);

	contiac.SldExt = 0.7;
	contiac.SldFcs = 0.5;

	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	// continf
	ContInf oldContinf(continf);

	if (ixVSource == VecVSource::VISL) continf.ButMasterOn = xchg->getMsjobMastNotSlv(acqvisl);
	else if (ixVSource == VecVSource::VISR) continf.ButMasterOn = xchg->getMsjobMastNotSlv(acqvisr);
	else if (ixVSource == VecVSource::LWIR) continf.ButMasterOn = xchg->getMsjobMastNotSlv(acqlwir);
	else continf.ButMasterOn = true;

	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);

	// statshr
	statshr.PupResAvail = ((ixVSource == VecVSource::VISL) || (ixVSource == VecVSource::VISR));

	statshr.ButStopActive = started();
	statshr.ButPlayActive = ((ixVSource == VecVSource::VISL) || (ixVSource == VecVSource::VISR) || (ixVSource == VecVSource::LWIR)) && !statshr.ButStopActive;

	statshr.SldExtAvail = ((ixVSource == VecVSource::VISL) || (ixVSource == VecVSource::VISR));
	statshr.SldExtActive = continf.ButMasterOn;

	statshr.SldFcsAvail = (((ixVSource == VecVSource::VISL) && (acqvisl->stg.ixMsdcVCamtype == VecMsdcVCamtype::MSLIFE)) || ((ixVSource == VecVSource::VISR) && (acqvisr->stg.ixMsdcVCamtype == VecMsdcVCamtype::MSLIFE)));
	statshr.SldFcsActive = continf.ButMasterOn;
	// IP refresh --- REND

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlMsdcLivVideo::handleRequest(
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

		} else if (req->dpchapp->ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCLIVVIDEODATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbsmsdc, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCLIVVIDEODO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTREGULARIZECLICK) {
					handleDpchAppDoButRegularizeClick(dbsmsdc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTMINIMIZECLICK) {
					handleDpchAppDoButMinimizeClick(dbsmsdc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTMASTERCLICK) {
					handleDpchAppDoButMasterClick(dbsmsdc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTPLAYCLICK) {
					handleDpchAppDoButPlayClick(dbsmsdc, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTSTOPCLICK) {
					handleDpchAppDoButStopClick(dbsmsdc, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlMsdcLivVideo::handleDpchAppMsdcInit(
			DbsMsdc* dbsmsdc
			, DpchAppMsdcInit* dpchappmsdcinit
			, DpchEngMsdc** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlMsdcLivVideo::handleDpchAppDataContiac(
			DbsMsdc* dbsmsdc
			, ContIac* _contiac
			, DpchEngMsdc** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);
	// IP handleDpchAppDataContiac --- IBEGIN

	muteRefresh = true;

	if (has(diffitems, ContIac::NUMFPUPSRC)) {
		// preliminary
		contiac.numFPupSrc = _contiac->numFPupSrc;
		changeSource(dbsmsdc, feedFPupSrc.getIxByNum(contiac.numFPupSrc));
	};


	refresh(dbsmsdc, moditems);

	muteRefresh = false;

	// IP handleDpchAppDataContiac --- IEND
	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlMsdcLivVideo::handleDpchAppDoButRegularizeClick(
			DbsMsdc* dbsmsdc
			, DpchEngMsdc** dpcheng
		) {
	// IP handleDpchAppDoButRegularizeClick --- BEGIN
	statshr.ixMsdcVExpstate = VecMsdcVExpstate::REGD;
	*dpcheng = getNewDpchEng({DpchEngData::STATSHR});
	// IP handleDpchAppDoButRegularizeClick --- END
};

void PnlMsdcLivVideo::handleDpchAppDoButMinimizeClick(
			DbsMsdc* dbsmsdc
			, DpchEngMsdc** dpcheng
		) {
	// IP handleDpchAppDoButMinimizeClick --- BEGIN
	statshr.ixMsdcVExpstate = VecMsdcVExpstate::MIND;
	*dpcheng = getNewDpchEng({DpchEngData::STATSHR});
	// IP handleDpchAppDoButMinimizeClick --- END
};

void PnlMsdcLivVideo::handleDpchAppDoButMasterClick(
			DbsMsdc* dbsmsdc
			, DpchEngMsdc** dpcheng
		) {
	// IP handleDpchAppDoButMasterClick --- IBEGIN
	muteRefresh = true;

	if (!xchg->getMsjobMastNotSlv(acqlwir)) xchg->claimMsjobMaster(dbsmsdc, acqlwir->jref);
	if (!xchg->getMsjobMastNotSlv(acqvisl)) xchg->claimMsjobMaster(dbsmsdc, acqvisl->jref);
	if (!xchg->getMsjobMastNotSlv(acqvisr)) xchg->claimMsjobMaster(dbsmsdc, acqvisr->jref);

	refreshWithDpchEng(dbsmsdc, dpcheng);

	muteRefresh = false;
	// IP handleDpchAppDoButMasterClick --- IEND
};

void PnlMsdcLivVideo::handleDpchAppDoButPlayClick(
			DbsMsdc* dbsmsdc
			, DpchEngMsdc** dpcheng
		) {
	// IP handleDpchAppDoButPlayClick --- IBEGIN
	muteRefresh = true;

	if (ixVSource == VecVSource::VISL) acqvisl->start(dbsmsdc);
	else if (ixVSource == VecVSource::VISR) acqvisr->start(dbsmsdc);
	else if (ixVSource == VecVSource::LWIR) acqlwir->start(dbsmsdc);

	refreshWithDpchEng(dbsmsdc, dpcheng);

	muteRefresh = false;
	// IP handleDpchAppDoButPlayClick --- IEND
};

void PnlMsdcLivVideo::handleDpchAppDoButStopClick(
			DbsMsdc* dbsmsdc
			, DpchEngMsdc** dpcheng
		) {
	// IP handleDpchAppDoButStopClick --- IBEGIN
	muteRefresh = true;

	if (ixVSource == VecVSource::VISL) acqvisl->stop(dbsmsdc);
	else if (ixVSource == VecVSource::VISR) acqvisr->stop(dbsmsdc);
	else if (ixVSource == VecVSource::LWIR) acqlwir->stop(dbsmsdc);

	refreshWithDpchEng(dbsmsdc, dpcheng);

	muteRefresh = false;
	// IP handleDpchAppDoButStopClick --- IEND
};

void PnlMsdcLivVideo::handleCall(
			DbsMsdc* dbsmsdc
			, Call* call
		) {
	if (call->ixVCall == VecMsdcVCall::CALLMSDCIMGRDY) {
		call->abort = handleCallMsdcImgrdy(dbsmsdc, call->jref);
	} else if (call->ixVCall == VecMsdcVCall::CALLMSDCMASTSLVCHG) {
		call->abort = handleCallMsdcMastslvChg(dbsmsdc, call->jref);
	} else if (call->ixVCall == VecMsdcVCall::CALLMSDCSGECHG) {
		call->abort = handleCallMsdcSgeChg(dbsmsdc, call->jref);
	};
};

bool PnlMsdcLivVideo::handleCallMsdcImgrdy(
			DbsMsdc* dbsmsdc
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallMsdcImgrdy --- IBEGIN
	DpchEngLive* dpchlive = NULL;

	set<uint> mask;

//	if (statshr.ixMsdcVExpstate == VecMsdcVExpstate::REGD) {
		if (ixVSource == VecVSource::VISL) {
			if (jrefTrig == acqvisl->jref) {
				fnew++;

				insert(mask, DpchEngLive::RED);
				insert(mask, DpchEngLive::GREEN);
				insert(mask, DpchEngLive::BLUE);
			};
		};

		if (ixVSource == VecVSource::VISR) {
			if (jrefTrig == acqvisr->jref) {
				fnew++;

				insert(mask, DpchEngLive::RED);
				insert(mask, DpchEngLive::GREEN);
				insert(mask, DpchEngLive::BLUE);
			};
		};

		if (ixVSource == VecVSource::LWIR) {
			if (jrefTrig == acqlwir->jref) {
				fnew++;

				insert(mask, DpchEngLive::GRAY);
			};
		};

		if (!mask.empty()) {
			insert(mask, DpchEngLive::JREF);

			dpchlive = new DpchEngLive(jref, NULL, {}, {}, {}, {}, {}, mask);

			if (has(mask, DpchEngLive::RED)) {
				dpchlive->red.resize(red->w*red->h);
				memcpy((void*) dpchlive->red.data(), (void*) red->data, red->w*red->h);
			};
			if (has(mask, DpchEngLive::GREEN)) {
				dpchlive->green.resize(green->w*green->h);
				memcpy((void*) dpchlive->green.data(), (void*) green->data, green->w*green->h);
			};
			if (has(mask, DpchEngLive::BLUE)) {
				dpchlive->blue.resize(blue->w*blue->h);
				memcpy((void*) dpchlive->blue.data(), (void*) blue->data, blue->w*blue->h);
			};
			if (ixVSource == VecVSource::LWIR) {
				dpchlive->gray.resize(gray->w*gray->h);
				memcpy((void*) dpchlive->gray.data(), (void*) gray->data, 2*gray->w*gray->h);
			};

			xchg->submitDpch(dpchlive);
		};
//	};

	// IP handleCallMsdcImgrdy --- IEND
	return retval;
};

bool PnlMsdcLivVideo::handleCallMsdcMastslvChg(
			DbsMsdc* dbsmsdc
			, const ubigint jrefTrig
		) {
	bool retval = false;
	if (!muteRefresh) refreshWithDpchEng(dbsmsdc); // IP handleCallMsdcMastslvChg --- ILINE
	return retval;
};

bool PnlMsdcLivVideo::handleCallMsdcSgeChg(
			DbsMsdc* dbsmsdc
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallMsdcSgeChg --- IBEGIN

	bool toidle = false;

	if (ixVSource == VecVSource::VISL) toidle = ((jrefTrig == acqvisl->jref) && !acqvisl->srd);
	else if (ixVSource == VecVSource::VISR) toidle = ((jrefTrig == acqvisr->jref) && !acqvisr->srd);
	else if (ixVSource == VecVSource::LWIR) toidle = ((jrefTrig == acqlwir->jref) && !acqlwir->srd);

	if (toidle) {
		invalidateWakeups();
		if (!muteRefresh) refreshWithDpchEng(dbsmsdc);
	};

	// IP handleCallMsdcSgeChg --- IEND
	return retval;
};



