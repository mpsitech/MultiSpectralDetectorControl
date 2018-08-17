/**
  * \file MsdcQUsgList.cpp
  * Dbs and XML wrapper for table TblMsdcQUsgList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 15 Aug 2018
  * \date modified: 15 Aug 2018
  */

#include "MsdcQUsgList.h"

/******************************************************************************
 class MsdcQUsgList
 ******************************************************************************/

MsdcQUsgList::MsdcQUsgList(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->sref = sref;
};

void MsdcQUsgList::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "MsdcQUsgList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "srf", sref);
	} else {
		writeString(wr, "sref", sref);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListMsdcQUsgList
 ******************************************************************************/

ListMsdcQUsgList::ListMsdcQUsgList() {
};

ListMsdcQUsgList::ListMsdcQUsgList(
			const ListMsdcQUsgList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new MsdcQUsgList(*(src.nodes[i]));
};

ListMsdcQUsgList::~ListMsdcQUsgList() {
	clear();
};

void ListMsdcQUsgList::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListMsdcQUsgList::size() const {
	return(nodes.size());
};

void ListMsdcQUsgList::append(
			MsdcQUsgList* rec
		) {
	nodes.push_back(rec);
};

ListMsdcQUsgList& ListMsdcQUsgList::operator=(
			const ListMsdcQUsgList& src
		) {
	MsdcQUsgList* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new MsdcQUsgList(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListMsdcQUsgList::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListMsdcQUsgList";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblMsdcQUsgList
 ******************************************************************************/

TblMsdcQUsgList::TblMsdcQUsgList() {
};

TblMsdcQUsgList::~TblMsdcQUsgList() {
};

bool TblMsdcQUsgList::loadRecBySQL(
			const string& sqlstr
			, MsdcQUsgList** rec
		) {
	return false;
};

ubigint TblMsdcQUsgList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListMsdcQUsgList& rst
		) {
	return 0;
};

void TblMsdcQUsgList::insertRec(
			MsdcQUsgList* rec
		) {
};

ubigint TblMsdcQUsgList::insertNewRec(
			MsdcQUsgList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
		) {
	ubigint retval = 0;
	MsdcQUsgList* _rec = NULL;

	_rec = new MsdcQUsgList(0, jref, jnum, ref, sref);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblMsdcQUsgList::appendNewRecToRst(
			ListMsdcQUsgList& rst
			, MsdcQUsgList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
		) {
	ubigint retval = 0;
	MsdcQUsgList* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, sref);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblMsdcQUsgList::insertRst(
			ListMsdcQUsgList& rst
		) {
};

void TblMsdcQUsgList::updateRec(
			MsdcQUsgList* rec
		) {
};

void TblMsdcQUsgList::updateRst(
			ListMsdcQUsgList& rst
		) {
};

void TblMsdcQUsgList::removeRecByQref(
			ubigint qref
		) {
};

void TblMsdcQUsgList::removeRstByJref(
			ubigint jref
		) {
};

bool TblMsdcQUsgList::loadRecByQref(
			ubigint qref
			, MsdcQUsgList** rec
		) {
	return false;
};

ubigint TblMsdcQUsgList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListMsdcQUsgList& rst
		) {
	return 0;
};

/******************************************************************************
 class LiteTblMsdcQUsgList
 ******************************************************************************/

LiteTblMsdcQUsgList::LiteTblMsdcQUsgList() : TblMsdcQUsgList(), LiteTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;

	stmtLoadRecByQref = NULL;
	stmtLoadRecByJref = NULL;
	stmtLoadRstByJref = NULL;
};

LiteTblMsdcQUsgList::~LiteTblMsdcQUsgList() {
	if (stmtInsertRec) sqlite3_finalize(stmtInsertRec);
	if (stmtUpdateRec) sqlite3_finalize(stmtUpdateRec);
	if (stmtRemoveRecByQref) sqlite3_finalize(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) sqlite3_finalize(stmtRemoveRstByJref);

	if (stmtLoadRecByQref) sqlite3_finalize(stmtLoadRecByQref);
	if (stmtLoadRecByJref) sqlite3_finalize(stmtLoadRecByJref);
	if (stmtLoadRstByJref) sqlite3_finalize(stmtLoadRstByJref);
};

void LiteTblMsdcQUsgList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblMsdcQUsgList (jref, jnum, ref, sref) VALUES (?1,?2,?3,?4)");
	stmtUpdateRec = createStatement("UPDATE TblMsdcQUsgList SET jref = ?1, jnum = ?2, ref = ?3, sref = ?4 WHERE qref = ?5");
	stmtRemoveRecByQref = createStatement("DELETE FROM TblMsdcQUsgList WHERE qref = ?1");
	stmtRemoveRstByJref = createStatement("DELETE FROM TblMsdcQUsgList WHERE jref = ?1");

	stmtLoadRecByQref = createStatement("SELECT qref, jref, jnum, ref, sref FROM TblMsdcQUsgList WHERE qref = ?1");
	stmtLoadRstByJref = createStatement("SELECT qref, jref, jnum, ref, sref FROM TblMsdcQUsgList WHERE jref = ?1 ORDER BY jnum ASC");
};

bool LiteTblMsdcQUsgList::loadRec(
			sqlite3_stmt* stmt
			, MsdcQUsgList** rec
		) {
	int res;

	MsdcQUsgList* _rec = NULL;
	bool retval = false;

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		_rec = new MsdcQUsgList();

		_rec->qref = sqlite3_column_int64(stmt, 0);
		_rec->jref = sqlite3_column_int64(stmt, 1);
		_rec->jnum = sqlite3_column_int(stmt, 2);
		_rec->ref = sqlite3_column_int64(stmt, 3);
		_rec->sref.assign((const char*) sqlite3_column_text(stmt, 4));

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

ubigint LiteTblMsdcQUsgList::loadRst(
			sqlite3_stmt* stmt
			, const bool append
			, ListMsdcQUsgList& rst
		) {
	int res; ubigint numread = 0;

	MsdcQUsgList* rec;

	if (!append) rst.clear();

	res = sqlite3_step(stmt);
	while (res == SQLITE_ROW) {
		rec = new MsdcQUsgList();

		rec->qref = sqlite3_column_int64(stmt, 0);
		rec->jref = sqlite3_column_int64(stmt, 1);
		rec->jnum = sqlite3_column_int(stmt, 2);
		rec->ref = sqlite3_column_int64(stmt, 3);
		rec->sref.assign((const char*) sqlite3_column_text(stmt, 4));

		rst.nodes.push_back(rec);

		numread++;

		res = sqlite3_step(stmt);
	};

	return(numread);
};

bool LiteTblMsdcQUsgList::loadRecByStmt(
			sqlite3_stmt* stmt
			, MsdcQUsgList** rec
		) {
	bool retval = loadRec(stmt, rec);

	sqlite3_reset(stmt);

	return retval;
};

ubigint LiteTblMsdcQUsgList::loadRstByStmt(
			sqlite3_stmt* stmt
			, const bool append
			, ListMsdcQUsgList& rst
		) {
	ubigint retval = loadRst(stmt, append, rst);

	sqlite3_reset(stmt);

	return retval;
};

bool LiteTblMsdcQUsgList::loadRecBySQL(
			const string& sqlstr
			, MsdcQUsgList** rec
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

ubigint LiteTblMsdcQUsgList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListMsdcQUsgList& rst
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

void LiteTblMsdcQUsgList::insertRec(
			MsdcQUsgList* rec
		) {
	sqlite3_bind_int64(stmtInsertRec, 1, rec->jref);
	sqlite3_bind_int(stmtInsertRec, 2, rec->jnum);
	sqlite3_bind_int64(stmtInsertRec, 3, rec->ref);
	sqlite3_bind_text(stmtInsertRec, 4, rec->sref.c_str(), rec->sref.length(), SQLITE_STATIC);

	if (sqlite3_step(stmtInsertRec) != SQLITE_DONE) throw DbsException("DbsException / SQLite: error executing statement! (TblMsdcQUsgList / stmtInsertRec)\n");

	rec->qref = sqlite3_last_insert_rowid(dbs);

	sqlite3_reset(stmtInsertRec);
};

void LiteTblMsdcQUsgList::insertRst(
			ListMsdcQUsgList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void LiteTblMsdcQUsgList::updateRec(
			MsdcQUsgList* rec
		) {
	sqlite3_bind_int64(stmtUpdateRec, 1, rec->jref);
	sqlite3_bind_int(stmtUpdateRec, 2, rec->jnum);
	sqlite3_bind_int64(stmtUpdateRec, 3, rec->ref);
	sqlite3_bind_text(stmtUpdateRec, 4, rec->sref.c_str(), rec->sref.length(), SQLITE_STATIC);
	sqlite3_bind_int64(stmtUpdateRec, 5, rec->qref);

	if (sqlite3_step(stmtUpdateRec) != SQLITE_DONE) throw DbsException("DbsException / SQLite: error executing statement! (TblMsdcQUsgList / stmtUpdateRec)\n");

	sqlite3_reset(stmtUpdateRec);
};

void LiteTblMsdcQUsgList::updateRst(
			ListMsdcQUsgList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void LiteTblMsdcQUsgList::removeRecByQref(
			ubigint qref
		) {
	sqlite3_bind_int64(stmtRemoveRecByQref, 1, qref);

	if (sqlite3_step(stmtRemoveRecByQref) != SQLITE_DONE) throw DbsException("DbsException / SQLite: error executing statement! (TblMsdcQUsgList / stmtRemoveRecByQref)\n");

	sqlite3_reset(stmtRemoveRecByQref);
};

void LiteTblMsdcQUsgList::removeRstByJref(
			ubigint jref
		) {
	sqlite3_bind_int64(stmtRemoveRstByJref, 1, jref);

	if (sqlite3_step(stmtRemoveRstByJref) != SQLITE_DONE) throw DbsException("DbsException / SQLite: error executing statement! (TblMsdcQUsgList / stmtRemoveRstByJref)\n");

	sqlite3_reset(stmtRemoveRstByJref);
};

bool LiteTblMsdcQUsgList::loadRecByQref(
			ubigint qref
			, MsdcQUsgList** rec
		) {
	sqlite3_bind_int64(stmtLoadRecByQref, 1, qref);

	return loadRecByStmt(stmtLoadRecByQref, rec);
};

ubigint LiteTblMsdcQUsgList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListMsdcQUsgList& rst
		) {
	sqlite3_bind_int64(stmtLoadRstByJref, 1, jref);

	return loadRstByStmt(stmtLoadRstByJref, append, rst);
};

