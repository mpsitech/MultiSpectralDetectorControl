/**
  * \file MsdcMSession.cpp
  * database access for table TblMsdcMSession (implementation)
  * \author Alexander Wirthmueller
  * \date created: 12 Sep 2018
  * \date modified: 12 Sep 2018
  */

#include "MsdcMSession.h"

/******************************************************************************
 class MsdcMSession
 ******************************************************************************/

MsdcMSession::MsdcMSession(
			const ubigint ref
			, const ubigint refMsdcMUser
			, const uint start
			, const uint stop
			, const string Ip
		) {

	this->ref = ref;
	this->refMsdcMUser = refMsdcMUser;
	this->start = start;
	this->stop = stop;
	this->Ip = Ip;
};

bool MsdcMSession::operator==(
			const MsdcMSession& comp
		) {
	return false;
};

bool MsdcMSession::operator!=(
			const MsdcMSession& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListMsdcMSession
 ******************************************************************************/

ListMsdcMSession::ListMsdcMSession() {
};

ListMsdcMSession::ListMsdcMSession(
			const ListMsdcMSession& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new MsdcMSession(*(src.nodes[i]));
};

ListMsdcMSession::~ListMsdcMSession() {
	clear();
};

void ListMsdcMSession::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListMsdcMSession::size() const {
	return(nodes.size());
};

void ListMsdcMSession::append(
			MsdcMSession* rec
		) {
	nodes.push_back(rec);
};

MsdcMSession* ListMsdcMSession::operator[](
			const uint ix
		) {
	MsdcMSession* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListMsdcMSession& ListMsdcMSession::operator=(
			const ListMsdcMSession& src
		) {
	MsdcMSession* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new MsdcMSession(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListMsdcMSession::operator==(
			const ListMsdcMSession& comp
		) {
	bool retval;

	retval = (size() == comp.size());

	if (retval) {
		for (unsigned int i=0;i<size();i++) {
			retval = ( *(nodes[i]) == *(comp.nodes[i]) );

			if (!retval) break;
		};
	};

	return retval;
};

bool ListMsdcMSession::operator!=(
			const ListMsdcMSession& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblMsdcMSession
 ******************************************************************************/

TblMsdcMSession::TblMsdcMSession() {
};

TblMsdcMSession::~TblMsdcMSession() {
};

bool TblMsdcMSession::loadRecBySQL(
			const string& sqlstr
			, MsdcMSession** rec
		) {
	return false;
};

ubigint TblMsdcMSession::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListMsdcMSession& rst
		) {
	return 0;
};

void TblMsdcMSession::insertRec(
			MsdcMSession* rec
		) {
};

ubigint TblMsdcMSession::insertNewRec(
			MsdcMSession** rec
			, const ubigint refMsdcMUser
			, const uint start
			, const uint stop
			, const string Ip
		) {
	ubigint retval = 0;
	MsdcMSession* _rec = NULL;

	_rec = new MsdcMSession(0, refMsdcMUser, start, stop, Ip);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblMsdcMSession::appendNewRecToRst(
			ListMsdcMSession& rst
			, MsdcMSession** rec
			, const ubigint refMsdcMUser
			, const uint start
			, const uint stop
			, const string Ip
		) {
	ubigint retval = 0;
	MsdcMSession* _rec = NULL;

	retval = insertNewRec(&_rec, refMsdcMUser, start, stop, Ip);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblMsdcMSession::insertRst(
			ListMsdcMSession& rst
			, bool transact
		) {
};

void TblMsdcMSession::updateRec(
			MsdcMSession* rec
		) {
};

void TblMsdcMSession::updateRst(
			ListMsdcMSession& rst
			, bool transact
		) {
};

void TblMsdcMSession::removeRecByRef(
			ubigint ref
		) {
};

bool TblMsdcMSession::loadRecByRef(
			ubigint ref
			, MsdcMSession** rec
		) {
	return false;
};

ubigint TblMsdcMSession::loadRefsByUsr(
			ubigint refMsdcMUser
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblMsdcMSession::loadRstByUsr(
			ubigint refMsdcMUser
			, const bool append
			, ListMsdcMSession& rst
		) {
	return 0;
};

ubigint TblMsdcMSession::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListMsdcMSession& rst
		) {
	ubigint numload = 0;
	MsdcMSession* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

/******************************************************************************
 class LiteTblMsdcMSession
 ******************************************************************************/

LiteTblMsdcMSession::LiteTblMsdcMSession() :
			TblMsdcMSession()
			, LiteTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;

	stmtLoadRefsByUsr = NULL;
	stmtLoadRstByUsr = NULL;
};

LiteTblMsdcMSession::~LiteTblMsdcMSession() {
	if (stmtInsertRec) sqlite3_finalize(stmtInsertRec);
	if (stmtUpdateRec) sqlite3_finalize(stmtUpdateRec);
	if (stmtRemoveRecByRef) sqlite3_finalize(stmtRemoveRecByRef);

	if (stmtLoadRefsByUsr) sqlite3_finalize(stmtLoadRefsByUsr);
	if (stmtLoadRstByUsr) sqlite3_finalize(stmtLoadRstByUsr);
};

void LiteTblMsdcMSession::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblMsdcMSession (refMsdcMUser, start, stop, Ip) VALUES (?1,?2,?3,?4)");
	stmtUpdateRec = createStatement("UPDATE TblMsdcMSession SET refMsdcMUser = ?1, start = ?2, stop = ?3, Ip = ?4 WHERE ref = ?5");
	stmtRemoveRecByRef = createStatement("DELETE FROM TblMsdcMSession WHERE ref = ?1");

	stmtLoadRecByRef = createStatement("SELECT ref, refMsdcMUser, start, stop, Ip FROM TblMsdcMSession WHERE ref = ?1");
	stmtLoadRefsByUsr = createStatement("SELECT ref FROM TblMsdcMSession WHERE refMsdcMUser = ?1 ORDER BY start ASC");
	stmtLoadRstByUsr = createStatement("SELECT ref, refMsdcMUser, start, stop, Ip FROM TblMsdcMSession WHERE refMsdcMUser = ?1 ORDER BY start ASC");
};

bool LiteTblMsdcMSession::loadRec(
			sqlite3_stmt* stmt
			, MsdcMSession** rec
		) {
	int res;

	MsdcMSession* _rec = NULL;
	bool retval = false;

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		_rec = new MsdcMSession();

		_rec->ref = sqlite3_column_int64(stmt, 0);
		_rec->refMsdcMUser = sqlite3_column_int64(stmt, 1);
		_rec->start = sqlite3_column_int(stmt, 2);
		_rec->stop = sqlite3_column_int(stmt, 3);
		_rec->Ip.assign((const char*) sqlite3_column_text(stmt, 4));

		res = sqlite3_step(stmt);
		if (res == SQLITE_DONE) {
			*rec = _rec;
			retval = true;
		} else {
			delete _rec;
		};
	};

	return retval;
};

ubigint LiteTblMsdcMSession::loadRst(
			sqlite3_stmt* stmt
			, const bool append
			, ListMsdcMSession& rst
		) {
	int res; ubigint numread = 0;

	MsdcMSession* rec;

	if (!append) rst.clear();

	res = sqlite3_step(stmt);
	while (res == SQLITE_ROW) {
		rec = new MsdcMSession();

		rec->ref = sqlite3_column_int64(stmt, 0);
		rec->refMsdcMUser = sqlite3_column_int64(stmt, 1);
		rec->start = sqlite3_column_int(stmt, 2);
		rec->stop = sqlite3_column_int(stmt, 3);
		rec->Ip.assign((const char*) sqlite3_column_text(stmt, 4));

		rst.nodes.push_back(rec);

		numread++;

		res = sqlite3_step(stmt);
	};

	return(numread);
};

bool LiteTblMsdcMSession::loadRecByStmt(
			sqlite3_stmt* stmt
			, MsdcMSession** rec
		) {
	bool retval = loadRec(stmt, rec);

	sqlite3_reset(stmt);

	return retval;
};

ubigint LiteTblMsdcMSession::loadRstByStmt(
			sqlite3_stmt* stmt
			, const bool append
			, ListMsdcMSession& rst
		) {
	ubigint retval = loadRst(stmt, append, rst);

	sqlite3_reset(stmt);

	return retval;
};

bool LiteTblMsdcMSession::loadRecBySQL(
			const string& sqlstr
			, MsdcMSession** rec
		) {
	int res;
	sqlite3_stmt* stmt;

	bool retval = false;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) throw DbsException("DbsException / SQLite: failed to execute query '" + sqlstr + "'\n");

	retval = loadRec(stmt, rec);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblMsdcMSession::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListMsdcMSession& rst
		) {
	int res;
	sqlite3_stmt* stmt;

	ubigint retval = 0;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) throw DbsException("DbsException / SQLite: failed to execute query '" + sqlstr + "'\n");

	retval = loadRst(stmt, append, rst);

	sqlite3_finalize(stmt);

	return retval;
};

void LiteTblMsdcMSession::insertRec(
			MsdcMSession* rec
		) {
	sqlite3_bind_int64(stmtInsertRec, 1, rec->refMsdcMUser);
	sqlite3_bind_int(stmtInsertRec, 2, rec->start);
	sqlite3_bind_int(stmtInsertRec, 3, rec->stop);
	sqlite3_bind_text(stmtInsertRec, 4, rec->Ip.c_str(), rec->Ip.length(), SQLITE_STATIC);

	if (sqlite3_step(stmtInsertRec) != SQLITE_DONE) throw DbsException("DbsException / SQLite: error executing statement! (TblMsdcMSession / stmtInsertRec)\n");
	rec->ref = sqlite3_last_insert_rowid(dbs);

	sqlite3_reset(stmtInsertRec);
};

void LiteTblMsdcMSession::insertRst(
			ListMsdcMSession& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void LiteTblMsdcMSession::updateRec(
			MsdcMSession* rec
		) {
	sqlite3_bind_int64(stmtUpdateRec, 1, rec->refMsdcMUser);
	sqlite3_bind_int(stmtUpdateRec, 2, rec->start);
	sqlite3_bind_int(stmtUpdateRec, 3, rec->stop);
	sqlite3_bind_text(stmtUpdateRec, 4, rec->Ip.c_str(), rec->Ip.length(), SQLITE_STATIC);
	sqlite3_bind_int64(stmtUpdateRec, 5, rec->ref);

	if (sqlite3_step(stmtUpdateRec) != SQLITE_DONE) throw DbsException("DbsException / SQLite: error executing statement! (TblMsdcMSession / stmtUpdateRec)\n");

	sqlite3_reset(stmtUpdateRec);
};

void LiteTblMsdcMSession::updateRst(
			ListMsdcMSession& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void LiteTblMsdcMSession::removeRecByRef(
			ubigint ref
		) {
	sqlite3_bind_int64(stmtRemoveRecByRef, 1, ref);

	if (sqlite3_step(stmtRemoveRecByRef) != SQLITE_DONE) throw DbsException("DbsException / SQLite: error executing statement! (TblMsdcMSession / stmtRemoveRecByRef)\n");

	sqlite3_reset(stmtRemoveRecByRef);
};

bool LiteTblMsdcMSession::loadRecByRef(
			ubigint ref
			, MsdcMSession** rec
		) {
	sqlite3_bind_int64(stmtLoadRecByRef, 1, ref);

	return loadRecByStmt(stmtLoadRecByRef, rec);
};

ubigint LiteTblMsdcMSession::loadRefsByUsr(
			ubigint refMsdcMUser
			, const bool append
			, vector<ubigint>& refs
		) {
	sqlite3_bind_int64(stmtLoadRefsByUsr, 1, refMsdcMUser);

	return loadRefsByStmt(stmtLoadRefsByUsr, append, refs);
};

ubigint LiteTblMsdcMSession::loadRstByUsr(
			ubigint refMsdcMUser
			, const bool append
			, ListMsdcMSession& rst
		) {
	sqlite3_bind_int64(stmtLoadRstByUsr, 1, refMsdcMUser);

	return loadRstByStmt(stmtLoadRstByUsr, append, rst);
};

