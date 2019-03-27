/**
  * \file MsdcQDatRef1NFile.h
  * Dbs and XML wrapper for table TblMsdcQDatRef1NFile (declarations)
  * \author Alexander Wirthmueller
  * \date created: 18 Dec 2018
  * \date modified: 18 Dec 2018
  */

#ifndef MSDCQDATREF1NFILE_H
#define MSDCQDATREF1NFILE_H

#include <sbecore/LiteDbs.h>

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * MsdcQDatRef1NFile: record of TblMsdcQDatRef1NFile
  */
class MsdcQDatRef1NFile {

public:
	MsdcQDatRef1NFile(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");

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
  * ListMsdcQDatRef1NFile: recordset of TblMsdcQDatRef1NFile
  */
class ListMsdcQDatRef1NFile {

public:
	ListMsdcQDatRef1NFile();
	ListMsdcQDatRef1NFile(const ListMsdcQDatRef1NFile& src);
	~ListMsdcQDatRef1NFile();

	void clear();
	unsigned int size() const;
	void append(MsdcQDatRef1NFile* rec);

	ListMsdcQDatRef1NFile& operator=(const ListMsdcQDatRef1NFile& src);

public:
	vector<MsdcQDatRef1NFile*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblMsdcQDatRef1NFile: C++ wrapper for table TblMsdcQDatRef1NFile
  */
class TblMsdcQDatRef1NFile {

public:
	TblMsdcQDatRef1NFile();
	virtual ~TblMsdcQDatRef1NFile();

public:
	virtual bool loadRecBySQL(const string& sqlstr, MsdcQDatRef1NFile** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListMsdcQDatRef1NFile& rst);

	virtual void insertRec(MsdcQDatRef1NFile* rec);
	ubigint insertNewRec(MsdcQDatRef1NFile** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	ubigint appendNewRecToRst(ListMsdcQDatRef1NFile& rst, MsdcQDatRef1NFile** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	virtual void insertRst(ListMsdcQDatRef1NFile& rst);
	virtual void updateRec(MsdcQDatRef1NFile* rec);
	virtual void updateRst(ListMsdcQDatRef1NFile& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, MsdcQDatRef1NFile** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListMsdcQDatRef1NFile& rst);
};

/**
  * LiteMsdcQDatRef1NFile: C++ wrapper for table TblMsdcQDatRef1NFile (SQLite database)
  */
class LiteTblMsdcQDatRef1NFile : public TblMsdcQDatRef1NFile, public LiteTable {

public:
	LiteTblMsdcQDatRef1NFile();
	~LiteTblMsdcQDatRef1NFile();

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
	bool loadRec(sqlite3_stmt* stmt, MsdcQDatRef1NFile** rec);
	ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListMsdcQDatRef1NFile& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, MsdcQDatRef1NFile** rec);
	ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListMsdcQDatRef1NFile& rst);

public:
	bool loadRecBySQL(const string& sqlstr, MsdcQDatRef1NFile** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListMsdcQDatRef1NFile& rst);

	void insertRec(MsdcQDatRef1NFile* rec);
	void insertRst(ListMsdcQDatRef1NFile& rst);
	void updateRec(MsdcQDatRef1NFile* rec);
	void updateRst(ListMsdcQDatRef1NFile& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, MsdcQDatRef1NFile** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListMsdcQDatRef1NFile& rst);
};
#endif

