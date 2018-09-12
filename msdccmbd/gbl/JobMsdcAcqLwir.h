/**
  * \file JobMsdcAcqLwir.h
  * job handler for job JobMsdcAcqLwir (declarations)
  * \author Alexander Wirthmueller
  * \date created: 12 Sep 2018
  * \date modified: 12 Sep 2018
  */

#ifndef JOBMSDCACQLWIR_H
#define JOBMSDCACQLWIR_H

// IP custInclude --- INSERT

#include "JobMsdcSrcMsdd.h"
#include "JobMsdcSrcTrigger.h"

#define VecVJobMsdcAcqLwirMethod JobMsdcAcqLwir::VecVMethod
#define VecVJobMsdcAcqLwirSge JobMsdcAcqLwir::VecVSge
#define VecVJobMsdcAcqLwirVar JobMsdcAcqLwir::VecVVar

#define StgJobMsdcAcqLwir JobMsdcAcqLwir::Stg

#define ShrdatJobMsdcAcqLwir JobMsdcAcqLwir::Shrdat

/**
  * JobMsdcAcqLwir
  */
class JobMsdcAcqLwir : public MsjobMsdc {

public:
	/**
		* VecVMethod (full: VecVJobMsdcAcqLwirMethod)
		*/
	class VecVMethod {

	public:
		static const uint SETOUTPUT = 1;
		static const uint START = 2;
		static const uint STOP = 3;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);

		static void fillFeed(Feed& feed);
	};

	/**
		* VecVSge (full: VecVJobMsdcAcqLwirSge)
		*/
	class VecVSge {

	public:
		static const uint IDLE = 1;
		static const uint READY = 2;
		static const uint WAITBUF = 3;
		static const uint ACQ = 4;
		static const uint PRCIDLE = 5;
		static const uint PRC = 6;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);

		static void fillFeed(Feed& feed);
	};

	/**
		* VecVVar (full: VecVJobMsdcAcqLwirVar)
		*/
	class VecVVar {

	public:
		static const uint SEQNOTGRAY16 = 1;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);

		static void fillFeed(Feed& feed);
	};

	/**
		* Stg (full: StgJobMsdcAcqLwir)
		*/
	class Stg : public Block {

	public:
		static const uint WIDTH = 1;
		static const uint HEIGHT = 2;
		static const uint HPIX = 3;
		static const uint SERNO = 4;
		static const uint A = 5;
		static const uint B = 6;
		static const uint IXMSDCVSQRGRP = 7;
		static const uint F = 8;
		static const uint FN = 9;
		static const uint K1 = 10;
		static const uint K2 = 11;
		static const uint P1 = 12;
		static const uint P2 = 13;
		static const uint K3 = 14;
		static const uint K4 = 15;
		static const uint K5 = 16;
		static const uint K6 = 17;

	public:
		Stg(const uint width = 160, const uint height = 120, const double hpix = 12, const string& serno = "", const double a = 0.05, const double b = 15000, const uint ixMsdcVSqrgrp = 0, const double f = 9, const double fn = 1.1, const double k1 = 0.0, const double k2 = 0.0, const double p1 = 0.0, const double p2 = 0.0, const double k3 = 0.0, const double k4 = 0.0, const double k5 = 0.0, const double k6 = 0.0);

	public:
		uint width;
		uint height;
		double hpix;
		string serno;
		double a;
		double b;
		uint ixMsdcVSqrgrp;
		double f;
		double fn;
		double k1;
		double k2;
		double p1;
		double p2;
		double k3;
		double k4;
		double k5;
		double k6;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const Stg* comp);
		set<uint> diff(const Stg* comp);
	};

	/**
		* Shrdat (full: ShrdatJobMsdcAcqLwir)
		*/
	class Shrdat : public ShrdatMsdc {

	public:
		// IP Shrdat.subs --- INSERT

	public:
		Shrdat();

	public:
		uint seqno;
		double t;
		vector<usmallint> gray16;
		// IP Shrdat.custVar --- IBEGIN

		uint ixMsdcVCamste;

		ExtcallMsdc* extcall;

		// camera data at full resolution, no orientation transform applied ; ping-pong buffer
		bool fill1Not0;
		bool read1Not0;

		unsigned short* gray0;
		uint gray0Tkst;
		usmallint gray0Min;
		usmallint gray0Max;

		unsigned short* gray1;
		uint gray1Tkst;
		usmallint gray1Min;
		usmallint gray1Max;

		// camera data at full resolution with orientation transform applied
		Imgbuf gray;
		// IP Shrdat.custVar --- IEND

	public:
		void init(XchgMsdc* xchg, DbsMsdc* dbsmsdc);
		void term();
	};

public:
	JobMsdcAcqLwir(XchgMsdc* xchg, DbsMsdc* dbsmsdc, const ubigint jrefSup, const uint ixMsdcVLocale, const bool prefmast);
	~JobMsdcAcqLwir();

public:
	static Stg stg;
	static Shrdat shrdat;

	JobMsdcSrcMsdd* srcmsdd;
	JobMsdcSrcTrigger* srctrigger;

	// IP specVar --- INSERT

	// IP custVar --- IBEGIN
	ubigint bref;

	unsigned int seqno;
	double t;

	vector<Snippet*> snippets;

	vector<usmallint> gray16; // data has to be equivalent to main snippet
	// IP custVar --- IEND

public:
	// IP cust --- IBEGIN
	static void MsddCallback(void* arg);
	unsigned int intavg(const unsigned int in, const unsigned int im, bool* rshs, const unsigned int rshsN);
	// IP cust --- IEND

public:
	// IP spec --- INSERT

public:
	bool setOutput(DbsMsdc* dbsmsdc, const uint ixMsdcVSqrgrp);

	void changeStage(DbsMsdc* dbsmsdc, uint _ixVSge);

	uint enterSgeIdle(DbsMsdc* dbsmsdc, const bool reenter);
	void leaveSgeIdle(DbsMsdc* dbsmsdc);
	uint enterSgeReady(DbsMsdc* dbsmsdc, const bool reenter);
	void leaveSgeReady(DbsMsdc* dbsmsdc);
	uint enterSgeWaitbuf(DbsMsdc* dbsmsdc, const bool reenter);
	void leaveSgeWaitbuf(DbsMsdc* dbsmsdc);
	uint enterSgeAcq(DbsMsdc* dbsmsdc, const bool reenter);
	void leaveSgeAcq(DbsMsdc* dbsmsdc);
	uint enterSgePrcidle(DbsMsdc* dbsmsdc, const bool reenter);
	void leaveSgePrcidle(DbsMsdc* dbsmsdc);
	uint enterSgePrc(DbsMsdc* dbsmsdc, const bool reenter);
	void leaveSgePrc(DbsMsdc* dbsmsdc);

	string getSquawk(DbsMsdc* dbsmsdc);

	void giveupMaster(DbsMsdc* dbsmsdc, Msjobinfo* msji);
	void giveupSlave(DbsMsdc* dbsmsdc, Msjobinfo* msji);
	void becomeMaster(DbsMsdc* dbsmsdc, Msjobinfo* msji);
	void becomeSlave(DbsMsdc* dbsmsdc, Msjobinfo* msji);

	bool handleClaimMaster(DbsMsdc* dbsmsdc, Msjobinfo* msji);

	void handleRequest(DbsMsdc* dbsmsdc, ReqMsdc* req);

	bool handleTest(DbsMsdc* dbsmsdc);

	void handleTimer(DbsMsdc* dbsmsdc, const string& sref);
	void handleCall(DbsMsdc* dbsmsdc, Call* call);

	bool handleCallMsdcBufrdy(DbsMsdc* dbsmsdc, const ubigint jrefTrig, const bool boolvalInv);
	bool handleCallMsdcIbitrdy(DbsMsdc* dbsmsdc, const ubigint jrefTrig, const ubigint refInv);
	bool handleCallMsdcTrig(DbsMsdc* dbsmsdc, const ubigint jrefTrig, const int intvalInv);
	bool handleCallMsdcMastsrdChg(DbsMsdc* dbsmsdc, const ubigint jrefTrig, const bool boolvalInv);
};

#endif



