/**
  * \file PnlMsdcLivTrack.js
  * web client functionality for panel PnlMsdcLivTrack
  * \author Alexander Wirthmueller
  * \date created: 18 Dec 2018
  * \date modified: 18 Dec 2018
  */

// IP cust --- INSERT

// --- expand state management
function minimize() {
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
	initCpt(contcontdoc, "HdgAls", retrieveTi(srcdoc, "TagMsdcLivTrack", "HdgAls"));
	initCpt(contcontdoc, "CptAmf", retrieveTi(srcdoc, "TagMsdcLivTrack", "CptAmf"));
	initCpt(contcontdoc, "CptApr", retrieveTi(srcdoc, "TagMsdcLivTrack", "CptApr"));
	initCpt(contcontdoc, "HdgVsl", retrieveTi(srcdoc, "TagMsdcLivTrack", "HdgVsl"));
	initCpt(contcontdoc, "CptVid", retrieveTi(srcdoc, "TagMsdcLivTrack", "CptVid"));
	initCpt(contcontdoc, "CptVpx", retrieveTi(srcdoc, "TagMsdcLivTrack", "CptVpx"));
	initCpt(contcontdoc, "CptVpy", retrieveTi(srcdoc, "TagMsdcLivTrack", "CptVpy"));
	initCpt(contcontdoc, "HdgWsr", retrieveTi(srcdoc, "TagMsdcLivTrack", "HdgWsr"));
	initCpt(contcontdoc, "CptWid", retrieveTi(srcdoc, "TagMsdcLivTrack", "CptWid"));
	initCpt(contcontdoc, "CptWpx", retrieveTi(srcdoc, "TagMsdcLivTrack", "CptWpx"));
	initCpt(contcontdoc, "CptWpy", retrieveTi(srcdoc, "TagMsdcLivTrack", "CptWpy"));
	initCpt(contcontdoc, "CptDis", retrieveTi(srcdoc, "TagMsdcLivTrack", "CptDis"));
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxMsdcVExpstate = retrieveSi(srcdoc, "StatShrMsdcLivTrack", "srefIxMsdcVExpstate");

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
	if (!contcontdoc) return;

	var height = 331; // full cont height

	// IP refreshBD.vars --- BEGIN

	var PupAmfActive = (retrieveSi(srcdoc, "StatShrMsdcLivTrack", "PupAmfActive") == "true");

	var UpdAprActive = (retrieveSi(srcdoc, "StatShrMsdcLivTrack", "UpdAprActive") == "true");

	var ChkVidActive = (retrieveSi(srcdoc, "StatShrMsdcLivTrack", "ChkVidActive") == "true");

	var ChkWidActive = (retrieveSi(srcdoc, "StatShrMsdcLivTrack", "ChkWidActive") == "true");

	// IP refreshBD.vars --- END

	// IP refreshBD --- BEGIN
	refreshButicon(hdrdoc, "ButMaster", "icon/master", true, retrieveCi(srcdoc, "ContInfMsdcLivTrack", "ButMasterOn") == "true");

	refreshPup(contcontdoc, srcdoc, "PupAmf", "", "FeedFPupAmf", retrieveCi(srcdoc, "ContIacMsdcLivTrack", "numFPupAmf"), PupAmfActive, false);

	refreshUpd(contcontdoc, "UpdApr", parseInt(retrieveSi(srcdoc, "StatShrMsdcLivTrack", "UpdAprMin")), parseInt(retrieveSi(srcdoc, "StatShrMsdcLivTrack", "UpdAprMax")), parseInt(retrieveCi(srcdoc, "ContIacMsdcLivTrack", "UpdApr")), UpdAprActive, false);

	refreshChk(contcontdoc, "ChkVid", (retrieveCi(srcdoc, "ContIacMsdcLivTrack", "ChkVid") == "true"), ChkVidActive);

	refreshTxt(contcontdoc, "TxtVpx", retrieveCi(srcdoc, "ContInfMsdcLivTrack", "TxtVpx"));

	refreshTxt(contcontdoc, "TxtVpy", retrieveCi(srcdoc, "ContInfMsdcLivTrack", "TxtVpy"));

	refreshChk(contcontdoc, "ChkWid", (retrieveCi(srcdoc, "ContIacMsdcLivTrack", "ChkWid") == "true"), ChkWidActive);

	refreshTxt(contcontdoc, "TxtWpx", retrieveCi(srcdoc, "ContInfMsdcLivTrack", "TxtWpx"));

	refreshTxt(contcontdoc, "TxtWpy", retrieveCi(srcdoc, "ContInfMsdcLivTrack", "TxtWpy"));

	refreshTxt(contcontdoc, "TxtDis", retrieveCi(srcdoc, "ContInfMsdcLivTrack", "TxtDis"));

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
	var srefIxMsdcVExpstate = retrieveSi(srcdoc, "StatShrMsdcLivTrack", "srefIxMsdcVExpstate");

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

// --- generalized event handlers for app controls

// --- generalized event handlers for shared controls

function handleButClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppMsdcLivTrackDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleChkChange(_doc, ctlsref) {
	var elem = _doc.getElementById(ctlsref);
	var checked;

	elem.setAttribute("class", "chkmod");

	if (elem.checked == true) checked = "true"; else checked = "false";
	setCi(srcdoc, "ContIacMsdcLivTrack", ctlsref, checked);

	var str = serializeDpchAppData(srcdoc, "DpchAppMsdcLivTrackData", scrJref, "ContIacMsdcLivTrack");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handlePupChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "pup" + size + "mod");
	setCi(srcdoc, "ContIacMsdcLivTrack", "numF" + ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppMsdcLivTrackData", scrJref, "ContIacMsdcLivTrack");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleUpdValKey(_doc, ctlsref, shr, evt) {
	var elem = _doc.getElementById(ctlsref + "Val");

	var val;

	var min, max;

	elem.setAttribute("class", "txfsmod");

	if (evt.keyCode == 13) {
		min = parseInt(retrieveSi(srcdoc, "StatShrMsdcLivTrack", ctlsref + "Min"));
		max = parseInt(retrieveSi(srcdoc, "StatShrMsdcLivTrack", ctlsref + "Max"));

		val = parseInt(elem.value);
		if (isNaN(val)) val = 0;
		if (val < min) val = min;
		if (val > max) val = max;

		refreshUpd(_doc, ctlsref, min, max, val, true, true);

		if (shr) {
			setCi(srcdoc, "ContIacMsdcLivTrack", ctlsref, "" + val);

			var str = serializeDpchAppData(srcdoc, "DpchAppMsdcLivTrackData", scrJref, "ContIacMsdcLivTrack");
			sendReq(str, doc, handleDpchAppDataDoReply);

		} else {
			window["handle" + ctlsref + "Change"](val);
		};

		return false;
	};

	return true;
};

function handleUpdValChange(_doc, ctlsref, shr) {
	var elem = _doc.getElementById(ctlsref + "Val");

	var val;

	var min, max;

	elem.setAttribute("class", "txfsmod");

	min = parseInt(retrieveSi(srcdoc, "StatShrMsdcLivTrack", ctlsref + "Min"));
	max = parseInt(retrieveSi(srcdoc, "StatShrMsdcLivTrack", ctlsref + "Max"));

	val = parseInt(elem.value);
	if (isNaN(val)) val = 0;
	if (val < min) val = min;
	if (val > max) val = max;

	refreshUpd(_doc, ctlsref, min, max, val, true, true);

	if (shr) {
		setCi(srcdoc, "ContIacMsdcLivTrack", ctlsref, "" + val);

			var str = serializeDpchAppData(srcdoc, "DpchAppMsdcLivTrackData", scrJref, "ContIacMsdcLivTrack");
		setCi(srcdoc, "ContIacMsdcLivTrack", ctlsref, "" + val);
		sendReq(str, doc, handleDpchAppDataDoReply);

	} else {
		window["handle" + ctlsref + "Change"](val);
	};
};

function handleUpdUpClick(_doc, ctlsref, shr) {
	var oldVal, val;

	var min, max;

	if (shr) oldVal = parseInt(retrieveCi(srcdoc, "ContIacMsdcLivTrack", ctlsref));
	else oldVal = parseInt(_doc.getElementById(ctlsref + "Val").value);
	min = parseInt(retrieveSi(srcdoc, "StatShrMsdcLivTrack", ctlsref + "Min"));
	max = parseInt(retrieveSi(srcdoc, "StatShrMsdcLivTrack", ctlsref + "Max"));

	val = oldVal + 1;
	if (val < min) val = min;
	if (val > max) val = max;

	refreshUpd(_doc, ctlsref, min, max, val, true, true);

	if (shr) {
		setCi(srcdoc, "ContIacMsdcLivTrack", ctlsref, "" + val);

		var str = serializeDpchAppData(srcdoc, "DpchAppMsdcLivTrackData", scrJref, "ContIacMsdcLivTrack");
		sendReq(str, doc, handleDpchAppDataDoReply);

	} else {
		window["handle" + ctlsref + "Change"](val);
	};
};

function handleUpdDownClick(_doc, ctlsref, shr) {
	var oldVal, val;

	var min, max;

	if (shr) oldVal = parseInt(retrieveCi(srcdoc, "ContIacMsdcLivTrack", ctlsref));
	else oldVal = parseInt(_doc.getElementById(ctlsref + "Val").value);
	min = parseInt(retrieveSi(srcdoc, "StatShrMsdcLivTrack", ctlsref + "Min"));
	max = parseInt(retrieveSi(srcdoc, "StatShrMsdcLivTrack", ctlsref + "Max"));

	val = oldVal - 1;
	if (val < min) val = min;
	if (val > max) val = max;

	refreshUpd(_doc, ctlsref, min, max, val, true, true);

	if (shr) {
		setCi(srcdoc, "ContIacMsdcLivTrack", ctlsref, "" + val);

		var str = serializeDpchAppData(srcdoc, "DpchAppMsdcLivTrackData", scrJref, "ContIacMsdcLivTrack");
		sendReq(str, doc, handleDpchAppDataDoReply);

	} else {
		window["handle" + ctlsref + "Change"](val);
	};
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngMsdcLivTrackData", "ContIacMsdcLivTrack", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngMsdcLivTrackData", "ContInfMsdcLivTrack", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngMsdcLivTrackData", "FeedFPupAmf", srcdoc)) mask.push("feedFPupAmf");
	if (updateSrcblock(dom, "DpchEngMsdcLivTrackData", "StatShrMsdcLivTrack", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngMsdcLivTrackData", "TagMsdcLivTrack", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngMsdcLivTrackData") {
		var oldSrefIxMsdcVExpstate = retrieveSi(srcdoc, "StatShrMsdcLivTrack", "srefIxMsdcVExpstate");

		var mask = mergeDpchEngData(dom);

		if (mask.indexOf("statshr") != -1) {
			var srefIxMsdcVExpstate = retrieveSi(srcdoc, "StatShrMsdcLivTrack", "srefIxMsdcVExpstate");

			if (srefIxMsdcVExpstate != oldSrefIxMsdcVExpstate) {
				if (srefIxMsdcVExpstate == "mind") minimize();
				else if (srefIxMsdcVExpstate == "regd") regularize();
			} else {
				refresh();
			};

		} else {
			refresh();
		};
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
				var oldSrefIxMsdcVExpstate = retrieveSi(srcdoc, "StatShrMsdcLivTrack", "srefIxMsdcVExpstate");

				var mask = mergeDpchEngData(dom);

				if (mask.indexOf("statshr") != -1) {
					var srefIxMsdcVExpstate = retrieveSi(srcdoc, "StatShrMsdcLivTrack", "srefIxMsdcVExpstate");

					if (srefIxMsdcVExpstate != oldSrefIxMsdcVExpstate) {
						if (srefIxMsdcVExpstate == "mind") minimize();
						else if (srefIxMsdcVExpstate == "regd") regularize();
					} else {
						refresh();
					};

				} else {
					refresh();
				};
			};
		};
	};
};

