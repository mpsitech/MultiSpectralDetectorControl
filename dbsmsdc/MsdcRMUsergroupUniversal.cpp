/**
  * \file MsdcRMUsergroupUniversal.cpp
  * database access for table TblMsdcRMUsergroupUniversal (implementation)
  * \author Alexander Wirthmueller
  * \date created: 12 Sep 2018
  * \date modified: 12 Sep 2018
  */

#include "MsdcRMUsergroupUniversal.h"

/******************************************************************************
 class MsdcRMUsergroupUniversal
 ******************************************************************************/

MsdcRMUsergroupUniversal::MsdcRMUsergroupUniversal(
			const ubigint ref
			, const ubigint refMsdcMUsergroup
			, const uint unvIxMsdcVMaintable
			, const ubigint unvUref
			, const uint ixMsdcVRecaccess
		) {

	this->ref = ref;
	this->refMsdcMUsergroup = refMsdcMUsergroup;
	this->unvIxMsdcVMaintable = unvIxMsdcVMaintable;
	this->unvUref = unvUref;
	this->ixMsdcVRecaccess = ixMsdcVRecaccess;
};

bool MsdcRMUsergroupUniversal::operator==(
			const MsdcRMUsergroupUniversal& comp
		) {
	return false;
};

bool MsdcRMUsergroupUniversal::operator!=(
			const MsdcRMUsergroupUniversal& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListMsdcRMUsergroupUniversal
 ******************************************************************************/

ListMsdcRMUsergroupUniversal::ListMsdcRMUsergroupUniversal() {
};

ListMsdcRMUsergroupUniversal::ListMsdcRMUsergroupUniversal(
			const ListMsdcRMUsergroupUniversal& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new MsdcRMUsergroupUniversal(*(src.nodes[i]));
};

ListMsdcRMUsergroupUniversal::~ListMsdcRMUsergroupUniversal() {
	clear();
};

void ListMsdcRMUsergroupUniversal::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListMsdcRMUsergroupUniversal::size() const {
	return(nodes.size());
};

void ListMsdcRMUsergroupUniversal::append(
			MsdcRMUsergroupUniversal* rec
		) {
	nodes.push_back(rec);
};

MsdcRMUsergroupUniversal* ListMsdcRMUsergroupUniversal::operator[](
			const uint ix
		) {
	MsdcRMUsergroupUniversal* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListMsdcRMUsergroupUniversal& ListMsdcRMUsergroupUniversal::operator=(
			const ListMsdcRMUsergroupUniversal& src
		) {
	MsdcRMUsergroupUniversal* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new MsdcRMUsergroupUniversal(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListMsdcRMUsergroupUniversal::operator==(
			const ListMsdcRMUsergroupUniversal& comp
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

bool ListMsdcRMUsergroupUniversal::operator!=(
			const ListMsdcRMUsergroupUniversal& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblMsdcRMUsergroupUniversal
 ******************************************************************************/

TblMsdcRMUsergroupUniversal::TblMsdcRMUsergroupUniversal() {
};

TblMsdcRMUsergroupUniversal::~TblMsdcRMUsergroupUniversal() {
};

bool TblMsdcRMUsergroupUniversal::loadRecBySQL(
			const string& sqlstr
			, MsdcRMUsergroupUniversal** rec
		) {
	return false;
};

ubigint TblMsdcRMUsergroupUniversal::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListMsdcRMUsergroupUniversal& rst
		) {
	return 0;
};

void TblMsdcRMUsergroupUniversal::insertRec(
			MsdcRMUsergroupUniversal* rec
		) {
};

ubigint TblMsdcRMUsergroupUniversal::insertNewRec(
			MsdcRMUsergroupUniversal** rec
			, const ubigint refMsdcMUsergroup
			, const uint unvIxMsdcVMaintable
			, const ubigint unvUref
			, const uint ixMsdcVRecaccess
		) {
	ubigint retval = 0;
	MsdcRMUsergroupUniversal* _rec = NULL;

	_rec = new MsdcRMUsergroupUniversal(0, refMsdcMUsergroup, unvIxMsdcVMaintable, unvUref, ixMsdcVRecaccess);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblMsdcRMUsergroupUniversal::appendNewRecToRst(
			ListMsdcRMUsergroupUniversal& rst
			, MsdcRMUsergroupUniversal** rec
			, const ubigint refMsdcMUsergroup
			, const uint unvIxMsdcVMaintable
			, const ubigint unvUref
			, const uint ixMsdcVRecaccess
		) {
	ubigint retval = 0;
	MsdcRMUsergroupUniversal* _rec = NULL;

	retval = insertNewRec(&_rec, refMsdcMUsergroup, unvIxMsdcVMaintable, unvUref, ixMsdcVRecaccess);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblMsdcRMUsergroupUniversal::insertRst(
			ListMsdcRMUsergroupUniversal& rst
			, bool transact
		) {
};

void TblMsdcRMUsergroupUniversal::updateRec(
			MsdcRMUsergroupUniversal* rec
		) {
};

void TblMsdcRMUsergroupUniversal::updateRst(
			ListMsdcRMUsergroupUniversal& rst
			, bool transact
		) {
};

void TblMsdcRMUsergroupUniversal::removeRecByRef(
			ubigint ref
		) {
};

bool TblMsdcRMUsergroupUniversal::loadRecByRef(
			ubigint ref
			, MsdcRMUsergroupUniversal** rec
		) {
	return false;
};

bool TblMsdcRMUsergroupUniversal::loadRecByUsgMtbUnv(
			ubigint refMsdcMUsergroup
			, uint unvIxMsdcVMaintable
			, ubigint unvUref
			, MsdcRMUsergroupUniversal** rec
		) {
	return false;
};

ubigint TblMsdcRMUsergroupUniversal::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListMsdcRMUsergroupUniversal& rst
		) {
	ubigint numload = 0;
	MsdcRMUsergroupUniversal* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

/******************************************************************************
 class LiteTblMsdcRMUsergroupUniversal
 ******************************************************************************/

LiteTblMsdcRMUsergroupUniversal::LiteTblMsdcRMUsergroupUniversal() :
			TblMsdcRMUsergroupUniversal()
			, LiteTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;

	stmtLoadRecByUsgMtbUnv = NULL;
};

LiteTblMsdcRMUsergroupUniversal::~LiteTblMsdcRMUsergroupUniversal() {
	if (stmtInsertRec) sqlite3_finalize(stmtInsertRec);
	if (stmtUpdateRec) sqlite3_finalize(stmtUpdateRec);
	if (stmtRemoveRecByRef) sqlite3_finalize(stmtRemoveRecByRef);

	if (stmtLoadRecByUsgMtbUnv) sqlite3_finalize(stmtLoadRecByUsgMtbUnv);
};

void LiteTblMsdcRMUsergroupUniversal::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblMsdcRMUsergroupUniversal (refMsdcMUsergroup, unvIxMsdcVMaintable, unvUref, ixMsdcVRecaccess) VALUES (?1,?2,?3,?4)");
	stmtUpdateRec = createStatement("UPDATE TblMsdcRMUsergroupUniversal SET refMsdcMUsergroup = ?1, unvIxMsdcVMaintable = ?2, unvUref = ?3, ixMsdcVRecaccess = ?4 WHERE ref = ?5");
	stmtRemoveRecByRef = createStatement("DELETE FROM TblMsdcRMUsergroupUniversal WHERE ref = ?1");

	stmtLoadRecByRef = createStatement("SELECT ref, refMsdcMUsergroup, unvIxMsdcVMaintable, unvUref, ixMsdcVRecaccess FROM TblMsdcRMUsergroupUniversal WHERE ref = ?1");
	stmtLoadRecByUsgMtbUnv = createStatement("SELECT ref, refMsdcMUsergroup, unvIxMsdcVMaintable, unvUref, ixMsdcVRecaccess FROM TblMsdcRMUsergroupUniversal WHERE refMsdcMUsergroup = ?1 AND unvIxMsdcVMaintable = ?2 AND unvUref = ?3");
};

bool LiteTblMsdcRMUsergroupUniversal::loadRec(
			sqlite3_stmt* stmt
			, MsdcRMUsergroupUniversal** rec
		) {
	int res;

	MsdcRMUsergroupUniversal* _rec = NULL;
	bool retval = false;

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		_rec = new MsdcRMUsergroupUniversal();

		_rec->ref = sqlite3_column_int64(stmt, 0);
		_rec->refMsdcMUsergroup = sqlite3_column_int64(stmt, 1);
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

ubigint LiteTblMsdcRMUsergroupUniversal::loadRst(
			sqlite3_stmt* stmt
			, const bool append
			, ListMsdcRMUsergroupUniversal& rst
		) {
	int res; ubigint numread = 0;

	MsdcRMUsergroupUniversal* rec;

	if (!append) rst.clear();

	res = sqlite3_step(stmt);
	while (res == SQLITE_ROW) {
		rec = new MsdcRMUsergroupUniversal();

		rec->ref = sqlite3_column_int64(stmt, 0);
		rec->refMsdcMUsergroup = sqlite3_column_int64(stmt, 1);
		rec->unvIxMsdcVMaintable = sqlite3_column_int(stmt, 2);
		rec->unvUref = sqlite3_column_int64(stmt, 3);
		rec->ixMsdcVRecaccess = sqlite3_column_int(stmt, 4);

		rst.nodes.push_back(rec);

		numread++;

		res = sqlite3_step(stmt);
	};

	return(numread);
};

bool LiteTblMsdcRMUsergroupUniversal::loadRecByStmt(
			sqlite3_stmt* stmt
			, MsdcRMUsergroupUniversal** rec
		) {
	bool retval = loadRec(stmt, rec);

	sqlite3_reset(stmt);

	return retval;
};

bool LiteTblMsdcRMUsergroupUniversal::loadRecBySQL(
			const string& sqlstr
			, MsdcRMUsergroupUniversal** rec
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

ubigint LiteTblMsdcRMUsergroupUniversal::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListMsdcRMUsergroupUniversal& rst
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

void LiteTblMsdcRMUsergroupUniversal::insertRec(
			MsdcRMUsergroupUniversal* rec
		) {
	sqlite3_bind_int64(stmtInsertRec, 1, rec->refMsdcMUsergroup);
	sqlite3_bind_int(stmtInsertRec, 2, rec->unvIxMsdcVMaintable);
	sqlite3_bind_int64(stmtInsertRec, 3, rec->unvUref);
	sqlite3_bind_int(stmtInsertRec, 4, rec->ixMsdcVRecaccess);

	if (sqlite3_step(stmtInsertRec) != SQLITE_DONE) throw DbsException("DbsException / SQLite: error executing statement! (TblMsdcRMUsergroupUniversal / stmtInsertRec)\n");
	rec->ref = sqlite3_last_insert_rowid(dbs);

	sqlite3_reset(stmtInsertRec);
};

void LiteTblMsdcRMUsergroupUniversal::insertRst(
			ListMsdcRMUsergroupUniversal& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void LiteTblMsdcRMUsergroupUniversal::updateRec(
			MsdcRMUsergroupUniversal* rec
		) {
	sqlite3_bind_int64(stmtUpdateRec, 1, rec->refMsdcMUsergroup);
	sqlite3_bind_int(stmtUpdateRec, 2, rec->unvIxMsdcVMaintable);
	sqlite3_bind_int64(stmtUpdateRec, 3, rec->unvUref);
	sqlite3_bind_int(stmtUpdateRec, 4, rec->ixMsdcVRecaccess);
	sqlite3_bind_int64(stmtUpdateRec, 5, rec->ref);

	if (sqlite3_step(stmtUpdateRec) != SQLITE_DONE) throw DbsException("DbsException / SQLite: error executing statement! (TblMsdcRMUsergroupUniversal / stmtUpdateRec)\n");

	sqlite3_reset(stmtUpdateRec);
};

void LiteTblMsdcRMUsergroupUniversal::updateRst(
			ListMsdcRMUsergroupUniversal& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void LiteTblMsdcRMUsergroupUniversal::removeRecByRef(
			ubigint ref
		) {
	sqlite3_bind_int64(stmtRemoveRecByRef, 1, ref);

	if (sqlite3_step(stmtRemoveRecByRef) != SQLITE_DONE) throw DbsException("DbsException / SQLite: error executing statement! (TblMsdcRMUsergroupUniversal / stmtRemoveRecByRef)\n");

	sqlite3_reset(stmtRemoveRecByRef);
};

bool LiteTblMsdcRMUsergroupUniversal::loadRecByRef(
			ubigint ref
			, MsdcRMUsergroupUniversal** rec
		) {
	sqlite3_bind_int64(stmtLoadRecByRef, 1, ref);

	return loadRecByStmt(stmtLoadRecByRef, rec);
};

bool LiteTblMsdcRMUsergroupUniversal::loadRecByUsgMtbUnv(
			ubigint refMsdcMUsergroup
			, uint unvIxMsdcVMaintable
			, ubigint unvUref
			, MsdcRMUsergroupUniversal** rec
		) {
	sqlite3_bind_int64(stmtLoadRecByUsgMtbUnv, 1, refMsdcMUsergroup);
	sqlite3_bind_int(stmtLoadRecByUsgMtbUnv, 2, unvIxMsdcVMaintable);
	sqlite3_bind_int64(stmtLoadRecByUsgMtbUnv, 3, unvUref);

	return loadRecByStmt(stmtLoadRecByUsgMtbUnv, rec);
};

