/**
  * \file PnlMsdcUsrList_evals.cpp
  * job handler for job PnlMsdcUsrList (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 15 Aug 2018
  * \date modified: 15 Aug 2018
  */

bool PnlMsdcUsrList::evalButDeleteActive(
			DbsMsdc* dbsmsdc
		) {
	// sel()

	vector<bool> args;
	bool a;

	a = false; a = (qry->stgiac.jnum != 0);
	args.push_back(a);

	return(args.back());
};

