/**
  * \file MsdcQUsgMNUser.cpp
  * Dbs and XML wrapper for table TblMsdcQUsgMNUser (implementation)
  * \author Alexander Wirthmueller
  * \date created: 29 Aug 2018
  * \date modified: 29 Aug 2018
  */

#include "MsdcQUsgMNUser.h"

/******************************************************************************
 class MsdcQUsgMNUser
 ******************************************************************************/

MsdcQUsgMNUser::MsdcQUsgMNUser(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
			, const uint ixMsdcVUserlevel
			, const string srefIxMsdcVUserlevel
			, const string titIxMsdcVUserlevel
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->mref = mref;
	this->stubMref = stubMref;
	this->ref = ref;
	this->ixMsdcVUserlevel = ixMsdcVUserlevel;
	this->srefIxMsdcVUserlevel = srefIxMsdcVUserlevel;
	this->titIxMsdcVUserlevel = titIxMsdcVUserlevel;
};

void MsdcQUsgMNUser::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "MsdcQUsgMNUser";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "mref", stubMref);
		writeString(wr, "ulv", srefIxMsdcVUserlevel);
		writeString(wr, "ulv2", titIxMsdcVUserlevel);
	} else {
		writeString(wr, "stubMref", stubMref);
		writeString(wr, "srefIxMsdcVUserlevel", srefIxMsdcVUserlevel);
		writeString(wr, "titIxMsdcVUserlevel", titIxMsdcVUserlevel);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListMsdcQUsgMNUser
 ******************************************************************************/

ListMsdcQUsgMNUser::ListMsdcQUsgMNUser() {
};

ListMsdcQUsgMNUser::ListMsdcQUsgMNUser(
			const ListMsdcQUsgMNUser& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new MsdcQUsgMNUser(*(src.nodes[i]));
};

ListMsdcQUsgMNUser::~ListMsdcQUsgMNUser() {
	clear();
};

void ListMsdcQUsgMNUser::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListMsdcQUsgMNUser::size() const {
	return(nodes.size());
};

void ListMsdcQUsgMNUser::append(
			MsdcQUsgMNUser* rec
		) {
	nodes.push_back(rec);
};

ListMsdcQUsgMNUser& ListMsdcQUsgMNUser::operator=(
			const ListMsdcQUsgMNUser& src
		) {
	MsdcQUsgMNUser* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new MsdcQUsgMNUser(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListMsdcQUsgMNUser::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListMsdcQUsgMNUser";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblMsdcQUsgMNUser
 ******************************************************************************/

TblMsdcQUsgMNUser::TblMsdcQUsgMNUser() {
};

TblMsdcQUsgMNUser::~TblMsdcQUsgMNUser() {
};

bool TblMsdcQUsgMNUser::loadRecBySQL(
			const string& sqlstr
			, MsdcQUsgMNUser** rec
		) {
	return false;
};

ubigint TblMsdcQUsgMNUser::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListMsdcQUsgMNUser& rst
		) {
	return 0;
};

void TblMsdcQUsgMNUser::insertRec(
			MsdcQUsgMNUser* rec
		) {
};

ubigint TblMsdcQUsgMNUser::insertNewRec(
			MsdcQUsgMNUser** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
			, const uint ixMsdcVUserlevel
			, const string srefIxMsdcVUserlevel
			, const string titIxMsdcVUserlevel
		) {
	ubigint retval = 0;
	MsdcQUsgMNUser* _rec = NULL;

	_rec = new MsdcQUsgMNUser(0, jref, jnum, mref, stubMref, ref, ixMsdcVUserlevel, srefIxMsdcVUserlevel, titIxMsdcVUserlevel);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblMsdcQUsgMNUser::appendNewRecToRst(
			ListMsdcQUsgMNUser& rst
			, MsdcQUsgMNUser** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
			, const uint ixMsdcVUserlevel
			, const string srefIxMsdcVUserlevel
			, const string titIxMsdcVUserlevel
		) {
	ubigint retval = 0;
	MsdcQUsgMNUser* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, mref, stubMref, ref, ixMsdcVUserlevel, srefIxMsdcVUserlevel, titIxMsdcVUserlevel);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblMsdcQUsgMNUser::insertRst(
			ListMsdcQUsgMNUser& rst
		) {
};

void TblMsdcQUsgMNUser::updateRec(
			MsdcQUsgMNUser* rec
		) {
};

void TblMsdcQUsgMNUser::updateRst(
			ListMsdcQUsgMNUser& rst
		) {
};

void TblMsdcQUsgMNUser::removeRecByQref(
			ubigint qref
		) {
};

void TblMsdcQUsgMNUser::removeRstByJref(
			ubigint jref
		) {
};

bool TblMsdcQUsgMNUser::loadRecByQref(
			ubigint qref
			, MsdcQUsgMNUser** rec
		) {
	return false;
};

ubigint TblMsdcQUsgMNUser::loadRstByJref(
			ubigint jref
			, const bool append
			, ListMsdcQUsgMNUser& rst
		) {
	return 0;
};

/******************************************************************************
 class LiteTblMsdcQUsgMNUser
 ******************************************************************************/

LiteTblMsdcQUsgMNUser::LiteTblMsdcQUsgMNUser() :
			TblMsdcQUsgMNUser()
			, LiteTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;

	stmtLoadRecByQref = NULL;
	stmtLoadRecByJref = NULL;
	stmtLoadRstByJref = NULL;
};

LiteTblMsdcQUsgMNUser::~LiteTblMsdcQUsgMNUser() {
	if (stmtInsertRec) sqlite3_finalize(stmtInsertRec);
	if (stmtUpdateRec) sqlite3_finalize(stmtUpdateRec);
	if (stmtRemoveRecByQref) sqlite3_finalize(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) sqlite3_finalize(stmtRemoveRstByJref);

	if (stmtLoadRecByQref) sqlite3_finalize(stmtLoadRecByQref);
	if (stmtLoadRecByJref) sqlite3_finalize(stmtLoadRecByJref);
	if (stmtLoadRstByJref) sqlite3_finalize(stmtLoadRstByJref);
};

void LiteTblMsdcQUsgMNUser::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblMsdcQUsgMNUser (jref, jnum, mref, ref, ixMsdcVUserlevel) VALUES (?1,?2,?3,?4,?5)");
	stmtUpdateRec = createStatement("UPDATE TblMsdcQUsgMNUser SET jref = ?1, jnum = ?2, mref = ?3, ref = ?4, ixMsdcVUserlevel = ?5 WHERE qref = ?6");
	stmtRemoveRecByQref = createStatement("DELETE FROM TblMsdcQUsgMNUser WHERE qref = ?1");
	stmtRemoveRstByJref = createStatement("DELETE FROM TblMsdcQUsgMNUser WHERE jref = ?1");

	stmtLoadRecByQref = createStatement("SELECT qref, jref, jnum, mref, ref, ixMsdcVUserlevel FROM TblMsdcQUsgMNUser WHERE qref = ?1");
	stmtLoadRstByJref = createStatement("SELECT qref, jref, jnum, mref, ref, ixMsdcVUserlevel FROM TblMsdcQUsgMNUser WHERE jref = ?1 ORDER BY jnum ASC");
};

bool LiteTblMsdcQUsgMNUser::loadRec(
			sqlite3_stmt* stmt
			, MsdcQUsgMNUser** rec
		) {
	int res;

	MsdcQUsgMNUser* _rec = NULL;
	bool retval = false;

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		_rec = new MsdcQUsgMNUser();

		_rec->qref = sqlite3_column_int64(stmt, 0);
		_rec->jref = sqlite3_column_int64(stmt, 1);
		_rec->jnum = sqlite3_column_int(stmt, 2);
		_rec->mref = sqlite3_column_int64(stmt, 3);
		_rec->ref = sqlite3_column_int64(stmt, 4);
		_rec->ixMsdcVUserlevel = sqlite3_column_int(stmt, 5);

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

ubigint LiteTblMsdcQUsgMNUser::loadRst(
			sqlite3_stmt* stmt
			, const bool append
			, ListMsdcQUsgMNUser& rst
		) {
	int res; ubigint numread = 0;

	MsdcQUsgMNUser* rec;

	if (!append) rst.clear();

	res = sqlite3_step(stmt);
	while (res == SQLITE_ROW) {
		rec = new MsdcQUsgMNUser();

		rec->qref = sqlite3_column_int64(stmt, 0);
		rec->jref = sqlite3_column_int64(stmt, 1);
		rec->jnum = sqlite3_column_int(stmt, 2);
		rec->mref = sqlite3_column_int64(stmt, 3);
		rec->ref = sqlite3_column_int64(stmt, 4);
		rec->ixMsdcVUserlevel = sqlite3_column_int(stmt, 5);

		rst.nodes.push_back(rec);

		numread++;

		res = sqlite3_step(stmt);
	};

	return(numread);
};

bool LiteTblMsdcQUsgMNUser::loadRecByStmt(
			sqlite3_stmt* stmt
			, MsdcQUsgMNUser** rec
		) {
	bool retval = loadRec(stmt, rec);

	sqlite3_reset(stmt);

	return retval;
};

ubigint LiteTblMsdcQUsgMNUser::loadRstByStmt(
			sqlite3_stmt* stmt
			, const bool append
			, ListMsdcQUsgMNUser& rst
		) {
	ubigint retval = loadRst(stmt, append, rst);

	sqlite3_reset(stmt);

	return retval;
};

bool LiteTblMsdcQUsgMNUser::loadRecBySQL(
			const string& sqlstr
			, MsdcQUsgMNUser** rec
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

ubigint LiteTblMsdcQUsgMNUser::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListMsdcQUsgMNUser& rst
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

void LiteTblMsdcQUsgMNUser::insertRec(
			MsdcQUsgMNUser* rec
		) {
	sqlite3_bind_int64(stmtInsertRec, 1, rec->jref);
	sqlite3_bind_int(stmtInsertRec, 2, rec->jnum);
	sqlite3_bind_int64(stmtInsertRec, 3, rec->mref);
	sqlite3_bind_int64(stmtInsertRec, 4, rec->ref);
	sqlite3_bind_int(stmtInsertRec, 5, rec->ixMsdcVUserlevel);

	if (sqlite3_step(stmtInsertRec) != SQLITE_DONE) throw DbsException("DbsException / SQLite: error executing statement! (TblMsdcQUsgMNUser / stmtInsertRec)\n");

	rec->qref = sqlite3_last_insert_rowid(dbs);

	sqlite3_reset(stmtInsertRec);
};

void LiteTblMsdcQUsgMNUser::insertRst(
			ListMsdcQUsgMNUser& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void LiteTblMsdcQUsgMNUser::updateRec(
			MsdcQUsgMNUser* rec
		) {
	sqlite3_bind_int64(stmtUpdateRec, 1, rec->jref);
	sqlite3_bind_int(stmtUpdateRec, 2, rec->jnum);
	sqlite3_bind_int64(stmtUpdateRec, 3, rec->mref);
	sqlite3_bind_int64(stmtUpdateRec, 4, rec->ref);
	sqlite3_bind_int(stmtUpdateRec, 5, rec->ixMsdcVUserlevel);
	sqlite3_bind_int64(stmtUpdateRec, 6, rec->qref);

	if (sqlite3_step(stmtUpdateRec) != SQLITE_DONE) throw DbsException("DbsException / SQLite: error executing statement! (TblMsdcQUsgMNUser / stmtUpdateRec)\n");

	sqlite3_reset(stmtUpdateRec);
};

void LiteTblMsdcQUsgMNUser::updateRst(
			ListMsdcQUsgMNUser& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void LiteTblMsdcQUsgMNUser::removeRecByQref(
			ubigint qref
		) {
	sqlite3_bind_int64(stmtRemoveRecByQref, 1, qref);

	if (sqlite3_step(stmtRemoveRecByQref) != SQLITE_DONE) throw DbsException("DbsException / SQLite: error executing statement! (TblMsdcQUsgMNUser / stmtRemoveRecByQref)\n");

	sqlite3_reset(stmtRemoveRecByQref);
};

void LiteTblMsdcQUsgMNUser::removeRstByJref(
			ubigint jref
		) {
	sqlite3_bind_int64(stmtRemoveRstByJref, 1, jref);

	if (sqlite3_step(stmtRemoveRstByJref) != SQLITE_DONE) throw DbsException("DbsException / SQLite: error executing statement! (TblMsdcQUsgMNUser / stmtRemoveRstByJref)\n");

	sqlite3_reset(stmtRemoveRstByJref);
};

bool LiteTblMsdcQUsgMNUser::loadRecByQref(
			ubigint qref
			, MsdcQUsgMNUser** rec
		) {
	sqlite3_bind_int64(stmtLoadRecByQref, 1, qref);

	return loadRecByStmt(stmtLoadRecByQref, rec);
};

ubigint LiteTblMsdcQUsgMNUser::loadRstByJref(
			ubigint jref
			, const bool append
			, ListMsdcQUsgMNUser& rst
		) {
	sqlite3_bind_int64(stmtLoadRstByJref, 1, jref);

	return loadRstByStmt(stmtLoadRstByJref, append, rst);
};

