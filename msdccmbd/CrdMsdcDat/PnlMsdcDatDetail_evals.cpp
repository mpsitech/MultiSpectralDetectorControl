/**
  * \file PnlMsdcDatDetail_evals.cpp
  * job handler for job PnlMsdcDatDetail (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 4 Oct 2018
  * \date modified: 4 Oct 2018
  */

bool PnlMsdcDatDetail::evalButSaveAvail(
			DbsMsdc* dbsmsdc
		) {
	// pre.ixCrdaccDatIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecMsdcVPreset::PREMSDCIXCRDACCDAT, jref) & VecMsdcWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlMsdcDatDetail::evalButSaveActive(
			DbsMsdc* dbsmsdc
		) {
	// dirty()

	vector<bool> args;
	bool a;

	a = false; a = dirty;
	args.push_back(a);

	return(args.back());
};

bool PnlMsdcDatDetail::evalPupAftActive(
			DbsMsdc* dbsmsdc
		) {
	// pre.ixCrdaccDatIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecMsdcVPreset::PREMSDCIXCRDACCDAT, jref) & VecMsdcWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlMsdcDatDetail::evalButAftEditAvail(
			DbsMsdc* dbsmsdc
		) {
	// pre.adm()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getBoolvalPreset(VecMsdcVPreset::PREMSDCADM, jref));
	args.push_back(a);

	return(args.back());
};

bool PnlMsdcDatDetail::evalTxtPrdActive(
			DbsMsdc* dbsmsdc
		) {
	// pre.ixCrdaccDatIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecMsdcVPreset::PREMSDCIXCRDACCDAT, jref) & VecMsdcWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlMsdcDatDetail::evalButPrdViewAvail(
			DbsMsdc* dbsmsdc
		) {
	// dat.prdEq(0)|(pre.ixCrdaccPrd())

	vector<bool> args;
	bool a, b;

	a = false; a = (recDat.refMsdcMPeriod == 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecMsdcVPreset::PREMSDCIXCRDACCPRD, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlMsdcDatDetail::evalButPrdViewActive(
			DbsMsdc* dbsmsdc
		) {
	// !dat.prdEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recDat.refMsdcMPeriod == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlMsdcDatDetail::evalTxfStaActive(
			DbsMsdc* dbsmsdc
		) {
	// pre.ixCrdaccDatIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecMsdcVPreset::PREMSDCIXCRDACCDAT, jref) & VecMsdcWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlMsdcDatDetail::evalTxfStoActive(
			DbsMsdc* dbsmsdc
		) {
	// pre.ixCrdaccDatIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecMsdcVPreset::PREMSDCIXCRDACCDAT, jref) & VecMsdcWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlMsdcDatDetail::evalTxfCmtActive(
			DbsMsdc* dbsmsdc
		) {
	// pre.ixCrdaccDatIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecMsdcVPreset::PREMSDCIXCRDACCDAT, jref) & VecMsdcWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

