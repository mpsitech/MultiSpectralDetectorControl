/**
  * \file MsdcCFile.h
  * Dbs and XML wrapper for table TblMsdcCFile (declarations)
  * \author Alexander Wirthmueller
  * \date created: 29 Aug 2018
  * \date modified: 29 Aug 2018
  */

#ifndef MSDCCFILE_H
#define MSDCCFILE_H

#include <sbecore/LiteDbs.h>

/**
  * TblMsdcCFile: C++ wrapper for table TblMsdcCFile
  */
class TblMsdcCFile {

public:
	TblMsdcCFile();
	virtual ~TblMsdcCFile();

public:
	virtual ubigint getNewRef();
};

/**
  * LiteTblMsdcCFile: C++ wrapper for table TblMsdcCFile (SQLite database)
  */
class LiteTblMsdcCFile : public TblMsdcCFile, public LiteTable {

public:
	LiteTblMsdcCFile();
	~LiteTblMsdcCFile();

public:
	void initStatements();

public:
	sqlite3_stmt* stmtGetNewRef;

public:
	ubigint getNewRef();
};
#endif

