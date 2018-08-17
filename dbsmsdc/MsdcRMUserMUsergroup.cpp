/**
  * \file MsdcRMUserMUsergroup.cpp
  * database access for table TblMsdcRMUserMUsergroup (implementation)
  * \author Alexander Wirthmueller
  * \date created: 15 Aug 2018
  * \date modified: 15 Aug 2018
  */

#include "MsdcRMUserMUsergroup.h"

/******************************************************************************
 class MsdcRMUserMUsergroup
 ******************************************************************************/

MsdcRMUserMUsergroup::MsdcRMUserMUsergroup(
			const ubigint ref
			, const ubigint refMsdcMUser
			, const ubigint refMsdcMUsergroup
			, const uint ixMsdcVUserlevel
		) {

	this->ref = ref;
	this->refMsdcMUser = refMsdcMUser;
	this->refMsdcMUsergroup = refMsdcMUsergroup;
	this->ixMsdcVUserlevel = ixMsdcVUserlevel;
};

bool MsdcRMUserMUsergroup::operator==(
			const MsdcRMUserMUsergroup& comp
		) {
	return false;
};

bool MsdcRMUserMUsergroup::operator!=(
			const MsdcRMUserMUsergroup& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListMsdcRMUserMUsergroup
 ******************************************************************************/

ListMsdcRMUserMUsergroup::ListMsdcRMUserMUsergroup() {
};

ListMsdcRMUserMUsergroup::ListMsdcRMUserMUsergroup(
			const ListMsdcRMUserMUsergroup& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new MsdcRMUserMUsergroup(*(src.nodes[i]));
};

ListMsdcRMUserMUsergroup::~ListMsdcRMUserMUsergroup() {
	clear();
};

void ListMsdcRMUserMUsergroup::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListMsdcRMUserMUsergroup::size() const {
	return(nodes.size());
};

void ListMsdcRMUserMUsergroup::append(
			MsdcRMUserMUsergroup* rec
		) {
	nodes.push_back(rec);
};

MsdcRMUserMUsergroup* ListMsdcRMUserMUsergroup::operator[](
			const uint ix
		) {
	MsdcRMUserMUsergroup* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListMsdcRMUserMUsergroup& ListMsdcRMUserMUsergroup::operator=(
			const ListMsdcRMUserMUsergroup& src
		) {
	MsdcRMUserMUsergroup* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new MsdcRMUserMUsergroup(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListMsdcRMUserMUsergroup::operator==(
			const ListMsdcRMUserMUsergroup& comp
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

bool ListMsdcRMUserMUsergroup::operator!=(
			const ListMsdcRMUserMUsergroup& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblMsdcRMUserMUsergroup
 ******************************************************************************/

TblMsdcRMUserMUsergroup::TblMsdcRMUserMUsergroup() {
};

TblMsdcRMUserMUsergroup::~TblMsdcRMUserMUsergroup() {
};

bool TblMsdcRMUserMUsergroup::loadRecBySQL(
			const string& sqlstr
			, MsdcRMUserMUsergroup** rec
		) {
	return false;
};

ubigint TblMsdcRMUserMUsergroup::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListMsdcRMUserMUsergroup& rst
		) {
	return 0;
};

void TblMsdcRMUserMUsergroup::insertRec(
			MsdcRMUserMUsergroup* rec
		) {
};

ubigint TblMsdcRMUserMUsergroup::insertNewRec(
			MsdcRMUserMUsergroup** rec
			, const ubigint refMsdcMUser
			, const ubigint refMsdcMUsergroup
			, const uint ixMsdcVUserlevel
		) {
	ubigint retval = 0;
	MsdcRMUserMUsergroup* _rec = NULL;

	_rec = new MsdcRMUserMUsergroup(0, refMsdcMUser, refMsdcMUsergroup, ixMsdcVUserlevel);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblMsdcRMUserMUsergroup::appendNewRecToRst(
			ListMsdcRMUserMUsergroup& rst
			, MsdcRMUserMUsergroup** rec
			, const ubigint refMsdcMUser
			, const ubigint refMsdcMUsergroup
			, const uint ixMsdcVUserlevel
		) {
	ubigint retval = 0;
	MsdcRMUserMUsergroup* _rec = NULL;

	retval = insertNewRec(&_rec, refMsdcMUser, refMsdcMUsergroup, ixMsdcVUserlevel);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblMsdcRMUserMUsergroup::insertRst(
			ListMsdcRMUserMUsergroup& rst
			, bool transact
		) {
};

void TblMsdcRMUserMUsergroup::updateRec(
			MsdcRMUserMUsergroup* rec
		) {
};

void TblMsdcRMUserMUsergroup::updateRst(
			ListMsdcRMUserMUsergroup& rst
			, bool transact
		) {
};

void TblMsdcRMUserMUsergroup::removeRecByRef(
			ubigint ref
		) {
};

bool TblMsdcRMUserMUsergroup::loadRecByRef(
			ubigint ref
			, MsdcRMUserMUsergroup** rec
		) {
	return false;
};

ubigint TblMsdcRMUserMUsergroup::loadRstByUsg(
			ubigint refMsdcMUsergroup
			, const bool append
			, ListMsdcRMUserMUsergroup& rst
		) {
	return 0;
};

ubigint TblMsdcRMUserMUsergroup::loadRstByUsr(
			ubigint refMsdcMUser
			, const bool append
			, ListMsdcRMUserMUsergroup& rst
		) {
	return 0;
};

ubigint TblMsdcRMUserMUsergroup::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListMsdcRMUserMUsergroup& rst
		) {
	ubigint numload = 0;
	MsdcRMUserMUsergroup* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

/******************************************************************************
 class LiteTblMsdcRMUserMUsergroup
 ******************************************************************************/

LiteTblMsdcRMUserMUsergroup::LiteTblMsdcRMUserMUsergroup() : TblMsdcRMUserMUsergroup(), LiteTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;

	stmtLoadRstByUsg = NULL;
	stmtLoadRstByUsr = NULL;
};

LiteTblMsdcRMUserMUsergroup::~LiteTblMsdcRMUserMUsergroup() {
	if (stmtInsertRec) sqlite3_finalize(stmtInsertRec);
	if (stmtUpdateRec) sqlite3_finalize(stmtUpdateRec);
	if (stmtRemoveRecByRef) sqlite3_finalize(stmtRemoveRecByRef);

	if (stmtLoadRstByUsg) sqlite3_finalize(stmtLoadRstByUsg);
	if (stmtLoadRstByUsr) sqlite3_finalize(stmtLoadRstByUsr);
};

void LiteTblMsdcRMUserMUsergroup::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblMsdcRMUserMUsergroup (refMsdcMUser, refMsdcMUsergroup, ixMsdcVUserlevel) VALUES (?1,?2,?3)");
	stmtUpdateRec = createStatement("UPDATE TblMsdcRMUserMUsergroup SET refMsdcMUser = ?1, refMsdcMUsergroup = ?2, ixMsdcVUserlevel = ?3 WHERE ref = ?4");
	stmtRemoveRecByRef = createStatement("DELETE FROM TblMsdcRMUserMUsergroup WHERE ref = ?1");

	stmtLoadRecByRef = createStatement("SELECT ref, refMsdcMUser, refMsdcMUsergroup, ixMsdcVUserlevel FROM TblMsdcRMUserMUsergroup WHERE ref = ?1");
	stmtLoadRstByUsg = createStatement("SELECT ref, refMsdcMUser, refMsdcMUsergroup, ixMsdcVUserlevel FROM TblMsdcRMUserMUsergroup WHERE refMsdcMUsergroup = ?1");
	stmtLoadRstByUsr = createStatement("SELECT ref, refMsdcMUser, refMsdcMUsergroup, ixMsdcVUserlevel FROM TblMsdcRMUserMUsergroup WHERE refMsdcMUser = ?1");
};

bool LiteTblMsdcRMUserMUsergroup::loadRec(
			sqlite3_stmt* stmt
			, MsdcRMUserMUsergroup** rec
		) {
	int res;

	MsdcRMUserMUsergroup* _rec = NULL;
	bool retval = false;

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		_rec = new MsdcRMUserMUsergroup();

		_rec->ref = sqlite3_column_int64(stmt, 0);
		_rec->refMsdcMUser = sqlite3_column_int64(stmt, 1);
		_rec->refMsdcMUsergroup = sqlite3_column_int64(stmt, 2);
		_rec->ixMsdcVUserlevel = sqlite3_column_int(stmt, 3);

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

ubigint LiteTblMsdcRMUserMUsergroup::loadRst(
			sqlite3_stmt* stmt
			, const bool append
			, ListMsdcRMUserMUsergroup& rst
		) {
	int res; ubigint numread = 0;

	MsdcRMUserMUsergroup* rec;

	if (!append) rst.clear();

	res = sqlite3_step(stmt);
	while (res == SQLITE_ROW) {
		rec = new MsdcRMUserMUsergroup();

		rec->ref = sqlite3_column_int64(stmt, 0);
		rec->refMsdcMUser = sqlite3_column_int64(stmt, 1);
		rec->refMsdcMUsergroup = sqlite3_column_int64(stmt, 2);
		rec->ixMsdcVUserlevel = sqlite3_column_int(stmt, 3);

		rst.nodes.push_back(rec);

		numread++;

		res = sqlite3_step(stmt);
	};

	return(numread);
};

bool LiteTblMsdcRMUserMUsergroup::loadRecByStmt(
			sqlite3_stmt* stmt
			, MsdcRMUserMUsergroup** rec
		) {
	bool retval = loadRec(stmt, rec);

	sqlite3_reset(stmt);

	return retval;
};

ubigint LiteTblMsdcRMUserMUsergroup::loadRstByStmt(
			sqlite3_stmt* stmt
			, const bool append
			, ListMsdcRMUserMUsergroup& rst
		) {
	ubigint retval = loadRst(stmt, append, rst);

	sqlite3_reset(stmt);

	return retval;
};

bool LiteTblMsdcRMUserMUsergroup::loadRecBySQL(
			const string& sqlstr
			, MsdcRMUserMUsergroup** rec
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

ubigint LiteTblMsdcRMUserMUsergroup::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListMsdcRMUserMUsergroup& rst
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

void LiteTblMsdcRMUserMUsergroup::insertRec(
			MsdcRMUserMUsergroup* rec
		) {
	sqlite3_bind_int64(stmtInsertRec, 1, rec->refMsdcMUser);
	sqlite3_bind_int64(stmtInsertRec, 2, rec->refMsdcMUsergroup);
	sqlite3_bind_int(stmtInsertRec, 3, rec->ixMsdcVUserlevel);

	if (sqlite3_step(stmtInsertRec) != SQLITE_DONE) throw DbsException("DbsException / SQLite: error executing statement! (TblMsdcRMUserMUsergroup / stmtInsertRec)\n");
	rec->ref = sqlite3_last_insert_rowid(dbs);

	sqlite3_reset(stmtInsertRec);
};

void LiteTblMsdcRMUserMUsergroup::insertRst(
			ListMsdcRMUserMUsergroup& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void LiteTblMsdcRMUserMUsergroup::updateRec(
			MsdcRMUserMUsergroup* rec
		) {
	sqlite3_bind_int64(stmtUpdateRec, 1, rec->refMsdcMUser);
	sqlite3_bind_int64(stmtUpdateRec, 2, rec->refMsdcMUsergroup);
	sqlite3_bind_int(stmtUpdateRec, 3, rec->ixMsdcVUserlevel);
	sqlite3_bind_int64(stmtUpdateRec, 4, rec->ref);

	if (sqlite3_step(stmtUpdateRec) != SQLITE_DONE) throw DbsException("DbsException / SQLite: error executing statement! (TblMsdcRMUserMUsergroup / stmtUpdateRec)\n");

	sqlite3_reset(stmtUpdateRec);
};

void LiteTblMsdcRMUserMUsergroup::updateRst(
			ListMsdcRMUserMUsergroup& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void LiteTblMsdcRMUserMUsergroup::removeRecByRef(
			ubigint ref
		) {
	sqlite3_bind_int64(stmtRemoveRecByRef, 1, ref);

	if (sqlite3_step(stmtRemoveRecByRef) != SQLITE_DONE) throw DbsException("DbsException / SQLite: error executing statement! (TblMsdcRMUserMUsergroup / stmtRemoveRecByRef)\n");

	sqlite3_reset(stmtRemoveRecByRef);
};

bool LiteTblMsdcRMUserMUsergroup::loadRecByRef(
			ubigint ref
			, MsdcRMUserMUsergroup** rec
		) {
	sqlite3_bind_int64(stmtLoadRecByRef, 1, ref);

	return loadRecByStmt(stmtLoadRecByRef, rec);
};

ubigint LiteTblMsdcRMUserMUsergroup::loadRstByUsg(
			ubigint refMsdcMUsergroup
			, const bool append
			, ListMsdcRMUserMUsergroup& rst
		) {
	sqlite3_bind_int64(stmtLoadRstByUsg, 1, refMsdcMUsergroup);

	return loadRstByStmt(stmtLoadRstByUsg, append, rst);
};

ubigint LiteTblMsdcRMUserMUsergroup::loadRstByUsr(
			ubigint refMsdcMUser
			, const bool append
			, ListMsdcRMUserMUsergroup& rst
		) {
	sqlite3_bind_int64(stmtLoadRstByUsr, 1, refMsdcMUser);

	return loadRstByStmt(stmtLoadRstByUsr, append, rst);
};

