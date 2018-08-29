/**
  * \file MsdcAccRMUserUniversal.cpp
  * database access for table TblMsdcAccRMUserUniversal (implementation)
  * \author Alexander Wirthmueller
  * \date created: 29 Aug 2018
  * \date modified: 29 Aug 2018
  */

#include "MsdcAccRMUserUniversal.h"

/******************************************************************************
 class MsdcAccRMUserUniversal
 ******************************************************************************/

MsdcAccRMUserUniversal::MsdcAccRMUserUniversal(
			const ubigint ref
			, const ubigint refMsdcMUser
			, const uint unvIxMsdcVMaintable
			, const ubigint unvUref
			, const uint ixMsdcVRecaccess
		) {

	this->ref = ref;
	this->refMsdcMUser = refMsdcMUser;
	this->unvIxMsdcVMaintable = unvIxMsdcVMaintable;
	this->unvUref = unvUref;
	this->ixMsdcVRecaccess = ixMsdcVRecaccess;
};

bool MsdcAccRMUserUniversal::operator==(
			const MsdcAccRMUserUniversal& comp
		) {
	return false;
};

bool MsdcAccRMUserUniversal::operator!=(
			const MsdcAccRMUserUniversal& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListMsdcAccRMUserUniversal
 ******************************************************************************/

ListMsdcAccRMUserUniversal::ListMsdcAccRMUserUniversal() {
};

ListMsdcAccRMUserUniversal::ListMsdcAccRMUserUniversal(
			const ListMsdcAccRMUserUniversal& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new MsdcAccRMUserUniversal(*(src.nodes[i]));
};

ListMsdcAccRMUserUniversal::~ListMsdcAccRMUserUniversal() {
	clear();
};

void ListMsdcAccRMUserUniversal::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListMsdcAccRMUserUniversal::size() const {
	return(nodes.size());
};

void ListMsdcAccRMUserUniversal::append(
			MsdcAccRMUserUniversal* rec
		) {
	nodes.push_back(rec);
};

MsdcAccRMUserUniversal* ListMsdcAccRMUserUniversal::operator[](
			const uint ix
		) {
	MsdcAccRMUserUniversal* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListMsdcAccRMUserUniversal& ListMsdcAccRMUserUniversal::operator=(
			const ListMsdcAccRMUserUniversal& src
		) {
	MsdcAccRMUserUniversal* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new MsdcAccRMUserUniversal(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListMsdcAccRMUserUniversal::operator==(
			const ListMsdcAccRMUserUniversal& comp
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

bool ListMsdcAccRMUserUniversal::operator!=(
			const ListMsdcAccRMUserUniversal& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblMsdcAccRMUserUniversal
 ******************************************************************************/

TblMsdcAccRMUserUniversal::TblMsdcAccRMUserUniversal() {
};

TblMsdcAccRMUserUniversal::~TblMsdcAccRMUserUniversal() {
};

bool TblMsdcAccRMUserUniversal::loadRecBySQL(
			const string& sqlstr
			, MsdcAccRMUserUniversal** rec
		) {
	return false;
};

ubigint TblMsdcAccRMUserUniversal::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListMsdcAccRMUserUniversal& rst
		) {
	return 0;
};

void TblMsdcAccRMUserUniversal::insertRec(
			MsdcAccRMUserUniversal* rec
		) {
};

ubigint TblMsdcAccRMUserUniversal::insertNewRec(
			MsdcAccRMUserUniversal** rec
			, const ubigint refMsdcMUser
			, const uint unvIxMsdcVMaintable
			, const ubigint unvUref
			, const uint ixMsdcVRecaccess
		) {
	ubigint retval = 0;
	MsdcAccRMUserUniversal* _rec = NULL;

	_rec = new MsdcAccRMUserUniversal(0, refMsdcMUser, unvIxMsdcVMaintable, unvUref, ixMsdcVRecaccess);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblMsdcAccRMUserUniversal::appendNewRecToRst(
			ListMsdcAccRMUserUniversal& rst
			, MsdcAccRMUserUniversal** rec
			, const ubigint refMsdcMUser
			, const uint unvIxMsdcVMaintable
			, const ubigint unvUref
			, const uint ixMsdcVRecaccess
		) {
	ubigint retval = 0;
	MsdcAccRMUserUniversal* _rec = NULL;

	retval = insertNewRec(&_rec, refMsdcMUser, unvIxMsdcVMaintable, unvUref, ixMsdcVRecaccess);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblMsdcAccRMUserUniversal::insertRst(
			ListMsdcAccRMUserUniversal& rst
			, bool transact
		) {
};

void TblMsdcAccRMUserUniversal::updateRec(
			MsdcAccRMUserUniversal* rec
		) {
};

void TblMsdcAccRMUserUniversal::updateRst(
			ListMsdcAccRMUserUniversal& rst
			, bool transact
		) {
};

void TblMsdcAccRMUserUniversal::removeRecByRef(
			ubigint ref
		) {
};

bool TblMsdcAccRMUserUniversal::loadRecByRef(
			ubigint ref
			, MsdcAccRMUserUniversal** rec
		) {
	return false;
};

bool TblMsdcAccRMUserUniversal::loadRecByUsrMtbUnv(
			ubigint refMsdcMUser
			, uint unvIxMsdcVMaintable
			, ubigint unvUref
			, MsdcAccRMUserUniversal** rec
		) {
	return false;
};

ubigint TblMsdcAccRMUserUniversal::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListMsdcAccRMUserUniversal& rst
		) {
	ubigint numload = 0;
	MsdcAccRMUserUniversal* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

/******************************************************************************
 class LiteTblMsdcAccRMUserUniversal
 ******************************************************************************/

LiteTblMsdcAccRMUserUniversal::LiteTblMsdcAccRMUserUniversal() :
			TblMsdcAccRMUserUniversal()
			, LiteTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;

	stmtLoadRecByUsrMtbUnv = NULL;
};

LiteTblMsdcAccRMUserUniversal::~LiteTblMsdcAccRMUserUniversal() {
	if (stmtInsertRec) sqlite3_finalize(stmtInsertRec);
	if (stmtUpdateRec) sqlite3_finalize(stmtUpdateRec);
	if (stmtRemoveRecByRef) sqlite3_finalize(stmtRemoveRecByRef);

	if (stmtLoadRecByUsrMtbUnv) sqlite3_finalize(stmtLoadRecByUsrMtbUnv);
};

void LiteTblMsdcAccRMUserUniversal::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblMsdcAccRMUserUniversal (refMsdcMUser, unvIxMsdcVMaintable, unvUref, ixMsdcVRecaccess) VALUES (?1,?2,?3,?4)");
	stmtUpdateRec = createStatement("UPDATE TblMsdcAccRMUserUniversal SET refMsdcMUser = ?1, unvIxMsdcVMaintable = ?2, unvUref = ?3, ixMsdcVRecaccess = ?4 WHERE ref = ?5");
	stmtRemoveRecByRef = createStatement("DELETE FROM TblMsdcAccRMUserUniversal WHERE ref = ?1");

	stmtLoadRecByRef = createStatement("SELECT ref, refMsdcMUser, unvIxMsdcVMaintable, unvUref, ixMsdcVRecaccess FROM TblMsdcAccRMUserUniversal WHERE ref = ?1");
	stmtLoadRecByUsrMtbUnv = createStatement("SELECT ref, refMsdcMUser, unvIxMsdcVMaintable, unvUref, ixMsdcVRecaccess FROM TblMsdcAccRMUserUniversal WHERE refMsdcMUser = ?1 AND unvIxMsdcVMaintable = ?2 AND unvUref = ?3");
};

bool LiteTblMsdcAccRMUserUniversal::loadRec(
			sqlite3_stmt* stmt
			, MsdcAccRMUserUniversal** rec
		) {
	int res;

	MsdcAccRMUserUniversal* _rec = NULL;
	bool retval = false;

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		_rec = new MsdcAccRMUserUniversal();

		_rec->ref = sqlite3_column_int64(stmt, 0);
		_rec->refMsdcMUser = sqlite3_column_int64(stmt, 1);
		_rec->unvIxMsdcVMaintable = sqlite3_column_int(stmt, 2);
		_rec->unvUref = sqlite3_column_int64(stmt, 3);
		_rec->ixMsdcVRecaccess = sqlite3_column_int(stmt, 4);

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

ubigint LiteTblMsdcAccRMUserUniversal::loadRst(
			sqlite3_stmt* stmt
			, const bool append
			, ListMsdcAccRMUserUniversal& rst
		) {
	int res; ubigint numread = 0;

	MsdcAccRMUserUniversal* rec;

	if (!append) rst.clear();

	res = sqlite3_step(stmt);
	while (res == SQLITE_ROW) {
		rec = new MsdcAccRMUserUniversal();

		rec->ref = sqlite3_column_int64(stmt, 0);
		rec->refMsdcMUser = sqlite3_column_int64(stmt, 1);
		rec->unvIxMsdcVMaintable = sqlite3_column_int(stmt, 2);
		rec->unvUref = sqlite3_column_int64(stmt, 3);
		rec->ixMsdcVRecaccess = sqlite3_column_int(stmt, 4);

		rst.nodes.push_back(rec);

		numread++;

		res = sqlite3_step(stmt);
	};

	return(numread);
};

bool LiteTblMsdcAccRMUserUniversal::loadRecByStmt(
			sqlite3_stmt* stmt
			, MsdcAccRMUserUniversal** rec
		) {
	bool retval = loadRec(stmt, rec);

	sqlite3_reset(stmt);

	return retval;
};

bool LiteTblMsdcAccRMUserUniversal::loadRecBySQL(
			const string& sqlstr
			, MsdcAccRMUserUniversal** rec
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

ubigint LiteTblMsdcAccRMUserUniversal::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListMsdcAccRMUserUniversal& rst
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

void LiteTblMsdcAccRMUserUniversal::insertRec(
			MsdcAccRMUserUniversal* rec
		) {
	sqlite3_bind_int64(stmtInsertRec, 1, rec->refMsdcMUser);
	sqlite3_bind_int(stmtInsertRec, 2, rec->unvIxMsdcVMaintable);
	sqlite3_bind_int64(stmtInsertRec, 3, rec->unvUref);
	sqlite3_bind_int(stmtInsertRec, 4, rec->ixMsdcVRecaccess);

	if (sqlite3_step(stmtInsertRec) != SQLITE_DONE) throw DbsException("DbsException / SQLite: error executing statement! (TblMsdcAccRMUserUniversal / stmtInsertRec)\n");
	rec->ref = sqlite3_last_insert_rowid(dbs);

	sqlite3_reset(stmtInsertRec);
};

void LiteTblMsdcAccRMUserUniversal::insertRst(
			ListMsdcAccRMUserUniversal& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void LiteTblMsdcAccRMUserUniversal::updateRec(
			MsdcAccRMUserUniversal* rec
		) {
	sqlite3_bind_int64(stmtUpdateRec, 1, rec->refMsdcMUser);
	sqlite3_bind_int(stmtUpdateRec, 2, rec->unvIxMsdcVMaintable);
	sqlite3_bind_int64(stmtUpdateRec, 3, rec->unvUref);
	sqlite3_bind_int(stmtUpdateRec, 4, rec->ixMsdcVRecaccess);
	sqlite3_bind_int64(stmtUpdateRec, 5, rec->ref);

	if (sqlite3_step(stmtUpdateRec) != SQLITE_DONE) throw DbsException("DbsException / SQLite: error executing statement! (TblMsdcAccRMUserUniversal / stmtUpdateRec)\n");

	sqlite3_reset(stmtUpdateRec);
};

void LiteTblMsdcAccRMUserUniversal::updateRst(
			ListMsdcAccRMUserUniversal& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void LiteTblMsdcAccRMUserUniversal::removeRecByRef(
			ubigint ref
		) {
	sqlite3_bind_int64(stmtRemoveRecByRef, 1, ref);

	if (sqlite3_step(stmtRemoveRecByRef) != SQLITE_DONE) throw DbsException("DbsException / SQLite: error executing statement! (TblMsdcAccRMUserUniversal / stmtRemoveRecByRef)\n");

	sqlite3_reset(stmtRemoveRecByRef);
};

bool LiteTblMsdcAccRMUserUniversal::loadRecByRef(
			ubigint ref
			, MsdcAccRMUserUniversal** rec
		) {
	sqlite3_bind_int64(stmtLoadRecByRef, 1, ref);

	return loadRecByStmt(stmtLoadRecByRef, rec);
};

bool LiteTblMsdcAccRMUserUniversal::loadRecByUsrMtbUnv(
			ubigint refMsdcMUser
			, uint unvIxMsdcVMaintable
			, ubigint unvUref
			, MsdcAccRMUserUniversal** rec
		) {
	sqlite3_bind_int64(stmtLoadRecByUsrMtbUnv, 1, refMsdcMUser);
	sqlite3_bind_int(stmtLoadRecByUsrMtbUnv, 2, unvIxMsdcVMaintable);
	sqlite3_bind_int64(stmtLoadRecByUsrMtbUnv, 3, unvUref);

	return loadRecByStmt(stmtLoadRecByUsrMtbUnv, rec);
};

