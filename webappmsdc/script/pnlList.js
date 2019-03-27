function strShowing(tpl, firstdisp, lastdisp, ntot, empty) {
	var retval;

	if (parseInt(ntot) == 0) {
		retval = empty;
	} else {
		retval = tpl;
		retval = retval.replace(/&firstdisp;/g, firstdisp);
		retval = retval.replace(/&lastdisp;/g, lastdisp);
		retval = retval.replace(/&ntot;/g, ntot);
	};

	return retval;
};

function strFor(tpl, pretit) {
	var retval;

	if (pretit == "") {
		retval = "";
	} else {
		retval = tpl;
		retval = retval.replace(/&pretit;/g, pretit);
	};

	return retval;
};
