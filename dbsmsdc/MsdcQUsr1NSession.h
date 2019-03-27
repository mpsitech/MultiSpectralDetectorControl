/**
  * \file MsdcQUsr1NSession.h
  * Dbs and XML wrapper for table TblMsdcQUsr1NSession (declarations)
  * \author Alexander Wirthmueller
  * \date created: 18 Dec 2018
  * \date modified: 18 Dec 2018
  */

#ifndef MSDCQUSR1NSESSION_H
#define MSDCQUSR1NSESSION_H

#include <sbecore/LiteDbs.h>

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * MsdcQUsr1NSession: record of TblMsdcQUsr1NSession
  */
class MsdcQUsr1NSession {

public:
	MsdcQUsr1NSession(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	string stubRef;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListMsdcQUsr1NSession: recordset of TblMsdcQUsr1NSession
  */
class ListMsdcQUsr1NSession {

public:
	ListMsdcQUsr1NSession();
	ListMsdcQUsr1NSession(const ListMsdcQUsr1NSession& src);
	~ListMsdcQUsr1NSession();

	void clear();
	unsigned int size() const;
	void append(MsdcQUsr1NSession* rec);

	ListMsdcQUsr1NSession& operator=(const ListMsdcQUsr1NSession& src);

public:
	vector<MsdcQUsr1NSession*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblMsdcQUsr1NSession: C++ wrapper for table TblMsdcQUsr1NSession
  */
class TblMsdcQUsr1NSession {

public:
	TblMsdcQUsr1NSession();
	virtual ~TblMsdcQUsr1NSession();

public:
	virtual bool loadRecBySQL(const string& sqlstr, MsdcQUsr1NSession** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListMsdcQUsr1NSession& rst);

	virtual void insertRec(MsdcQUsr1NSession* rec);
	ubigint insertNewRec(MsdcQUsr1NSession** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	ubigint appendNewRecToRst(ListMsdcQUsr1NSession& rst, MsdcQUsr1NSession** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	virtual void insertRst(ListMsdcQUsr1NSession& rst);
	virtual void updateRec(MsdcQUsr1NSession* rec);
	virtual void updateRst(ListMsdcQUsr1NSession& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, MsdcQUsr1NSession** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListMsdcQUsr1NSession& rst);
};

/**
  * LiteMsdcQUsr1NSession: C++ wrapper for table TblMsdcQUsr1NSession (SQLite database)
  */
class LiteTblMsdcQUsr1NSession : public TblMsdcQUsr1NSession, public LiteTable {

public:
	LiteTblMsdcQUsr1NSession();
	~LiteTblMsdcQUsr1NSession();

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
	bool loadRec(sqlite3_stmt* stmt, MsdcQUsr1NSession** rec);
	ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListMsdcQUsr1NSession& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, MsdcQUsr1NSession** rec);
	ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListMsdcQUsr1NSession& rst);

public:
	bool loadRecBySQL(const string& sqlstr, MsdcQUsr1NSession** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListMsdcQUsr1NSession& rst);

	void insertRec(MsdcQUsr1NSession* rec);
	void insertRst(ListMsdcQUsr1NSession& rst);
	void updateRec(MsdcQUsr1NSession* rec);
	void updateRst(ListMsdcQUsr1NSession& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, MsdcQUsr1NSession** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListMsdcQUsr1NSession& rst);
};
#endif

