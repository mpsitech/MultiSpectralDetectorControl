/**
  * \file MsdcQDatRef1NFile.cpp
  * Dbs and XML wrapper for table TblMsdcQDatRef1NFile (implementation)
  * \author Alexander Wirthmueller
  * \date created: 29 Aug 2018
  * \date modified: 29 Aug 2018
  */

#include "MsdcQDatRef1NFile.h"

/******************************************************************************
 class MsdcQDatRef1NFile
 ******************************************************************************/

MsdcQDatRef1NFile::MsdcQDatRef1NFile(
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

void MsdcQDatRef1NFile::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "MsdcQDatRef1NFile";

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
 class ListMsdcQDatRef1NFile
 ******************************************************************************/

ListMsdcQDatRef1NFile::ListMsdcQDatRef1NFile() {
};

ListMsdcQDatRef1NFile::ListMsdcQDatRef1NFile(
			const ListMsdcQDatRef1NFile& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new MsdcQDatRef1NFile(*(src.nodes[i]));
};

ListMsdcQDatRef1NFile::~ListMsdcQDatRef1NFile() {
	clear();
};

void ListMsdcQDatRef1NFile::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListMsdcQDatRef1NFile::size() const {
	return(nodes.size());
};

void ListMsdcQDatRef1NFile::append(
			MsdcQDatRef1NFile* rec
		) {
	nodes.push_back(rec);
};

ListMsdcQDatRef1NFile& ListMsdcQDatRef1NFile::operator=(
			const ListMsdcQDatRef1NFile& src
		) {
	MsdcQDatRef1NFile* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new MsdcQDatRef1NFile(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListMsdcQDatRef1NFile::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListMsdcQDatRef1NFile";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblMsdcQDatRef1NFile
 ******************************************************************************/

TblMsdcQDatRef1NFile::TblMsdcQDatRef1NFile() {
};

TblMsdcQDatRef1NFile::~TblMsdcQDatRef1NFile() {
};

bool TblMsdcQDatRef1NFile::loadRecBySQL(
			const string& sqlstr
			, MsdcQDatRef1NFile** rec
		) {
	return false;
};

ubigint TblMsdcQDatRef1NFile::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListMsdcQDatRef1NFile& rst
		) {
	return 0;
};

void TblMsdcQDatRef1NFile::insertRec(
			MsdcQDatRef1NFile* rec
		) {
};

ubigint TblMsdcQDatRef1NFile::insertNewRec(
			MsdcQDatRef1NFile** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	MsdcQDatRef1NFile* _rec = NULL;

	_rec = new MsdcQDatRef1NFile(0, jref, jnum, ref, stubRef);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblMsdcQDatRef1NFile::appendNewRecToRst(
			ListMsdcQDatRef1NFile& rst
			, MsdcQDatRef1NFile** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	MsdcQDatRef1NFile* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, stubRef);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblMsdcQDatRef1NFile::insertRst(
			ListMsdcQDatRef1NFile& rst
		) {
};

void TblMsdcQDatRef1NFile::updateRec(
			MsdcQDatRef1NFile* rec
		) {
};

void TblMsdcQDatRef1NFile::updateRst(
			ListMsdcQDatRef1NFile& rst
		) {
};

void TblMsdcQDatRef1NFile::removeRecByQref(
			ubigint qref
		) {
};

void TblMsdcQDatRef1NFile::removeRstByJref(
			ubigint jref
		) {
};

bool TblMsdcQDatRef1NFile::loadRecByQref(
			ubigint qref
			, MsdcQDatRef1NFile** rec
		) {
	return false;
};

ubigint TblMsdcQDatRef1NFile::loadRstByJref(
			ubigint jref
			, const bool append
			, ListMsdcQDatRef1NFile& rst
		) {
	return 0;
};

/******************************************************************************
 class LiteTblMsdcQDatRef1NFile
 ******************************************************************************/

LiteTblMsdcQDatRef1NFile::LiteTblMsdcQDatRef1NFile() :
			TblMsdcQDatRef1NFile()
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

LiteTblMsdcQDatRef1NFile::~LiteTblMsdcQDatRef1NFile() {
	if (stmtInsertRec) sqlite3_finalize(stmtInsertRec);
	if (stmtUpdateRec) sqlite3_finalize(stmtUpdateRec);
	if (stmtRemoveRecByQref) sqlite3_finalize(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) sqlite3_finalize(stmtRemoveRstByJref);

	if (stmtLoadRecByQref) sqlite3_finalize(stmtLoadRecByQref);
	if (stmtLoadRecByJref) sqlite3_finalize(stmtLoadRecByJref);
	if (stmtLoadRstByJref) sqlite3_finalize(stmtLoadRstByJref);
};

void LiteTblMsdcQDatRef1NFile::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblMsdcQDatRef1NFile (jref, jnum, ref) VALUES (?1,?2,?3)");
	stmtUpdateRec = createStatement("UPDATE TblMsdcQDatRef1NFile SET jref = ?1, jnum = ?2, ref = ?3 WHERE qref = ?4");
	stmtRemoveRecByQref = createStatement("DELETE FROM TblMsdcQDatRef1NFile WHERE qref = ?1");
	stmtRemoveRstByJref = createStatement("DELETE FROM TblMsdcQDatRef1NFile WHERE jref = ?1");

	stmtLoadRecByQref = createStatement("SELECT qref, jref, jnum, ref FROM TblMsdcQDatRef1NFile WHERE qref = ?1");
	stmtLoadRstByJref = createStatement("SELECT qref, jref, jnum, ref FROM TblMsdcQDatRef1NFile WHERE jref = ?1 ORDER BY jnum ASC");
};

bool LiteTblMsdcQDatRef1NFile::loadRec(
			sqlite3_stmt* stmt
			, MsdcQDatRef1NFile** rec
		) {
	int res;

	MsdcQDatRef1NFile* _rec = NULL;
	bool retval = false;

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		_rec = new MsdcQDatRef1NFile();

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

ubigint LiteTblMsdcQDatRef1NFile::loadRst(
			sqlite3_stmt* stmt
			, const bool append
			, ListMsdcQDatRef1NFile& rst
		) {
	int res; ubigint numread = 0;

	MsdcQDatRef1NFile* rec;

	if (!append) rst.clear();

	res = sqlite3_step(stmt);
	while (res == SQLITE_ROW) {
		rec = new MsdcQDatRef1NFile();

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

bool LiteTblMsdcQDatRef1NFile::loadRecByStmt(
			sqlite3_stmt* stmt
			, MsdcQDatRef1NFile** rec
		) {
	bool retval = loadRec(stmt, rec);

	sqlite3_reset(stmt);

	return retval;
};

ubigint LiteTblMsdcQDatRef1NFile::loadRstByStmt(
			sqlite3_stmt* stmt
			, const bool append
			, ListMsdcQDatRef1NFile& rst
		) {
	ubigint retval = loadRst(stmt, append, rst);

	sqlite3_reset(stmt);

	return retval;
};

bool LiteTblMsdcQDatRef1NFile::loadRecBySQL(
			const string& sqlstr
			, MsdcQDatRef1NFile** rec
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

ubigint LiteTblMsdcQDatRef1NFile::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListMsdcQDatRef1NFile& rst
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

void LiteTblMsdcQDatRef1NFile::insertRec(
			MsdcQDatRef1NFile* rec
		) {
	sqlite3_bind_int64(stmtInsertRec, 1, rec->jref);
	sqlite3_bind_int(stmtInsertRec, 2, rec->jnum);
	sqlite3_bind_int64(stmtInsertRec, 3, rec->ref);

	if (sqlite3_step(stmtInsertRec) != SQLITE_DONE) throw DbsException("DbsException / SQLite: error executing statement! (TblMsdcQDatRef1NFile / stmtInsertRec)\n");

	rec->qref = sqlite3_last_insert_rowid(dbs);

	sqlite3_reset(stmtInsertRec);
};

void LiteTblMsdcQDatRef1NFile::insertRst(
			ListMsdcQDatRef1NFile& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void LiteTblMsdcQDatRef1NFile::updateRec(
			MsdcQDatRef1NFile* rec
		) {
	sqlite3_bind_int64(stmtUpdateRec, 1, rec->jref);
	sqlite3_bind_int(stmtUpdateRec, 2, rec->jnum);
	sqlite3_bind_int64(stmtUpdateRec, 3, rec->ref);
	sqlite3_bind_int64(stmtUpdateRec, 4, rec->qref);

	if (sqlite3_step(stmtUpdateRec) != SQLITE_DONE) throw DbsException("DbsException / SQLite: error executing statement! (TblMsdcQDatRef1NFile / stmtUpdateRec)\n");

	sqlite3_reset(stmtUpdateRec);
};

void LiteTblMsdcQDatRef1NFile::updateRst(
			ListMsdcQDatRef1NFile& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void LiteTblMsdcQDatRef1NFile::removeRecByQref(
			ubigint qref
		) {
	sqlite3_bind_int64(stmtRemoveRecByQref, 1, qref);

	if (sqlite3_step(stmtRemoveRecByQref) != SQLITE_DONE) throw DbsException("DbsException / SQLite: error executing statement! (TblMsdcQDatRef1NFile / stmtRemoveRecByQref)\n");

	sqlite3_reset(stmtRemoveRecByQref);
};

void LiteTblMsdcQDatRef1NFile::removeRstByJref(
			ubigint jref
		) {
	sqlite3_bind_int64(stmtRemoveRstByJref, 1, jref);

	if (sqlite3_step(stmtRemoveRstByJref) != SQLITE_DONE) throw DbsException("DbsException / SQLite: error executing statement! (TblMsdcQDatRef1NFile / stmtRemoveRstByJref)\n");

	sqlite3_reset(stmtRemoveRstByJref);
};

bool LiteTblMsdcQDatRef1NFile::loadRecByQref(
			ubigint qref
			, MsdcQDatRef1NFile** rec
		) {
	sqlite3_bind_int64(stmtLoadRecByQref, 1, qref);

	return loadRecByStmt(stmtLoadRecByQref, rec);
};

ubigint LiteTblMsdcQDatRef1NFile::loadRstByJref(
			ubigint jref
			, const bool append
			, ListMsdcQDatRef1NFile& rst
		) {
	sqlite3_bind_int64(stmtLoadRstByJref, 1, jref);

	return loadRstByStmt(stmtLoadRstByJref, append, rst);
};

