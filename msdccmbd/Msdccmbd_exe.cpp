/**
  * \file Msdccmbd_exe.cpp
  * Msdc combined daemon main (implementation)
  * \author Alexander Wirthmueller
  * \date created: 15 Aug 2018
  * \date modified: 15 Aug 2018
  */

#include "Msdccmbd.h"

#include "Msdccmbd_exe.h"

Msdccmbd* msdccmbd;

/******************************************************************************
 class Msdccmbd
 ******************************************************************************/

Msdccmbd::Msdccmbd(
			const string& exedir
			, const bool clearAll
			, const bool startMon
		) {
	pthread_attr_t attr;

	srand(time(NULL));

	sqlite3_initialize();

	// 1. create exchange object
	xchg = new XchgMsdccmbd();
	xchg->exedir = exedir;

	// 2. load preferences and SSL key/certificate
	loadPref();
	loadKeycert();

	// 3. connect to database
	dbsmsdc.init(xchg->stgmsdcdatabase.ixDbsVDbstype, xchg->stgmsdcdatabase.dbspath, xchg->stgmsdcdatabase.dbsname, xchg->stgmsdcdatabase.ip
			, xchg->stgmsdcdatabase.port, xchg->stgmsdcdatabase.username, xchg->stgmsdcdatabase.password);

	// 4. initialize shared data
	xchg->shrdatJobprc.init(xchg, &dbsmsdc);

	JobMsdcAcqAdxl::shrdat.init(xchg, &dbsmsdc);
	JobMsdcAcqLwir::shrdat.init(xchg, &dbsmsdc);
	JobMsdcAcqVisl::shrdat.init(xchg, &dbsmsdc);
	JobMsdcAcqVisr::shrdat.init(xchg, &dbsmsdc);
	JobMsdcActAlign::shrdat.init(xchg, &dbsmsdc);
	JobMsdcActLed::shrdat.init(xchg, &dbsmsdc);
	JobMsdcActServo::shrdat.init(xchg, &dbsmsdc);
	JobMsdcPrcSpotfind::shrdat.init(xchg, &dbsmsdc);
	JobMsdcPrcStereo::shrdat.init(xchg, &dbsmsdc);
	JobMsdcPrcTrack::shrdat.init(xchg, &dbsmsdc);
	JobMsdcSrcMsdd::shrdat.init(xchg, &dbsmsdc);
	JobMsdcSrcTrigger::shrdat.init(xchg, &dbsmsdc);

	xchg->shrdatOpprc.init(xchg, &dbsmsdc);

	// 5. start monitoring (optional)
	if (startMon) xchg->startMon();

	// 6. establish root job
	root = new RootMsdc(xchg, &dbsmsdc, clearAll);

	// 7. start job processor threads
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

	for (unsigned int i=0;i<xchg->stgmsdccmbd.jobprcn;i++) {
		// thread
		jobprcs.push_back(0);
		pthread_create(&(jobprcs[i]), &attr, &MsdccmbdJobprc::run, (void*) xchg);
	};

	// 8. start op processor threads
	for (unsigned int i=0;i<xchg->stgmsdccmbd.opprcn;i++) {
		// thread
		opprcs.push_back(0);
		pthread_create(&(opprcs[i]), &attr, &MsdccmbdOpprc::run, (void*) xchg);
	};

	// 9. start web server
	if (xchg->stgmsdccmbd.appsrv) appsrv = MsdccmbdAppsrv::start(xchg);

	// 10. start DDS publisher
	if (xchg->stgmsdccmbd.ddspub) pthread_create(&ddspub, &attr, &MsdccmbdDdspub::run, (void*) xchg);

	// 11. start OPC UA server
	if (xchg->stgmsdccmbd.uasrv) pthread_create(&uasrv, &attr, &MsdccmbdUasrv::run, (void*) xchg);

	pthread_attr_destroy(&attr);
};

Msdccmbd::~Msdccmbd() {
	// 1. stop OPC UA server
	if (xchg->stgmsdccmbd.uasrv) {
		pthread_cancel(uasrv);
		pthread_join(uasrv, NULL);
	};

	// 2. stop DDS publisher
	if (xchg->stgmsdccmbd.ddspub) {
		pthread_cancel(ddspub);
		pthread_join(ddspub, NULL);
	};

	// 3. stop web server
	if (xchg->stgmsdccmbd.appsrv) MsdccmbdAppsrv::stop(appsrv);

	// 4. end op processor threads
	for (unsigned int i=0;i<opprcs.size();i++) {
		//if (opprcs[i]) {
			pthread_cancel(opprcs[i]);
			pthread_join(opprcs[i], NULL);
		//};
	};

	// 5. end job processor threads
	for (unsigned int i=0;i<jobprcs.size();i++) {
		//if (jobprcs[i]) {
			pthread_cancel(jobprcs[i]);
			pthread_join(jobprcs[i], NULL);
		//};
	};

	// 6. delete root job
	delete root;
	root = NULL;

	// 7. terminate shared data
	xchg->shrdatOpprc.term();

	JobMsdcAcqAdxl::shrdat.term();
	JobMsdcAcqLwir::shrdat.term();
	JobMsdcAcqVisl::shrdat.term();
	JobMsdcAcqVisr::shrdat.term();
	JobMsdcActAlign::shrdat.term();
	JobMsdcActLed::shrdat.term();
	JobMsdcActServo::shrdat.term();
	JobMsdcPrcSpotfind::shrdat.term();
	JobMsdcPrcStereo::shrdat.term();
	JobMsdcPrcTrack::shrdat.term();
	JobMsdcSrcMsdd::shrdat.term();
	JobMsdcSrcTrigger::shrdat.term();

	xchg->shrdatJobprc.term();

	// 8. store preferences
	storePref();

	// 9. delete exchange object
	delete xchg;
};

void Msdccmbd::loadPref() {
	xmlDoc* doc = NULL;
	xmlXPathContext* docctx = NULL;

	string basexpath;

	parseFile(xchg->exedir + "/PrefMsdccmbd.xml", &doc, &docctx);

	if (checkUclcXPaths(docctx, basexpath, "/", "PrefMsdccmbd")) {
		xchg->stgmsdccmbd.readXML(docctx, basexpath, true);
		xchg->stgmsdcdatabase.readXML(docctx, basexpath, true);
		xchg->stgmsdcddspub.readXML(docctx, basexpath, true);
		xchg->stgmsdcpath.readXML(docctx, basexpath, true);
		xchg->stgmsdcuasrv.readXML(docctx, basexpath, true);
		JobMsdcAcqLwir::stg.readXML(docctx, basexpath, true);
		JobMsdcAcqVisl::stg.readXML(docctx, basexpath, true);
		JobMsdcAcqVisr::stg.readXML(docctx, basexpath, true);
		JobMsdcActServo::stg.readXML(docctx, basexpath, true);
		JobMsdcSrcMsdd::stg.readXML(docctx, basexpath, true);
		JobMsdcSrcTrigger::stg.readXML(docctx, basexpath, true);
	};

	closeParsed(doc, docctx);

	xchg->acvpath = xchg->stgmsdcpath.acvpath;
	xchg->tmppath = xchg->stgmsdcpath.tmppath;
	xchg->helpurl = xchg->stgmsdcpath.helpurl;
};

void Msdccmbd::storePref() {
	xmlTextWriter* wr = NULL;

	startwriteFile(xchg->exedir + "/PrefMsdccmbd.xml", &wr);
	xmlTextWriterStartElement(wr, BAD_CAST "PrefMsdccmbd");
		xchg->stgmsdccmbd.writeXML(wr);
		xchg->stgmsdcdatabase.writeXML(wr);
		xchg->stgmsdcddspub.writeXML(wr);
		xchg->stgmsdcpath.writeXML(wr);
		xchg->stgmsdcuasrv.writeXML(wr);
		JobMsdcAcqLwir::stg.writeXML(wr);
		JobMsdcAcqVisl::stg.writeXML(wr);
		JobMsdcAcqVisr::stg.writeXML(wr);
		JobMsdcActServo::stg.writeXML(wr);
		JobMsdcSrcMsdd::stg.writeXML(wr);
		JobMsdcSrcTrigger::stg.writeXML(wr);
	xmlTextWriterEndElement(wr);
	closewriteFile(wr);
};

void Msdccmbd::loadKeycert() {
	ifstream infile;
	char* buf = new char[1048576];

	string s;

	// key file
	s = xchg->exedir + "/server.key";
	infile.open(s.c_str(), ifstream::in);

	while (infile.good() && !infile.eof()) {
		infile.getline(buf, 1048576, '\r');
		s = string(buf);
		if (s.length() > 0) if (s[0] == '\n') s = s.substr(1);

		xchg->key += s + "\n";
	};

	infile.close();

	// certificate file
	s = xchg->exedir + "/server.pem";
	infile.open(s.c_str(), ifstream::in);

	while (infile.good() && !infile.eof()) {
		infile.getline(buf, 1048576, '\r');
		s = string(buf);
		if (s.length() > 0) if (s[0] == '\n') s = s.substr(1);

		xchg->cert += s + "\n";
	};

	infile.close();

	delete[] buf;
};

/******************************************************************************
 settings for jobs, operation packs and operations
 ******************************************************************************/

StgJobMsdcAcqLwir JobMsdcAcqLwir::stg;
StgJobMsdcAcqVisl JobMsdcAcqVisl::stg;
StgJobMsdcAcqVisr JobMsdcAcqVisr::stg;
StgJobMsdcActServo JobMsdcActServo::stg;
StgJobMsdcSrcMsdd JobMsdcSrcMsdd::stg;
StgJobMsdcSrcTrigger JobMsdcSrcTrigger::stg;

/******************************************************************************
 shared data for jobs, operation packs and operations
 ******************************************************************************/

ShrdatJobMsdcAcqAdxl JobMsdcAcqAdxl::shrdat;
ShrdatJobMsdcAcqLwir JobMsdcAcqLwir::shrdat;
ShrdatJobMsdcAcqVisl JobMsdcAcqVisl::shrdat;
ShrdatJobMsdcAcqVisr JobMsdcAcqVisr::shrdat;
ShrdatJobMsdcActAlign JobMsdcActAlign::shrdat;
ShrdatJobMsdcActLed JobMsdcActLed::shrdat;
ShrdatJobMsdcActServo JobMsdcActServo::shrdat;
ShrdatJobMsdcPrcSpotfind JobMsdcPrcSpotfind::shrdat;
ShrdatJobMsdcPrcStereo JobMsdcPrcStereo::shrdat;
ShrdatJobMsdcPrcTrack JobMsdcPrcTrack::shrdat;
ShrdatJobMsdcSrcMsdd JobMsdcSrcMsdd::shrdat;
ShrdatJobMsdcSrcTrigger JobMsdcSrcTrigger::shrdat;

/******************************************************************************
 main program
 ******************************************************************************/

void showSubjobs(
			XchgMsdccmbd* xchg
			, JobMsdc* job
			, bool clstns
			, bool ops
			, bool presets
			, bool dcolcont
			, bool stmgrcont
			, unsigned int indent
		) {
	string id;

	// http://stackoverflow.com/questions/2616906/how-do-i-output-coloured-text-to-a-linux-terminal
	string setgray = "\033[38;2;196;196;196m";
	string reset = "\033[0m";

	DcolMsdc* dcol = NULL;
	StmgrMsdc* stmgr = NULL;

	vector<uint> icsMsdcVCall;
	vector<uint> icsVJobmask;

	vector<uint> icsMsdcVPreset;
	vector<Arg> args;

	// indentation
	for (unsigned int i=0;i<indent;i++) id = id + "\t";

	// actual entry
	if (job->jrefsSub.empty()) cout << "\t" << id << "- ";
	else cout << "\t" << id << "+ ";
	cout << VecMsdcVJob::getSref(job->ixMsdcVJob);

	if (xchg->getMsjobNotJob(job->ixMsdcVJob)) {
		if (((MsjobMsdc*) job)->getMastNotSlv()) cout << "/M";
		else cout << "/S";
	};

	cout << " (" << job->jref;

	dcol = xchg->getDcolByJref(job->jref, false);
	if (dcol) {
		cout << ", dcol";
		dcol->unlockAccess("", "showSubjobs");
	};

	stmgr = xchg->getStmgrByJref(job->jref);
	if (stmgr) {
		cout << ", stmgr";
		stmgr->unlockAccess("", "showSubjobs");
	};

	cout << ")" << endl;

	if (clstns) {
		// call listeners
		cout << setgray;

		xchg->getClstnsByJref(job->jref, Clstn::VecVTarget::JOB, icsMsdcVCall, icsVJobmask);
		for (unsigned int i=0;i<icsMsdcVCall.size();i++)
					cout << "\t\t" << id << VecMsdcVCall::getSref(icsMsdcVCall[i]) << " (" << Clstn::VecVJobmask::getSref(icsVJobmask[i]) << ")" << endl;

		xchg->getClstnsByJref(job->jref, Clstn::VecVTarget::STMGR, icsMsdcVCall, icsVJobmask);
		for (unsigned int i=0;i<icsMsdcVCall.size();i++)
					cout << "\t\t" << id << "stmgr: " << VecMsdcVCall::getSref(icsMsdcVCall[i]) << endl;

		cout << reset;
	};

	if (ops) {
		// ops
		cout << setgray;

		Mutex::lock(&(job->mOps), "job(" + to_string(job->jref) + ")->mOps", "", "showSubjobs");

		for (auto it=job->ops.begin();it!=job->ops.end();it++)
					cout << "\t\t" << id << VecMsdcVDpch::getSref((*it)->ixVDpch).substr(4+3) << " (" << to_string((*it)->oref) << "): " << (*it)->squawk << endl;

		Mutex::unlock(&(job->mOps), "job(" + to_string(job->jref) + ")->mOps", "", "showSubjobs");

		cout << reset;
	};

	if (presets) {
		// presettings
		cout << setgray;

		xchg->getPresetsByJref(job->jref, icsMsdcVPreset, args);

		for (unsigned int i=0;i<icsMsdcVPreset.size();i++)
					cout << "\t\t" << id << VecMsdcVPreset::getSref(icsMsdcVPreset[i]) << ": " << args[i].writeText() << endl;

		cout << reset;
	};

	if (dcolcont) {
		// dispatch collector content
		dcol = xchg->getDcolByJref(job->jref, false);

		if (dcol) {
			cout << setgray;

			for (auto it=dcol->dpchs.begin();it!=dcol->dpchs.end();it++)
						cout << "\t\t" << id << VecMsdcVDpch::getSref((*it)->ixMsdcVDpch) << " (" << (*it)->jref << ")" << endl;

			dcol->unlockAccess("", "showSubjobs");
			cout << reset;
		};
	};

	if (stmgrcont) {
		// stub manager content
		stmgr = xchg->getStmgrByJref(job->jref);

		if (stmgr) {
			cout << setgray;

			for (auto it=stmgr->stcch->nodes.begin();it!=stmgr->stcch->nodes.end();it++)
						cout << "\t\t" << id << VecMsdcVStub::getSref(it->second->stref.ixVStub) << " (" << it->second->stref.ref << "): " << it->second->stub << endl;

			stmgr->unlockAccess("", "showSubjobs");
			cout << reset;
		};
	};

	// sub-entries
	JobMsdc* subjob;
	for (auto it=job->jrefsSub.begin();it!=job->jrefsSub.end();it++) {
		subjob = xchg->getJobByJref(*it);
		if (subjob) showSubjobs(xchg, subjob, clstns, ops, presets, dcolcont, stmgrcont, indent+1);
	};
};

void handleSignal(
			int sig
		) {
	// deleting msdccmbd forces PrefMsdccmbd to be written
	if (msdccmbd) delete msdccmbd;

	exit(sig);
};

int main(
			const int argc
			, const char** argv
		) {
	char* buf = NULL;
	string exedir;
	size_t ptr;

	string s;
	bool nocp = false;
	bool clearAll = false;
	bool startMon = false;

	pthread_mutex_t mcDummy;
	pthread_cond_t cDummy;

	string cmd;

	string input;
	int iinput;

	string s_backup;

	XchgMsdccmbd* xchg;

	JobMsdc* job;

	ReqMsdc* req;

	msdccmbd = NULL;

	// ensure proper termination on signals such as ctrl-c
#ifndef _WIN32
	signal(SIGHUP, handleSignal);
#endif
	signal(SIGINT, handleSignal); // 2
	signal(SIGTERM, handleSignal); // 15

	// determine executable path
	buf = new char[4096];

	if (readlink("/proc/self/exe", buf, 4096) >= 1) {
		exedir = buf;

	} else {
		if (strlen(argv[0]) >= 1) {
			exedir = argv[0];

			if (exedir[0] != '/') {
				if (getcwd(buf, 4096)) {
					exedir = "/" + exedir;
					exedir = buf + exedir;
				};
			};
		};
	};

	delete[] buf;

	ptr = exedir.rfind('/');
	if ((ptr != string::npos) && (ptr > 0)) exedir = exedir.substr(0, ptr);

	// evaluate command line options
	for (int i=1;i<argc;i++) {
		s = argv[i];

		if (s == "-nocp") nocp = true;
		else if (s == "-clearAll") clearAll = true;
		else if (s == "-startMon") startMon = true;
	};

	try {
		// calls msdccmbd.init()
		msdccmbd = new Msdccmbd(exedir, clearAll, startMon);
		xchg = msdccmbd->xchg;

		// welcome message
		cout << "Welcome to MultispectralDetectorControl 0.1.45!" << endl;

		if (nocp) {
			// wait on a dummy condition
			Mutex::init(&mcDummy, false, "mcDummy", "", "main");
			Cond::init(&cDummy, "cDummy", "", "main");
			Mutex::lock(&mcDummy, "mcDummy", "", "main");
			Cond::wait(&cDummy, &mcDummy, "cDummy", "", "main");
			Mutex::unlock(&mcDummy, "mcDummy", "", "main");
			Mutex::destroy(&mcDummy, false, "mcDummy", "", "main");
			Cond::destroy(&cDummy, "cDummy", "", "main");

		} else {
			// main command loop
			while (cmd != "quit") {
				cout << "Msdccmbd >> ";
				cin >> cmd;

				if (cmd == "quit") {

				} else if (cmd == "cmdsetStd") {
					cout << "\tquit" << endl;

					cout << "\tstartMon" << endl;
					cout << "\tstopMon" << endl;

					cout << "\tshowJobs" << endl;
					cout << "\tshowSubjobs" << endl;

					cout << "\tgotoJob" << endl;
					cout << "\tgotoSupjob" << endl;

					cout << "\tshowClstns" << endl;
					cout << "\tshowOps" << endl;
					cout << "\tshowPresets" << endl;

					cout << "\tshowDcolContent" << endl;
					cout << "\tshowStmgrContent" << endl;

				} else if (cmd == "startMon") {
					xchg->startMon();

				} else if (cmd == "stopMon") {
					xchg->stopMon();

				} else if (cmd == "showJobs") {
					job = xchg->getJobByJref(xchg->jrefRoot);
					if (job) showSubjobs(xchg, job, false, false, false, false, false, 0);

				} else if (cmd == "showSubjobs") {
					job = xchg->getJobByJref(xchg->jrefCmd);
					if (job) showSubjobs(xchg, job, false, false, false, false, false, 0);

				} else if (cmd == "gotoJob") {
					cout << "\tjob reference: ";
					cin >> input;
					iinput = atoi(input.c_str());

					job = xchg->getJobByJref(iinput);

					if (job) xchg->jrefCmd = job->jref;
					else cout << "\tjob reference doesn't exist!" << endl;

				} else if (cmd == "gotoSupjob") {
					job = xchg->getJobByJref(xchg->jrefCmd);

					if (job) {
						job = xchg->getJobByJref(job->jrefSup);

						if (job) xchg->jrefCmd = job->jref;
						else cout << "\talready at topmost job!" << endl;
					};

				} else if (cmd == "showClstns") {
					job = xchg->getJobByJref(xchg->jrefRoot);
					if (job) showSubjobs(xchg, job, true, false, false, false, false, 0);

				} else if (cmd == "showOps") {
					job = xchg->getJobByJref(xchg->jrefRoot);
					if (job) showSubjobs(xchg, job, false, true, false, false, false, 0);

				} else if (cmd == "showPresets") {
					job = xchg->getJobByJref(xchg->jrefRoot);
					if (job) showSubjobs(xchg, job, false, false, true, false, false, 0);

				} else if (cmd == "showDcolContent") {
					job = xchg->getJobByJref(xchg->jrefRoot);
					if (job) showSubjobs(xchg, job, false, false, false, true, false, 0);

				} else if (cmd == "showStmgrContent") {
					job = xchg->getJobByJref(xchg->jrefRoot);
					if (job) showSubjobs(xchg, job, false, false, false, false, true, 0);

				} else {
					job = xchg->getJobByJref(xchg->jrefCmd);

					if (job) {
						req = new ReqMsdc(ReqMsdc::VecVBasetype::CMD, ReqMsdc::VecVState::RECEIVE);
						req->cmd = cmd;
						req->jref = xchg->jrefCmd;

						xchg->addReq(req);

						s_backup = "";

						while (req->ixVState != ReqMsdc::VecVState::REPLY) {
							// wait for job processor to finish or to time out
							Mutex::lock(&(req->mcReady), "req->mcReady", "", "main");
							Cond::timedwait(&(req->cReady), &(req->mcReady), 1000000, "req->cReady", "", "main");
							Mutex::unlock(&(req->mcReady), "req->mcReady", "", "main");

							if (req->ixVState == ReqMsdc::VecVState::WAITPRC) {
								cout << "\twaiting for processing" << endl;

							} else if (req->ixVState == ReqMsdc::VecVState::PRC) {
								s = job->getSquawk(&(msdccmbd->dbsmsdc));
								if (s != s_backup) {
									cout << "\t" << s << endl;
									s_backup = s;
								};
							};
						};

						delete req;
					};
				};
			};
		};

		delete msdccmbd;

	} catch (DbsException e) {
		cout << e.err << endl;
	};
	
	return(0);
};

