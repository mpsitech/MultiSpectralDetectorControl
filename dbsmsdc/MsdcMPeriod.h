/**
  * \file MsdcMPeriod.h
  * database access for table TblMsdcMPeriod (declarations)
  * \author Alexander Wirthmueller
  * \date created: 15 Aug 2018
  * \date modified: 15 Aug 2018
  */

#ifndef MSDCMPERIOD_H
#define MSDCMPERIOD_H

#include <sbecore/LiteDbs.h>

/**
  * MsdcMPeriod: record of TblMsdcMPeriod
  */
class MsdcMPeriod {

public:
	MsdcMPeriod(const ubigint ref = 0, const uint start = 0, const uint stop = 0);

public:
	ubigint ref;
	uint start;
	uint stop;

public:
	bool operator==(const MsdcMPeriod& comp);
	bool operator!=(const MsdcMPeriod& comp);
};

/**
  * ListMsdcMPeriod: recordset of TblMsdcMPeriod
  */
class ListMsdcMPeriod {

public:
	ListMsdcMPeriod();
	ListMsdcMPeriod(const ListMsdcMPeriod& src);
	~ListMsdcMPeriod();

	void clear();
	unsigned int size() const;
	void append(MsdcMPeriod* rec);

	MsdcMPeriod* operator[](const uint ix);
	ListMsdcMPeriod& operator=(const ListMsdcMPeriod& src);
	bool operator==(const ListMsdcMPeriod& comp);
	bool operator!=(const ListMsdcMPeriod& comp);

public:
	vector<MsdcMPeriod*> nodes;
};

/**
  * TblMsdcMPeriod: C++ wrapper for table TblMsdcMPeriod
  */
class TblMsdcMPeriod {

public:

public:
	TblMsdcMPeriod();
	virtual ~TblMsdcMPeriod();

public:
	virtual bool loadRecBySQL(const string& sqlstr, MsdcMPeriod** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListMsdcMPeriod& rst);

	virtual void insertRec(MsdcMPeriod* rec);
	ubigint insertNewRec(MsdcMPeriod** rec = NULL, const uint start = 0, const uint stop = 0);
	ubigint appendNewRecToRst(ListMsdcMPeriod& rst, MsdcMPeriod** rec = NULL, const uint start = 0, const uint stop = 0);
	virtual void insertRst(ListMsdcMPeriod& rst, bool transact = false);
	virtual void updateRec(MsdcMPeriod* rec);
	virtual void updateRst(ListMsdcMPeriod& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, MsdcMPeriod** rec);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListMsdcMPeriod& rst);
};

/**
  * LiteTblMsdcMPeriod: C++ wrapper for table TblMsdcMPeriod (SQLite database)
  */
class LiteTblMsdcMPeriod : public TblMsdcMPeriod, public LiteTable {

public:
	LiteTblMsdcMPeriod();
	~LiteTblMsdcMPeriod();

public:
	void initStatements();

public:
	sqlite3_stmt* stmtInsertRec;
	sqlite3_stmt* stmtUpdateRec;
	sqlite3_stmt* stmtRemoveRecByRef;

	sqlite3_stmt* stmtLoadRecByRef;

private:
	bool loadRec(sqlite3_stmt* stmt, MsdcMPeriod** rec);
	ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListMsdcMPeriod& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, MsdcMPeriod** rec);

public:
	bool loadRecBySQL(const string& sqlstr, MsdcMPeriod** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListMsdcMPeriod& rst);

	void insertRec(MsdcMPeriod* rec);
	void insertRst(ListMsdcMPeriod& rst, bool transact = false);
	void updateRec(MsdcMPeriod* rec);
	void updateRst(ListMsdcMPeriod& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, MsdcMPeriod** rec);
};

#endif

