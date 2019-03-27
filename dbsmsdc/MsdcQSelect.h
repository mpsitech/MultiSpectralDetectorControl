/**
  * \file MsdcQSelect.h
  * Dbs and XML wrapper for table TblMsdcQSelect (declarations)
  * \author Alexander Wirthmueller
  * \date created: 18 Dec 2018
  * \date modified: 18 Dec 2018
  */

#ifndef MSDCQSELECT_H
#define MSDCQSELECT_H

#include <sbecore/LiteDbs.h>

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * MsdcQSelect: record of TblMsdcQSelect
  */
class MsdcQSelect {

public:
	MsdcQSelect(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const uint ix = 0, const ubigint ref = 0);

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	uint ix;
	ubigint ref;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListMsdcQSelect: recordset of TblMsdcQSelect
  */
class ListMsdcQSelect {

public:
	ListMsdcQSelect();
	ListMsdcQSelect(const ListMsdcQSelect& src);
	~ListMsdcQSelect();

	void clear();
	unsigned int size() const;
	void append(MsdcQSelect* rec);

	ListMsdcQSelect& operator=(const ListMsdcQSelect& src);

public:
	vector<MsdcQSelect*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblMsdcQSelect: C++ wrapper for table TblMsdcQSelect
  */
class TblMsdcQSelect {

public:
	TblMsdcQSelect();
	virtual ~TblMsdcQSelect();

public:
	virtual bool loadRecBySQL(const string& sqlstr, MsdcQSelect** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListMsdcQSelect& rst);

	virtual void insertRec(MsdcQSelect* rec);
	ubigint insertNewRec(MsdcQSelect** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const uint ix = 0, const ubigint ref = 0);
	ubigint appendNewRecToRst(ListMsdcQSelect& rst, MsdcQSelect** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const uint ix = 0, const ubigint ref = 0);
	virtual void insertRst(ListMsdcQSelect& rst);
	virtual void updateRec(MsdcQSelect* rec);
	virtual void updateRst(ListMsdcQSelect& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, MsdcQSelect** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListMsdcQSelect& rst);
};

/**
  * LiteMsdcQSelect: C++ wrapper for table TblMsdcQSelect (SQLite database)
  */
class LiteTblMsdcQSelect : public TblMsdcQSelect, public LiteTable {

public:
	LiteTblMsdcQSelect();
	~LiteTblMsdcQSelect();

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
	bool loadRec(sqlite3_stmt* stmt, MsdcQSelect** rec);
	ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListMsdcQSelect& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, MsdcQSelect** rec);
	ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListMsdcQSelect& rst);

public:
	bool loadRecBySQL(const string& sqlstr, MsdcQSelect** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListMsdcQSelect& rst);

	void insertRec(MsdcQSelect* rec);
	void insertRst(ListMsdcQSelect& rst);
	void updateRec(MsdcQSelect* rec);
	void updateRst(ListMsdcQSelect& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, MsdcQSelect** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListMsdcQSelect& rst);
};
#endif

