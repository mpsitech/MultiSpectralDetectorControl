/**
  * \file QryMsdcFilList.cpp
  * job handler for job QryMsdcFilList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 18 Dec 2018
  * \date modified: 18 Dec 2018
  */

#ifdef MSDCCMBD
	#include <Msdccmbd.h>
#else
	#include <Msdcd.h>
#endif

#include "QryMsdcFilList.h"

#include "QryMsdcFilList_blks.cpp"

/******************************************************************************
 class QryMsdcFilList
 ******************************************************************************/

QryMsdcFilList::QryMsdcFilList(
			XchgMsdc* xchg
			, DbsMsdc* dbsmsdc
			, const ubigint jrefSup
			, const uint ixMsdcVLocale
		) :
			JobMsdc(xchg, VecMsdcVJob::QRYMSDCFILLIST, jrefSup, ixMsdcVLocale)
		{

	jref = xchg->addJob(this);

	// IP constructor.cust1 --- INSERT

	xchg->addStmgr(jref, Stub::VecVNonetype::SHORT);
	ixMsdcVQrystate = VecMsdcVQrystate::OOD;

	// IP constructor.cust2 --- INSERT

	rerun(dbsmsdc);

	xchg->addClstn(VecMsdcVCall::CALLMSDCSTUBCHG, jref, Clstn::VecVJobmask::SPEC, jref, Arg(), Clstn::VecVJactype::LOCK);

	xchg->addClstn(VecMsdcVCall::CALLMSDCFILMOD, jref, Clstn::VecVJobmask::ALL, 0, Arg(), Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
	
};

QryMsdcFilList::~QryMsdcFilList() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void QryMsdcFilList::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecMsdcVPreset::PREMSDCREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);

	xchg->removeClstns(VecMsdcVCall::CALLMSDCFILUPD_REFEQ, jref);
	if (preRefSel != 0) xchg->addRefClstn(VecMsdcVCall::CALLMSDCFILUPD_REFEQ, jref, Clstn::VecVJobmask::ALL, 0, preRefSel, Clstn::VecVJactype::LOCK);
};

void QryMsdcFilList::rerun(
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
	ubigint preRefDat = xchg->getRefPreset(VecMsdcVPreset::PREMSDCREFDAT, jref);
	ubigint preRefPrd = xchg->getRefPreset(VecMsdcVPreset::PREMSDCREFPRD, jref);
	string preFnm = xchg->getTxtvalPreset(VecMsdcVPreset::PREMSDCFILLIST_FNM, jref);
	uint preRet = xchg->getIxPreset(VecMsdcVPreset::PREMSDCFILLIST_RET, jref);
	ubigint preReu = xchg->getRefPreset(VecMsdcVPreset::PREMSDCFILLIST_REU, jref);

	dbsmsdc->tblmsdcqselect->removeRstByJref(jref);
	dbsmsdc->tblmsdcqfillist->removeRstByJref(jref);

	cntsum = 0;

	if (preIxPre == VecMsdcVPreset::PREMSDCREFDAT) {
		sqlstr = "SELECT COUNT(TblMsdcMFile.ref)";
		sqlstr += " FROM TblMsdcMFile";
		sqlstr += " WHERE TblMsdcMFile.refIxVTbl = " + to_string(VecMsdcVMFileRefTbl::DAT);
		sqlstr += " AND TblMsdcMFile.refUref = " + to_string(preRefDat) + "";
		rerun_filtSQL(sqlstr, preFnm, preRet, preReu, false);
		dbsmsdc->loadUintBySQL(sqlstr, cnt);
		cnts.push_back(cnt); lims.push_back(0); ofss.push_back(0);
		cntsum += cnt;

	} else if (preIxPre == VecMsdcVPreset::PREMSDCREFPRD) {
		sqlstr = "SELECT COUNT(TblMsdcMFile.ref)";
		sqlstr += " FROM TblMsdcMFile, TblMsdcMData";
		sqlstr += " WHERE TblMsdcMFile.refIxVTbl = " + to_string(VecMsdcVMFileRefTbl::DAT);
		sqlstr += " AND TblMsdcMFile.refUref = TblMsdcMData.ref";
		sqlstr += " AND TblMsdcMData.refMsdcMPeriod = " + to_string(preRefPrd) + "";
		rerun_filtSQL(sqlstr, preFnm, preRet, preReu, false);
		dbsmsdc->loadUintBySQL(sqlstr, cnt);
		cnts.push_back(cnt); lims.push_back(0); ofss.push_back(0);
		cntsum += cnt;

	} else {
		sqlstr = "SELECT COUNT(TblMsdcMFile.ref)";
		sqlstr += " FROM TblMsdcMFile";
		rerun_filtSQL(sqlstr, preFnm, preRet, preReu, true);
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

	if (preIxPre == VecMsdcVPreset::PREMSDCREFDAT) {
		rerun_baseSQL(sqlstr);
		sqlstr += " FROM TblMsdcMFile";
		sqlstr += " WHERE TblMsdcMFile.refIxVTbl = " + to_string(VecMsdcVMFileRefTbl::DAT);
		sqlstr += " AND TblMsdcMFile.refUref = " + to_string(preRefDat) + "";
		rerun_filtSQL(sqlstr, preFnm, preRet, preReu, false);
		rerun_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbsmsdc->executeQuery(sqlstr);

	} else if (preIxPre == VecMsdcVPreset::PREMSDCREFPRD) {
		rerun_baseSQL(sqlstr);
		sqlstr += " FROM TblMsdcMFile, TblMsdcMData";
		sqlstr += " WHERE TblMsdcMFile.refIxVTbl = " + to_string(VecMsdcVMFileRefTbl::DAT);
		sqlstr += " AND TblMsdcMFile.refUref = TblMsdcMData.ref";
		sqlstr += " AND TblMsdcMData.refMsdcMPeriod = " + to_string(preRefPrd) + "";
		rerun_filtSQL(sqlstr, preFnm, preRet, preReu, false);
		rerun_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbsmsdc->executeQuery(sqlstr);

	} else {
		rerun_baseSQL(sqlstr);
		sqlstr += " FROM TblMsdcMFile";
		rerun_filtSQL(sqlstr, preFnm, preRet, preReu, true);
		rerun_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbsmsdc->executeQuery(sqlstr);
	};

	sqlstr = "UPDATE TblMsdcQFilList SET jnum = qref WHERE jref = " + to_string(jref);
	dbsmsdc->executeQuery(sqlstr);

	ixMsdcVQrystate = VecMsdcVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbsmsdc);

	if (call) xchg->triggerCall(dbsmsdc, VecMsdcVCall::CALLMSDCSTATCHG, jref);

};

void QryMsdcFilList::rerun_baseSQL(
			string& sqlstr
		) {
	sqlstr = "INSERT INTO TblMsdcQFilList(jref, jnum, ref, Filename, refIxVTbl, refUref, osrefKContent, srefKMimetype, Size)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblMsdcMFile.ref, TblMsdcMFile.Filename, TblMsdcMFile.refIxVTbl, TblMsdcMFile.refUref, TblMsdcMFile.osrefKContent, TblMsdcMFile.srefKMimetype, TblMsdcMFile.Size";
};

void QryMsdcFilList::rerun_filtSQL(
			string& sqlstr
			, const string& preFnm
			, const uint preRet
			, const ubigint preReu
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preFnm.length() > 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblMsdcMFile.Filename LIKE '" + preFnm + "'";
	};

	if (preRet != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblMsdcMFile.refIxVTbl = " + to_string(preRet) + "";
	};

	if (preReu != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblMsdcMFile.refUref = " + to_string(preReu) + "";
	};
};

void QryMsdcFilList::rerun_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryMsdcFilList::rerun_orderSQL(
			string& sqlstr
			, const uint preIxOrd
		) {
	if (preIxOrd == VecVOrd::FNM) sqlstr += " ORDER BY TblMsdcMFile.Filename ASC";
	else if (preIxOrd == VecVOrd::RET) sqlstr += " ORDER BY TblMsdcMFile.refIxVTbl ASC";
	else if (preIxOrd == VecVOrd::REU) sqlstr += " ORDER BY TblMsdcMFile.refUref ASC";
};

void QryMsdcFilList::fetch(
			DbsMsdc* dbsmsdc
		) {
	string sqlstr;

	StmgrMsdc* stmgr = NULL;
	Stcch* stcch = NULL;

	MsdcQFilList* rec = NULL;

	dbsmsdc->tblmsdcqfillist->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i=0;i<rst.nodes.size();i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->srefRefIxVTbl = VecMsdcVMFileRefTbl::getSref(rec->refIxVTbl);
			rec->titRefIxVTbl = VecMsdcVMFileRefTbl::getTitle(rec->refIxVTbl, ixMsdcVLocale);
			if (rec->refIxVTbl == VecMsdcVMFileRefTbl::DAT) {
				rec->stubRefUref = StubMsdc::getStubDatStd(dbsmsdc, rec->refUref, ixMsdcVLocale, Stub::VecVNonetype::SHORT, stcch);
			} else rec->stubRefUref = "-";
			rec->titOsrefKContent = dbsmsdc->getKlstTitleBySref(VecMsdcVKeylist::KLSTMSDCKMFILECONTENT, rec->osrefKContent, ixMsdcVLocale);
			rec->titSrefKMimetype = dbsmsdc->getKlstTitleBySref(VecMsdcVKeylist::KLSTMSDCKMFILEMIMETYPE, rec->srefKMimetype, ixMsdcVLocale);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryMsdcFilList", "fetch");
	};

	refreshJnum();
};

uint QryMsdcFilList::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	MsdcQFilList* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryMsdcFilList::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	MsdcQFilList* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

MsdcQFilList* QryMsdcFilList::getRecByJnum(
			const uint jnum
		) {
	MsdcQFilList* rec = NULL;

	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryMsdcFilList::handleRequest(
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

bool QryMsdcFilList::handleRerun(
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

bool QryMsdcFilList::handleShow(
			DbsMsdc* dbsmsdc
		) {
	bool retval = false;
	MsdcQFilList* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tFilename";
	cout << "\trefIxVTbl";
	cout << "\tsrefRefIxVTbl";
	cout << "\ttitRefIxVTbl";
	cout << "\trefUref";
	cout << "\tstubRefUref";
	cout << "\tosrefKContent";
	cout << "\ttitOsrefKContent";
	cout << "\tsrefKMimetype";
	cout << "\ttitSrefKMimetype";
	cout << "\tSize";
	cout << endl;

	// record rows
	for (unsigned int i=0;i<rst.nodes.size();i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->Filename;
		cout << "\t" << rec->refIxVTbl;
		cout << "\t" << rec->srefRefIxVTbl;
		cout << "\t" << rec->titRefIxVTbl;
		cout << "\t" << rec->refUref;
		cout << "\t" << rec->stubRefUref;
		cout << "\t" << rec->osrefKContent;
		cout << "\t" << rec->titOsrefKContent;
		cout << "\t" << rec->srefKMimetype;
		cout << "\t" << rec->titSrefKMimetype;
		cout << "\t" << rec->Size;
		cout << endl;
	};
	return retval;
};

void QryMsdcFilList::handleCall(
			DbsMsdc* dbsmsdc
			, Call* call
		) {
	if (call->ixVCall == VecMsdcVCall::CALLMSDCSTUBCHG) {
		call->abort = handleCallMsdcStubChg(dbsmsdc, call->jref);
	} else if (call->ixVCall == VecMsdcVCall::CALLMSDCFILMOD) {
		call->abort = handleCallMsdcFilMod(dbsmsdc, call->jref);
	} else if (call->ixVCall == VecMsdcVCall::CALLMSDCFILUPD_REFEQ) {
		call->abort = handleCallMsdcFilUpd_refEq(dbsmsdc, call->jref, call->argInv.ref);
	};
};

bool QryMsdcFilList::handleCallMsdcStubChg(
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

bool QryMsdcFilList::handleCallMsdcFilMod(
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

bool QryMsdcFilList::handleCallMsdcFilUpd_refEq(
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

