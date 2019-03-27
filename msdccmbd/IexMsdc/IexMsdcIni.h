/**
  * \file IexMsdcIni.h
  * import/export handler for database DbsMsdc (declarations)
  * \author Alexander Wirthmueller
  * \date created: 18 Dec 2018
  * \date modified: 18 Dec 2018
  */

#ifndef IEXMSDCINI_H
#define IEXMSDCINI_H

#define VecVIexMsdcIniIme IexMsdcIni::VecVIme

#define ImeitemIMsdcIniAVControlPar IexMsdcIni::ImeitemIAVControlPar
#define ImeIMsdcIniAVControlPar IexMsdcIni::ImeIAVControlPar
#define VecWImeIMsdcIniAVControlParIel IexMsdcIni::ImeIAVControlPar::VecWIel

#define ImeitemIMsdcIniJAVKeylistKey IexMsdcIni::ImeitemIJAVKeylistKey
#define ImeIMsdcIniJAVKeylistKey IexMsdcIni::ImeIJAVKeylistKey
#define VecWImeIMsdcIniJAVKeylistKeyIel IexMsdcIni::ImeIJAVKeylistKey::VecWIel

#define ImeitemIMsdcIniAVKeylistKey IexMsdcIni::ImeitemIAVKeylistKey
#define ImeIMsdcIniAVKeylistKey IexMsdcIni::ImeIAVKeylistKey
#define VecWImeIMsdcIniAVKeylistKeyIel IexMsdcIni::ImeIAVKeylistKey::VecWIel

#define ImeitemIMsdcIniAVValuelistVal IexMsdcIni::ImeitemIAVValuelistVal
#define ImeIMsdcIniAVValuelistVal IexMsdcIni::ImeIAVValuelistVal
#define VecWImeIMsdcIniAVValuelistValIel IexMsdcIni::ImeIAVValuelistVal::VecWIel

#define ImeitemIMsdcIniMFile IexMsdcIni::ImeitemIMFile
#define ImeIMsdcIniMFile IexMsdcIni::ImeIMFile
#define VecWImeIMsdcIniMFileIel IexMsdcIni::ImeIMFile::VecWIel

#define ImeitemIMsdcIniAMUsergroupAccess IexMsdcIni::ImeitemIAMUsergroupAccess
#define ImeIMsdcIniAMUsergroupAccess IexMsdcIni::ImeIAMUsergroupAccess
#define VecWImeIMsdcIniAMUsergroupAccessIel IexMsdcIni::ImeIAMUsergroupAccess::VecWIel

#define ImeitemIMsdcIniAMUserAccess IexMsdcIni::ImeitemIAMUserAccess
#define ImeIMsdcIniAMUserAccess IexMsdcIni::ImeIAMUserAccess
#define VecWImeIMsdcIniAMUserAccessIel IexMsdcIni::ImeIAMUserAccess::VecWIel

#define ImeitemIMsdcIniJMUserState IexMsdcIni::ImeitemIJMUserState
#define ImeIMsdcIniJMUserState IexMsdcIni::ImeIJMUserState
#define VecWImeIMsdcIniJMUserStateIel IexMsdcIni::ImeIJMUserState::VecWIel

#define ImeitemIMsdcIniJMPersonLastname IexMsdcIni::ImeitemIJMPersonLastname
#define ImeIMsdcIniJMPersonLastname IexMsdcIni::ImeIJMPersonLastname
#define VecWImeIMsdcIniJMPersonLastnameIel IexMsdcIni::ImeIJMPersonLastname::VecWIel

#define ImeitemIMsdcIniMPerson IexMsdcIni::ImeitemIMPerson
#define ImeIMsdcIniMPerson IexMsdcIni::ImeIMPerson
#define VecWImeIMsdcIniMPersonIel IexMsdcIni::ImeIMPerson::VecWIel

#define ImeitemIMsdcIniMUser IexMsdcIni::ImeitemIMUser
#define ImeIMsdcIniMUser IexMsdcIni::ImeIMUser
#define VecWImeIMsdcIniMUserIel IexMsdcIni::ImeIMUser::VecWIel

#define ImeitemIMsdcIniMUsergroup IexMsdcIni::ImeitemIMUsergroup
#define ImeIMsdcIniMUsergroup IexMsdcIni::ImeIMUsergroup
#define VecWImeIMsdcIniMUsergroupIel IexMsdcIni::ImeIMUsergroup::VecWIel

/**
	* IexMsdcIni
	*/
class IexMsdcIni : public JobMsdc {

public:
	/**
		* VecVIme (full: VecVIexMsdcIniIme)
		*/
	class VecVIme {

	public:
		static const uint IMEIAVCONTROLPAR = 1;
		static const uint IMEIAVKEYLISTKEY = 2;
		static const uint IMEIAVVALUELISTVAL = 3;
		static const uint IMEIMFILE = 4;
		static const uint IMEIMUSERGROUP = 5;
		static const uint IMEIAMUSERGROUPACCESS = 6;
		static const uint IMEIJAVKEYLISTKEY = 7;
		static const uint IMEIMUSER = 8;
		static const uint IMEIAMUSERACCESS = 9;
		static const uint IMEIJMUSERSTATE = 10;
		static const uint IMEIMPERSON = 11;
		static const uint IMEIJMPERSONLASTNAME = 12;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

public:
	/**
		* ImeitemIAVControlPar (full: ImeitemIMsdcIniAVControlPar)
		*/
	class ImeitemIAVControlPar : public MsdcAVControlPar {

	public:
		ImeitemIAVControlPar(const uint ixMsdcVControl = 0, const string& Par = "", const string& Val = "");
		ImeitemIAVControlPar(DbsMsdc* dbsmsdc, const ubigint ref);

	public:
		uint lineno;
		uint ixWIelValid;

	public:
		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const string& basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const uint num, const bool shorttags = true);
	};

	/**
		* ImeIAVControlPar (full: ImeIMsdcIniAVControlPar)
		*/
	class ImeIAVControlPar {

	public:
		/**
			* VecWIel (full: VecWImeIMsdcIniAVControlParIel)
			*/
		class VecWIel {

		public:
			static const uint SREFIXMSDCVCONTROL = 1;
			static const uint PAR = 2;
			static const uint VAL = 4;

			static uint getIx(const string& srefs);
			static void getIcs(const uint ix, set<uint>& ics);
			static string getSrefs(const uint ix);
		};

	public:
		ImeIAVControlPar();
		~ImeIAVControlPar();

	public:
		vector<ImeitemIAVControlPar*> nodes;

	public:
		void clear();

		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, string basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIJAVKeylistKey (full: ImeitemIMsdcIniJAVKeylistKey)
		*/
	class ImeitemIJAVKeylistKey : public MsdcJAVKeylistKey {

	public:
		ImeitemIJAVKeylistKey(const uint x1IxMsdcVLocale = 0, const string& Title = "", const string& Comment = "");
		ImeitemIJAVKeylistKey(DbsMsdc* dbsmsdc, const ubigint ref);

	public:
		uint lineno;
		uint ixWIelValid;

	public:
		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const string& basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const uint num, const bool shorttags = true);
	};

	/**
		* ImeIJAVKeylistKey (full: ImeIMsdcIniJAVKeylistKey)
		*/
	class ImeIJAVKeylistKey {

	public:
		/**
			* VecWIel (full: VecWImeIMsdcIniJAVKeylistKeyIel)
			*/
		class VecWIel {

		public:
			static const uint SREFX1IXMSDCVLOCALE = 1;
			static const uint TITLE = 2;
			static const uint COMMENT = 4;

			static uint getIx(const string& srefs);
			static void getIcs(const uint ix, set<uint>& ics);
			static string getSrefs(const uint ix);
		};

	public:
		ImeIJAVKeylistKey();
		~ImeIJAVKeylistKey();

	public:
		vector<ImeitemIJAVKeylistKey*> nodes;

	public:
		void clear();

		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, string basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIAVKeylistKey (full: ImeitemIMsdcIniAVKeylistKey)
		*/
	class ImeitemIAVKeylistKey : public MsdcAVKeylistKey {

	public:
		ImeitemIAVKeylistKey(const uint klsIxMsdcVKeylist = 0, const string& sref = "", const string& Avail = "", const string& Implied = "");
		ImeitemIAVKeylistKey(DbsMsdc* dbsmsdc, const ubigint ref);

	public:
		uint lineno;
		uint ixWIelValid;

		ImeIJAVKeylistKey imeijavkeylistkey;

	public:
		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const string& basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const uint num, const bool shorttags = true);
	};

	/**
		* ImeIAVKeylistKey (full: ImeIMsdcIniAVKeylistKey)
		*/
	class ImeIAVKeylistKey {

	public:
		/**
			* VecWIel (full: VecWImeIMsdcIniAVKeylistKeyIel)
			*/
		class VecWIel {

		public:
			static const uint SREFKLSIXMSDCVKEYLIST = 1;
			static const uint SREF = 2;
			static const uint AVAIL = 4;
			static const uint IMPLIED = 8;

			static uint getIx(const string& srefs);
			static void getIcs(const uint ix, set<uint>& ics);
			static string getSrefs(const uint ix);
		};

	public:
		ImeIAVKeylistKey();
		~ImeIAVKeylistKey();

	public:
		vector<ImeitemIAVKeylistKey*> nodes;

	public:
		void clear();

		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, string basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIAVValuelistVal (full: ImeitemIMsdcIniAVValuelistVal)
		*/
	class ImeitemIAVValuelistVal : public MsdcAVValuelistVal {

	public:
		ImeitemIAVValuelistVal(const uint vlsIxMsdcVValuelist = 0, const uint x1IxMsdcVLocale = 0, const string& Val = "");
		ImeitemIAVValuelistVal(DbsMsdc* dbsmsdc, const ubigint ref);

	public:
		uint lineno;
		uint ixWIelValid;

	public:
		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const string& basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const uint num, const bool shorttags = true);
	};

	/**
		* ImeIAVValuelistVal (full: ImeIMsdcIniAVValuelistVal)
		*/
	class ImeIAVValuelistVal {

	public:
		/**
			* VecWIel (full: VecWImeIMsdcIniAVValuelistValIel)
			*/
		class VecWIel {

		public:
			static const uint SREFVLSIXMSDCVVALUELIST = 1;
			static const uint SREFX1IXMSDCVLOCALE = 2;
			static const uint VAL = 4;

			static uint getIx(const string& srefs);
			static void getIcs(const uint ix, set<uint>& ics);
			static string getSrefs(const uint ix);
		};

	public:
		ImeIAVValuelistVal();
		~ImeIAVValuelistVal();

	public:
		vector<ImeitemIAVValuelistVal*> nodes;

	public:
		void clear();

		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, string basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMFile (full: ImeitemIMsdcIniMFile)
		*/
	class ImeitemIMFile : public MsdcMFile {

	public:
		ImeitemIMFile(const string& osrefKContent = "", const string& Filename = "", const string& srefKMimetype = "", const string& Comment = "");
		ImeitemIMFile(DbsMsdc* dbsmsdc, const ubigint ref);

	public:
		uint lineno;
		uint ixWIelValid;

	public:
		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const string& basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const uint num, const bool shorttags = true);
	};

	/**
		* ImeIMFile (full: ImeIMsdcIniMFile)
		*/
	class ImeIMFile {

	public:
		/**
			* VecWIel (full: VecWImeIMsdcIniMFileIel)
			*/
		class VecWIel {

		public:
			static const uint OSREFKCONTENT = 1;
			static const uint FILENAME = 2;
			static const uint SREFKMIMETYPE = 4;
			static const uint COMMENT = 8;

			static uint getIx(const string& srefs);
			static void getIcs(const uint ix, set<uint>& ics);
			static string getSrefs(const uint ix);
		};

	public:
		ImeIMFile();
		~ImeIMFile();

	public:
		vector<ImeitemIMFile*> nodes;

	public:
		void clear();

		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, string basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIAMUsergroupAccess (full: ImeitemIMsdcIniAMUsergroupAccess)
		*/
	class ImeitemIAMUsergroupAccess : public MsdcAMUsergroupAccess {

	public:
		ImeitemIAMUsergroupAccess(const uint x1IxMsdcVFeatgroup = 0, const string& x2FeaSrefUix = "", const uint ixMsdcWAccess = 0);
		ImeitemIAMUsergroupAccess(DbsMsdc* dbsmsdc, const ubigint ref);

	public:
		uint lineno;
		uint ixWIelValid;

	public:
		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const string& basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const uint num, const bool shorttags = true);
	};

	/**
		* ImeIAMUsergroupAccess (full: ImeIMsdcIniAMUsergroupAccess)
		*/
	class ImeIAMUsergroupAccess {

	public:
		/**
			* VecWIel (full: VecWImeIMsdcIniAMUsergroupAccessIel)
			*/
		class VecWIel {

		public:
			static const uint SREFX1IXMSDCVFEATGROUP = 1;
			static const uint X2FEASREFUIX = 2;
			static const uint SREFSIXMSDCWACCESS = 4;

			static uint getIx(const string& srefs);
			static void getIcs(const uint ix, set<uint>& ics);
			static string getSrefs(const uint ix);
		};

	public:
		ImeIAMUsergroupAccess();
		~ImeIAMUsergroupAccess();

	public:
		vector<ImeitemIAMUsergroupAccess*> nodes;

	public:
		void clear();

		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, string basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIAMUserAccess (full: ImeitemIMsdcIniAMUserAccess)
		*/
	class ImeitemIAMUserAccess : public MsdcAMUserAccess {

	public:
		ImeitemIAMUserAccess(const uint x1IxMsdcVFeatgroup = 0, const string& x2FeaSrefUix = "", const uint ixMsdcWAccess = 0);
		ImeitemIAMUserAccess(DbsMsdc* dbsmsdc, const ubigint ref);

	public:
		uint lineno;
		uint ixWIelValid;

	public:
		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const string& basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const uint num, const bool shorttags = true);
	};

	/**
		* ImeIAMUserAccess (full: ImeIMsdcIniAMUserAccess)
		*/
	class ImeIAMUserAccess {

	public:
		/**
			* VecWIel (full: VecWImeIMsdcIniAMUserAccessIel)
			*/
		class VecWIel {

		public:
			static const uint SREFX1IXMSDCVFEATGROUP = 1;
			static const uint X2FEASREFUIX = 2;
			static const uint SREFSIXMSDCWACCESS = 4;

			static uint getIx(const string& srefs);
			static void getIcs(const uint ix, set<uint>& ics);
			static string getSrefs(const uint ix);
		};

	public:
		ImeIAMUserAccess();
		~ImeIAMUserAccess();

	public:
		vector<ImeitemIAMUserAccess*> nodes;

	public:
		void clear();

		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, string basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIJMUserState (full: ImeitemIMsdcIniJMUserState)
		*/
	class ImeitemIJMUserState : public MsdcJMUserState {

	public:
		ImeitemIJMUserState(const uint ixVState = 0);
		ImeitemIJMUserState(DbsMsdc* dbsmsdc, const ubigint ref);

	public:
		uint lineno;
		uint ixWIelValid;

	public:
		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const string& basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const uint num, const bool shorttags = true);
	};

	/**
		* ImeIJMUserState (full: ImeIMsdcIniJMUserState)
		*/
	class ImeIJMUserState {

	public:
		/**
			* VecWIel (full: VecWImeIMsdcIniJMUserStateIel)
			*/
		class VecWIel {

		public:
			static const uint SREFIXVSTATE = 1;

			static uint getIx(const string& srefs);
			static void getIcs(const uint ix, set<uint>& ics);
			static string getSrefs(const uint ix);
		};

	public:
		ImeIJMUserState();
		~ImeIJMUserState();

	public:
		vector<ImeitemIJMUserState*> nodes;

	public:
		void clear();

		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, string basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIJMPersonLastname (full: ImeitemIMsdcIniJMPersonLastname)
		*/
	class ImeitemIJMPersonLastname : public MsdcJMPersonLastname {

	public:
		ImeitemIJMPersonLastname(const string& Lastname = "");
		ImeitemIJMPersonLastname(DbsMsdc* dbsmsdc, const ubigint ref);

	public:
		uint lineno;
		uint ixWIelValid;

	public:
		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const string& basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const uint num, const bool shorttags = true);
	};

	/**
		* ImeIJMPersonLastname (full: ImeIMsdcIniJMPersonLastname)
		*/
	class ImeIJMPersonLastname {

	public:
		/**
			* VecWIel (full: VecWImeIMsdcIniJMPersonLastnameIel)
			*/
		class VecWIel {

		public:
			static const uint LASTNAME = 1;

			static uint getIx(const string& srefs);
			static void getIcs(const uint ix, set<uint>& ics);
			static string getSrefs(const uint ix);
		};

	public:
		ImeIJMPersonLastname();
		~ImeIJMPersonLastname();

	public:
		vector<ImeitemIJMPersonLastname*> nodes;

	public:
		void clear();

		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, string basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMPerson (full: ImeitemIMsdcIniMPerson)
		*/
	class ImeitemIMPerson : public MsdcMPerson {

	public:
		ImeitemIMPerson(const uint ixVSex = 0, const string& Title = "", const string& Firstname = "");
		ImeitemIMPerson(DbsMsdc* dbsmsdc, const ubigint ref);

	public:
		uint lineno;
		uint ixWIelValid;

		ImeIJMPersonLastname imeijmpersonlastname;

	public:
		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const string& basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const uint num, const bool shorttags = true);
	};

	/**
		* ImeIMPerson (full: ImeIMsdcIniMPerson)
		*/
	class ImeIMPerson {

	public:
		/**
			* VecWIel (full: VecWImeIMsdcIniMPersonIel)
			*/
		class VecWIel {

		public:
			static const uint SREFIXVSEX = 1;
			static const uint TITLE = 2;
			static const uint FIRSTNAME = 4;

			static uint getIx(const string& srefs);
			static void getIcs(const uint ix, set<uint>& ics);
			static string getSrefs(const uint ix);
		};

	public:
		ImeIMPerson();
		~ImeIMPerson();

	public:
		vector<ImeitemIMPerson*> nodes;

	public:
		void clear();

		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, string basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMUser (full: ImeitemIMsdcIniMUser)
		*/
	class ImeitemIMUser : public MsdcMUser {

	public:
		ImeitemIMUser(const string& sref = "", const uint ixMsdcVLocale = 0, const uint ixMsdcVUserlevel = 0, const string& Password = "", const string& Fullkey = "", const string& Comment = "");
		ImeitemIMUser(DbsMsdc* dbsmsdc, const ubigint ref);

	public:
		uint lineno;
		uint ixWIelValid;

		ImeIAMUserAccess imeiamuseraccess;
		ImeIJMUserState imeijmuserstate;
		ImeIMPerson imeimperson;

	public:
		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const string& basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const uint num, const bool shorttags = true);
	};

	/**
		* ImeIMUser (full: ImeIMsdcIniMUser)
		*/
	class ImeIMUser {

	public:
		/**
			* VecWIel (full: VecWImeIMsdcIniMUserIel)
			*/
		class VecWIel {

		public:
			static const uint SREF = 1;
			static const uint SREFIXMSDCVLOCALE = 2;
			static const uint SREFIXMSDCVUSERLEVEL = 4;
			static const uint PASSWORD = 8;
			static const uint FULLKEY = 16;
			static const uint COMMENT = 32;

			static uint getIx(const string& srefs);
			static void getIcs(const uint ix, set<uint>& ics);
			static string getSrefs(const uint ix);
		};

	public:
		ImeIMUser();
		~ImeIMUser();

	public:
		vector<ImeitemIMUser*> nodes;

	public:
		void clear();

		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, string basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMUsergroup (full: ImeitemIMsdcIniMUsergroup)
		*/
	class ImeitemIMUsergroup : public MsdcMUsergroup {

	public:
		ImeitemIMUsergroup(const string& sref = "", const string& Comment = "");
		ImeitemIMUsergroup(DbsMsdc* dbsmsdc, const ubigint ref);

	public:
		uint lineno;
		uint ixWIelValid;

		ImeIAMUsergroupAccess imeiamusergroupaccess;
		ImeIMUser imeimuser;

	public:
		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const string& basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const uint num, const bool shorttags = true);
	};

	/**
		* ImeIMUsergroup (full: ImeIMsdcIniMUsergroup)
		*/
	class ImeIMUsergroup {

	public:
		/**
			* VecWIel (full: VecWImeIMsdcIniMUsergroupIel)
			*/
		class VecWIel {

		public:
			static const uint SREF = 1;
			static const uint COMMENT = 2;

			static uint getIx(const string& srefs);
			static void getIcs(const uint ix, set<uint>& ics);
			static string getSrefs(const uint ix);
		};

	public:
		ImeIMUsergroup();
		~ImeIMUsergroup();

	public:
		vector<ImeitemIMUsergroup*> nodes;

	public:
		void clear();

		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, string basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

public:
	IexMsdcIni(XchgMsdc* xchg, DbsMsdc* dbsmsdc, const ubigint jrefSup, const uint ixMsdcVLocale);
	~IexMsdcIni();

public:
	uint lineno;
	uint impcnt;

	ImeIAVControlPar imeiavcontrolpar;
	ImeIAVKeylistKey imeiavkeylistkey;
	ImeIAVValuelistVal imeiavvaluelistval;
	ImeIMFile imeimfile;
	ImeIMUsergroup imeimusergroup;

public:
	// IP cust --- INSERT

public:
	void reset();

	void import(DbsMsdc* dbsmsdc);

	void collect(DbsMsdc* dbsmsdc, const map<uint,uint>& icsMsdcVIop = icsMsdcVIopInsAll());

public:
	bool readTxt(Txtrd& txtrd);
	void readXML(xmlXPathContext* docctx, string basexpath);

	bool readTxtFile(const string& fullpath);
	bool readXMLFile(const string& fullpath);

	void writeTxt(fstream& outfile);
	void writeXML(xmlTextWriter* wr, const bool shorttags);

	void writeTxtFile(const string& fullpath);
	void writeXMLFile(const string& fullpath, const bool shorttags);

	static map<uint,uint> icsMsdcVIopInsAll();
	uint getIxMsdcVIop(const map<uint,uint>& icsMsdcVIop, const uint ixVIme, uint& ixMsdcVIop);

public:
	void handleRequest(DbsMsdc* dbsmsdc, ReqMsdc* req);

	void handleCall(DbsMsdc* dbsmsdc, Call* call);
};

#endif

