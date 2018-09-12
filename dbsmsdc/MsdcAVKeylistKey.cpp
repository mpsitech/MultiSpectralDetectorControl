/**
  * \file MsdcAVKeylistKey.cpp
  * database access for table TblMsdcAVKeylistKey (implementation)
  * \author Alexander Wirthmueller
  * \date created: 12 Sep 2018
  * \date modified: 12 Sep 2018
  */

#include "MsdcAVKeylistKey.h"

/******************************************************************************
 class MsdcAVKeylistKey
 ******************************************************************************/

MsdcAVKeylistKey::MsdcAVKeylistKey(
			const ubigint ref
			, const uint klsIxMsdcVKeylist
			, const uint klsNum
			, const uint x1IxMsdcVMaintable
			, const ubigint x1Uref
			, const bool Fixed
			, const string sref
			, const string Avail
			, const string Implied
			, const ubigint refJ
			, const string Title
			, const string Comment
		) {

	this->ref = ref;
	this->klsIxMsdcVKeylist = klsIxMsdcVKeylist;
	this->klsNum = klsNum;
	this->x1IxMsdcVMaintable = x1IxMsdcVMaintable;
	this->x1Uref = x1Uref;
	this->Fixed = Fixed;
	this->sref = sref;
	this->Avail = Avail;
	this->Implied = Implied;
	this->refJ = refJ;
	this->Title = Title;
	this->Comment = Comment;
};

bool MsdcAVKeylistKey::operator==(
			const MsdcAVKeylistKey& comp
		) {
	return false;
};

bool MsdcAVKeylistKey::operator!=(
			const MsdcAVKeylistKey& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListMsdcAVKeylistKey
 ******************************************************************************/

ListMsdcAVKeylistKey::ListMsdcAVKeylistKey() {
};

ListMsdcAVKeylistKey::ListMsdcAVKeylistKey(
			const ListMsdcAVKeylistKey& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new MsdcAVKeylistKey(*(src.nodes[i]));
};

ListMsdcAVKeylistKey::~ListMsdcAVKeylistKey() {
	clear();
};

void ListMsdcAVKeylistKey::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListMsdcAVKeylistKey::size() const {
	return(nodes.size());
};

void ListMsdcAVKeylistKey::append(
			MsdcAVKeylistKey* rec
		) {
	nodes.push_back(rec);
};

MsdcAVKeylistKey* ListMsdcAVKeylistKey::operator[](
			const uint ix
		) {
	MsdcAVKeylistKey* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListMsdcAVKeylistKey& ListMsdcAVKeylistKey::operator=(
			const ListMsdcAVKeylistKey& src
		) {
	MsdcAVKeylistKey* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new MsdcAVKeylistKey(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListMsdcAVKeylistKey::operator==(
			const ListMsdcAVKeylistKey& comp
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

bool ListMsdcAVKeylistKey::operator!=(
			const ListMsdcAVKeylistKey& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblMsdcAVKeylistKey
 ******************************************************************************/

TblMsdcAVKeylistKey::TblMsdcAVKeylistKey() {
};

TblMsdcAVKeylistKey::~TblMsdcAVKeylistKey() {
};

bool TblMsdcAVKeylistKey::loadRecBySQL(
			const string& sqlstr
			, MsdcAVKeylistKey** rec
		) {
	return false;
};

ubigint TblMsdcAVKeylistKey::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListMsdcAVKeylistKey& rst
		) {
	return 0;
};

void TblMsdcAVKeylistKey::insertRec(
			MsdcAVKeylistKey* rec
		) {
};

ubigint TblMsdcAVKeylistKey::insertNewRec(
			MsdcAVKeylistKey** rec
			, const uint klsIxMsdcVKeylist
			, const uint klsNum
			, const uint x1IxMsdcVMaintable
			, const ubigint x1Uref
			, const bool Fixed
			, const string sref
			, const string Avail
			, const string Implied
			, const ubigint refJ
			, const string Title
			, const string Comment
		) {
	ubigint retval = 0;
	MsdcAVKeylistKey* _rec = NULL;

	_rec = new MsdcAVKeylistKey(0, klsIxMsdcVKeylist, klsNum, x1IxMsdcVMaintable, x1Uref, Fixed, sref, Avail, Implied, refJ, Title, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblMsdcAVKeylistKey::appendNewRecToRst(
			ListMsdcAVKeylistKey& rst
			, MsdcAVKeylistKey** rec
			, const uint klsIxMsdcVKeylist
			, const uint klsNum
			, const uint x1IxMsdcVMaintable
			, const ubigint x1Uref
			, const bool Fixed
			, const string sref
			, const string Avail
			, const string Implied
			, const ubigint refJ
			, const string Title
			, const string Comment
		) {
	ubigint retval = 0;
	MsdcAVKeylistKey* _rec = NULL;

	retval = insertNewRec(&_rec, klsIxMsdcVKeylist, klsNum, x1IxMsdcVMaintable, x1Uref, Fixed, sref, Avail, Implied, refJ, Title, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblMsdcAVKeylistKey::insertRst(
			ListMsdcAVKeylistKey& rst
			, bool transact
		) {
};

void TblMsdcAVKeylistKey::updateRec(
			MsdcAVKeylistKey* rec
		) {
};

void TblMsdcAVKeylistKey::updateRst(
			ListMsdcAVKeylistKey& rst
			, bool transact
		) {
};

void TblMsdcAVKeylistKey::removeRecByRef(
			ubigint ref
		) {
};

bool TblMsdcAVKeylistKey::loadRecByRef(
			ubigint ref
			, MsdcAVKeylistKey** rec
		) {
	return false;
};

bool TblMsdcAVKeylistKey::loadRefByKlsMtbUrfSrf(
			uint klsIxMsdcVKeylist
			, uint x1IxMsdcVMaintable
			, ubigint x1Uref
			, string sref
			, ubigint& ref
		) {
	return false;
};

bool TblMsdcAVKeylistKey::loadRefByKlsSrf(
			uint klsIxMsdcVKeylist
			, string sref
			, ubigint& ref
		) {
	return false;
};

ubigint TblMsdcAVKeylistKey::loadRstByKls(
			uint klsIxMsdcVKeylist
			, const bool append
			, ListMsdcAVKeylistKey& rst
		) {
	return 0;
};

ubigint TblMsdcAVKeylistKey::loadRstByKlsMtbUrf(
			uint klsIxMsdcVKeylist
			, uint x1IxMsdcVMaintable
			, ubigint x1Uref
			, const bool append
			, ListMsdcAVKeylistKey& rst
		) {
	return 0;
};

bool TblMsdcAVKeylistKey::loadTitByRef(
			ubigint ref
			, string& Title
		) {
	return false;
};

ubigint TblMsdcAVKeylistKey::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListMsdcAVKeylistKey& rst
		) {
	ubigint numload = 0;
	MsdcAVKeylistKey* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

/******************************************************************************
 class LiteTblMsdcAVKeylistKey
 ******************************************************************************/

LiteTblMsdcAVKeylistKey::LiteTblMsdcAVKeylistKey() :
			TblMsdcAVKeylistKey()
			, LiteTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;

	stmtLoadRefByKlsMtbUrfSrf = NULL;
	stmtLoadRefByKlsSrf = NULL;
	stmtLoadRstByKls = NULL;
	stmtLoadRstByKlsMtbUrf = NULL;
	stmtLoadTitByRef = NULL;
};

LiteTblMsdcAVKeylistKey::~LiteTblMsdcAVKeylistKey() {
	if (stmtInsertRec) sqlite3_finalize(stmtInsertRec);
	if (stmtUpdateRec) sqlite3_finalize(stmtUpdateRec);
	if (stmtRemoveRecByRef) sqlite3_finalize(stmtRemoveRecByRef);

	if (stmtLoadRefByKlsMtbUrfSrf) sqlite3_finalize(stmtLoadRefByKlsMtbUrfSrf);
	if (stmtLoadRefByKlsSrf) sqlite3_finalize(stmtLoadRefByKlsSrf);
	if (stmtLoadRstByKls) sqlite3_finalize(stmtLoadRstByKls);
	if (stmtLoadRstByKlsMtbUrf) sqlite3_finalize(stmtLoadRstByKlsMtbUrf);
	if (stmtLoadTitByRef) sqlite3_finalize(stmtLoadTitByRef);
};

void LiteTblMsdcAVKeylistKey::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblMsdcAVKeylistKey (klsIxMsdcVKeylist, klsNum, x1IxMsdcVMaintable, x1Uref, Fixed, sref, Avail, Implied, refJ, Title, Comment) VALUES (?1,?2,?3,?4,?5,?6,?7,?8,?9,?10,?11)");
	stmtUpdateRec = createStatement("UPDATE TblMsdcAVKeylistKey SET klsIxMsdcVKeylist = ?1, klsNum = ?2, x1IxMsdcVMaintable = ?3, x1Uref = ?4, Fixed = ?5, sref = ?6, Avail = ?7, Implied = ?8, refJ = ?9, Title = ?10, Comment = ?11 WHERE ref = ?12");
	stmtRemoveRecByRef = createStatement("DELETE FROM TblMsdcAVKeylistKey WHERE ref = ?1");

	stmtLoadRecByRef = createStatement("SELECT ref, klsIxMsdcVKeylist, klsNum, x1IxMsdcVMaintable, x1Uref, Fixed, sref, Avail, Implied, refJ, Title, Comment FROM TblMsdcAVKeylistKey WHERE ref = ?1");
	stmtLoadRefByKlsMtbUrfSrf = createStatement("SELECT ref FROM TblMsdcAVKeylistKey WHERE klsIxMsdcVKeylist = ?1 AND x1IxMsdcVMaintable = ?2 AND x1Uref = ?3 AND sref = ?4");
	stmtLoadRefByKlsSrf = createStatement("SELECT ref FROM TblMsdcAVKeylistKey WHERE klsIxMsdcVKeylist = ?1 AND sref = ?2");
	stmtLoadRstByKls = createStatement("SELECT ref, klsIxMsdcVKeylist, klsNum, x1IxMsdcVMaintable, x1Uref, Fixed, sref, Avail, Implied, refJ, Title, Comment FROM TblMsdcAVKeylistKey WHERE klsIxMsdcVKeylist = ?1 ORDER BY klsNum ASC");
	stmtLoadRstByKlsMtbUrf = createStatement("SELECT ref, klsIxMsdcVKeylist, klsNum, x1IxMsdcVMaintable, x1Uref, Fixed, sref, Avail, Implied, refJ, Title, Comment FROM TblMsdcAVKeylistKey WHERE klsIxMsdcVKeylist = ?1 AND x1IxMsdcVMaintable = ?2 AND x1Uref = ?3 ORDER BY klsNum ASC");
	stmtLoadTitByRef = createStatement("SELECT Title FROM TblMsdcAVKeylistKey WHERE ref = ?1");
};

bool LiteTblMsdcAVKeylistKey::loadRec(
			sqlite3_stmt* stmt
			, MsdcAVKeylistKey** rec
		) {
	int res;

	MsdcAVKeylistKey* _rec = NULL;
	bool retval = false;

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		_rec = new MsdcAVKeylistKey();

		_rec->ref = sqlite3_column_int64(stmt, 0);
		_rec->klsIxMsdcVKeylist = sqlite3_column_int(stmt, 1);
		_rec->klsNum = sqlite3_column_int(stmt, 2);
		_rec->x1IxMsdcVMaintable = sqlite3_column_int(stmt, 3);
		_rec->x1Uref = sqlite3_column_int64(stmt, 4);
		_rec->Fixed = (sqlite3_column_int(stmt, 5) != 0);
		_rec->sref.assign((const char*) sqlite3_column_text(stmt, 6));
		_rec->Avail.assign((const char*) sqlite3_column_text(stmt, 7));
		_rec->Implied.assign((const char*) sqlite3_column_text(stmt, 8));
		_rec->refJ = sqlite3_column_int64(stmt, 9);
		_rec->Title.assign((const char*) sqlite3_column_text(stmt, 10));
		_rec->Comment.assign((const char*) sqlite3_column_text(stmt, 11));

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

ubigint LiteTblMsdcAVKeylistKey::loadRst(
			sqlite3_stmt* stmt
			, const bool append
			, ListMsdcAVKeylistKey& rst
		) {
	int res; ubigint numread = 0;

	MsdcAVKeylistKey* rec;

	if (!append) rst.clear();

	res = sqlite3_step(stmt);
	while (res == SQLITE_ROW) {
		rec = new MsdcAVKeylistKey();

		rec->ref = sqlite3_column_int64(stmt, 0);
		rec->klsIxMsdcVKeylist = sqlite3_column_int(stmt, 1);
		rec->klsNum = sqlite3_column_int(stmt, 2);
		rec->x1IxMsdcVMaintable = sqlite3_column_int(stmt, 3);
		rec->x1Uref = sqlite3_column_int64(stmt, 4);
		rec->Fixed = (sqlite3_column_int(stmt, 5) != 0);
		rec->sref.assign((const char*) sqlite3_column_text(stmt, 6));
		rec->Avail.assign((const char*) sqlite3_column_text(stmt, 7));
		rec->Implied.assign((const char*) sqlite3_column_text(stmt, 8));
		rec->refJ = sqlite3_column_int64(stmt, 9);
		rec->Title.assign((const char*) sqlite3_column_text(stmt, 10));
		rec->Comment.assign((const char*) sqlite3_column_text(stmt, 11));

		rst.nodes.push_back(rec);

		numread++;

		res = sqlite3_step(stmt);
	};

	return(numread);
};

bool LiteTblMsdcAVKeylistKey::loadRecByStmt(
			sqlite3_stmt* stmt
			, MsdcAVKeylistKey** rec
		) {
	bool retval = loadRec(stmt, rec);

	sqlite3_reset(stmt);

	return retval;
};

ubigint LiteTblMsdcAVKeylistKey::loadRstByStmt(
			sqlite3_stmt* stmt
			, const bool append
			, ListMsdcAVKeylistKey& rst
		) {
	ubigint retval = loadRst(stmt, append, rst);

	sqlite3_reset(stmt);

	return retval;
};

bool LiteTblMsdcAVKeylistKey::loadRecBySQL(
			const string& sqlstr
			, MsdcAVKeylistKey** rec
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

ubigint LiteTblMsdcAVKeylistKey::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListMsdcAVKeylistKey& rst
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

void LiteTblMsdcAVKeylistKey::insertRec(
			MsdcAVKeylistKey* rec
		) {
	sqlite3_bind_int(stmtInsertRec, 1, rec->klsIxMsdcVKeylist);
	sqlite3_bind_int(stmtInsertRec, 2, rec->klsNum);
	sqlite3_bind_int(stmtInsertRec, 3, rec->x1IxMsdcVMaintable);
	sqlite3_bind_int64(stmtInsertRec, 4, rec->x1Uref);
	sqlite3_bind_int(stmtInsertRec, 5, rec->Fixed);
	sqlite3_bind_text(stmtInsertRec, 6, rec->sref.c_str(), rec->sref.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtInsertRec, 7, rec->Avail.c_str(), rec->Avail.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtInsertRec, 8, rec->Implied.c_str(), rec->Implied.length(), SQLITE_STATIC);
	sqlite3_bind_int64(stmtInsertRec, 9, rec->refJ);
	sqlite3_bind_text(stmtInsertRec, 10, rec->Title.c_str(), rec->Title.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtInsertRec, 11, rec->Comment.c_str(), rec->Comment.length(), SQLITE_STATIC);

	if (sqlite3_step(stmtInsertRec) != SQLITE_DONE) throw DbsException("DbsException / SQLite: error executing statement! (TblMsdcAVKeylistKey / stmtInsertRec)\n");
	rec->ref = sqlite3_last_insert_rowid(dbs);

	sqlite3_reset(stmtInsertRec);
};

void LiteTblMsdcAVKeylistKey::insertRst(
			ListMsdcAVKeylistKey& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void LiteTblMsdcAVKeylistKey::updateRec(
			MsdcAVKeylistKey* rec
		) {
	sqlite3_bind_int(stmtUpdateRec, 1, rec->klsIxMsdcVKeylist);
	sqlite3_bind_int(stmtUpdateRec, 2, rec->klsNum);
	sqlite3_bind_int(stmtUpdateRec, 3, rec->x1IxMsdcVMaintable);
	sqlite3_bind_int64(stmtUpdateRec, 4, rec->x1Uref);
	sqlite3_bind_int(stmtUpdateRec, 5, rec->Fixed);
	sqlite3_bind_text(stmtUpdateRec, 6, rec->sref.c_str(), rec->sref.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtUpdateRec, 7, rec->Avail.c_str(), rec->Avail.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtUpdateRec, 8, rec->Implied.c_str(), rec->Implied.length(), SQLITE_STATIC);
	sqlite3_bind_int64(stmtUpdateRec, 9, rec->refJ);
	sqlite3_bind_text(stmtUpdateRec, 10, rec->Title.c_str(), rec->Title.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtUpdateRec, 11, rec->Comment.c_str(), rec->Comment.length(), SQLITE_STATIC);
	sqlite3_bind_int64(stmtUpdateRec, 12, rec->ref);

	if (sqlite3_step(stmtUpdateRec) != SQLITE_DONE) throw DbsException("DbsException / SQLite: error executing statement! (TblMsdcAVKeylistKey / stmtUpdateRec)\n");

	sqlite3_reset(stmtUpdateRec);
};

void LiteTblMsdcAVKeylistKey::updateRst(
			ListMsdcAVKeylistKey& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void LiteTblMsdcAVKeylistKey::removeRecByRef(
			ubigint ref
		) {
	sqlite3_bind_int64(stmtRemoveRecByRef, 1, ref);

	if (sqlite3_step(stmtRemoveRecByRef) != SQLITE_DONE) throw DbsException("DbsException / SQLite: error executing statement! (TblMsdcAVKeylistKey / stmtRemoveRecByRef)\n");

	sqlite3_reset(stmtRemoveRecByRef);
};

bool LiteTblMsdcAVKeylistKey::loadRecByRef(
			ubigint ref
			, MsdcAVKeylistKey** rec
		) {
	sqlite3_bind_int64(stmtLoadRecByRef, 1, ref);

	return loadRecByStmt(stmtLoadRecByRef, rec);
};

bool LiteTblMsdcAVKeylistKey::loadRefByKlsMtbUrfSrf(
			uint klsIxMsdcVKeylist
			, uint x1IxMsdcVMaintable
			, ubigint x1Uref
			, string sref
			, ubigint& ref
		) {
	sqlite3_bind_int(stmtLoadRefByKlsMtbUrfSrf, 1, klsIxMsdcVKeylist);
	sqlite3_bind_int(stmtLoadRefByKlsMtbUrfSrf, 2, x1IxMsdcVMaintable);
	sqlite3_bind_int64(stmtLoadRefByKlsMtbUrfSrf, 3, x1Uref);
	sqlite3_bind_text(stmtLoadRefByKlsMtbUrfSrf, 4, sref.c_str(), sref.length(), SQLITE_STATIC);

	return loadRefByStmt(stmtLoadRefByKlsMtbUrfSrf, ref);
};

bool LiteTblMsdcAVKeylistKey::loadRefByKlsSrf(
			uint klsIxMsdcVKeylist
			, string sref
			, ubigint& ref
		) {
	sqlite3_bind_int(stmtLoadRefByKlsSrf, 1, klsIxMsdcVKeylist);
	sqlite3_bind_text(stmtLoadRefByKlsSrf, 2, sref.c_str(), sref.length(), SQLITE_STATIC);

	return loadRefByStmt(stmtLoadRefByKlsSrf, ref);
};

ubigint LiteTblMsdcAVKeylistKey::loadRstByKls(
			uint klsIxMsdcVKeylist
			, const bool append
			, ListMsdcAVKeylistKey& rst
		) {
	sqlite3_bind_int(stmtLoadRstByKls, 1, klsIxMsdcVKeylist);

	return loadRstByStmt(stmtLoadRstByKls, append, rst);
};

ubigint LiteTblMsdcAVKeylistKey::loadRstByKlsMtbUrf(
			uint klsIxMsdcVKeylist
			, uint x1IxMsdcVMaintable
			, ubigint x1Uref
			, const bool append
			, ListMsdcAVKeylistKey& rst
		) {
	sqlite3_bind_int(stmtLoadRstByKlsMtbUrf, 1, klsIxMsdcVKeylist);
	sqlite3_bind_int(stmtLoadRstByKlsMtbUrf, 2, x1IxMsdcVMaintable);
	sqlite3_bind_int64(stmtLoadRstByKlsMtbUrf, 3, x1Uref);

	return loadRstByStmt(stmtLoadRstByKlsMtbUrf, append, rst);
};

bool LiteTblMsdcAVKeylistKey::loadTitByRef(
			ubigint ref
			, string& Title
		) {
	sqlite3_bind_int64(stmtLoadTitByRef, 1, ref);

	return loadStringByStmt(stmtLoadTitByRef, Title);
};

