/**
  * \file MsdccmbdOpprc.cpp
  * operation processor for Msdc combined daemon (implementation)
  * \author Alexander Wirthmueller
  * \date created: 15 Aug 2018
  * \date modified: 15 Aug 2018
  */

#include "Msdccmbd.h"

#include "MsdccmbdOpprc.h"

/******************************************************************************
 namespace MsdccmbdOpprc
 ******************************************************************************/

void* MsdccmbdOpprc::run(
			void* arg
		) {
	XchgMsdccmbd* xchg = (XchgMsdccmbd*) arg;

	ReqMsdc* req = NULL;
	DpchInvMsdc* inv = NULL;

	// thread settings
	pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, 0);
	pthread_cleanup_push(&cleanup, arg);

	// open database connection
	DbsMsdc dbsmsdc;
	int contry = 10;

	while (contry > 0) {
		try {
			dbsmsdc.init(xchg->stgmsdcdatabase.ixDbsVDbstype, xchg->stgmsdcdatabase.dbspath, xchg->stgmsdcdatabase.dbsname, xchg->stgmsdcdatabase.ip
						, xchg->stgmsdcdatabase.port, xchg->stgmsdcdatabase.username, xchg->stgmsdcdatabase.password);
			break;
		} catch (DbsException e) {
			contry--;
			if (contry == 0) throw;
		};
	};

	// main loop: wait for operation invocations
	while (true) {
		Mutex::lock(&(xchg->mcOpprcs), "xchg->mcOpprcs", "MsdccmbdOpprc", "run");
		inv = xchg->pullFirstInv();

		while (!inv) {
			Cond::wait(&(xchg->cOpprcs), &(xchg->mcOpprcs), "xchg->cOpprcs", "MsdccmbdOpprc", "run");
			inv = xchg->pullFirstInv();
		};

		Mutex::unlock(&(xchg->mcOpprcs), "xchg->mcOpprcs", "MsdccmbdOpprc", "run");

		// re-signal condition to avoid using broadcast
		Cond::signal(&(xchg->cOpprcs), &(xchg->mcOpprcs), "xchg->cOpprcs", "xchg->mcOpprcs", "MsdccmbdOpprc", "run");

		// prepare request
		req = new ReqMsdc(ReqMsdc::VecVBasetype::RET);

		req->jref = inv->jref;
		req->dpchinv = inv;

		// perform op

		if (req->dpchret) {
			req->dpchret->oref = req->dpchinv->oref;
			req->dpchret->jref = req->dpchinv->jref;

			xchg->addReq(req);

		} else {
			delete req;
		};
	};

	pthread_cleanup_pop(0);

	return(NULL);
};

void MsdccmbdOpprc::cleanup(
			void* arg
		) {
	XchgMsdccmbd* xchg = (XchgMsdccmbd*) arg;

	Mutex::unlock(&(xchg->mcOpprcs), "xchg->mcOpprcs", "MsdccmbdOpprc", "cleanup");
};

