/**
  * \file PnlMsdcDatRec_evals.cpp
  * job handler for job PnlMsdcDatRec (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 18 Dec 2018
  * \date modified: 18 Dec 2018
  */

bool PnlMsdcDatRec::evalButRegularizeActive(
			DbsMsdc* dbsmsdc
		) {
	// pre.refDat()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecMsdcVPreset::PREMSDCREFDAT, jref) != 0);
	args.push_back(a);

	return(args.back());
};

