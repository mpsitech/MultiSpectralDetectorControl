/**
  * \file QryMsdcPrsList.cpp
  * job handler for job QryMsdcPrsList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 15 Aug 2018
  * \date modified: 15 Aug 2018
  */

#ifdef MSDCCMBD
	#include <Msdccmbd.h>
#else
	#include <Msdcd.h>
#endif

#include "QryMsdcPrsList.h"

#include "QryMsdcPrsList_blks.cpp"

/******************************************************************************
 class QryMsdcPrsList
 ******************************************************************************/

QryMsdcPrsList::QryMsdcPrsList(
			XchgMsdc* xchg
			, DbsMsdc* dbsmsdc
			, const ubigint jrefSup
			, const uint ixMsdcVLocale
		) : JobMsdc(xchg, VecMsdcVJob::QRYMSDCPRSLIST, jrefSup, ixMsdcVLocale) {

	jref = xchg->addJob(this);

	// IP constructor.cust1 --- INSERT

	xchg->addStmgr(jref, Stub::VecVNonetype::SHORT);
	ixMsdcVQrystate = VecMsdcVQrystate::OOD;

	// IP constructor.cust2 --- INSERT

	rerun(dbsmsdc);

	xchg->addClstn(VecMsdcVCall::CALLMSDCSTUBCHG, jref, Clstn::VecVJobmask::SPEC, jref, Arg(), Clstn::VecVJactype::LOCK);

	xchg->addClstn(VecMsdcVCall::CALLMSDCPRSMOD, jref, Clstn::VecVJobmask::ALL, 0, Arg(), Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
	
};

QryMsdcPrsList::~QryMsdcPrsList() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryMsdcPrsList::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecMsdcVPreset::PREMSDCREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);

	xchg->removeClstns(VecMsdcVCall::CALLMSDCPRSUPD_REFEQ, jref);
	if (preRefSel != 0) xchg->addRefClstn(VecMsdcVCall::CALLMSDCPRSUPD_REFEQ, jref, Clstn::VecVJobmask::ALL, 0, preRefSel, Clstn::VecVJactype::LOCK);
};

void QryMsdcPrsList::rerun(
			DbsMsdc* dbsmsdc
			, const bool call
		) {
	string sqlstr;

	uint cnt;

	ubigint preJrefSess = xchg->getRefPreset(VecMsdcVPreset::PREMSDCJREFSESS, jref);
	uint preIxOrd = xchg->getIxPreset(VecMsdcVPreset::PREMSDCIXORD, jref);
	string preLnm = xchg->getTxtvalPreset(VecMsdcVPreset::PREMSDCPRSLIST_LNM, jref);
	ubigint preGrp = xchg->getRefPreset(VecMsdcVPreset::PREMSDCPRSLIST_GRP, jref);
	ubigint preOwn = xchg->getRefPreset(VecMsdcVPreset::PREMSDCPRSLIST_OWN, jref);

	dbsmsdc->tblmsdcqselect->removeRstByJref(jref);
	dbsmsdc->tblmsdcqprslist->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblMsdcMPerson.ref)";
	sqlstr += " FROM TblMsdcMPerson, TblMsdcQSelect";
	sqlstr += " WHERE TblMsdcQSelect.jref = " + to_string(preJrefSess) + "";
	sqlstr += " AND TblMsdcMPerson.grp = TblMsdcQSelect.ref";
	rerun_filtSQL(sqlstr, preLnm, preGrp, preOwn, false);
	dbsmsdc->loadUintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblMsdcQPrsList(jref, jnum, ref, Title, Firstname, Lastname, grp, own, ixVSex, telVal, emlVal)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblMsdcMPerson.ref, TblMsdcMPerson.Title, TblMsdcMPerson.Firstname, TblMsdcMPerson.Lastname, TblMsdcMPerson.grp, TblMsdcMPerson.own, TblMsdcMPerson.ixVSex, TblMsdcMPerson.telVal, TblMsdcMPerson.emlVal";
	sqlstr += " FROM TblMsdcMPerson, TblMsdcQSelect";
	sqlstr += " WHERE TblMsdcQSelect.jref = " + to_string(preJrefSess) + "";
	sqlstr += " AND TblMsdcMPerson.grp = TblMsdcQSelect.ref";
	rerun_filtSQL(sqlstr, preLnm, preGrp, preOwn, false);
	rerun_orderSQL(sqlstr, preIxOrd);
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbsmsdc->executeQuery(sqlstr);

	sqlstr = "UPDATE TblMsdcQPrsList SET jnum = qref WHERE jref = " + to_string(jref);
	dbsmsdc->executeQuery(sqlstr);

	ixMsdcVQrystate = VecMsdcVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsmsdc);

	if (call) xchg->triggerCall(dbsmsdc, VecMsdcVCall::CALLMSDCSTATCHG, jref);

};

void QryMsdcPrsList::rerun_filtSQL(
			string& sqlstr
			, const string& preLnm
			, const ubigint preGrp
			, const ubigint preOwn
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preLnm.length() > 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblMsdcMPerson.Lastname LIKE '" + preLnm + "'";
	};

	if (preGrp != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblMsdcMPerson.grp = " + to_string(preGrp) + "";
	};

	if (preOwn != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblMsdcMPerson.own = " + to_string(preOwn) + "";
	};
};

void QryMsdcPrsList::rerun_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryMsdcPrsList::rerun_orderSQL(
			string& sqlstr
			, const uint preIxOrd
		) {
	if (preIxOrd == VecVOrd::LNM) sqlstr += " ORDER BY TblMsdcMPerson.Lastname ASC";
	else if (preIxOrd == VecVOrd::GRP) sqlstr += " ORDER BY TblMsdcMPerson.grp ASC";
	else if (preIxOrd == VecVOrd::OWN) sqlstr += " ORDER BY TblMsdcMPerson.own ASC";
};

void QryMsdcPrsList::fetch(
			DbsMsdc* dbsmsdc
		) {
	string sqlstr;

	StmgrMsdc* stmgr = NULL;
	Stcch* stcch = NULL;

	MsdcQPrsList* rec = NULL;

	dbsmsdc->tblmsdcqprslist->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i=0;i<rst.nodes.size();i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubGrp = StubMsdc::getStubGrp(dbsmsdc, rec->grp, ixMsdcVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->stubOwn = StubMsdc::getStubOwn(dbsmsdc, rec->own, ixMsdcVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->srefIxVSex = VecMsdcVMPersonSex::getSref(rec->ixVSex);
			rec->titIxVSex = VecMsdcVMPersonSex::getTitle(rec->ixVSex, ixMsdcVLocale);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryMsdcPrsList", "fetch");
	};

	refreshJnum();
};

uint QryMsdcPrsList::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	MsdcQPrsList* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryMsdcPrsList::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	MsdcQPrsList* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

MsdcQPrsList* QryMsdcPrsList::getRecByJnum(
			const uint jnum
		) {
	MsdcQPrsList* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryMsdcPrsList::handleRequest(
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

bool QryMsdcPrsList::handleRerun(
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

bool QryMsdcPrsList::handleShow(
			DbsMsdc* dbsmsdc
		) {
	bool retval = false;
	MsdcQPrsList* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tTitle";
	cout << "\tFirstname";
	cout << "\tLastname";
	cout << "\tgrp";
	cout << "\tstubGrp";
	cout << "\town";
	cout << "\tstubOwn";
	cout << "\tixVSex";
	cout << "\tsrefIxVSex";
	cout << "\ttitIxVSex";
	cout << "\ttelVal";
	cout << "\temlVal";
	cout << endl;

	// record rows
	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->Title;
		cout << "\t" << rec->Firstname;
		cout << "\t" << rec->Lastname;
		cout << "\t" << rec->grp;
		cout << "\t" << rec->stubGrp;
		cout << "\t" << rec->own;
		cout << "\t" << rec->stubOwn;
		cout << "\t" << rec->ixVSex;
		cout << "\t" << rec->srefIxVSex;
		cout << "\t" << rec->titIxVSex;
		cout << "\t" << rec->telVal;
		cout << "\t" << rec->emlVal;
		cout << endl;
	};
	return retval;
};

void QryMsdcPrsList::handleCall(
			DbsMsdc* dbsmsdc
			, Call* call
		) {
	if (call->ixVCall == VecMsdcVCall::CALLMSDCSTUBCHG) {
		call->abort = handleCallMsdcStubChg(dbsmsdc, call->jref);
	} else if (call->ixVCall == VecMsdcVCall::CALLMSDCPRSMOD) {
		call->abort = handleCallMsdcPrsMod(dbsmsdc, call->jref);
	} else if (call->ixVCall == VecMsdcVCall::CALLMSDCPRSUPD_REFEQ) {
		call->abort = handleCallMsdcPrsUpd_refEq(dbsmsdc, call->jref, call->argInv.ref);
	};
};

bool QryMsdcPrsList::handleCallMsdcStubChg(
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

bool QryMsdcPrsList::handleCallMsdcPrsMod(
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

bool QryMsdcPrsList::handleCallMsdcPrsUpd_refEq(
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

