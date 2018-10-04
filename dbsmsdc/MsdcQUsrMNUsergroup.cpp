/**
  * \file MsdcQUsrMNUsergroup.cpp
  * Dbs and XML wrapper for table TblMsdcQUsrMNUsergroup (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Oct 2018
  * \date modified: 4 Oct 2018
  */

#include "MsdcQUsrMNUsergroup.h"

/******************************************************************************
 class MsdcQUsrMNUsergroup
 ******************************************************************************/

MsdcQUsrMNUsergroup::MsdcQUsrMNUsergroup(
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

void MsdcQUsrMNUsergroup::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "MsdcQUsrMNUsergroup";

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
 class ListMsdcQUsrMNUsergroup
 ******************************************************************************/

ListMsdcQUsrMNUsergroup::ListMsdcQUsrMNUsergroup() {
};

ListMsdcQUsrMNUsergroup::ListMsdcQUsrMNUsergroup(
			const ListMsdcQUsrMNUsergroup& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new MsdcQUsrMNUsergroup(*(src.nodes[i]));
};

ListMsdcQUsrMNUsergroup::~ListMsdcQUsrMNUsergroup() {
	clear();
};

void ListMsdcQUsrMNUsergroup::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListMsdcQUsrMNUsergroup::size() const {
	return(nodes.size());
};

void ListMsdcQUsrMNUsergroup::append(
			MsdcQUsrMNUsergroup* rec
		) {
	nodes.push_back(rec);
};

ListMsdcQUsrMNUsergroup& ListMsdcQUsrMNUsergroup::operator=(
			const ListMsdcQUsrMNUsergroup& src
		) {
	MsdcQUsrMNUsergroup* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new MsdcQUsrMNUsergroup(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListMsdcQUsrMNUsergroup::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListMsdcQUsrMNUsergroup";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblMsdcQUsrMNUsergroup
 ******************************************************************************/

TblMsdcQUsrMNUsergroup::TblMsdcQUsrMNUsergroup() {
};

TblMsdcQUsrMNUsergroup::~TblMsdcQUsrMNUsergroup() {
};

bool TblMsdcQUsrMNUsergroup::loadRecBySQL(
			const string& sqlstr
			, MsdcQUsrMNUsergroup** rec
		) {
	return false;
};

ubigint TblMsdcQUsrMNUsergroup::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListMsdcQUsrMNUsergroup& rst
		) {
	return 0;
};

void TblMsdcQUsrMNUsergroup::insertRec(
			MsdcQUsrMNUsergroup* rec
		) {
};

ubigint TblMsdcQUsrMNUsergroup::insertNewRec(
			MsdcQUsrMNUsergroup** rec
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
	MsdcQUsrMNUsergroup* _rec = NULL;

	_rec = new MsdcQUsrMNUsergroup(0, jref, jnum, mref, stubMref, ref, ixMsdcVUserlevel, srefIxMsdcVUserlevel, titIxMsdcVUserlevel);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblMsdcQUsrMNUsergroup::appendNewRecToRst(
			ListMsdcQUsrMNUsergroup& rst
			, MsdcQUsrMNUsergroup** rec
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
	MsdcQUsrMNUsergroup* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, mref, stubMref, ref, ixMsdcVUserlevel, srefIxMsdcVUserlevel, titIxMsdcVUserlevel);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblMsdcQUsrMNUsergroup::insertRst(
			ListMsdcQUsrMNUsergroup& rst
		) {
};

void TblMsdcQUsrMNUsergroup::updateRec(
			MsdcQUsrMNUsergroup* rec
		) {
};

void TblMsdcQUsrMNUsergroup::updateRst(
			ListMsdcQUsrMNUsergroup& rst
		) {
};

void TblMsdcQUsrMNUsergroup::removeRecByQref(
			ubigint qref
		) {
};

void TblMsdcQUsrMNUsergroup::removeRstByJref(
			ubigint jref
		) {
};

bool TblMsdcQUsrMNUsergroup::loadRecByQref(
			ubigint qref
			, MsdcQUsrMNUsergroup** rec
		) {
	return false;
};

ubigint TblMsdcQUsrMNUsergroup::loadRstByJref(
			ubigint jref
			, const bool append
			, ListMsdcQUsrMNUsergroup& rst
		) {
	return 0;
};

/******************************************************************************
 class LiteTblMsdcQUsrMNUsergroup
 ******************************************************************************/

LiteTblMsdcQUsrMNUsergroup::LiteTblMsdcQUsrMNUsergroup() :
			TblMsdcQUsrMNUsergroup()
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

LiteTblMsdcQUsrMNUsergroup::~LiteTblMsdcQUsrMNUsergroup() {
	if (stmtInsertRec) sqlite3_finalize(stmtInsertRec);
	if (stmtUpdateRec) sqlite3_finalize(stmtUpdateRec);
	if (stmtRemoveRecByQref) sqlite3_finalize(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) sqlite3_finalize(stmtRemoveRstByJref);

	if (stmtLoadRecByQref) sqlite3_finalize(stmtLoadRecByQref);
	if (stmtLoadRecByJref) sqlite3_finalize(stmtLoadRecByJref);
	if (stmtLoadRstByJref) sqlite3_finalize(stmtLoadRstByJref);
};

void LiteTblMsdcQUsrMNUsergroup::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblMsdcQUsrMNUsergroup (jref, jnum, mref, ref, ixMsdcVUserlevel) VALUES (?1,?2,?3,?4,?5)");
	stmtUpdateRec = createStatement("UPDATE TblMsdcQUsrMNUsergroup SET jref = ?1, jnum = ?2, mref = ?3, ref = ?4, ixMsdcVUserlevel = ?5 WHERE qref = ?6");
	stmtRemoveRecByQref = createStatement("DELETE FROM TblMsdcQUsrMNUsergroup WHERE qref = ?1");
	stmtRemoveRstByJref = createStatement("DELETE FROM TblMsdcQUsrMNUsergroup WHERE jref = ?1");

	stmtLoadRecByQref = createStatement("SELECT qref, jref, jnum, mref, ref, ixMsdcVUserlevel FROM TblMsdcQUsrMNUsergroup WHERE qref = ?1");
	stmtLoadRstByJref = createStatement("SELECT qref, jref, jnum, mref, ref, ixMsdcVUserlevel FROM TblMsdcQUsrMNUsergroup WHERE jref = ?1 ORDER BY jnum ASC");
};

bool LiteTblMsdcQUsrMNUsergroup::loadRec(
			sqlite3_stmt* stmt
			, MsdcQUsrMNUsergroup** rec
		) {
	int res;

	MsdcQUsrMNUsergroup* _rec = NULL;
	bool retval = false;

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		_rec = new MsdcQUsrMNUsergroup();

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

ubigint LiteTblMsdcQUsrMNUsergroup::loadRst(
			sqlite3_stmt* stmt
			, const bool append
			, ListMsdcQUsrMNUsergroup& rst
		) {
	int res; ubigint numread = 0;

	MsdcQUsrMNUsergroup* rec;

	if (!append) rst.clear();

	res = sqlite3_step(stmt);
	while (res == SQLITE_ROW) {
		rec = new MsdcQUsrMNUsergroup();

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

bool LiteTblMsdcQUsrMNUsergroup::loadRecByStmt(
			sqlite3_stmt* stmt
			, MsdcQUsrMNUsergroup** rec
		) {
	bool retval = loadRec(stmt, rec);

	sqlite3_reset(stmt);

	return retval;
};

ubigint LiteTblMsdcQUsrMNUsergroup::loadRstByStmt(
			sqlite3_stmt* stmt
			, const bool append
			, ListMsdcQUsrMNUsergroup& rst
		) {
	ubigint retval = loadRst(stmt, append, rst);

	sqlite3_reset(stmt);

	return retval;
};

bool LiteTblMsdcQUsrMNUsergroup::loadRecBySQL(
			const string& sqlstr
			, MsdcQUsrMNUsergroup** rec
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

ubigint LiteTblMsdcQUsrMNUsergroup::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListMsdcQUsrMNUsergroup& rst
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

void LiteTblMsdcQUsrMNUsergroup::insertRec(
			MsdcQUsrMNUsergroup* rec
		) {
	sqlite3_bind_int64(stmtInsertRec, 1, rec->jref);
	sqlite3_bind_int(stmtInsertRec, 2, rec->jnum);
	sqlite3_bind_int64(stmtInsertRec, 3, rec->mref);
	sqlite3_bind_int64(stmtInsertRec, 4, rec->ref);
	sqlite3_bind_int(stmtInsertRec, 5, rec->ixMsdcVUserlevel);

	if (sqlite3_step(stmtInsertRec) != SQLITE_DONE) throw DbsException("DbsException / SQLite: error executing statement! (TblMsdcQUsrMNUsergroup / stmtInsertRec)\n");

	rec->qref = sqlite3_last_insert_rowid(dbs);

	sqlite3_reset(stmtInsertRec);
};

void LiteTblMsdcQUsrMNUsergroup::insertRst(
			ListMsdcQUsrMNUsergroup& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void LiteTblMsdcQUsrMNUsergroup::updateRec(
			MsdcQUsrMNUsergroup* rec
		) {
	sqlite3_bind_int64(stmtUpdateRec, 1, rec->jref);
	sqlite3_bind_int(stmtUpdateRec, 2, rec->jnum);
	sqlite3_bind_int64(stmtUpdateRec, 3, rec->mref);
	sqlite3_bind_int64(stmtUpdateRec, 4, rec->ref);
	sqlite3_bind_int(stmtUpdateRec, 5, rec->ixMsdcVUserlevel);
	sqlite3_bind_int64(stmtUpdateRec, 6, rec->qref);

	if (sqlite3_step(stmtUpdateRec) != SQLITE_DONE) throw DbsException("DbsException / SQLite: error executing statement! (TblMsdcQUsrMNUsergroup / stmtUpdateRec)\n");

	sqlite3_reset(stmtUpdateRec);
};

void LiteTblMsdcQUsrMNUsergroup::updateRst(
			ListMsdcQUsrMNUsergroup& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void LiteTblMsdcQUsrMNUsergroup::removeRecByQref(
			ubigint qref
		) {
	sqlite3_bind_int64(stmtRemoveRecByQref, 1, qref);

	if (sqlite3_step(stmtRemoveRecByQref) != SQLITE_DONE) throw DbsException("DbsException / SQLite: error executing statement! (TblMsdcQUsrMNUsergroup / stmtRemoveRecByQref)\n");

	sqlite3_reset(stmtRemoveRecByQref);
};

void LiteTblMsdcQUsrMNUsergroup::removeRstByJref(
			ubigint jref
		) {
	sqlite3_bind_int64(stmtRemoveRstByJref, 1, jref);

	if (sqlite3_step(stmtRemoveRstByJref) != SQLITE_DONE) throw DbsException("DbsException / SQLite: error executing statement! (TblMsdcQUsrMNUsergroup / stmtRemoveRstByJref)\n");

	sqlite3_reset(stmtRemoveRstByJref);
};

bool LiteTblMsdcQUsrMNUsergroup::loadRecByQref(
			ubigint qref
			, MsdcQUsrMNUsergroup** rec
		) {
	if (qref == 0) return false;

	sqlite3_bind_int64(stmtLoadRecByQref, 1, qref);

	return loadRecByStmt(stmtLoadRecByQref, rec);
};

ubigint LiteTblMsdcQUsrMNUsergroup::loadRstByJref(
			ubigint jref
			, const bool append
			, ListMsdcQUsrMNUsergroup& rst
		) {
	sqlite3_bind_int64(stmtLoadRstByJref, 1, jref);

	return loadRstByStmt(stmtLoadRstByJref, append, rst);
};

