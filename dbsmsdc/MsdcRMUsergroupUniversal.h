/**
  * \file MsdcRMUsergroupUniversal.h
  * database access for table TblMsdcRMUsergroupUniversal (declarations)
  * \author Alexander Wirthmueller
  * \date created: 12 Sep 2018
  * \date modified: 12 Sep 2018
  */

#ifndef MSDCRMUSERGROUPUNIVERSAL_H
#define MSDCRMUSERGROUPUNIVERSAL_H

#include <sbecore/LiteDbs.h>

/**
  * MsdcRMUsergroupUniversal: record of TblMsdcRMUsergroupUniversal
  */
class MsdcRMUsergroupUniversal {

public:
	MsdcRMUsergroupUniversal(const ubigint ref = 0, const ubigint refMsdcMUsergroup = 0, const uint unvIxMsdcVMaintable = 0, const ubigint unvUref = 0, const uint ixMsdcVRecaccess = 0);

public:
	ubigint ref;
	ubigint refMsdcMUsergroup;
	uint unvIxMsdcVMaintable;
	ubigint unvUref;
	uint ixMsdcVRecaccess;

public:
	bool operator==(const MsdcRMUsergroupUniversal& comp);
	bool operator!=(const MsdcRMUsergroupUniversal& comp);
};

/**
  * ListMsdcRMUsergroupUniversal: recordset of TblMsdcRMUsergroupUniversal
  */
class ListMsdcRMUsergroupUniversal {

public:
	ListMsdcRMUsergroupUniversal();
	ListMsdcRMUsergroupUniversal(const ListMsdcRMUsergroupUniversal& src);
	~ListMsdcRMUsergroupUniversal();

	void clear();
	unsigned int size() const;
	void append(MsdcRMUsergroupUniversal* rec);

	MsdcRMUsergroupUniversal* operator[](const uint ix);
	ListMsdcRMUsergroupUniversal& operator=(const ListMsdcRMUsergroupUniversal& src);
	bool operator==(const ListMsdcRMUsergroupUniversal& comp);
	bool operator!=(const ListMsdcRMUsergroupUniversal& comp);

public:
	vector<MsdcRMUsergroupUniversal*> nodes;
};

/**
  * TblMsdcRMUsergroupUniversal: C++ wrapper for table TblMsdcRMUsergroupUniversal
  */
class TblMsdcRMUsergroupUniversal {

public:

public:
	TblMsdcRMUsergroupUniversal();
	virtual ~TblMsdcRMUsergroupUniversal();

public:
	virtual bool loadRecBySQL(const string& sqlstr, MsdcRMUsergroupUniversal** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListMsdcRMUsergroupUniversal& rst);

	virtual void insertRec(MsdcRMUsergroupUniversal* rec);
	ubigint insertNewRec(MsdcRMUsergroupUniversal** rec = NULL, const ubigint refMsdcMUsergroup = 0, const uint unvIxMsdcVMaintable = 0, const ubigint unvUref = 0, const uint ixMsdcVRecaccess = 0);
	ubigint appendNewRecToRst(ListMsdcRMUsergroupUniversal& rst, MsdcRMUsergroupUniversal** rec = NULL, const ubigint refMsdcMUsergroup = 0, const uint unvIxMsdcVMaintable = 0, const ubigint unvUref = 0, const uint ixMsdcVRecaccess = 0);
	virtual void insertRst(ListMsdcRMUsergroupUniversal& rst, bool transact = false);
	virtual void updateRec(MsdcRMUsergroupUniversal* rec);
	virtual void updateRst(ListMsdcRMUsergroupUniversal& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, MsdcRMUsergroupUniversal** rec);
	virtual bool loadRecByUsgMtbUnv(ubigint refMsdcMUsergroup, uint unvIxMsdcVMaintable, ubigint unvUref, MsdcRMUsergroupUniversal** rec);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListMsdcRMUsergroupUniversal& rst);
};

/**
  * LiteTblMsdcRMUsergroupUniversal: C++ wrapper for table TblMsdcRMUsergroupUniversal (SQLite database)
  */
class LiteTblMsdcRMUsergroupUniversal : public TblMsdcRMUsergroupUniversal, public LiteTable {

public:
	LiteTblMsdcRMUsergroupUniversal();
	~LiteTblMsdcRMUsergroupUniversal();

public:
	void initStatements();

public:
	sqlite3_stmt* stmtInsertRec;
	sqlite3_stmt* stmtUpdateRec;
	sqlite3_stmt* stmtRemoveRecByRef;

	sqlite3_stmt* stmtLoadRecByRef;
	sqlite3_stmt* stmtLoadRecByUsgMtbUnv;

private:
	bool loadRec(sqlite3_stmt* stmt, MsdcRMUsergroupUniversal** rec);
	ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListMsdcRMUsergroupUniversal& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, MsdcRMUsergroupUniversal** rec);

public:
	bool loadRecBySQL(const string& sqlstr, MsdcRMUsergroupUniversal** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListMsdcRMUsergroupUniversal& rst);

	void insertRec(MsdcRMUsergroupUniversal* rec);
	void insertRst(ListMsdcRMUsergroupUniversal& rst, bool transact = false);
	void updateRec(MsdcRMUsergroupUniversal* rec);
	void updateRst(ListMsdcRMUsergroupUniversal& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, MsdcRMUsergroupUniversal** rec);
	bool loadRecByUsgMtbUnv(ubigint refMsdcMUsergroup, uint unvIxMsdcVMaintable, ubigint unvUref, MsdcRMUsergroupUniversal** rec);
};

#endif

