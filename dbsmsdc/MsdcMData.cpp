/**
  * \file MsdcMData.cpp
  * database access for table TblMsdcMData (implementation)
  * \author Alexander Wirthmueller
  * \date created: 15 Aug 2018
  * \date modified: 15 Aug 2018
  */

#include "MsdcMData.h"

/******************************************************************************
 class MsdcMData
 ******************************************************************************/

MsdcMData::MsdcMData(
			const ubigint ref
			, const ubigint refMsdcMPeriod
			, const uint start
			, const uint stop
			, const string srefMsdcKAcqfeat
			, const string Comment
		) {

	this->ref = ref;
	this->refMsdcMPeriod = refMsdcMPeriod;
	this->start = start;
	this->stop = stop;
	this->srefMsdcKAcqfeat = srefMsdcKAcqfeat;
	this->Comment = Comment;
};

bool MsdcMData::operator==(
			const MsdcMData& comp
		) {
	return false;
};

bool MsdcMData::operator!=(
			const MsdcMData& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListMsdcMData
 ******************************************************************************/

ListMsdcMData::ListMsdcMData() {
};

ListMsdcMData::ListMsdcMData(
			const ListMsdcMData& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new MsdcMData(*(src.nodes[i]));
};

ListMsdcMData::~ListMsdcMData() {
	clear();
};

void ListMsdcMData::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListMsdcMData::size() const {
	return(nodes.size());
};

void ListMsdcMData::append(
			MsdcMData* rec
		) {
	nodes.push_back(rec);
};

MsdcMData* ListMsdcMData::operator[](
			const uint ix
		) {
	MsdcMData* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListMsdcMData& ListMsdcMData::operator=(
			const ListMsdcMData& src
		) {
	MsdcMData* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new MsdcMData(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListMsdcMData::operator==(
			const ListMsdcMData& comp
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

bool ListMsdcMData::operator!=(
			const ListMsdcMData& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblMsdcMData
 ******************************************************************************/

TblMsdcMData::TblMsdcMData() {
};

TblMsdcMData::~TblMsdcMData() {
};

bool TblMsdcMData::loadRecBySQL(
			const string& sqlstr
			, MsdcMData** rec
		) {
	return false;
};

ubigint TblMsdcMData::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListMsdcMData& rst
		) {
	return 0;
};

void TblMsdcMData::insertRec(
			MsdcMData* rec
		) {
};

ubigint TblMsdcMData::insertNewRec(
			MsdcMData** rec
			, const ubigint refMsdcMPeriod
			, const uint start
			, const uint stop
			, const string srefMsdcKAcqfeat
			, const string Comment
		) {
	ubigint retval = 0;
	MsdcMData* _rec = NULL;

	_rec = new MsdcMData(0, refMsdcMPeriod, start, stop, srefMsdcKAcqfeat, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblMsdcMData::appendNewRecToRst(
			ListMsdcMData& rst
			, MsdcMData** rec
			, const ubigint refMsdcMPeriod
			, const uint start
			, const uint stop
			, const string srefMsdcKAcqfeat
			, const string Comment
		) {
	ubigint retval = 0;
	MsdcMData* _rec = NULL;

	retval = insertNewRec(&_rec, refMsdcMPeriod, start, stop, srefMsdcKAcqfeat, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblMsdcMData::insertRst(
			ListMsdcMData& rst
			, bool transact
		) {
};

void TblMsdcMData::updateRec(
			MsdcMData* rec
		) {
};

void TblMsdcMData::updateRst(
			ListMsdcMData& rst
			, bool transact
		) {
};

void TblMsdcMData::removeRecByRef(
			ubigint ref
		) {
};

bool TblMsdcMData::loadRecByRef(
			ubigint ref
			, MsdcMData** rec
		) {
	return false;
};

ubigint TblMsdcMData::loadRstByPrd(
			ubigint refMsdcMPeriod
			, const bool append
			, ListMsdcMData& rst
		) {
	return 0;
};

ubigint TblMsdcMData::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListMsdcMData& rst
		) {
	ubigint numload = 0;
	MsdcMData* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

/******************************************************************************
 class LiteTblMsdcMData
 ******************************************************************************/

LiteTblMsdcMData::LiteTblMsdcMData() : TblMsdcMData(), LiteTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;

	stmtLoadRstByPrd = NULL;
};

LiteTblMsdcMData::~LiteTblMsdcMData() {
	if (stmtInsertRec) sqlite3_finalize(stmtInsertRec);
	if (stmtUpdateRec) sqlite3_finalize(stmtUpdateRec);
	if (stmtRemoveRecByRef) sqlite3_finalize(stmtRemoveRecByRef);

	if (stmtLoadRstByPrd) sqlite3_finalize(stmtLoadRstByPrd);
};

void LiteTblMsdcMData::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblMsdcMData (refMsdcMPeriod, start, stop, srefMsdcKAcqfeat, Comment) VALUES (?1,?2,?3,?4,?5)");
	stmtUpdateRec = createStatement("UPDATE TblMsdcMData SET refMsdcMPeriod = ?1, start = ?2, stop = ?3, srefMsdcKAcqfeat = ?4, Comment = ?5 WHERE ref = ?6");
	stmtRemoveRecByRef = createStatement("DELETE FROM TblMsdcMData WHERE ref = ?1");

	stmtLoadRecByRef = createStatement("SELECT ref, refMsdcMPeriod, start, stop, srefMsdcKAcqfeat, Comment FROM TblMsdcMData WHERE ref = ?1");
	stmtLoadRstByPrd = createStatement("SELECT ref, refMsdcMPeriod, start, stop, srefMsdcKAcqfeat, Comment FROM TblMsdcMData WHERE refMsdcMPeriod = ?1");
};

bool LiteTblMsdcMData::loadRec(
			sqlite3_stmt* stmt
			, MsdcMData** rec
		) {
	int res;

	MsdcMData* _rec = NULL;
	bool retval = false;

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		_rec = new MsdcMData();

		_rec->ref = sqlite3_column_int64(stmt, 0);
		_rec->refMsdcMPeriod = sqlite3_column_int64(stmt, 1);
		_rec->start = sqlite3_column_int(stmt, 2);
		_rec->stop = sqlite3_column_int(stmt, 3);
		_rec->srefMsdcKAcqfeat.assign((const char*) sqlite3_column_text(stmt, 4));
		_rec->Comment.assign((const char*) sqlite3_column_text(stmt, 5));

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

ubigint LiteTblMsdcMData::loadRst(
			sqlite3_stmt* stmt
			, const bool append
			, ListMsdcMData& rst
		) {
	int res; ubigint numread = 0;

	MsdcMData* rec;

	if (!append) rst.clear();

	res = sqlite3_step(stmt);
	while (res == SQLITE_ROW) {
		rec = new MsdcMData();

		rec->ref = sqlite3_column_int64(stmt, 0);
		rec->refMsdcMPeriod = sqlite3_column_int64(stmt, 1);
		rec->start = sqlite3_column_int(stmt, 2);
		rec->stop = sqlite3_column_int(stmt, 3);
		rec->srefMsdcKAcqfeat.assign((const char*) sqlite3_column_text(stmt, 4));
		rec->Comment.assign((const char*) sqlite3_column_text(stmt, 5));

		rst.nodes.push_back(rec);

		numread++;

		res = sqlite3_step(stmt);
	};

	return(numread);
};

bool LiteTblMsdcMData::loadRecByStmt(
			sqlite3_stmt* stmt
			, MsdcMData** rec
		) {
	bool retval = loadRec(stmt, rec);

	sqlite3_reset(stmt);

	return retval;
};

ubigint LiteTblMsdcMData::loadRstByStmt(
			sqlite3_stmt* stmt
			, const bool append
			, ListMsdcMData& rst
		) {
	ubigint retval = loadRst(stmt, append, rst);

	sqlite3_reset(stmt);

	return retval;
};

bool LiteTblMsdcMData::loadRecBySQL(
			const string& sqlstr
			, MsdcMData** rec
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

ubigint LiteTblMsdcMData::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListMsdcMData& rst
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

void LiteTblMsdcMData::insertRec(
			MsdcMData* rec
		) {
	sqlite3_bind_int64(stmtInsertRec, 1, rec->refMsdcMPeriod);
	sqlite3_bind_int(stmtInsertRec, 2, rec->start);
	sqlite3_bind_int(stmtInsertRec, 3, rec->stop);
	sqlite3_bind_text(stmtInsertRec, 4, rec->srefMsdcKAcqfeat.c_str(), rec->srefMsdcKAcqfeat.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtInsertRec, 5, rec->Comment.c_str(), rec->Comment.length(), SQLITE_STATIC);

	if (sqlite3_step(stmtInsertRec) != SQLITE_DONE) throw DbsException("DbsException / SQLite: error executing statement! (TblMsdcMData / stmtInsertRec)\n");
	rec->ref = sqlite3_last_insert_rowid(dbs);

	sqlite3_reset(stmtInsertRec);
};

void LiteTblMsdcMData::insertRst(
			ListMsdcMData& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void LiteTblMsdcMData::updateRec(
			MsdcMData* rec
		) {
	sqlite3_bind_int64(stmtUpdateRec, 1, rec->refMsdcMPeriod);
	sqlite3_bind_int(stmtUpdateRec, 2, rec->start);
	sqlite3_bind_int(stmtUpdateRec, 3, rec->stop);
	sqlite3_bind_text(stmtUpdateRec, 4, rec->srefMsdcKAcqfeat.c_str(), rec->srefMsdcKAcqfeat.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtUpdateRec, 5, rec->Comment.c_str(), rec->Comment.length(), SQLITE_STATIC);
	sqlite3_bind_int64(stmtUpdateRec, 6, rec->ref);

	if (sqlite3_step(stmtUpdateRec) != SQLITE_DONE) throw DbsException("DbsException / SQLite: error executing statement! (TblMsdcMData / stmtUpdateRec)\n");

	sqlite3_reset(stmtUpdateRec);
};

void LiteTblMsdcMData::updateRst(
			ListMsdcMData& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void LiteTblMsdcMData::removeRecByRef(
			ubigint ref
		) {
	sqlite3_bind_int64(stmtRemoveRecByRef, 1, ref);

	if (sqlite3_step(stmtRemoveRecByRef) != SQLITE_DONE) throw DbsException("DbsException / SQLite: error executing statement! (TblMsdcMData / stmtRemoveRecByRef)\n");

	sqlite3_reset(stmtRemoveRecByRef);
};

bool LiteTblMsdcMData::loadRecByRef(
			ubigint ref
			, MsdcMData** rec
		) {
	sqlite3_bind_int64(stmtLoadRecByRef, 1, ref);

	return loadRecByStmt(stmtLoadRecByRef, rec);
};

ubigint LiteTblMsdcMData::loadRstByPrd(
			ubigint refMsdcMPeriod
			, const bool append
			, ListMsdcMData& rst
		) {
	sqlite3_bind_int64(stmtLoadRstByPrd, 1, refMsdcMPeriod);

	return loadRstByStmt(stmtLoadRstByPrd, append, rst);
};

