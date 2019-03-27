/**
  * \file MsdcQPrsList.cpp
  * Dbs and XML wrapper for table TblMsdcQPrsList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 18 Dec 2018
  * \date modified: 18 Dec 2018
  */

#include "MsdcQPrsList.h"

/******************************************************************************
 class MsdcQPrsList
 ******************************************************************************/

MsdcQPrsList::MsdcQPrsList(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string Title
			, const string Firstname
			, const string Lastname
			, const ubigint grp
			, const string stubGrp
			, const ubigint own
			, const string stubOwn
			, const uint ixVSex
			, const string srefIxVSex
			, const string titIxVSex
			, const string telVal
			, const string emlVal
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->Title = Title;
	this->Firstname = Firstname;
	this->Lastname = Lastname;
	this->grp = grp;
	this->stubGrp = stubGrp;
	this->own = own;
	this->stubOwn = stubOwn;
	this->ixVSex = ixVSex;
	this->srefIxVSex = srefIxVSex;
	this->titIxVSex = titIxVSex;
	this->telVal = telVal;
	this->emlVal = emlVal;
};

void MsdcQPrsList::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "MsdcQPrsList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "tit", Title);
		writeString(wr, "fnm", Firstname);
		writeString(wr, "lnm", Lastname);
		writeString(wr, "grp", stubGrp);
		writeString(wr, "own", stubOwn);
		writeString(wr, "sex", srefIxVSex);
		writeString(wr, "sex2", titIxVSex);
		writeString(wr, "tel", telVal);
		writeString(wr, "eml", emlVal);
	} else {
		writeString(wr, "Title", Title);
		writeString(wr, "Firstname", Firstname);
		writeString(wr, "Lastname", Lastname);
		writeString(wr, "stubGrp", stubGrp);
		writeString(wr, "stubOwn", stubOwn);
		writeString(wr, "srefIxVSex", srefIxVSex);
		writeString(wr, "titIxVSex", titIxVSex);
		writeString(wr, "telVal", telVal);
		writeString(wr, "emlVal", emlVal);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListMsdcQPrsList
 ******************************************************************************/

ListMsdcQPrsList::ListMsdcQPrsList() {
};

ListMsdcQPrsList::ListMsdcQPrsList(
			const ListMsdcQPrsList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new MsdcQPrsList(*(src.nodes[i]));
};

ListMsdcQPrsList::~ListMsdcQPrsList() {
	clear();
};

void ListMsdcQPrsList::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListMsdcQPrsList::size() const {
	return(nodes.size());
};

void ListMsdcQPrsList::append(
			MsdcQPrsList* rec
		) {
	nodes.push_back(rec);
};

ListMsdcQPrsList& ListMsdcQPrsList::operator=(
			const ListMsdcQPrsList& src
		) {
	MsdcQPrsList* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new MsdcQPrsList(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListMsdcQPrsList::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListMsdcQPrsList";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblMsdcQPrsList
 ******************************************************************************/

TblMsdcQPrsList::TblMsdcQPrsList() {
};

TblMsdcQPrsList::~TblMsdcQPrsList() {
};

bool TblMsdcQPrsList::loadRecBySQL(
			const string& sqlstr
			, MsdcQPrsList** rec
		) {
	return false;
};

ubigint TblMsdcQPrsList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListMsdcQPrsList& rst
		) {
	return 0;
};

void TblMsdcQPrsList::insertRec(
			MsdcQPrsList* rec
		) {
};

ubigint TblMsdcQPrsList::insertNewRec(
			MsdcQPrsList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string Title
			, const string Firstname
			, const string Lastname
			, const ubigint grp
			, const string stubGrp
			, const ubigint own
			, const string stubOwn
			, const uint ixVSex
			, const string srefIxVSex
			, const string titIxVSex
			, const string telVal
			, const string emlVal
		) {
	ubigint retval = 0;
	MsdcQPrsList* _rec = NULL;

	_rec = new MsdcQPrsList(0, jref, jnum, ref, Title, Firstname, Lastname, grp, stubGrp, own, stubOwn, ixVSex, srefIxVSex, titIxVSex, telVal, emlVal);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblMsdcQPrsList::appendNewRecToRst(
			ListMsdcQPrsList& rst
			, MsdcQPrsList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string Title
			, const string Firstname
			, const string Lastname
			, const ubigint grp
			, const string stubGrp
			, const ubigint own
			, const string stubOwn
			, const uint ixVSex
			, const string srefIxVSex
			, const string titIxVSex
			, const string telVal
			, const string emlVal
		) {
	ubigint retval = 0;
	MsdcQPrsList* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, Title, Firstname, Lastname, grp, stubGrp, own, stubOwn, ixVSex, srefIxVSex, titIxVSex, telVal, emlVal);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblMsdcQPrsList::insertRst(
			ListMsdcQPrsList& rst
		) {
};

void TblMsdcQPrsList::updateRec(
			MsdcQPrsList* rec
		) {
};

void TblMsdcQPrsList::updateRst(
			ListMsdcQPrsList& rst
		) {
};

void TblMsdcQPrsList::removeRecByQref(
			ubigint qref
		) {
};

void TblMsdcQPrsList::removeRstByJref(
			ubigint jref
		) {
};

bool TblMsdcQPrsList::loadRecByQref(
			ubigint qref
			, MsdcQPrsList** rec
		) {
	return false;
};

ubigint TblMsdcQPrsList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListMsdcQPrsList& rst
		) {
	return 0;
};

/******************************************************************************
 class LiteTblMsdcQPrsList
 ******************************************************************************/

LiteTblMsdcQPrsList::LiteTblMsdcQPrsList() :
			TblMsdcQPrsList()
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

LiteTblMsdcQPrsList::~LiteTblMsdcQPrsList() {
	if (stmtInsertRec) sqlite3_finalize(stmtInsertRec);
	if (stmtUpdateRec) sqlite3_finalize(stmtUpdateRec);
	if (stmtRemoveRecByQref) sqlite3_finalize(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) sqlite3_finalize(stmtRemoveRstByJref);

	if (stmtLoadRecByQref) sqlite3_finalize(stmtLoadRecByQref);
	if (stmtLoadRecByJref) sqlite3_finalize(stmtLoadRecByJref);
	if (stmtLoadRstByJref) sqlite3_finalize(stmtLoadRstByJref);
};

void LiteTblMsdcQPrsList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblMsdcQPrsList (jref, jnum, ref, Title, Firstname, Lastname, grp, own, ixVSex, telVal, emlVal) VALUES (?1,?2,?3,?4,?5,?6,?7,?8,?9,?10,?11)");
	stmtUpdateRec = createStatement("UPDATE TblMsdcQPrsList SET jref = ?1, jnum = ?2, ref = ?3, Title = ?4, Firstname = ?5, Lastname = ?6, grp = ?7, own = ?8, ixVSex = ?9, telVal = ?10, emlVal = ?11 WHERE qref = ?12");
	stmtRemoveRecByQref = createStatement("DELETE FROM TblMsdcQPrsList WHERE qref = ?1");
	stmtRemoveRstByJref = createStatement("DELETE FROM TblMsdcQPrsList WHERE jref = ?1");

	stmtLoadRecByQref = createStatement("SELECT qref, jref, jnum, ref, Title, Firstname, Lastname, grp, own, ixVSex, telVal, emlVal FROM TblMsdcQPrsList WHERE qref = ?1");
	stmtLoadRstByJref = createStatement("SELECT qref, jref, jnum, ref, Title, Firstname, Lastname, grp, own, ixVSex, telVal, emlVal FROM TblMsdcQPrsList WHERE jref = ?1 ORDER BY jnum ASC");
};

bool LiteTblMsdcQPrsList::loadRec(
			sqlite3_stmt* stmt
			, MsdcQPrsList** rec
		) {
	int res;

	MsdcQPrsList* _rec = NULL;
	bool retval = false;

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		_rec = new MsdcQPrsList();

		_rec->qref = sqlite3_column_int64(stmt, 0);
		_rec->jref = sqlite3_column_int64(stmt, 1);
		_rec->jnum = sqlite3_column_int(stmt, 2);
		_rec->ref = sqlite3_column_int64(stmt, 3);
		_rec->Title.assign((const char*) sqlite3_column_text(stmt, 4));
		_rec->Firstname.assign((const char*) sqlite3_column_text(stmt, 5));
		_rec->Lastname.assign((const char*) sqlite3_column_text(stmt, 6));
		_rec->grp = sqlite3_column_int64(stmt, 7);
		_rec->own = sqlite3_column_int64(stmt, 8);
		_rec->ixVSex = sqlite3_column_int(stmt, 9);
		_rec->telVal.assign((const char*) sqlite3_column_text(stmt, 10));
		_rec->emlVal.assign((const char*) sqlite3_column_text(stmt, 11));

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

ubigint LiteTblMsdcQPrsList::loadRst(
			sqlite3_stmt* stmt
			, const bool append
			, ListMsdcQPrsList& rst
		) {
	int res; ubigint numread = 0;

	MsdcQPrsList* rec;

	if (!append) rst.clear();

	res = sqlite3_step(stmt);
	while (res == SQLITE_ROW) {
		rec = new MsdcQPrsList();

		rec->qref = sqlite3_column_int64(stmt, 0);
		rec->jref = sqlite3_column_int64(stmt, 1);
		rec->jnum = sqlite3_column_int(stmt, 2);
		rec->ref = sqlite3_column_int64(stmt, 3);
		rec->Title.assign((const char*) sqlite3_column_text(stmt, 4));
		rec->Firstname.assign((const char*) sqlite3_column_text(stmt, 5));
		rec->Lastname.assign((const char*) sqlite3_column_text(stmt, 6));
		rec->grp = sqlite3_column_int64(stmt, 7);
		rec->own = sqlite3_column_int64(stmt, 8);
		rec->ixVSex = sqlite3_column_int(stmt, 9);
		rec->telVal.assign((const char*) sqlite3_column_text(stmt, 10));
		rec->emlVal.assign((const char*) sqlite3_column_text(stmt, 11));

		rst.nodes.push_back(rec);

		numread++;

		res = sqlite3_step(stmt);
	};

	return(numread);
};

bool LiteTblMsdcQPrsList::loadRecByStmt(
			sqlite3_stmt* stmt
			, MsdcQPrsList** rec
		) {
	bool retval = loadRec(stmt, rec);

	sqlite3_reset(stmt);

	return retval;
};

ubigint LiteTblMsdcQPrsList::loadRstByStmt(
			sqlite3_stmt* stmt
			, const bool append
			, ListMsdcQPrsList& rst
		) {
	ubigint retval = loadRst(stmt, append, rst);

	sqlite3_reset(stmt);

	return retval;
};

bool LiteTblMsdcQPrsList::loadRecBySQL(
			const string& sqlstr
			, MsdcQPrsList** rec
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

ubigint LiteTblMsdcQPrsList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListMsdcQPrsList& rst
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

void LiteTblMsdcQPrsList::insertRec(
			MsdcQPrsList* rec
		) {
	sqlite3_bind_int64(stmtInsertRec, 1, rec->jref);
	sqlite3_bind_int(stmtInsertRec, 2, rec->jnum);
	sqlite3_bind_int64(stmtInsertRec, 3, rec->ref);
	sqlite3_bind_text(stmtInsertRec, 4, rec->Title.c_str(), rec->Title.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtInsertRec, 5, rec->Firstname.c_str(), rec->Firstname.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtInsertRec, 6, rec->Lastname.c_str(), rec->Lastname.length(), SQLITE_STATIC);
	sqlite3_bind_int64(stmtInsertRec, 7, rec->grp);
	sqlite3_bind_int64(stmtInsertRec, 8, rec->own);
	sqlite3_bind_int(stmtInsertRec, 9, rec->ixVSex);
	sqlite3_bind_text(stmtInsertRec, 10, rec->telVal.c_str(), rec->telVal.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtInsertRec, 11, rec->emlVal.c_str(), rec->emlVal.length(), SQLITE_STATIC);

	if (sqlite3_step(stmtInsertRec) != SQLITE_DONE) throw DbsException("DbsException / SQLite: error executing statement! (TblMsdcQPrsList / stmtInsertRec)\n");

	rec->qref = sqlite3_last_insert_rowid(dbs);

	sqlite3_reset(stmtInsertRec);
};

void LiteTblMsdcQPrsList::insertRst(
			ListMsdcQPrsList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void LiteTblMsdcQPrsList::updateRec(
			MsdcQPrsList* rec
		) {
	sqlite3_bind_int64(stmtUpdateRec, 1, rec->jref);
	sqlite3_bind_int(stmtUpdateRec, 2, rec->jnum);
	sqlite3_bind_int64(stmtUpdateRec, 3, rec->ref);
	sqlite3_bind_text(stmtUpdateRec, 4, rec->Title.c_str(), rec->Title.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtUpdateRec, 5, rec->Firstname.c_str(), rec->Firstname.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtUpdateRec, 6, rec->Lastname.c_str(), rec->Lastname.length(), SQLITE_STATIC);
	sqlite3_bind_int64(stmtUpdateRec, 7, rec->grp);
	sqlite3_bind_int64(stmtUpdateRec, 8, rec->own);
	sqlite3_bind_int(stmtUpdateRec, 9, rec->ixVSex);
	sqlite3_bind_text(stmtUpdateRec, 10, rec->telVal.c_str(), rec->telVal.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtUpdateRec, 11, rec->emlVal.c_str(), rec->emlVal.length(), SQLITE_STATIC);
	sqlite3_bind_int64(stmtUpdateRec, 12, rec->qref);

	if (sqlite3_step(stmtUpdateRec) != SQLITE_DONE) throw DbsException("DbsException / SQLite: error executing statement! (TblMsdcQPrsList / stmtUpdateRec)\n");

	sqlite3_reset(stmtUpdateRec);
};

void LiteTblMsdcQPrsList::updateRst(
			ListMsdcQPrsList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void LiteTblMsdcQPrsList::removeRecByQref(
			ubigint qref
		) {
	sqlite3_bind_int64(stmtRemoveRecByQref, 1, qref);

	if (sqlite3_step(stmtRemoveRecByQref) != SQLITE_DONE) throw DbsException("DbsException / SQLite: error executing statement! (TblMsdcQPrsList / stmtRemoveRecByQref)\n");

	sqlite3_reset(stmtRemoveRecByQref);
};

void LiteTblMsdcQPrsList::removeRstByJref(
			ubigint jref
		) {
	sqlite3_bind_int64(stmtRemoveRstByJref, 1, jref);

	if (sqlite3_step(stmtRemoveRstByJref) != SQLITE_DONE) throw DbsException("DbsException / SQLite: error executing statement! (TblMsdcQPrsList / stmtRemoveRstByJref)\n");

	sqlite3_reset(stmtRemoveRstByJref);
};

bool LiteTblMsdcQPrsList::loadRecByQref(
			ubigint qref
			, MsdcQPrsList** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	sqlite3_bind_int64(stmtLoadRecByQref, 1, qref);

	return loadRecByStmt(stmtLoadRecByQref, rec);
};

ubigint LiteTblMsdcQPrsList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListMsdcQPrsList& rst
		) {
	sqlite3_bind_int64(stmtLoadRstByJref, 1, jref);

	return loadRstByStmt(stmtLoadRstByJref, append, rst);
};

