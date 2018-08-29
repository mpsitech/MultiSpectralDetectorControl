/**
  * \file MsdcQDatList.h
  * Dbs and XML wrapper for table TblMsdcQDatList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 29 Aug 2018
  * \date modified: 29 Aug 2018
  */

#ifndef MSDCQDATLIST_H
#define MSDCQDATLIST_H

#include <sbecore/LiteDbs.h>

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * MsdcQDatList: record of TblMsdcQDatList
  */
class MsdcQDatList {

public:
	MsdcQDatList(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string srefMsdcKAcqfeat = "", const string titSrefMsdcKAcqfeat = "", const ubigint refMsdcMPeriod = 0, const string stubRefMsdcMPeriod = "", const uint start = 0, const string ftmStart = "", const uint stop = 0, const string ftmStop = "");

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	string srefMsdcKAcqfeat;
	string titSrefMsdcKAcqfeat;
	ubigint refMsdcMPeriod;
	string stubRefMsdcMPeriod;
	uint start;
	string ftmStart;
	uint stop;
	string ftmStop;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListMsdcQDatList: recordset of TblMsdcQDatList
  */
class ListMsdcQDatList {

public:
	ListMsdcQDatList();
	ListMsdcQDatList(const ListMsdcQDatList& src);
	~ListMsdcQDatList();

	void clear();
	unsigned int size() const;
	void append(MsdcQDatList* rec);

	ListMsdcQDatList& operator=(const ListMsdcQDatList& src);

public:
	vector<MsdcQDatList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblMsdcQDatList: C++ wrapper for table TblMsdcQDatList
  */
class TblMsdcQDatList {

public:
	TblMsdcQDatList();
	virtual ~TblMsdcQDatList();

public:
	virtual bool loadRecBySQL(const string& sqlstr, MsdcQDatList** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListMsdcQDatList& rst);

	virtual void insertRec(MsdcQDatList* rec);
	ubigint insertNewRec(MsdcQDatList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string srefMsdcKAcqfeat = "", const string titSrefMsdcKAcqfeat = "", const ubigint refMsdcMPeriod = 0, const string stubRefMsdcMPeriod = "", const uint start = 0, const string ftmStart = "", const uint stop = 0, const string ftmStop = "");
	ubigint appendNewRecToRst(ListMsdcQDatList& rst, MsdcQDatList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string srefMsdcKAcqfeat = "", const string titSrefMsdcKAcqfeat = "", const ubigint refMsdcMPeriod = 0, const string stubRefMsdcMPeriod = "", const uint start = 0, const string ftmStart = "", const uint stop = 0, const string ftmStop = "");
	virtual void insertRst(ListMsdcQDatList& rst);
	virtual void updateRec(MsdcQDatList* rec);
	virtual void updateRst(ListMsdcQDatList& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, MsdcQDatList** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListMsdcQDatList& rst);
};

/**
  * LiteMsdcQDatList: C++ wrapper for table TblMsdcQDatList (SQLite database)
  */
class LiteTblMsdcQDatList : public TblMsdcQDatList, public LiteTable {

public:
	LiteTblMsdcQDatList();
	~LiteTblMsdcQDatList();

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
	bool loadRec(sqlite3_stmt* stmt, MsdcQDatList** rec);
	ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListMsdcQDatList& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, MsdcQDatList** rec);
	ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListMsdcQDatList& rst);

public:
	bool loadRecBySQL(const string& sqlstr, MsdcQDatList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListMsdcQDatList& rst);

	void insertRec(MsdcQDatList* rec);
	void insertRst(ListMsdcQDatList& rst);
	void updateRec(MsdcQDatList* rec);
	void updateRst(ListMsdcQDatList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, MsdcQDatList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListMsdcQDatList& rst);
};
#endif

