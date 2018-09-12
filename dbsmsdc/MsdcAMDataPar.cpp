/**
  * \file MsdcAMDataPar.cpp
  * database access for table TblMsdcAMDataPar (implementation)
  * \author Alexander Wirthmueller
  * \date created: 12 Sep 2018
  * \date modified: 12 Sep 2018
  */

#include "MsdcAMDataPar.h"

/******************************************************************************
 class MsdcAMDataPar
 ******************************************************************************/

MsdcAMDataPar::MsdcAMDataPar(
			const ubigint ref
			, const ubigint refMsdcMData
			, const double x1Start
			, const string x2SrefKKey
			, const ubigint refMsdcMFile
			, const string Val
			, const string Bindata
		) {

	this->ref = ref;
	this->refMsdcMData = refMsdcMData;
	this->x1Start = x1Start;
	this->x2SrefKKey = x2SrefKKey;
	this->refMsdcMFile = refMsdcMFile;
	this->Val = Val;
	this->Bindata = Bindata;
};

bool MsdcAMDataPar::operator==(
			const MsdcAMDataPar& comp
		) {
	return false;
};

bool MsdcAMDataPar::operator!=(
			const MsdcAMDataPar& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListMsdcAMDataPar
 ******************************************************************************/

ListMsdcAMDataPar::ListMsdcAMDataPar() {
};

ListMsdcAMDataPar::ListMsdcAMDataPar(
			const ListMsdcAMDataPar& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new MsdcAMDataPar(*(src.nodes[i]));
};

ListMsdcAMDataPar::~ListMsdcAMDataPar() {
	clear();
};

void ListMsdcAMDataPar::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListMsdcAMDataPar::size() const {
	return(nodes.size());
};

void ListMsdcAMDataPar::append(
			MsdcAMDataPar* rec
		) {
	nodes.push_back(rec);
};

MsdcAMDataPar* ListMsdcAMDataPar::operator[](
			const uint ix
		) {
	MsdcAMDataPar* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListMsdcAMDataPar& ListMsdcAMDataPar::operator=(
			const ListMsdcAMDataPar& src
		) {
	MsdcAMDataPar* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new MsdcAMDataPar(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListMsdcAMDataPar::operator==(
			const ListMsdcAMDataPar& comp
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

bool ListMsdcAMDataPar::operator!=(
			const ListMsdcAMDataPar& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblMsdcAMDataPar
 ******************************************************************************/

TblMsdcAMDataPar::TblMsdcAMDataPar() {
};

TblMsdcAMDataPar::~TblMsdcAMDataPar() {
};

bool TblMsdcAMDataPar::loadRecBySQL(
			const string& sqlstr
			, MsdcAMDataPar** rec
		) {
	return false;
};

ubigint TblMsdcAMDataPar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListMsdcAMDataPar& rst
		) {
	return 0;
};

void TblMsdcAMDataPar::insertRec(
			MsdcAMDataPar* rec
		) {
};

ubigint TblMsdcAMDataPar::insertNewRec(
			MsdcAMDataPar** rec
			, const ubigint refMsdcMData
			, const double x1Start
			, const string x2SrefKKey
			, const ubigint refMsdcMFile
			, const string Val
			, const string Bindata
		) {
	ubigint retval = 0;
	MsdcAMDataPar* _rec = NULL;

	_rec = new MsdcAMDataPar(0, refMsdcMData, x1Start, x2SrefKKey, refMsdcMFile, Val, Bindata);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblMsdcAMDataPar::appendNewRecToRst(
			ListMsdcAMDataPar& rst
			, MsdcAMDataPar** rec
			, const ubigint refMsdcMData
			, const double x1Start
			, const string x2SrefKKey
			, const ubigint refMsdcMFile
			, const string Val
			, const string Bindata
		) {
	ubigint retval = 0;
	MsdcAMDataPar* _rec = NULL;

	retval = insertNewRec(&_rec, refMsdcMData, x1Start, x2SrefKKey, refMsdcMFile, Val, Bindata);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblMsdcAMDataPar::insertRst(
			ListMsdcAMDataPar& rst
			, bool transact
		) {
};

void TblMsdcAMDataPar::updateRec(
			MsdcAMDataPar* rec
		) {
};

void TblMsdcAMDataPar::updateRst(
			ListMsdcAMDataPar& rst
			, bool transact
		) {
};

void TblMsdcAMDataPar::removeRecByRef(
			ubigint ref
		) {
};

bool TblMsdcAMDataPar::loadRecByRef(
			ubigint ref
			, MsdcAMDataPar** rec
		) {
	return false;
};

ubigint TblMsdcAMDataPar::loadRstByDat(
			ubigint refMsdcMData
			, const bool append
			, ListMsdcAMDataPar& rst
		) {
	return 0;
};

ubigint TblMsdcAMDataPar::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListMsdcAMDataPar& rst
		) {
	ubigint numload = 0;
	MsdcAMDataPar* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

/******************************************************************************
 class LiteTblMsdcAMDataPar
 ******************************************************************************/

LiteTblMsdcAMDataPar::LiteTblMsdcAMDataPar() :
			TblMsdcAMDataPar()
			, LiteTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;

	stmtLoadRstByDat = NULL;
};

LiteTblMsdcAMDataPar::~LiteTblMsdcAMDataPar() {
	if (stmtInsertRec) sqlite3_finalize(stmtInsertRec);
	if (stmtUpdateRec) sqlite3_finalize(stmtUpdateRec);
	if (stmtRemoveRecByRef) sqlite3_finalize(stmtRemoveRecByRef);

	if (stmtLoadRstByDat) sqlite3_finalize(stmtLoadRstByDat);
};

void LiteTblMsdcAMDataPar::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblMsdcAMDataPar (refMsdcMData, x1Start, x2SrefKKey, refMsdcMFile, Val, Bindata) VALUES (?1,?2,?3,?4,?5,?6)");
	stmtUpdateRec = createStatement("UPDATE TblMsdcAMDataPar SET refMsdcMData = ?1, x1Start = ?2, x2SrefKKey = ?3, refMsdcMFile = ?4, Val = ?5, Bindata = ?6 WHERE ref = ?7");
	stmtRemoveRecByRef = createStatement("DELETE FROM TblMsdcAMDataPar WHERE ref = ?1");

	stmtLoadRecByRef = createStatement("SELECT ref, refMsdcMData, x1Start, x2SrefKKey, refMsdcMFile, Val, Bindata FROM TblMsdcAMDataPar WHERE ref = ?1");
	stmtLoadRstByDat = createStatement("SELECT ref, refMsdcMData, x1Start, x2SrefKKey, refMsdcMFile, Val, Bindata FROM TblMsdcAMDataPar WHERE refMsdcMData = ?1 ORDER BY x1Start ASC, x2SrefKKey ASC");
};

bool LiteTblMsdcAMDataPar::loadRec(
			sqlite3_stmt* stmt
			, MsdcAMDataPar** rec
		) {
	int res;

	MsdcAMDataPar* _rec = NULL;
	bool retval = false;

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		_rec = new MsdcAMDataPar();

		_rec->ref = sqlite3_column_int64(stmt, 0);
		_rec->refMsdcMData = sqlite3_column_int64(stmt, 1);
		_rec->x1Start = sqlite3_column_double(stmt, 2);
		_rec->x2SrefKKey.assign((const char*) sqlite3_column_text(stmt, 3));
		_rec->refMsdcMFile = sqlite3_column_int64(stmt, 4);
		_rec->Val.assign((const char*) sqlite3_column_text(stmt, 5));
		_rec->Bindata.assign((const char*) sqlite3_column_text(stmt, 6));

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

ubigint LiteTblMsdcAMDataPar::loadRst(
			sqlite3_stmt* stmt
			, const bool append
			, ListMsdcAMDataPar& rst
		) {
	int res; ubigint numread = 0;

	MsdcAMDataPar* rec;

	if (!append) rst.clear();

	res = sqlite3_step(stmt);
	while (res == SQLITE_ROW) {
		rec = new MsdcAMDataPar();

		rec->ref = sqlite3_column_int64(stmt, 0);
		rec->refMsdcMData = sqlite3_column_int64(stmt, 1);
		rec->x1Start = sqlite3_column_double(stmt, 2);
		rec->x2SrefKKey.assign((const char*) sqlite3_column_text(stmt, 3));
		rec->refMsdcMFile = sqlite3_column_int64(stmt, 4);
		rec->Val.assign((const char*) sqlite3_column_text(stmt, 5));
		rec->Bindata.assign((const char*) sqlite3_column_text(stmt, 6));

		rst.nodes.push_back(rec);

		numread++;

		res = sqlite3_step(stmt);
	};

	return(numread);
};

bool LiteTblMsdcAMDataPar::loadRecByStmt(
			sqlite3_stmt* stmt
			, MsdcAMDataPar** rec
		) {
	bool retval = loadRec(stmt, rec);

	sqlite3_reset(stmt);

	return retval;
};

ubigint LiteTblMsdcAMDataPar::loadRstByStmt(
			sqlite3_stmt* stmt
			, const bool append
			, ListMsdcAMDataPar& rst
		) {
	ubigint retval = loadRst(stmt, append, rst);

	sqlite3_reset(stmt);

	return retval;
};

bool LiteTblMsdcAMDataPar::loadRecBySQL(
			const string& sqlstr
			, MsdcAMDataPar** rec
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

ubigint LiteTblMsdcAMDataPar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListMsdcAMDataPar& rst
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

void LiteTblMsdcAMDataPar::insertRec(
			MsdcAMDataPar* rec
		) {
	sqlite3_bind_int64(stmtInsertRec, 1, rec->refMsdcMData);
	sqlite3_bind_double(stmtInsertRec, 2, rec->x1Start);
	sqlite3_bind_text(stmtInsertRec, 3, rec->x2SrefKKey.c_str(), rec->x2SrefKKey.length(), SQLITE_STATIC);
	sqlite3_bind_int64(stmtInsertRec, 4, rec->refMsdcMFile);
	sqlite3_bind_text(stmtInsertRec, 5, rec->Val.c_str(), rec->Val.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtInsertRec, 6, rec->Bindata.c_str(), rec->Bindata.length(), SQLITE_STATIC);

	if (sqlite3_step(stmtInsertRec) != SQLITE_DONE) throw DbsException("DbsException / SQLite: error executing statement! (TblMsdcAMDataPar / stmtInsertRec)\n");
	rec->ref = sqlite3_last_insert_rowid(dbs);

	sqlite3_reset(stmtInsertRec);
};

void LiteTblMsdcAMDataPar::insertRst(
			ListMsdcAMDataPar& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void LiteTblMsdcAMDataPar::updateRec(
			MsdcAMDataPar* rec
		) {
	sqlite3_bind_int64(stmtUpdateRec, 1, rec->refMsdcMData);
	sqlite3_bind_double(stmtUpdateRec, 2, rec->x1Start);
	sqlite3_bind_text(stmtUpdateRec, 3, rec->x2SrefKKey.c_str(), rec->x2SrefKKey.length(), SQLITE_STATIC);
	sqlite3_bind_int64(stmtUpdateRec, 4, rec->refMsdcMFile);
	sqlite3_bind_text(stmtUpdateRec, 5, rec->Val.c_str(), rec->Val.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtUpdateRec, 6, rec->Bindata.c_str(), rec->Bindata.length(), SQLITE_STATIC);
	sqlite3_bind_int64(stmtUpdateRec, 7, rec->ref);

	if (sqlite3_step(stmtUpdateRec) != SQLITE_DONE) throw DbsException("DbsException / SQLite: error executing statement! (TblMsdcAMDataPar / stmtUpdateRec)\n");

	sqlite3_reset(stmtUpdateRec);
};

void LiteTblMsdcAMDataPar::updateRst(
			ListMsdcAMDataPar& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void LiteTblMsdcAMDataPar::removeRecByRef(
			ubigint ref
		) {
	sqlite3_bind_int64(stmtRemoveRecByRef, 1, ref);

	if (sqlite3_step(stmtRemoveRecByRef) != SQLITE_DONE) throw DbsException("DbsException / SQLite: error executing statement! (TblMsdcAMDataPar / stmtRemoveRecByRef)\n");

	sqlite3_reset(stmtRemoveRecByRef);
};

bool LiteTblMsdcAMDataPar::loadRecByRef(
			ubigint ref
			, MsdcAMDataPar** rec
		) {
	sqlite3_bind_int64(stmtLoadRecByRef, 1, ref);

	return loadRecByStmt(stmtLoadRecByRef, rec);
};

ubigint LiteTblMsdcAMDataPar::loadRstByDat(
			ubigint refMsdcMData
			, const bool append
			, ListMsdcAMDataPar& rst
		) {
	sqlite3_bind_int64(stmtLoadRstByDat, 1, refMsdcMData);

	return loadRstByStmt(stmtLoadRstByDat, append, rst);
};

