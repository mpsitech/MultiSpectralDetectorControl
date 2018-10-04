/**
  * \file MsdcMPeriod.cpp
  * database access for table TblMsdcMPeriod (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Oct 2018
  * \date modified: 4 Oct 2018
  */

#include "MsdcMPeriod.h"

/******************************************************************************
 class MsdcMPeriod
 ******************************************************************************/

MsdcMPeriod::MsdcMPeriod(
			const ubigint ref
			, const uint start
			, const uint stop
		) {

	this->ref = ref;
	this->start = start;
	this->stop = stop;
};

bool MsdcMPeriod::operator==(
			const MsdcMPeriod& comp
		) {
	return false;
};

bool MsdcMPeriod::operator!=(
			const MsdcMPeriod& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListMsdcMPeriod
 ******************************************************************************/

ListMsdcMPeriod::ListMsdcMPeriod() {
};

ListMsdcMPeriod::ListMsdcMPeriod(
			const ListMsdcMPeriod& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new MsdcMPeriod(*(src.nodes[i]));
};

ListMsdcMPeriod::~ListMsdcMPeriod() {
	clear();
};

void ListMsdcMPeriod::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListMsdcMPeriod::size() const {
	return(nodes.size());
};

void ListMsdcMPeriod::append(
			MsdcMPeriod* rec
		) {
	nodes.push_back(rec);
};

MsdcMPeriod* ListMsdcMPeriod::operator[](
			const uint ix
		) {
	MsdcMPeriod* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListMsdcMPeriod& ListMsdcMPeriod::operator=(
			const ListMsdcMPeriod& src
		) {
	MsdcMPeriod* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new MsdcMPeriod(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListMsdcMPeriod::operator==(
			const ListMsdcMPeriod& comp
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

bool ListMsdcMPeriod::operator!=(
			const ListMsdcMPeriod& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblMsdcMPeriod
 ******************************************************************************/

TblMsdcMPeriod::TblMsdcMPeriod() {
};

TblMsdcMPeriod::~TblMsdcMPeriod() {
};

bool TblMsdcMPeriod::loadRecBySQL(
			const string& sqlstr
			, MsdcMPeriod** rec
		) {
	return false;
};

ubigint TblMsdcMPeriod::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListMsdcMPeriod& rst
		) {
	return 0;
};

void TblMsdcMPeriod::insertRec(
			MsdcMPeriod* rec
		) {
};

ubigint TblMsdcMPeriod::insertNewRec(
			MsdcMPeriod** rec
			, const uint start
			, const uint stop
		) {
	ubigint retval = 0;
	MsdcMPeriod* _rec = NULL;

	_rec = new MsdcMPeriod(0, start, stop);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblMsdcMPeriod::appendNewRecToRst(
			ListMsdcMPeriod& rst
			, MsdcMPeriod** rec
			, const uint start
			, const uint stop
		) {
	ubigint retval = 0;
	MsdcMPeriod* _rec = NULL;

	retval = insertNewRec(&_rec, start, stop);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblMsdcMPeriod::insertRst(
			ListMsdcMPeriod& rst
			, bool transact
		) {
};

void TblMsdcMPeriod::updateRec(
			MsdcMPeriod* rec
		) {
};

void TblMsdcMPeriod::updateRst(
			ListMsdcMPeriod& rst
			, bool transact
		) {
};

void TblMsdcMPeriod::removeRecByRef(
			ubigint ref
		) {
};

bool TblMsdcMPeriod::loadRecByRef(
			ubigint ref
			, MsdcMPeriod** rec
		) {
	return false;
};

ubigint TblMsdcMPeriod::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListMsdcMPeriod& rst
		) {
	ubigint numload = 0;
	MsdcMPeriod* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

/******************************************************************************
 class LiteTblMsdcMPeriod
 ******************************************************************************/

LiteTblMsdcMPeriod::LiteTblMsdcMPeriod() :
			TblMsdcMPeriod()
			, LiteTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;

};

LiteTblMsdcMPeriod::~LiteTblMsdcMPeriod() {
	if (stmtInsertRec) sqlite3_finalize(stmtInsertRec);
	if (stmtUpdateRec) sqlite3_finalize(stmtUpdateRec);
	if (stmtRemoveRecByRef) sqlite3_finalize(stmtRemoveRecByRef);

};

void LiteTblMsdcMPeriod::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblMsdcMPeriod (start, stop) VALUES (?1,?2)");
	stmtUpdateRec = createStatement("UPDATE TblMsdcMPeriod SET start = ?1, stop = ?2 WHERE ref = ?3");
	stmtRemoveRecByRef = createStatement("DELETE FROM TblMsdcMPeriod WHERE ref = ?1");

	stmtLoadRecByRef = createStatement("SELECT ref, start, stop FROM TblMsdcMPeriod WHERE ref = ?1");
};

bool LiteTblMsdcMPeriod::loadRec(
			sqlite3_stmt* stmt
			, MsdcMPeriod** rec
		) {
	int res;

	MsdcMPeriod* _rec = NULL;
	bool retval = false;

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		_rec = new MsdcMPeriod();

		_rec->ref = sqlite3_column_int64(stmt, 0);
		_rec->start = sqlite3_column_int(stmt, 1);
		_rec->stop = sqlite3_column_int(stmt, 2);

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

ubigint LiteTblMsdcMPeriod::loadRst(
			sqlite3_stmt* stmt
			, const bool append
			, ListMsdcMPeriod& rst
		) {
	int res; ubigint numread = 0;

	MsdcMPeriod* rec;

	if (!append) rst.clear();

	res = sqlite3_step(stmt);
	while (res == SQLITE_ROW) {
		rec = new MsdcMPeriod();

		rec->ref = sqlite3_column_int64(stmt, 0);
		rec->start = sqlite3_column_int(stmt, 1);
		rec->stop = sqlite3_column_int(stmt, 2);

		rst.nodes.push_back(rec);

		numread++;

		res = sqlite3_step(stmt);
	};

	return(numread);
};

bool LiteTblMsdcMPeriod::loadRecByStmt(
			sqlite3_stmt* stmt
			, MsdcMPeriod** rec
		) {
	bool retval = loadRec(stmt, rec);

	sqlite3_reset(stmt);

	return retval;
};

bool LiteTblMsdcMPeriod::loadRecBySQL(
			const string& sqlstr
			, MsdcMPeriod** rec
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

ubigint LiteTblMsdcMPeriod::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListMsdcMPeriod& rst
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

void LiteTblMsdcMPeriod::insertRec(
			MsdcMPeriod* rec
		) {
	sqlite3_bind_int(stmtInsertRec, 1, rec->start);
	sqlite3_bind_int(stmtInsertRec, 2, rec->stop);

	if (sqlite3_step(stmtInsertRec) != SQLITE_DONE) throw DbsException("DbsException / SQLite: error executing statement! (TblMsdcMPeriod / stmtInsertRec)\n");
	rec->ref = sqlite3_last_insert_rowid(dbs);

	sqlite3_reset(stmtInsertRec);
};

void LiteTblMsdcMPeriod::insertRst(
			ListMsdcMPeriod& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void LiteTblMsdcMPeriod::updateRec(
			MsdcMPeriod* rec
		) {
	sqlite3_bind_int(stmtUpdateRec, 1, rec->start);
	sqlite3_bind_int(stmtUpdateRec, 2, rec->stop);
	sqlite3_bind_int64(stmtUpdateRec, 3, rec->ref);

	if (sqlite3_step(stmtUpdateRec) != SQLITE_DONE) throw DbsException("DbsException / SQLite: error executing statement! (TblMsdcMPeriod / stmtUpdateRec)\n");

	sqlite3_reset(stmtUpdateRec);
};

void LiteTblMsdcMPeriod::updateRst(
			ListMsdcMPeriod& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void LiteTblMsdcMPeriod::removeRecByRef(
			ubigint ref
		) {
	sqlite3_bind_int64(stmtRemoveRecByRef, 1, ref);

	if (sqlite3_step(stmtRemoveRecByRef) != SQLITE_DONE) throw DbsException("DbsException / SQLite: error executing statement! (TblMsdcMPeriod / stmtRemoveRecByRef)\n");

	sqlite3_reset(stmtRemoveRecByRef);
};

bool LiteTblMsdcMPeriod::loadRecByRef(
			ubigint ref
			, MsdcMPeriod** rec
		) {
	if (ref == 0) return false;

	sqlite3_bind_int64(stmtLoadRecByRef, 1, ref);

	return loadRecByStmt(stmtLoadRecByRef, rec);
};

