/**
  * \file JobMsdcAcqLwir.h
  * API code for job JobMsdcAcqLwir (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Oct 2018
  * \date modified: 4 Oct 2018
  */

#ifndef JOBMSDCACQLWIR_H
#define JOBMSDCACQLWIR_H

#include "ApiMsdc_blks.h"

#define VecVJobMsdcAcqLwirMethod JobMsdcAcqLwir::VecVMethod
#define VecVJobMsdcAcqLwirSge JobMsdcAcqLwir::VecVSge
#define VecVJobMsdcAcqLwirVar JobMsdcAcqLwir::VecVVar

#define StgJobMsdcAcqLwir JobMsdcAcqLwir::Stg

/**
  * JobMsdcAcqLwir
  */
namespace JobMsdcAcqLwir {
	/**
		* VecVMethod (full: VecVJobMsdcAcqLwirMethod)
		*/
	class VecVMethod {

	public:
		static const uint SETOUTPUT = 1;
		static const uint START = 2;
		static const uint STOP = 3;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
		* VecVSge (full: VecVJobMsdcAcqLwirSge)
		*/
	class VecVSge {

	public:
		static const uint IDLE = 1;
		static const uint READY = 2;
		static const uint WAITBUF = 3;
		static const uint ACQ = 4;
		static const uint PRCIDLE = 5;
		static const uint PRC = 6;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
		* VecVVar (full: VecVJobMsdcAcqLwirVar)
		*/
	class VecVVar {

	public:
		static const uint SEQNOTGRAY16 = 1;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * Stg (full: StgJobMsdcAcqLwir)
	  */
	class Stg : public Block {

	public:
		static const uint WIDTH = 1;
		static const uint HEIGHT = 2;
		static const uint HPIX = 3;
		static const uint SERNO = 4;
		static const uint A = 5;
		static const uint B = 6;
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
		Stg(const uint width = 160, const uint height = 120, const double hpix = 12, const string& serno = "", const double a = 0.05, const double b = 15000, const uint ixMsdcVSqrgrp = 0, const double f = 9, const double fn = 1.1, const double k1 = 0.0, const double k2 = 0.0, const double p1 = 0.0, const double p2 = 0.0, const double k3 = 0.0, const double k4 = 0.0, const double k5 = 0.0, const double k6 = 0.0);

	public:
		uint width;
		uint height;
		double hpix;
		string serno;
		double a;
		double b;
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

