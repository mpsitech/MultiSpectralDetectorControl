/**
  * \file MsdcQUsgMNUser.h
  * Dbs and XML wrapper for table TblMsdcQUsgMNUser (declarations)
  * \author Alexander Wirthmueller
  * \date created: 15 Aug 2018
  * \date modified: 15 Aug 2018
  */

#ifndef MSDCQUSGMNUSER_H
#define MSDCQUSGMNUSER_H

#include <sbecore/LiteDbs.h>

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * MsdcQUsgMNUser: record of TblMsdcQUsgMNUser
  */
class MsdcQUsgMNUser {

public:
	MsdcQUsgMNUser(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const uint ixMsdcVUserlevel = 0, const string srefIxMsdcVUserlevel = "", const string titIxMsdcVUserlevel = "");

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint mref;
	string stubMref;
	ubigint ref;
	uint ixMsdcVUserlevel;
	string srefIxMsdcVUserlevel;
	string titIxMsdcVUserlevel;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListMsdcQUsgMNUser: recordset of TblMsdcQUsgMNUser
  */
class ListMsdcQUsgMNUser {

public:
	ListMsdcQUsgMNUser();
	ListMsdcQUsgMNUser(const ListMsdcQUsgMNUser& src);
	~ListMsdcQUsgMNUser();

	void clear();
	unsigned int size() const;
	void append(MsdcQUsgMNUser* rec);

	ListMsdcQUsgMNUser& operator=(const ListMsdcQUsgMNUser& src);

public:
	vector<MsdcQUsgMNUser*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblMsdcQUsgMNUser: C++ wrapper for table TblMsdcQUsgMNUser
  */
class TblMsdcQUsgMNUser {

public:
	TblMsdcQUsgMNUser();
	virtual ~TblMsdcQUsgMNUser();

public:
	virtual bool loadRecBySQL(const string& sqlstr, MsdcQUsgMNUser** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListMsdcQUsgMNUser& rst);

	virtual void insertRec(MsdcQUsgMNUser* rec);
	ubigint insertNewRec(MsdcQUsgMNUser** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const uint ixMsdcVUserlevel = 0, const string srefIxMsdcVUserlevel = "", const string titIxMsdcVUserlevel = "");
	ubigint appendNewRecToRst(ListMsdcQUsgMNUser& rst, MsdcQUsgMNUser** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const uint ixMsdcVUserlevel = 0, const string srefIxMsdcVUserlevel = "", const string titIxMsdcVUserlevel = "");
	virtual void insertRst(ListMsdcQUsgMNUser& rst);
	virtual void updateRec(MsdcQUsgMNUser* rec);
	virtual void updateRst(ListMsdcQUsgMNUser& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, MsdcQUsgMNUser** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListMsdcQUsgMNUser& rst);
};

/**
  * LiteMsdcQUsgMNUser: C++ wrapper for table TblMsdcQUsgMNUser (SQLite database)
  */
class LiteTblMsdcQUsgMNUser : public TblMsdcQUsgMNUser, public LiteTable {

public:
	LiteTblMsdcQUsgMNUser();
	~LiteTblMsdcQUsgMNUser();

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
	bool loadRec(sqlite3_stmt* stmt, MsdcQUsgMNUser** rec);
	ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListMsdcQUsgMNUser& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, MsdcQUsgMNUser** rec);
	ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListMsdcQUsgMNUser& rst);

public:
	bool loadRecBySQL(const string& sqlstr, MsdcQUsgMNUser** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListMsdcQUsgMNUser& rst);

	void insertRec(MsdcQUsgMNUser* rec);
	void insertRst(ListMsdcQUsgMNUser& rst);
	void updateRec(MsdcQUsgMNUser* rec);
	void updateRst(ListMsdcQUsgMNUser& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, MsdcQUsgMNUser** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListMsdcQUsgMNUser& rst);
};
#endif

