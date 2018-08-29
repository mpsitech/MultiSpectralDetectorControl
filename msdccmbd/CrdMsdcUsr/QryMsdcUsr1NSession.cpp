/**
  * \file QryMsdcUsr1NSession.cpp
  * job handler for job QryMsdcUsr1NSession (implementation)
  * \author Alexander Wirthmueller
  * \date created: 29 Aug 2018
  * \date modified: 29 Aug 2018
  */

#ifdef MSDCCMBD
	#include <Msdccmbd.h>
#else
	#include <Msdcd.h>
#endif

#include "QryMsdcUsr1NSession.h"

#include "QryMsdcUsr1NSession_blks.cpp"

/******************************************************************************
 class QryMsdcUsr1NSession
 ******************************************************************************/

QryMsdcUsr1NSession::QryMsdcUsr1NSession(
			XchgMsdc* xchg
			, DbsMsdc* dbsmsdc
			, const ubigint jrefSup
			, const uint ixMsdcVLocale
		) :
			JobMsdc(xchg, VecMsdcVJob::QRYMSDCUSR1NSESSION, jrefSup, ixMsdcVLocale)
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

QryMsdcUsr1NSession::~QryMsdcUsr1NSession() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryMsdcUsr1NSession::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecMsdcVPreset::PREMSDCREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryMsdcUsr1NSession::rerun(
			DbsMsdc* dbsmsdc
			, const bool call
		) {
	string sqlstr;

	uint cnt;

	ubigint preRefUsr = xchg->getRefPreset(VecMsdcVPreset::PREMSDCREFUSR, jref);

	xchg->removeClstns(VecMsdcVCall::CALLMSDCSESMOD_USREQ, jref);

	dbsmsdc->tblmsdcqselect->removeRstByJref(jref);
	dbsmsdc->tblmsdcqusr1nsession->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblMsdcMSession.ref)";
	sqlstr += " FROM TblMsdcMSession";
	sqlstr += " WHERE TblMsdcMSession.refMsdcMUser = " + to_string(preRefUsr) + "";
	dbsmsdc->loadUintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblMsdcQUsr1NSession(jref, jnum, ref)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblMsdcMSession.ref";
	sqlstr += " FROM TblMsdcMSession";
	sqlstr += " WHERE TblMsdcMSession.refMsdcMUser = " + to_string(preRefUsr) + "";
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbsmsdc->executeQuery(sqlstr);

	sqlstr = "UPDATE TblMsdcQUsr1NSession SET jnum = qref WHERE jref = " + to_string(jref);
	dbsmsdc->executeQuery(sqlstr);

	ixMsdcVQrystate = VecMsdcVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsmsdc);

	if (call) xchg->triggerCall(dbsmsdc, VecMsdcVCall::CALLMSDCSTATCHG, jref);

	xchg->addRefClstn(VecMsdcVCall::CALLMSDCSESMOD_USREQ, jref, Clstn::VecVJobmask::ALL, 0, preRefUsr, Clstn::VecVJactype::LOCK);
};

void QryMsdcUsr1NSession::fetch(
			DbsMsdc* dbsmsdc
		) {
	string sqlstr;

	StmgrMsdc* stmgr = NULL;
	Stcch* stcch = NULL;

	MsdcQUsr1NSession* rec = NULL;

	dbsmsdc->tblmsdcqusr1nsession->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i=0;i<rst.nodes.size();i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubRef = StubMsdc::getStubSesStd(dbsmsdc, rec->ref, ixMsdcVLocale, Stub::VecVNonetype::SHORT, stcch);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryMsdcUsr1NSession", "fetch");
	};

	refreshJnum();
};

uint QryMsdcUsr1NSession::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	MsdcQUsr1NSession* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryMsdcUsr1NSession::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	MsdcQUsr1NSession* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

MsdcQUsr1NSession* QryMsdcUsr1NSession::getRecByJnum(
			const uint jnum
		) {
	MsdcQUsr1NSession* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryMsdcUsr1NSession::handleRequest(
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

bool QryMsdcUsr1NSession::handleRerun(
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

bool QryMsdcUsr1NSession::handleShow(
			DbsMsdc* dbsmsdc
		) {
	bool retval = false;
	MsdcQUsr1NSession* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tstubRef";
	cout << endl;

	// record rows
	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->stubRef;
		cout << endl;
	};
	return retval;
};

void QryMsdcUsr1NSession::handleCall(
			DbsMsdc* dbsmsdc
			, Call* call
		) {
	if (call->ixVCall == VecMsdcVCall::CALLMSDCSTUBCHG) {
		call->abort = handleCallMsdcStubChg(dbsmsdc, call->jref);
	} else if (call->ixVCall == VecMsdcVCall::CALLMSDCSESMOD_USREQ) {
		call->abort = handleCallMsdcSesMod_usrEq(dbsmsdc, call->jref, call->argInv.ref);
	};
};

bool QryMsdcUsr1NSession::handleCallMsdcStubChg(
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

bool QryMsdcUsr1NSession::handleCallMsdcSesMod_usrEq(
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

