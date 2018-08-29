/**
  * \file QryMsdcUsrList.cpp
  * job handler for job QryMsdcUsrList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 29 Aug 2018
  * \date modified: 29 Aug 2018
  */

#ifdef MSDCCMBD
	#include <Msdccmbd.h>
#else
	#include <Msdcd.h>
#endif

#include "QryMsdcUsrList.h"

#include "QryMsdcUsrList_blks.cpp"

/******************************************************************************
 class QryMsdcUsrList
 ******************************************************************************/

QryMsdcUsrList::QryMsdcUsrList(
			XchgMsdc* xchg
			, DbsMsdc* dbsmsdc
			, const ubigint jrefSup
			, const uint ixMsdcVLocale
		) :
			JobMsdc(xchg, VecMsdcVJob::QRYMSDCUSRLIST, jrefSup, ixMsdcVLocale)
		{

	jref = xchg->addJob(this);

	// IP constructor.cust1 --- INSERT

	xchg->addStmgr(jref, Stub::VecVNonetype::SHORT);
	ixMsdcVQrystate = VecMsdcVQrystate::OOD;

	// IP constructor.cust2 --- INSERT

	rerun(dbsmsdc);

	xchg->addClstn(VecMsdcVCall::CALLMSDCSTUBCHG, jref, Clstn::VecVJobmask::SPEC, jref, Arg(), Clstn::VecVJactype::LOCK);

	xchg->addClstn(VecMsdcVCall::CALLMSDCUSRMOD, jref, Clstn::VecVJobmask::ALL, 0, Arg(), Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
	
};

QryMsdcUsrList::~QryMsdcUsrList() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryMsdcUsrList::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecMsdcVPreset::PREMSDCREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);

	xchg->removeClstns(VecMsdcVCall::CALLMSDCUSRUPD_REFEQ, jref);
	if (preRefSel != 0) xchg->addRefClstn(VecMsdcVCall::CALLMSDCUSRUPD_REFEQ, jref, Clstn::VecVJobmask::ALL, 0, preRefSel, Clstn::VecVJactype::LOCK);
};

void QryMsdcUsrList::rerun(
			DbsMsdc* dbsmsdc
			, const bool call
		) {
	string sqlstr;

	uint cnt;

	uint preIxOrd = xchg->getIxPreset(VecMsdcVPreset::PREMSDCIXORD, jref);
	ubigint prePrs = xchg->getRefPreset(VecMsdcVPreset::PREMSDCUSRLIST_PRS, jref);
	string preSrf = xchg->getSrefPreset(VecMsdcVPreset::PREMSDCUSRLIST_SRF, jref);
	ubigint preUsg = xchg->getRefPreset(VecMsdcVPreset::PREMSDCUSRLIST_USG, jref);
	uint preSte = xchg->getIxPreset(VecMsdcVPreset::PREMSDCUSRLIST_STE, jref);

	dbsmsdc->tblmsdcqselect->removeRstByJref(jref);
	dbsmsdc->tblmsdcqusrlist->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblMsdcMUser.ref)";
	sqlstr += " FROM TblMsdcMUser";
	rerun_filtSQL(sqlstr, prePrs, preSrf, preUsg, preSte, true);
	dbsmsdc->loadUintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblMsdcQUsrList(jref, jnum, ref, refMsdcMPerson, sref, refMsdcMUsergroup, ixVState, ixMsdcVLocale, ixMsdcVUserlevel)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblMsdcMUser.ref, TblMsdcMUser.refMsdcMPerson, TblMsdcMUser.sref, TblMsdcMUser.refMsdcMUsergroup, TblMsdcMUser.ixVState, TblMsdcMUser.ixMsdcVLocale, TblMsdcMUser.ixMsdcVUserlevel";
	sqlstr += " FROM TblMsdcMUser";
	rerun_filtSQL(sqlstr, prePrs, preSrf, preUsg, preSte, true);
	rerun_orderSQL(sqlstr, preIxOrd);
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbsmsdc->executeQuery(sqlstr);

	sqlstr = "UPDATE TblMsdcQUsrList SET jnum = qref WHERE jref = " + to_string(jref);
	dbsmsdc->executeQuery(sqlstr);

	ixMsdcVQrystate = VecMsdcVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsmsdc);

	if (call) xchg->triggerCall(dbsmsdc, VecMsdcVCall::CALLMSDCSTATCHG, jref);

};

void QryMsdcUsrList::rerun_filtSQL(
			string& sqlstr
			, const ubigint prePrs
			, const string& preSrf
			, const ubigint preUsg
			, const uint preSte
			, const bool addwhere
		) {
	bool first = addwhere;

	if (prePrs != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblMsdcMUser.refMsdcMPerson = " + to_string(prePrs) + "";
	};

	if (preSrf.length() > 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblMsdcMUser.sref = '" + preSrf + "'";
	};

	if (preUsg != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblMsdcMUser.refMsdcMUsergroup = " + to_string(preUsg) + "";
	};

	if (preSte != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblMsdcMUser.ixVState = " + to_string(preSte) + "";
	};
};

void QryMsdcUsrList::rerun_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryMsdcUsrList::rerun_orderSQL(
			string& sqlstr
			, const uint preIxOrd
		) {
	if (preIxOrd == VecVOrd::PRS) sqlstr += " ORDER BY TblMsdcMUser.refMsdcMPerson ASC";
	else if (preIxOrd == VecVOrd::SRF) sqlstr += " ORDER BY TblMsdcMUser.sref ASC";
	else if (preIxOrd == VecVOrd::USG) sqlstr += " ORDER BY TblMsdcMUser.refMsdcMUsergroup ASC";
	else if (preIxOrd == VecVOrd::STE) sqlstr += " ORDER BY TblMsdcMUser.ixVState ASC";
};

void QryMsdcUsrList::fetch(
			DbsMsdc* dbsmsdc
		) {
	string sqlstr;

	StmgrMsdc* stmgr = NULL;
	Stcch* stcch = NULL;

	MsdcQUsrList* rec = NULL;

	dbsmsdc->tblmsdcqusrlist->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i=0;i<rst.nodes.size();i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubRefMsdcMPerson = StubMsdc::getStubPrsStd(dbsmsdc, rec->refMsdcMPerson, ixMsdcVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->stubRefMsdcMUsergroup = StubMsdc::getStubUsgStd(dbsmsdc, rec->refMsdcMUsergroup, ixMsdcVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->srefIxVState = VecMsdcVMUserState::getSref(rec->ixVState);
			rec->titIxVState = VecMsdcVMUserState::getTitle(rec->ixVState, ixMsdcVLocale);
			rec->srefIxMsdcVLocale = VecMsdcVLocale::getSref(rec->ixMsdcVLocale);
			rec->titIxMsdcVLocale = VecMsdcVLocale::getTitle(rec->ixMsdcVLocale, ixMsdcVLocale);
			rec->srefIxMsdcVUserlevel = VecMsdcVUserlevel::getSref(rec->ixMsdcVUserlevel);
			rec->titIxMsdcVUserlevel = VecMsdcVUserlevel::getTitle(rec->ixMsdcVUserlevel, ixMsdcVLocale);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryMsdcUsrList", "fetch");
	};

	refreshJnum();
};

uint QryMsdcUsrList::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	MsdcQUsrList* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryMsdcUsrList::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	MsdcQUsrList* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

MsdcQUsrList* QryMsdcUsrList::getRecByJnum(
			const uint jnum
		) {
	MsdcQUsrList* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryMsdcUsrList::handleRequest(
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

bool QryMsdcUsrList::handleRerun(
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

bool QryMsdcUsrList::handleShow(
			DbsMsdc* dbsmsdc
		) {
	bool retval = false;
	MsdcQUsrList* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\trefMsdcMPerson";
	cout << "\tstubRefMsdcMPerson";
	cout << "\tsref";
	cout << "\trefMsdcMUsergroup";
	cout << "\tstubRefMsdcMUsergroup";
	cout << "\tixVState";
	cout << "\tsrefIxVState";
	cout << "\ttitIxVState";
	cout << "\tixMsdcVLocale";
	cout << "\tsrefIxMsdcVLocale";
	cout << "\ttitIxMsdcVLocale";
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
		cout << "\t" << rec->ref;
		cout << "\t" << rec->refMsdcMPerson;
		cout << "\t" << rec->stubRefMsdcMPerson;
		cout << "\t" << rec->sref;
		cout << "\t" << rec->refMsdcMUsergroup;
		cout << "\t" << rec->stubRefMsdcMUsergroup;
		cout << "\t" << rec->ixVState;
		cout << "\t" << rec->srefIxVState;
		cout << "\t" << rec->titIxVState;
		cout << "\t" << rec->ixMsdcVLocale;
		cout << "\t" << rec->srefIxMsdcVLocale;
		cout << "\t" << rec->titIxMsdcVLocale;
		cout << "\t" << rec->ixMsdcVUserlevel;
		cout << "\t" << rec->srefIxMsdcVUserlevel;
		cout << "\t" << rec->titIxMsdcVUserlevel;
		cout << endl;
	};
	return retval;
};

void QryMsdcUsrList::handleCall(
			DbsMsdc* dbsmsdc
			, Call* call
		) {
	if (call->ixVCall == VecMsdcVCall::CALLMSDCSTUBCHG) {
		call->abort = handleCallMsdcStubChg(dbsmsdc, call->jref);
	} else if (call->ixVCall == VecMsdcVCall::CALLMSDCUSRMOD) {
		call->abort = handleCallMsdcUsrMod(dbsmsdc, call->jref);
	} else if (call->ixVCall == VecMsdcVCall::CALLMSDCUSRUPD_REFEQ) {
		call->abort = handleCallMsdcUsrUpd_refEq(dbsmsdc, call->jref, call->argInv.ref);
	};
};

bool QryMsdcUsrList::handleCallMsdcStubChg(
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

bool QryMsdcUsrList::handleCallMsdcUsrMod(
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

bool QryMsdcUsrList::handleCallMsdcUsrUpd_refEq(
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

