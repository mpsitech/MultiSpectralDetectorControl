/**
  * \file PnlMsdcNavOpr_evals.cpp
  * job handler for job PnlMsdcNavOpr (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 29 Aug 2018
  * \date modified: 29 Aug 2018
  */

bool PnlMsdcNavOpr::evalButLivNewcrdAvail(
			DbsMsdc* dbsmsdc
		) {
	// pre.ixCrdaccLiv()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecMsdcVPreset::PREMSDCIXCRDACCLIV, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlMsdcNavOpr::evalLstPrdAvail(
			DbsMsdc* dbsmsdc
		) {
	// pre.ixCrdaccPrd()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecMsdcVPreset::PREMSDCIXCRDACCPRD, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlMsdcNavOpr::evalButPrdViewActive(
			DbsMsdc* dbsmsdc
		) {
	// LstPrd.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstPrd != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlMsdcNavOpr::evalLstDatAvail(
			DbsMsdc* dbsmsdc
		) {
	// pre.ixCrdaccDat()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecMsdcVPreset::PREMSDCIXCRDACCDAT, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlMsdcNavOpr::evalButDatViewActive(
			DbsMsdc* dbsmsdc
		) {
	// LstDat.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstDat != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlMsdcNavOpr::evalButDatNewcrdActive(
			DbsMsdc* dbsmsdc
		) {
	// pre.refPrd()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecMsdcVPreset::PREMSDCREFPRD, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlMsdcNavOpr::evalLstFilAvail(
			DbsMsdc* dbsmsdc
		) {
	// pre.ixCrdaccFil()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecMsdcVPreset::PREMSDCIXCRDACCFIL, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlMsdcNavOpr::evalButFilViewActive(
			DbsMsdc* dbsmsdc
		) {
	// LstFil.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstFil != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlMsdcNavOpr::evalButFilNewcrdActive(
			DbsMsdc* dbsmsdc
		) {
	// pre.refDat()|pre.refPrd()

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getRefPreset(VecMsdcVPreset::PREMSDCREFDAT, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getRefPreset(VecMsdcVPreset::PREMSDCREFPRD, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

