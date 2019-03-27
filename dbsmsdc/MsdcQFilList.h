/**
  * \file MsdcQFilList.h
  * Dbs and XML wrapper for table TblMsdcQFilList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 18 Dec 2018
  * \date modified: 18 Dec 2018
  */

#ifndef MSDCQFILLIST_H
#define MSDCQFILLIST_H

#include <sbecore/LiteDbs.h>

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * MsdcQFilList: record of TblMsdcQFilList
  */
class MsdcQFilList {

public:
	MsdcQFilList(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string Filename = "", const uint refIxVTbl = 0, const string srefRefIxVTbl = "", const string titRefIxVTbl = "", const ubigint refUref = 0, const string stubRefUref = "", const string osrefKContent = "", const string titOsrefKContent = "", const string srefKMimetype = "", const string titSrefKMimetype = "", const usmallint Size = 0);

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	string Filename;
	uint refIxVTbl;
	string srefRefIxVTbl;
	string titRefIxVTbl;
	ubigint refUref;
	string stubRefUref;
	string osrefKContent;
	string titOsrefKContent;
	string srefKMimetype;
	string titSrefKMimetype;
	usmallint Size;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListMsdcQFilList: recordset of TblMsdcQFilList
  */
class ListMsdcQFilList {

public:
	ListMsdcQFilList();
	ListMsdcQFilList(const ListMsdcQFilList& src);
	~ListMsdcQFilList();

	void clear();
	unsigned int size() const;
	void append(MsdcQFilList* rec);

	ListMsdcQFilList& operator=(const ListMsdcQFilList& src);

public:
	vector<MsdcQFilList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblMsdcQFilList: C++ wrapper for table TblMsdcQFilList
  */
class TblMsdcQFilList {

public:
	TblMsdcQFilList();
	virtual ~TblMsdcQFilList();

public:
	virtual bool loadRecBySQL(const string& sqlstr, MsdcQFilList** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListMsdcQFilList& rst);

	virtual void insertRec(MsdcQFilList* rec);
	ubigint insertNewRec(MsdcQFilList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string Filename = "", const uint refIxVTbl = 0, const string srefRefIxVTbl = "", const string titRefIxVTbl = "", const ubigint refUref = 0, const string stubRefUref = "", const string osrefKContent = "", const string titOsrefKContent = "", const string srefKMimetype = "", const string titSrefKMimetype = "", const usmallint Size = 0);
	ubigint appendNewRecToRst(ListMsdcQFilList& rst, MsdcQFilList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string Filename = "", const uint refIxVTbl = 0, const string srefRefIxVTbl = "", const string titRefIxVTbl = "", const ubigint refUref = 0, const string stubRefUref = "", const string osrefKContent = "", const string titOsrefKContent = "", const string srefKMimetype = "", const string titSrefKMimetype = "", const usmallint Size = 0);
	virtual void insertRst(ListMsdcQFilList& rst);
	virtual void updateRec(MsdcQFilList* rec);
	virtual void updateRst(ListMsdcQFilList& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, MsdcQFilList** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListMsdcQFilList& rst);
};

/**
  * LiteMsdcQFilList: C++ wrapper for table TblMsdcQFilList (SQLite database)
  */
class LiteTblMsdcQFilList : public TblMsdcQFilList, public LiteTable {

public:
	LiteTblMsdcQFilList();
	~LiteTblMsdcQFilList();

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
	bool loadRec(sqlite3_stmt* stmt, MsdcQFilList** rec);
	ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListMsdcQFilList& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, MsdcQFilList** rec);
	ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListMsdcQFilList& rst);

public:
	bool loadRecBySQL(const string& sqlstr, MsdcQFilList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListMsdcQFilList& rst);

	void insertRec(MsdcQFilList* rec);
	void insertRst(ListMsdcQFilList& rst);
	void updateRec(MsdcQFilList* rec);
	void updateRst(ListMsdcQFilList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, MsdcQFilList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListMsdcQFilList& rst);
};
#endif

