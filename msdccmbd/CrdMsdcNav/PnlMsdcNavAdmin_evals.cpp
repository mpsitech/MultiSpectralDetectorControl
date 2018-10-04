/**
  * \file PnlMsdcNavAdmin_evals.cpp
  * job handler for job PnlMsdcNavAdmin (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 4 Oct 2018
  * \date modified: 4 Oct 2018
  */

bool PnlMsdcNavAdmin::evalLstUsgAvail(
			DbsMsdc* dbsmsdc
		) {
	// pre.ixCrdaccUsg()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecMsdcVPreset::PREMSDCIXCRDACCUSG, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlMsdcNavAdmin::evalButUsgViewActive(
			DbsMsdc* dbsmsdc
		) {
	// LstUsg.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstUsg != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlMsdcNavAdmin::evalLstUsrAvail(
			DbsMsdc* dbsmsdc
		) {
	// pre.ixCrdaccUsr()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecMsdcVPreset::PREMSDCIXCRDACCUSR, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlMsdcNavAdmin::evalButUsrViewActive(
			DbsMsdc* dbsmsdc
		) {
	// LstUsr.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstUsr != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlMsdcNavAdmin::evalLstPrsAvail(
			DbsMsdc* dbsmsdc
		) {
	// pre.ixCrdaccPrs()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecMsdcVPreset::PREMSDCIXCRDACCPRS, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlMsdcNavAdmin::evalButPrsViewActive(
			DbsMsdc* dbsmsdc
		) {
	// LstPrs.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstPrs != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlMsdcNavAdmin::evalButScfNewcrdAvail(
			DbsMsdc* dbsmsdc
		) {
	// pre.ixCrdaccScf()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecMsdcVPreset::PREMSDCIXCRDACCSCF, jref) != 0);
	args.push_back(a);

	return(args.back());
};

