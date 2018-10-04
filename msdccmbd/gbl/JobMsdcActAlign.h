/**
  * \file JobMsdcActAlign.h
  * job handler for job JobMsdcActAlign (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Oct 2018
  * \date modified: 4 Oct 2018
  */

#ifndef JOBMSDCACTALIGN_H
#define JOBMSDCACTALIGN_H

// IP custInclude --- INSERT

#include "JobMsdcSrcMsdd.h"

#define VecVJobMsdcActAlignFunction JobMsdcActAlign::VecVFunction
#define VecVJobMsdcActAlignMethod JobMsdcActAlign::VecVMethod
#define VecVJobMsdcActAlignSge JobMsdcActAlign::VecVSge

#define ShrdatJobMsdcActAlign JobMsdcActAlign::Shrdat

/**
  * JobMsdcActAlign
  */
class JobMsdcActAlign : public MsjobMsdc {

public:
	/**
		* VecVFunction (full: VecVJobMsdcActAlignFunction)
		*/
	class VecVFunction {

	public:
		static const uint CUST = 1;
		static const uint SIN = 2;
		static const uint SQR = 3;
		static const uint SWT = 4;
		static const uint TRI = 5;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);

		static string getTitle(const uint ix, const uint ixMsdcVLocale);

		static void appendToFeed(const uint ix, const uint ixMsdcVLocale, Feed& feed);
		static void fillFeed(const uint ixMsdcVLocale, Feed& feed);
	};

	/**
		* VecVMethod (full: VecVJobMsdcActAlignMethod)
		*/
	class VecVMethod {

	public:
		static const uint SETWAVE = 1;
		static const uint START = 2;
		static const uint STOP = 3;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);

		static void fillFeed(Feed& feed);
	};

	/**
		* VecVSge (full: VecVJobMsdcActAlignSge)
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
		* Shrdat (full: ShrdatJobMsdcActAlign)
		*/
	class Shrdat : public ShrdatMsdc {

	public:
		// IP Shrdat.subs --- INSERT

	public:
		Shrdat();

	public:
		// IP Shrdat.custVar --- IBEGIN
		vector<float> seq;
		// IP Shrdat.custVar --- IEND

	public:
		void init(XchgMsdc* xchg, DbsMsdc* dbsmsdc);
		void term();
	};

public:
	JobMsdcActAlign(XchgMsdc* xchg, DbsMsdc* dbsmsdc, const ubigint jrefSup, const uint ixMsdcVLocale, const bool prefmast);
	~JobMsdcActAlign();

public:
	static Shrdat shrdat;

	JobMsdcSrcMsdd* srcmsdd;

	// IP specVar --- INSERT

	// IP custVar --- IBEGIN
	static constexpr double pi = 3.14159265359;
	// IP custVar --- IEND

public:
	// IP cust --- INSERT

public:
	// IP spec --- INSERT

public:
	bool setWave(DbsMsdc* dbsmsdc, const uint ixVFunction, const utinyint N, const vector<float>& seq);

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

	bool handleCallMsdcMastsrdChg(DbsMsdc* dbsmsdc, const ubigint jrefTrig, const bool boolvalInv);
};

#endif




