/**
  * \file PnlMsdcScfSource.js
  * web client functionality for panel PnlMsdcScfSource
  * \author Alexander Wirthmueller
  * \date created: 4 Oct 2018
  * \date modified: 4 Oct 2018
  */

// IP cust --- INSERT

// --- expand state management
function minimize() {
	if (retrieveSi(srcdoc, "StatAppMsdcScfSource", "srefIxMsdcVExpstate") == "mind") return;

	setSi(srcdoc, "StatAppMsdcScfSource", "srefIxMsdcVExpstate", "mind");

	// change container heights
	getCrdwnd().changeHeight("Source", 30);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Source_side").setAttribute("height", "30");
	doc.getElementById("Source_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Source_side").src = "./PnlMsdcScfSource_aside.html";
	doc.getElementById("Source_cont").src = "./PnlMsdcScfSource_a.html";
};

function regularize() {
	if (retrieveSi(srcdoc, "StatAppMsdcScfSource", "srefIxMsdcVExpstate") == "regd") return;

	setSi(srcdoc, "StatAppMsdcScfSource", "srefIxMsdcVExpstate", "regd");

	// change content (container heights in refreshBD)
	doc.getElementById("Source_side").src = "./PnlMsdcScfSource_bside.html";
	doc.getElementById("Source_cont").src = "./PnlMsdcScfSource_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Source_side").contentDocument;
	contdoc = doc.getElementById("Source_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagMsdcScfSource", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("Source_side").contentDocument;
	contdoc = doc.getElementById("Source_cont").contentDocument;
	hdrdoc = contdoc.getElementById("Source_hdr").contentDocument;
	contcontdoc = contdoc.getElementById("Source_cont").contentDocument;

	// IP initBD --- BEGIN
	initCpt(hdrdoc, "Cpt", retrieveTi(srcdoc, "TagMsdcScfSource", "Cpt"));
	initCpt(contcontdoc, "HdgFpg", retrieveTi(srcdoc, "TagMsdcScfSource", "HdgFpg"));
	initCpt(contcontdoc, "CptFpp", retrieveTi(srcdoc, "TagMsdcScfSource", "CptFpp"));
	initCpt(contcontdoc, "CptFxa", retrieveTi(srcdoc, "TagMsdcScfSource", "CptFxa"));
	initCpt(contcontdoc, "CptFa0", retrieveTi(srcdoc, "TagMsdcScfSource", "CptFa0"));
	initCpt(contcontdoc, "CptFb0", retrieveTi(srcdoc, "TagMsdcScfSource", "CptFb0"));
	initCpt(contcontdoc, "CptFam", retrieveTi(srcdoc, "TagMsdcScfSource", "CptFam"));
	initCpt(contcontdoc, "CptFsa", retrieveTi(srcdoc, "TagMsdcScfSource", "CptFsa"));
	initCpt(contcontdoc, "CptFt0", retrieveTi(srcdoc, "TagMsdcScfSource", "CptFt0"));
	initCpt(contcontdoc, "CptFp0", retrieveTi(srcdoc, "TagMsdcScfSource", "CptFp0"));
	initCpt(contcontdoc, "CptTrp", retrieveTi(srcdoc, "TagMsdcScfSource", "CptTrp"));
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxMsdcVExpstate = retrieveSi(srcdoc, "StatAppMsdcScfSource", "srefIxMsdcVExpstate");

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
	var height = 267; // full cont height

	// IP refreshBD.vars --- BEGIN

	// IP refreshBD.vars --- END

	// IP refreshBD --- BEGIN
	refreshButicon(hdrdoc, "ButMaster", "icon/master", true, retrieveCi(srcdoc, "ContInfMsdcScfSource", "ButMasterOn") == "true");

	refreshTxf(contcontdoc, "TxfFpp", "", retrieveCi(srcdoc, "ContIacMsdcScfSource", "TxfFpp"), true, false, true);

	refreshSld(contcontdoc, "SldFxa", true, false, parseFloat(retrieveSi(srcdoc, "StatShrMsdcScfSource", "SldFxaMin")), parseFloat(retrieveSi(srcdoc, "StatShrMsdcScfSource", "SldFxaMax")), parseFloat(retrieveCi(srcdoc, "ContIacMsdcScfSource", "SldFxa")), true, false);

	refreshSld(contcontdoc, "SldFa0", true, false, parseFloat(retrieveSi(srcdoc, "StatShrMsdcScfSource", "SldFa0Min")), parseFloat(retrieveSi(srcdoc, "StatShrMsdcScfSource", "SldFa0Max")), parseFloat(retrieveCi(srcdoc, "ContIacMsdcScfSource", "SldFa0")), true, false);

	refreshSld(contcontdoc, "SldFb0", true, false, parseFloat(retrieveSi(srcdoc, "StatShrMsdcScfSource", "SldFb0Min")), parseFloat(retrieveSi(srcdoc, "StatShrMsdcScfSource", "SldFb0Max")), parseFloat(retrieveCi(srcdoc, "ContIacMsdcScfSource", "SldFb0")), true, false);

	refreshUpd(contcontdoc, "UpdFam", parseInt(retrieveSi(srcdoc, "StatShrMsdcScfSource", "UpdFamMin")), parseInt(retrieveSi(srcdoc, "StatShrMsdcScfSource", "UpdFamMax")), parseInt(retrieveCi(srcdoc, "ContIacMsdcScfSource", "UpdFam")), true, false);

	refreshSld(contcontdoc, "SldFsa", true, false, parseFloat(retrieveSi(srcdoc, "StatShrMsdcScfSource", "SldFsaMin")), parseFloat(retrieveSi(srcdoc, "StatShrMsdcScfSource", "SldFsaMax")), parseFloat(retrieveCi(srcdoc, "ContIacMsdcScfSource", "SldFsa")), true, false);

	refreshSld(contcontdoc, "SldFt0", true, false, parseFloat(retrieveSi(srcdoc, "StatShrMsdcScfSource", "SldFt0Min")), parseFloat(retrieveSi(srcdoc, "StatShrMsdcScfSource", "SldFt0Max")), parseFloat(retrieveCi(srcdoc, "ContIacMsdcScfSource", "SldFt0")), true, false);

	refreshSld(contcontdoc, "SldFp0", true, false, parseFloat(retrieveSi(srcdoc, "StatShrMsdcScfSource", "SldFp0Min")), parseFloat(retrieveSi(srcdoc, "StatShrMsdcScfSource", "SldFp0Max")), parseFloat(retrieveCi(srcdoc, "ContIacMsdcScfSource", "SldFp0")), true, false);

	refreshSld(contcontdoc, "SldTrp", true, false, parseFloat(retrieveSi(srcdoc, "StatShrMsdcScfSource", "SldTrpMin")), parseFloat(retrieveSi(srcdoc, "StatShrMsdcScfSource", "SldTrpMax")), parseFloat(retrieveCi(srcdoc, "ContIacMsdcScfSource", "SldTrp")), true, false);

	// IP refreshBD --- END

	getCrdwnd().changeHeight("Source", height+31);
	doc.getElementById("tdSide").setAttribute("height", "" + (height+31));
	doc.getElementById("Source_side").setAttribute("height", "" + (height+31));
	doc.getElementById("Source_cont").setAttribute("height", "" + (height+31));
	sidedoc.getElementById("tdFlex").setAttribute("height", "" + (height+31-30));
	contdoc.getElementById("tdCont").setAttribute("height", "" + height);
	contdoc.getElementById("Source_cont").setAttribute("height", "" + height);
};

function refresh() {
	var srefIxMsdcVExpstate = retrieveSi(srcdoc, "StatAppMsdcScfSource", "srefIxMsdcVExpstate");

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
	srcdoc = doc.getElementById("Source_src").contentDocument;

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
	var str = serializeDpchAppDo(srcdoc, "DpchAppMsdcScfSourceDo", scrJref, ctlsref + "Click");
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

	if (shr) oldVal = parseFloat(retrieveCi(srcdoc, "ContIacMsdcScfSource", ctlsref));
	else oldVal = parseFloat(_doc.getElementById(ctlsref + "Val").value);
	min = parseFloat(retrieveSi(srcdoc, "StatShrMsdcScfSource", ctlsref + "Min"));
	max = parseFloat(retrieveSi(srcdoc, "StatShrMsdcScfSource", ctlsref + "Max"));

	if (_rast) rast = parseFloat(retrieveSi(srcdoc, "StatShrMsdcScfSource", ctlsref + "Rast"));

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
		setCi(srcdoc, "ContIacMsdcScfSource", ctlsref, "" + val);

		var str = serializeDpchAppData(srcdoc, "DpchAppMsdcScfSourceData", scrJref, "ContIacMsdcScfSource");
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

	if (shr) oldVal = parseFloat(retrieveCi(srcdoc, "ContIacMsdcScfSource", ctlsref));
	else oldVal = parseFloat(_doc.getElementById(ctlsref + "Val").value);
	min = parseFloat(retrieveSi(srcdoc, "StatShrMsdcScfSource", ctlsref + "Min"));
	max = parseFloat(retrieveSi(srcdoc, "StatShrMsdcScfSource", ctlsref + "Max"));

	if (_rast) rast = parseFloat(retrieveSi(srcdoc, "StatShrMsdcScfSource", ctlsref + "Rast"));

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
		setCi(srcdoc, "ContIacMsdcScfSource", ctlsref, "" + val);

		var str = serializeDpchAppData(srcdoc, "DpchAppMsdcScfSourceData", scrJref, "ContIacMsdcScfSource");
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

	min = parseFloat(retrieveSi(srcdoc, "StatShrMsdcScfSource", ctlsref + "Min"));
	max = parseFloat(retrieveSi(srcdoc, "StatShrMsdcScfSource", ctlsref + "Max"));

	if (_rast) rast = parseFloat(retrieveSi(srcdoc, "StatShrMsdcScfSource", ctlsref + "Rast"));
	else rast = 0.0;

	pos = getSldPosFromEvtx(true, evt.clientX);

	if (log) val = getSldLogvalFromPos(min, max, rast, pos);
	else val = getSldValFromPos(min, max, rast, pos);

	setSldPos(_doc, ctlsref, true, pos);
	setSldVal(_doc, ctlsref, val, true, true);

	if (shr) setCi(srcdoc, "ContIacMsdcScfSource", ctlsref, "" + val);
	else window["handle" + ctlsref + "Change"](val);
};

function handleSldMup(_doc, ctlsref, shr) {
	_doc.getElementById("td" + ctlsref).onmousemove = null;
	_doc.getElementById("td" + ctlsref).onmouseup = null;

	if (shr) {
		var str = serializeDpchAppData(srcdoc, "DpchAppMsdcScfSourceData", scrJref, "ContIacMsdcScfSource");
		sendReq(str, doc, handleDpchAppDataDoReply);
	};
};

function handleSldValKey(_doc, ctlsref, shr, log, _rast, evt) {
	var elem = _doc.getElementById(ctlsref + "Val");

	var pos, val;

	var min, max, rast;

	elem.setAttribute("class", "txfxsmod");

	if (evt.keyCode == 13) {
		min = parseFloat(retrieveSi(srcdoc, "StatShrMsdcScfSource", ctlsref + "Min"));
		max = parseFloat(retrieveSi(srcdoc, "StatShrMsdcScfSource", ctlsref + "Max"));

		if (_rast) rast = parseFloat(retrieveSi(srcdoc, "StatShrMsdcScfSource", ctlsref + "Rast"));
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
			setCi(srcdoc, "ContIacMsdcScfSource", ctlsref, "" + val);

			var str = serializeDpchAppData(srcdoc, "DpchAppMsdcScfSourceData", scrJref, "ContIacMsdcScfSource");
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

	min = parseFloat(retrieveSi(srcdoc, "StatShrMsdcScfSource", ctlsref + "Min"));
	max = parseFloat(retrieveSi(srcdoc, "StatShrMsdcScfSource", ctlsref + "Max"));

	if (_rast) rast = parseFloat(retrieveSi(srcdoc, "StatShrMsdcScfSource", ctlsref + "Rast"));
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
		setCi(srcdoc, "ContIacMsdcScfSource", ctlsref, "" + val);

		var str = serializeDpchAppData(srcdoc, "DpchAppMsdcScfSourceData", scrJref, "ContIacMsdcScfSource");
		sendReq(str, doc, handleDpchAppDataDoReply);

	} else {
	window["handle" + ctlsref + "Change"](val);
	};
};

function handleTxfKey(_doc, ctlsref, size, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	if (evt.keyCode == 13) {
		setCi(srcdoc, "ContIacMsdcScfSource", ctlsref, elem.value);

		var str = serializeDpchAppData(srcdoc, "DpchAppMsdcScfSourceData", scrJref, "ContIacMsdcScfSource");
		sendReq(str, doc, handleDpchAppDataDoReply);

		return false;
	};

	return true;
};

function handleTxfChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	setCi(srcdoc, "ContIacMsdcScfSource", ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppMsdcScfSourceData", scrJref, "ContIacMsdcScfSource");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleUpdValKey(_doc, ctlsref, shr, evt) {
	var elem = _doc.getElementById(ctlsref + "Val");

	var val;

	var min, max;

	elem.setAttribute("class", "txfsmod");

	if (evt.keyCode == 13) {
		min = parseInt(retrieveSi(srcdoc, "StatShrMsdcScfSource", ctlsref + "Min"));
		max = parseInt(retrieveSi(srcdoc, "StatShrMsdcScfSource", ctlsref + "Max"));

		val = parseInt(elem.value);
		if (isNaN(val)) val = 0;
		if (val < min) val = min;
		if (val > max) val = max;

		refreshUpd(_doc, ctlsref, min, max, val, true, true);

		if (shr) {
			setCi(srcdoc, "ContIacMsdcScfSource", ctlsref, "" + val);

			var str = serializeDpchAppData(srcdoc, "DpchAppMsdcScfSourceData", scrJref, "ContIacMsdcScfSource");
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

	min = parseInt(retrieveSi(srcdoc, "StatShrMsdcScfSource", ctlsref + "Min"));
	max = parseInt(retrieveSi(srcdoc, "StatShrMsdcScfSource", ctlsref + "Max"));

	val = parseInt(elem.value);
	if (isNaN(val)) val = 0;
	if (val < min) val = min;
	if (val > max) val = max;

	refreshUpd(_doc, ctlsref, min, max, val, true, true);

	if (shr) {
		setCi(srcdoc, "ContIacMsdcScfSource", ctlsref, "" + val);

			var str = serializeDpchAppData(srcdoc, "DpchAppMsdcScfSourceData", scrJref, "ContIacMsdcScfSource");
		setCi(srcdoc, "ContIacMsdcScfSource", ctlsref, "" + val);
		sendReq(str, doc, handleDpchAppDataDoReply);

	} else {
		window["handle" + ctlsref + "Change"](val);
	};
};

function handleUpdUpClick(_doc, ctlsref, shr) {
	var oldVal, val;

	var min, max;

	if (shr) oldVal = parseInt(retrieveCi(srcdoc, "ContIacMsdcScfSource", ctlsref));
	else oldVal = parseInt(_doc.getElementById(ctlsref + "Val").value);
	min = parseInt(retrieveSi(srcdoc, "StatShrMsdcScfSource", ctlsref + "Min"));
	max = parseInt(retrieveSi(srcdoc, "StatShrMsdcScfSource", ctlsref + "Max"));

	val = oldVal + 1;
	if (val < min) val = min;
	if (val > max) val = max;

	refreshUpd(_doc, ctlsref, min, max, val, true, true);

	if (shr) {
		setCi(srcdoc, "ContIacMsdcScfSource", ctlsref, "" + val);

		var str = serializeDpchAppData(srcdoc, "DpchAppMsdcScfSourceData", scrJref, "ContIacMsdcScfSource");
		sendReq(str, doc, handleDpchAppDataDoReply);

	} else {
		window["handle" + ctlsref + "Change"](val);
	};
};

function handleUpdDownClick(_doc, ctlsref, shr) {
	var oldVal, val;

	var min, max;

	if (shr) oldVal = parseInt(retrieveCi(srcdoc, "ContIacMsdcScfSource", ctlsref));
	else oldVal = parseInt(_doc.getElementById(ctlsref + "Val").value);
	min = parseInt(retrieveSi(srcdoc, "StatShrMsdcScfSource", ctlsref + "Min"));
	max = parseInt(retrieveSi(srcdoc, "StatShrMsdcScfSource", ctlsref + "Max"));

	val = oldVal - 1;
	if (val < min) val = min;
	if (val > max) val = max;

	refreshUpd(_doc, ctlsref, min, max, val, true, true);

	if (shr) {
		setCi(srcdoc, "ContIacMsdcScfSource", ctlsref, "" + val);

		var str = serializeDpchAppData(srcdoc, "DpchAppMsdcScfSourceData", scrJref, "ContIacMsdcScfSource");
		sendReq(str, doc, handleDpchAppDataDoReply);

	} else {
		window["handle" + ctlsref + "Change"](val);
	};
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngMsdcScfSourceData", "ContIacMsdcScfSource", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngMsdcScfSourceData", "ContInfMsdcScfSource", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngMsdcScfSourceData", "StatAppMsdcScfSource", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngMsdcScfSourceData", "StatShrMsdcScfSource", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngMsdcScfSourceData", "TagMsdcScfSource", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngMsdcScfSourceData") {
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
			if (blk.nodeName == "DpchEngMsdcScfSourceData") {
				mergeDpchEngData(dom);
				init();

				getCrdwnd().setInitdone("Source");
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

			} else if (blk.nodeName == "DpchEngMsdcScfSourceData") {
				mergeDpchEngData(dom);
				refresh();
			};
		};
	};
};

