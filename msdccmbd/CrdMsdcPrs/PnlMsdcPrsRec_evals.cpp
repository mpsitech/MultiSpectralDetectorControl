/**
  * \file PnlMsdcPrsRec_evals.cpp
  * job handler for job PnlMsdcPrsRec (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 12 Sep 2018
  * \date modified: 12 Sep 2018
  */

bool PnlMsdcPrsRec::evalButRegularizeActive(
			DbsMsdc* dbsmsdc
		) {
	// pre.refPrs()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecMsdcVPreset::PREMSDCREFPRS, jref) != 0);
	args.push_back(a);

	return(args.back());
};

