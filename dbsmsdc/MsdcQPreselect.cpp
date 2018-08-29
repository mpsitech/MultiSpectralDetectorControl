/**
  * \file MsdcQPreselect.cpp
  * Dbs and XML wrapper for table TblMsdcQPreselect (implementation)
  * \author Alexander Wirthmueller
  * \date created: 29 Aug 2018
  * \date modified: 29 Aug 2018
  */

#include "MsdcQPreselect.h"

/******************************************************************************
 class MsdcQPreselect
 ******************************************************************************/

MsdcQPreselect::MsdcQPreselect(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
};

void MsdcQPreselect::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "MsdcQPreselect";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
	} else {
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListMsdcQPreselect
 ******************************************************************************/

ListMsdcQPreselect::ListMsdcQPreselect() {
};

ListMsdcQPreselect::ListMsdcQPreselect(
			const ListMsdcQPreselect& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new MsdcQPreselect(*(src.nodes[i]));
};

ListMsdcQPreselect::~ListMsdcQPreselect() {
	clear();
};

void ListMsdcQPreselect::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListMsdcQPreselect::size() const {
	return(nodes.size());
};

void ListMsdcQPreselect::append(
			MsdcQPreselect* rec
		) {
	nodes.push_back(rec);
};

ListMsdcQPreselect& ListMsdcQPreselect::operator=(
			const ListMsdcQPreselect& src
		) {
	MsdcQPreselect* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new MsdcQPreselect(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListMsdcQPreselect::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListMsdcQPreselect";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblMsdcQPreselect
 ******************************************************************************/

TblMsdcQPreselect::TblMsdcQPreselect() {
};

TblMsdcQPreselect::~TblMsdcQPreselect() {
};

bool TblMsdcQPreselect::loadRecBySQL(
			const string& sqlstr
			, MsdcQPreselect** rec
		) {
	return false;
};

ubigint TblMsdcQPreselect::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListMsdcQPreselect& rst
		) {
	return 0;
};

void TblMsdcQPreselect::insertRec(
			MsdcQPreselect* rec
		) {
};

ubigint TblMsdcQPreselect::insertNewRec(
			MsdcQPreselect** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
		) {
	ubigint retval = 0;
	MsdcQPreselect* _rec = NULL;

	_rec = new MsdcQPreselect(0, jref, jnum, ref);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblMsdcQPreselect::appendNewRecToRst(
			ListMsdcQPreselect& rst
			, MsdcQPreselect** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
		) {
	ubigint retval = 0;
	MsdcQPreselect* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblMsdcQPreselect::insertRst(
			ListMsdcQPreselect& rst
		) {
};

void TblMsdcQPreselect::updateRec(
			MsdcQPreselect* rec
		) {
};

void TblMsdcQPreselect::updateRst(
			ListMsdcQPreselect& rst
		) {
};

void TblMsdcQPreselect::removeRecByQref(
			ubigint qref
		) {
};

void TblMsdcQPreselect::removeRstByJref(
			ubigint jref
		) {
};

bool TblMsdcQPreselect::loadRecByQref(
			ubigint qref
			, MsdcQPreselect** rec
		) {
	return false;
};

ubigint TblMsdcQPreselect::loadRstByJref(
			ubigint jref
			, const bool append
			, ListMsdcQPreselect& rst
		) {
	return 0;
};

/******************************************************************************
 class LiteTblMsdcQPreselect
 ******************************************************************************/

LiteTblMsdcQPreselect::LiteTblMsdcQPreselect() :
			TblMsdcQPreselect()
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

LiteTblMsdcQPreselect::~LiteTblMsdcQPreselect() {
	if (stmtInsertRec) sqlite3_finalize(stmtInsertRec);
	if (stmtUpdateRec) sqlite3_finalize(stmtUpdateRec);
	if (stmtRemoveRecByQref) sqlite3_finalize(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) sqlite3_finalize(stmtRemoveRstByJref);

	if (stmtLoadRecByQref) sqlite3_finalize(stmtLoadRecByQref);
	if (stmtLoadRecByJref) sqlite3_finalize(stmtLoadRecByJref);
	if (stmtLoadRstByJref) sqlite3_finalize(stmtLoadRstByJref);
};

void LiteTblMsdcQPreselect::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblMsdcQPreselect (jref, jnum, ref) VALUES (?1,?2,?3)");
	stmtUpdateRec = createStatement("UPDATE TblMsdcQPreselect SET jref = ?1, jnum = ?2, ref = ?3 WHERE qref = ?4");
	stmtRemoveRecByQref = createStatement("DELETE FROM TblMsdcQPreselect WHERE qref = ?1");
	stmtRemoveRstByJref = createStatement("DELETE FROM TblMsdcQPreselect WHERE jref = ?1");

	stmtLoadRecByQref = createStatement("SELECT qref, jref, jnum, ref FROM TblMsdcQPreselect WHERE qref = ?1");
	stmtLoadRstByJref = createStatement("SELECT qref, jref, jnum, ref FROM TblMsdcQPreselect WHERE jref = ?1 ORDER BY jnum ASC");
};

bool LiteTblMsdcQPreselect::loadRec(
			sqlite3_stmt* stmt
			, MsdcQPreselect** rec
		) {
	int res;

	MsdcQPreselect* _rec = NULL;
	bool retval = false;

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		_rec = new MsdcQPreselect();

		_rec->qref = sqlite3_column_int64(stmt, 0);
		_rec->jref = sqlite3_column_int64(stmt, 1);
		_rec->jnum = sqlite3_column_int(stmt, 2);
		_rec->ref = sqlite3_column_int64(stmt, 3);

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

ubigint LiteTblMsdcQPreselect::loadRst(
			sqlite3_stmt* stmt
			, const bool append
			, ListMsdcQPreselect& rst
		) {
	int res; ubigint numread = 0;

	MsdcQPreselect* rec;

	if (!append) rst.clear();

	res = sqlite3_step(stmt);
	while (res == SQLITE_ROW) {
		rec = new MsdcQPreselect();

		rec->qref = sqlite3_column_int64(stmt, 0);
		rec->jref = sqlite3_column_int64(stmt, 1);
		rec->jnum = sqlite3_column_int(stmt, 2);
		rec->ref = sqlite3_column_int64(stmt, 3);

		rst.nodes.push_back(rec);

		numread++;

		res = sqlite3_step(stmt);
	};

	return(numread);
};

bool LiteTblMsdcQPreselect::loadRecByStmt(
			sqlite3_stmt* stmt
			, MsdcQPreselect** rec
		) {
	bool retval = loadRec(stmt, rec);

	sqlite3_reset(stmt);

	return retval;
};

ubigint LiteTblMsdcQPreselect::loadRstByStmt(
			sqlite3_stmt* stmt
			, const bool append
			, ListMsdcQPreselect& rst
		) {
	ubigint retval = loadRst(stmt, append, rst);

	sqlite3_reset(stmt);

	return retval;
};

bool LiteTblMsdcQPreselect::loadRecBySQL(
			const string& sqlstr
			, MsdcQPreselect** rec
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

ubigint LiteTblMsdcQPreselect::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListMsdcQPreselect& rst
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

void LiteTblMsdcQPreselect::insertRec(
			MsdcQPreselect* rec
		) {
	sqlite3_bind_int64(stmtInsertRec, 1, rec->jref);
	sqlite3_bind_int(stmtInsertRec, 2, rec->jnum);
	sqlite3_bind_int64(stmtInsertRec, 3, rec->ref);

	if (sqlite3_step(stmtInsertRec) != SQLITE_DONE) throw DbsException("DbsException / SQLite: error executing statement! (TblMsdcQPreselect / stmtInsertRec)\n");

	rec->qref = sqlite3_last_insert_rowid(dbs);

	sqlite3_reset(stmtInsertRec);
};

void LiteTblMsdcQPreselect::insertRst(
			ListMsdcQPreselect& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void LiteTblMsdcQPreselect::updateRec(
			MsdcQPreselect* rec
		) {
	sqlite3_bind_int64(stmtUpdateRec, 1, rec->jref);
	sqlite3_bind_int(stmtUpdateRec, 2, rec->jnum);
	sqlite3_bind_int64(stmtUpdateRec, 3, rec->ref);
	sqlite3_bind_int64(stmtUpdateRec, 4, rec->qref);

	if (sqlite3_step(stmtUpdateRec) != SQLITE_DONE) throw DbsException("DbsException / SQLite: error executing statement! (TblMsdcQPreselect / stmtUpdateRec)\n");

	sqlite3_reset(stmtUpdateRec);
};

void LiteTblMsdcQPreselect::updateRst(
			ListMsdcQPreselect& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void LiteTblMsdcQPreselect::removeRecByQref(
			ubigint qref
		) {
	sqlite3_bind_int64(stmtRemoveRecByQref, 1, qref);

	if (sqlite3_step(stmtRemoveRecByQref) != SQLITE_DONE) throw DbsException("DbsException / SQLite: error executing statement! (TblMsdcQPreselect / stmtRemoveRecByQref)\n");

	sqlite3_reset(stmtRemoveRecByQref);
};

void LiteTblMsdcQPreselect::removeRstByJref(
			ubigint jref
		) {
	sqlite3_bind_int64(stmtRemoveRstByJref, 1, jref);

	if (sqlite3_step(stmtRemoveRstByJref) != SQLITE_DONE) throw DbsException("DbsException / SQLite: error executing statement! (TblMsdcQPreselect / stmtRemoveRstByJref)\n");

	sqlite3_reset(stmtRemoveRstByJref);
};

bool LiteTblMsdcQPreselect::loadRecByQref(
			ubigint qref
			, MsdcQPreselect** rec
		) {
	sqlite3_bind_int64(stmtLoadRecByQref, 1, qref);

	return loadRecByStmt(stmtLoadRecByQref, rec);
};

ubigint LiteTblMsdcQPreselect::loadRstByJref(
			ubigint jref
			, const bool append
			, ListMsdcQPreselect& rst
		) {
	sqlite3_bind_int64(stmtLoadRstByJref, 1, jref);

	return loadRstByStmt(stmtLoadRstByJref, append, rst);
};

