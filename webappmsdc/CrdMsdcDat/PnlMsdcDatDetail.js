/**
  * \file PnlMsdcDatDetail.js
  * web client functionality for panel PnlMsdcDatDetail
  * \author Alexander Wirthmueller
  * \date created: 15 Aug 2018
  * \date modified: 15 Aug 2018
  */

// IP cust --- INSERT

// --- expand state management
function minimize(updh) {
	if (retrieveSi(srcdoc, "StatAppMsdcDatDetail", "srefIxMsdcVExpstate") == "mind") return;

	setSi(srcdoc, "StatAppMsdcDatDetail", "srefIxMsdcVExpstate", "mind");

	// change container heights
	getRecwnd().changeHeight("Detail", 30, updh);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Detail_side").setAttribute("height", "30");
	doc.getElementById("Detail_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Detail_side").src = "./PnlMsdcDatDetail_aside.html";
	doc.getElementById("Detail_cont").src = "./PnlMsdcDatDetail_a.html";
};

function regularize() {
	if (retrieveSi(srcdoc, "StatAppMsdcDatDetail", "srefIxMsdcVExpstate") == "regd") return;

	setSi(srcdoc, "StatAppMsdcDatDetail", "srefIxMsdcVExpstate", "regd");

	// change content (container heights in refreshBD)
	doc.getElementById("Detail_side").src = "./PnlMsdcDatDetail_bside.html";
	doc.getElementById("Detail_cont").src = "./PnlMsdcDatDetail_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagMsdcDatDetail", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	contcontdoc = contdoc.getElementById("Detail_cont").contentDocument;
	ftrdoc = contdoc.getElementById("Detail_ftr").contentDocument;

	// IP initBD --- BEGIN
	initCpt(contcontdoc, "CptAft", retrieveTi(srcdoc, "TagMsdcDatDetail", "CptAft"));
	initCpt(contcontdoc, "CptPrd", retrieveTi(srcdoc, "TagMsdcDatDetail", "CptPrd"));
	initCpt(contcontdoc, "CptSta", retrieveTi(srcdoc, "TagMsdcDatDetail", "CptSta"));
	initCpt(contcontdoc, "CptSto", retrieveTi(srcdoc, "TagMsdcDatDetail", "CptSto"));
	initCpt(contcontdoc, "CptCmt", retrieveTi(srcdoc, "TagMsdcDatDetail", "CptCmt"));
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxMsdcVExpstate = retrieveSi(srcdoc, "StatAppMsdcDatDetail", "srefIxMsdcVExpstate");

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
	var height = 192; // full cont height

	// IP refreshBD.vars --- BEGIN
	var PupAftAlt = (retrieveSi(srcdoc, "StatAppMsdcDatDetail", "PupAftAlt") == "true");
	var TxfAftValid = (retrieveSi(srcdoc, "StatShrMsdcDatDetail", "TxfAftValid") == "true");
	var PupAftActive = (retrieveSi(srcdoc, "StatShrMsdcDatDetail", "PupAftActive") == "true");
	var ButAftEditAvail = (retrieveSi(srcdoc, "StatShrMsdcDatDetail", "ButAftEditAvail") == "true");

	var TxtPrdActive = (retrieveSi(srcdoc, "StatShrMsdcDatDetail", "TxtPrdActive") == "true");
	var ButPrdViewAvail = (retrieveSi(srcdoc, "StatShrMsdcDatDetail", "ButPrdViewAvail") == "true");
	var ButPrdViewActive = (retrieveSi(srcdoc, "StatShrMsdcDatDetail", "ButPrdViewActive") == "true");

	var TxfStaActive = (retrieveSi(srcdoc, "StatShrMsdcDatDetail", "TxfStaActive") == "true");

	var TxfStoActive = (retrieveSi(srcdoc, "StatShrMsdcDatDetail", "TxfStoActive") == "true");

	var TxfCmtActive = (retrieveSi(srcdoc, "StatShrMsdcDatDetail", "TxfCmtActive") == "true");

	var ButSaveActive = (retrieveSi(srcdoc, "StatShrMsdcDatDetail", "ButSaveActive") == "true");
	var mytd, first;
	// IP refreshBD.vars --- END

	// IP refreshBD --- BEGIN
	if ( (PupAftAlt == !contcontdoc.getElementById("TxfAft")) || (!PupAftAlt == !contcontdoc.getElementById("PupAft")) ) {
		mytd = contcontdoc.getElementById("dynAft");
		clearElem(mytd);

		if (PupAftAlt) mytd.appendChild(makeInputTxf(contcontdoc, "TxfAft", ""));
		else mytd.appendChild(makeSelectPup(contcontdoc, "PupAft", ""));
	};

	if (PupAftAlt) refreshTxf(contcontdoc, "TxfAft", "", retrieveCi(srcdoc, "ContIacMsdcDatDetail", "TxfAft"), PupAftActive, false, TxfAftValid);
	else refreshPup(contcontdoc, srcdoc, "PupAft", "", "FeedFPupAft", retrieveCi(srcdoc, "ContIacMsdcDatDetail", "numFPupAft"), true, false);

	if ((ButAftEditAvail == !contcontdoc.getElementById("ButAftEdit"))) {
		mytd = contcontdoc.getElementById("rdynAft");
		clearElem(mytd);

		first = true;

		if (ButAftEditAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButAftEdit", "icon/edit"));
		};
	};

	if ((ButPrdViewAvail == !contcontdoc.getElementById("ButPrdView"))) {
		mytd = contcontdoc.getElementById("rdynPrd");
		clearElem(mytd);

		first = true;

		if (ButPrdViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButPrdView", "icon/view"));
		};
	};

	refreshTxt(contcontdoc, "TxtPrd", retrieveCi(srcdoc, "ContInfMsdcDatDetail", "TxtPrd"));

	if (ButPrdViewAvail) refreshButicon(contcontdoc, "ButPrdView", "icon/view", ButPrdViewActive, false);

	refreshTxf(contcontdoc, "TxfSta", "", retrieveCi(srcdoc, "ContIacMsdcDatDetail", "TxfSta"), TxfStaActive, false, true);

	refreshTxf(contcontdoc, "TxfSto", "", retrieveCi(srcdoc, "ContIacMsdcDatDetail", "TxfSto"), TxfStoActive, false, true);

	refreshTxft(contcontdoc, "TxfCmt", retrieveCi(srcdoc, "ContIacMsdcDatDetail", "TxfCmt"), TxfCmtActive, false, true);

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
	var srefIxMsdcVExpstate = retrieveSi(srcdoc, "StatAppMsdcDatDetail", "srefIxMsdcVExpstate");

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

function handleButToggleClick(basectlsref) {
	var alt;

	if (retrieveSi(srcdoc, "StatAppMsdcDatDetail", basectlsref + "Alt") == "true") alt = "false"; else alt = "true";
	setSi(srcdoc, "StatAppMsdcDatDetail", basectlsref + "Alt", alt);

	refresh();
};

// --- generalized event handlers for shared controls

function handleButClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppMsdcDatDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButCrdopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppMsdcDatDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);
};

function handleButDlgopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppMsdcDatDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoDlgopenReply);
};

function handlePupChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "pup" + size + "mod");
	setCi(srcdoc, "ContIacMsdcDatDetail", "numF" + ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppMsdcDatDetailData", scrJref, "ContIacMsdcDatDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleTxfKey(_doc, ctlsref, size, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	if (evt.keyCode == 13) {
		setCi(srcdoc, "ContIacMsdcDatDetail", ctlsref, elem.value);

		var str = serializeDpchAppData(srcdoc, "DpchAppMsdcDatDetailData", scrJref, "ContIacMsdcDatDetail");
		sendReq(str, doc, handleDpchAppDataDoReply);

		return false;
	};

	return true;
};

function handleTxfChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	setCi(srcdoc, "ContIacMsdcDatDetail", ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppMsdcDatDetailData", scrJref, "ContIacMsdcDatDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleTxftKey(_doc, ctlsref, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txfmod");

	return true;
};

function handleTxftChange(_doc, ctlsref) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txfmod");

	setCi(srcdoc, "ContIacMsdcDatDetail", ctlsref, elem.value.replace(/\n/g, ";"));

	var str = serializeDpchAppData(srcdoc, "DpchAppMsdcDatDetailData", scrJref, "ContIacMsdcDatDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngMsdcDatDetailData", "ContIacMsdcDatDetail", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngMsdcDatDetailData", "ContInfMsdcDatDetail", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngMsdcDatDetailData", "FeedFPupAft", srcdoc)) mask.push("feedFPupAft");
	if (updateSrcblock(dom, "DpchEngMsdcDatDetailData", "StatAppMsdcDatDetail", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngMsdcDatDetailData", "StatShrMsdcDatDetail", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngMsdcDatDetailData", "TagMsdcDatDetail", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngMsdcDatDetailData") {
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
			if (blk.nodeName == "DpchEngMsdcDatDetailData") {
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

			} else if (blk.nodeName == "DpchEngMsdcDatDetailData") {
				mergeDpchEngData(dom);
				refresh();
			};
		};
	};
};

function handleDpchAppDoCrdopenReply() {
	var dom, blk;

	var accepted, _scrJref, sref;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//msdc:*");

		if (blk) {
			if (blk.nodeName == "DpchEngMsdcConfirm") {
				accepted = retrieveValue(dom, "//msdc:DpchEngMsdcConfirm/msdc:accepted");
				_scrJref = retrieveValue(dom, "//msdc:DpchEngMsdcConfirm/msdc:scrJref");
				sref = retrieveValue(dom, "//msdc:DpchEngMsdcConfirm/msdc:sref");

				if (accepted == "true") window.open("/web/" + sref + "/" + sref + ".html?scrJref=" + _scrJref, "_blank");

			} else if (blk.nodeName == "DpchEngMsdcAlert") {
				getCrdwnd().showAlr(retrieveValue(dom, "//msdc:DpchEngMsdcAlert/msdc:scrJref"),
						retrieveBlock(dom, "//msdc:DpchEngMsdcAlert/msdc:ContInfMsdcAlert"),
						retrieveBlock(dom, "//msdc:DpchEngMsdcAlert/msdc:FeedFMcbAlert"));
			};
		};
	};
};

function handleDpchAppDoDlgopenReply() {
	var dom, blk;

	var accepted, _scrJref, sref;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//msdc:*");

		if (blk) {
			if (blk.nodeName == "DpchEngMsdcConfirm") {
				accepted = retrieveValue(dom, "//msdc:DpchEngMsdcConfirm/msdc:accepted");
				_scrJref = retrieveValue(dom, "//msdc:DpchEngMsdcConfirm/msdc:scrJref");
				sref = retrieveValue(dom, "//msdc:DpchEngMsdcConfirm/msdc:sref");

				if ((accepted == "true") && (sref != "")) getCrdwnd().showDlg(sref, _scrJref);
			};
		};
	};
};

