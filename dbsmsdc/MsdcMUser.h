/**
  * \file MsdcMUser.h
  * database access for table TblMsdcMUser (declarations)
  * \author Alexander Wirthmueller
  * \date created: 12 Sep 2018
  * \date modified: 12 Sep 2018
  */

#ifndef MSDCMUSER_H
#define MSDCMUSER_H

#include <sbecore/LiteDbs.h>

#include <sbecore/Xmlio.h>

using namespace Xmlio;

#define VecMsdcVMUserState TblMsdcMUser::VecVState

/**
  * MsdcMUser: record of TblMsdcMUser
  */
class MsdcMUser {

public:
	MsdcMUser(const ubigint ref = 0, const ubigint grp = 0, const ubigint own = 0, const ubigint refRUsergroup = 0, const ubigint refMsdcMUsergroup = 0, const ubigint refMsdcMPerson = 0, const string sref = "", const ubigint refJState = 0, const uint ixVState = 0, const uint ixMsdcVLocale = 0, const uint ixMsdcVUserlevel = 0, const string Password = "", const string Fullkey = "", const string Comment = "");

public:
	ubigint ref;
	ubigint grp;
	ubigint own;
	ubigint refRUsergroup;
	ubigint refMsdcMUsergroup;
	ubigint refMsdcMPerson;
	string sref;
	ubigint refJState;
	uint ixVState;
	uint ixMsdcVLocale;
	uint ixMsdcVUserlevel;
	string Password;
	string Fullkey;
	string Comment;

public:
	bool operator==(const MsdcMUser& comp);
	bool operator!=(const MsdcMUser& comp);
};

/**
  * ListMsdcMUser: recordset of TblMsdcMUser
  */
class ListMsdcMUser {

public:
	ListMsdcMUser();
	ListMsdcMUser(const ListMsdcMUser& src);
	~ListMsdcMUser();

	void clear();
	unsigned int size() const;
	void append(MsdcMUser* rec);

	MsdcMUser* operator[](const uint ix);
	ListMsdcMUser& operator=(const ListMsdcMUser& src);
	bool operator==(const ListMsdcMUser& comp);
	bool operator!=(const ListMsdcMUser& comp);

public:
	vector<MsdcMUser*> nodes;
};

/**
  * TblMsdcMUser: C++ wrapper for table TblMsdcMUser
  */
class TblMsdcMUser {

public:
	/**
		* VecVState (full: VecMsdcVMUserState)
		*/
	class VecVState {

	public:
		static const uint ACT = 1;
		static const uint DSG = 2;
		static const uint DUE = 3;
		static const uint EXP = 4;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);

		static string getTitle(const uint ix, const uint ixMsdcVLocale);

		static void fillFeed(const uint ixMsdcVLocale, Feed& feed);
	};

public:
	TblMsdcMUser();
	virtual ~TblMsdcMUser();

public:
	virtual bool loadRecBySQL(const string& sqlstr, MsdcMUser** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListMsdcMUser& rst);

	virtual void insertRec(MsdcMUser* rec);
	ubigint insertNewRec(MsdcMUser** rec = NULL, const ubigint grp = 0, const ubigint own = 0, const ubigint refRUsergroup = 0, const ubigint refMsdcMUsergroup = 0, const ubigint refMsdcMPerson = 0, const string sref = "", const ubigint refJState = 0, const uint ixVState = 0, const uint ixMsdcVLocale = 0, const uint ixMsdcVUserlevel = 0, const string Password = "", const string Fullkey = "", const string Comment = "");
	ubigint appendNewRecToRst(ListMsdcMUser& rst, MsdcMUser** rec = NULL, const ubigint grp = 0, const ubigint own = 0, const ubigint refRUsergroup = 0, const ubigint refMsdcMUsergroup = 0, const ubigint refMsdcMPerson = 0, const string sref = "", const ubigint refJState = 0, const uint ixVState = 0, const uint ixMsdcVLocale = 0, const uint ixMsdcVUserlevel = 0, const string Password = "", const string Fullkey = "", const string Comment = "");
	virtual void insertRst(ListMsdcMUser& rst, bool transact = false);
	virtual void updateRec(MsdcMUser* rec);
	virtual void updateRst(ListMsdcMUser& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, MsdcMUser** rec);
	virtual bool loadRecByPrs(ubigint refMsdcMPerson, MsdcMUser** rec);
	virtual bool loadRecBySrf(string sref, MsdcMUser** rec);
	virtual bool loadRefByPrs(ubigint refMsdcMPerson, ubigint& ref);
	virtual bool loadRefBySrf(string sref, ubigint& ref);
	virtual bool loadRefBySrfPwd(string sref, string Password, ubigint& ref);
	virtual ubigint loadRefsByUsg(ubigint refMsdcMUsergroup, const bool append, vector<ubigint>& refs);
	virtual bool loadSrfByRef(ubigint ref, string& sref);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListMsdcMUser& rst);
};

/**
  * LiteTblMsdcMUser: C++ wrapper for table TblMsdcMUser (SQLite database)
  */
class LiteTblMsdcMUser : public TblMsdcMUser, public LiteTable {

public:
	LiteTblMsdcMUser();
	~LiteTblMsdcMUser();

public:
	void initStatements();

public:
	sqlite3_stmt* stmtInsertRec;
	sqlite3_stmt* stmtUpdateRec;
	sqlite3_stmt* stmtRemoveRecByRef;

	sqlite3_stmt* stmtLoadRecByRef;
	sqlite3_stmt* stmtLoadRecByPrs;
	sqlite3_stmt* stmtLoadRecBySrf;
	sqlite3_stmt* stmtLoadRefByPrs;
	sqlite3_stmt* stmtLoadRefBySrf;
	sqlite3_stmt* stmtLoadRefBySrfPwd;
	sqlite3_stmt* stmtLoadRefsByUsg;
	sqlite3_stmt* stmtLoadSrfByRef;

private:
	bool loadRec(sqlite3_stmt* stmt, MsdcMUser** rec);
	ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListMsdcMUser& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, MsdcMUser** rec);

public:
	bool loadRecBySQL(const string& sqlstr, MsdcMUser** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListMsdcMUser& rst);

	void insertRec(MsdcMUser* rec);
	void insertRst(ListMsdcMUser& rst, bool transact = false);
	void updateRec(MsdcMUser* rec);
	void updateRst(ListMsdcMUser& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, MsdcMUser** rec);
	bool loadRecByPrs(ubigint refMsdcMPerson, MsdcMUser** rec);
	bool loadRecBySrf(string sref, MsdcMUser** rec);
	bool loadRefByPrs(ubigint refMsdcMPerson, ubigint& ref);
	bool loadRefBySrf(string sref, ubigint& ref);
	bool loadRefBySrfPwd(string sref, string Password, ubigint& ref);
	ubigint loadRefsByUsg(ubigint refMsdcMUsergroup, const bool append, vector<ubigint>& refs);
	bool loadSrfByRef(ubigint ref, string& sref);
};

#endif

