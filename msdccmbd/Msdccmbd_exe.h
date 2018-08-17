/**
  * \file Msdccmbd_exe.h
  * Msdc combined daemon main (declarations)
  * \author Alexander Wirthmueller
  * \date created: 15 Aug 2018
  * \date modified: 15 Aug 2018
  */

#ifndef MSDCCMBD_EXE_H
#define MSDCCMBD_EXE_H

#include <string>
#include <vector>

using namespace std;

#include <signal.h>

#include "MsdccmbdAppsrv.h"
#include "MsdccmbdJobprc.h"
#include "MsdccmbdOpprc.h"
#include "MsdccmbdDdspub.h"
#include "MsdccmbdUasrv.h"

/**
  * Msdccmbd
  */
class Msdccmbd {

public:
	Msdccmbd(const string& exedir, const bool clearAll, const bool startMon);
	~Msdccmbd();

public:
	string exedir;

	DbsMsdc dbsmsdc;

	XchgMsdccmbd* xchg;
	
	RootMsdc* root;

	MHD_Daemon* appsrv;

	vector<pthread_t> jobprcs;

	vector<pthread_t> opprcs;

	pthread_t ddspub;

	pthread_t uasrv;

public:
	void loadPref();
	void storePref();

	void loadKeycert();
};

#endif

