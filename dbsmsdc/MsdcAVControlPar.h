/**
  * \file MsdcAVControlPar.h
  * database access for table TblMsdcAVControlPar (declarations)
  * \author Alexander Wirthmueller
  * \date created: 15 Aug 2018
  * \date modified: 15 Aug 2018
  */

#ifndef MSDCAVCONTROLPAR_H
#define MSDCAVCONTROLPAR_H

#include <sbecore/LiteDbs.h>

/**
  * MsdcAVControlPar: record of TblMsdcAVControlPar
  */
class MsdcAVControlPar {

public:
	MsdcAVControlPar(const ubigint ref = 0, const uint ixMsdcVControl = 0, const ubigint x1RefMsdcMUser = 0, const uint x2IxMsdcVLocale = 0, const string Par = "", const string Val = "");

public:
	ubigint ref;
	uint ixMsdcVControl;
	ubigint x1RefMsdcMUser;
	uint x2IxMsdcVLocale;
	string Par;
	string Val;

public:
	bool operator==(const MsdcAVControlPar& comp);
	bool operator!=(const MsdcAVControlPar& comp);
};

/**
  * ListMsdcAVControlPar: recordset of TblMsdcAVControlPar
  */
class ListMsdcAVControlPar {

public:
	ListMsdcAVControlPar();
	ListMsdcAVControlPar(const ListMsdcAVControlPar& src);
	~ListMsdcAVControlPar();

	void clear();
	unsigned int size() const;
	void append(MsdcAVControlPar* rec);

	MsdcAVControlPar* operator[](const uint ix);
	ListMsdcAVControlPar& operator=(const ListMsdcAVControlPar& src);
	bool operator==(const ListMsdcAVControlPar& comp);
	bool operator!=(const ListMsdcAVControlPar& comp);

public:
	vector<MsdcAVControlPar*> nodes;
};

/**
  * TblMsdcAVControlPar: C++ wrapper for table TblMsdcAVControlPar
  */
class TblMsdcAVControlPar {

public:

public:
	TblMsdcAVControlPar();
	virtual ~TblMsdcAVControlPar();

public:
	virtual bool loadRecBySQL(const string& sqlstr, MsdcAVControlPar** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListMsdcAVControlPar& rst);

	virtual void insertRec(MsdcAVControlPar* rec);
	ubigint insertNewRec(MsdcAVControlPar** rec = NULL, const uint ixMsdcVControl = 0, const ubigint x1RefMsdcMUser = 0, const uint x2IxMsdcVLocale = 0, const string Par = "", const string Val = "");
	ubigint appendNewRecToRst(ListMsdcAVControlPar& rst, MsdcAVControlPar** rec = NULL, const uint ixMsdcVControl = 0, const ubigint x1RefMsdcMUser = 0, const uint x2IxMsdcVLocale = 0, const string Par = "", const string Val = "");
	virtual void insertRst(ListMsdcAVControlPar& rst, bool transact = false);
	virtual void updateRec(MsdcAVControlPar* rec);
	virtual void updateRst(ListMsdcAVControlPar& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, MsdcAVControlPar** rec);
	virtual bool loadRefByCtlUsrPar(uint ixMsdcVControl, ubigint x1RefMsdcMUser, string Par, ubigint& ref);
	virtual bool loadValByCtlUsrPar(uint ixMsdcVControl, ubigint x1RefMsdcMUser, string Par, string& Val);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListMsdcAVControlPar& rst);
};

/**
  * LiteTblMsdcAVControlPar: C++ wrapper for table TblMsdcAVControlPar (SQLite database)
  */
class LiteTblMsdcAVControlPar : public TblMsdcAVControlPar, public LiteTable {

public:
	LiteTblMsdcAVControlPar();
	~LiteTblMsdcAVControlPar();

public:
	void initStatements();

public:
	sqlite3_stmt* stmtInsertRec;
	sqlite3_stmt* stmtUpdateRec;
	sqlite3_stmt* stmtRemoveRecByRef;

	sqlite3_stmt* stmtLoadRecByRef;
	sqlite3_stmt* stmtLoadRefByCtlUsrPar;
	sqlite3_stmt* stmtLoadValByCtlUsrPar;

private:
	bool loadRec(sqlite3_stmt* stmt, MsdcAVControlPar** rec);
	ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListMsdcAVControlPar& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, MsdcAVControlPar** rec);

public:
	bool loadRecBySQL(const string& sqlstr, MsdcAVControlPar** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListMsdcAVControlPar& rst);

	void insertRec(MsdcAVControlPar* rec);
	void insertRst(ListMsdcAVControlPar& rst, bool transact = false);
	void updateRec(MsdcAVControlPar* rec);
	void updateRst(ListMsdcAVControlPar& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, MsdcAVControlPar** rec);
	bool loadRefByCtlUsrPar(uint ixMsdcVControl, ubigint x1RefMsdcMUser, string Par, ubigint& ref);
	bool loadValByCtlUsrPar(uint ixMsdcVControl, ubigint x1RefMsdcMUser, string Par, string& Val);
};

#endif

