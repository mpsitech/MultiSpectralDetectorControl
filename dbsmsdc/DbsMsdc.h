/**
  * \file DbsMsdc.h
  * C++ wrapper for database DbsMsdc (declarations)
  * \author Alexander Wirthmueller
  * \date created: 15 Aug 2018
  * \date modified: 15 Aug 2018
  */

#ifndef DBSMSDC_H
#define DBSMSDC_H

#define MSDC_VERSION "0.1.45"
#define MSDC_VERSION_MAJOR 0
#define MSDC_VERSION_MINOR 1
#define MSDC_VERSION_SUB 45

#include <sbecore/LiteDbs.h>

#include "MsdcAccRMUserUniversal.h"
#include "MsdcAMDataPar.h"
#include "MsdcAMPersonDetail.h"
#include "MsdcAMUserAccess.h"
#include "MsdcAMUsergroupAccess.h"
#include "MsdcAVControlPar.h"
#include "MsdcAVKeylistKey.h"
#include "MsdcAVValuelistVal.h"
#include "MsdcCFile.h"
#include "MsdcHistRMUserUniversal.h"
#include "MsdcJAVKeylistKey.h"
#include "MsdcJMPersonLastname.h"
#include "MsdcJMUserState.h"
#include "MsdcMData.h"
#include "MsdcMFile.h"
#include "MsdcMPeriod.h"
#include "MsdcMPerson.h"
#include "MsdcMSession.h"
#include "MsdcMUser.h"
#include "MsdcMUsergroup.h"
#include "MsdcRMUsergroupUniversal.h"
#include "MsdcRMUserMUsergroup.h"

#include "MsdcQDatAPar.h"
#include "MsdcQDatList.h"
#include "MsdcQDatRef1NFile.h"
#include "MsdcQFilList.h"
#include "MsdcQPrd1NData.h"
#include "MsdcQPrdList.h"
#include "MsdcQPreselect.h"
#include "MsdcQPrsList.h"
#include "MsdcQSelect.h"
#include "MsdcQUsgAAccess.h"
#include "MsdcQUsgList.h"
#include "MsdcQUsgMNUser.h"
#include "MsdcQUsr1NSession.h"
#include "MsdcQUsrAAccess.h"
#include "MsdcQUsrList.h"
#include "MsdcQUsrMNUsergroup.h"

#define VecMsdcVCard DbsMsdc::VecVCard
#define VecMsdcVControl DbsMsdc::VecVControl
#define VecMsdcVFeatgroup DbsMsdc::VecVFeatgroup
#define VecMsdcVKeylist DbsMsdc::VecVKeylist
#define VecMsdcVLocale DbsMsdc::VecVLocale
#define VecMsdcVMaintable DbsMsdc::VecVMaintable
#define VecMsdcVPreset DbsMsdc::VecVPreset
#define VecMsdcVRecaccess DbsMsdc::VecVRecaccess
#define VecMsdcVUserlevel DbsMsdc::VecVUserlevel
#define VecMsdcVValuelist DbsMsdc::VecVValuelist
#define VecMsdcWAccess DbsMsdc::VecWAccess

/**
  * DbsMsdc
  */
class DbsMsdc {

public:
	/**
		* VecVCard (full: VecMsdcVCard)
		*/
	class VecVCard {

	public:
		static const uint CRDMSDCNAV = 1;
		static const uint CRDMSDCUSG = 2;
		static const uint CRDMSDCUSR = 3;
		static const uint CRDMSDCPRS = 4;
		static const uint CRDMSDCSCF = 5;
		static const uint CRDMSDCLIV = 6;
		static const uint CRDMSDCPRD = 7;
		static const uint CRDMSDCDAT = 8;
		static const uint CRDMSDCFIL = 9;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);

		static string getTitle(const uint ix, const uint ixMsdcVLocale);

		static void fillFeed(const uint ixMsdcVLocale, Feed& feed);
	};

	/**
		* VecVControl (full: VecMsdcVControl)
		*/
	class VecVControl {

	public:
		static const uint PNLMSDCUSGLIST_TCOSRF = 1;
		static const uint PNLMSDCUSGAACCESS_TCOFEG = 2;
		static const uint PNLMSDCUSGAACCESS_TCOFEA = 3;
		static const uint PNLMSDCUSGAACCESS_TCOACC = 4;
		static const uint PNLMSDCUSGMNUSER_TCOMREF = 5;
		static const uint PNLMSDCUSGMNUSER_TCOULV = 6;
		static const uint PNLMSDCUSRLIST_TCOPRS = 7;
		static const uint PNLMSDCUSRLIST_TCOSRF = 8;
		static const uint PNLMSDCUSRLIST_TCOUSG = 9;
		static const uint PNLMSDCUSRLIST_TCOSTE = 10;
		static const uint PNLMSDCUSRLIST_TCOLCL = 11;
		static const uint PNLMSDCUSRLIST_TCOULV = 12;
		static const uint PNLMSDCUSRAACCESS_TCOFEG = 13;
		static const uint PNLMSDCUSRAACCESS_TCOFEA = 14;
		static const uint PNLMSDCUSRAACCESS_TCOACC = 15;
		static const uint PNLMSDCUSR1NSESSION_TCOREF = 16;
		static const uint PNLMSDCUSRMNUSERGROUP_TCOMREF = 17;
		static const uint PNLMSDCUSRMNUSERGROUP_TCOULV = 18;
		static const uint PNLMSDCPRSLIST_TCOTIT = 19;
		static const uint PNLMSDCPRSLIST_TCOFNM = 20;
		static const uint PNLMSDCPRSLIST_TCOLNM = 21;
		static const uint PNLMSDCPRSLIST_TCOGRP = 22;
		static const uint PNLMSDCPRSLIST_TCOOWN = 23;
		static const uint PNLMSDCPRSLIST_TCOSEX = 24;
		static const uint PNLMSDCPRSLIST_TCOTEL = 25;
		static const uint PNLMSDCPRSLIST_TCOEML = 26;
		static const uint PNLMSDCPRDLIST_TCOSTA = 27;
		static const uint PNLMSDCPRDLIST_TCOSTO = 28;
		static const uint PNLMSDCPRD1NDATA_TCOREF = 29;
		static const uint PNLMSDCDATLIST_TCOAFT = 30;
		static const uint PNLMSDCDATLIST_TCOPRD = 31;
		static const uint PNLMSDCDATLIST_TCOSTA = 32;
		static const uint PNLMSDCDATLIST_TCOSTO = 33;
		static const uint PNLMSDCDATAPAR_TCOSTA = 34;
		static const uint PNLMSDCDATAPAR_TCOKEY = 35;
		static const uint PNLMSDCDATAPAR_TCOFIL = 36;
		static const uint PNLMSDCDATAPAR_TCOVAL = 37;
		static const uint PNLMSDCDATAPAR_TCOBIN = 38;
		static const uint PNLMSDCDATREF1NFILE_TCOREF = 39;
		static const uint PNLMSDCFILLIST_TCOFNM = 40;
		static const uint PNLMSDCFILLIST_TCORET = 41;
		static const uint PNLMSDCFILLIST_TCOREU = 42;
		static const uint PNLMSDCFILLIST_TCOCNT = 43;
		static const uint PNLMSDCFILLIST_TCOMIM = 44;
		static const uint PNLMSDCFILLIST_TCOSIZ = 45;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
		* VecVFeatgroup (full: VecMsdcVFeatgroup)
		*/
	class VecVFeatgroup {

	public:
		static const uint VECMSDCVCARD = 1;
		static const uint VECVJOBMSDCACQADXLVAR = 2;
		static const uint VECVJOBMSDCACQLWIRMETHOD = 3;
		static const uint VECVJOBMSDCACQLWIRVAR = 4;
		static const uint VECVJOBMSDCACQVISLMETHOD = 5;
		static const uint VECVJOBMSDCACQVISLVAR = 6;
		static const uint VECVJOBMSDCACQVISRMETHOD = 7;
		static const uint VECVJOBMSDCACQVISRVAR = 8;
		static const uint VECVJOBMSDCACTALIGNMETHOD = 9;
		static const uint VECVJOBMSDCACTLEDMETHOD = 10;
		static const uint VECVJOBMSDCACTLEDVAR = 11;
		static const uint VECVJOBMSDCACTSERVOMETHOD = 12;
		static const uint VECVJOBMSDCACTSERVOVAR = 13;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);

		static string getTitle(const uint ix, const uint ixMsdcVLocale);

		static void fillFeed(const uint ixMsdcVLocale, Feed& feed);
	};

	/**
		* VecVKeylist (full: VecMsdcVKeylist)
		*/
	class VecVKeylist {

	public:
		static const uint KLSTMSDCKACQFEAT = 1;
		static const uint KLSTMSDCKAMDATAPARKEY = 2;
		static const uint KLSTMSDCKAMPERSONDETAILTYPE = 3;
		static const uint KLSTMSDCKMFILECONTENT = 4;
		static const uint KLSTMSDCKMFILEMIMETYPE = 5;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);

		static string getTitle(const uint ix, const uint ixMsdcVLocale);
	};

	/**
		* VecVLocale (full: VecMsdcVLocale)
		*/
	class VecVLocale {

	public:
		static const uint ENUS = 1;
		static const uint DECH = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);

		static string getTitle(const uint ix, const uint ixMsdcVLocale);

		static void fillFeed(const uint ixMsdcVLocale, Feed& feed);
	};

	/**
		* VecVMaintable (full: VecMsdcVMaintable)
		*/
	class VecVMaintable {

	public:
		static const uint VOID = 1;
		static const uint TBLMSDCMDATA = 2;
		static const uint TBLMSDCMFILE = 3;
		static const uint TBLMSDCMPERIOD = 4;
		static const uint TBLMSDCMPERSON = 5;
		static const uint TBLMSDCMSESSION = 6;
		static const uint TBLMSDCMUSER = 7;
		static const uint TBLMSDCMUSERGROUP = 8;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);

		static string getTitle(const uint ix, const uint ixMsdcVLocale);

		static void fillFeed(const uint ixMsdcVLocale, Feed& feed);
	};

	/**
		* VecVPreset (full: VecMsdcVPreset)
		*/
	class VecVPreset {

	public:
		static const uint VOID = 1;
		static const uint PREMSDCADM = 2;
		static const uint PREMSDCDATAPAR_X1 = 3;
		static const uint PREMSDCDATAPAR_X2 = 4;
		static const uint PREMSDCDATLIST_AFT = 5;
		static const uint PREMSDCDATLIST_PRD = 6;
		static const uint PREMSDCDATLIST_STA = 7;
		static const uint PREMSDCFILLIST_FNM = 8;
		static const uint PREMSDCFILLIST_RET = 9;
		static const uint PREMSDCFILLIST_REU = 10;
		static const uint PREMSDCGRP = 11;
		static const uint PREMSDCIP = 12;
		static const uint PREMSDCIXCRDACCDAT = 13;
		static const uint PREMSDCIXCRDACCFIL = 14;
		static const uint PREMSDCIXCRDACCLIV = 15;
		static const uint PREMSDCIXCRDACCPRD = 16;
		static const uint PREMSDCIXCRDACCPRS = 17;
		static const uint PREMSDCIXCRDACCSCF = 18;
		static const uint PREMSDCIXCRDACCUSG = 19;
		static const uint PREMSDCIXCRDACCUSR = 20;
		static const uint PREMSDCIXLCL = 21;
		static const uint PREMSDCIXORD = 22;
		static const uint PREMSDCIXPRE = 23;
		static const uint PREMSDCIXRECACC = 24;
		static const uint PREMSDCJREFNOTIFY = 25;
		static const uint PREMSDCJREFSESS = 26;
		static const uint PREMSDCOWN = 27;
		static const uint PREMSDCPRD = 28;
		static const uint PREMSDCPRDLIST_STA = 29;
		static const uint PREMSDCPRSLIST_GRP = 30;
		static const uint PREMSDCPRSLIST_LNM = 31;
		static const uint PREMSDCPRSLIST_OWN = 32;
		static const uint PREMSDCREFDAT = 33;
		static const uint PREMSDCREFFIL = 34;
		static const uint PREMSDCREFPRD = 35;
		static const uint PREMSDCREFPRS = 36;
		static const uint PREMSDCREFSEL = 37;
		static const uint PREMSDCREFSES = 38;
		static const uint PREMSDCREFUSG = 39;
		static const uint PREMSDCREFUSR = 40;
		static const uint PREMSDCSESS = 41;
		static const uint PREMSDCSUSPSESS = 42;
		static const uint PREMSDCSYSDATE = 43;
		static const uint PREMSDCSYSSTAMP = 44;
		static const uint PREMSDCSYSTIME = 45;
		static const uint PREMSDCUSGAACCESS_X1 = 46;
		static const uint PREMSDCUSGAACCESS_X2 = 47;
		static const uint PREMSDCUSGLIST_SRF = 48;
		static const uint PREMSDCUSRAACCESS_X1 = 49;
		static const uint PREMSDCUSRAACCESS_X2 = 50;
		static const uint PREMSDCUSRLIST_PRS = 51;
		static const uint PREMSDCUSRLIST_SRF = 52;
		static const uint PREMSDCUSRLIST_STE = 53;
		static const uint PREMSDCUSRLIST_USG = 54;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);

		static string getTitle(const uint ix, const uint ixMsdcVLocale);
	};

	/**
		* VecVRecaccess (full: VecMsdcVRecaccess)
		*/
	class VecVRecaccess {

	public:
		static const uint FULL = 1;
		static const uint NONE = 2;
		static const uint VIEW = 3;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);

		static string getTitle(const uint ix, const uint ixMsdcVLocale);

		static void fillFeed(const uint ixMsdcVLocale, Feed& feed);
	};

	/**
		* VecVUserlevel (full: VecMsdcVUserlevel)
		*/
	class VecVUserlevel {

	public:
		static const uint ADM = 1;
		static const uint GADM = 2;
		static const uint REG = 3;
		static const uint VTOR = 4;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);

		static string getTitle(const uint ix, const uint ixMsdcVLocale);

		static void fillFeed(const uint ixMsdcVLocale, Feed& feed);
	};

	/**
		* VecVValuelist (full: VecMsdcVValuelist)
		*/
	class VecVValuelist {

	public:
		static const uint VLSTMSDCUMPERSONTITLE = 1;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);

		static string getTitle(const uint ix, const uint ixMsdcVLocale);
	};

	/**
		* VecWAccess (full: VecMsdcWAccess)
		*/
	class VecWAccess {

	public:
		static const uint EDIT = 1;
		static const uint EXEC = 2;
		static const uint VIEW = 4;

		static uint getIx(const string& srefs);
		static void getIcs(const uint ix, set<uint>& ics);
		static string getSrefs(const uint ix);

		static string getTitle(const uint ix, const uint ixMsdcVLocale);

		static void fillFeed(const uint ixMsdcVLocale, Feed& feed);
	};

public:
	DbsMsdc();
	~DbsMsdc();

	void init(const uint _ixDbsVDbstype, const string& _dbspath, const string& _dbsname, const string& _ip, const uint _port, const string& _username, const string& _password);
	void term();

	void initLite();
	void termLite();

public:
	uint ixDbsVDbstype;
	string dbspath;
	string dbsname;
	string username;
	string password;
	string ip;
	int port;

	bool initdone;

	sqlite3* dbsLite;

public:
	void begin();																						//!< transaction functionality
	bool commit();
	void rollback();

	void beginLite();
	bool commitLite();
	void rollbackLite();

	bool loadUintBySQL(const string& sqlstr, uint& val);		//!< execute a SQL query returning a single uint (arbitrary tables)
	bool loadStringBySQL(const string& sqlstr, string& val);//!< execute a SQL query returning a single string (arbitrary tables)

	bool loadRefBySQL(const string& sqlstr, ubigint& ref);	//!< execute a SQL query returning a single reference (arbitrary tables)
																													//! load a list of references by a SQL query (arbitrary tables)
	ubigint loadRefsBySQL(const string& sqlstr, const bool append, vector<ubigint>& refs);

	bool loadUintBySQLLite(const string& sqlstr, uint& val);
	bool loadStringBySQLLite(const string& sqlstr, string& val);

	bool loadRefBySQLLite(const string& sqlstr, ubigint& ref);
	ubigint loadRefsBySQLLite(const string& sqlstr, const bool append, vector<ubigint>& refs);

	void executeQuery(const string& sqlstr);								//!< run single SQL command
	void executeQueryDiv(const string& sqlstrlite);
	void executeFile(const string& fullpath);								//!< SQL file batch execution

public:

	void fillFeedFromKlst(const uint klsIxMsdcVKeylist, const uint ixMsdcVLocale, Feed& feed);
	void fillFeedFromKlstByMtbUref(const uint klsIxMsdcVKeylist, const uint x1IxMsdcVMaintable, const ubigint x1Uref, const uint ixMsdcVLocale, Feed& feed);

	string getKlstTitleBySref(const uint klsIxMsdcVKeylist, const string& sref, const uint ixMsdcVLocale = 0);
	string getKlstTitleByMtbUrefSref(const uint klsIxMsdcVKeylist, const uint x1IxMsdcVMaintable, const ubigint x1Uref, const string& sref, const uint ixMsdcVLocale = 0);

	void fillFeedFromVlst(const uint vlsIxMsdcVValuelist, const uint x1IxMsdcVLocale, Feed& feed);

public:
	TblMsdcAccRMUserUniversal* tblmsdcaccrmuseruniversal;
	TblMsdcAMDataPar* tblmsdcamdatapar;
	TblMsdcAMPersonDetail* tblmsdcampersondetail;
	TblMsdcAMUserAccess* tblmsdcamuseraccess;
	TblMsdcAMUsergroupAccess* tblmsdcamusergroupaccess;
	TblMsdcAVControlPar* tblmsdcavcontrolpar;
	TblMsdcAVKeylistKey* tblmsdcavkeylistkey;
	TblMsdcAVValuelistVal* tblmsdcavvaluelistval;
	TblMsdcCFile* tblmsdccfile;
	TblMsdcHistRMUserUniversal* tblmsdchistrmuseruniversal;
	TblMsdcJAVKeylistKey* tblmsdcjavkeylistkey;
	TblMsdcJMPersonLastname* tblmsdcjmpersonlastname;
	TblMsdcJMUserState* tblmsdcjmuserstate;
	TblMsdcMData* tblmsdcmdata;
	TblMsdcMFile* tblmsdcmfile;
	TblMsdcMPeriod* tblmsdcmperiod;
	TblMsdcMPerson* tblmsdcmperson;
	TblMsdcMSession* tblmsdcmsession;
	TblMsdcMUser* tblmsdcmuser;
	TblMsdcMUsergroup* tblmsdcmusergroup;
	TblMsdcRMUsergroupUniversal* tblmsdcrmusergroupuniversal;
	TblMsdcRMUserMUsergroup* tblmsdcrmusermusergroup;

	TblMsdcQDatAPar* tblmsdcqdatapar;
	TblMsdcQDatList* tblmsdcqdatlist;
	TblMsdcQDatRef1NFile* tblmsdcqdatref1nfile;
	TblMsdcQFilList* tblmsdcqfillist;
	TblMsdcQPrd1NData* tblmsdcqprd1ndata;
	TblMsdcQPrdList* tblmsdcqprdlist;
	TblMsdcQPreselect* tblmsdcqpreselect;
	TblMsdcQPrsList* tblmsdcqprslist;
	TblMsdcQSelect* tblmsdcqselect;
	TblMsdcQUsgAAccess* tblmsdcqusgaaccess;
	TblMsdcQUsgList* tblmsdcqusglist;
	TblMsdcQUsgMNUser* tblmsdcqusgmnuser;
	TblMsdcQUsr1NSession* tblmsdcqusr1nsession;
	TblMsdcQUsrAAccess* tblmsdcqusraaccess;
	TblMsdcQUsrList* tblmsdcqusrlist;
	TblMsdcQUsrMNUsergroup* tblmsdcqusrmnusergroup;
};
#endif

