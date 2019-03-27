/**
  * \file PnlMsdcLivVideo.js
  * web client functionality for panel PnlMsdcLivVideo
  * \author Alexander Wirthmueller
  * \date created: 18 Dec 2018
  * \date modified: 18 Dec 2018
  */

// IP cust --- IBEGIN
function refreshLive(mask) {
	if (!contcontdoc) return;

	var cvsctx = contcontdoc.getElementById("cvs").getContext("2d");

	var d = doc.imgdat.data;

	var w = 640;
	var h = 480;

	var mult = 1;
	var ix, ix2;

	var a, b, x;
///
	var min, max;
	var littleNotBig = !bigendian();
///

	if ( (mask.indexOf("red") != -1) && (mask.indexOf("green") != -1) && (mask.indexOf("blue") != -1) ) {
		mult = Math.round(Math.sqrt((w*h) / doc.red.length));

		if ( (mult*mult*doc.red.length) == (w*h) ) {
			for (var i=0;i<h/mult;i++) {
				for (var j=0;j<w/mult;j++) {
					ix = (i*w/mult)+j;
					ix2 = 4 * (i*mult*w + j*mult);

					d[ix2] = doc.red[ix];
					d[ix2+1] = doc.green[ix];
					d[ix2+2] = doc.blue[ix];
					d[ix2+3] = 255;
				};
			};

		} else mult = 1;

	} else if (mask.indexOf("gray") != -1) {
		// adjust with contrast/brightness
		//a = parseFloat(contcontdoc.getElementById("SldConVal").value);
		//if (isNaN(a)) a = 1.0;
		a = 1.0;
		if (a < 1.0) a = 0.0;
		if (a > 100.0) a = 100.0;
		a /= 256.0;

		//b = parseFloat(contcontdoc.getElementById("SldBriVal").value);
		//if (isNaN(b)) b = 0.0;
		b = 1.0;
		if (b < 0.0) b = 0.0;
		if (b > 1.0) b = 1.0;
		b = 65535.0 * (1.0-b);

		var dv = new DataView(doc.gray.buffer);

		mult = 3;
		
		for (var i=0;i<120;i++) {
			for (var j=0;j<160;j++) {
				ix = 2 * (i*160+j);
				ix2 = 4 * (j*mult*640 + mult*(120-i-1));

				x = a*(1.0*dv.getUint16(ix, littleNotBig)-b);
				if (x < 0.0) x = 0.0;
				if (x > 255.0) x = 255.0;

				d[ix2] = x;
				d[ix2+1] = d[ix2];
				d[ix2+2] = d[ix2];
				d[ix2+3] = 255;
			}
		}

/*
		mult = Math.round(Math.sqrt((w*h) / doc.gray.length));

		if ( (mult*mult*doc.gray.length) == (w*h) ) {
			for (var i=0;i<h/mult;i++) {
				for (var j=0;j<w/mult;j++) {
					ix = 2 * ((i*w/mult)+j);
					ix2 = 4 * (i*mult*w + j*mult);

					x = a*(1.0*dv.getUint16(ix, littleNotBig)-b);
					if (x < 0.0) x = 0.0;
					if (x > 255.0) x = 255.0;

					d[ix2] = x;
					d[ix2+1] = d[ix2];
					d[ix2+2] = d[ix2];
					d[ix2+3] = 255;
				};
			};

		} else mult = 1;
*/
	};

	if (mult > 1) {
		// scale (enlarge) image
		for (var i=0;i<h/mult;i++) {
			for (var j=0;j<w/mult;j++) {
				ix = 4 * (i*mult*w + j*mult);

				for (var k=0;k<mult;k++) {
					for (var l=0;l<mult;l++) {
						if ((k != 0) || (l != 0)) {
							ix2 = 4 * ((i*mult+k)*w + j*mult+l);

							d[ix2] = d[ix];
							d[ix2+1] = d[ix+1];
							d[ix2+2] = d[ix+2];
							d[ix2+3] = d[ix+3];
						};
					};
				};
			};
		};
	};

	cvsctx.putImageData(doc.imgdat, 25, 0);
};
// IP cust --- IEND

// --- expand state management
function minimize() {
	// change container heights
	getCrdwnd().changeHeight("Video", 30);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Video_side").setAttribute("height", "30");
	doc.getElementById("Video_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Video_side").src = "./PnlMsdcLivVideo_aside.html";
	doc.getElementById("Video_cont").src = "./PnlMsdcLivVideo_a.html";
};

function regularize() {
	// change content (container heights in refreshBD)
	doc.getElementById("Video_side").src = "./PnlMsdcLivVideo_bside.html";
	doc.getElementById("Video_cont").src = "./PnlMsdcLivVideo_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Video_side").contentDocument;
	contdoc = doc.getElementById("Video_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagMsdcLivVideo", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("Video_side").contentDocument;
	contdoc = doc.getElementById("Video_cont").contentDocument;
	hdrdoc = contdoc.getElementById("Video_hdr").contentDocument;
	contcontdoc = contdoc.getElementById("Video_cont").contentDocument;

	// IP initBD --- RBEGIN
	initCpt(hdrdoc, "Cpt", retrieveTi(srcdoc, "TagMsdcLivVideo", "Cpt"));
	initCpt(contcontdoc, "CptSrc", retrieveTi(srcdoc, "TagMsdcLivVideo", "CptSrc"));
	refreshPup(contcontdoc, srcdoc, "PupSrc", "", "FeedFPupSrc", retrieveCi(srcdoc, "ContIacMsdcLivVideo", "numFPupSrc"), true, false);
	initCpt(contcontdoc, "CptRes", retrieveTi(srcdoc, "TagMsdcLivVideo", "CptRes"));
	initCpt(contcontdoc, "CptGrs", retrieveTi(srcdoc, "TagMsdcLivVideo", "CptGrs"));
	initCpt(contcontdoc, "CptExt", retrieveTi(srcdoc, "TagMsdcLivVideo", "CptExt"));
	initCpt(contcontdoc, "CptFcs", retrieveTi(srcdoc, "TagMsdcLivVideo", "CptFcs"));
	initCpt(contcontdoc, "CptTcp", retrieveTi(srcdoc, "TagMsdcLivVideo", "CptTcp"));

	doc.imgdat = contcontdoc.getElementById("cvs").getContext("2d").createImageData(640, 480);
	// IP initBD --- REND

	refreshBD(bNotD);
};

function init() {
	var srefIxMsdcVExpstate = retrieveSi(srcdoc, "StatShrMsdcLivVideo", "srefIxMsdcVExpstate");

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

	var height = 761; // full cont height

	// IP refreshBD.vars --- RBEGIN
	height = 681; // full cont height

	var PupResAvail = (retrieveSi(srcdoc, "StatShrMsdcLivVideo", "PupResAvail") == "true");

	var ChkGrsAvail = (retrieveSi(srcdoc, "StatShrMsdcLivVideo", "ChkGrsAvail") == "true");

	var ButPlayActive = (retrieveSi(srcdoc, "StatShrMsdcLivVideo", "ButPlayActive") == "true");
	var ButStopActive = (retrieveSi(srcdoc, "StatShrMsdcLivVideo", "ButStopActive") == "true");

	var SldExtAvail = (retrieveSi(srcdoc, "StatShrMsdcLivVideo", "SldExtAvail") == "true");
	var SldExtActive = (retrieveSi(srcdoc, "StatShrMsdcLivVideo", "SldExtActive") == "true");

	var SldFcsAvail = (retrieveSi(srcdoc, "StatShrMsdcLivVideo", "SldFcsAvail") == "true");
	var SldFcsActive = (retrieveSi(srcdoc, "StatShrMsdcLivVideo", "SldFcsActive") == "true");

	var ChkTcpAvail = (retrieveSi(srcdoc, "StatShrMsdcLivVideo", "ChkTcpAvail") == "true");

	// IP refreshBD.vars --- REND

	// IP refreshBD --- BEGIN
	refreshButicon(hdrdoc, "ButMaster", "icon/master", true, retrieveCi(srcdoc, "ContInfMsdcLivVideo", "ButMasterOn") == "true");
	contcontdoc.getElementById("PupSrc").value = retrieveCi(srcdoc, "ContIacMsdcLivVideo", "numFPupSrc");

	height -= setCtlAvail(contcontdoc, "Res", PupResAvail, 25);
	if (PupResAvail) {
		refreshPup(contcontdoc, srcdoc, "PupRes", "", "FeedFPupRes", retrieveCi(srcdoc, "ContIacMsdcLivVideo", "numFPupRes"), true, false);

	};

	height -= setCtlAvail(contcontdoc, "Grs", ChkGrsAvail, 25);
	if (ChkGrsAvail) {
		refreshChk(contcontdoc, "ChkGrs", (retrieveCi(srcdoc, "ContIacMsdcLivVideo", "ChkGrs") == "true"), true);

	};

	refreshButicon(contcontdoc, "ButPlay", "iconmsdc/play", ButPlayActive, false);
	refreshButicon(contcontdoc, "ButStop", "iconmsdc/stop", ButStopActive, false);

	height -= setCtlAvail(contcontdoc, "Ext", SldExtAvail, 25);
	if (SldExtAvail) {
		refreshSld(contcontdoc, "SldExt", true, true, parseFloat(retrieveSi(srcdoc, "StatShrMsdcLivVideo", "SldExtMin")), parseFloat(retrieveSi(srcdoc, "StatShrMsdcLivVideo", "SldExtMax")), parseFloat(retrieveCi(srcdoc, "ContIacMsdcLivVideo", "SldExt")), SldExtActive, false);

	};

	height -= setCtlAvail(contcontdoc, "Fcs", SldFcsAvail, 25);
	if (SldFcsAvail) {
		refreshSld(contcontdoc, "SldFcs", true, false, parseFloat(retrieveSi(srcdoc, "StatShrMsdcLivVideo", "SldFcsMin")), parseFloat(retrieveSi(srcdoc, "StatShrMsdcLivVideo", "SldFcsMax")), parseFloat(retrieveCi(srcdoc, "ContIacMsdcLivVideo", "SldFcs")), SldFcsActive, false);

	};

	height -= setCtlAvail(contcontdoc, "Tcp", ChkTcpAvail, 25);
	if (ChkTcpAvail) {
		refreshChk(contcontdoc, "ChkTcp", (retrieveCi(srcdoc, "ContIacMsdcLivVideo", "ChkTcp") == "true"), true);

	};

	// IP refreshBD --- END

	getCrdwnd().changeHeight("Video", height+31);
	doc.getElementById("tdSide").setAttribute("height", "" + (height+31));
	doc.getElementById("Video_side").setAttribute("height", "" + (height+31));
	doc.getElementById("Video_cont").setAttribute("height", "" + (height+31));
	sidedoc.getElementById("tdFlex").setAttribute("height", "" + (height+31-30));
	contdoc.getElementById("tdCont").setAttribute("height", "" + height);
	contdoc.getElementById("Video_cont").setAttribute("height", "" + height);
};

function refresh() {
	var srefIxMsdcVExpstate = retrieveSi(srcdoc, "StatShrMsdcLivVideo", "srefIxMsdcVExpstate");

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
	srcdoc = doc.getElementById("Video_src").contentDocument;

	var str = serializeDpchApp("DpchAppMsdcInit", scrJref);
	sendReq(str, doc, handleDpchAppInitReply, true);
};

// --- specific event handlers for app controls

// --- generalized event handlers for app controls

// --- generalized event handlers for shared controls

function handleButClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppMsdcLivVideoDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleChkChange(_doc, ctlsref) {
	var elem = _doc.getElementById(ctlsref);
	var checked;

	elem.setAttribute("class", "chkmod");

	if (elem.checked == true) checked = "true"; else checked = "false";
	setCi(srcdoc, "ContIacMsdcLivVideo", ctlsref, checked);

	var str = serializeDpchAppData(srcdoc, "DpchAppMsdcLivVideoData", scrJref, "ContIacMsdcLivVideo");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleLstLoad(lstdoc, ctlsref, ncol, multsel) {
	if (multsel) {
		refreshLst(lstdoc, srcdoc, ncol, true, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppMsdcLivVideo", ctlsref + "NumFirstdisp")),
					parseUintvec(retrieveCi(srcdoc, "ContIacMsdcLivVideo", "numsF" + ctlsref)));
	} else {
		refreshLst(lstdoc, srcdoc, ncol, true, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppMsdcLivVideo", ctlsref + "NumFirstdisp")),
					[parseInt(retrieveCi(srcdoc, "ContIacMsdcLivVideo", "numF" + ctlsref))]);
	};
};

function handleLstSelect(ctlsref, multsel, num) {
	var found, oldNumFLst, numsFLst, oldNumsFLst;

	if (multsel) {
		oldNumsFLst = parseUintvec(retrieveCi(srcdoc, "ContIacMsdcLivVideo", "numsF" + ctlsref));

		found = false;

		for (var i=0;i<oldNumsFLst.length;i++) {
			if (oldNumsFLst[i] == num) {
				numsFLst = new Uint32Array(oldNumsFLst.length-1);

				for (var j=0;j<oldNumsFLst.length;j++)
					if (j < i) numsFLst[j] = oldNumsFLst[j];
					else if (j > i) numsFLst[j-1] = oldNumsFLst[j];

				found = true;
				break;
			};
		};

		if (!found) {
			numsFLst = new Uint32Array(oldNumsFLst.length+1);

			for (var i=0;i<oldNumsFLst.length;i++) numsFLst[i] = oldNumsFLst[i];
			numsFLst[oldNumsFLst.length] = num;
		};

		setCi(srcdoc, "ContIacMsdcLivVideo", "numsF" + ctlsref, encodeUintvec(numsFLst));

	} else {
		oldNumFLst = parseInt(retrieveCi(srcdoc, "ContIacMsdcLivVideo", "numF" + ctlsref));
		if (num == oldNumFLst) num = 0;

		setCi(srcdoc, "ContIacMsdcLivVideo", "numF" + ctlsref, num);
	};

	var str = serializeDpchAppData(srcdoc, "DpchAppMsdcLivVideoData", scrJref, "ContIacMsdcLivVideo");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function changeLstNumFirstdisp(lstdoc, ctlsref, ncol, multsel, numFirstdisp, dNumFirstdisp) {
	var oldNumFirstdisp = parseInt(retrieveSi(srcdoc, "StatAppMsdcLivVideo", ctlsref + "NumFirstdisp"));
	if (dNumFirstdisp != 0) numFirstdisp = oldNumFirstdisp + dNumFirstdisp;

	var cnt = getFeedSize(srcdoc, "FeedF" + ctlsref);

	if (numFirstdisp > (cnt-5+1)) numFirstdisp = cnt-5+1;
	if (numFirstdisp < 1) numFirstdisp = 1;

	if (numFirstdisp != oldNumFirstdisp) {
		setSi(srcdoc, "StatAppMsdcLivVideo", ctlsref + "NumFirstdisp", "" + numFirstdisp);

		if (multsel) refreshLst(lstdoc, srcdoc, ncol, true, multsel, "FeedF" + ctlsref, numFirstdisp, parseUintvec(retrieveCi(srcdoc, "ContIacMsdcLivVideo", "numsF" + ctlsref)));
		else refreshLst(lstdoc, srcdoc, ncol, true, multsel, "FeedF" + ctlsref, numFirstdisp, [parseInt(retrieveCi(srcdoc, "ContIacMsdcLivVideo", "numF" + ctlsref))]);
	};
};

function handlePupChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "pup" + size + "mod");
	setCi(srcdoc, "ContIacMsdcLivVideo", "numF" + ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppMsdcLivVideoData", scrJref, "ContIacMsdcLivVideo");
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

	if (shr) oldVal = parseFloat(retrieveCi(srcdoc, "ContIacMsdcLivVideo", ctlsref));
	else oldVal = parseFloat(_doc.getElementById(ctlsref + "Val").value);
	min = parseFloat(retrieveSi(srcdoc, "StatShrMsdcLivVideo", ctlsref + "Min"));
	max = parseFloat(retrieveSi(srcdoc, "StatShrMsdcLivVideo", ctlsref + "Max"));

	if (_rast) rast = parseFloat(retrieveSi(srcdoc, "StatShrMsdcLivVideo", ctlsref + "Rast"));

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
		setCi(srcdoc, "ContIacMsdcLivVideo", ctlsref, "" + val);

		var str = serializeDpchAppData(srcdoc, "DpchAppMsdcLivVideoData", scrJref, "ContIacMsdcLivVideo");
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

	if (shr) oldVal = parseFloat(retrieveCi(srcdoc, "ContIacMsdcLivVideo", ctlsref));
	else oldVal = parseFloat(_doc.getElementById(ctlsref + "Val").value);
	min = parseFloat(retrieveSi(srcdoc, "StatShrMsdcLivVideo", ctlsref + "Min"));
	max = parseFloat(retrieveSi(srcdoc, "StatShrMsdcLivVideo", ctlsref + "Max"));

	if (_rast) rast = parseFloat(retrieveSi(srcdoc, "StatShrMsdcLivVideo", ctlsref + "Rast"));

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
		setCi(srcdoc, "ContIacMsdcLivVideo", ctlsref, "" + val);

		var str = serializeDpchAppData(srcdoc, "DpchAppMsdcLivVideoData", scrJref, "ContIacMsdcLivVideo");
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

	min = parseFloat(retrieveSi(srcdoc, "StatShrMsdcLivVideo", ctlsref + "Min"));
	max = parseFloat(retrieveSi(srcdoc, "StatShrMsdcLivVideo", ctlsref + "Max"));

	if (_rast) rast = parseFloat(retrieveSi(srcdoc, "StatShrMsdcLivVideo", ctlsref + "Rast"));
	else rast = 0.0;

	pos = getSldPosFromEvtx(true, evt.clientX);

	if (log) val = getSldLogvalFromPos(min, max, rast, pos);
	else val = getSldValFromPos(min, max, rast, pos);

	setSldPos(_doc, ctlsref, true, pos);
	setSldVal(_doc, ctlsref, val, true, true);

	if (shr) setCi(srcdoc, "ContIacMsdcLivVideo", ctlsref, "" + val);
	else window["handle" + ctlsref + "Change"](val);
};

function handleSldMup(_doc, ctlsref, shr) {
	_doc.getElementById("td" + ctlsref).onmousemove = null;
	_doc.getElementById("td" + ctlsref).onmouseup = null;

	if (shr) {
		var str = serializeDpchAppData(srcdoc, "DpchAppMsdcLivVideoData", scrJref, "ContIacMsdcLivVideo");
		sendReq(str, doc, handleDpchAppDataDoReply);
	};
};

function handleSldValKey(_doc, ctlsref, shr, log, _rast, evt) {
	var elem = _doc.getElementById(ctlsref + "Val");

	var pos, val;

	var min, max, rast;

	elem.setAttribute("class", "txfxsmod");

	if (evt.keyCode == 13) {
		min = parseFloat(retrieveSi(srcdoc, "StatShrMsdcLivVideo", ctlsref + "Min"));
		max = parseFloat(retrieveSi(srcdoc, "StatShrMsdcLivVideo", ctlsref + "Max"));

		if (_rast) rast = parseFloat(retrieveSi(srcdoc, "StatShrMsdcLivVideo", ctlsref + "Rast"));
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
			setCi(srcdoc, "ContIacMsdcLivVideo", ctlsref, "" + val);

			var str = serializeDpchAppData(srcdoc, "DpchAppMsdcLivVideoData", scrJref, "ContIacMsdcLivVideo");
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

	min = parseFloat(retrieveSi(srcdoc, "StatShrMsdcLivVideo", ctlsref + "Min"));
	max = parseFloat(retrieveSi(srcdoc, "StatShrMsdcLivVideo", ctlsref + "Max"));

	if (_rast) rast = parseFloat(retrieveSi(srcdoc, "StatShrMsdcLivVideo", ctlsref + "Rast"));
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
		setCi(srcdoc, "ContIacMsdcLivVideo", ctlsref, "" + val);

		var str = serializeDpchAppData(srcdoc, "DpchAppMsdcLivVideoData", scrJref, "ContIacMsdcLivVideo");
		sendReq(str, doc, handleDpchAppDataDoReply);

	} else {
	window["handle" + ctlsref + "Change"](val);
	};
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngMsdcLivVideoData", "ContIacMsdcLivVideo", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngMsdcLivVideoData", "ContInfMsdcLivVideo", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngMsdcLivVideoData", "FeedFLstFst", srcdoc)) mask.push("feedFLstFst");
	if (updateSrcblock(dom, "DpchEngMsdcLivVideoData", "FeedFPupRes", srcdoc)) mask.push("feedFPupRes");
	if (updateSrcblock(dom, "DpchEngMsdcLivVideoData", "FeedFPupSrc", srcdoc)) mask.push("feedFPupSrc");
	if (updateSrcblock(dom, "DpchEngMsdcLivVideoData", "StatAppMsdcLivVideo", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngMsdcLivVideoData", "StatShrMsdcLivVideo", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngMsdcLivVideoData", "TagMsdcLivVideo", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngMsdcLivVideoData") {
		var oldSrefIxMsdcVExpstate = retrieveSi(srcdoc, "StatShrMsdcLivVideo", "srefIxMsdcVExpstate");

		var mask = mergeDpchEngData(dom);

		if (mask.indexOf("statshr") != -1) {
			var srefIxMsdcVExpstate = retrieveSi(srcdoc, "StatShrMsdcLivVideo", "srefIxMsdcVExpstate");

			if (srefIxMsdcVExpstate != oldSrefIxMsdcVExpstate) {
				if (srefIxMsdcVExpstate == "mind") minimize();
				else if (srefIxMsdcVExpstate == "regd") regularize();
			} else {
				refresh();
			};

		} else {
			refresh();
		};
	} else if (dpch == "DpchEngMsdcLivVideoLive") {
		handleDpchEngMsdcLivVideoLive(dom);
	};
};

function handleDpchEngMsdcLivVideoLive(dom) {
	// IP handleDpchEngMsdcLivVideoLive --- IBEGIN
	var mask = [];

	var resnode;

	updateSrcblock(dom, "DpchEngMsdcLivVideoLive", "ContInfMsdcLivVideo", srcdoc);

	resnode = getNode(dom, "//msdc:DpchEngMsdcLivVideoLive/msdc:red");
	if (resnode) {
		doc.red = parseUtinyintvec(resnode.textContent);
		mask.push("red");
	};

	resnode = getNode(dom, "//msdc:DpchEngMsdcLivVideoLive/msdc:green");
	if (resnode) {
		doc.green = parseUtinyintvec(resnode.textContent);
		mask.push("green");
	};

	resnode = getNode(dom, "//msdc:DpchEngMsdcLivVideoLive/msdc:blue");
	if (resnode) {
		doc.blue = parseUtinyintvec(resnode.textContent);
		mask.push("blue");
	};

	resnode = getNode(dom, "//msdc:DpchEngMsdcLivVideoLive/msdc:gray");
	if (resnode) {
		doc.gray = parseUsmallintvec(resnode.textContent);
		mask.push("gray");
	};

	var srefIxMsdcVExpstate = retrieveSi(srcdoc, "StatShrMsdcLivVideo", "srefIxMsdcVExpstate");
	if (srefIxMsdcVExpstate == "regd") refreshLive(mask);
	// IP handleDpchEngMsdcLivVideoLive --- IEND
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//msdc:*");
		if (blk) {
			if (blk.nodeName == "DpchEngMsdcLivVideoData") {
				mergeDpchEngData(dom);
				init();

				getCrdwnd().setInitdone("Video");
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

			} else if (blk.nodeName == "DpchEngMsdcLivVideoData") {
				var oldSrefIxMsdcVExpstate = retrieveSi(srcdoc, "StatShrMsdcLivVideo", "srefIxMsdcVExpstate");

				var mask = mergeDpchEngData(dom);

				if (mask.indexOf("statshr") != -1) {
					var srefIxMsdcVExpstate = retrieveSi(srcdoc, "StatShrMsdcLivVideo", "srefIxMsdcVExpstate");

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



