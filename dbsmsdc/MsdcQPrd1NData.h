/**
  * \file MsdcQPrd1NData.h
  * Dbs and XML wrapper for table TblMsdcQPrd1NData (declarations)
  * \author Alexander Wirthmueller
  * \date created: 15 Aug 2018
  * \date modified: 15 Aug 2018
  */

#ifndef MSDCQPRD1NDATA_H
#define MSDCQPRD1NDATA_H

#include <sbecore/LiteDbs.h>

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * MsdcQPrd1NData: record of TblMsdcQPrd1NData
  */
class MsdcQPrd1NData {

public:
	MsdcQPrd1NData(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	string stubRef;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListMsdcQPrd1NData: recordset of TblMsdcQPrd1NData
  */
class ListMsdcQPrd1NData {

public:
	ListMsdcQPrd1NData();
	ListMsdcQPrd1NData(const ListMsdcQPrd1NData& src);
	~ListMsdcQPrd1NData();

	void clear();
	unsigned int size() const;
	void append(MsdcQPrd1NData* rec);

	ListMsdcQPrd1NData& operator=(const ListMsdcQPrd1NData& src);

public:
	vector<MsdcQPrd1NData*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblMsdcQPrd1NData: C++ wrapper for table TblMsdcQPrd1NData
  */
class TblMsdcQPrd1NData {

public:
	TblMsdcQPrd1NData();
	virtual ~TblMsdcQPrd1NData();

public:
	virtual bool loadRecBySQL(const string& sqlstr, MsdcQPrd1NData** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListMsdcQPrd1NData& rst);

	virtual void insertRec(MsdcQPrd1NData* rec);
	ubigint insertNewRec(MsdcQPrd1NData** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	ubigint appendNewRecToRst(ListMsdcQPrd1NData& rst, MsdcQPrd1NData** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	virtual void insertRst(ListMsdcQPrd1NData& rst);
	virtual void updateRec(MsdcQPrd1NData* rec);
	virtual void updateRst(ListMsdcQPrd1NData& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, MsdcQPrd1NData** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListMsdcQPrd1NData& rst);
};

/**
  * LiteMsdcQPrd1NData: C++ wrapper for table TblMsdcQPrd1NData (SQLite database)
  */
class LiteTblMsdcQPrd1NData : public TblMsdcQPrd1NData, public LiteTable {

public:
	LiteTblMsdcQPrd1NData();
	~LiteTblMsdcQPrd1NData();

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
	bool loadRec(sqlite3_stmt* stmt, MsdcQPrd1NData** rec);
	ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListMsdcQPrd1NData& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, MsdcQPrd1NData** rec);
	ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListMsdcQPrd1NData& rst);

public:
	bool loadRecBySQL(const string& sqlstr, MsdcQPrd1NData** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListMsdcQPrd1NData& rst);

	void insertRec(MsdcQPrd1NData* rec);
	void insertRst(ListMsdcQPrd1NData& rst);
	void updateRec(MsdcQPrd1NData* rec);
	void updateRst(ListMsdcQPrd1NData& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, MsdcQPrd1NData** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListMsdcQPrd1NData& rst);
};
#endif

