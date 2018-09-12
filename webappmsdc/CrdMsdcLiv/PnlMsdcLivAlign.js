/**
  * \file PnlMsdcLivAlign.js
  * web client functionality for panel PnlMsdcLivAlign
  * \author Alexander Wirthmueller
  * \date created: 12 Sep 2018
  * \date modified: 12 Sep 2018
  */

// IP cust --- INSERT

// --- expand state management
function minimize() {
	if (retrieveSi(srcdoc, "StatAppMsdcLivAlign", "srefIxMsdcVExpstate") == "mind") return;

	setSi(srcdoc, "StatAppMsdcLivAlign", "srefIxMsdcVExpstate", "mind");

	// change container heights
	getCrdwnd().changeHeight("Align", 30);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Align_side").setAttribute("height", "30");
	doc.getElementById("Align_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Align_side").src = "./PnlMsdcLivAlign_aside.html";
	doc.getElementById("Align_cont").src = "./PnlMsdcLivAlign_a.html";
};

function regularize() {
	if (retrieveSi(srcdoc, "StatAppMsdcLivAlign", "srefIxMsdcVExpstate") == "regd") return;

	setSi(srcdoc, "StatAppMsdcLivAlign", "srefIxMsdcVExpstate", "regd");

	// change content (container heights in refreshBD)
	doc.getElementById("Align_side").src = "./PnlMsdcLivAlign_bside.html";
	doc.getElementById("Align_cont").src = "./PnlMsdcLivAlign_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Align_side").contentDocument;
	contdoc = doc.getElementById("Align_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagMsdcLivAlign", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("Align_side").contentDocument;
	contdoc = doc.getElementById("Align_cont").contentDocument;
	hdrdoc = contdoc.getElementById("Align_hdr").contentDocument;
	contcontdoc = contdoc.getElementById("Align_cont").contentDocument;

	// IP initBD --- BEGIN
	initCpt(hdrdoc, "Cpt", retrieveTi(srcdoc, "TagMsdcLivAlign", "Cpt"));
	initCpt(contcontdoc, "CptAph", retrieveTi(srcdoc, "TagMsdcLivAlign", "CptAph"));
	initCpt(contcontdoc, "CptBta", retrieveTi(srcdoc, "TagMsdcLivAlign", "CptBta"));
	initCpt(contcontdoc, "CptThe", retrieveTi(srcdoc, "TagMsdcLivAlign", "CptThe"));
	initCpt(contcontdoc, "CptPhi", retrieveTi(srcdoc, "TagMsdcLivAlign", "CptPhi"));
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxMsdcVExpstate = retrieveSi(srcdoc, "StatAppMsdcLivAlign", "srefIxMsdcVExpstate");

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
	var height = 117; // full cont height

	// IP refreshBD.vars --- BEGIN

	var SldTheActive = (retrieveSi(srcdoc, "StatShrMsdcLivAlign", "SldTheActive") == "true");

	var SldPhiActive = (retrieveSi(srcdoc, "StatShrMsdcLivAlign", "SldPhiActive") == "true");

	// IP refreshBD.vars --- END

	// IP refreshBD --- BEGIN
	refreshButicon(hdrdoc, "ButMaster", "icon/master", true, retrieveCi(srcdoc, "ContInfMsdcLivAlign", "ButMasterOn") == "true");
	refreshTxt(contcontdoc, "TxtAph", retrieveCi(srcdoc, "ContInfMsdcLivAlign", "TxtAph"));

	refreshTxt(contcontdoc, "TxtBta", retrieveCi(srcdoc, "ContInfMsdcLivAlign", "TxtBta"));

	refreshSld(contcontdoc, "SldThe", true, false, parseFloat(retrieveSi(srcdoc, "StatShrMsdcLivAlign", "SldTheMin")), parseFloat(retrieveSi(srcdoc, "StatShrMsdcLivAlign", "SldTheMax")), parseFloat(retrieveCi(srcdoc, "ContIacMsdcLivAlign", "SldThe")), SldTheActive, false);

	refreshSld(contcontdoc, "SldPhi", true, false, parseFloat(retrieveSi(srcdoc, "StatShrMsdcLivAlign", "SldPhiMin")), parseFloat(retrieveSi(srcdoc, "StatShrMsdcLivAlign", "SldPhiMax")), parseFloat(retrieveCi(srcdoc, "ContIacMsdcLivAlign", "SldPhi")), SldPhiActive, false);

	// IP refreshBD --- END

	getCrdwnd().changeHeight("Align", height+31);
	doc.getElementById("tdSide").setAttribute("height", "" + (height+31));
	doc.getElementById("Align_side").setAttribute("height", "" + (height+31));
	doc.getElementById("Align_cont").setAttribute("height", "" + (height+31));
	sidedoc.getElementById("tdFlex").setAttribute("height", "" + (height+31-30));
	contdoc.getElementById("tdCont").setAttribute("height", "" + height);
	contdoc.getElementById("Align_cont").setAttribute("height", "" + height);
};

function refresh() {
	var srefIxMsdcVExpstate = retrieveSi(srcdoc, "StatAppMsdcLivAlign", "srefIxMsdcVExpstate");

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
	srcdoc = doc.getElementById("Align_src").contentDocument;

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
	var str = serializeDpchAppDo(srcdoc, "DpchAppMsdcLivAlignDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleSldJpleftMov(_doc, ctlsref) {
	if (_doc.getElementById("td" + ctlsref).onmousemove == null) {
		_doc.getElementById(ctlsref + "Jpleftl").setAttribute("class", "sldlhlt");
	};
};

function handleSldJpleftMou(_doc, ctlsref) {
	_doc.getElementById(ctlsref + "Jpleftl").setAttribute("class", "sldl");
};

function handleSldJpleftClick(_doc, ctlsref, shr, log, _rast, evt) {
	var pos, oldVal, val;

	var min, max, rast;

	if (shr) oldVal = parseFloat(retrieveCi(srcdoc, "ContIacMsdcLivAlign", ctlsref));
	else oldVal = parseFloat(_doc.getElementById(ctlsref + "Val").value);
	min = parseFloat(retrieveSi(srcdoc, "StatShrMsdcLivAlign", ctlsref + "Min"));
	max = parseFloat(retrieveSi(srcdoc, "StatShrMsdcLivAlign", ctlsref + "Max"));

	if (_rast) rast = parseFloat(retrieveSi(srcdoc, "StatShrMsdcLivAlign", ctlsref + "Rast"));

	if (_rast) {
		if (log) val = oldVal / rast;
		else val = oldVal - rast;

		if (val < min) val = min;
		if (val > max) val = max;

	} else {
		pos = getSldPosFromEvtx(true, evt.clientX);
		val = getSldValFromPos(min, max, rast, pos);
	};

	pos = getSldPosFromVal(min, max, val);

	setSldPos(_doc, ctlsref, true, pos);
	setSldVal(_doc, ctlsref, val, true, true);

	if (shr) {
		setCi(srcdoc, "ContIacMsdcLivAlign", ctlsref, "" + val);

		var str = serializeDpchAppData(srcdoc, "DpchAppMsdcLivAlignData", scrJref, "ContIacMsdcLivAlign");
		sendReq(str, doc, handleDpchAppDataDoReply);

	} else {
		window["handle" + ctlsref + "Change"](val);
	};
};

function handleSldJprightMov(_doc, ctlsref) {
	if (_doc.getElementById("td" + ctlsref).onmousemove == null) {
		_doc.getElementById(ctlsref + "Jprightl").setAttribute("class", "sldlhlt");
	};
};

function handleSldJprightMou(_doc, ctlsref) {
	_doc.getElementById(ctlsref + "Jprightl").setAttribute("class", "sldl");
};

function handleSldJprightClick(_doc, ctlsref, shr, log, _rast, evt) {
	var pos, oldVal, val;

	var min, max, rast;

	if (shr) oldVal = parseFloat(retrieveCi(srcdoc, "ContIacMsdcLivAlign", ctlsref));
	else oldVal = parseFloat(_doc.getElementById(ctlsref + "Val").value);
	min = parseFloat(retrieveSi(srcdoc, "StatShrMsdcLivAlign", ctlsref + "Min"));
	max = parseFloat(retrieveSi(srcdoc, "StatShrMsdcLivAlign", ctlsref + "Max"));

	if (_rast) rast = parseFloat(retrieveSi(srcdoc, "StatShrMsdcLivAlign", ctlsref + "Rast"));

	if (_rast) {
		if (log) val = oldVal * rast;
		else val = oldVal + rast;

		if (val < min) val = min;
		if (val > max) val = max;

	} else {
		pos = getSldPosFromEvtx(true, evt.clientX);
		val = getSldValFromPos(min, max, rast, pos);
	};

	pos = getSldPosFromVal(min, max, val);

	setSldPos(_doc, ctlsref, true, pos);
	setSldVal(_doc, ctlsref, val, true, true);

	if (shr) {
		setCi(srcdoc, "ContIacMsdcLivAlign", ctlsref, "" + val);

		var str = serializeDpchAppData(srcdoc, "DpchAppMsdcLivAlignData", scrJref, "ContIacMsdcLivAlign");
		sendReq(str, doc, handleDpchAppDataDoReply);

	} else {
		window["handle" + ctlsref + "Change"](val);
	};
};

function handleSldMov(_doc, ctlsref) {
	_doc.getElementById(ctlsref + "Bar").setAttribute("class", "sldlhlt");
};

function handleSldMou(_doc, ctlsref) {
	if (_doc.getElementById("td" + ctlsref).onmousemove == null) {
		_doc.getElementById(ctlsref + "Bar").setAttribute("class", "sldl");
	};
};

function handleSldMdn(_doc, ctlsref) {
	_doc.getElementById("td" + ctlsref).setAttribute("onmousemove", "handle" + ctlsref + "Move(event)");
	_doc.getElementById("td" + ctlsref).setAttribute("onmouseup", "handle" + ctlsref + "Mup(event)");
};

function handleSldMove(_doc, ctlsref, shr, log, _rast, evt) {
	var pos, val;

	var min, max, rast;

	min = parseFloat(retrieveSi(srcdoc, "StatShrMsdcLivAlign", ctlsref + "Min"));
	max = parseFloat(retrieveSi(srcdoc, "StatShrMsdcLivAlign", ctlsref + "Max"));

	if (_rast) rast = parseFloat(retrieveSi(srcdoc, "StatShrMsdcLivAlign", ctlsref + "Rast"));
	else rast = 0.0;

	pos = getSldPosFromEvtx(true, evt.clientX);

	if (log) val = getSldLogvalFromPos(min, max, rast, pos);
	else val = getSldValFromPos(min, max, rast, pos);

	setSldPos(_doc, ctlsref, true, pos);
	setSldVal(_doc, ctlsref, val, true, true);

	if (shr) setCi(srcdoc, "ContIacMsdcLivAlign", ctlsref, "" + val);
	else window["handle" + ctlsref + "Change"](val);
};

function handleSldMup(_doc, ctlsref, shr) {
	_doc.getElementById("td" + ctlsref).onmousemove = null;
	_doc.getElementById("td" + ctlsref).onmouseup = null;

	if (shr) {
		var str = serializeDpchAppData(srcdoc, "DpchAppMsdcLivAlignData", scrJref, "ContIacMsdcLivAlign");
		sendReq(str, doc, handleDpchAppDataDoReply);
	};
};

function handleSldValKey(_doc, ctlsref, shr, log, _rast, evt) {
	var elem = _doc.getElementById(ctlsref + "Val");

	var pos, val;

	var min, max, rast;

	elem.setAttribute("class", "txfxsmod");

	if (evt.keyCode == 13) {
		min = parseFloat(retrieveSi(srcdoc, "StatShrMsdcLivAlign", ctlsref + "Min"));
		max = parseFloat(retrieveSi(srcdoc, "StatShrMsdcLivAlign", ctlsref + "Max"));

		if (_rast) rast = parseFloat(retrieveSi(srcdoc, "StatShrMsdcLivAlign", ctlsref + "Rast"));
		else rast = 0.0;

		val = parseFloat(elem.value);
		if (isNaN(val)) val = 0.0;

		if (log) {
			val = alignSldLogval(min, max, rast, val);
			pos = getSldPosFromLogval(min, max, val);
		} else {
			val = alignSldVal(min, max, rast, val);
			pos = getSldPosFromVal(min, max, val);
		};

		setSldPos(_doc, ctlsref, true, pos);
		setSldVal(_doc, ctlsref, val, true, true);

		if (shr) {
			setCi(srcdoc, "ContIacMsdcLivAlign", ctlsref, "" + val);

			var str = serializeDpchAppData(srcdoc, "DpchAppMsdcLivAlignData", scrJref, "ContIacMsdcLivAlign");
			sendReq(str, doc, handleDpchAppDataDoReply);

		} else {
			window["handle" + ctlsref + "Change"](val);
		};

		return false;
	};

	return true;
};

function handleSldValChange(_doc, ctlsref, shr, log, _rast) {
	var elem = _doc.getElementById(ctlsref + "Val");

	var pos, val;

	var min, max, rast;

	elem.setAttribute("class", "txfxsmod");

	min = parseFloat(retrieveSi(srcdoc, "StatShrMsdcLivAlign", ctlsref + "Min"));
	max = parseFloat(retrieveSi(srcdoc, "StatShrMsdcLivAlign", ctlsref + "Max"));

	if (_rast) rast = parseFloat(retrieveSi(srcdoc, "StatShrMsdcLivAlign", ctlsref + "Rast"));
	else rast = 0.0;

	val = parseFloat(elem.value);
	if (isNaN(val)) val = 0.0;

	if (log) {
		val = alignSldLogval(min, max, rast, val);
		pos = getSldPosFromLogval(min, max, val);
	} else {
		val = alignSldVal(min, max, rast, val);
		pos = getSldPosFromVal(min, max, val);
	};

	setSldPos(_doc, ctlsref, true, pos);
	setSldVal(_doc, ctlsref, val, true, true);

	if (shr) {
		setCi(srcdoc, "ContIacMsdcLivAlign", ctlsref, "" + val);

		var str = serializeDpchAppData(srcdoc, "DpchAppMsdcLivAlignData", scrJref, "ContIacMsdcLivAlign");
		sendReq(str, doc, handleDpchAppDataDoReply);

	} else {
	window["handle" + ctlsref + "Change"](val);
	};
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngMsdcLivAlignData", "ContIacMsdcLivAlign", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngMsdcLivAlignData", "ContInfMsdcLivAlign", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngMsdcLivAlignData", "StatAppMsdcLivAlign", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngMsdcLivAlignData", "StatShrMsdcLivAlign", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngMsdcLivAlignData", "TagMsdcLivAlign", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngMsdcLivAlignData") {
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
			if (blk.nodeName == "DpchEngMsdcLivAlignData") {
				mergeDpchEngData(dom);
				init();

				getCrdwnd().setInitdone("Align");
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

			} else if (blk.nodeName == "DpchEngMsdcLivAlignData") {
				mergeDpchEngData(dom);
				refresh();
			};
		};
	};
};

