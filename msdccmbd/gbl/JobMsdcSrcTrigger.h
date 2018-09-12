/**
  * \file JobMsdcSrcTrigger.h
  * job handler for job JobMsdcSrcTrigger (declarations)
  * \author Alexander Wirthmueller
  * \date created: 12 Sep 2018
  * \date modified: 12 Sep 2018
  */

#ifndef JOBMSDCSRCTRIGGER_H
#define JOBMSDCSRCTRIGGER_H

// IP custInclude --- INSERT

#define VecVJobMsdcSrcTriggerSge JobMsdcSrcTrigger::VecVSge

#define StgJobMsdcSrcTrigger JobMsdcSrcTrigger::Stg

#define ShrdatJobMsdcSrcTrigger JobMsdcSrcTrigger::Shrdat

/**
  * JobMsdcSrcTrigger
  */
class JobMsdcSrcTrigger : public MsjobMsdc {

public:
	/**
		* VecVSge (full: VecVJobMsdcSrcTriggerSge)
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
		* Stg (full: StgJobMsdcSrcTrigger)
		*/
	class Stg : public Block {

	public:
		static const uint DT = 1;

	public:
		Stg(const float dt = 0.25);

	public:
		float dt;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const Stg* comp);
		set<uint> diff(const Stg* comp);
	};

	/**
		* Shrdat (full: ShrdatJobMsdcSrcTrigger)
		*/
	class Shrdat : public ShrdatMsdc {

	public:
		// IP Shrdat.subs --- INSERT

	public:
		Shrdat();

	public:
		// IP Shrdat.custVar --- IBEGIN
		unsigned int seqno;
		double t;
		// IP Shrdat.custVar --- IEND

	public:
		void init(XchgMsdc* xchg, DbsMsdc* dbsmsdc);
		void term();
	};

public:
	JobMsdcSrcTrigger(XchgMsdc* xchg, DbsMsdc* dbsmsdc, const ubigint jrefSup, const uint ixMsdcVLocale, const bool prefmast);
	~JobMsdcSrcTrigger();

public:
	static Stg stg;
	static Shrdat shrdat;

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

	void handleTimer(DbsMsdc* dbsmsdc, const string& sref);
	void handleCall(DbsMsdc* dbsmsdc, Call* call);

	bool handleCallMsdcTrig(DbsMsdc* dbsmsdc, const ubigint jrefTrig, const int intvalInv);
	bool handleCallMsdcMastsgeChg(DbsMsdc* dbsmsdc, const ubigint jrefTrig, const uint ixInv);
	bool handleCallMsdcMastsrdChg(DbsMsdc* dbsmsdc, const ubigint jrefTrig, const bool boolvalInv);
};

#endif



