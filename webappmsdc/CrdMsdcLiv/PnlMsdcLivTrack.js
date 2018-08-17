/**
  * \file PnlMsdcLivTrack.js
  * web client functionality for panel PnlMsdcLivTrack
  * \author Alexander Wirthmueller
  * \date created: 15 Aug 2018
  * \date modified: 15 Aug 2018
  */

// IP cust --- INSERT

// --- expand state management
function minimize() {
	if (retrieveSi(srcdoc, "StatAppMsdcLivTrack", "srefIxMsdcVExpstate") == "mind") return;

	setSi(srcdoc, "StatAppMsdcLivTrack", "srefIxMsdcVExpstate", "mind");

	// change container heights
	getCrdwnd().changeHeight("Track", 30);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Track_side").setAttribute("height", "30");
	doc.getElementById("Track_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Track_side").src = "./PnlMsdcLivTrack_aside.html";
	doc.getElementById("Track_cont").src = "./PnlMsdcLivTrack_a.html";
};

function regularize() {
	if (retrieveSi(srcdoc, "StatAppMsdcLivTrack", "srefIxMsdcVExpstate") == "regd") return;

	setSi(srcdoc, "StatAppMsdcLivTrack", "srefIxMsdcVExpstate", "regd");

	// change content (container heights in refreshBD)
	doc.getElementById("Track_side").src = "./PnlMsdcLivTrack_bside.html";
	doc.getElementById("Track_cont").src = "./PnlMsdcLivTrack_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Track_side").contentDocument;
	contdoc = doc.getElementById("Track_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagMsdcLivTrack", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("Track_side").contentDocument;
	contdoc = doc.getElementById("Track_cont").contentDocument;
	hdrdoc = contdoc.getElementById("Track_hdr").contentDocument;
	contcontdoc = contdoc.getElementById("Track_cont").contentDocument;

	// IP initBD --- BEGIN
	initCpt(hdrdoc, "Cpt", retrieveTi(srcdoc, "TagMsdcLivTrack", "Cpt"));
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxMsdcVExpstate = retrieveSi(srcdoc, "StatAppMsdcLivTrack", "srefIxMsdcVExpstate");

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
	refreshButicon(hdrdoc, "ButMaster", "icon/master", true, retrieveCi(srcdoc, "ContInfMsdcLivTrack", "ButMasterOn") == "true");
	// IP refreshBD --- END

	getCrdwnd().changeHeight("Track", height+31);
	doc.getElementById("tdSide").setAttribute("height", "" + (height+31));
	doc.getElementById("Track_side").setAttribute("height", "" + (height+31));
	doc.getElementById("Track_cont").setAttribute("height", "" + (height+31));
	sidedoc.getElementById("tdFlex").setAttribute("height", "" + (height+31-30));
	contdoc.getElementById("tdCont").setAttribute("height", "" + height);
	contdoc.getElementById("Track_cont").setAttribute("height", "" + height);
};

function refresh() {
	var srefIxMsdcVExpstate = retrieveSi(srcdoc, "StatAppMsdcLivTrack", "srefIxMsdcVExpstate");

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
	srcdoc = doc.getElementById("Track_src").contentDocument;

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
	var str = serializeDpchAppDo(srcdoc, "DpchAppMsdcLivTrackDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngMsdcLivTrackData", "ContInfMsdcLivTrack", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngMsdcLivTrackData", "StatAppMsdcLivTrack", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngMsdcLivTrackData", "TagMsdcLivTrack", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngMsdcLivTrackData") {
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
			if (blk.nodeName == "DpchEngMsdcLivTrackData") {
				mergeDpchEngData(dom);
				init();

				getCrdwnd().setInitdone("Track");
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

			} else if (blk.nodeName == "DpchEngMsdcLivTrackData") {
				mergeDpchEngData(dom);
				refresh();
			};
		};
	};
};

