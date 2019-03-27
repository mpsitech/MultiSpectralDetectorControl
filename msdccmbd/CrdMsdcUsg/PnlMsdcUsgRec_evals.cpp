/**
  * \file PnlMsdcUsgRec_evals.cpp
  * job handler for job PnlMsdcUsgRec (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 18 Dec 2018
  * \date modified: 18 Dec 2018
  */

bool PnlMsdcUsgRec::evalButRegularizeActive(
			DbsMsdc* dbsmsdc
		) {
	// pre.refUsg()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecMsdcVPreset::PREMSDCREFUSG, jref) != 0);
	args.push_back(a);

	return(args.back());
};

