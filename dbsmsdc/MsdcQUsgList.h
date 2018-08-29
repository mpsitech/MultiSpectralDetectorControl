/**
  * \file MsdcQUsgList.h
  * Dbs and XML wrapper for table TblMsdcQUsgList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 29 Aug 2018
  * \date modified: 29 Aug 2018
  */

#ifndef MSDCQUSGLIST_H
#define MSDCQUSGLIST_H

#include <sbecore/LiteDbs.h>

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * MsdcQUsgList: record of TblMsdcQUsgList
  */
class MsdcQUsgList {

public:
	MsdcQUsgList(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string sref = "");

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	string sref;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListMsdcQUsgList: recordset of TblMsdcQUsgList
  */
class ListMsdcQUsgList {

public:
	ListMsdcQUsgList();
	ListMsdcQUsgList(const ListMsdcQUsgList& src);
	~ListMsdcQUsgList();

	void clear();
	unsigned int size() const;
	void append(MsdcQUsgList* rec);

	ListMsdcQUsgList& operator=(const ListMsdcQUsgList& src);

public:
	vector<MsdcQUsgList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblMsdcQUsgList: C++ wrapper for table TblMsdcQUsgList
  */
class TblMsdcQUsgList {

public:
	TblMsdcQUsgList();
	virtual ~TblMsdcQUsgList();

public:
	virtual bool loadRecBySQL(const string& sqlstr, MsdcQUsgList** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListMsdcQUsgList& rst);

	virtual void insertRec(MsdcQUsgList* rec);
	ubigint insertNewRec(MsdcQUsgList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string sref = "");
	ubigint appendNewRecToRst(ListMsdcQUsgList& rst, MsdcQUsgList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string sref = "");
	virtual void insertRst(ListMsdcQUsgList& rst);
	virtual void updateRec(MsdcQUsgList* rec);
	virtual void updateRst(ListMsdcQUsgList& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, MsdcQUsgList** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListMsdcQUsgList& rst);
};

/**
  * LiteMsdcQUsgList: C++ wrapper for table TblMsdcQUsgList (SQLite database)
  */
class LiteTblMsdcQUsgList : public TblMsdcQUsgList, public LiteTable {

public:
	LiteTblMsdcQUsgList();
	~LiteTblMsdcQUsgList();

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
	bool loadRec(sqlite3_stmt* stmt, MsdcQUsgList** rec);
	ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListMsdcQUsgList& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, MsdcQUsgList** rec);
	ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListMsdcQUsgList& rst);

public:
	bool loadRecBySQL(const string& sqlstr, MsdcQUsgList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListMsdcQUsgList& rst);

	void insertRec(MsdcQUsgList* rec);
	void insertRst(ListMsdcQUsgList& rst);
	void updateRec(MsdcQUsgList* rec);
	void updateRst(ListMsdcQUsgList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, MsdcQUsgList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListMsdcQUsgList& rst);
};
#endif

