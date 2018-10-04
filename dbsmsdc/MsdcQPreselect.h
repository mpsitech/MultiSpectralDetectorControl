/**
  * \file MsdcQPreselect.h
  * Dbs and XML wrapper for table TblMsdcQPreselect (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Oct 2018
  * \date modified: 4 Oct 2018
  */

#ifndef MSDCQPRESELECT_H
#define MSDCQPRESELECT_H

#include <sbecore/LiteDbs.h>

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * MsdcQPreselect: record of TblMsdcQPreselect
  */
class MsdcQPreselect {

public:
	MsdcQPreselect(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0);

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListMsdcQPreselect: recordset of TblMsdcQPreselect
  */
class ListMsdcQPreselect {

public:
	ListMsdcQPreselect();
	ListMsdcQPreselect(const ListMsdcQPreselect& src);
	~ListMsdcQPreselect();

	void clear();
	unsigned int size() const;
	void append(MsdcQPreselect* rec);

	ListMsdcQPreselect& operator=(const ListMsdcQPreselect& src);

public:
	vector<MsdcQPreselect*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblMsdcQPreselect: C++ wrapper for table TblMsdcQPreselect
  */
class TblMsdcQPreselect {

public:
	TblMsdcQPreselect();
	virtual ~TblMsdcQPreselect();

public:
	virtual bool loadRecBySQL(const string& sqlstr, MsdcQPreselect** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListMsdcQPreselect& rst);

	virtual void insertRec(MsdcQPreselect* rec);
	ubigint insertNewRec(MsdcQPreselect** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0);
	ubigint appendNewRecToRst(ListMsdcQPreselect& rst, MsdcQPreselect** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0);
	virtual void insertRst(ListMsdcQPreselect& rst);
	virtual void updateRec(MsdcQPreselect* rec);
	virtual void updateRst(ListMsdcQPreselect& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, MsdcQPreselect** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListMsdcQPreselect& rst);
};

/**
  * LiteMsdcQPreselect: C++ wrapper for table TblMsdcQPreselect (SQLite database)
  */
class LiteTblMsdcQPreselect : public TblMsdcQPreselect, public LiteTable {

public:
	LiteTblMsdcQPreselect();
	~LiteTblMsdcQPreselect();

public:
	void initStatements();

public:
	sqlite3_stmt* stmtInsertRec;
	sqlite3_stmt* stmtUpdateRec;
	sqlite3_stmt* stmtRemoveRecByQref;
	sqlite3_stmt* stmtRemoveRstByJref;

	sqlite3_stmt* stmtLoadRecByQref;
	sqlite3_stmt* stmtLoadRecByJref;
	sqlite3_stmt* stmtLoadRstByJref;

private:
	bool loadRec(sqlite3_stmt* stmt, MsdcQPreselect** rec);
	ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListMsdcQPreselect& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, MsdcQPreselect** rec);
	ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListMsdcQPreselect& rst);

public:
	bool loadRecBySQL(const string& sqlstr, MsdcQPreselect** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListMsdcQPreselect& rst);

	void insertRec(MsdcQPreselect* rec);
	void insertRst(ListMsdcQPreselect& rst);
	void updateRec(MsdcQPreselect* rec);
	void updateRst(ListMsdcQPreselect& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, MsdcQPreselect** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListMsdcQPreselect& rst);
};
#endif

