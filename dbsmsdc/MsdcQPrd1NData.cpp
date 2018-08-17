/**
  * \file MsdcQPrd1NData.cpp
  * Dbs and XML wrapper for table TblMsdcQPrd1NData (implementation)
  * \author Alexander Wirthmueller
  * \date created: 15 Aug 2018
  * \date modified: 15 Aug 2018
  */

#include "MsdcQPrd1NData.h"

/******************************************************************************
 class MsdcQPrd1NData
 ******************************************************************************/

MsdcQPrd1NData::MsdcQPrd1NData(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->stubRef = stubRef;
};

void MsdcQPrd1NData::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "MsdcQPrd1NData";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "ref", stubRef);
	} else {
		writeString(wr, "stubRef", stubRef);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListMsdcQPrd1NData
 ******************************************************************************/

ListMsdcQPrd1NData::ListMsdcQPrd1NData() {
};

ListMsdcQPrd1NData::ListMsdcQPrd1NData(
			const ListMsdcQPrd1NData& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new MsdcQPrd1NData(*(src.nodes[i]));
};

ListMsdcQPrd1NData::~ListMsdcQPrd1NData() {
	clear();
};

void ListMsdcQPrd1NData::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListMsdcQPrd1NData::size() const {
	return(nodes.size());
};

void ListMsdcQPrd1NData::append(
			MsdcQPrd1NData* rec
		) {
	nodes.push_back(rec);
};

ListMsdcQPrd1NData& ListMsdcQPrd1NData::operator=(
			const ListMsdcQPrd1NData& src
		) {
	MsdcQPrd1NData* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new MsdcQPrd1NData(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListMsdcQPrd1NData::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListMsdcQPrd1NData";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblMsdcQPrd1NData
 ******************************************************************************/

TblMsdcQPrd1NData::TblMsdcQPrd1NData() {
};

TblMsdcQPrd1NData::~TblMsdcQPrd1NData() {
};

bool TblMsdcQPrd1NData::loadRecBySQL(
			const string& sqlstr
			, MsdcQPrd1NData** rec
		) {
	return false;
};

ubigint TblMsdcQPrd1NData::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListMsdcQPrd1NData& rst
		) {
	return 0;
};

void TblMsdcQPrd1NData::insertRec(
			MsdcQPrd1NData* rec
		) {
};

ubigint TblMsdcQPrd1NData::insertNewRec(
			MsdcQPrd1NData** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	MsdcQPrd1NData* _rec = NULL;

	_rec = new MsdcQPrd1NData(0, jref, jnum, ref, stubRef);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblMsdcQPrd1NData::appendNewRecToRst(
			ListMsdcQPrd1NData& rst
			, MsdcQPrd1NData** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	MsdcQPrd1NData* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, stubRef);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblMsdcQPrd1NData::insertRst(
			ListMsdcQPrd1NData& rst
		) {
};

void TblMsdcQPrd1NData::updateRec(
			MsdcQPrd1NData* rec
		) {
};

void TblMsdcQPrd1NData::updateRst(
			ListMsdcQPrd1NData& rst
		) {
};

void TblMsdcQPrd1NData::removeRecByQref(
			ubigint qref
		) {
};

void TblMsdcQPrd1NData::removeRstByJref(
			ubigint jref
		) {
};

bool TblMsdcQPrd1NData::loadRecByQref(
			ubigint qref
			, MsdcQPrd1NData** rec
		) {
	return false;
};

ubigint TblMsdcQPrd1NData::loadRstByJref(
			ubigint jref
			, const bool append
			, ListMsdcQPrd1NData& rst
		) {
	return 0;
};

/******************************************************************************
 class LiteTblMsdcQPrd1NData
 ******************************************************************************/

LiteTblMsdcQPrd1NData::LiteTblMsdcQPrd1NData() : TblMsdcQPrd1NData(), LiteTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;

	stmtLoadRecByQref = NULL;
	stmtLoadRecByJref = NULL;
	stmtLoadRstByJref = NULL;
};

LiteTblMsdcQPrd1NData::~LiteTblMsdcQPrd1NData() {
	if (stmtInsertRec) sqlite3_finalize(stmtInsertRec);
	if (stmtUpdateRec) sqlite3_finalize(stmtUpdateRec);
	if (stmtRemoveRecByQref) sqlite3_finalize(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) sqlite3_finalize(stmtRemoveRstByJref);

	if (stmtLoadRecByQref) sqlite3_finalize(stmtLoadRecByQref);
	if (stmtLoadRecByJref) sqlite3_finalize(stmtLoadRecByJref);
	if (stmtLoadRstByJref) sqlite3_finalize(stmtLoadRstByJref);
};

void LiteTblMsdcQPrd1NData::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblMsdcQPrd1NData (jref, jnum, ref) VALUES (?1,?2,?3)");
	stmtUpdateRec = createStatement("UPDATE TblMsdcQPrd1NData SET jref = ?1, jnum = ?2, ref = ?3 WHERE qref = ?4");
	stmtRemoveRecByQref = createStatement("DELETE FROM TblMsdcQPrd1NData WHERE qref = ?1");
	stmtRemoveRstByJref = createStatement("DELETE FROM TblMsdcQPrd1NData WHERE jref = ?1");

	stmtLoadRecByQref = createStatement("SELECT qref, jref, jnum, ref FROM TblMsdcQPrd1NData WHERE qref = ?1");
	stmtLoadRstByJref = createStatement("SELECT qref, jref, jnum, ref FROM TblMsdcQPrd1NData WHERE jref = ?1 ORDER BY jnum ASC");
};

bool LiteTblMsdcQPrd1NData::loadRec(
			sqlite3_stmt* stmt
			, MsdcQPrd1NData** rec
		) {
	int res;

	MsdcQPrd1NData* _rec = NULL;
	bool retval = false;

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		_rec = new MsdcQPrd1NData();

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

ubigint LiteTblMsdcQPrd1NData::loadRst(
			sqlite3_stmt* stmt
			, const bool append
			, ListMsdcQPrd1NData& rst
		) {
	int res; ubigint numread = 0;

	MsdcQPrd1NData* rec;

	if (!append) rst.clear();

	res = sqlite3_step(stmt);
	while (res == SQLITE_ROW) {
		rec = new MsdcQPrd1NData();

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

bool LiteTblMsdcQPrd1NData::loadRecByStmt(
			sqlite3_stmt* stmt
			, MsdcQPrd1NData** rec
		) {
	bool retval = loadRec(stmt, rec);

	sqlite3_reset(stmt);

	return retval;
};

ubigint LiteTblMsdcQPrd1NData::loadRstByStmt(
			sqlite3_stmt* stmt
			, const bool append
			, ListMsdcQPrd1NData& rst
		) {
	ubigint retval = loadRst(stmt, append, rst);

	sqlite3_reset(stmt);

	return retval;
};

bool LiteTblMsdcQPrd1NData::loadRecBySQL(
			const string& sqlstr
			, MsdcQPrd1NData** rec
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

ubigint LiteTblMsdcQPrd1NData::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListMsdcQPrd1NData& rst
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

void LiteTblMsdcQPrd1NData::insertRec(
			MsdcQPrd1NData* rec
		) {
	sqlite3_bind_int64(stmtInsertRec, 1, rec->jref);
	sqlite3_bind_int(stmtInsertRec, 2, rec->jnum);
	sqlite3_bind_int64(stmtInsertRec, 3, rec->ref);

	if (sqlite3_step(stmtInsertRec) != SQLITE_DONE) throw DbsException("DbsException / SQLite: error executing statement! (TblMsdcQPrd1NData / stmtInsertRec)\n");

	rec->qref = sqlite3_last_insert_rowid(dbs);

	sqlite3_reset(stmtInsertRec);
};

void LiteTblMsdcQPrd1NData::insertRst(
			ListMsdcQPrd1NData& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void LiteTblMsdcQPrd1NData::updateRec(
			MsdcQPrd1NData* rec
		) {
	sqlite3_bind_int64(stmtUpdateRec, 1, rec->jref);
	sqlite3_bind_int(stmtUpdateRec, 2, rec->jnum);
	sqlite3_bind_int64(stmtUpdateRec, 3, rec->ref);
	sqlite3_bind_int64(stmtUpdateRec, 4, rec->qref);

	if (sqlite3_step(stmtUpdateRec) != SQLITE_DONE) throw DbsException("DbsException / SQLite: error executing statement! (TblMsdcQPrd1NData / stmtUpdateRec)\n");

	sqlite3_reset(stmtUpdateRec);
};

void LiteTblMsdcQPrd1NData::updateRst(
			ListMsdcQPrd1NData& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void LiteTblMsdcQPrd1NData::removeRecByQref(
			ubigint qref
		) {
	sqlite3_bind_int64(stmtRemoveRecByQref, 1, qref);

	if (sqlite3_step(stmtRemoveRecByQref) != SQLITE_DONE) throw DbsException("DbsException / SQLite: error executing statement! (TblMsdcQPrd1NData / stmtRemoveRecByQref)\n");

	sqlite3_reset(stmtRemoveRecByQref);
};

void LiteTblMsdcQPrd1NData::removeRstByJref(
			ubigint jref
		) {
	sqlite3_bind_int64(stmtRemoveRstByJref, 1, jref);

	if (sqlite3_step(stmtRemoveRstByJref) != SQLITE_DONE) throw DbsException("DbsException / SQLite: error executing statement! (TblMsdcQPrd1NData / stmtRemoveRstByJref)\n");

	sqlite3_reset(stmtRemoveRstByJref);
};

bool LiteTblMsdcQPrd1NData::loadRecByQref(
			ubigint qref
			, MsdcQPrd1NData** rec
		) {
	sqlite3_bind_int64(stmtLoadRecByQref, 1, qref);

	return loadRecByStmt(stmtLoadRecByQref, rec);
};

ubigint LiteTblMsdcQPrd1NData::loadRstByJref(
			ubigint jref
			, const bool append
			, ListMsdcQPrd1NData& rst
		) {
	sqlite3_bind_int64(stmtLoadRstByJref, 1, jref);

	return loadRstByStmt(stmtLoadRstByJref, append, rst);
};

