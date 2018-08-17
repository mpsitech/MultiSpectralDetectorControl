/**
  * \file DbsMsdc.cpp
  * C++ wrapper for database DbsMsdc (implementation)
  * \author Alexander Wirthmueller
  * \date created: 15 Aug 2018
  * \date modified: 15 Aug 2018
  */

#include "DbsMsdc.h"

#include "DbsMsdc_vecs.cpp"

/******************************************************************************
 class DbsMsdc
 ******************************************************************************/

DbsMsdc::DbsMsdc() {
	initdone = false;

	dbsLite = NULL;
};

DbsMsdc::~DbsMsdc() {
	if (initdone) term();
};

void DbsMsdc::init(
			const uint _ixDbsVDbstype
			, const string& _dbspath
			, const string& _dbsname
			, const string& _ip
			, const uint _port
			, const string& _username
			, const string& _password
		) {
	ixDbsVDbstype = _ixDbsVDbstype;
	dbspath = _dbspath;
	dbsname = _dbsname;
	username = _username;
	password = _password;
	ip = _ip;
	port = _port;

	if (ixDbsVDbstype == VecDbsVDbstype::LITE) initLite();

	initdone = true;
};

void DbsMsdc::term() {
	if (ixDbsVDbstype == VecDbsVDbstype::LITE) termLite();

	initdone = false;
};

void DbsMsdc::initLite() {
	int res;

	res = sqlite3_open_v2(dbspath.c_str(), &dbsLite, SQLITE_OPEN_READWRITE | SQLITE_OPEN_FULLMUTEX, NULL);
	if (res != SQLITE_OK) throw DbsException("DbsException / SQLite: connection failure");

	sqlite3_extended_result_codes(dbsLite, 1);

	tblmsdcaccrmuseruniversal = new LiteTblMsdcAccRMUserUniversal();
	((LiteTblMsdcAccRMUserUniversal*) tblmsdcaccrmuseruniversal)->init(dbsLite);
	tblmsdcamdatapar = new LiteTblMsdcAMDataPar();
	((LiteTblMsdcAMDataPar*) tblmsdcamdatapar)->init(dbsLite);
	tblmsdcampersondetail = new LiteTblMsdcAMPersonDetail();
	((LiteTblMsdcAMPersonDetail*) tblmsdcampersondetail)->init(dbsLite);
	tblmsdcamuseraccess = new LiteTblMsdcAMUserAccess();
	((LiteTblMsdcAMUserAccess*) tblmsdcamuseraccess)->init(dbsLite);
	tblmsdcamusergroupaccess = new LiteTblMsdcAMUsergroupAccess();
	((LiteTblMsdcAMUsergroupAccess*) tblmsdcamusergroupaccess)->init(dbsLite);
	tblmsdcavcontrolpar = new LiteTblMsdcAVControlPar();
	((LiteTblMsdcAVControlPar*) tblmsdcavcontrolpar)->init(dbsLite);
	tblmsdcavkeylistkey = new LiteTblMsdcAVKeylistKey();
	((LiteTblMsdcAVKeylistKey*) tblmsdcavkeylistkey)->init(dbsLite);
	tblmsdcavvaluelistval = new LiteTblMsdcAVValuelistVal();
	((LiteTblMsdcAVValuelistVal*) tblmsdcavvaluelistval)->init(dbsLite);
	tblmsdccfile = new LiteTblMsdcCFile();
	((LiteTblMsdcCFile*) tblmsdccfile)->init(dbsLite);
	tblmsdchistrmuseruniversal = new LiteTblMsdcHistRMUserUniversal();
	((LiteTblMsdcHistRMUserUniversal*) tblmsdchistrmuseruniversal)->init(dbsLite);
	tblmsdcjavkeylistkey = new LiteTblMsdcJAVKeylistKey();
	((LiteTblMsdcJAVKeylistKey*) tblmsdcjavkeylistkey)->init(dbsLite);
	tblmsdcjmpersonlastname = new LiteTblMsdcJMPersonLastname();
	((LiteTblMsdcJMPersonLastname*) tblmsdcjmpersonlastname)->init(dbsLite);
	tblmsdcjmuserstate = new LiteTblMsdcJMUserState();
	((LiteTblMsdcJMUserState*) tblmsdcjmuserstate)->init(dbsLite);
	tblmsdcmdata = new LiteTblMsdcMData();
	((LiteTblMsdcMData*) tblmsdcmdata)->init(dbsLite);
	tblmsdcmfile = new LiteTblMsdcMFile();
	((LiteTblMsdcMFile*) tblmsdcmfile)->init(dbsLite);
	tblmsdcmperiod = new LiteTblMsdcMPeriod();
	((LiteTblMsdcMPeriod*) tblmsdcmperiod)->init(dbsLite);
	tblmsdcmperson = new LiteTblMsdcMPerson();
	((LiteTblMsdcMPerson*) tblmsdcmperson)->init(dbsLite);
	tblmsdcmsession = new LiteTblMsdcMSession();
	((LiteTblMsdcMSession*) tblmsdcmsession)->init(dbsLite);
	tblmsdcmuser = new LiteTblMsdcMUser();
	((LiteTblMsdcMUser*) tblmsdcmuser)->init(dbsLite);
	tblmsdcmusergroup = new LiteTblMsdcMUsergroup();
	((LiteTblMsdcMUsergroup*) tblmsdcmusergroup)->init(dbsLite);
	tblmsdcrmusergroupuniversal = new LiteTblMsdcRMUsergroupUniversal();
	((LiteTblMsdcRMUsergroupUniversal*) tblmsdcrmusergroupuniversal)->init(dbsLite);
	tblmsdcrmusermusergroup = new LiteTblMsdcRMUserMUsergroup();
	((LiteTblMsdcRMUserMUsergroup*) tblmsdcrmusermusergroup)->init(dbsLite);

	tblmsdcqdatapar = new LiteTblMsdcQDatAPar();
	((LiteTblMsdcQDatAPar*) tblmsdcqdatapar)->init(dbsLite);
	tblmsdcqdatlist = new LiteTblMsdcQDatList();
	((LiteTblMsdcQDatList*) tblmsdcqdatlist)->init(dbsLite);
	tblmsdcqdatref1nfile = new LiteTblMsdcQDatRef1NFile();
	((LiteTblMsdcQDatRef1NFile*) tblmsdcqdatref1nfile)->init(dbsLite);
	tblmsdcqfillist = new LiteTblMsdcQFilList();
	((LiteTblMsdcQFilList*) tblmsdcqfillist)->init(dbsLite);
	tblmsdcqprd1ndata = new LiteTblMsdcQPrd1NData();
	((LiteTblMsdcQPrd1NData*) tblmsdcqprd1ndata)->init(dbsLite);
	tblmsdcqprdlist = new LiteTblMsdcQPrdList();
	((LiteTblMsdcQPrdList*) tblmsdcqprdlist)->init(dbsLite);
	tblmsdcqpreselect = new LiteTblMsdcQPreselect();
	((LiteTblMsdcQPreselect*) tblmsdcqpreselect)->init(dbsLite);
	tblmsdcqprslist = new LiteTblMsdcQPrsList();
	((LiteTblMsdcQPrsList*) tblmsdcqprslist)->init(dbsLite);
	tblmsdcqselect = new LiteTblMsdcQSelect();
	((LiteTblMsdcQSelect*) tblmsdcqselect)->init(dbsLite);
	tblmsdcqusgaaccess = new LiteTblMsdcQUsgAAccess();
	((LiteTblMsdcQUsgAAccess*) tblmsdcqusgaaccess)->init(dbsLite);
	tblmsdcqusglist = new LiteTblMsdcQUsgList();
	((LiteTblMsdcQUsgList*) tblmsdcqusglist)->init(dbsLite);
	tblmsdcqusgmnuser = new LiteTblMsdcQUsgMNUser();
	((LiteTblMsdcQUsgMNUser*) tblmsdcqusgmnuser)->init(dbsLite);
	tblmsdcqusr1nsession = new LiteTblMsdcQUsr1NSession();
	((LiteTblMsdcQUsr1NSession*) tblmsdcqusr1nsession)->init(dbsLite);
	tblmsdcqusraaccess = new LiteTblMsdcQUsrAAccess();
	((LiteTblMsdcQUsrAAccess*) tblmsdcqusraaccess)->init(dbsLite);
	tblmsdcqusrlist = new LiteTblMsdcQUsrList();
	((LiteTblMsdcQUsrList*) tblmsdcqusrlist)->init(dbsLite);
	tblmsdcqusrmnusergroup = new LiteTblMsdcQUsrMNUsergroup();
	((LiteTblMsdcQUsrMNUsergroup*) tblmsdcqusrmnusergroup)->init(dbsLite);
};

void DbsMsdc::termLite() {
	sqlite3_close(dbsLite);
};

void DbsMsdc::begin() {
	if (ixDbsVDbstype == VecDbsVDbstype::LITE) beginLite();
};

bool DbsMsdc::commit() {
	if (ixDbsVDbstype == VecDbsVDbstype::LITE) return commitLite();

	return false;
};

void DbsMsdc::rollback() {
	if (ixDbsVDbstype == VecDbsVDbstype::LITE) rollbackLite();
};

void DbsMsdc::beginLite() {
	if (sqlite3_exec(dbsLite, "BEGIN", NULL, NULL, NULL) != SQLITE_OK) throw DbsException("DbsException / SQLite: failed to begin transaction\n");
};

bool DbsMsdc::commitLite() {
	if (sqlite3_exec(dbsLite, "COMMIT", NULL, NULL, NULL) != SQLITE_OK) {
		rollbackLite();
		return false;
	};

	return true;
};

void DbsMsdc::rollbackLite() {
	if (sqlite3_exec(dbsLite, "ROLLBACK", NULL, NULL, NULL) != SQLITE_OK) throw DbsException("DbsException / SQLite: failed to roll back transaction\n");
};

bool DbsMsdc::loadUintBySQL(
			const string& sqlstr
			, uint& val
		) {
	if (ixDbsVDbstype == VecDbsVDbstype::LITE) return loadUintBySQLLite(sqlstr, val);

	return false;
};

bool DbsMsdc::loadStringBySQL(
			const string& sqlstr
			, string& val
		) {
	if (ixDbsVDbstype == VecDbsVDbstype::LITE) return loadStringBySQLLite(sqlstr, val);

	return false;
};

bool DbsMsdc::loadRefBySQL(
			const string& sqlstr
			, ubigint& ref
		) {
	if (ixDbsVDbstype == VecDbsVDbstype::LITE) return loadRefBySQLLite(sqlstr, ref);

	return false;
};

ubigint DbsMsdc::loadRefsBySQL(
			const string& sqlstr
			, const bool append
			, vector<ubigint>& refs
		) {
	if (ixDbsVDbstype == VecDbsVDbstype::LITE) return loadRefsBySQLLite(sqlstr, append, refs);

	return 0;
};

bool DbsMsdc::loadUintBySQLLite(
			const string& sqlstr
			, uint& val
		) {
	int res;
	sqlite3_stmt* stmt;

	bool retval = false;

	res = sqlite3_prepare_v2(dbsLite, sqlstr.c_str(), -1, &stmt, NULL);
	if (res != SQLITE_OK) throw DbsException("DbsException / SQLite: failed to execute query '" + sqlstr + "'\n");

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		val = sqlite3_column_int(stmt, 0);

		res = sqlite3_step(stmt);
		if (res == SQLITE_DONE) retval = true;
	};

	sqlite3_finalize(stmt);

	return retval;
};

bool DbsMsdc::loadStringBySQLLite(
			const string& sqlstr
			, string& val
		) {
	int res;
	sqlite3_stmt* stmt;

	bool retval = false;

	res = sqlite3_prepare_v2(dbsLite, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) throw DbsException("DbsException / SQLite: failed to execute query '" + sqlstr + "'\n");

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		val.assign((const char*) sqlite3_column_text(stmt, 0));

		res = sqlite3_step(stmt);
		if (res == SQLITE_DONE) retval = true;
	};

	sqlite3_finalize(stmt);

	return retval;
};

bool DbsMsdc::loadRefBySQLLite(
			const string& sqlstr
			, ubigint& val
		) {
	int res;
	sqlite3_stmt* stmt;

	bool retval = false;

	res = sqlite3_prepare_v2(dbsLite, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) throw DbsException("DbsException / SQLite: failed to execute query '" + sqlstr + "'\n");

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		val = sqlite3_column_int64(stmt, 0);

		res = sqlite3_step(stmt);
		if (res == SQLITE_DONE) retval = true;
	};

	sqlite3_finalize(stmt);

	return retval;
};

ubigint DbsMsdc::loadRefsBySQLLite(
			const string& sqlstr
			, const bool append
			, vector<ubigint>& refs
		) {
	int res; ubigint numread = 0;
	sqlite3_stmt* stmt;

	res = sqlite3_prepare_v2(dbsLite, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) throw DbsException("DbsException / SQLite: failed to execute query '" + sqlstr + "'\n");

	if (!append) refs.resize(0);

	res = sqlite3_step(stmt);
	while (res == SQLITE_ROW) {
		refs.push_back(sqlite3_column_int64(stmt, 0));
		numread++;

		res = sqlite3_step(stmt);
	};

	sqlite3_finalize(stmt);

	return(numread);
};

void DbsMsdc::executeQuery(
			const string& sqlstr
		) {
	if (ixDbsVDbstype == VecDbsVDbstype::LITE) {
		int res;

		res = sqlite3_exec(dbsLite, sqlstr.c_str(), NULL, NULL, NULL);
		if (res != SQLITE_OK)
			throw DbsException("DbsException / SQLite: failed to execute query '" + sqlstr + "'\n");

	};
};

void DbsMsdc::executeQueryDiv(
			const string& sqlstrlite
		) {
	if (ixDbsVDbstype == VecDbsVDbstype::LITE) executeQuery(sqlstrlite);
};

void DbsMsdc::executeFile(
			const string& fullpath
		) {
	string sqlstr = "";
	char c;
	
	ifstream sqlfile(fullpath.c_str());

	while (sqlfile.get(c)) {
		switch (c) {
			case '\n':
				break;
			case '\t':
				break;
			case ';':
				executeQuery(sqlstr);
				sqlstr = "";
				break;
			default:
				sqlstr = sqlstr + c;
				break;
		};
	};
	sqlfile.close();
};

void DbsMsdc::fillFeedFromKlst(
			const uint klsIxMsdcVKeylist
			, const uint ixMsdcVLocale
			, Feed& feed
		) {
	ListMsdcAVKeylistKey klsAkeys;
	MsdcAVKeylistKey* klsAkey = NULL;

	tblmsdcavkeylistkey->loadRstByKls(klsIxMsdcVKeylist, false, klsAkeys);

	feed.clear();
	for (unsigned int i=0;i<klsAkeys.nodes.size();i++) {
		klsAkey = klsAkeys.nodes[i];

		tblmsdcjavkeylistkey->loadTitByKlkLcl(klsAkey->ref, ixMsdcVLocale, klsAkey->Title);
		feed.appendIxSrefTitles(i+1, klsAkey->sref, klsAkey->Title);
	};
};

void DbsMsdc::fillFeedFromKlstByMtbUref(
			const uint klsIxMsdcVKeylist
			, const uint x1IxMsdcVMaintable
			, const ubigint x1Uref
			, const uint ixMsdcVLocale
			, Feed& feed
		) {
	ListMsdcAVKeylistKey klsAkeys;
	MsdcAVKeylistKey* klsAkey = NULL;

	tblmsdcavkeylistkey->loadRstByKlsMtbUrf(klsIxMsdcVKeylist, x1IxMsdcVMaintable, x1Uref, false, klsAkeys);

	feed.clear();
	for (unsigned int i=0;i<klsAkeys.nodes.size();i++) {
		klsAkey = klsAkeys.nodes[i];

		tblmsdcjavkeylistkey->loadTitByKlkLcl(klsAkey->ref, ixMsdcVLocale, klsAkey->Title);
		feed.appendIxSrefTitles(i+1, klsAkey->sref, klsAkey->Title);
	};
};

string DbsMsdc::getKlstTitleBySref(
			const uint klsIxMsdcVKeylist
			, const string& sref
			, const uint ixMsdcVLocale
		) {
	string retval;

	ubigint refKlk;

	if (tblmsdcavkeylistkey->loadRefByKlsSrf(klsIxMsdcVKeylist, sref, refKlk))
		if (!tblmsdcjavkeylistkey->loadTitByKlkLcl(refKlk, ixMsdcVLocale, retval))
			tblmsdcavkeylistkey->loadTitByRef(refKlk, retval);

	return retval;
};

string DbsMsdc::getKlstTitleByMtbUrefSref(
			const uint klsIxMsdcVKeylist
			, const uint x1IxMsdcVMaintable
			, const ubigint x1Uref
			, const string& sref
			, const uint ixMsdcVLocale
		) {
	string retval;

	ubigint refKlk;

	if (tblmsdcavkeylistkey->loadRefByKlsMtbUrfSrf(klsIxMsdcVKeylist, x1IxMsdcVMaintable, x1Uref, sref, refKlk))
		if (!tblmsdcjavkeylistkey->loadTitByKlkLcl(refKlk, ixMsdcVLocale, retval))
			tblmsdcavkeylistkey->loadTitByRef(refKlk, retval);

	return retval;
};

void DbsMsdc::fillFeedFromVlst(
			const uint vlsIxMsdcVValuelist
			, const uint x1IxMsdcVLocale
			, Feed& feed
		) {
	ListMsdcAVValuelistVal vlsAvals;
	MsdcAVValuelistVal* vlsAval = NULL;

	tblmsdcavvaluelistval->loadRstByVlsLcl(vlsIxMsdcVValuelist, x1IxMsdcVLocale, false, vlsAvals);

	feed.clear();
	for (unsigned int i=0;i<vlsAvals.nodes.size();i++) {
		vlsAval = vlsAvals.nodes[i];

		feed.appendTitles(vlsAval->Val);
	};
};

