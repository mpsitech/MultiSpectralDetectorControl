/**
  * \file MsdcQPrdList.h
  * Dbs and XML wrapper for table TblMsdcQPrdList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Oct 2018
  * \date modified: 4 Oct 2018
  */

#ifndef MSDCQPRDLIST_H
#define MSDCQPRDLIST_H

#include <sbecore/LiteDbs.h>

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * MsdcQPrdList: record of TblMsdcQPrdList
  */
class MsdcQPrdList {

public:
	MsdcQPrdList(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const uint start = 0, const string ftmStart = "", const uint stop = 0, const string ftmStop = "");

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	uint start;
	string ftmStart;
	uint stop;
	string ftmStop;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListMsdcQPrdList: recordset of TblMsdcQPrdList
  */
class ListMsdcQPrdList {

public:
	ListMsdcQPrdList();
	ListMsdcQPrdList(const ListMsdcQPrdList& src);
	~ListMsdcQPrdList();

	void clear();
	unsigned int size() const;
	void append(MsdcQPrdList* rec);

	ListMsdcQPrdList& operator=(const ListMsdcQPrdList& src);

public:
	vector<MsdcQPrdList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblMsdcQPrdList: C++ wrapper for table TblMsdcQPrdList
  */
class TblMsdcQPrdList {

public:
	TblMsdcQPrdList();
	virtual ~TblMsdcQPrdList();

public:
	virtual bool loadRecBySQL(const string& sqlstr, MsdcQPrdList** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListMsdcQPrdList& rst);

	virtual void insertRec(MsdcQPrdList* rec);
	ubigint insertNewRec(MsdcQPrdList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const uint start = 0, const string ftmStart = "", const uint stop = 0, const string ftmStop = "");
	ubigint appendNewRecToRst(ListMsdcQPrdList& rst, MsdcQPrdList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const uint start = 0, const string ftmStart = "", const uint stop = 0, const string ftmStop = "");
	virtual void insertRst(ListMsdcQPrdList& rst);
	virtual void updateRec(MsdcQPrdList* rec);
	virtual void updateRst(ListMsdcQPrdList& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, MsdcQPrdList** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListMsdcQPrdList& rst);
};

/**
  * LiteMsdcQPrdList: C++ wrapper for table TblMsdcQPrdList (SQLite database)
  */
class LiteTblMsdcQPrdList : public TblMsdcQPrdList, public LiteTable {

public:
	LiteTblMsdcQPrdList();
	~LiteTblMsdcQPrdList();

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
	bool loadRec(sqlite3_stmt* stmt, MsdcQPrdList** rec);
	ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListMsdcQPrdList& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, MsdcQPrdList** rec);
	ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListMsdcQPrdList& rst);

public:
	bool loadRecBySQL(const string& sqlstr, MsdcQPrdList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListMsdcQPrdList& rst);

	void insertRec(MsdcQPrdList* rec);
	void insertRst(ListMsdcQPrdList& rst);
	void updateRec(MsdcQPrdList* rec);
	void updateRst(ListMsdcQPrdList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, MsdcQPrdList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListMsdcQPrdList& rst);
};
#endif

