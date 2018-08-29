/**
  * \file QryMsdcDatAPar.cpp
  * job handler for job QryMsdcDatAPar (implementation)
  * \author Alexander Wirthmueller
  * \date created: 29 Aug 2018
  * \date modified: 29 Aug 2018
  */

#ifdef MSDCCMBD
	#include <Msdccmbd.h>
#else
	#include <Msdcd.h>
#endif

#include "QryMsdcDatAPar.h"

#include "QryMsdcDatAPar_blks.cpp"

/******************************************************************************
 class QryMsdcDatAPar
 ******************************************************************************/

QryMsdcDatAPar::QryMsdcDatAPar(
			XchgMsdc* xchg
			, DbsMsdc* dbsmsdc
			, const ubigint jrefSup
			, const uint ixMsdcVLocale
		) :
			JobMsdc(xchg, VecMsdcVJob::QRYMSDCDATAPAR, jrefSup, ixMsdcVLocale)
		{

	jref = xchg->addJob(this);

	// IP constructor.cust1 --- INSERT

	xchg->addStmgr(jref, Stub::VecVNonetype::SHORT);
	ixMsdcVQrystate = VecMsdcVQrystate::OOD;

	// IP constructor.cust2 --- INSERT

	rerun(dbsmsdc);

	xchg->addClstn(VecMsdcVCall::CALLMSDCSTUBCHG, jref, Clstn::VecVJobmask::SPEC, jref, Arg(), Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
	
};

QryMsdcDatAPar::~QryMsdcDatAPar() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryMsdcDatAPar::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecMsdcVPreset::PREMSDCREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryMsdcDatAPar::rerun(
			DbsMsdc* dbsmsdc
			, const bool call
		) {
	string sqlstr;

	uint cnt;

	ubigint preRefDat = xchg->getRefPreset(VecMsdcVPreset::PREMSDCREFDAT, jref);
	double preX1 = xchg->getDblvalPreset(VecMsdcVPreset::PREMSDCDATAPAR_X1, jref);
	string preX2 = xchg->getSrefPreset(VecMsdcVPreset::PREMSDCDATAPAR_X2, jref);

	xchg->removeClstns(VecMsdcVCall::CALLMSDCDATAPARMOD_DATEQ, jref);

	dbsmsdc->tblmsdcqselect->removeRstByJref(jref);
	dbsmsdc->tblmsdcqdatapar->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblMsdcAMDataPar.ref)";
	sqlstr += " FROM TblMsdcAMDataPar";
	sqlstr += " WHERE TblMsdcAMDataPar.refMsdcMData = " + to_string(preRefDat) + "";
	rerun_filtSQL(sqlstr, preX1, preX2, false);
	dbsmsdc->loadUintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblMsdcQDatAPar(jref, jnum, ref, x1Start, x2SrefKKey, refMsdcMFile, Val, Bindata)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblMsdcAMDataPar.ref, TblMsdcAMDataPar.x1Start, TblMsdcAMDataPar.x2SrefKKey, TblMsdcAMDataPar.refMsdcMFile, TblMsdcAMDataPar.Val, TblMsdcAMDataPar.Bindata";
	sqlstr += " FROM TblMsdcAMDataPar";
	sqlstr += " WHERE TblMsdcAMDataPar.refMsdcMData = " + to_string(preRefDat) + "";
	rerun_filtSQL(sqlstr, preX1, preX2, false);
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbsmsdc->executeQuery(sqlstr);

	sqlstr = "UPDATE TblMsdcQDatAPar SET jnum = qref WHERE jref = " + to_string(jref);
	dbsmsdc->executeQuery(sqlstr);

	ixMsdcVQrystate = VecMsdcVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsmsdc);

	if (call) xchg->triggerCall(dbsmsdc, VecMsdcVCall::CALLMSDCSTATCHG, jref);

	xchg->addRefClstn(VecMsdcVCall::CALLMSDCDATAPARMOD_DATEQ, jref, Clstn::VecVJobmask::ALL, 0, preRefDat, Clstn::VecVJactype::LOCK);
};

void QryMsdcDatAPar::rerun_filtSQL(
			string& sqlstr
			, const double preX1
			, const string& preX2
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preX1 != -numeric_limits<double>::infinity()) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblMsdcAMDataPar.x1Start = " + to_string(preX1) + "";
	};

	if (preX2.length() > 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblMsdcAMDataPar.x2SrefKKey = '" + preX2 + "'";
	};
};

void QryMsdcDatAPar::rerun_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryMsdcDatAPar::fetch(
			DbsMsdc* dbsmsdc
		) {
	string sqlstr;

	StmgrMsdc* stmgr = NULL;
	Stcch* stcch = NULL;

	MsdcQDatAPar* rec = NULL;

	dbsmsdc->tblmsdcqdatapar->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i=0;i<rst.nodes.size();i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->ftmX1Start = Ftm::usecstamp(rec->x1Start);
			rec->titX2SrefKKey = dbsmsdc->getKlstTitleBySref(VecMsdcVKeylist::KLSTMSDCKAMDATAPARKEY, rec->x2SrefKKey, ixMsdcVLocale);
			rec->stubRefMsdcMFile = StubMsdc::getStubFilStd(dbsmsdc, rec->refMsdcMFile, ixMsdcVLocale, Stub::VecVNonetype::SHORT, stcch);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryMsdcDatAPar", "fetch");
	};

	refreshJnum();
};

uint QryMsdcDatAPar::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	MsdcQDatAPar* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryMsdcDatAPar::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	MsdcQDatAPar* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

MsdcQDatAPar* QryMsdcDatAPar::getRecByJnum(
			const uint jnum
		) {
	MsdcQDatAPar* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryMsdcDatAPar::handleRequest(
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

bool QryMsdcDatAPar::handleRerun(
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

bool QryMsdcDatAPar::handleShow(
			DbsMsdc* dbsmsdc
		) {
	bool retval = false;
	MsdcQDatAPar* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tx1Start";
	cout << "\tftmX1Start";
	cout << "\tx2SrefKKey";
	cout << "\ttitX2SrefKKey";
	cout << "\trefMsdcMFile";
	cout << "\tstubRefMsdcMFile";
	cout << "\tVal";
	cout << "\tBindata";
	cout << endl;

	// record rows
	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->x1Start;
		cout << "\t" << rec->ftmX1Start;
		cout << "\t" << rec->x2SrefKKey;
		cout << "\t" << rec->titX2SrefKKey;
		cout << "\t" << rec->refMsdcMFile;
		cout << "\t" << rec->stubRefMsdcMFile;
		cout << "\t" << rec->Val;
		cout << "\t" << rec->Bindata;
		cout << endl;
	};
	return retval;
};

void QryMsdcDatAPar::handleCall(
			DbsMsdc* dbsmsdc
			, Call* call
		) {
	if (call->ixVCall == VecMsdcVCall::CALLMSDCSTUBCHG) {
		call->abort = handleCallMsdcStubChg(dbsmsdc, call->jref);
	} else if (call->ixVCall == VecMsdcVCall::CALLMSDCDATAPARMOD_DATEQ) {
		call->abort = handleCallMsdcDatAparMod_datEq(dbsmsdc, call->jref, call->argInv.ref);
	};
};

bool QryMsdcDatAPar::handleCallMsdcStubChg(
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

bool QryMsdcDatAPar::handleCallMsdcDatAparMod_datEq(
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

