DROP TABLE IF EXISTS TblMsdcAccRMUserUniversal;
DROP TABLE IF EXISTS TblMsdcAMDataPar;
DROP TABLE IF EXISTS TblMsdcAMPersonDetail;
DROP TABLE IF EXISTS TblMsdcAMUserAccess;
DROP TABLE IF EXISTS TblMsdcAMUsergroupAccess;
DROP TABLE IF EXISTS TblMsdcAVControlPar;
DROP TABLE IF EXISTS TblMsdcAVKeylistKey;
DROP TABLE IF EXISTS TblMsdcAVValuelistVal;
DROP TABLE IF EXISTS TblMsdcCFile;
DROP TABLE IF EXISTS TblMsdcHistRMUserUniversal;
DROP TABLE IF EXISTS TblMsdcJAVKeylistKey;
DROP TABLE IF EXISTS TblMsdcJMPersonLastname;
DROP TABLE IF EXISTS TblMsdcJMUserState;
DROP TABLE IF EXISTS TblMsdcMData;
DROP TABLE IF EXISTS TblMsdcMFile;
DROP TABLE IF EXISTS TblMsdcMPeriod;
DROP TABLE IF EXISTS TblMsdcMPerson;
DROP TABLE IF EXISTS TblMsdcMSession;
DROP TABLE IF EXISTS TblMsdcMUser;
DROP TABLE IF EXISTS TblMsdcMUsergroup;
DROP TABLE IF EXISTS TblMsdcRMUsergroupUniversal;
DROP TABLE IF EXISTS TblMsdcRMUserMUsergroup;

DROP TABLE IF EXISTS TblMsdcQDatAPar;
DROP TABLE IF EXISTS TblMsdcQDatList;
DROP TABLE IF EXISTS TblMsdcQDatRef1NFile;
DROP TABLE IF EXISTS TblMsdcQFilList;
DROP TABLE IF EXISTS TblMsdcQPrd1NData;
DROP TABLE IF EXISTS TblMsdcQPrdList;
DROP TABLE IF EXISTS TblMsdcQPreselect;
DROP TABLE IF EXISTS TblMsdcQPrsList;
DROP TABLE IF EXISTS TblMsdcQSelect;
DROP TABLE IF EXISTS TblMsdcQUsgAAccess;
DROP TABLE IF EXISTS TblMsdcQUsgList;
DROP TABLE IF EXISTS TblMsdcQUsgMNUser;
DROP TABLE IF EXISTS TblMsdcQUsr1NSession;
DROP TABLE IF EXISTS TblMsdcQUsrAAccess;
DROP TABLE IF EXISTS TblMsdcQUsrList;
DROP TABLE IF EXISTS TblMsdcQUsrMNUsergroup;

CREATE TABLE TblMsdcAccRMUserUniversal(
	ref INTEGER PRIMARY KEY AUTOINCREMENT,
	refMsdcMUser BIGINT,
	unvIxMsdcVMaintable INT,
	unvUref BIGINT,
	ixMsdcVRecaccess INT
);
CREATE INDEX TblMsdcAccRMUserUniversal_refMsdcMUser ON TblMsdcAccRMUserUniversal (refMsdcMUser);
CREATE INDEX TblMsdcAccRMUserUniversal_unvIxMsdcVMaintable ON TblMsdcAccRMUserUniversal (unvIxMsdcVMaintable);
CREATE INDEX TblMsdcAccRMUserUniversal_unvUref ON TblMsdcAccRMUserUniversal (unvUref);

CREATE TABLE TblMsdcAMDataPar(
	ref INTEGER PRIMARY KEY AUTOINCREMENT,
	refMsdcMData BIGINT,
	x1Start DOUBLE PRECISION,
	x2SrefKKey VARCHAR(50),
	refMsdcMFile BIGINT,
	Val TEXT,
	Bindata TEXT
);
CREATE INDEX TblMsdcAMDataPar_refMsdcMData ON TblMsdcAMDataPar (refMsdcMData);
CREATE INDEX TblMsdcAMDataPar_x1Start ON TblMsdcAMDataPar (x1Start);
CREATE INDEX TblMsdcAMDataPar_x2SrefKKey ON TblMsdcAMDataPar (x2SrefKKey);

CREATE TABLE TblMsdcAMPersonDetail(
	ref INTEGER PRIMARY KEY AUTOINCREMENT,
	refMsdcMPerson BIGINT,
	x1SrefKType VARCHAR(50),
	Val VARCHAR(256)
);
CREATE INDEX TblMsdcAMPersonDetail_refMsdcMPerson ON TblMsdcAMPersonDetail (refMsdcMPerson);

CREATE TABLE TblMsdcAMUserAccess(
	ref INTEGER PRIMARY KEY AUTOINCREMENT,
	refMsdcMUser BIGINT,
	x1IxMsdcVFeatgroup INT,
	x2FeaSrefUix VARCHAR(50),
	ixMsdcWAccess INT
);
CREATE INDEX TblMsdcAMUserAccess_refMsdcMUser ON TblMsdcAMUserAccess (refMsdcMUser);
CREATE INDEX TblMsdcAMUserAccess_x1IxMsdcVFeatgroup ON TblMsdcAMUserAccess (x1IxMsdcVFeatgroup);
CREATE INDEX TblMsdcAMUserAccess_x2FeaSrefUix ON TblMsdcAMUserAccess (x2FeaSrefUix);

CREATE TABLE TblMsdcAMUsergroupAccess(
	ref INTEGER PRIMARY KEY AUTOINCREMENT,
	refMsdcMUsergroup BIGINT,
	x1IxMsdcVFeatgroup INT,
	x2FeaSrefUix VARCHAR(50),
	ixMsdcWAccess INT
);
CREATE INDEX TblMsdcAMUsergroupAccess_refMsdcMUsergroup ON TblMsdcAMUsergroupAccess (refMsdcMUsergroup);
CREATE INDEX TblMsdcAMUsergroupAccess_x1IxMsdcVFeatgroup ON TblMsdcAMUsergroupAccess (x1IxMsdcVFeatgroup);
CREATE INDEX TblMsdcAMUsergroupAccess_x2FeaSrefUix ON TblMsdcAMUsergroupAccess (x2FeaSrefUix);

CREATE TABLE TblMsdcAVControlPar(
	ref INTEGER PRIMARY KEY AUTOINCREMENT,
	ixMsdcVControl INT,
	x1RefMsdcMUser BIGINT,
	x2IxMsdcVLocale INT,
	Par VARCHAR(256),
	Val VARCHAR(256)
);
CREATE INDEX TblMsdcAVControlPar_ixMsdcVControl ON TblMsdcAVControlPar (ixMsdcVControl);
CREATE INDEX TblMsdcAVControlPar_x1RefMsdcMUser ON TblMsdcAVControlPar (x1RefMsdcMUser);
CREATE INDEX TblMsdcAVControlPar_x2IxMsdcVLocale ON TblMsdcAVControlPar (x2IxMsdcVLocale);
CREATE INDEX TblMsdcAVControlPar_Par ON TblMsdcAVControlPar (Par);

CREATE TABLE TblMsdcAVKeylistKey(
	ref INTEGER PRIMARY KEY AUTOINCREMENT,
	klsIxMsdcVKeylist INT,
	klsNum INT,
	x1IxMsdcVMaintable INT,
	x1Uref BIGINT,
	Fixed SMALLINT,
	sref VARCHAR(50),
	Avail VARCHAR(1024),
	Implied VARCHAR(1024),
	refJ BIGINT,
	Title VARCHAR(256),
	Comment TEXT
);
CREATE INDEX TblMsdcAVKeylistKey_klsIxMsdcVKeylist ON TblMsdcAVKeylistKey (klsIxMsdcVKeylist);
CREATE INDEX TblMsdcAVKeylistKey_klsNum ON TblMsdcAVKeylistKey (klsNum);
CREATE INDEX TblMsdcAVKeylistKey_x1IxMsdcVMaintable ON TblMsdcAVKeylistKey (x1IxMsdcVMaintable);
CREATE INDEX TblMsdcAVKeylistKey_x1Uref ON TblMsdcAVKeylistKey (x1Uref);
CREATE INDEX TblMsdcAVKeylistKey_sref ON TblMsdcAVKeylistKey (sref);

CREATE TABLE TblMsdcAVValuelistVal(
	ref INTEGER PRIMARY KEY AUTOINCREMENT,
	vlsIxMsdcVValuelist INT,
	vlsNum INT,
	x1IxMsdcVLocale INT,
	Val VARCHAR(256)
);
CREATE INDEX TblMsdcAVValuelistVal_vlsIxMsdcVValuelist ON TblMsdcAVValuelistVal (vlsIxMsdcVValuelist);
CREATE INDEX TblMsdcAVValuelistVal_vlsNum ON TblMsdcAVValuelistVal (vlsNum);
CREATE INDEX TblMsdcAVValuelistVal_x1IxMsdcVLocale ON TblMsdcAVValuelistVal (x1IxMsdcVLocale);

CREATE TABLE TblMsdcCFile(
	ref INTEGER PRIMARY KEY AUTOINCREMENT,
	void SMALLINT

);

CREATE TABLE TblMsdcHistRMUserUniversal(
	ref INTEGER PRIMARY KEY AUTOINCREMENT,
	refMsdcMUser BIGINT,
	unvIxMsdcVMaintable INT,
	unvUref BIGINT,
	ixMsdcVCard INT,
	ixMsdcVPreset INT,
	preIxMsdcVMaintable INT,
	preUref BIGINT,
	start INT
);
CREATE INDEX TblMsdcHistRMUserUniversal_refMsdcMUser ON TblMsdcHistRMUserUniversal (refMsdcMUser);
CREATE INDEX TblMsdcHistRMUserUniversal_unvIxMsdcVMaintable ON TblMsdcHistRMUserUniversal (unvIxMsdcVMaintable);
CREATE INDEX TblMsdcHistRMUserUniversal_unvUref ON TblMsdcHistRMUserUniversal (unvUref);
CREATE INDEX TblMsdcHistRMUserUniversal_ixMsdcVCard ON TblMsdcHistRMUserUniversal (ixMsdcVCard);
CREATE INDEX TblMsdcHistRMUserUniversal_ixMsdcVPreset ON TblMsdcHistRMUserUniversal (ixMsdcVPreset);
CREATE INDEX TblMsdcHistRMUserUniversal_preIxMsdcVMaintable ON TblMsdcHistRMUserUniversal (preIxMsdcVMaintable);
CREATE INDEX TblMsdcHistRMUserUniversal_preUref ON TblMsdcHistRMUserUniversal (preUref);

CREATE TABLE TblMsdcJAVKeylistKey(
	ref INTEGER PRIMARY KEY AUTOINCREMENT,
	refMsdcAVKeylistKey BIGINT,
	x1IxMsdcVLocale INT,
	Title VARCHAR(256),
	Comment TEXT
);
CREATE INDEX TblMsdcJAVKeylistKey_refMsdcAVKeylistKey ON TblMsdcJAVKeylistKey (refMsdcAVKeylistKey);
CREATE INDEX TblMsdcJAVKeylistKey_x1IxMsdcVLocale ON TblMsdcJAVKeylistKey (x1IxMsdcVLocale);

CREATE TABLE TblMsdcJMPersonLastname(
	ref INTEGER PRIMARY KEY AUTOINCREMENT,
	refMsdcMPerson BIGINT,
	x1Startd INT,
	Lastname VARCHAR(50)
);
CREATE INDEX TblMsdcJMPersonLastname_refMsdcMPerson ON TblMsdcJMPersonLastname (refMsdcMPerson);
CREATE INDEX TblMsdcJMPersonLastname_x1Startd ON TblMsdcJMPersonLastname (x1Startd);
CREATE INDEX TblMsdcJMPersonLastname_Lastname ON TblMsdcJMPersonLastname (Lastname);

CREATE TABLE TblMsdcJMUserState(
	ref INTEGER PRIMARY KEY AUTOINCREMENT,
	refMsdcMUser BIGINT,
	x1Startd INT,
	ixVState INT
);
CREATE INDEX TblMsdcJMUserState_refMsdcMUser ON TblMsdcJMUserState (refMsdcMUser);
CREATE INDEX TblMsdcJMUserState_x1Startd ON TblMsdcJMUserState (x1Startd);

CREATE TABLE TblMsdcMData(
	ref INTEGER PRIMARY KEY AUTOINCREMENT,
	refMsdcMPeriod BIGINT,
	start INT,
	stop INT,
	srefMsdcKAcqfeat VARCHAR(50),
	Comment TEXT
);
CREATE INDEX TblMsdcMData_refMsdcMPeriod ON TblMsdcMData (refMsdcMPeriod);
CREATE INDEX TblMsdcMData_start ON TblMsdcMData (start);
CREATE INDEX TblMsdcMData_srefMsdcKAcqfeat ON TblMsdcMData (srefMsdcKAcqfeat);

CREATE TABLE TblMsdcMFile(
	ref INTEGER PRIMARY KEY AUTOINCREMENT,
	grp BIGINT,
	own BIGINT,
	refMsdcCFile BIGINT,
	refIxVTbl INT,
	refUref BIGINT,
	osrefKContent VARCHAR(50),
	Archived INT,
	Filename VARCHAR(50),
	Archivename VARCHAR(30),
	srefKMimetype VARCHAR(50),
	Size SMALLINT,
	Comment TEXT
);
CREATE INDEX TblMsdcMFile_grp ON TblMsdcMFile (grp);
CREATE INDEX TblMsdcMFile_own ON TblMsdcMFile (own);
CREATE INDEX TblMsdcMFile_refMsdcCFile ON TblMsdcMFile (refMsdcCFile);
CREATE INDEX TblMsdcMFile_refIxVTbl ON TblMsdcMFile (refIxVTbl);
CREATE INDEX TblMsdcMFile_refUref ON TblMsdcMFile (refUref);
CREATE INDEX TblMsdcMFile_Filename ON TblMsdcMFile (Filename);

CREATE TABLE TblMsdcMPeriod(
	ref INTEGER PRIMARY KEY AUTOINCREMENT,
	start INT,
	stop INT
);
CREATE INDEX TblMsdcMPeriod_start ON TblMsdcMPeriod (start);

CREATE TABLE TblMsdcMPerson(
	ref INTEGER PRIMARY KEY AUTOINCREMENT,
	grp BIGINT,
	own BIGINT,
	ixWDerivate INT,
	ixVSex INT,
	Title VARCHAR(30),
	Firstname VARCHAR(30),
	refJLastname BIGINT,
	Lastname VARCHAR(50),
	telRefADetail BIGINT,
	telVal VARCHAR(256),
	emlRefADetail BIGINT,
	emlVal VARCHAR(256),
	Salutation VARCHAR(100)
);
CREATE INDEX TblMsdcMPerson_grp ON TblMsdcMPerson (grp);
CREATE INDEX TblMsdcMPerson_own ON TblMsdcMPerson (own);
CREATE INDEX TblMsdcMPerson_ixWDerivate ON TblMsdcMPerson (ixWDerivate);
CREATE INDEX TblMsdcMPerson_Lastname ON TblMsdcMPerson (Lastname);

CREATE TABLE TblMsdcMSession(
	ref INTEGER PRIMARY KEY AUTOINCREMENT,
	refMsdcMUser BIGINT,
	start INT,
	stop INT,
	Ip VARCHAR(30)
);
CREATE INDEX TblMsdcMSession_refMsdcMUser ON TblMsdcMSession (refMsdcMUser);
CREATE INDEX TblMsdcMSession_start ON TblMsdcMSession (start);

CREATE TABLE TblMsdcMUser(
	ref INTEGER PRIMARY KEY AUTOINCREMENT,
	grp BIGINT,
	own BIGINT,
	refRUsergroup BIGINT,
	refMsdcMUsergroup BIGINT,
	refMsdcMPerson BIGINT,
	sref VARCHAR(50),
	refJState BIGINT,
	ixVState INT,
	ixMsdcVLocale INT,
	ixMsdcVUserlevel INT,
	Password VARCHAR(30),
	Fullkey TEXT,
	Comment TEXT
);
CREATE INDEX TblMsdcMUser_grp ON TblMsdcMUser (grp);
CREATE INDEX TblMsdcMUser_own ON TblMsdcMUser (own);
CREATE INDEX TblMsdcMUser_refMsdcMUsergroup ON TblMsdcMUser (refMsdcMUsergroup);
CREATE INDEX TblMsdcMUser_refMsdcMPerson ON TblMsdcMUser (refMsdcMPerson);
CREATE INDEX TblMsdcMUser_sref ON TblMsdcMUser (sref);
CREATE INDEX TblMsdcMUser_refJState ON TblMsdcMUser (refJState);
CREATE INDEX TblMsdcMUser_ixVState ON TblMsdcMUser (ixVState);

CREATE TABLE TblMsdcMUsergroup(
	ref INTEGER PRIMARY KEY AUTOINCREMENT,
	grp BIGINT,
	own BIGINT,
	sref VARCHAR(50),
	Comment TEXT
);
CREATE INDEX TblMsdcMUsergroup_grp ON TblMsdcMUsergroup (grp);
CREATE INDEX TblMsdcMUsergroup_own ON TblMsdcMUsergroup (own);
CREATE INDEX TblMsdcMUsergroup_sref ON TblMsdcMUsergroup (sref);

CREATE TABLE TblMsdcRMUsergroupUniversal(
	ref INTEGER PRIMARY KEY AUTOINCREMENT,
	refMsdcMUsergroup BIGINT,
	unvIxMsdcVMaintable INT,
	unvUref BIGINT,
	ixMsdcVRecaccess INT
);
CREATE INDEX TblMsdcRMUsergroupUniversal_refMsdcMUsergroup ON TblMsdcRMUsergroupUniversal (refMsdcMUsergroup);
CREATE INDEX TblMsdcRMUsergroupUniversal_unvIxMsdcVMaintable ON TblMsdcRMUsergroupUniversal (unvIxMsdcVMaintable);
CREATE INDEX TblMsdcRMUsergroupUniversal_unvUref ON TblMsdcRMUsergroupUniversal (unvUref);

CREATE TABLE TblMsdcRMUserMUsergroup(
	ref INTEGER PRIMARY KEY AUTOINCREMENT,
	refMsdcMUser BIGINT,
	refMsdcMUsergroup BIGINT,
	ixMsdcVUserlevel INT
);
CREATE INDEX TblMsdcRMUserMUsergroup_refMsdcMUser ON TblMsdcRMUserMUsergroup (refMsdcMUser);
CREATE INDEX TblMsdcRMUserMUsergroup_refMsdcMUsergroup ON TblMsdcRMUserMUsergroup (refMsdcMUsergroup);

CREATE TABLE TblMsdcQDatAPar(
	qref INTEGER PRIMARY KEY AUTOINCREMENT,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	x1Start DOUBLE PRECISION,
	x2SrefKKey VARCHAR(50),
	refMsdcMFile BIGINT,
	Val TEXT,
	Bindata TEXT
);
CREATE INDEX TblMsdcQDatAPar_jref ON TblMsdcQDatAPar (jref);
CREATE INDEX TblMsdcQDatAPar_jnum ON TblMsdcQDatAPar (jnum);

CREATE TABLE TblMsdcQDatList(
	qref INTEGER PRIMARY KEY AUTOINCREMENT,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	srefMsdcKAcqfeat VARCHAR(50),
	refMsdcMPeriod BIGINT,
	start INT,
	stop INT
);
CREATE INDEX TblMsdcQDatList_jref ON TblMsdcQDatList (jref);
CREATE INDEX TblMsdcQDatList_jnum ON TblMsdcQDatList (jnum);

CREATE TABLE TblMsdcQDatRef1NFile(
	qref INTEGER PRIMARY KEY AUTOINCREMENT,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
CREATE INDEX TblMsdcQDatRef1NFile_jref ON TblMsdcQDatRef1NFile (jref);
CREATE INDEX TblMsdcQDatRef1NFile_jnum ON TblMsdcQDatRef1NFile (jnum);

CREATE TABLE TblMsdcQFilList(
	qref INTEGER PRIMARY KEY AUTOINCREMENT,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	Filename VARCHAR(50),
	refIxVTbl INT,
	refUref BIGINT,
	osrefKContent VARCHAR(50),
	srefKMimetype VARCHAR(50),
	Size SMALLINT
);
CREATE INDEX TblMsdcQFilList_jref ON TblMsdcQFilList (jref);
CREATE INDEX TblMsdcQFilList_jnum ON TblMsdcQFilList (jnum);

CREATE TABLE TblMsdcQPrd1NData(
	qref INTEGER PRIMARY KEY AUTOINCREMENT,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
CREATE INDEX TblMsdcQPrd1NData_jref ON TblMsdcQPrd1NData (jref);
CREATE INDEX TblMsdcQPrd1NData_jnum ON TblMsdcQPrd1NData (jnum);

CREATE TABLE TblMsdcQPrdList(
	qref INTEGER PRIMARY KEY AUTOINCREMENT,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	start INT,
	stop INT
);
CREATE INDEX TblMsdcQPrdList_jref ON TblMsdcQPrdList (jref);
CREATE INDEX TblMsdcQPrdList_jnum ON TblMsdcQPrdList (jnum);

CREATE TABLE TblMsdcQPreselect(
	qref INTEGER PRIMARY KEY AUTOINCREMENT,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
CREATE INDEX TblMsdcQPreselect_jref ON TblMsdcQPreselect (jref);

CREATE TABLE TblMsdcQPrsList(
	qref INTEGER PRIMARY KEY AUTOINCREMENT,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	Title VARCHAR(30),
	Firstname VARCHAR(30),
	Lastname VARCHAR(50),
	grp BIGINT,
	own BIGINT,
	ixVSex INT,
	telVal VARCHAR(256),
	emlVal VARCHAR(256)
);
CREATE INDEX TblMsdcQPrsList_jref ON TblMsdcQPrsList (jref);
CREATE INDEX TblMsdcQPrsList_jnum ON TblMsdcQPrsList (jnum);

CREATE TABLE TblMsdcQSelect(
	qref INTEGER PRIMARY KEY AUTOINCREMENT,
	jref BIGINT,
	jnum INT,
	ix INT,
	ref BIGINT
);
CREATE INDEX TblMsdcQSelect_jref ON TblMsdcQSelect (jref);
CREATE INDEX TblMsdcQSelect_ix ON TblMsdcQSelect (ix);

CREATE TABLE TblMsdcQUsgAAccess(
	qref INTEGER PRIMARY KEY AUTOINCREMENT,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	x1IxMsdcVFeatgroup INT,
	x2FeaSrefUix VARCHAR(50),
	ixMsdcWAccess INT
);
CREATE INDEX TblMsdcQUsgAAccess_jref ON TblMsdcQUsgAAccess (jref);
CREATE INDEX TblMsdcQUsgAAccess_jnum ON TblMsdcQUsgAAccess (jnum);

CREATE TABLE TblMsdcQUsgList(
	qref INTEGER PRIMARY KEY AUTOINCREMENT,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	sref VARCHAR(50)
);
CREATE INDEX TblMsdcQUsgList_jref ON TblMsdcQUsgList (jref);
CREATE INDEX TblMsdcQUsgList_jnum ON TblMsdcQUsgList (jnum);

CREATE TABLE TblMsdcQUsgMNUser(
	qref INTEGER PRIMARY KEY AUTOINCREMENT,
	jref BIGINT,
	jnum INT,
	mref BIGINT,
	ref BIGINT,
	ixMsdcVUserlevel INT
);
CREATE INDEX TblMsdcQUsgMNUser_jref ON TblMsdcQUsgMNUser (jref);
CREATE INDEX TblMsdcQUsgMNUser_jnum ON TblMsdcQUsgMNUser (jnum);

CREATE TABLE TblMsdcQUsr1NSession(
	qref INTEGER PRIMARY KEY AUTOINCREMENT,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
CREATE INDEX TblMsdcQUsr1NSession_jref ON TblMsdcQUsr1NSession (jref);
CREATE INDEX TblMsdcQUsr1NSession_jnum ON TblMsdcQUsr1NSession (jnum);

CREATE TABLE TblMsdcQUsrAAccess(
	qref INTEGER PRIMARY KEY AUTOINCREMENT,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	x1IxMsdcVFeatgroup INT,
	x2FeaSrefUix VARCHAR(50),
	ixMsdcWAccess INT
);
CREATE INDEX TblMsdcQUsrAAccess_jref ON TblMsdcQUsrAAccess (jref);
CREATE INDEX TblMsdcQUsrAAccess_jnum ON TblMsdcQUsrAAccess (jnum);

CREATE TABLE TblMsdcQUsrList(
	qref INTEGER PRIMARY KEY AUTOINCREMENT,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	refMsdcMPerson BIGINT,
	sref VARCHAR(50),
	refMsdcMUsergroup BIGINT,
	ixVState INT,
	ixMsdcVLocale INT,
	ixMsdcVUserlevel INT
);
CREATE INDEX TblMsdcQUsrList_jref ON TblMsdcQUsrList (jref);
CREATE INDEX TblMsdcQUsrList_jnum ON TblMsdcQUsrList (jnum);

CREATE TABLE TblMsdcQUsrMNUsergroup(
	qref INTEGER PRIMARY KEY AUTOINCREMENT,
	jref BIGINT,
	jnum INT,
	mref BIGINT,
	ref BIGINT,
	ixMsdcVUserlevel INT
);
CREATE INDEX TblMsdcQUsrMNUsergroup_jref ON TblMsdcQUsrMNUsergroup (jref);
CREATE INDEX TblMsdcQUsrMNUsergroup_jnum ON TblMsdcQUsrMNUsergroup (jnum);

