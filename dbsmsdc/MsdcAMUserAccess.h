/**
  * \file MsdcAMUserAccess.h
  * database access for table TblMsdcAMUserAccess (declarations)
  * \author Alexander Wirthmueller
  * \date created: 12 Sep 2018
  * \date modified: 12 Sep 2018
  */

#ifndef MSDCAMUSERACCESS_H
#define MSDCAMUSERACCESS_H

#include <sbecore/LiteDbs.h>

/**
  * MsdcAMUserAccess: record of TblMsdcAMUserAccess
  */
class MsdcAMUserAccess {

public:
	MsdcAMUserAccess(const ubigint ref = 0, const ubigint refMsdcMUser = 0, const uint x1IxMsdcVFeatgroup = 0, const string x2FeaSrefUix = "", const uint ixMsdcWAccess = 0);

public:
	ubigint ref;
	ubigint refMsdcMUser;
	uint x1IxMsdcVFeatgroup;
	string x2FeaSrefUix;
	uint ixMsdcWAccess;

public:
	bool operator==(const MsdcAMUserAccess& comp);
	bool operator!=(const MsdcAMUserAccess& comp);
};

/**
  * ListMsdcAMUserAccess: recordset of TblMsdcAMUserAccess
  */
class ListMsdcAMUserAccess {

public:
	ListMsdcAMUserAccess();
	ListMsdcAMUserAccess(const ListMsdcAMUserAccess& src);
	~ListMsdcAMUserAccess();

	void clear();
	unsigned int size() const;
	void append(MsdcAMUserAccess* rec);

	MsdcAMUserAccess* operator[](const uint ix);
	ListMsdcAMUserAccess& operator=(const ListMsdcAMUserAccess& src);
	bool operator==(const ListMsdcAMUserAccess& comp);
	bool operator!=(const ListMsdcAMUserAccess& comp);

public:
	vector<MsdcAMUserAccess*> nodes;
};

/**
  * TblMsdcAMUserAccess: C++ wrapper for table TblMsdcAMUserAccess
  */
class TblMsdcAMUserAccess {

public:

public:
	TblMsdcAMUserAccess();
	virtual ~TblMsdcAMUserAccess();

public:
	virtual bool loadRecBySQL(const string& sqlstr, MsdcAMUserAccess** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListMsdcAMUserAccess& rst);

	virtual void insertRec(MsdcAMUserAccess* rec);
	ubigint insertNewRec(MsdcAMUserAccess** rec = NULL, const ubigint refMsdcMUser = 0, const uint x1IxMsdcVFeatgroup = 0, const string x2FeaSrefUix = "", const uint ixMsdcWAccess = 0);
	ubigint appendNewRecToRst(ListMsdcAMUserAccess& rst, MsdcAMUserAccess** rec = NULL, const ubigint refMsdcMUser = 0, const uint x1IxMsdcVFeatgroup = 0, const string x2FeaSrefUix = "", const uint ixMsdcWAccess = 0);
	virtual void insertRst(ListMsdcAMUserAccess& rst, bool transact = false);
	virtual void updateRec(MsdcAMUserAccess* rec);
	virtual void updateRst(ListMsdcAMUserAccess& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, MsdcAMUserAccess** rec);
	virtual ubigint loadRefsByUsr(ubigint refMsdcMUser, const bool append, vector<ubigint>& refs);
	virtual ubigint loadRstByUsr(ubigint refMsdcMUser, const bool append, ListMsdcAMUserAccess& rst);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListMsdcAMUserAccess& rst);
};

/**
  * LiteTblMsdcAMUserAccess: C++ wrapper for table TblMsdcAMUserAccess (SQLite database)
  */
class LiteTblMsdcAMUserAccess : public TblMsdcAMUserAccess, public LiteTable {

public:
	LiteTblMsdcAMUserAccess();
	~LiteTblMsdcAMUserAccess();

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
	bool loadRec(sqlite3_stmt* stmt, MsdcAMUserAccess** rec);
	ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListMsdcAMUserAccess& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, MsdcAMUserAccess** rec);
	ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListMsdcAMUserAccess& rst);

public:
	bool loadRecBySQL(const string& sqlstr, MsdcAMUserAccess** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListMsdcAMUserAccess& rst);

	void insertRec(MsdcAMUserAccess* rec);
	void insertRst(ListMsdcAMUserAccess& rst, bool transact = false);
	void updateRec(MsdcAMUserAccess* rec);
	void updateRst(ListMsdcAMUserAccess& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, MsdcAMUserAccess** rec);
	ubigint loadRefsByUsr(ubigint refMsdcMUser, const bool append, vector<ubigint>& refs);
	ubigint loadRstByUsr(ubigint refMsdcMUser, const bool append, ListMsdcAMUserAccess& rst);
};

#endif

