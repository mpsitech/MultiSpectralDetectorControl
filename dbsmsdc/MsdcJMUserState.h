/**
  * \file MsdcJMUserState.h
  * database access for table TblMsdcJMUserState (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Oct 2018
  * \date modified: 4 Oct 2018
  */

#ifndef MSDCJMUSERSTATE_H
#define MSDCJMUSERSTATE_H

#include <sbecore/LiteDbs.h>

/**
  * MsdcJMUserState: record of TblMsdcJMUserState
  */
class MsdcJMUserState {

public:
	MsdcJMUserState(const ubigint ref = 0, const ubigint refMsdcMUser = 0, const uint x1Startd = 0, const uint ixVState = 0);

public:
	ubigint ref;
	ubigint refMsdcMUser;
	uint x1Startd;
	uint ixVState;

public:
	bool operator==(const MsdcJMUserState& comp);
	bool operator!=(const MsdcJMUserState& comp);
};

/**
  * ListMsdcJMUserState: recordset of TblMsdcJMUserState
  */
class ListMsdcJMUserState {

public:
	ListMsdcJMUserState();
	ListMsdcJMUserState(const ListMsdcJMUserState& src);
	~ListMsdcJMUserState();

	void clear();
	unsigned int size() const;
	void append(MsdcJMUserState* rec);

	MsdcJMUserState* operator[](const uint ix);
	ListMsdcJMUserState& operator=(const ListMsdcJMUserState& src);
	bool operator==(const ListMsdcJMUserState& comp);
	bool operator!=(const ListMsdcJMUserState& comp);

public:
	vector<MsdcJMUserState*> nodes;
};

/**
  * TblMsdcJMUserState: C++ wrapper for table TblMsdcJMUserState
  */
class TblMsdcJMUserState {

public:

public:
	TblMsdcJMUserState();
	virtual ~TblMsdcJMUserState();

public:
	virtual bool loadRecBySQL(const string& sqlstr, MsdcJMUserState** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListMsdcJMUserState& rst);

	virtual void insertRec(MsdcJMUserState* rec);
	ubigint insertNewRec(MsdcJMUserState** rec = NULL, const ubigint refMsdcMUser = 0, const uint x1Startd = 0, const uint ixVState = 0);
	ubigint appendNewRecToRst(ListMsdcJMUserState& rst, MsdcJMUserState** rec = NULL, const ubigint refMsdcMUser = 0, const uint x1Startd = 0, const uint ixVState = 0);
	virtual void insertRst(ListMsdcJMUserState& rst, bool transact = false);
	virtual void updateRec(MsdcJMUserState* rec);
	virtual void updateRst(ListMsdcJMUserState& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, MsdcJMUserState** rec);
	virtual bool loadRecByUsrSta(ubigint refMsdcMUser, uint x1Startd, MsdcJMUserState** rec);
	virtual ubigint loadRefsByUsr(ubigint refMsdcMUser, const bool append, vector<ubigint>& refs);
	virtual ubigint loadRstByUsr(ubigint refMsdcMUser, const bool append, ListMsdcJMUserState& rst);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListMsdcJMUserState& rst);
};

/**
  * LiteTblMsdcJMUserState: C++ wrapper for table TblMsdcJMUserState (SQLite database)
  */
class LiteTblMsdcJMUserState : public TblMsdcJMUserState, public LiteTable {

public:
	LiteTblMsdcJMUserState();
	~LiteTblMsdcJMUserState();

public:
	void initStatements();

public:
	sqlite3_stmt* stmtInsertRec;
	sqlite3_stmt* stmtUpdateRec;
	sqlite3_stmt* stmtRemoveRecByRef;

	sqlite3_stmt* stmtLoadRecByRef;
	sqlite3_stmt* stmtLoadRecByUsrSta;
	sqlite3_stmt* stmtLoadRefsByUsr;
	sqlite3_stmt* stmtLoadRstByUsr;

private:
	bool loadRec(sqlite3_stmt* stmt, MsdcJMUserState** rec);
	ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListMsdcJMUserState& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, MsdcJMUserState** rec);
	ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListMsdcJMUserState& rst);

public:
	bool loadRecBySQL(const string& sqlstr, MsdcJMUserState** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListMsdcJMUserState& rst);

	void insertRec(MsdcJMUserState* rec);
	void insertRst(ListMsdcJMUserState& rst, bool transact = false);
	void updateRec(MsdcJMUserState* rec);
	void updateRst(ListMsdcJMUserState& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, MsdcJMUserState** rec);
	bool loadRecByUsrSta(ubigint refMsdcMUser, uint x1Startd, MsdcJMUserState** rec);
	ubigint loadRefsByUsr(ubigint refMsdcMUser, const bool append, vector<ubigint>& refs);
	ubigint loadRstByUsr(ubigint refMsdcMUser, const bool append, ListMsdcJMUserState& rst);
};

#endif

