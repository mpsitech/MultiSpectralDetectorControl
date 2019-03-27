/**
  * \file MsdcQUsrList.cpp
  * Dbs and XML wrapper for table TblMsdcQUsrList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 18 Dec 2018
  * \date modified: 18 Dec 2018
  */

#include "MsdcQUsrList.h"

/******************************************************************************
 class MsdcQUsrList
 ******************************************************************************/

MsdcQUsrList::MsdcQUsrList(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint refMsdcMPerson
			, const string stubRefMsdcMPerson
			, const string sref
			, const ubigint refMsdcMUsergroup
			, const string stubRefMsdcMUsergroup
			, const uint ixVState
			, const string srefIxVState
			, const string titIxVState
			, const uint ixMsdcVLocale
			, const string srefIxMsdcVLocale
			, const string titIxMsdcVLocale
			, const uint ixMsdcVUserlevel
			, const string srefIxMsdcVUserlevel
			, const string titIxMsdcVUserlevel
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->refMsdcMPerson = refMsdcMPerson;
	this->stubRefMsdcMPerson = stubRefMsdcMPerson;
	this->sref = sref;
	this->refMsdcMUsergroup = refMsdcMUsergroup;
	this->stubRefMsdcMUsergroup = stubRefMsdcMUsergroup;
	this->ixVState = ixVState;
	this->srefIxVState = srefIxVState;
	this->titIxVState = titIxVState;
	this->ixMsdcVLocale = ixMsdcVLocale;
	this->srefIxMsdcVLocale = srefIxMsdcVLocale;
	this->titIxMsdcVLocale = titIxMsdcVLocale;
	this->ixMsdcVUserlevel = ixMsdcVUserlevel;
	this->srefIxMsdcVUserlevel = srefIxMsdcVUserlevel;
	this->titIxMsdcVUserlevel = titIxMsdcVUserlevel;
};

void MsdcQUsrList::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "MsdcQUsrList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "prs", stubRefMsdcMPerson);
		writeString(wr, "srf", sref);
		writeString(wr, "usg", stubRefMsdcMUsergroup);
		writeString(wr, "ste", srefIxVState);
		writeString(wr, "ste2", titIxVState);
		writeString(wr, "lcl", srefIxMsdcVLocale);
		writeString(wr, "lcl2", titIxMsdcVLocale);
		writeString(wr, "ulv", srefIxMsdcVUserlevel);
		writeString(wr, "ulv2", titIxMsdcVUserlevel);
	} else {
		writeString(wr, "stubRefMsdcMPerson", stubRefMsdcMPerson);
		writeString(wr, "sref", sref);
		writeString(wr, "stubRefMsdcMUsergroup", stubRefMsdcMUsergroup);
		writeString(wr, "srefIxVState", srefIxVState);
		writeString(wr, "titIxVState", titIxVState);
		writeString(wr, "srefIxMsdcVLocale", srefIxMsdcVLocale);
		writeString(wr, "titIxMsdcVLocale", titIxMsdcVLocale);
		writeString(wr, "srefIxMsdcVUserlevel", srefIxMsdcVUserlevel);
		writeString(wr, "titIxMsdcVUserlevel", titIxMsdcVUserlevel);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListMsdcQUsrList
 ******************************************************************************/

ListMsdcQUsrList::ListMsdcQUsrList() {
};

ListMsdcQUsrList::ListMsdcQUsrList(
			const ListMsdcQUsrList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new MsdcQUsrList(*(src.nodes[i]));
};

ListMsdcQUsrList::~ListMsdcQUsrList() {
	clear();
};

void ListMsdcQUsrList::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListMsdcQUsrList::size() const {
	return(nodes.size());
};

void ListMsdcQUsrList::append(
			MsdcQUsrList* rec
		) {
	nodes.push_back(rec);
};

ListMsdcQUsrList& ListMsdcQUsrList::operator=(
			const ListMsdcQUsrList& src
		) {
	MsdcQUsrList* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new MsdcQUsrList(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListMsdcQUsrList::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListMsdcQUsrList";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblMsdcQUsrList
 ******************************************************************************/

TblMsdcQUsrList::TblMsdcQUsrList() {
};

TblMsdcQUsrList::~TblMsdcQUsrList() {
};

bool TblMsdcQUsrList::loadRecBySQL(
			const string& sqlstr
			, MsdcQUsrList** rec
		) {
	return false;
};

ubigint TblMsdcQUsrList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListMsdcQUsrList& rst
		) {
	return 0;
};

void TblMsdcQUsrList::insertRec(
			MsdcQUsrList* rec
		) {
};

ubigint TblMsdcQUsrList::insertNewRec(
			MsdcQUsrList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint refMsdcMPerson
			, const string stubRefMsdcMPerson
			, const string sref
			, const ubigint refMsdcMUsergroup
			, const string stubRefMsdcMUsergroup
			, const uint ixVState
			, const string srefIxVState
			, const string titIxVState
			, const uint ixMsdcVLocale
			, const string srefIxMsdcVLocale
			, const string titIxMsdcVLocale
			, const uint ixMsdcVUserlevel
			, const string srefIxMsdcVUserlevel
			, const string titIxMsdcVUserlevel
		) {
	ubigint retval = 0;
	MsdcQUsrList* _rec = NULL;

	_rec = new MsdcQUsrList(0, jref, jnum, ref, refMsdcMPerson, stubRefMsdcMPerson, sref, refMsdcMUsergroup, stubRefMsdcMUsergroup, ixVState, srefIxVState, titIxVState, ixMsdcVLocale, srefIxMsdcVLocale, titIxMsdcVLocale, ixMsdcVUserlevel, srefIxMsdcVUserlevel, titIxMsdcVUserlevel);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblMsdcQUsrList::appendNewRecToRst(
			ListMsdcQUsrList& rst
			, MsdcQUsrList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint refMsdcMPerson
			, const string stubRefMsdcMPerson
			, const string sref
			, const ubigint refMsdcMUsergroup
			, const string stubRefMsdcMUsergroup
			, const uint ixVState
			, const string srefIxVState
			, const string titIxVState
			, const uint ixMsdcVLocale
			, const string srefIxMsdcVLocale
			, const string titIxMsdcVLocale
			, const uint ixMsdcVUserlevel
			, const string srefIxMsdcVUserlevel
			, const string titIxMsdcVUserlevel
		) {
	ubigint retval = 0;
	MsdcQUsrList* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, refMsdcMPerson, stubRefMsdcMPerson, sref, refMsdcMUsergroup, stubRefMsdcMUsergroup, ixVState, srefIxVState, titIxVState, ixMsdcVLocale, srefIxMsdcVLocale, titIxMsdcVLocale, ixMsdcVUserlevel, srefIxMsdcVUserlevel, titIxMsdcVUserlevel);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblMsdcQUsrList::insertRst(
			ListMsdcQUsrList& rst
		) {
};

void TblMsdcQUsrList::updateRec(
			MsdcQUsrList* rec
		) {
};

void TblMsdcQUsrList::updateRst(
			ListMsdcQUsrList& rst
		) {
};

void TblMsdcQUsrList::removeRecByQref(
			ubigint qref
		) {
};

void TblMsdcQUsrList::removeRstByJref(
			ubigint jref
		) {
};

bool TblMsdcQUsrList::loadRecByQref(
			ubigint qref
			, MsdcQUsrList** rec
		) {
	return false;
};

ubigint TblMsdcQUsrList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListMsdcQUsrList& rst
		) {
	return 0;
};

/******************************************************************************
 class LiteTblMsdcQUsrList
 ******************************************************************************/

LiteTblMsdcQUsrList::LiteTblMsdcQUsrList() :
			TblMsdcQUsrList()
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

LiteTblMsdcQUsrList::~LiteTblMsdcQUsrList() {
	if (stmtInsertRec) sqlite3_finalize(stmtInsertRec);
	if (stmtUpdateRec) sqlite3_finalize(stmtUpdateRec);
	if (stmtRemoveRecByQref) sqlite3_finalize(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) sqlite3_finalize(stmtRemoveRstByJref);

	if (stmtLoadRecByQref) sqlite3_finalize(stmtLoadRecByQref);
	if (stmtLoadRecByJref) sqlite3_finalize(stmtLoadRecByJref);
	if (stmtLoadRstByJref) sqlite3_finalize(stmtLoadRstByJref);
};

void LiteTblMsdcQUsrList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblMsdcQUsrList (jref, jnum, ref, refMsdcMPerson, sref, refMsdcMUsergroup, ixVState, ixMsdcVLocale, ixMsdcVUserlevel) VALUES (?1,?2,?3,?4,?5,?6,?7,?8,?9)");
	stmtUpdateRec = createStatement("UPDATE TblMsdcQUsrList SET jref = ?1, jnum = ?2, ref = ?3, refMsdcMPerson = ?4, sref = ?5, refMsdcMUsergroup = ?6, ixVState = ?7, ixMsdcVLocale = ?8, ixMsdcVUserlevel = ?9 WHERE qref = ?10");
	stmtRemoveRecByQref = createStatement("DELETE FROM TblMsdcQUsrList WHERE qref = ?1");
	stmtRemoveRstByJref = createStatement("DELETE FROM TblMsdcQUsrList WHERE jref = ?1");

	stmtLoadRecByQref = createStatement("SELECT qref, jref, jnum, ref, refMsdcMPerson, sref, refMsdcMUsergroup, ixVState, ixMsdcVLocale, ixMsdcVUserlevel FROM TblMsdcQUsrList WHERE qref = ?1");
	stmtLoadRstByJref = createStatement("SELECT qref, jref, jnum, ref, refMsdcMPerson, sref, refMsdcMUsergroup, ixVState, ixMsdcVLocale, ixMsdcVUserlevel FROM TblMsdcQUsrList WHERE jref = ?1 ORDER BY jnum ASC");
};

bool LiteTblMsdcQUsrList::loadRec(
			sqlite3_stmt* stmt
			, MsdcQUsrList** rec
		) {
	int res;

	MsdcQUsrList* _rec = NULL;
	bool retval = false;

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		_rec = new MsdcQUsrList();

		_rec->qref = sqlite3_column_int64(stmt, 0);
		_rec->jref = sqlite3_column_int64(stmt, 1);
		_rec->jnum = sqlite3_column_int(stmt, 2);
		_rec->ref = sqlite3_column_int64(stmt, 3);
		_rec->refMsdcMPerson = sqlite3_column_int64(stmt, 4);
		_rec->sref.assign((const char*) sqlite3_column_text(stmt, 5));
		_rec->refMsdcMUsergroup = sqlite3_column_int64(stmt, 6);
		_rec->ixVState = sqlite3_column_int(stmt, 7);
		_rec->ixMsdcVLocale = sqlite3_column_int(stmt, 8);
		_rec->ixMsdcVUserlevel = sqlite3_column_int(stmt, 9);

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

ubigint LiteTblMsdcQUsrList::loadRst(
			sqlite3_stmt* stmt
			, const bool append
			, ListMsdcQUsrList& rst
		) {
	int res; ubigint numread = 0;

	MsdcQUsrList* rec;

	if (!append) rst.clear();

	res = sqlite3_step(stmt);
	while (res == SQLITE_ROW) {
		rec = new MsdcQUsrList();

		rec->qref = sqlite3_column_int64(stmt, 0);
		rec->jref = sqlite3_column_int64(stmt, 1);
		rec->jnum = sqlite3_column_int(stmt, 2);
		rec->ref = sqlite3_column_int64(stmt, 3);
		rec->refMsdcMPerson = sqlite3_column_int64(stmt, 4);
		rec->sref.assign((const char*) sqlite3_column_text(stmt, 5));
		rec->refMsdcMUsergroup = sqlite3_column_int64(stmt, 6);
		rec->ixVState = sqlite3_column_int(stmt, 7);
		rec->ixMsdcVLocale = sqlite3_column_int(stmt, 8);
		rec->ixMsdcVUserlevel = sqlite3_column_int(stmt, 9);

		rst.nodes.push_back(rec);

		numread++;

		res = sqlite3_step(stmt);
	};

	return(numread);
};

bool LiteTblMsdcQUsrList::loadRecByStmt(
			sqlite3_stmt* stmt
			, MsdcQUsrList** rec
		) {
	bool retval = loadRec(stmt, rec);

	sqlite3_reset(stmt);

	return retval;
};

ubigint LiteTblMsdcQUsrList::loadRstByStmt(
			sqlite3_stmt* stmt
			, const bool append
			, ListMsdcQUsrList& rst
		) {
	ubigint retval = loadRst(stmt, append, rst);

	sqlite3_reset(stmt);

	return retval;
};

bool LiteTblMsdcQUsrList::loadRecBySQL(
			const string& sqlstr
			, MsdcQUsrList** rec
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

ubigint LiteTblMsdcQUsrList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListMsdcQUsrList& rst
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

void LiteTblMsdcQUsrList::insertRec(
			MsdcQUsrList* rec
		) {
	sqlite3_bind_int64(stmtInsertRec, 1, rec->jref);
	sqlite3_bind_int(stmtInsertRec, 2, rec->jnum);
	sqlite3_bind_int64(stmtInsertRec, 3, rec->ref);
	sqlite3_bind_int64(stmtInsertRec, 4, rec->refMsdcMPerson);
	sqlite3_bind_text(stmtInsertRec, 5, rec->sref.c_str(), rec->sref.length(), SQLITE_STATIC);
	sqlite3_bind_int64(stmtInsertRec, 6, rec->refMsdcMUsergroup);
	sqlite3_bind_int(stmtInsertRec, 7, rec->ixVState);
	sqlite3_bind_int(stmtInsertRec, 8, rec->ixMsdcVLocale);
	sqlite3_bind_int(stmtInsertRec, 9, rec->ixMsdcVUserlevel);

	if (sqlite3_step(stmtInsertRec) != SQLITE_DONE) throw DbsException("DbsException / SQLite: error executing statement! (TblMsdcQUsrList / stmtInsertRec)\n");

	rec->qref = sqlite3_last_insert_rowid(dbs);

	sqlite3_reset(stmtInsertRec);
};

void LiteTblMsdcQUsrList::insertRst(
			ListMsdcQUsrList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void LiteTblMsdcQUsrList::updateRec(
			MsdcQUsrList* rec
		) {
	sqlite3_bind_int64(stmtUpdateRec, 1, rec->jref);
	sqlite3_bind_int(stmtUpdateRec, 2, rec->jnum);
	sqlite3_bind_int64(stmtUpdateRec, 3, rec->ref);
	sqlite3_bind_int64(stmtUpdateRec, 4, rec->refMsdcMPerson);
	sqlite3_bind_text(stmtUpdateRec, 5, rec->sref.c_str(), rec->sref.length(), SQLITE_STATIC);
	sqlite3_bind_int64(stmtUpdateRec, 6, rec->refMsdcMUsergroup);
	sqlite3_bind_int(stmtUpdateRec, 7, rec->ixVState);
	sqlite3_bind_int(stmtUpdateRec, 8, rec->ixMsdcVLocale);
	sqlite3_bind_int(stmtUpdateRec, 9, rec->ixMsdcVUserlevel);
	sqlite3_bind_int64(stmtUpdateRec, 10, rec->qref);

	if (sqlite3_step(stmtUpdateRec) != SQLITE_DONE) throw DbsException("DbsException / SQLite: error executing statement! (TblMsdcQUsrList / stmtUpdateRec)\n");

	sqlite3_reset(stmtUpdateRec);
};

void LiteTblMsdcQUsrList::updateRst(
			ListMsdcQUsrList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void LiteTblMsdcQUsrList::removeRecByQref(
			ubigint qref
		) {
	sqlite3_bind_int64(stmtRemoveRecByQref, 1, qref);

	if (sqlite3_step(stmtRemoveRecByQref) != SQLITE_DONE) throw DbsException("DbsException / SQLite: error executing statement! (TblMsdcQUsrList / stmtRemoveRecByQref)\n");

	sqlite3_reset(stmtRemoveRecByQref);
};

void LiteTblMsdcQUsrList::removeRstByJref(
			ubigint jref
		) {
	sqlite3_bind_int64(stmtRemoveRstByJref, 1, jref);

	if (sqlite3_step(stmtRemoveRstByJref) != SQLITE_DONE) throw DbsException("DbsException / SQLite: error executing statement! (TblMsdcQUsrList / stmtRemoveRstByJref)\n");

	sqlite3_reset(stmtRemoveRstByJref);
};

bool LiteTblMsdcQUsrList::loadRecByQref(
			ubigint qref
			, MsdcQUsrList** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	sqlite3_bind_int64(stmtLoadRecByQref, 1, qref);

	return loadRecByStmt(stmtLoadRecByQref, rec);
};

ubigint LiteTblMsdcQUsrList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListMsdcQUsrList& rst
		) {
	sqlite3_bind_int64(stmtLoadRstByJref, 1, jref);

	return loadRstByStmt(stmtLoadRstByJref, append, rst);
};

