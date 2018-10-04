/**
  * \file JobMsdcSrcMsdd.h
  * job handler for job JobMsdcSrcMsdd (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Oct 2018
  * \date modified: 4 Oct 2018
  */

#ifndef JOBMSDCSRCMSDD_H
#define JOBMSDCSRCMSDD_H

// IP custInclude --- IBEGIN
#include <png.h>
// IP custInclude --- IEND

#define VecVJobMsdcSrcMsddSge JobMsdcSrcMsdd::VecVSge

#define StgJobMsdcSrcMsdd JobMsdcSrcMsdd::Stg

#define ShrdatJobMsdcSrcMsdd JobMsdcSrcMsdd::Shrdat

/**
  * JobMsdcSrcMsdd
  */
class JobMsdcSrcMsdd : public MsjobMsdc {

public:
	/**
		* VecVSge (full: VecVJobMsdcSrcMsddSge)
		*/
	class VecVSge {

	public:
		static const uint NC = 1;
		static const uint READY = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);

		static void fillFeed(Feed& feed);
	};

	/**
		* Stg (full: StgJobMsdcSrcMsdd)
		*/
	class Stg : public Block {

	public:
		static const uint PATH = 1;
		static const uint ADXLA = 2;
		static const uint ADXLALPHA0 = 3;
		static const uint ADXLBETA0 = 4;
		static const uint ALIGNMAX = 5;
		static const uint SERVOA = 6;
		static const uint SERVOTHETA0 = 7;
		static const uint SERVOPHI0 = 8;

	public:
		Stg(const string& path = "/dev/zedb", const float adxlA = 0.004, const float adxlAlpha0 = 0, const float adxlBeta0 = 0, const utinyint alignMax = 80, const float servoA = 8.889, const float servoTheta0 = 0, const float servoPhi0 = 0);

	public:
		string path;

		float adxlA;
		float adxlAlpha0;
		float adxlBeta0;

		utinyint alignMax;

		float servoA;
		float servoTheta0;
		float servoPhi0;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const Stg* comp);
		set<uint> diff(const Stg* comp);
	};

	/**
		* Shrdat (full: ShrdatJobMsdcSrcMsdd)
		*/
	class Shrdat : public ShrdatMsdc {

	public:
		// IP Shrdat.subs --- IBEGIN
		class Lwirdata {

		public:
			Lwirdata(unsigned char* buf0 = NULL, void (*callback)(void*) = NULL, void* argCallback = NULL);

		public:
			// passed as arguments to helper thread
			void (*callback)(void*);
			void* argCallback;

			// passed to helper thread while running
			bool cancel;

			unsigned char* buf;

			// updated by helper thread
			uint tkst;
			usmallint min;
			usmallint max;
		};
		// IP Shrdat.subs --- IEND

	public:
		Shrdat();

	public:
		// IP Shrdat.custVar --- IBEGIN
#ifdef FPGA_ZEDB
		UntMsddZedb fpga;
#endif
#ifdef FPGA_BSS3
		UntMsddBss3 fpga;
#endif

		bool excdump;

		// sync
		double t0;
		uint tkst0;

		// lwir functionality
		pthread_t lwir;
		Mutex mLwir;

		Lwirdata lwirdata;
		// IP Shrdat.custVar --- IEND

	public:
		void init(XchgMsdc* xchg, DbsMsdc* dbsmsdc);
		void term();
	};

public:
	JobMsdcSrcMsdd(XchgMsdc* xchg, DbsMsdc* dbsmsdc, const ubigint jrefSup, const uint ixMsdcVLocale, const bool prefmast);
	~JobMsdcSrcMsdd();

public:
	static Stg stg;
	static Shrdat shrdat;

	// IP specVar --- INSERT

	// IP custVar --- IBEGIN
	static constexpr double pi = 3.14159265359;
	// IP custVar --- IEND

public:
	// IP cust --- IBEGIN
	// high-level methods
	void makeLwirPng(unsigned char* data, unsigned short min, unsigned short max, unsigned int frameno);

	double radToDeg(double _rad);

	void sync();

	// adxl
	bool getAdxlAngles(float& alpha, float& beta); // adxlAlpha0 [°], adxlBeta0 [°]

	// lwir
	bool startLwir(unsigned char* buf0, void (*callback)(void*), void* argCallback);
	void stopLwir();

	static void setLwirBuf(unsigned char* buf);

	static void* runLwir(void* arg);
	static void cleanupLwir(void* arg);

	// trigger
	bool setTriggerFps(const float fps);

	// DevMsdd methods available to the outside
	// align
	bool align_setSeq(vector<float>& seq); // alignMin [LSB]

	// led
	bool led_setTon15(const float ton15);
	bool led_setTon60(const float ton60);

	// lwirif

	// servo
	bool servo_setTheta(const float theta); // servoTheta0 [°], servoA [ms/°]
	bool servo_setPhi(const float phi); // servoPhi0 [°]

	// state (ev. private)
	bool state_get(utinyint& tixVZedbState);

	// tkclksrc
	bool tkclksrc_getTkst(uint& tkst);

	// trigger
	bool trigger_setRng(const bool rng, const bool btnNotTfrm);
	bool trigger_setTdlyLwir(const float tdlyLwir);
	bool trigger_setTdlyVisr(const float tdlyVisr);

	// vga

private:
	// DevMsdd methods used internally
	// adxl
	static bool adxl_getAx(float& ax); // adxlA [g/LSB]
	static bool adxl_getAy(float& ay);
	static bool adxl_getAz(float& az);

	// lwiracq
	static bool lwiracq_setRng(const bool rng);
	static bool lwiracq_getInfo(utinyint& tixVBufstate, uint& tkst, usmallint& min, usmallint& max);

	// trigger
	static bool trigger_setTfrm(const float Tfrm);

	// vgaacq
	static bool vgaacq_setRng(const bool rng);
	static bool vgaacq_getInfo(utinyint& tixVBufstate, uint& tkst);
	// IP cust --- IEND

public:
	// IP spec --- INSERT

public:
	void changeStage(DbsMsdc* dbsmsdc, uint _ixVSge);

	uint enterSgeNc(DbsMsdc* dbsmsdc, const bool reenter);
	void leaveSgeNc(DbsMsdc* dbsmsdc);
	uint enterSgeReady(DbsMsdc* dbsmsdc, const bool reenter);
	void leaveSgeReady(DbsMsdc* dbsmsdc);

	string getSquawk(DbsMsdc* dbsmsdc);

	void giveupMaster(DbsMsdc* dbsmsdc, Msjobinfo* msji);
	void giveupSlave(DbsMsdc* dbsmsdc, Msjobinfo* msji);
	void becomeMaster(DbsMsdc* dbsmsdc, Msjobinfo* msji);
	void becomeSlave(DbsMsdc* dbsmsdc, Msjobinfo* msji);

	bool handleClaimMaster(DbsMsdc* dbsmsdc, Msjobinfo* msji);

	void handleRequest(DbsMsdc* dbsmsdc, ReqMsdc* req);

	bool handleTest(DbsMsdc* dbsmsdc);

	void handleCall(DbsMsdc* dbsmsdc, Call* call);

	bool handleCallMsdcMastsgeChg(DbsMsdc* dbsmsdc, const ubigint jrefTrig, const uint ixInv);
};

#endif




