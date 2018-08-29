/**
  * \file CrdMsdcNav_evals.cpp
  * job handler for job CrdMsdcNav (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 29 Aug 2018
  * \date modified: 29 Aug 2018
  */

bool CrdMsdcNav::evalPnlpreAvail(
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

bool CrdMsdcNav::evalPnladminAvail(
			DbsMsdc* dbsmsdc
		) {
	// pre.ixCrdaccUsg()|pre.ixCrdaccUsr()|pre.ixCrdaccPrs()|pre.ixCrdaccScf()

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecMsdcVPreset::PREMSDCIXCRDACCUSG, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecMsdcVPreset::PREMSDCIXCRDACCUSR, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecMsdcVPreset::PREMSDCIXCRDACCPRS, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecMsdcVPreset::PREMSDCIXCRDACCSCF, jref) != 0);
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

bool CrdMsdcNav::evalPnloprAvail(
			DbsMsdc* dbsmsdc
		) {
	// pre.ixCrdaccLiv()|pre.ixCrdaccPrd()|pre.ixCrdaccDat()|pre.ixCrdaccFil()

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecMsdcVPreset::PREMSDCIXCRDACCLIV, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecMsdcVPreset::PREMSDCIXCRDACCPRD, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecMsdcVPreset::PREMSDCIXCRDACCDAT, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecMsdcVPreset::PREMSDCIXCRDACCFIL, jref) != 0);
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

bool CrdMsdcNav::evalMspCrd1Avail(
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

bool CrdMsdcNav::evalMitCrdUsgAvail(
			DbsMsdc* dbsmsdc
		) {
	// pre.ixCrdaccUsg()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecMsdcVPreset::PREMSDCIXCRDACCUSG, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdMsdcNav::evalMitCrdUsrAvail(
			DbsMsdc* dbsmsdc
		) {
	// pre.ixCrdaccUsr()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecMsdcVPreset::PREMSDCIXCRDACCUSR, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdMsdcNav::evalMitCrdPrsAvail(
			DbsMsdc* dbsmsdc
		) {
	// pre.ixCrdaccPrs()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecMsdcVPreset::PREMSDCIXCRDACCPRS, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdMsdcNav::evalMitCrdScfAvail(
			DbsMsdc* dbsmsdc
		) {
	// pre.ixCrdaccScf()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecMsdcVPreset::PREMSDCIXCRDACCSCF, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdMsdcNav::evalMspCrd2Avail(
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

bool CrdMsdcNav::evalMitCrdLivAvail(
			DbsMsdc* dbsmsdc
		) {
	// pre.ixCrdaccLiv()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecMsdcVPreset::PREMSDCIXCRDACCLIV, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdMsdcNav::evalMitCrdPrdAvail(
			DbsMsdc* dbsmsdc
		) {
	// pre.ixCrdaccPrd()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecMsdcVPreset::PREMSDCIXCRDACCPRD, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdMsdcNav::evalMitCrdDatAvail(
			DbsMsdc* dbsmsdc
		) {
	// pre.ixCrdaccDat()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecMsdcVPreset::PREMSDCIXCRDACCDAT, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdMsdcNav::evalMitCrdDatActive(
			DbsMsdc* dbsmsdc
		) {
	// pre.refPrd()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecMsdcVPreset::PREMSDCREFPRD, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdMsdcNav::evalMitCrdFilAvail(
			DbsMsdc* dbsmsdc
		) {
	// pre.ixCrdaccFil()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecMsdcVPreset::PREMSDCIXCRDACCFIL, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdMsdcNav::evalMspApp2Avail(
			DbsMsdc* dbsmsdc
		) {
	// MitAppLoiAvail()

	vector<bool> args;
	bool a;

	a = false; a = evalMitAppLoiAvail(dbsmsdc);
	args.push_back(a);

	return(args.back());
};

bool CrdMsdcNav::evalMitAppLoiAvail(
			DbsMsdc* dbsmsdc
		) {
	// virgin()

	vector<bool> args;
	bool a;

	a = false; {uint cnt = 0; dbsmsdc->loadUintBySQL("SELECT COUNT(ref) FROM TblMsdcMUser WHERE sref <> 'temp'", cnt); a = (cnt == 0);};
	args.push_back(a);

	return(args.back());
};

