/**
  * \file PnlMsdcUsgMNUser_evals.cpp
  * job handler for job PnlMsdcUsgMNUser (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 15 Aug 2018
  * \date modified: 15 Aug 2018
  */

bool PnlMsdcUsgMNUser::evalButViewAvail(
			DbsMsdc* dbsmsdc
		) {
	// !sel()|(pre.ixCrdaccUsr())

	vector<bool> args;
	bool a, b;

	a = false; a = (qry->stgiac.jnum != 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);
	a = false; a = (xchg->getIxPreset(VecMsdcVPreset::PREMSDCIXCRDACCUSR, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlMsdcUsgMNUser::evalButViewActive(
			DbsMsdc* dbsmsdc
		) {
	// sel()

	vector<bool> args;
	bool a;

	a = false; a = (qry->stgiac.jnum != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlMsdcUsgMNUser::evalButAddAvail(
			DbsMsdc* dbsmsdc
		) {
	// pre.ixCrdaccUsgIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecMsdcVPreset::PREMSDCIXCRDACCUSG, jref) & VecMsdcWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlMsdcUsgMNUser::evalButSubAvail(
			DbsMsdc* dbsmsdc
		) {
	// pre.ixCrdaccUsgIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecMsdcVPreset::PREMSDCIXCRDACCUSG, jref) & VecMsdcWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlMsdcUsgMNUser::evalButSubActive(
			DbsMsdc* dbsmsdc
		) {
	// sel()

	vector<bool> args;
	bool a;

	a = false; a = (qry->stgiac.jnum != 0);
	args.push_back(a);

	return(args.back());
};

