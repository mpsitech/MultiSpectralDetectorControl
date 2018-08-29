/**
  * \file PnlMsdcScfPrcctl.js
  * web client functionality for panel PnlMsdcScfPrcctl
  * \author Alexander Wirthmueller
  * \date created: 29 Aug 2018
  * \date modified: 29 Aug 2018
  */

// IP cust --- INSERT

// --- expand state management
function minimize() {
	if (retrieveSi(srcdoc, "StatAppMsdcScfPrcctl", "srefIxMsdcVExpstate") == "mind") return;

	setSi(srcdoc, "StatAppMsdcScfPrcctl", "srefIxMsdcVExpstate", "mind");

	// change container heights
	getCrdwnd().changeHeight("Prcctl", 30);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Prcctl_side").setAttribute("height", "30");
	doc.getElementById("Prcctl_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Prcctl_side").src = "./PnlMsdcScfPrcctl_aside.html";
	doc.getElementById("Prcctl_cont").src = "./PnlMsdcScfPrcctl_a.html";
};

function regularize() {
	if (retrieveSi(srcdoc, "StatAppMsdcScfPrcctl", "srefIxMsdcVExpstate") == "regd") return;

	setSi(srcdoc, "StatAppMsdcScfPrcctl", "srefIxMsdcVExpstate", "regd");

	// change content (container heights in refreshBD)
	doc.getElementById("Prcctl_side").src = "./PnlMsdcScfPrcctl_bside.html";
	doc.getElementById("Prcctl_cont").src = "./PnlMsdcScfPrcctl_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Prcctl_side").contentDocument;
	contdoc = doc.getElementById("Prcctl_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagMsdcScfPrcctl", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("Prcctl_side").contentDocument;
	contdoc = doc.getElementById("Prcctl_cont").contentDocument;
	hdrdoc = contdoc.getElementById("Prcctl_hdr").contentDocument;
	contcontdoc = contdoc.getElementById("Prcctl_cont").contentDocument;

	// IP initBD --- BEGIN
	initCpt(hdrdoc, "Cpt", retrieveTi(srcdoc, "TagMsdcScfPrcctl", "Cpt"));
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxMsdcVExpstate = retrieveSi(srcdoc, "StatAppMsdcScfPrcctl", "srefIxMsdcVExpstate");

	if (srefIxMsdcVExpstate == "mind") {
		initA();
	} else if (srefIxMsdcVExpstate == "regd") {
		initBD(true);
	} else if (srefIxMsdcVExpstate == "detd") {
		initBD(false);
	};
};

function refreshA() {
};

function refreshBD(bNotD) {
	var height = 10; // full cont height

	// IP refreshBD.vars --- BEGIN
	// IP refreshBD.vars --- END

	// IP refreshBD --- BEGIN
	refreshButicon(hdrdoc, "ButMaster", "icon/master", true, retrieveCi(srcdoc, "ContInfMsdcScfPrcctl", "ButMasterOn") == "true");
	// IP refreshBD --- END

	getCrdwnd().changeHeight("Prcctl", height+31);
	doc.getElementById("tdSide").setAttribute("height", "" + (height+31));
	doc.getElementById("Prcctl_side").setAttribute("height", "" + (height+31));
	doc.getElementById("Prcctl_cont").setAttribute("height", "" + (height+31));
	sidedoc.getElementById("tdFlex").setAttribute("height", "" + (height+31-30));
	contdoc.getElementById("tdCont").setAttribute("height", "" + height);
	contdoc.getElementById("Prcctl_cont").setAttribute("height", "" + height);
};

function refresh() {
	var srefIxMsdcVExpstate = retrieveSi(srcdoc, "StatAppMsdcScfPrcctl", "srefIxMsdcVExpstate");

	if (srefIxMsdcVExpstate == "mind") {
		refreshA();
	} else if (srefIxMsdcVExpstate == "regd") {
		refreshBD(true);
	} else if (srefIxMsdcVExpstate == "detd") {
		refreshBD(false);
	};
};

// --- event handlers
function handleLoad() {
	scrJref = location.search.substr(location.search.indexOf("scrJref=")+8);

	doc = document;
	srcdoc = doc.getElementById("Prcctl_src").contentDocument;

	var str = serializeDpchApp("DpchAppMsdcInit", scrJref);
	sendReq(str, doc, handleDpchAppInitReply, true);
};

// --- specific event handlers for app controls

function handleButRegularizeClick() {
	regularize(true);
};

function handleButMinimizeClick() {
	minimize(true);
};

// --- generalized event handlers for app controls

// --- generalized event handlers for shared controls

function handleButClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppMsdcScfPrcctlDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngMsdcScfPrcctlData", "ContInfMsdcScfPrcctl", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngMsdcScfPrcctlData", "StatAppMsdcScfPrcctl", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngMsdcScfPrcctlData", "TagMsdcScfPrcctl", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngMsdcScfPrcctlData") {
		mergeDpchEngData(dom);
		refresh();
	};
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//msdc:*");
		if (blk) {
			if (blk.nodeName == "DpchEngMsdcScfPrcctlData") {
				mergeDpchEngData(dom);
				init();

				getCrdwnd().setInitdone("Prcctl");
			};
		};
	};
};

function handleDpchAppDataDoReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		// check dispatch type
		blk = retrieveBlock(dom, "//msdc:*");

		if (blk) {
			if (blk.nodeName == "DpchEngMsdcConfirm") {
				// do nothing

			} else if (blk.nodeName == "DpchEngMsdcScfPrcctlData") {
				mergeDpchEngData(dom);
				refresh();
			};
		};
	};
};

