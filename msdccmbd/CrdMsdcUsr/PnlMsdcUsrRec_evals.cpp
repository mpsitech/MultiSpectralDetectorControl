/**
  * \file PnlMsdcUsrRec_evals.cpp
  * job handler for job PnlMsdcUsrRec (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 4 Oct 2018
  * \date modified: 4 Oct 2018
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

