/**
  * \file DlgMsdcFilDownload.h
  * API code for job DlgMsdcFilDownload (declarations)
  * \author Alexander Wirthmueller
  * \date created: 29 Aug 2018
  * \date modified: 29 Aug 2018
  */

#ifndef DLGMSDCFILDOWNLOAD_H
#define DLGMSDCFILDOWNLOAD_H

#include "ApiMsdc_blks.h"

#define VecVDlgMsdcFilDownloadDo DlgMsdcFilDownload::VecVDo

#define ContInfDlgMsdcFilDownload DlgMsdcFilDownload::ContInf
#define StatAppDlgMsdcFilDownload DlgMsdcFilDownload::StatApp
#define TagDlgMsdcFilDownload DlgMsdcFilDownload::Tag

#define DpchAppDlgMsdcFilDownloadDo DlgMsdcFilDownload::DpchAppDo
#define DpchEngDlgMsdcFilDownloadData DlgMsdcFilDownload::DpchEngData

/**
  * DlgMsdcFilDownload
  */
namespace DlgMsdcFilDownload {
	/**
		* VecVDo (full: VecVDlgMsdcFilDownloadDo)
		*/
	class VecVDo {

	public:
		static const uint BUTDNECLICK = 1;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContInf (full: ContInfDlgMsdcFilDownload)
	  */
	class ContInf : public Block {

	public:
		static const uint DLD = 1;

	public:
		ContInf(const string& Dld = "file");

	public:
		string Dld;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppDlgMsdcFilDownload)
	  */
	class StatApp : public Block {

	public:
		static const uint SHORTMENU = 1;

	public:
		StatApp(const string& shortMenu = "");

	public:
		string shortMenu;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatApp* comp);
		set<uint> diff(const StatApp* comp);
	};

	/**
	  * Tag (full: TagDlgMsdcFilDownload)
	  */
	class Tag : public Block {

	public:
		static const uint CPT = 1;
		static const uint DLD = 2;
		static const uint BUTDNE = 3;

	public:
		Tag(const string& Cpt = "", const string& Dld = "", const string& ButDne = "");

	public:
		string Cpt;
		string Dld;
		string ButDne;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppDlgMsdcFilDownloadDo)
		*/
	class DpchAppDo : public DpchAppMsdc {

	public:
		static const uint SCRJREF = 1;
		static const uint IXVDO = 2;
		static const uint ALL = 3;

	public:
		DpchAppDo(const string& scrJref = "", const uint ixVDo = 0, const set<uint>& mask = {NONE});

	public:
		uint ixVDo;

	public:
		string getSrefsMask();

		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchEngData (full: DpchEngDlgMsdcFilDownloadData)
		*/
	class DpchEngData : public DpchEngMsdc {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTINF = 2;
		static const uint STATAPP = 3;
		static const uint TAG = 4;

	public:
		DpchEngData();

	public:
		ContInf continf;
		StatApp statapp;
		Tag tag;

	public:
		string getSrefsMask();

		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

