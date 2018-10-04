/**
  * \file MsdcMUsergroup.h
  * database access for table TblMsdcMUsergroup (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Oct 2018
  * \date modified: 4 Oct 2018
  */

#ifndef MSDCMUSERGROUP_H
#define MSDCMUSERGROUP_H

#include <sbecore/LiteDbs.h>

/**
  * MsdcMUsergroup: record of TblMsdcMUsergroup
  */
class MsdcMUsergroup {

public:
	MsdcMUsergroup(const ubigint ref = 0, const ubigint grp = 0, const ubigint own = 0, const string sref = "", const string Comment = "");

public:
	ubigint ref;
	ubigint grp;
	ubigint own;
	string sref;
	string Comment;

public:
	bool operator==(const MsdcMUsergroup& comp);
	bool operator!=(const MsdcMUsergroup& comp);
};

/**
  * ListMsdcMUsergroup: recordset of TblMsdcMUsergroup
  */
class ListMsdcMUsergroup {

public:
	ListMsdcMUsergroup();
	ListMsdcMUsergroup(const ListMsdcMUsergroup& src);
	~ListMsdcMUsergroup();

	void clear();
	unsigned int size() const;
	void append(MsdcMUsergroup* rec);

	MsdcMUsergroup* operator[](const uint ix);
	ListMsdcMUsergroup& operator=(const ListMsdcMUsergroup& src);
	bool operator==(const ListMsdcMUsergroup& comp);
	bool operator!=(const ListMsdcMUsergroup& comp);

public:
	vector<MsdcMUsergroup*> nodes;
};

/**
  * TblMsdcMUsergroup: C++ wrapper for table TblMsdcMUsergroup
  */
class TblMsdcMUsergroup {

public:

public:
	TblMsdcMUsergroup();
	virtual ~TblMsdcMUsergroup();

public:
	virtual bool loadRecBySQL(const string& sqlstr, MsdcMUsergroup** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListMsdcMUsergroup& rst);

	virtual void insertRec(MsdcMUsergroup* rec);
	ubigint insertNewRec(MsdcMUsergroup** rec = NULL, const ubigint grp = 0, const ubigint own = 0, const string sref = "", const string Comment = "");
	ubigint appendNewRecToRst(ListMsdcMUsergroup& rst, MsdcMUsergroup** rec = NULL, const ubigint grp = 0, const ubigint own = 0, const string sref = "", const string Comment = "");
	virtual void insertRst(ListMsdcMUsergroup& rst, bool transact = false);
	virtual void updateRec(MsdcMUsergroup* rec);
	virtual void updateRst(ListMsdcMUsergroup& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, MsdcMUsergroup** rec);
	virtual bool loadRecBySrf(string sref, MsdcMUsergroup** rec);
	virtual bool loadRefBySrf(string sref, ubigint& ref);
	virtual bool loadSrfByRef(ubigint ref, string& sref);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListMsdcMUsergroup& rst);
};

/**
  * LiteTblMsdcMUsergroup: C++ wrapper for table TblMsdcMUsergroup (SQLite database)
  */
class LiteTblMsdcMUsergroup : public TblMsdcMUsergroup, public LiteTable {

public:
	LiteTblMsdcMUsergroup();
	~LiteTblMsdcMUsergroup();

public:
	void initStatements();

public:
	sqlite3_stmt* stmtInsertRec;
	sqlite3_stmt* stmtUpdateRec;
	sqlite3_stmt* stmtRemoveRecByRef;

	sqlite3_stmt* stmtLoadRecByRef;
	sqlite3_stmt* stmtLoadRecBySrf;
	sqlite3_stmt* stmtLoadRefBySrf;
	sqlite3_stmt* stmtLoadSrfByRef;

private:
	bool loadRec(sqlite3_stmt* stmt, MsdcMUsergroup** rec);
	ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListMsdcMUsergroup& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, MsdcMUsergroup** rec);

public:
	bool loadRecBySQL(const string& sqlstr, MsdcMUsergroup** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListMsdcMUsergroup& rst);

	void insertRec(MsdcMUsergroup* rec);
	void insertRst(ListMsdcMUsergroup& rst, bool transact = false);
	void updateRec(MsdcMUsergroup* rec);
	void updateRst(ListMsdcMUsergroup& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, MsdcMUsergroup** rec);
	bool loadRecBySrf(string sref, MsdcMUsergroup** rec);
	bool loadRefBySrf(string sref, ubigint& ref);
	bool loadSrfByRef(ubigint ref, string& sref);
};

#endif

