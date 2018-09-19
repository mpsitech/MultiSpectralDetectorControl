/**
  * \file JobMsdcAcqLwir.cpp
  * job handler for job JobMsdcAcqLwir (implementation)
  * \author Alexander Wirthmueller
  * \date created: 12 Sep 2018
  * \date modified: 12 Sep 2018
  */

#ifdef MSDCCMBD
	#include <Msdccmbd.h>
#else
	#include <Msdcd.h>
#endif

#include "JobMsdcAcqLwir.h"

#include "JobMsdcAcqLwir_blks.cpp"

// IP Shrdat.subs --- INSERT

/******************************************************************************
 class JobMsdcAcqLwir::Shrdat
 ******************************************************************************/

JobMsdcAcqLwir::Shrdat::Shrdat() :
			ShrdatMsdc("JobMsdcAcqLwir", "Shrdat")
		{
};

void JobMsdcAcqLwir::Shrdat::init(
			XchgMsdc* xchg
			, DbsMsdc* dbsmsdc
		) {
		// IP Shrdat.init --- IBEGIN
		ixMsdcVCamste = VecMsdcVCamste::NC;

		extcall = NULL;

		seqno = 0;

		fill1Not0 = false;
		read1Not0 = false;

		gray0 = NULL;
		gray0Tkst = 0;
		gray0Min = 0;
		gray0Max = 0;

		gray1 = NULL;
		gray1Tkst = 0;
		gray1Min = 0;
		gray1Max = 0;
		// IP Shrdat.init --- IEND
};

void JobMsdcAcqLwir::Shrdat::term() {
	// IP Shrdat.term --- IBEGIN
	if (extcall) delete extcall;

	if (gray0) delete[] gray0;
	if (gray1) delete[] gray1;
	// IP Shrdat.term --- IEND
};

/******************************************************************************
 class JobMsdcAcqLwir
 ******************************************************************************/

JobMsdcAcqLwir::JobMsdcAcqLwir(
			XchgMsdc* xchg
			, DbsMsdc* dbsmsdc
			, const ubigint jrefSup
			, const uint ixMsdcVLocale
			, const bool prefmast
		) :
			MsjobMsdc(xchg, VecMsdcVJob::JOBMSDCACQLWIR, jrefSup, ixMsdcVLocale, prefmast)
		{

	jref = xchg->addMsjob(dbsmsdc, this);

	srcmsdd = NULL;
	srctrigger = NULL;

	// IP constructor.cust1 --- INSERT

	// IP constructor.spec1 --- INSERT

	srcmsdd = new JobMsdcSrcMsdd(xchg, dbsmsdc, jref, ixMsdcVLocale, true);
	srctrigger = new JobMsdcSrcTrigger(xchg, dbsmsdc, jref, ixMsdcVLocale, true);

	// IP constructor.cust2 --- IBEGIN
	bref = 0;
	seqno = 0;
	t = 0.0;
	// IP constructor.cust2 --- IEND

	// IP constructor.spec2 --- INSERT

	xchg->addClstn(VecMsdcVCall::CALLMSDCBUFRDY, jref, Clstn::VecVJobmask::SELF, 0, Arg(), Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecMsdcVCall::CALLMSDCIBITRDY, jref, Clstn::VecVJobmask::MAST, 0, Arg(), Clstn::VecVJactype::TRY);
	xchg->addClstn(VecMsdcVCall::CALLMSDCTRIG, jref, Clstn::VecVJobmask::IMM, 0, Arg(), Clstn::VecVJactype::TRY);
	xchg->addClstn(VecMsdcVCall::CALLMSDCMASTSRDCHG, jref, Clstn::VecVJobmask::SELF, 0, Arg(), Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecMsdcVCall::CALLMSDCMASTSRDCHG, jref, Clstn::VecVJobmask::SLV, 0, Arg(), Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
	
};

JobMsdcAcqLwir::~JobMsdcAcqLwir() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- IBEGIN
	shrdat.gray.releaseByJref(jref);
	// IP destructor.cust --- IEND

	xchg->removeMsjobByJref(jref);
};

// IP cust --- IBEGIN
void JobMsdcAcqLwir::MsddCallback(
			void* arg
		) {
	ExtcallMsdc* extcall = (ExtcallMsdc*) arg;
	XchgMsdc* xchg = extcall->xchg;

	shrdat.wlockAccess("JobMsdcAcqLwir", "MsddCallback");

	// renew extcall as present one will be deleted
	shrdat.extcall = new ExtcallMsdc(xchg, new Call(VecMsdcVCall::CALLMSDCBUFRDY, extcall->call->jref, Arg()));
	JobMsdcSrcMsdd::shrdat.lwirdata.argCallback = (void*) shrdat.extcall;

	if (JobMsdcSrcMsdd::shrdat.lwirdata.cancel) {
		// error
		extcall->call->argInv.boolval = false;

	} else {
		if (shrdat.fill1Not0) {
			shrdat.gray1Tkst = JobMsdcSrcMsdd::shrdat.lwirdata.tkst;
			shrdat.gray1Min = JobMsdcSrcMsdd::shrdat.lwirdata.min;
			shrdat.gray1Max = JobMsdcSrcMsdd::shrdat.lwirdata.max;
		} else {
			shrdat.gray0Tkst = JobMsdcSrcMsdd::shrdat.lwirdata.tkst;
			shrdat.gray0Min = JobMsdcSrcMsdd::shrdat.lwirdata.min;
			shrdat.gray0Max = JobMsdcSrcMsdd::shrdat.lwirdata.max;
		};

		shrdat.fill1Not0 = !shrdat.fill1Not0;

		if (shrdat.fill1Not0) {
			if (shrdat.read1Not0) JobMsdcSrcMsdd::setLwirBuf(NULL);
			else JobMsdcSrcMsdd::setLwirBuf((unsigned char*) shrdat.gray1);
		} else {
			if (!shrdat.read1Not0) JobMsdcSrcMsdd::setLwirBuf(NULL);
			else JobMsdcSrcMsdd::setLwirBuf((unsigned char*) shrdat.gray0);
		};

		extcall->call->argInv.boolval = true;
	};

	XchgMsdc::runExtcall(extcall);

	shrdat.wunlockAccess("JobMsdcAcqLwir", "MsddCallback");
};

// exact copy from Msdc.cpp but inline
inline unsigned int JobMsdcAcqLwir::intavg(
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
bool JobMsdcAcqLwir::setOutput(
			DbsMsdc* dbsmsdc
			, const uint ixMsdcVSqrgrp
		) {
	bool retval = true;

	lockAccess("setOutput");

	// IP setOutput --- INSERT

	unlockAccess("setOutput");

	return retval;
};

void JobMsdcAcqLwir::changeStage(
			DbsMsdc* dbsmsdc
			, uint _ixVSge
		) {
	bool reenter = true;

	do {
		if (ixVSge != _ixVSge) {
			switch (ixVSge) {
				case VecVSge::IDLE: leaveSgeIdle(dbsmsdc); break;
				case VecVSge::READY: leaveSgeReady(dbsmsdc); break;
				case VecVSge::WAITBUF: leaveSgeWaitbuf(dbsmsdc); break;
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
			case VecVSge::WAITBUF: _ixVSge = enterSgeWaitbuf(dbsmsdc, reenter); break;
			case VecVSge::ACQ: _ixVSge = enterSgeAcq(dbsmsdc, reenter); break;
			case VecVSge::PRCIDLE: _ixVSge = enterSgePrcidle(dbsmsdc, reenter); break;
			case VecVSge::PRC: _ixVSge = enterSgePrc(dbsmsdc, reenter); break;
		};

		// IP changeStage.refresh2 --- INSERT
	} while (ixVSge != _ixVSge);
};

uint JobMsdcAcqLwir::enterSgeIdle(
			DbsMsdc* dbsmsdc
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;
	nextIxVSge = retval;
	// IP enterSgeIdle --- IBEGIN

	if (getMastNotSlv()) {
		// stop acquisition
		srcmsdd->stopLwir();
	};

	shrdat.wlockAccess(jref, "enterSgeIdle");
	shrdat.gray.releaseByJref(jref);
	shrdat.wunlockAccess(jref, "enterSgeIdle");

	// IP enterSgeIdle --- IEND
	return retval;
};

void JobMsdcAcqLwir::leaveSgeIdle(
			DbsMsdc* dbsmsdc
		) {
	// IP leaveSgeIdle --- IBEGIN
	if (getMastNotSlv()) {
		shrdat.wlockAccess(jref, "leaveSgeIdle");

		if (shrdat.extcall) delete shrdat.extcall;
		shrdat.extcall = new ExtcallMsdc(xchg, new Call(VecMsdcVCall::CALLMSDCBUFRDY, jref, Arg()));

		shrdat.seqno = 0;

		shrdat.fill1Not0 = false;
		shrdat.read1Not0 = false;

		// reset / initialize buffers (2 extra bytes for CRC to allow bufxf from FPGA without copy)
		if (!shrdat.gray0) {
			shrdat.gray0 = new unsigned short[stg.width*stg.height+1]; memset(shrdat.gray0, 127, 2*stg.width*stg.height);
			shrdat.gray1 = new unsigned short[stg.width*stg.height+1]; memset(shrdat.gray1, 127, 2*stg.width*stg.height);
			shrdat.gray.init(16, 1*stg.width*stg.height*2);
		};

		// start acquisition
		srcmsdd->startLwir((unsigned char*) shrdat.gray0, MsddCallback, (void*) shrdat.extcall);

		shrdat.wunlockAccess(jref, "leaveSgeIdle");
	};

	bref = 0;
	seqno = 0;
	t = 0.0;
	// IP leaveSgeIdle --- IEND
};

uint JobMsdcAcqLwir::enterSgeReady(
			DbsMsdc* dbsmsdc
			, const bool reenter
		) {
	uint retval = VecVSge::READY;
	nextIxVSge = retval;
	// IP enterSgeReady --- INSERT
	return retval;
};

void JobMsdcAcqLwir::leaveSgeReady(
			DbsMsdc* dbsmsdc
		) {
	// IP leaveSgeReady --- INSERT
};

uint JobMsdcAcqLwir::enterSgeWaitbuf(
			DbsMsdc* dbsmsdc
			, const bool reenter
		) {
	uint retval = VecVSge::WAITBUF;
	nextIxVSge = retval;
	// IP enterSgeWaitbuf --- INSERT
	return retval;
};

void JobMsdcAcqLwir::leaveSgeWaitbuf(
			DbsMsdc* dbsmsdc
		) {
	// IP leaveSgeWaitbuf --- INSERT
};

uint JobMsdcAcqLwir::enterSgeAcq(
			DbsMsdc* dbsmsdc
			, const bool reenter
		) {
	uint retval = VecVSge::ACQ;
	nextIxVSge = retval;
	// IP enterSgeAcq --- IBEGIN
	// should only be invoked as master: get raw image data
	bool valid;

	Imgbufitem* ibit = NULL;

	usmallint* _g;

	float scale;
	usmallint min, max;

	valid = true;

	bref = 0;

	// obtain available slot in gray
	bref = shrdat.gray.getNewItem(jref, shrdat.seqno, 0.0); // seqno from trigger, timestamp generated at this time
	valid = (bref != 0);
	
	if (valid) {
		// gray0/1 -> ibit
		ibit = shrdat.gray.getItem(bref);

		_g = (usmallint*) ibit->data;

		shrdat.wlockAccess(jref, "enterSgeAcq");

		// apply orientation transform (r0, r2, s0, s2 are allowed)
		if (shrdat.read1Not0) {
			Msdc::copytrfBuf((unsigned char*) shrdat.gray1, (unsigned char*) _g, 2, stg.width, stg.height, stg.ixMsdcVSqrgrp);

			min = shrdat.gray1Min;
			max = shrdat.gray1Max;

			if (shrdat.fill1Not0) JobMsdcSrcMsdd::setLwirBuf((unsigned char*) shrdat.gray1);

		} else {
			Msdc::copytrfBuf((unsigned char*) shrdat.gray0, (unsigned char*) _g, 2, stg.width, stg.height, stg.ixMsdcVSqrgrp);

			min = shrdat.gray0Min;
			max = shrdat.gray0Max;

			if (!shrdat.fill1Not0) JobMsdcSrcMsdd::setLwirBuf((unsigned char*) shrdat.gray0);
		};

		// perform AGC
		if (min == max) scale = 1.0;
		else scale = 65535.0 / ((float) (max-min));

		for (unsigned int i=0;i<(stg.width*stg.height);i++) _g[i] = lround(scale * ((float) (_g[i]-min)));

		shrdat.read1Not0 = !shrdat.read1Not0;

		shrdat.wunlockAccess(jref, "enterSgeAcq");

		// spread the news ; BAD: nobody is listening to this!
		xchg->triggerRefCall(dbsmsdc, VecMsdcVCall::CALLMSDCIBITRDY, jref, bref);

		if (!srd) retval = VecVSge::READY;
		else retval = VecVSge::PRC;

	} else {
		retval = VecVSge::READY;
	};

	if ((bref != 0) && (retval != VecVSge::PRC)) shrdat.gray.release(bref, jref);

	// IP enterSgeAcq --- IEND
	return retval;
};

void JobMsdcAcqLwir::leaveSgeAcq(
			DbsMsdc* dbsmsdc
		) {
	// IP leaveSgeAcq --- INSERT
};

uint JobMsdcAcqLwir::enterSgePrcidle(
			DbsMsdc* dbsmsdc
			, const bool reenter
		) {
	uint retval = VecVSge::PRCIDLE;
	nextIxVSge = VecVSge::PRC;

	wrefLast = xchg->addWakeup(jref, "callback", 0);
	// IP enterSgePrcidle --- INSERT
	return retval;
};

void JobMsdcAcqLwir::leaveSgePrcidle(
			DbsMsdc* dbsmsdc
		) {
	// IP leaveSgePrcidle --- INSERT
};

uint JobMsdcAcqLwir::enterSgePrc(
			DbsMsdc* dbsmsdc
			, const bool reenter
		) {
	uint retval = VecVSge::PRC;
	nextIxVSge = retval;
	// IP enterSgePrc --- IBEGIN
	bool valid;

	Imgbufitem* ibit = NULL;

	usmallint* _g = NULL;

	Snippet* snippet = NULL;

	unsigned int w, h, wh;

	unsigned int mult;

	unsigned int x0, y0;

	unsigned int cpyw, cpyh;

	unsigned int sum;

	unsigned int im;
	unsigned int rshsN;
	bool rshs[16];

	unsigned int ix;

	ibit = shrdat.gray.getItem(bref);
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

		_g = (usmallint*) (ibit->data);

		for (unsigned int m=0;m<snippets.size();m++) {
			snippet = snippets[m];

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

			// borders to the right and below
			if (cpyw < snippet->w) for (unsigned int i=0;i<cpyh;i++) memset((void*) &(snippet->data[2*(i*snippet->w+cpyw)]), 127, 2*(snippet->w-cpyw));
			if (cpyh < snippet->h) memset((void*) &(snippet->data[2*(snippet->w*cpyh)]), 127, 2*(snippet->w*(snippet->h-cpyh)));

			if ((mult == 1) && (cpyw == stg.width) && (cpyh == stg.height)) {
				if (cpyw == snippet->w) memcpy(snippet->data, (void*) _g, 2*wh);
				else for (unsigned int i=0;i<cpyh;i++) memcpy((void*) &(snippet->data[2*(i*snippet->w)]), (void*) &(_g[i*stg.width]), 2*cpyw);

			} else {
				rshsN = 16;
				Msdc::setupIntavg(mult*mult, 65535, 65535, 0.999, im, rshs, rshsN);

				for (unsigned int i=0;i<cpyh;i++) {
					for (unsigned int j=0;j<cpyw;j++) {
						sum = 0;

						for (unsigned int k=0;k<mult;k++) {
							for (unsigned int l=0;l<mult;l++) {
								ix = (y0+mult*i+k)*stg.width + (x0+mult*j+l);

								sum += _g[ix];
							};
						};

						((unsigned short*) (snippet->data))[i*snippet->w+j] = intavg(sum, im, rshs, rshsN);
					};
				};
			};

			snippet->release();
		};

		if (snippets.size() > 0) xchg->triggerCall(dbsmsdc, VecMsdcVCall::CALLMSDCIMGRDY, jref);
	};

	if (ibit) shrdat.gray.release(bref, jref);

	retval = VecVSge::READY;
	// IP enterSgePrc --- IEND
	return retval;
};

void JobMsdcAcqLwir::leaveSgePrc(
			DbsMsdc* dbsmsdc
		) {
	// IP leaveSgePrc --- INSERT
};

string JobMsdcAcqLwir::getSquawk(
			DbsMsdc* dbsmsdc
		) {
	string retval;
	// IP getSquawk --- BEGIN
	retval = VecVSge::getSref(ixVSge);
	// IP getSquawk --- END
	return retval;
};

void JobMsdcAcqLwir::giveupMaster(
			DbsMsdc* dbsmsdc
			, Msjobinfo* msji
		) {
	// IP giveupMaster --- INSERT
};

void JobMsdcAcqLwir::giveupSlave(
			DbsMsdc* dbsmsdc
			, Msjobinfo* msji
		) {
	// IP giveupSlave --- INSERT
};

void JobMsdcAcqLwir::becomeMaster(
			DbsMsdc* dbsmsdc
			, Msjobinfo* msji
		) {
	// IP becomeMaster --- INSERT
};

void JobMsdcAcqLwir::becomeSlave(
			DbsMsdc* dbsmsdc
			, Msjobinfo* msji
		) {
	// IP becomeSlave --- INSERT
};

bool JobMsdcAcqLwir::handleClaimMaster(
			DbsMsdc* dbsmsdc
			, Msjobinfo* msji
		) {
	bool retval = !prefmast;
	retval = true; // IP handleClaimMaster --- ILINE
	return retval;
};

void JobMsdcAcqLwir::handleRequest(
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

	} else if ((req->ixVBasetype == ReqMsdc::VecVBasetype::METHOD) && (req->method->ixVFeatgroup == VecMsdcVFeatgroup::VECVJOBMSDCACQLWIRMETHOD)) {
		uint ixVMethod = VecVMethod::getIx(req->method->srefIxVMethod);

		if ((ixVMethod == VecVMethod::SETOUTPUT) && (req->method->parsInv.size() == 1) && (req->method->parsRet.size() == 1)) {
			*((bool*) (req->method->parsRet[0])) = setOutput(dbsmsdc, *((const uint*) (req->method->parsInv[0])));
		} else if ((ixVMethod == VecVMethod::START) && (req->method->parsInv.size() == 0) && (req->method->parsRet.size() == 1)) {
			*((bool*) (req->method->parsRet[0])) = start(dbsmsdc);
		} else if ((ixVMethod == VecVMethod::STOP) && (req->method->parsInv.size() == 0) && (req->method->parsRet.size() == 1)) {
			*((bool*) (req->method->parsRet[0])) = stop(dbsmsdc);
		};

	} else if (req->ixVBasetype == ReqMsdc::VecVBasetype::TIMER) {
		handleTimer(dbsmsdc, req->sref);
	};
};

bool JobMsdcAcqLwir::handleTest(
			DbsMsdc* dbsmsdc
		) {
	bool retval = false;
	// IP handleTest --- INSERT
	return retval;
};

void JobMsdcAcqLwir::handleTimer(
			DbsMsdc* dbsmsdc
			, const string& sref
		) {
	if (ixVSge == VecVSge::PRCIDLE) {
		changeStage(dbsmsdc, nextIxVSge);
	};
};

void JobMsdcAcqLwir::handleCall(
			DbsMsdc* dbsmsdc
			, Call* call
		) {
	if (call->ixVCall == VecMsdcVCall::CALLMSDCBUFRDY) {
		call->abort = handleCallMsdcBufrdy(dbsmsdc, call->jref, call->argInv.boolval);
	} else if (call->ixVCall == VecMsdcVCall::CALLMSDCIBITRDY) {
		call->abort = handleCallMsdcIbitrdy(dbsmsdc, call->jref, call->argInv.ref);
	} else if (call->ixVCall == VecMsdcVCall::CALLMSDCTRIG) {
		call->abort = handleCallMsdcTrig(dbsmsdc, call->jref, call->argInv.intval);
	} else if (call->ixVCall == VecMsdcVCall::CALLMSDCMASTSRDCHG) {
		call->abort = handleCallMsdcMastsrdChg(dbsmsdc, call->jref, call->argInv.boolval);
	};
};

bool JobMsdcAcqLwir::handleCallMsdcBufrdy(
			DbsMsdc* dbsmsdc
			, const ubigint jrefTrig
			, const bool boolvalInv
		) {
	bool retval = false;
	// IP handleCallMsdcBufrdy --- IBEGIN
	if (boolvalInv == false) {
		if (ixVSge != VecVSge::IDLE) changeStage(dbsmsdc, VecVSge::IDLE);
	} else {
		if (ixVSge == VecVSge::WAITBUF) {
			changeStage(dbsmsdc, VecVSge::ACQ);

		} else {
			// drop frame
			shrdat.wlockAccess(jref, "handleCallMsdcBufrdy");

			if (shrdat.read1Not0 && shrdat.fill1Not0) JobMsdcSrcMsdd::setLwirBuf((unsigned char*) shrdat.gray1);
			else if (!shrdat.read1Not0 && !shrdat.fill1Not0) JobMsdcSrcMsdd::setLwirBuf((unsigned char*) shrdat.gray0);

			shrdat.read1Not0 = !shrdat.read1Not0;

			shrdat.wunlockAccess(jref, "handleCallMsdcBufrdy");
		};
	};
	// IP handleCallMsdcBufrdy --- IEND
	return retval;
};

bool JobMsdcAcqLwir::handleCallMsdcIbitrdy(
			DbsMsdc* dbsmsdc
			, const ubigint jrefTrig
			, const ubigint refInv
		) {
	bool retval = false;
	// IP handleCallMsdcIbitrdy --- INSERT
	return retval;
};

bool JobMsdcAcqLwir::handleCallMsdcTrig(
			DbsMsdc* dbsmsdc
			, const ubigint jrefTrig
			, const int intvalInv
		) {
	bool retval = false;
	// IP handleCallMsdcTrig --- IBEGIN
	if (getMastNotSlv() && (ixVSge == VecVSge::READY)) {
		shrdat.seqno = intvalInv;
		changeStage(dbsmsdc, VecVSge::WAITBUF);
	};
	// IP handleCallMsdcTrig --- IEND
	return retval;
};

bool JobMsdcAcqLwir::handleCallMsdcMastsrdChg(
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



