/**
  * \file MsdcAVControlPar.cpp
  * database access for table TblMsdcAVControlPar (implementation)
  * \author Alexander Wirthmueller
  * \date created: 18 Dec 2018
  * \date modified: 18 Dec 2018
  */

#include "MsdcAVControlPar.h"

/******************************************************************************
 class MsdcAVControlPar
 ******************************************************************************/

MsdcAVControlPar::MsdcAVControlPar(
			const ubigint ref
			, const uint ixMsdcVControl
			, const ubigint x1RefMsdcMUser
			, const uint x2IxMsdcVLocale
			, const string Par
			, const string Val
		) {

	this->ref = ref;
	this->ixMsdcVControl = ixMsdcVControl;
	this->x1RefMsdcMUser = x1RefMsdcMUser;
	this->x2IxMsdcVLocale = x2IxMsdcVLocale;
	this->Par = Par;
	this->Val = Val;
};

bool MsdcAVControlPar::operator==(
			const MsdcAVControlPar& comp
		) {
	return false;
};

bool MsdcAVControlPar::operator!=(
			const MsdcAVControlPar& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListMsdcAVControlPar
 ******************************************************************************/

ListMsdcAVControlPar::ListMsdcAVControlPar() {
};

ListMsdcAVControlPar::ListMsdcAVControlPar(
			const ListMsdcAVControlPar& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new MsdcAVControlPar(*(src.nodes[i]));
};

ListMsdcAVControlPar::~ListMsdcAVControlPar() {
	clear();
};

void ListMsdcAVControlPar::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListMsdcAVControlPar::size() const {
	return(nodes.size());
};

void ListMsdcAVControlPar::append(
			MsdcAVControlPar* rec
		) {
	nodes.push_back(rec);
};

MsdcAVControlPar* ListMsdcAVControlPar::operator[](
			const uint ix
		) {
	MsdcAVControlPar* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListMsdcAVControlPar& ListMsdcAVControlPar::operator=(
			const ListMsdcAVControlPar& src
		) {
	MsdcAVControlPar* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new MsdcAVControlPar(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListMsdcAVControlPar::operator==(
			const ListMsdcAVControlPar& comp
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

bool ListMsdcAVControlPar::operator!=(
			const ListMsdcAVControlPar& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblMsdcAVControlPar
 ******************************************************************************/

TblMsdcAVControlPar::TblMsdcAVControlPar() {
};

TblMsdcAVControlPar::~TblMsdcAVControlPar() {
};

bool TblMsdcAVControlPar::loadRecBySQL(
			const string& sqlstr
			, MsdcAVControlPar** rec
		) {
	return false;
};

ubigint TblMsdcAVControlPar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListMsdcAVControlPar& rst
		) {
	return 0;
};

void TblMsdcAVControlPar::insertRec(
			MsdcAVControlPar* rec
		) {
};

ubigint TblMsdcAVControlPar::insertNewRec(
			MsdcAVControlPar** rec
			, const uint ixMsdcVControl
			, const ubigint x1RefMsdcMUser
			, const uint x2IxMsdcVLocale
			, const string Par
			, const string Val
		) {
	ubigint retval = 0;
	MsdcAVControlPar* _rec = NULL;

	_rec = new MsdcAVControlPar(0, ixMsdcVControl, x1RefMsdcMUser, x2IxMsdcVLocale, Par, Val);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblMsdcAVControlPar::appendNewRecToRst(
			ListMsdcAVControlPar& rst
			, MsdcAVControlPar** rec
			, const uint ixMsdcVControl
			, const ubigint x1RefMsdcMUser
			, const uint x2IxMsdcVLocale
			, const string Par
			, const string Val
		) {
	ubigint retval = 0;
	MsdcAVControlPar* _rec = NULL;

	retval = insertNewRec(&_rec, ixMsdcVControl, x1RefMsdcMUser, x2IxMsdcVLocale, Par, Val);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblMsdcAVControlPar::insertRst(
			ListMsdcAVControlPar& rst
			, bool transact
		) {
};

void TblMsdcAVControlPar::updateRec(
			MsdcAVControlPar* rec
		) {
};

void TblMsdcAVControlPar::updateRst(
			ListMsdcAVControlPar& rst
			, bool transact
		) {
};

void TblMsdcAVControlPar::removeRecByRef(
			ubigint ref
		) {
};

bool TblMsdcAVControlPar::loadRecByRef(
			ubigint ref
			, MsdcAVControlPar** rec
		) {
	return false;
};

bool TblMsdcAVControlPar::loadRefByCtlUsrPar(
			uint ixMsdcVControl
			, ubigint x1RefMsdcMUser
			, string Par
			, ubigint& ref
		) {
	return false;
};

bool TblMsdcAVControlPar::loadValByCtlUsrPar(
			uint ixMsdcVControl
			, ubigint x1RefMsdcMUser
			, string Par
			, string& Val
		) {
	return false;
};

ubigint TblMsdcAVControlPar::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListMsdcAVControlPar& rst
		) {
	ubigint numload = 0;
	MsdcAVControlPar* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

/******************************************************************************
 class LiteTblMsdcAVControlPar
 ******************************************************************************/

LiteTblMsdcAVControlPar::LiteTblMsdcAVControlPar() :
			TblMsdcAVControlPar()
			, LiteTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;

	stmtLoadRefByCtlUsrPar = NULL;
	stmtLoadValByCtlUsrPar = NULL;
};

LiteTblMsdcAVControlPar::~LiteTblMsdcAVControlPar() {
	if (stmtInsertRec) sqlite3_finalize(stmtInsertRec);
	if (stmtUpdateRec) sqlite3_finalize(stmtUpdateRec);
	if (stmtRemoveRecByRef) sqlite3_finalize(stmtRemoveRecByRef);

	if (stmtLoadRefByCtlUsrPar) sqlite3_finalize(stmtLoadRefByCtlUsrPar);
	if (stmtLoadValByCtlUsrPar) sqlite3_finalize(stmtLoadValByCtlUsrPar);
};

void LiteTblMsdcAVControlPar::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblMsdcAVControlPar (ixMsdcVControl, x1RefMsdcMUser, x2IxMsdcVLocale, Par, Val) VALUES (?1,?2,?3,?4,?5)");
	stmtUpdateRec = createStatement("UPDATE TblMsdcAVControlPar SET ixMsdcVControl = ?1, x1RefMsdcMUser = ?2, x2IxMsdcVLocale = ?3, Par = ?4, Val = ?5 WHERE ref = ?6");
	stmtRemoveRecByRef = createStatement("DELETE FROM TblMsdcAVControlPar WHERE ref = ?1");

	stmtLoadRecByRef = createStatement("SELECT ref, ixMsdcVControl, x1RefMsdcMUser, x2IxMsdcVLocale, Par, Val FROM TblMsdcAVControlPar WHERE ref = ?1");
	stmtLoadRefByCtlUsrPar = createStatement("SELECT ref FROM TblMsdcAVControlPar WHERE ixMsdcVControl = ?1 AND x1RefMsdcMUser = ?2 AND Par = ?3");
	stmtLoadValByCtlUsrPar = createStatement("SELECT Val FROM TblMsdcAVControlPar WHERE ixMsdcVControl = ?1 AND x1RefMsdcMUser = ?2 AND Par = ?3");
};

bool LiteTblMsdcAVControlPar::loadRec(
			sqlite3_stmt* stmt
			, MsdcAVControlPar** rec
		) {
	int res;

	MsdcAVControlPar* _rec = NULL;
	bool retval = false;

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		_rec = new MsdcAVControlPar();

		_rec->ref = sqlite3_column_int64(stmt, 0);
		_rec->ixMsdcVControl = sqlite3_column_int(stmt, 1);
		_rec->x1RefMsdcMUser = sqlite3_column_int64(stmt, 2);
		_rec->x2IxMsdcVLocale = sqlite3_column_int(stmt, 3);
		_rec->Par.assign((const char*) sqlite3_column_text(stmt, 4));
		_rec->Val.assign((const char*) sqlite3_column_text(stmt, 5));

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

ubigint LiteTblMsdcAVControlPar::loadRst(
			sqlite3_stmt* stmt
			, const bool append
			, ListMsdcAVControlPar& rst
		) {
	int res; ubigint numread = 0;

	MsdcAVControlPar* rec;

	if (!append) rst.clear();

	res = sqlite3_step(stmt);
	while (res == SQLITE_ROW) {
		rec = new MsdcAVControlPar();

		rec->ref = sqlite3_column_int64(stmt, 0);
		rec->ixMsdcVControl = sqlite3_column_int(stmt, 1);
		rec->x1RefMsdcMUser = sqlite3_column_int64(stmt, 2);
		rec->x2IxMsdcVLocale = sqlite3_column_int(stmt, 3);
		rec->Par.assign((const char*) sqlite3_column_text(stmt, 4));
		rec->Val.assign((const char*) sqlite3_column_text(stmt, 5));

		rst.nodes.push_back(rec);

		numread++;

		res = sqlite3_step(stmt);
	};

	return(numread);
};

bool LiteTblMsdcAVControlPar::loadRecByStmt(
			sqlite3_stmt* stmt
			, MsdcAVControlPar** rec
		) {
	bool retval = loadRec(stmt, rec);

	sqlite3_reset(stmt);

	return retval;
};

bool LiteTblMsdcAVControlPar::loadRecBySQL(
			const string& sqlstr
			, MsdcAVControlPar** rec
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

ubigint LiteTblMsdcAVControlPar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListMsdcAVControlPar& rst
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

void LiteTblMsdcAVControlPar::insertRec(
			MsdcAVControlPar* rec
		) {
	sqlite3_bind_int(stmtInsertRec, 1, rec->ixMsdcVControl);
	sqlite3_bind_int64(stmtInsertRec, 2, rec->x1RefMsdcMUser);
	sqlite3_bind_int(stmtInsertRec, 3, rec->x2IxMsdcVLocale);
	sqlite3_bind_text(stmtInsertRec, 4, rec->Par.c_str(), rec->Par.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtInsertRec, 5, rec->Val.c_str(), rec->Val.length(), SQLITE_STATIC);

	if (sqlite3_step(stmtInsertRec) != SQLITE_DONE) throw DbsException("DbsException / SQLite: error executing statement! (TblMsdcAVControlPar / stmtInsertRec)\n");
	rec->ref = sqlite3_last_insert_rowid(dbs);

	sqlite3_reset(stmtInsertRec);
};

void LiteTblMsdcAVControlPar::insertRst(
			ListMsdcAVControlPar& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void LiteTblMsdcAVControlPar::updateRec(
			MsdcAVControlPar* rec
		) {
	sqlite3_bind_int(stmtUpdateRec, 1, rec->ixMsdcVControl);
	sqlite3_bind_int64(stmtUpdateRec, 2, rec->x1RefMsdcMUser);
	sqlite3_bind_int(stmtUpdateRec, 3, rec->x2IxMsdcVLocale);
	sqlite3_bind_text(stmtUpdateRec, 4, rec->Par.c_str(), rec->Par.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtUpdateRec, 5, rec->Val.c_str(), rec->Val.length(), SQLITE_STATIC);
	sqlite3_bind_int64(stmtUpdateRec, 6, rec->ref);

	if (sqlite3_step(stmtUpdateRec) != SQLITE_DONE) throw DbsException("DbsException / SQLite: error executing statement! (TblMsdcAVControlPar / stmtUpdateRec)\n");

	sqlite3_reset(stmtUpdateRec);
};

void LiteTblMsdcAVControlPar::updateRst(
			ListMsdcAVControlPar& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void LiteTblMsdcAVControlPar::removeRecByRef(
			ubigint ref
		) {
	sqlite3_bind_int64(stmtRemoveRecByRef, 1, ref);

	if (sqlite3_step(stmtRemoveRecByRef) != SQLITE_DONE) throw DbsException("DbsException / SQLite: error executing statement! (TblMsdcAVControlPar / stmtRemoveRecByRef)\n");

	sqlite3_reset(stmtRemoveRecByRef);
};

bool LiteTblMsdcAVControlPar::loadRecByRef(
			ubigint ref
			, MsdcAVControlPar** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	sqlite3_bind_int64(stmtLoadRecByRef, 1, ref);

	return loadRecByStmt(stmtLoadRecByRef, rec);
};

bool LiteTblMsdcAVControlPar::loadRefByCtlUsrPar(
			uint ixMsdcVControl
			, ubigint x1RefMsdcMUser
			, string Par
			, ubigint& ref
		) {
	sqlite3_bind_int(stmtLoadRefByCtlUsrPar, 1, ixMsdcVControl);
	sqlite3_bind_int64(stmtLoadRefByCtlUsrPar, 2, x1RefMsdcMUser);
	sqlite3_bind_text(stmtLoadRefByCtlUsrPar, 3, Par.c_str(), Par.length(), SQLITE_STATIC);

	return loadRefByStmt(stmtLoadRefByCtlUsrPar, ref);
};

bool LiteTblMsdcAVControlPar::loadValByCtlUsrPar(
			uint ixMsdcVControl
			, ubigint x1RefMsdcMUser
			, string Par
			, string& Val
		) {
	sqlite3_bind_int(stmtLoadValByCtlUsrPar, 1, ixMsdcVControl);
	sqlite3_bind_int64(stmtLoadValByCtlUsrPar, 2, x1RefMsdcMUser);
	sqlite3_bind_text(stmtLoadValByCtlUsrPar, 3, Par.c_str(), Par.length(), SQLITE_STATIC);

	return loadStringByStmt(stmtLoadValByCtlUsrPar, Val);
};

