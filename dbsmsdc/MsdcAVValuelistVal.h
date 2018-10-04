/**
  * \file MsdcAVValuelistVal.h
  * database access for table TblMsdcAVValuelistVal (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Oct 2018
  * \date modified: 4 Oct 2018
  */

#ifndef MSDCAVVALUELISTVAL_H
#define MSDCAVVALUELISTVAL_H

#include <sbecore/LiteDbs.h>

/**
  * MsdcAVValuelistVal: record of TblMsdcAVValuelistVal
  */
class MsdcAVValuelistVal {

public:
	MsdcAVValuelistVal(const ubigint ref = 0, const uint vlsIxMsdcVValuelist = 0, const uint vlsNum = 0, const uint x1IxMsdcVLocale = 0, const string Val = "");

public:
	ubigint ref;
	uint vlsIxMsdcVValuelist;
	uint vlsNum;
	uint x1IxMsdcVLocale;
	string Val;

public:
	bool operator==(const MsdcAVValuelistVal& comp);
	bool operator!=(const MsdcAVValuelistVal& comp);
};

/**
  * ListMsdcAVValuelistVal: recordset of TblMsdcAVValuelistVal
  */
class ListMsdcAVValuelistVal {

public:
	ListMsdcAVValuelistVal();
	ListMsdcAVValuelistVal(const ListMsdcAVValuelistVal& src);
	~ListMsdcAVValuelistVal();

	void clear();
	unsigned int size() const;
	void append(MsdcAVValuelistVal* rec);

	MsdcAVValuelistVal* operator[](const uint ix);
	ListMsdcAVValuelistVal& operator=(const ListMsdcAVValuelistVal& src);
	bool operator==(const ListMsdcAVValuelistVal& comp);
	bool operator!=(const ListMsdcAVValuelistVal& comp);

public:
	vector<MsdcAVValuelistVal*> nodes;
};

/**
  * TblMsdcAVValuelistVal: C++ wrapper for table TblMsdcAVValuelistVal
  */
class TblMsdcAVValuelistVal {

public:

public:
	TblMsdcAVValuelistVal();
	virtual ~TblMsdcAVValuelistVal();

public:
	virtual bool loadRecBySQL(const string& sqlstr, MsdcAVValuelistVal** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListMsdcAVValuelistVal& rst);

	virtual void insertRec(MsdcAVValuelistVal* rec);
	ubigint insertNewRec(MsdcAVValuelistVal** rec = NULL, const uint vlsIxMsdcVValuelist = 0, const uint vlsNum = 0, const uint x1IxMsdcVLocale = 0, const string Val = "");
	ubigint appendNewRecToRst(ListMsdcAVValuelistVal& rst, MsdcAVValuelistVal** rec = NULL, const uint vlsIxMsdcVValuelist = 0, const uint vlsNum = 0, const uint x1IxMsdcVLocale = 0, const string Val = "");
	virtual void insertRst(ListMsdcAVValuelistVal& rst, bool transact = false);
	virtual void updateRec(MsdcAVValuelistVal* rec);
	virtual void updateRst(ListMsdcAVValuelistVal& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, MsdcAVValuelistVal** rec);
	virtual ubigint loadRstByVlsLcl(uint vlsIxMsdcVValuelist, uint x1IxMsdcVLocale, const bool append, ListMsdcAVValuelistVal& rst);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListMsdcAVValuelistVal& rst);
};

/**
  * LiteTblMsdcAVValuelistVal: C++ wrapper for table TblMsdcAVValuelistVal (SQLite database)
  */
class LiteTblMsdcAVValuelistVal : public TblMsdcAVValuelistVal, public LiteTable {

public:
	LiteTblMsdcAVValuelistVal();
	~LiteTblMsdcAVValuelistVal();

public:
	void initStatements();

public:
	sqlite3_stmt* stmtInsertRec;
	sqlite3_stmt* stmtUpdateRec;
	sqlite3_stmt* stmtRemoveRecByRef;

	sqlite3_stmt* stmtLoadRecByRef;
	sqlite3_stmt* stmtLoadRstByVlsLcl;

private:
	bool loadRec(sqlite3_stmt* stmt, MsdcAVValuelistVal** rec);
	ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListMsdcAVValuelistVal& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, MsdcAVValuelistVal** rec);
	ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListMsdcAVValuelistVal& rst);

public:
	bool loadRecBySQL(const string& sqlstr, MsdcAVValuelistVal** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListMsdcAVValuelistVal& rst);

	void insertRec(MsdcAVValuelistVal* rec);
	void insertRst(ListMsdcAVValuelistVal& rst, bool transact = false);
	void updateRec(MsdcAVValuelistVal* rec);
	void updateRst(ListMsdcAVValuelistVal& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, MsdcAVValuelistVal** rec);
	ubigint loadRstByVlsLcl(uint vlsIxMsdcVValuelist, uint x1IxMsdcVLocale, const bool append, ListMsdcAVValuelistVal& rst);
};

#endif

