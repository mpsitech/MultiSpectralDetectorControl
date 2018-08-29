/**
  * \file Msdc.cpp
  * Msdc global functionality (implementation)
  * \author Alexander Wirthmueller
  * \date created: 29 Aug 2018
  * \date modified: 29 Aug 2018
  */

#include "Msdc.h"

/******************************************************************************
 namespace Acv
 ******************************************************************************/

ubigint Acv::addfile(
			DbsMsdc* dbsmsdc
			, const string& acvpath
			, const string& path
			, const uint refIxVTbl
			, const ubigint refUref
			, const string& osrefKContent
			, const string& Filename
			, const string& srefKMimetype
			, const string& Comment
		) {
	ubigint retval = 0;

	MsdcMFile* fil = NULL;

	uint Archived;
	uint Size;

	ostringstream str;
	string s;

	int res;

	// set archived time to current time
	Archived = time(NULL);

	// determine file size in kB
	struct stat st;
	stat(path.c_str(), &st);
	Size = st.st_size / 1024;

	fil = new MsdcMFile(0, 0, 0, 0, refIxVTbl, refUref, osrefKContent, Archived, Filename, "", srefKMimetype, Size, Comment);
	dbsmsdc->tblmsdcmfile->insertRec(fil);
	
	// adjust archive name in record
	str.str(""); str.fill('0'); str.width(8); str << right << fil->ref; str.width(0);
	if (Filename.rfind('.') != string::npos) str << Filename.substr(Filename.rfind('.'));

	fil->Archivename = str.str();
	dbsmsdc->tblmsdcmfile->updateRec(fil);

	// create folder if required
	str.str(""); str << acvpath << "/";
	str.fill('0'); str.width(5); str << right << ((fil->ref-(fil->ref%1000)) / 1000); str.width(0);

#ifdef _WIN32
	if (access(str.str().c_str(), R_OK | W_OK) == -1) mkdir(str.str().c_str());
#else
	if (access(str.str().c_str(), R_OK | W_OK) == -1) mkdir(str.str().c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
#endif

	// copy file
	s = "cp -p " + path + " " + str.str() + "/" + fil->Archivename;

	res = system(s.c_str());
	if (res != 0) cout << "Acv::addfile() error copying file (" << res << ")" << endl;

	retval = fil->ref;
	delete fil;

	return retval;
};

void Acv::alterfile(
			DbsMsdc* dbsmsdc
			, const string& acvpath
			, const string& path
			, const ubigint ref
		) {
	MsdcMFile* fil = NULL;

	uint Archived;
	uint Size;

	ostringstream str;
	string s;

	int res;

	// set archived time to current time
	Archived = time(NULL);

	// determine file size in kB
	struct stat st;
	stat(path.c_str(), &st);
	Size = st.st_size / 1024;

	// load record
	dbsmsdc->tblmsdcmfile->loadRecByRef(ref, &fil);

	if (fil) {
		// update record
		fil->Archived = Archived;

		str.str(""); str.fill('0'); str.width(8); str << right << fil->ref; str.width(0);
		if (fil->Filename.rfind('.') != string::npos) str << fil->Filename.substr(fil->Filename.rfind('.'));
		fil->Archivename = str.str();

		fil->Size = Size;

		dbsmsdc->tblmsdcmfile->updateRec(fil);

		// create folder if required
		str.str(""); str << acvpath << "/";
		str.fill('0'); str.width(5); str << right << ((fil->ref-(fil->ref%1000)) / 1000); str.width(0);

#ifdef _WIN32
		if (access(str.str().c_str(), R_OK | W_OK) == -1) mkdir(str.str().c_str());
#else
		if (access(str.str().c_str(), R_OK | W_OK) == -1) mkdir(str.str().c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
#endif

		// copy file
		s = "cp -p " + path + " " + str.str() + "/" + fil->Archivename;

		res = system(s.c_str());
		if (res != 0) cout << "Acv::alterfile() error copying file (" << res << ")" << endl;

		delete fil;
	};
};

string Acv::getfile(
			DbsMsdc* dbsmsdc
			, const ubigint refMsdcMFile
		) {
	MsdcMFile* fil = NULL;

	ostringstream str;

	dbsmsdc->tblmsdcmfile->loadRecByRef(refMsdcMFile, &fil);

	if (fil) {
		str.fill('0');
		str.width(5);
		str << right << ((fil->ref-(fil->ref%1000)) / 1000);
		
		str.width(0);
		str << "/" << fil->Archivename;

		delete fil;
	};

	return(str.str());
};

/******************************************************************************
 namespace Lop
 ******************************************************************************/

void Lop::apply(
			const uint ixMsdcVLop
			, vector<ubigint>& refsList
			, vector<ubigint>& refsPool
			, const ubigint ref
		) {
	if (ixMsdcVLop == VecMsdcVLop::INS) insert(refsList, refsPool, ref);
	else if (ixMsdcVLop == VecMsdcVLop::RMV) remove(refsList, refsPool, ref);
};

void Lop::insert(
			vector<ubigint>& refsList
			, vector<ubigint>& refsPool
			, const ubigint ref
		) {
	for (unsigned int i=0;i<refsPool.size();i++) {
		if (refsPool[i] == ref) {
			refsList[i] = ref;
			refsPool[i] = 0;
			break;
		};
	};
};

void Lop::remove(
			vector<ubigint>& refsList
			, vector<ubigint>& refsPool
			, const ubigint ref
		) {
	for (unsigned int i=0;i<refsList.size();i++) {
		if (refsList[i] == ref) {
			refsPool[i] = ref;
			refsList[i] = 0;
			break;
		};
	};
};

/******************************************************************************
 namespace Oolop
 ******************************************************************************/

void Oolop::apply(
			const uint ixMsdcVOolop
			, vector<ubigint>& refsList
			, vector<ubigint>& refsPool
			, const ubigint ref1
			, const ubigint ref2
		) {
	if (ixMsdcVOolop == VecMsdcVOolop::INB) insertBefore(refsList, refsPool, ref1, ref2);
	else if (ixMsdcVOolop == VecMsdcVOolop::INA) insertAfter(refsList, refsPool, ref1, ref2);
	else if (ixMsdcVOolop == VecMsdcVOolop::RMV) remove(refsList, refsPool, ref1);
	else if (ixMsdcVOolop == VecMsdcVOolop::TOB) toBefore(refsList, ref1, ref2);
	else if (ixMsdcVOolop == VecMsdcVOolop::TOA) toAfter(refsList, ref1, ref2);
	else if (ixMsdcVOolop == VecMsdcVOolop::SWP) swap(refsList, ref1, ref2);
};

void Oolop::insertBefore(
			vector<ubigint>& refsList
			, vector<ubigint>& refsPool
			, const ubigint ref1
			, const ubigint ref2
		) {
	for (auto itPool=refsPool.begin();itPool!=refsPool.end();itPool++) {
		if (*itPool == ref1) {
			if (ref2 == 0) {
				refsList.insert(refsList.begin(), ref1);
				refsPool.erase(itPool);
			} else {
				for (auto itList=refsList.begin();itList!=refsList.end();itList++) {
					if (*itList == ref2) {
						refsList.insert(itList, ref1);
						refsPool.erase(itPool);
						break;
					};
				};
			};
			break;
		};
	};
};

void Oolop::insertAfter(
			vector<ubigint>& refsList
			, vector<ubigint>& refsPool
			, const ubigint ref1
			, const ubigint ref2
		) {
	for (auto itPool=refsPool.begin();itPool!=refsPool.end();itPool++) {
		if (*itPool == ref1) {
			if (ref2 == 0) {
				refsList.push_back(ref1);
				refsPool.erase(itPool);
			} else {
				for (auto itList=refsList.begin();itList!=refsList.end();itList++) {
					if (*itList == ref2) {
						refsList.insert(++itList, ref1);
						refsPool.erase(itPool);
						break;
					};
				};
			};
			break;
		};
	};
};

void Oolop::remove(
			vector<ubigint>& refsList
			, vector<ubigint>& refsPool
			, const ubigint ref
		) {
	for (auto itList=refsList.begin();itList!=refsList.end();itList++) {
		if (*itList == ref) {
			refsList.erase(itList);
			refsPool.push_back(ref);
		};
	};
};

void Oolop::toBefore(
			vector<ubigint>& refsList
			, const ubigint ref1
			, const ubigint ref2
		) {
	// *******2*****1****
	// *******12*********
	for (unsigned int i=0;i<refsList.size();i++) {
		if (refsList[i] == ref2) {
			for (unsigned int j=i+1;j<refsList.size();j++) {
				if (refsList[j] == ref1) {
					for (unsigned int k=i+1;k<j;k++) refsList[k+1] = refsList[k];
					refsList[i] = ref1;
					refsList[i+1] = ref2;
					break;
				};
			};
			break;
		};
	};
};

void Oolop::toAfter(
			vector<ubigint>& refsList
			, const ubigint ref1
			, const ubigint ref2
		) {
	// *******1*****2****
	// ************21****
	for (unsigned int i=0;i<refsList.size();i++) {
		if (refsList[i] == ref1) {
			for (unsigned int j=i+1;j<refsList.size();j++) {
				if (refsList[j] == ref2) {
					for (unsigned int k=i+1;k<j;k++) refsList[k-1] = refsList[k];
					refsList[j] = ref1;
					refsList[j-1] = ref2;
					break;
				};
			};
			break;
		};
	};
};

void Oolop::swap(
			vector<ubigint>& refsList
			, const ubigint ref1
			, const ubigint ref2
		) {
	for (auto itList=refsList.begin();itList!=refsList.end();itList++) {
		if (*itList == ref1) {
			for (auto itList2=refsList.begin();itList2!=refsList.end();itList2++) {
				if (*itList2 == ref2) {
					*itList = ref2;
					*itList2 = ref1;
					break;
				};
			};
			break;
		};
	};
};

/******************************************************************************
 namespace Tmp
 ******************************************************************************/

string Tmp::newfile(
			const string& tmppath
			, const string& ext
		) {
	string filename;
	fstream tmpfile;

	unsigned int pathlen = tmppath.length() + 1;

	FILE* file;

	bool valid = false;

	while (!valid) {
		filename = tmppath + "/" + random();
		if (ext.length() > 0) filename += "." + ext;

		file = fopen(filename.c_str(), "w+x");

		if (file) {
			fclose(file);
			valid = true;
		} else if (errno != EEXIST) break;
	};

	return(filename.substr(pathlen));
};

string Tmp::newfolder(
			const string& tmppath
		) {
	string foldername;

	unsigned int pathlen = tmppath.length() + 1;

	bool valid = false;

	while (!valid) {
		foldername = tmppath + "/" + random();

		// mkdir() fails if folder exists
#ifdef _WIN32
		valid = (mkdir(foldername.c_str()) == 0);
#else
		valid = (mkdir(foldername.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH) == 0);
#endif

		if (!valid) if (errno != EEXIST) break;
	};

	return(foldername.substr(pathlen));
};

string Tmp::random() {
	string retval;

	int digit;

	// random seed is done in engine initialization

	// fetch digits and make sure their ASCII code is in the range 0..9/a..z
	for (unsigned int i=0;i<8;i++) {
		digit = rand() % 36 + 48;
		if (digit > 57) digit += (97-48-10);

		retval = retval + ((char) digit);
	};

	return retval;
};

// IP cust --- IBEGIN
/******************************************************************************
 class Imgbufitem
 ******************************************************************************/

Imgbufitem::Imgbufitem(
			const unsigned int seqno
			, const double t
			, unsigned char* data
			, const size_t datalen
			, const ubigint jref
		) {
	this->seqno = seqno;
	this->t = t;
	this->data = data;
	this->datalen = datalen;

	claim(jref);
};

void Imgbufitem::claim(
			const ubigint jref
		) {
	bool found = false;

	for (list<ubigint>::iterator it=jrefsClaim.begin() ; it!=jrefsClaim.end() ; it++) {
		if (*it > jref) {
			jrefsClaim.insert(it, jref);
			found = true;
			break;
		};
	};

	if (!found) jrefsClaim.push_back(jref);
};

void Imgbufitem::release(
			const ubigint jref
		) {
	for (list<ubigint>::iterator it=jrefsClaim.begin() ; it!=jrefsClaim.end() ; it++) {
		if (*it == jref) {
			jrefsClaim.erase(it);
			break;
		} else if (*it > jref) break;
	};
};

/******************************************************************************
 class Imgbuf
 ******************************************************************************/

Imgbuf::Imgbuf() {
	N = 0;
	itemlen = 0;

	brefseq = 0;

	initdone = false;
};

Imgbuf::~Imgbuf() {
	term();
};

void Imgbuf::init(
			const unsigned int N
			, const unsigned int itemlen
		) {
	int res;
	pthread_mutexattr_t attr;

	pthread_mutexattr_init(&attr);
	pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE);

	data = new unsigned char[N*itemlen];
	this->N = N;
	this->itemlen = itemlen;

	res = pthread_mutex_init(&mAccess, &attr);
	if (res != 0) {cout << "Imgbuf::init() error initializing mutex mAccess (" << res << ")" << endl;};

	brefseq = 0;

	brefs.clear();
	brefs.resize(N, 0);

	brefsItems.clear();

	pthread_mutexattr_destroy(&attr);
	
	initdone = true;
};

void Imgbuf::term() {
	int res;

	if (initdone) {
		res = pthread_mutex_lock(&mAccess);
		if (res != 0) {cout << "Imgbuf::term() error locking mutex mAccess (" << res << ")" << endl;};

		res = pthread_mutex_unlock(&mAccess);
		if (res != 0) {cout << "Imgbuf::term() error unlocking mutex mAccess (" << res << ")" << endl;};

		while (true) {
			res = pthread_mutex_destroy(&mAccess);
			if (res == EBUSY) {
				res = pthread_mutex_unlock(&mAccess);
				if (res != 0) {cout << "Imgbuf::term() error unlocking mutex mAccess (" << res << ")" << endl;};
			} else {
				if (res != 0) {cout << "Imgbuf::term() error destroying mutex mAccess (" << res << ")" << endl;};
				break;
			};
		};

		delete[] data;
		for (map<ubigint,Imgbufitem*>::iterator it=brefsItems.begin() ; it!=brefsItems.end() ; it++) delete(it->second);
		
		initdone = false;
	};
};

ubigint Imgbuf::getNewItem(
			const ubigint jref
			, const unsigned int seqno
			, double t
		) {
	int res;
	ubigint bref;

	unsigned int ix;
	bool found;

	if (initdone) {
		res = pthread_mutex_lock(&mAccess);
		if (res != 0) {cout << "Imgbuf::getNewItem() error locking mutex mAccess (" << res << ")" << endl;};

		// check for available slot
		bref = 0;

		found = false;

		for (ix=0;ix<N;ix++) {
			if (brefs[ix] == 0) {
				found = true;
				break;
			};
		};

		if (!found) {
			ix = cleanup();
			found = (ix < N);
		};

		if (found) {
			// get new bref
			brefseq++;
			bref = brefseq;

			brefs[ix] = bref;

			// create new item
			if (t == 0.0) t = Msdc::getNow();
			brefsItems[bref] = new Imgbufitem(seqno, t, &(data[ix*itemlen]), itemlen, jref);
		};

		res = pthread_mutex_unlock(&mAccess);
		if (res != 0) {cout << "Imgbuf::getNewItem() error unlocking mutex mAccess (" << res << ")" << endl;};

		return(bref);
	};

	return 0;
};

Imgbufitem* Imgbuf::getItem(
			const ubigint bref
		) {
	// assuming that claim is already made or mAccess is locked

	map<ubigint,Imgbufitem*>::iterator it;

	if (initdone) {
		it = brefsItems.find(bref);
		if (it != brefsItems.end()) return it->second;
	};

	return NULL;
};

void Imgbuf::claim(
			const ubigint bref
			, const ubigint jref
		) {
	int res;

	Imgbufitem* item = NULL;

	if (initdone) {
		res = pthread_mutex_lock(&mAccess);
		if (res != 0) {cout << "Imgbuf::claim() error locking mutex mAccess (" << res << ")" << endl;};

		item = getItem(bref);
		if (item) item->claim(jref);

		res = pthread_mutex_unlock(&mAccess);
		if (res != 0) {cout << "Imgbuf::claim() error unlocking mutex mAccess (" << res << ")" << endl;};
	};
};

void Imgbuf::release(
			const ubigint bref
			, const ubigint jref
		) {
	int res;

	Imgbufitem* item = NULL;

	if (initdone) {
		res = pthread_mutex_lock(&mAccess);
		if (res != 0) {cout << "Imgbuf::release() error locking mutex mAccess (" << res << ")" << endl;};

		item = getItem(bref);
		if (item) item->release(jref);

		res = pthread_mutex_unlock(&mAccess);
		if (res != 0) {cout << "Imgbuf::release() error unlocking mutex mAccess (" << res << ")" << endl;};
	};
};

void Imgbuf::releaseByJref(
			const ubigint jref
		) {
	int res;

	Imgbufitem* item = NULL;

	if (initdone) {
		res = pthread_mutex_lock(&mAccess);
		if (res != 0) {cout << "Imgbuf::releaseByJref() error locking mutex mAccess (" << res << ")" << endl;};

		for (map<ubigint,Imgbufitem*>::iterator it=brefsItems.begin() ; it!=brefsItems.end() ; it++) {
			item = it->second;
			item->release(jref);
		};

		res = pthread_mutex_unlock(&mAccess);
		if (res != 0) {cout << "Imgbuf::releaseByJref() error unlocking mutex mAccess (" << res << ")" << endl;};
	};
};

unsigned int Imgbuf::cleanup() {
	unsigned int ix = 0;

	map<ubigint,Imgbufitem*>::iterator it;

	Imgbufitem* item = NULL;

	if (initdone) {
		// all entries in brefs are != 0
		for (;ix<N;ix++) {
			it = brefsItems.find(brefs[ix]);

			if (it != brefsItems.end()) {
				item = it->second;

				if (item->jrefsClaim.empty()) {
					brefsItems.erase(it);
					delete item;

					brefs[ix] = 0;

					break;
				};
			} else break;
		};
	};

	return ix;
};

/******************************************************************************
 class Snippet
 ******************************************************************************/

Snippet::Snippet(
			const uint ixMsdcVCamres
			, const uint ixMsdcVChannel
			, const unsigned int w
			, const unsigned int h
			, const unsigned int x0
			, const unsigned int y0
		) {
	int res;
	pthread_mutexattr_t attr;

	unsigned int wh;

	pthread_mutexattr_init(&attr);
	pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE);

	this->ixMsdcVCamres = ixMsdcVCamres;
	this->ixMsdcVChannel = ixMsdcVChannel;

	this->w = w;
	this->h = h;

	if (w == 0) Msdc::getCamresWh(ixMsdcVCamres, this->w, this->h);

	wh = this->w * this->h;

	if (wh == 0) data = NULL;
	else data = new unsigned char[wh];

	this->x0 = x0;
	this->y0 = y0;

	res = pthread_mutex_init(&mAccess, &attr);
	if (res != 0) {cout << "Snippet::Snippet() error initializing mutex mAccess (" << res << ")" << endl;};

	jrefClaim = 0;

	pthread_mutexattr_destroy(&attr);
};

Snippet::~Snippet() {
	int res;

	res = pthread_mutex_lock(&mAccess);
	if (res != 0) {cout << "Snippet::~Snippet() error locking mutex mAccess (" << res << ")" << endl;};

	res = pthread_mutex_unlock(&mAccess);
	if (res != 0) {cout << "Snippet::~Snippet() error unlocking mutex mAccess (" << res << ")" << endl;};

	while (true) {
		res = pthread_mutex_destroy(&mAccess);
		if (res == EBUSY) {
			res = pthread_mutex_unlock(&mAccess);
			if (res != 0) {cout << "Snippet::~Snippet() error unlocking mutex mAccess (" << res << ")" << endl;};
		} else {
			if (res != 0) {cout << "Snippet::~Snippet() error destroying mutex mAccess (" << res << ")" << endl;};
			break;
		};
	};

	if (data) delete[] data;
};

void Snippet::reposition(
			const unsigned int _x0
			, const unsigned int _y0
		) {
	x0 = _x0;
	y0 = _y0;
};

void Snippet::clear() {
	unsigned int wh = w*h;

	if (data) memset((void*) data, 0, wh);
};

bool Snippet::claim(
			const ubigint jref
		) {
	bool retval;

	int res;

	res = pthread_mutex_lock(&mAccess);
	if (res != 0) cout << "Snippet::claim() error locking mutex mAccess (" << res << ")" << endl;

	if (jrefClaim == 0) {
		jrefClaim = jref;
		retval = true;
	} else retval = false;

	res = pthread_mutex_unlock(&mAccess);
	if (res != 0) cout << "Snippet::claim() error unlocking mutex mAccess (" << res << ")" << endl;

	return retval;
};

void Snippet::release() {
	int res;

	res = pthread_mutex_lock(&mAccess);
	if (res != 0) cout << "Snippet::release() error locking mutex mAccess (" << res << ")" << endl;

	jrefClaim = 0;

	res = pthread_mutex_unlock(&mAccess);
	if (res != 0) cout << "Snippet::release() error unlocking mutex mAccess (" << res << ")" << endl;
};

// IP cust --- IEND

/******************************************************************************
 namespace Msdc
 ******************************************************************************/

// IP gbl --- IBEGIN
double Msdc::getNow() {
	timespec ts;
	clock_gettime(CLOCK_REALTIME, &ts);

	return(((double) ts.tv_sec) + 1.0e-9*((double) ts.tv_nsec));
};

double Msdc::invusecstamp(
			const string& s
		) {
	// turn '1-1-2010 9:34:07 1234' into system time (ex.)
	double retval = 0.0;

	vector<string> ss;

	StrMod::stringToVector(s, ss, ' ');

	if (ss.size() == 3) {
		retval = Ftm::invstamp(ss[0] + " " + ss[1]);
		retval += 1e-6 * atoi(ss[2].c_str());
	};

	return retval;
};

void Msdc::getCamresWh(
			const uint ixMsdcVCamres
			, unsigned int& w
			, unsigned int& h
			, const unsigned int _w
			, const unsigned int _h
		) {
	switch (ixMsdcVCamres) {
		case VecMsdcVCamres::_160: w = 160; h = 120; break;
		case VecMsdcVCamres::_320: w = 320; h = 240; break;
		case VecMsdcVCamres::_640: w = 640; h = 480; break;
		case VecMsdcVCamres::_800: w = 800; h = 600; break;
		case VecMsdcVCamres::_1024: w = 1024; h = 768; break;
		case VecMsdcVCamres::MAX: w = _w; h = _h; break;
		default: w = 0; h = 0;
	};
};

void Msdc::setupIntavg(
			const unsigned int inN
			, const unsigned int inMax
			, const unsigned int outMax
			, const double outPmin
			, unsigned int& im
			, bool* rshs
			, unsigned int& rshsN
		) {
	double insum, p;

	double doutMax = outMax;

	double scl = inMax * inN;

	double m;

	// integer multiplier
	im = outMax / scl;

	insum = im * scl;
	p = insum / doutMax;

	// sub-integer multipliers
	m = 0.5;

	for (unsigned int i=0;i<rshsN;i++) {
		if ((p < outPmin) && ((insum + m*scl) < doutMax)) {
			rshs[i] = true;
			insum += m*scl;
			p = insum / doutMax;

		} else {
			rshs[i] = false;
		};

		m *= 0.5;
	};

	for (unsigned int i=rshsN;i>0;i--) if (!rshs[i-1]) rshsN--; else break;

	// dump result
/*
	double d = im;

	m = 0.5;
	for (unsigned int i=0 ; i<rshsN ; i++) {
		if (rshs[i]) d += m;
		m *= 0.5;
	};

	cout << "\tfor inN=" << inN << ", inMax=" << inMax << ", outMax=" << outMax << ", calculated im=" << im << " and rshs=";
	for (unsigned int i=0;i<rshsN;i++) if (rshs[i]) cout << "1"; else cout << "0";
	cout << ", corresponding to m=" << d << endl;
*/
};

unsigned int Msdc::intavg(
			const unsigned int in
			, const unsigned int im
			, bool* rshs
			, const unsigned int rshsN
		) {
	unsigned int retval = im*in;

	for (unsigned int i=0;i<rshsN;i++) if (rshs[i]) retval += (in >> (i+1));

	return retval;
};

void Msdc::copytrfBuf(
			unsigned char* src
			, unsigned char* trg
			, const unsigned int wlen
			, const unsigned int w
			, const unsigned int h
			, const uint ixMsdcVSqrgrp
		) {
	unsigned int i, invi;
	unsigned int j, invj;

	unsigned int* k = NULL;
	unsigned int* l = NULL;

	unsigned int ix;

	bool skip = false;

	if ((w == h) && (ixMsdcVSqrgrp == VecMsdcVSqrgrp::R1)) {
		k = &invj;
		l = &i;
	} else if (ixMsdcVSqrgrp == VecMsdcVSqrgrp::R2) {
		k = &invi;
		l = &invj;
	} else if ((w == h) && (ixMsdcVSqrgrp == VecMsdcVSqrgrp::R3)) {
		k = &j;
		l = &invi;
	} else if (ixMsdcVSqrgrp == VecMsdcVSqrgrp::S0) {
		k = &i;
		l = &invj;
	} else if ((w == h) && (ixMsdcVSqrgrp == VecMsdcVSqrgrp::S1)) {
		k = &j;
		l = &i;
	} else if (ixMsdcVSqrgrp == VecMsdcVSqrgrp::S2) {
		k = &invi;
		l = &j;
	} else if ((w == h) && (ixMsdcVSqrgrp == VecMsdcVSqrgrp::S3)) {
		k = &invj;
		l = &invi;
	} else {
		// R0 and invalid ; perform straight copy
		memcpy(trg, src, wlen*w*h);
		skip = true;
	};

	if (!skip) {
		for (i=0,invi=h-1 ; i<h ; i++,invi--) {
			for (j=0,invj=w-1 ; j<w ; j++,invj--) {
				ix = (*k)*w + (*l);
				for (unsigned int m=0;m<wlen;m++) trg[wlen*ix+m] = src[wlen*(i*w+j)+m];
			};
		};
	};
};

void Msdc::addBindataDatAPar(
			DbsMsdc* dbsmsdc
			, const ubigint refMsdcMData
			, const double x1Start
			, const string& x2SrefKKey
			, const unsigned char* buf
			, const size_t buflen
		) {
	char* outbuf = NULL;
	unsigned int outbuflen;

	toBase64(buf, buflen, &outbuf, outbuflen);
	if (outbuf) {
		dbsmsdc->tblmsdcamdatapar->insertNewRec(NULL, refMsdcMData, x1Start, x2SrefKKey, 0, "", string(outbuf, outbuflen));

		delete[] outbuf;
		outbuf = NULL;
	};
};
// IP gbl --- IEND

/******************************************************************************
 namespace OpengMsdc
 ******************************************************************************/

void OpengMsdc::getIcsMsdcVOppackByIxMsdcVOpengtype(
			const uint ixMsdcVOpengtype
			, vector<uint>& icsMsdcVOppack
		) {
	icsMsdcVOppack.clear();

};

void OpengMsdc::getIcsMsdcVDpchByIxMsdcVOppack(
			const uint ixMsdcVOppack
			, set<uint>& icsMsdcVDpch
		) {
};

/******************************************************************************
 namespace StubMsdc
 ******************************************************************************/

string StubMsdc::getStub(
			DbsMsdc* dbsmsdc
			, const uint ixMsdcVStub
			, const ubigint ref
			, const uint ixMsdcVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	if (ixMsdcVStub == VecMsdcVStub::STUBMSDCDATSTD) return getStubDatStd(dbsmsdc, ref, ixMsdcVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixMsdcVStub == VecMsdcVStub::STUBMSDCFILSTD) return getStubFilStd(dbsmsdc, ref, ixMsdcVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixMsdcVStub == VecMsdcVStub::STUBMSDCGRP) return getStubGrp(dbsmsdc, ref, ixMsdcVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixMsdcVStub == VecMsdcVStub::STUBMSDCOWN) return getStubOwn(dbsmsdc, ref, ixMsdcVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixMsdcVStub == VecMsdcVStub::STUBMSDCPRDSTD) return getStubPrdStd(dbsmsdc, ref, ixMsdcVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixMsdcVStub == VecMsdcVStub::STUBMSDCPRSSTD) return getStubPrsStd(dbsmsdc, ref, ixMsdcVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixMsdcVStub == VecMsdcVStub::STUBMSDCSESMENU) return getStubSesMenu(dbsmsdc, ref, ixMsdcVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixMsdcVStub == VecMsdcVStub::STUBMSDCSESSTD) return getStubSesStd(dbsmsdc, ref, ixMsdcVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixMsdcVStub == VecMsdcVStub::STUBMSDCUSGSTD) return getStubUsgStd(dbsmsdc, ref, ixMsdcVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixMsdcVStub == VecMsdcVStub::STUBMSDCUSRSTD) return getStubUsrStd(dbsmsdc, ref, ixMsdcVLocale, ixVNonetype, stcch, strefSub, refresh);

	return("");
};

string StubMsdc::getStubDatStd(
			DbsMsdc* dbsmsdc
			, const ubigint ref
			, const uint ixMsdcVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "I and V 15-9-2017 12:37:00"
	string stub;

	MsdcMData* rec = NULL;

	stcchitemref_t stref(VecMsdcVStub::STUBMSDCDATSTD, ref, ixMsdcVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixMsdcVLocale == VecMsdcVLocale::ENUS) stub = "(none)";
		else if (ixMsdcVLocale == VecMsdcVLocale::DECH) stub = "(keine)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixMsdcVLocale == VecMsdcVLocale::ENUS) stub = "(no raw data)";
		else if (ixMsdcVLocale == VecMsdcVLocale::DECH) stub = "(keine Rohdaten)";
	};

	if (ref != 0) {
		if (dbsmsdc->tblmsdcmdata->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
			// IP getStubDatStd --- IBEGIN
			stub = dbsmsdc->getKlstTitleBySref(VecMsdcVKeylist::KLSTMSDCKACQFEAT, rec->srefMsdcKAcqfeat, ixMsdcVLocale);
			stub += " " + Ftm::stamp(rec->start);
			// IP getStubDatStd --- IEND
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubMsdc::getStubFilStd(
			DbsMsdc* dbsmsdc
			, const ubigint ref
			, const uint ixMsdcVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "customers.xlsx"
	string stub;

	stcchitemref_t stref(VecMsdcVStub::STUBMSDCFILSTD, ref, ixMsdcVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixMsdcVLocale == VecMsdcVLocale::ENUS) stub = "(none)";
		else if (ixMsdcVLocale == VecMsdcVLocale::DECH) stub = "(keine)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixMsdcVLocale == VecMsdcVLocale::ENUS) stub = "(no file)";
		else if (ixMsdcVLocale == VecMsdcVLocale::DECH) stub = "(keine Datei)";
	};

	if (ref != 0) {
		if (dbsmsdc->tblmsdcmfile->loadFnmByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubMsdc::getStubGrp(
			DbsMsdc* dbsmsdc
			, const ubigint ref
			, const uint ixMsdcVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "agroup"
	string stub;

	stcchitemref_t stref(VecMsdcVStub::STUBMSDCGRP, ref, ixMsdcVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixMsdcVLocale == VecMsdcVLocale::ENUS) stub = "(none)";
		else if (ixMsdcVLocale == VecMsdcVLocale::DECH) stub = "(keine)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixMsdcVLocale == VecMsdcVLocale::ENUS) stub = "(no user group)";
		else if (ixMsdcVLocale == VecMsdcVLocale::DECH) stub = "(keine Benutzergruppe)";
	};

	if (ref != 0) {
		if (dbsmsdc->tblmsdcmusergroup->loadSrfByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubMsdc::getStubOwn(
			DbsMsdc* dbsmsdc
			, const ubigint ref
			, const uint ixMsdcVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "auser"
	string stub;

	stcchitemref_t stref(VecMsdcVStub::STUBMSDCOWN, ref, ixMsdcVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixMsdcVLocale == VecMsdcVLocale::ENUS) stub = "(none)";
		else if (ixMsdcVLocale == VecMsdcVLocale::DECH) stub = "(keiner)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixMsdcVLocale == VecMsdcVLocale::ENUS) stub = "(no user)";
		else if (ixMsdcVLocale == VecMsdcVLocale::DECH) stub = "(kein Benutzer)";
	};

	if (ref != 0) {
		if (dbsmsdc->tblmsdcmuser->loadSrfByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubMsdc::getStubPrdStd(
			DbsMsdc* dbsmsdc
			, const ubigint ref
			, const uint ixMsdcVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "15-9-2017 12:34:56 (active)"
	string stub;

	MsdcMPeriod* rec = NULL;

	stcchitemref_t stref(VecMsdcVStub::STUBMSDCPRDSTD, ref, ixMsdcVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixMsdcVLocale == VecMsdcVLocale::ENUS) stub = "(none)";
		else if (ixMsdcVLocale == VecMsdcVLocale::DECH) stub = "(keine)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixMsdcVLocale == VecMsdcVLocale::ENUS) stub = "(no acquisition period)";
		else if (ixMsdcVLocale == VecMsdcVLocale::DECH) stub = "(keine Aufzeichnungsperiode)";
	};

	if (ref != 0) {
		if (dbsmsdc->tblmsdcmperiod->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
			// IP getStubPrdStd --- IBEGIN
			stub = Ftm::stamp(rec->start);

			if (rec->stop == 0) {
				if (ixMsdcVLocale == VecMsdcVLocale::ENUS) stub += " (active)";
				else if (ixMsdcVLocale == VecMsdcVLocale::DECH) stub += " (aktiv)";

			} else {
				if (ixMsdcVLocale == VecMsdcVLocale::ENUS) stub += " until ";
				else if (ixMsdcVLocale == VecMsdcVLocale::DECH) stub += " bis ";

				stub += Ftm::stamp(rec->stop);
			};
			// IP getStubPrdStd --- IEND
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubMsdc::getStubPrsStd(
			DbsMsdc* dbsmsdc
			, const ubigint ref
			, const uint ixMsdcVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "Franz Kuntz"
	string stub;

	MsdcMPerson* rec = NULL;

	stcchitemref_t stref(VecMsdcVStub::STUBMSDCPRSSTD, ref, ixMsdcVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixMsdcVLocale == VecMsdcVLocale::ENUS) stub = "(none)";
		else if (ixMsdcVLocale == VecMsdcVLocale::DECH) stub = "(keine)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixMsdcVLocale == VecMsdcVLocale::ENUS) stub = "(no person)";
		else if (ixMsdcVLocale == VecMsdcVLocale::DECH) stub = "(keine Person)";
	};

	if (ref != 0) {
		if (dbsmsdc->tblmsdcmperson->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
			// IP getStubMsdcPrsStd --- BEGIN
			stub = rec->Lastname;
			if (rec->Firstname.length() > 0) stub = rec->Firstname + " " + stub;
			// IP getStubMsdcPrsStd --- END
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubMsdc::getStubSesMenu(
			DbsMsdc* dbsmsdc
			, const ubigint ref
			, const uint ixMsdcVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "user fkuntz / Franz Kuntz;logged in from 127.0.0.1;since 01-01-2010 10:34"
	string stub;

	MsdcMSession* rec = NULL;

	stcchitemref_t stref(VecMsdcVStub::STUBMSDCSESMENU, ref, ixMsdcVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixMsdcVLocale == VecMsdcVLocale::ENUS) stub = "(none)";
		else if (ixMsdcVLocale == VecMsdcVLocale::DECH) stub = "(keine)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixMsdcVLocale == VecMsdcVLocale::ENUS) stub = "(no session)";
		else if (ixMsdcVLocale == VecMsdcVLocale::DECH) stub = "(keine Sitzung)";
	};

	if (ref != 0) {
		if (dbsmsdc->tblmsdcmsession->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
			// IP getStubMsdcSesMenu --- BEGIN
			if (ixMsdcVLocale == VecMsdcVLocale::ENUS) stub = "user " + getStubUsrStd(dbsmsdc, rec->refMsdcMUser, ixMsdcVLocale, ixVNonetype, stcch, &stref) + ";logged in from " + rec->Ip + ";since " + Ftm::stamp(rec->start);
			else if (ixMsdcVLocale == VecMsdcVLocale::DECH) stub = "Benutzer " + getStubUsrStd(dbsmsdc, rec->refMsdcMUser, ixMsdcVLocale, ixVNonetype, stcch, &stref) + ";eingeloggt von " + rec->Ip + ";seit " + Ftm::stamp(rec->start);
			// IP getStubMsdcSesMenu --- END
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubMsdc::getStubSesStd(
			DbsMsdc* dbsmsdc
			, const ubigint ref
			, const uint ixMsdcVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "01-01-2010 10:34 from 127.0.0.1"
	string stub;

	MsdcMSession* rec = NULL;

	stcchitemref_t stref(VecMsdcVStub::STUBMSDCSESSTD, ref, ixMsdcVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixMsdcVLocale == VecMsdcVLocale::ENUS) stub = "(none)";
		else if (ixMsdcVLocale == VecMsdcVLocale::DECH) stub = "(keine)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixMsdcVLocale == VecMsdcVLocale::ENUS) stub = "(no session)";
		else if (ixMsdcVLocale == VecMsdcVLocale::DECH) stub = "(keine Sitzung)";
	};

	if (ref != 0) {
		if (dbsmsdc->tblmsdcmsession->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
			// IP getStubMsdcSesStd --- BEGIN
			if (ixMsdcVLocale == VecMsdcVLocale::ENUS) stub = Ftm::stamp(rec->start) + " from " + rec->Ip;
			else if (ixMsdcVLocale == VecMsdcVLocale::DECH) stub = Ftm::stamp(rec->start) + " von " + rec->Ip;
			// IP getStubMsdcSesStd --- END
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubMsdc::getStubUsgStd(
			DbsMsdc* dbsmsdc
			, const ubigint ref
			, const uint ixMsdcVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "super"
	string stub;

	stcchitemref_t stref(VecMsdcVStub::STUBMSDCUSGSTD, ref, ixMsdcVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixMsdcVLocale == VecMsdcVLocale::ENUS) stub = "(none)";
		else if (ixMsdcVLocale == VecMsdcVLocale::DECH) stub = "(keine)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixMsdcVLocale == VecMsdcVLocale::ENUS) stub = "(no user group)";
		else if (ixMsdcVLocale == VecMsdcVLocale::DECH) stub = "(keine Benutzergruppe)";
	};

	if (ref != 0) {
		if (dbsmsdc->tblmsdcmusergroup->loadSrfByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubMsdc::getStubUsrStd(
			DbsMsdc* dbsmsdc
			, const ubigint ref
			, const uint ixMsdcVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "fkuntz / Franz Kuntz"
	string stub;

	MsdcMUser* rec = NULL;

	stcchitemref_t stref(VecMsdcVStub::STUBMSDCUSRSTD, ref, ixMsdcVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixMsdcVLocale == VecMsdcVLocale::ENUS) stub = "(none)";
		else if (ixMsdcVLocale == VecMsdcVLocale::DECH) stub = "(keiner)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixMsdcVLocale == VecMsdcVLocale::ENUS) stub = "(no user)";
		else if (ixMsdcVLocale == VecMsdcVLocale::DECH) stub = "(kein Benutzer)";
	};

	if (ref != 0) {
		if (dbsmsdc->tblmsdcmuser->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
			// IP getStubMsdcUsrStd --- BEGIN
			stub = rec->sref + " / " + getStubPrsStd(dbsmsdc, rec->refMsdcMPerson, ixMsdcVLocale, ixVNonetype, stcch, &stref);
			// IP getStubMsdcUsrStd --- END
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

/******************************************************************************
 class ContInfMsdcAlert
 ******************************************************************************/

ContInfMsdcAlert::ContInfMsdcAlert(
			const string& TxtCpt
			, const string& TxtMsg1
			, const string& TxtMsg2
			, const string& TxtMsg3
			, const string& TxtMsg4
			, const string& TxtMsg5
			, const string& TxtMsg6
			, const string& TxtMsg7
			, const string& TxtMsg8
			, const string& TxtMsg9
			, const string& TxtMsg10
			, const string& TxtMsg11
			, const string& TxtMsg12
		) :
			Block()
		{
	this->TxtCpt = TxtCpt;
	this->TxtMsg1 = TxtMsg1;
	this->TxtMsg2 = TxtMsg2;
	this->TxtMsg3 = TxtMsg3;
	this->TxtMsg4 = TxtMsg4;
	this->TxtMsg5 = TxtMsg5;
	this->TxtMsg6 = TxtMsg6;
	this->TxtMsg7 = TxtMsg7;
	this->TxtMsg8 = TxtMsg8;
	this->TxtMsg9 = TxtMsg9;
	this->TxtMsg10 = TxtMsg10;
	this->TxtMsg11 = TxtMsg11;
	this->TxtMsg12 = TxtMsg12;

	mask = {TXTCPT, TXTMSG1, TXTMSG2, TXTMSG3, TXTMSG4, TXTMSG5, TXTMSG6, TXTMSG7, TXTMSG8, TXTMSG9, TXTMSG10, TXTMSG11, TXTMSG12};
};

bool ContInfMsdcAlert::all(
			const set<uint>& items
		) {
	if (!find(items, TXTCPT)) return false;
	if (!find(items, TXTMSG1)) return false;
	if (!find(items, TXTMSG2)) return false;
	if (!find(items, TXTMSG3)) return false;
	if (!find(items, TXTMSG4)) return false;
	if (!find(items, TXTMSG5)) return false;
	if (!find(items, TXTMSG6)) return false;
	if (!find(items, TXTMSG7)) return false;
	if (!find(items, TXTMSG8)) return false;
	if (!find(items, TXTMSG9)) return false;
	if (!find(items, TXTMSG10)) return false;
	if (!find(items, TXTMSG11)) return false;
	if (!find(items, TXTMSG12)) return false;

	return true;
};

void ContInfMsdcAlert::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfMsdcAlert";

	string itemtag;
	if (shorttags)
		itemtag = "Ci";
	else
		itemtag = "ContitemInfMsdcAlert";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtCpt", TxtCpt);
		writeStringAttr(wr, itemtag, "sref", "TxtMsg1", TxtMsg1);
		writeStringAttr(wr, itemtag, "sref", "TxtMsg2", TxtMsg2);
		writeStringAttr(wr, itemtag, "sref", "TxtMsg3", TxtMsg3);
		writeStringAttr(wr, itemtag, "sref", "TxtMsg4", TxtMsg4);
		writeStringAttr(wr, itemtag, "sref", "TxtMsg5", TxtMsg5);
		writeStringAttr(wr, itemtag, "sref", "TxtMsg6", TxtMsg6);
		writeStringAttr(wr, itemtag, "sref", "TxtMsg7", TxtMsg7);
		writeStringAttr(wr, itemtag, "sref", "TxtMsg8", TxtMsg8);
		writeStringAttr(wr, itemtag, "sref", "TxtMsg9", TxtMsg9);
		writeStringAttr(wr, itemtag, "sref", "TxtMsg10", TxtMsg10);
		writeStringAttr(wr, itemtag, "sref", "TxtMsg11", TxtMsg11);
		writeStringAttr(wr, itemtag, "sref", "TxtMsg12", TxtMsg12);
	xmlTextWriterEndElement(wr);
};

set<uint> ContInfMsdcAlert::compare(
			const ContInfMsdcAlert* comp
		) {
	set<uint> items;

	if (TxtCpt == comp->TxtCpt) insert(items, TXTCPT);
	if (TxtMsg1 == comp->TxtMsg1) insert(items, TXTMSG1);
	if (TxtMsg2 == comp->TxtMsg2) insert(items, TXTMSG2);
	if (TxtMsg3 == comp->TxtMsg3) insert(items, TXTMSG3);
	if (TxtMsg4 == comp->TxtMsg4) insert(items, TXTMSG4);
	if (TxtMsg5 == comp->TxtMsg5) insert(items, TXTMSG5);
	if (TxtMsg6 == comp->TxtMsg6) insert(items, TXTMSG6);
	if (TxtMsg7 == comp->TxtMsg7) insert(items, TXTMSG7);
	if (TxtMsg8 == comp->TxtMsg8) insert(items, TXTMSG8);
	if (TxtMsg9 == comp->TxtMsg9) insert(items, TXTMSG9);
	if (TxtMsg10 == comp->TxtMsg10) insert(items, TXTMSG10);
	if (TxtMsg11 == comp->TxtMsg11) insert(items, TXTMSG11);
	if (TxtMsg12 == comp->TxtMsg12) insert(items, TXTMSG12);

	return(items);
};

/******************************************************************************
 class DpchMsdc
 ******************************************************************************/

DpchMsdc::DpchMsdc(
			const uint ixMsdcVDpch
		) {
	this->ixMsdcVDpch = ixMsdcVDpch;
};

DpchMsdc::~DpchMsdc() {
};

/******************************************************************************
 class DpchInvMsdc
 ******************************************************************************/

DpchInvMsdc::DpchInvMsdc(
			const uint ixMsdcVDpch
			, const ubigint oref
			, const ubigint jref
		) :
			DpchMsdc(ixMsdcVDpch)
		{
	this->oref = oref;
	this->jref = jref;
};

DpchInvMsdc::~DpchInvMsdc() {
};

void DpchInvMsdc::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvMsdc");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
	};
};

void DpchInvMsdc::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchRetMsdc");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/msdc");
		writeString(wr, "scrOref", Scr::scramble(oref));
		writeString(wr, "scrJref", Scr::scramble(jref));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchRetMsdc
 ******************************************************************************/

DpchRetMsdc::DpchRetMsdc(
			const uint ixMsdcVDpch
			, const string& scrOref
			, const string& scrJref
			, const utinyint ixOpVOpres
			, const utinyint pdone
		) :
			DpchMsdc(ixMsdcVDpch)
		{
	this->scrOref = scrOref;
	this->scrJref = scrJref;
	this->ixOpVOpres = ixOpVOpres;
	this->pdone = pdone;
};

DpchRetMsdc::~DpchRetMsdc() {
};

void DpchRetMsdc::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxOpVOpres;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchRetMsdc");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) {
			oref = Scr::descramble(scrOref);
			add(OREF);
		};
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) {
			jref = Scr::descramble(scrJref);
			add(JREF);
		};
		if (extractStringUclc(docctx, basexpath, "srefIxOpVOpres", "", srefIxOpVOpres)) {
			ixOpVOpres = VecOpVOpres::getIx(srefIxOpVOpres);
			add(IXOPVOPRES);
		};
		if (extractUtinyintUclc(docctx, basexpath, "pdone", "", pdone)) add(PDONE);
	};
};

void DpchRetMsdc::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchRetMsdc");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/msdc");
		writeString(wr, "scrOref", scrOref);
		writeString(wr, "scrJref", scrJref);
		writeString(wr, "srefIxOpVOpres", VecOpVOpres::getSref(ixOpVOpres));
		writeUtinyint(wr, "pdone", pdone);
	xmlTextWriterEndElement(wr);
};




