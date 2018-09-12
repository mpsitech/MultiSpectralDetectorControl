/**
  * \file PnlMsdcDatAPar_evals.cpp
  * job handler for job PnlMsdcDatAPar (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 12 Sep 2018
  * \date modified: 12 Sep 2018
  */

bool PnlMsdcDatAPar::evalButNewAvail(
			DbsMsdc* dbsmsdc
		) {
	// pre.ixCrdaccDatIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecMsdcVPreset::PREMSDCIXCRDACCDAT, jref) & VecMsdcWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlMsdcDatAPar::evalButDuplicateAvail(
			DbsMsdc* dbsmsdc
		) {
	// pre.ixCrdaccDatIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecMsdcVPreset::PREMSDCIXCRDACCDAT, jref) & VecMsdcWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlMsdcDatAPar::evalButDuplicateActive(
			DbsMsdc* dbsmsdc
		) {
	// sel()

	vector<bool> args;
	bool a;

	a = false; a = (qry->stgiac.jnum != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlMsdcDatAPar::evalButDeleteAvail(
			DbsMsdc* dbsmsdc
		) {
	// pre.ixCrdaccDatIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecMsdcVPreset::PREMSDCIXCRDACCDAT, jref) & VecMsdcWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlMsdcDatAPar::evalButDeleteActive(
			DbsMsdc* dbsmsdc
		) {
	// sel()

	vector<bool> args;
	bool a;

	a = false; a = (qry->stgiac.jnum != 0);
	args.push_back(a);

	return(args.back());
};

