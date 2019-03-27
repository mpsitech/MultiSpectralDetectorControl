/**
  * \file JobMsdcActServo.h
  * job handler for job JobMsdcActServo (declarations)
  * \author Alexander Wirthmueller
  * \date created: 18 Dec 2018
  * \date modified: 18 Dec 2018
  */

#ifndef JOBMSDCACTSERVO_H
#define JOBMSDCACTSERVO_H

// IP custInclude --- INSERT

#include "JobMsdcSrcMsdd.h"

#define VecVJobMsdcActServoMethod JobMsdcActServo::VecVMethod
#define VecVJobMsdcActServoVar JobMsdcActServo::VecVVar

#define StgJobMsdcActServo JobMsdcActServo::Stg

#define ShrdatJobMsdcActServo JobMsdcActServo::Shrdat

/**
  * JobMsdcActServo
  */
class JobMsdcActServo : public MsjobMsdc {

public:
	/**
		* VecVMethod (full: VecVJobMsdcActServoMethod)
		*/
	class VecVMethod {

	public:
		static const uint SETPHI = 1;
		static const uint SETTHETA = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);

		static void fillFeed(Feed& feed);
	};

	/**
		* VecVVar (full: VecVJobMsdcActServoVar)
		*/
	class VecVVar {

	public:
		static const uint THETAPHI = 1;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);

		static void fillFeed(Feed& feed);
	};

	/**
		* Stg (full: StgJobMsdcActServo)
		*/
	class Stg : public Block {

	public:
		static const uint PHIMIN = 1;
		static const uint PHIMAX = 2;
		static const uint THETAMIN = 3;
		static const uint THETAMAX = 4;

	public:
		Stg(const double phimin = -40, const double phimax = 40, const double thetamin = -40, const double thetamax = 15);

	public:
		double phimin;
		double phimax;
		double thetamin;
		double thetamax;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const Stg* comp);
		set<uint> diff(const Stg* comp);
	};

	/**
		* Shrdat (full: ShrdatJobMsdcActServo)
		*/
	class Shrdat : public ShrdatMsdc {

	public:
		// IP Shrdat.subs --- INSERT

	public:
		Shrdat();

	public:
		float theta;
		float phi;
		// IP Shrdat.custVar --- INSERT

	public:
		void init(XchgMsdc* xchg, DbsMsdc* dbsmsdc);
		void term();
	};

public:
	JobMsdcActServo(XchgMsdc* xchg, DbsMsdc* dbsmsdc, const ubigint jrefSup, const uint ixMsdcVLocale, const bool prefmast);
	~JobMsdcActServo();

public:
	static Stg stg;
	static Shrdat shrdat;

	JobMsdcSrcMsdd* srcmsdd;

	// IP specVar --- INSERT

	// IP custVar --- INSERT

public:
	// IP cust --- INSERT

public:
	// IP spec --- INSERT

public:
	bool setPhi(DbsMsdc* dbsmsdc, const float phi);
	bool setTheta(DbsMsdc* dbsmsdc, const float theta);

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

