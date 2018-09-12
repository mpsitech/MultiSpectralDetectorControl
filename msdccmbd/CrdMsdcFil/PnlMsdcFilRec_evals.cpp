/**
  * \file PnlMsdcFilRec_evals.cpp
  * job handler for job PnlMsdcFilRec (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 12 Sep 2018
  * \date modified: 12 Sep 2018
  */

bool PnlMsdcFilRec::evalButRegularizeActive(
			DbsMsdc* dbsmsdc
		) {
	// pre.refFil()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecMsdcVPreset::PREMSDCREFFIL, jref) != 0);
	args.push_back(a);

	return(args.back());
};

