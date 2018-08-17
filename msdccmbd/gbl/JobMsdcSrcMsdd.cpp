/**
  * \file JobMsdcSrcMsdd.cpp
  * job handler for job JobMsdcSrcMsdd (implementation)
  * \author Alexander Wirthmueller
  * \date created: 15 Aug 2018
  * \date modified: 15 Aug 2018
  */

#ifdef MSDCCMBD
	#include <Msdccmbd.h>
#else
	#include <Msdcd.h>
#endif

#include "JobMsdcSrcMsdd.h"

#include "JobMsdcSrcMsdd_blks.cpp"

// IP Shrdat.subs --- IBEGIN
/******************************************************************************
 class JobMsdcSrcMsdd::Shrdat::Lwirdata
 ******************************************************************************/

JobMsdcSrcMsdd::Shrdat::Lwirdata::Lwirdata(
			unsigned char* buf0
			, void (*callback)(void*)
			, void* argCallback
		) {
	this->buf = buf0;

	this->callback = callback;
	this->argCallback = argCallback;

	this->cancel = false;
};
// IP Shrdat.subs --- IEND

/******************************************************************************
 class JobMsdcSrcMsdd::Shrdat
 ******************************************************************************/

JobMsdcSrcMsdd::Shrdat::Shrdat() : ShrdatMsdc("JobMsdcSrcMsdd", "Shrdat", "JobMsdcSrcMsdd::shrdat") {
};

void JobMsdcSrcMsdd::Shrdat::init(
			XchgMsdc* xchg
			, DbsMsdc* dbsmsdc
		) {
		// IP Shrdat.init --- IBEGIN
		try {
#ifdef FPGA_ZEDB
			fpga.init(stg.path);
#endif
#ifdef FPGA_BSS3
			fpga.init(stg.path, 5000000);
#endif
			fpga.rxtxdump = false;
			fpga.reset();

		} catch (DbeException e) {
			cout << e.err << endl;
		};

		excdump = false;

		t0 = Msdc::getNow();
		tkst0 = 0;

		lwir = 0;
		Mutex::init(&mLwir, true, "mLwir", "JobMsdcSrcMsdd::Shrdat", "init");
		// IP Shrdat.init --- IEND
};

void JobMsdcSrcMsdd::Shrdat::term() {
	// IP Shrdat.term --- IBEGIN
	fpga.term();

	Mutex::destroy(&mLwir, true, "mLwir", "JobMsdcSrcMsdd::Shrdat", "term");
	// IP Shrdat.term --- IEND
};

/******************************************************************************
 class JobMsdcSrcMsdd
 ******************************************************************************/

JobMsdcSrcMsdd::JobMsdcSrcMsdd(
			XchgMsdc* xchg
			, DbsMsdc* dbsmsdc
			, const ubigint jrefSup
			, const uint ixMsdcVLocale
			, const bool prefmast
		) : MsjobMsdc(xchg, VecMsdcVJob::JOBMSDCSRCMSDD, jrefSup, ixMsdcVLocale, prefmast) {

	jref = xchg->addMsjob(dbsmsdc, this);

	// IP constructor.cust1 --- INSERT

	// IP constructor.spec1 --- INSERT

	// IP constructor.cust2 --- INSERT

	// IP constructor.spec2 --- INSERT

	xchg->addClstn(VecMsdcVCall::CALLMSDCMASTSGECHG, jref, Clstn::VecVJobmask::MAST, 0, Arg(), Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
	
};

JobMsdcSrcMsdd::~JobMsdcSrcMsdd() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeMsjobByJref(jref);
};

// IP cust --- IBEGIN
void JobMsdcSrcMsdd::makeLwirPng(
			unsigned char* data
			, unsigned short min
			, unsigned short max
			, unsigned int frameno
		) {
	const int width = 160;
	const int height = 120;

	string path;
	FILE* fp;

	double scale;

	usmallint val;

	utinyint rval, gval, bval;

	unsigned char* imgdat;
	imgdat = new unsigned char[4*width*height];

	unsigned char** rowptr;
	rowptr = new unsigned char*[height];

	// vertical flip
	for (int i=0;i<height;i++) rowptr[i] = &(imgdat[4*width*(height-i-1)]);

	// AGC
	if (min == max) scale = 1.0;
	else scale = 255.0 / ((double) (max-min));

	// transform into RGB (8bit per channel)
	for (int i=0;i<(width*height);i++) {
		val = 256*data[2*i] + data[2*i+1];

		if (val < min) rval = 0x00;
		else if (val > max) rval = 0xFF;
		else rval = lround(scale * ((double) (val-min)));

		gval = rval;
		bval = rval;

		imgdat[4*i+1] = rval;
		imgdat[4*i+2] = gval;
		imgdat[4*i+3] = bval;
	};

	// --- write using libpng
	png_structp png_ptr;
	png_infop info_ptr;

	// open file
	path = "/home/root/bin/msdccmbd/lwir_" + to_string(frameno) + ".png";
	fp = fopen(path.c_str(), "wb");
	if (!fp) {
		cout << "error opening file" << endl;
		return;
	};

	// allocate structures
	png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
	info_ptr = png_create_info_struct(png_ptr);

	// set error handling
	setjmp(png_jmpbuf(png_ptr));

	// set up output control
	png_init_io(png_ptr, fp);

	// set file information
	png_set_IHDR(png_ptr, info_ptr, width, height, 8, PNG_COLOR_TYPE_RGB, PNG_INTERLACE_NONE, PNG_COMPRESSION_TYPE_DEFAULT, PNG_FILTER_TYPE_DEFAULT);

	// write file information
	png_write_info(png_ptr, info_ptr);

	// pack RGB into 3 bytes
	png_set_filler(png_ptr, 0, PNG_FILLER_BEFORE);

	// write image
	png_write_image(png_ptr, rowptr);

	// write rest of file
	png_write_end(png_ptr, info_ptr);

	fclose(fp);

	// clean up
	png_free_data(png_ptr, info_ptr, PNG_FREE_ALL, -1);

	delete[] imgdat;
	delete[] rowptr;
};

double JobMsdcSrcMsdd::radToDeg(
			double _rad
		) {
	return(180.0*_rad/pi);
};

void JobMsdcSrcMsdd::sync() {
	uint tkst;

	if (tkclksrc_getTkst(tkst)) {
		shrdat.t0 = Msdc::getNow();
		shrdat.tkst0 = tkst;
	};
};

// adxl
bool JobMsdcSrcMsdd::getAdxlAngles(
			float& alpha
			, float& beta
		) {
	float ax, ay, az;

	alpha = 0.0;
	beta = 0.0;

	if (!adxl_getAx(ax)) return false;
	if (!adxl_getAy(ay)) return false;
	if (!adxl_getAz(az)) return false;

	alpha = radToDeg(atan2(-ay, -az)) + 90.0 - stg.adxlAlpha0;
	beta = radToDeg(atan2(-ay, -ax)) + 90.0 - stg.adxlBeta0;

	return true;
};

// lwir
bool JobMsdcSrcMsdd::startLwir(
			unsigned char* buf0
			, void (*callback)(void*)
			, void* argCallback
		) {
	bool success = false;

	pthread_attr_t attr;

	if (getMastNotSlv()) {
		lockAccess("startLwir");

		if (Mutex::trylock(&shrdat.mLwir, "mLwir", "JobMsdcSrcMsdd", "startLwir") == 0) {
			success = (shrdat.lwir == 0);

			if (success) {
				sync();

				shrdat.lwirdata = Shrdat::Lwirdata(buf0, callback, argCallback);

				pthread_attr_init(&attr);
				pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

				pthread_create(&shrdat.lwir, &attr, &runLwir, (void*) xchg);
			};

			Mutex::unlock(&shrdat.mLwir, "mLwir", "JobMsdcSrcMsdd", "startLwir");
		};

		unlockAccess("startLwir");

	} else {
		JobMsdcSrcMsdd* master = (JobMsdcSrcMsdd*) lockMaster("startLwir");

		if (master) {
			success = master->startLwir(buf0, callback, argCallback);
			unlockMaster(master, "startLwir");
		};
	};

	return success;
};

void JobMsdcSrcMsdd::stopLwir() {
	if (getMastNotSlv()) {
		lockAccess("stopLwir");

		pthread_t oldLwir = shrdat.lwir; // original will be set 0 in the process

		if (oldLwir != 0) {
			Mutex::lock(&shrdat.mLwir, "mLwir", "JobMsdcSrcMsdd", "stopLwir");
			shrdat.lwirdata.cancel = true;
			Mutex::unlock(&shrdat.mLwir, "mLwir", "JobMsdcSrcMsdd", "stopLwir");

			pthread_join(oldLwir, NULL);
		};

		unlockAccess("stopLwir");

	} else {
		JobMsdcSrcMsdd* master = (JobMsdcSrcMsdd*) lockMaster("stopLwir");

		if (master) {
			master->stopLwir();
			unlockMaster(master, "stopLwir");
		};
	};
};

// trigger
bool JobMsdcSrcMsdd::setTriggerFps(
			const float fps
		) {
	return(trigger_setTfrm(1000.0/fps));
};

// DevMsdd methods available to the outside
// align
bool JobMsdcSrcMsdd::align_setSeq(
			vector<float>& seq
		) {
	bool success = false;

	if (seq.size() > 32) return false;
	for (unsigned int i=0;i<seq.size();i++) if ((seq[i] < 0.0) || (seq[i] > 1.0)) return false;

	size_t _seqlen = seq.size();
	unsigned char* _seq = new unsigned char[_seqlen];

	for (unsigned int i=0;i<seq.size();i++) _seq[i] = lround(((float) stg.alignMax) * (1.0-seq[i]));

	try {
		shrdat.fpga.align->setSeq(_seq, _seqlen);

		success = true;

	} catch (DbeException e) {
		if (shrdat.excdump) cout << e.err << endl;
	};

	delete[] _seq;

	return success;
};

// led
bool JobMsdcSrcMsdd::led_setTon15(
			const float ton15
		) {
	bool success = false;

	if ((ton15 < 0.0) || (ton15 > 1.0)) return false;

	try {
		shrdat.fpga.led->setTon15(lround(100.0*ton15));

		success = true;

	} catch (DbeException e) {
		if (shrdat.excdump) cout << e.err << endl;
	};

	return success;
};

bool JobMsdcSrcMsdd::led_setTon60(
			const float ton60
		) {
	bool success = false;

	if ((ton60 < 0.0) || (ton60 > 1.0)) return false;

	try {
		shrdat.fpga.led->setTon60(lround(100.0*ton60));

		success = true;

	} catch (DbeException e) {
		if (shrdat.excdump) cout << e.err << endl;
	};

	return success;
};

// lwirif

// servo
bool JobMsdcSrcMsdd::servo_setTheta(
			const float theta
		) {
	bool success = false;

	float _theta;

	_theta = stg.servoA * (theta-stg.servoTheta0);
	if ((_theta < -600.0) || (theta > 600.0)) return false;

	try {
		shrdat.fpga.servo->setTheta(lround(_theta));

		success = true;

	} catch (DbeException e) {
		if (shrdat.excdump) cout << e.err << endl;
	};

	return success;
};

bool JobMsdcSrcMsdd::servo_setPhi(
			const float phi
		) {
	bool success = false;

	float _phi;

	_phi = stg.servoA * (phi-stg.servoPhi0);
	if ((_phi < -600.0) || (phi > 600.0)) return false;

	try {
		shrdat.fpga.servo->setPhi(lround(_phi));

		success = true;

	} catch (DbeException e) {
		if (shrdat.excdump) cout << e.err << endl;
	};

	return success;
};

// state
bool JobMsdcSrcMsdd::state_get(
			utinyint& tixVZedbState
		) {
	bool success = false;

	try {
		shrdat.fpga.state->get(tixVZedbState);

		success = true;

	} catch (DbeException e) {
		if (shrdat.excdump) cout << e.err << endl;
	};

	return success;
};

// tkclksrc
bool JobMsdcSrcMsdd::tkclksrc_getTkst(
			uint& tkst
		) {
	bool success = false;

	try {
		shrdat.fpga.tkclksrc->getTkst(tkst);

		success = true;

	} catch (DbeException e) {
		if (shrdat.excdump) cout << e.err << endl;
	};

	return success;
};

// trigger
bool JobMsdcSrcMsdd::trigger_setRng(
			const bool rng
			, const bool btnNotTfrm
		) {
	bool success = false;

	try {
		shrdat.fpga.trigger->setRng(rng, btnNotTfrm);

		success = true;

	} catch (DbeException e) {
		if (shrdat.excdump) cout << e.err << endl;
	};

	return success;
};

bool JobMsdcSrcMsdd::trigger_setTdlyLwir(
			const float tdlyLwir
		) {
	bool success = false;

	if ((tdlyLwir < 0.0) || (tdlyLwir > 6553.5)) return false;

	try {
		shrdat.fpga.trigger->setTdlyLwir(lround(10.0*tdlyLwir));

		success = true;

	} catch (DbeException e) {
		if (shrdat.excdump) cout << e.err << endl;
	};

	return success;
};

bool JobMsdcSrcMsdd::trigger_setTdlyVisr(
			const float tdlyVisr
		) {
	bool success = false;

	if ((tdlyVisr < 0.0) || (tdlyVisr > 6553.5)) return false;

	try {
		shrdat.fpga.trigger->setTdlyVisr(lround(10.0*tdlyVisr));

		success = true;

	} catch (DbeException e) {
		if (shrdat.excdump) cout << e.err << endl;
	};

	return success;
};

// vga

// internal high-level methods
// lwir
void* JobMsdcSrcMsdd::runLwir(
			void* arg
		) {
	const size_t sizeBuf = 2*160*120;
	unsigned char* buf;

	unsigned char* trg;

	utinyint tixVBufstate;

	uint _tkst;
	usmallint _min, _max;

	size_t datalen;

	timespec deltat;

	// thread settings
	pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, 0);
	pthread_cleanup_push(&cleanupLwir, arg);

	try {
		// - prepare
		Mutex::lock(&shrdat.mLwir, "mLwir", "JobMsdcSrcMsdd", "runLwir[1]");

		try {
			lwiracq_setRng(true);

		} catch (DbeException e) {
			shrdat.lwirdata.cancel = true;
			shrdat.lwirdata.callback(shrdat.lwirdata.argCallback);
			Mutex::unlock(&shrdat.mLwir, "mLwir", "JobMsdcSrcMsdd", "runLwir[1]");

			throw;
		};

		Mutex::unlock(&shrdat.mLwir, "mLwir", "JobMsdcSrcMsdd", "runLwir[2]");

		// - loop
		while (true) {
			if (shrdat.lwirdata.cancel) break;

			lwiracq_getInfo(tixVBufstate, _tkst, _min, _max);

			if ((tixVBufstate == VecVMsddZedbLwiracqBufstate::ABUF) || (tixVBufstate == VecVMsddZedbLwiracqBufstate::BBUF)) {
				Mutex::lock(&shrdat.mLwir, "mLwir", "JobMsdcSrcMsdd", "runLwir[2]");

				try {
					buf = NULL;

					/// TODO: avoid malloc
					if (tixVBufstate == VecVMsddZedbLwiracqBufstate::ABUF) shrdat.fpga.readAbufFromLwiracq(sizeBuf, buf, datalen);
					else if (tixVBufstate == VecVMsddZedbLwiracqBufstate::BBUF) shrdat.fpga.readBbufFromLwiracq(sizeBuf, buf, datalen);

					if (shrdat.lwirdata.buf) {
						if (bigendian()) memcpy(shrdat.lwirdata.buf, buf, sizeBuf);
						else {
							for (unsigned int i=0;i<sizeBuf;i+=2) {
								shrdat.lwirdata.buf[i] = buf[i+1];
								shrdat.lwirdata.buf[i+1] = buf[i];
							};
						};

						shrdat.lwirdata.tkst = _tkst;
						shrdat.lwirdata.min = _min;
						shrdat.lwirdata.max = _max;

						// callback has to set shrdat.lwirdata.buf NULL if no data can be received
						shrdat.lwirdata.callback(shrdat.lwirdata.argCallback);
					};

					if (buf) delete[] buf;

				} catch (DbeException e) {
					Mutex::unlock(&shrdat.mLwir, "mLwir", "JobMsdcSrcMsdd", "runLwir[3]");

					continue;
				};

				Mutex::unlock(&shrdat.mLwir, "mLwir", "JobMsdcSrcMsdd", "runLwir[4]");

				// sleep for 1/9Hz - 11ms = 100ms
				deltat = {.tv_sec = 0, .tv_nsec = 100000000};
				nanosleep(&deltat, NULL);
			};

			// sleep for a millisecond
			deltat = {.tv_sec = 0, .tv_nsec = 1000000};
			nanosleep(&deltat, NULL);
		};

	} catch (DbeException e) {
		if (shrdat.excdump) cout << e.err << endl;
	};

	pthread_cleanup_pop(0);

	shrdat.lwir = 0;

	return NULL;
};

void JobMsdcSrcMsdd::cleanupLwir(
			void* arg
		) {
	Mutex::lock(&shrdat.mLwir, "mLwir", "JobMsdcSrcMsdd", "cleanupLwir");
	shrdat.lwir = 0;
	Mutex::unlock(&shrdat.mLwir, "mLwir", "JobMsdcSrcMsdd", "cleanupLwir");
};

// DevMsdd methods used internally
// adxl
bool JobMsdcSrcMsdd::adxl_getAx(
			float& ax
		) {
	bool success = false;

	smallint _ax;

	try {
		shrdat.fpga.adxl->getAx(_ax);

		ax = stg.adxlA * ((float) _ax);

		success = true;

	} catch (DbeException e) {
		if (shrdat.excdump) cout << e.err << endl;
	};

	return success;
};

bool JobMsdcSrcMsdd::adxl_getAy(
			float& ay
		) {
	bool success = false;

	smallint _ay;

	try {
		shrdat.fpga.adxl->getAy(_ay);

		ay = stg.adxlA * ((float) _ay);

		success = true;

	} catch (DbeException e) {
		if (shrdat.excdump) cout << e.err << endl;
	};

	return success;
};

bool JobMsdcSrcMsdd::adxl_getAz(
			float& az
		) {
	bool success = false;

	smallint _az;

	try {
		shrdat.fpga.adxl->getAz(_az);

		az = stg.adxlA * ((float) _az);

		success = true;

	} catch (DbeException e) {
		if (shrdat.excdump) cout << e.err << endl;
	};

	return success;
};

// lwiracq
bool JobMsdcSrcMsdd::lwiracq_setRng(
			const bool rng
		) {
	bool success = false;

	try {
		shrdat.fpga.lwiracq->setRng(rng);

		success = true;

	} catch (DbeException e) {
		if (shrdat.excdump) cout << e.err << endl;
	};

	return success;
};

bool JobMsdcSrcMsdd::lwiracq_getInfo(
			utinyint& tixVBufstate
			, uint& tkst
			, usmallint& min
			, usmallint& max
		) {
	bool success = false;

	try {
		shrdat.fpga.lwiracq->getInfo(tixVBufstate, tkst, min, max);

		success = true;

	} catch (DbeException e) {
		if (shrdat.excdump) cout << e.err << endl;
	};

	return success;
};

// trigger
bool JobMsdcSrcMsdd::trigger_setTfrm(
			const float Tfrm
		) {
	bool success = false;

	if ((Tfrm < 0.0) || (Tfrm > 6553.5)) return false;

	try {
		shrdat.fpga.trigger->setTfrm(lround(10.0*Tfrm));

		success = true;

	} catch (DbeException e) {
		if (shrdat.excdump) cout << e.err << endl;
	};

	return success;
};

// vgaacq
bool JobMsdcSrcMsdd::vgaacq_setRng(
			const bool rng
		) {
	bool success = false;

	try {
		shrdat.fpga.vgaacq->setRng(rng);

		success = true;

	} catch (DbeException e) {
		if (shrdat.excdump) cout << e.err << endl;
	};

	return success;
};

bool JobMsdcSrcMsdd::vgaacq_getInfo(
			utinyint& tixVBufstate
			, uint& tkst
		) {
	bool success = false;

	try {
		shrdat.fpga.vgaacq->getInfo(tixVBufstate, tkst);

		success = true;

	} catch (DbeException e) {
		if (shrdat.excdump) cout << e.err << endl;
	};

	return success;
};

// IP cust --- IEND
// IP spec --- INSERT

void JobMsdcSrcMsdd::changeStage(
			DbsMsdc* dbsmsdc
			, uint _ixVSge
		) {
	bool reenter = true;

	do {
		if (ixVSge != _ixVSge) {
			switch (ixVSge) {
				case VecVSge::NC: leaveSgeNc(dbsmsdc); break;
				case VecVSge::READY: leaveSgeReady(dbsmsdc); break;
			};

			setStage(dbsmsdc, _ixVSge);
			reenter = false;
			// IP changeStage.refresh1 --- INSERT
		};

		switch (_ixVSge) {
			case VecVSge::NC: _ixVSge = enterSgeNc(dbsmsdc, reenter); break;
			case VecVSge::READY: _ixVSge = enterSgeReady(dbsmsdc, reenter); break;
		};

		// IP changeStage.refresh2 --- INSERT
	} while (ixVSge != _ixVSge);
};

uint JobMsdcSrcMsdd::enterSgeNc(
			DbsMsdc* dbsmsdc
			, const bool reenter
		) {
	uint retval = VecVSge::NC;
	nextIxVSge = retval;
	// IP enterSgeNc --- INSERT
	return retval;
};

void JobMsdcSrcMsdd::leaveSgeNc(
			DbsMsdc* dbsmsdc
		) {
	// IP leaveSgeNc --- INSERT
};

uint JobMsdcSrcMsdd::enterSgeReady(
			DbsMsdc* dbsmsdc
			, const bool reenter
		) {
	uint retval = VecVSge::READY;
	nextIxVSge = retval;
	// IP enterSgeReady --- INSERT
	return retval;
};

void JobMsdcSrcMsdd::leaveSgeReady(
			DbsMsdc* dbsmsdc
		) {
	// IP leaveSgeReady --- INSERT
};

string JobMsdcSrcMsdd::getSquawk(
			DbsMsdc* dbsmsdc
		) {
	string retval;
	// IP getSquawk --- BEGIN
	retval = VecVSge::getSref(ixVSge);
	// IP getSquawk --- END
	return retval;
};

void JobMsdcSrcMsdd::giveupMaster(
			DbsMsdc* dbsmsdc
			, Msjobinfo* msji
		) {
	// IP giveupMaster --- INSERT
};

void JobMsdcSrcMsdd::giveupSlave(
			DbsMsdc* dbsmsdc
			, Msjobinfo* msji
		) {
	// IP giveupSlave --- INSERT
};

void JobMsdcSrcMsdd::becomeMaster(
			DbsMsdc* dbsmsdc
			, Msjobinfo* msji
		) {
	// IP becomeMaster --- INSERT
};

void JobMsdcSrcMsdd::becomeSlave(
			DbsMsdc* dbsmsdc
			, Msjobinfo* msji
		) {
	// IP becomeSlave --- INSERT
};

bool JobMsdcSrcMsdd::handleClaimMaster(
			DbsMsdc* dbsmsdc
			, Msjobinfo* msji
		) {
	bool retval = !prefmast;
	retval = true; // IP handleClaimMaster --- ILINE
	return retval;
};

void JobMsdcSrcMsdd::handleRequest(
			DbsMsdc* dbsmsdc
			, ReqMsdc* req
		) {
	if (req->ixVBasetype == ReqMsdc::VecVBasetype::CMD) {
		reqCmd = req;

		if (req->cmd == "cmdset") {
			cout << "\ttest" << endl;
		} else if (req->cmd == "test") {
			req->retain = handleTest(dbsmsdc);

		} else {
			cout << "\tinvalid command!" << endl;
		};

		if (!req->retain) reqCmd = NULL;

	} else if (req->ixVBasetype == ReqMsdc::VecVBasetype::REGULAR) {
	};
};

bool JobMsdcSrcMsdd::handleTest(
			DbsMsdc* dbsmsdc
		) {
	bool retval = false;
	// IP handleTest --- IBEGIN

	utinyint tixVBufstate;
	uint tkst;
	usmallint min, max;

	size_t reqlen = 2*160*120;

	unsigned char* data = new unsigned char[reqlen+2];
	size_t datalen;

	timespec deltat;

string s;

	try {
		// check alive test
		tkclksrc_getTkst(tkst);

		// 10 images from LWIR camera
		shrdat.fpga.lwiracq->setRng(true);
		cout << "setRng success!" << endl;

		cout << "waiting for first frame ..." << endl;
		tixVBufstate = VecVMsddZedbLwiracqBufstate::IDLE;
		while (tixVBufstate == VecVMsddZedbLwiracqBufstate::IDLE) {
			shrdat.fpga.lwiracq->getInfo(tixVBufstate, tkst, min, max);
			cout << "tixVBufstate=" << VecVMsddZedbLwiracqBufstate::getSref(tixVBufstate) << endl;
		};
		cout << "... success!" << endl;

		for (unsigned int i=0;i<10;i++) {
			cout << "fetching frame #" << i << " ..." << endl;

			tixVBufstate = VecVMsddZedbLwiracqBufstate::IDLE;
			while ((tixVBufstate != VecVMsddZedbLwiracqBufstate::ABUF) && (tixVBufstate != VecVMsddZedbLwiracqBufstate::BBUF)) {
				shrdat.fpga.lwiracq->getInfo(tixVBufstate, tkst, min, max);

				deltat = {.tv_sec = 0, .tv_nsec = 10000000};
				nanosleep(&deltat, NULL);
			};

			cout << "reading from "	<< VecVMsddZedbLwiracqBufstate::getSref(tixVBufstate) << endl;

			if (tixVBufstate == VecVMsddZedbLwiracqBufstate::ABUF) shrdat.fpga.readAbufFromLwiracq(reqlen, data, datalen);
			else if (tixVBufstate == VecVMsddZedbLwiracqBufstate::BBUF) shrdat.fpga.readBbufFromLwiracq(reqlen, data, datalen);

			cout << "... success! (datalen=" << datalen << ")" << endl;

			makeLwirPng(data, min, max, i);
		};

		shrdat.fpga.lwiracq->setRng(false);

		delete[] data;

		cout << "done!" << endl;
		cout << endl;

	} catch (DbeException e) {
		if (shrdat.excdump) cout << e.err << endl;
	};

	// IP handleTest --- IEND
	return retval;
};

void JobMsdcSrcMsdd::handleCall(
			DbsMsdc* dbsmsdc
			, Call* call
		) {
	if (call->ixVCall == VecMsdcVCall::CALLMSDCMASTSGECHG) {
		call->abort = handleCallMsdcMastsgeChg(dbsmsdc, call->jref, call->argInv.ix);
	};
};

bool JobMsdcSrcMsdd::handleCallMsdcMastsgeChg(
			DbsMsdc* dbsmsdc
			, const ubigint jrefTrig
			, const uint ixInv
		) {
	bool retval = false;
	// IP handleCallMsdcMastsgeChg --- IBEGIN
	setStage(dbsmsdc, ixInv);
	// IP handleCallMsdcMastsgeChg --- IEND
	return retval;
};




