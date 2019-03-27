/**
  * \file MsdcAVKeylistKey.h
  * database access for table TblMsdcAVKeylistKey (declarations)
  * \author Alexander Wirthmueller
  * \date created: 18 Dec 2018
  * \date modified: 18 Dec 2018
  */

#ifndef MSDCAVKEYLISTKEY_H
#define MSDCAVKEYLISTKEY_H

#include <sbecore/LiteDbs.h>

/**
  * MsdcAVKeylistKey: record of TblMsdcAVKeylistKey
  */
class MsdcAVKeylistKey {

public:
	MsdcAVKeylistKey(const ubigint ref = 0, const uint klsIxMsdcVKeylist = 0, const uint klsNum = 0, const uint x1IxMsdcVMaintable = 0, const ubigint x1Uref = 0, const bool Fixed = false, const string sref = "", const string Avail = "", const string Implied = "", const ubigint refJ = 0, const string Title = "", const string Comment = "");

public:
	ubigint ref;
	uint klsIxMsdcVKeylist;
	uint klsNum;
	uint x1IxMsdcVMaintable;
	ubigint x1Uref;
	bool Fixed;
	string sref;
	string Avail;
	string Implied;
	ubigint refJ;
	string Title;
	string Comment;

public:
	bool operator==(const MsdcAVKeylistKey& comp);
	bool operator!=(const MsdcAVKeylistKey& comp);
};

/**
  * ListMsdcAVKeylistKey: recordset of TblMsdcAVKeylistKey
  */
class ListMsdcAVKeylistKey {

public:
	ListMsdcAVKeylistKey();
	ListMsdcAVKeylistKey(const ListMsdcAVKeylistKey& src);
	~ListMsdcAVKeylistKey();

	void clear();
	unsigned int size() const;
	void append(MsdcAVKeylistKey* rec);

	MsdcAVKeylistKey* operator[](const uint ix);
	ListMsdcAVKeylistKey& operator=(const ListMsdcAVKeylistKey& src);
	bool operator==(const ListMsdcAVKeylistKey& comp);
	bool operator!=(const ListMsdcAVKeylistKey& comp);

public:
	vector<MsdcAVKeylistKey*> nodes;
};

/**
  * TblMsdcAVKeylistKey: C++ wrapper for table TblMsdcAVKeylistKey
  */
class TblMsdcAVKeylistKey {

public:

public:
	TblMsdcAVKeylistKey();
	virtual ~TblMsdcAVKeylistKey();

public:
	virtual bool loadRecBySQL(const string& sqlstr, MsdcAVKeylistKey** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListMsdcAVKeylistKey& rst);

	virtual void insertRec(MsdcAVKeylistKey* rec);
	ubigint insertNewRec(MsdcAVKeylistKey** rec = NULL, const uint klsIxMsdcVKeylist = 0, const uint klsNum = 0, const uint x1IxMsdcVMaintable = 0, const ubigint x1Uref = 0, const bool Fixed = false, const string sref = "", const string Avail = "", const string Implied = "", const ubigint refJ = 0, const string Title = "", const string Comment = "");
	ubigint appendNewRecToRst(ListMsdcAVKeylistKey& rst, MsdcAVKeylistKey** rec = NULL, const uint klsIxMsdcVKeylist = 0, const uint klsNum = 0, const uint x1IxMsdcVMaintable = 0, const ubigint x1Uref = 0, const bool Fixed = false, const string sref = "", const string Avail = "", const string Implied = "", const ubigint refJ = 0, const string Title = "", const string Comment = "");
	virtual void insertRst(ListMsdcAVKeylistKey& rst, bool transact = false);
	virtual void updateRec(MsdcAVKeylistKey* rec);
	virtual void updateRst(ListMsdcAVKeylistKey& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, MsdcAVKeylistKey** rec);
	virtual bool loadRefByKlsMtbUrfSrf(uint klsIxMsdcVKeylist, uint x1IxMsdcVMaintable, ubigint x1Uref, string sref, ubigint& ref);
	virtual bool loadRefByKlsSrf(uint klsIxMsdcVKeylist, string sref, ubigint& ref);
	virtual ubigint loadRstByKls(uint klsIxMsdcVKeylist, const bool append, ListMsdcAVKeylistKey& rst);
	virtual ubigint loadRstByKlsMtbUrf(uint klsIxMsdcVKeylist, uint x1IxMsdcVMaintable, ubigint x1Uref, const bool append, ListMsdcAVKeylistKey& rst);
	virtual bool loadTitByRef(ubigint ref, string& Title);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListMsdcAVKeylistKey& rst);
};

/**
  * LiteTblMsdcAVKeylistKey: C++ wrapper for table TblMsdcAVKeylistKey (SQLite database)
  */
class LiteTblMsdcAVKeylistKey : public TblMsdcAVKeylistKey, public LiteTable {

public:
	LiteTblMsdcAVKeylistKey();
	~LiteTblMsdcAVKeylistKey();

public:
	void initStatements();

public:
	sqlite3_stmt* stmtInsertRec;
	sqlite3_stmt* stmtUpdateRec;
	sqlite3_stmt* stmtRemoveRecByRef;

	sqlite3_stmt* stmtLoadRecByRef;
	sqlite3_stmt* stmtLoadRefByKlsMtbUrfSrf;
	sqlite3_stmt* stmtLoadRefByKlsSrf;
	sqlite3_stmt* stmtLoadRstByKls;
	sqlite3_stmt* stmtLoadRstByKlsMtbUrf;
	sqlite3_stmt* stmtLoadTitByRef;

private:
	bool loadRec(sqlite3_stmt* stmt, MsdcAVKeylistKey** rec);
	ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListMsdcAVKeylistKey& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, MsdcAVKeylistKey** rec);
	ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListMsdcAVKeylistKey& rst);

public:
	bool loadRecBySQL(const string& sqlstr, MsdcAVKeylistKey** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListMsdcAVKeylistKey& rst);

	void insertRec(MsdcAVKeylistKey* rec);
	void insertRst(ListMsdcAVKeylistKey& rst, bool transact = false);
	void updateRec(MsdcAVKeylistKey* rec);
	void updateRst(ListMsdcAVKeylistKey& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, MsdcAVKeylistKey** rec);
	bool loadRefByKlsMtbUrfSrf(uint klsIxMsdcVKeylist, uint x1IxMsdcVMaintable, ubigint x1Uref, string sref, ubigint& ref);
	bool loadRefByKlsSrf(uint klsIxMsdcVKeylist, string sref, ubigint& ref);
	ubigint loadRstByKls(uint klsIxMsdcVKeylist, const bool append, ListMsdcAVKeylistKey& rst);
	ubigint loadRstByKlsMtbUrf(uint klsIxMsdcVKeylist, uint x1IxMsdcVMaintable, ubigint x1Uref, const bool append, ListMsdcAVKeylistKey& rst);
	bool loadTitByRef(ubigint ref, string& Title);
};

#endif

