/**
  * \file QryMsdcUsgMNUser.cpp
  * job handler for job QryMsdcUsgMNUser (implementation)
  * \author Alexander Wirthmueller
  * \date created: 12 Sep 2018
  * \date modified: 12 Sep 2018
  */

#ifdef MSDCCMBD
	#include <Msdccmbd.h>
#else
	#include <Msdcd.h>
#endif

#include "QryMsdcUsgMNUser.h"

#include "QryMsdcUsgMNUser_blks.cpp"

/******************************************************************************
 class QryMsdcUsgMNUser
 ******************************************************************************/

QryMsdcUsgMNUser::QryMsdcUsgMNUser(
			XchgMsdc* xchg
			, DbsMsdc* dbsmsdc
			, const ubigint jrefSup
			, const uint ixMsdcVLocale
		) :
			JobMsdc(xchg, VecMsdcVJob::QRYMSDCUSGMNUSER, jrefSup, ixMsdcVLocale)
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

QryMsdcUsgMNUser::~QryMsdcUsgMNUser() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryMsdcUsgMNUser::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecMsdcVPreset::PREMSDCREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryMsdcUsgMNUser::rerun(
			DbsMsdc* dbsmsdc
			, const bool call
		) {
	string sqlstr;

	uint cnt;

	ubigint preRefUsg = xchg->getRefPreset(VecMsdcVPreset::PREMSDCREFUSG, jref);

	xchg->removeClstns(VecMsdcVCall::CALLMSDCUSRRUSGMOD_USGEQ, jref);

	dbsmsdc->tblmsdcqselect->removeRstByJref(jref);
	dbsmsdc->tblmsdcqusgmnuser->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblMsdcRMUserMUsergroup.ref)";
	sqlstr += " FROM TblMsdcRMUserMUsergroup, TblMsdcMUser";
	sqlstr += " WHERE TblMsdcRMUserMUsergroup.refMsdcMUser = TblMsdcMUser.ref";
	sqlstr += " AND TblMsdcRMUserMUsergroup.refMsdcMUsergroup = " + to_string(preRefUsg) + "";
	dbsmsdc->loadUintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblMsdcQUsgMNUser(jref, jnum, mref, ref, ixMsdcVUserlevel)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblMsdcMUser.ref, TblMsdcRMUserMUsergroup.ref, TblMsdcRMUserMUsergroup.ixMsdcVUserlevel";
	sqlstr += " FROM TblMsdcRMUserMUsergroup, TblMsdcMUser";
	sqlstr += " WHERE TblMsdcRMUserMUsergroup.refMsdcMUser = TblMsdcMUser.ref";
	sqlstr += " AND TblMsdcRMUserMUsergroup.refMsdcMUsergroup = " + to_string(preRefUsg) + "";
	sqlstr += " ORDER BY TblMsdcMUser.sref ASC";
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbsmsdc->executeQuery(sqlstr);

	sqlstr = "UPDATE TblMsdcQUsgMNUser SET jnum = qref WHERE jref = " + to_string(jref);
	dbsmsdc->executeQuery(sqlstr);

	ixMsdcVQrystate = VecMsdcVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsmsdc);

	if (call) xchg->triggerCall(dbsmsdc, VecMsdcVCall::CALLMSDCSTATCHG, jref);

	xchg->addRefClstn(VecMsdcVCall::CALLMSDCUSRRUSGMOD_USGEQ, jref, Clstn::VecVJobmask::ALL, 0, preRefUsg, Clstn::VecVJactype::LOCK);
};

void QryMsdcUsgMNUser::fetch(
			DbsMsdc* dbsmsdc
		) {
	string sqlstr;

	StmgrMsdc* stmgr = NULL;
	Stcch* stcch = NULL;

	MsdcQUsgMNUser* rec = NULL;

	dbsmsdc->tblmsdcqusgmnuser->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i=0;i<rst.nodes.size();i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubMref = StubMsdc::getStubUsrStd(dbsmsdc, rec->mref, ixMsdcVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->srefIxMsdcVUserlevel = VecMsdcVUserlevel::getSref(rec->ixMsdcVUserlevel);
			rec->titIxMsdcVUserlevel = VecMsdcVUserlevel::getTitle(rec->ixMsdcVUserlevel, ixMsdcVLocale);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryMsdcUsgMNUser", "fetch");
	};

	refreshJnum();
};

uint QryMsdcUsgMNUser::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	MsdcQUsgMNUser* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryMsdcUsgMNUser::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	MsdcQUsgMNUser* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

MsdcQUsgMNUser* QryMsdcUsgMNUser::getRecByJnum(
			const uint jnum
		) {
	MsdcQUsgMNUser* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryMsdcUsgMNUser::handleRequest(
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

bool QryMsdcUsgMNUser::handleRerun(
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

bool QryMsdcUsgMNUser::handleShow(
			DbsMsdc* dbsmsdc
		) {
	bool retval = false;
	MsdcQUsgMNUser* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tmref";
	cout << "\tstubMref";
	cout << "\tref";
	cout << "\tixMsdcVUserlevel";
	cout << "\tsrefIxMsdcVUserlevel";
	cout << "\ttitIxMsdcVUserlevel";
	cout << endl;

	// record rows
	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->mref;
		cout << "\t" << rec->stubMref;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->ixMsdcVUserlevel;
		cout << "\t" << rec->srefIxMsdcVUserlevel;
		cout << "\t" << rec->titIxMsdcVUserlevel;
		cout << endl;
	};
	return retval;
};

void QryMsdcUsgMNUser::handleCall(
			DbsMsdc* dbsmsdc
			, Call* call
		) {
	if (call->ixVCall == VecMsdcVCall::CALLMSDCSTUBCHG) {
		call->abort = handleCallMsdcStubChg(dbsmsdc, call->jref);
	} else if (call->ixVCall == VecMsdcVCall::CALLMSDCUSRRUSGMOD_USGEQ) {
		call->abort = handleCallMsdcUsrRusgMod_usgEq(dbsmsdc, call->jref, call->argInv.ref);
	};
};

bool QryMsdcUsgMNUser::handleCallMsdcStubChg(
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

bool QryMsdcUsgMNUser::handleCallMsdcUsrRusgMod_usgEq(
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

