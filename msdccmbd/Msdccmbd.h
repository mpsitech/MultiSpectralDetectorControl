/**
  * \file Msdccmbd.h
  * inter-thread exchange object for Msdc combined daemon (declarations)
  * \author Alexander Wirthmueller
  * \date created: 12 Sep 2018
  * \date modified: 12 Sep 2018
  */

#ifndef MSDCCMBD_H
#define MSDCCMBD_H

#ifdef __CYGWIN__
	#include <sys/select.h>
#endif

#include <unistd.h>

#ifndef _WIN32
	#include <sys/socket.h>
#endif
#ifdef _WIN32
	#include <windows.h>
	#include <winsock.h>
	typedef int socklen_t;
#endif

#include <sys/stat.h>

#include <microhttpd.h>

#include <sbecore/Txtrd.h>
#include <sbecore/TxtMon.h>

#include "Msdc.h"

// IP incl --- IBEGIN
#ifdef __linux__
	#include "Spinnaker.h"
#endif

#include "DevMsdd.h"
// IP incl --- IEND

class XchgMsdccmbd;
typedef XchgMsdccmbd XchgMsdc;

/**
	* DpchAppMsdc
	*/
class DpchAppMsdc : public DpchMsdc {

public:
	static const uint JREF = 1;

public:
	DpchAppMsdc(const uint ixMsdcVDpch = 0);
	virtual ~DpchAppMsdc();

public:
	ubigint jref;

public:
	static bool all(const set<uint>& items);
	virtual string getSrefsMask();

	virtual void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * DpchAppMsdcAlert
  */
class DpchAppMsdcAlert : public DpchAppMsdc {

public:
	static const uint JREF = 1;
	static const uint NUMFMCB = 2;

public:
	DpchAppMsdcAlert();

public:
	uint numFMcb;

public:
	static bool all(const set<uint>& items);
	string getSrefsMask();

	void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * DpchAppMsdcInit
  */
class DpchAppMsdcInit : public DpchAppMsdc {

public:
	DpchAppMsdcInit();
};

/**
  * DpchAppMsdcResume
  */
class DpchAppMsdcResume : public DpchAppMsdc {

public:
	DpchAppMsdcResume();
};

/**
	* DpchEngMsdc
	*/
class DpchEngMsdc : public DpchMsdc {

public:
	static const uint JREF = 1;

public:
	DpchEngMsdc(const uint ixMsdcVDpch = 0, const ubigint jref = 0);
	virtual ~DpchEngMsdc();

public:
	ubigint jref;

public:
	static bool all(const set<uint>& items);
	virtual string getSrefsMask();
	virtual void merge(DpchEngMsdc* dpcheng);

	virtual void writeXML(const uint ixMsdcVLocale, xmlTextWriter* wr);
};

/**
  * DpchEngMsdcAck
  */
class DpchEngMsdcAck : public DpchEngMsdc {

public:
	DpchEngMsdcAck(const ubigint jref = 0);
};

/**
  * DpchEngMsdcAlert
  */
class DpchEngMsdcAlert : public DpchEngMsdc {

public:
	static const uint JREF = 1;
	static const uint CONTINF = 2;
	static const uint FEEDFMCB = 3;
	static const uint ALL = 4;

public:
	DpchEngMsdcAlert(const ubigint jref = 0, ContInfMsdcAlert* continf = NULL, Feed* feedFMcb = NULL, const set<uint>& mask = {NONE});

public:
	ContInfMsdcAlert continf;
	Feed feedFMcb;

public:
	static bool all(const set<uint>& items);
	string getSrefsMask();
	void merge(DpchEngMsdc* dpcheng);

	void writeXML(const uint ixMsdcVLocale, xmlTextWriter* wr);
};

/**
  * DpchEngMsdcConfirm
  */
class DpchEngMsdcConfirm : public DpchEngMsdc {

public:
	static const uint ACCEPTED = 1;
	static const uint JREF = 2;
	static const uint SREF = 3;
	static const uint ALL = 4;

public:
	DpchEngMsdcConfirm(const bool accepted = false, const ubigint jref = 0, const string& sref = "", const set<uint>& mask = {ALL});

public:
	bool accepted;
	string sref;

public:
	static bool all(const set<uint>& items);
	string getSrefsMask();
	void merge(DpchEngMsdc* dpcheng);

	void writeXML(const uint ixMsdcVLocale, xmlTextWriter* wr);
};

/**
  * DpchEngMsdcSuspend
  */
class DpchEngMsdcSuspend : public DpchEngMsdc {

public:
	DpchEngMsdcSuspend(const ubigint jref = 0);
};

/**
	* StgMsdccmbd
	*/
class StgMsdccmbd : public Block {

public:
	static const uint JOBPRCN = 1;
	static const uint OPPRCN = 2;
	static const uint APPSRVPORT = 3;
	static const uint HTTPS = 4;
	static const uint APPSRV = 5;
	static const uint UASRV = 6;
	static const uint HISTLENGTH = 7;

public:
	StgMsdccmbd(const usmallint jobprcn = 1, const usmallint opprcn = 1, const usmallint appsrvport = 0, const bool https = false, const bool appsrv = true, const bool uasrv = true, const usmallint histlength = 20);

public:
	usmallint jobprcn;
	usmallint opprcn;
	usmallint appsrvport;
	bool https;
	bool appsrv;
	bool uasrv;
	usmallint histlength;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	set<uint> comm(const StgMsdccmbd* comp);
	set<uint> diff(const StgMsdccmbd* comp);
};

/**
	* StgMsdcDatabase
	*/
class StgMsdcDatabase : public Block {

public:
	static const uint IXDBSVDBSTYPE = 1;
	static const uint DBSPATH = 2;
	static const uint DBSNAME = 3;
	static const uint USERNAME = 4;
	static const uint PASSWORD = 5;
	static const uint IP = 6;
	static const uint PORT = 7;

public:
	StgMsdcDatabase(const uint ixDbsVDbstype = 0, const string& dbspath = "", const string& dbsname = "", const string& username = "mpsitech", const string& password = "f9w8feeh", const string& ip = "", const usmallint port = 0);

public:
	uint ixDbsVDbstype;
	string dbspath;
	string dbsname;
	string username;
	string password;
	string ip;
	usmallint port;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	set<uint> comm(const StgMsdcDatabase* comp);
	set<uint> diff(const StgMsdcDatabase* comp);
};

/**
	* StgMsdcPath
	*/
class StgMsdcPath : public Block {

public:
	static const uint ACVPATH = 1;
	static const uint KEYPATH = 2;
	static const uint MONPATH = 3;
	static const uint TMPPATH = 4;
	static const uint WEBPATH = 5;
	static const uint HELPURL = 6;

public:
	StgMsdcPath(const string& acvpath = "", const string& keypath = "", const string& monpath = "", const string& tmppath = "", const string& webpath = "", const string& helpurl = "");

public:
	string acvpath;
	string keypath;
	string monpath;
	string tmppath;
	string webpath;
	string helpurl;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	set<uint> comm(const StgMsdcPath* comp);
	set<uint> diff(const StgMsdcPath* comp);
};

/**
	* StgMsdcUasrv
	*/
class StgMsdcUasrv : public Block {

public:
	static const uint PROFILE = 1;
	static const uint PORT = 2;
	static const uint CYCLE = 3;
	static const uint MAXBROWSE = 4;
	static const uint MAXMON = 5;

public:
	StgMsdcUasrv(const string& profile = "", const usmallint port = 0, const usmallint cycle = 0, const uint maxbrowse = 0, const uint maxmon = 0);

public:
	string profile;
	usmallint port;
	usmallint cycle;
	uint maxbrowse;
	uint maxmon;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	set<uint> comm(const StgMsdcUasrv* comp);
	set<uint> diff(const StgMsdcUasrv* comp);
};

/**
  * AlrMsdc
  */
namespace AlrMsdc {
	DpchEngMsdcAlert* prepareAlrAbt(const ubigint jref, const uint ixMsdcVLocale, Feed& feedFMcbAlert);
	DpchEngMsdcAlert* prepareAlrPer(const ubigint jref, const uint ixMsdcVLocale, const string& lineno, Feed& feedFMcbAlert);
	DpchEngMsdcAlert* prepareAlrSav(const ubigint jref, const uint ixMsdcVLocale, Feed& feedFMcbAlert);
};

/**
  * ReqMsdc
  */
class ReqMsdc {

public:
	/**
		* VecVBasetype
		*/
	class VecVBasetype {

	public:
		static const uint NONE = 0; // invalid
		static const uint WEB = 1; // web client triggered ui file request (GET)
		static const uint CMD = 2; // command line request
		static const uint REGULAR = 3; // web client triggered Dpch request (POST+Dpch)
		static const uint NOTIFY = 4; // web client triggered notify-on-Dpch request (GET)
		static const uint POLL = 5; // web client triggered Dpch poll request (GET)
		static const uint UPLOAD = 6; // web client triggered file upload request (POST)
		static const uint DOWNLOAD = 7; // web client triggered file download request (GET)
		static const uint RET = 8; // op engine or opprc triggered op return (DpchRet)
		static const uint METHOD = 9; // M2M interface triggered method request
		static const uint TIMER = 10; // timer triggered request
		static const uint EXTCALL = 11; // externally triggered call request
	};

	/**
		* VecVState
		*/
	class VecVState {

	public:
		static const uint NONE = 0; // invalid
		static const uint RECEIVE = 1; // during data reception - appsrv internal
		static const uint WAITPRC = 2; // before caught by job processor that is idle - in reqs list
		static const uint PRC = 3; // while being processesd by job processor ; appsrv thread waiting on cReply
		static const uint REPLY = 4; // after being processed by job processor
	};

public:
	ReqMsdc(const uint ixVBasetype = VecVBasetype::NONE, const uint ixVState = VecVState::RECEIVE, const string& ip = "");
	~ReqMsdc();

public:
	uint ixVBasetype;
	uint ixVState;

	// specific data for base type CMD
	string cmd;

	// specific data for base types REGULAR, NOTIFY, POLL, UPLOAD, DOWNLOAD
	string ip;

	// specific data for base types REGULAR, NOTIFY, POLL, UPLOAD
	MHD_PostProcessor* pp;

	// specific data for base types CMD, REGULAR, NOTIFY, UPLOAD, DOWNLOAD, METHOD
	bool retain;
	Cond cReady; // mutex also protects compare/set of ixVState to REPLY

	// specific data for base types WEB, UPLOAD, DOWNLOAD
	string filename; // full path
	fstream* file;
	size_t filelen;

	// specific data for base types REGULAR, NOTIFY, POLL, RET
	char* request;
	size_t requestlen;

	// specific data for base types CMD, REGULAR, NOTIFY, POLL, UPLOAD, DOWNLOAD, RET, TIMER
	ubigint jref;

	// specific data for base type TIMER
	ubigint wref;
	string sref;

	// specific data for base type EXTCALL
	Call* call;

	// specific data for base types CMD, REGULAR, UPLOAD, DOWNLOAD, RET, TIMER
	bool weak;

	// specific data for base type REGULAR
	DpchAppMsdc* dpchapp;

	// specific data for base types REGULAR, NOTIFY, POLL
	DpchEngMsdc* dpcheng;
	uint ixMsdcVLocale;

	// specific data for base type RET
	DpchInvMsdc* dpchinv;
	DpchRetMsdc* dpchret;

	// specific data for base types REGULAR, NOTIFY, POLL, RET
	char* reply;
	size_t replylen;

	// specific data for base type METHOD
	Method* method;

public:
	void setStateReply();
};

/**
	* DcolMsdc
	*/
class DcolMsdc {

public:
	DcolMsdc(const ubigint jref = 0, const uint ixMsdcVLocale = VecMsdcVLocale::ENUS);
	~DcolMsdc();

public:
	ubigint jref;

	uint ixMsdcVLocale;

	Mutex mAccess;

	bool hot;

	list<DpchEngMsdc*> dpchs;

	ReqMsdc* req;

public:
	void lockAccess(const string& srefObject = "", const string& srefMember = "");
	void unlockAccess(const string& srefObject = "", const string& srefMember = "");
};

/**
  * JobMsdc
  */
class JobMsdc {

public:
	JobMsdc(XchgMsdc* xchg, const uint ixMsdcVJob = 0, const ubigint jrefSup = 0, const uint ixMsdcVLocale = VecMsdcVLocale::ENUS);
	virtual ~JobMsdc();

public:
	XchgMsdc* xchg;

	ubigint jref;

	uint ixMsdcVJob;

	ubigint jrefSup;
	set<ubigint> jrefsSub;

	uint ixMsdcVLocale;

	Mutex mAccess;

	bool muteRefresh;

	uint ixVSge;
	uint nextIxVSge;

	uint opNdone;
	uint opN;

	vector<DpchInvMsdc*> invs;

	Mutex mOps;
	list<Op*> ops;
	string opsqkLast;

	ubigint wrefLast;
	ubigint wrefMin;

	ReqMsdc* reqCmd;

public:
	virtual DpchEngMsdc* getNewDpchEng(set<uint> items);

	virtual void refresh(DbsMsdc* dbsmsdc, set<uint>& moditems);
	void refreshWithDpchEng(DbsMsdc* dbsmsdc, DpchEngMsdc** dpcheng = NULL);

	virtual string getSquawk(DbsMsdc* dbsmsdc);

	virtual void handleRequest(DbsMsdc* dbsmsdc, ReqMsdc* req);
	virtual void handleCall(DbsMsdc* dbsmsdc, Call* call);

	void lockAccess(const string& srefObject, const string& srefMember);
	bool trylockAccess(const string& srefObject, const string& srefMember);
	void unlockAccess(const string& srefObject, const string& srefMember);

	void lockAccess(const string& srefMember);
	bool trylockAccess(const string& srefMember);
	void unlockAccess(const string& srefMember);

	void setStage(DbsMsdc* dbsmsdc, const uint _ixVSge);

	void clearInvs();
	ubigint addInv(DpchInvMsdc* inv);
	void addInvs(vector<DpchInvMsdc*>& _invs);
	void submitInvs(DbsMsdc* dbsmsdc, const uint emptyIxVSge, uint& _ixVSge);

	void clearOps();
	void addOp(DbsMsdc* dbsmsdc, DpchInvMsdc* inv);
	void removeOp(const ubigint oref);
	string getOpsqkLast();

	void callback(const uint _nextIxVSge);
	void invalidateWakeups();
};

/**
  * MsjobMsdc
  */
class MsjobMsdc : public JobMsdc {

public:
	MsjobMsdc(XchgMsdc* xchg, const uint ixMsdcVJob = 0, const ubigint jrefSup = 0, const uint ixMsdcVLocale = VecMsdcVLocale::ENUS, const bool prefmast = false);
	virtual ~MsjobMsdc();

public:
	bool prefmast;

	bool srd;

public:
	virtual void giveupMaster(DbsMsdc* dbsmsdc, Msjobinfo* msji);
	virtual void giveupSlave(DbsMsdc* dbsmsdc, Msjobinfo* msji);
	virtual void becomeMaster(DbsMsdc* dbsmsdc, Msjobinfo* msji);
	virtual void becomeSlave(DbsMsdc* dbsmsdc, Msjobinfo* msji);

	virtual bool handleClaimMaster(DbsMsdc* dbsmsdc, Msjobinfo* msji);

	bool getMastNotSlv();

	MsjobMsdc* lockMaster(const string& srefMember);
	void unlockMaster(MsjobMsdc* job, const string& srefMember);

	bool start(DbsMsdc* dbsmsdc);
	bool stop(DbsMsdc* dbsmsdc);

	void setStage(DbsMsdc* dbsmsdc, const uint _ixVSge);
};

/**
  * ShrdatMsdc
  */
class ShrdatMsdc {

public:
	ShrdatMsdc(const string& srefSupclass, const string& srefObject);
	~ShrdatMsdc();

public:
	string srefSupclass;
	string srefObject;

	Rwmutex rwmAccess;

public:
	virtual void init(XchgMsdc* xchg, DbsMsdc* dbsmsdc);
	virtual void term();

	void rlockAccess(const string& srefObject, const string& srefMember);
	void runlockAccess(const string& srefObject, const string& srefMember);
	void rlockAccess(const ubigint jref, const string& srefMember);
	void runlockAccess(const ubigint jref, const string& srefMember);

	void wlockAccess(const string& srefObject, const string& srefMember);
	void wunlockAccess(const string& srefObject, const string& srefMember);
	void wlockAccess(const ubigint jref, const string& srefMember);
	void wunlockAccess(const ubigint jref, const string& srefMember);
};

/**
  * StmgrMsdc
  */
class StmgrMsdc {

public:
	StmgrMsdc(XchgMsdc* xchg, const ubigint jref, const uint ixVNonetype);
	~StmgrMsdc();

public:
	XchgMsdc* xchg;

	ubigint jref;
	uint ixVNonetype;

	Stcch* stcch;

	Mutex mAccess;

public:
	void handleCall(DbsMsdc* dbsmsdc, Call* call);
	bool refresh(DbsMsdc* dbsmsdc, Stcchitem* stit);

	void begin();
	void commit();

	void lockAccess(const string& srefObject = "", const string& srefMember = "");
	void unlockAccess(const string& srefObject = "", const string& srefMember = "");
};

/**
  * WakeupMsdc
  */
class WakeupMsdc {

public:
	WakeupMsdc(XchgMsdc* xchg, const ubigint wref, const ubigint jref, const string sref, const unsigned int deltat = 0, const bool weak = false);

public:
	XchgMsdc* xchg;

	ubigint wref;

	ubigint jref;
	string sref;
	unsigned int deltat;
	bool weak;
};

/**
  * ExtcallMsdc
  */
class ExtcallMsdc {

public:
	ExtcallMsdc(XchgMsdc* xchg, Call* call);

public:
	XchgMsdc* xchg;
	Call* call;
};

/**
  * XchgMsdccmbd
  */
class XchgMsdccmbd {

public:
	/**
		* ShrdatJobprc
		*/
	class ShrdatJobprc : public ShrdatMsdc {

	public:
		// IP ShrdatJobprc.subs --- INSERT

	public:
		ShrdatJobprc();

	public:
		// IP ShrdatJobprc.vars --- IBEGIN
#ifdef __linux__
		// pointer to singleton Spinnaker object when Blackfly cameras are used in AcqVisl/AcqVisr
		Spinnaker::SystemPtr spinsys;
#endif
		// IP ShrdatJobprc.vars --- IEND

	public:
		void init(XchgMsdc* xchg, DbsMsdc* dbsmsdc);
		void term();
	};

	/**
		* ShrdatOpprc
		*/
	class ShrdatOpprc : public ShrdatMsdc {

	public:
		// IP ShrdatOpprc.subs --- INSERT

	public:
		ShrdatOpprc();

	public:
		// IP ShrdatOpprc.vars --- INSERT

	public:
		void init(XchgMsdc* xchg, DbsMsdc* dbsmsdc);
		void term();
	};

public:
	XchgMsdccmbd();
	~XchgMsdccmbd();

public:
	StgMsdccmbd stgmsdccmbd;
	StgMsdcDatabase stgmsdcdatabase;
	StgMsdcPath stgmsdcpath;
	StgMsdcUasrv stgmsdcuasrv;

	ShrdatJobprc shrdatJobprc;
	ShrdatOpprc shrdatOpprc;

public:
	// IP cust --- INSERT

public:
	// executable/archive/temporary folder paths and help URL
	string exedir;
	string acvpath;
	string tmppath;
	string helpurl;

	string key;
	string cert;

	// root job
	ubigint jrefRoot;

	// job receiving commands
	ubigint jrefCmd;

	// monitor object
	TxtMon mon;

	// log file
	Mutex mLogfile;

	// condition for job processors
	Cond cJobprcs;

	// condition for op processors
	Cond cOpprcs;

	// condition for OPC UA server
	Cond cUasrv;

	// request list
	Mutex mReqs;
	list<ReqMsdc*> reqs;

	// operation invocation list
	Refseq orefseq;
	Mutex mInvs;
	list<DpchInvMsdc*> invs;

	// presetting list
	Rwmutex rwmPresets;
	multimap<presetref_t,Preset*> presets;

	// stub manager list
	Rwmutex rwmStmgrs;
	map<ubigint,StmgrMsdc*> stmgrs;

	// call listener list
	Rwmutex rwmClstns;
	multimap<clstnref_t,Clstn*> clstns;
	multimap<clstnref2_t,clstnref_t> cref2sClstns;

	// dispatch collector list
	Rwmutex rwmDcols;
	map<ubigint,DcolMsdc*> dcols;

	// job list
	Refseq jrefseq;
	Rwmutex rwmJobs;
	map<ubigint,JobMsdc*> jobs;

	// master-slave job information
	Rwmutex rwmMsjobinfos;
	map<uint,Msjobinfo*> msjobinfos;

	// OPC UA server call
	Mutex mUasrvcall;
	Call* uasrvcall;

	// sequence for wakeup references
	Refseq wrefseq;

public:
	// monitor object methods
	void startMon();
	void stopMon();

	// log file methods
	void appendToLogfile(const string& str);

	// request list methods
	void addReq(ReqMsdc* req);
	ReqMsdc* pullFirstReq();

	// operation invocation list methods
	void addInvs(DbsMsdc* dbsmsdc, const ubigint jref, vector<DpchInvMsdc*>& dpchinvs);
	DpchInvMsdc* pullFirstInv();

	// presetting methods
	Preset* addPreset(const uint ixMsdcVPreset, const ubigint jref, const Arg& arg);

	Preset* addIxPreset(const uint ixMsdcVPreset, const ubigint jref, const uint ix);
	Preset* addRefPreset(const uint ixMsdcVPreset, const ubigint jref, const ubigint ref);
	Preset* addRefsPreset(const uint ixMsdcVPreset, const ubigint jref, const vector<ubigint>& refs);
	Preset* addSrefPreset(const uint ixMsdcVPreset, const ubigint jref, const string& sref);
	Preset* addIntvalPreset(const uint ixMsdcVPreset, const ubigint jref, const int intval);
	Preset* addDblvalPreset(const uint ixMsdcVPreset, const ubigint jref, const double dblval);
	Preset* addBoolvalPreset(const uint ixMsdcVPreset, const ubigint jref, const bool boolval);
	Preset* addTxtvalPreset(const uint ixMsdcVPreset, const ubigint jref, const string& txtval);

	Preset* getPresetByPref(const presetref_t& pref);

	Arg getPreset(const uint ixMsdcVPreset, const ubigint jref);

	uint getIxPreset(const uint ixMsdcVPreset, const ubigint jref);
	ubigint getRefPreset(const uint ixMsdcVPreset, const ubigint jref);
	vector<ubigint> getRefsPreset(const uint ixMsdcVPreset, const ubigint jref);
	string getSrefPreset(const uint ixMsdcVPreset, const ubigint jref);
	int getIntvalPreset(const uint ixMsdcVPreset, const ubigint jref);
	double getDblvalPreset(const uint ixMsdcVPreset, const ubigint jref);
	bool getBoolvalPreset(const uint ixMsdcVPreset, const ubigint jref);
	string getTxtvalPreset(const uint ixMsdcVPreset, const ubigint jref);

	void getPresetsByJref(const ubigint jref, vector<uint>& icsMsdcVPreset, vector<Arg>& args);

	void removePreset(const uint ixMsdcVPreset, const ubigint jref);
	void removePresetsByJref(const ubigint jref);

	// stub manager methods
	StmgrMsdc* addStmgr(const ubigint jref, const uint ixVNonetype);
	StmgrMsdc* getStmgrByJref(const ubigint jref);
	void removeStmgrByJref(const ubigint jref);

	// call listener list methods
	Clstn* addClstn(const uint ixMsdcVCall, const ubigint jref, const uint ixVJobmask, const ubigint jrefTrig, const Arg& argMask, const uint ixVJactype = Clstn::VecVJactype::LOCK);

	Clstn* addIxClstn(const uint ixMsdcVCall, const ubigint jref, const uint ixVJobmask, const ubigint jrefTrig, const uint ixMask, const uint ixVJactype = Clstn::VecVJactype::LOCK);
	Clstn* addRefClstn(const uint ixMsdcVCall, const ubigint jref, const uint ixVJobmask, const ubigint jrefTrig, const ubigint refMask, const uint ixVJactype = Clstn::VecVJactype::LOCK);
	Clstn* addIxRefClstn(const uint ixMsdcVCall, const ubigint jref, const uint ixVJobmask, const ubigint jrefTrig, const uint ixMask, const ubigint refMask, const uint ixVJactype = Clstn::VecVJactype::LOCK);
	Clstn* addIxRefSrefClstn(const uint ixMsdcVCall, const ubigint jref, const uint ixVJobmask, const ubigint jrefTrig, const uint ixMask, const ubigint refMask, const string& srefMask, const uint ixVJactype = Clstn::VecVJactype::LOCK);

	Clstn* addClstnStmgr(const uint ixMsdcVCall, const ubigint jref);
	Clstn* addClstnUasrv(const ubigint jrefTrig, const string& srefMask);

	Clstn* getClstnByCref(const clstnref_t& cref);
	void getClstnsByJref(const ubigint jref, const uint ixVTarget, vector<uint>& icsMsdcVCall, vector<uint>& icsVJobmask);

	void removeClstns(const uint ixMsdcVCall, const ubigint jref, const uint ixVTarget = Clstn::VecVTarget::JOB);
	void removeClstnsByJref(const ubigint jref, const uint ixVTarget = Clstn::VecVTarget::JOB);

	// call methods
	void findJrefsByCall(Call* call, vector<ubigint>& jrefs, vector<uint>& icsVTarget, vector<uint>& icsVJactype);

	void triggerCall(DbsMsdc* dbsmsdc, Call* call);

	bool triggerArgToArgCall(DbsMsdc* dbsmsdc, const uint ixMsdcVCall, const ubigint jref, const Arg& argInv, Arg& argRet);
	bool triggerCall(DbsMsdc* dbsmsdc, const uint ixMsdcVCall, const ubigint jref);
	bool triggerIxCall(DbsMsdc* dbsmsdc, const uint ixMsdcVCall, const ubigint jref, const uint ixInv);
	bool triggerRefCall(DbsMsdc* dbsmsdc, const uint ixMsdcVCall, const ubigint jref, const ubigint refInv);
	bool triggerIntvalCall(DbsMsdc* dbsmsdc, const uint ixMsdcVCall, const ubigint jref, const int intvalInv);
	bool triggerBoolvalCall(DbsMsdc* dbsmsdc, const uint ixMsdcVCall, const ubigint jref, const bool boolvalInv);
	bool triggerIxRefCall(DbsMsdc* dbsmsdc, const uint ixMsdcVCall, const ubigint jref, const uint ixInv, const ubigint refInv);
	bool triggerIxSrefCall(DbsMsdc* dbsmsdc, const uint ixMsdcVCall, const ubigint jref, const uint ixInv, const string& srefInv);
	bool triggerIxSrefToIxCall(DbsMsdc* dbsmsdc, const uint ixMsdcVCall, const ubigint jref, const uint ixInv, const string& srefInv, uint& ixRet);
	bool triggerIxIntvalCall(DbsMsdc* dbsmsdc, const uint ixMsdcVCall, const ubigint jref, const uint ixInv, const int intvalInv);
	bool triggerIxDblvalCall(DbsMsdc* dbsmsdc, const uint ixMsdcVCall, const ubigint jref, const uint ixInv, const double dblvalInv);
	bool triggerIxTxtvalCall(DbsMsdc* dbsmsdc, const uint ixMsdcVCall, const ubigint jref, const uint ixInv, const string& txtvalInv);
	bool triggerSrefCall(DbsMsdc* dbsmsdc, const uint ixMsdcVCall, const ubigint jref, const string& srefInv);
	bool triggerToBoolvalCall(DbsMsdc* dbsmsdc, const uint ixMsdcVCall, const ubigint jref, bool& boolvalRet);
	bool triggerIxToBoolvalCall(DbsMsdc* dbsmsdc, const uint ixMsdcVCall, const ubigint jref, const uint ixInv, bool& boolvalRet);
	bool triggerRefToSrefCall(DbsMsdc* dbsmsdc, const uint ixMsdcVCall, const ubigint jref, const ubigint refInv, string& srefRet);
	bool triggerRefToBoolvalCall(DbsMsdc* dbsmsdc, const uint ixMsdcVCall, const ubigint jref, const ubigint refInv, bool& boolvalRet);
	bool triggerIxRefToIxCall(DbsMsdc* dbsmsdc, const uint ixMsdcVCall, const ubigint jref, const uint ixInv, const ubigint refInv, uint& ixRet);
	bool triggerIxRefToRefCall(DbsMsdc* dbsmsdc, const uint ixMsdcVCall, const ubigint jref, const uint ixInv, const ubigint refInv, ubigint& refRet);
	bool triggerIxRefSrefCall(DbsMsdc* dbsmsdc, const uint ixMsdcVCall, const ubigint jref, const uint ixInv, const ubigint refInv, const string& srefInv);
	bool triggerIxRefSrefIntvalCall(DbsMsdc* dbsmsdc, const uint ixMsdcVCall, const ubigint jref, const uint ixInv, const ubigint refInv, const string& srefInv, const int intvalInv);
	bool triggerIxRefSrefIntvalToRefCall(DbsMsdc* dbsmsdc, const uint ixMsdcVCall, const ubigint jref, const uint ixInv, const ubigint refInv, const string& srefInv, const int intvalInv, ubigint& refRet);
	bool triggerRefToIxCall(DbsMsdc* dbsmsdc, const uint ixMsdcVCall, const ubigint jref, const ubigint refInv, uint& ixRet);
	bool triggerSrefToRefCall(DbsMsdc* dbsmsdc, const uint ixMsdcVCall, const ubigint jref, const string& srefInv, ubigint& refRet);

	// dispatch collector list methods
	DcolMsdc* addDcol(const ubigint jref);
	DcolMsdc* getDcolByJref(const ubigint jref, const bool tree = true);
	void removeDcolByJref(const ubigint jref);
	void removeDcolsByJref(const ubigint jref);

	void submitDpch(DpchEngMsdc* dpcheng);
	DpchEngMsdc* pullFirstDpch(DcolMsdc* dcol);

	// job list methods
	ubigint addJob(JobMsdc* job);
	ubigint addMsjob(DbsMsdc* dbsmsdc, MsjobMsdc* job, const bool syncsge = false);

	JobMsdc* getJobByJref(const ubigint jref);

	void removeJobByJref(const ubigint jref);
	void removeMsjobByJref(const ubigint jref);

	// master/slave job methods
	void transferMsjobMaster(DbsMsdc* dbsmsdc, MsjobMsdc* fromjob, MsjobMsdc* tojob, Msjobinfo* msji);
	void offerMsjobMaster(DbsMsdc* dbsmsdc, const ubigint jref);
	bool claimMsjobMaster(DbsMsdc* dbsmsdc, const ubigint jref);

	bool getMsjobNotJob(const uint ixMsdcVJob);

	bool getMsjobMastNotSlv(MsjobMsdc* job);
	MsjobMsdc* getMsjobMaster(MsjobMsdc* job, const string& srefMember);

	void setMsjobStarted(DbsMsdc* dbsmsdc, MsjobMsdc* job, const bool srd);

	void setMsjobStage(DbsMsdc* dbsmsdc, MsjobMsdc* job, const uint ixVSge);

	// timer methods
	ubigint addWakeup(const ubigint jref, const string sref, const unsigned int deltat = 0, const bool weak = false);
	static void* runWakeup(void* arg);

	// external call methods
	static void runExtcall(void* arg);
};
#endif



