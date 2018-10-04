/**
  * \file MsdcAMPersonDetail.cpp
  * database access for table TblMsdcAMPersonDetail (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Oct 2018
  * \date modified: 4 Oct 2018
  */

#include "MsdcAMPersonDetail.h"

/******************************************************************************
 class MsdcAMPersonDetail
 ******************************************************************************/

MsdcAMPersonDetail::MsdcAMPersonDetail(
			const ubigint ref
			, const ubigint refMsdcMPerson
			, const string x1SrefKType
			, const string Val
		) {

	this->ref = ref;
	this->refMsdcMPerson = refMsdcMPerson;
	this->x1SrefKType = x1SrefKType;
	this->Val = Val;
};

bool MsdcAMPersonDetail::operator==(
			const MsdcAMPersonDetail& comp
		) {
	return false;
};

bool MsdcAMPersonDetail::operator!=(
			const MsdcAMPersonDetail& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListMsdcAMPersonDetail
 ******************************************************************************/

ListMsdcAMPersonDetail::ListMsdcAMPersonDetail() {
};

ListMsdcAMPersonDetail::ListMsdcAMPersonDetail(
			const ListMsdcAMPersonDetail& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new MsdcAMPersonDetail(*(src.nodes[i]));
};

ListMsdcAMPersonDetail::~ListMsdcAMPersonDetail() {
	clear();
};

void ListMsdcAMPersonDetail::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListMsdcAMPersonDetail::size() const {
	return(nodes.size());
};

void ListMsdcAMPersonDetail::append(
			MsdcAMPersonDetail* rec
		) {
	nodes.push_back(rec);
};

MsdcAMPersonDetail* ListMsdcAMPersonDetail::operator[](
			const uint ix
		) {
	MsdcAMPersonDetail* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListMsdcAMPersonDetail& ListMsdcAMPersonDetail::operator=(
			const ListMsdcAMPersonDetail& src
		) {
	MsdcAMPersonDetail* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new MsdcAMPersonDetail(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListMsdcAMPersonDetail::operator==(
			const ListMsdcAMPersonDetail& comp
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

bool ListMsdcAMPersonDetail::operator!=(
			const ListMsdcAMPersonDetail& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblMsdcAMPersonDetail
 ******************************************************************************/

TblMsdcAMPersonDetail::TblMsdcAMPersonDetail() {
};

TblMsdcAMPersonDetail::~TblMsdcAMPersonDetail() {
};

bool TblMsdcAMPersonDetail::loadRecBySQL(
			const string& sqlstr
			, MsdcAMPersonDetail** rec
		) {
	return false;
};

ubigint TblMsdcAMPersonDetail::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListMsdcAMPersonDetail& rst
		) {
	return 0;
};

void TblMsdcAMPersonDetail::insertRec(
			MsdcAMPersonDetail* rec
		) {
};

ubigint TblMsdcAMPersonDetail::insertNewRec(
			MsdcAMPersonDetail** rec
			, const ubigint refMsdcMPerson
			, const string x1SrefKType
			, const string Val
		) {
	ubigint retval = 0;
	MsdcAMPersonDetail* _rec = NULL;

	_rec = new MsdcAMPersonDetail(0, refMsdcMPerson, x1SrefKType, Val);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblMsdcAMPersonDetail::appendNewRecToRst(
			ListMsdcAMPersonDetail& rst
			, MsdcAMPersonDetail** rec
			, const ubigint refMsdcMPerson
			, const string x1SrefKType
			, const string Val
		) {
	ubigint retval = 0;
	MsdcAMPersonDetail* _rec = NULL;

	retval = insertNewRec(&_rec, refMsdcMPerson, x1SrefKType, Val);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblMsdcAMPersonDetail::insertRst(
			ListMsdcAMPersonDetail& rst
			, bool transact
		) {
};

void TblMsdcAMPersonDetail::updateRec(
			MsdcAMPersonDetail* rec
		) {
};

void TblMsdcAMPersonDetail::updateRst(
			ListMsdcAMPersonDetail& rst
			, bool transact
		) {
};

void TblMsdcAMPersonDetail::removeRecByRef(
			ubigint ref
		) {
};

bool TblMsdcAMPersonDetail::loadRecByRef(
			ubigint ref
			, MsdcAMPersonDetail** rec
		) {
	return false;
};

bool TblMsdcAMPersonDetail::loadRecByPrsTyp(
			ubigint refMsdcMPerson
			, string x1SrefKType
			, MsdcAMPersonDetail** rec
		) {
	return false;
};

ubigint TblMsdcAMPersonDetail::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListMsdcAMPersonDetail& rst
		) {
	ubigint numload = 0;
	MsdcAMPersonDetail* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

/******************************************************************************
 class LiteTblMsdcAMPersonDetail
 ******************************************************************************/

LiteTblMsdcAMPersonDetail::LiteTblMsdcAMPersonDetail() :
			TblMsdcAMPersonDetail()
			, LiteTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;

	stmtLoadRecByPrsTyp = NULL;
};

LiteTblMsdcAMPersonDetail::~LiteTblMsdcAMPersonDetail() {
	if (stmtInsertRec) sqlite3_finalize(stmtInsertRec);
	if (stmtUpdateRec) sqlite3_finalize(stmtUpdateRec);
	if (stmtRemoveRecByRef) sqlite3_finalize(stmtRemoveRecByRef);

	if (stmtLoadRecByPrsTyp) sqlite3_finalize(stmtLoadRecByPrsTyp);
};

void LiteTblMsdcAMPersonDetail::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblMsdcAMPersonDetail (refMsdcMPerson, x1SrefKType, Val) VALUES (?1,?2,?3)");
	stmtUpdateRec = createStatement("UPDATE TblMsdcAMPersonDetail SET refMsdcMPerson = ?1, x1SrefKType = ?2, Val = ?3 WHERE ref = ?4");
	stmtRemoveRecByRef = createStatement("DELETE FROM TblMsdcAMPersonDetail WHERE ref = ?1");

	stmtLoadRecByRef = createStatement("SELECT ref, refMsdcMPerson, x1SrefKType, Val FROM TblMsdcAMPersonDetail WHERE ref = ?1");
	stmtLoadRecByPrsTyp = createStatement("SELECT ref, refMsdcMPerson, x1SrefKType, Val FROM TblMsdcAMPersonDetail WHERE refMsdcMPerson = ?1 AND x1SrefKType = ?2");
};

bool LiteTblMsdcAMPersonDetail::loadRec(
			sqlite3_stmt* stmt
			, MsdcAMPersonDetail** rec
		) {
	int res;

	MsdcAMPersonDetail* _rec = NULL;
	bool retval = false;

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		_rec = new MsdcAMPersonDetail();

		_rec->ref = sqlite3_column_int64(stmt, 0);
		_rec->refMsdcMPerson = sqlite3_column_int64(stmt, 1);
		_rec->x1SrefKType.assign((const char*) sqlite3_column_text(stmt, 2));
		_rec->Val.assign((const char*) sqlite3_column_text(stmt, 3));

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

ubigint LiteTblMsdcAMPersonDetail::loadRst(
			sqlite3_stmt* stmt
			, const bool append
			, ListMsdcAMPersonDetail& rst
		) {
	int res; ubigint numread = 0;

	MsdcAMPersonDetail* rec;

	if (!append) rst.clear();

	res = sqlite3_step(stmt);
	while (res == SQLITE_ROW) {
		rec = new MsdcAMPersonDetail();

		rec->ref = sqlite3_column_int64(stmt, 0);
		rec->refMsdcMPerson = sqlite3_column_int64(stmt, 1);
		rec->x1SrefKType.assign((const char*) sqlite3_column_text(stmt, 2));
		rec->Val.assign((const char*) sqlite3_column_text(stmt, 3));

		rst.nodes.push_back(rec);

		numread++;

		res = sqlite3_step(stmt);
	};

	return(numread);
};

bool LiteTblMsdcAMPersonDetail::loadRecByStmt(
			sqlite3_stmt* stmt
			, MsdcAMPersonDetail** rec
		) {
	bool retval = loadRec(stmt, rec);

	sqlite3_reset(stmt);

	return retval;
};

bool LiteTblMsdcAMPersonDetail::loadRecBySQL(
			const string& sqlstr
			, MsdcAMPersonDetail** rec
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

ubigint LiteTblMsdcAMPersonDetail::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListMsdcAMPersonDetail& rst
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

void LiteTblMsdcAMPersonDetail::insertRec(
			MsdcAMPersonDetail* rec
		) {
	sqlite3_bind_int64(stmtInsertRec, 1, rec->refMsdcMPerson);
	sqlite3_bind_text(stmtInsertRec, 2, rec->x1SrefKType.c_str(), rec->x1SrefKType.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtInsertRec, 3, rec->Val.c_str(), rec->Val.length(), SQLITE_STATIC);

	if (sqlite3_step(stmtInsertRec) != SQLITE_DONE) throw DbsException("DbsException / SQLite: error executing statement! (TblMsdcAMPersonDetail / stmtInsertRec)\n");
	rec->ref = sqlite3_last_insert_rowid(dbs);

	sqlite3_reset(stmtInsertRec);
};

void LiteTblMsdcAMPersonDetail::insertRst(
			ListMsdcAMPersonDetail& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void LiteTblMsdcAMPersonDetail::updateRec(
			MsdcAMPersonDetail* rec
		) {
	sqlite3_bind_int64(stmtUpdateRec, 1, rec->refMsdcMPerson);
	sqlite3_bind_text(stmtUpdateRec, 2, rec->x1SrefKType.c_str(), rec->x1SrefKType.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtUpdateRec, 3, rec->Val.c_str(), rec->Val.length(), SQLITE_STATIC);
	sqlite3_bind_int64(stmtUpdateRec, 4, rec->ref);

	if (sqlite3_step(stmtUpdateRec) != SQLITE_DONE) throw DbsException("DbsException / SQLite: error executing statement! (TblMsdcAMPersonDetail / stmtUpdateRec)\n");

	sqlite3_reset(stmtUpdateRec);
};

void LiteTblMsdcAMPersonDetail::updateRst(
			ListMsdcAMPersonDetail& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void LiteTblMsdcAMPersonDetail::removeRecByRef(
			ubigint ref
		) {
	sqlite3_bind_int64(stmtRemoveRecByRef, 1, ref);

	if (sqlite3_step(stmtRemoveRecByRef) != SQLITE_DONE) throw DbsException("DbsException / SQLite: error executing statement! (TblMsdcAMPersonDetail / stmtRemoveRecByRef)\n");

	sqlite3_reset(stmtRemoveRecByRef);
};

bool LiteTblMsdcAMPersonDetail::loadRecByRef(
			ubigint ref
			, MsdcAMPersonDetail** rec
		) {
	if (ref == 0) return false;

	sqlite3_bind_int64(stmtLoadRecByRef, 1, ref);

	return loadRecByStmt(stmtLoadRecByRef, rec);
};

bool LiteTblMsdcAMPersonDetail::loadRecByPrsTyp(
			ubigint refMsdcMPerson
			, string x1SrefKType
			, MsdcAMPersonDetail** rec
		) {
	sqlite3_bind_int64(stmtLoadRecByPrsTyp, 1, refMsdcMPerson);
	sqlite3_bind_text(stmtLoadRecByPrsTyp, 2, x1SrefKType.c_str(), x1SrefKType.length(), SQLITE_STATIC);

	return loadRecByStmt(stmtLoadRecByPrsTyp, rec);
};

