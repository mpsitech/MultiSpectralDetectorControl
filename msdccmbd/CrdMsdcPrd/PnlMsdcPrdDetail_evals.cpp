/**
  * \file PnlMsdcPrdDetail_evals.cpp
  * job handler for job PnlMsdcPrdDetail (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 18 Dec 2018
  * \date modified: 18 Dec 2018
  */

bool PnlMsdcPrdDetail::evalButSaveAvail(
			DbsMsdc* dbsmsdc
		) {
	// pre.ixCrdaccPrdIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecMsdcVPreset::PREMSDCIXCRDACCPRD, jref) & VecMsdcWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlMsdcPrdDetail::evalButSaveActive(
			DbsMsdc* dbsmsdc
		) {
	// dirty()

	vector<bool> args;
	bool a;

	a = false; a = dirty;
	args.push_back(a);

	return(args.back());
};

bool PnlMsdcPrdDetail::evalTxfStaActive(
			DbsMsdc* dbsmsdc
		) {
	// pre.ixCrdaccPrdIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecMsdcVPreset::PREMSDCIXCRDACCPRD, jref) & VecMsdcWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlMsdcPrdDetail::evalTxfStoActive(
			DbsMsdc* dbsmsdc
		) {
	// pre.ixCrdaccPrdIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecMsdcVPreset::PREMSDCIXCRDACCPRD, jref) & VecMsdcWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

