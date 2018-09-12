/**
  * \file RootMsdc.h
  * API code for job RootMsdc (declarations)
  * \author Alexander Wirthmueller
  * \date created: 12 Sep 2018
  * \date modified: 12 Sep 2018
  */

#ifndef ROOTMSDC_H
#define ROOTMSDC_H

#include "ApiMsdc_blks.h"

#define DpchAppRootMsdcLogin RootMsdc::DpchAppLogin
#define DpchEngRootMsdcData RootMsdc::DpchEngData

/**
  * RootMsdc
  */
namespace RootMsdc {
	/**
		* DpchAppLogin (full: DpchAppRootMsdcLogin)
		*/
	class DpchAppLogin : public DpchAppMsdc {

	public:
		static const uint SCRJREF = 1;
		static const uint USERNAME = 2;
		static const uint PASSWORD = 3;
		static const uint M2MNOTREG = 4;
		static const uint CHKSUSPSESS = 5;
		static const uint ALL = 6;

	public:
		DpchAppLogin(const string& scrJref = "", const string& username = "", const string& password = "", const bool m2mNotReg = false, const bool chksuspsess = false, const set<uint>& mask = {NONE});

	public:
		string username;
		string password;
		bool m2mNotReg;
		bool chksuspsess;

	public:
		string getSrefsMask();

		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchEngData (full: DpchEngRootMsdcData)
		*/
	class DpchEngData : public DpchEngMsdc {

	public:
		static const uint SCRJREF = 1;
		static const uint FEEDFENSSPS = 2;

	public:
		DpchEngData();

	public:
		Feed feedFEnsSps;

	public:
		string getSrefsMask();

		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

