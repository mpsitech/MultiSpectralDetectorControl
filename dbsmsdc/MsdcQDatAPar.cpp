/**
  * \file MsdcQDatAPar.cpp
  * Dbs and XML wrapper for table TblMsdcQDatAPar (implementation)
  * \author Alexander Wirthmueller
  * \date created: 12 Sep 2018
  * \date modified: 12 Sep 2018
  */

#include "MsdcQDatAPar.h"

/******************************************************************************
 class MsdcQDatAPar
 ******************************************************************************/

MsdcQDatAPar::MsdcQDatAPar(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const double x1Start
			, const string ftmX1Start
			, const string x2SrefKKey
			, const string titX2SrefKKey
			, const ubigint refMsdcMFile
			, const string stubRefMsdcMFile
			, const string Val
			, const string Bindata
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->x1Start = x1Start;
	this->ftmX1Start = ftmX1Start;
	this->x2SrefKKey = x2SrefKKey;
	this->titX2SrefKKey = titX2SrefKKey;
	this->refMsdcMFile = refMsdcMFile;
	this->stubRefMsdcMFile = stubRefMsdcMFile;
	this->Val = Val;
	this->Bindata = Bindata;
};

void MsdcQDatAPar::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "MsdcQDatAPar";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "sta", ftmX1Start);
		writeString(wr, "key", x2SrefKKey);
		writeString(wr, "key2", titX2SrefKKey);
		writeString(wr, "fil", stubRefMsdcMFile);
		writeString(wr, "val", Val);
		writeString(wr, "bin", Bindata);
	} else {
		writeString(wr, "ftmX1Start", ftmX1Start);
		writeString(wr, "x2SrefKKey", x2SrefKKey);
		writeString(wr, "titX2SrefKKey", titX2SrefKKey);
		writeString(wr, "stubRefMsdcMFile", stubRefMsdcMFile);
		writeString(wr, "Val", Val);
		writeString(wr, "Bindata", Bindata);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListMsdcQDatAPar
 ******************************************************************************/

ListMsdcQDatAPar::ListMsdcQDatAPar() {
};

ListMsdcQDatAPar::ListMsdcQDatAPar(
			const ListMsdcQDatAPar& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new MsdcQDatAPar(*(src.nodes[i]));
};

ListMsdcQDatAPar::~ListMsdcQDatAPar() {
	clear();
};

void ListMsdcQDatAPar::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListMsdcQDatAPar::size() const {
	return(nodes.size());
};

void ListMsdcQDatAPar::append(
			MsdcQDatAPar* rec
		) {
	nodes.push_back(rec);
};

ListMsdcQDatAPar& ListMsdcQDatAPar::operator=(
			const ListMsdcQDatAPar& src
		) {
	MsdcQDatAPar* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new MsdcQDatAPar(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListMsdcQDatAPar::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListMsdcQDatAPar";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblMsdcQDatAPar
 ******************************************************************************/

TblMsdcQDatAPar::TblMsdcQDatAPar() {
};

TblMsdcQDatAPar::~TblMsdcQDatAPar() {
};

bool TblMsdcQDatAPar::loadRecBySQL(
			const string& sqlstr
			, MsdcQDatAPar** rec
		) {
	return false;
};

ubigint TblMsdcQDatAPar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListMsdcQDatAPar& rst
		) {
	return 0;
};

void TblMsdcQDatAPar::insertRec(
			MsdcQDatAPar* rec
		) {
};

ubigint TblMsdcQDatAPar::insertNewRec(
			MsdcQDatAPar** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const double x1Start
			, const string ftmX1Start
			, const string x2SrefKKey
			, const string titX2SrefKKey
			, const ubigint refMsdcMFile
			, const string stubRefMsdcMFile
			, const string Val
			, const string Bindata
		) {
	ubigint retval = 0;
	MsdcQDatAPar* _rec = NULL;

	_rec = new MsdcQDatAPar(0, jref, jnum, ref, x1Start, ftmX1Start, x2SrefKKey, titX2SrefKKey, refMsdcMFile, stubRefMsdcMFile, Val, Bindata);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblMsdcQDatAPar::appendNewRecToRst(
			ListMsdcQDatAPar& rst
			, MsdcQDatAPar** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const double x1Start
			, const string ftmX1Start
			, const string x2SrefKKey
			, const string titX2SrefKKey
			, const ubigint refMsdcMFile
			, const string stubRefMsdcMFile
			, const string Val
			, const string Bindata
		) {
	ubigint retval = 0;
	MsdcQDatAPar* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, x1Start, ftmX1Start, x2SrefKKey, titX2SrefKKey, refMsdcMFile, stubRefMsdcMFile, Val, Bindata);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblMsdcQDatAPar::insertRst(
			ListMsdcQDatAPar& rst
		) {
};

void TblMsdcQDatAPar::updateRec(
			MsdcQDatAPar* rec
		) {
};

void TblMsdcQDatAPar::updateRst(
			ListMsdcQDatAPar& rst
		) {
};

void TblMsdcQDatAPar::removeRecByQref(
			ubigint qref
		) {
};

void TblMsdcQDatAPar::removeRstByJref(
			ubigint jref
		) {
};

bool TblMsdcQDatAPar::loadRecByQref(
			ubigint qref
			, MsdcQDatAPar** rec
		) {
	return false;
};

ubigint TblMsdcQDatAPar::loadRstByJref(
			ubigint jref
			, const bool append
			, ListMsdcQDatAPar& rst
		) {
	return 0;
};

/******************************************************************************
 class LiteTblMsdcQDatAPar
 ******************************************************************************/

LiteTblMsdcQDatAPar::LiteTblMsdcQDatAPar() :
			TblMsdcQDatAPar()
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

LiteTblMsdcQDatAPar::~LiteTblMsdcQDatAPar() {
	if (stmtInsertRec) sqlite3_finalize(stmtInsertRec);
	if (stmtUpdateRec) sqlite3_finalize(stmtUpdateRec);
	if (stmtRemoveRecByQref) sqlite3_finalize(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) sqlite3_finalize(stmtRemoveRstByJref);

	if (stmtLoadRecByQref) sqlite3_finalize(stmtLoadRecByQref);
	if (stmtLoadRecByJref) sqlite3_finalize(stmtLoadRecByJref);
	if (stmtLoadRstByJref) sqlite3_finalize(stmtLoadRstByJref);
};

void LiteTblMsdcQDatAPar::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblMsdcQDatAPar (jref, jnum, ref, x1Start, x2SrefKKey, refMsdcMFile, Val, Bindata) VALUES (?1,?2,?3,?4,?5,?6,?7,?8)");
	stmtUpdateRec = createStatement("UPDATE TblMsdcQDatAPar SET jref = ?1, jnum = ?2, ref = ?3, x1Start = ?4, x2SrefKKey = ?5, refMsdcMFile = ?6, Val = ?7, Bindata = ?8 WHERE qref = ?9");
	stmtRemoveRecByQref = createStatement("DELETE FROM TblMsdcQDatAPar WHERE qref = ?1");
	stmtRemoveRstByJref = createStatement("DELETE FROM TblMsdcQDatAPar WHERE jref = ?1");

	stmtLoadRecByQref = createStatement("SELECT qref, jref, jnum, ref, x1Start, x2SrefKKey, refMsdcMFile, Val, Bindata FROM TblMsdcQDatAPar WHERE qref = ?1");
	stmtLoadRstByJref = createStatement("SELECT qref, jref, jnum, ref, x1Start, x2SrefKKey, refMsdcMFile, Val, Bindata FROM TblMsdcQDatAPar WHERE jref = ?1 ORDER BY jnum ASC");
};

bool LiteTblMsdcQDatAPar::loadRec(
			sqlite3_stmt* stmt
			, MsdcQDatAPar** rec
		) {
	int res;

	MsdcQDatAPar* _rec = NULL;
	bool retval = false;

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		_rec = new MsdcQDatAPar();

		_rec->qref = sqlite3_column_int64(stmt, 0);
		_rec->jref = sqlite3_column_int64(stmt, 1);
		_rec->jnum = sqlite3_column_int(stmt, 2);
		_rec->ref = sqlite3_column_int64(stmt, 3);
		_rec->x1Start = sqlite3_column_double(stmt, 4);
		_rec->x2SrefKKey.assign((const char*) sqlite3_column_text(stmt, 5));
		_rec->refMsdcMFile = sqlite3_column_int64(stmt, 6);
		_rec->Val.assign((const char*) sqlite3_column_text(stmt, 7));
		_rec->Bindata.assign((const char*) sqlite3_column_text(stmt, 8));

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

ubigint LiteTblMsdcQDatAPar::loadRst(
			sqlite3_stmt* stmt
			, const bool append
			, ListMsdcQDatAPar& rst
		) {
	int res; ubigint numread = 0;

	MsdcQDatAPar* rec;

	if (!append) rst.clear();

	res = sqlite3_step(stmt);
	while (res == SQLITE_ROW) {
		rec = new MsdcQDatAPar();

		rec->qref = sqlite3_column_int64(stmt, 0);
		rec->jref = sqlite3_column_int64(stmt, 1);
		rec->jnum = sqlite3_column_int(stmt, 2);
		rec->ref = sqlite3_column_int64(stmt, 3);
		rec->x1Start = sqlite3_column_double(stmt, 4);
		rec->x2SrefKKey.assign((const char*) sqlite3_column_text(stmt, 5));
		rec->refMsdcMFile = sqlite3_column_int64(stmt, 6);
		rec->Val.assign((const char*) sqlite3_column_text(stmt, 7));
		rec->Bindata.assign((const char*) sqlite3_column_text(stmt, 8));

		rst.nodes.push_back(rec);

		numread++;

		res = sqlite3_step(stmt);
	};

	return(numread);
};

bool LiteTblMsdcQDatAPar::loadRecByStmt(
			sqlite3_stmt* stmt
			, MsdcQDatAPar** rec
		) {
	bool retval = loadRec(stmt, rec);

	sqlite3_reset(stmt);

	return retval;
};

ubigint LiteTblMsdcQDatAPar::loadRstByStmt(
			sqlite3_stmt* stmt
			, const bool append
			, ListMsdcQDatAPar& rst
		) {
	ubigint retval = loadRst(stmt, append, rst);

	sqlite3_reset(stmt);

	return retval;
};

bool LiteTblMsdcQDatAPar::loadRecBySQL(
			const string& sqlstr
			, MsdcQDatAPar** rec
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

ubigint LiteTblMsdcQDatAPar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListMsdcQDatAPar& rst
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

void LiteTblMsdcQDatAPar::insertRec(
			MsdcQDatAPar* rec
		) {
	sqlite3_bind_int64(stmtInsertRec, 1, rec->jref);
	sqlite3_bind_int(stmtInsertRec, 2, rec->jnum);
	sqlite3_bind_int64(stmtInsertRec, 3, rec->ref);
	sqlite3_bind_double(stmtInsertRec, 4, rec->x1Start);
	sqlite3_bind_text(stmtInsertRec, 5, rec->x2SrefKKey.c_str(), rec->x2SrefKKey.length(), SQLITE_STATIC);
	sqlite3_bind_int64(stmtInsertRec, 6, rec->refMsdcMFile);
	sqlite3_bind_text(stmtInsertRec, 7, rec->Val.c_str(), rec->Val.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtInsertRec, 8, rec->Bindata.c_str(), rec->Bindata.length(), SQLITE_STATIC);

	if (sqlite3_step(stmtInsertRec) != SQLITE_DONE) throw DbsException("DbsException / SQLite: error executing statement! (TblMsdcQDatAPar / stmtInsertRec)\n");

	rec->qref = sqlite3_last_insert_rowid(dbs);

	sqlite3_reset(stmtInsertRec);
};

void LiteTblMsdcQDatAPar::insertRst(
			ListMsdcQDatAPar& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void LiteTblMsdcQDatAPar::updateRec(
			MsdcQDatAPar* rec
		) {
	sqlite3_bind_int64(stmtUpdateRec, 1, rec->jref);
	sqlite3_bind_int(stmtUpdateRec, 2, rec->jnum);
	sqlite3_bind_int64(stmtUpdateRec, 3, rec->ref);
	sqlite3_bind_double(stmtUpdateRec, 4, rec->x1Start);
	sqlite3_bind_text(stmtUpdateRec, 5, rec->x2SrefKKey.c_str(), rec->x2SrefKKey.length(), SQLITE_STATIC);
	sqlite3_bind_int64(stmtUpdateRec, 6, rec->refMsdcMFile);
	sqlite3_bind_text(stmtUpdateRec, 7, rec->Val.c_str(), rec->Val.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtUpdateRec, 8, rec->Bindata.c_str(), rec->Bindata.length(), SQLITE_STATIC);
	sqlite3_bind_int64(stmtUpdateRec, 9, rec->qref);

	if (sqlite3_step(stmtUpdateRec) != SQLITE_DONE) throw DbsException("DbsException / SQLite: error executing statement! (TblMsdcQDatAPar / stmtUpdateRec)\n");

	sqlite3_reset(stmtUpdateRec);
};

void LiteTblMsdcQDatAPar::updateRst(
			ListMsdcQDatAPar& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void LiteTblMsdcQDatAPar::removeRecByQref(
			ubigint qref
		) {
	sqlite3_bind_int64(stmtRemoveRecByQref, 1, qref);

	if (sqlite3_step(stmtRemoveRecByQref) != SQLITE_DONE) throw DbsException("DbsException / SQLite: error executing statement! (TblMsdcQDatAPar / stmtRemoveRecByQref)\n");

	sqlite3_reset(stmtRemoveRecByQref);
};

void LiteTblMsdcQDatAPar::removeRstByJref(
			ubigint jref
		) {
	sqlite3_bind_int64(stmtRemoveRstByJref, 1, jref);

	if (sqlite3_step(stmtRemoveRstByJref) != SQLITE_DONE) throw DbsException("DbsException / SQLite: error executing statement! (TblMsdcQDatAPar / stmtRemoveRstByJref)\n");

	sqlite3_reset(stmtRemoveRstByJref);
};

bool LiteTblMsdcQDatAPar::loadRecByQref(
			ubigint qref
			, MsdcQDatAPar** rec
		) {
	sqlite3_bind_int64(stmtLoadRecByQref, 1, qref);

	return loadRecByStmt(stmtLoadRecByQref, rec);
};

ubigint LiteTblMsdcQDatAPar::loadRstByJref(
			ubigint jref
			, const bool append
			, ListMsdcQDatAPar& rst
		) {
	sqlite3_bind_int64(stmtLoadRstByJref, 1, jref);

	return loadRstByStmt(stmtLoadRstByJref, append, rst);
};

