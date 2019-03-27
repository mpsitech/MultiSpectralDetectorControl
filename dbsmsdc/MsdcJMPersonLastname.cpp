/**
  * \file MsdcJMPersonLastname.cpp
  * database access for table TblMsdcJMPersonLastname (implementation)
  * \author Alexander Wirthmueller
  * \date created: 18 Dec 2018
  * \date modified: 18 Dec 2018
  */

#include "MsdcJMPersonLastname.h"

/******************************************************************************
 class MsdcJMPersonLastname
 ******************************************************************************/

MsdcJMPersonLastname::MsdcJMPersonLastname(
			const ubigint ref
			, const ubigint refMsdcMPerson
			, const uint x1Startd
			, const string Lastname
		) {

	this->ref = ref;
	this->refMsdcMPerson = refMsdcMPerson;
	this->x1Startd = x1Startd;
	this->Lastname = Lastname;
};

bool MsdcJMPersonLastname::operator==(
			const MsdcJMPersonLastname& comp
		) {
	return false;
};

bool MsdcJMPersonLastname::operator!=(
			const MsdcJMPersonLastname& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListMsdcJMPersonLastname
 ******************************************************************************/

ListMsdcJMPersonLastname::ListMsdcJMPersonLastname() {
};

ListMsdcJMPersonLastname::ListMsdcJMPersonLastname(
			const ListMsdcJMPersonLastname& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new MsdcJMPersonLastname(*(src.nodes[i]));
};

ListMsdcJMPersonLastname::~ListMsdcJMPersonLastname() {
	clear();
};

void ListMsdcJMPersonLastname::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListMsdcJMPersonLastname::size() const {
	return(nodes.size());
};

void ListMsdcJMPersonLastname::append(
			MsdcJMPersonLastname* rec
		) {
	nodes.push_back(rec);
};

MsdcJMPersonLastname* ListMsdcJMPersonLastname::operator[](
			const uint ix
		) {
	MsdcJMPersonLastname* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListMsdcJMPersonLastname& ListMsdcJMPersonLastname::operator=(
			const ListMsdcJMPersonLastname& src
		) {
	MsdcJMPersonLastname* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new MsdcJMPersonLastname(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListMsdcJMPersonLastname::operator==(
			const ListMsdcJMPersonLastname& comp
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

bool ListMsdcJMPersonLastname::operator!=(
			const ListMsdcJMPersonLastname& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblMsdcJMPersonLastname
 ******************************************************************************/

TblMsdcJMPersonLastname::TblMsdcJMPersonLastname() {
};

TblMsdcJMPersonLastname::~TblMsdcJMPersonLastname() {
};

bool TblMsdcJMPersonLastname::loadRecBySQL(
			const string& sqlstr
			, MsdcJMPersonLastname** rec
		) {
	return false;
};

ubigint TblMsdcJMPersonLastname::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListMsdcJMPersonLastname& rst
		) {
	return 0;
};

void TblMsdcJMPersonLastname::insertRec(
			MsdcJMPersonLastname* rec
		) {
};

ubigint TblMsdcJMPersonLastname::insertNewRec(
			MsdcJMPersonLastname** rec
			, const ubigint refMsdcMPerson
			, const uint x1Startd
			, const string Lastname
		) {
	ubigint retval = 0;
	MsdcJMPersonLastname* _rec = NULL;

	_rec = new MsdcJMPersonLastname(0, refMsdcMPerson, x1Startd, Lastname);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblMsdcJMPersonLastname::appendNewRecToRst(
			ListMsdcJMPersonLastname& rst
			, MsdcJMPersonLastname** rec
			, const ubigint refMsdcMPerson
			, const uint x1Startd
			, const string Lastname
		) {
	ubigint retval = 0;
	MsdcJMPersonLastname* _rec = NULL;

	retval = insertNewRec(&_rec, refMsdcMPerson, x1Startd, Lastname);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblMsdcJMPersonLastname::insertRst(
			ListMsdcJMPersonLastname& rst
			, bool transact
		) {
};

void TblMsdcJMPersonLastname::updateRec(
			MsdcJMPersonLastname* rec
		) {
};

void TblMsdcJMPersonLastname::updateRst(
			ListMsdcJMPersonLastname& rst
			, bool transact
		) {
};

void TblMsdcJMPersonLastname::removeRecByRef(
			ubigint ref
		) {
};

bool TblMsdcJMPersonLastname::loadRecByRef(
			ubigint ref
			, MsdcJMPersonLastname** rec
		) {
	return false;
};

bool TblMsdcJMPersonLastname::loadRecByPrsSta(
			ubigint refMsdcMPerson
			, uint x1Startd
			, MsdcJMPersonLastname** rec
		) {
	return false;
};

ubigint TblMsdcJMPersonLastname::loadRefsByPrs(
			ubigint refMsdcMPerson
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblMsdcJMPersonLastname::loadRstByPrs(
			ubigint refMsdcMPerson
			, const bool append
			, ListMsdcJMPersonLastname& rst
		) {
	return 0;
};

ubigint TblMsdcJMPersonLastname::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListMsdcJMPersonLastname& rst
		) {
	ubigint numload = 0;
	MsdcJMPersonLastname* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

/******************************************************************************
 class LiteTblMsdcJMPersonLastname
 ******************************************************************************/

LiteTblMsdcJMPersonLastname::LiteTblMsdcJMPersonLastname() :
			TblMsdcJMPersonLastname()
			, LiteTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;

	stmtLoadRecByPrsSta = NULL;
	stmtLoadRefsByPrs = NULL;
	stmtLoadRstByPrs = NULL;
};

LiteTblMsdcJMPersonLastname::~LiteTblMsdcJMPersonLastname() {
	if (stmtInsertRec) sqlite3_finalize(stmtInsertRec);
	if (stmtUpdateRec) sqlite3_finalize(stmtUpdateRec);
	if (stmtRemoveRecByRef) sqlite3_finalize(stmtRemoveRecByRef);

	if (stmtLoadRecByPrsSta) sqlite3_finalize(stmtLoadRecByPrsSta);
	if (stmtLoadRefsByPrs) sqlite3_finalize(stmtLoadRefsByPrs);
	if (stmtLoadRstByPrs) sqlite3_finalize(stmtLoadRstByPrs);
};

void LiteTblMsdcJMPersonLastname::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblMsdcJMPersonLastname (refMsdcMPerson, x1Startd, Lastname) VALUES (?1,?2,?3)");
	stmtUpdateRec = createStatement("UPDATE TblMsdcJMPersonLastname SET refMsdcMPerson = ?1, x1Startd = ?2, Lastname = ?3 WHERE ref = ?4");
	stmtRemoveRecByRef = createStatement("DELETE FROM TblMsdcJMPersonLastname WHERE ref = ?1");

	stmtLoadRecByRef = createStatement("SELECT ref, refMsdcMPerson, x1Startd, Lastname FROM TblMsdcJMPersonLastname WHERE ref = ?1");
	stmtLoadRecByPrsSta = createStatement("SELECT ref, refMsdcMPerson, x1Startd, Lastname FROM TblMsdcJMPersonLastname WHERE refMsdcMPerson = ?1 AND x1Startd <= ?2 ORDER BY x1Startd DESC LIMIT 0,1");
	stmtLoadRefsByPrs = createStatement("SELECT ref FROM TblMsdcJMPersonLastname WHERE refMsdcMPerson = ?1");
	stmtLoadRstByPrs = createStatement("SELECT ref, refMsdcMPerson, x1Startd, Lastname FROM TblMsdcJMPersonLastname WHERE refMsdcMPerson = ?1 ORDER BY x1Startd ASC");
};

bool LiteTblMsdcJMPersonLastname::loadRec(
			sqlite3_stmt* stmt
			, MsdcJMPersonLastname** rec
		) {
	int res;

	MsdcJMPersonLastname* _rec = NULL;
	bool retval = false;

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		_rec = new MsdcJMPersonLastname();

		_rec->ref = sqlite3_column_int64(stmt, 0);
		_rec->refMsdcMPerson = sqlite3_column_int64(stmt, 1);
		_rec->x1Startd = sqlite3_column_int(stmt, 2);
		_rec->Lastname.assign((const char*) sqlite3_column_text(stmt, 3));

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

ubigint LiteTblMsdcJMPersonLastname::loadRst(
			sqlite3_stmt* stmt
			, const bool append
			, ListMsdcJMPersonLastname& rst
		) {
	int res; ubigint numread = 0;

	MsdcJMPersonLastname* rec;

	if (!append) rst.clear();

	res = sqlite3_step(stmt);
	while (res == SQLITE_ROW) {
		rec = new MsdcJMPersonLastname();

		rec->ref = sqlite3_column_int64(stmt, 0);
		rec->refMsdcMPerson = sqlite3_column_int64(stmt, 1);
		rec->x1Startd = sqlite3_column_int(stmt, 2);
		rec->Lastname.assign((const char*) sqlite3_column_text(stmt, 3));

		rst.nodes.push_back(rec);

		numread++;

		res = sqlite3_step(stmt);
	};

	return(numread);
};

bool LiteTblMsdcJMPersonLastname::loadRecByStmt(
			sqlite3_stmt* stmt
			, MsdcJMPersonLastname** rec
		) {
	bool retval = loadRec(stmt, rec);

	sqlite3_reset(stmt);

	return retval;
};

ubigint LiteTblMsdcJMPersonLastname::loadRstByStmt(
			sqlite3_stmt* stmt
			, const bool append
			, ListMsdcJMPersonLastname& rst
		) {
	ubigint retval = loadRst(stmt, append, rst);

	sqlite3_reset(stmt);

	return retval;
};

bool LiteTblMsdcJMPersonLastname::loadRecBySQL(
			const string& sqlstr
			, MsdcJMPersonLastname** rec
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

ubigint LiteTblMsdcJMPersonLastname::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListMsdcJMPersonLastname& rst
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

void LiteTblMsdcJMPersonLastname::insertRec(
			MsdcJMPersonLastname* rec
		) {
	sqlite3_bind_int64(stmtInsertRec, 1, rec->refMsdcMPerson);
	sqlite3_bind_int(stmtInsertRec, 2, rec->x1Startd);
	sqlite3_bind_text(stmtInsertRec, 3, rec->Lastname.c_str(), rec->Lastname.length(), SQLITE_STATIC);

	if (sqlite3_step(stmtInsertRec) != SQLITE_DONE) throw DbsException("DbsException / SQLite: error executing statement! (TblMsdcJMPersonLastname / stmtInsertRec)\n");
	rec->ref = sqlite3_last_insert_rowid(dbs);

	sqlite3_reset(stmtInsertRec);
};

void LiteTblMsdcJMPersonLastname::insertRst(
			ListMsdcJMPersonLastname& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void LiteTblMsdcJMPersonLastname::updateRec(
			MsdcJMPersonLastname* rec
		) {
	sqlite3_bind_int64(stmtUpdateRec, 1, rec->refMsdcMPerson);
	sqlite3_bind_int(stmtUpdateRec, 2, rec->x1Startd);
	sqlite3_bind_text(stmtUpdateRec, 3, rec->Lastname.c_str(), rec->Lastname.length(), SQLITE_STATIC);
	sqlite3_bind_int64(stmtUpdateRec, 4, rec->ref);

	if (sqlite3_step(stmtUpdateRec) != SQLITE_DONE) throw DbsException("DbsException / SQLite: error executing statement! (TblMsdcJMPersonLastname / stmtUpdateRec)\n");

	sqlite3_reset(stmtUpdateRec);
};

void LiteTblMsdcJMPersonLastname::updateRst(
			ListMsdcJMPersonLastname& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void LiteTblMsdcJMPersonLastname::removeRecByRef(
			ubigint ref
		) {
	sqlite3_bind_int64(stmtRemoveRecByRef, 1, ref);

	if (sqlite3_step(stmtRemoveRecByRef) != SQLITE_DONE) throw DbsException("DbsException / SQLite: error executing statement! (TblMsdcJMPersonLastname / stmtRemoveRecByRef)\n");

	sqlite3_reset(stmtRemoveRecByRef);
};

bool LiteTblMsdcJMPersonLastname::loadRecByRef(
			ubigint ref
			, MsdcJMPersonLastname** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	sqlite3_bind_int64(stmtLoadRecByRef, 1, ref);

	return loadRecByStmt(stmtLoadRecByRef, rec);
};

bool LiteTblMsdcJMPersonLastname::loadRecByPrsSta(
			ubigint refMsdcMPerson
			, uint x1Startd
			, MsdcJMPersonLastname** rec
		) {
	sqlite3_bind_int64(stmtLoadRecByPrsSta, 1, refMsdcMPerson);
	sqlite3_bind_int(stmtLoadRecByPrsSta, 2, x1Startd);

	return loadRecByStmt(stmtLoadRecByPrsSta, rec);
};

ubigint LiteTblMsdcJMPersonLastname::loadRefsByPrs(
			ubigint refMsdcMPerson
			, const bool append
			, vector<ubigint>& refs
		) {
	sqlite3_bind_int64(stmtLoadRefsByPrs, 1, refMsdcMPerson);

	return loadRefsByStmt(stmtLoadRefsByPrs, append, refs);
};

ubigint LiteTblMsdcJMPersonLastname::loadRstByPrs(
			ubigint refMsdcMPerson
			, const bool append
			, ListMsdcJMPersonLastname& rst
		) {
	sqlite3_bind_int64(stmtLoadRstByPrs, 1, refMsdcMPerson);

	return loadRstByStmt(stmtLoadRstByPrs, append, rst);
};

