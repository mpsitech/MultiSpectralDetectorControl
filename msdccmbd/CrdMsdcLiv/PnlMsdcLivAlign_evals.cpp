/**
  * \file PnlMsdcLivAlign_evals.cpp
  * job handler for job PnlMsdcLivAlign (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 4 Oct 2018
  * \date modified: 4 Oct 2018
  */

bool PnlMsdcLivAlign::evalSldTheActive(
			DbsMsdc* dbsmsdc
		) {
	// actservo.mast()

	vector<bool> args;
	bool a;

	a = false; if (actservo) a = xchg->getMsjobMastNotSlv(actservo);
	args.push_back(a);

	return(args.back());
};

bool PnlMsdcLivAlign::evalSldPhiActive(
			DbsMsdc* dbsmsdc
		) {
	// actservo.mast()

	vector<bool> args;
	bool a;

	a = false; if (actservo) a = xchg->getMsjobMastNotSlv(actservo);
	args.push_back(a);

	return(args.back());
};

