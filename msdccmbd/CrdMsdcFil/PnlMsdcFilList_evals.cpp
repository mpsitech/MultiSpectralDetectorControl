/**
  * \file PnlMsdcFilList_evals.cpp
  * job handler for job PnlMsdcFilList (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 12 Sep 2018
  * \date modified: 12 Sep 2018
  */

bool PnlMsdcFilList::evalButDeleteActive(
			DbsMsdc* dbsmsdc
		) {
	// sel()

	vector<bool> args;
	bool a;

	a = false; a = (qry->stgiac.jnum != 0);
	args.push_back(a);

	return(args.back());
};

