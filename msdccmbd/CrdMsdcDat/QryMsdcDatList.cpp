/**
  * \file QryMsdcDatList.cpp
  * job handler for job QryMsdcDatList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 18 Dec 2018
  * \date modified: 18 Dec 2018
  */

#ifdef MSDCCMBD
	#include <Msdccmbd.h>
#else
	#include <Msdcd.h>
#endif

#include "QryMsdcDatList.h"

#include "QryMsdcDatList_blks.cpp"

/******************************************************************************
 class QryMsdcDatList
 ******************************************************************************/

QryMsdcDatList::QryMsdcDatList(
			XchgMsdc* xchg
			, DbsMsdc* dbsmsdc
			, const ubigint jrefSup
			, const uint ixMsdcVLocale
		) :
			JobMsdc(xchg, VecMsdcVJob::QRYMSDCDATLIST, jrefSup, ixMsdcVLocale)
		{

	jref = xchg->addJob(this);

	// IP constructor.cust1 --- INSERT

	xchg->addStmgr(jref, Stub::VecVNonetype::SHORT);
	ixMsdcVQrystate = VecMsdcVQrystate::OOD;

	// IP constructor.cust2 --- INSERT

	rerun(dbsmsdc);

	xchg->addClstn(VecMsdcVCall::CALLMSDCSTUBCHG, jref, Clstn::VecVJobmask::SPEC, jref, Arg(), Clstn::VecVJactype::LOCK);

	xchg->addClstn(VecMsdcVCall::CALLMSDCDATMOD, jref, Clstn::VecVJobmask::ALL, 0, Arg(), Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
	
};

QryMsdcDatList::~QryMsdcDatList() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryMsdcDatList::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecMsdcVPreset::PREMSDCREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);

	xchg->removeClstns(VecMsdcVCall::CALLMSDCDATUPD_REFEQ, jref);
	if (preRefSel != 0) xchg->addRefClstn(VecMsdcVCall::CALLMSDCDATUPD_REFEQ, jref, Clstn::VecVJobmask::ALL, 0, preRefSel, Clstn::VecVJactype::LOCK);
};

void QryMsdcDatList::rerun(
			DbsMsdc* dbsmsdc
			, const bool call
		) {
	string sqlstr;

	vector<ubigint> cnts;
	uint cnt, cntsum;

	vector<ubigint> lims;
	vector<ubigint> ofss;

	uint preIxPre = xchg->getIxPreset(VecMsdcVPreset::PREMSDCIXPRE, jref);
	uint preIxOrd = xchg->getIxPreset(VecMsdcVPreset::PREMSDCIXORD, jref);
	ubigint preRefPrd = xchg->getRefPreset(VecMsdcVPreset::PREMSDCREFPRD, jref);
	string preAft = xchg->getSrefPreset(VecMsdcVPreset::PREMSDCDATLIST_AFT, jref);
	ubigint prePrd = xchg->getRefPreset(VecMsdcVPreset::PREMSDCDATLIST_PRD, jref);
	int preSta = xchg->getIntvalPreset(VecMsdcVPreset::PREMSDCDATLIST_STA, jref);

	dbsmsdc->tblmsdcqselect->removeRstByJref(jref);
	dbsmsdc->tblmsdcqdatlist->removeRstByJref(jref);

	cntsum = 0;

	if (preIxPre == VecMsdcVPreset::PREMSDCREFPRD) {
		sqlstr = "SELECT COUNT(TblMsdcMData.ref)";
		sqlstr += " FROM TblMsdcMData";
		sqlstr += " WHERE TblMsdcMData.refMsdcMPeriod = " + to_string(preRefPrd) + "";
		rerun_filtSQL(sqlstr, preAft, prePrd, preSta, false);
		dbsmsdc->loadUintBySQL(sqlstr, cnt);
		cnts.push_back(cnt); lims.push_back(0); ofss.push_back(0);
		cntsum += cnt;

	} else {
		sqlstr = "SELECT COUNT(TblMsdcMData.ref)";
		sqlstr += " FROM TblMsdcMData";
		rerun_filtSQL(sqlstr, preAft, prePrd, preSta, true);
		dbsmsdc->loadUintBySQL(sqlstr, cnt);
		cnts.push_back(cnt); lims.push_back(0); ofss.push_back(0);
		cntsum += cnt;
	};

	statshr.ntot = 0;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cntsum) {
		if (cntsum >= stgiac.nload) stgiac.jnumFirstload = cntsum-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	for (unsigned int i=0;i<cnts.size();i++) {
		if (statshr.nload < stgiac.nload) {
			if ((statshr.ntot+cnts[i]) >= stgiac.jnumFirstload) {
				if (statshr.ntot >= stgiac.jnumFirstload) {
					ofss[i] = 0;
				} else {
					ofss[i] = stgiac.jnumFirstload-statshr.ntot-1;
				};

				if ((statshr.nload+cnts[i]-ofss[i]) > stgiac.nload) lims[i] = stgiac.nload-statshr.nload;
				else lims[i] = cnts[i]-ofss[i];
			};
		};

		statshr.ntot += cnts[i];
		statshr.nload += lims[i];
	};

	if (preIxPre == VecMsdcVPreset::PREMSDCREFPRD) {
		rerun_baseSQL(sqlstr);
		sqlstr += " FROM TblMsdcMData";
		sqlstr += " WHERE TblMsdcMData.refMsdcMPeriod = " + to_string(preRefPrd) + "";
		rerun_filtSQL(sqlstr, preAft, prePrd, preSta, false);
		rerun_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbsmsdc->executeQuery(sqlstr);

	} else {
		rerun_baseSQL(sqlstr);
		sqlstr += " FROM TblMsdcMData";
		rerun_filtSQL(sqlstr, preAft, prePrd, preSta, true);
		rerun_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbsmsdc->executeQuery(sqlstr);
	};

	sqlstr = "UPDATE TblMsdcQDatList SET jnum = qref WHERE jref = " + to_string(jref);
	dbsmsdc->executeQuery(sqlstr);

	ixMsdcVQrystate = VecMsdcVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsmsdc);

	if (call) xchg->triggerCall(dbsmsdc, VecMsdcVCall::CALLMSDCSTATCHG, jref);

};

void QryMsdcDatList::rerun_baseSQL(
			string& sqlstr
		) {
	sqlstr = "INSERT INTO TblMsdcQDatList(jref, jnum, ref, srefMsdcKAcqfeat, refMsdcMPeriod, start, stop)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblMsdcMData.ref, TblMsdcMData.srefMsdcKAcqfeat, TblMsdcMData.refMsdcMPeriod, TblMsdcMData.start, TblMsdcMData.stop";
};

void QryMsdcDatList::rerun_filtSQL(
			string& sqlstr
			, const string& preAft
			, const ubigint prePrd
			, const int preSta
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preAft.length() > 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblMsdcMData.srefMsdcKAcqfeat = '" + preAft + "'";
	};

	if (prePrd != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblMsdcMData.refMsdcMPeriod = " + to_string(prePrd) + "";
	};

	if (preSta != numeric_limits<int>::min()) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblMsdcMData.start = " + to_string(preSta) + "";
	};
};

void QryMsdcDatList::rerun_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryMsdcDatList::rerun_orderSQL(
			string& sqlstr
			, const uint preIxOrd
		) {
	if (preIxOrd == VecVOrd::AFT) sqlstr += " ORDER BY TblMsdcMData.srefMsdcKAcqfeat ASC";
	else if (preIxOrd == VecVOrd::PRD) sqlstr += " ORDER BY TblMsdcMData.refMsdcMPeriod ASC";
	else if (preIxOrd == VecVOrd::STA) sqlstr += " ORDER BY TblMsdcMData.start ASC";
};

void QryMsdcDatList::fetch(
			DbsMsdc* dbsmsdc
		) {
	string sqlstr;

	StmgrMsdc* stmgr = NULL;
	Stcch* stcch = NULL;

	MsdcQDatList* rec = NULL;

	dbsmsdc->tblmsdcqdatlist->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i=0;i<rst.nodes.size();i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->titSrefMsdcKAcqfeat = dbsmsdc->getKlstTitleBySref(VecMsdcVKeylist::KLSTMSDCKACQFEAT, rec->srefMsdcKAcqfeat, ixMsdcVLocale);
			rec->stubRefMsdcMPeriod = StubMsdc::getStubPrdStd(dbsmsdc, rec->refMsdcMPeriod, ixMsdcVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->ftmStart = Ftm::stamp(rec->start);
			rec->ftmStop = Ftm::stamp(rec->stop);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryMsdcDatList", "fetch");
	};

	refreshJnum();
};

uint QryMsdcDatList::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	MsdcQDatList* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryMsdcDatList::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	MsdcQDatList* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

MsdcQDatList* QryMsdcDatList::getRecByJnum(
			const uint jnum
		) {
	MsdcQDatList* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryMsdcDatList::handleRequest(
			DbsMsdc* dbsmsdc
			, ReqMsdc* req
		) {
	if (req->ixVBasetype == ReqMsdc::VecVBasetype::CMD) {
		reqCmd = req;

		if (req->cmd == "cmdset") {
			cout << "\trerun" << endl;
			cout << "\tshow" << endl;
		} else if (req->cmd == "rerun") {
			req->retain = handleRerun(dbsmsdc);

		} else if (req->cmd == "show") {
			req->retain = handleShow(dbsmsdc);

		} else {
			cout << "\tinvalid command!" << endl;
		};

		if (!req->retain) reqCmd = NULL;

	} else if (req->ixVBasetype == ReqMsdc::VecVBasetype::REGULAR) {
	};
};

bool QryMsdcDatList::handleRerun(
			DbsMsdc* dbsmsdc
		) {
	bool retval = false;
	string input;

	cout << "\tjnumFirstload (" << stgiac.jnumFirstload << "): ";
	cin >> input;
	stgiac.jnumFirstload = atol(input.c_str());
	cout << "\tnload (" << stgiac.nload << "): ";
	cin >> input;
	stgiac.nload = atol(input.c_str());

	rerun(dbsmsdc);
	return retval;
};

bool QryMsdcDatList::handleShow(
			DbsMsdc* dbsmsdc
		) {
	bool retval = false;
	MsdcQDatList* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tsrefMsdcKAcqfeat";
	cout << "\ttitSrefMsdcKAcqfeat";
	cout << "\trefMsdcMPeriod";
	cout << "\tstubRefMsdcMPeriod";
	cout << "\tstart";
	cout << "\tftmStart";
	cout << "\tstop";
	cout << "\tftmStop";
	cout << endl;

	// record rows
	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->srefMsdcKAcqfeat;
		cout << "\t" << rec->titSrefMsdcKAcqfeat;
		cout << "\t" << rec->refMsdcMPeriod;
		cout << "\t" << rec->stubRefMsdcMPeriod;
		cout << "\t" << rec->start;
		cout << "\t" << rec->ftmStart;
		cout << "\t" << rec->stop;
		cout << "\t" << rec->ftmStop;
		cout << endl;
	};
	return retval;
};

void QryMsdcDatList::handleCall(
			DbsMsdc* dbsmsdc
			, Call* call
		) {
	if (call->ixVCall == VecMsdcVCall::CALLMSDCSTUBCHG) {
		call->abort = handleCallMsdcStubChg(dbsmsdc, call->jref);
	} else if (call->ixVCall == VecMsdcVCall::CALLMSDCDATMOD) {
		call->abort = handleCallMsdcDatMod(dbsmsdc, call->jref);
	} else if (call->ixVCall == VecMsdcVCall::CALLMSDCDATUPD_REFEQ) {
		call->abort = handleCallMsdcDatUpd_refEq(dbsmsdc, call->jref, call->argInv.ref);
	};
};

bool QryMsdcDatList::handleCallMsdcStubChg(
			DbsMsdc* dbsmsdc
			, const ubigint jrefTrig
		) {
	bool retval = false;

	if (ixMsdcVQrystate == VecMsdcVQrystate::UTD) {
		ixMsdcVQrystate = VecMsdcVQrystate::SLM;
		xchg->triggerCall(dbsmsdc, VecMsdcVCall::CALLMSDCSTATCHG, jref);
	};

	return retval;
};

bool QryMsdcDatList::handleCallMsdcDatMod(
			DbsMsdc* dbsmsdc
			, const ubigint jrefTrig
		) {
	bool retval = false;

	if ((ixMsdcVQrystate == VecMsdcVQrystate::UTD) || (ixMsdcVQrystate == VecMsdcVQrystate::SLM)) {
		ixMsdcVQrystate = VecMsdcVQrystate::MNR;
		xchg->triggerCall(dbsmsdc, VecMsdcVCall::CALLMSDCSTATCHG, jref);
	};

	return retval;
};

bool QryMsdcDatList::handleCallMsdcDatUpd_refEq(
			DbsMsdc* dbsmsdc
			, const ubigint jrefTrig
			, const ubigint refInv
		) {
	bool retval = false;

	if (ixMsdcVQrystate != VecMsdcVQrystate::OOD) {
		ixMsdcVQrystate = VecMsdcVQrystate::OOD;
		xchg->triggerCall(dbsmsdc, VecMsdcVCall::CALLMSDCSTATCHG, jref);
	};

	return retval;
};

