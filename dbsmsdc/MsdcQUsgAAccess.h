/**
  * \file MsdcQUsgAAccess.h
  * Dbs and XML wrapper for table TblMsdcQUsgAAccess (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Oct 2018
  * \date modified: 4 Oct 2018
  */

#ifndef MSDCQUSGAACCESS_H
#define MSDCQUSGAACCESS_H

#include <sbecore/LiteDbs.h>

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * MsdcQUsgAAccess: record of TblMsdcQUsgAAccess
  */
class MsdcQUsgAAccess {

public:
	MsdcQUsgAAccess(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const uint x1IxMsdcVFeatgroup = 0, const string srefX1IxMsdcVFeatgroup = "", const string titX1IxMsdcVFeatgroup = "", const string x2FeaSrefUix = "", const uint ixMsdcWAccess = 0, const string srefsIxMsdcWAccess = "", const string titsIxMsdcWAccess = "");

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	uint x1IxMsdcVFeatgroup;
	string srefX1IxMsdcVFeatgroup;
	string titX1IxMsdcVFeatgroup;
	string x2FeaSrefUix;
	uint ixMsdcWAccess;
	string srefsIxMsdcWAccess;
	string titsIxMsdcWAccess;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListMsdcQUsgAAccess: recordset of TblMsdcQUsgAAccess
  */
class ListMsdcQUsgAAccess {

public:
	ListMsdcQUsgAAccess();
	ListMsdcQUsgAAccess(const ListMsdcQUsgAAccess& src);
	~ListMsdcQUsgAAccess();

	void clear();
	unsigned int size() const;
	void append(MsdcQUsgAAccess* rec);

	ListMsdcQUsgAAccess& operator=(const ListMsdcQUsgAAccess& src);

public:
	vector<MsdcQUsgAAccess*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblMsdcQUsgAAccess: C++ wrapper for table TblMsdcQUsgAAccess
  */
class TblMsdcQUsgAAccess {

public:
	TblMsdcQUsgAAccess();
	virtual ~TblMsdcQUsgAAccess();

public:
	virtual bool loadRecBySQL(const string& sqlstr, MsdcQUsgAAccess** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListMsdcQUsgAAccess& rst);

	virtual void insertRec(MsdcQUsgAAccess* rec);
	ubigint insertNewRec(MsdcQUsgAAccess** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const uint x1IxMsdcVFeatgroup = 0, const string srefX1IxMsdcVFeatgroup = "", const string titX1IxMsdcVFeatgroup = "", const string x2FeaSrefUix = "", const uint ixMsdcWAccess = 0, const string srefsIxMsdcWAccess = "", const string titsIxMsdcWAccess = "");
	ubigint appendNewRecToRst(ListMsdcQUsgAAccess& rst, MsdcQUsgAAccess** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const uint x1IxMsdcVFeatgroup = 0, const string srefX1IxMsdcVFeatgroup = "", const string titX1IxMsdcVFeatgroup = "", const string x2FeaSrefUix = "", const uint ixMsdcWAccess = 0, const string srefsIxMsdcWAccess = "", const string titsIxMsdcWAccess = "");
	virtual void insertRst(ListMsdcQUsgAAccess& rst);
	virtual void updateRec(MsdcQUsgAAccess* rec);
	virtual void updateRst(ListMsdcQUsgAAccess& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, MsdcQUsgAAccess** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListMsdcQUsgAAccess& rst);
};

/**
  * LiteMsdcQUsgAAccess: C++ wrapper for table TblMsdcQUsgAAccess (SQLite database)
  */
class LiteTblMsdcQUsgAAccess : public TblMsdcQUsgAAccess, public LiteTable {

public:
	LiteTblMsdcQUsgAAccess();
	~LiteTblMsdcQUsgAAccess();

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
	bool loadRec(sqlite3_stmt* stmt, MsdcQUsgAAccess** rec);
	ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListMsdcQUsgAAccess& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, MsdcQUsgAAccess** rec);
	ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListMsdcQUsgAAccess& rst);

public:
	bool loadRecBySQL(const string& sqlstr, MsdcQUsgAAccess** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListMsdcQUsgAAccess& rst);

	void insertRec(MsdcQUsgAAccess* rec);
	void insertRst(ListMsdcQUsgAAccess& rst);
	void updateRec(MsdcQUsgAAccess* rec);
	void updateRst(ListMsdcQUsgAAccess& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, MsdcQUsgAAccess** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListMsdcQUsgAAccess& rst);
};
#endif

