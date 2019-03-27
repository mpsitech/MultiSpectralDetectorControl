/**
  * \file MsdcMUsergroup.cpp
  * database access for table TblMsdcMUsergroup (implementation)
  * \author Alexander Wirthmueller
  * \date created: 18 Dec 2018
  * \date modified: 18 Dec 2018
  */

#include "MsdcMUsergroup.h"

/******************************************************************************
 class MsdcMUsergroup
 ******************************************************************************/

MsdcMUsergroup::MsdcMUsergroup(
			const ubigint ref
			, const ubigint grp
			, const ubigint own
			, const string sref
			, const string Comment
		) {

	this->ref = ref;
	this->grp = grp;
	this->own = own;
	this->sref = sref;
	this->Comment = Comment;
};

bool MsdcMUsergroup::operator==(
			const MsdcMUsergroup& comp
		) {
	return false;
};

bool MsdcMUsergroup::operator!=(
			const MsdcMUsergroup& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListMsdcMUsergroup
 ******************************************************************************/

ListMsdcMUsergroup::ListMsdcMUsergroup() {
};

ListMsdcMUsergroup::ListMsdcMUsergroup(
			const ListMsdcMUsergroup& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new MsdcMUsergroup(*(src.nodes[i]));
};

ListMsdcMUsergroup::~ListMsdcMUsergroup() {
	clear();
};

void ListMsdcMUsergroup::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListMsdcMUsergroup::size() const {
	return(nodes.size());
};

void ListMsdcMUsergroup::append(
			MsdcMUsergroup* rec
		) {
	nodes.push_back(rec);
};

MsdcMUsergroup* ListMsdcMUsergroup::operator[](
			const uint ix
		) {
	MsdcMUsergroup* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListMsdcMUsergroup& ListMsdcMUsergroup::operator=(
			const ListMsdcMUsergroup& src
		) {
	MsdcMUsergroup* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new MsdcMUsergroup(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListMsdcMUsergroup::operator==(
			const ListMsdcMUsergroup& comp
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

bool ListMsdcMUsergroup::operator!=(
			const ListMsdcMUsergroup& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblMsdcMUsergroup
 ******************************************************************************/

TblMsdcMUsergroup::TblMsdcMUsergroup() {
};

TblMsdcMUsergroup::~TblMsdcMUsergroup() {
};

bool TblMsdcMUsergroup::loadRecBySQL(
			const string& sqlstr
			, MsdcMUsergroup** rec
		) {
	return false;
};

ubigint TblMsdcMUsergroup::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListMsdcMUsergroup& rst
		) {
	return 0;
};

void TblMsdcMUsergroup::insertRec(
			MsdcMUsergroup* rec
		) {
};

ubigint TblMsdcMUsergroup::insertNewRec(
			MsdcMUsergroup** rec
			, const ubigint grp
			, const ubigint own
			, const string sref
			, const string Comment
		) {
	ubigint retval = 0;
	MsdcMUsergroup* _rec = NULL;

	_rec = new MsdcMUsergroup(0, grp, own, sref, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblMsdcMUsergroup::appendNewRecToRst(
			ListMsdcMUsergroup& rst
			, MsdcMUsergroup** rec
			, const ubigint grp
			, const ubigint own
			, const string sref
			, const string Comment
		) {
	ubigint retval = 0;
	MsdcMUsergroup* _rec = NULL;

	retval = insertNewRec(&_rec, grp, own, sref, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblMsdcMUsergroup::insertRst(
			ListMsdcMUsergroup& rst
			, bool transact
		) {
};

void TblMsdcMUsergroup::updateRec(
			MsdcMUsergroup* rec
		) {
};

void TblMsdcMUsergroup::updateRst(
			ListMsdcMUsergroup& rst
			, bool transact
		) {
};

void TblMsdcMUsergroup::removeRecByRef(
			ubigint ref
		) {
};

bool TblMsdcMUsergroup::loadRecByRef(
			ubigint ref
			, MsdcMUsergroup** rec
		) {
	return false;
};

bool TblMsdcMUsergroup::loadRecBySrf(
			string sref
			, MsdcMUsergroup** rec
		) {
	return false;
};

bool TblMsdcMUsergroup::loadRefBySrf(
			string sref
			, ubigint& ref
		) {
	return false;
};

bool TblMsdcMUsergroup::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return false;
};

ubigint TblMsdcMUsergroup::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListMsdcMUsergroup& rst
		) {
	ubigint numload = 0;
	MsdcMUsergroup* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

/******************************************************************************
 class LiteTblMsdcMUsergroup
 ******************************************************************************/

LiteTblMsdcMUsergroup::LiteTblMsdcMUsergroup() :
			TblMsdcMUsergroup()
			, LiteTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;

	stmtLoadRecBySrf = NULL;
	stmtLoadRefBySrf = NULL;
	stmtLoadSrfByRef = NULL;
};

LiteTblMsdcMUsergroup::~LiteTblMsdcMUsergroup() {
	if (stmtInsertRec) sqlite3_finalize(stmtInsertRec);
	if (stmtUpdateRec) sqlite3_finalize(stmtUpdateRec);
	if (stmtRemoveRecByRef) sqlite3_finalize(stmtRemoveRecByRef);

	if (stmtLoadRecBySrf) sqlite3_finalize(stmtLoadRecBySrf);
	if (stmtLoadRefBySrf) sqlite3_finalize(stmtLoadRefBySrf);
	if (stmtLoadSrfByRef) sqlite3_finalize(stmtLoadSrfByRef);
};

void LiteTblMsdcMUsergroup::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblMsdcMUsergroup (grp, own, sref, Comment) VALUES (?1,?2,?3,?4)");
	stmtUpdateRec = createStatement("UPDATE TblMsdcMUsergroup SET grp = ?1, own = ?2, sref = ?3, Comment = ?4 WHERE ref = ?5");
	stmtRemoveRecByRef = createStatement("DELETE FROM TblMsdcMUsergroup WHERE ref = ?1");

	stmtLoadRecByRef = createStatement("SELECT ref, grp, own, sref, Comment FROM TblMsdcMUsergroup WHERE ref = ?1");
	stmtLoadRecBySrf = createStatement("SELECT ref, grp, own, sref, Comment FROM TblMsdcMUsergroup WHERE sref = ?1");
	stmtLoadRefBySrf = createStatement("SELECT ref FROM TblMsdcMUsergroup WHERE sref = ?1");
	stmtLoadSrfByRef = createStatement("SELECT sref FROM TblMsdcMUsergroup WHERE ref = ?1");
};

bool LiteTblMsdcMUsergroup::loadRec(
			sqlite3_stmt* stmt
			, MsdcMUsergroup** rec
		) {
	int res;

	MsdcMUsergroup* _rec = NULL;
	bool retval = false;

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		_rec = new MsdcMUsergroup();

		_rec->ref = sqlite3_column_int64(stmt, 0);
		_rec->grp = sqlite3_column_int64(stmt, 1);
		_rec->own = sqlite3_column_int64(stmt, 2);
		_rec->sref.assign((const char*) sqlite3_column_text(stmt, 3));
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

ubigint LiteTblMsdcMUsergroup::loadRst(
			sqlite3_stmt* stmt
			, const bool append
			, ListMsdcMUsergroup& rst
		) {
	int res; ubigint numread = 0;

	MsdcMUsergroup* rec;

	if (!append) rst.clear();

	res = sqlite3_step(stmt);
	while (res == SQLITE_ROW) {
		rec = new MsdcMUsergroup();

		rec->ref = sqlite3_column_int64(stmt, 0);
		rec->grp = sqlite3_column_int64(stmt, 1);
		rec->own = sqlite3_column_int64(stmt, 2);
		rec->sref.assign((const char*) sqlite3_column_text(stmt, 3));
		rec->Comment.assign((const char*) sqlite3_column_text(stmt, 4));

		rst.nodes.push_back(rec);

		numread++;

		res = sqlite3_step(stmt);
	};

	return(numread);
};

bool LiteTblMsdcMUsergroup::loadRecByStmt(
			sqlite3_stmt* stmt
			, MsdcMUsergroup** rec
		) {
	bool retval = loadRec(stmt, rec);

	sqlite3_reset(stmt);

	return retval;
};

bool LiteTblMsdcMUsergroup::loadRecBySQL(
			const string& sqlstr
			, MsdcMUsergroup** rec
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

ubigint LiteTblMsdcMUsergroup::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListMsdcMUsergroup& rst
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

void LiteTblMsdcMUsergroup::insertRec(
			MsdcMUsergroup* rec
		) {
	sqlite3_bind_int64(stmtInsertRec, 1, rec->grp);
	sqlite3_bind_int64(stmtInsertRec, 2, rec->own);
	sqlite3_bind_text(stmtInsertRec, 3, rec->sref.c_str(), rec->sref.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtInsertRec, 4, rec->Comment.c_str(), rec->Comment.length(), SQLITE_STATIC);

	if (sqlite3_step(stmtInsertRec) != SQLITE_DONE) throw DbsException("DbsException / SQLite: error executing statement! (TblMsdcMUsergroup / stmtInsertRec)\n");
	rec->ref = sqlite3_last_insert_rowid(dbs);

	sqlite3_reset(stmtInsertRec);
};

void LiteTblMsdcMUsergroup::insertRst(
			ListMsdcMUsergroup& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void LiteTblMsdcMUsergroup::updateRec(
			MsdcMUsergroup* rec
		) {
	sqlite3_bind_int64(stmtUpdateRec, 1, rec->grp);
	sqlite3_bind_int64(stmtUpdateRec, 2, rec->own);
	sqlite3_bind_text(stmtUpdateRec, 3, rec->sref.c_str(), rec->sref.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtUpdateRec, 4, rec->Comment.c_str(), rec->Comment.length(), SQLITE_STATIC);
	sqlite3_bind_int64(stmtUpdateRec, 5, rec->ref);

	if (sqlite3_step(stmtUpdateRec) != SQLITE_DONE) throw DbsException("DbsException / SQLite: error executing statement! (TblMsdcMUsergroup / stmtUpdateRec)\n");

	sqlite3_reset(stmtUpdateRec);
};

void LiteTblMsdcMUsergroup::updateRst(
			ListMsdcMUsergroup& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void LiteTblMsdcMUsergroup::removeRecByRef(
			ubigint ref
		) {
	sqlite3_bind_int64(stmtRemoveRecByRef, 1, ref);

	if (sqlite3_step(stmtRemoveRecByRef) != SQLITE_DONE) throw DbsException("DbsException / SQLite: error executing statement! (TblMsdcMUsergroup / stmtRemoveRecByRef)\n");

	sqlite3_reset(stmtRemoveRecByRef);
};

bool LiteTblMsdcMUsergroup::loadRecByRef(
			ubigint ref
			, MsdcMUsergroup** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	sqlite3_bind_int64(stmtLoadRecByRef, 1, ref);

	return loadRecByStmt(stmtLoadRecByRef, rec);
};

bool LiteTblMsdcMUsergroup::loadRecBySrf(
			string sref
			, MsdcMUsergroup** rec
		) {
	sqlite3_bind_text(stmtLoadRecBySrf, 1, sref.c_str(), sref.length(), SQLITE_STATIC);

	return loadRecByStmt(stmtLoadRecBySrf, rec);
};

bool LiteTblMsdcMUsergroup::loadRefBySrf(
			string sref
			, ubigint& ref
		) {
	sqlite3_bind_text(stmtLoadRefBySrf, 1, sref.c_str(), sref.length(), SQLITE_STATIC);

	return loadRefByStmt(stmtLoadRefBySrf, ref);
};

bool LiteTblMsdcMUsergroup::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	sqlite3_bind_int64(stmtLoadSrfByRef, 1, ref);

	return loadStringByStmt(stmtLoadSrfByRef, sref);
};

