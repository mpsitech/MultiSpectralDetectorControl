/**
  * \file MsdcAccRMUserUniversal.h
  * database access for table TblMsdcAccRMUserUniversal (declarations)
  * \author Alexander Wirthmueller
  * \date created: 18 Dec 2018
  * \date modified: 18 Dec 2018
  */

#ifndef MSDCACCRMUSERUNIVERSAL_H
#define MSDCACCRMUSERUNIVERSAL_H

#include <sbecore/LiteDbs.h>

/**
  * MsdcAccRMUserUniversal: record of TblMsdcAccRMUserUniversal
  */
class MsdcAccRMUserUniversal {

public:
	MsdcAccRMUserUniversal(const ubigint ref = 0, const ubigint refMsdcMUser = 0, const uint unvIxMsdcVMaintable = 0, const ubigint unvUref = 0, const uint ixMsdcVRecaccess = 0);

public:
	ubigint ref;
	ubigint refMsdcMUser;
	uint unvIxMsdcVMaintable;
	ubigint unvUref;
	uint ixMsdcVRecaccess;

public:
	bool operator==(const MsdcAccRMUserUniversal& comp);
	bool operator!=(const MsdcAccRMUserUniversal& comp);
};

/**
  * ListMsdcAccRMUserUniversal: recordset of TblMsdcAccRMUserUniversal
  */
class ListMsdcAccRMUserUniversal {

public:
	ListMsdcAccRMUserUniversal();
	ListMsdcAccRMUserUniversal(const ListMsdcAccRMUserUniversal& src);
	~ListMsdcAccRMUserUniversal();

	void clear();
	unsigned int size() const;
	void append(MsdcAccRMUserUniversal* rec);

	MsdcAccRMUserUniversal* operator[](const uint ix);
	ListMsdcAccRMUserUniversal& operator=(const ListMsdcAccRMUserUniversal& src);
	bool operator==(const ListMsdcAccRMUserUniversal& comp);
	bool operator!=(const ListMsdcAccRMUserUniversal& comp);

public:
	vector<MsdcAccRMUserUniversal*> nodes;
};

/**
  * TblMsdcAccRMUserUniversal: C++ wrapper for table TblMsdcAccRMUserUniversal
  */
class TblMsdcAccRMUserUniversal {

public:

public:
	TblMsdcAccRMUserUniversal();
	virtual ~TblMsdcAccRMUserUniversal();

public:
	virtual bool loadRecBySQL(const string& sqlstr, MsdcAccRMUserUniversal** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListMsdcAccRMUserUniversal& rst);

	virtual void insertRec(MsdcAccRMUserUniversal* rec);
	ubigint insertNewRec(MsdcAccRMUserUniversal** rec = NULL, const ubigint refMsdcMUser = 0, const uint unvIxMsdcVMaintable = 0, const ubigint unvUref = 0, const uint ixMsdcVRecaccess = 0);
	ubigint appendNewRecToRst(ListMsdcAccRMUserUniversal& rst, MsdcAccRMUserUniversal** rec = NULL, const ubigint refMsdcMUser = 0, const uint unvIxMsdcVMaintable = 0, const ubigint unvUref = 0, const uint ixMsdcVRecaccess = 0);
	virtual void insertRst(ListMsdcAccRMUserUniversal& rst, bool transact = false);
	virtual void updateRec(MsdcAccRMUserUniversal* rec);
	virtual void updateRst(ListMsdcAccRMUserUniversal& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, MsdcAccRMUserUniversal** rec);
	virtual bool loadRecByUsrMtbUnv(ubigint refMsdcMUser, uint unvIxMsdcVMaintable, ubigint unvUref, MsdcAccRMUserUniversal** rec);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListMsdcAccRMUserUniversal& rst);
};

/**
  * LiteTblMsdcAccRMUserUniversal: C++ wrapper for table TblMsdcAccRMUserUniversal (SQLite database)
  */
class LiteTblMsdcAccRMUserUniversal : public TblMsdcAccRMUserUniversal, public LiteTable {

public:
	LiteTblMsdcAccRMUserUniversal();
	~LiteTblMsdcAccRMUserUniversal();

public:
	void initStatements();

public:
	sqlite3_stmt* stmtInsertRec;
	sqlite3_stmt* stmtUpdateRec;
	sqlite3_stmt* stmtRemoveRecByRef;

	sqlite3_stmt* stmtLoadRecByRef;
	sqlite3_stmt* stmtLoadRecByUsrMtbUnv;

private:
	bool loadRec(sqlite3_stmt* stmt, MsdcAccRMUserUniversal** rec);
	ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListMsdcAccRMUserUniversal& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, MsdcAccRMUserUniversal** rec);

public:
	bool loadRecBySQL(const string& sqlstr, MsdcAccRMUserUniversal** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListMsdcAccRMUserUniversal& rst);

	void insertRec(MsdcAccRMUserUniversal* rec);
	void insertRst(ListMsdcAccRMUserUniversal& rst, bool transact = false);
	void updateRec(MsdcAccRMUserUniversal* rec);
	void updateRst(ListMsdcAccRMUserUniversal& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, MsdcAccRMUserUniversal** rec);
	bool loadRecByUsrMtbUnv(ubigint refMsdcMUser, uint unvIxMsdcVMaintable, ubigint unvUref, MsdcAccRMUserUniversal** rec);
};

#endif

