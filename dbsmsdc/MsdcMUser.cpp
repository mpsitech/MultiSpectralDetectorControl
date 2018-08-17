/**
  * \file MsdcMUser.cpp
  * database access for table TblMsdcMUser (implementation)
  * \author Alexander Wirthmueller
  * \date created: 15 Aug 2018
  * \date modified: 15 Aug 2018
  */

#include "MsdcMUser.h"

#include "MsdcMUser_vecs.cpp"

/******************************************************************************
 class MsdcMUser
 ******************************************************************************/

MsdcMUser::MsdcMUser(
			const ubigint ref
			, const ubigint grp
			, const ubigint own
			, const ubigint refRUsergroup
			, const ubigint refMsdcMUsergroup
			, const ubigint refMsdcMPerson
			, const string sref
			, const ubigint refJState
			, const uint ixVState
			, const uint ixMsdcVLocale
			, const uint ixMsdcVUserlevel
			, const string Password
			, const string Fullkey
			, const string Comment
		) {

	this->ref = ref;
	this->grp = grp;
	this->own = own;
	this->refRUsergroup = refRUsergroup;
	this->refMsdcMUsergroup = refMsdcMUsergroup;
	this->refMsdcMPerson = refMsdcMPerson;
	this->sref = sref;
	this->refJState = refJState;
	this->ixVState = ixVState;
	this->ixMsdcVLocale = ixMsdcVLocale;
	this->ixMsdcVUserlevel = ixMsdcVUserlevel;
	this->Password = Password;
	this->Fullkey = Fullkey;
	this->Comment = Comment;
};

bool MsdcMUser::operator==(
			const MsdcMUser& comp
		) {
	return false;
};

bool MsdcMUser::operator!=(
			const MsdcMUser& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListMsdcMUser
 ******************************************************************************/

ListMsdcMUser::ListMsdcMUser() {
};

ListMsdcMUser::ListMsdcMUser(
			const ListMsdcMUser& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new MsdcMUser(*(src.nodes[i]));
};

ListMsdcMUser::~ListMsdcMUser() {
	clear();
};

void ListMsdcMUser::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListMsdcMUser::size() const {
	return(nodes.size());
};

void ListMsdcMUser::append(
			MsdcMUser* rec
		) {
	nodes.push_back(rec);
};

MsdcMUser* ListMsdcMUser::operator[](
			const uint ix
		) {
	MsdcMUser* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListMsdcMUser& ListMsdcMUser::operator=(
			const ListMsdcMUser& src
		) {
	MsdcMUser* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new MsdcMUser(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListMsdcMUser::operator==(
			const ListMsdcMUser& comp
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

bool ListMsdcMUser::operator!=(
			const ListMsdcMUser& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblMsdcMUser
 ******************************************************************************/

TblMsdcMUser::TblMsdcMUser() {
};

TblMsdcMUser::~TblMsdcMUser() {
};

bool TblMsdcMUser::loadRecBySQL(
			const string& sqlstr
			, MsdcMUser** rec
		) {
	return false;
};

ubigint TblMsdcMUser::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListMsdcMUser& rst
		) {
	return 0;
};

void TblMsdcMUser::insertRec(
			MsdcMUser* rec
		) {
};

ubigint TblMsdcMUser::insertNewRec(
			MsdcMUser** rec
			, const ubigint grp
			, const ubigint own
			, const ubigint refRUsergroup
			, const ubigint refMsdcMUsergroup
			, const ubigint refMsdcMPerson
			, const string sref
			, const ubigint refJState
			, const uint ixVState
			, const uint ixMsdcVLocale
			, const uint ixMsdcVUserlevel
			, const string Password
			, const string Fullkey
			, const string Comment
		) {
	ubigint retval = 0;
	MsdcMUser* _rec = NULL;

	_rec = new MsdcMUser(0, grp, own, refRUsergroup, refMsdcMUsergroup, refMsdcMPerson, sref, refJState, ixVState, ixMsdcVLocale, ixMsdcVUserlevel, Password, Fullkey, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblMsdcMUser::appendNewRecToRst(
			ListMsdcMUser& rst
			, MsdcMUser** rec
			, const ubigint grp
			, const ubigint own
			, const ubigint refRUsergroup
			, const ubigint refMsdcMUsergroup
			, const ubigint refMsdcMPerson
			, const string sref
			, const ubigint refJState
			, const uint ixVState
			, const uint ixMsdcVLocale
			, const uint ixMsdcVUserlevel
			, const string Password
			, const string Fullkey
			, const string Comment
		) {
	ubigint retval = 0;
	MsdcMUser* _rec = NULL;

	retval = insertNewRec(&_rec, grp, own, refRUsergroup, refMsdcMUsergroup, refMsdcMPerson, sref, refJState, ixVState, ixMsdcVLocale, ixMsdcVUserlevel, Password, Fullkey, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblMsdcMUser::insertRst(
			ListMsdcMUser& rst
			, bool transact
		) {
};

void TblMsdcMUser::updateRec(
			MsdcMUser* rec
		) {
};

void TblMsdcMUser::updateRst(
			ListMsdcMUser& rst
			, bool transact
		) {
};

void TblMsdcMUser::removeRecByRef(
			ubigint ref
		) {
};

bool TblMsdcMUser::loadRecByRef(
			ubigint ref
			, MsdcMUser** rec
		) {
	return false;
};

bool TblMsdcMUser::loadRecByPrs(
			ubigint refMsdcMPerson
			, MsdcMUser** rec
		) {
	return false;
};

bool TblMsdcMUser::loadRecBySrf(
			string sref
			, MsdcMUser** rec
		) {
	return false;
};

bool TblMsdcMUser::loadRefByPrs(
			ubigint refMsdcMPerson
			, ubigint& ref
		) {
	return false;
};

bool TblMsdcMUser::loadRefBySrf(
			string sref
			, ubigint& ref
		) {
	return false;
};

bool TblMsdcMUser::loadRefBySrfPwd(
			string sref
			, string Password
			, ubigint& ref
		) {
	return false;
};

ubigint TblMsdcMUser::loadRefsByUsg(
			ubigint refMsdcMUsergroup
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

bool TblMsdcMUser::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return false;
};

ubigint TblMsdcMUser::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListMsdcMUser& rst
		) {
	ubigint numload = 0;
	MsdcMUser* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

/******************************************************************************
 class LiteTblMsdcMUser
 ******************************************************************************/

LiteTblMsdcMUser::LiteTblMsdcMUser() : TblMsdcMUser(), LiteTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;

	stmtLoadRecByPrs = NULL;
	stmtLoadRecBySrf = NULL;
	stmtLoadRefByPrs = NULL;
	stmtLoadRefBySrf = NULL;
	stmtLoadRefBySrfPwd = NULL;
	stmtLoadRefsByUsg = NULL;
	stmtLoadSrfByRef = NULL;
};

LiteTblMsdcMUser::~LiteTblMsdcMUser() {
	if (stmtInsertRec) sqlite3_finalize(stmtInsertRec);
	if (stmtUpdateRec) sqlite3_finalize(stmtUpdateRec);
	if (stmtRemoveRecByRef) sqlite3_finalize(stmtRemoveRecByRef);

	if (stmtLoadRecByPrs) sqlite3_finalize(stmtLoadRecByPrs);
	if (stmtLoadRecBySrf) sqlite3_finalize(stmtLoadRecBySrf);
	if (stmtLoadRefByPrs) sqlite3_finalize(stmtLoadRefByPrs);
	if (stmtLoadRefBySrf) sqlite3_finalize(stmtLoadRefBySrf);
	if (stmtLoadRefBySrfPwd) sqlite3_finalize(stmtLoadRefBySrfPwd);
	if (stmtLoadRefsByUsg) sqlite3_finalize(stmtLoadRefsByUsg);
	if (stmtLoadSrfByRef) sqlite3_finalize(stmtLoadSrfByRef);
};

void LiteTblMsdcMUser::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblMsdcMUser (grp, own, refRUsergroup, refMsdcMUsergroup, refMsdcMPerson, sref, refJState, ixVState, ixMsdcVLocale, ixMsdcVUserlevel, Password, Fullkey, Comment) VALUES (?1,?2,?3,?4,?5,?6,?7,?8,?9,?10,?11,?12,?13)");
	stmtUpdateRec = createStatement("UPDATE TblMsdcMUser SET grp = ?1, own = ?2, refRUsergroup = ?3, refMsdcMUsergroup = ?4, refMsdcMPerson = ?5, sref = ?6, refJState = ?7, ixVState = ?8, ixMsdcVLocale = ?9, ixMsdcVUserlevel = ?10, Password = ?11, Fullkey = ?12, Comment = ?13 WHERE ref = ?14");
	stmtRemoveRecByRef = createStatement("DELETE FROM TblMsdcMUser WHERE ref = ?1");

	stmtLoadRecByRef = createStatement("SELECT ref, grp, own, refRUsergroup, refMsdcMUsergroup, refMsdcMPerson, sref, refJState, ixVState, ixMsdcVLocale, ixMsdcVUserlevel, Password, Fullkey, Comment FROM TblMsdcMUser WHERE ref = ?1");
	stmtLoadRecByPrs = createStatement("SELECT ref, grp, own, refRUsergroup, refMsdcMUsergroup, refMsdcMPerson, sref, refJState, ixVState, ixMsdcVLocale, ixMsdcVUserlevel, Password, Fullkey, Comment FROM TblMsdcMUser WHERE refMsdcMPerson = ?1");
	stmtLoadRecBySrf = createStatement("SELECT ref, grp, own, refRUsergroup, refMsdcMUsergroup, refMsdcMPerson, sref, refJState, ixVState, ixMsdcVLocale, ixMsdcVUserlevel, Password, Fullkey, Comment FROM TblMsdcMUser WHERE sref = ?1");
	stmtLoadRefByPrs = createStatement("SELECT ref FROM TblMsdcMUser WHERE refMsdcMPerson = ?1");
	stmtLoadRefBySrf = createStatement("SELECT ref FROM TblMsdcMUser WHERE sref = ?1");
	stmtLoadRefBySrfPwd = createStatement("SELECT ref FROM TblMsdcMUser WHERE sref = ?1 AND Password = ?2");
	stmtLoadRefsByUsg = createStatement("SELECT ref FROM TblMsdcMUser WHERE refMsdcMUsergroup = ?1");
	stmtLoadSrfByRef = createStatement("SELECT sref FROM TblMsdcMUser WHERE ref = ?1");
};

bool LiteTblMsdcMUser::loadRec(
			sqlite3_stmt* stmt
			, MsdcMUser** rec
		) {
	int res;

	MsdcMUser* _rec = NULL;
	bool retval = false;

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		_rec = new MsdcMUser();

		_rec->ref = sqlite3_column_int64(stmt, 0);
		_rec->grp = sqlite3_column_int64(stmt, 1);
		_rec->own = sqlite3_column_int64(stmt, 2);
		_rec->refRUsergroup = sqlite3_column_int64(stmt, 3);
		_rec->refMsdcMUsergroup = sqlite3_column_int64(stmt, 4);
		_rec->refMsdcMPerson = sqlite3_column_int64(stmt, 5);
		_rec->sref.assign((const char*) sqlite3_column_text(stmt, 6));
		_rec->refJState = sqlite3_column_int64(stmt, 7);
		_rec->ixVState = sqlite3_column_int(stmt, 8);
		_rec->ixMsdcVLocale = sqlite3_column_int(stmt, 9);
		_rec->ixMsdcVUserlevel = sqlite3_column_int(stmt, 10);
		_rec->Password.assign((const char*) sqlite3_column_text(stmt, 11));
		_rec->Fullkey.assign((const char*) sqlite3_column_text(stmt, 12));
		_rec->Comment.assign((const char*) sqlite3_column_text(stmt, 13));

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

ubigint LiteTblMsdcMUser::loadRst(
			sqlite3_stmt* stmt
			, const bool append
			, ListMsdcMUser& rst
		) {
	int res; ubigint numread = 0;

	MsdcMUser* rec;

	if (!append) rst.clear();

	res = sqlite3_step(stmt);
	while (res == SQLITE_ROW) {
		rec = new MsdcMUser();

		rec->ref = sqlite3_column_int64(stmt, 0);
		rec->grp = sqlite3_column_int64(stmt, 1);
		rec->own = sqlite3_column_int64(stmt, 2);
		rec->refRUsergroup = sqlite3_column_int64(stmt, 3);
		rec->refMsdcMUsergroup = sqlite3_column_int64(stmt, 4);
		rec->refMsdcMPerson = sqlite3_column_int64(stmt, 5);
		rec->sref.assign((const char*) sqlite3_column_text(stmt, 6));
		rec->refJState = sqlite3_column_int64(stmt, 7);
		rec->ixVState = sqlite3_column_int(stmt, 8);
		rec->ixMsdcVLocale = sqlite3_column_int(stmt, 9);
		rec->ixMsdcVUserlevel = sqlite3_column_int(stmt, 10);
		rec->Password.assign((const char*) sqlite3_column_text(stmt, 11));
		rec->Fullkey.assign((const char*) sqlite3_column_text(stmt, 12));
		rec->Comment.assign((const char*) sqlite3_column_text(stmt, 13));

		rst.nodes.push_back(rec);

		numread++;

		res = sqlite3_step(stmt);
	};

	return(numread);
};

bool LiteTblMsdcMUser::loadRecByStmt(
			sqlite3_stmt* stmt
			, MsdcMUser** rec
		) {
	bool retval = loadRec(stmt, rec);

	sqlite3_reset(stmt);

	return retval;
};

bool LiteTblMsdcMUser::loadRecBySQL(
			const string& sqlstr
			, MsdcMUser** rec
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

ubigint LiteTblMsdcMUser::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListMsdcMUser& rst
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

void LiteTblMsdcMUser::insertRec(
			MsdcMUser* rec
		) {
	sqlite3_bind_int64(stmtInsertRec, 1, rec->grp);
	sqlite3_bind_int64(stmtInsertRec, 2, rec->own);
	sqlite3_bind_int64(stmtInsertRec, 3, rec->refRUsergroup);
	sqlite3_bind_int64(stmtInsertRec, 4, rec->refMsdcMUsergroup);
	sqlite3_bind_int64(stmtInsertRec, 5, rec->refMsdcMPerson);
	sqlite3_bind_text(stmtInsertRec, 6, rec->sref.c_str(), rec->sref.length(), SQLITE_STATIC);
	sqlite3_bind_int64(stmtInsertRec, 7, rec->refJState);
	sqlite3_bind_int(stmtInsertRec, 8, rec->ixVState);
	sqlite3_bind_int(stmtInsertRec, 9, rec->ixMsdcVLocale);
	sqlite3_bind_int(stmtInsertRec, 10, rec->ixMsdcVUserlevel);
	sqlite3_bind_text(stmtInsertRec, 11, rec->Password.c_str(), rec->Password.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtInsertRec, 12, rec->Fullkey.c_str(), rec->Fullkey.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtInsertRec, 13, rec->Comment.c_str(), rec->Comment.length(), SQLITE_STATIC);

	if (sqlite3_step(stmtInsertRec) != SQLITE_DONE) throw DbsException("DbsException / SQLite: error executing statement! (TblMsdcMUser / stmtInsertRec)\n");
	rec->ref = sqlite3_last_insert_rowid(dbs);

	sqlite3_reset(stmtInsertRec);
};

void LiteTblMsdcMUser::insertRst(
			ListMsdcMUser& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void LiteTblMsdcMUser::updateRec(
			MsdcMUser* rec
		) {
	sqlite3_bind_int64(stmtUpdateRec, 1, rec->grp);
	sqlite3_bind_int64(stmtUpdateRec, 2, rec->own);
	sqlite3_bind_int64(stmtUpdateRec, 3, rec->refRUsergroup);
	sqlite3_bind_int64(stmtUpdateRec, 4, rec->refMsdcMUsergroup);
	sqlite3_bind_int64(stmtUpdateRec, 5, rec->refMsdcMPerson);
	sqlite3_bind_text(stmtUpdateRec, 6, rec->sref.c_str(), rec->sref.length(), SQLITE_STATIC);
	sqlite3_bind_int64(stmtUpdateRec, 7, rec->refJState);
	sqlite3_bind_int(stmtUpdateRec, 8, rec->ixVState);
	sqlite3_bind_int(stmtUpdateRec, 9, rec->ixMsdcVLocale);
	sqlite3_bind_int(stmtUpdateRec, 10, rec->ixMsdcVUserlevel);
	sqlite3_bind_text(stmtUpdateRec, 11, rec->Password.c_str(), rec->Password.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtUpdateRec, 12, rec->Fullkey.c_str(), rec->Fullkey.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtUpdateRec, 13, rec->Comment.c_str(), rec->Comment.length(), SQLITE_STATIC);
	sqlite3_bind_int64(stmtUpdateRec, 14, rec->ref);

	if (sqlite3_step(stmtUpdateRec) != SQLITE_DONE) throw DbsException("DbsException / SQLite: error executing statement! (TblMsdcMUser / stmtUpdateRec)\n");

	sqlite3_reset(stmtUpdateRec);
};

void LiteTblMsdcMUser::updateRst(
			ListMsdcMUser& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void LiteTblMsdcMUser::removeRecByRef(
			ubigint ref
		) {
	sqlite3_bind_int64(stmtRemoveRecByRef, 1, ref);

	if (sqlite3_step(stmtRemoveRecByRef) != SQLITE_DONE) throw DbsException("DbsException / SQLite: error executing statement! (TblMsdcMUser / stmtRemoveRecByRef)\n");

	sqlite3_reset(stmtRemoveRecByRef);
};

bool LiteTblMsdcMUser::loadRecByRef(
			ubigint ref
			, MsdcMUser** rec
		) {
	sqlite3_bind_int64(stmtLoadRecByRef, 1, ref);

	return loadRecByStmt(stmtLoadRecByRef, rec);
};

bool LiteTblMsdcMUser::loadRecByPrs(
			ubigint refMsdcMPerson
			, MsdcMUser** rec
		) {
	sqlite3_bind_int64(stmtLoadRecByPrs, 1, refMsdcMPerson);

	return loadRecByStmt(stmtLoadRecByPrs, rec);
};

bool LiteTblMsdcMUser::loadRecBySrf(
			string sref
			, MsdcMUser** rec
		) {
	sqlite3_bind_text(stmtLoadRecBySrf, 1, sref.c_str(), sref.length(), SQLITE_STATIC);

	return loadRecByStmt(stmtLoadRecBySrf, rec);
};

bool LiteTblMsdcMUser::loadRefByPrs(
			ubigint refMsdcMPerson
			, ubigint& ref
		) {
	sqlite3_bind_int64(stmtLoadRefByPrs, 1, refMsdcMPerson);

	return loadRefByStmt(stmtLoadRefByPrs, ref);
};

bool LiteTblMsdcMUser::loadRefBySrf(
			string sref
			, ubigint& ref
		) {
	sqlite3_bind_text(stmtLoadRefBySrf, 1, sref.c_str(), sref.length(), SQLITE_STATIC);

	return loadRefByStmt(stmtLoadRefBySrf, ref);
};

bool LiteTblMsdcMUser::loadRefBySrfPwd(
			string sref
			, string Password
			, ubigint& ref
		) {
	sqlite3_bind_text(stmtLoadRefBySrfPwd, 1, sref.c_str(), sref.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtLoadRefBySrfPwd, 2, Password.c_str(), Password.length(), SQLITE_STATIC);

	return loadRefByStmt(stmtLoadRefBySrfPwd, ref);
};

ubigint LiteTblMsdcMUser::loadRefsByUsg(
			ubigint refMsdcMUsergroup
			, const bool append
			, vector<ubigint>& refs
		) {
	sqlite3_bind_int64(stmtLoadRefsByUsg, 1, refMsdcMUsergroup);

	return loadRefsByStmt(stmtLoadRefsByUsg, append, refs);
};

bool LiteTblMsdcMUser::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	sqlite3_bind_int64(stmtLoadSrfByRef, 1, ref);

	return loadStringByStmt(stmtLoadSrfByRef, sref);
};

