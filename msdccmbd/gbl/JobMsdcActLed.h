/**
  * \file JobMsdcActLed.h
  * job handler for job JobMsdcActLed (declarations)
  * \author Alexander Wirthmueller
  * \date created: 29 Aug 2018
  * \date modified: 29 Aug 2018
  */

#ifndef JOBMSDCACTLED_H
#define JOBMSDCACTLED_H

// IP custInclude --- INSERT

#include "JobMsdcSrcMsdd.h"

#define VecVJobMsdcActLedMethod JobMsdcActLed::VecVMethod
#define VecVJobMsdcActLedVar JobMsdcActLed::VecVVar

#define ShrdatJobMsdcActLed JobMsdcActLed::Shrdat

/**
  * JobMsdcActLed
  */
class JobMsdcActLed : public MsjobMsdc {

public:
	/**
		* VecVMethod (full: VecVJobMsdcActLedMethod)
		*/
	class VecVMethod {

	public:
		static const uint SETFLOOD = 1;
		static const uint SETSPOT = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);

		static void fillFeed(Feed& feed);
	};

	/**
		* VecVVar (full: VecVJobMsdcActLedVar)
		*/
	class VecVVar {

	public:
		static const uint FLOODSPOT = 1;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);

		static void fillFeed(Feed& feed);
	};

	/**
		* Shrdat (full: ShrdatJobMsdcActLed)
		*/
	class Shrdat : public ShrdatMsdc {

	public:
		// IP Shrdat.subs --- INSERT

	public:
		Shrdat();

	public:
		float flood;
		float spot;
		// IP Shrdat.custVar --- INSERT

	public:
		void init(XchgMsdc* xchg, DbsMsdc* dbsmsdc);
		void term();
	};

public:
	JobMsdcActLed(XchgMsdc* xchg, DbsMsdc* dbsmsdc, const ubigint jrefSup, const uint ixMsdcVLocale, const bool prefmast);
	~JobMsdcActLed();

public:
	static Shrdat shrdat;

	JobMsdcSrcMsdd* srcmsdd;

	// IP specVar --- INSERT

	// IP custVar --- INSERT

public:
	// IP cust --- INSERT

public:
	// IP spec --- INSERT

public:
	bool setFlood(DbsMsdc* dbsmsdc, const float flood);
	bool setSpot(DbsMsdc* dbsmsdc, const float spot);

	void giveupMaster(DbsMsdc* dbsmsdc, Msjobinfo* msji);
	void giveupSlave(DbsMsdc* dbsmsdc, Msjobinfo* msji);
	void becomeMaster(DbsMsdc* dbsmsdc, Msjobinfo* msji);
	void becomeSlave(DbsMsdc* dbsmsdc, Msjobinfo* msji);

	bool handleClaimMaster(DbsMsdc* dbsmsdc, Msjobinfo* msji);

	void handleRequest(DbsMsdc* dbsmsdc, ReqMsdc* req);

	void handleCall(DbsMsdc* dbsmsdc, Call* call);

	bool handleCallMsdcMastsgeChg(DbsMsdc* dbsmsdc, const ubigint jrefTrig, const uint ixInv);
	bool handleCallMsdcShrdatChg(DbsMsdc* dbsmsdc, const ubigint jrefTrig, const uint ixInv, const string& srefInv);
};

#endif

