/**
  * \file MsdcJMUserState.cpp
  * database access for table TblMsdcJMUserState (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Oct 2018
  * \date modified: 4 Oct 2018
  */

#include "MsdcJMUserState.h"

/******************************************************************************
 class MsdcJMUserState
 ******************************************************************************/

MsdcJMUserState::MsdcJMUserState(
			const ubigint ref
			, const ubigint refMsdcMUser
			, const uint x1Startd
			, const uint ixVState
		) {

	this->ref = ref;
	this->refMsdcMUser = refMsdcMUser;
	this->x1Startd = x1Startd;
	this->ixVState = ixVState;
};

bool MsdcJMUserState::operator==(
			const MsdcJMUserState& comp
		) {
	return false;
};

bool MsdcJMUserState::operator!=(
			const MsdcJMUserState& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListMsdcJMUserState
 ******************************************************************************/

ListMsdcJMUserState::ListMsdcJMUserState() {
};

ListMsdcJMUserState::ListMsdcJMUserState(
			const ListMsdcJMUserState& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new MsdcJMUserState(*(src.nodes[i]));
};

ListMsdcJMUserState::~ListMsdcJMUserState() {
	clear();
};

void ListMsdcJMUserState::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListMsdcJMUserState::size() const {
	return(nodes.size());
};

void ListMsdcJMUserState::append(
			MsdcJMUserState* rec
		) {
	nodes.push_back(rec);
};

MsdcJMUserState* ListMsdcJMUserState::operator[](
			const uint ix
		) {
	MsdcJMUserState* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListMsdcJMUserState& ListMsdcJMUserState::operator=(
			const ListMsdcJMUserState& src
		) {
	MsdcJMUserState* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new MsdcJMUserState(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListMsdcJMUserState::operator==(
			const ListMsdcJMUserState& comp
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

bool ListMsdcJMUserState::operator!=(
			const ListMsdcJMUserState& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblMsdcJMUserState
 ******************************************************************************/

TblMsdcJMUserState::TblMsdcJMUserState() {
};

TblMsdcJMUserState::~TblMsdcJMUserState() {
};

bool TblMsdcJMUserState::loadRecBySQL(
			const string& sqlstr
			, MsdcJMUserState** rec
		) {
	return false;
};

ubigint TblMsdcJMUserState::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListMsdcJMUserState& rst
		) {
	return 0;
};

void TblMsdcJMUserState::insertRec(
			MsdcJMUserState* rec
		) {
};

ubigint TblMsdcJMUserState::insertNewRec(
			MsdcJMUserState** rec
			, const ubigint refMsdcMUser
			, const uint x1Startd
			, const uint ixVState
		) {
	ubigint retval = 0;
	MsdcJMUserState* _rec = NULL;

	_rec = new MsdcJMUserState(0, refMsdcMUser, x1Startd, ixVState);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblMsdcJMUserState::appendNewRecToRst(
			ListMsdcJMUserState& rst
			, MsdcJMUserState** rec
			, const ubigint refMsdcMUser
			, const uint x1Startd
			, const uint ixVState
		) {
	ubigint retval = 0;
	MsdcJMUserState* _rec = NULL;

	retval = insertNewRec(&_rec, refMsdcMUser, x1Startd, ixVState);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblMsdcJMUserState::insertRst(
			ListMsdcJMUserState& rst
			, bool transact
		) {
};

void TblMsdcJMUserState::updateRec(
			MsdcJMUserState* rec
		) {
};

void TblMsdcJMUserState::updateRst(
			ListMsdcJMUserState& rst
			, bool transact
		) {
};

void TblMsdcJMUserState::removeRecByRef(
			ubigint ref
		) {
};

bool TblMsdcJMUserState::loadRecByRef(
			ubigint ref
			, MsdcJMUserState** rec
		) {
	return false;
};

bool TblMsdcJMUserState::loadRecByUsrSta(
			ubigint refMsdcMUser
			, uint x1Startd
			, MsdcJMUserState** rec
		) {
	return false;
};

ubigint TblMsdcJMUserState::loadRefsByUsr(
			ubigint refMsdcMUser
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblMsdcJMUserState::loadRstByUsr(
			ubigint refMsdcMUser
			, const bool append
			, ListMsdcJMUserState& rst
		) {
	return 0;
};

ubigint TblMsdcJMUserState::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListMsdcJMUserState& rst
		) {
	ubigint numload = 0;
	MsdcJMUserState* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

/******************************************************************************
 class LiteTblMsdcJMUserState
 ******************************************************************************/

LiteTblMsdcJMUserState::LiteTblMsdcJMUserState() :
			TblMsdcJMUserState()
			, LiteTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;

	stmtLoadRecByUsrSta = NULL;
	stmtLoadRefsByUsr = NULL;
	stmtLoadRstByUsr = NULL;
};

LiteTblMsdcJMUserState::~LiteTblMsdcJMUserState() {
	if (stmtInsertRec) sqlite3_finalize(stmtInsertRec);
	if (stmtUpdateRec) sqlite3_finalize(stmtUpdateRec);
	if (stmtRemoveRecByRef) sqlite3_finalize(stmtRemoveRecByRef);

	if (stmtLoadRecByUsrSta) sqlite3_finalize(stmtLoadRecByUsrSta);
	if (stmtLoadRefsByUsr) sqlite3_finalize(stmtLoadRefsByUsr);
	if (stmtLoadRstByUsr) sqlite3_finalize(stmtLoadRstByUsr);
};

void LiteTblMsdcJMUserState::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblMsdcJMUserState (refMsdcMUser, x1Startd, ixVState) VALUES (?1,?2,?3)");
	stmtUpdateRec = createStatement("UPDATE TblMsdcJMUserState SET refMsdcMUser = ?1, x1Startd = ?2, ixVState = ?3 WHERE ref = ?4");
	stmtRemoveRecByRef = createStatement("DELETE FROM TblMsdcJMUserState WHERE ref = ?1");

	stmtLoadRecByRef = createStatement("SELECT ref, refMsdcMUser, x1Startd, ixVState FROM TblMsdcJMUserState WHERE ref = ?1");
	stmtLoadRecByUsrSta = createStatement("SELECT ref, refMsdcMUser, x1Startd, ixVState FROM TblMsdcJMUserState WHERE refMsdcMUser = ?1 AND x1Startd <= ?2 ORDER BY x1Startd DESC LIMIT 0,1");
	stmtLoadRefsByUsr = createStatement("SELECT ref FROM TblMsdcJMUserState WHERE refMsdcMUser = ?1");
	stmtLoadRstByUsr = createStatement("SELECT ref, refMsdcMUser, x1Startd, ixVState FROM TblMsdcJMUserState WHERE refMsdcMUser = ?1 ORDER BY x1Startd ASC");
};

bool LiteTblMsdcJMUserState::loadRec(
			sqlite3_stmt* stmt
			, MsdcJMUserState** rec
		) {
	int res;

	MsdcJMUserState* _rec = NULL;
	bool retval = false;

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		_rec = new MsdcJMUserState();

		_rec->ref = sqlite3_column_int64(stmt, 0);
		_rec->refMsdcMUser = sqlite3_column_int64(stmt, 1);
		_rec->x1Startd = sqlite3_column_int(stmt, 2);
		_rec->ixVState = sqlite3_column_int(stmt, 3);

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

ubigint LiteTblMsdcJMUserState::loadRst(
			sqlite3_stmt* stmt
			, const bool append
			, ListMsdcJMUserState& rst
		) {
	int res; ubigint numread = 0;

	MsdcJMUserState* rec;

	if (!append) rst.clear();

	res = sqlite3_step(stmt);
	while (res == SQLITE_ROW) {
		rec = new MsdcJMUserState();

		rec->ref = sqlite3_column_int64(stmt, 0);
		rec->refMsdcMUser = sqlite3_column_int64(stmt, 1);
		rec->x1Startd = sqlite3_column_int(stmt, 2);
		rec->ixVState = sqlite3_column_int(stmt, 3);

		rst.nodes.push_back(rec);

		numread++;

		res = sqlite3_step(stmt);
	};

	return(numread);
};

bool LiteTblMsdcJMUserState::loadRecByStmt(
			sqlite3_stmt* stmt
			, MsdcJMUserState** rec
		) {
	bool retval = loadRec(stmt, rec);

	sqlite3_reset(stmt);

	return retval;
};

ubigint LiteTblMsdcJMUserState::loadRstByStmt(
			sqlite3_stmt* stmt
			, const bool append
			, ListMsdcJMUserState& rst
		) {
	ubigint retval = loadRst(stmt, append, rst);

	sqlite3_reset(stmt);

	return retval;
};

bool LiteTblMsdcJMUserState::loadRecBySQL(
			const string& sqlstr
			, MsdcJMUserState** rec
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

ubigint LiteTblMsdcJMUserState::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListMsdcJMUserState& rst
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

void LiteTblMsdcJMUserState::insertRec(
			MsdcJMUserState* rec
		) {
	sqlite3_bind_int64(stmtInsertRec, 1, rec->refMsdcMUser);
	sqlite3_bind_int(stmtInsertRec, 2, rec->x1Startd);
	sqlite3_bind_int(stmtInsertRec, 3, rec->ixVState);

	if (sqlite3_step(stmtInsertRec) != SQLITE_DONE) throw DbsException("DbsException / SQLite: error executing statement! (TblMsdcJMUserState / stmtInsertRec)\n");
	rec->ref = sqlite3_last_insert_rowid(dbs);

	sqlite3_reset(stmtInsertRec);
};

void LiteTblMsdcJMUserState::insertRst(
			ListMsdcJMUserState& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void LiteTblMsdcJMUserState::updateRec(
			MsdcJMUserState* rec
		) {
	sqlite3_bind_int64(stmtUpdateRec, 1, rec->refMsdcMUser);
	sqlite3_bind_int(stmtUpdateRec, 2, rec->x1Startd);
	sqlite3_bind_int(stmtUpdateRec, 3, rec->ixVState);
	sqlite3_bind_int64(stmtUpdateRec, 4, rec->ref);

	if (sqlite3_step(stmtUpdateRec) != SQLITE_DONE) throw DbsException("DbsException / SQLite: error executing statement! (TblMsdcJMUserState / stmtUpdateRec)\n");

	sqlite3_reset(stmtUpdateRec);
};

void LiteTblMsdcJMUserState::updateRst(
			ListMsdcJMUserState& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void LiteTblMsdcJMUserState::removeRecByRef(
			ubigint ref
		) {
	sqlite3_bind_int64(stmtRemoveRecByRef, 1, ref);

	if (sqlite3_step(stmtRemoveRecByRef) != SQLITE_DONE) throw DbsException("DbsException / SQLite: error executing statement! (TblMsdcJMUserState / stmtRemoveRecByRef)\n");

	sqlite3_reset(stmtRemoveRecByRef);
};

bool LiteTblMsdcJMUserState::loadRecByRef(
			ubigint ref
			, MsdcJMUserState** rec
		) {
	if (ref == 0) return false;

	sqlite3_bind_int64(stmtLoadRecByRef, 1, ref);

	return loadRecByStmt(stmtLoadRecByRef, rec);
};

bool LiteTblMsdcJMUserState::loadRecByUsrSta(
			ubigint refMsdcMUser
			, uint x1Startd
			, MsdcJMUserState** rec
		) {
	sqlite3_bind_int64(stmtLoadRecByUsrSta, 1, refMsdcMUser);
	sqlite3_bind_int(stmtLoadRecByUsrSta, 2, x1Startd);

	return loadRecByStmt(stmtLoadRecByUsrSta, rec);
};

ubigint LiteTblMsdcJMUserState::loadRefsByUsr(
			ubigint refMsdcMUser
			, const bool append
			, vector<ubigint>& refs
		) {
	sqlite3_bind_int64(stmtLoadRefsByUsr, 1, refMsdcMUser);

	return loadRefsByStmt(stmtLoadRefsByUsr, append, refs);
};

ubigint LiteTblMsdcJMUserState::loadRstByUsr(
			ubigint refMsdcMUser
			, const bool append
			, ListMsdcJMUserState& rst
		) {
	sqlite3_bind_int64(stmtLoadRstByUsr, 1, refMsdcMUser);

	return loadRstByStmt(stmtLoadRstByUsr, append, rst);
};

