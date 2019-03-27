/**
  * \file MsdcQUsrAAccess.cpp
  * Dbs and XML wrapper for table TblMsdcQUsrAAccess (implementation)
  * \author Alexander Wirthmueller
  * \date created: 18 Dec 2018
  * \date modified: 18 Dec 2018
  */

#include "MsdcQUsrAAccess.h"

/******************************************************************************
 class MsdcQUsrAAccess
 ******************************************************************************/

MsdcQUsrAAccess::MsdcQUsrAAccess(
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

void MsdcQUsrAAccess::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "MsdcQUsrAAccess";

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
 class ListMsdcQUsrAAccess
 ******************************************************************************/

ListMsdcQUsrAAccess::ListMsdcQUsrAAccess() {
};

ListMsdcQUsrAAccess::ListMsdcQUsrAAccess(
			const ListMsdcQUsrAAccess& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new MsdcQUsrAAccess(*(src.nodes[i]));
};

ListMsdcQUsrAAccess::~ListMsdcQUsrAAccess() {
	clear();
};

void ListMsdcQUsrAAccess::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListMsdcQUsrAAccess::size() const {
	return(nodes.size());
};

void ListMsdcQUsrAAccess::append(
			MsdcQUsrAAccess* rec
		) {
	nodes.push_back(rec);
};

ListMsdcQUsrAAccess& ListMsdcQUsrAAccess::operator=(
			const ListMsdcQUsrAAccess& src
		) {
	MsdcQUsrAAccess* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new MsdcQUsrAAccess(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListMsdcQUsrAAccess::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListMsdcQUsrAAccess";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblMsdcQUsrAAccess
 ******************************************************************************/

TblMsdcQUsrAAccess::TblMsdcQUsrAAccess() {
};

TblMsdcQUsrAAccess::~TblMsdcQUsrAAccess() {
};

bool TblMsdcQUsrAAccess::loadRecBySQL(
			const string& sqlstr
			, MsdcQUsrAAccess** rec
		) {
	return false;
};

ubigint TblMsdcQUsrAAccess::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListMsdcQUsrAAccess& rst
		) {
	return 0;
};

void TblMsdcQUsrAAccess::insertRec(
			MsdcQUsrAAccess* rec
		) {
};

ubigint TblMsdcQUsrAAccess::insertNewRec(
			MsdcQUsrAAccess** rec
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
	MsdcQUsrAAccess* _rec = NULL;

	_rec = new MsdcQUsrAAccess(0, jref, jnum, ref, x1IxMsdcVFeatgroup, srefX1IxMsdcVFeatgroup, titX1IxMsdcVFeatgroup, x2FeaSrefUix, ixMsdcWAccess, srefsIxMsdcWAccess, titsIxMsdcWAccess);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblMsdcQUsrAAccess::appendNewRecToRst(
			ListMsdcQUsrAAccess& rst
			, MsdcQUsrAAccess** rec
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
	MsdcQUsrAAccess* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, x1IxMsdcVFeatgroup, srefX1IxMsdcVFeatgroup, titX1IxMsdcVFeatgroup, x2FeaSrefUix, ixMsdcWAccess, srefsIxMsdcWAccess, titsIxMsdcWAccess);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblMsdcQUsrAAccess::insertRst(
			ListMsdcQUsrAAccess& rst
		) {
};

void TblMsdcQUsrAAccess::updateRec(
			MsdcQUsrAAccess* rec
		) {
};

void TblMsdcQUsrAAccess::updateRst(
			ListMsdcQUsrAAccess& rst
		) {
};

void TblMsdcQUsrAAccess::removeRecByQref(
			ubigint qref
		) {
};

void TblMsdcQUsrAAccess::removeRstByJref(
			ubigint jref
		) {
};

bool TblMsdcQUsrAAccess::loadRecByQref(
			ubigint qref
			, MsdcQUsrAAccess** rec
		) {
	return false;
};

ubigint TblMsdcQUsrAAccess::loadRstByJref(
			ubigint jref
			, const bool append
			, ListMsdcQUsrAAccess& rst
		) {
	return 0;
};

/******************************************************************************
 class LiteTblMsdcQUsrAAccess
 ******************************************************************************/

LiteTblMsdcQUsrAAccess::LiteTblMsdcQUsrAAccess() :
			TblMsdcQUsrAAccess()
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

LiteTblMsdcQUsrAAccess::~LiteTblMsdcQUsrAAccess() {
	if (stmtInsertRec) sqlite3_finalize(stmtInsertRec);
	if (stmtUpdateRec) sqlite3_finalize(stmtUpdateRec);
	if (stmtRemoveRecByQref) sqlite3_finalize(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) sqlite3_finalize(stmtRemoveRstByJref);

	if (stmtLoadRecByQref) sqlite3_finalize(stmtLoadRecByQref);
	if (stmtLoadRecByJref) sqlite3_finalize(stmtLoadRecByJref);
	if (stmtLoadRstByJref) sqlite3_finalize(stmtLoadRstByJref);
};

void LiteTblMsdcQUsrAAccess::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblMsdcQUsrAAccess (jref, jnum, ref, x1IxMsdcVFeatgroup, x2FeaSrefUix, ixMsdcWAccess) VALUES (?1,?2,?3,?4,?5,?6)");
	stmtUpdateRec = createStatement("UPDATE TblMsdcQUsrAAccess SET jref = ?1, jnum = ?2, ref = ?3, x1IxMsdcVFeatgroup = ?4, x2FeaSrefUix = ?5, ixMsdcWAccess = ?6 WHERE qref = ?7");
	stmtRemoveRecByQref = createStatement("DELETE FROM TblMsdcQUsrAAccess WHERE qref = ?1");
	stmtRemoveRstByJref = createStatement("DELETE FROM TblMsdcQUsrAAccess WHERE jref = ?1");

	stmtLoadRecByQref = createStatement("SELECT qref, jref, jnum, ref, x1IxMsdcVFeatgroup, x2FeaSrefUix, ixMsdcWAccess FROM TblMsdcQUsrAAccess WHERE qref = ?1");
	stmtLoadRstByJref = createStatement("SELECT qref, jref, jnum, ref, x1IxMsdcVFeatgroup, x2FeaSrefUix, ixMsdcWAccess FROM TblMsdcQUsrAAccess WHERE jref = ?1 ORDER BY jnum ASC");
};

bool LiteTblMsdcQUsrAAccess::loadRec(
			sqlite3_stmt* stmt
			, MsdcQUsrAAccess** rec
		) {
	int res;

	MsdcQUsrAAccess* _rec = NULL;
	bool retval = false;

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		_rec = new MsdcQUsrAAccess();

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

ubigint LiteTblMsdcQUsrAAccess::loadRst(
			sqlite3_stmt* stmt
			, const bool append
			, ListMsdcQUsrAAccess& rst
		) {
	int res; ubigint numread = 0;

	MsdcQUsrAAccess* rec;

	if (!append) rst.clear();

	res = sqlite3_step(stmt);
	while (res == SQLITE_ROW) {
		rec = new MsdcQUsrAAccess();

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

bool LiteTblMsdcQUsrAAccess::loadRecByStmt(
			sqlite3_stmt* stmt
			, MsdcQUsrAAccess** rec
		) {
	bool retval = loadRec(stmt, rec);

	sqlite3_reset(stmt);

	return retval;
};

ubigint LiteTblMsdcQUsrAAccess::loadRstByStmt(
			sqlite3_stmt* stmt
			, const bool append
			, ListMsdcQUsrAAccess& rst
		) {
	ubigint retval = loadRst(stmt, append, rst);

	sqlite3_reset(stmt);

	return retval;
};

bool LiteTblMsdcQUsrAAccess::loadRecBySQL(
			const string& sqlstr
			, MsdcQUsrAAccess** rec
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

ubigint LiteTblMsdcQUsrAAccess::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListMsdcQUsrAAccess& rst
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

void LiteTblMsdcQUsrAAccess::insertRec(
			MsdcQUsrAAccess* rec
		) {
	sqlite3_bind_int64(stmtInsertRec, 1, rec->jref);
	sqlite3_bind_int(stmtInsertRec, 2, rec->jnum);
	sqlite3_bind_int64(stmtInsertRec, 3, rec->ref);
	sqlite3_bind_int(stmtInsertRec, 4, rec->x1IxMsdcVFeatgroup);
	sqlite3_bind_text(stmtInsertRec, 5, rec->x2FeaSrefUix.c_str(), rec->x2FeaSrefUix.length(), SQLITE_STATIC);
	sqlite3_bind_int(stmtInsertRec, 6, rec->ixMsdcWAccess);

	if (sqlite3_step(stmtInsertRec) != SQLITE_DONE) throw DbsException("DbsException / SQLite: error executing statement! (TblMsdcQUsrAAccess / stmtInsertRec)\n");

	rec->qref = sqlite3_last_insert_rowid(dbs);

	sqlite3_reset(stmtInsertRec);
};

void LiteTblMsdcQUsrAAccess::insertRst(
			ListMsdcQUsrAAccess& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void LiteTblMsdcQUsrAAccess::updateRec(
			MsdcQUsrAAccess* rec
		) {
	sqlite3_bind_int64(stmtUpdateRec, 1, rec->jref);
	sqlite3_bind_int(stmtUpdateRec, 2, rec->jnum);
	sqlite3_bind_int64(stmtUpdateRec, 3, rec->ref);
	sqlite3_bind_int(stmtUpdateRec, 4, rec->x1IxMsdcVFeatgroup);
	sqlite3_bind_text(stmtUpdateRec, 5, rec->x2FeaSrefUix.c_str(), rec->x2FeaSrefUix.length(), SQLITE_STATIC);
	sqlite3_bind_int(stmtUpdateRec, 6, rec->ixMsdcWAccess);
	sqlite3_bind_int64(stmtUpdateRec, 7, rec->qref);

	if (sqlite3_step(stmtUpdateRec) != SQLITE_DONE) throw DbsException("DbsException / SQLite: error executing statement! (TblMsdcQUsrAAccess / stmtUpdateRec)\n");

	sqlite3_reset(stmtUpdateRec);
};

void LiteTblMsdcQUsrAAccess::updateRst(
			ListMsdcQUsrAAccess& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void LiteTblMsdcQUsrAAccess::removeRecByQref(
			ubigint qref
		) {
	sqlite3_bind_int64(stmtRemoveRecByQref, 1, qref);

	if (sqlite3_step(stmtRemoveRecByQref) != SQLITE_DONE) throw DbsException("DbsException / SQLite: error executing statement! (TblMsdcQUsrAAccess / stmtRemoveRecByQref)\n");

	sqlite3_reset(stmtRemoveRecByQref);
};

void LiteTblMsdcQUsrAAccess::removeRstByJref(
			ubigint jref
		) {
	sqlite3_bind_int64(stmtRemoveRstByJref, 1, jref);

	if (sqlite3_step(stmtRemoveRstByJref) != SQLITE_DONE) throw DbsException("DbsException / SQLite: error executing statement! (TblMsdcQUsrAAccess / stmtRemoveRstByJref)\n");

	sqlite3_reset(stmtRemoveRstByJref);
};

bool LiteTblMsdcQUsrAAccess::loadRecByQref(
			ubigint qref
			, MsdcQUsrAAccess** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	sqlite3_bind_int64(stmtLoadRecByQref, 1, qref);

	return loadRecByStmt(stmtLoadRecByQref, rec);
};

ubigint LiteTblMsdcQUsrAAccess::loadRstByJref(
			ubigint jref
			, const bool append
			, ListMsdcQUsrAAccess& rst
		) {
	sqlite3_bind_int64(stmtLoadRstByJref, 1, jref);

	return loadRstByStmt(stmtLoadRstByJref, append, rst);
};

