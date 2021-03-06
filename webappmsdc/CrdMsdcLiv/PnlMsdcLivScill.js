/**
  * \file PnlMsdcLivScill.js
  * web client functionality for panel PnlMsdcLivScill
  * \author Alexander Wirthmueller
  * \date created: 18 Dec 2018
  * \date modified: 18 Dec 2018
  */

// IP cust --- INSERT

// --- expand state management
function minimize() {
	// change container heights
	getCrdwnd().changeHeight("Scill", 30);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Scill_side").setAttribute("height", "30");
	doc.getElementById("Scill_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Scill_side").src = "./PnlMsdcLivScill_aside.html";
	doc.getElementById("Scill_cont").src = "./PnlMsdcLivScill_a.html";
};

function regularize() {
	// change content (container heights in refreshBD)
	doc.getElementById("Scill_side").src = "./PnlMsdcLivScill_bside.html";
	doc.getElementById("Scill_cont").src = "./PnlMsdcLivScill_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Scill_side").contentDocument;
	contdoc = doc.getElementById("Scill_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagMsdcLivScill", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("Scill_side").contentDocument;
	contdoc = doc.getElementById("Scill_cont").contentDocument;
	hdrdoc = contdoc.getElementById("Scill_hdr").contentDocument;
	contcontdoc = contdoc.getElementById("Scill_cont").contentDocument;

	// IP initBD --- BEGIN
	initCpt(hdrdoc, "Cpt", retrieveTi(srcdoc, "TagMsdcLivScill", "Cpt"));
	initCpt(contcontdoc, "CptFld", retrieveTi(srcdoc, "TagMsdcLivScill", "CptFld"));
	initCpt(contcontdoc, "CptSpt", retrieveTi(srcdoc, "TagMsdcLivScill", "CptSpt"));
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxMsdcVExpstate = retrieveSi(srcdoc, "StatShrMsdcLivScill", "srefIxMsdcVExpstate");

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

	var height = 60; // full cont height

	// IP refreshBD.vars --- BEGIN
	var SldFldActive = (retrieveSi(srcdoc, "StatShrMsdcLivScill", "SldFldActive") == "true");

	var SldSptActive = (retrieveSi(srcdoc, "StatShrMsdcLivScill", "SldSptActive") == "true");

	// IP refreshBD.vars --- END

	// IP refreshBD --- BEGIN
	refreshButicon(hdrdoc, "ButMaster", "icon/master", true, retrieveCi(srcdoc, "ContInfMsdcLivScill", "ButMasterOn") == "true");
	refreshSld(contcontdoc, "SldFld", true, false, parseFloat(retrieveSi(srcdoc, "StatShrMsdcLivScill", "SldFldMin")), parseFloat(retrieveSi(srcdoc, "StatShrMsdcLivScill", "SldFldMax")), parseFloat(retrieveCi(srcdoc, "ContIacMsdcLivScill", "SldFld")), SldFldActive, false);

	refreshSld(contcontdoc, "SldSpt", true, false, parseFloat(retrieveSi(srcdoc, "StatShrMsdcLivScill", "SldSptMin")), parseFloat(retrieveSi(srcdoc, "StatShrMsdcLivScill", "SldSptMax")), parseFloat(retrieveCi(srcdoc, "ContIacMsdcLivScill", "SldSpt")), SldSptActive, false);

	// IP refreshBD --- END

	getCrdwnd().changeHeight("Scill", height+31);
	doc.getElementById("tdSide").setAttribute("height", "" + (height+31));
	doc.getElementById("Scill_side").setAttribute("height", "" + (height+31));
	doc.getElementById("Scill_cont").setAttribute("height", "" + (height+31));
	sidedoc.getElementById("tdFlex").setAttribute("height", "" + (height+31-30));
	contdoc.getElementById("tdCont").setAttribute("height", "" + height);
	contdoc.getElementById("Scill_cont").setAttribute("height", "" + height);
};

function refresh() {
	var srefIxMsdcVExpstate = retrieveSi(srcdoc, "StatShrMsdcLivScill", "srefIxMsdcVExpstate");

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
	srcdoc = doc.getElementById("Scill_src").contentDocument;

	var str = serializeDpchApp("DpchAppMsdcInit", scrJref);
	sendReq(str, doc, handleDpchAppInitReply, true);
};

// --- specific event handlers for app controls

// --- generalized event handlers for app controls

// --- generalized event handlers for shared controls

function handleButClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppMsdcLivScillDo", scrJref, ctlsref + "Click");
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

	if (shr) oldVal = parseFloat(retrieveCi(srcdoc, "ContIacMsdcLivScill", ctlsref));
	else oldVal = parseFloat(_doc.getElementById(ctlsref + "Val").value);
	min = parseFloat(retrieveSi(srcdoc, "StatShrMsdcLivScill", ctlsref + "Min"));
	max = parseFloat(retrieveSi(srcdoc, "StatShrMsdcLivScill", ctlsref + "Max"));

	if (_rast) rast = parseFloat(retrieveSi(srcdoc, "StatShrMsdcLivScill", ctlsref + "Rast"));

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
		setCi(srcdoc, "ContIacMsdcLivScill", ctlsref, "" + val);

		var str = serializeDpchAppData(srcdoc, "DpchAppMsdcLivScillData", scrJref, "ContIacMsdcLivScill");
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

	if (shr) oldVal = parseFloat(retrieveCi(srcdoc, "ContIacMsdcLivScill", ctlsref));
	else oldVal = parseFloat(_doc.getElementById(ctlsref + "Val").value);
	min = parseFloat(retrieveSi(srcdoc, "StatShrMsdcLivScill", ctlsref + "Min"));
	max = parseFloat(retrieveSi(srcdoc, "StatShrMsdcLivScill", ctlsref + "Max"));

	if (_rast) rast = parseFloat(retrieveSi(srcdoc, "StatShrMsdcLivScill", ctlsref + "Rast"));

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
		setCi(srcdoc, "ContIacMsdcLivScill", ctlsref, "" + val);

		var str = serializeDpchAppData(srcdoc, "DpchAppMsdcLivScillData", scrJref, "ContIacMsdcLivScill");
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

	min = parseFloat(retrieveSi(srcdoc, "StatShrMsdcLivScill", ctlsref + "Min"));
	max = parseFloat(retrieveSi(srcdoc, "StatShrMsdcLivScill", ctlsref + "Max"));

	if (_rast) rast = parseFloat(retrieveSi(srcdoc, "StatShrMsdcLivScill", ctlsref + "Rast"));
	else rast = 0.0;

	pos = getSldPosFromEvtx(true, evt.clientX);

	if (log) val = getSldLogvalFromPos(min, max, rast, pos);
	else val = getSldValFromPos(min, max, rast, pos);

	setSldPos(_doc, ctlsref, true, pos);
	setSldVal(_doc, ctlsref, val, true, true);

	if (shr) setCi(srcdoc, "ContIacMsdcLivScill", ctlsref, "" + val);
	else window["handle" + ctlsref + "Change"](val);
};

function handleSldMup(_doc, ctlsref, shr) {
	_doc.getElementById("td" + ctlsref).onmousemove = null;
	_doc.getElementById("td" + ctlsref).onmouseup = null;

	if (shr) {
		var str = serializeDpchAppData(srcdoc, "DpchAppMsdcLivScillData", scrJref, "ContIacMsdcLivScill");
		sendReq(str, doc, handleDpchAppDataDoReply);
	};
};

function handleSldValKey(_doc, ctlsref, shr, log, _rast, evt) {
	var elem = _doc.getElementById(ctlsref + "Val");

	var pos, val;

	var min, max, rast;

	elem.setAttribute("class", "txfxsmod");

	if (evt.keyCode == 13) {
		min = parseFloat(retrieveSi(srcdoc, "StatShrMsdcLivScill", ctlsref + "Min"));
		max = parseFloat(retrieveSi(srcdoc, "StatShrMsdcLivScill", ctlsref + "Max"));

		if (_rast) rast = parseFloat(retrieveSi(srcdoc, "StatShrMsdcLivScill", ctlsref + "Rast"));
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
			setCi(srcdoc, "ContIacMsdcLivScill", ctlsref, "" + val);

			var str = serializeDpchAppData(srcdoc, "DpchAppMsdcLivScillData", scrJref, "ContIacMsdcLivScill");
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

	min = parseFloat(retrieveSi(srcdoc, "StatShrMsdcLivScill", ctlsref + "Min"));
	max = parseFloat(retrieveSi(srcdoc, "StatShrMsdcLivScill", ctlsref + "Max"));

	if (_rast) rast = parseFloat(retrieveSi(srcdoc, "StatShrMsdcLivScill", ctlsref + "Rast"));
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
		setCi(srcdoc, "ContIacMsdcLivScill", ctlsref, "" + val);

		var str = serializeDpchAppData(srcdoc, "DpchAppMsdcLivScillData", scrJref, "ContIacMsdcLivScill");
		sendReq(str, doc, handleDpchAppDataDoReply);

	} else {
	window["handle" + ctlsref + "Change"](val);
	};
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngMsdcLivScillData", "ContIacMsdcLivScill", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngMsdcLivScillData", "ContInfMsdcLivScill", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngMsdcLivScillData", "StatShrMsdcLivScill", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngMsdcLivScillData", "TagMsdcLivScill", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngMsdcLivScillData") {
		var oldSrefIxMsdcVExpstate = retrieveSi(srcdoc, "StatShrMsdcLivScill", "srefIxMsdcVExpstate");

		var mask = mergeDpchEngData(dom);

		if (mask.indexOf("statshr") != -1) {
			var srefIxMsdcVExpstate = retrieveSi(srcdoc, "StatShrMsdcLivScill", "srefIxMsdcVExpstate");

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
			if (blk.nodeName == "DpchEngMsdcLivScillData") {
				mergeDpchEngData(dom);
				init();

				getCrdwnd().setInitdone("Scill");
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

			} else if (blk.nodeName == "DpchEngMsdcLivScillData") {
				var oldSrefIxMsdcVExpstate = retrieveSi(srcdoc, "StatShrMsdcLivScill", "srefIxMsdcVExpstate");

				var mask = mergeDpchEngData(dom);

				if (mask.indexOf("statshr") != -1) {
					var srefIxMsdcVExpstate = retrieveSi(srcdoc, "StatShrMsdcLivScill", "srefIxMsdcVExpstate");

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

