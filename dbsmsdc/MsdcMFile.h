/**
  * \file MsdcMFile.h
  * database access for table TblMsdcMFile (declarations)
  * \author Alexander Wirthmueller
  * \date created: 15 Aug 2018
  * \date modified: 15 Aug 2018
  */

#ifndef MSDCMFILE_H
#define MSDCMFILE_H

#include <sbecore/LiteDbs.h>

#include <sbecore/Xmlio.h>

using namespace Xmlio;

#define VecMsdcVMFileRefTbl TblMsdcMFile::VecVRefTbl

/**
  * MsdcMFile: record of TblMsdcMFile
  */
class MsdcMFile {

public:
	MsdcMFile(const ubigint ref = 0, const ubigint grp = 0, const ubigint own = 0, const ubigint refMsdcCFile = 0, const uint refIxVTbl = 0, const ubigint refUref = 0, const string osrefKContent = "", const uint Archived = 0, const string Filename = "", const string Archivename = "", const string srefKMimetype = "", const usmallint Size = 0, const string Comment = "");

public:
	ubigint ref;
	ubigint grp;
	ubigint own;
	ubigint refMsdcCFile;
	uint refIxVTbl;
	ubigint refUref;
	string osrefKContent;
	uint Archived;
	string Filename;
	string Archivename;
	string srefKMimetype;
	usmallint Size;
	string Comment;

public:
	bool operator==(const MsdcMFile& comp);
	bool operator!=(const MsdcMFile& comp);
};

/**
  * ListMsdcMFile: recordset of TblMsdcMFile
  */
class ListMsdcMFile {

public:
	ListMsdcMFile();
	ListMsdcMFile(const ListMsdcMFile& src);
	~ListMsdcMFile();

	void clear();
	unsigned int size() const;
	void append(MsdcMFile* rec);

	MsdcMFile* operator[](const uint ix);
	ListMsdcMFile& operator=(const ListMsdcMFile& src);
	bool operator==(const ListMsdcMFile& comp);
	bool operator!=(const ListMsdcMFile& comp);

public:
	vector<MsdcMFile*> nodes;
};

/**
  * TblMsdcMFile: C++ wrapper for table TblMsdcMFile
  */
class TblMsdcMFile {

public:
	/**
		* VecVRefTbl (full: VecMsdcVMFileRefTbl)
		*/
	class VecVRefTbl {

	public:
		static const uint VOID = 1;
		static const uint DAT = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);

		static string getTitle(const uint ix, const uint ixMsdcVLocale);

		static void fillFeed(const uint ixMsdcVLocale, Feed& feed);
	};

public:
	TblMsdcMFile();
	virtual ~TblMsdcMFile();

public:
	virtual bool loadRecBySQL(const string& sqlstr, MsdcMFile** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListMsdcMFile& rst);

	virtual void insertRec(MsdcMFile* rec);
	ubigint insertNewRec(MsdcMFile** rec = NULL, const ubigint grp = 0, const ubigint own = 0, const ubigint refMsdcCFile = 0, const uint refIxVTbl = 0, const ubigint refUref = 0, const string osrefKContent = "", const uint Archived = 0, const string Filename = "", const string Archivename = "", const string srefKMimetype = "", const usmallint Size = 0, const string Comment = "");
	ubigint appendNewRecToRst(ListMsdcMFile& rst, MsdcMFile** rec = NULL, const ubigint grp = 0, const ubigint own = 0, const ubigint refMsdcCFile = 0, const uint refIxVTbl = 0, const ubigint refUref = 0, const string osrefKContent = "", const uint Archived = 0, const string Filename = "", const string Archivename = "", const string srefKMimetype = "", const usmallint Size = 0, const string Comment = "");
	virtual void insertRst(ListMsdcMFile& rst, bool transact = false);
	virtual void updateRec(MsdcMFile* rec);
	virtual void updateRst(ListMsdcMFile& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, MsdcMFile** rec);
	virtual bool loadFnmByRef(ubigint ref, string& Filename);
	virtual ubigint loadRefsByClu(ubigint refMsdcCFile, const bool append, vector<ubigint>& refs);
	virtual ubigint loadRstByClu(ubigint refMsdcCFile, const bool append, ListMsdcMFile& rst);
	virtual ubigint loadRstByRetReu(uint refIxVTbl, ubigint refUref, const bool append, ListMsdcMFile& rst);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListMsdcMFile& rst);
};

/**
  * LiteTblMsdcMFile: C++ wrapper for table TblMsdcMFile (SQLite database)
  */
class LiteTblMsdcMFile : public TblMsdcMFile, public LiteTable {

public:
	LiteTblMsdcMFile();
	~LiteTblMsdcMFile();

public:
	void initStatements();

public:
	sqlite3_stmt* stmtInsertRec;
	sqlite3_stmt* stmtUpdateRec;
	sqlite3_stmt* stmtRemoveRecByRef;

	sqlite3_stmt* stmtLoadRecByRef;
	sqlite3_stmt* stmtLoadFnmByRef;
	sqlite3_stmt* stmtLoadRefsByClu;
	sqlite3_stmt* stmtLoadRstByClu;
	sqlite3_stmt* stmtLoadRstByRetReu;

private:
	bool loadRec(sqlite3_stmt* stmt, MsdcMFile** rec);
	ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListMsdcMFile& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, MsdcMFile** rec);
	ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListMsdcMFile& rst);

public:
	bool loadRecBySQL(const string& sqlstr, MsdcMFile** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListMsdcMFile& rst);

	void insertRec(MsdcMFile* rec);
	void insertRst(ListMsdcMFile& rst, bool transact = false);
	void updateRec(MsdcMFile* rec);
	void updateRst(ListMsdcMFile& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, MsdcMFile** rec);
	bool loadFnmByRef(ubigint ref, string& Filename);
	ubigint loadRefsByClu(ubigint refMsdcCFile, const bool append, vector<ubigint>& refs);
	ubigint loadRstByClu(ubigint refMsdcCFile, const bool append, ListMsdcMFile& rst);
	ubigint loadRstByRetReu(uint refIxVTbl, ubigint refUref, const bool append, ListMsdcMFile& rst);
};

#endif

