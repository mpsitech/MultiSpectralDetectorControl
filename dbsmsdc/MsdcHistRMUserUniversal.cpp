/**
  * \file MsdcHistRMUserUniversal.cpp
  * database access for table TblMsdcHistRMUserUniversal (implementation)
  * \author Alexander Wirthmueller
  * \date created: 29 Aug 2018
  * \date modified: 29 Aug 2018
  */

#include "MsdcHistRMUserUniversal.h"

/******************************************************************************
 class MsdcHistRMUserUniversal
 ******************************************************************************/

MsdcHistRMUserUniversal::MsdcHistRMUserUniversal(
			const ubigint ref
			, const ubigint refMsdcMUser
			, const uint unvIxMsdcVMaintable
			, const ubigint unvUref
			, const uint ixMsdcVCard
			, const uint ixMsdcVPreset
			, const uint preIxMsdcVMaintable
			, const ubigint preUref
			, const uint start
		) {

	this->ref = ref;
	this->refMsdcMUser = refMsdcMUser;
	this->unvIxMsdcVMaintable = unvIxMsdcVMaintable;
	this->unvUref = unvUref;
	this->ixMsdcVCard = ixMsdcVCard;
	this->ixMsdcVPreset = ixMsdcVPreset;
	this->preIxMsdcVMaintable = preIxMsdcVMaintable;
	this->preUref = preUref;
	this->start = start;
};

bool MsdcHistRMUserUniversal::operator==(
			const MsdcHistRMUserUniversal& comp
		) {
	return false;
};

bool MsdcHistRMUserUniversal::operator!=(
			const MsdcHistRMUserUniversal& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListMsdcHistRMUserUniversal
 ******************************************************************************/

ListMsdcHistRMUserUniversal::ListMsdcHistRMUserUniversal() {
};

ListMsdcHistRMUserUniversal::ListMsdcHistRMUserUniversal(
			const ListMsdcHistRMUserUniversal& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new MsdcHistRMUserUniversal(*(src.nodes[i]));
};

ListMsdcHistRMUserUniversal::~ListMsdcHistRMUserUniversal() {
	clear();
};

void ListMsdcHistRMUserUniversal::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListMsdcHistRMUserUniversal::size() const {
	return(nodes.size());
};

void ListMsdcHistRMUserUniversal::append(
			MsdcHistRMUserUniversal* rec
		) {
	nodes.push_back(rec);
};

MsdcHistRMUserUniversal* ListMsdcHistRMUserUniversal::operator[](
			const uint ix
		) {
	MsdcHistRMUserUniversal* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListMsdcHistRMUserUniversal& ListMsdcHistRMUserUniversal::operator=(
			const ListMsdcHistRMUserUniversal& src
		) {
	MsdcHistRMUserUniversal* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new MsdcHistRMUserUniversal(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListMsdcHistRMUserUniversal::operator==(
			const ListMsdcHistRMUserUniversal& comp
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

bool ListMsdcHistRMUserUniversal::operator!=(
			const ListMsdcHistRMUserUniversal& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblMsdcHistRMUserUniversal
 ******************************************************************************/

TblMsdcHistRMUserUniversal::TblMsdcHistRMUserUniversal() {
};

TblMsdcHistRMUserUniversal::~TblMsdcHistRMUserUniversal() {
};

bool TblMsdcHistRMUserUniversal::loadRecBySQL(
			const string& sqlstr
			, MsdcHistRMUserUniversal** rec
		) {
	return false;
};

ubigint TblMsdcHistRMUserUniversal::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListMsdcHistRMUserUniversal& rst
		) {
	return 0;
};

void TblMsdcHistRMUserUniversal::insertRec(
			MsdcHistRMUserUniversal* rec
		) {
};

ubigint TblMsdcHistRMUserUniversal::insertNewRec(
			MsdcHistRMUserUniversal** rec
			, const ubigint refMsdcMUser
			, const uint unvIxMsdcVMaintable
			, const ubigint unvUref
			, const uint ixMsdcVCard
			, const uint ixMsdcVPreset
			, const uint preIxMsdcVMaintable
			, const ubigint preUref
			, const uint start
		) {
	ubigint retval = 0;
	MsdcHistRMUserUniversal* _rec = NULL;

	_rec = new MsdcHistRMUserUniversal(0, refMsdcMUser, unvIxMsdcVMaintable, unvUref, ixMsdcVCard, ixMsdcVPreset, preIxMsdcVMaintable, preUref, start);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblMsdcHistRMUserUniversal::appendNewRecToRst(
			ListMsdcHistRMUserUniversal& rst
			, MsdcHistRMUserUniversal** rec
			, const ubigint refMsdcMUser
			, const uint unvIxMsdcVMaintable
			, const ubigint unvUref
			, const uint ixMsdcVCard
			, const uint ixMsdcVPreset
			, const uint preIxMsdcVMaintable
			, const ubigint preUref
			, const uint start
		) {
	ubigint retval = 0;
	MsdcHistRMUserUniversal* _rec = NULL;

	retval = insertNewRec(&_rec, refMsdcMUser, unvIxMsdcVMaintable, unvUref, ixMsdcVCard, ixMsdcVPreset, preIxMsdcVMaintable, preUref, start);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblMsdcHistRMUserUniversal::insertRst(
			ListMsdcHistRMUserUniversal& rst
			, bool transact
		) {
};

void TblMsdcHistRMUserUniversal::updateRec(
			MsdcHistRMUserUniversal* rec
		) {
};

void TblMsdcHistRMUserUniversal::updateRst(
			ListMsdcHistRMUserUniversal& rst
			, bool transact
		) {
};

void TblMsdcHistRMUserUniversal::removeRecByRef(
			ubigint ref
		) {
};

bool TblMsdcHistRMUserUniversal::loadRecByRef(
			ubigint ref
			, MsdcHistRMUserUniversal** rec
		) {
	return false;
};

ubigint TblMsdcHistRMUserUniversal::loadRstByUsrCrd(
			ubigint refMsdcMUser
			, uint ixMsdcVCard
			, const bool append
			, ListMsdcHistRMUserUniversal& rst
		) {
	return 0;
};

bool TblMsdcHistRMUserUniversal::loadUnuByRef(
			ubigint ref
			, ubigint& unvUref
		) {
	return false;
};

ubigint TblMsdcHistRMUserUniversal::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListMsdcHistRMUserUniversal& rst
		) {
	ubigint numload = 0;
	MsdcHistRMUserUniversal* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

/******************************************************************************
 class LiteTblMsdcHistRMUserUniversal
 ******************************************************************************/

LiteTblMsdcHistRMUserUniversal::LiteTblMsdcHistRMUserUniversal() :
			TblMsdcHistRMUserUniversal()
			, LiteTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;

	stmtLoadRstByUsrCrd = NULL;
	stmtLoadUnuByRef = NULL;
};

LiteTblMsdcHistRMUserUniversal::~LiteTblMsdcHistRMUserUniversal() {
	if (stmtInsertRec) sqlite3_finalize(stmtInsertRec);
	if (stmtUpdateRec) sqlite3_finalize(stmtUpdateRec);
	if (stmtRemoveRecByRef) sqlite3_finalize(stmtRemoveRecByRef);

	if (stmtLoadRstByUsrCrd) sqlite3_finalize(stmtLoadRstByUsrCrd);
	if (stmtLoadUnuByRef) sqlite3_finalize(stmtLoadUnuByRef);
};

void LiteTblMsdcHistRMUserUniversal::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblMsdcHistRMUserUniversal (refMsdcMUser, unvIxMsdcVMaintable, unvUref, ixMsdcVCard, ixMsdcVPreset, preIxMsdcVMaintable, preUref, start) VALUES (?1,?2,?3,?4,?5,?6,?7,?8)");
	stmtUpdateRec = createStatement("UPDATE TblMsdcHistRMUserUniversal SET refMsdcMUser = ?1, unvIxMsdcVMaintable = ?2, unvUref = ?3, ixMsdcVCard = ?4, ixMsdcVPreset = ?5, preIxMsdcVMaintable = ?6, preUref = ?7, start = ?8 WHERE ref = ?9");
	stmtRemoveRecByRef = createStatement("DELETE FROM TblMsdcHistRMUserUniversal WHERE ref = ?1");

	stmtLoadRecByRef = createStatement("SELECT ref, refMsdcMUser, unvIxMsdcVMaintable, unvUref, ixMsdcVCard, ixMsdcVPreset, preIxMsdcVMaintable, preUref, start FROM TblMsdcHistRMUserUniversal WHERE ref = ?1");
	stmtLoadRstByUsrCrd = createStatement("SELECT ref, refMsdcMUser, unvIxMsdcVMaintable, unvUref, ixMsdcVCard, ixMsdcVPreset, preIxMsdcVMaintable, preUref, start FROM TblMsdcHistRMUserUniversal WHERE refMsdcMUser = ?1 AND ixMsdcVCard = ?2 ORDER BY start DESC");
	stmtLoadUnuByRef = createStatement("SELECT unvUref FROM TblMsdcHistRMUserUniversal WHERE ref = ?1");
};

bool LiteTblMsdcHistRMUserUniversal::loadRec(
			sqlite3_stmt* stmt
			, MsdcHistRMUserUniversal** rec
		) {
	int res;

	MsdcHistRMUserUniversal* _rec = NULL;
	bool retval = false;

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		_rec = new MsdcHistRMUserUniversal();

		_rec->ref = sqlite3_column_int64(stmt, 0);
		_rec->refMsdcMUser = sqlite3_column_int64(stmt, 1);
		_rec->unvIxMsdcVMaintable = sqlite3_column_int(stmt, 2);
		_rec->unvUref = sqlite3_column_int64(stmt, 3);
		_rec->ixMsdcVCard = sqlite3_column_int(stmt, 4);
		_rec->ixMsdcVPreset = sqlite3_column_int(stmt, 5);
		_rec->preIxMsdcVMaintable = sqlite3_column_int(stmt, 6);
		_rec->preUref = sqlite3_column_int64(stmt, 7);
		_rec->start = sqlite3_column_int(stmt, 8);

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

ubigint LiteTblMsdcHistRMUserUniversal::loadRst(
			sqlite3_stmt* stmt
			, const bool append
			, ListMsdcHistRMUserUniversal& rst
		) {
	int res; ubigint numread = 0;

	MsdcHistRMUserUniversal* rec;

	if (!append) rst.clear();

	res = sqlite3_step(stmt);
	while (res == SQLITE_ROW) {
		rec = new MsdcHistRMUserUniversal();

		rec->ref = sqlite3_column_int64(stmt, 0);
		rec->refMsdcMUser = sqlite3_column_int64(stmt, 1);
		rec->unvIxMsdcVMaintable = sqlite3_column_int(stmt, 2);
		rec->unvUref = sqlite3_column_int64(stmt, 3);
		rec->ixMsdcVCard = sqlite3_column_int(stmt, 4);
		rec->ixMsdcVPreset = sqlite3_column_int(stmt, 5);
		rec->preIxMsdcVMaintable = sqlite3_column_int(stmt, 6);
		rec->preUref = sqlite3_column_int64(stmt, 7);
		rec->start = sqlite3_column_int(stmt, 8);

		rst.nodes.push_back(rec);

		numread++;

		res = sqlite3_step(stmt);
	};

	return(numread);
};

bool LiteTblMsdcHistRMUserUniversal::loadRecByStmt(
			sqlite3_stmt* stmt
			, MsdcHistRMUserUniversal** rec
		) {
	bool retval = loadRec(stmt, rec);

	sqlite3_reset(stmt);

	return retval;
};

ubigint LiteTblMsdcHistRMUserUniversal::loadRstByStmt(
			sqlite3_stmt* stmt
			, const bool append
			, ListMsdcHistRMUserUniversal& rst
		) {
	ubigint retval = loadRst(stmt, append, rst);

	sqlite3_reset(stmt);

	return retval;
};

bool LiteTblMsdcHistRMUserUniversal::loadRecBySQL(
			const string& sqlstr
			, MsdcHistRMUserUniversal** rec
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

ubigint LiteTblMsdcHistRMUserUniversal::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListMsdcHistRMUserUniversal& rst
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

void LiteTblMsdcHistRMUserUniversal::insertRec(
			MsdcHistRMUserUniversal* rec
		) {
	sqlite3_bind_int64(stmtInsertRec, 1, rec->refMsdcMUser);
	sqlite3_bind_int(stmtInsertRec, 2, rec->unvIxMsdcVMaintable);
	sqlite3_bind_int64(stmtInsertRec, 3, rec->unvUref);
	sqlite3_bind_int(stmtInsertRec, 4, rec->ixMsdcVCard);
	sqlite3_bind_int(stmtInsertRec, 5, rec->ixMsdcVPreset);
	sqlite3_bind_int(stmtInsertRec, 6, rec->preIxMsdcVMaintable);
	sqlite3_bind_int64(stmtInsertRec, 7, rec->preUref);
	sqlite3_bind_int(stmtInsertRec, 8, rec->start);

	if (sqlite3_step(stmtInsertRec) != SQLITE_DONE) throw DbsException("DbsException / SQLite: error executing statement! (TblMsdcHistRMUserUniversal / stmtInsertRec)\n");
	rec->ref = sqlite3_last_insert_rowid(dbs);

	sqlite3_reset(stmtInsertRec);
};

void LiteTblMsdcHistRMUserUniversal::insertRst(
			ListMsdcHistRMUserUniversal& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void LiteTblMsdcHistRMUserUniversal::updateRec(
			MsdcHistRMUserUniversal* rec
		) {
	sqlite3_bind_int64(stmtUpdateRec, 1, rec->refMsdcMUser);
	sqlite3_bind_int(stmtUpdateRec, 2, rec->unvIxMsdcVMaintable);
	sqlite3_bind_int64(stmtUpdateRec, 3, rec->unvUref);
	sqlite3_bind_int(stmtUpdateRec, 4, rec->ixMsdcVCard);
	sqlite3_bind_int(stmtUpdateRec, 5, rec->ixMsdcVPreset);
	sqlite3_bind_int(stmtUpdateRec, 6, rec->preIxMsdcVMaintable);
	sqlite3_bind_int64(stmtUpdateRec, 7, rec->preUref);
	sqlite3_bind_int(stmtUpdateRec, 8, rec->start);
	sqlite3_bind_int64(stmtUpdateRec, 9, rec->ref);

	if (sqlite3_step(stmtUpdateRec) != SQLITE_DONE) throw DbsException("DbsException / SQLite: error executing statement! (TblMsdcHistRMUserUniversal / stmtUpdateRec)\n");

	sqlite3_reset(stmtUpdateRec);
};

void LiteTblMsdcHistRMUserUniversal::updateRst(
			ListMsdcHistRMUserUniversal& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void LiteTblMsdcHistRMUserUniversal::removeRecByRef(
			ubigint ref
		) {
	sqlite3_bind_int64(stmtRemoveRecByRef, 1, ref);

	if (sqlite3_step(stmtRemoveRecByRef) != SQLITE_DONE) throw DbsException("DbsException / SQLite: error executing statement! (TblMsdcHistRMUserUniversal / stmtRemoveRecByRef)\n");

	sqlite3_reset(stmtRemoveRecByRef);
};

bool LiteTblMsdcHistRMUserUniversal::loadRecByRef(
			ubigint ref
			, MsdcHistRMUserUniversal** rec
		) {
	sqlite3_bind_int64(stmtLoadRecByRef, 1, ref);

	return loadRecByStmt(stmtLoadRecByRef, rec);
};

ubigint LiteTblMsdcHistRMUserUniversal::loadRstByUsrCrd(
			ubigint refMsdcMUser
			, uint ixMsdcVCard
			, const bool append
			, ListMsdcHistRMUserUniversal& rst
		) {
	sqlite3_bind_int64(stmtLoadRstByUsrCrd, 1, refMsdcMUser);
	sqlite3_bind_int(stmtLoadRstByUsrCrd, 2, ixMsdcVCard);

	return loadRstByStmt(stmtLoadRstByUsrCrd, append, rst);
};

bool LiteTblMsdcHistRMUserUniversal::loadUnuByRef(
			ubigint ref
			, ubigint& unvUref
		) {
	sqlite3_bind_int64(stmtLoadUnuByRef, 1, ref);

	return loadRefByStmt(stmtLoadUnuByRef, unvUref);
};

