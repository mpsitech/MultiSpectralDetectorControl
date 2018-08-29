/**
  * \file MsdcQUsrMNUsergroup.h
  * Dbs and XML wrapper for table TblMsdcQUsrMNUsergroup (declarations)
  * \author Alexander Wirthmueller
  * \date created: 29 Aug 2018
  * \date modified: 29 Aug 2018
  */

#ifndef MSDCQUSRMNUSERGROUP_H
#define MSDCQUSRMNUSERGROUP_H

#include <sbecore/LiteDbs.h>

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * MsdcQUsrMNUsergroup: record of TblMsdcQUsrMNUsergroup
  */
class MsdcQUsrMNUsergroup {

public:
	MsdcQUsrMNUsergroup(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const uint ixMsdcVUserlevel = 0, const string srefIxMsdcVUserlevel = "", const string titIxMsdcVUserlevel = "");

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
  * ListMsdcQUsrMNUsergroup: recordset of TblMsdcQUsrMNUsergroup
  */
class ListMsdcQUsrMNUsergroup {

public:
	ListMsdcQUsrMNUsergroup();
	ListMsdcQUsrMNUsergroup(const ListMsdcQUsrMNUsergroup& src);
	~ListMsdcQUsrMNUsergroup();

	void clear();
	unsigned int size() const;
	void append(MsdcQUsrMNUsergroup* rec);

	ListMsdcQUsrMNUsergroup& operator=(const ListMsdcQUsrMNUsergroup& src);

public:
	vector<MsdcQUsrMNUsergroup*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblMsdcQUsrMNUsergroup: C++ wrapper for table TblMsdcQUsrMNUsergroup
  */
class TblMsdcQUsrMNUsergroup {

public:
	TblMsdcQUsrMNUsergroup();
	virtual ~TblMsdcQUsrMNUsergroup();

public:
	virtual bool loadRecBySQL(const string& sqlstr, MsdcQUsrMNUsergroup** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListMsdcQUsrMNUsergroup& rst);

	virtual void insertRec(MsdcQUsrMNUsergroup* rec);
	ubigint insertNewRec(MsdcQUsrMNUsergroup** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const uint ixMsdcVUserlevel = 0, const string srefIxMsdcVUserlevel = "", const string titIxMsdcVUserlevel = "");
	ubigint appendNewRecToRst(ListMsdcQUsrMNUsergroup& rst, MsdcQUsrMNUsergroup** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const uint ixMsdcVUserlevel = 0, const string srefIxMsdcVUserlevel = "", const string titIxMsdcVUserlevel = "");
	virtual void insertRst(ListMsdcQUsrMNUsergroup& rst);
	virtual void updateRec(MsdcQUsrMNUsergroup* rec);
	virtual void updateRst(ListMsdcQUsrMNUsergroup& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, MsdcQUsrMNUsergroup** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListMsdcQUsrMNUsergroup& rst);
};

/**
  * LiteMsdcQUsrMNUsergroup: C++ wrapper for table TblMsdcQUsrMNUsergroup (SQLite database)
  */
class LiteTblMsdcQUsrMNUsergroup : public TblMsdcQUsrMNUsergroup, public LiteTable {

public:
	LiteTblMsdcQUsrMNUsergroup();
	~LiteTblMsdcQUsrMNUsergroup();

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
	bool loadRec(sqlite3_stmt* stmt, MsdcQUsrMNUsergroup** rec);
	ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListMsdcQUsrMNUsergroup& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, MsdcQUsrMNUsergroup** rec);
	ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListMsdcQUsrMNUsergroup& rst);

public:
	bool loadRecBySQL(const string& sqlstr, MsdcQUsrMNUsergroup** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListMsdcQUsrMNUsergroup& rst);

	void insertRec(MsdcQUsrMNUsergroup* rec);
	void insertRst(ListMsdcQUsrMNUsergroup& rst);
	void updateRec(MsdcQUsrMNUsergroup* rec);
	void updateRst(ListMsdcQUsrMNUsergroup& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, MsdcQUsrMNUsergroup** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListMsdcQUsrMNUsergroup& rst);
};
#endif

