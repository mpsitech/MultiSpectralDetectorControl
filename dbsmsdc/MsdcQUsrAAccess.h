/**
  * \file MsdcQUsrAAccess.h
  * Dbs and XML wrapper for table TblMsdcQUsrAAccess (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Oct 2018
  * \date modified: 4 Oct 2018
  */

#ifndef MSDCQUSRAACCESS_H
#define MSDCQUSRAACCESS_H

#include <sbecore/LiteDbs.h>

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * MsdcQUsrAAccess: record of TblMsdcQUsrAAccess
  */
class MsdcQUsrAAccess {

public:
	MsdcQUsrAAccess(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const uint x1IxMsdcVFeatgroup = 0, const string srefX1IxMsdcVFeatgroup = "", const string titX1IxMsdcVFeatgroup = "", const string x2FeaSrefUix = "", const uint ixMsdcWAccess = 0, const string srefsIxMsdcWAccess = "", const string titsIxMsdcWAccess = "");

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
  * ListMsdcQUsrAAccess: recordset of TblMsdcQUsrAAccess
  */
class ListMsdcQUsrAAccess {

public:
	ListMsdcQUsrAAccess();
	ListMsdcQUsrAAccess(const ListMsdcQUsrAAccess& src);
	~ListMsdcQUsrAAccess();

	void clear();
	unsigned int size() const;
	void append(MsdcQUsrAAccess* rec);

	ListMsdcQUsrAAccess& operator=(const ListMsdcQUsrAAccess& src);

public:
	vector<MsdcQUsrAAccess*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblMsdcQUsrAAccess: C++ wrapper for table TblMsdcQUsrAAccess
  */
class TblMsdcQUsrAAccess {

public:
	TblMsdcQUsrAAccess();
	virtual ~TblMsdcQUsrAAccess();

public:
	virtual bool loadRecBySQL(const string& sqlstr, MsdcQUsrAAccess** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListMsdcQUsrAAccess& rst);

	virtual void insertRec(MsdcQUsrAAccess* rec);
	ubigint insertNewRec(MsdcQUsrAAccess** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const uint x1IxMsdcVFeatgroup = 0, const string srefX1IxMsdcVFeatgroup = "", const string titX1IxMsdcVFeatgroup = "", const string x2FeaSrefUix = "", const uint ixMsdcWAccess = 0, const string srefsIxMsdcWAccess = "", const string titsIxMsdcWAccess = "");
	ubigint appendNewRecToRst(ListMsdcQUsrAAccess& rst, MsdcQUsrAAccess** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const uint x1IxMsdcVFeatgroup = 0, const string srefX1IxMsdcVFeatgroup = "", const string titX1IxMsdcVFeatgroup = "", const string x2FeaSrefUix = "", const uint ixMsdcWAccess = 0, const string srefsIxMsdcWAccess = "", const string titsIxMsdcWAccess = "");
	virtual void insertRst(ListMsdcQUsrAAccess& rst);
	virtual void updateRec(MsdcQUsrAAccess* rec);
	virtual void updateRst(ListMsdcQUsrAAccess& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, MsdcQUsrAAccess** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListMsdcQUsrAAccess& rst);
};

/**
  * LiteMsdcQUsrAAccess: C++ wrapper for table TblMsdcQUsrAAccess (SQLite database)
  */
class LiteTblMsdcQUsrAAccess : public TblMsdcQUsrAAccess, public LiteTable {

public:
	LiteTblMsdcQUsrAAccess();
	~LiteTblMsdcQUsrAAccess();

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
	bool loadRec(sqlite3_stmt* stmt, MsdcQUsrAAccess** rec);
	ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListMsdcQUsrAAccess& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, MsdcQUsrAAccess** rec);
	ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListMsdcQUsrAAccess& rst);

public:
	bool loadRecBySQL(const string& sqlstr, MsdcQUsrAAccess** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListMsdcQUsrAAccess& rst);

	void insertRec(MsdcQUsrAAccess* rec);
	void insertRst(ListMsdcQUsrAAccess& rst);
	void updateRec(MsdcQUsrAAccess* rec);
	void updateRst(ListMsdcQUsrAAccess& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, MsdcQUsrAAccess** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListMsdcQUsrAAccess& rst);
};
#endif

