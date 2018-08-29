/**
  * \file MsdcMSession.h
  * database access for table TblMsdcMSession (declarations)
  * \author Alexander Wirthmueller
  * \date created: 29 Aug 2018
  * \date modified: 29 Aug 2018
  */

#ifndef MSDCMSESSION_H
#define MSDCMSESSION_H

#include <sbecore/LiteDbs.h>

/**
  * MsdcMSession: record of TblMsdcMSession
  */
class MsdcMSession {

public:
	MsdcMSession(const ubigint ref = 0, const ubigint refMsdcMUser = 0, const uint start = 0, const uint stop = 0, const string Ip = "");

public:
	ubigint ref;
	ubigint refMsdcMUser;
	uint start;
	uint stop;
	string Ip;

public:
	bool operator==(const MsdcMSession& comp);
	bool operator!=(const MsdcMSession& comp);
};

/**
  * ListMsdcMSession: recordset of TblMsdcMSession
  */
class ListMsdcMSession {

public:
	ListMsdcMSession();
	ListMsdcMSession(const ListMsdcMSession& src);
	~ListMsdcMSession();

	void clear();
	unsigned int size() const;
	void append(MsdcMSession* rec);

	MsdcMSession* operator[](const uint ix);
	ListMsdcMSession& operator=(const ListMsdcMSession& src);
	bool operator==(const ListMsdcMSession& comp);
	bool operator!=(const ListMsdcMSession& comp);

public:
	vector<MsdcMSession*> nodes;
};

/**
  * TblMsdcMSession: C++ wrapper for table TblMsdcMSession
  */
class TblMsdcMSession {

public:

public:
	TblMsdcMSession();
	virtual ~TblMsdcMSession();

public:
	virtual bool loadRecBySQL(const string& sqlstr, MsdcMSession** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListMsdcMSession& rst);

	virtual void insertRec(MsdcMSession* rec);
	ubigint insertNewRec(MsdcMSession** rec = NULL, const ubigint refMsdcMUser = 0, const uint start = 0, const uint stop = 0, const string Ip = "");
	ubigint appendNewRecToRst(ListMsdcMSession& rst, MsdcMSession** rec = NULL, const ubigint refMsdcMUser = 0, const uint start = 0, const uint stop = 0, const string Ip = "");
	virtual void insertRst(ListMsdcMSession& rst, bool transact = false);
	virtual void updateRec(MsdcMSession* rec);
	virtual void updateRst(ListMsdcMSession& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, MsdcMSession** rec);
	virtual ubigint loadRefsByUsr(ubigint refMsdcMUser, const bool append, vector<ubigint>& refs);
	virtual ubigint loadRstByUsr(ubigint refMsdcMUser, const bool append, ListMsdcMSession& rst);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListMsdcMSession& rst);
};

/**
  * LiteTblMsdcMSession: C++ wrapper for table TblMsdcMSession (SQLite database)
  */
class LiteTblMsdcMSession : public TblMsdcMSession, public LiteTable {

public:
	LiteTblMsdcMSession();
	~LiteTblMsdcMSession();

public:
	void initStatements();

public:
	sqlite3_stmt* stmtInsertRec;
	sqlite3_stmt* stmtUpdateRec;
	sqlite3_stmt* stmtRemoveRecByRef;

	sqlite3_stmt* stmtLoadRecByRef;
	sqlite3_stmt* stmtLoadRefsByUsr;
	sqlite3_stmt* stmtLoadRstByUsr;

private:
	bool loadRec(sqlite3_stmt* stmt, MsdcMSession** rec);
	ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListMsdcMSession& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, MsdcMSession** rec);
	ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListMsdcMSession& rst);

public:
	bool loadRecBySQL(const string& sqlstr, MsdcMSession** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListMsdcMSession& rst);

	void insertRec(MsdcMSession* rec);
	void insertRst(ListMsdcMSession& rst, bool transact = false);
	void updateRec(MsdcMSession* rec);
	void updateRst(ListMsdcMSession& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, MsdcMSession** rec);
	ubigint loadRefsByUsr(ubigint refMsdcMUser, const bool append, vector<ubigint>& refs);
	ubigint loadRstByUsr(ubigint refMsdcMUser, const bool append, ListMsdcMSession& rst);
};

#endif

