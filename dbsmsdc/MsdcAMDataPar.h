/**
  * \file MsdcAMDataPar.h
  * database access for table TblMsdcAMDataPar (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Oct 2018
  * \date modified: 4 Oct 2018
  */

#ifndef MSDCAMDATAPAR_H
#define MSDCAMDATAPAR_H

#include <sbecore/LiteDbs.h>

/**
  * MsdcAMDataPar: record of TblMsdcAMDataPar
  */
class MsdcAMDataPar {

public:
	MsdcAMDataPar(const ubigint ref = 0, const ubigint refMsdcMData = 0, const double x1Start = 0.0, const string x2SrefKKey = "", const ubigint refMsdcMFile = 0, const string Val = "", const string Bindata = "");

public:
	ubigint ref;
	ubigint refMsdcMData;
	double x1Start;
	string x2SrefKKey;
	ubigint refMsdcMFile;
	string Val;
	string Bindata;

public:
	bool operator==(const MsdcAMDataPar& comp);
	bool operator!=(const MsdcAMDataPar& comp);
};

/**
  * ListMsdcAMDataPar: recordset of TblMsdcAMDataPar
  */
class ListMsdcAMDataPar {

public:
	ListMsdcAMDataPar();
	ListMsdcAMDataPar(const ListMsdcAMDataPar& src);
	~ListMsdcAMDataPar();

	void clear();
	unsigned int size() const;
	void append(MsdcAMDataPar* rec);

	MsdcAMDataPar* operator[](const uint ix);
	ListMsdcAMDataPar& operator=(const ListMsdcAMDataPar& src);
	bool operator==(const ListMsdcAMDataPar& comp);
	bool operator!=(const ListMsdcAMDataPar& comp);

public:
	vector<MsdcAMDataPar*> nodes;
};

/**
  * TblMsdcAMDataPar: C++ wrapper for table TblMsdcAMDataPar
  */
class TblMsdcAMDataPar {

public:

public:
	TblMsdcAMDataPar();
	virtual ~TblMsdcAMDataPar();

public:
	virtual bool loadRecBySQL(const string& sqlstr, MsdcAMDataPar** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListMsdcAMDataPar& rst);

	virtual void insertRec(MsdcAMDataPar* rec);
	ubigint insertNewRec(MsdcAMDataPar** rec = NULL, const ubigint refMsdcMData = 0, const double x1Start = 0.0, const string x2SrefKKey = "", const ubigint refMsdcMFile = 0, const string Val = "", const string Bindata = "");
	ubigint appendNewRecToRst(ListMsdcAMDataPar& rst, MsdcAMDataPar** rec = NULL, const ubigint refMsdcMData = 0, const double x1Start = 0.0, const string x2SrefKKey = "", const ubigint refMsdcMFile = 0, const string Val = "", const string Bindata = "");
	virtual void insertRst(ListMsdcAMDataPar& rst, bool transact = false);
	virtual void updateRec(MsdcAMDataPar* rec);
	virtual void updateRst(ListMsdcAMDataPar& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, MsdcAMDataPar** rec);
	virtual ubigint loadRstByDat(ubigint refMsdcMData, const bool append, ListMsdcAMDataPar& rst);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListMsdcAMDataPar& rst);
};

/**
  * LiteTblMsdcAMDataPar: C++ wrapper for table TblMsdcAMDataPar (SQLite database)
  */
class LiteTblMsdcAMDataPar : public TblMsdcAMDataPar, public LiteTable {

public:
	LiteTblMsdcAMDataPar();
	~LiteTblMsdcAMDataPar();

public:
	void initStatements();

public:
	sqlite3_stmt* stmtInsertRec;
	sqlite3_stmt* stmtUpdateRec;
	sqlite3_stmt* stmtRemoveRecByRef;

	sqlite3_stmt* stmtLoadRecByRef;
	sqlite3_stmt* stmtLoadRstByDat;

private:
	bool loadRec(sqlite3_stmt* stmt, MsdcAMDataPar** rec);
	ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListMsdcAMDataPar& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, MsdcAMDataPar** rec);
	ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListMsdcAMDataPar& rst);

public:
	bool loadRecBySQL(const string& sqlstr, MsdcAMDataPar** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListMsdcAMDataPar& rst);

	void insertRec(MsdcAMDataPar* rec);
	void insertRst(ListMsdcAMDataPar& rst, bool transact = false);
	void updateRec(MsdcAMDataPar* rec);
	void updateRst(ListMsdcAMDataPar& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, MsdcAMDataPar** rec);
	ubigint loadRstByDat(ubigint refMsdcMData, const bool append, ListMsdcAMDataPar& rst);
};

#endif

