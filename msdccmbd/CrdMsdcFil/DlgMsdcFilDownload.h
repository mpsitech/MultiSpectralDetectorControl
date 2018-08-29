/**
  * \file DlgMsdcFilDownload.h
  * job handler for job DlgMsdcFilDownload (declarations)
  * \author Alexander Wirthmueller
  * \date created: 29 Aug 2018
  * \date modified: 29 Aug 2018
  */

#ifndef DLGMSDCFILDOWNLOAD_H
#define DLGMSDCFILDOWNLOAD_H

// IP custInclude --- INSERT

#define VecVDlgMsdcFilDownloadDo DlgMsdcFilDownload::VecVDo

#define ContInfDlgMsdcFilDownload DlgMsdcFilDownload::ContInf
#define StatAppDlgMsdcFilDownload DlgMsdcFilDownload::StatApp
#define TagDlgMsdcFilDownload DlgMsdcFilDownload::Tag

#define DpchAppDlgMsdcFilDownloadDo DlgMsdcFilDownload::DpchAppDo
#define DpchEngDlgMsdcFilDownloadData DlgMsdcFilDownload::DpchEngData

/**
  * DlgMsdcFilDownload
  */
class DlgMsdcFilDownload : public JobMsdc {

public:
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
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppDlgMsdcFilDownload)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const string& shortMenu = "");
	};

	/**
		* Tag (full: TagDlgMsdcFilDownload)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixMsdcVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppDo (full: DpchAppDlgMsdcFilDownloadDo)
		*/
	class DpchAppDo : public DpchAppMsdc {

	public:
		static const uint JREF = 1;
		static const uint IXVDO = 2;

	public:
		DpchAppDo();

	public:
		uint ixVDo;

	public:
		string getSrefsMask();

		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngData (full: DpchEngDlgMsdcFilDownloadData)
		*/
	class DpchEngData : public DpchEngMsdc {

	public:
		static const uint JREF = 1;
		static const uint CONTINF = 2;
		static const uint STATAPP = 3;
		static const uint TAG = 4;
		static const uint ALL = 5;

	public:
		DpchEngData(const ubigint jref = 0, ContInf* continf = NULL, const set<uint>& mask = {NONE});

	public:
		ContInf continf;

	public:
		string getSrefsMask();
		void merge(DpchEngMsdc* dpcheng);

		void writeXML(const uint ixMsdcVLocale, xmlTextWriter* wr);
	};

public:
	DlgMsdcFilDownload(XchgMsdc* xchg, DbsMsdc* dbsmsdc, const ubigint jrefSup, const uint ixMsdcVLocale);
	~DlgMsdcFilDownload();

public:
	ContInf continf;

	// IP custVar --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngMsdc* getNewDpchEng(set<uint> items);

	void refresh(DbsMsdc* dbsmsdc, set<uint>& moditems);

public:

	void handleRequest(DbsMsdc* dbsmsdc, ReqMsdc* req);

	void handleDpchAppMsdcInit(DbsMsdc* dbsmsdc, DpchAppMsdcInit* dpchappmsdcinit, DpchEngMsdc** dpcheng);

	void handleDpchAppDoButDneClick(DbsMsdc* dbsmsdc, DpchEngMsdc** dpcheng);

	string handleDownload(DbsMsdc* dbsmsdc);

};

#endif

