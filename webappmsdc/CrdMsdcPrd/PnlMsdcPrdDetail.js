/**
  * \file PnlMsdcPrdDetail.js
  * web client functionality for panel PnlMsdcPrdDetail
  * \author Alexander Wirthmueller
  * \date created: 15 Aug 2018
  * \date modified: 15 Aug 2018
  */

// IP cust --- INSERT

// --- expand state management
function minimize(updh) {
	if (retrieveSi(srcdoc, "StatAppMsdcPrdDetail", "srefIxMsdcVExpstate") == "mind") return;

	setSi(srcdoc, "StatAppMsdcPrdDetail", "srefIxMsdcVExpstate", "mind");

	// change container heights
	getRecwnd().changeHeight("Detail", 30, updh);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Detail_side").setAttribute("height", "30");
	doc.getElementById("Detail_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Detail_side").src = "./PnlMsdcPrdDetail_aside.html";
	doc.getElementById("Detail_cont").src = "./PnlMsdcPrdDetail_a.html";
};

function regularize() {
	if (retrieveSi(srcdoc, "StatAppMsdcPrdDetail", "srefIxMsdcVExpstate") == "regd") return;

	setSi(srcdoc, "StatAppMsdcPrdDetail", "srefIxMsdcVExpstate", "regd");

	// change content (container heights in refreshBD)
	doc.getElementById("Detail_side").src = "./PnlMsdcPrdDetail_bside.html";
	doc.getElementById("Detail_cont").src = "./PnlMsdcPrdDetail_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagMsdcPrdDetail", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	contcontdoc = contdoc.getElementById("Detail_cont").contentDocument;
	ftrdoc = contdoc.getElementById("Detail_ftr").contentDocument;

	// IP initBD --- BEGIN
	initCpt(contcontdoc, "CptSta", retrieveTi(srcdoc, "TagMsdcPrdDetail", "CptSta"));
	initCpt(contcontdoc, "CptSto", retrieveTi(srcdoc, "TagMsdcPrdDetail", "CptSto"));
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxMsdcVExpstate = retrieveSi(srcdoc, "StatAppMsdcPrdDetail", "srefIxMsdcVExpstate");

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
	var height = 60; // full cont height

	// IP refreshBD.vars --- BEGIN
	var TxfStaActive = (retrieveSi(srcdoc, "StatShrMsdcPrdDetail", "TxfStaActive") == "true");

	var TxfStoActive = (retrieveSi(srcdoc, "StatShrMsdcPrdDetail", "TxfStoActive") == "true");

	var ButSaveActive = (retrieveSi(srcdoc, "StatShrMsdcPrdDetail", "ButSaveActive") == "true");
	// IP refreshBD.vars --- END

	// IP refreshBD --- BEGIN
	refreshTxf(contcontdoc, "TxfSta", "", retrieveCi(srcdoc, "ContIacMsdcPrdDetail", "TxfSta"), TxfStaActive, false, true);

	refreshTxf(contcontdoc, "TxfSto", "", retrieveCi(srcdoc, "ContIacMsdcPrdDetail", "TxfSto"), TxfStoActive, false, true);

	refreshButicon(ftrdoc, "ButSave", "icon/save", ButSaveActive, false);
	// IP refreshBD --- END

	getRecwnd().changeHeight("Detail", height+26, true);
	doc.getElementById("tdSide").setAttribute("height", "" + (height+26));
	doc.getElementById("Detail_side").setAttribute("height", "" + (height+26));
	doc.getElementById("Detail_cont").setAttribute("height", "" + (height+26));
	sidedoc.getElementById("tdFlex").setAttribute("height", "" + (height+26-30));
	contdoc.getElementById("tdCont").setAttribute("height", "" + height);
	contdoc.getElementById("Detail_cont").setAttribute("height", "" + height);
};

function refresh() {
	var srefIxMsdcVExpstate = retrieveSi(srcdoc, "StatAppMsdcPrdDetail", "srefIxMsdcVExpstate");

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
	srcdoc = doc.getElementById("Detail_src").contentDocument;

	var str = serializeDpchApp("DpchAppMsdcInit", scrJref);
	sendReq(str, doc, handleDpchAppInitReply, true);
};

// --- specific event handlers for app controls

function handleButMinimizeClick() {
	minimize(true);
};

function handleButRegularizeClick() {
	regularize(true);
};

// --- generalized event handlers for app controls

// --- generalized event handlers for shared controls

function handleButClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppMsdcPrdDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleTxfKey(_doc, ctlsref, size, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	if (evt.keyCode == 13) {
		setCi(srcdoc, "ContIacMsdcPrdDetail", ctlsref, elem.value);

		var str = serializeDpchAppData(srcdoc, "DpchAppMsdcPrdDetailData", scrJref, "ContIacMsdcPrdDetail");
		sendReq(str, doc, handleDpchAppDataDoReply);

		return false;
	};

	return true;
};

function handleTxfChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	setCi(srcdoc, "ContIacMsdcPrdDetail", ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppMsdcPrdDetailData", scrJref, "ContIacMsdcPrdDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngMsdcPrdDetailData", "ContIacMsdcPrdDetail", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngMsdcPrdDetailData", "StatAppMsdcPrdDetail", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngMsdcPrdDetailData", "StatShrMsdcPrdDetail", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngMsdcPrdDetailData", "TagMsdcPrdDetail", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngMsdcPrdDetailData") {
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
			if (blk.nodeName == "DpchEngMsdcPrdDetailData") {
				mergeDpchEngData(dom);
				init();

				getRecwnd().setInitdone("Detail");
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

			} else if (blk.nodeName == "DpchEngMsdcPrdDetailData") {
				mergeDpchEngData(dom);
				refresh();
			};
		};
	};
};

