/**
  * \file PnlMsdcScfActu.js
  * web client functionality for panel PnlMsdcScfActu
  * \author Alexander Wirthmueller
  * \date created: 12 Sep 2018
  * \date modified: 12 Sep 2018
  */

// IP cust --- INSERT

// --- expand state management
function minimize() {
	if (retrieveSi(srcdoc, "StatAppMsdcScfActu", "srefIxMsdcVExpstate") == "mind") return;

	setSi(srcdoc, "StatAppMsdcScfActu", "srefIxMsdcVExpstate", "mind");

	// change container heights
	getCrdwnd().changeHeight("Actu", 30);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Actu_side").setAttribute("height", "30");
	doc.getElementById("Actu_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Actu_side").src = "./PnlMsdcScfActu_aside.html";
	doc.getElementById("Actu_cont").src = "./PnlMsdcScfActu_a.html";
};

function regularize() {
	if (retrieveSi(srcdoc, "StatAppMsdcScfActu", "srefIxMsdcVExpstate") == "regd") return;

	setSi(srcdoc, "StatAppMsdcScfActu", "srefIxMsdcVExpstate", "regd");

	// change content (container heights in refreshBD)
	doc.getElementById("Actu_side").src = "./PnlMsdcScfActu_bside.html";
	doc.getElementById("Actu_cont").src = "./PnlMsdcScfActu_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Actu_side").contentDocument;
	contdoc = doc.getElementById("Actu_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagMsdcScfActu", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("Actu_side").contentDocument;
	contdoc = doc.getElementById("Actu_cont").contentDocument;
	hdrdoc = contdoc.getElementById("Actu_hdr").contentDocument;
	contcontdoc = contdoc.getElementById("Actu_cont").contentDocument;

	// IP initBD --- BEGIN
	initCpt(hdrdoc, "Cpt", retrieveTi(srcdoc, "TagMsdcScfActu", "Cpt"));
	initCpt(contcontdoc, "HdgSrv", retrieveTi(srcdoc, "TagMsdcScfActu", "HdgSrv"));
	initCpt(contcontdoc, "CptStm", retrieveTi(srcdoc, "TagMsdcScfActu", "CptStm"));
	initCpt(contcontdoc, "CptStx", retrieveTi(srcdoc, "TagMsdcScfActu", "CptStx"));
	initCpt(contcontdoc, "CptSpm", retrieveTi(srcdoc, "TagMsdcScfActu", "CptSpm"));
	initCpt(contcontdoc, "CptSpx", retrieveTi(srcdoc, "TagMsdcScfActu", "CptSpx"));
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxMsdcVExpstate = retrieveSi(srcdoc, "StatAppMsdcScfActu", "srefIxMsdcVExpstate");

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
	var height = 135; // full cont height

	// IP refreshBD.vars --- BEGIN

	// IP refreshBD.vars --- END

	// IP refreshBD --- BEGIN
	refreshButicon(hdrdoc, "ButMaster", "icon/master", true, retrieveCi(srcdoc, "ContInfMsdcScfActu", "ButMasterOn") == "true");

	refreshSld(contcontdoc, "SldStm", true, false, parseFloat(retrieveSi(srcdoc, "StatShrMsdcScfActu", "SldStmMin")), parseFloat(retrieveSi(srcdoc, "StatShrMsdcScfActu", "SldStmMax")), parseFloat(retrieveCi(srcdoc, "ContIacMsdcScfActu", "SldStm")), true, false);

	refreshSld(contcontdoc, "SldStx", true, false, parseFloat(retrieveSi(srcdoc, "StatShrMsdcScfActu", "SldStxMin")), parseFloat(retrieveSi(srcdoc, "StatShrMsdcScfActu", "SldStxMax")), parseFloat(retrieveCi(srcdoc, "ContIacMsdcScfActu", "SldStx")), true, false);

	refreshSld(contcontdoc, "SldSpm", true, false, parseFloat(retrieveSi(srcdoc, "StatShrMsdcScfActu", "SldSpmMin")), parseFloat(retrieveSi(srcdoc, "StatShrMsdcScfActu", "SldSpmMax")), parseFloat(retrieveCi(srcdoc, "ContIacMsdcScfActu", "SldSpm")), true, false);

	refreshSld(contcontdoc, "SldSpx", true, false, parseFloat(retrieveSi(srcdoc, "StatShrMsdcScfActu", "SldSpxMin")), parseFloat(retrieveSi(srcdoc, "StatShrMsdcScfActu", "SldSpxMax")), parseFloat(retrieveCi(srcdoc, "ContIacMsdcScfActu", "SldSpx")), true, false);

	// IP refreshBD --- END

	getCrdwnd().changeHeight("Actu", height+31);
	doc.getElementById("tdSide").setAttribute("height", "" + (height+31));
	doc.getElementById("Actu_side").setAttribute("height", "" + (height+31));
	doc.getElementById("Actu_cont").setAttribute("height", "" + (height+31));
	sidedoc.getElementById("tdFlex").setAttribute("height", "" + (height+31-30));
	contdoc.getElementById("tdCont").setAttribute("height", "" + height);
	contdoc.getElementById("Actu_cont").setAttribute("height", "" + height);
};

function refresh() {
	var srefIxMsdcVExpstate = retrieveSi(srcdoc, "StatAppMsdcScfActu", "srefIxMsdcVExpstate");

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
	srcdoc = doc.getElementById("Actu_src").contentDocument;

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
	var str = serializeDpchAppDo(srcdoc, "DpchAppMsdcScfActuDo", scrJref, ctlsref + "Click");
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

	if (shr) oldVal = parseFloat(retrieveCi(srcdoc, "ContIacMsdcScfActu", ctlsref));
	else oldVal = parseFloat(_doc.getElementById(ctlsref + "Val").value);
	min = parseFloat(retrieveSi(srcdoc, "StatShrMsdcScfActu", ctlsref + "Min"));
	max = parseFloat(retrieveSi(srcdoc, "StatShrMsdcScfActu", ctlsref + "Max"));

	if (_rast) rast = parseFloat(retrieveSi(srcdoc, "StatShrMsdcScfActu", ctlsref + "Rast"));

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
		setCi(srcdoc, "ContIacMsdcScfActu", ctlsref, "" + val);

		var str = serializeDpchAppData(srcdoc, "DpchAppMsdcScfActuData", scrJref, "ContIacMsdcScfActu");
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

	if (shr) oldVal = parseFloat(retrieveCi(srcdoc, "ContIacMsdcScfActu", ctlsref));
	else oldVal = parseFloat(_doc.getElementById(ctlsref + "Val").value);
	min = parseFloat(retrieveSi(srcdoc, "StatShrMsdcScfActu", ctlsref + "Min"));
	max = parseFloat(retrieveSi(srcdoc, "StatShrMsdcScfActu", ctlsref + "Max"));

	if (_rast) rast = parseFloat(retrieveSi(srcdoc, "StatShrMsdcScfActu", ctlsref + "Rast"));

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
		setCi(srcdoc, "ContIacMsdcScfActu", ctlsref, "" + val);

		var str = serializeDpchAppData(srcdoc, "DpchAppMsdcScfActuData", scrJref, "ContIacMsdcScfActu");
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

	min = parseFloat(retrieveSi(srcdoc, "StatShrMsdcScfActu", ctlsref + "Min"));
	max = parseFloat(retrieveSi(srcdoc, "StatShrMsdcScfActu", ctlsref + "Max"));

	if (_rast) rast = parseFloat(retrieveSi(srcdoc, "StatShrMsdcScfActu", ctlsref + "Rast"));
	else rast = 0.0;

	pos = getSldPosFromEvtx(true, evt.clientX);

	if (log) val = getSldLogvalFromPos(min, max, rast, pos);
	else val = getSldValFromPos(min, max, rast, pos);

	setSldPos(_doc, ctlsref, true, pos);
	setSldVal(_doc, ctlsref, val, true, true);

	if (shr) setCi(srcdoc, "ContIacMsdcScfActu", ctlsref, "" + val);
	else window["handle" + ctlsref + "Change"](val);
};

function handleSldMup(_doc, ctlsref, shr) {
	_doc.getElementById("td" + ctlsref).onmousemove = null;
	_doc.getElementById("td" + ctlsref).onmouseup = null;

	if (shr) {
		var str = serializeDpchAppData(srcdoc, "DpchAppMsdcScfActuData", scrJref, "ContIacMsdcScfActu");
		sendReq(str, doc, handleDpchAppDataDoReply);
	};
};

function handleSldValKey(_doc, ctlsref, shr, log, _rast, evt) {
	var elem = _doc.getElementById(ctlsref + "Val");

	var pos, val;

	var min, max, rast;

	elem.setAttribute("class", "txfxsmod");

	if (evt.keyCode == 13) {
		min = parseFloat(retrieveSi(srcdoc, "StatShrMsdcScfActu", ctlsref + "Min"));
		max = parseFloat(retrieveSi(srcdoc, "StatShrMsdcScfActu", ctlsref + "Max"));

		if (_rast) rast = parseFloat(retrieveSi(srcdoc, "StatShrMsdcScfActu", ctlsref + "Rast"));
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
			setCi(srcdoc, "ContIacMsdcScfActu", ctlsref, "" + val);

			var str = serializeDpchAppData(srcdoc, "DpchAppMsdcScfActuData", scrJref, "ContIacMsdcScfActu");
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

	min = parseFloat(retrieveSi(srcdoc, "StatShrMsdcScfActu", ctlsref + "Min"));
	max = parseFloat(retrieveSi(srcdoc, "StatShrMsdcScfActu", ctlsref + "Max"));

	if (_rast) rast = parseFloat(retrieveSi(srcdoc, "StatShrMsdcScfActu", ctlsref + "Rast"));
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
		setCi(srcdoc, "ContIacMsdcScfActu", ctlsref, "" + val);

		var str = serializeDpchAppData(srcdoc, "DpchAppMsdcScfActuData", scrJref, "ContIacMsdcScfActu");
		sendReq(str, doc, handleDpchAppDataDoReply);

	} else {
	window["handle" + ctlsref + "Change"](val);
	};
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngMsdcScfActuData", "ContIacMsdcScfActu", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngMsdcScfActuData", "ContInfMsdcScfActu", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngMsdcScfActuData", "StatAppMsdcScfActu", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngMsdcScfActuData", "StatShrMsdcScfActu", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngMsdcScfActuData", "TagMsdcScfActu", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngMsdcScfActuData") {
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
			if (blk.nodeName == "DpchEngMsdcScfActuData") {
				mergeDpchEngData(dom);
				init();

				getCrdwnd().setInitdone("Actu");
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

			} else if (blk.nodeName == "DpchEngMsdcScfActuData") {
				mergeDpchEngData(dom);
				refresh();
			};
		};
	};
};

