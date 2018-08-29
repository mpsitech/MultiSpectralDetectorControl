/**
  * \file JobMsdcAcqVisr.cpp
  * job handler for job JobMsdcAcqVisr (implementation)
  * \author Alexander Wirthmueller
  * \date created: 29 Aug 2018
  * \date modified: 29 Aug 2018
  */

#ifdef MSDCCMBD
	#include <Msdccmbd.h>
#else
	#include <Msdcd.h>
#endif

#include "JobMsdcAcqVisr.h"

#include "JobMsdcAcqVisr_blks.cpp"

// IP Shrdat.subs --- INSERT

/******************************************************************************
 class JobMsdcAcqVisr::Shrdat
 ******************************************************************************/

JobMsdcAcqVisr::Shrdat::Shrdat() :
			ShrdatMsdc("JobMsdcAcqVisr", "Shrdat")
		{
};

void JobMsdcAcqVisr::Shrdat::init(
			XchgMsdc* xchg
			, DbsMsdc* dbsmsdc
		) {
	// IP Shrdat.init --- IBEGIN
	ixMsdcVCamste = VecMsdcVCamste::NC;

	seqno = 0;

#ifdef __linux__
	camfile = 0;
	buf = {};
	cammmap = NULL;
#endif

	cinfo.err = jpeg_std_error(&jerr);

	jpegbuf = NULL;
	rowptrsJpegbuf = NULL;

	red0 = NULL;
	green0 = NULL;
	blue0 = NULL;
	// IP Shrdat.init --- IEND
};

void JobMsdcAcqVisr::Shrdat::term() {
	// IP Shrdat.term --- IBEGIN
	if (jpegbuf) delete[] jpegbuf;
	if (rowptrsJpegbuf) delete[] rowptrsJpegbuf;

	if (red0) delete[] red0;
	if (green0) delete[] green0;
	if (blue0) delete[] blue0;
	// IP Shrdat.term --- IEND
};

/******************************************************************************
 class JobMsdcAcqVisr
 ******************************************************************************/

JobMsdcAcqVisr::JobMsdcAcqVisr(
			XchgMsdc* xchg
			, DbsMsdc* dbsmsdc
			, const ubigint jrefSup
			, const uint ixMsdcVLocale
			, const bool prefmast
		) :
			MsjobMsdc(xchg, VecMsdcVJob::JOBMSDCACQVISR, jrefSup, ixMsdcVLocale, prefmast)
		{

	jref = xchg->addMsjob(dbsmsdc, this);

	srctrigger = NULL;

	// IP constructor.cust1 --- INSERT

	// IP constructor.spec1 --- INSERT

	srctrigger = new JobMsdcSrcTrigger(xchg, dbsmsdc, jref, ixMsdcVLocale, true);

	// IP constructor.cust2 --- IBEGIN
	bref = 0;
	seqno = 0;
	t = 0.0;
	// IP constructor.cust2 --- IEND

	// IP constructor.spec2 --- INSERT

	xchg->addClstn(VecMsdcVCall::CALLMSDCIBITRDY, jref, Clstn::VecVJobmask::MAST, 0, Arg(), Clstn::VecVJactype::TRY);
	xchg->addClstn(VecMsdcVCall::CALLMSDCTRIG, jref, Clstn::VecVJobmask::IMM, 0, Arg(), Clstn::VecVJactype::TRY);
	xchg->addClstn(VecMsdcVCall::CALLMSDCMASTSRDCHG, jref, Clstn::VecVJobmask::SELF, 0, Arg(), Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecMsdcVCall::CALLMSDCMASTSRDCHG, jref, Clstn::VecVJobmask::SLV, 0, Arg(), Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
	
};

JobMsdcAcqVisr::~JobMsdcAcqVisr() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- IBEGIN
	shrdat.rgb.releaseByJref(jref);
	// IP destructor.cust --- IEND

	xchg->removeMsjobByJref(jref);
};

// IP cust --- IBEGIN
void JobMsdcAcqVisr::changeCamtype(
			const uint ixMsdcVCamtype
		) {
	if (getMastNotSlv()) {
		lockAccess("changeCamtype");

		if (ixVSge == VecVSge::IDLE) {
			if (stg.ixMsdcVCamtype != ixMsdcVCamtype) {
				stg.ixMsdcVCamtype = ixMsdcVCamtype;

				if (ixMsdcVCamtype == VecMsdcVCamtype::PGBFLY) {
					stg.width = 1280;
					stg.height = 960;
					stg.hpix = 3.75;
					stg.f = 6.0;
					stg.fn = 1.2;
				} else if (ixMsdcVCamtype == VecMsdcVCamtype::MSLIFE) {
					stg.width = 1280;
					stg.height = 720;
					stg.hpix = 3.0;
					stg.f = 3.0;
					stg.fn = 2.0;
				};

				if (shrdat.red0) {
					delete[] shrdat.red0; shrdat.red0 = NULL;
					delete[] shrdat.green0; shrdat.green0 = NULL;
					delete[] shrdat.blue0; shrdat.blue0 = NULL;
					shrdat.rgb.term();
				};
			};
		};

		unlockAccess("changeCamtype");

	} else {
		JobMsdcAcqVisr* master = (JobMsdcAcqVisr*) lockMaster("changeCamtype");

		if (master) {
			master->changeCamtype(ixMsdcVCamtype);
			unlockMaster(master, "changeCamtype");
		};
	};
};

void JobMsdcAcqVisr::changeSqrgrp(
			const uint ixMsdcVSqrgrp
		) {
	if (getMastNotSlv()) {
		lockAccess("changeSqrgrp");

		if (ixVSge == VecVSge::IDLE) {
			if (ixMsdcVSqrgrp != stg.ixMsdcVSqrgrp) {
				stg.ixMsdcVSqrgrp = ixMsdcVSqrgrp;
			};
		};

		unlockAccess("changeSqrgrp");

	} else {
		JobMsdcAcqVisr* master = (JobMsdcAcqVisr*) lockMaster("changeSqrgrp");

		if (master) {
			master->changeSqrgrp(ixMsdcVSqrgrp);
			unlockMaster(master, "changeSqrgrp");
		};
	};
};

bool JobMsdcAcqVisr::openBlackfly() {
#ifdef __linux__
	CameraList camList;

	bool valid;

	camList = xchg->shrdatJobprc.spinsys->GetCameras();
	shrdat.cam = camList.GetBySerial(stg.serno);
	camList.Clear();

	shrdat.cam->Init();

	INodeMap& nodeMap = shrdat.cam->GetNodeMap();
	INodeMap& nodeMapTLS = shrdat.cam->GetTLStreamNodeMap();

	// set hardware trigger
	valid = openBlackfly_setNodeEnum(nodeMap, "GainAuto", "Off");
	if (valid) valid = openBlackfly_setNodeEnum(nodeMap, "BalanceWhiteAuto", "Off");
	if (valid) valid = openBlackfly_setNodeEnum(nodeMap, "TriggerMode", "Off");
	if (valid) openBlackfly_setNodeEnum(nodeMap, "TriggerSource", "Line0");
	if (valid) valid = openBlackfly_setNodeEnum(nodeMap, "TriggerActivation", "RisingEdge");
	if (valid) valid = openBlackfly_setNodeEnum(nodeMap, "ExposureMode", "Timed");
	if (valid) valid = openBlackfly_setNodeEnum(nodeMap, "ExposureAuto", "Off");
	if (valid) valid = openBlackfly_setNodeFloat(nodeMap, "ExposureTime", 15000.0);
	if (valid) valid = openBlackfly_setNodeEnum(nodeMap, "LineSelector", "Line0");
	if (valid) openBlackfly_setNodeEnum(nodeMap, "LineMode", "Trigger");
//	if (valid) valid = openBlackfly_setNodeEnum(nodeMap, "TriggerMode", "On");

	// reduce bandwidth requirement
	if (valid) valid = openBlackfly_setNodeInteger(nodeMap, "GevSCPD", 10000);

	// standard BayerGR8 doesn't match the de-mosaic algorithm implemented in enterSgeAcq()
	if (valid) valid = openBlackfly_setNodeEnum(nodeMap, "PixelFormat", "YUV422Packed");

	// expect to drop many frames
	if (valid) valid = openBlackfly_setNodeEnum(nodeMapTLS, "StreamBufferCountMode", "Manual");
	if (valid) valid = openBlackfly_setNodeInteger(nodeMapTLS, "StreamBufferCountManual", 3);
	if (valid) valid = openBlackfly_setNodeEnum(nodeMapTLS, "StreamBufferHandlingMode", "NewestOnly");

	if (valid) shrdat.cam->BeginAcquisition();

	return valid;
#else
	return false;
#endif
};

bool JobMsdcAcqVisr::openBlackfly_setNodeEnum(
			INodeMap& nodeMap
			, const string& key
			, const string& value
		) {
#ifdef __linux__
	bool valid;

	CEnumerationPtr enumeration;
	CEnumEntryPtr enumEntry;

	enumeration = nodeMap.GetNode(key.c_str());
	valid = (IsAvailable(enumeration) && IsWritable(enumeration));

	if (valid) {
		enumEntry = enumeration->GetEntryByName(value.c_str());
		valid = (IsAvailable(enumEntry) && IsReadable(enumEntry));

		if (valid) enumeration->SetIntValue(enumEntry->GetValue());
		else cout << "enumeration value '" << value << "' not found for key '" << key << "'." << endl;

	} else {
		cout << "key '" << key << "' not found / not writeable." << endl;
	};

	return valid;
#else
	return false;
#endif
};

bool JobMsdcAcqVisr::openBlackfly_setNodeInteger(
			INodeMap& nodeMap
			, const string& key
			, const int value
		) {
#ifdef __linux__
	bool valid;

	CIntegerPtr integer;

	integer = nodeMap.GetNode(key.c_str());
	valid = (IsAvailable(integer) && IsWritable(integer));

	if (valid) integer->SetValue(value);
	else cout << "key '" << key << "' not found / not writeable." << endl;

	return valid;
#else
	return false;
#endif
};

bool JobMsdcAcqVisr::openBlackfly_setNodeFloat(
			INodeMap& nodeMap
			, const string& key
			, const float value
		) {
#ifdef __linux__
	bool valid;

	CFloatPtr _float;

	_float = nodeMap.GetNode(key.c_str());
	valid = (IsAvailable(_float) && IsWritable(_float));

	if (valid) _float->SetValue(value);
	else cout << "key '" << key << "' not found / not writeable." << endl;

	return valid;
#else
	return false;
#endif
};

void JobMsdcAcqVisr::closeBlackfly() {
#ifdef __linux__
	shrdat.cam->EndAcquisition();
	shrdat.cam->DeInit();
#endif
};

vector<string> JobMsdcAcqVisr::surveyBlackfly() {
	vector<string> sernos;

#ifdef __linux__
//	SystemPtr system = System::GetInstance();
	CameraList camList = xchg->shrdatJobprc.spinsys->GetCameras();

	CameraPtr cam = NULL;

	for (unsigned int i=0;i<camList.GetSize();i++) {
		cam = camList.GetByIndex(i);

		sernos.push_back(cam->TLDevice.DeviceSerialNumber.GetValue().c_str());
	};

	cam = NULL;

	camList.Clear();
//	system->ReleaseInstance();
#endif

	return sernos;
};

bool JobMsdcAcqVisr::openLifecam() {
#ifdef __linux__
	bool valid;

	v4l2_format fmt = {};
	v4l2_requestbuffers req = {};

	// open camera
	shrdat.camfile = open(stg.path.c_str(), O_RDWR);

	valid = (shrdat.camfile != -1);
	if (!valid) cout << "\terror connecting to camera!" << endl;

	if (valid) {
		// set image format
		fmt.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
		fmt.fmt.pix.width = stg.width;
		fmt.fmt.pix.height = stg.height;

		fmt.fmt.pix.pixelformat = V4L2_PIX_FMT_YUYV;
//		fmt.fmt.pix.pixelformat = V4L2_PIX_FMT_MJPEG;

		fmt.fmt.pix.field = V4L2_FIELD_NONE;

		while (true) {
			valid = (ioctl(shrdat.camfile, VIDIOC_S_FMT, &fmt) != -1);

			if (valid) break;

			if (errno != EINTR) {
				cout << "\terror setting image format!" << strerror(errno) << endl;
				break;
			};
		};
	};

	//if (valid) valid = openLifecam_setCtrl(V4L2_CID_PRIVATE_BASE+12, "white_balance_temperature_auto", true, 0, false);
	if (valid) valid = openLifecam_setCtrl(V4L2_CID_POWER_LINE_FREQUENCY, "power_line_frequency", false, V4L2_CID_POWER_LINE_FREQUENCY_50HZ, false);
	//if (valid) valid = openLifecam_setCtrl(V4L2_CID_BACKLIGHT_COMPENSATION, "backlight_compensation", false, 5, false);
	//if (valid) valid = openLifecam_setCtrl(V4L2_CID_EXPOSURE_AUTO, "exposure_auto", false, V4L2_EXPOSURE_MANUAL, false);
	//if (valid) valid = openLifecam_setCtrl(V4L2_CID_EXPOSURE_ABSOLUTE, "exposure_absolute", false, 100, false);
	if (valid) valid = openLifecam_setCtrl(V4L2_CID_FOCUS_AUTO, "focus_auto", true, 0, false);
	if (valid) valid = openLifecam_setCtrl(V4L2_CID_FOCUS_ABSOLUTE, "focus_absolute", false, 10, false);

	if (valid) {
		// request buffer
		req.count = 1;
		req.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
		req.memory = V4L2_MEMORY_MMAP;

		while (true) {
			valid = (ioctl(shrdat.camfile, VIDIOC_REQBUFS, &req) != -1);

			if (valid) break;

			if (errno != EINTR) {
				cout << "\terror requesting buffer!" << endl;
				break;
			};
		};
	};

	if (valid) {
		// map memory
		shrdat.buf.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
		shrdat.buf.memory = V4L2_MEMORY_MMAP;
		shrdat.buf.index = 0;

		while (true) {
			valid = (ioctl(shrdat.camfile, VIDIOC_QUERYBUF, &shrdat.buf) != -1);

			if (valid) {
				shrdat.cammmap = mmap(NULL, shrdat.buf.length, PROT_READ | PROT_WRITE, MAP_SHARED, shrdat.camfile, shrdat.buf.m.offset);
				break;
			};

			if (errno != EINTR) {
				cout << "\terror mapping memory!" << endl;
				break;
			};
		};
	};

	if (valid) {
		// initialize JPEG decompression
		shrdat.jpegbuf = new unsigned char[3*stg.width*stg.height];
		shrdat.rowptrsJpegbuf = new unsigned char*[stg.height];

		for (unsigned int i=0;i<stg.height;i++) shrdat.rowptrsJpegbuf[i] = &(shrdat.jpegbuf[3*stg.width*i]);
	};

	if (valid) {
		// start capture
		while (true) {
			valid = (ioctl(shrdat.camfile, VIDIOC_STREAMON, &shrdat.buf.type) != -1);

			if (valid) break;

			if (errno != EINTR) {
				cout << "\terror starting capture (" << strerror(errno) << ")!" << endl;
				break;
			};
		};
	};

	if (!valid && shrdat.cammmap) {
		munmap(shrdat.cammmap, shrdat.buf.length);
		shrdat.buf = {};
		shrdat.cammmap = NULL;
	};

	if (!valid && (shrdat.camfile != -1)) {
		close(shrdat.camfile);
		shrdat.camfile = 0;
	};

	if (!valid && shrdat.jpegbuf) {
		delete[] shrdat.jpegbuf;
		shrdat.jpegbuf = NULL;
	};

	if (!valid && shrdat.rowptrsJpegbuf) {
		delete[] shrdat.rowptrsJpegbuf;
		shrdat.rowptrsJpegbuf = NULL;
	};

	return valid;
#else
	return false;
#endif
};

bool JobMsdcAcqVisr::openLifecam_setCtrl(
			const int id
			, const string& sref
			, const bool boolvalNotIntval
			, const int intval
			, const bool boolval
		) {
#ifdef __linux__
	bool valid;

	v4l2_ext_controls ctrls = {};
	v4l2_ext_control ctrl = {};

	memset(&ctrls, 0, sizeof(ctrls));
	memset(&ctrl, 0, sizeof(ctrl));

	ctrl.id = id;
	if (boolvalNotIntval) ctrl.value = (int) boolval;
	else ctrl.value = intval;

	ctrls.ctrl_class = V4L2_CTRL_ID2CLASS(ctrl.id);
	ctrls.count = 1;
	ctrls.controls = &ctrl;

	while (true) {
		valid = (ioctl(shrdat.camfile, VIDIOC_S_EXT_CTRLS, &ctrls) != -1);

		if (valid) break;

		if (errno != EINTR) {
			cout << "\terror setting control parameter '" << sref << "'!" << endl;
			break;
		};
	};

	return valid;
#else
	return false;
#endif
};

void JobMsdcAcqVisr::closeLifecam() {
#ifdef __linux__
	if (shrdat.cammmap) {
		munmap(shrdat.cammmap, shrdat.buf.length);
		shrdat.buf = {};
		shrdat.cammmap = NULL;
	};

	if (shrdat.camfile != -1) {
		close(shrdat.camfile);
		shrdat.camfile = 0;
	};

	if (shrdat.jpegbuf) {
		delete[] shrdat.jpegbuf;
		shrdat.jpegbuf = NULL;
	};

	if (shrdat.rowptrsJpegbuf) {
		delete[] shrdat.rowptrsJpegbuf;
		shrdat.rowptrsJpegbuf = NULL;
	};
#endif
};

vector<string> JobMsdcAcqVisr::surveyLifecam() {
	vector<string> paths;

	DIR* dir = NULL;

	dirent* diritem = NULL;

	// identify camera devices at /dev/video*
	dir = opendir("/dev");

	if (dir) {
		diritem = readdir(dir);
		while (diritem) {
			if (diritem->d_type == DT_CHR) {
				if (strncmp(diritem->d_name, "video", 5) == 0) paths.push_back("/dev/" + string(diritem->d_name));
			};

			diritem = readdir(dir);
		};

		closedir(dir);
	};

	return paths;
};

// exact copy from Msdc.cpp but inline
inline unsigned int JobMsdcAcqVisr::intavg(
			const unsigned int in
			, const unsigned int im
			, bool* rshs
			, const unsigned int rshsN
		) {
	unsigned int retval = im*in;

	for (unsigned int i=0;i<rshsN;i++) if (rshs[i]) retval += (in >> (i+1));

	return retval;
};
// IP cust --- IEND
// IP spec --- INSERT
bool JobMsdcAcqVisr::setFocus(
			DbsMsdc* dbsmsdc
			, const float focus
		) {
	bool retval = true;

	if (getMastNotSlv()) {
		lockAccess("setFocus");

		// IP setFocus --- IBEGIN
		// IP setFocus --- IEND

		unlockAccess("setFocus");

	} else {
		JobMsdcAcqVisr* master = (JobMsdcAcqVisr*) lockMaster("setFocus");

		if (master) {
			master->setFocus(dbsmsdc, focus);
			unlockMaster(master, "setFocus");
		};
	};

	return retval;
};

bool JobMsdcAcqVisr::setOutput(
			DbsMsdc* dbsmsdc
			, const uint ixMsdcVCamres
			, const uint ixMsdcVSqrgrp
			, const bool grayscale
		) {
	bool retval = true;

	lockAccess("setOutput");

	// IP setOutput --- IBEGIN
	// IP setOutput --- IEND

	unlockAccess("setOutput");

	return retval;
};

bool JobMsdcAcqVisr::setTint(
			DbsMsdc* dbsmsdc
			, const float Tint
		) {
	bool retval = true;

	if (getMastNotSlv()) {
		lockAccess("setTint");

		// IP setTint --- IBEGIN
		// IP setTint --- IEND

		unlockAccess("setTint");

	} else {
		JobMsdcAcqVisr* master = (JobMsdcAcqVisr*) lockMaster("setTint");

		if (master) {
			master->setTint(dbsmsdc, Tint);
			unlockMaster(master, "setTint");
		};
	};

	return retval;
};

void JobMsdcAcqVisr::changeStage(
			DbsMsdc* dbsmsdc
			, uint _ixVSge
		) {
	bool reenter = true;

	do {
		if (ixVSge != _ixVSge) {
			switch (ixVSge) {
				case VecVSge::IDLE: leaveSgeIdle(dbsmsdc); break;
				case VecVSge::READY: leaveSgeReady(dbsmsdc); break;
				case VecVSge::ACQIDLE: leaveSgeAcqidle(dbsmsdc); break;
				case VecVSge::ACQ: leaveSgeAcq(dbsmsdc); break;
				case VecVSge::PRCIDLE: leaveSgePrcidle(dbsmsdc); break;
				case VecVSge::PRC: leaveSgePrc(dbsmsdc); break;
			};

			setStage(dbsmsdc, _ixVSge);
			reenter = false;
			// IP changeStage.refresh1 --- INSERT
		};

		switch (_ixVSge) {
			case VecVSge::IDLE: _ixVSge = enterSgeIdle(dbsmsdc, reenter); break;
			case VecVSge::READY: _ixVSge = enterSgeReady(dbsmsdc, reenter); break;
			case VecVSge::ACQIDLE: _ixVSge = enterSgeAcqidle(dbsmsdc, reenter); break;
			case VecVSge::ACQ: _ixVSge = enterSgeAcq(dbsmsdc, reenter); break;
			case VecVSge::PRCIDLE: _ixVSge = enterSgePrcidle(dbsmsdc, reenter); break;
			case VecVSge::PRC: _ixVSge = enterSgePrc(dbsmsdc, reenter); break;
		};

		// IP changeStage.refresh2 --- INSERT
	} while (ixVSge != _ixVSge);
};

uint JobMsdcAcqVisr::enterSgeIdle(
			DbsMsdc* dbsmsdc
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;
	nextIxVSge = retval;
	// IP enterSgeIdle --- IBEGIN

	if (getMastNotSlv()) {
		// close connection
		if (stg.ixMsdcVCamtype == VecMsdcVCamtype::PGBFLY) closeBlackfly();
		else if (stg.ixMsdcVCamtype == VecMsdcVCamtype::MSLIFE) closeLifecam();
	};

	shrdat.rgb.releaseByJref(jref);

	// IP enterSgeIdle --- IEND
	return retval;
};

void JobMsdcAcqVisr::leaveSgeIdle(
			DbsMsdc* dbsmsdc
		) {
	// IP leaveSgeIdle --- IBEGIN
	if (getMastNotSlv()) {
		shrdat.seqno = 0;

		// reset / initialize buffers
		if (!shrdat.red0) {
			shrdat.red0 = new unsigned char[stg.width*stg.height]; memset(shrdat.red0, 127, stg.width*stg.height);
			shrdat.green0 = new unsigned char[stg.width*stg.height]; memset(shrdat.green0, 127, stg.width*stg.height);
			shrdat.blue0 = new unsigned char[stg.width*stg.height]; memset(shrdat.blue0, 127, stg.width*stg.height);
			shrdat.rgb.init(8, 3*stg.width*stg.height*1);
		};

		// open connection
		if (stg.ixMsdcVCamtype == VecMsdcVCamtype::PGBFLY) openBlackfly();
		else if (stg.ixMsdcVCamtype == VecMsdcVCamtype::MSLIFE) openLifecam();
	};

	bref = 0;
	seqno = 0;
	t = 0.0;
	// IP leaveSgeIdle --- IEND
};

uint JobMsdcAcqVisr::enterSgeReady(
			DbsMsdc* dbsmsdc
			, const bool reenter
		) {
	uint retval = VecVSge::READY;
	nextIxVSge = retval;
	// IP enterSgeReady --- INSERT
	return retval;
};

void JobMsdcAcqVisr::leaveSgeReady(
			DbsMsdc* dbsmsdc
		) {
	// IP leaveSgeReady --- INSERT
};

uint JobMsdcAcqVisr::enterSgeAcqidle(
			DbsMsdc* dbsmsdc
			, const bool reenter
		) {
	uint retval = VecVSge::ACQIDLE;
	nextIxVSge = VecVSge::ACQ;

	wrefLast = xchg->addWakeup(jref, "callback", 0);
	// IP enterSgeAcqidle --- INSERT
	return retval;
};

void JobMsdcAcqVisr::leaveSgeAcqidle(
			DbsMsdc* dbsmsdc
		) {
	// IP leaveSgeAcqidle --- INSERT
};

uint JobMsdcAcqVisr::enterSgeAcq(
			DbsMsdc* dbsmsdc
			, const bool reenter
		) {
	uint retval = VecVSge::ACQ;
	nextIxVSge = retval;
	// IP enterSgeAcq --- IBEGIN
	// should only be invoked as master: get raw image data
	bool valid;

	Imgbufitem* ibit = NULL;

	utinyint* _r = NULL;
	utinyint* _g = NULL;
	utinyint* _b = NULL;

#ifdef __linux__
	// Blackfly specific
	ImagePtr resultImage;

	unsigned char* img;

	// Bayer specific
	unsigned int ipl;
#endif

#ifdef __linux__
	// Lifecam specific
	fd_set fds = {};

	timeval to = {};

	// Y'UV422 floating point version specific
	double y1, u, y2, v, d;

	// Y'UV422 integer version specific
//	int y1, u, y2, v, d;
#endif

	unsigned int ix, ix2;

	valid = false;

	if (stg.ixMsdcVCamtype == VecMsdcVCamtype::PGBFLY) {
#ifdef __linux__
		while (true) {
			resultImage = shrdat.cam->GetNextImage();
			valid = !resultImage->IsIncomplete();

			if (valid) {
				// GetBufferSize() should return 1280*960 = 1228800
				// GetPixelFormatName() should return YUV422Packed

				img = (unsigned char*) resultImage->GetData();

				// Y'UV422 floating point version
				for (unsigned int i=0;i<stg.height;i++) {
					for (unsigned int j=0;j<(stg.width/2);j++) {
						ix = 2* (i*stg.width+j*2);
						ix2 = i*stg.width+j*2;

						u = img[ix];
						y1 = img[ix+1];
						v = img[ix+2];
						y2 = img[ix+3];

						d = y1 + 1.402*(v-128.0); if (d < 0.0) d = 0.0; if (d > 255.0) d = 255.0;
						shrdat.red0[ix2] = lround(d);
						d = y1 - 0.344*(u-128.0) - 0.714*(v-128.0); if (d < 0.0) d = 0.0; if (d > 255.0) d = 255.0;
						shrdat.green0[ix2] = lround(d);
						d = y1 + 1.772*(u-128.0); if (d < 0.0) d = 0.0; if (d > 255.0) d = 255.0;
						shrdat.blue0[ix2] = lround(d);

						d = y2 + 1.402*(v-128.0); if (d < 0.0) d = 0.0; if (d > 255.0) d = 255.0;
						shrdat.red0[ix2+1] = lround(d);
						d = y2 - 0.344*(u-128.0) - 0.714*(v-128.0); if (d < 0.0) d = 0.0; if (d > 255.0) d = 255.0;
						shrdat.green0[ix2+1] = lround(d);
						d = y2 + 1.772*(u-128.0); if (d < 0.0) d = 0.0; if (d > 255.0) d = 255.0;
						shrdat.blue0[ix2+1] = lround(d);
					};
				};

/*
				for (unsigned int i=0;i<stg.height;i++) {
					for (unsigned int j=0;j<stg.width;j++) {
						ix = i*stg.width+j;

						// Bayer mosaic
						if ( ((i%2)==0) && ((j%2)==0) ) {
							shrdat.green0[ix] = img[ix];
						} else if ( ((i%2)==0) && ((j%2)==1) ) {
							shrdat.blue0[ix] = img[ix];
						} else if ( ((i%2)==1) && ((j%2)==0) ) {
							shrdat.red0[ix] = img[ix];
						} else if ( ((i%2)==1) && ((j%2)==1) ) {
							shrdat.green0[ix] = img[ix];
						};
					};
				};

				for (unsigned int i=0;i<stg.height;i++) {
					for (unsigned int j=0;j<stg.width;j++) {
						ix2 = i*stg.width+j;

						// bilinear de-mosaic
						if ( ((i%2)==0) && ((j%2)==0) ) {
							if ((i!=0) && (i!=(stg.height-1))) {
								ipl = (shrdat.red0[(i-1)*stg.width+j]+shrdat.red0[(i+1)*stg.width+j]) >> 1;
								shrdat.red0[ix2] = ipl;
							} else shrdat.red0[ix2] = 0;
							if ((j!=0) && (j!=(stg.width-1))) {
								ipl = (shrdat.blue0[i*stg.width+j-1]+shrdat.blue0[i*stg.width+j+1]) >> 1;
								shrdat.blue0[ix2] = ipl;
							} else shrdat.blue0[ix2] = 0;
						} else if ( ((i%2)==0) && ((j%2)==1) ) {
							if ((i!=0) && (i!=(stg.height-1)) && (j!=0) && (j!=(stg.width-1))) {
								ipl = (shrdat.red0[(i-1)*stg.width+j-1]+shrdat.red0[(i+1)*stg.width+j+1]+shrdat.red0[(i-1)*stg.width+j+1]+shrdat.red0[(i+1)*stg.width+j-1]) >> 2;
								shrdat.red0[ix2] = ipl;
							} else shrdat.red0[ix2] = 0;
							if ((i!=0) && (i!=(stg.height-1)) && (j!=0) && (j!=(stg.width-1))) {
								ipl = (shrdat.green0[(i-1)*stg.width+j]+shrdat.green0[(i+1)*stg.width+j]+shrdat.green0[i*stg.width+j-1]+shrdat.green0[i*stg.width+j+1]) >> 2;
								shrdat.green0[ix2] = ipl;
							} else shrdat.green0[ix2] = 0;
						} else if ( ((i%2)==1) && ((j%2)==0) ) {
							if ((i!=0) && (i!=(stg.height-1)) && (j!=0) && (j!=(stg.width-1))) {
								ipl = (shrdat.green0[(i-1)*stg.width+j]+shrdat.green0[(i+1)*stg.width+j]+shrdat.green0[i*stg.width+j-1]+shrdat.green0[i*stg.width+j+1]) >> 2;
								shrdat.green0[ix2] = ipl;
							} else shrdat.green0[ix2] = 0;
							if ((i!=0) && (i!=(stg.height-1)) && (j!=0) && (j!=(stg.width-1))) {
								ipl = (shrdat.blue0[(i-1)*stg.width+j-1]+shrdat.blue0[(i+1)*stg.width+j+1]+shrdat.blue0[(i-1)*stg.width+j+1]+shrdat.blue0[(i+1)*stg.width+j-1]) >> 2;
								shrdat.blue0[ix2] = ipl;
							} else shrdat.blue0[ix2] = 0;
						} else if ( ((i%2)==1) && ((j%2)==1) ) {
							if ((j!=0) && (j!=(stg.width-1))) {
								ipl = (shrdat.red0[i*stg.width+j-1]+shrdat.red0[i*stg.width+j+1]) >> 1;
								shrdat.red0[ix2] = ipl;
							} else shrdat.red0[ix2] = 0;
							if ((i!=0) && (i!=(stg.height-1))) {
								ipl = (shrdat.blue0[(i-1)*stg.width+j]+shrdat.blue0[(i+1)*stg.width+j]) >> 1;
								shrdat.blue0[ix2] = ipl;
							} else shrdat.blue0[ix2] = 0;
						};
					};
				};
*/
			};

			resultImage->Release();

			if (valid) break;
		};
#endif

	} else if (stg.ixMsdcVCamtype == VecMsdcVCamtype::MSLIFE) {
#ifdef __linux__
		FD_SET(shrdat.camfile, &fds);

		to.tv_sec = 1;

		// queue buffer
		while (true) {
			valid = (ioctl(shrdat.camfile, VIDIOC_QBUF, &shrdat.buf) != -1);

			if (valid) break;

			if (errno != EINTR) {
				cout << "\terror queuing buffer at image #" << shrdat.seqno << endl;
				break;
			};
		};

		if (valid) {
			valid = (select(shrdat.camfile+1, &fds, NULL, NULL, &to) != -1);
			if (!valid) cout << "\ttimeout waiting for image #" << shrdat.seqno << endl;
		};

		if (valid) {
			// de-queue buffer
			while (true) {
				valid = (ioctl(shrdat.camfile, VIDIOC_DQBUF, &shrdat.buf) != -1);

				if (valid) {
					// update shrdat.red0, shrdat.green0, shrdat.blue0

					// Y'UV422 floating point version
					for (unsigned int i=0;i<stg.height;i++) {
						for (unsigned int j=0;j<(stg.width/2);j++) {
							ix = 2* (i*stg.width+j*2);
							ix2 = i*stg.width+j*2;

							// non-standard order
							y1 = ((unsigned char*) shrdat.cammmap)[ix];
							u = ((unsigned char*) shrdat.cammmap)[ix+1];
							y2 = ((unsigned char*) shrdat.cammmap)[ix+2];
							v = ((unsigned char*) shrdat.cammmap)[ix+3];

							d = y1 + 1.402*(v-128.0); if (d < 0.0) d = 0.0; if (d > 255.0) d = 255.0;
							shrdat.red0[ix2] = lround(d);
							d = y1 - 0.344*(u-128.0) - 0.714*(v-128.0); if (d < 0.0) d = 0.0; if (d > 255.0) d = 255.0;
							shrdat.green0[ix2] = lround(d);
							d = y1 + 1.772*(u-128.0); if (d < 0.0) d = 0.0; if (d > 255.0) d = 255.0;
							shrdat.blue0[ix2] = lround(d);

							d = y2 + 1.402*(v-128.0); if (d < 0.0) d = 0.0; if (d > 255.0) d = 255.0;
							shrdat.red0[ix2+1] = lround(d);
							d = y2 - 0.344*(u-128.0) - 0.714*(v-128.0); if (d < 0.0) d = 0.0; if (d > 255.0) d = 255.0;
							shrdat.green0[ix2+1] = lround(d);
							d = y2 + 1.772*(u-128.0); if (d < 0.0) d = 0.0; if (d > 255.0) d = 255.0;
							shrdat.blue0[ix2+1] = lround(d);
						};
					};

/*
					// Y'UV422 integer version

					for (unsigned int i=0;i<stg.height;i++) {
						for (unsigned int j=0;j<(stg.width/2);j++) {
							ix = 2* (i*stg.width+j*2);
							ix2 = i*stg.width+j*2;

							y1 = ((unsigned char*) shrdat.cammmap)[ix];
							u = ((unsigned char*) shrdat.cammmap)[ix+1];
							y2 = ((unsigned char*) shrdat.cammmap)[ix+2];
							v = ((unsigned char*) shrdat.cammmap)[ix+3];

							v -= 128;
							u -= 128;

							d = y1 + v + (v >> 2) + (v >> 3) + (v >> 5); if (d < 0) d = 0; if (d > 255) d = 255;
							shrdat.red0[ix2] = d;
							d = y1 - ((u >> 2) + (u >> 4) + (u >> 5)) - ((v >> 1) + (v >> 3) + (v >> 4) + (v >> 5)); if (d < 0) d = 0; if (d > 255) d = 255;
							shrdat.green0[ix2] = d;
							d = y1 + u + (u >> 1) + (u >> 2) + (u >> 6); if (d < 0) d = 0; if (d > 255) d = 255;
							shrdat.blue0[ix2] = d;
							
							d = y2 + v + (v >> 2) + (v >> 3) + (v >> 5); if (d < 0) d = 0; if (d > 255) d = 255;
							shrdat.red0[ix2+1] = d;
							d = y2 - ((u >> 2) + (u >> 4) + (u >> 5)) - ((v >> 1) + (v >> 3) + (v >> 4) + (v >> 5)); if (d < 0) d = 0; if (d > 255) d = 255;
							shrdat.green0[ix2+1] = d;
							d = y2 + u + (u >> 1) + (u >> 2) + (u >> 6); if (d < 0) d = 0; if (d > 255) d = 255;
							shrdat.blue0[ix2+1] = d;
						};
					};
*/

/*
					// JPEG to RGB

					jpeg_create_decompress(&shrdat.cinfo);
					jpeg_mem_src(&shrdat.cinfo, (unsigned char*) shrdat.cammmap, shrdat.buf.bytesused);

					valid = (jpeg_read_header(&shrdat.cinfo, true) == 1);
					if (!valid) {
						cout << "\tno valid JPEG header was detected" << endl;
						break;
					};

					jpeg_start_decompress(&shrdat.cinfo);

					valid = ((shrdat.cinfo.output_width == stg.width) && (shrdat.cinfo.output_height == stg.height) && (shrdat.cinfo.output_components == 3));
					if (!valid) {
						cout << "\twrong JPEG frame size" << endl;
						break;
					};

					for (unsigned int i=0;i<stg.height;i++) {
						valid = (jpeg_read_scanlines(&shrdat.cinfo, &(shrdat.rowptrsJpegbuf[i]), 1) == 1);

						if (!valid) {
							cout << "\terror reading JPEG scan line " << i << endl;
							break;
						};
					};

					if (!valid) break;

					ix = 0;
					ix2 = 0;

					for (unsigned int i=0;i<stg.height;i++) {
						for (unsigned int j=0;j<stg.width;j++) {
							shrdat.red0[ix2] = shrdat.jpegbuf[ix];
							shrdat.green0[ix2] = shrdat.jpegbuf[ix+1];
							shrdat.blue0[ix2] = shrdat.jpegbuf[ix+2];

							ix += 3;
							ix2 += 1;
						};
					};

					jpeg_finish_decompress(&shrdat.cinfo);
					jpeg_destroy_decompress(&shrdat.cinfo);
*/

					break;
				};

				if (errno != EINTR) {
					cout << "\terror de-queuing buffer at image #" << shrdat.seqno << endl;
					break;
				};
			};
		};
#endif
	};

	// - prepare for processing
	bref = 0;

	if (valid) {
		// obtain available slot in shrdat.rgb
		bref = shrdat.rgb.getNewItem(jref, shrdat.seqno, 0.0); // seqno from trigger, timestamp generated at this time
		valid = (bref != 0);
	};

	if (valid) {
		ibit = shrdat.rgb.getItem(bref);

		// shrdat.red0/shrdat.green0/shrdat.blue0 -> ibit
		_r = ibit->data;
		_g = &(ibit->data[stg.width*stg.height]);
		_b = &(ibit->data[2*stg.width*stg.height]);

		// apply orientation transform (r0, r2, s0, s2 are allowed)
		Msdc::copytrfBuf(shrdat.red0, _r, 1, stg.width, stg.height, stg.ixMsdcVSqrgrp);
		Msdc::copytrfBuf(shrdat.green0, _g, 1, stg.width, stg.height, stg.ixMsdcVSqrgrp);
		Msdc::copytrfBuf(shrdat.blue0, _b, 1, stg.width, stg.height, stg.ixMsdcVSqrgrp);

		// spread the news
		xchg->triggerRefCall(dbsmsdc, VecMsdcVCall::CALLMSDCIBITRDY, jref, bref);

		if (!srd) retval = VecVSge::READY;
		else retval = VecVSge::PRC;

	} else {
		retval = VecVSge::READY;
	};

	if ((bref != 0) && (retval != VecVSge::PRC)) shrdat.rgb.release(bref, jref);

	// IP enterSgeAcq --- IEND
	return retval;
};

void JobMsdcAcqVisr::leaveSgeAcq(
			DbsMsdc* dbsmsdc
		) {
	// IP leaveSgeAcq --- INSERT
};

uint JobMsdcAcqVisr::enterSgePrcidle(
			DbsMsdc* dbsmsdc
			, const bool reenter
		) {
	uint retval = VecVSge::PRCIDLE;
	nextIxVSge = VecVSge::PRC;

	wrefLast = xchg->addWakeup(jref, "callback", 0);
	// IP enterSgePrcidle --- INSERT
	return retval;
};

void JobMsdcAcqVisr::leaveSgePrcidle(
			DbsMsdc* dbsmsdc
		) {
	// IP leaveSgePrcidle --- INSERT
};

uint JobMsdcAcqVisr::enterSgePrc(
			DbsMsdc* dbsmsdc
			, const bool reenter
		) {
	uint retval = VecVSge::PRC;
	nextIxVSge = retval;
	// IP enterSgePrc --- IBEGIN

	bool valid;

	Imgbufitem* ibit = NULL;

	utinyint* _r = NULL;
	utinyint* _g = NULL;
	utinyint* _b = NULL;
	utinyint* src = NULL;

	Snippet* snippet = NULL;

	unsigned int wlen;

	unsigned int w, h, wh;

	unsigned int mult;

	unsigned int x0, y0;

	unsigned int cpyw, cpyh;

	unsigned int sum;

	unsigned int im;
	unsigned int rshsN;
	bool rshs[16];

	unsigned int ix;

	ibit = shrdat.rgb.getItem(bref);
	valid = (ibit != NULL);

	if (valid) {
		for (unsigned int i=0;i<snippets.size();i++) {
			valid = snippets[i]->claim(jref);

			if (!valid) {
				for (unsigned int j=0;j<i;j++) snippets[j]->release();
				break;
			};
		};
	};

	if (valid) {
		seqno = ibit->seqno;
		t = ibit->t;

		_r = ibit->data;
		_g = &(ibit->data[stg.width*stg.height]);
		_b = &(ibit->data[2*stg.width*stg.height]);

		for (unsigned int m=0;m<snippets.size();m++) {
			snippet = snippets[m];

			if (snippet->ixMsdcVChannel == VecMsdcVChannel::RED8) src = _r;
			else if (snippet->ixMsdcVChannel == VecMsdcVChannel::GREEN8) src = _g;
			else if (snippet->ixMsdcVChannel == VecMsdcVChannel::BLUE8) src = _b;

			wlen = 1;

			// determine integer scaling factor
			Msdc::getCamresWh(snippet->ixMsdcVCamres, w, h, stg.width, stg.height);
			wh = w*h;

			mult = 1;
			while (((mult*w+16) < stg.width) && ((mult*h+12) < stg.height)) mult++;

			// - padding in coordinates of (non-scaled) raw image
			x0 = snippet->x0*mult;
			y0 = snippet->y0*mult;

			cpyw = snippet->w;
			cpyh = snippet->h;

			if ((x0 + mult*cpyw) > stg.width) cpyw = (stg.width-x0)/mult;
			if ((y0 + mult*cpyh) > stg.height) cpyh = (stg.height-y0)/mult;

			// border to the right
			if (cpyw < snippet->w) for (unsigned int i=0;i<cpyh;i++) memset((void*) &(snippet->data[wlen*(i*snippet->w+cpyw)]), 127, wlen*(snippet->w-cpyw));

			// border below
			if (cpyh < snippet->h) memset((void*) &(snippet->data[wlen*(snippet->w*cpyh)]), 127, wlen*(snippet->w*(snippet->h-cpyh)));

			if ((mult == 1) && (cpyw == stg.width) && (cpyh == stg.height)) {
				// straight copy in case of exact overlap
				if ((snippet->ixMsdcVChannel == VecMsdcVChannel::RED8) || (snippet->ixMsdcVChannel == VecMsdcVChannel::GREEN8) || (snippet->ixMsdcVChannel == VecMsdcVChannel::BLUE8)) {
					memcpy(snippet->data, src, wh);
				};

			} else {
				if ((snippet->ixMsdcVChannel == VecMsdcVChannel::RED8) || (snippet->ixMsdcVChannel == VecMsdcVChannel::GREEN8) || (snippet->ixMsdcVChannel == VecMsdcVChannel::BLUE8)) {
					rshsN = 16;
					Msdc::setupIntavg(mult*mult, 255, 255, 0.999, im, rshs, rshsN);

					for (unsigned int i=0;i<cpyh;i++) {
						for (unsigned int j=0;j<cpyw;j++) {
							sum = 0;

							for (unsigned int k=0;k<mult;k++) {
								for (unsigned int l=0;l<mult;l++) {
									ix = (y0+mult*i+k)*stg.width + (x0+mult*j+l);

									sum += src[ix];
								};
							};

							snippet->data[i*snippet->w+j] = intavg(sum, im, rshs, rshsN);
						};
					};
				};
			};

			snippet->release();
		};

		if (snippets.size() > 0) xchg->triggerCall(dbsmsdc, VecMsdcVCall::CALLMSDCIMGRDY, jref);
	};

	if (ibit) shrdat.rgb.release(bref, jref);

	retval = VecVSge::READY;

	// IP enterSgePrc --- IEND
	return retval;
};

void JobMsdcAcqVisr::leaveSgePrc(
			DbsMsdc* dbsmsdc
		) {
	// IP leaveSgePrc --- INSERT
};

string JobMsdcAcqVisr::getSquawk(
			DbsMsdc* dbsmsdc
		) {
	string retval;
	// IP getSquawk --- BEGIN
	retval = VecVSge::getSref(ixVSge);
	// IP getSquawk --- END
	return retval;
};

void JobMsdcAcqVisr::giveupMaster(
			DbsMsdc* dbsmsdc
			, Msjobinfo* msji
		) {
	// IP giveupMaster --- INSERT
};

void JobMsdcAcqVisr::giveupSlave(
			DbsMsdc* dbsmsdc
			, Msjobinfo* msji
		) {
	// IP giveupSlave --- INSERT
};

void JobMsdcAcqVisr::becomeMaster(
			DbsMsdc* dbsmsdc
			, Msjobinfo* msji
		) {
	if ((ixVSge == VecVSge::IDLE) && !msji->jrefsSrd.empty()) ixVSge = VecVSge::READY; // IP becomeMaster --- ILINE
};

void JobMsdcAcqVisr::becomeSlave(
			DbsMsdc* dbsmsdc
			, Msjobinfo* msji
		) {
	if ((ixVSge != VecVSge::IDLE) && !srd) ixVSge = VecVSge::IDLE; // IP becomeSlave --- ILINE
};

bool JobMsdcAcqVisr::handleClaimMaster(
			DbsMsdc* dbsmsdc
			, Msjobinfo* msji
		) {
	bool retval = !prefmast;
	retval = true; // IP handleClaimMaster --- ILINE
	return retval;
};

void JobMsdcAcqVisr::handleRequest(
			DbsMsdc* dbsmsdc
			, ReqMsdc* req
		) {
	if (req->ixVBasetype == ReqMsdc::VecVBasetype::CMD) {
		reqCmd = req;

		if (req->cmd == "cmdset") {

		} else {
			cout << "\tinvalid command!" << endl;
		};

		if (!req->retain) reqCmd = NULL;

	} else if (req->ixVBasetype == ReqMsdc::VecVBasetype::REGULAR) {

	} else if ((req->ixVBasetype == ReqMsdc::VecVBasetype::METHOD) && (req->method->ixVFeatgroup == VecMsdcVFeatgroup::VECVJOBMSDCACQVISRMETHOD)) {
		uint ixVMethod = VecVMethod::getIx(req->method->srefIxVMethod);

		if ((ixVMethod == VecVMethod::SETFOCUS) && (req->method->parsInv.size() == 1) && (req->method->parsRet.size() == 1)) {
			*((bool*) (req->method->parsRet[0])) = setFocus(dbsmsdc, *((const float*) (req->method->parsInv[0])));
		} else if ((ixVMethod == VecVMethod::SETOUTPUT) && (req->method->parsInv.size() == 3) && (req->method->parsRet.size() == 1)) {
			*((bool*) (req->method->parsRet[0])) = setOutput(dbsmsdc, *((const uint*) (req->method->parsInv[0])), *((const uint*) (req->method->parsInv[1])), *((const bool*) (req->method->parsInv[2])));
		} else if ((ixVMethod == VecVMethod::SETTINT) && (req->method->parsInv.size() == 1) && (req->method->parsRet.size() == 1)) {
			*((bool*) (req->method->parsRet[0])) = setTint(dbsmsdc, *((const float*) (req->method->parsInv[0])));
		} else if ((ixVMethod == VecVMethod::START) && (req->method->parsInv.size() == 0) && (req->method->parsRet.size() == 1)) {
			*((bool*) (req->method->parsRet[0])) = start(dbsmsdc);
		} else if ((ixVMethod == VecVMethod::STOP) && (req->method->parsInv.size() == 0) && (req->method->parsRet.size() == 1)) {
			*((bool*) (req->method->parsRet[0])) = stop(dbsmsdc);
		};

	} else if (req->ixVBasetype == ReqMsdc::VecVBasetype::TIMER) {
		handleTimer(dbsmsdc, req->sref);
	};
};

void JobMsdcAcqVisr::handleTimer(
			DbsMsdc* dbsmsdc
			, const string& sref
		) {
	if (ixVSge == VecVSge::ACQIDLE) {
		changeStage(dbsmsdc, nextIxVSge);
	} else if (ixVSge == VecVSge::PRCIDLE) {
		changeStage(dbsmsdc, nextIxVSge);
	};
};

void JobMsdcAcqVisr::handleCall(
			DbsMsdc* dbsmsdc
			, Call* call
		) {
	if (call->ixVCall == VecMsdcVCall::CALLMSDCIBITRDY) {
		call->abort = handleCallMsdcIbitrdy(dbsmsdc, call->jref, call->argInv.ref);
	} else if (call->ixVCall == VecMsdcVCall::CALLMSDCTRIG) {
		call->abort = handleCallMsdcTrig(dbsmsdc, call->jref, call->argInv.intval);
	} else if (call->ixVCall == VecMsdcVCall::CALLMSDCMASTSRDCHG) {
		call->abort = handleCallMsdcMastsrdChg(dbsmsdc, call->jref, call->argInv.boolval);
	};
};

bool JobMsdcAcqVisr::handleCallMsdcIbitrdy(
			DbsMsdc* dbsmsdc
			, const ubigint jrefTrig
			, const ubigint refInv
		) {
	bool retval = false;
	// IP handleCallMsdcIbitrdy --- IBEGIN
	if (!getMastNotSlv() && (ixVSge == VecVSge::READY)) {
		bref = refInv;
		shrdat.rgb.claim(refInv, jref);

		changeStage(dbsmsdc, VecVSge::PRCIDLE);
	};
	// IP handleCallMsdcIbitrdy --- IEND
	return retval;
};

bool JobMsdcAcqVisr::handleCallMsdcTrig(
			DbsMsdc* dbsmsdc
			, const ubigint jrefTrig
			, const int intvalInv
		) {
	bool retval = false;
	// IP handleCallMsdcTrig --- IBEGIN
	if (getMastNotSlv() && (ixVSge == VecVSge::READY)) {
		shrdat.seqno = intvalInv;
		changeStage(dbsmsdc, VecVSge::ACQIDLE);
	};
	// IP handleCallMsdcTrig --- IEND
	return retval;
};

bool JobMsdcAcqVisr::handleCallMsdcMastsrdChg(
			DbsMsdc* dbsmsdc
			, const ubigint jrefTrig
			, const bool boolvalInv
		) {
	bool retval = false;
	// IP handleCallMsdcMastsrdChg --- IBEGIN
	if (getMastNotSlv()) {
		if (boolvalInv && (ixVSge == VecVSge::IDLE)) changeStage(dbsmsdc, VecVSge::READY);
		else if (!boolvalInv && (ixVSge != VecVSge::IDLE)) changeStage(dbsmsdc, VecVSge::IDLE);
	};
	// IP handleCallMsdcMastsrdChg --- IEND
	return retval;
};




