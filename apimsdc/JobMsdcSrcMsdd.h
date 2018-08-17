/**
  * \file JobMsdcSrcMsdd.h
  * API code for job JobMsdcSrcMsdd (declarations)
  * \author Alexander Wirthmueller
  * \date created: 15 Aug 2018
  * \date modified: 15 Aug 2018
  */

#ifndef JOBMSDCSRCMSDD_H
#define JOBMSDCSRCMSDD_H

#include "ApiMsdc_blks.h"

#define VecVJobMsdcSrcMsddSge JobMsdcSrcMsdd::VecVSge

#define StgJobMsdcSrcMsdd JobMsdcSrcMsdd::Stg

/**
  * JobMsdcSrcMsdd
  */
namespace JobMsdcSrcMsdd {
	/**
		* VecVSge (full: VecVJobMsdcSrcMsddSge)
		*/
	class VecVSge {

	public:
		static const uint NC = 1;
		static const uint READY = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
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

};

#endif

