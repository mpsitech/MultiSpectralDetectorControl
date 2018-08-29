/**
  * \file MsdcQSelect.cpp
  * Dbs and XML wrapper for table TblMsdcQSelect (implementation)
  * \author Alexander Wirthmueller
  * \date created: 29 Aug 2018
  * \date modified: 29 Aug 2018
  */

#include "MsdcQSelect.h"

/******************************************************************************
 class MsdcQSelect
 ******************************************************************************/

MsdcQSelect::MsdcQSelect(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const uint ix
			, const ubigint ref
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ix = ix;
	this->ref = ref;
};

void MsdcQSelect::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "MsdcQSelect";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
	} else {
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListMsdcQSelect
 ******************************************************************************/

ListMsdcQSelect::ListMsdcQSelect() {
};

ListMsdcQSelect::ListMsdcQSelect(
			const ListMsdcQSelect& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new MsdcQSelect(*(src.nodes[i]));
};

ListMsdcQSelect::~ListMsdcQSelect() {
	clear();
};

void ListMsdcQSelect::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListMsdcQSelect::size() const {
	return(nodes.size());
};

void ListMsdcQSelect::append(
			MsdcQSelect* rec
		) {
	nodes.push_back(rec);
};

ListMsdcQSelect& ListMsdcQSelect::operator=(
			const ListMsdcQSelect& src
		) {
	MsdcQSelect* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new MsdcQSelect(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListMsdcQSelect::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListMsdcQSelect";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblMsdcQSelect
 ******************************************************************************/

TblMsdcQSelect::TblMsdcQSelect() {
};

TblMsdcQSelect::~TblMsdcQSelect() {
};

bool TblMsdcQSelect::loadRecBySQL(
			const string& sqlstr
			, MsdcQSelect** rec
		) {
	return false;
};

ubigint TblMsdcQSelect::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListMsdcQSelect& rst
		) {
	return 0;
};

void TblMsdcQSelect::insertRec(
			MsdcQSelect* rec
		) {
};

ubigint TblMsdcQSelect::insertNewRec(
			MsdcQSelect** rec
			, const ubigint jref
			, const uint jnum
			, const uint ix
			, const ubigint ref
		) {
	ubigint retval = 0;
	MsdcQSelect* _rec = NULL;

	_rec = new MsdcQSelect(0, jref, jnum, ix, ref);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblMsdcQSelect::appendNewRecToRst(
			ListMsdcQSelect& rst
			, MsdcQSelect** rec
			, const ubigint jref
			, const uint jnum
			, const uint ix
			, const ubigint ref
		) {
	ubigint retval = 0;
	MsdcQSelect* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ix, ref);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblMsdcQSelect::insertRst(
			ListMsdcQSelect& rst
		) {
};

void TblMsdcQSelect::updateRec(
			MsdcQSelect* rec
		) {
};

void TblMsdcQSelect::updateRst(
			ListMsdcQSelect& rst
		) {
};

void TblMsdcQSelect::removeRecByQref(
			ubigint qref
		) {
};

void TblMsdcQSelect::removeRstByJref(
			ubigint jref
		) {
};

bool TblMsdcQSelect::loadRecByQref(
			ubigint qref
			, MsdcQSelect** rec
		) {
	return false;
};

ubigint TblMsdcQSelect::loadRstByJref(
			ubigint jref
			, const bool append
			, ListMsdcQSelect& rst
		) {
	return 0;
};

/******************************************************************************
 class LiteTblMsdcQSelect
 ******************************************************************************/

LiteTblMsdcQSelect::LiteTblMsdcQSelect() :
			TblMsdcQSelect()
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

LiteTblMsdcQSelect::~LiteTblMsdcQSelect() {
	if (stmtInsertRec) sqlite3_finalize(stmtInsertRec);
	if (stmtUpdateRec) sqlite3_finalize(stmtUpdateRec);
	if (stmtRemoveRecByQref) sqlite3_finalize(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) sqlite3_finalize(stmtRemoveRstByJref);

	if (stmtLoadRecByQref) sqlite3_finalize(stmtLoadRecByQref);
	if (stmtLoadRecByJref) sqlite3_finalize(stmtLoadRecByJref);
	if (stmtLoadRstByJref) sqlite3_finalize(stmtLoadRstByJref);
};

void LiteTblMsdcQSelect::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblMsdcQSelect (jref, jnum, ix, ref) VALUES (?1,?2,?3,?4)");
	stmtUpdateRec = createStatement("UPDATE TblMsdcQSelect SET jref = ?1, jnum = ?2, ix = ?3, ref = ?4 WHERE qref = ?5");
	stmtRemoveRecByQref = createStatement("DELETE FROM TblMsdcQSelect WHERE qref = ?1");
	stmtRemoveRstByJref = createStatement("DELETE FROM TblMsdcQSelect WHERE jref = ?1");

	stmtLoadRecByQref = createStatement("SELECT qref, jref, jnum, ix, ref FROM TblMsdcQSelect WHERE qref = ?1");
	stmtLoadRstByJref = createStatement("SELECT qref, jref, jnum, ix, ref FROM TblMsdcQSelect WHERE jref = ?1 ORDER BY jnum ASC");
};

bool LiteTblMsdcQSelect::loadRec(
			sqlite3_stmt* stmt
			, MsdcQSelect** rec
		) {
	int res;

	MsdcQSelect* _rec = NULL;
	bool retval = false;

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		_rec = new MsdcQSelect();

		_rec->qref = sqlite3_column_int64(stmt, 0);
		_rec->jref = sqlite3_column_int64(stmt, 1);
		_rec->jnum = sqlite3_column_int(stmt, 2);
		_rec->ix = sqlite3_column_int(stmt, 3);
		_rec->ref = sqlite3_column_int64(stmt, 4);

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

ubigint LiteTblMsdcQSelect::loadRst(
			sqlite3_stmt* stmt
			, const bool append
			, ListMsdcQSelect& rst
		) {
	int res; ubigint numread = 0;

	MsdcQSelect* rec;

	if (!append) rst.clear();

	res = sqlite3_step(stmt);
	while (res == SQLITE_ROW) {
		rec = new MsdcQSelect();

		rec->qref = sqlite3_column_int64(stmt, 0);
		rec->jref = sqlite3_column_int64(stmt, 1);
		rec->jnum = sqlite3_column_int(stmt, 2);
		rec->ix = sqlite3_column_int(stmt, 3);
		rec->ref = sqlite3_column_int64(stmt, 4);

		rst.nodes.push_back(rec);

		numread++;

		res = sqlite3_step(stmt);
	};

	return(numread);
};

bool LiteTblMsdcQSelect::loadRecByStmt(
			sqlite3_stmt* stmt
			, MsdcQSelect** rec
		) {
	bool retval = loadRec(stmt, rec);

	sqlite3_reset(stmt);

	return retval;
};

ubigint LiteTblMsdcQSelect::loadRstByStmt(
			sqlite3_stmt* stmt
			, const bool append
			, ListMsdcQSelect& rst
		) {
	ubigint retval = loadRst(stmt, append, rst);

	sqlite3_reset(stmt);

	return retval;
};

bool LiteTblMsdcQSelect::loadRecBySQL(
			const string& sqlstr
			, MsdcQSelect** rec
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

ubigint LiteTblMsdcQSelect::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListMsdcQSelect& rst
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

void LiteTblMsdcQSelect::insertRec(
			MsdcQSelect* rec
		) {
	sqlite3_bind_int64(stmtInsertRec, 1, rec->jref);
	sqlite3_bind_int(stmtInsertRec, 2, rec->jnum);
	sqlite3_bind_int(stmtInsertRec, 3, rec->ix);
	sqlite3_bind_int64(stmtInsertRec, 4, rec->ref);

	if (sqlite3_step(stmtInsertRec) != SQLITE_DONE) throw DbsException("DbsException / SQLite: error executing statement! (TblMsdcQSelect / stmtInsertRec)\n");

	rec->qref = sqlite3_last_insert_rowid(dbs);

	sqlite3_reset(stmtInsertRec);
};

void LiteTblMsdcQSelect::insertRst(
			ListMsdcQSelect& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void LiteTblMsdcQSelect::updateRec(
			MsdcQSelect* rec
		) {
	sqlite3_bind_int64(stmtUpdateRec, 1, rec->jref);
	sqlite3_bind_int(stmtUpdateRec, 2, rec->jnum);
	sqlite3_bind_int(stmtUpdateRec, 3, rec->ix);
	sqlite3_bind_int64(stmtUpdateRec, 4, rec->ref);
	sqlite3_bind_int64(stmtUpdateRec, 5, rec->qref);

	if (sqlite3_step(stmtUpdateRec) != SQLITE_DONE) throw DbsException("DbsException / SQLite: error executing statement! (TblMsdcQSelect / stmtUpdateRec)\n");

	sqlite3_reset(stmtUpdateRec);
};

void LiteTblMsdcQSelect::updateRst(
			ListMsdcQSelect& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void LiteTblMsdcQSelect::removeRecByQref(
			ubigint qref
		) {
	sqlite3_bind_int64(stmtRemoveRecByQref, 1, qref);

	if (sqlite3_step(stmtRemoveRecByQref) != SQLITE_DONE) throw DbsException("DbsException / SQLite: error executing statement! (TblMsdcQSelect / stmtRemoveRecByQref)\n");

	sqlite3_reset(stmtRemoveRecByQref);
};

void LiteTblMsdcQSelect::removeRstByJref(
			ubigint jref
		) {
	sqlite3_bind_int64(stmtRemoveRstByJref, 1, jref);

	if (sqlite3_step(stmtRemoveRstByJref) != SQLITE_DONE) throw DbsException("DbsException / SQLite: error executing statement! (TblMsdcQSelect / stmtRemoveRstByJref)\n");

	sqlite3_reset(stmtRemoveRstByJref);
};

bool LiteTblMsdcQSelect::loadRecByQref(
			ubigint qref
			, MsdcQSelect** rec
		) {
	sqlite3_bind_int64(stmtLoadRecByQref, 1, qref);

	return loadRecByStmt(stmtLoadRecByQref, rec);
};

ubigint LiteTblMsdcQSelect::loadRstByJref(
			ubigint jref
			, const bool append
			, ListMsdcQSelect& rst
		) {
	sqlite3_bind_int64(stmtLoadRstByJref, 1, jref);

	return loadRstByStmt(stmtLoadRstByJref, append, rst);
};

