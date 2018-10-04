/**
  * \file DlgMsdcNavLoaini.cpp
  * job handler for job DlgMsdcNavLoaini (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Oct 2018
  * \date modified: 4 Oct 2018
  */

#ifdef MSDCCMBD
	#include <Msdccmbd.h>
#else
	#include <Msdcd.h>
#endif

#include "DlgMsdcNavLoaini.h"

#include "DlgMsdcNavLoaini_blks.cpp"
#include "DlgMsdcNavLoaini_evals.cpp"

/******************************************************************************
 class DlgMsdcNavLoaini
 ******************************************************************************/

DlgMsdcNavLoaini::DlgMsdcNavLoaini(
			XchgMsdc* xchg
			, DbsMsdc* dbsmsdc
			, const ubigint jrefSup
			, const uint ixMsdcVLocale
		) :
			JobMsdc(xchg, VecMsdcVJob::DLGMSDCNAVLOAINI, jrefSup, ixMsdcVLocale)
		{

	jref = xchg->addJob(this);

	feedFMcbAlert.tag = "FeedFMcbAlert";
	feedFDse.tag = "FeedFDse";
	VecVDit::fillFeed(ixMsdcVLocale, feedFDse);
	feedFSge.tag = "FeedFSge";
	VecVSge::fillFeed(feedFSge);

	iex = NULL;

	// IP constructor.cust1 --- INSERT

	ixVDit = VecVDit::IFI;

	iex = new IexMsdcIni(xchg, dbsmsdc, jref, ixMsdcVLocale);

	// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	refresh(dbsmsdc, moditems);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
	
};

DlgMsdcNavLoaini::~DlgMsdcNavLoaini() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngMsdc* DlgMsdcNavLoaini::getNewDpchEng(
			set<uint> items
		) {
	DpchEngMsdc* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngMsdcConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &continfimp, &continflfi, &feedFDse, &feedFSge, &statshr, &statshrifi, &statshrimp, &statshrlfi, items);
	};

	return dpcheng;
};

void DlgMsdcNavLoaini::refreshIfi(
			DbsMsdc* dbsmsdc
			, set<uint>& moditems
		) {
	StatShrIfi oldStatshrifi(statshrifi);

	// IP refreshIfi --- BEGIN
	// statshrifi
	statshrifi.UldActive = evalIfiUldActive(dbsmsdc);

	// IP refreshIfi --- END
	if (statshrifi.diff(&oldStatshrifi).size() != 0) insert(moditems, DpchEngData::STATSHRIFI);
};

void DlgMsdcNavLoaini::refreshImp(
			DbsMsdc* dbsmsdc
			, set<uint>& moditems
		) {
	ContInfImp oldContinfimp(continfimp);
	StatShrImp oldStatshrimp(statshrimp);

	// IP refreshImp --- RBEGIN
	// continfimp
	continfimp.TxtPrg = getSquawk(dbsmsdc);

	// statshrimp
	statshrimp.ButRunActive = evalImpButRunActive(dbsmsdc);
	statshrimp.ButStoActive = evalImpButStoActive(dbsmsdc);

	// IP refreshImp --- REND
	if (continfimp.diff(&oldContinfimp).size() != 0) insert(moditems, DpchEngData::CONTINFIMP);
	if (statshrimp.diff(&oldStatshrimp).size() != 0) insert(moditems, DpchEngData::STATSHRIMP);
};

void DlgMsdcNavLoaini::refreshLfi(
			DbsMsdc* dbsmsdc
			, set<uint>& moditems
		) {
	StatShrLfi oldStatshrlfi(statshrlfi);
	ContInfLfi oldContinflfi(continflfi);

	// IP refreshLfi --- BEGIN
	// statshrlfi
	statshrlfi.DldActive = evalLfiDldActive(dbsmsdc);

	// continflfi

	// IP refreshLfi --- END
	if (statshrlfi.diff(&oldStatshrlfi).size() != 0) insert(moditems, DpchEngData::STATSHRLFI);
	if (continflfi.diff(&oldContinflfi).size() != 0) insert(moditems, DpchEngData::CONTINFLFI);
};

void DlgMsdcNavLoaini::refresh(
			DbsMsdc* dbsmsdc
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);
	ContIac oldContiac(contiac);
	StatShr oldStatshr(statshr);

	// IP refresh --- BEGIN
	// continf
	continf.numFSge = ixVSge;

	// contiac
	contiac.numFDse = ixVDit;

	// statshr
	statshr.ButDneActive = evalButDneActive(dbsmsdc);

	// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	refreshIfi(dbsmsdc, moditems);
	refreshImp(dbsmsdc, moditems);
	refreshLfi(dbsmsdc, moditems);
};

void DlgMsdcNavLoaini::changeStage(
			DbsMsdc* dbsmsdc
			, uint _ixVSge
			, DpchEngMsdc** dpcheng
		) {
	bool reenter = true;

	do {
		if (ixVSge != _ixVSge) {
			switch (ixVSge) {
				case VecVSge::IDLE: leaveSgeIdle(dbsmsdc); break;
				case VecVSge::PRSIDLE: leaveSgePrsidle(dbsmsdc); break;
				case VecVSge::PARSE: leaveSgeParse(dbsmsdc); break;
				case VecVSge::ALRMSDCPER: leaveSgeAlrMsdcper(dbsmsdc); break;
				case VecVSge::PRSDONE: leaveSgePrsdone(dbsmsdc); break;
				case VecVSge::IMPIDLE: leaveSgeImpidle(dbsmsdc); break;
				case VecVSge::IMPORT: leaveSgeImport(dbsmsdc); break;
				case VecVSge::DONE: leaveSgeDone(dbsmsdc); break;
			};

			setStage(dbsmsdc, _ixVSge);
			reenter = false;
			if (!muteRefresh) refreshWithDpchEng(dbsmsdc, dpcheng); // IP changeStage.refresh1 --- LINE
		};

		switch (_ixVSge) {
			case VecVSge::IDLE: _ixVSge = enterSgeIdle(dbsmsdc, reenter); break;
			case VecVSge::PRSIDLE: _ixVSge = enterSgePrsidle(dbsmsdc, reenter); break;
			case VecVSge::PARSE: _ixVSge = enterSgeParse(dbsmsdc, reenter); break;
			case VecVSge::ALRMSDCPER: _ixVSge = enterSgeAlrMsdcper(dbsmsdc, reenter); break;
			case VecVSge::PRSDONE: _ixVSge = enterSgePrsdone(dbsmsdc, reenter); break;
			case VecVSge::IMPIDLE: _ixVSge = enterSgeImpidle(dbsmsdc, reenter); break;
			case VecVSge::IMPORT: _ixVSge = enterSgeImport(dbsmsdc, reenter); break;
			case VecVSge::DONE: _ixVSge = enterSgeDone(dbsmsdc, reenter); break;
		};

		// IP changeStage.refresh2 --- INSERT
	} while (ixVSge != _ixVSge);
};

uint DlgMsdcNavLoaini::enterSgeIdle(
			DbsMsdc* dbsmsdc
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;
	nextIxVSge = retval;
	// IP enterSgeIdle --- INSERT
	return retval;
};

void DlgMsdcNavLoaini::leaveSgeIdle(
			DbsMsdc* dbsmsdc
		) {
	// IP leaveSgeIdle --- INSERT
};

uint DlgMsdcNavLoaini::enterSgePrsidle(
			DbsMsdc* dbsmsdc
			, const bool reenter
		) {
	uint retval = VecVSge::PRSIDLE;
	nextIxVSge = VecVSge::PARSE;

	wrefLast = xchg->addWakeup(jref, "callback", 0);
	// IP enterSgePrsidle --- INSERT
	return retval;
};

void DlgMsdcNavLoaini::leaveSgePrsidle(
			DbsMsdc* dbsmsdc
		) {
	// IP leaveSgePrsidle --- INSERT
};

uint DlgMsdcNavLoaini::enterSgeParse(
			DbsMsdc* dbsmsdc
			, const bool reenter
		) {
	uint retval = VecVSge::PARSE;
	nextIxVSge = retval;
	// IP enterSgeParse --- IBEGIN
	ifstream ififile;

	char* buf;
	string s;

	bool ifitxt;
	bool ifixml;

	bool success;

	iex->reset();

	// check file type
	ififile.open(infilename.c_str(), ifstream::in);

	buf = new char[16];
	ififile.get(buf, 16);
	s = string(buf);

	ifitxt = (s.find("- ") == 0);
	ifixml = (s.find("<?xml") == 0);

	delete[] buf;
	ififile.close();

	// parse file accordingly
	success = false;

	if (ifitxt) success = iex->readTxtFile(infilename);
	else if (ifixml) success = iex->readXMLFile(infilename);

	if (success) {
		retval = VecVSge::PRSDONE;
	} else {
		if (reqCmd) {
			cout << "\tparse error at line " << iex->lineno << endl;
			retval = VecVSge::IDLE;
		} else {
			retval = VecVSge::ALRMSDCPER;
		};
	};
	// IP enterSgeParse --- IEND
	return retval;
};

void DlgMsdcNavLoaini::leaveSgeParse(
			DbsMsdc* dbsmsdc
		) {
	// IP leaveSgeParse --- INSERT
};

uint DlgMsdcNavLoaini::enterSgeAlrMsdcper(
			DbsMsdc* dbsmsdc
			, const bool reenter
		) {
	uint retval = VecVSge::ALRMSDCPER;
	nextIxVSge = VecVSge::IDLE;
	xchg->submitDpch(AlrMsdc::prepareAlrPer(jref, ixMsdcVLocale, "", feedFMcbAlert)); // IP enterSgeAlrMsdcper --- LINE
	return retval;
};

void DlgMsdcNavLoaini::leaveSgeAlrMsdcper(
			DbsMsdc* dbsmsdc
		) {
	// IP leaveSgeAlrMsdcper --- INSERT
};

uint DlgMsdcNavLoaini::enterSgePrsdone(
			DbsMsdc* dbsmsdc
			, const bool reenter
		) {
	uint retval = VecVSge::PRSDONE;
	nextIxVSge = retval;
	// IP enterSgePrsdone --- INSERT
	return retval;
};

void DlgMsdcNavLoaini::leaveSgePrsdone(
			DbsMsdc* dbsmsdc
		) {
	// IP leaveSgePrsdone --- INSERT
};

uint DlgMsdcNavLoaini::enterSgeImpidle(
			DbsMsdc* dbsmsdc
			, const bool reenter
		) {
	uint retval = VecVSge::IMPIDLE;
	nextIxVSge = VecVSge::IMPORT;

	wrefLast = xchg->addWakeup(jref, "callback", 0);
	// IP enterSgeImpidle --- INSERT
	return retval;
};

void DlgMsdcNavLoaini::leaveSgeImpidle(
			DbsMsdc* dbsmsdc
		) {
	// IP leaveSgeImpidle --- INSERT
};

uint DlgMsdcNavLoaini::enterSgeImport(
			DbsMsdc* dbsmsdc
			, const bool reenter
		) {
	uint retval = VecVSge::IMPORT;
	nextIxVSge = VecVSge::DONE;

	if (!reenter) wrefLast = xchg->addWakeup(jref, "mon", 250000, true);
	iex->import(dbsmsdc); // IP enterSgeImport --- ILINE
	retval = nextIxVSge;
	return retval;
};

void DlgMsdcNavLoaini::leaveSgeImport(
			DbsMsdc* dbsmsdc
		) {
	invalidateWakeups();
	// IP leaveSgeImport --- INSERT
};

uint DlgMsdcNavLoaini::enterSgeDone(
			DbsMsdc* dbsmsdc
			, const bool reenter
		) {
	uint retval = VecVSge::DONE;
	nextIxVSge = retval;
	// IP enterSgeDone --- INSERT
	return retval;
};

void DlgMsdcNavLoaini::leaveSgeDone(
			DbsMsdc* dbsmsdc
		) {
	// IP leaveSgeDone --- INSERT
};

string DlgMsdcNavLoaini::getSquawk(
			DbsMsdc* dbsmsdc
		) {
	string retval;
	// IP getSquawk --- RBEGIN
	if ( (ixVSge == VecVSge::PARSE) || (ixVSge == VecVSge::ALRMSDCPER) || (ixVSge == VecVSge::PRSDONE) || (ixVSge == VecVSge::IMPORT) ) {
		if (ixMsdcVLocale == VecMsdcVLocale::ENUS) {
			if (ixVSge == VecVSge::PARSE) retval = "parsing initialization data";
			else if (ixVSge == VecVSge::ALRMSDCPER) retval = "parse error";
			else if (ixVSge == VecVSge::PRSDONE) retval = "initialization data parsed";
			else if (ixVSge == VecVSge::IMPORT) retval = "importing initialization data (" + to_string(iex->impcnt) + " records added)";
		} else if (ixMsdcVLocale == VecMsdcVLocale::DECH) {
			if (ixVSge == VecVSge::PARSE) retval = "parsing initialization data";
			else if (ixVSge == VecVSge::ALRMSDCPER) retval = "parse error";
			else if (ixVSge == VecVSge::PRSDONE) retval = "initialization data parsed";
			else if (ixVSge == VecVSge::IMPORT) retval = "importing initialization data (" + to_string(iex->impcnt) + " records added)";
		};

	} else {
		retval = VecVSge::getSref(ixVSge);
	};
	// IP getSquawk --- REND
	return retval;
};

void DlgMsdcNavLoaini::handleRequest(
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

		} else if (req->dpchapp->ixMsdcVDpch == VecMsdcVDpch::DPCHAPPDLGMSDCNAVLOAINIDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbsmsdc, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixMsdcVDpch == VecMsdcVDpch::DPCHAPPDLGMSDCNAVLOAINIDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTDNECLICK) {
					handleDpchAppDoButDneClick(dbsmsdc, &(req->dpcheng));
				};

			} else if (dpchappdo->ixVDoImp != 0) {
				if (dpchappdo->ixVDoImp == VecVDoImp::BUTRUNCLICK) {
					handleDpchAppDoImpButRunClick(dbsmsdc, &(req->dpcheng));
				} else if (dpchappdo->ixVDoImp == VecVDoImp::BUTSTOCLICK) {
					handleDpchAppDoImpButStoClick(dbsmsdc, &(req->dpcheng));
				};

			};

		} else if (req->dpchapp->ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCALERT) {
			handleDpchAppMsdcAlert(dbsmsdc, (DpchAppMsdcAlert*) (req->dpchapp), &(req->dpcheng));

		};

	} else if (req->ixVBasetype == ReqMsdc::VecVBasetype::UPLOAD) {
		handleUpload(dbsmsdc, req->filename);

	} else if (req->ixVBasetype == ReqMsdc::VecVBasetype::DOWNLOAD) {
		req->filename = handleDownload(dbsmsdc);

	} else if (req->ixVBasetype == ReqMsdc::VecVBasetype::TIMER) {
		handleTimer(dbsmsdc, req->sref);
	};
};

void DlgMsdcNavLoaini::handleDpchAppMsdcInit(
			DbsMsdc* dbsmsdc
			, DpchAppMsdcInit* dpchappmsdcinit
			, DpchEngMsdc** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void DlgMsdcNavLoaini::handleDpchAppDataContiac(
			DbsMsdc* dbsmsdc
			, ContIac* _contiac
			, DpchEngMsdc** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (has(diffitems, ContIac::NUMFDSE)) {
		if ((_contiac->numFDse >= VecVDit::IFI) && (_contiac->numFDse <= VecVDit::LFI)) ixVDit = _contiac->numFDse;
		refresh(dbsmsdc, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void DlgMsdcNavLoaini::handleDpchAppDoButDneClick(
			DbsMsdc* dbsmsdc
			, DpchEngMsdc** dpcheng
		) {
	// IP handleDpchAppDoButDneClick --- IBEGIN
	if (statshr.ButDneActive) {
		*dpcheng = new DpchEngMsdcConfirm(true, jref, "");
		xchg->triggerCall(dbsmsdc, VecMsdcVCall::CALLMSDCDLGCLOSE, jref);
	};
	// IP handleDpchAppDoButDneClick --- IEND
};

void DlgMsdcNavLoaini::handleDpchAppDoImpButRunClick(
			DbsMsdc* dbsmsdc
			, DpchEngMsdc** dpcheng
		) {
	// IP handleDpchAppDoImpButRunClick --- BEGIN
	if (statshrimp.ButRunActive) {
		if (ixVSge == VecVSge::PRSDONE) {
			changeStage(dbsmsdc, VecVSge::IMPIDLE, dpcheng);
		};
	};
	// IP handleDpchAppDoImpButRunClick --- END
};

void DlgMsdcNavLoaini::handleDpchAppDoImpButStoClick(
			DbsMsdc* dbsmsdc
			, DpchEngMsdc** dpcheng
		) {
	// IP handleDpchAppDoImpButStoClick --- INSERT
};

void DlgMsdcNavLoaini::handleDpchAppMsdcAlert(
			DbsMsdc* dbsmsdc
			, DpchAppMsdcAlert* dpchappmsdcalert
			, DpchEngMsdc** dpcheng
		) {
	if (ixVSge == VecVSge::ALRMSDCPER) changeStage(dbsmsdc, nextIxVSge); // IP handleDpchAppMsdcAlert --- ILINE
};

void DlgMsdcNavLoaini::handleUpload(
			DbsMsdc* dbsmsdc
			, const string& filename
		) {
	// IP handleUpload --- BEGIN
	if (ixVSge == VecVSge::IDLE) {
		infilename = filename; // IP handleUpload.prsidle --- ILINE
		changeStage(dbsmsdc, VecVSge::PRSIDLE);
	};
	// IP handleUpload --- END
};

string DlgMsdcNavLoaini::handleDownload(
			DbsMsdc* dbsmsdc
		) {
	return(""); // IP handleDownload --- LINE
};

void DlgMsdcNavLoaini::handleTimer(
			DbsMsdc* dbsmsdc
			, const string& sref
		) {
	if (ixVSge == VecVSge::PRSIDLE) {
		changeStage(dbsmsdc, nextIxVSge);
	} else if (ixVSge == VecVSge::IMPIDLE) {
		changeStage(dbsmsdc, nextIxVSge);
	} else if ((ixVSge == VecVSge::IMPORT) && (sref == "mon")) {
		wrefLast = xchg->addWakeup(jref, "mon", 250000, true);
		// IP handleTimer.import.mon --- IBEGIN
		set<uint> moditems;
		refresh(dbsmsdc, moditems);
		xchg->submitDpch(getNewDpchEng(moditems));
		// IP handleTimer.import.mon --- IEND
	};
};




