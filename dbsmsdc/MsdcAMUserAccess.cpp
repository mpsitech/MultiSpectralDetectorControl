/**
  * \file MsdcAMUserAccess.cpp
  * database access for table TblMsdcAMUserAccess (implementation)
  * \author Alexander Wirthmueller
  * \date created: 12 Sep 2018
  * \date modified: 12 Sep 2018
  */

#include "MsdcAMUserAccess.h"

/******************************************************************************
 class MsdcAMUserAccess
 ******************************************************************************/

MsdcAMUserAccess::MsdcAMUserAccess(
			const ubigint ref
			, const ubigint refMsdcMUser
			, const uint x1IxMsdcVFeatgroup
			, const string x2FeaSrefUix
			, const uint ixMsdcWAccess
		) {

	this->ref = ref;
	this->refMsdcMUser = refMsdcMUser;
	this->x1IxMsdcVFeatgroup = x1IxMsdcVFeatgroup;
	this->x2FeaSrefUix = x2FeaSrefUix;
	this->ixMsdcWAccess = ixMsdcWAccess;
};

bool MsdcAMUserAccess::operator==(
			const MsdcAMUserAccess& comp
		) {
	return false;
};

bool MsdcAMUserAccess::operator!=(
			const MsdcAMUserAccess& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListMsdcAMUserAccess
 ******************************************************************************/

ListMsdcAMUserAccess::ListMsdcAMUserAccess() {
};

ListMsdcAMUserAccess::ListMsdcAMUserAccess(
			const ListMsdcAMUserAccess& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new MsdcAMUserAccess(*(src.nodes[i]));
};

ListMsdcAMUserAccess::~ListMsdcAMUserAccess() {
	clear();
};

void ListMsdcAMUserAccess::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListMsdcAMUserAccess::size() const {
	return(nodes.size());
};

void ListMsdcAMUserAccess::append(
			MsdcAMUserAccess* rec
		) {
	nodes.push_back(rec);
};

MsdcAMUserAccess* ListMsdcAMUserAccess::operator[](
			const uint ix
		) {
	MsdcAMUserAccess* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListMsdcAMUserAccess& ListMsdcAMUserAccess::operator=(
			const ListMsdcAMUserAccess& src
		) {
	MsdcAMUserAccess* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new MsdcAMUserAccess(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListMsdcAMUserAccess::operator==(
			const ListMsdcAMUserAccess& comp
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

bool ListMsdcAMUserAccess::operator!=(
			const ListMsdcAMUserAccess& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblMsdcAMUserAccess
 ******************************************************************************/

TblMsdcAMUserAccess::TblMsdcAMUserAccess() {
};

TblMsdcAMUserAccess::~TblMsdcAMUserAccess() {
};

bool TblMsdcAMUserAccess::loadRecBySQL(
			const string& sqlstr
			, MsdcAMUserAccess** rec
		) {
	return false;
};

ubigint TblMsdcAMUserAccess::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListMsdcAMUserAccess& rst
		) {
	return 0;
};

void TblMsdcAMUserAccess::insertRec(
			MsdcAMUserAccess* rec
		) {
};

ubigint TblMsdcAMUserAccess::insertNewRec(
			MsdcAMUserAccess** rec
			, const ubigint refMsdcMUser
			, const uint x1IxMsdcVFeatgroup
			, const string x2FeaSrefUix
			, const uint ixMsdcWAccess
		) {
	ubigint retval = 0;
	MsdcAMUserAccess* _rec = NULL;

	_rec = new MsdcAMUserAccess(0, refMsdcMUser, x1IxMsdcVFeatgroup, x2FeaSrefUix, ixMsdcWAccess);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblMsdcAMUserAccess::appendNewRecToRst(
			ListMsdcAMUserAccess& rst
			, MsdcAMUserAccess** rec
			, const ubigint refMsdcMUser
			, const uint x1IxMsdcVFeatgroup
			, const string x2FeaSrefUix
			, const uint ixMsdcWAccess
		) {
	ubigint retval = 0;
	MsdcAMUserAccess* _rec = NULL;

	retval = insertNewRec(&_rec, refMsdcMUser, x1IxMsdcVFeatgroup, x2FeaSrefUix, ixMsdcWAccess);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblMsdcAMUserAccess::insertRst(
			ListMsdcAMUserAccess& rst
			, bool transact
		) {
};

void TblMsdcAMUserAccess::updateRec(
			MsdcAMUserAccess* rec
		) {
};

void TblMsdcAMUserAccess::updateRst(
			ListMsdcAMUserAccess& rst
			, bool transact
		) {
};

void TblMsdcAMUserAccess::removeRecByRef(
			ubigint ref
		) {
};

bool TblMsdcAMUserAccess::loadRecByRef(
			ubigint ref
			, MsdcAMUserAccess** rec
		) {
	return false;
};

ubigint TblMsdcAMUserAccess::loadRefsByUsr(
			ubigint refMsdcMUser
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblMsdcAMUserAccess::loadRstByUsr(
			ubigint refMsdcMUser
			, const bool append
			, ListMsdcAMUserAccess& rst
		) {
	return 0;
};

ubigint TblMsdcAMUserAccess::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListMsdcAMUserAccess& rst
		) {
	ubigint numload = 0;
	MsdcAMUserAccess* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

/******************************************************************************
 class LiteTblMsdcAMUserAccess
 ******************************************************************************/

LiteTblMsdcAMUserAccess::LiteTblMsdcAMUserAccess() :
			TblMsdcAMUserAccess()
			, LiteTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;

	stmtLoadRefsByUsr = NULL;
	stmtLoadRstByUsr = NULL;
};

LiteTblMsdcAMUserAccess::~LiteTblMsdcAMUserAccess() {
	if (stmtInsertRec) sqlite3_finalize(stmtInsertRec);
	if (stmtUpdateRec) sqlite3_finalize(stmtUpdateRec);
	if (stmtRemoveRecByRef) sqlite3_finalize(stmtRemoveRecByRef);

	if (stmtLoadRefsByUsr) sqlite3_finalize(stmtLoadRefsByUsr);
	if (stmtLoadRstByUsr) sqlite3_finalize(stmtLoadRstByUsr);
};

void LiteTblMsdcAMUserAccess::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblMsdcAMUserAccess (refMsdcMUser, x1IxMsdcVFeatgroup, x2FeaSrefUix, ixMsdcWAccess) VALUES (?1,?2,?3,?4)");
	stmtUpdateRec = createStatement("UPDATE TblMsdcAMUserAccess SET refMsdcMUser = ?1, x1IxMsdcVFeatgroup = ?2, x2FeaSrefUix = ?3, ixMsdcWAccess = ?4 WHERE ref = ?5");
	stmtRemoveRecByRef = createStatement("DELETE FROM TblMsdcAMUserAccess WHERE ref = ?1");

	stmtLoadRecByRef = createStatement("SELECT ref, refMsdcMUser, x1IxMsdcVFeatgroup, x2FeaSrefUix, ixMsdcWAccess FROM TblMsdcAMUserAccess WHERE ref = ?1");
	stmtLoadRefsByUsr = createStatement("SELECT ref FROM TblMsdcAMUserAccess WHERE refMsdcMUser = ?1");
	stmtLoadRstByUsr = createStatement("SELECT ref, refMsdcMUser, x1IxMsdcVFeatgroup, x2FeaSrefUix, ixMsdcWAccess FROM TblMsdcAMUserAccess WHERE refMsdcMUser = ?1 ORDER BY x1IxMsdcVFeatgroup ASC, x2FeaSrefUix ASC");
};

bool LiteTblMsdcAMUserAccess::loadRec(
			sqlite3_stmt* stmt
			, MsdcAMUserAccess** rec
		) {
	int res;

	MsdcAMUserAccess* _rec = NULL;
	bool retval = false;

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		_rec = new MsdcAMUserAccess();

		_rec->ref = sqlite3_column_int64(stmt, 0);
		_rec->refMsdcMUser = sqlite3_column_int64(stmt, 1);
		_rec->x1IxMsdcVFeatgroup = sqlite3_column_int(stmt, 2);
		_rec->x2FeaSrefUix.assign((const char*) sqlite3_column_text(stmt, 3));
		_rec->ixMsdcWAccess = sqlite3_column_int(stmt, 4);

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

ubigint LiteTblMsdcAMUserAccess::loadRst(
			sqlite3_stmt* stmt
			, const bool append
			, ListMsdcAMUserAccess& rst
		) {
	int res; ubigint numread = 0;

	MsdcAMUserAccess* rec;

	if (!append) rst.clear();

	res = sqlite3_step(stmt);
	while (res == SQLITE_ROW) {
		rec = new MsdcAMUserAccess();

		rec->ref = sqlite3_column_int64(stmt, 0);
		rec->refMsdcMUser = sqlite3_column_int64(stmt, 1);
		rec->x1IxMsdcVFeatgroup = sqlite3_column_int(stmt, 2);
		rec->x2FeaSrefUix.assign((const char*) sqlite3_column_text(stmt, 3));
		rec->ixMsdcWAccess = sqlite3_column_int(stmt, 4);

		rst.nodes.push_back(rec);

		numread++;

		res = sqlite3_step(stmt);
	};

	return(numread);
};

bool LiteTblMsdcAMUserAccess::loadRecByStmt(
			sqlite3_stmt* stmt
			, MsdcAMUserAccess** rec
		) {
	bool retval = loadRec(stmt, rec);

	sqlite3_reset(stmt);

	return retval;
};

ubigint LiteTblMsdcAMUserAccess::loadRstByStmt(
			sqlite3_stmt* stmt
			, const bool append
			, ListMsdcAMUserAccess& rst
		) {
	ubigint retval = loadRst(stmt, append, rst);

	sqlite3_reset(stmt);

	return retval;
};

bool LiteTblMsdcAMUserAccess::loadRecBySQL(
			const string& sqlstr
			, MsdcAMUserAccess** rec
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

ubigint LiteTblMsdcAMUserAccess::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListMsdcAMUserAccess& rst
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

void LiteTblMsdcAMUserAccess::insertRec(
			MsdcAMUserAccess* rec
		) {
	sqlite3_bind_int64(stmtInsertRec, 1, rec->refMsdcMUser);
	sqlite3_bind_int(stmtInsertRec, 2, rec->x1IxMsdcVFeatgroup);
	sqlite3_bind_text(stmtInsertRec, 3, rec->x2FeaSrefUix.c_str(), rec->x2FeaSrefUix.length(), SQLITE_STATIC);
	sqlite3_bind_int(stmtInsertRec, 4, rec->ixMsdcWAccess);

	if (sqlite3_step(stmtInsertRec) != SQLITE_DONE) throw DbsException("DbsException / SQLite: error executing statement! (TblMsdcAMUserAccess / stmtInsertRec)\n");
	rec->ref = sqlite3_last_insert_rowid(dbs);

	sqlite3_reset(stmtInsertRec);
};

void LiteTblMsdcAMUserAccess::insertRst(
			ListMsdcAMUserAccess& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void LiteTblMsdcAMUserAccess::updateRec(
			MsdcAMUserAccess* rec
		) {
	sqlite3_bind_int64(stmtUpdateRec, 1, rec->refMsdcMUser);
	sqlite3_bind_int(stmtUpdateRec, 2, rec->x1IxMsdcVFeatgroup);
	sqlite3_bind_text(stmtUpdateRec, 3, rec->x2FeaSrefUix.c_str(), rec->x2FeaSrefUix.length(), SQLITE_STATIC);
	sqlite3_bind_int(stmtUpdateRec, 4, rec->ixMsdcWAccess);
	sqlite3_bind_int64(stmtUpdateRec, 5, rec->ref);

	if (sqlite3_step(stmtUpdateRec) != SQLITE_DONE) throw DbsException("DbsException / SQLite: error executing statement! (TblMsdcAMUserAccess / stmtUpdateRec)\n");

	sqlite3_reset(stmtUpdateRec);
};

void LiteTblMsdcAMUserAccess::updateRst(
			ListMsdcAMUserAccess& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void LiteTblMsdcAMUserAccess::removeRecByRef(
			ubigint ref
		) {
	sqlite3_bind_int64(stmtRemoveRecByRef, 1, ref);

	if (sqlite3_step(stmtRemoveRecByRef) != SQLITE_DONE) throw DbsException("DbsException / SQLite: error executing statement! (TblMsdcAMUserAccess / stmtRemoveRecByRef)\n");

	sqlite3_reset(stmtRemoveRecByRef);
};

bool LiteTblMsdcAMUserAccess::loadRecByRef(
			ubigint ref
			, MsdcAMUserAccess** rec
		) {
	sqlite3_bind_int64(stmtLoadRecByRef, 1, ref);

	return loadRecByStmt(stmtLoadRecByRef, rec);
};

ubigint LiteTblMsdcAMUserAccess::loadRefsByUsr(
			ubigint refMsdcMUser
			, const bool append
			, vector<ubigint>& refs
		) {
	sqlite3_bind_int64(stmtLoadRefsByUsr, 1, refMsdcMUser);

	return loadRefsByStmt(stmtLoadRefsByUsr, append, refs);
};

ubigint LiteTblMsdcAMUserAccess::loadRstByUsr(
			ubigint refMsdcMUser
			, const bool append
			, ListMsdcAMUserAccess& rst
		) {
	sqlite3_bind_int64(stmtLoadRstByUsr, 1, refMsdcMUser);

	return loadRstByStmt(stmtLoadRstByUsr, append, rst);
};

