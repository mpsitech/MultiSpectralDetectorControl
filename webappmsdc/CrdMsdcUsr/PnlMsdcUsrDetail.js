/**
  * \file PnlMsdcUsrDetail.js
  * web client functionality for panel PnlMsdcUsrDetail
  * \author Alexander Wirthmueller
  * \date created: 29 Aug 2018
  * \date modified: 29 Aug 2018
  */

// IP cust --- INSERT

// --- expand state management
function minimize(updh) {
	if (retrieveSi(srcdoc, "StatAppMsdcUsrDetail", "srefIxMsdcVExpstate") == "mind") return;

	setSi(srcdoc, "StatAppMsdcUsrDetail", "srefIxMsdcVExpstate", "mind");

	// change container heights
	getRecwnd().changeHeight("Detail", 30, updh);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Detail_side").setAttribute("height", "30");
	doc.getElementById("Detail_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Detail_side").src = "./PnlMsdcUsrDetail_aside.html";
	doc.getElementById("Detail_cont").src = "./PnlMsdcUsrDetail_a.html";
};

function regularize() {
	if (retrieveSi(srcdoc, "StatAppMsdcUsrDetail", "srefIxMsdcVExpstate") == "regd") return;

	setSi(srcdoc, "StatAppMsdcUsrDetail", "srefIxMsdcVExpstate", "regd");

	// change content (container heights in refreshBD)
	doc.getElementById("Detail_side").src = "./PnlMsdcUsrDetail_bside.html";
	doc.getElementById("Detail_cont").src = "./PnlMsdcUsrDetail_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagMsdcUsrDetail", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	contcontdoc = contdoc.getElementById("Detail_cont").contentDocument;
	ftrdoc = contdoc.getElementById("Detail_ftr").contentDocument;

	// IP initBD --- BEGIN
	initCpt(contcontdoc, "CptPrs", retrieveTi(srcdoc, "TagMsdcUsrDetail", "CptPrs"));
	initCpt(contcontdoc, "CptSrf", retrieveTi(srcdoc, "TagMsdcUsrDetail", "CptSrf"));
	initCpt(contcontdoc, "CptUsg", retrieveTi(srcdoc, "TagMsdcUsrDetail", "CptUsg"));
	initCpt(contcontdoc, "CptSte", retrieveTi(srcdoc, "TagMsdcUsrDetail", "CptSte"));
	refreshPup(contcontdoc, srcdoc, "PupSte", "", "FeedFPupSte", retrieveCi(srcdoc, "ContIacMsdcUsrDetail", "numFPupSte"), retrieveSi(srcdoc, "StatShrMsdcUsrDetail", "PupSteActive"), false);
	initCpt(contcontdoc, "CptLcl", retrieveTi(srcdoc, "TagMsdcUsrDetail", "CptLcl"));
	refreshPup(contcontdoc, srcdoc, "PupLcl", "", "FeedFPupLcl", retrieveCi(srcdoc, "ContIacMsdcUsrDetail", "numFPupLcl"), retrieveSi(srcdoc, "StatShrMsdcUsrDetail", "PupLclActive"), false);
	initCpt(contcontdoc, "CptUlv", retrieveTi(srcdoc, "TagMsdcUsrDetail", "CptUlv"));
	refreshPup(contcontdoc, srcdoc, "PupUlv", "", "FeedFPupUlv", retrieveCi(srcdoc, "ContIacMsdcUsrDetail", "numFPupUlv"), retrieveSi(srcdoc, "StatShrMsdcUsrDetail", "PupUlvActive"), false);
	initCpt(contcontdoc, "CptPwd", retrieveTi(srcdoc, "TagMsdcUsrDetail", "CptPwd"));
	initCpt(contcontdoc, "CptFky", retrieveTi(srcdoc, "TagMsdcUsrDetail", "CptFky"));
	initCpt(contcontdoc, "CptCmt", retrieveTi(srcdoc, "TagMsdcUsrDetail", "CptCmt"));
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxMsdcVExpstate = retrieveSi(srcdoc, "StatAppMsdcUsrDetail", "srefIxMsdcVExpstate");

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
	var height = 342; // full cont height

	// IP refreshBD.vars --- BEGIN
	var TxtPrsActive = (retrieveSi(srcdoc, "StatShrMsdcUsrDetail", "TxtPrsActive") == "true");
	var ButPrsViewAvail = (retrieveSi(srcdoc, "StatShrMsdcUsrDetail", "ButPrsViewAvail") == "true");
	var ButPrsViewActive = (retrieveSi(srcdoc, "StatShrMsdcUsrDetail", "ButPrsViewActive") == "true");

	var TxtSrfActive = (retrieveSi(srcdoc, "StatShrMsdcUsrDetail", "TxtSrfActive") == "true");

	var TxtUsgActive = (retrieveSi(srcdoc, "StatShrMsdcUsrDetail", "TxtUsgActive") == "true");
	var ButUsgViewAvail = (retrieveSi(srcdoc, "StatShrMsdcUsrDetail", "ButUsgViewAvail") == "true");
	var ButUsgViewActive = (retrieveSi(srcdoc, "StatShrMsdcUsrDetail", "ButUsgViewActive") == "true");

	var PupSteActive = (retrieveSi(srcdoc, "StatShrMsdcUsrDetail", "PupSteActive") == "true");

	var PupLclActive = (retrieveSi(srcdoc, "StatShrMsdcUsrDetail", "PupLclActive") == "true");

	var PupUlvActive = (retrieveSi(srcdoc, "StatShrMsdcUsrDetail", "PupUlvActive") == "true");

	var TxfPwdActive = (retrieveSi(srcdoc, "StatShrMsdcUsrDetail", "TxfPwdActive") == "true");

	var TxfFkyActive = (retrieveSi(srcdoc, "StatShrMsdcUsrDetail", "TxfFkyActive") == "true");

	var TxfCmtActive = (retrieveSi(srcdoc, "StatShrMsdcUsrDetail", "TxfCmtActive") == "true");

	var ButSaveActive = (retrieveSi(srcdoc, "StatShrMsdcUsrDetail", "ButSaveActive") == "true");
	var mytd, first;
	// IP refreshBD.vars --- END

	// IP refreshBD --- BEGIN
	if ((ButPrsViewAvail == !contcontdoc.getElementById("ButPrsView"))) {
		mytd = contcontdoc.getElementById("rdynPrs");
		clearElem(mytd);

		first = true;

		if (ButPrsViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButPrsView", "icon/view"));
		};
	};

	refreshTxt(contcontdoc, "TxtPrs", retrieveCi(srcdoc, "ContInfMsdcUsrDetail", "TxtPrs"));

	if (ButPrsViewAvail) refreshButicon(contcontdoc, "ButPrsView", "icon/view", ButPrsViewActive, false);

	refreshTxt(contcontdoc, "TxtSrf", retrieveCi(srcdoc, "ContInfMsdcUsrDetail", "TxtSrf"));

	if ((ButUsgViewAvail == !contcontdoc.getElementById("ButUsgView"))) {
		mytd = contcontdoc.getElementById("rdynUsg");
		clearElem(mytd);

		first = true;

		if (ButUsgViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButUsgView", "icon/view"));
		};
	};

	refreshTxt(contcontdoc, "TxtUsg", retrieveCi(srcdoc, "ContInfMsdcUsrDetail", "TxtUsg"));

	if (ButUsgViewAvail) refreshButicon(contcontdoc, "ButUsgView", "icon/view", ButUsgViewActive, false);

	contcontdoc.getElementById("PupSte").value = retrieveCi(srcdoc, "ContIacMsdcUsrDetail", "numFPupSte");

	contcontdoc.getElementById("PupLcl").value = retrieveCi(srcdoc, "ContIacMsdcUsrDetail", "numFPupLcl");

	contcontdoc.getElementById("PupUlv").value = retrieveCi(srcdoc, "ContIacMsdcUsrDetail", "numFPupUlv");

	refreshTxf(contcontdoc, "TxfPwd", "s", retrieveCi(srcdoc, "ContIacMsdcUsrDetail", "TxfPwd"), TxfPwdActive, false, true);

	refreshTxft(contcontdoc, "TxfFky", retrieveCi(srcdoc, "ContIacMsdcUsrDetail", "TxfFky"), TxfFkyActive, false, true);

	refreshTxft(contcontdoc, "TxfCmt", retrieveCi(srcdoc, "ContIacMsdcUsrDetail", "TxfCmt"), TxfCmtActive, false, true);

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
	var srefIxMsdcVExpstate = retrieveSi(srcdoc, "StatAppMsdcUsrDetail", "srefIxMsdcVExpstate");

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
	var str = serializeDpchAppDo(srcdoc, "DpchAppMsdcUsrDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButCrdopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppMsdcUsrDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);
};

function handlePupChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "pup" + size + "mod");
	setCi(srcdoc, "ContIacMsdcUsrDetail", "numF" + ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppMsdcUsrDetailData", scrJref, "ContIacMsdcUsrDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleTxfKey(_doc, ctlsref, size, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	if (evt.keyCode == 13) {
		setCi(srcdoc, "ContIacMsdcUsrDetail", ctlsref, elem.value);

		var str = serializeDpchAppData(srcdoc, "DpchAppMsdcUsrDetailData", scrJref, "ContIacMsdcUsrDetail");
		sendReq(str, doc, handleDpchAppDataDoReply);

		return false;
	};

	return true;
};

function handleTxfChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	setCi(srcdoc, "ContIacMsdcUsrDetail", ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppMsdcUsrDetailData", scrJref, "ContIacMsdcUsrDetail");
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

	setCi(srcdoc, "ContIacMsdcUsrDetail", ctlsref, elem.value.replace(/\n/g, ";"));

	var str = serializeDpchAppData(srcdoc, "DpchAppMsdcUsrDetailData", scrJref, "ContIacMsdcUsrDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngMsdcUsrDetailData", "ContIacMsdcUsrDetail", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngMsdcUsrDetailData", "ContInfMsdcUsrDetail", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngMsdcUsrDetailData", "FeedFPupLcl", srcdoc)) mask.push("feedFPupLcl");
	if (updateSrcblock(dom, "DpchEngMsdcUsrDetailData", "FeedFPupSte", srcdoc)) mask.push("feedFPupSte");
	if (updateSrcblock(dom, "DpchEngMsdcUsrDetailData", "FeedFPupUlv", srcdoc)) mask.push("feedFPupUlv");
	if (updateSrcblock(dom, "DpchEngMsdcUsrDetailData", "StatAppMsdcUsrDetail", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngMsdcUsrDetailData", "StatShrMsdcUsrDetail", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngMsdcUsrDetailData", "TagMsdcUsrDetail", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngMsdcUsrDetailData") {
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
			if (blk.nodeName == "DpchEngMsdcUsrDetailData") {
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

			} else if (blk.nodeName == "DpchEngMsdcUsrDetailData") {
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

