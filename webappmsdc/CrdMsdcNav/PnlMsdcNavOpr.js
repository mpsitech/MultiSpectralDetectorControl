/**
  * \file PnlMsdcNavOpr.js
  * web client functionality for panel PnlMsdcNavOpr
  * \author Alexander Wirthmueller
  * \date created: 4 Oct 2018
  * \date modified: 4 Oct 2018
  */

// IP cust --- INSERT

// --- expand state management
function minimize() {
	if (retrieveSi(srcdoc, "StatAppMsdcNavOpr", "srefIxMsdcVExpstate") == "mind") return;

	setSi(srcdoc, "StatAppMsdcNavOpr", "srefIxMsdcVExpstate", "mind");

	// change container heights
	getCrdwnd().changeHeight("Opr", 30);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Opr_side").setAttribute("height", "30");
	doc.getElementById("Opr_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Opr_side").src = "./PnlMsdcNavOpr_aside.html";
	doc.getElementById("Opr_cont").src = "./PnlMsdcNavOpr_a.html";
};

function regularize() {
	if (retrieveSi(srcdoc, "StatAppMsdcNavOpr", "srefIxMsdcVExpstate") == "regd") return;

	setSi(srcdoc, "StatAppMsdcNavOpr", "srefIxMsdcVExpstate", "regd");

	// change content (container heights in refreshBD)
	doc.getElementById("Opr_side").src = "./PnlMsdcNavOpr_bside.html";
	doc.getElementById("Opr_cont").src = "./PnlMsdcNavOpr_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Opr_side").contentDocument;
	contdoc = doc.getElementById("Opr_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagMsdcNavOpr", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("Opr_side").contentDocument;
	contdoc = doc.getElementById("Opr_cont").contentDocument;
	hdrdoc = contdoc.getElementById("Opr_hdr").contentDocument;
	contcontdoc = contdoc.getElementById("Opr_cont").contentDocument;

	// IP initBD --- BEGIN
	initCpt(hdrdoc, "Cpt", retrieveTi(srcdoc, "TagMsdcNavOpr", "Cpt"));
	initCpt(contcontdoc, "CptLiv", retrieveTi(srcdoc, "TagMsdcNavOpr", "CptLiv"));
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxMsdcVExpstate = retrieveSi(srcdoc, "StatAppMsdcNavOpr", "srefIxMsdcVExpstate");

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
	var height = 323; // full cont height

	// IP refreshBD.vars --- BEGIN
	var ButLivNewcrdAvail = (retrieveSi(srcdoc, "StatShrMsdcNavOpr", "ButLivNewcrdAvail") == "true");

	var LstPrdAlt = (retrieveSi(srcdoc, "StatAppMsdcNavOpr", "LstPrdAlt") == "true");
	var LstPrdAvail = (retrieveSi(srcdoc, "StatShrMsdcNavOpr", "LstPrdAvail") == "true");
	var ButPrdViewAvail = !LstPrdAlt;
	var ButPrdViewActive = (retrieveSi(srcdoc, "StatShrMsdcNavOpr", "ButPrdViewActive") == "true");

	var LstDatAlt = (retrieveSi(srcdoc, "StatAppMsdcNavOpr", "LstDatAlt") == "true");
	var LstDatAvail = (retrieveSi(srcdoc, "StatShrMsdcNavOpr", "LstDatAvail") == "true");
	var ButDatViewAvail = !LstDatAlt;
	var ButDatViewActive = (retrieveSi(srcdoc, "StatShrMsdcNavOpr", "ButDatViewActive") == "true");
	var ButDatNewcrdActive = (retrieveSi(srcdoc, "StatShrMsdcNavOpr", "ButDatNewcrdActive") == "true");

	var LstFilAlt = (retrieveSi(srcdoc, "StatAppMsdcNavOpr", "LstFilAlt") == "true");
	var LstFilAvail = (retrieveSi(srcdoc, "StatShrMsdcNavOpr", "LstFilAvail") == "true");
	var ButFilViewAvail = !LstFilAlt;
	var ButFilViewActive = (retrieveSi(srcdoc, "StatShrMsdcNavOpr", "ButFilViewActive") == "true");
	var ButFilNewcrdActive = (retrieveSi(srcdoc, "StatShrMsdcNavOpr", "ButFilNewcrdActive") == "true");

	var mytd, first;
	// IP refreshBD.vars --- END

	// IP refreshBD --- BEGIN
	height -= setCtlAvail(contcontdoc, "Liv", ButLivNewcrdAvail, 25);
	if (ButLivNewcrdAvail) {
		if ((ButLivNewcrdAvail == !contcontdoc.getElementById("ButLivNewcrd"))) {
			mytd = contcontdoc.getElementById("dynLiv");
			clearElem(mytd);

			first = true;

			if (ButLivNewcrdAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButLivNewcrd", "icon/newcrd"));
			};
		};

	};

	height -= setCtlAvail(contcontdoc, "Prd", LstPrdAvail, 96);
	height -= setCtlAvail(contcontdoc, "Prd2", LstPrdAvail && !LstPrdAlt, (LstPrdAvail) ? 71 : 0);
	if (LstPrdAvail) {
		if ( (LstPrdAlt == !contcontdoc.getElementById("ButPrdExpand")) || (!LstPrdAlt == !contcontdoc.getElementById("ButPrdCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynPrd");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptPrd", retrieveTi(srcdoc, "TagMsdcNavOpr", "CptPrd")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstPrdAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButPrdExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButPrdCollapse", "icon/collapse"));
		};

		if (!LstPrdAlt == !contcontdoc.getElementById("LstPrd")) {
			mytd = contcontdoc.getElementById("rdynPrd");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynPrd");
			clearElem(mytd);

			if (LstPrdAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstPrd", "./PnlMsdcNavOpr_LstPrd.xml", true));
			};

		} else {
			if (!LstPrdAlt) refreshLst(contcontdoc.getElementById("LstPrd").contentWindow.document, srcdoc, 1, true, false, "FeedFLstPrd",
						parseInt(retrieveSi(srcdoc, "StatAppMsdcNavOpr", "LstPrdNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacMsdcNavOpr", "numFLstPrd"))]);
		};

		if ((ButPrdViewAvail == !contcontdoc.getElementById("ButPrdView")) || !contcontdoc.getElementById("ButPrdNewcrd")) {
			if (LstPrdAlt) mytd = contcontdoc.getElementById("dynPrd");
			else mytd = contcontdoc.getElementById("rdynPrd");
			clearElem(mytd);

			first = true;

			if (ButPrdViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButPrdView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButPrdNewcrd", "icon/newcrd"));
		};

		if (ButPrdViewAvail) refreshButicon(contcontdoc, "ButPrdView", "icon/view", ButPrdViewActive, false);

	} else setCtlAvail(contcontdoc, "Prd2", false, 0);

	height -= setCtlAvail(contcontdoc, "Dat", LstDatAvail, 96);
	height -= setCtlAvail(contcontdoc, "Dat2", LstDatAvail && !LstDatAlt, (LstDatAvail) ? 71 : 0);
	if (LstDatAvail) {
		if ( (LstDatAlt == !contcontdoc.getElementById("ButDatExpand")) || (!LstDatAlt == !contcontdoc.getElementById("ButDatCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynDat");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptDat", retrieveTi(srcdoc, "TagMsdcNavOpr", "CptDat")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstDatAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButDatExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButDatCollapse", "icon/collapse"));
		};

		if (!LstDatAlt == !contcontdoc.getElementById("LstDat")) {
			mytd = contcontdoc.getElementById("rdynDat");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynDat");
			clearElem(mytd);

			if (LstDatAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstDat", "./PnlMsdcNavOpr_LstDat.xml", true));
			};

		} else {
			if (!LstDatAlt) refreshLst(contcontdoc.getElementById("LstDat").contentWindow.document, srcdoc, 1, true, false, "FeedFLstDat",
						parseInt(retrieveSi(srcdoc, "StatAppMsdcNavOpr", "LstDatNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacMsdcNavOpr", "numFLstDat"))]);
		};

		if ((ButDatViewAvail == !contcontdoc.getElementById("ButDatView")) || !contcontdoc.getElementById("ButDatNewcrd")) {
			if (LstDatAlt) mytd = contcontdoc.getElementById("dynDat");
			else mytd = contcontdoc.getElementById("rdynDat");
			clearElem(mytd);

			first = true;

			if (ButDatViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButDatView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButDatNewcrd", "icon/newcrd"));
		};

		if (ButDatViewAvail) refreshButicon(contcontdoc, "ButDatView", "icon/view", ButDatViewActive, false);
		refreshButicon(contcontdoc, "ButDatNewcrd", "icon/newcrd", ButDatNewcrdActive, false);

	} else setCtlAvail(contcontdoc, "Dat2", false, 0);

	height -= setCtlAvail(contcontdoc, "Fil", LstFilAvail, 96);
	height -= setCtlAvail(contcontdoc, "Fil2", LstFilAvail && !LstFilAlt, (LstFilAvail) ? 71 : 0);
	if (LstFilAvail) {
		if ( (LstFilAlt == !contcontdoc.getElementById("ButFilExpand")) || (!LstFilAlt == !contcontdoc.getElementById("ButFilCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynFil");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptFil", retrieveTi(srcdoc, "TagMsdcNavOpr", "CptFil")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstFilAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButFilExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButFilCollapse", "icon/collapse"));
		};

		if (!LstFilAlt == !contcontdoc.getElementById("LstFil")) {
			mytd = contcontdoc.getElementById("rdynFil");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynFil");
			clearElem(mytd);

			if (LstFilAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstFil", "./PnlMsdcNavOpr_LstFil.xml", true));
			};

		} else {
			if (!LstFilAlt) refreshLst(contcontdoc.getElementById("LstFil").contentWindow.document, srcdoc, 1, true, false, "FeedFLstFil",
						parseInt(retrieveSi(srcdoc, "StatAppMsdcNavOpr", "LstFilNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacMsdcNavOpr", "numFLstFil"))]);
		};

		if ((ButFilViewAvail == !contcontdoc.getElementById("ButFilView")) || !contcontdoc.getElementById("ButFilNewcrd")) {
			if (LstFilAlt) mytd = contcontdoc.getElementById("dynFil");
			else mytd = contcontdoc.getElementById("rdynFil");
			clearElem(mytd);

			first = true;

			if (ButFilViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButFilView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButFilNewcrd", "icon/newcrd"));
		};

		if (ButFilViewAvail) refreshButicon(contcontdoc, "ButFilView", "icon/view", ButFilViewActive, false);
		refreshButicon(contcontdoc, "ButFilNewcrd", "icon/newcrd", ButFilNewcrdActive, false);

	} else setCtlAvail(contcontdoc, "Fil2", false, 0);

	// IP refreshBD --- END

	getCrdwnd().changeHeight("Opr", height+31);
	doc.getElementById("tdSide").setAttribute("height", "" + (height+31));
	doc.getElementById("Opr_side").setAttribute("height", "" + (height+31));
	doc.getElementById("Opr_cont").setAttribute("height", "" + (height+31));
	sidedoc.getElementById("tdFlex").setAttribute("height", "" + (height+31-30));
	contdoc.getElementById("tdCont").setAttribute("height", "" + height);
	contdoc.getElementById("Opr_cont").setAttribute("height", "" + height);
};

function refresh() {
	var srefIxMsdcVExpstate = retrieveSi(srcdoc, "StatAppMsdcNavOpr", "srefIxMsdcVExpstate");

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
	srcdoc = doc.getElementById("Opr_src").contentDocument;

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

function handleButCollapseClick(basectlsref) {
	setSi(srcdoc, "StatAppMsdcNavOpr", basectlsref + "Alt", "true");
	refresh();
};

function handleButExpandClick(basectlsref) {
	setSi(srcdoc, "StatAppMsdcNavOpr", basectlsref + "Alt", "false");
	refresh();
};

function setLsbPos(lstdoc, pos) {
	var vpos = (16 + Math.round(pos * (90-2*16)));

	lstdoc.getElementById("LsbJpupr").setAttribute("height", "" + (vpos-10));
	lstdoc.getElementById("LsbJpupl").setAttribute("y2", "" + vpos);

	lstdoc.getElementById("LsbJpdownr").setAttribute("y", "" + vpos);
	lstdoc.getElementById("LsbJpdownr").setAttribute("height", "" + (90-vpos-10));
	lstdoc.getElementById("LsbJpdownl").setAttribute("y1", "" + vpos);

	lstdoc.getElementById("Lsb").setAttribute("transform", "translate(0 " + vpos + ")");
};

function handleLsbUpClick(lstdoc, basectlsref, ncol, multsel) {
	changeLstNumFirstdisp(lstdoc, basectlsref, multsel, ncol, 0, -1);
};

function handleLsbJpupClick(lstdoc, basectlsref, ncol, multsel) {
	changeLstNumFirstdisp(lstdoc, basectlsref, ncol, multsel, 0, -4);
};

function handleLsbJpdownClick(lstdoc, basectlsref, ncol, multsel) {
	changeLstNumFirstdisp(lstdoc, basectlsref, ncol, multsel, 0, 4);
};

function handleLsbDownClick(lstdoc, basectlsref, ncol, multsel) {
	changeLstNumFirstdisp(lstdoc, basectlsref, ncol, multsel, 0, 1);
};

function handleLsbMdn(lstdoc, basectlsref) {
	lstdoc.getElementById("tdLsb").onmousemove = contcontdoc.getElementById(basectlsref).contentWindow.handleLsbMove;
	lstdoc.getElementById("tdLsb").onmouseup = contcontdoc.getElementById(basectlsref).contentWindow.handleLsbMup;
};

function handleLsbMove(lstdoc, evt) {
	if ((evt.clientY >= 16) && (evt.clientY <= (90-16))) {
		var pos = (evt.clientY-16)/(90-2*16);
		setLsbPos(lstdoc, pos);
	};
};

function handleLsbMup(lstdoc, basectlsref, ncol, multsel, evt) {
	lstdoc.getElementById("tdLsb").removeAttribute("onmousemove");
	lstdoc.getElementById("tdLsb").removeAttribute("onmouseup");

	var cnt = getFeedSize(srcdoc, "FeedF" + basectlsref);

	var pos = (evt.clientY-16)/(90-2*16);
	changeLstNumFirstdisp(lstdoc, basectlsref, ncol, multsel, Math.round(pos*(cnt-5))+1, 0);
};

// --- generalized event handlers for shared controls

function handleButClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppMsdcNavOprDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButCrdopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppMsdcNavOprDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);
};

function handleLstLoad(lstdoc, ctlsref, ncol, multsel) {
	if (multsel) {
		refreshLst(lstdoc, srcdoc, ncol, true, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppMsdcNavOpr", ctlsref + "NumFirstdisp")),
					parseUintvec(retrieveCi(srcdoc, "ContIacMsdcNavOpr", "numsF" + ctlsref)));
	} else {
		refreshLst(lstdoc, srcdoc, ncol, true, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppMsdcNavOpr", ctlsref + "NumFirstdisp")),
					[parseInt(retrieveCi(srcdoc, "ContIacMsdcNavOpr", "numF" + ctlsref))]);
	};
};

function handleLstSelect(ctlsref, multsel, num) {
	var found, oldNumFLst, numsFLst, oldNumsFLst;

	if (multsel) {
		oldNumsFLst = parseUintvec(retrieveCi(srcdoc, "ContIacMsdcNavOpr", "numsF" + ctlsref));

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

		setCi(srcdoc, "ContIacMsdcNavOpr", "numsF" + ctlsref, encodeUintvec(numsFLst));

	} else {
		oldNumFLst = parseInt(retrieveCi(srcdoc, "ContIacMsdcNavOpr", "numF" + ctlsref));
		if (num == oldNumFLst) num = 0;

		setCi(srcdoc, "ContIacMsdcNavOpr", "numF" + ctlsref, num);
	};

	var str = serializeDpchAppData(srcdoc, "DpchAppMsdcNavOprData", scrJref, "ContIacMsdcNavOpr");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function changeLstNumFirstdisp(lstdoc, ctlsref, ncol, multsel, numFirstdisp, dNumFirstdisp) {
	var oldNumFirstdisp = parseInt(retrieveSi(srcdoc, "StatAppMsdcNavOpr", ctlsref + "NumFirstdisp"));
	if (dNumFirstdisp != 0) numFirstdisp = oldNumFirstdisp + dNumFirstdisp;

	var cnt = getFeedSize(srcdoc, "FeedF" + ctlsref);

	if (numFirstdisp > (cnt-5+1)) numFirstdisp = cnt-5+1;
	if (numFirstdisp < 1) numFirstdisp = 1;

	if (numFirstdisp != oldNumFirstdisp) {
		setSi(srcdoc, "StatAppMsdcNavOpr", ctlsref + "NumFirstdisp", "" + numFirstdisp);

		if (multsel) refreshLst(lstdoc, srcdoc, ncol, true, multsel, "FeedF" + ctlsref, numFirstdisp, parseUintvec(retrieveCi(srcdoc, "ContIacMsdcNavOpr", "numsF" + ctlsref)));
		else refreshLst(lstdoc, srcdoc, ncol, true, multsel, "FeedF" + ctlsref, numFirstdisp, [parseInt(retrieveCi(srcdoc, "ContIacMsdcNavOpr", "numF" + ctlsref))]);
	};
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngMsdcNavOprData", "ContIacMsdcNavOpr", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngMsdcNavOprData", "FeedFLstDat", srcdoc)) mask.push("feedFLstDat");
	if (updateSrcblock(dom, "DpchEngMsdcNavOprData", "FeedFLstFil", srcdoc)) mask.push("feedFLstFil");
	if (updateSrcblock(dom, "DpchEngMsdcNavOprData", "FeedFLstPrd", srcdoc)) mask.push("feedFLstPrd");
	if (updateSrcblock(dom, "DpchEngMsdcNavOprData", "StatAppMsdcNavOpr", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngMsdcNavOprData", "StatShrMsdcNavOpr", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngMsdcNavOprData", "TagMsdcNavOpr", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngMsdcNavOprData") {
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
			if (blk.nodeName == "DpchEngMsdcNavOprData") {
				mergeDpchEngData(dom);
				init();

				getCrdwnd().setInitdone("Opr");
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

			} else if (blk.nodeName == "DpchEngMsdcNavOprData") {
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

