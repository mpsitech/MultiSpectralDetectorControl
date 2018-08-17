/**
  * \file PnlMsdcPrdRec_evals.cpp
  * job handler for job PnlMsdcPrdRec (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 15 Aug 2018
  * \date modified: 15 Aug 2018
  */

bool PnlMsdcPrdRec::evalButRegularizeActive(
			DbsMsdc* dbsmsdc
		) {
	// pre.refPrd()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecMsdcVPreset::PREMSDCREFPRD, jref) != 0);
	args.push_back(a);

	return(args.back());
};

