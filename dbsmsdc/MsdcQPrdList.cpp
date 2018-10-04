/**
  * \file MsdcQPrdList.cpp
  * Dbs and XML wrapper for table TblMsdcQPrdList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Oct 2018
  * \date modified: 4 Oct 2018
  */

#include "MsdcQPrdList.h"

/******************************************************************************
 class MsdcQPrdList
 ******************************************************************************/

MsdcQPrdList::MsdcQPrdList(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint start
			, const string ftmStart
			, const uint stop
			, const string ftmStop
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->start = start;
	this->ftmStart = ftmStart;
	this->stop = stop;
	this->ftmStop = ftmStop;
};

void MsdcQPrdList::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "MsdcQPrdList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "sta", ftmStart);
		writeString(wr, "sto", ftmStop);
	} else {
		writeString(wr, "ftmStart", ftmStart);
		writeString(wr, "ftmStop", ftmStop);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListMsdcQPrdList
 ******************************************************************************/

ListMsdcQPrdList::ListMsdcQPrdList() {
};

ListMsdcQPrdList::ListMsdcQPrdList(
			const ListMsdcQPrdList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new MsdcQPrdList(*(src.nodes[i]));
};

ListMsdcQPrdList::~ListMsdcQPrdList() {
	clear();
};

void ListMsdcQPrdList::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListMsdcQPrdList::size() const {
	return(nodes.size());
};

void ListMsdcQPrdList::append(
			MsdcQPrdList* rec
		) {
	nodes.push_back(rec);
};

ListMsdcQPrdList& ListMsdcQPrdList::operator=(
			const ListMsdcQPrdList& src
		) {
	MsdcQPrdList* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new MsdcQPrdList(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListMsdcQPrdList::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListMsdcQPrdList";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblMsdcQPrdList
 ******************************************************************************/

TblMsdcQPrdList::TblMsdcQPrdList() {
};

TblMsdcQPrdList::~TblMsdcQPrdList() {
};

bool TblMsdcQPrdList::loadRecBySQL(
			const string& sqlstr
			, MsdcQPrdList** rec
		) {
	return false;
};

ubigint TblMsdcQPrdList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListMsdcQPrdList& rst
		) {
	return 0;
};

void TblMsdcQPrdList::insertRec(
			MsdcQPrdList* rec
		) {
};

ubigint TblMsdcQPrdList::insertNewRec(
			MsdcQPrdList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint start
			, const string ftmStart
			, const uint stop
			, const string ftmStop
		) {
	ubigint retval = 0;
	MsdcQPrdList* _rec = NULL;

	_rec = new MsdcQPrdList(0, jref, jnum, ref, start, ftmStart, stop, ftmStop);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblMsdcQPrdList::appendNewRecToRst(
			ListMsdcQPrdList& rst
			, MsdcQPrdList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint start
			, const string ftmStart
			, const uint stop
			, const string ftmStop
		) {
	ubigint retval = 0;
	MsdcQPrdList* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, start, ftmStart, stop, ftmStop);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblMsdcQPrdList::insertRst(
			ListMsdcQPrdList& rst
		) {
};

void TblMsdcQPrdList::updateRec(
			MsdcQPrdList* rec
		) {
};

void TblMsdcQPrdList::updateRst(
			ListMsdcQPrdList& rst
		) {
};

void TblMsdcQPrdList::removeRecByQref(
			ubigint qref
		) {
};

void TblMsdcQPrdList::removeRstByJref(
			ubigint jref
		) {
};

bool TblMsdcQPrdList::loadRecByQref(
			ubigint qref
			, MsdcQPrdList** rec
		) {
	return false;
};

ubigint TblMsdcQPrdList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListMsdcQPrdList& rst
		) {
	return 0;
};

/******************************************************************************
 class LiteTblMsdcQPrdList
 ******************************************************************************/

LiteTblMsdcQPrdList::LiteTblMsdcQPrdList() :
			TblMsdcQPrdList()
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

LiteTblMsdcQPrdList::~LiteTblMsdcQPrdList() {
	if (stmtInsertRec) sqlite3_finalize(stmtInsertRec);
	if (stmtUpdateRec) sqlite3_finalize(stmtUpdateRec);
	if (stmtRemoveRecByQref) sqlite3_finalize(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) sqlite3_finalize(stmtRemoveRstByJref);

	if (stmtLoadRecByQref) sqlite3_finalize(stmtLoadRecByQref);
	if (stmtLoadRecByJref) sqlite3_finalize(stmtLoadRecByJref);
	if (stmtLoadRstByJref) sqlite3_finalize(stmtLoadRstByJref);
};

void LiteTblMsdcQPrdList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblMsdcQPrdList (jref, jnum, ref, start, stop) VALUES (?1,?2,?3,?4,?5)");
	stmtUpdateRec = createStatement("UPDATE TblMsdcQPrdList SET jref = ?1, jnum = ?2, ref = ?3, start = ?4, stop = ?5 WHERE qref = ?6");
	stmtRemoveRecByQref = createStatement("DELETE FROM TblMsdcQPrdList WHERE qref = ?1");
	stmtRemoveRstByJref = createStatement("DELETE FROM TblMsdcQPrdList WHERE jref = ?1");

	stmtLoadRecByQref = createStatement("SELECT qref, jref, jnum, ref, start, stop FROM TblMsdcQPrdList WHERE qref = ?1");
	stmtLoadRstByJref = createStatement("SELECT qref, jref, jnum, ref, start, stop FROM TblMsdcQPrdList WHERE jref = ?1 ORDER BY jnum ASC");
};

bool LiteTblMsdcQPrdList::loadRec(
			sqlite3_stmt* stmt
			, MsdcQPrdList** rec
		) {
	int res;

	MsdcQPrdList* _rec = NULL;
	bool retval = false;

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		_rec = new MsdcQPrdList();

		_rec->qref = sqlite3_column_int64(stmt, 0);
		_rec->jref = sqlite3_column_int64(stmt, 1);
		_rec->jnum = sqlite3_column_int(stmt, 2);
		_rec->ref = sqlite3_column_int64(stmt, 3);
		_rec->start = sqlite3_column_int(stmt, 4);
		_rec->stop = sqlite3_column_int(stmt, 5);

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

ubigint LiteTblMsdcQPrdList::loadRst(
			sqlite3_stmt* stmt
			, const bool append
			, ListMsdcQPrdList& rst
		) {
	int res; ubigint numread = 0;

	MsdcQPrdList* rec;

	if (!append) rst.clear();

	res = sqlite3_step(stmt);
	while (res == SQLITE_ROW) {
		rec = new MsdcQPrdList();

		rec->qref = sqlite3_column_int64(stmt, 0);
		rec->jref = sqlite3_column_int64(stmt, 1);
		rec->jnum = sqlite3_column_int(stmt, 2);
		rec->ref = sqlite3_column_int64(stmt, 3);
		rec->start = sqlite3_column_int(stmt, 4);
		rec->stop = sqlite3_column_int(stmt, 5);

		rst.nodes.push_back(rec);

		numread++;

		res = sqlite3_step(stmt);
	};

	return(numread);
};

bool LiteTblMsdcQPrdList::loadRecByStmt(
			sqlite3_stmt* stmt
			, MsdcQPrdList** rec
		) {
	bool retval = loadRec(stmt, rec);

	sqlite3_reset(stmt);

	return retval;
};

ubigint LiteTblMsdcQPrdList::loadRstByStmt(
			sqlite3_stmt* stmt
			, const bool append
			, ListMsdcQPrdList& rst
		) {
	ubigint retval = loadRst(stmt, append, rst);

	sqlite3_reset(stmt);

	return retval;
};

bool LiteTblMsdcQPrdList::loadRecBySQL(
			const string& sqlstr
			, MsdcQPrdList** rec
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

ubigint LiteTblMsdcQPrdList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListMsdcQPrdList& rst
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

void LiteTblMsdcQPrdList::insertRec(
			MsdcQPrdList* rec
		) {
	sqlite3_bind_int64(stmtInsertRec, 1, rec->jref);
	sqlite3_bind_int(stmtInsertRec, 2, rec->jnum);
	sqlite3_bind_int64(stmtInsertRec, 3, rec->ref);
	sqlite3_bind_int(stmtInsertRec, 4, rec->start);
	sqlite3_bind_int(stmtInsertRec, 5, rec->stop);

	if (sqlite3_step(stmtInsertRec) != SQLITE_DONE) throw DbsException("DbsException / SQLite: error executing statement! (TblMsdcQPrdList / stmtInsertRec)\n");

	rec->qref = sqlite3_last_insert_rowid(dbs);

	sqlite3_reset(stmtInsertRec);
};

void LiteTblMsdcQPrdList::insertRst(
			ListMsdcQPrdList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void LiteTblMsdcQPrdList::updateRec(
			MsdcQPrdList* rec
		) {
	sqlite3_bind_int64(stmtUpdateRec, 1, rec->jref);
	sqlite3_bind_int(stmtUpdateRec, 2, rec->jnum);
	sqlite3_bind_int64(stmtUpdateRec, 3, rec->ref);
	sqlite3_bind_int(stmtUpdateRec, 4, rec->start);
	sqlite3_bind_int(stmtUpdateRec, 5, rec->stop);
	sqlite3_bind_int64(stmtUpdateRec, 6, rec->qref);

	if (sqlite3_step(stmtUpdateRec) != SQLITE_DONE) throw DbsException("DbsException / SQLite: error executing statement! (TblMsdcQPrdList / stmtUpdateRec)\n");

	sqlite3_reset(stmtUpdateRec);
};

void LiteTblMsdcQPrdList::updateRst(
			ListMsdcQPrdList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void LiteTblMsdcQPrdList::removeRecByQref(
			ubigint qref
		) {
	sqlite3_bind_int64(stmtRemoveRecByQref, 1, qref);

	if (sqlite3_step(stmtRemoveRecByQref) != SQLITE_DONE) throw DbsException("DbsException / SQLite: error executing statement! (TblMsdcQPrdList / stmtRemoveRecByQref)\n");

	sqlite3_reset(stmtRemoveRecByQref);
};

void LiteTblMsdcQPrdList::removeRstByJref(
			ubigint jref
		) {
	sqlite3_bind_int64(stmtRemoveRstByJref, 1, jref);

	if (sqlite3_step(stmtRemoveRstByJref) != SQLITE_DONE) throw DbsException("DbsException / SQLite: error executing statement! (TblMsdcQPrdList / stmtRemoveRstByJref)\n");

	sqlite3_reset(stmtRemoveRstByJref);
};

bool LiteTblMsdcQPrdList::loadRecByQref(
			ubigint qref
			, MsdcQPrdList** rec
		) {
	if (qref == 0) return false;

	sqlite3_bind_int64(stmtLoadRecByQref, 1, qref);

	return loadRecByStmt(stmtLoadRecByQref, rec);
};

ubigint LiteTblMsdcQPrdList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListMsdcQPrdList& rst
		) {
	sqlite3_bind_int64(stmtLoadRstByJref, 1, jref);

	return loadRstByStmt(stmtLoadRstByJref, append, rst);
};

