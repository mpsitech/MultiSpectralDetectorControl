/**
  * \file CrdMsdcFil_evals.cpp
  * job handler for job CrdMsdcFil (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 12 Sep 2018
  * \date modified: 12 Sep 2018
  */

bool CrdMsdcFil::evalMitCrdDldAvail(
			DbsMsdc* dbsmsdc
		) {
	// pre.ixCrdaccFilIncl(exec)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecMsdcVPreset::PREMSDCIXCRDACCFIL, jref) & VecMsdcWAccess::EXEC);
	args.push_back(a);

	return(args.back());
};

bool CrdMsdcFil::evalMitCrdDldActive(
			DbsMsdc* dbsmsdc
		) {
	// pre.refFil()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecMsdcVPreset::PREMSDCREFFIL, jref) != 0);
	args.push_back(a);

	return(args.back());
};

