/**
  * \file MsdcMData.h
  * database access for table TblMsdcMData (declarations)
  * \author Alexander Wirthmueller
  * \date created: 12 Sep 2018
  * \date modified: 12 Sep 2018
  */

#ifndef MSDCMDATA_H
#define MSDCMDATA_H

#include <sbecore/LiteDbs.h>

/**
  * MsdcMData: record of TblMsdcMData
  */
class MsdcMData {

public:
	MsdcMData(const ubigint ref = 0, const ubigint refMsdcMPeriod = 0, const uint start = 0, const uint stop = 0, const string srefMsdcKAcqfeat = "", const string Comment = "");

public:
	ubigint ref;
	ubigint refMsdcMPeriod;
	uint start;
	uint stop;
	string srefMsdcKAcqfeat;
	string Comment;

public:
	bool operator==(const MsdcMData& comp);
	bool operator!=(const MsdcMData& comp);
};

/**
  * ListMsdcMData: recordset of TblMsdcMData
  */
class ListMsdcMData {

public:
	ListMsdcMData();
	ListMsdcMData(const ListMsdcMData& src);
	~ListMsdcMData();

	void clear();
	unsigned int size() const;
	void append(MsdcMData* rec);

	MsdcMData* operator[](const uint ix);
	ListMsdcMData& operator=(const ListMsdcMData& src);
	bool operator==(const ListMsdcMData& comp);
	bool operator!=(const ListMsdcMData& comp);

public:
	vector<MsdcMData*> nodes;
};

/**
  * TblMsdcMData: C++ wrapper for table TblMsdcMData
  */
class TblMsdcMData {

public:

public:
	TblMsdcMData();
	virtual ~TblMsdcMData();

public:
	virtual bool loadRecBySQL(const string& sqlstr, MsdcMData** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListMsdcMData& rst);

	virtual void insertRec(MsdcMData* rec);
	ubigint insertNewRec(MsdcMData** rec = NULL, const ubigint refMsdcMPeriod = 0, const uint start = 0, const uint stop = 0, const string srefMsdcKAcqfeat = "", const string Comment = "");
	ubigint appendNewRecToRst(ListMsdcMData& rst, MsdcMData** rec = NULL, const ubigint refMsdcMPeriod = 0, const uint start = 0, const uint stop = 0, const string srefMsdcKAcqfeat = "", const string Comment = "");
	virtual void insertRst(ListMsdcMData& rst, bool transact = false);
	virtual void updateRec(MsdcMData* rec);
	virtual void updateRst(ListMsdcMData& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, MsdcMData** rec);
	virtual ubigint loadRstByPrd(ubigint refMsdcMPeriod, const bool append, ListMsdcMData& rst);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListMsdcMData& rst);
};

/**
  * LiteTblMsdcMData: C++ wrapper for table TblMsdcMData (SQLite database)
  */
class LiteTblMsdcMData : public TblMsdcMData, public LiteTable {

public:
	LiteTblMsdcMData();
	~LiteTblMsdcMData();

public:
	void initStatements();

public:
	sqlite3_stmt* stmtInsertRec;
	sqlite3_stmt* stmtUpdateRec;
	sqlite3_stmt* stmtRemoveRecByRef;

	sqlite3_stmt* stmtLoadRecByRef;
	sqlite3_stmt* stmtLoadRstByPrd;

private:
	bool loadRec(sqlite3_stmt* stmt, MsdcMData** rec);
	ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListMsdcMData& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, MsdcMData** rec);
	ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListMsdcMData& rst);

public:
	bool loadRecBySQL(const string& sqlstr, MsdcMData** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListMsdcMData& rst);

	void insertRec(MsdcMData* rec);
	void insertRst(ListMsdcMData& rst, bool transact = false);
	void updateRec(MsdcMData* rec);
	void updateRst(ListMsdcMData& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, MsdcMData** rec);
	ubigint loadRstByPrd(ubigint refMsdcMPeriod, const bool append, ListMsdcMData& rst);
};

#endif

