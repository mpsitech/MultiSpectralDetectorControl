/**
  * \file MsdcRMUserMUsergroup.h
  * database access for table TblMsdcRMUserMUsergroup (declarations)
  * \author Alexander Wirthmueller
  * \date created: 15 Aug 2018
  * \date modified: 15 Aug 2018
  */

#ifndef MSDCRMUSERMUSERGROUP_H
#define MSDCRMUSERMUSERGROUP_H

#include <sbecore/LiteDbs.h>

/**
  * MsdcRMUserMUsergroup: record of TblMsdcRMUserMUsergroup
  */
class MsdcRMUserMUsergroup {

public:
	MsdcRMUserMUsergroup(const ubigint ref = 0, const ubigint refMsdcMUser = 0, const ubigint refMsdcMUsergroup = 0, const uint ixMsdcVUserlevel = 0);

public:
	ubigint ref;
	ubigint refMsdcMUser;
	ubigint refMsdcMUsergroup;
	uint ixMsdcVUserlevel;

public:
	bool operator==(const MsdcRMUserMUsergroup& comp);
	bool operator!=(const MsdcRMUserMUsergroup& comp);
};

/**
  * ListMsdcRMUserMUsergroup: recordset of TblMsdcRMUserMUsergroup
  */
class ListMsdcRMUserMUsergroup {

public:
	ListMsdcRMUserMUsergroup();
	ListMsdcRMUserMUsergroup(const ListMsdcRMUserMUsergroup& src);
	~ListMsdcRMUserMUsergroup();

	void clear();
	unsigned int size() const;
	void append(MsdcRMUserMUsergroup* rec);

	MsdcRMUserMUsergroup* operator[](const uint ix);
	ListMsdcRMUserMUsergroup& operator=(const ListMsdcRMUserMUsergroup& src);
	bool operator==(const ListMsdcRMUserMUsergroup& comp);
	bool operator!=(const ListMsdcRMUserMUsergroup& comp);

public:
	vector<MsdcRMUserMUsergroup*> nodes;
};

/**
  * TblMsdcRMUserMUsergroup: C++ wrapper for table TblMsdcRMUserMUsergroup
  */
class TblMsdcRMUserMUsergroup {

public:

public:
	TblMsdcRMUserMUsergroup();
	virtual ~TblMsdcRMUserMUsergroup();

public:
	virtual bool loadRecBySQL(const string& sqlstr, MsdcRMUserMUsergroup** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListMsdcRMUserMUsergroup& rst);

	virtual void insertRec(MsdcRMUserMUsergroup* rec);
	ubigint insertNewRec(MsdcRMUserMUsergroup** rec = NULL, const ubigint refMsdcMUser = 0, const ubigint refMsdcMUsergroup = 0, const uint ixMsdcVUserlevel = 0);
	ubigint appendNewRecToRst(ListMsdcRMUserMUsergroup& rst, MsdcRMUserMUsergroup** rec = NULL, const ubigint refMsdcMUser = 0, const ubigint refMsdcMUsergroup = 0, const uint ixMsdcVUserlevel = 0);
	virtual void insertRst(ListMsdcRMUserMUsergroup& rst, bool transact = false);
	virtual void updateRec(MsdcRMUserMUsergroup* rec);
	virtual void updateRst(ListMsdcRMUserMUsergroup& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, MsdcRMUserMUsergroup** rec);
	virtual ubigint loadRstByUsg(ubigint refMsdcMUsergroup, const bool append, ListMsdcRMUserMUsergroup& rst);
	virtual ubigint loadRstByUsr(ubigint refMsdcMUser, const bool append, ListMsdcRMUserMUsergroup& rst);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListMsdcRMUserMUsergroup& rst);
};

/**
  * LiteTblMsdcRMUserMUsergroup: C++ wrapper for table TblMsdcRMUserMUsergroup (SQLite database)
  */
class LiteTblMsdcRMUserMUsergroup : public TblMsdcRMUserMUsergroup, public LiteTable {

public:
	LiteTblMsdcRMUserMUsergroup();
	~LiteTblMsdcRMUserMUsergroup();

public:
	void initStatements();

public:
	sqlite3_stmt* stmtInsertRec;
	sqlite3_stmt* stmtUpdateRec;
	sqlite3_stmt* stmtRemoveRecByRef;

	sqlite3_stmt* stmtLoadRecByRef;
	sqlite3_stmt* stmtLoadRstByUsg;
	sqlite3_stmt* stmtLoadRstByUsr;

private:
	bool loadRec(sqlite3_stmt* stmt, MsdcRMUserMUsergroup** rec);
	ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListMsdcRMUserMUsergroup& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, MsdcRMUserMUsergroup** rec);
	ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListMsdcRMUserMUsergroup& rst);

public:
	bool loadRecBySQL(const string& sqlstr, MsdcRMUserMUsergroup** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListMsdcRMUserMUsergroup& rst);

	void insertRec(MsdcRMUserMUsergroup* rec);
	void insertRst(ListMsdcRMUserMUsergroup& rst, bool transact = false);
	void updateRec(MsdcRMUserMUsergroup* rec);
	void updateRst(ListMsdcRMUserMUsergroup& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, MsdcRMUserMUsergroup** rec);
	ubigint loadRstByUsg(ubigint refMsdcMUsergroup, const bool append, ListMsdcRMUserMUsergroup& rst);
	ubigint loadRstByUsr(ubigint refMsdcMUser, const bool append, ListMsdcRMUserMUsergroup& rst);
};

#endif

