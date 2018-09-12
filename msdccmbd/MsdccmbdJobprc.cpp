/**
  * \file MsdccmbdJobprc.cpp
  * job processor for Msdc combined daemon (implementation)
  * \author Alexander Wirthmueller
  * \date created: 12 Sep 2018
  * \date modified: 12 Sep 2018
  */

#include "Msdccmbd.h"

#include "MsdccmbdJobprc.h"

/******************************************************************************
 namespace MsdccmbdJobprc
 ******************************************************************************/

void* MsdccmbdJobprc::run(
			void* arg
		) {
	XchgMsdccmbd* xchg = (XchgMsdccmbd*) arg;

	ReqMsdc* req = NULL;
	JobMsdc* job = NULL;

	ubigint eref;

	// thread settings
	pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, 0);
	pthread_cleanup_push(&cleanup, arg);

	// open database connection
	DbsMsdc dbsmsdc;
	int contry = 10;

	while (contry > 0) {
		try {
			dbsmsdc.init(xchg->stgmsdcdatabase.ixDbsVDbstype, xchg->stgmsdcdatabase.dbspath, xchg->stgmsdcdatabase.dbsname, xchg->stgmsdcdatabase.ip,
						xchg->stgmsdcdatabase.port, xchg->stgmsdcdatabase.username, xchg->stgmsdcdatabase.password);
			break;
		} catch (DbsException e) {
			contry--;
			if (contry == 0) throw;
		};
	};

	// main loop: wait for requests
	while (true) {
		xchg->cJobprcs.lockMutex("MsdccmbdJobprc", "run");
		req = xchg->pullFirstReq();

		while (!req) {
			xchg->cJobprcs.wait("MsdccmbdJobprc", "run");
			req = xchg->pullFirstReq();
		};

		xchg->cJobprcs.unlockMutex("MsdccmbdJobprc", "run");

		// re-signal condition to avoid using broadcast
		xchg->cJobprcs.signal("MsdccmbdJobprc", "run");

		// --- handle request
		if (req->ixVBasetype == ReqMsdc::VecVBasetype::CMD) {
			xchg->mon.eventHandleReqCmd(req->jref, req->cmd);

			// pass on to job
			accessJob(xchg, &dbsmsdc, req);

		} else if (req->ixVBasetype == ReqMsdc::VecVBasetype::REGULAR) {
			if (req->dpchapp) {
				//cout << "MsdccmbdJobprc::run() REGULAR request: '" << VecMsdcVDpch::getSref(req->dpchapp->ixMsdcVDpch) << "'" << endl;
				eref = xchg->mon.eventHandleReqRegular(req->jref, VecMsdcVDpch::getSref(req->dpchapp->ixMsdcVDpch), req->dpchapp->getSrefsMask(), "");

				// pass on to job
				accessJob(xchg, &dbsmsdc, req);
			};

			if (!req->dpcheng) req->dpcheng = new DpchEngMsdcAck(req->jref);
			xchg->mon.eventReplyReqRegular(eref, req->jref, VecMsdcVDpch::getSref(req->dpcheng->ixMsdcVDpch), req->dpcheng->getSrefsMask(), "");

		} else if (req->ixVBasetype == ReqMsdc::VecVBasetype::UPLOAD) {
			//cout << "MsdccmbdJobprc::run() UPLOAD request file name: '" << req->filename << "'" << endl;
			xchg->mon.eventHandleReqUpload(req->jref, req->filename);

			// pass on to job
			accessJob(xchg, &dbsmsdc, req);

			// usually the job leaves req unchanged

		} else if (req->ixVBasetype == ReqMsdc::VecVBasetype::DOWNLOAD) {
			eref = xchg->mon.eventHandleReqDownload(req->jref);

			// pass on to job
			accessJob(xchg, &dbsmsdc, req);

			xchg->mon.eventReplyReqDownload(eref, req->jref, req->filename);

		} else if (req->ixVBasetype == ReqMsdc::VecVBasetype::RET) {
			if (req->dpchret) {
				//cout << "MsdccmbdJobprc::run() RET request: '" << VecMsdcVDpch::getSref(req->dpchret->ixMsdcVDpch) << "'" << endl;

				job = xchg->getJobByJref(req->jref);
				if (job) job->removeOp(req->dpchret->oref);

				xchg->mon.eventHandleReqRet(req->jref, VecMsdcVDpch::getSref(req->dpchret->ixMsdcVDpch), "", req->dpchret->oref);

				accessJob(xchg, &dbsmsdc, req);
			};

		} else if (req->ixVBasetype == ReqMsdc::VecVBasetype::METHOD) {
			if (req->method) {
				//cout << "MsdccmbdJobprc::run() METHOD request: '" << VecMsdcVFeatgroup::getSref(req->method->ixVFeatgroup) << "." << req->method->srefIxVMethod << "'" << endl;
				xchg->mon.eventHandleReqMethod(req->jref, VecMsdcVFeatgroup::getSref(req->method->ixVFeatgroup), req->method->srefIxVMethod);

				// pass on to job
				accessJob(xchg, &dbsmsdc, req);
			};

		} else if (req->ixVBasetype == ReqMsdc::VecVBasetype::TIMER) {
			// pass on to job
			job = xchg->getJobByJref(req->jref);

			if (job) if (req->wref >= job->wrefMin) {
				xchg->mon.eventHandleReqTimer(req->jref, req->sref);
				accessJob(xchg, &dbsmsdc, req);
			};

		} else if (req->ixVBasetype == ReqMsdc::VecVBasetype::EXTCALL) {
			xchg->triggerCall(&dbsmsdc, req->call);
		};

		if ((req->ixVBasetype == ReqMsdc::VecVBasetype::RET) || (req->ixVBasetype == ReqMsdc::VecVBasetype::TIMER) || (req->ixVBasetype == ReqMsdc::VecVBasetype::EXTCALL)) {
			// ret, timer and extcall requests can be deleted here
			delete req;

		} else {
			// all other requests are being waited for for further processing
			if (!(req->retain)) req->setStateReply();
		};
	};

	pthread_cleanup_pop(0);

	return(NULL);
};

void MsdccmbdJobprc::cleanup(
			void* arg
		) {
	XchgMsdccmbd* xchg = (XchgMsdccmbd*) arg;

	xchg->cJobprcs.unlockMutex("MsdccmbdJobprc", "cleanup");
};

void MsdccmbdJobprc::accessJob(
			XchgMsdccmbd* xchg
			, DbsMsdc* dbsmsdc
			, ReqMsdc* req
		) {
	JobMsdc* job = NULL;
	
	job = xchg->getJobByJref(req->jref);
	if (job) {
		if (!req->weak) job->lockAccess("MsdccmbdJobprc", "accessJob");

		req->ixMsdcVLocale = job->ixMsdcVLocale;
		job->handleRequest(dbsmsdc, req);
	};

	if (!req->weak) {
		job = xchg->getJobByJref(req->jref);
		if (job) job->unlockAccess("MsdccmbdJobprc", "accessJob");
	};
};

