/**
  * \file PnlMsdcDatRef1NFile_evals.cpp
  * job handler for job PnlMsdcDatRef1NFile (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 12 Sep 2018
  * \date modified: 12 Sep 2018
  */

bool PnlMsdcDatRef1NFile::evalButViewAvail(
			DbsMsdc* dbsmsdc
		) {
	// !sel()|(pre.ixCrdaccFil()&pre.refDat())

	vector<bool> args;
	bool a, b;

	a = false; a = (qry->stgiac.jnum != 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);
	a = false; a = (xchg->getIxPreset(VecMsdcVPreset::PREMSDCIXCRDACCFIL, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getRefPreset(VecMsdcVPreset::PREMSDCREFDAT, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlMsdcDatRef1NFile::evalButViewActive(
			DbsMsdc* dbsmsdc
		) {
	// sel()

	vector<bool> args;
	bool a;

	a = false; a = (qry->stgiac.jnum != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlMsdcDatRef1NFile::evalButNewAvail(
			DbsMsdc* dbsmsdc
		) {
	// pre.ixCrdaccFilIncl(edit)&pre.refDat()

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecMsdcVPreset::PREMSDCIXCRDACCFIL, jref) & VecMsdcWAccess::EDIT);
	args.push_back(a);
	a = false; a = (xchg->getRefPreset(VecMsdcVPreset::PREMSDCREFDAT, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);

	return(args.back());
};

bool PnlMsdcDatRef1NFile::evalButDeleteAvail(
			DbsMsdc* dbsmsdc
		) {
	// pre.ixCrdaccDatIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecMsdcVPreset::PREMSDCIXCRDACCDAT, jref) & VecMsdcWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlMsdcDatRef1NFile::evalButDeleteActive(
			DbsMsdc* dbsmsdc
		) {
	// sel()

	vector<bool> args;
	bool a;

	a = false; a = (qry->stgiac.jnum != 0);
	args.push_back(a);

	return(args.back());
};

