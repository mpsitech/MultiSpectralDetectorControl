/**
	* \file MsdccmbdDdspub.cpp
	* DDS publisher based on rti DDS Connext for Msdc combined daemon (implementation)
	* \author Alexander Wirthmueller
	* \date created: 15 Aug 2018
	* \date modified: 15 Aug 2018
	*/

#include "Msdccmbd.h"

#include "MsdccmbdDdspub.h"

/******************************************************************************
 replier classes
 ******************************************************************************/

namespace rti {
	namespace request {
		template<> void ReplierListener<DdsJobMsdcAcqLwir::setOutput_req,DdsJobMsdcAcqLwir::setOutput_reply>::on_request_available(
					Replier<DdsJobMsdcAcqLwir::setOutput_req,DdsJobMsdcAcqLwir::setOutput_reply>& replier
				) {
			auto requests = replier.receive_requests(dds::core::Duration());
			DdsJobMsdcAcqLwir::setOutput_reply reply;

			for (const auto& request: requests) {
				if (!request.info().valid()) continue;

				MsdccmbdDdspub::runMethod(MsdccmbdDdspub::statshr.jrefAcqlwir, VecMsdcVFeatgroup::VECVJOBMSDCACQLWIRMETHOD, "setOutput",
							{&request.data().ixMsdcVSqrgrp()},
							{&reply.success()});

				replier.send_reply(reply, request.info());
			};
		};

		template<> void ReplierListener<DdsJobMsdcAcqLwir::start_req,DdsJobMsdcAcqLwir::start_reply>::on_request_available(
					Replier<DdsJobMsdcAcqLwir::start_req,DdsJobMsdcAcqLwir::start_reply>& replier
				) {
			auto requests = replier.receive_requests(dds::core::Duration());
			DdsJobMsdcAcqLwir::start_reply reply;

			for (const auto& request: requests) {
				if (!request.info().valid()) continue;

				MsdccmbdDdspub::runMethod(MsdccmbdDdspub::statshr.jrefAcqlwir, VecMsdcVFeatgroup::VECVJOBMSDCACQLWIRMETHOD, "start",
							{&request.data().dummy()},
							{&reply.success()});

				replier.send_reply(reply, request.info());
			};
		};

		template<> void ReplierListener<DdsJobMsdcAcqLwir::stop_req,DdsJobMsdcAcqLwir::stop_reply>::on_request_available(
					Replier<DdsJobMsdcAcqLwir::stop_req,DdsJobMsdcAcqLwir::stop_reply>& replier
				) {
			auto requests = replier.receive_requests(dds::core::Duration());
			DdsJobMsdcAcqLwir::stop_reply reply;

			for (const auto& request: requests) {
				if (!request.info().valid()) continue;

				MsdccmbdDdspub::runMethod(MsdccmbdDdspub::statshr.jrefAcqlwir, VecMsdcVFeatgroup::VECVJOBMSDCACQLWIRMETHOD, "stop",
							{&request.data().dummy()},
							{&reply.success()});

				replier.send_reply(reply, request.info());
			};
		};

		template<> void ReplierListener<DdsJobMsdcAcqVisl::setFocus_req,DdsJobMsdcAcqVisl::setFocus_reply>::on_request_available(
					Replier<DdsJobMsdcAcqVisl::setFocus_req,DdsJobMsdcAcqVisl::setFocus_reply>& replier
				) {
			auto requests = replier.receive_requests(dds::core::Duration());
			DdsJobMsdcAcqVisl::setFocus_reply reply;

			for (const auto& request: requests) {
				if (!request.info().valid()) continue;

				MsdccmbdDdspub::runMethod(MsdccmbdDdspub::statshr.jrefAcqvisl, VecMsdcVFeatgroup::VECVJOBMSDCACQVISLMETHOD, "setFocus",
							{&request.data().focus()},
							{&reply.success()});

				replier.send_reply(reply, request.info());
			};
		};

		template<> void ReplierListener<DdsJobMsdcAcqVisl::setOutput_req,DdsJobMsdcAcqVisl::setOutput_reply>::on_request_available(
					Replier<DdsJobMsdcAcqVisl::setOutput_req,DdsJobMsdcAcqVisl::setOutput_reply>& replier
				) {
			auto requests = replier.receive_requests(dds::core::Duration());
			DdsJobMsdcAcqVisl::setOutput_reply reply;

			for (const auto& request: requests) {
				if (!request.info().valid()) continue;

				MsdccmbdDdspub::runMethod(MsdccmbdDdspub::statshr.jrefAcqvisl, VecMsdcVFeatgroup::VECVJOBMSDCACQVISLMETHOD, "setOutput",
							{&request.data().ixMsdcVCamres(), &request.data().ixMsdcVSqrgrp(), &request.data().grayscale()},
							{&reply.success()});

				replier.send_reply(reply, request.info());
			};
		};

		template<> void ReplierListener<DdsJobMsdcAcqVisl::setTint_req,DdsJobMsdcAcqVisl::setTint_reply>::on_request_available(
					Replier<DdsJobMsdcAcqVisl::setTint_req,DdsJobMsdcAcqVisl::setTint_reply>& replier
				) {
			auto requests = replier.receive_requests(dds::core::Duration());
			DdsJobMsdcAcqVisl::setTint_reply reply;

			for (const auto& request: requests) {
				if (!request.info().valid()) continue;

				MsdccmbdDdspub::runMethod(MsdccmbdDdspub::statshr.jrefAcqvisl, VecMsdcVFeatgroup::VECVJOBMSDCACQVISLMETHOD, "setTint",
							{&request.data().Tint()},
							{&reply.success()});

				replier.send_reply(reply, request.info());
			};
		};

		template<> void ReplierListener<DdsJobMsdcAcqVisl::start_req,DdsJobMsdcAcqVisl::start_reply>::on_request_available(
					Replier<DdsJobMsdcAcqVisl::start_req,DdsJobMsdcAcqVisl::start_reply>& replier
				) {
			auto requests = replier.receive_requests(dds::core::Duration());
			DdsJobMsdcAcqVisl::start_reply reply;

			for (const auto& request: requests) {
				if (!request.info().valid()) continue;

				MsdccmbdDdspub::runMethod(MsdccmbdDdspub::statshr.jrefAcqvisl, VecMsdcVFeatgroup::VECVJOBMSDCACQVISLMETHOD, "start",
							{&request.data().dummy()},
							{&reply.success()});

				replier.send_reply(reply, request.info());
			};
		};

		template<> void ReplierListener<DdsJobMsdcAcqVisl::stop_req,DdsJobMsdcAcqVisl::stop_reply>::on_request_available(
					Replier<DdsJobMsdcAcqVisl::stop_req,DdsJobMsdcAcqVisl::stop_reply>& replier
				) {
			auto requests = replier.receive_requests(dds::core::Duration());
			DdsJobMsdcAcqVisl::stop_reply reply;

			for (const auto& request: requests) {
				if (!request.info().valid()) continue;

				MsdccmbdDdspub::runMethod(MsdccmbdDdspub::statshr.jrefAcqvisl, VecMsdcVFeatgroup::VECVJOBMSDCACQVISLMETHOD, "stop",
							{&request.data().dummy()},
							{&reply.success()});

				replier.send_reply(reply, request.info());
			};
		};

		template<> void ReplierListener<DdsJobMsdcAcqVisr::setFocus_req,DdsJobMsdcAcqVisr::setFocus_reply>::on_request_available(
					Replier<DdsJobMsdcAcqVisr::setFocus_req,DdsJobMsdcAcqVisr::setFocus_reply>& replier
				) {
			auto requests = replier.receive_requests(dds::core::Duration());
			DdsJobMsdcAcqVisr::setFocus_reply reply;

			for (const auto& request: requests) {
				if (!request.info().valid()) continue;

				MsdccmbdDdspub::runMethod(MsdccmbdDdspub::statshr.jrefAcqvisr, VecMsdcVFeatgroup::VECVJOBMSDCACQVISRMETHOD, "setFocus",
							{&request.data().focus()},
							{&reply.success()});

				replier.send_reply(reply, request.info());
			};
		};

		template<> void ReplierListener<DdsJobMsdcAcqVisr::setOutput_req,DdsJobMsdcAcqVisr::setOutput_reply>::on_request_available(
					Replier<DdsJobMsdcAcqVisr::setOutput_req,DdsJobMsdcAcqVisr::setOutput_reply>& replier
				) {
			auto requests = replier.receive_requests(dds::core::Duration());
			DdsJobMsdcAcqVisr::setOutput_reply reply;

			for (const auto& request: requests) {
				if (!request.info().valid()) continue;

				MsdccmbdDdspub::runMethod(MsdccmbdDdspub::statshr.jrefAcqvisr, VecMsdcVFeatgroup::VECVJOBMSDCACQVISRMETHOD, "setOutput",
							{&request.data().ixMsdcVCamres(), &request.data().ixMsdcVSqrgrp(), &request.data().grayscale()},
							{&reply.success()});

				replier.send_reply(reply, request.info());
			};
		};

		template<> void ReplierListener<DdsJobMsdcAcqVisr::setTint_req,DdsJobMsdcAcqVisr::setTint_reply>::on_request_available(
					Replier<DdsJobMsdcAcqVisr::setTint_req,DdsJobMsdcAcqVisr::setTint_reply>& replier
				) {
			auto requests = replier.receive_requests(dds::core::Duration());
			DdsJobMsdcAcqVisr::setTint_reply reply;

			for (const auto& request: requests) {
				if (!request.info().valid()) continue;

				MsdccmbdDdspub::runMethod(MsdccmbdDdspub::statshr.jrefAcqvisr, VecMsdcVFeatgroup::VECVJOBMSDCACQVISRMETHOD, "setTint",
							{&request.data().Tint()},
							{&reply.success()});

				replier.send_reply(reply, request.info());
			};
		};

		template<> void ReplierListener<DdsJobMsdcAcqVisr::start_req,DdsJobMsdcAcqVisr::start_reply>::on_request_available(
					Replier<DdsJobMsdcAcqVisr::start_req,DdsJobMsdcAcqVisr::start_reply>& replier
				) {
			auto requests = replier.receive_requests(dds::core::Duration());
			DdsJobMsdcAcqVisr::start_reply reply;

			for (const auto& request: requests) {
				if (!request.info().valid()) continue;

				MsdccmbdDdspub::runMethod(MsdccmbdDdspub::statshr.jrefAcqvisr, VecMsdcVFeatgroup::VECVJOBMSDCACQVISRMETHOD, "start",
							{&request.data().dummy()},
							{&reply.success()});

				replier.send_reply(reply, request.info());
			};
		};

		template<> void ReplierListener<DdsJobMsdcAcqVisr::stop_req,DdsJobMsdcAcqVisr::stop_reply>::on_request_available(
					Replier<DdsJobMsdcAcqVisr::stop_req,DdsJobMsdcAcqVisr::stop_reply>& replier
				) {
			auto requests = replier.receive_requests(dds::core::Duration());
			DdsJobMsdcAcqVisr::stop_reply reply;

			for (const auto& request: requests) {
				if (!request.info().valid()) continue;

				MsdccmbdDdspub::runMethod(MsdccmbdDdspub::statshr.jrefAcqvisr, VecMsdcVFeatgroup::VECVJOBMSDCACQVISRMETHOD, "stop",
							{&request.data().dummy()},
							{&reply.success()});

				replier.send_reply(reply, request.info());
			};
		};

		template<> void ReplierListener<DdsJobMsdcActAlign::setWave_req,DdsJobMsdcActAlign::setWave_reply>::on_request_available(
					Replier<DdsJobMsdcActAlign::setWave_req,DdsJobMsdcActAlign::setWave_reply>& replier
				) {
			auto requests = replier.receive_requests(dds::core::Duration());
			DdsJobMsdcActAlign::setWave_reply reply;

			for (const auto& request: requests) {
				if (!request.info().valid()) continue;

				MsdccmbdDdspub::runMethod(MsdccmbdDdspub::statshr.jrefActalign, VecMsdcVFeatgroup::VECVJOBMSDCACTALIGNMETHOD, "setWave",
							{&request.data().ixVFunction(), &request.data().N(), &request.data().seq()},
							{&reply.success()});

				replier.send_reply(reply, request.info());
			};
		};

		template<> void ReplierListener<DdsJobMsdcActAlign::start_req,DdsJobMsdcActAlign::start_reply>::on_request_available(
					Replier<DdsJobMsdcActAlign::start_req,DdsJobMsdcActAlign::start_reply>& replier
				) {
			auto requests = replier.receive_requests(dds::core::Duration());
			DdsJobMsdcActAlign::start_reply reply;

			for (const auto& request: requests) {
				if (!request.info().valid()) continue;

				MsdccmbdDdspub::runMethod(MsdccmbdDdspub::statshr.jrefActalign, VecMsdcVFeatgroup::VECVJOBMSDCACTALIGNMETHOD, "start",
							{&request.data().dummy()},
							{&reply.success()});

				replier.send_reply(reply, request.info());
			};
		};

		template<> void ReplierListener<DdsJobMsdcActAlign::stop_req,DdsJobMsdcActAlign::stop_reply>::on_request_available(
					Replier<DdsJobMsdcActAlign::stop_req,DdsJobMsdcActAlign::stop_reply>& replier
				) {
			auto requests = replier.receive_requests(dds::core::Duration());
			DdsJobMsdcActAlign::stop_reply reply;

			for (const auto& request: requests) {
				if (!request.info().valid()) continue;

				MsdccmbdDdspub::runMethod(MsdccmbdDdspub::statshr.jrefActalign, VecMsdcVFeatgroup::VECVJOBMSDCACTALIGNMETHOD, "stop",
							{&request.data().dummy()},
							{&reply.success()});

				replier.send_reply(reply, request.info());
			};
		};

		template<> void ReplierListener<DdsJobMsdcActLed::setFlood_req,DdsJobMsdcActLed::setFlood_reply>::on_request_available(
					Replier<DdsJobMsdcActLed::setFlood_req,DdsJobMsdcActLed::setFlood_reply>& replier
				) {
			auto requests = replier.receive_requests(dds::core::Duration());
			DdsJobMsdcActLed::setFlood_reply reply;

			for (const auto& request: requests) {
				if (!request.info().valid()) continue;

				MsdccmbdDdspub::runMethod(MsdccmbdDdspub::statshr.jrefActled, VecMsdcVFeatgroup::VECVJOBMSDCACTLEDMETHOD, "setFlood",
							{&request.data().flood()},
							{&reply.success()});

				replier.send_reply(reply, request.info());
			};
		};

		template<> void ReplierListener<DdsJobMsdcActLed::setSpot_req,DdsJobMsdcActLed::setSpot_reply>::on_request_available(
					Replier<DdsJobMsdcActLed::setSpot_req,DdsJobMsdcActLed::setSpot_reply>& replier
				) {
			auto requests = replier.receive_requests(dds::core::Duration());
			DdsJobMsdcActLed::setSpot_reply reply;

			for (const auto& request: requests) {
				if (!request.info().valid()) continue;

				MsdccmbdDdspub::runMethod(MsdccmbdDdspub::statshr.jrefActled, VecMsdcVFeatgroup::VECVJOBMSDCACTLEDMETHOD, "setSpot",
							{&request.data().spot()},
							{&reply.success()});

				replier.send_reply(reply, request.info());
			};
		};

		template<> void ReplierListener<DdsJobMsdcActServo::setPhi_req,DdsJobMsdcActServo::setPhi_reply>::on_request_available(
					Replier<DdsJobMsdcActServo::setPhi_req,DdsJobMsdcActServo::setPhi_reply>& replier
				) {
			auto requests = replier.receive_requests(dds::core::Duration());
			DdsJobMsdcActServo::setPhi_reply reply;

			for (const auto& request: requests) {
				if (!request.info().valid()) continue;

				MsdccmbdDdspub::runMethod(MsdccmbdDdspub::statshr.jrefActservo, VecMsdcVFeatgroup::VECVJOBMSDCACTSERVOMETHOD, "setPhi",
							{&request.data().phi()},
							{&reply.success()});

				replier.send_reply(reply, request.info());
			};
		};

		template<> void ReplierListener<DdsJobMsdcActServo::setTheta_req,DdsJobMsdcActServo::setTheta_reply>::on_request_available(
					Replier<DdsJobMsdcActServo::setTheta_req,DdsJobMsdcActServo::setTheta_reply>& replier
				) {
			auto requests = replier.receive_requests(dds::core::Duration());
			DdsJobMsdcActServo::setTheta_reply reply;

			for (const auto& request: requests) {
				if (!request.info().valid()) continue;

				MsdccmbdDdspub::runMethod(MsdccmbdDdspub::statshr.jrefActservo, VecMsdcVFeatgroup::VECVJOBMSDCACTSERVOMETHOD, "setTheta",
							{&request.data().theta()},
							{&reply.success()});

				replier.send_reply(reply, request.info());
			};
		};

	};
};

/******************************************************************************
 class MsdccmbdDdspub::Repliers
 ******************************************************************************/

MsdccmbdDdspub::Repliers::Repliers() {
	replierJobMsdcAcqLwir_setOutput = NULL;
	replierJobMsdcAcqLwir_start = NULL;
	replierJobMsdcAcqLwir_stop = NULL;

	replierJobMsdcAcqVisl_setFocus = NULL;
	replierJobMsdcAcqVisl_setOutput = NULL;
	replierJobMsdcAcqVisl_setTint = NULL;
	replierJobMsdcAcqVisl_start = NULL;
	replierJobMsdcAcqVisl_stop = NULL;

	replierJobMsdcAcqVisr_setFocus = NULL;
	replierJobMsdcAcqVisr_setOutput = NULL;
	replierJobMsdcAcqVisr_setTint = NULL;
	replierJobMsdcAcqVisr_start = NULL;
	replierJobMsdcAcqVisr_stop = NULL;

	replierJobMsdcActAlign_setWave = NULL;
	replierJobMsdcActAlign_start = NULL;
	replierJobMsdcActAlign_stop = NULL;

	replierJobMsdcActLed_setFlood = NULL;
	replierJobMsdcActLed_setSpot = NULL;

	replierJobMsdcActServo_setPhi = NULL;
	replierJobMsdcActServo_setTheta = NULL;
};

MsdccmbdDdspub::Repliers::~Repliers() {
	if (replierJobMsdcAcqLwir_setOutput) delete replierJobMsdcAcqLwir_setOutput;
	if (replierJobMsdcAcqLwir_start) delete replierJobMsdcAcqLwir_start;
	if (replierJobMsdcAcqLwir_stop) delete replierJobMsdcAcqLwir_stop;

	if (replierJobMsdcAcqVisl_setFocus) delete replierJobMsdcAcqVisl_setFocus;
	if (replierJobMsdcAcqVisl_setOutput) delete replierJobMsdcAcqVisl_setOutput;
	if (replierJobMsdcAcqVisl_setTint) delete replierJobMsdcAcqVisl_setTint;
	if (replierJobMsdcAcqVisl_start) delete replierJobMsdcAcqVisl_start;
	if (replierJobMsdcAcqVisl_stop) delete replierJobMsdcAcqVisl_stop;

	if (replierJobMsdcAcqVisr_setFocus) delete replierJobMsdcAcqVisr_setFocus;
	if (replierJobMsdcAcqVisr_setOutput) delete replierJobMsdcAcqVisr_setOutput;
	if (replierJobMsdcAcqVisr_setTint) delete replierJobMsdcAcqVisr_setTint;
	if (replierJobMsdcAcqVisr_start) delete replierJobMsdcAcqVisr_start;
	if (replierJobMsdcAcqVisr_stop) delete replierJobMsdcAcqVisr_stop;

	if (replierJobMsdcActAlign_setWave) delete replierJobMsdcActAlign_setWave;
	if (replierJobMsdcActAlign_start) delete replierJobMsdcActAlign_start;
	if (replierJobMsdcActAlign_stop) delete replierJobMsdcActAlign_stop;

	if (replierJobMsdcActLed_setFlood) delete replierJobMsdcActLed_setFlood;
	if (replierJobMsdcActLed_setSpot) delete replierJobMsdcActLed_setSpot;

	if (replierJobMsdcActServo_setPhi) delete replierJobMsdcActServo_setPhi;
	if (replierJobMsdcActServo_setTheta) delete replierJobMsdcActServo_setTheta;
};

/******************************************************************************
 class MsdccmbdDdspub::DataWriters
 ******************************************************************************/

MsdccmbdDdspub::DataWriters::DataWriters() {
	topicJobMsdcAcqAdxl_alphaBeta = NULL;
	writerJobMsdcAcqAdxl_alphaBeta = NULL;
	JobMsdcAcqAdxl_alphaBeta = NULL;

	topicJobMsdcAcqLwir_seqnoTGray16 = NULL;
	writerJobMsdcAcqLwir_seqnoTGray16 = NULL;
	JobMsdcAcqLwir_seqnoTGray16 = NULL;

	topicJobMsdcAcqVisl_seqnoTRgbx8Gray8 = NULL;
	writerJobMsdcAcqVisl_seqnoTRgbx8Gray8 = NULL;
	JobMsdcAcqVisl_seqnoTRgbx8Gray8 = NULL;

	topicJobMsdcAcqVisr_seqnoTRgbx8Gray8 = NULL;
	writerJobMsdcAcqVisr_seqnoTRgbx8Gray8 = NULL;
	JobMsdcAcqVisr_seqnoTRgbx8Gray8 = NULL;

	topicJobMsdcActLed_floodSpot = NULL;
	writerJobMsdcActLed_floodSpot = NULL;
	JobMsdcActLed_floodSpot = NULL;

	topicJobMsdcActServo_thetaPhi = NULL;
	writerJobMsdcActServo_thetaPhi = NULL;
	JobMsdcActServo_thetaPhi = NULL;
};

MsdccmbdDdspub::DataWriters::~DataWriters() {
	if (topicJobMsdcAcqAdxl_alphaBeta) {
		delete topicJobMsdcAcqAdxl_alphaBeta;
		delete writerJobMsdcAcqAdxl_alphaBeta;
		delete JobMsdcAcqAdxl_alphaBeta;
	};
	if (topicJobMsdcAcqLwir_seqnoTGray16) {
		delete topicJobMsdcAcqLwir_seqnoTGray16;
		delete writerJobMsdcAcqLwir_seqnoTGray16;
		delete JobMsdcAcqLwir_seqnoTGray16;
	};
	if (topicJobMsdcAcqVisl_seqnoTRgbx8Gray8) {
		delete topicJobMsdcAcqVisl_seqnoTRgbx8Gray8;
		delete writerJobMsdcAcqVisl_seqnoTRgbx8Gray8;
		delete JobMsdcAcqVisl_seqnoTRgbx8Gray8;
	};
	if (topicJobMsdcAcqVisr_seqnoTRgbx8Gray8) {
		delete topicJobMsdcAcqVisr_seqnoTRgbx8Gray8;
		delete writerJobMsdcAcqVisr_seqnoTRgbx8Gray8;
		delete JobMsdcAcqVisr_seqnoTRgbx8Gray8;
	};
	if (topicJobMsdcActLed_floodSpot) {
		delete topicJobMsdcActLed_floodSpot;
		delete writerJobMsdcActLed_floodSpot;
		delete JobMsdcActLed_floodSpot;
	};
	if (topicJobMsdcActServo_thetaPhi) {
		delete topicJobMsdcActServo_thetaPhi;
		delete writerJobMsdcActServo_thetaPhi;
		delete JobMsdcActServo_thetaPhi;
	};
};

/******************************************************************************
 namespace MsdccmbdDdspub
 ******************************************************************************/

void* MsdccmbdDdspub::run(
			void* arg
		) {
	xchg = (XchgMsdccmbd*) arg;
	jrefM2msess = 0;

	ReqMsdc* req = NULL;

	RootMsdc::DpchAppLogin* dpchapplogin = NULL;

	uint ixAcc;

	// thread settings
	pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, 0);
	pthread_cleanup_push(&cleanup, arg);

	// - start M2M session
	req = new ReqMsdc(ReqMsdc::VecVBasetype::REGULAR, ReqMsdc::VecVState::RECEIVE, "127.0.0.1");

	req->jref = xchg->jrefRoot;

	dpchapplogin = new RootMsdc::DpchAppLogin();
	dpchapplogin->jref = xchg->jrefRoot;
	dpchapplogin->username = xchg->stgmsdcddspub.username;
	dpchapplogin->password = xchg->stgmsdcddspub.password;
	dpchapplogin->m2mNotReg = true;

	req->dpchapp = dpchapplogin;

	xchg->addReq(req);

	Mutex::lock(&(req->mcReady), "req->mcReady", "MsdccmbdDdspub", "run");
	if (req->ixVState != ReqMsdc::VecVState::REPLY) Cond::wait(&(req->cReady), &(req->mcReady), "req->cReady", "MsdccmbdDdspub", "run");
	Mutex::unlock(&(req->mcReady), "req->mcReady", "MsdccmbdDdspub", "run");

	if (req->dpcheng) if (req->dpcheng->ixMsdcVDpch == VecMsdcVDpch::DPCHENGMSDCCONFIRM) if (((DpchEngMsdcConfirm*) (req->dpcheng))->accepted) jrefM2msess = req->dpcheng->jref;

	delete req;

	if (jrefM2msess != 0) {
		// - determine available jobs
		req = new ReqMsdc(ReqMsdc::VecVBasetype::REGULAR, ReqMsdc::VecVState::RECEIVE, "127.0.0.1");

		req->jref = jrefM2msess;

		req->dpchapp = new DpchAppMsdcInit();
		req->dpchapp->jref = jrefM2msess;

		xchg->addReq(req);

		Mutex::lock(&(req->mcReady), "req->mcReady", "MsdccmbdDdspub", "run");
		if (req->ixVState != ReqMsdc::VecVState::REPLY) Cond::wait(&(req->cReady), &(req->mcReady), "req->cReady", "MsdccmbdDdspub", "run");
		Mutex::unlock(&(req->mcReady), "req->mcReady", "MsdccmbdDdspub", "run");

		if (req->dpcheng) if (req->dpcheng->ixMsdcVDpch == VecMsdcVDpch::DPCHENGM2MSESSMSDCDATA) if (req->dpcheng->has(M2msessMsdc::DpchEngData::STATSHR)) statshr = ((M2msessMsdc::DpchEngData*) (req->dpcheng))->statshr;

		delete req;
	};

	// -- set up DDS (method) repliers and (variable) publishers
	dds::domain::DomainParticipant participant(0);

	// - add replier for each method with execute access
	rti::request::ReplierParams params = rti::request::ReplierParams(participant);

	if (statshr.jrefAcqlwir != 0) {
		xchg->triggerIxSrefToIxCall(NULL, VecMsdcVCall::CALLMSDCACCESS, statshr.jrefAcqlwir, VecMsdcVFeatgroup::VECVJOBMSDCACQLWIRMETHOD, "setOutput", ixAcc);
		if ((ixAcc & VecMsdcWAccess::EXEC) == VecMsdcWAccess::EXEC) {
			params.service_name("JobMsdcAcqLwir.setOutput");
			repliers.replierJobMsdcAcqLwir_setOutput = new rti::request::Replier<DdsJobMsdcAcqLwir::setOutput_req,DdsJobMsdcAcqLwir::setOutput_reply>(params);
		};
		xchg->triggerIxSrefToIxCall(NULL, VecMsdcVCall::CALLMSDCACCESS, statshr.jrefAcqlwir, VecMsdcVFeatgroup::VECVJOBMSDCACQLWIRMETHOD, "start", ixAcc);
		if ((ixAcc & VecMsdcWAccess::EXEC) == VecMsdcWAccess::EXEC) {
			params.service_name("JobMsdcAcqLwir.start");
			repliers.replierJobMsdcAcqLwir_start = new rti::request::Replier<DdsJobMsdcAcqLwir::start_req,DdsJobMsdcAcqLwir::start_reply>(params);
		};
		xchg->triggerIxSrefToIxCall(NULL, VecMsdcVCall::CALLMSDCACCESS, statshr.jrefAcqlwir, VecMsdcVFeatgroup::VECVJOBMSDCACQLWIRMETHOD, "stop", ixAcc);
		if ((ixAcc & VecMsdcWAccess::EXEC) == VecMsdcWAccess::EXEC) {
			params.service_name("JobMsdcAcqLwir.stop");
			repliers.replierJobMsdcAcqLwir_stop = new rti::request::Replier<DdsJobMsdcAcqLwir::stop_req,DdsJobMsdcAcqLwir::stop_reply>(params);
		};
	};
	if (statshr.jrefAcqvisl != 0) {
		xchg->triggerIxSrefToIxCall(NULL, VecMsdcVCall::CALLMSDCACCESS, statshr.jrefAcqvisl, VecMsdcVFeatgroup::VECVJOBMSDCACQVISLMETHOD, "setFocus", ixAcc);
		if ((ixAcc & VecMsdcWAccess::EXEC) == VecMsdcWAccess::EXEC) {
			params.service_name("JobMsdcAcqVisl.setFocus");
			repliers.replierJobMsdcAcqVisl_setFocus = new rti::request::Replier<DdsJobMsdcAcqVisl::setFocus_req,DdsJobMsdcAcqVisl::setFocus_reply>(params);
		};
		xchg->triggerIxSrefToIxCall(NULL, VecMsdcVCall::CALLMSDCACCESS, statshr.jrefAcqvisl, VecMsdcVFeatgroup::VECVJOBMSDCACQVISLMETHOD, "setOutput", ixAcc);
		if ((ixAcc & VecMsdcWAccess::EXEC) == VecMsdcWAccess::EXEC) {
			params.service_name("JobMsdcAcqVisl.setOutput");
			repliers.replierJobMsdcAcqVisl_setOutput = new rti::request::Replier<DdsJobMsdcAcqVisl::setOutput_req,DdsJobMsdcAcqVisl::setOutput_reply>(params);
		};
		xchg->triggerIxSrefToIxCall(NULL, VecMsdcVCall::CALLMSDCACCESS, statshr.jrefAcqvisl, VecMsdcVFeatgroup::VECVJOBMSDCACQVISLMETHOD, "setTint", ixAcc);
		if ((ixAcc & VecMsdcWAccess::EXEC) == VecMsdcWAccess::EXEC) {
			params.service_name("JobMsdcAcqVisl.setTint");
			repliers.replierJobMsdcAcqVisl_setTint = new rti::request::Replier<DdsJobMsdcAcqVisl::setTint_req,DdsJobMsdcAcqVisl::setTint_reply>(params);
		};
		xchg->triggerIxSrefToIxCall(NULL, VecMsdcVCall::CALLMSDCACCESS, statshr.jrefAcqvisl, VecMsdcVFeatgroup::VECVJOBMSDCACQVISLMETHOD, "start", ixAcc);
		if ((ixAcc & VecMsdcWAccess::EXEC) == VecMsdcWAccess::EXEC) {
			params.service_name("JobMsdcAcqVisl.start");
			repliers.replierJobMsdcAcqVisl_start = new rti::request::Replier<DdsJobMsdcAcqVisl::start_req,DdsJobMsdcAcqVisl::start_reply>(params);
		};
		xchg->triggerIxSrefToIxCall(NULL, VecMsdcVCall::CALLMSDCACCESS, statshr.jrefAcqvisl, VecMsdcVFeatgroup::VECVJOBMSDCACQVISLMETHOD, "stop", ixAcc);
		if ((ixAcc & VecMsdcWAccess::EXEC) == VecMsdcWAccess::EXEC) {
			params.service_name("JobMsdcAcqVisl.stop");
			repliers.replierJobMsdcAcqVisl_stop = new rti::request::Replier<DdsJobMsdcAcqVisl::stop_req,DdsJobMsdcAcqVisl::stop_reply>(params);
		};
	};
	if (statshr.jrefAcqvisr != 0) {
		xchg->triggerIxSrefToIxCall(NULL, VecMsdcVCall::CALLMSDCACCESS, statshr.jrefAcqvisr, VecMsdcVFeatgroup::VECVJOBMSDCACQVISRMETHOD, "setFocus", ixAcc);
		if ((ixAcc & VecMsdcWAccess::EXEC) == VecMsdcWAccess::EXEC) {
			params.service_name("JobMsdcAcqVisr.setFocus");
			repliers.replierJobMsdcAcqVisr_setFocus = new rti::request::Replier<DdsJobMsdcAcqVisr::setFocus_req,DdsJobMsdcAcqVisr::setFocus_reply>(params);
		};
		xchg->triggerIxSrefToIxCall(NULL, VecMsdcVCall::CALLMSDCACCESS, statshr.jrefAcqvisr, VecMsdcVFeatgroup::VECVJOBMSDCACQVISRMETHOD, "setOutput", ixAcc);
		if ((ixAcc & VecMsdcWAccess::EXEC) == VecMsdcWAccess::EXEC) {
			params.service_name("JobMsdcAcqVisr.setOutput");
			repliers.replierJobMsdcAcqVisr_setOutput = new rti::request::Replier<DdsJobMsdcAcqVisr::setOutput_req,DdsJobMsdcAcqVisr::setOutput_reply>(params);
		};
		xchg->triggerIxSrefToIxCall(NULL, VecMsdcVCall::CALLMSDCACCESS, statshr.jrefAcqvisr, VecMsdcVFeatgroup::VECVJOBMSDCACQVISRMETHOD, "setTint", ixAcc);
		if ((ixAcc & VecMsdcWAccess::EXEC) == VecMsdcWAccess::EXEC) {
			params.service_name("JobMsdcAcqVisr.setTint");
			repliers.replierJobMsdcAcqVisr_setTint = new rti::request::Replier<DdsJobMsdcAcqVisr::setTint_req,DdsJobMsdcAcqVisr::setTint_reply>(params);
		};
		xchg->triggerIxSrefToIxCall(NULL, VecMsdcVCall::CALLMSDCACCESS, statshr.jrefAcqvisr, VecMsdcVFeatgroup::VECVJOBMSDCACQVISRMETHOD, "start", ixAcc);
		if ((ixAcc & VecMsdcWAccess::EXEC) == VecMsdcWAccess::EXEC) {
			params.service_name("JobMsdcAcqVisr.start");
			repliers.replierJobMsdcAcqVisr_start = new rti::request::Replier<DdsJobMsdcAcqVisr::start_req,DdsJobMsdcAcqVisr::start_reply>(params);
		};
		xchg->triggerIxSrefToIxCall(NULL, VecMsdcVCall::CALLMSDCACCESS, statshr.jrefAcqvisr, VecMsdcVFeatgroup::VECVJOBMSDCACQVISRMETHOD, "stop", ixAcc);
		if ((ixAcc & VecMsdcWAccess::EXEC) == VecMsdcWAccess::EXEC) {
			params.service_name("JobMsdcAcqVisr.stop");
			repliers.replierJobMsdcAcqVisr_stop = new rti::request::Replier<DdsJobMsdcAcqVisr::stop_req,DdsJobMsdcAcqVisr::stop_reply>(params);
		};
	};
	if (statshr.jrefActalign != 0) {
		xchg->triggerIxSrefToIxCall(NULL, VecMsdcVCall::CALLMSDCACCESS, statshr.jrefActalign, VecMsdcVFeatgroup::VECVJOBMSDCACTALIGNMETHOD, "setWave", ixAcc);
		if ((ixAcc & VecMsdcWAccess::EXEC) == VecMsdcWAccess::EXEC) {
			params.service_name("JobMsdcActAlign.setWave");
			repliers.replierJobMsdcActAlign_setWave = new rti::request::Replier<DdsJobMsdcActAlign::setWave_req,DdsJobMsdcActAlign::setWave_reply>(params);
		};
		xchg->triggerIxSrefToIxCall(NULL, VecMsdcVCall::CALLMSDCACCESS, statshr.jrefActalign, VecMsdcVFeatgroup::VECVJOBMSDCACTALIGNMETHOD, "start", ixAcc);
		if ((ixAcc & VecMsdcWAccess::EXEC) == VecMsdcWAccess::EXEC) {
			params.service_name("JobMsdcActAlign.start");
			repliers.replierJobMsdcActAlign_start = new rti::request::Replier<DdsJobMsdcActAlign::start_req,DdsJobMsdcActAlign::start_reply>(params);
		};
		xchg->triggerIxSrefToIxCall(NULL, VecMsdcVCall::CALLMSDCACCESS, statshr.jrefActalign, VecMsdcVFeatgroup::VECVJOBMSDCACTALIGNMETHOD, "stop", ixAcc);
		if ((ixAcc & VecMsdcWAccess::EXEC) == VecMsdcWAccess::EXEC) {
			params.service_name("JobMsdcActAlign.stop");
			repliers.replierJobMsdcActAlign_stop = new rti::request::Replier<DdsJobMsdcActAlign::stop_req,DdsJobMsdcActAlign::stop_reply>(params);
		};
	};
	if (statshr.jrefActled != 0) {
		xchg->triggerIxSrefToIxCall(NULL, VecMsdcVCall::CALLMSDCACCESS, statshr.jrefActled, VecMsdcVFeatgroup::VECVJOBMSDCACTLEDMETHOD, "setFlood", ixAcc);
		if ((ixAcc & VecMsdcWAccess::EXEC) == VecMsdcWAccess::EXEC) {
			params.service_name("JobMsdcActLed.setFlood");
			repliers.replierJobMsdcActLed_setFlood = new rti::request::Replier<DdsJobMsdcActLed::setFlood_req,DdsJobMsdcActLed::setFlood_reply>(params);
		};
		xchg->triggerIxSrefToIxCall(NULL, VecMsdcVCall::CALLMSDCACCESS, statshr.jrefActled, VecMsdcVFeatgroup::VECVJOBMSDCACTLEDMETHOD, "setSpot", ixAcc);
		if ((ixAcc & VecMsdcWAccess::EXEC) == VecMsdcWAccess::EXEC) {
			params.service_name("JobMsdcActLed.setSpot");
			repliers.replierJobMsdcActLed_setSpot = new rti::request::Replier<DdsJobMsdcActLed::setSpot_req,DdsJobMsdcActLed::setSpot_reply>(params);
		};
	};
	if (statshr.jrefActservo != 0) {
		xchg->triggerIxSrefToIxCall(NULL, VecMsdcVCall::CALLMSDCACCESS, statshr.jrefActservo, VecMsdcVFeatgroup::VECVJOBMSDCACTSERVOMETHOD, "setPhi", ixAcc);
		if ((ixAcc & VecMsdcWAccess::EXEC) == VecMsdcWAccess::EXEC) {
			params.service_name("JobMsdcActServo.setPhi");
			repliers.replierJobMsdcActServo_setPhi = new rti::request::Replier<DdsJobMsdcActServo::setPhi_req,DdsJobMsdcActServo::setPhi_reply>(params);
		};
		xchg->triggerIxSrefToIxCall(NULL, VecMsdcVCall::CALLMSDCACCESS, statshr.jrefActservo, VecMsdcVFeatgroup::VECVJOBMSDCACTSERVOMETHOD, "setTheta", ixAcc);
		if ((ixAcc & VecMsdcWAccess::EXEC) == VecMsdcWAccess::EXEC) {
			params.service_name("JobMsdcActServo.setTheta");
			repliers.replierJobMsdcActServo_setTheta = new rti::request::Replier<DdsJobMsdcActServo::setTheta_req,DdsJobMsdcActServo::setTheta_reply>(params);
		};
	};

	// - register call listeners for each variable with view (read) access
	if (statshr.jrefAcqadxl != 0) {
		xchg->triggerIxSrefToIxCall(NULL, VecMsdcVCall::CALLMSDCACCESS, statshr.jrefAcqadxl, VecMsdcVFeatgroup::VECVJOBMSDCACQADXLVAR, "alphaBeta", ixAcc);
		if ((ixAcc & VecMsdcWAccess::VIEW) == VecMsdcWAccess::VIEW) {
			dataWriters.JobMsdcAcqAdxl_alphaBeta = new DdsJobMsdcAcqAdxl::alphaBeta();
			dataWriters.topicJobMsdcAcqAdxl_alphaBeta = new dds::topic::Topic<DdsJobMsdcAcqAdxl::alphaBeta>(participant, "JobMsdcAcqAdxl.alphaBeta");
			dataWriters.writerJobMsdcAcqAdxl_alphaBeta = new dds::pub::DataWriter<DdsJobMsdcAcqAdxl::alphaBeta>(dds::pub::Publisher(participant), *dataWriters.topicJobMsdcAcqAdxl_alphaBeta);

			xchg->addClstnDdspub(statshr.jrefAcqadxl, "alphaBeta");
		};
	};
	if (statshr.jrefAcqlwir != 0) {
		xchg->triggerIxSrefToIxCall(NULL, VecMsdcVCall::CALLMSDCACCESS, statshr.jrefAcqlwir, VecMsdcVFeatgroup::VECVJOBMSDCACQLWIRVAR, "seqnoTGray16", ixAcc);
		if ((ixAcc & VecMsdcWAccess::VIEW) == VecMsdcWAccess::VIEW) {
			dataWriters.JobMsdcAcqLwir_seqnoTGray16 = new DdsJobMsdcAcqLwir::seqnoTGray16();
			dataWriters.topicJobMsdcAcqLwir_seqnoTGray16 = new dds::topic::Topic<DdsJobMsdcAcqLwir::seqnoTGray16>(participant, "JobMsdcAcqLwir.seqnoTGray16");
			// dataWriters.writerJobMsdcAcqLwir_seqnoTGray16 = new dds::pub::DataWriter<DdsJobMsdcAcqLwir::seqnoTGray16>(dds::pub::Publisher(participant), *dataWriters.topicJobMsdcAcqLwir_seqnoTGray16);

			xchg->addClstnDdspub(statshr.jrefAcqlwir, "seqnoTGray16");
		};
	};
	if (statshr.jrefAcqvisl != 0) {
		xchg->triggerIxSrefToIxCall(NULL, VecMsdcVCall::CALLMSDCACCESS, statshr.jrefAcqvisl, VecMsdcVFeatgroup::VECVJOBMSDCACQVISLVAR, "seqnoTRgbx8Gray8", ixAcc);
		if ((ixAcc & VecMsdcWAccess::VIEW) == VecMsdcWAccess::VIEW) {
			dataWriters.JobMsdcAcqVisl_seqnoTRgbx8Gray8 = new DdsJobMsdcAcqVisl::seqnoTRgbx8Gray8();
			dataWriters.topicJobMsdcAcqVisl_seqnoTRgbx8Gray8 = new dds::topic::Topic<DdsJobMsdcAcqVisl::seqnoTRgbx8Gray8>(participant, "JobMsdcAcqVisl.seqnoTRgbx8Gray8");
			// dataWriters.writerJobMsdcAcqVisl_seqnoTRgbx8Gray8 = new dds::pub::DataWriter<DdsJobMsdcAcqVisl::seqnoTRgbx8Gray8>(dds::pub::Publisher(participant), *dataWriters.topicJobMsdcAcqVisl_seqnoTRgbx8Gray8);

			xchg->addClstnDdspub(statshr.jrefAcqvisl, "seqnoTRgbx8Gray8");
		};
	};
	if (statshr.jrefAcqvisr != 0) {
		xchg->triggerIxSrefToIxCall(NULL, VecMsdcVCall::CALLMSDCACCESS, statshr.jrefAcqvisr, VecMsdcVFeatgroup::VECVJOBMSDCACQVISRVAR, "seqnoTRgbx8Gray8", ixAcc);
		if ((ixAcc & VecMsdcWAccess::VIEW) == VecMsdcWAccess::VIEW) {
			dataWriters.JobMsdcAcqVisr_seqnoTRgbx8Gray8 = new DdsJobMsdcAcqVisr::seqnoTRgbx8Gray8();
			dataWriters.topicJobMsdcAcqVisr_seqnoTRgbx8Gray8 = new dds::topic::Topic<DdsJobMsdcAcqVisr::seqnoTRgbx8Gray8>(participant, "JobMsdcAcqVisr.seqnoTRgbx8Gray8");
			// dataWriters.writerJobMsdcAcqVisr_seqnoTRgbx8Gray8 = new dds::pub::DataWriter<DdsJobMsdcAcqVisr::seqnoTRgbx8Gray8>(dds::pub::Publisher(participant), *dataWriters.topicJobMsdcAcqVisr_seqnoTRgbx8Gray8);

			xchg->addClstnDdspub(statshr.jrefAcqvisr, "seqnoTRgbx8Gray8");
		};
	};
	if (statshr.jrefActled != 0) {
		xchg->triggerIxSrefToIxCall(NULL, VecMsdcVCall::CALLMSDCACCESS, statshr.jrefActled, VecMsdcVFeatgroup::VECVJOBMSDCACTLEDVAR, "floodSpot", ixAcc);
		if ((ixAcc & VecMsdcWAccess::VIEW) == VecMsdcWAccess::VIEW) {
			dataWriters.JobMsdcActLed_floodSpot = new DdsJobMsdcActLed::floodSpot();
			dataWriters.topicJobMsdcActLed_floodSpot = new dds::topic::Topic<DdsJobMsdcActLed::floodSpot>(participant, "JobMsdcActLed.floodSpot");
			dataWriters.writerJobMsdcActLed_floodSpot = new dds::pub::DataWriter<DdsJobMsdcActLed::floodSpot>(dds::pub::Publisher(participant), *dataWriters.topicJobMsdcActLed_floodSpot);

			xchg->addClstnDdspub(statshr.jrefActled, "floodSpot");
		};
	};
	if (statshr.jrefActservo != 0) {
		xchg->triggerIxSrefToIxCall(NULL, VecMsdcVCall::CALLMSDCACCESS, statshr.jrefActservo, VecMsdcVFeatgroup::VECVJOBMSDCACTSERVOVAR, "thetaPhi", ixAcc);
		if ((ixAcc & VecMsdcWAccess::VIEW) == VecMsdcWAccess::VIEW) {
			dataWriters.JobMsdcActServo_thetaPhi = new DdsJobMsdcActServo::thetaPhi();
			dataWriters.topicJobMsdcActServo_thetaPhi = new dds::topic::Topic<DdsJobMsdcActServo::thetaPhi>(participant, "JobMsdcActServo.thetaPhi");
			dataWriters.writerJobMsdcActServo_thetaPhi = new dds::pub::DataWriter<DdsJobMsdcActServo::thetaPhi>(dds::pub::Publisher(participant), *dataWriters.topicJobMsdcActServo_thetaPhi);

			xchg->addClstnDdspub(statshr.jrefActservo, "thetaPhi");
		};
	};

	while (true) {
		Mutex::lock(&(xchg->mcDdspub), "xchg->mcDdspub", "MsdccmbdDdspub", "run");
		if (!(xchg->ddspubcall)) Cond::wait(&(xchg->cDdspub), &(xchg->mcDdspub), "xchg->cDdspub", "MsdccmbdDdspub", "run");

		if ((xchg->ddspubcall->jref == statshr.jrefAcqadxl) && (xchg->ddspubcall->argInv.sref == "alphaBeta")) {
			JobMsdcAcqAdxl::shrdat.lockAccess("MsdccmbdDdspub", "run");
			dataWriters.JobMsdcAcqAdxl_alphaBeta->alpha(JobMsdcAcqAdxl::shrdat.alpha);
			dataWriters.JobMsdcAcqAdxl_alphaBeta->beta(JobMsdcAcqAdxl::shrdat.beta);
			JobMsdcAcqAdxl::shrdat.unlockAccess("MsdccmbdDdspub", "run");

			dataWriters.writerJobMsdcAcqAdxl_alphaBeta->write(*(dataWriters.JobMsdcAcqAdxl_alphaBeta));
		} else if ((xchg->ddspubcall->jref == statshr.jrefAcqlwir) && (xchg->ddspubcall->argInv.sref == "seqnoTGray16")) {
			JobMsdcAcqLwir::shrdat.lockAccess("MsdccmbdDdspub", "run");
			dataWriters.JobMsdcAcqLwir_seqnoTGray16->seqno(JobMsdcAcqLwir::shrdat.seqno);
			dataWriters.JobMsdcAcqLwir_seqnoTGray16->t(JobMsdcAcqLwir::shrdat.t);
			dataWriters.JobMsdcAcqLwir_seqnoTGray16->gray16(JobMsdcAcqLwir::shrdat.gray16);
			JobMsdcAcqLwir::shrdat.unlockAccess("MsdccmbdDdspub", "run");

			dataWriters.writerJobMsdcAcqLwir_seqnoTGray16->write(*(dataWriters.JobMsdcAcqLwir_seqnoTGray16));
		} else if ((xchg->ddspubcall->jref == statshr.jrefAcqvisl) && (xchg->ddspubcall->argInv.sref == "seqnoTRgbx8Gray8")) {
			JobMsdcAcqVisl::shrdat.lockAccess("MsdccmbdDdspub", "run");
			dataWriters.JobMsdcAcqVisl_seqnoTRgbx8Gray8->seqno(JobMsdcAcqVisl::shrdat.seqno);
			dataWriters.JobMsdcAcqVisl_seqnoTRgbx8Gray8->t(JobMsdcAcqVisl::shrdat.t);
			dataWriters.JobMsdcAcqVisl_seqnoTRgbx8Gray8->rgbx8(JobMsdcAcqVisl::shrdat.rgbx8);
			dataWriters.JobMsdcAcqVisl_seqnoTRgbx8Gray8->gray8(JobMsdcAcqVisl::shrdat.gray8);
			JobMsdcAcqVisl::shrdat.unlockAccess("MsdccmbdDdspub", "run");

			dataWriters.writerJobMsdcAcqVisl_seqnoTRgbx8Gray8->write(*(dataWriters.JobMsdcAcqVisl_seqnoTRgbx8Gray8));
		} else if ((xchg->ddspubcall->jref == statshr.jrefAcqvisr) && (xchg->ddspubcall->argInv.sref == "seqnoTRgbx8Gray8")) {
			JobMsdcAcqVisr::shrdat.lockAccess("MsdccmbdDdspub", "run");
			dataWriters.JobMsdcAcqVisr_seqnoTRgbx8Gray8->seqno(JobMsdcAcqVisr::shrdat.seqno);
			dataWriters.JobMsdcAcqVisr_seqnoTRgbx8Gray8->t(JobMsdcAcqVisr::shrdat.t);
			dataWriters.JobMsdcAcqVisr_seqnoTRgbx8Gray8->rgbx8(JobMsdcAcqVisr::shrdat.rgbx8);
			dataWriters.JobMsdcAcqVisr_seqnoTRgbx8Gray8->gray8(JobMsdcAcqVisr::shrdat.gray8);
			JobMsdcAcqVisr::shrdat.unlockAccess("MsdccmbdDdspub", "run");

			dataWriters.writerJobMsdcAcqVisr_seqnoTRgbx8Gray8->write(*(dataWriters.JobMsdcAcqVisr_seqnoTRgbx8Gray8));
		} else if ((xchg->ddspubcall->jref == statshr.jrefActled) && (xchg->ddspubcall->argInv.sref == "floodSpot")) {
			JobMsdcActLed::shrdat.lockAccess("MsdccmbdDdspub", "run");
			dataWriters.JobMsdcActLed_floodSpot->flood(JobMsdcActLed::shrdat.flood);
			dataWriters.JobMsdcActLed_floodSpot->spot(JobMsdcActLed::shrdat.spot);
			JobMsdcActLed::shrdat.unlockAccess("MsdccmbdDdspub", "run");

			dataWriters.writerJobMsdcActLed_floodSpot->write(*(dataWriters.JobMsdcActLed_floodSpot));
		} else if ((xchg->ddspubcall->jref == statshr.jrefActservo) && (xchg->ddspubcall->argInv.sref == "thetaPhi")) {
			JobMsdcActServo::shrdat.lockAccess("MsdccmbdDdspub", "run");
			dataWriters.JobMsdcActServo_thetaPhi->theta(JobMsdcActServo::shrdat.theta);
			dataWriters.JobMsdcActServo_thetaPhi->phi(JobMsdcActServo::shrdat.phi);
			JobMsdcActServo::shrdat.unlockAccess("MsdccmbdDdspub", "run");

			dataWriters.writerJobMsdcActServo_thetaPhi->write(*(dataWriters.JobMsdcActServo_thetaPhi));
		};

		xchg->ddspubcall = NULL;
		Mutex::unlock(&(xchg->mcDdspub), "xchg->mcDdspub", "MsdccmbdDdspub", "run");

		Cond::signal(&(xchg->cDdspub), &(xchg->mcDdspub), "xchg->cDdspub", "xchg->mcDdspub", "MsdccmbdDdspub", "run");
	};

	pthread_cleanup_pop(0);

	return NULL;
};

void MsdccmbdDdspub::cleanup(
			void* arg
		) {
	XchgMsdccmbd* xchg = (XchgMsdccmbd*) arg;

	Mutex::unlock(&(xchg->mcDdspub), "xchg->mcDdspub", "MsdccmbdDdspub", "cleanup");
};

void MsdccmbdDdspub::runMethod(
			const ubigint jref
			, const uint ixMsdcVFeatgroup
			, const string& srefIxVMethod
			, const vector<const void*>& parsInv
			, const vector<void*>& parsRet
		) {
	ReqMsdc* req = new ReqMsdc(ReqMsdc::VecVBasetype::METHOD, ReqMsdc::VecVState::RECEIVE, "127.0.0.1");

	req->jref = jref;

	req->method = new Method(ixMsdcVFeatgroup, srefIxVMethod);
	req->method->parsInv = parsInv;
	req->method->parsRet = parsRet;

	xchg->addReq(req);

	Mutex::lock(&(req->mcReady), "req->mcReady", "MsdccmbdDdspub", "runMethod");
	if (req->ixVState != ReqMsdc::VecVState::REPLY) Cond::wait(&(req->cReady), &(req->mcReady), "req->cReady", "MsdccmbdDdspub", "runMethod");
	Mutex::unlock(&(req->mcReady), "req->mcReady", "MsdccmbdDdspub", "runMethod");

	delete req;
};

XchgMsdccmbd* MsdccmbdDdspub::xchg;
ubigint MsdccmbdDdspub::jrefM2msess;
M2msessMsdc::StatShr MsdccmbdDdspub::statshr;
MsdccmbdDdspub::Repliers MsdccmbdDdspub::repliers;
MsdccmbdDdspub::DataWriters MsdccmbdDdspub::dataWriters;

