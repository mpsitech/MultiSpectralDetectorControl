/**
  * \file MsdcAMUsergroupAccess.cpp
  * database access for table TblMsdcAMUsergroupAccess (implementation)
  * \author Alexander Wirthmueller
  * \date created: 18 Dec 2018
  * \date modified: 18 Dec 2018
  */

#include "MsdcAMUsergroupAccess.h"

/******************************************************************************
 class MsdcAMUsergroupAccess
 ******************************************************************************/

MsdcAMUsergroupAccess::MsdcAMUsergroupAccess(
			const ubigint ref
			, const ubigint refMsdcMUsergroup
			, const uint x1IxMsdcVFeatgroup
			, const string x2FeaSrefUix
			, const uint ixMsdcWAccess
		) {

	this->ref = ref;
	this->refMsdcMUsergroup = refMsdcMUsergroup;
	this->x1IxMsdcVFeatgroup = x1IxMsdcVFeatgroup;
	this->x2FeaSrefUix = x2FeaSrefUix;
	this->ixMsdcWAccess = ixMsdcWAccess;
};

bool MsdcAMUsergroupAccess::operator==(
			const MsdcAMUsergroupAccess& comp
		) {
	return false;
};

bool MsdcAMUsergroupAccess::operator!=(
			const MsdcAMUsergroupAccess& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListMsdcAMUsergroupAccess
 ******************************************************************************/

ListMsdcAMUsergroupAccess::ListMsdcAMUsergroupAccess() {
};

ListMsdcAMUsergroupAccess::ListMsdcAMUsergroupAccess(
			const ListMsdcAMUsergroupAccess& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new MsdcAMUsergroupAccess(*(src.nodes[i]));
};

ListMsdcAMUsergroupAccess::~ListMsdcAMUsergroupAccess() {
	clear();
};

void ListMsdcAMUsergroupAccess::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListMsdcAMUsergroupAccess::size() const {
	return(nodes.size());
};

void ListMsdcAMUsergroupAccess::append(
			MsdcAMUsergroupAccess* rec
		) {
	nodes.push_back(rec);
};

MsdcAMUsergroupAccess* ListMsdcAMUsergroupAccess::operator[](
			const uint ix
		) {
	MsdcAMUsergroupAccess* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListMsdcAMUsergroupAccess& ListMsdcAMUsergroupAccess::operator=(
			const ListMsdcAMUsergroupAccess& src
		) {
	MsdcAMUsergroupAccess* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new MsdcAMUsergroupAccess(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListMsdcAMUsergroupAccess::operator==(
			const ListMsdcAMUsergroupAccess& comp
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

bool ListMsdcAMUsergroupAccess::operator!=(
			const ListMsdcAMUsergroupAccess& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblMsdcAMUsergroupAccess
 ******************************************************************************/

TblMsdcAMUsergroupAccess::TblMsdcAMUsergroupAccess() {
};

TblMsdcAMUsergroupAccess::~TblMsdcAMUsergroupAccess() {
};

bool TblMsdcAMUsergroupAccess::loadRecBySQL(
			const string& sqlstr
			, MsdcAMUsergroupAccess** rec
		) {
	return false;
};

ubigint TblMsdcAMUsergroupAccess::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListMsdcAMUsergroupAccess& rst
		) {
	return 0;
};

void TblMsdcAMUsergroupAccess::insertRec(
			MsdcAMUsergroupAccess* rec
		) {
};

ubigint TblMsdcAMUsergroupAccess::insertNewRec(
			MsdcAMUsergroupAccess** rec
			, const ubigint refMsdcMUsergroup
			, const uint x1IxMsdcVFeatgroup
			, const string x2FeaSrefUix
			, const uint ixMsdcWAccess
		) {
	ubigint retval = 0;
	MsdcAMUsergroupAccess* _rec = NULL;

	_rec = new MsdcAMUsergroupAccess(0, refMsdcMUsergroup, x1IxMsdcVFeatgroup, x2FeaSrefUix, ixMsdcWAccess);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblMsdcAMUsergroupAccess::appendNewRecToRst(
			ListMsdcAMUsergroupAccess& rst
			, MsdcAMUsergroupAccess** rec
			, const ubigint refMsdcMUsergroup
			, const uint x1IxMsdcVFeatgroup
			, const string x2FeaSrefUix
			, const uint ixMsdcWAccess
		) {
	ubigint retval = 0;
	MsdcAMUsergroupAccess* _rec = NULL;

	retval = insertNewRec(&_rec, refMsdcMUsergroup, x1IxMsdcVFeatgroup, x2FeaSrefUix, ixMsdcWAccess);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblMsdcAMUsergroupAccess::insertRst(
			ListMsdcAMUsergroupAccess& rst
			, bool transact
		) {
};

void TblMsdcAMUsergroupAccess::updateRec(
			MsdcAMUsergroupAccess* rec
		) {
};

void TblMsdcAMUsergroupAccess::updateRst(
			ListMsdcAMUsergroupAccess& rst
			, bool transact
		) {
};

void TblMsdcAMUsergroupAccess::removeRecByRef(
			ubigint ref
		) {
};

bool TblMsdcAMUsergroupAccess::loadRecByRef(
			ubigint ref
			, MsdcAMUsergroupAccess** rec
		) {
	return false;
};

ubigint TblMsdcAMUsergroupAccess::loadRefsByUsg(
			ubigint refMsdcMUsergroup
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblMsdcAMUsergroupAccess::loadRstByUsg(
			ubigint refMsdcMUsergroup
			, const bool append
			, ListMsdcAMUsergroupAccess& rst
		) {
	return 0;
};

ubigint TblMsdcAMUsergroupAccess::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListMsdcAMUsergroupAccess& rst
		) {
	ubigint numload = 0;
	MsdcAMUsergroupAccess* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

/******************************************************************************
 class LiteTblMsdcAMUsergroupAccess
 ******************************************************************************/

LiteTblMsdcAMUsergroupAccess::LiteTblMsdcAMUsergroupAccess() :
			TblMsdcAMUsergroupAccess()
			, LiteTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;

	stmtLoadRefsByUsg = NULL;
	stmtLoadRstByUsg = NULL;
};

LiteTblMsdcAMUsergroupAccess::~LiteTblMsdcAMUsergroupAccess() {
	if (stmtInsertRec) sqlite3_finalize(stmtInsertRec);
	if (stmtUpdateRec) sqlite3_finalize(stmtUpdateRec);
	if (stmtRemoveRecByRef) sqlite3_finalize(stmtRemoveRecByRef);

	if (stmtLoadRefsByUsg) sqlite3_finalize(stmtLoadRefsByUsg);
	if (stmtLoadRstByUsg) sqlite3_finalize(stmtLoadRstByUsg);
};

void LiteTblMsdcAMUsergroupAccess::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblMsdcAMUsergroupAccess (refMsdcMUsergroup, x1IxMsdcVFeatgroup, x2FeaSrefUix, ixMsdcWAccess) VALUES (?1,?2,?3,?4)");
	stmtUpdateRec = createStatement("UPDATE TblMsdcAMUsergroupAccess SET refMsdcMUsergroup = ?1, x1IxMsdcVFeatgroup = ?2, x2FeaSrefUix = ?3, ixMsdcWAccess = ?4 WHERE ref = ?5");
	stmtRemoveRecByRef = createStatement("DELETE FROM TblMsdcAMUsergroupAccess WHERE ref = ?1");

	stmtLoadRecByRef = createStatement("SELECT ref, refMsdcMUsergroup, x1IxMsdcVFeatgroup, x2FeaSrefUix, ixMsdcWAccess FROM TblMsdcAMUsergroupAccess WHERE ref = ?1");
	stmtLoadRefsByUsg = createStatement("SELECT ref FROM TblMsdcAMUsergroupAccess WHERE refMsdcMUsergroup = ?1");
	stmtLoadRstByUsg = createStatement("SELECT ref, refMsdcMUsergroup, x1IxMsdcVFeatgroup, x2FeaSrefUix, ixMsdcWAccess FROM TblMsdcAMUsergroupAccess WHERE refMsdcMUsergroup = ?1 ORDER BY x1IxMsdcVFeatgroup ASC, x2FeaSrefUix ASC");
};

bool LiteTblMsdcAMUsergroupAccess::loadRec(
			sqlite3_stmt* stmt
			, MsdcAMUsergroupAccess** rec
		) {
	int res;

	MsdcAMUsergroupAccess* _rec = NULL;
	bool retval = false;

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		_rec = new MsdcAMUsergroupAccess();

		_rec->ref = sqlite3_column_int64(stmt, 0);
		_rec->refMsdcMUsergroup = sqlite3_column_int64(stmt, 1);
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

ubigint LiteTblMsdcAMUsergroupAccess::loadRst(
			sqlite3_stmt* stmt
			, const bool append
			, ListMsdcAMUsergroupAccess& rst
		) {
	int res; ubigint numread = 0;

	MsdcAMUsergroupAccess* rec;

	if (!append) rst.clear();

	res = sqlite3_step(stmt);
	while (res == SQLITE_ROW) {
		rec = new MsdcAMUsergroupAccess();

		rec->ref = sqlite3_column_int64(stmt, 0);
		rec->refMsdcMUsergroup = sqlite3_column_int64(stmt, 1);
		rec->x1IxMsdcVFeatgroup = sqlite3_column_int(stmt, 2);
		rec->x2FeaSrefUix.assign((const char*) sqlite3_column_text(stmt, 3));
		rec->ixMsdcWAccess = sqlite3_column_int(stmt, 4);

		rst.nodes.push_back(rec);

		numread++;

		res = sqlite3_step(stmt);
	};

	return(numread);
};

bool LiteTblMsdcAMUsergroupAccess::loadRecByStmt(
			sqlite3_stmt* stmt
			, MsdcAMUsergroupAccess** rec
		) {
	bool retval = loadRec(stmt, rec);

	sqlite3_reset(stmt);

	return retval;
};

ubigint LiteTblMsdcAMUsergroupAccess::loadRstByStmt(
			sqlite3_stmt* stmt
			, const bool append
			, ListMsdcAMUsergroupAccess& rst
		) {
	ubigint retval = loadRst(stmt, append, rst);

	sqlite3_reset(stmt);

	return retval;
};

bool LiteTblMsdcAMUsergroupAccess::loadRecBySQL(
			const string& sqlstr
			, MsdcAMUsergroupAccess** rec
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

ubigint LiteTblMsdcAMUsergroupAccess::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListMsdcAMUsergroupAccess& rst
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

void LiteTblMsdcAMUsergroupAccess::insertRec(
			MsdcAMUsergroupAccess* rec
		) {
	sqlite3_bind_int64(stmtInsertRec, 1, rec->refMsdcMUsergroup);
	sqlite3_bind_int(stmtInsertRec, 2, rec->x1IxMsdcVFeatgroup);
	sqlite3_bind_text(stmtInsertRec, 3, rec->x2FeaSrefUix.c_str(), rec->x2FeaSrefUix.length(), SQLITE_STATIC);
	sqlite3_bind_int(stmtInsertRec, 4, rec->ixMsdcWAccess);

	if (sqlite3_step(stmtInsertRec) != SQLITE_DONE) throw DbsException("DbsException / SQLite: error executing statement! (TblMsdcAMUsergroupAccess / stmtInsertRec)\n");
	rec->ref = sqlite3_last_insert_rowid(dbs);

	sqlite3_reset(stmtInsertRec);
};

void LiteTblMsdcAMUsergroupAccess::insertRst(
			ListMsdcAMUsergroupAccess& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void LiteTblMsdcAMUsergroupAccess::updateRec(
			MsdcAMUsergroupAccess* rec
		) {
	sqlite3_bind_int64(stmtUpdateRec, 1, rec->refMsdcMUsergroup);
	sqlite3_bind_int(stmtUpdateRec, 2, rec->x1IxMsdcVFeatgroup);
	sqlite3_bind_text(stmtUpdateRec, 3, rec->x2FeaSrefUix.c_str(), rec->x2FeaSrefUix.length(), SQLITE_STATIC);
	sqlite3_bind_int(stmtUpdateRec, 4, rec->ixMsdcWAccess);
	sqlite3_bind_int64(stmtUpdateRec, 5, rec->ref);

	if (sqlite3_step(stmtUpdateRec) != SQLITE_DONE) throw DbsException("DbsException / SQLite: error executing statement! (TblMsdcAMUsergroupAccess / stmtUpdateRec)\n");

	sqlite3_reset(stmtUpdateRec);
};

void LiteTblMsdcAMUsergroupAccess::updateRst(
			ListMsdcAMUsergroupAccess& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void LiteTblMsdcAMUsergroupAccess::removeRecByRef(
			ubigint ref
		) {
	sqlite3_bind_int64(stmtRemoveRecByRef, 1, ref);

	if (sqlite3_step(stmtRemoveRecByRef) != SQLITE_DONE) throw DbsException("DbsException / SQLite: error executing statement! (TblMsdcAMUsergroupAccess / stmtRemoveRecByRef)\n");

	sqlite3_reset(stmtRemoveRecByRef);
};

bool LiteTblMsdcAMUsergroupAccess::loadRecByRef(
			ubigint ref
			, MsdcAMUsergroupAccess** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	sqlite3_bind_int64(stmtLoadRecByRef, 1, ref);

	return loadRecByStmt(stmtLoadRecByRef, rec);
};

ubigint LiteTblMsdcAMUsergroupAccess::loadRefsByUsg(
			ubigint refMsdcMUsergroup
			, const bool append
			, vector<ubigint>& refs
		) {
	sqlite3_bind_int64(stmtLoadRefsByUsg, 1, refMsdcMUsergroup);

	return loadRefsByStmt(stmtLoadRefsByUsg, append, refs);
};

ubigint LiteTblMsdcAMUsergroupAccess::loadRstByUsg(
			ubigint refMsdcMUsergroup
			, const bool append
			, ListMsdcAMUsergroupAccess& rst
		) {
	sqlite3_bind_int64(stmtLoadRstByUsg, 1, refMsdcMUsergroup);

	return loadRstByStmt(stmtLoadRstByUsg, append, rst);
};

