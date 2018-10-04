/**
  * \file JobMsdcActServo.h
  * API code for job JobMsdcActServo (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Oct 2018
  * \date modified: 4 Oct 2018
  */

#ifndef JOBMSDCACTSERVO_H
#define JOBMSDCACTSERVO_H

#include "ApiMsdc_blks.h"

#define VecVJobMsdcActServoMethod JobMsdcActServo::VecVMethod
#define VecVJobMsdcActServoVar JobMsdcActServo::VecVVar

#define StgJobMsdcActServo JobMsdcActServo::Stg

/**
  * JobMsdcActServo
  */
namespace JobMsdcActServo {
	/**
		* VecVMethod (full: VecVJobMsdcActServoMethod)
		*/
	class VecVMethod {

	public:
		static const uint SETPHI = 1;
		static const uint SETTHETA = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
		* VecVVar (full: VecVJobMsdcActServoVar)
		*/
	class VecVVar {

	public:
		static const uint THETAPHI = 1;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * Stg (full: StgJobMsdcActServo)
	  */
	class Stg : public Block {

	public:
		static const uint PHIMIN = 1;
		static const uint PHIMAX = 2;
		static const uint THETAMIN = 3;
		static const uint THETAMAX = 4;

	public:
		Stg(const double phimin = -40, const double phimax = 40, const double thetamin = -40, const double thetamax = 15);

	public:
		double phimin;
		double phimax;
		double thetamin;
		double thetamax;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const Stg* comp);
		set<uint> diff(const Stg* comp);
	};

};

#endif

