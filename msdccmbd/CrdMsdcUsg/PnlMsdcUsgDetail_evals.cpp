/**
  * \file PnlMsdcUsgDetail_evals.cpp
  * job handler for job PnlMsdcUsgDetail (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 29 Aug 2018
  * \date modified: 29 Aug 2018
  */

bool PnlMsdcUsgDetail::evalButSaveAvail(
			DbsMsdc* dbsmsdc
		) {
	// pre.ixCrdaccUsgIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecMsdcVPreset::PREMSDCIXCRDACCUSG, jref) & VecMsdcWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlMsdcUsgDetail::evalButSaveActive(
			DbsMsdc* dbsmsdc
		) {
	// dirty()

	vector<bool> args;
	bool a;

	a = false; a = dirty;
	args.push_back(a);

	return(args.back());
};

bool PnlMsdcUsgDetail::evalTxtSrfActive(
			DbsMsdc* dbsmsdc
		) {
	// pre.ixCrdaccUsgIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecMsdcVPreset::PREMSDCIXCRDACCUSG, jref) & VecMsdcWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlMsdcUsgDetail::evalTxfCmtActive(
			DbsMsdc* dbsmsdc
		) {
	// pre.ixCrdaccUsgIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecMsdcVPreset::PREMSDCIXCRDACCUSG, jref) & VecMsdcWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

