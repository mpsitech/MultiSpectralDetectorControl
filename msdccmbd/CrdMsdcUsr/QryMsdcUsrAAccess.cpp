/**
  * \file QryMsdcUsrAAccess.cpp
  * job handler for job QryMsdcUsrAAccess (implementation)
  * \author Alexander Wirthmueller
  * \date created: 12 Sep 2018
  * \date modified: 12 Sep 2018
  */

#ifdef MSDCCMBD
	#include <Msdccmbd.h>
#else
	#include <Msdcd.h>
#endif

#include "QryMsdcUsrAAccess.h"

#include "QryMsdcUsrAAccess_blks.cpp"

/******************************************************************************
 class QryMsdcUsrAAccess
 ******************************************************************************/

QryMsdcUsrAAccess::QryMsdcUsrAAccess(
			XchgMsdc* xchg
			, DbsMsdc* dbsmsdc
			, const ubigint jrefSup
			, const uint ixMsdcVLocale
		) :
			JobMsdc(xchg, VecMsdcVJob::QRYMSDCUSRAACCESS, jrefSup, ixMsdcVLocale)
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

QryMsdcUsrAAccess::~QryMsdcUsrAAccess() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryMsdcUsrAAccess::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecMsdcVPreset::PREMSDCREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryMsdcUsrAAccess::rerun(
			DbsMsdc* dbsmsdc
			, const bool call
		) {
	string sqlstr;

	uint cnt;

	ubigint preRefUsr = xchg->getRefPreset(VecMsdcVPreset::PREMSDCREFUSR, jref);
	uint preX1 = xchg->getIxPreset(VecMsdcVPreset::PREMSDCUSRAACCESS_X1, jref);
	string preX2 = xchg->getSrefPreset(VecMsdcVPreset::PREMSDCUSRAACCESS_X2, jref);

	xchg->removeClstns(VecMsdcVCall::CALLMSDCUSRAACCMOD_USREQ, jref);

	dbsmsdc->tblmsdcqselect->removeRstByJref(jref);
	dbsmsdc->tblmsdcqusraaccess->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblMsdcAMUserAccess.ref)";
	sqlstr += " FROM TblMsdcAMUserAccess";
	sqlstr += " WHERE TblMsdcAMUserAccess.refMsdcMUser = " + to_string(preRefUsr) + "";
	rerun_filtSQL(sqlstr, preX1, preX2, false);
	dbsmsdc->loadUintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblMsdcQUsrAAccess(jref, jnum, ref, x1IxMsdcVFeatgroup, x2FeaSrefUix, ixMsdcWAccess)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblMsdcAMUserAccess.ref, TblMsdcAMUserAccess.x1IxMsdcVFeatgroup, TblMsdcAMUserAccess.x2FeaSrefUix, TblMsdcAMUserAccess.ixMsdcWAccess";
	sqlstr += " FROM TblMsdcAMUserAccess";
	sqlstr += " WHERE TblMsdcAMUserAccess.refMsdcMUser = " + to_string(preRefUsr) + "";
	rerun_filtSQL(sqlstr, preX1, preX2, false);
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbsmsdc->executeQuery(sqlstr);

	sqlstr = "UPDATE TblMsdcQUsrAAccess SET jnum = qref WHERE jref = " + to_string(jref);
	dbsmsdc->executeQuery(sqlstr);

	ixMsdcVQrystate = VecMsdcVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsmsdc);

	if (call) xchg->triggerCall(dbsmsdc, VecMsdcVCall::CALLMSDCSTATCHG, jref);

	xchg->addRefClstn(VecMsdcVCall::CALLMSDCUSRAACCMOD_USREQ, jref, Clstn::VecVJobmask::ALL, 0, preRefUsr, Clstn::VecVJactype::LOCK);
};

void QryMsdcUsrAAccess::rerun_filtSQL(
			string& sqlstr
			, const uint preX1
			, const string& preX2
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preX1 != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblMsdcAMUserAccess.x1IxMsdcVFeatgroup = " + to_string(preX1) + "";
	};

	if (preX2.length() > 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblMsdcAMUserAccess.x2FeaSrefUix = " + preX2 + "";
	};
};

void QryMsdcUsrAAccess::rerun_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryMsdcUsrAAccess::fetch(
			DbsMsdc* dbsmsdc
		) {
	string sqlstr;

	StmgrMsdc* stmgr = NULL;
	Stcch* stcch = NULL;

	MsdcQUsrAAccess* rec = NULL;

	dbsmsdc->tblmsdcqusraaccess->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i=0;i<rst.nodes.size();i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->srefX1IxMsdcVFeatgroup = VecMsdcVFeatgroup::getSref(rec->x1IxMsdcVFeatgroup);
			rec->titX1IxMsdcVFeatgroup = VecMsdcVFeatgroup::getTitle(rec->x1IxMsdcVFeatgroup, ixMsdcVLocale);
			rec->srefsIxMsdcWAccess = VecMsdcWAccess::getSrefs(rec->ixMsdcWAccess);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryMsdcUsrAAccess", "fetch");
	};

	refreshJnum();
};

uint QryMsdcUsrAAccess::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	MsdcQUsrAAccess* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryMsdcUsrAAccess::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	MsdcQUsrAAccess* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

MsdcQUsrAAccess* QryMsdcUsrAAccess::getRecByJnum(
			const uint jnum
		) {
	MsdcQUsrAAccess* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryMsdcUsrAAccess::handleRequest(
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

bool QryMsdcUsrAAccess::handleRerun(
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

bool QryMsdcUsrAAccess::handleShow(
			DbsMsdc* dbsmsdc
		) {
	bool retval = false;
	MsdcQUsrAAccess* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tx1IxMsdcVFeatgroup";
	cout << "\tsrefX1IxMsdcVFeatgroup";
	cout << "\ttitX1IxMsdcVFeatgroup";
	cout << "\tx2FeaSrefUix";
	cout << "\tixMsdcWAccess";
	cout << "\tsrefsIxMsdcWAccess";
	cout << "\ttitsIxMsdcWAccess";
	cout << endl;

	// record rows
	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->x1IxMsdcVFeatgroup;
		cout << "\t" << rec->srefX1IxMsdcVFeatgroup;
		cout << "\t" << rec->titX1IxMsdcVFeatgroup;
		cout << "\t" << rec->x2FeaSrefUix;
		cout << "\t" << rec->ixMsdcWAccess;
		cout << "\t" << rec->srefsIxMsdcWAccess;
		cout << "\t" << rec->titsIxMsdcWAccess;
		cout << endl;
	};
	return retval;
};

void QryMsdcUsrAAccess::handleCall(
			DbsMsdc* dbsmsdc
			, Call* call
		) {
	if (call->ixVCall == VecMsdcVCall::CALLMSDCSTUBCHG) {
		call->abort = handleCallMsdcStubChg(dbsmsdc, call->jref);
	} else if (call->ixVCall == VecMsdcVCall::CALLMSDCUSRAACCMOD_USREQ) {
		call->abort = handleCallMsdcUsrAaccMod_usrEq(dbsmsdc, call->jref, call->argInv.ref);
	};
};

bool QryMsdcUsrAAccess::handleCallMsdcStubChg(
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

bool QryMsdcUsrAAccess::handleCallMsdcUsrAaccMod_usrEq(
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

