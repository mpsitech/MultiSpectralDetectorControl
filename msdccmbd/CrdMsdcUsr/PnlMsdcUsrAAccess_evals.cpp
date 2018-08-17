/**
  * \file PnlMsdcUsrAAccess_evals.cpp
  * job handler for job PnlMsdcUsrAAccess (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 15 Aug 2018
  * \date modified: 15 Aug 2018
  */

bool PnlMsdcUsrAAccess::evalButNewAvail(
			DbsMsdc* dbsmsdc
		) {
	// pre.ixCrdaccUsrIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecMsdcVPreset::PREMSDCIXCRDACCUSR, jref) & VecMsdcWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlMsdcUsrAAccess::evalButDuplicateAvail(
			DbsMsdc* dbsmsdc
		) {
	// pre.ixCrdaccUsrIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecMsdcVPreset::PREMSDCIXCRDACCUSR, jref) & VecMsdcWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlMsdcUsrAAccess::evalButDuplicateActive(
			DbsMsdc* dbsmsdc
		) {
	// sel()

	vector<bool> args;
	bool a;

	a = false; a = (qry->stgiac.jnum != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlMsdcUsrAAccess::evalButDeleteAvail(
			DbsMsdc* dbsmsdc
		) {
	// pre.ixCrdaccUsrIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecMsdcVPreset::PREMSDCIXCRDACCUSR, jref) & VecMsdcWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlMsdcUsrAAccess::evalButDeleteActive(
			DbsMsdc* dbsmsdc
		) {
	// sel()

	vector<bool> args;
	bool a;

	a = false; a = (qry->stgiac.jnum != 0);
	args.push_back(a);

	return(args.back());
};

