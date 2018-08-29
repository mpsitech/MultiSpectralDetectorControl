/**
  * \file MsdcAVValuelistVal.cpp
  * database access for table TblMsdcAVValuelistVal (implementation)
  * \author Alexander Wirthmueller
  * \date created: 29 Aug 2018
  * \date modified: 29 Aug 2018
  */

#include "MsdcAVValuelistVal.h"

/******************************************************************************
 class MsdcAVValuelistVal
 ******************************************************************************/

MsdcAVValuelistVal::MsdcAVValuelistVal(
			const ubigint ref
			, const uint vlsIxMsdcVValuelist
			, const uint vlsNum
			, const uint x1IxMsdcVLocale
			, const string Val
		) {

	this->ref = ref;
	this->vlsIxMsdcVValuelist = vlsIxMsdcVValuelist;
	this->vlsNum = vlsNum;
	this->x1IxMsdcVLocale = x1IxMsdcVLocale;
	this->Val = Val;
};

bool MsdcAVValuelistVal::operator==(
			const MsdcAVValuelistVal& comp
		) {
	return false;
};

bool MsdcAVValuelistVal::operator!=(
			const MsdcAVValuelistVal& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListMsdcAVValuelistVal
 ******************************************************************************/

ListMsdcAVValuelistVal::ListMsdcAVValuelistVal() {
};

ListMsdcAVValuelistVal::ListMsdcAVValuelistVal(
			const ListMsdcAVValuelistVal& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new MsdcAVValuelistVal(*(src.nodes[i]));
};

ListMsdcAVValuelistVal::~ListMsdcAVValuelistVal() {
	clear();
};

void ListMsdcAVValuelistVal::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListMsdcAVValuelistVal::size() const {
	return(nodes.size());
};

void ListMsdcAVValuelistVal::append(
			MsdcAVValuelistVal* rec
		) {
	nodes.push_back(rec);
};

MsdcAVValuelistVal* ListMsdcAVValuelistVal::operator[](
			const uint ix
		) {
	MsdcAVValuelistVal* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListMsdcAVValuelistVal& ListMsdcAVValuelistVal::operator=(
			const ListMsdcAVValuelistVal& src
		) {
	MsdcAVValuelistVal* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new MsdcAVValuelistVal(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListMsdcAVValuelistVal::operator==(
			const ListMsdcAVValuelistVal& comp
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

bool ListMsdcAVValuelistVal::operator!=(
			const ListMsdcAVValuelistVal& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblMsdcAVValuelistVal
 ******************************************************************************/

TblMsdcAVValuelistVal::TblMsdcAVValuelistVal() {
};

TblMsdcAVValuelistVal::~TblMsdcAVValuelistVal() {
};

bool TblMsdcAVValuelistVal::loadRecBySQL(
			const string& sqlstr
			, MsdcAVValuelistVal** rec
		) {
	return false;
};

ubigint TblMsdcAVValuelistVal::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListMsdcAVValuelistVal& rst
		) {
	return 0;
};

void TblMsdcAVValuelistVal::insertRec(
			MsdcAVValuelistVal* rec
		) {
};

ubigint TblMsdcAVValuelistVal::insertNewRec(
			MsdcAVValuelistVal** rec
			, const uint vlsIxMsdcVValuelist
			, const uint vlsNum
			, const uint x1IxMsdcVLocale
			, const string Val
		) {
	ubigint retval = 0;
	MsdcAVValuelistVal* _rec = NULL;

	_rec = new MsdcAVValuelistVal(0, vlsIxMsdcVValuelist, vlsNum, x1IxMsdcVLocale, Val);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblMsdcAVValuelistVal::appendNewRecToRst(
			ListMsdcAVValuelistVal& rst
			, MsdcAVValuelistVal** rec
			, const uint vlsIxMsdcVValuelist
			, const uint vlsNum
			, const uint x1IxMsdcVLocale
			, const string Val
		) {
	ubigint retval = 0;
	MsdcAVValuelistVal* _rec = NULL;

	retval = insertNewRec(&_rec, vlsIxMsdcVValuelist, vlsNum, x1IxMsdcVLocale, Val);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblMsdcAVValuelistVal::insertRst(
			ListMsdcAVValuelistVal& rst
			, bool transact
		) {
};

void TblMsdcAVValuelistVal::updateRec(
			MsdcAVValuelistVal* rec
		) {
};

void TblMsdcAVValuelistVal::updateRst(
			ListMsdcAVValuelistVal& rst
			, bool transact
		) {
};

void TblMsdcAVValuelistVal::removeRecByRef(
			ubigint ref
		) {
};

bool TblMsdcAVValuelistVal::loadRecByRef(
			ubigint ref
			, MsdcAVValuelistVal** rec
		) {
	return false;
};

ubigint TblMsdcAVValuelistVal::loadRstByVlsLcl(
			uint vlsIxMsdcVValuelist
			, uint x1IxMsdcVLocale
			, const bool append
			, ListMsdcAVValuelistVal& rst
		) {
	return 0;
};

ubigint TblMsdcAVValuelistVal::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListMsdcAVValuelistVal& rst
		) {
	ubigint numload = 0;
	MsdcAVValuelistVal* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

/******************************************************************************
 class LiteTblMsdcAVValuelistVal
 ******************************************************************************/

LiteTblMsdcAVValuelistVal::LiteTblMsdcAVValuelistVal() :
			TblMsdcAVValuelistVal()
			, LiteTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;

	stmtLoadRstByVlsLcl = NULL;
};

LiteTblMsdcAVValuelistVal::~LiteTblMsdcAVValuelistVal() {
	if (stmtInsertRec) sqlite3_finalize(stmtInsertRec);
	if (stmtUpdateRec) sqlite3_finalize(stmtUpdateRec);
	if (stmtRemoveRecByRef) sqlite3_finalize(stmtRemoveRecByRef);

	if (stmtLoadRstByVlsLcl) sqlite3_finalize(stmtLoadRstByVlsLcl);
};

void LiteTblMsdcAVValuelistVal::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblMsdcAVValuelistVal (vlsIxMsdcVValuelist, vlsNum, x1IxMsdcVLocale, Val) VALUES (?1,?2,?3,?4)");
	stmtUpdateRec = createStatement("UPDATE TblMsdcAVValuelistVal SET vlsIxMsdcVValuelist = ?1, vlsNum = ?2, x1IxMsdcVLocale = ?3, Val = ?4 WHERE ref = ?5");
	stmtRemoveRecByRef = createStatement("DELETE FROM TblMsdcAVValuelistVal WHERE ref = ?1");

	stmtLoadRecByRef = createStatement("SELECT ref, vlsIxMsdcVValuelist, vlsNum, x1IxMsdcVLocale, Val FROM TblMsdcAVValuelistVal WHERE ref = ?1");
	stmtLoadRstByVlsLcl = createStatement("SELECT ref, vlsIxMsdcVValuelist, vlsNum, x1IxMsdcVLocale, Val FROM TblMsdcAVValuelistVal WHERE vlsIxMsdcVValuelist = ?1 AND x1IxMsdcVLocale = ?2 ORDER BY vlsNum ASC");
};

bool LiteTblMsdcAVValuelistVal::loadRec(
			sqlite3_stmt* stmt
			, MsdcAVValuelistVal** rec
		) {
	int res;

	MsdcAVValuelistVal* _rec = NULL;
	bool retval = false;

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		_rec = new MsdcAVValuelistVal();

		_rec->ref = sqlite3_column_int64(stmt, 0);
		_rec->vlsIxMsdcVValuelist = sqlite3_column_int(stmt, 1);
		_rec->vlsNum = sqlite3_column_int(stmt, 2);
		_rec->x1IxMsdcVLocale = sqlite3_column_int(stmt, 3);
		_rec->Val.assign((const char*) sqlite3_column_text(stmt, 4));

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

ubigint LiteTblMsdcAVValuelistVal::loadRst(
			sqlite3_stmt* stmt
			, const bool append
			, ListMsdcAVValuelistVal& rst
		) {
	int res; ubigint numread = 0;

	MsdcAVValuelistVal* rec;

	if (!append) rst.clear();

	res = sqlite3_step(stmt);
	while (res == SQLITE_ROW) {
		rec = new MsdcAVValuelistVal();

		rec->ref = sqlite3_column_int64(stmt, 0);
		rec->vlsIxMsdcVValuelist = sqlite3_column_int(stmt, 1);
		rec->vlsNum = sqlite3_column_int(stmt, 2);
		rec->x1IxMsdcVLocale = sqlite3_column_int(stmt, 3);
		rec->Val.assign((const char*) sqlite3_column_text(stmt, 4));

		rst.nodes.push_back(rec);

		numread++;

		res = sqlite3_step(stmt);
	};

	return(numread);
};

bool LiteTblMsdcAVValuelistVal::loadRecByStmt(
			sqlite3_stmt* stmt
			, MsdcAVValuelistVal** rec
		) {
	bool retval = loadRec(stmt, rec);

	sqlite3_reset(stmt);

	return retval;
};

ubigint LiteTblMsdcAVValuelistVal::loadRstByStmt(
			sqlite3_stmt* stmt
			, const bool append
			, ListMsdcAVValuelistVal& rst
		) {
	ubigint retval = loadRst(stmt, append, rst);

	sqlite3_reset(stmt);

	return retval;
};

bool LiteTblMsdcAVValuelistVal::loadRecBySQL(
			const string& sqlstr
			, MsdcAVValuelistVal** rec
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

ubigint LiteTblMsdcAVValuelistVal::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListMsdcAVValuelistVal& rst
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

void LiteTblMsdcAVValuelistVal::insertRec(
			MsdcAVValuelistVal* rec
		) {
	sqlite3_bind_int(stmtInsertRec, 1, rec->vlsIxMsdcVValuelist);
	sqlite3_bind_int(stmtInsertRec, 2, rec->vlsNum);
	sqlite3_bind_int(stmtInsertRec, 3, rec->x1IxMsdcVLocale);
	sqlite3_bind_text(stmtInsertRec, 4, rec->Val.c_str(), rec->Val.length(), SQLITE_STATIC);

	if (sqlite3_step(stmtInsertRec) != SQLITE_DONE) throw DbsException("DbsException / SQLite: error executing statement! (TblMsdcAVValuelistVal / stmtInsertRec)\n");
	rec->ref = sqlite3_last_insert_rowid(dbs);

	sqlite3_reset(stmtInsertRec);
};

void LiteTblMsdcAVValuelistVal::insertRst(
			ListMsdcAVValuelistVal& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void LiteTblMsdcAVValuelistVal::updateRec(
			MsdcAVValuelistVal* rec
		) {
	sqlite3_bind_int(stmtUpdateRec, 1, rec->vlsIxMsdcVValuelist);
	sqlite3_bind_int(stmtUpdateRec, 2, rec->vlsNum);
	sqlite3_bind_int(stmtUpdateRec, 3, rec->x1IxMsdcVLocale);
	sqlite3_bind_text(stmtUpdateRec, 4, rec->Val.c_str(), rec->Val.length(), SQLITE_STATIC);
	sqlite3_bind_int64(stmtUpdateRec, 5, rec->ref);

	if (sqlite3_step(stmtUpdateRec) != SQLITE_DONE) throw DbsException("DbsException / SQLite: error executing statement! (TblMsdcAVValuelistVal / stmtUpdateRec)\n");

	sqlite3_reset(stmtUpdateRec);
};

void LiteTblMsdcAVValuelistVal::updateRst(
			ListMsdcAVValuelistVal& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void LiteTblMsdcAVValuelistVal::removeRecByRef(
			ubigint ref
		) {
	sqlite3_bind_int64(stmtRemoveRecByRef, 1, ref);

	if (sqlite3_step(stmtRemoveRecByRef) != SQLITE_DONE) throw DbsException("DbsException / SQLite: error executing statement! (TblMsdcAVValuelistVal / stmtRemoveRecByRef)\n");

	sqlite3_reset(stmtRemoveRecByRef);
};

bool LiteTblMsdcAVValuelistVal::loadRecByRef(
			ubigint ref
			, MsdcAVValuelistVal** rec
		) {
	sqlite3_bind_int64(stmtLoadRecByRef, 1, ref);

	return loadRecByStmt(stmtLoadRecByRef, rec);
};

ubigint LiteTblMsdcAVValuelistVal::loadRstByVlsLcl(
			uint vlsIxMsdcVValuelist
			, uint x1IxMsdcVLocale
			, const bool append
			, ListMsdcAVValuelistVal& rst
		) {
	sqlite3_bind_int(stmtLoadRstByVlsLcl, 1, vlsIxMsdcVValuelist);
	sqlite3_bind_int(stmtLoadRstByVlsLcl, 2, x1IxMsdcVLocale);

	return loadRstByStmt(stmtLoadRstByVlsLcl, append, rst);
};

