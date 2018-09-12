/**
  * \file PnlMsdcNavPre_evals.cpp
  * job handler for job PnlMsdcNavPre (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 12 Sep 2018
  * \date modified: 12 Sep 2018
  */

bool PnlMsdcNavPre::evalTxtDatAvail(
			DbsMsdc* dbsmsdc
		) {
	// pre.refDat()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecMsdcVPreset::PREMSDCREFDAT, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlMsdcNavPre::evalTxtPrdAvail(
			DbsMsdc* dbsmsdc
		) {
	// pre.refPrd()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecMsdcVPreset::PREMSDCREFPRD, jref) != 0);
	args.push_back(a);

	return(args.back());
};

