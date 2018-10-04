/**
  * \file PnlMsdcUsrMNUsergroup_evals.cpp
  * job handler for job PnlMsdcUsrMNUsergroup (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 4 Oct 2018
  * \date modified: 4 Oct 2018
  */

bool PnlMsdcUsrMNUsergroup::evalButViewAvail(
			DbsMsdc* dbsmsdc
		) {
	// !sel()|(pre.ixCrdaccUsg())

	vector<bool> args;
	bool a, b;

	a = false; a = (qry->stgiac.jnum != 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);
	a = false; a = (xchg->getIxPreset(VecMsdcVPreset::PREMSDCIXCRDACCUSG, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlMsdcUsrMNUsergroup::evalButViewActive(
			DbsMsdc* dbsmsdc
		) {
	// sel()

	vector<bool> args;
	bool a;

	a = false; a = (qry->stgiac.jnum != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlMsdcUsrMNUsergroup::evalButAddAvail(
			DbsMsdc* dbsmsdc
		) {
	// pre.ixCrdaccUsrIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecMsdcVPreset::PREMSDCIXCRDACCUSR, jref) & VecMsdcWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlMsdcUsrMNUsergroup::evalButSubAvail(
			DbsMsdc* dbsmsdc
		) {
	// pre.ixCrdaccUsrIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecMsdcVPreset::PREMSDCIXCRDACCUSR, jref) & VecMsdcWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlMsdcUsrMNUsergroup::evalButSubActive(
			DbsMsdc* dbsmsdc
		) {
	// sel()

	vector<bool> args;
	bool a;

	a = false; a = (qry->stgiac.jnum != 0);
	args.push_back(a);

	return(args.back());
};

