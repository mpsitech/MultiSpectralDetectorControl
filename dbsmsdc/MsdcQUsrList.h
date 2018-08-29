/**
  * \file MsdcQUsrList.h
  * Dbs and XML wrapper for table TblMsdcQUsrList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 29 Aug 2018
  * \date modified: 29 Aug 2018
  */

#ifndef MSDCQUSRLIST_H
#define MSDCQUSRLIST_H

#include <sbecore/LiteDbs.h>

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * MsdcQUsrList: record of TblMsdcQUsrList
  */
class MsdcQUsrList {

public:
	MsdcQUsrList(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const ubigint refMsdcMPerson = 0, const string stubRefMsdcMPerson = "", const string sref = "", const ubigint refMsdcMUsergroup = 0, const string stubRefMsdcMUsergroup = "", const uint ixVState = 0, const string srefIxVState = "", const string titIxVState = "", const uint ixMsdcVLocale = 0, const string srefIxMsdcVLocale = "", const string titIxMsdcVLocale = "", const uint ixMsdcVUserlevel = 0, const string srefIxMsdcVUserlevel = "", const string titIxMsdcVUserlevel = "");

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	ubigint refMsdcMPerson;
	string stubRefMsdcMPerson;
	string sref;
	ubigint refMsdcMUsergroup;
	string stubRefMsdcMUsergroup;
	uint ixVState;
	string srefIxVState;
	string titIxVState;
	uint ixMsdcVLocale;
	string srefIxMsdcVLocale;
	string titIxMsdcVLocale;
	uint ixMsdcVUserlevel;
	string srefIxMsdcVUserlevel;
	string titIxMsdcVUserlevel;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListMsdcQUsrList: recordset of TblMsdcQUsrList
  */
class ListMsdcQUsrList {

public:
	ListMsdcQUsrList();
	ListMsdcQUsrList(const ListMsdcQUsrList& src);
	~ListMsdcQUsrList();

	void clear();
	unsigned int size() const;
	void append(MsdcQUsrList* rec);

	ListMsdcQUsrList& operator=(const ListMsdcQUsrList& src);

public:
	vector<MsdcQUsrList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblMsdcQUsrList: C++ wrapper for table TblMsdcQUsrList
  */
class TblMsdcQUsrList {

public:
	TblMsdcQUsrList();
	virtual ~TblMsdcQUsrList();

public:
	virtual bool loadRecBySQL(const string& sqlstr, MsdcQUsrList** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListMsdcQUsrList& rst);

	virtual void insertRec(MsdcQUsrList* rec);
	ubigint insertNewRec(MsdcQUsrList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const ubigint refMsdcMPerson = 0, const string stubRefMsdcMPerson = "", const string sref = "", const ubigint refMsdcMUsergroup = 0, const string stubRefMsdcMUsergroup = "", const uint ixVState = 0, const string srefIxVState = "", const string titIxVState = "", const uint ixMsdcVLocale = 0, const string srefIxMsdcVLocale = "", const string titIxMsdcVLocale = "", const uint ixMsdcVUserlevel = 0, const string srefIxMsdcVUserlevel = "", const string titIxMsdcVUserlevel = "");
	ubigint appendNewRecToRst(ListMsdcQUsrList& rst, MsdcQUsrList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const ubigint refMsdcMPerson = 0, const string stubRefMsdcMPerson = "", const string sref = "", const ubigint refMsdcMUsergroup = 0, const string stubRefMsdcMUsergroup = "", const uint ixVState = 0, const string srefIxVState = "", const string titIxVState = "", const uint ixMsdcVLocale = 0, const string srefIxMsdcVLocale = "", const string titIxMsdcVLocale = "", const uint ixMsdcVUserlevel = 0, const string srefIxMsdcVUserlevel = "", const string titIxMsdcVUserlevel = "");
	virtual void insertRst(ListMsdcQUsrList& rst);
	virtual void updateRec(MsdcQUsrList* rec);
	virtual void updateRst(ListMsdcQUsrList& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, MsdcQUsrList** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListMsdcQUsrList& rst);
};

/**
  * LiteMsdcQUsrList: C++ wrapper for table TblMsdcQUsrList (SQLite database)
  */
class LiteTblMsdcQUsrList : public TblMsdcQUsrList, public LiteTable {

public:
	LiteTblMsdcQUsrList();
	~LiteTblMsdcQUsrList();

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
	bool loadRec(sqlite3_stmt* stmt, MsdcQUsrList** rec);
	ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListMsdcQUsrList& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, MsdcQUsrList** rec);
	ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListMsdcQUsrList& rst);

public:
	bool loadRecBySQL(const string& sqlstr, MsdcQUsrList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListMsdcQUsrList& rst);

	void insertRec(MsdcQUsrList* rec);
	void insertRst(ListMsdcQUsrList& rst);
	void updateRec(MsdcQUsrList* rec);
	void updateRst(ListMsdcQUsrList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, MsdcQUsrList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListMsdcQUsrList& rst);
};
#endif

