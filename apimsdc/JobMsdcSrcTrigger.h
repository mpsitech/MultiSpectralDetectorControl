/**
  * \file JobMsdcSrcTrigger.h
  * API code for job JobMsdcSrcTrigger (declarations)
  * \author Alexander Wirthmueller
  * \date created: 29 Aug 2018
  * \date modified: 29 Aug 2018
  */

#ifndef JOBMSDCSRCTRIGGER_H
#define JOBMSDCSRCTRIGGER_H

#include "ApiMsdc_blks.h"

#define VecVJobMsdcSrcTriggerSge JobMsdcSrcTrigger::VecVSge

#define StgJobMsdcSrcTrigger JobMsdcSrcTrigger::Stg

/**
  * JobMsdcSrcTrigger
  */
namespace JobMsdcSrcTrigger {
	/**
		* VecVSge (full: VecVJobMsdcSrcTriggerSge)
		*/
	class VecVSge {

	public:
		static const uint IDLE = 1;
		static const uint RUN = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * Stg (full: StgJobMsdcSrcTrigger)
	  */
	class Stg : public Block {

	public:
		static const uint DT = 1;

	public:
		Stg(const float dt = 0.25);

	public:
		float dt;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const Stg* comp);
		set<uint> diff(const Stg* comp);
	};

};

#endif

