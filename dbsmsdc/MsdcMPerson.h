/**
  * \file MsdcMPerson.h
  * database access for table TblMsdcMPerson (declarations)
  * \author Alexander Wirthmueller
  * \date created: 15 Aug 2018
  * \date modified: 15 Aug 2018
  */

#ifndef MSDCMPERSON_H
#define MSDCMPERSON_H

#include <sbecore/LiteDbs.h>

#include <sbecore/Xmlio.h>

using namespace Xmlio;

#define VecMsdcVMPersonSex TblMsdcMPerson::VecVSex
#define VecMsdcWMPersonDerivate TblMsdcMPerson::VecWDerivate

/**
  * MsdcMPerson: record of TblMsdcMPerson
  */
class MsdcMPerson {

public:
	MsdcMPerson(const ubigint ref = 0, const ubigint grp = 0, const ubigint own = 0, const uint ixWDerivate = 0, const uint ixVSex = 0, const string Title = "", const string Firstname = "", const ubigint refJLastname = 0, const string Lastname = "", const ubigint telRefADetail = 0, const string telVal = "", const ubigint emlRefADetail = 0, const string emlVal = "", const string Salutation = "");

public:
	ubigint ref;
	ubigint grp;
	ubigint own;
	uint ixWDerivate;
	uint ixVSex;
	string Title;
	string Firstname;
	ubigint refJLastname;
	string Lastname;
	ubigint telRefADetail;
	string telVal;
	ubigint emlRefADetail;
	string emlVal;
	string Salutation;

public:
	bool operator==(const MsdcMPerson& comp);
	bool operator!=(const MsdcMPerson& comp);
};

/**
  * ListMsdcMPerson: recordset of TblMsdcMPerson
  */
class ListMsdcMPerson {

public:
	ListMsdcMPerson();
	ListMsdcMPerson(const ListMsdcMPerson& src);
	~ListMsdcMPerson();

	void clear();
	unsigned int size() const;
	void append(MsdcMPerson* rec);

	MsdcMPerson* operator[](const uint ix);
	ListMsdcMPerson& operator=(const ListMsdcMPerson& src);
	bool operator==(const ListMsdcMPerson& comp);
	bool operator!=(const ListMsdcMPerson& comp);

public:
	vector<MsdcMPerson*> nodes;
};

/**
  * TblMsdcMPerson: C++ wrapper for table TblMsdcMPerson
  */
class TblMsdcMPerson {

public:
	/**
		* VecVSex (full: VecMsdcVMPersonSex)
		*/
	class VecVSex {

	public:
		static const uint F = 1;
		static const uint M = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);

		static string getTitle(const uint ix, const uint ixMsdcVLocale);

		static void fillFeed(const uint ixMsdcVLocale, Feed& feed);
	};

	/**
		* VecWDerivate (full: VecMsdcWMPersonDerivate)
		*/
	class VecWDerivate {

	public:
		static const uint USR = 1;

		static uint getIx(const string& srefs);
		static void getIcs(const uint ix, set<uint>& ics);
		static string getSrefs(const uint ix);

		static string getTitle(const uint ix, const uint ixMsdcVLocale);

		static void fillFeed(const uint ixMsdcVLocale, Feed& feed);
	};

public:
	TblMsdcMPerson();
	virtual ~TblMsdcMPerson();

public:
	virtual bool loadRecBySQL(const string& sqlstr, MsdcMPerson** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListMsdcMPerson& rst);

	virtual void insertRec(MsdcMPerson* rec);
	ubigint insertNewRec(MsdcMPerson** rec = NULL, const ubigint grp = 0, const ubigint own = 0, const uint ixWDerivate = 0, const uint ixVSex = 0, const string Title = "", const string Firstname = "", const ubigint refJLastname = 0, const string Lastname = "", const ubigint telRefADetail = 0, const string telVal = "", const ubigint emlRefADetail = 0, const string emlVal = "", const string Salutation = "");
	ubigint appendNewRecToRst(ListMsdcMPerson& rst, MsdcMPerson** rec = NULL, const ubigint grp = 0, const ubigint own = 0, const uint ixWDerivate = 0, const uint ixVSex = 0, const string Title = "", const string Firstname = "", const ubigint refJLastname = 0, const string Lastname = "", const ubigint telRefADetail = 0, const string telVal = "", const ubigint emlRefADetail = 0, const string emlVal = "", const string Salutation = "");
	virtual void insertRst(ListMsdcMPerson& rst, bool transact = false);
	virtual void updateRec(MsdcMPerson* rec);
	virtual void updateRst(ListMsdcMPerson& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, MsdcMPerson** rec);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListMsdcMPerson& rst);
};

/**
  * LiteTblMsdcMPerson: C++ wrapper for table TblMsdcMPerson (SQLite database)
  */
class LiteTblMsdcMPerson : public TblMsdcMPerson, public LiteTable {

public:
	LiteTblMsdcMPerson();
	~LiteTblMsdcMPerson();

public:
	void initStatements();

public:
	sqlite3_stmt* stmtInsertRec;
	sqlite3_stmt* stmtUpdateRec;
	sqlite3_stmt* stmtRemoveRecByRef;

	sqlite3_stmt* stmtLoadRecByRef;

private:
	bool loadRec(sqlite3_stmt* stmt, MsdcMPerson** rec);
	ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListMsdcMPerson& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, MsdcMPerson** rec);

public:
	bool loadRecBySQL(const string& sqlstr, MsdcMPerson** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListMsdcMPerson& rst);

	void insertRec(MsdcMPerson* rec);
	void insertRst(ListMsdcMPerson& rst, bool transact = false);
	void updateRec(MsdcMPerson* rec);
	void updateRst(ListMsdcMPerson& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, MsdcMPerson** rec);
};

#endif

