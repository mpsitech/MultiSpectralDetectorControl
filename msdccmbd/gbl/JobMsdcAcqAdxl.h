/**
  * \file JobMsdcAcqAdxl.h
  * job handler for job JobMsdcAcqAdxl (declarations)
  * \author Alexander Wirthmueller
  * \date created: 12 Sep 2018
  * \date modified: 12 Sep 2018
  */

#ifndef JOBMSDCACQADXL_H
#define JOBMSDCACQADXL_H

// IP custInclude --- INSERT

#include "JobMsdcSrcMsdd.h"
#include "JobMsdcSrcTrigger.h"

#define VecVJobMsdcAcqAdxlSge JobMsdcAcqAdxl::VecVSge
#define VecVJobMsdcAcqAdxlVar JobMsdcAcqAdxl::VecVVar

#define ShrdatJobMsdcAcqAdxl JobMsdcAcqAdxl::Shrdat

/**
  * JobMsdcAcqAdxl
  */
class JobMsdcAcqAdxl : public MsjobMsdc {

public:
	/**
		* VecVSge (full: VecVJobMsdcAcqAdxlSge)
		*/
	class VecVSge {

	public:
		static const uint IDLE = 1;
		static const uint RUN = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);

		static void fillFeed(Feed& feed);
	};

	/**
		* VecVVar (full: VecVJobMsdcAcqAdxlVar)
		*/
	class VecVVar {

	public:
		static const uint ALPHABETA = 1;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);

		static void fillFeed(Feed& feed);
	};

	/**
		* Shrdat (full: ShrdatJobMsdcAcqAdxl)
		*/
	class Shrdat : public ShrdatMsdc {

	public:
		// IP Shrdat.subs --- INSERT

	public:
		Shrdat();

	public:
		float alpha;
		float beta;
		// IP Shrdat.custVar --- INSERT

	public:
		void init(XchgMsdc* xchg, DbsMsdc* dbsmsdc);
		void term();
	};

public:
	JobMsdcAcqAdxl(XchgMsdc* xchg, DbsMsdc* dbsmsdc, const ubigint jrefSup, const uint ixMsdcVLocale, const bool prefmast);
	~JobMsdcAcqAdxl();

public:
	static Shrdat shrdat;

	JobMsdcSrcMsdd* srcmsdd;
	JobMsdcSrcTrigger* srctrigger;

	// IP specVar --- INSERT

	// IP custVar --- INSERT

public:
	// IP cust --- INSERT

public:
	// IP spec --- INSERT

public:
	void changeStage(DbsMsdc* dbsmsdc, uint _ixVSge);

	uint enterSgeIdle(DbsMsdc* dbsmsdc, const bool reenter);
	void leaveSgeIdle(DbsMsdc* dbsmsdc);
	uint enterSgeRun(DbsMsdc* dbsmsdc, const bool reenter);
	void leaveSgeRun(DbsMsdc* dbsmsdc);

	string getSquawk(DbsMsdc* dbsmsdc);

	void giveupMaster(DbsMsdc* dbsmsdc, Msjobinfo* msji);
	void giveupSlave(DbsMsdc* dbsmsdc, Msjobinfo* msji);
	void becomeMaster(DbsMsdc* dbsmsdc, Msjobinfo* msji);
	void becomeSlave(DbsMsdc* dbsmsdc, Msjobinfo* msji);

	bool handleClaimMaster(DbsMsdc* dbsmsdc, Msjobinfo* msji);

	void handleRequest(DbsMsdc* dbsmsdc, ReqMsdc* req);

	void handleCall(DbsMsdc* dbsmsdc, Call* call);

	bool handleCallMsdcTrig(DbsMsdc* dbsmsdc, const ubigint jrefTrig, const int intvalInv);
	bool handleCallMsdcMastsrdChg(DbsMsdc* dbsmsdc, const ubigint jrefTrig, const bool boolvalInv);
	bool handleCallMsdcShrdatChg(DbsMsdc* dbsmsdc, const ubigint jrefTrig, const uint ixInv, const string& srefInv);
};

#endif

