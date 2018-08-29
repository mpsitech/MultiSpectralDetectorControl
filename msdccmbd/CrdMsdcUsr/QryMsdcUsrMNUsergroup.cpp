/**
  * \file QryMsdcUsrMNUsergroup.cpp
  * job handler for job QryMsdcUsrMNUsergroup (implementation)
  * \author Alexander Wirthmueller
  * \date created: 29 Aug 2018
  * \date modified: 29 Aug 2018
  */

#ifdef MSDCCMBD
	#include <Msdccmbd.h>
#else
	#include <Msdcd.h>
#endif

#include "QryMsdcUsrMNUsergroup.h"

#include "QryMsdcUsrMNUsergroup_blks.cpp"

/******************************************************************************
 class QryMsdcUsrMNUsergroup
 ******************************************************************************/

QryMsdcUsrMNUsergroup::QryMsdcUsrMNUsergroup(
			XchgMsdc* xchg
			, DbsMsdc* dbsmsdc
			, const ubigint jrefSup
			, const uint ixMsdcVLocale
		) :
			JobMsdc(xchg, VecMsdcVJob::QRYMSDCUSRMNUSERGROUP, jrefSup, ixMsdcVLocale)
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

QryMsdcUsrMNUsergroup::~QryMsdcUsrMNUsergroup() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryMsdcUsrMNUsergroup::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecMsdcVPreset::PREMSDCREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryMsdcUsrMNUsergroup::rerun(
			DbsMsdc* dbsmsdc
			, const bool call
		) {
	string sqlstr;

	uint cnt;

	ubigint preRefUsr = xchg->getRefPreset(VecMsdcVPreset::PREMSDCREFUSR, jref);

	xchg->removeClstns(VecMsdcVCall::CALLMSDCUSRRUSGMOD_USREQ, jref);

	dbsmsdc->tblmsdcqselect->removeRstByJref(jref);
	dbsmsdc->tblmsdcqusrmnusergroup->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblMsdcRMUserMUsergroup.ref)";
	sqlstr += " FROM TblMsdcRMUserMUsergroup, TblMsdcMUsergroup";
	sqlstr += " WHERE TblMsdcRMUserMUsergroup.refMsdcMUsergroup = TblMsdcMUsergroup.ref";
	sqlstr += " AND TblMsdcRMUserMUsergroup.refMsdcMUser = " + to_string(preRefUsr) + "";
	dbsmsdc->loadUintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblMsdcQUsrMNUsergroup(jref, jnum, mref, ref, ixMsdcVUserlevel)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblMsdcMUsergroup.ref, TblMsdcRMUserMUsergroup.ref, TblMsdcRMUserMUsergroup.ixMsdcVUserlevel";
	sqlstr += " FROM TblMsdcRMUserMUsergroup, TblMsdcMUsergroup";
	sqlstr += " WHERE TblMsdcRMUserMUsergroup.refMsdcMUsergroup = TblMsdcMUsergroup.ref";
	sqlstr += " AND TblMsdcRMUserMUsergroup.refMsdcMUser = " + to_string(preRefUsr) + "";
	sqlstr += " ORDER BY TblMsdcMUsergroup.sref ASC";
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbsmsdc->executeQuery(sqlstr);

	sqlstr = "UPDATE TblMsdcQUsrMNUsergroup SET jnum = qref WHERE jref = " + to_string(jref);
	dbsmsdc->executeQuery(sqlstr);

	ixMsdcVQrystate = VecMsdcVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsmsdc);

	if (call) xchg->triggerCall(dbsmsdc, VecMsdcVCall::CALLMSDCSTATCHG, jref);

	xchg->addRefClstn(VecMsdcVCall::CALLMSDCUSRRUSGMOD_USREQ, jref, Clstn::VecVJobmask::ALL, 0, preRefUsr, Clstn::VecVJactype::LOCK);
};

void QryMsdcUsrMNUsergroup::fetch(
			DbsMsdc* dbsmsdc
		) {
	string sqlstr;

	StmgrMsdc* stmgr = NULL;
	Stcch* stcch = NULL;

	MsdcQUsrMNUsergroup* rec = NULL;

	dbsmsdc->tblmsdcqusrmnusergroup->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i=0;i<rst.nodes.size();i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubMref = StubMsdc::getStubUsgStd(dbsmsdc, rec->mref, ixMsdcVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->srefIxMsdcVUserlevel = VecMsdcVUserlevel::getSref(rec->ixMsdcVUserlevel);
			rec->titIxMsdcVUserlevel = VecMsdcVUserlevel::getTitle(rec->ixMsdcVUserlevel, ixMsdcVLocale);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryMsdcUsrMNUsergroup", "fetch");
	};

	refreshJnum();
};

uint QryMsdcUsrMNUsergroup::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	MsdcQUsrMNUsergroup* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryMsdcUsrMNUsergroup::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	MsdcQUsrMNUsergroup* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

MsdcQUsrMNUsergroup* QryMsdcUsrMNUsergroup::getRecByJnum(
			const uint jnum
		) {
	MsdcQUsrMNUsergroup* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryMsdcUsrMNUsergroup::handleRequest(
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

bool QryMsdcUsrMNUsergroup::handleRerun(
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

bool QryMsdcUsrMNUsergroup::handleShow(
			DbsMsdc* dbsmsdc
		) {
	bool retval = false;
	MsdcQUsrMNUsergroup* rec = NULL;

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

void QryMsdcUsrMNUsergroup::handleCall(
			DbsMsdc* dbsmsdc
			, Call* call
		) {
	if (call->ixVCall == VecMsdcVCall::CALLMSDCSTUBCHG) {
		call->abort = handleCallMsdcStubChg(dbsmsdc, call->jref);
	} else if (call->ixVCall == VecMsdcVCall::CALLMSDCUSRRUSGMOD_USREQ) {
		call->abort = handleCallMsdcUsrRusgMod_usrEq(dbsmsdc, call->jref, call->argInv.ref);
	};
};

bool QryMsdcUsrMNUsergroup::handleCallMsdcStubChg(
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

bool QryMsdcUsrMNUsergroup::handleCallMsdcUsrRusgMod_usrEq(
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

