/**
  * \file JobMsdcAcqVisr.h
  * API code for job JobMsdcAcqVisr (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Oct 2018
  * \date modified: 4 Oct 2018
  */

#ifndef JOBMSDCACQVISR_H
#define JOBMSDCACQVISR_H

#include "ApiMsdc_blks.h"

#define VecVJobMsdcAcqVisrMethod JobMsdcAcqVisr::VecVMethod
#define VecVJobMsdcAcqVisrSge JobMsdcAcqVisr::VecVSge
#define VecVJobMsdcAcqVisrVar JobMsdcAcqVisr::VecVVar

#define StgJobMsdcAcqVisr JobMsdcAcqVisr::Stg

/**
  * JobMsdcAcqVisr
  */
namespace JobMsdcAcqVisr {
	/**
		* VecVMethod (full: VecVJobMsdcAcqVisrMethod)
		*/
	class VecVMethod {

	public:
		static const uint SETFOCUS = 1;
		static const uint SETOUTPUT = 2;
		static const uint SETTINT = 3;
		static const uint START = 4;
		static const uint STOP = 5;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
		* VecVSge (full: VecVJobMsdcAcqVisrSge)
		*/
	class VecVSge {

	public:
		static const uint IDLE = 1;
		static const uint READY = 2;
		static const uint ACQIDLE = 3;
		static const uint ACQ = 4;
		static const uint PRCIDLE = 5;
		static const uint PRC = 6;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
		* VecVVar (full: VecVJobMsdcAcqVisrVar)
		*/
	class VecVVar {

	public:
		static const uint SEQNOTRGBX8GRAY8 = 1;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * Stg (full: StgJobMsdcAcqVisr)
	  */
	class Stg : public Block {

	public:
		static const uint IXMSDCVCAMTYPE = 1;
		static const uint WIDTH = 2;
		static const uint HEIGHT = 3;
		static const uint HPIX = 4;
		static const uint PATH = 5;
		static const uint SERNO = 6;
		static const uint IXMSDCVSQRGRP = 7;
		static const uint F = 8;
		static const uint FN = 9;
		static const uint K1 = 10;
		static const uint K2 = 11;
		static const uint P1 = 12;
		static const uint P2 = 13;
		static const uint K3 = 14;
		static const uint K4 = 15;
		static const uint K5 = 16;
		static const uint K6 = 17;

	public:
		Stg(const uint ixMsdcVCamtype = 0, const uint width = 1280, const uint height = 720, const double hpix = 3, const string& path = "", const string& serno = "", const uint ixMsdcVSqrgrp = 0, const double f = 3, const double fn = 2, const double k1 = 0.0, const double k2 = 0.0, const double p1 = 0.0, const double p2 = 0.0, const double k3 = 0.0, const double k4 = 0.0, const double k5 = 0.0, const double k6 = 0.0);

	public:
		uint ixMsdcVCamtype;
		uint width;
		uint height;
		double hpix;
		string path;
		string serno;
		uint ixMsdcVSqrgrp;
		double f;
		double fn;
		double k1;
		double k2;
		double p1;
		double p2;
		double k3;
		double k4;
		double k5;
		double k6;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const Stg* comp);
		set<uint> diff(const Stg* comp);
	};

};

#endif

