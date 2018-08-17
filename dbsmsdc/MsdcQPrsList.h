/**
  * \file MsdcQPrsList.h
  * Dbs and XML wrapper for table TblMsdcQPrsList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 15 Aug 2018
  * \date modified: 15 Aug 2018
  */

#ifndef MSDCQPRSLIST_H
#define MSDCQPRSLIST_H

#include <sbecore/LiteDbs.h>

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * MsdcQPrsList: record of TblMsdcQPrsList
  */
class MsdcQPrsList {

public:
	MsdcQPrsList(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string Title = "", const string Firstname = "", const string Lastname = "", const ubigint grp = 0, const string stubGrp = "", const ubigint own = 0, const string stubOwn = "", const uint ixVSex = 0, const string srefIxVSex = "", const string titIxVSex = "", const string telVal = "", const string emlVal = "");

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	string Title;
	string Firstname;
	string Lastname;
	ubigint grp;
	string stubGrp;
	ubigint own;
	string stubOwn;
	uint ixVSex;
	string srefIxVSex;
	string titIxVSex;
	string telVal;
	string emlVal;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListMsdcQPrsList: recordset of TblMsdcQPrsList
  */
class ListMsdcQPrsList {

public:
	ListMsdcQPrsList();
	ListMsdcQPrsList(const ListMsdcQPrsList& src);
	~ListMsdcQPrsList();

	void clear();
	unsigned int size() const;
	void append(MsdcQPrsList* rec);

	ListMsdcQPrsList& operator=(const ListMsdcQPrsList& src);

public:
	vector<MsdcQPrsList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblMsdcQPrsList: C++ wrapper for table TblMsdcQPrsList
  */
class TblMsdcQPrsList {

public:
	TblMsdcQPrsList();
	virtual ~TblMsdcQPrsList();

public:
	virtual bool loadRecBySQL(const string& sqlstr, MsdcQPrsList** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListMsdcQPrsList& rst);

	virtual void insertRec(MsdcQPrsList* rec);
	ubigint insertNewRec(MsdcQPrsList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string Title = "", const string Firstname = "", const string Lastname = "", const ubigint grp = 0, const string stubGrp = "", const ubigint own = 0, const string stubOwn = "", const uint ixVSex = 0, const string srefIxVSex = "", const string titIxVSex = "", const string telVal = "", const string emlVal = "");
	ubigint appendNewRecToRst(ListMsdcQPrsList& rst, MsdcQPrsList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string Title = "", const string Firstname = "", const string Lastname = "", const ubigint grp = 0, const string stubGrp = "", const ubigint own = 0, const string stubOwn = "", const uint ixVSex = 0, const string srefIxVSex = "", const string titIxVSex = "", const string telVal = "", const string emlVal = "");
	virtual void insertRst(ListMsdcQPrsList& rst);
	virtual void updateRec(MsdcQPrsList* rec);
	virtual void updateRst(ListMsdcQPrsList& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, MsdcQPrsList** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListMsdcQPrsList& rst);
};

/**
  * LiteMsdcQPrsList: C++ wrapper for table TblMsdcQPrsList (SQLite database)
  */
class LiteTblMsdcQPrsList : public TblMsdcQPrsList, public LiteTable {

public:
	LiteTblMsdcQPrsList();
	~LiteTblMsdcQPrsList();

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
	bool loadRec(sqlite3_stmt* stmt, MsdcQPrsList** rec);
	ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListMsdcQPrsList& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, MsdcQPrsList** rec);
	ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListMsdcQPrsList& rst);

public:
	bool loadRecBySQL(const string& sqlstr, MsdcQPrsList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListMsdcQPrsList& rst);

	void insertRec(MsdcQPrsList* rec);
	void insertRst(ListMsdcQPrsList& rst);
	void updateRec(MsdcQPrsList* rec);
	void updateRst(ListMsdcQPrsList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, MsdcQPrsList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListMsdcQPrsList& rst);
};
#endif

