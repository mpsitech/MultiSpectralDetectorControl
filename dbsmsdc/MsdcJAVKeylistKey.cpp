/**
  * \file MsdcJAVKeylistKey.cpp
  * database access for table TblMsdcJAVKeylistKey (implementation)
  * \author Alexander Wirthmueller
  * \date created: 29 Aug 2018
  * \date modified: 29 Aug 2018
  */

#include "MsdcJAVKeylistKey.h"

/******************************************************************************
 class MsdcJAVKeylistKey
 ******************************************************************************/

MsdcJAVKeylistKey::MsdcJAVKeylistKey(
			const ubigint ref
			, const ubigint refMsdcAVKeylistKey
			, const uint x1IxMsdcVLocale
			, const string Title
			, const string Comment
		) {

	this->ref = ref;
	this->refMsdcAVKeylistKey = refMsdcAVKeylistKey;
	this->x1IxMsdcVLocale = x1IxMsdcVLocale;
	this->Title = Title;
	this->Comment = Comment;
};

bool MsdcJAVKeylistKey::operator==(
			const MsdcJAVKeylistKey& comp
		) {
	return false;
};

bool MsdcJAVKeylistKey::operator!=(
			const MsdcJAVKeylistKey& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListMsdcJAVKeylistKey
 ******************************************************************************/

ListMsdcJAVKeylistKey::ListMsdcJAVKeylistKey() {
};

ListMsdcJAVKeylistKey::ListMsdcJAVKeylistKey(
			const ListMsdcJAVKeylistKey& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new MsdcJAVKeylistKey(*(src.nodes[i]));
};

ListMsdcJAVKeylistKey::~ListMsdcJAVKeylistKey() {
	clear();
};

void ListMsdcJAVKeylistKey::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListMsdcJAVKeylistKey::size() const {
	return(nodes.size());
};

void ListMsdcJAVKeylistKey::append(
			MsdcJAVKeylistKey* rec
		) {
	nodes.push_back(rec);
};

MsdcJAVKeylistKey* ListMsdcJAVKeylistKey::operator[](
			const uint ix
		) {
	MsdcJAVKeylistKey* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListMsdcJAVKeylistKey& ListMsdcJAVKeylistKey::operator=(
			const ListMsdcJAVKeylistKey& src
		) {
	MsdcJAVKeylistKey* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new MsdcJAVKeylistKey(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListMsdcJAVKeylistKey::operator==(
			const ListMsdcJAVKeylistKey& comp
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

bool ListMsdcJAVKeylistKey::operator!=(
			const ListMsdcJAVKeylistKey& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblMsdcJAVKeylistKey
 ******************************************************************************/

TblMsdcJAVKeylistKey::TblMsdcJAVKeylistKey() {
};

TblMsdcJAVKeylistKey::~TblMsdcJAVKeylistKey() {
};

bool TblMsdcJAVKeylistKey::loadRecBySQL(
			const string& sqlstr
			, MsdcJAVKeylistKey** rec
		) {
	return false;
};

ubigint TblMsdcJAVKeylistKey::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListMsdcJAVKeylistKey& rst
		) {
	return 0;
};

void TblMsdcJAVKeylistKey::insertRec(
			MsdcJAVKeylistKey* rec
		) {
};

ubigint TblMsdcJAVKeylistKey::insertNewRec(
			MsdcJAVKeylistKey** rec
			, const ubigint refMsdcAVKeylistKey
			, const uint x1IxMsdcVLocale
			, const string Title
			, const string Comment
		) {
	ubigint retval = 0;
	MsdcJAVKeylistKey* _rec = NULL;

	_rec = new MsdcJAVKeylistKey(0, refMsdcAVKeylistKey, x1IxMsdcVLocale, Title, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblMsdcJAVKeylistKey::appendNewRecToRst(
			ListMsdcJAVKeylistKey& rst
			, MsdcJAVKeylistKey** rec
			, const ubigint refMsdcAVKeylistKey
			, const uint x1IxMsdcVLocale
			, const string Title
			, const string Comment
		) {
	ubigint retval = 0;
	MsdcJAVKeylistKey* _rec = NULL;

	retval = insertNewRec(&_rec, refMsdcAVKeylistKey, x1IxMsdcVLocale, Title, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblMsdcJAVKeylistKey::insertRst(
			ListMsdcJAVKeylistKey& rst
			, bool transact
		) {
};

void TblMsdcJAVKeylistKey::updateRec(
			MsdcJAVKeylistKey* rec
		) {
};

void TblMsdcJAVKeylistKey::updateRst(
			ListMsdcJAVKeylistKey& rst
			, bool transact
		) {
};

void TblMsdcJAVKeylistKey::removeRecByRef(
			ubigint ref
		) {
};

bool TblMsdcJAVKeylistKey::loadRecByRef(
			ubigint ref
			, MsdcJAVKeylistKey** rec
		) {
	return false;
};

bool TblMsdcJAVKeylistKey::loadRecByKlkLcl(
			ubigint refMsdcAVKeylistKey
			, uint x1IxMsdcVLocale
			, MsdcJAVKeylistKey** rec
		) {
	return false;
};

ubigint TblMsdcJAVKeylistKey::loadRefsByKlk(
			ubigint refMsdcAVKeylistKey
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblMsdcJAVKeylistKey::loadRstByKlk(
			ubigint refMsdcAVKeylistKey
			, const bool append
			, ListMsdcJAVKeylistKey& rst
		) {
	return 0;
};

bool TblMsdcJAVKeylistKey::loadTitByKlkLcl(
			ubigint refMsdcAVKeylistKey
			, uint x1IxMsdcVLocale
			, string& Title
		) {
	return false;
};

ubigint TblMsdcJAVKeylistKey::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListMsdcJAVKeylistKey& rst
		) {
	ubigint numload = 0;
	MsdcJAVKeylistKey* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

/******************************************************************************
 class LiteTblMsdcJAVKeylistKey
 ******************************************************************************/

LiteTblMsdcJAVKeylistKey::LiteTblMsdcJAVKeylistKey() :
			TblMsdcJAVKeylistKey()
			, LiteTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;

	stmtLoadRecByKlkLcl = NULL;
	stmtLoadRefsByKlk = NULL;
	stmtLoadRstByKlk = NULL;
	stmtLoadTitByKlkLcl = NULL;
};

LiteTblMsdcJAVKeylistKey::~LiteTblMsdcJAVKeylistKey() {
	if (stmtInsertRec) sqlite3_finalize(stmtInsertRec);
	if (stmtUpdateRec) sqlite3_finalize(stmtUpdateRec);
	if (stmtRemoveRecByRef) sqlite3_finalize(stmtRemoveRecByRef);

	if (stmtLoadRecByKlkLcl) sqlite3_finalize(stmtLoadRecByKlkLcl);
	if (stmtLoadRefsByKlk) sqlite3_finalize(stmtLoadRefsByKlk);
	if (stmtLoadRstByKlk) sqlite3_finalize(stmtLoadRstByKlk);
	if (stmtLoadTitByKlkLcl) sqlite3_finalize(stmtLoadTitByKlkLcl);
};

void LiteTblMsdcJAVKeylistKey::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblMsdcJAVKeylistKey (refMsdcAVKeylistKey, x1IxMsdcVLocale, Title, Comment) VALUES (?1,?2,?3,?4)");
	stmtUpdateRec = createStatement("UPDATE TblMsdcJAVKeylistKey SET refMsdcAVKeylistKey = ?1, x1IxMsdcVLocale = ?2, Title = ?3, Comment = ?4 WHERE ref = ?5");
	stmtRemoveRecByRef = createStatement("DELETE FROM TblMsdcJAVKeylistKey WHERE ref = ?1");

	stmtLoadRecByRef = createStatement("SELECT ref, refMsdcAVKeylistKey, x1IxMsdcVLocale, Title, Comment FROM TblMsdcJAVKeylistKey WHERE ref = ?1");
	stmtLoadRecByKlkLcl = createStatement("SELECT ref, refMsdcAVKeylistKey, x1IxMsdcVLocale, Title, Comment FROM TblMsdcJAVKeylistKey WHERE refMsdcAVKeylistKey = ?1 AND x1IxMsdcVLocale = ?2");
	stmtLoadRefsByKlk = createStatement("SELECT ref FROM TblMsdcJAVKeylistKey WHERE refMsdcAVKeylistKey = ?1");
	stmtLoadRstByKlk = createStatement("SELECT ref, refMsdcAVKeylistKey, x1IxMsdcVLocale, Title, Comment FROM TblMsdcJAVKeylistKey WHERE refMsdcAVKeylistKey = ?1 ORDER BY x1IxMsdcVLocale ASC");
	stmtLoadTitByKlkLcl = createStatement("SELECT Title FROM TblMsdcJAVKeylistKey WHERE refMsdcAVKeylistKey = ?1 AND x1IxMsdcVLocale = ?2");
};

bool LiteTblMsdcJAVKeylistKey::loadRec(
			sqlite3_stmt* stmt
			, MsdcJAVKeylistKey** rec
		) {
	int res;

	MsdcJAVKeylistKey* _rec = NULL;
	bool retval = false;

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		_rec = new MsdcJAVKeylistKey();

		_rec->ref = sqlite3_column_int64(stmt, 0);
		_rec->refMsdcAVKeylistKey = sqlite3_column_int64(stmt, 1);
		_rec->x1IxMsdcVLocale = sqlite3_column_int(stmt, 2);
		_rec->Title.assign((const char*) sqlite3_column_text(stmt, 3));
		_rec->Comment.assign((const char*) sqlite3_column_text(stmt, 4));

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

ubigint LiteTblMsdcJAVKeylistKey::loadRst(
			sqlite3_stmt* stmt
			, const bool append
			, ListMsdcJAVKeylistKey& rst
		) {
	int res; ubigint numread = 0;

	MsdcJAVKeylistKey* rec;

	if (!append) rst.clear();

	res = sqlite3_step(stmt);
	while (res == SQLITE_ROW) {
		rec = new MsdcJAVKeylistKey();

		rec->ref = sqlite3_column_int64(stmt, 0);
		rec->refMsdcAVKeylistKey = sqlite3_column_int64(stmt, 1);
		rec->x1IxMsdcVLocale = sqlite3_column_int(stmt, 2);
		rec->Title.assign((const char*) sqlite3_column_text(stmt, 3));
		rec->Comment.assign((const char*) sqlite3_column_text(stmt, 4));

		rst.nodes.push_back(rec);

		numread++;

		res = sqlite3_step(stmt);
	};

	return(numread);
};

bool LiteTblMsdcJAVKeylistKey::loadRecByStmt(
			sqlite3_stmt* stmt
			, MsdcJAVKeylistKey** rec
		) {
	bool retval = loadRec(stmt, rec);

	sqlite3_reset(stmt);

	return retval;
};

ubigint LiteTblMsdcJAVKeylistKey::loadRstByStmt(
			sqlite3_stmt* stmt
			, const bool append
			, ListMsdcJAVKeylistKey& rst
		) {
	ubigint retval = loadRst(stmt, append, rst);

	sqlite3_reset(stmt);

	return retval;
};

bool LiteTblMsdcJAVKeylistKey::loadRecBySQL(
			const string& sqlstr
			, MsdcJAVKeylistKey** rec
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

ubigint LiteTblMsdcJAVKeylistKey::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListMsdcJAVKeylistKey& rst
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

void LiteTblMsdcJAVKeylistKey::insertRec(
			MsdcJAVKeylistKey* rec
		) {
	sqlite3_bind_int64(stmtInsertRec, 1, rec->refMsdcAVKeylistKey);
	sqlite3_bind_int(stmtInsertRec, 2, rec->x1IxMsdcVLocale);
	sqlite3_bind_text(stmtInsertRec, 3, rec->Title.c_str(), rec->Title.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtInsertRec, 4, rec->Comment.c_str(), rec->Comment.length(), SQLITE_STATIC);

	if (sqlite3_step(stmtInsertRec) != SQLITE_DONE) throw DbsException("DbsException / SQLite: error executing statement! (TblMsdcJAVKeylistKey / stmtInsertRec)\n");
	rec->ref = sqlite3_last_insert_rowid(dbs);

	sqlite3_reset(stmtInsertRec);
};

void LiteTblMsdcJAVKeylistKey::insertRst(
			ListMsdcJAVKeylistKey& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void LiteTblMsdcJAVKeylistKey::updateRec(
			MsdcJAVKeylistKey* rec
		) {
	sqlite3_bind_int64(stmtUpdateRec, 1, rec->refMsdcAVKeylistKey);
	sqlite3_bind_int(stmtUpdateRec, 2, rec->x1IxMsdcVLocale);
	sqlite3_bind_text(stmtUpdateRec, 3, rec->Title.c_str(), rec->Title.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtUpdateRec, 4, rec->Comment.c_str(), rec->Comment.length(), SQLITE_STATIC);
	sqlite3_bind_int64(stmtUpdateRec, 5, rec->ref);

	if (sqlite3_step(stmtUpdateRec) != SQLITE_DONE) throw DbsException("DbsException / SQLite: error executing statement! (TblMsdcJAVKeylistKey / stmtUpdateRec)\n");

	sqlite3_reset(stmtUpdateRec);
};

void LiteTblMsdcJAVKeylistKey::updateRst(
			ListMsdcJAVKeylistKey& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void LiteTblMsdcJAVKeylistKey::removeRecByRef(
			ubigint ref
		) {
	sqlite3_bind_int64(stmtRemoveRecByRef, 1, ref);

	if (sqlite3_step(stmtRemoveRecByRef) != SQLITE_DONE) throw DbsException("DbsException / SQLite: error executing statement! (TblMsdcJAVKeylistKey / stmtRemoveRecByRef)\n");

	sqlite3_reset(stmtRemoveRecByRef);
};

bool LiteTblMsdcJAVKeylistKey::loadRecByRef(
			ubigint ref
			, MsdcJAVKeylistKey** rec
		) {
	sqlite3_bind_int64(stmtLoadRecByRef, 1, ref);

	return loadRecByStmt(stmtLoadRecByRef, rec);
};

bool LiteTblMsdcJAVKeylistKey::loadRecByKlkLcl(
			ubigint refMsdcAVKeylistKey
			, uint x1IxMsdcVLocale
			, MsdcJAVKeylistKey** rec
		) {
	sqlite3_bind_int64(stmtLoadRecByKlkLcl, 1, refMsdcAVKeylistKey);
	sqlite3_bind_int(stmtLoadRecByKlkLcl, 2, x1IxMsdcVLocale);

	return loadRecByStmt(stmtLoadRecByKlkLcl, rec);
};

ubigint LiteTblMsdcJAVKeylistKey::loadRefsByKlk(
			ubigint refMsdcAVKeylistKey
			, const bool append
			, vector<ubigint>& refs
		) {
	sqlite3_bind_int64(stmtLoadRefsByKlk, 1, refMsdcAVKeylistKey);

	return loadRefsByStmt(stmtLoadRefsByKlk, append, refs);
};

ubigint LiteTblMsdcJAVKeylistKey::loadRstByKlk(
			ubigint refMsdcAVKeylistKey
			, const bool append
			, ListMsdcJAVKeylistKey& rst
		) {
	sqlite3_bind_int64(stmtLoadRstByKlk, 1, refMsdcAVKeylistKey);

	return loadRstByStmt(stmtLoadRstByKlk, append, rst);
};

bool LiteTblMsdcJAVKeylistKey::loadTitByKlkLcl(
			ubigint refMsdcAVKeylistKey
			, uint x1IxMsdcVLocale
			, string& Title
		) {
	sqlite3_bind_int64(stmtLoadTitByKlkLcl, 1, refMsdcAVKeylistKey);
	sqlite3_bind_int(stmtLoadTitByKlkLcl, 2, x1IxMsdcVLocale);

	return loadStringByStmt(stmtLoadTitByKlkLcl, Title);
};

