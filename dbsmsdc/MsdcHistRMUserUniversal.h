/**
  * \file MsdcHistRMUserUniversal.h
  * database access for table TblMsdcHistRMUserUniversal (declarations)
  * \author Alexander Wirthmueller
  * \date created: 29 Aug 2018
  * \date modified: 29 Aug 2018
  */

#ifndef MSDCHISTRMUSERUNIVERSAL_H
#define MSDCHISTRMUSERUNIVERSAL_H

#include <sbecore/LiteDbs.h>

/**
  * MsdcHistRMUserUniversal: record of TblMsdcHistRMUserUniversal
  */
class MsdcHistRMUserUniversal {

public:
	MsdcHistRMUserUniversal(const ubigint ref = 0, const ubigint refMsdcMUser = 0, const uint unvIxMsdcVMaintable = 0, const ubigint unvUref = 0, const uint ixMsdcVCard = 0, const uint ixMsdcVPreset = 0, const uint preIxMsdcVMaintable = 0, const ubigint preUref = 0, const uint start = 0);

public:
	ubigint ref;
	ubigint refMsdcMUser;
	uint unvIxMsdcVMaintable;
	ubigint unvUref;
	uint ixMsdcVCard;
	uint ixMsdcVPreset;
	uint preIxMsdcVMaintable;
	ubigint preUref;
	uint start;

public:
	bool operator==(const MsdcHistRMUserUniversal& comp);
	bool operator!=(const MsdcHistRMUserUniversal& comp);
};

/**
  * ListMsdcHistRMUserUniversal: recordset of TblMsdcHistRMUserUniversal
  */
class ListMsdcHistRMUserUniversal {

public:
	ListMsdcHistRMUserUniversal();
	ListMsdcHistRMUserUniversal(const ListMsdcHistRMUserUniversal& src);
	~ListMsdcHistRMUserUniversal();

	void clear();
	unsigned int size() const;
	void append(MsdcHistRMUserUniversal* rec);

	MsdcHistRMUserUniversal* operator[](const uint ix);
	ListMsdcHistRMUserUniversal& operator=(const ListMsdcHistRMUserUniversal& src);
	bool operator==(const ListMsdcHistRMUserUniversal& comp);
	bool operator!=(const ListMsdcHistRMUserUniversal& comp);

public:
	vector<MsdcHistRMUserUniversal*> nodes;
};

/**
  * TblMsdcHistRMUserUniversal: C++ wrapper for table TblMsdcHistRMUserUniversal
  */
class TblMsdcHistRMUserUniversal {

public:

public:
	TblMsdcHistRMUserUniversal();
	virtual ~TblMsdcHistRMUserUniversal();

public:
	virtual bool loadRecBySQL(const string& sqlstr, MsdcHistRMUserUniversal** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListMsdcHistRMUserUniversal& rst);

	virtual void insertRec(MsdcHistRMUserUniversal* rec);
	ubigint insertNewRec(MsdcHistRMUserUniversal** rec = NULL, const ubigint refMsdcMUser = 0, const uint unvIxMsdcVMaintable = 0, const ubigint unvUref = 0, const uint ixMsdcVCard = 0, const uint ixMsdcVPreset = 0, const uint preIxMsdcVMaintable = 0, const ubigint preUref = 0, const uint start = 0);
	ubigint appendNewRecToRst(ListMsdcHistRMUserUniversal& rst, MsdcHistRMUserUniversal** rec = NULL, const ubigint refMsdcMUser = 0, const uint unvIxMsdcVMaintable = 0, const ubigint unvUref = 0, const uint ixMsdcVCard = 0, const uint ixMsdcVPreset = 0, const uint preIxMsdcVMaintable = 0, const ubigint preUref = 0, const uint start = 0);
	virtual void insertRst(ListMsdcHistRMUserUniversal& rst, bool transact = false);
	virtual void updateRec(MsdcHistRMUserUniversal* rec);
	virtual void updateRst(ListMsdcHistRMUserUniversal& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, MsdcHistRMUserUniversal** rec);
	virtual ubigint loadRstByUsrCrd(ubigint refMsdcMUser, uint ixMsdcVCard, const bool append, ListMsdcHistRMUserUniversal& rst);
	virtual bool loadUnuByRef(ubigint ref, ubigint& unvUref);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListMsdcHistRMUserUniversal& rst);
};

/**
  * LiteTblMsdcHistRMUserUniversal: C++ wrapper for table TblMsdcHistRMUserUniversal (SQLite database)
  */
class LiteTblMsdcHistRMUserUniversal : public TblMsdcHistRMUserUniversal, public LiteTable {

public:
	LiteTblMsdcHistRMUserUniversal();
	~LiteTblMsdcHistRMUserUniversal();

public:
	void initStatements();

public:
	sqlite3_stmt* stmtInsertRec;
	sqlite3_stmt* stmtUpdateRec;
	sqlite3_stmt* stmtRemoveRecByRef;

	sqlite3_stmt* stmtLoadRecByRef;
	sqlite3_stmt* stmtLoadRstByUsrCrd;
	sqlite3_stmt* stmtLoadUnuByRef;

private:
	bool loadRec(sqlite3_stmt* stmt, MsdcHistRMUserUniversal** rec);
	ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListMsdcHistRMUserUniversal& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, MsdcHistRMUserUniversal** rec);
	ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListMsdcHistRMUserUniversal& rst);

public:
	bool loadRecBySQL(const string& sqlstr, MsdcHistRMUserUniversal** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListMsdcHistRMUserUniversal& rst);

	void insertRec(MsdcHistRMUserUniversal* rec);
	void insertRst(ListMsdcHistRMUserUniversal& rst, bool transact = false);
	void updateRec(MsdcHistRMUserUniversal* rec);
	void updateRst(ListMsdcHistRMUserUniversal& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, MsdcHistRMUserUniversal** rec);
	ubigint loadRstByUsrCrd(ubigint refMsdcMUser, uint ixMsdcVCard, const bool append, ListMsdcHistRMUserUniversal& rst);
	bool loadUnuByRef(ubigint ref, ubigint& unvUref);
};

#endif

