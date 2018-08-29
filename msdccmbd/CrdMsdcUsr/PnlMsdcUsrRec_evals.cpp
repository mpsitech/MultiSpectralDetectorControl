/**
  * \file PnlMsdcUsrRec_evals.cpp
  * job handler for job PnlMsdcUsrRec (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 29 Aug 2018
  * \date modified: 29 Aug 2018
  */

bool PnlMsdcUsrRec::evalButRegularizeActive(
			DbsMsdc* dbsmsdc
		) {
	// pre.refUsr()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecMsdcVPreset::PREMSDCREFUSR, jref) != 0);
	args.push_back(a);

	return(args.back());
};

