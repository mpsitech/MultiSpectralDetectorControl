/**
	* \file MsdccmbdDdspub.h
	* DDS publisher based on rti DDS Connext for Msdc combined daemon (declarations)
	* \author Alexander Wirthmueller
	* \date created: 18 Dec 2018
	* \date modified: 18 Dec 2018
	*/

#ifndef MSDCCMBDDDSPUB_H
#define MSDCCMBDDDSPUB_H

#include "RootMsdc.h"

#include <dds/dds.hpp>
#include <rti/request/rtirequest.hpp>

#include "DdsMsdc.hpp"

/**
	* MsdccmbdDdspub
	*/
namespace MsdccmbdDdspub {
	/**
		* Repliers
		*/
	class Repliers {

	public:
		Repliers();
		~Repliers();

	public:
		rti::request::Replier<DdsJobMsdcAcqLwir::setOutput_req,DdsJobMsdcAcqLwir::setOutput_reply>* replierJobMsdcAcqLwir_setOutput;
		rti::request::Replier<DdsJobMsdcAcqLwir::start_req,DdsJobMsdcAcqLwir::start_reply>* replierJobMsdcAcqLwir_start;
		rti::request::Replier<DdsJobMsdcAcqLwir::stop_req,DdsJobMsdcAcqLwir::stop_reply>* replierJobMsdcAcqLwir_stop;

		rti::request::Replier<DdsJobMsdcAcqVisl::setFocus_req,DdsJobMsdcAcqVisl::setFocus_reply>* replierJobMsdcAcqVisl_setFocus;
		rti::request::Replier<DdsJobMsdcAcqVisl::setOutput_req,DdsJobMsdcAcqVisl::setOutput_reply>* replierJobMsdcAcqVisl_setOutput;
		rti::request::Replier<DdsJobMsdcAcqVisl::setTint_req,DdsJobMsdcAcqVisl::setTint_reply>* replierJobMsdcAcqVisl_setTint;
		rti::request::Replier<DdsJobMsdcAcqVisl::start_req,DdsJobMsdcAcqVisl::start_reply>* replierJobMsdcAcqVisl_start;
		rti::request::Replier<DdsJobMsdcAcqVisl::stop_req,DdsJobMsdcAcqVisl::stop_reply>* replierJobMsdcAcqVisl_stop;

		rti::request::Replier<DdsJobMsdcAcqVisr::setFocus_req,DdsJobMsdcAcqVisr::setFocus_reply>* replierJobMsdcAcqVisr_setFocus;
		rti::request::Replier<DdsJobMsdcAcqVisr::setOutput_req,DdsJobMsdcAcqVisr::setOutput_reply>* replierJobMsdcAcqVisr_setOutput;
		rti::request::Replier<DdsJobMsdcAcqVisr::setTint_req,DdsJobMsdcAcqVisr::setTint_reply>* replierJobMsdcAcqVisr_setTint;
		rti::request::Replier<DdsJobMsdcAcqVisr::start_req,DdsJobMsdcAcqVisr::start_reply>* replierJobMsdcAcqVisr_start;
		rti::request::Replier<DdsJobMsdcAcqVisr::stop_req,DdsJobMsdcAcqVisr::stop_reply>* replierJobMsdcAcqVisr_stop;

		rti::request::Replier<DdsJobMsdcActAlign::setWave_req,DdsJobMsdcActAlign::setWave_reply>* replierJobMsdcActAlign_setWave;
		rti::request::Replier<DdsJobMsdcActAlign::start_req,DdsJobMsdcActAlign::start_reply>* replierJobMsdcActAlign_start;
		rti::request::Replier<DdsJobMsdcActAlign::stop_req,DdsJobMsdcActAlign::stop_reply>* replierJobMsdcActAlign_stop;

		rti::request::Replier<DdsJobMsdcActLed::setFlood_req,DdsJobMsdcActLed::setFlood_reply>* replierJobMsdcActLed_setFlood;
		rti::request::Replier<DdsJobMsdcActLed::setSpot_req,DdsJobMsdcActLed::setSpot_reply>* replierJobMsdcActLed_setSpot;

		rti::request::Replier<DdsJobMsdcActServo::setPhi_req,DdsJobMsdcActServo::setPhi_reply>* replierJobMsdcActServo_setPhi;
		rti::request::Replier<DdsJobMsdcActServo::setTheta_req,DdsJobMsdcActServo::setTheta_reply>* replierJobMsdcActServo_setTheta;
	};

	/**
		* DataWriters
		*/
	class DataWriters {

	public:
		DataWriters();
		~DataWriters();

	public:
		dds::topic::Topic<DdsJobMsdcAcqAdxl::alphaBeta>* topicJobMsdcAcqAdxl_alphaBeta;
		dds::pub::DataWriter<DdsJobMsdcAcqAdxl::alphaBeta>* writerJobMsdcAcqAdxl_alphaBeta;
		DdsJobMsdcAcqAdxl::alphaBeta* JobMsdcAcqAdxl_alphaBeta;

		dds::topic::Topic<DdsJobMsdcAcqLwir::seqnoTGray16>* topicJobMsdcAcqLwir_seqnoTGray16;
		dds::pub::DataWriter<DdsJobMsdcAcqLwir::seqnoTGray16>* writerJobMsdcAcqLwir_seqnoTGray16;
		DdsJobMsdcAcqLwir::seqnoTGray16* JobMsdcAcqLwir_seqnoTGray16;

		dds::topic::Topic<DdsJobMsdcAcqVisl::seqnoTRgbx8Gray8>* topicJobMsdcAcqVisl_seqnoTRgbx8Gray8;
		dds::pub::DataWriter<DdsJobMsdcAcqVisl::seqnoTRgbx8Gray8>* writerJobMsdcAcqVisl_seqnoTRgbx8Gray8;
		DdsJobMsdcAcqVisl::seqnoTRgbx8Gray8* JobMsdcAcqVisl_seqnoTRgbx8Gray8;

		dds::topic::Topic<DdsJobMsdcAcqVisr::seqnoTRgbx8Gray8>* topicJobMsdcAcqVisr_seqnoTRgbx8Gray8;
		dds::pub::DataWriter<DdsJobMsdcAcqVisr::seqnoTRgbx8Gray8>* writerJobMsdcAcqVisr_seqnoTRgbx8Gray8;
		DdsJobMsdcAcqVisr::seqnoTRgbx8Gray8* JobMsdcAcqVisr_seqnoTRgbx8Gray8;

		dds::topic::Topic<DdsJobMsdcActLed::floodSpot>* topicJobMsdcActLed_floodSpot;
		dds::pub::DataWriter<DdsJobMsdcActLed::floodSpot>* writerJobMsdcActLed_floodSpot;
		DdsJobMsdcActLed::floodSpot* JobMsdcActLed_floodSpot;

		dds::topic::Topic<DdsJobMsdcActServo::thetaPhi>* topicJobMsdcActServo_thetaPhi;
		dds::pub::DataWriter<DdsJobMsdcActServo::thetaPhi>* writerJobMsdcActServo_thetaPhi;
		DdsJobMsdcActServo::thetaPhi* JobMsdcActServo_thetaPhi;
	};

	void* run(void* arg);
	void cleanup(void* arg);

	void runMethod(const ubigint jref, const uint ixMsdcVFeatgroup, const string& srefIxVMethod, const vector<const void*>& parsInv, const vector<void*>& parsRet);

	extern XchgMsdccmbd* xchg;
	extern ubigint jrefM2msess;
	extern M2msessMsdc::StatShr statshr;
	extern Repliers repliers;
	extern DataWriters dataWriters;
};

#endif

