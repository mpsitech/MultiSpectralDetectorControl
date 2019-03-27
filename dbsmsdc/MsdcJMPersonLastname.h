/**
  * \file MsdcJMPersonLastname.h
  * database access for table TblMsdcJMPersonLastname (declarations)
  * \author Alexander Wirthmueller
  * \date created: 18 Dec 2018
  * \date modified: 18 Dec 2018
  */

#ifndef MSDCJMPERSONLASTNAME_H
#define MSDCJMPERSONLASTNAME_H

#include <sbecore/LiteDbs.h>

/**
  * MsdcJMPersonLastname: record of TblMsdcJMPersonLastname
  */
class MsdcJMPersonLastname {

public:
	MsdcJMPersonLastname(const ubigint ref = 0, const ubigint refMsdcMPerson = 0, const uint x1Startd = 0, const string Lastname = "");

public:
	ubigint ref;
	ubigint refMsdcMPerson;
	uint x1Startd;
	string Lastname;

public:
	bool operator==(const MsdcJMPersonLastname& comp);
	bool operator!=(const MsdcJMPersonLastname& comp);
};

/**
  * ListMsdcJMPersonLastname: recordset of TblMsdcJMPersonLastname
  */
class ListMsdcJMPersonLastname {

public:
	ListMsdcJMPersonLastname();
	ListMsdcJMPersonLastname(const ListMsdcJMPersonLastname& src);
	~ListMsdcJMPersonLastname();

	void clear();
	unsigned int size() const;
	void append(MsdcJMPersonLastname* rec);

	MsdcJMPersonLastname* operator[](const uint ix);
	ListMsdcJMPersonLastname& operator=(const ListMsdcJMPersonLastname& src);
	bool operator==(const ListMsdcJMPersonLastname& comp);
	bool operator!=(const ListMsdcJMPersonLastname& comp);

public:
	vector<MsdcJMPersonLastname*> nodes;
};

/**
  * TblMsdcJMPersonLastname: C++ wrapper for table TblMsdcJMPersonLastname
  */
class TblMsdcJMPersonLastname {

public:

public:
	TblMsdcJMPersonLastname();
	virtual ~TblMsdcJMPersonLastname();

public:
	virtual bool loadRecBySQL(const string& sqlstr, MsdcJMPersonLastname** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListMsdcJMPersonLastname& rst);

	virtual void insertRec(MsdcJMPersonLastname* rec);
	ubigint insertNewRec(MsdcJMPersonLastname** rec = NULL, const ubigint refMsdcMPerson = 0, const uint x1Startd = 0, const string Lastname = "");
	ubigint appendNewRecToRst(ListMsdcJMPersonLastname& rst, MsdcJMPersonLastname** rec = NULL, const ubigint refMsdcMPerson = 0, const uint x1Startd = 0, const string Lastname = "");
	virtual void insertRst(ListMsdcJMPersonLastname& rst, bool transact = false);
	virtual void updateRec(MsdcJMPersonLastname* rec);
	virtual void updateRst(ListMsdcJMPersonLastname& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, MsdcJMPersonLastname** rec);
	virtual bool loadRecByPrsSta(ubigint refMsdcMPerson, uint x1Startd, MsdcJMPersonLastname** rec);
	virtual ubigint loadRefsByPrs(ubigint refMsdcMPerson, const bool append, vector<ubigint>& refs);
	virtual ubigint loadRstByPrs(ubigint refMsdcMPerson, const bool append, ListMsdcJMPersonLastname& rst);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListMsdcJMPersonLastname& rst);
};

/**
  * LiteTblMsdcJMPersonLastname: C++ wrapper for table TblMsdcJMPersonLastname (SQLite database)
  */
class LiteTblMsdcJMPersonLastname : public TblMsdcJMPersonLastname, public LiteTable {

public:
	LiteTblMsdcJMPersonLastname();
	~LiteTblMsdcJMPersonLastname();

public:
	void initStatements();

public:
	sqlite3_stmt* stmtInsertRec;
	sqlite3_stmt* stmtUpdateRec;
	sqlite3_stmt* stmtRemoveRecByRef;

	sqlite3_stmt* stmtLoadRecByRef;
	sqlite3_stmt* stmtLoadRecByPrsSta;
	sqlite3_stmt* stmtLoadRefsByPrs;
	sqlite3_stmt* stmtLoadRstByPrs;

private:
	bool loadRec(sqlite3_stmt* stmt, MsdcJMPersonLastname** rec);
	ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListMsdcJMPersonLastname& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, MsdcJMPersonLastname** rec);
	ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListMsdcJMPersonLastname& rst);

public:
	bool loadRecBySQL(const string& sqlstr, MsdcJMPersonLastname** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListMsdcJMPersonLastname& rst);

	void insertRec(MsdcJMPersonLastname* rec);
	void insertRst(ListMsdcJMPersonLastname& rst, bool transact = false);
	void updateRec(MsdcJMPersonLastname* rec);
	void updateRst(ListMsdcJMPersonLastname& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, MsdcJMPersonLastname** rec);
	bool loadRecByPrsSta(ubigint refMsdcMPerson, uint x1Startd, MsdcJMPersonLastname** rec);
	ubigint loadRefsByPrs(ubigint refMsdcMPerson, const bool append, vector<ubigint>& refs);
	ubigint loadRstByPrs(ubigint refMsdcMPerson, const bool append, ListMsdcJMPersonLastname& rst);
};

#endif

