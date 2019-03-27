/**
  * \file PnlMsdcLivTrack_evals.cpp
  * job handler for job PnlMsdcLivTrack (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 18 Dec 2018
  * \date modified: 18 Dec 2018
  */

bool PnlMsdcLivTrack::evalPupAmfActive(
			DbsMsdc* dbsmsdc
		) {
	// prctrack.mast()

	vector<bool> args;
	bool a;

	a = false; if (prctrack) a = xchg->getMsjobMastNotSlv(prctrack);
	args.push_back(a);

	return(args.back());
};

bool PnlMsdcLivTrack::evalUpdAprActive(
			DbsMsdc* dbsmsdc
		) {
	// prctrack.mast()

	vector<bool> args;
	bool a;

	a = false; if (prctrack) a = xchg->getMsjobMastNotSlv(prctrack);
	args.push_back(a);

	return(args.back());
};

bool PnlMsdcLivTrack::evalChkVidActive(
			DbsMsdc* dbsmsdc
		) {
	// false

	vector<bool> args;
	bool a;

	args.push_back(false);

	return(args.back());
};

bool PnlMsdcLivTrack::evalChkWidActive(
			DbsMsdc* dbsmsdc
		) {
	// false

	vector<bool> args;
	bool a;

	args.push_back(false);

	return(args.back());
};

