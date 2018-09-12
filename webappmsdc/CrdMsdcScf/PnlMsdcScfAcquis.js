/**
  * \file PnlMsdcScfAcquis.js
  * web client functionality for panel PnlMsdcScfAcquis
  * \author Alexander Wirthmueller
  * \date created: 12 Sep 2018
  * \date modified: 12 Sep 2018
  */

// IP cust --- INSERT

// --- expand state management
function minimize() {
	if (retrieveSi(srcdoc, "StatAppMsdcScfAcquis", "srefIxMsdcVExpstate") == "mind") return;

	setSi(srcdoc, "StatAppMsdcScfAcquis", "srefIxMsdcVExpstate", "mind");

	// change container heights
	getCrdwnd().changeHeight("Acquis", 30);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Acquis_side").setAttribute("height", "30");
	doc.getElementById("Acquis_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Acquis_side").src = "./PnlMsdcScfAcquis_aside.html";
	doc.getElementById("Acquis_cont").src = "./PnlMsdcScfAcquis_a.html";
};

function regularize() {
	if (retrieveSi(srcdoc, "StatAppMsdcScfAcquis", "srefIxMsdcVExpstate") == "regd") return;

	setSi(srcdoc, "StatAppMsdcScfAcquis", "srefIxMsdcVExpstate", "regd");

	// change content (container heights in refreshBD)
	doc.getElementById("Acquis_side").src = "./PnlMsdcScfAcquis_bside.html";
	doc.getElementById("Acquis_cont").src = "./PnlMsdcScfAcquis_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Acquis_side").contentDocument;
	contdoc = doc.getElementById("Acquis_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagMsdcScfAcquis", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("Acquis_side").contentDocument;
	contdoc = doc.getElementById("Acquis_cont").contentDocument;
	hdrdoc = contdoc.getElementById("Acquis_hdr").contentDocument;
	contcontdoc = contdoc.getElementById("Acquis_cont").contentDocument;

	// IP initBD --- BEGIN
	initCpt(hdrdoc, "Cpt", retrieveTi(srcdoc, "TagMsdcScfAcquis", "Cpt"));
	initCpt(contcontdoc, "HdgIwi", retrieveTi(srcdoc, "TagMsdcScfAcquis", "HdgIwi"));
	initCpt(contcontdoc, "CptIsn", retrieveTi(srcdoc, "TagMsdcScfAcquis", "CptIsn"));
	initCpt(contcontdoc, "CptIps", retrieveTi(srcdoc, "TagMsdcScfAcquis", "CptIps"));
	initCpt(contcontdoc, "CptIfl", retrieveTi(srcdoc, "TagMsdcScfAcquis", "CptIfl"));
	initCpt(contcontdoc, "CptIfn", retrieveTi(srcdoc, "TagMsdcScfAcquis", "CptIfn"));
	initCpt(contcontdoc, "HdgVis", retrieveTi(srcdoc, "TagMsdcScfAcquis", "HdgVis"));
	initCpt(contcontdoc, "CptVty", retrieveTi(srcdoc, "TagMsdcScfAcquis", "CptVty"));
	refreshPup(contcontdoc, srcdoc, "PupVty", "", "FeedFPupVty", retrieveCi(srcdoc, "ContIacMsdcScfAcquis", "numFPupVty"), true, false);
	initCpt(contcontdoc, "CptVlp", retrieveTi(srcdoc, "TagMsdcScfAcquis", "CptVlp"));
	initCpt(contcontdoc, "CptVrp", retrieveTi(srcdoc, "TagMsdcScfAcquis", "CptVrp"));
	initCpt(contcontdoc, "CptVps", retrieveTi(srcdoc, "TagMsdcScfAcquis", "CptVps"));
	initCpt(contcontdoc, "CptVfl", retrieveTi(srcdoc, "TagMsdcScfAcquis", "CptVfl"));
	initCpt(contcontdoc, "CptVfn", retrieveTi(srcdoc, "TagMsdcScfAcquis", "CptVfn"));
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxMsdcVExpstate = retrieveSi(srcdoc, "StatAppMsdcScfAcquis", "srefIxMsdcVExpstate");

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
	var height = 317; // full cont height

	// IP refreshBD.vars --- BEGIN

	// IP refreshBD.vars --- END

	// IP refreshBD --- BEGIN
	refreshButicon(hdrdoc, "ButMaster", "icon/master", true, retrieveCi(srcdoc, "ContInfMsdcScfAcquis", "ButMasterOn") == "true");

	refreshTxt(contcontdoc, "TxtIsn", retrieveCi(srcdoc, "ContInfMsdcScfAcquis", "TxtIsn"));

	refreshTxt(contcontdoc, "TxtIps", retrieveCi(srcdoc, "ContInfMsdcScfAcquis", "TxtIps"));

	refreshTxt(contcontdoc, "TxtIfl", retrieveCi(srcdoc, "ContInfMsdcScfAcquis", "TxtIfl"));

	refreshTxt(contcontdoc, "TxtIfn", retrieveCi(srcdoc, "ContInfMsdcScfAcquis", "TxtIfn"));

	contcontdoc.getElementById("PupVty").value = retrieveCi(srcdoc, "ContIacMsdcScfAcquis", "numFPupVty");

	refreshTxf(contcontdoc, "TxfVlp", "", retrieveCi(srcdoc, "ContIacMsdcScfAcquis", "TxfVlp"), true, false, true);

	refreshTxf(contcontdoc, "TxfVrp", "", retrieveCi(srcdoc, "ContIacMsdcScfAcquis", "TxfVrp"), true, false, true);

	refreshTxt(contcontdoc, "TxtVps", retrieveCi(srcdoc, "ContInfMsdcScfAcquis", "TxtVps"));

	refreshTxt(contcontdoc, "TxtVfl", retrieveCi(srcdoc, "ContInfMsdcScfAcquis", "TxtVfl"));

	refreshTxt(contcontdoc, "TxtVfn", retrieveCi(srcdoc, "ContInfMsdcScfAcquis", "TxtVfn"));

	// IP refreshBD --- END

	getCrdwnd().changeHeight("Acquis", height+31);
	doc.getElementById("tdSide").setAttribute("height", "" + (height+31));
	doc.getElementById("Acquis_side").setAttribute("height", "" + (height+31));
	doc.getElementById("Acquis_cont").setAttribute("height", "" + (height+31));
	sidedoc.getElementById("tdFlex").setAttribute("height", "" + (height+31-30));
	contdoc.getElementById("tdCont").setAttribute("height", "" + height);
	contdoc.getElementById("Acquis_cont").setAttribute("height", "" + height);
};

function refresh() {
	var srefIxMsdcVExpstate = retrieveSi(srcdoc, "StatAppMsdcScfAcquis", "srefIxMsdcVExpstate");

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
	srcdoc = doc.getElementById("Acquis_src").contentDocument;

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
	var str = serializeDpchAppDo(srcdoc, "DpchAppMsdcScfAcquisDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handlePupChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "pup" + size + "mod");
	setCi(srcdoc, "ContIacMsdcScfAcquis", "numF" + ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppMsdcScfAcquisData", scrJref, "ContIacMsdcScfAcquis");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleTxfKey(_doc, ctlsref, size, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	if (evt.keyCode == 13) {
		setCi(srcdoc, "ContIacMsdcScfAcquis", ctlsref, elem.value);

		var str = serializeDpchAppData(srcdoc, "DpchAppMsdcScfAcquisData", scrJref, "ContIacMsdcScfAcquis");
		sendReq(str, doc, handleDpchAppDataDoReply);

		return false;
	};

	return true;
};

function handleTxfChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	setCi(srcdoc, "ContIacMsdcScfAcquis", ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppMsdcScfAcquisData", scrJref, "ContIacMsdcScfAcquis");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngMsdcScfAcquisData", "ContIacMsdcScfAcquis", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngMsdcScfAcquisData", "ContInfMsdcScfAcquis", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngMsdcScfAcquisData", "FeedFPupVty", srcdoc)) mask.push("feedFPupVty");
	if (updateSrcblock(dom, "DpchEngMsdcScfAcquisData", "StatAppMsdcScfAcquis", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngMsdcScfAcquisData", "TagMsdcScfAcquis", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngMsdcScfAcquisData") {
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
			if (blk.nodeName == "DpchEngMsdcScfAcquisData") {
				mergeDpchEngData(dom);
				init();

				getCrdwnd().setInitdone("Acquis");
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

			} else if (blk.nodeName == "DpchEngMsdcScfAcquisData") {
				mergeDpchEngData(dom);
				refresh();
			};
		};
	};
};

