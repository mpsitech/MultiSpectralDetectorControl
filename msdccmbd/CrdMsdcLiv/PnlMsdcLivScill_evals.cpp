/**
  * \file PnlMsdcLivScill_evals.cpp
  * job handler for job PnlMsdcLivScill (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 4 Oct 2018
  * \date modified: 4 Oct 2018
  */

bool PnlMsdcLivScill::evalSldFldActive(
			DbsMsdc* dbsmsdc
		) {
	// actled.mast()

	vector<bool> args;
	bool a;

	a = false; if (actled) a = xchg->getMsjobMastNotSlv(actled);
	args.push_back(a);

	return(args.back());
};

bool PnlMsdcLivScill::evalSldSptActive(
			DbsMsdc* dbsmsdc
		) {
	// actled.mast()

	vector<bool> args;
	bool a;

	a = false; if (actled) a = xchg->getMsjobMastNotSlv(actled);
	args.push_back(a);

	return(args.back());
};

