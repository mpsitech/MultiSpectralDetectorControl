/**
  * \file MsdcJAVKeylistKey.h
  * database access for table TblMsdcJAVKeylistKey (declarations)
  * \author Alexander Wirthmueller
  * \date created: 15 Aug 2018
  * \date modified: 15 Aug 2018
  */

#ifndef MSDCJAVKEYLISTKEY_H
#define MSDCJAVKEYLISTKEY_H

#include <sbecore/LiteDbs.h>

/**
  * MsdcJAVKeylistKey: record of TblMsdcJAVKeylistKey
  */
class MsdcJAVKeylistKey {

public:
	MsdcJAVKeylistKey(const ubigint ref = 0, const ubigint refMsdcAVKeylistKey = 0, const uint x1IxMsdcVLocale = 0, const string Title = "", const string Comment = "");

public:
	ubigint ref;
	ubigint refMsdcAVKeylistKey;
	uint x1IxMsdcVLocale;
	string Title;
	string Comment;

public:
	bool operator==(const MsdcJAVKeylistKey& comp);
	bool operator!=(const MsdcJAVKeylistKey& comp);
};

/**
  * ListMsdcJAVKeylistKey: recordset of TblMsdcJAVKeylistKey
  */
class ListMsdcJAVKeylistKey {

public:
	ListMsdcJAVKeylistKey();
	ListMsdcJAVKeylistKey(const ListMsdcJAVKeylistKey& src);
	~ListMsdcJAVKeylistKey();

	void clear();
	unsigned int size() const;
	void append(MsdcJAVKeylistKey* rec);

	MsdcJAVKeylistKey* operator[](const uint ix);
	ListMsdcJAVKeylistKey& operator=(const ListMsdcJAVKeylistKey& src);
	bool operator==(const ListMsdcJAVKeylistKey& comp);
	bool operator!=(const ListMsdcJAVKeylistKey& comp);

public:
	vector<MsdcJAVKeylistKey*> nodes;
};

/**
  * TblMsdcJAVKeylistKey: C++ wrapper for table TblMsdcJAVKeylistKey
  */
class TblMsdcJAVKeylistKey {

public:

public:
	TblMsdcJAVKeylistKey();
	virtual ~TblMsdcJAVKeylistKey();

public:
	virtual bool loadRecBySQL(const string& sqlstr, MsdcJAVKeylistKey** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListMsdcJAVKeylistKey& rst);

	virtual void insertRec(MsdcJAVKeylistKey* rec);
	ubigint insertNewRec(MsdcJAVKeylistKey** rec = NULL, const ubigint refMsdcAVKeylistKey = 0, const uint x1IxMsdcVLocale = 0, const string Title = "", const string Comment = "");
	ubigint appendNewRecToRst(ListMsdcJAVKeylistKey& rst, MsdcJAVKeylistKey** rec = NULL, const ubigint refMsdcAVKeylistKey = 0, const uint x1IxMsdcVLocale = 0, const string Title = "", const string Comment = "");
	virtual void insertRst(ListMsdcJAVKeylistKey& rst, bool transact = false);
	virtual void updateRec(MsdcJAVKeylistKey* rec);
	virtual void updateRst(ListMsdcJAVKeylistKey& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, MsdcJAVKeylistKey** rec);
	virtual bool loadRecByKlkLcl(ubigint refMsdcAVKeylistKey, uint x1IxMsdcVLocale, MsdcJAVKeylistKey** rec);
	virtual ubigint loadRefsByKlk(ubigint refMsdcAVKeylistKey, const bool append, vector<ubigint>& refs);
	virtual ubigint loadRstByKlk(ubigint refMsdcAVKeylistKey, const bool append, ListMsdcJAVKeylistKey& rst);
	virtual bool loadTitByKlkLcl(ubigint refMsdcAVKeylistKey, uint x1IxMsdcVLocale, string& Title);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListMsdcJAVKeylistKey& rst);
};

/**
  * LiteTblMsdcJAVKeylistKey: C++ wrapper for table TblMsdcJAVKeylistKey (SQLite database)
  */
class LiteTblMsdcJAVKeylistKey : public TblMsdcJAVKeylistKey, public LiteTable {

public:
	LiteTblMsdcJAVKeylistKey();
	~LiteTblMsdcJAVKeylistKey();

public:
	void initStatements();

public:
	sqlite3_stmt* stmtInsertRec;
	sqlite3_stmt* stmtUpdateRec;
	sqlite3_stmt* stmtRemoveRecByRef;

	sqlite3_stmt* stmtLoadRecByRef;
	sqlite3_stmt* stmtLoadRecByKlkLcl;
	sqlite3_stmt* stmtLoadRefsByKlk;
	sqlite3_stmt* stmtLoadRstByKlk;
	sqlite3_stmt* stmtLoadTitByKlkLcl;

private:
	bool loadRec(sqlite3_stmt* stmt, MsdcJAVKeylistKey** rec);
	ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListMsdcJAVKeylistKey& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, MsdcJAVKeylistKey** rec);
	ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListMsdcJAVKeylistKey& rst);

public:
	bool loadRecBySQL(const string& sqlstr, MsdcJAVKeylistKey** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListMsdcJAVKeylistKey& rst);

	void insertRec(MsdcJAVKeylistKey* rec);
	void insertRst(ListMsdcJAVKeylistKey& rst, bool transact = false);
	void updateRec(MsdcJAVKeylistKey* rec);
	void updateRst(ListMsdcJAVKeylistKey& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, MsdcJAVKeylistKey** rec);
	bool loadRecByKlkLcl(ubigint refMsdcAVKeylistKey, uint x1IxMsdcVLocale, MsdcJAVKeylistKey** rec);
	ubigint loadRefsByKlk(ubigint refMsdcAVKeylistKey, const bool append, vector<ubigint>& refs);
	ubigint loadRstByKlk(ubigint refMsdcAVKeylistKey, const bool append, ListMsdcJAVKeylistKey& rst);
	bool loadTitByKlkLcl(ubigint refMsdcAVKeylistKey, uint x1IxMsdcVLocale, string& Title);
};

#endif

