/**
  * \file MsdcQDatList.cpp
  * Dbs and XML wrapper for table TblMsdcQDatList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Oct 2018
  * \date modified: 4 Oct 2018
  */

#include "MsdcQDatList.h"

/******************************************************************************
 class MsdcQDatList
 ******************************************************************************/

MsdcQDatList::MsdcQDatList(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string srefMsdcKAcqfeat
			, const string titSrefMsdcKAcqfeat
			, const ubigint refMsdcMPeriod
			, const string stubRefMsdcMPeriod
			, const uint start
			, const string ftmStart
			, const uint stop
			, const string ftmStop
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->srefMsdcKAcqfeat = srefMsdcKAcqfeat;
	this->titSrefMsdcKAcqfeat = titSrefMsdcKAcqfeat;
	this->refMsdcMPeriod = refMsdcMPeriod;
	this->stubRefMsdcMPeriod = stubRefMsdcMPeriod;
	this->start = start;
	this->ftmStart = ftmStart;
	this->stop = stop;
	this->ftmStop = ftmStop;
};

void MsdcQDatList::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "MsdcQDatList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "aft", srefMsdcKAcqfeat);
		writeString(wr, "aft2", titSrefMsdcKAcqfeat);
		writeString(wr, "prd", stubRefMsdcMPeriod);
		writeString(wr, "sta", ftmStart);
		writeString(wr, "sto", ftmStop);
	} else {
		writeString(wr, "srefMsdcKAcqfeat", srefMsdcKAcqfeat);
		writeString(wr, "titSrefMsdcKAcqfeat", titSrefMsdcKAcqfeat);
		writeString(wr, "stubRefMsdcMPeriod", stubRefMsdcMPeriod);
		writeString(wr, "ftmStart", ftmStart);
		writeString(wr, "ftmStop", ftmStop);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListMsdcQDatList
 ******************************************************************************/

ListMsdcQDatList::ListMsdcQDatList() {
};

ListMsdcQDatList::ListMsdcQDatList(
			const ListMsdcQDatList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new MsdcQDatList(*(src.nodes[i]));
};

ListMsdcQDatList::~ListMsdcQDatList() {
	clear();
};

void ListMsdcQDatList::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListMsdcQDatList::size() const {
	return(nodes.size());
};

void ListMsdcQDatList::append(
			MsdcQDatList* rec
		) {
	nodes.push_back(rec);
};

ListMsdcQDatList& ListMsdcQDatList::operator=(
			const ListMsdcQDatList& src
		) {
	MsdcQDatList* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new MsdcQDatList(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListMsdcQDatList::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListMsdcQDatList";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblMsdcQDatList
 ******************************************************************************/

TblMsdcQDatList::TblMsdcQDatList() {
};

TblMsdcQDatList::~TblMsdcQDatList() {
};

bool TblMsdcQDatList::loadRecBySQL(
			const string& sqlstr
			, MsdcQDatList** rec
		) {
	return false;
};

ubigint TblMsdcQDatList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListMsdcQDatList& rst
		) {
	return 0;
};

void TblMsdcQDatList::insertRec(
			MsdcQDatList* rec
		) {
};

ubigint TblMsdcQDatList::insertNewRec(
			MsdcQDatList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string srefMsdcKAcqfeat
			, const string titSrefMsdcKAcqfeat
			, const ubigint refMsdcMPeriod
			, const string stubRefMsdcMPeriod
			, const uint start
			, const string ftmStart
			, const uint stop
			, const string ftmStop
		) {
	ubigint retval = 0;
	MsdcQDatList* _rec = NULL;

	_rec = new MsdcQDatList(0, jref, jnum, ref, srefMsdcKAcqfeat, titSrefMsdcKAcqfeat, refMsdcMPeriod, stubRefMsdcMPeriod, start, ftmStart, stop, ftmStop);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblMsdcQDatList::appendNewRecToRst(
			ListMsdcQDatList& rst
			, MsdcQDatList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string srefMsdcKAcqfeat
			, const string titSrefMsdcKAcqfeat
			, const ubigint refMsdcMPeriod
			, const string stubRefMsdcMPeriod
			, const uint start
			, const string ftmStart
			, const uint stop
			, const string ftmStop
		) {
	ubigint retval = 0;
	MsdcQDatList* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, srefMsdcKAcqfeat, titSrefMsdcKAcqfeat, refMsdcMPeriod, stubRefMsdcMPeriod, start, ftmStart, stop, ftmStop);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblMsdcQDatList::insertRst(
			ListMsdcQDatList& rst
		) {
};

void TblMsdcQDatList::updateRec(
			MsdcQDatList* rec
		) {
};

void TblMsdcQDatList::updateRst(
			ListMsdcQDatList& rst
		) {
};

void TblMsdcQDatList::removeRecByQref(
			ubigint qref
		) {
};

void TblMsdcQDatList::removeRstByJref(
			ubigint jref
		) {
};

bool TblMsdcQDatList::loadRecByQref(
			ubigint qref
			, MsdcQDatList** rec
		) {
	return false;
};

ubigint TblMsdcQDatList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListMsdcQDatList& rst
		) {
	return 0;
};

/******************************************************************************
 class LiteTblMsdcQDatList
 ******************************************************************************/

LiteTblMsdcQDatList::LiteTblMsdcQDatList() :
			TblMsdcQDatList()
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

LiteTblMsdcQDatList::~LiteTblMsdcQDatList() {
	if (stmtInsertRec) sqlite3_finalize(stmtInsertRec);
	if (stmtUpdateRec) sqlite3_finalize(stmtUpdateRec);
	if (stmtRemoveRecByQref) sqlite3_finalize(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) sqlite3_finalize(stmtRemoveRstByJref);

	if (stmtLoadRecByQref) sqlite3_finalize(stmtLoadRecByQref);
	if (stmtLoadRecByJref) sqlite3_finalize(stmtLoadRecByJref);
	if (stmtLoadRstByJref) sqlite3_finalize(stmtLoadRstByJref);
};

void LiteTblMsdcQDatList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblMsdcQDatList (jref, jnum, ref, srefMsdcKAcqfeat, refMsdcMPeriod, start, stop) VALUES (?1,?2,?3,?4,?5,?6,?7)");
	stmtUpdateRec = createStatement("UPDATE TblMsdcQDatList SET jref = ?1, jnum = ?2, ref = ?3, srefMsdcKAcqfeat = ?4, refMsdcMPeriod = ?5, start = ?6, stop = ?7 WHERE qref = ?8");
	stmtRemoveRecByQref = createStatement("DELETE FROM TblMsdcQDatList WHERE qref = ?1");
	stmtRemoveRstByJref = createStatement("DELETE FROM TblMsdcQDatList WHERE jref = ?1");

	stmtLoadRecByQref = createStatement("SELECT qref, jref, jnum, ref, srefMsdcKAcqfeat, refMsdcMPeriod, start, stop FROM TblMsdcQDatList WHERE qref = ?1");
	stmtLoadRstByJref = createStatement("SELECT qref, jref, jnum, ref, srefMsdcKAcqfeat, refMsdcMPeriod, start, stop FROM TblMsdcQDatList WHERE jref = ?1 ORDER BY jnum ASC");
};

bool LiteTblMsdcQDatList::loadRec(
			sqlite3_stmt* stmt
			, MsdcQDatList** rec
		) {
	int res;

	MsdcQDatList* _rec = NULL;
	bool retval = false;

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		_rec = new MsdcQDatList();

		_rec->qref = sqlite3_column_int64(stmt, 0);
		_rec->jref = sqlite3_column_int64(stmt, 1);
		_rec->jnum = sqlite3_column_int(stmt, 2);
		_rec->ref = sqlite3_column_int64(stmt, 3);
		_rec->srefMsdcKAcqfeat.assign((const char*) sqlite3_column_text(stmt, 4));
		_rec->refMsdcMPeriod = sqlite3_column_int64(stmt, 5);
		_rec->start = sqlite3_column_int(stmt, 6);
		_rec->stop = sqlite3_column_int(stmt, 7);

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

ubigint LiteTblMsdcQDatList::loadRst(
			sqlite3_stmt* stmt
			, const bool append
			, ListMsdcQDatList& rst
		) {
	int res; ubigint numread = 0;

	MsdcQDatList* rec;

	if (!append) rst.clear();

	res = sqlite3_step(stmt);
	while (res == SQLITE_ROW) {
		rec = new MsdcQDatList();

		rec->qref = sqlite3_column_int64(stmt, 0);
		rec->jref = sqlite3_column_int64(stmt, 1);
		rec->jnum = sqlite3_column_int(stmt, 2);
		rec->ref = sqlite3_column_int64(stmt, 3);
		rec->srefMsdcKAcqfeat.assign((const char*) sqlite3_column_text(stmt, 4));
		rec->refMsdcMPeriod = sqlite3_column_int64(stmt, 5);
		rec->start = sqlite3_column_int(stmt, 6);
		rec->stop = sqlite3_column_int(stmt, 7);

		rst.nodes.push_back(rec);

		numread++;

		res = sqlite3_step(stmt);
	};

	return(numread);
};

bool LiteTblMsdcQDatList::loadRecByStmt(
			sqlite3_stmt* stmt
			, MsdcQDatList** rec
		) {
	bool retval = loadRec(stmt, rec);

	sqlite3_reset(stmt);

	return retval;
};

ubigint LiteTblMsdcQDatList::loadRstByStmt(
			sqlite3_stmt* stmt
			, const bool append
			, ListMsdcQDatList& rst
		) {
	ubigint retval = loadRst(stmt, append, rst);

	sqlite3_reset(stmt);

	return retval;
};

bool LiteTblMsdcQDatList::loadRecBySQL(
			const string& sqlstr
			, MsdcQDatList** rec
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

ubigint LiteTblMsdcQDatList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListMsdcQDatList& rst
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

void LiteTblMsdcQDatList::insertRec(
			MsdcQDatList* rec
		) {
	sqlite3_bind_int64(stmtInsertRec, 1, rec->jref);
	sqlite3_bind_int(stmtInsertRec, 2, rec->jnum);
	sqlite3_bind_int64(stmtInsertRec, 3, rec->ref);
	sqlite3_bind_text(stmtInsertRec, 4, rec->srefMsdcKAcqfeat.c_str(), rec->srefMsdcKAcqfeat.length(), SQLITE_STATIC);
	sqlite3_bind_int64(stmtInsertRec, 5, rec->refMsdcMPeriod);
	sqlite3_bind_int(stmtInsertRec, 6, rec->start);
	sqlite3_bind_int(stmtInsertRec, 7, rec->stop);

	if (sqlite3_step(stmtInsertRec) != SQLITE_DONE) throw DbsException("DbsException / SQLite: error executing statement! (TblMsdcQDatList / stmtInsertRec)\n");

	rec->qref = sqlite3_last_insert_rowid(dbs);

	sqlite3_reset(stmtInsertRec);
};

void LiteTblMsdcQDatList::insertRst(
			ListMsdcQDatList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void LiteTblMsdcQDatList::updateRec(
			MsdcQDatList* rec
		) {
	sqlite3_bind_int64(stmtUpdateRec, 1, rec->jref);
	sqlite3_bind_int(stmtUpdateRec, 2, rec->jnum);
	sqlite3_bind_int64(stmtUpdateRec, 3, rec->ref);
	sqlite3_bind_text(stmtUpdateRec, 4, rec->srefMsdcKAcqfeat.c_str(), rec->srefMsdcKAcqfeat.length(), SQLITE_STATIC);
	sqlite3_bind_int64(stmtUpdateRec, 5, rec->refMsdcMPeriod);
	sqlite3_bind_int(stmtUpdateRec, 6, rec->start);
	sqlite3_bind_int(stmtUpdateRec, 7, rec->stop);
	sqlite3_bind_int64(stmtUpdateRec, 8, rec->qref);

	if (sqlite3_step(stmtUpdateRec) != SQLITE_DONE) throw DbsException("DbsException / SQLite: error executing statement! (TblMsdcQDatList / stmtUpdateRec)\n");

	sqlite3_reset(stmtUpdateRec);
};

void LiteTblMsdcQDatList::updateRst(
			ListMsdcQDatList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void LiteTblMsdcQDatList::removeRecByQref(
			ubigint qref
		) {
	sqlite3_bind_int64(stmtRemoveRecByQref, 1, qref);

	if (sqlite3_step(stmtRemoveRecByQref) != SQLITE_DONE) throw DbsException("DbsException / SQLite: error executing statement! (TblMsdcQDatList / stmtRemoveRecByQref)\n");

	sqlite3_reset(stmtRemoveRecByQref);
};

void LiteTblMsdcQDatList::removeRstByJref(
			ubigint jref
		) {
	sqlite3_bind_int64(stmtRemoveRstByJref, 1, jref);

	if (sqlite3_step(stmtRemoveRstByJref) != SQLITE_DONE) throw DbsException("DbsException / SQLite: error executing statement! (TblMsdcQDatList / stmtRemoveRstByJref)\n");

	sqlite3_reset(stmtRemoveRstByJref);
};

bool LiteTblMsdcQDatList::loadRecByQref(
			ubigint qref
			, MsdcQDatList** rec
		) {
	if (qref == 0) return false;

	sqlite3_bind_int64(stmtLoadRecByQref, 1, qref);

	return loadRecByStmt(stmtLoadRecByQref, rec);
};

ubigint LiteTblMsdcQDatList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListMsdcQDatList& rst
		) {
	sqlite3_bind_int64(stmtLoadRstByJref, 1, jref);

	return loadRstByStmt(stmtLoadRstByJref, append, rst);
};

