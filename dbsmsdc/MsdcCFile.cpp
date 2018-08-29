/**
  * \file MsdcCFile.cpp
  * Dbs and XML wrapper for table TblMsdcCFile (implementation)
  * \author Alexander Wirthmueller
  * \date created: 29 Aug 2018
  * \date modified: 29 Aug 2018
  */

#include "MsdcCFile.h"

/******************************************************************************
 class TblMsdcCFile
 ******************************************************************************/

TblMsdcCFile::TblMsdcCFile() {
};

TblMsdcCFile::~TblMsdcCFile() {
};

ubigint TblMsdcCFile::getNewRef() {
	return 0;
};

/******************************************************************************
 class LiteTblMsdcCFile
 ******************************************************************************/

LiteTblMsdcCFile::LiteTblMsdcCFile() :
			TblMsdcCFile()
			, LiteTable()
		{
	stmtGetNewRef = NULL;
};

LiteTblMsdcCFile::~LiteTblMsdcCFile() {
	if (stmtGetNewRef) sqlite3_finalize(stmtGetNewRef);
};

void LiteTblMsdcCFile::initStatements() {
	stmtGetNewRef = createStatement("INSERT INTO TblMsdcCFile (void) VALUES (0)");
};

ubigint LiteTblMsdcCFile::getNewRef() {
	if (sqlite3_step(stmtGetNewRef) != SQLITE_DONE) throw DbsException("DbsException / SQLite: error executing statement! (TblMsdcCFile / stmtGetNewRef)\n");
	return sqlite3_last_insert_rowid(dbs);
};

