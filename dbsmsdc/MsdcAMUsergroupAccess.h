/**
  * \file MsdcAMUsergroupAccess.h
  * database access for table TblMsdcAMUsergroupAccess (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Oct 2018
  * \date modified: 4 Oct 2018
  */

#ifndef MSDCAMUSERGROUPACCESS_H
#define MSDCAMUSERGROUPACCESS_H

#include <sbecore/LiteDbs.h>

/**
  * MsdcAMUsergroupAccess: record of TblMsdcAMUsergroupAccess
  */
class MsdcAMUsergroupAccess {

public:
	MsdcAMUsergroupAccess(const ubigint ref = 0, const ubigint refMsdcMUsergroup = 0, const uint x1IxMsdcVFeatgroup = 0, const string x2FeaSrefUix = "", const uint ixMsdcWAccess = 0);

public:
	ubigint ref;
	ubigint refMsdcMUsergroup;
	uint x1IxMsdcVFeatgroup;
	string x2FeaSrefUix;
	uint ixMsdcWAccess;

public:
	bool operator==(const MsdcAMUsergroupAccess& comp);
	bool operator!=(const MsdcAMUsergroupAccess& comp);
};

/**
  * ListMsdcAMUsergroupAccess: recordset of TblMsdcAMUsergroupAccess
  */
class ListMsdcAMUsergroupAccess {

public:
	ListMsdcAMUsergroupAccess();
	ListMsdcAMUsergroupAccess(const ListMsdcAMUsergroupAccess& src);
	~ListMsdcAMUsergroupAccess();

	void clear();
	unsigned int size() const;
	void append(MsdcAMUsergroupAccess* rec);

	MsdcAMUsergroupAccess* operator[](const uint ix);
	ListMsdcAMUsergroupAccess& operator=(const ListMsdcAMUsergroupAccess& src);
	bool operator==(const ListMsdcAMUsergroupAccess& comp);
	bool operator!=(const ListMsdcAMUsergroupAccess& comp);

public:
	vector<MsdcAMUsergroupAccess*> nodes;
};

/**
  * TblMsdcAMUsergroupAccess: C++ wrapper for table TblMsdcAMUsergroupAccess
  */
class TblMsdcAMUsergroupAccess {

public:

public:
	TblMsdcAMUsergroupAccess();
	virtual ~TblMsdcAMUsergroupAccess();

public:
	virtual bool loadRecBySQL(const string& sqlstr, MsdcAMUsergroupAccess** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListMsdcAMUsergroupAccess& rst);

	virtual void insertRec(MsdcAMUsergroupAccess* rec);
	ubigint insertNewRec(MsdcAMUsergroupAccess** rec = NULL, const ubigint refMsdcMUsergroup = 0, const uint x1IxMsdcVFeatgroup = 0, const string x2FeaSrefUix = "", const uint ixMsdcWAccess = 0);
	ubigint appendNewRecToRst(ListMsdcAMUsergroupAccess& rst, MsdcAMUsergroupAccess** rec = NULL, const ubigint refMsdcMUsergroup = 0, const uint x1IxMsdcVFeatgroup = 0, const string x2FeaSrefUix = "", const uint ixMsdcWAccess = 0);
	virtual void insertRst(ListMsdcAMUsergroupAccess& rst, bool transact = false);
	virtual void updateRec(MsdcAMUsergroupAccess* rec);
	virtual void updateRst(ListMsdcAMUsergroupAccess& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, MsdcAMUsergroupAccess** rec);
	virtual ubigint loadRefsByUsg(ubigint refMsdcMUsergroup, const bool append, vector<ubigint>& refs);
	virtual ubigint loadRstByUsg(ubigint refMsdcMUsergroup, const bool append, ListMsdcAMUsergroupAccess& rst);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListMsdcAMUsergroupAccess& rst);
};

/**
  * LiteTblMsdcAMUsergroupAccess: C++ wrapper for table TblMsdcAMUsergroupAccess (SQLite database)
  */
class LiteTblMsdcAMUsergroupAccess : public TblMsdcAMUsergroupAccess, public LiteTable {

public:
	LiteTblMsdcAMUsergroupAccess();
	~LiteTblMsdcAMUsergroupAccess();

public:
	void initStatements();

public:
	sqlite3_stmt* stmtInsertRec;
	sqlite3_stmt* stmtUpdateRec;
	sqlite3_stmt* stmtRemoveRecByRef;

	sqlite3_stmt* stmtLoadRecByRef;
	sqlite3_stmt* stmtLoadRefsByUsg;
	sqlite3_stmt* stmtLoadRstByUsg;

private:
	bool loadRec(sqlite3_stmt* stmt, MsdcAMUsergroupAccess** rec);
	ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListMsdcAMUsergroupAccess& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, MsdcAMUsergroupAccess** rec);
	ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListMsdcAMUsergroupAccess& rst);

public:
	bool loadRecBySQL(const string& sqlstr, MsdcAMUsergroupAccess** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListMsdcAMUsergroupAccess& rst);

	void insertRec(MsdcAMUsergroupAccess* rec);
	void insertRst(ListMsdcAMUsergroupAccess& rst, bool transact = false);
	void updateRec(MsdcAMUsergroupAccess* rec);
	void updateRst(ListMsdcAMUsergroupAccess& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, MsdcAMUsergroupAccess** rec);
	ubigint loadRefsByUsg(ubigint refMsdcMUsergroup, const bool append, vector<ubigint>& refs);
	ubigint loadRstByUsg(ubigint refMsdcMUsergroup, const bool append, ListMsdcAMUsergroupAccess& rst);
};

#endif

