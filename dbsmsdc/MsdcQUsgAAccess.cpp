/**
  * \file MsdcQUsgAAccess.cpp
  * Dbs and XML wrapper for table TblMsdcQUsgAAccess (implementation)
  * \author Alexander Wirthmueller
  * \date created: 12 Sep 2018
  * \date modified: 12 Sep 2018
  */

#include "MsdcQUsgAAccess.h"

/******************************************************************************
 class MsdcQUsgAAccess
 ******************************************************************************/

MsdcQUsgAAccess::MsdcQUsgAAccess(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint x1IxMsdcVFeatgroup
			, const string srefX1IxMsdcVFeatgroup
			, const string titX1IxMsdcVFeatgroup
			, const string x2FeaSrefUix
			, const uint ixMsdcWAccess
			, const string srefsIxMsdcWAccess
			, const string titsIxMsdcWAccess
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->x1IxMsdcVFeatgroup = x1IxMsdcVFeatgroup;
	this->srefX1IxMsdcVFeatgroup = srefX1IxMsdcVFeatgroup;
	this->titX1IxMsdcVFeatgroup = titX1IxMsdcVFeatgroup;
	this->x2FeaSrefUix = x2FeaSrefUix;
	this->ixMsdcWAccess = ixMsdcWAccess;
	this->srefsIxMsdcWAccess = srefsIxMsdcWAccess;
	this->titsIxMsdcWAccess = titsIxMsdcWAccess;
};

void MsdcQUsgAAccess::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "MsdcQUsgAAccess";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "feg", srefX1IxMsdcVFeatgroup);
		writeString(wr, "feg2", titX1IxMsdcVFeatgroup);
		writeString(wr, "fea", x2FeaSrefUix);
		writeString(wr, "acc", srefsIxMsdcWAccess);
		writeString(wr, "acc2", titsIxMsdcWAccess);
	} else {
		writeString(wr, "srefX1IxMsdcVFeatgroup", srefX1IxMsdcVFeatgroup);
		writeString(wr, "titX1IxMsdcVFeatgroup", titX1IxMsdcVFeatgroup);
		writeString(wr, "x2FeaSrefUix", x2FeaSrefUix);
		writeString(wr, "srefsIxMsdcWAccess", srefsIxMsdcWAccess);
		writeString(wr, "titsIxMsdcWAccess", titsIxMsdcWAccess);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListMsdcQUsgAAccess
 ******************************************************************************/

ListMsdcQUsgAAccess::ListMsdcQUsgAAccess() {
};

ListMsdcQUsgAAccess::ListMsdcQUsgAAccess(
			const ListMsdcQUsgAAccess& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new MsdcQUsgAAccess(*(src.nodes[i]));
};

ListMsdcQUsgAAccess::~ListMsdcQUsgAAccess() {
	clear();
};

void ListMsdcQUsgAAccess::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListMsdcQUsgAAccess::size() const {
	return(nodes.size());
};

void ListMsdcQUsgAAccess::append(
			MsdcQUsgAAccess* rec
		) {
	nodes.push_back(rec);
};

ListMsdcQUsgAAccess& ListMsdcQUsgAAccess::operator=(
			const ListMsdcQUsgAAccess& src
		) {
	MsdcQUsgAAccess* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new MsdcQUsgAAccess(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListMsdcQUsgAAccess::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListMsdcQUsgAAccess";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblMsdcQUsgAAccess
 ******************************************************************************/

TblMsdcQUsgAAccess::TblMsdcQUsgAAccess() {
};

TblMsdcQUsgAAccess::~TblMsdcQUsgAAccess() {
};

bool TblMsdcQUsgAAccess::loadRecBySQL(
			const string& sqlstr
			, MsdcQUsgAAccess** rec
		) {
	return false;
};

ubigint TblMsdcQUsgAAccess::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListMsdcQUsgAAccess& rst
		) {
	return 0;
};

void TblMsdcQUsgAAccess::insertRec(
			MsdcQUsgAAccess* rec
		) {
};

ubigint TblMsdcQUsgAAccess::insertNewRec(
			MsdcQUsgAAccess** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint x1IxMsdcVFeatgroup
			, const string srefX1IxMsdcVFeatgroup
			, const string titX1IxMsdcVFeatgroup
			, const string x2FeaSrefUix
			, const uint ixMsdcWAccess
			, const string srefsIxMsdcWAccess
			, const string titsIxMsdcWAccess
		) {
	ubigint retval = 0;
	MsdcQUsgAAccess* _rec = NULL;

	_rec = new MsdcQUsgAAccess(0, jref, jnum, ref, x1IxMsdcVFeatgroup, srefX1IxMsdcVFeatgroup, titX1IxMsdcVFeatgroup, x2FeaSrefUix, ixMsdcWAccess, srefsIxMsdcWAccess, titsIxMsdcWAccess);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblMsdcQUsgAAccess::appendNewRecToRst(
			ListMsdcQUsgAAccess& rst
			, MsdcQUsgAAccess** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint x1IxMsdcVFeatgroup
			, const string srefX1IxMsdcVFeatgroup
			, const string titX1IxMsdcVFeatgroup
			, const string x2FeaSrefUix
			, const uint ixMsdcWAccess
			, const string srefsIxMsdcWAccess
			, const string titsIxMsdcWAccess
		) {
	ubigint retval = 0;
	MsdcQUsgAAccess* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, x1IxMsdcVFeatgroup, srefX1IxMsdcVFeatgroup, titX1IxMsdcVFeatgroup, x2FeaSrefUix, ixMsdcWAccess, srefsIxMsdcWAccess, titsIxMsdcWAccess);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblMsdcQUsgAAccess::insertRst(
			ListMsdcQUsgAAccess& rst
		) {
};

void TblMsdcQUsgAAccess::updateRec(
			MsdcQUsgAAccess* rec
		) {
};

void TblMsdcQUsgAAccess::updateRst(
			ListMsdcQUsgAAccess& rst
		) {
};

void TblMsdcQUsgAAccess::removeRecByQref(
			ubigint qref
		) {
};

void TblMsdcQUsgAAccess::removeRstByJref(
			ubigint jref
		) {
};

bool TblMsdcQUsgAAccess::loadRecByQref(
			ubigint qref
			, MsdcQUsgAAccess** rec
		) {
	return false;
};

ubigint TblMsdcQUsgAAccess::loadRstByJref(
			ubigint jref
			, const bool append
			, ListMsdcQUsgAAccess& rst
		) {
	return 0;
};

/******************************************************************************
 class LiteTblMsdcQUsgAAccess
 ******************************************************************************/

LiteTblMsdcQUsgAAccess::LiteTblMsdcQUsgAAccess() :
			TblMsdcQUsgAAccess()
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

LiteTblMsdcQUsgAAccess::~LiteTblMsdcQUsgAAccess() {
	if (stmtInsertRec) sqlite3_finalize(stmtInsertRec);
	if (stmtUpdateRec) sqlite3_finalize(stmtUpdateRec);
	if (stmtRemoveRecByQref) sqlite3_finalize(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) sqlite3_finalize(stmtRemoveRstByJref);

	if (stmtLoadRecByQref) sqlite3_finalize(stmtLoadRecByQref);
	if (stmtLoadRecByJref) sqlite3_finalize(stmtLoadRecByJref);
	if (stmtLoadRstByJref) sqlite3_finalize(stmtLoadRstByJref);
};

void LiteTblMsdcQUsgAAccess::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblMsdcQUsgAAccess (jref, jnum, ref, x1IxMsdcVFeatgroup, x2FeaSrefUix, ixMsdcWAccess) VALUES (?1,?2,?3,?4,?5,?6)");
	stmtUpdateRec = createStatement("UPDATE TblMsdcQUsgAAccess SET jref = ?1, jnum = ?2, ref = ?3, x1IxMsdcVFeatgroup = ?4, x2FeaSrefUix = ?5, ixMsdcWAccess = ?6 WHERE qref = ?7");
	stmtRemoveRecByQref = createStatement("DELETE FROM TblMsdcQUsgAAccess WHERE qref = ?1");
	stmtRemoveRstByJref = createStatement("DELETE FROM TblMsdcQUsgAAccess WHERE jref = ?1");

	stmtLoadRecByQref = createStatement("SELECT qref, jref, jnum, ref, x1IxMsdcVFeatgroup, x2FeaSrefUix, ixMsdcWAccess FROM TblMsdcQUsgAAccess WHERE qref = ?1");
	stmtLoadRstByJref = createStatement("SELECT qref, jref, jnum, ref, x1IxMsdcVFeatgroup, x2FeaSrefUix, ixMsdcWAccess FROM TblMsdcQUsgAAccess WHERE jref = ?1 ORDER BY jnum ASC");
};

bool LiteTblMsdcQUsgAAccess::loadRec(
			sqlite3_stmt* stmt
			, MsdcQUsgAAccess** rec
		) {
	int res;

	MsdcQUsgAAccess* _rec = NULL;
	bool retval = false;

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		_rec = new MsdcQUsgAAccess();

		_rec->qref = sqlite3_column_int64(stmt, 0);
		_rec->jref = sqlite3_column_int64(stmt, 1);
		_rec->jnum = sqlite3_column_int(stmt, 2);
		_rec->ref = sqlite3_column_int64(stmt, 3);
		_rec->x1IxMsdcVFeatgroup = sqlite3_column_int(stmt, 4);
		_rec->x2FeaSrefUix.assign((const char*) sqlite3_column_text(stmt, 5));
		_rec->ixMsdcWAccess = sqlite3_column_int(stmt, 6);

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

ubigint LiteTblMsdcQUsgAAccess::loadRst(
			sqlite3_stmt* stmt
			, const bool append
			, ListMsdcQUsgAAccess& rst
		) {
	int res; ubigint numread = 0;

	MsdcQUsgAAccess* rec;

	if (!append) rst.clear();

	res = sqlite3_step(stmt);
	while (res == SQLITE_ROW) {
		rec = new MsdcQUsgAAccess();

		rec->qref = sqlite3_column_int64(stmt, 0);
		rec->jref = sqlite3_column_int64(stmt, 1);
		rec->jnum = sqlite3_column_int(stmt, 2);
		rec->ref = sqlite3_column_int64(stmt, 3);
		rec->x1IxMsdcVFeatgroup = sqlite3_column_int(stmt, 4);
		rec->x2FeaSrefUix.assign((const char*) sqlite3_column_text(stmt, 5));
		rec->ixMsdcWAccess = sqlite3_column_int(stmt, 6);

		rst.nodes.push_back(rec);

		numread++;

		res = sqlite3_step(stmt);
	};

	return(numread);
};

bool LiteTblMsdcQUsgAAccess::loadRecByStmt(
			sqlite3_stmt* stmt
			, MsdcQUsgAAccess** rec
		) {
	bool retval = loadRec(stmt, rec);

	sqlite3_reset(stmt);

	return retval;
};

ubigint LiteTblMsdcQUsgAAccess::loadRstByStmt(
			sqlite3_stmt* stmt
			, const bool append
			, ListMsdcQUsgAAccess& rst
		) {
	ubigint retval = loadRst(stmt, append, rst);

	sqlite3_reset(stmt);

	return retval;
};

bool LiteTblMsdcQUsgAAccess::loadRecBySQL(
			const string& sqlstr
			, MsdcQUsgAAccess** rec
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

ubigint LiteTblMsdcQUsgAAccess::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListMsdcQUsgAAccess& rst
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

void LiteTblMsdcQUsgAAccess::insertRec(
			MsdcQUsgAAccess* rec
		) {
	sqlite3_bind_int64(stmtInsertRec, 1, rec->jref);
	sqlite3_bind_int(stmtInsertRec, 2, rec->jnum);
	sqlite3_bind_int64(stmtInsertRec, 3, rec->ref);
	sqlite3_bind_int(stmtInsertRec, 4, rec->x1IxMsdcVFeatgroup);
	sqlite3_bind_text(stmtInsertRec, 5, rec->x2FeaSrefUix.c_str(), rec->x2FeaSrefUix.length(), SQLITE_STATIC);
	sqlite3_bind_int(stmtInsertRec, 6, rec->ixMsdcWAccess);

	if (sqlite3_step(stmtInsertRec) != SQLITE_DONE) throw DbsException("DbsException / SQLite: error executing statement! (TblMsdcQUsgAAccess / stmtInsertRec)\n");

	rec->qref = sqlite3_last_insert_rowid(dbs);

	sqlite3_reset(stmtInsertRec);
};

void LiteTblMsdcQUsgAAccess::insertRst(
			ListMsdcQUsgAAccess& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void LiteTblMsdcQUsgAAccess::updateRec(
			MsdcQUsgAAccess* rec
		) {
	sqlite3_bind_int64(stmtUpdateRec, 1, rec->jref);
	sqlite3_bind_int(stmtUpdateRec, 2, rec->jnum);
	sqlite3_bind_int64(stmtUpdateRec, 3, rec->ref);
	sqlite3_bind_int(stmtUpdateRec, 4, rec->x1IxMsdcVFeatgroup);
	sqlite3_bind_text(stmtUpdateRec, 5, rec->x2FeaSrefUix.c_str(), rec->x2FeaSrefUix.length(), SQLITE_STATIC);
	sqlite3_bind_int(stmtUpdateRec, 6, rec->ixMsdcWAccess);
	sqlite3_bind_int64(stmtUpdateRec, 7, rec->qref);

	if (sqlite3_step(stmtUpdateRec) != SQLITE_DONE) throw DbsException("DbsException / SQLite: error executing statement! (TblMsdcQUsgAAccess / stmtUpdateRec)\n");

	sqlite3_reset(stmtUpdateRec);
};

void LiteTblMsdcQUsgAAccess::updateRst(
			ListMsdcQUsgAAccess& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void LiteTblMsdcQUsgAAccess::removeRecByQref(
			ubigint qref
		) {
	sqlite3_bind_int64(stmtRemoveRecByQref, 1, qref);

	if (sqlite3_step(stmtRemoveRecByQref) != SQLITE_DONE) throw DbsException("DbsException / SQLite: error executing statement! (TblMsdcQUsgAAccess / stmtRemoveRecByQref)\n");

	sqlite3_reset(stmtRemoveRecByQref);
};

void LiteTblMsdcQUsgAAccess::removeRstByJref(
			ubigint jref
		) {
	sqlite3_bind_int64(stmtRemoveRstByJref, 1, jref);

	if (sqlite3_step(stmtRemoveRstByJref) != SQLITE_DONE) throw DbsException("DbsException / SQLite: error executing statement! (TblMsdcQUsgAAccess / stmtRemoveRstByJref)\n");

	sqlite3_reset(stmtRemoveRstByJref);
};

bool LiteTblMsdcQUsgAAccess::loadRecByQref(
			ubigint qref
			, MsdcQUsgAAccess** rec
		) {
	sqlite3_bind_int64(stmtLoadRecByQref, 1, qref);

	return loadRecByStmt(stmtLoadRecByQref, rec);
};

ubigint LiteTblMsdcQUsgAAccess::loadRstByJref(
			ubigint jref
			, const bool append
			, ListMsdcQUsgAAccess& rst
		) {
	sqlite3_bind_int64(stmtLoadRstByJref, 1, jref);

	return loadRstByStmt(stmtLoadRstByJref, append, rst);
};

