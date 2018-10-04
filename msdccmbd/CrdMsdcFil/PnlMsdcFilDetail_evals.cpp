/**
  * \file PnlMsdcFilDetail_evals.cpp
  * job handler for job PnlMsdcFilDetail (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 4 Oct 2018
  * \date modified: 4 Oct 2018
  */

bool PnlMsdcFilDetail::evalButSaveAvail(
			DbsMsdc* dbsmsdc
		) {
	// pre.ixCrdaccFilIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecMsdcVPreset::PREMSDCIXCRDACCFIL, jref) & VecMsdcWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlMsdcFilDetail::evalButSaveActive(
			DbsMsdc* dbsmsdc
		) {
	// dirty()

	vector<bool> args;
	bool a;

	a = false; a = dirty;
	args.push_back(a);

	return(args.back());
};

bool PnlMsdcFilDetail::evalTxfFnmActive(
			DbsMsdc* dbsmsdc
		) {
	// pre.ixCrdaccFilIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecMsdcVPreset::PREMSDCIXCRDACCFIL, jref) & VecMsdcWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlMsdcFilDetail::evalLstCluActive(
			DbsMsdc* dbsmsdc
		) {
	// pre.ixCrdaccFilIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecMsdcVPreset::PREMSDCIXCRDACCFIL, jref) & VecMsdcWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlMsdcFilDetail::evalButCluViewActive(
			DbsMsdc* dbsmsdc
		) {
	// LstClu.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstClu != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlMsdcFilDetail::evalButCluClusterAvail(
			DbsMsdc* dbsmsdc
		) {
	// pre.ixCrdaccFilIncl(edit)&fil.cluEq(0)

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecMsdcVPreset::PREMSDCIXCRDACCFIL, jref) & VecMsdcWAccess::EDIT);
	args.push_back(a);
	a = false; a = (recFil.refMsdcCFile == 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);

	return(args.back());
};

bool PnlMsdcFilDetail::evalButCluUnclusterAvail(
			DbsMsdc* dbsmsdc
		) {
	// pre.ixCrdaccFilIncl(edit)&!fil.cluEq(0)

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecMsdcVPreset::PREMSDCIXCRDACCFIL, jref) & VecMsdcWAccess::EDIT);
	args.push_back(a);
	a = false; a = (recFil.refMsdcCFile == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);

	return(args.back());
};

bool PnlMsdcFilDetail::evalTxtReuActive(
			DbsMsdc* dbsmsdc
		) {
	// pre.ixCrdaccFilIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecMsdcVPreset::PREMSDCIXCRDACCFIL, jref) & VecMsdcWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlMsdcFilDetail::evalButReuViewAvail(
			DbsMsdc* dbsmsdc
		) {
	// fil.reuEq(0)|(pre.ixCrdaccDat()&fil.retEq(dat)&pre.refPrd())

	vector<bool> args;
	bool a, b;

	a = false; a = (recFil.refUref == 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecMsdcVPreset::PREMSDCIXCRDACCDAT, jref) != 0);
	args.push_back(a);
	a = false; a = (recFil.refIxVTbl == VecMsdcVMFileRefTbl::DAT);
	args.push_back(a);
	a = false; a = (xchg->getRefPreset(VecMsdcVPreset::PREMSDCREFPRD, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlMsdcFilDetail::evalButReuViewActive(
			DbsMsdc* dbsmsdc
		) {
	// !fil.reuEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recFil.refUref == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlMsdcFilDetail::evalPupCntActive(
			DbsMsdc* dbsmsdc
		) {
	// pre.ixCrdaccFilIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecMsdcVPreset::PREMSDCIXCRDACCFIL, jref) & VecMsdcWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlMsdcFilDetail::evalButCntEditAvail(
			DbsMsdc* dbsmsdc
		) {
	// pre.adm()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getBoolvalPreset(VecMsdcVPreset::PREMSDCADM, jref));
	args.push_back(a);

	return(args.back());
};

bool PnlMsdcFilDetail::evalTxfAcvActive(
			DbsMsdc* dbsmsdc
		) {
	// pre.ixCrdaccFilIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecMsdcVPreset::PREMSDCIXCRDACCFIL, jref) & VecMsdcWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlMsdcFilDetail::evalTxfAnmActive(
			DbsMsdc* dbsmsdc
		) {
	// pre.ixCrdaccFilIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecMsdcVPreset::PREMSDCIXCRDACCFIL, jref) & VecMsdcWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlMsdcFilDetail::evalPupMimActive(
			DbsMsdc* dbsmsdc
		) {
	// pre.ixCrdaccFilIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecMsdcVPreset::PREMSDCIXCRDACCFIL, jref) & VecMsdcWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlMsdcFilDetail::evalButMimEditAvail(
			DbsMsdc* dbsmsdc
		) {
	// pre.adm()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getBoolvalPreset(VecMsdcVPreset::PREMSDCADM, jref));
	args.push_back(a);

	return(args.back());
};

bool PnlMsdcFilDetail::evalTxfSizActive(
			DbsMsdc* dbsmsdc
		) {
	// pre.ixCrdaccFilIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecMsdcVPreset::PREMSDCIXCRDACCFIL, jref) & VecMsdcWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlMsdcFilDetail::evalTxfCmtActive(
			DbsMsdc* dbsmsdc
		) {
	// pre.ixCrdaccFilIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecMsdcVPreset::PREMSDCIXCRDACCFIL, jref) & VecMsdcWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

