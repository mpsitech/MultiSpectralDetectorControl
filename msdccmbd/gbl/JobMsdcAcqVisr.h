/**
  * \file JobMsdcAcqVisr.h
  * job handler for job JobMsdcAcqVisr (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Oct 2018
  * \date modified: 4 Oct 2018
  */

#ifndef JOBMSDCACQVISR_H
#define JOBMSDCACQVISR_H

// IP custInclude --- IBEGIN
#ifdef __linux__
	#include "Spinnaker.h"
	#include "SpinGenApi/SpinnakerGenApi.h"

	using namespace Spinnaker;
	using namespace Spinnaker::GenApi;
	using namespace Spinnaker::GenICam;
#endif

#ifdef __linux__
	#include <linux/videodev2.h>
#endif

#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#undef MAP_TYPE
#include <sys/types.h>

#include <jpeglib.h>
// IP custInclude --- IEND

#include "JobMsdcSrcTrigger.h"

#define VecVJobMsdcAcqVisrMethod JobMsdcAcqVisr::VecVMethod
#define VecVJobMsdcAcqVisrSge JobMsdcAcqVisr::VecVSge
#define VecVJobMsdcAcqVisrVar JobMsdcAcqVisr::VecVVar

#define StgJobMsdcAcqVisr JobMsdcAcqVisr::Stg

#define ShrdatJobMsdcAcqVisr JobMsdcAcqVisr::Shrdat

/**
  * JobMsdcAcqVisr
  */
class JobMsdcAcqVisr : public MsjobMsdc {

public:
	/**
		* VecVMethod (full: VecVJobMsdcAcqVisrMethod)
		*/
	class VecVMethod {

	public:
		static const uint SETFOCUS = 1;
		static const uint SETOUTPUT = 2;
		static const uint SETTINT = 3;
		static const uint START = 4;
		static const uint STOP = 5;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);

		static void fillFeed(Feed& feed);
	};

	/**
		* VecVSge (full: VecVJobMsdcAcqVisrSge)
		*/
	class VecVSge {

	public:
		static const uint IDLE = 1;
		static const uint READY = 2;
		static const uint ACQIDLE = 3;
		static const uint ACQ = 4;
		static const uint PRCIDLE = 5;
		static const uint PRC = 6;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);

		static void fillFeed(Feed& feed);
	};

	/**
		* VecVVar (full: VecVJobMsdcAcqVisrVar)
		*/
	class VecVVar {

	public:
		static const uint SEQNOTRGBX8GRAY8 = 1;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);

		static void fillFeed(Feed& feed);
	};

	/**
		* Stg (full: StgJobMsdcAcqVisr)
		*/
	class Stg : public Block {

	public:
		static const uint IXMSDCVCAMTYPE = 1;
		static const uint WIDTH = 2;
		static const uint HEIGHT = 3;
		static const uint HPIX = 4;
		static const uint PATH = 5;
		static const uint SERNO = 6;
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
		Stg(const uint ixMsdcVCamtype = 0, const uint width = 1280, const uint height = 720, const double hpix = 3, const string& path = "", const string& serno = "", const uint ixMsdcVSqrgrp = 0, const double f = 3, const double fn = 2, const double k1 = 0.0, const double k2 = 0.0, const double p1 = 0.0, const double p2 = 0.0, const double k3 = 0.0, const double k4 = 0.0, const double k5 = 0.0, const double k6 = 0.0);

	public:
		uint ixMsdcVCamtype;
		uint width;
		uint height;
		double hpix;
		string path;
		string serno;
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
		* Shrdat (full: ShrdatJobMsdcAcqVisr)
		*/
	class Shrdat : public ShrdatMsdc {

	public:
		// IP Shrdat.subs --- INSERT

	public:
		Shrdat();

	public:
		uint seqno;
		double t;
		vector<utinyint> rgbx8;
		vector<utinyint> gray8;
		// IP Shrdat.custVar --- IBEGIN

		uint ixMsdcVCamste;

#ifdef __linux__
		// Blackfly specific
		CameraPtr cam;
#endif

#ifdef __linux__
		// Lifecam specific
		int camfile;
		v4l2_buffer buf;
		void* cammmap;
#endif

		// JPEG specific
		jpeg_decompress_struct cinfo;
		jpeg_error_mgr jerr;

		unsigned char* jpegbuf;
		unsigned char** rowptrsJpegbuf;

		// camera data at full resolution, no orientation transform applied
		unsigned char* red0;
		unsigned char* green0;
		unsigned char* blue0;

		// camera data at full resolution with orientation transform applied
		Imgbuf rgb;
		// IP Shrdat.custVar --- IEND

	public:
		void init(XchgMsdc* xchg, DbsMsdc* dbsmsdc);
		void term();
	};

public:
	JobMsdcAcqVisr(XchgMsdc* xchg, DbsMsdc* dbsmsdc, const ubigint jrefSup, const uint ixMsdcVLocale, const bool prefmast);
	~JobMsdcAcqVisr();

public:
	static Stg stg;
	static Shrdat shrdat;

	JobMsdcSrcTrigger* srctrigger;

	// IP specVar --- INSERT

	// IP custVar --- IBEGIN
	ubigint bref;

	unsigned int seqno;
	double t;

	vector<Snippet*> snippets;
	// IP custVar --- IEND

public:
	// IP cust --- IBEGIN
	void changeCamtype(const uint ixMsdcVCamtype);
	void changeSqrgrp(const uint ixMsdcVSqrgrp);

	bool openBlackfly();
	bool openBlackfly_setNodeEnum(INodeMap& nodeMap, const string& key, const string& value);
	bool openBlackfly_setNodeInteger(INodeMap& nodeMap, const string& key, const int value);
	bool openBlackfly_setNodeFloat(INodeMap& nodeMap, const string& key, const float value);

	void closeBlackfly();

	vector<string> surveyBlackfly();

	bool openLifecam();
	bool openLifecam_setCtrl(const int id, const string& sref, const bool boolvalNotIntval, const int intval, const bool boolval);

	void closeLifecam();

	vector<string> surveyLifecam();

	// exact copy from Msdc but inline
	inline unsigned int intavg(const unsigned int in, const unsigned int im, bool* rshs, const unsigned int rshsN);
	// IP cust --- IEND

public:
	// IP spec --- INSERT

public:
	bool setFocus(DbsMsdc* dbsmsdc, const float focus);
	bool setOutput(DbsMsdc* dbsmsdc, const uint ixMsdcVCamres, const uint ixMsdcVSqrgrp, const bool grayscale);
	bool setTint(DbsMsdc* dbsmsdc, const float Tint);

	void changeStage(DbsMsdc* dbsmsdc, uint _ixVSge);

	uint enterSgeIdle(DbsMsdc* dbsmsdc, const bool reenter);
	void leaveSgeIdle(DbsMsdc* dbsmsdc);
	uint enterSgeReady(DbsMsdc* dbsmsdc, const bool reenter);
	void leaveSgeReady(DbsMsdc* dbsmsdc);
	uint enterSgeAcqidle(DbsMsdc* dbsmsdc, const bool reenter);
	void leaveSgeAcqidle(DbsMsdc* dbsmsdc);
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

	void handleTimer(DbsMsdc* dbsmsdc, const string& sref);
	void handleCall(DbsMsdc* dbsmsdc, Call* call);

	bool handleCallMsdcIbitrdy(DbsMsdc* dbsmsdc, const ubigint jrefTrig, const ubigint refInv);
	bool handleCallMsdcTrig(DbsMsdc* dbsmsdc, const ubigint jrefTrig, const int intvalInv);
	bool handleCallMsdcMastsrdChg(DbsMsdc* dbsmsdc, const ubigint jrefTrig, const bool boolvalInv);
};

#endif




