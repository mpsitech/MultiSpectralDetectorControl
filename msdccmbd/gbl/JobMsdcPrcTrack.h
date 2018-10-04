/**
  * \file JobMsdcPrcTrack.h
  * job handler for job JobMsdcPrcTrack (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Oct 2018
  * \date modified: 4 Oct 2018
  */

#ifndef JOBMSDCPRCTRACK_H
#define JOBMSDCPRCTRACK_H

// IP custInclude --- INSERT

#include "JobMsdcAcqVisl.h"
#include "JobMsdcActServo.h"
#include "JobMsdcActAlign.h"

#define VecVJobMsdcPrcTrackSge JobMsdcPrcTrack::VecVSge

#define ShrdatJobMsdcPrcTrack JobMsdcPrcTrack::Shrdat

/**
  * JobMsdcPrcTrack
  */
class JobMsdcPrcTrack : public MsjobMsdc {

public:
	/**
		* VecVSge (full: VecVJobMsdcPrcTrackSge)
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
		* Shrdat (full: ShrdatJobMsdcPrcTrack)
		*/
	class Shrdat : public ShrdatMsdc {

	public:
		// IP Shrdat.subs --- INSERT

	public:
		Shrdat();

	public:
		// IP Shrdat.custVar --- INSERT

	public:
		void init(XchgMsdc* xchg, DbsMsdc* dbsmsdc);
		void term();
	};

public:
	JobMsdcPrcTrack(XchgMsdc* xchg, DbsMsdc* dbsmsdc, const ubigint jrefSup, const uint ixMsdcVLocale, const bool prefmast);
	~JobMsdcPrcTrack();

public:
	static Shrdat shrdat;

	JobMsdcAcqVisl* acqvisl;
	JobMsdcActServo* actservo;
	JobMsdcActAlign* actalign;

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

};

#endif

