/**
  * \file MsdcAMPersonDetail.h
  * database access for table TblMsdcAMPersonDetail (declarations)
  * \author Alexander Wirthmueller
  * \date created: 18 Dec 2018
  * \date modified: 18 Dec 2018
  */

#ifndef MSDCAMPERSONDETAIL_H
#define MSDCAMPERSONDETAIL_H

#include <sbecore/LiteDbs.h>

/**
  * MsdcAMPersonDetail: record of TblMsdcAMPersonDetail
  */
class MsdcAMPersonDetail {

public:
	MsdcAMPersonDetail(const ubigint ref = 0, const ubigint refMsdcMPerson = 0, const string x1SrefKType = "", const string Val = "");

public:
	ubigint ref;
	ubigint refMsdcMPerson;
	string x1SrefKType;
	string Val;

public:
	bool operator==(const MsdcAMPersonDetail& comp);
	bool operator!=(const MsdcAMPersonDetail& comp);
};

/**
  * ListMsdcAMPersonDetail: recordset of TblMsdcAMPersonDetail
  */
class ListMsdcAMPersonDetail {

public:
	ListMsdcAMPersonDetail();
	ListMsdcAMPersonDetail(const ListMsdcAMPersonDetail& src);
	~ListMsdcAMPersonDetail();

	void clear();
	unsigned int size() const;
	void append(MsdcAMPersonDetail* rec);

	MsdcAMPersonDetail* operator[](const uint ix);
	ListMsdcAMPersonDetail& operator=(const ListMsdcAMPersonDetail& src);
	bool operator==(const ListMsdcAMPersonDetail& comp);
	bool operator!=(const ListMsdcAMPersonDetail& comp);

public:
	vector<MsdcAMPersonDetail*> nodes;
};

/**
  * TblMsdcAMPersonDetail: C++ wrapper for table TblMsdcAMPersonDetail
  */
class TblMsdcAMPersonDetail {

public:

public:
	TblMsdcAMPersonDetail();
	virtual ~TblMsdcAMPersonDetail();

public:
	virtual bool loadRecBySQL(const string& sqlstr, MsdcAMPersonDetail** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListMsdcAMPersonDetail& rst);

	virtual void insertRec(MsdcAMPersonDetail* rec);
	ubigint insertNewRec(MsdcAMPersonDetail** rec = NULL, const ubigint refMsdcMPerson = 0, const string x1SrefKType = "", const string Val = "");
	ubigint appendNewRecToRst(ListMsdcAMPersonDetail& rst, MsdcAMPersonDetail** rec = NULL, const ubigint refMsdcMPerson = 0, const string x1SrefKType = "", const string Val = "");
	virtual void insertRst(ListMsdcAMPersonDetail& rst, bool transact = false);
	virtual void updateRec(MsdcAMPersonDetail* rec);
	virtual void updateRst(ListMsdcAMPersonDetail& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, MsdcAMPersonDetail** rec);
	virtual bool loadRecByPrsTyp(ubigint refMsdcMPerson, string x1SrefKType, MsdcAMPersonDetail** rec);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListMsdcAMPersonDetail& rst);
};

/**
  * LiteTblMsdcAMPersonDetail: C++ wrapper for table TblMsdcAMPersonDetail (SQLite database)
  */
class LiteTblMsdcAMPersonDetail : public TblMsdcAMPersonDetail, public LiteTable {

public:
	LiteTblMsdcAMPersonDetail();
	~LiteTblMsdcAMPersonDetail();

public:
	void initStatements();

public:
	sqlite3_stmt* stmtInsertRec;
	sqlite3_stmt* stmtUpdateRec;
	sqlite3_stmt* stmtRemoveRecByRef;

	sqlite3_stmt* stmtLoadRecByRef;
	sqlite3_stmt* stmtLoadRecByPrsTyp;

private:
	bool loadRec(sqlite3_stmt* stmt, MsdcAMPersonDetail** rec);
	ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListMsdcAMPersonDetail& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, MsdcAMPersonDetail** rec);

public:
	bool loadRecBySQL(const string& sqlstr, MsdcAMPersonDetail** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListMsdcAMPersonDetail& rst);

	void insertRec(MsdcAMPersonDetail* rec);
	void insertRst(ListMsdcAMPersonDetail& rst, bool transact = false);
	void updateRec(MsdcAMPersonDetail* rec);
	void updateRst(ListMsdcAMPersonDetail& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, MsdcAMPersonDetail** rec);
	bool loadRecByPrsTyp(ubigint refMsdcMPerson, string x1SrefKType, MsdcAMPersonDetail** rec);
};

#endif

