/**
  * \file MsdcQDatAPar.h
  * Dbs and XML wrapper for table TblMsdcQDatAPar (declarations)
  * \author Alexander Wirthmueller
  * \date created: 12 Sep 2018
  * \date modified: 12 Sep 2018
  */

#ifndef MSDCQDATAPAR_H
#define MSDCQDATAPAR_H

#include <sbecore/LiteDbs.h>

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * MsdcQDatAPar: record of TblMsdcQDatAPar
  */
class MsdcQDatAPar {

public:
	MsdcQDatAPar(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const double x1Start = 0.0, const string ftmX1Start = "", const string x2SrefKKey = "", const string titX2SrefKKey = "", const ubigint refMsdcMFile = 0, const string stubRefMsdcMFile = "", const string Val = "", const string Bindata = "");

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	double x1Start;
	string ftmX1Start;
	string x2SrefKKey;
	string titX2SrefKKey;
	ubigint refMsdcMFile;
	string stubRefMsdcMFile;
	string Val;
	string Bindata;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListMsdcQDatAPar: recordset of TblMsdcQDatAPar
  */
class ListMsdcQDatAPar {

public:
	ListMsdcQDatAPar();
	ListMsdcQDatAPar(const ListMsdcQDatAPar& src);
	~ListMsdcQDatAPar();

	void clear();
	unsigned int size() const;
	void append(MsdcQDatAPar* rec);

	ListMsdcQDatAPar& operator=(const ListMsdcQDatAPar& src);

public:
	vector<MsdcQDatAPar*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblMsdcQDatAPar: C++ wrapper for table TblMsdcQDatAPar
  */
class TblMsdcQDatAPar {

public:
	TblMsdcQDatAPar();
	virtual ~TblMsdcQDatAPar();

public:
	virtual bool loadRecBySQL(const string& sqlstr, MsdcQDatAPar** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListMsdcQDatAPar& rst);

	virtual void insertRec(MsdcQDatAPar* rec);
	ubigint insertNewRec(MsdcQDatAPar** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const double x1Start = 0.0, const string ftmX1Start = "", const string x2SrefKKey = "", const string titX2SrefKKey = "", const ubigint refMsdcMFile = 0, const string stubRefMsdcMFile = "", const string Val = "", const string Bindata = "");
	ubigint appendNewRecToRst(ListMsdcQDatAPar& rst, MsdcQDatAPar** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const double x1Start = 0.0, const string ftmX1Start = "", const string x2SrefKKey = "", const string titX2SrefKKey = "", const ubigint refMsdcMFile = 0, const string stubRefMsdcMFile = "", const string Val = "", const string Bindata = "");
	virtual void insertRst(ListMsdcQDatAPar& rst);
	virtual void updateRec(MsdcQDatAPar* rec);
	virtual void updateRst(ListMsdcQDatAPar& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, MsdcQDatAPar** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListMsdcQDatAPar& rst);
};

/**
  * LiteMsdcQDatAPar: C++ wrapper for table TblMsdcQDatAPar (SQLite database)
  */
class LiteTblMsdcQDatAPar : public TblMsdcQDatAPar, public LiteTable {

public:
	LiteTblMsdcQDatAPar();
	~LiteTblMsdcQDatAPar();

public:
	void initStatements();

public:
	sqlite3_stmt* stmtInsertRec;
	sqlite3_stmt* stmtUpdateRec;
	sqlite3_stmt* stmtRemoveRecByQref;
	sqlite3_stmt* stmtRemoveRstByJref;

	sqlite3_stmt* stmtLoadRecByQref;
	sqlite3_stmt* stmtLoadRecByJref;
	sqlite3_stmt* stmtLoadRstByJref;

private:
	bool loadRec(sqlite3_stmt* stmt, MsdcQDatAPar** rec);
	ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListMsdcQDatAPar& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, MsdcQDatAPar** rec);
	ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListMsdcQDatAPar& rst);

public:
	bool loadRecBySQL(const string& sqlstr, MsdcQDatAPar** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListMsdcQDatAPar& rst);

	void insertRec(MsdcQDatAPar* rec);
	void insertRst(ListMsdcQDatAPar& rst);
	void updateRec(MsdcQDatAPar* rec);
	void updateRst(ListMsdcQDatAPar& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, MsdcQDatAPar** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListMsdcQDatAPar& rst);
};
#endif

