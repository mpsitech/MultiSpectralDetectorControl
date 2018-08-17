/**
  * \file PnlMsdcNavHeadbar_evals.cpp
  * job handler for job PnlMsdcNavHeadbar (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 15 Aug 2018
  * \date modified: 15 Aug 2018
  */

bool PnlMsdcNavHeadbar::evalMenCrdAvail(
			DbsMsdc* dbsmsdc
		) {
	// MspCrd1Avail()|MspCrd2Avail()

	vector<bool> args;
	bool a, b;

	a = false; a = evalMspCrd1Avail(dbsmsdc);
	args.push_back(a);
	a = false; a = evalMspCrd2Avail(dbsmsdc);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlMsdcNavHeadbar::evalMspCrd1Avail(
			DbsMsdc* dbsmsdc
		) {
	// MitCrdUsgAvail()|MitCrdUsrAvail()|MitCrdPrsAvail()|MitCrdScfAvail()

	vector<bool> args;
	bool a, b;

	a = false; a = evalMitCrdUsgAvail(dbsmsdc);
	args.push_back(a);
	a = false; a = evalMitCrdUsrAvail(dbsmsdc);
	args.push_back(a);
	a = false; a = evalMitCrdPrsAvail(dbsmsdc);
	args.push_back(a);
	a = false; a = evalMitCrdScfAvail(dbsmsdc);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlMsdcNavHeadbar::evalMitCrdUsgAvail(
			DbsMsdc* dbsmsdc
		) {
	// pre.ixCrdaccUsg()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecMsdcVPreset::PREMSDCIXCRDACCUSG, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlMsdcNavHeadbar::evalMitCrdUsrAvail(
			DbsMsdc* dbsmsdc
		) {
	// pre.ixCrdaccUsr()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecMsdcVPreset::PREMSDCIXCRDACCUSR, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlMsdcNavHeadbar::evalMitCrdPrsAvail(
			DbsMsdc* dbsmsdc
		) {
	// pre.ixCrdaccPrs()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecMsdcVPreset::PREMSDCIXCRDACCPRS, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlMsdcNavHeadbar::evalMitCrdScfAvail(
			DbsMsdc* dbsmsdc
		) {
	// pre.ixCrdaccScf()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecMsdcVPreset::PREMSDCIXCRDACCSCF, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlMsdcNavHeadbar::evalMspCrd2Avail(
			DbsMsdc* dbsmsdc
		) {
	// MitCrdLivAvail()|MitCrdPrdAvail()|MitCrdDatAvail()|MitCrdFilAvail()

	vector<bool> args;
	bool a, b;

	a = false; a = evalMitCrdLivAvail(dbsmsdc);
	args.push_back(a);
	a = false; a = evalMitCrdPrdAvail(dbsmsdc);
	args.push_back(a);
	a = false; a = evalMitCrdDatAvail(dbsmsdc);
	args.push_back(a);
	a = false; a = evalMitCrdFilAvail(dbsmsdc);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlMsdcNavHeadbar::evalMitCrdLivAvail(
			DbsMsdc* dbsmsdc
		) {
	// pre.ixCrdaccLiv()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecMsdcVPreset::PREMSDCIXCRDACCLIV, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlMsdcNavHeadbar::evalMitCrdPrdAvail(
			DbsMsdc* dbsmsdc
		) {
	// pre.ixCrdaccPrd()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecMsdcVPreset::PREMSDCIXCRDACCPRD, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlMsdcNavHeadbar::evalMitCrdDatAvail(
			DbsMsdc* dbsmsdc
		) {
	// pre.ixCrdaccDat()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecMsdcVPreset::PREMSDCIXCRDACCDAT, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlMsdcNavHeadbar::evalMitCrdFilAvail(
			DbsMsdc* dbsmsdc
		) {
	// pre.ixCrdaccFil()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecMsdcVPreset::PREMSDCIXCRDACCFIL, jref) != 0);
	args.push_back(a);

	return(args.back());
};

