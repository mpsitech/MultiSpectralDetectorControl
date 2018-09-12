/**
  * \file RootMsdc.cpp
  * job handler for job RootMsdc (implementation)
  * \author Alexander Wirthmueller
  * \date created: 12 Sep 2018
  * \date modified: 12 Sep 2018
  */

#ifdef MSDCCMBD
	#include <Msdccmbd.h>
#else
	#include <Msdcd.h>
#endif

#include "RootMsdc.h"

#include "RootMsdc_blks.cpp"

/******************************************************************************
 class RootMsdc
 ******************************************************************************/

RootMsdc::RootMsdc(
			XchgMsdc* xchg
			, DbsMsdc* dbsmsdc
			, const bool _clearAll
		) :
			JobMsdc(xchg, VecMsdcVJob::ROOTMSDC, 0, VecMsdcVLocale::ENUS)
		{

	jref = xchg->addJob(this);

	srcmsdd = NULL;
	srctrigger = NULL;

	// IP constructor.cust1 --- IBEGIN

	// autostart new acquisition period
	unsigned int now = time(NULL);

	dbsmsdc->executeQuery("UPDATE TblMsdcMPeriod SET stop = " + to_string(now) + " WHERE stop = 0");

	ubigint refPrd = dbsmsdc->tblmsdcmperiod->insertNewRec(NULL, now, 0);
	xchg->addRefPreset(VecMsdcVPreset::PREMSDCPRD, jref, refPrd);

	// IP constructor.cust1 --- IEND

	// log
	xchg->appendToLogfile("root job created");

	if (_clearAll) clearAll(dbsmsdc);
	else clearQtb(dbsmsdc);

	srcmsdd = new JobMsdcSrcMsdd(xchg, dbsmsdc, jref, ixMsdcVLocale, true);
	srctrigger = new JobMsdcSrcTrigger(xchg, dbsmsdc, jref, ixMsdcVLocale, true);

	// IP constructor.cust2 --- INSERT

	// IP constructor.spec2 --- INSERT

	xchg->addClstn(VecMsdcVCall::CALLMSDCLOGOUT, jref, Clstn::VecVJobmask::IMM, 0, Arg(), Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecMsdcVCall::CALLMSDCSUSPSESS, jref, Clstn::VecVJobmask::IMM, 0, Arg(), Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
	
};

RootMsdc::~RootMsdc() {
	// log
	xchg->appendToLogfile("root job deleted");

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void RootMsdc::clearAll(
			DbsMsdc* dbsmsdc
		) {
	MsdcMUsergroup* usg = NULL;
	MsdcRMUserMUsergroup* uru = NULL;
	MsdcMUser* usr = NULL;
	ubigint refUjs = 0;
	MsdcMPerson* prs = NULL;
	ubigint refPjl = 0;

	time_t timeval;
	uint dateval;

	string s;

	// empty out tables
	dbsmsdc->executeQuery("DELETE FROM TblMsdcAccRMUserUniversal");
	dbsmsdc->executeQuery("DELETE FROM TblMsdcAMDataPar");
	dbsmsdc->executeQuery("DELETE FROM TblMsdcAMPersonDetail");
	dbsmsdc->executeQuery("DELETE FROM TblMsdcAMUserAccess");
	dbsmsdc->executeQuery("DELETE FROM TblMsdcAMUsergroupAccess");
	dbsmsdc->executeQuery("DELETE FROM TblMsdcAVControlPar");
	dbsmsdc->executeQuery("DELETE FROM TblMsdcAVKeylistKey");
	dbsmsdc->executeQuery("DELETE FROM TblMsdcAVValuelistVal");
	if (dbsmsdc->ixDbsVDbstype == VecDbsVDbstype::MY) dbsmsdc->executeQuery("DELETE FROM TblMsdcCFile");
	else if (dbsmsdc->ixDbsVDbstype == VecDbsVDbstype::PG) dbsmsdc->executeQuery("ALTER SEQUENCE TblMsdcCFile RESTART WITH 1");
	dbsmsdc->executeQuery("DELETE FROM TblMsdcHistRMUserUniversal");
	dbsmsdc->executeQuery("DELETE FROM TblMsdcJAVKeylistKey");
	dbsmsdc->executeQuery("DELETE FROM TblMsdcJMPersonLastname");
	dbsmsdc->executeQuery("DELETE FROM TblMsdcJMUserState");
	dbsmsdc->executeQuery("DELETE FROM TblMsdcMData");
	dbsmsdc->executeQuery("DELETE FROM TblMsdcMFile");
	dbsmsdc->executeQuery("DELETE FROM TblMsdcMPeriod");
	dbsmsdc->executeQuery("DELETE FROM TblMsdcMPerson");
	dbsmsdc->executeQuery("DELETE FROM TblMsdcMSession");
	dbsmsdc->executeQuery("DELETE FROM TblMsdcMUser");
	dbsmsdc->executeQuery("DELETE FROM TblMsdcMUsergroup");
	dbsmsdc->executeQuery("DELETE FROM TblMsdcRMUsergroupUniversal");
	dbsmsdc->executeQuery("DELETE FROM TblMsdcRMUserMUsergroup");

	clearQtb(dbsmsdc);

	// generate a temporary user such that a session can be generated
	dbsmsdc->tblmsdcmusergroup->insertNewRec(&usg, 0, 0, "temp", "temporary user group for system initialization");
	dbsmsdc->tblmsdcamusergroupaccess->insertNewRec(NULL, usg->ref, VecMsdcVFeatgroup::VECMSDCVCARD, "CrdMsdcNav", VecMsdcWAccess::EDIT + VecMsdcWAccess::EXEC + VecMsdcWAccess::VIEW);
	dbsmsdc->tblmsdcrmusermusergroup->insertNewRec(&uru, 0, usg->ref, VecMsdcVUserlevel::GADM);
	dbsmsdc->tblmsdcmuser->insertNewRec(&usr, usg->ref, 0, uru->ref, usg->ref, 0, "temp", 0, VecMsdcVMUserState::DUE, VecMsdcVLocale::ENUS, VecMsdcVUserlevel::GADM, "asdf1234", "", "temporary user for system initialization");
	refUjs = dbsmsdc->tblmsdcjmuserstate->insertNewRec(NULL, usr->ref, 0, VecMsdcVMUserState::DUE);

	time(&timeval);
	dateval = 1 + (timeval - (timeval % (3600*24))) / (3600*24);

	dbsmsdc->tblmsdcjmuserstate->insertNewRec(NULL, usr->ref, dateval, VecMsdcVMUserState::EXP);
	dbsmsdc->tblmsdcmperson->insertNewRec(&prs, usg->ref, usr->ref, VecMsdcWMPersonDerivate::USR, VecMsdcVMPersonSex::M, "Mr.", "Jack", 0, "Smith", 0, "", 0, "", "Dear Jack");

	refPjl = dbsmsdc->tblmsdcjmpersonlastname->insertNewRec(NULL, prs->ref, 0, "Smith");

	usg->grp = usg->ref;
	usg->own = usr->ref;
	dbsmsdc->tblmsdcmusergroup->updateRec(usg);

	uru->refMsdcMUser = usr->ref;
	dbsmsdc->tblmsdcrmusermusergroup->updateRec(uru);

	usr->refMsdcMPerson = prs->ref;
	usr->refJState = refUjs;
	dbsmsdc->tblmsdcmuser->updateRec(usr);

	prs->refJLastname = refPjl;
	dbsmsdc->tblmsdcmperson->updateRec(prs);

	cout << "\ttemporary account created for user 'temp', expires " << Ftm::date(dateval) << "; use password 'asdf1234' to log in" << endl;

	xchg->appendToLogfile("database cleared");

	delete usg;
	delete uru;
	delete usr;
	delete prs;
};

void RootMsdc::clearQtb(
			DbsMsdc* dbsmsdc
		) {
	dbsmsdc->executeQuery("DELETE FROM TblMsdcQDatAPar");
	dbsmsdc->executeQuery("DELETE FROM TblMsdcQDatList");
	dbsmsdc->executeQuery("DELETE FROM TblMsdcQDatRef1NFile");
	dbsmsdc->executeQuery("DELETE FROM TblMsdcQFilList");
	dbsmsdc->executeQuery("DELETE FROM TblMsdcQPrd1NData");
	dbsmsdc->executeQuery("DELETE FROM TblMsdcQPrdList");
	dbsmsdc->executeQuery("DELETE FROM TblMsdcQPreselect");
	dbsmsdc->executeQuery("DELETE FROM TblMsdcQPrsList");
	dbsmsdc->executeQuery("DELETE FROM TblMsdcQSelect");
	dbsmsdc->executeQuery("DELETE FROM TblMsdcQUsgAAccess");
	dbsmsdc->executeQuery("DELETE FROM TblMsdcQUsgList");
	dbsmsdc->executeQuery("DELETE FROM TblMsdcQUsgMNUser");
	dbsmsdc->executeQuery("DELETE FROM TblMsdcQUsr1NSession");
	dbsmsdc->executeQuery("DELETE FROM TblMsdcQUsrAAccess");
	dbsmsdc->executeQuery("DELETE FROM TblMsdcQUsrList");
	dbsmsdc->executeQuery("DELETE FROM TblMsdcQUsrMNUsergroup");
};

void RootMsdc::handleRequest(
			DbsMsdc* dbsmsdc
			, ReqMsdc* req
		) {
	if (req->ixVBasetype == ReqMsdc::VecVBasetype::CMD) {
		reqCmd = req;

		if (req->cmd == "cmdset") {
			cout << "\tclearAll" << endl;
			cout << "\tcreateSess" << endl;
			cout << "\teraseSess" << endl;
			cout << "\ttest" << endl;
		} else if (req->cmd == "clearAll") {
			req->retain = handleClearAll(dbsmsdc);

		} else if (req->cmd == "createSess") {
			req->retain = handleCreateSess(dbsmsdc);

		} else if (req->cmd == "eraseSess") {
			req->retain = handleEraseSess(dbsmsdc);

		} else if (req->cmd == "test") {
			req->retain = handleTest(dbsmsdc);

		} else {
			cout << "\tinvalid command!" << endl;
		};

		if (!req->retain) reqCmd = NULL;

	} else if (req->ixVBasetype == ReqMsdc::VecVBasetype::REGULAR) {
		if (req->dpchapp->ixMsdcVDpch == VecMsdcVDpch::DPCHAPPROOTMSDCLOGIN) {
			handleDpchAppLogin(dbsmsdc, (DpchAppLogin*) (req->dpchapp), req->ip, &(req->dpcheng));

		};
	};
};

bool RootMsdc::handleClearAll(
			DbsMsdc* dbsmsdc
		) {
	bool retval = false;
	clearAll(dbsmsdc);
	return retval;
};

bool RootMsdc::handleCreateSess(
			DbsMsdc* dbsmsdc
		) {
	bool retval = false;
	string input;
	string input2;

	ubigint refUsr;

	SessMsdc* sess = NULL;

	cout << "\tuser name: ";
	cin >> input;
	cout << "\tpassword: ";
	cin >> input2;

	// verify password and create a session
	if (dbsmsdc->tblmsdcmuser->loadRefBySrfPwd(input, input2, refUsr)) {
		sess = new SessMsdc(xchg, dbsmsdc, jref, refUsr, "127.0.0.1");
		sesss.push_back(sess);

		cout << "\tjob reference: " << sess->jref << endl;
		xchg->jrefCmd = sess->jref;

		xchg->appendToLogfile("command line session created for user '" + input + "'");

	} else {
		cout << "\tlogin failed." << endl;

		xchg->appendToLogfile("command line login refused for user '" + input + "'");
	};

	return false;
	return retval;
};

bool RootMsdc::handleEraseSess(
			DbsMsdc* dbsmsdc
		) {
	bool retval = false;
	string input;
	uint iinput;

	SessMsdc* sess = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it=sesss.begin();it!=sesss.end();) {
		sess = *it;
		if (sess->jref == iinput) {
			it = sesss.erase(it);
			delete sess;
			break;
		} else it++;
	};

	return false;
	return retval;
};

bool RootMsdc::handleTest(
			DbsMsdc* dbsmsdc
		) {
	bool retval = false;
	// IP handleTest --- INSERT
	return retval;
};

void RootMsdc::handleDpchAppLogin(
			DbsMsdc* dbsmsdc
			, DpchAppLogin* dpchapplogin
			, const string ip
			, DpchEngMsdc** dpcheng
		) {
	ubigint refUsr;

	SessMsdc* sess = NULL;
	M2msessMsdc* m2msess = NULL;

	Feed feedFEnsSps("FeedFEnsSps");

	// verify password
	if (dbsmsdc->tblmsdcmuser->loadRefBySrfPwd(dpchapplogin->username, dpchapplogin->password, refUsr)) {
		if (!(dpchapplogin->m2mNotReg)) {
			if (dpchapplogin->chksuspsess) {
				// look for suspended sessions
				for (auto it=sesss.begin();it!=sesss.end();it++) {
					sess = *it;

					if (xchg->getRefPreset(VecMsdcVPreset::PREMSDCOWN, sess->jref) == refUsr) {
						if (xchg->getBoolvalPreset(VecMsdcVPreset::PREMSDCSUSPSESS, sess->jref)) {
							xchg->addTxtvalPreset(VecMsdcVPreset::PREMSDCIP, sess->jref, ip);
							feedFEnsSps.appendIxSrefTitles(0, Scr::scramble(sess->jref), StubMsdc::getStubSesStd(dbsmsdc, xchg->getRefPreset(VecMsdcVPreset::PREMSDCSESS, sess->jref)));
						};
					};
				};
			};

			if (feedFEnsSps.size() == 0) {
				// start new session
				sess = new SessMsdc(xchg, dbsmsdc, jref, refUsr, ip);
				sesss.push_back(sess);

				xchg->appendToLogfile("session created for user '" + dpchapplogin->username + "' from IP " + ip);

				*dpcheng = new DpchEngMsdcConfirm(true, sess->jref, "");

			} else {
				// return suspended sessions
				*dpcheng = new DpchEngData(0, &feedFEnsSps, {DpchEngData::ALL});
			};

		} else {
			m2msess = new M2msessMsdc(xchg, dbsmsdc, jref, refUsr, ip);

			m2msesss.push_back(m2msess);

			xchg->appendToLogfile("M2M session created for user '" + dpchapplogin->username + "' from IP " + ip);

			*dpcheng = new DpchEngMsdcConfirm(true, m2msess->jref, "");
		};

	} else {
		xchg->appendToLogfile("login refused for user '" + dpchapplogin->username + "' from IP " + ip);

		*dpcheng = new DpchEngMsdcConfirm(false, 0, "");
	};
};

void RootMsdc::handleCall(
			DbsMsdc* dbsmsdc
			, Call* call
		) {
	if (call->ixVCall == VecMsdcVCall::CALLMSDCLOGOUT) {
		call->abort = handleCallMsdcLogout(dbsmsdc, call->jref, call->argInv.boolval);
	} else if (call->ixVCall == VecMsdcVCall::CALLMSDCSUSPSESS) {
		call->abort = handleCallMsdcSuspsess(dbsmsdc, call->jref);
	};
};

bool RootMsdc::handleCallMsdcLogout(
			DbsMsdc* dbsmsdc
			, const ubigint jrefTrig
			, const bool boolvalInv
		) {
	bool retval = false;

	SessMsdc* sess = NULL;
	M2msessMsdc* m2msess = NULL;

	if (!boolvalInv) {
		for (auto it=sesss.begin();it!=sesss.end();) {
			sess = *it;
			if (sess->jref == jrefTrig) {
				sess->term(dbsmsdc);
				it = sesss.erase(it);

				delete sess;
				break;
			} else it++;
		};

	} else {
		for (auto it=m2msesss.begin();it!=m2msesss.end();) {
			m2msess = *it;
			if (m2msess->jref == jrefTrig) {
				m2msess->term(dbsmsdc);
				it = m2msesss.erase(it);

				delete m2msess;
				break;
			} else it++;
		};
	};

	return retval;
};

bool RootMsdc::handleCallMsdcSuspsess(
			DbsMsdc* dbsmsdc
			, const ubigint jrefTrig
		) {
	bool retval = false;

	xchg->addBoolvalPreset(VecMsdcVPreset::PREMSDCSUSPSESS, jrefTrig, true);
	xchg->removeDcolsByJref(jrefTrig);

	return retval;
};



