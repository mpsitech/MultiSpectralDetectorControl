/**
  * \file PnlMsdcDatRec.js
  * web client functionality for panel PnlMsdcDatRec
  * \author Alexander Wirthmueller
  * \date created: 12 Sep 2018
  * \date modified: 12 Sep 2018
  */

function updateScrJrefs() {
	scrJrefDetail = retrieveSi(srcdoc, "StatShrMsdcDatRec", "scrJrefDetail");
	scrJrefAPar = retrieveSi(srcdoc, "StatShrMsdcDatRec", "scrJrefAPar");
	scrJrefRef1NFile = retrieveSi(srcdoc, "StatShrMsdcDatRec", "scrJrefRef1NFile");
};

function resetInitdones() {
	setSi(srcdoc, "StatAppMsdcDatRec", "initdoneDetail", "false");
	setSi(srcdoc, "StatAppMsdcDatRec", "initdoneAPar", "false");
	setSi(srcdoc, "StatAppMsdcDatRec", "initdoneRef1NFile", "false");
};

function resetHeights() {
	heightDetail = 30;
	heightAPar = 30;
	heightRef1NFile = 30;
};

function getInitdone(pnlshort) {
	return(retrieveSi(srcdoc, "StatAppMsdcDatRec", "initdone" + pnlshort) == "true");
};

function setInitdone(pnlshort) {
	setSi(srcdoc, "StatAppMsdcDatRec", "initdone" + pnlshort, "true");

	checkInitdone();
};

function checkInitdone() {
	var initdoneDetail = (retrieveSi(srcdoc, "StatAppMsdcDatRec", "initdoneDetail") == "true");
	var initdoneAPar = (retrieveSi(srcdoc, "StatAppMsdcDatRec", "initdoneAPar") == "true");
	var initdone1NRelease = (retrieveSi(srcdoc, "StatAppMsdcDatRec", "initdone1NRelease") == "true");

	var initdoneDetail = (retrieveSi(srcdoc, "StatAppMsdcDatRec", "initdoneDetail") == "true");
	var initdoneAPar = (retrieveSi(srcdoc, "StatAppMsdcDatRec", "initdoneAPar") == "true");
	var initdoneRef1NFile = (retrieveSi(srcdoc, "StatAppMsdcDatRec", "initdoneRef1NFile") == "true");

	if (!initdoneDetail) {
		lhsdoc.getElementById("Detail").src = "./PnlMsdcDatDetail.html?scrJref=" + scrJrefDetail;
	} else if (!initdoneAPar) {
		lhsdoc.getElementById("APar").src = "./PnlMsdcDatAPar.html?scrJref=" + scrJrefAPar;
	} else if (!initdoneRef1NFile) {
		rhsdoc.getElementById("Ref1NFile").src = "./PnlMsdcDatRef1NFile.html?scrJref=" + scrJrefRef1NFile;

	} else {
		refreshB();
	};
};

function reinitPnl(scrJrefPnl) {
};

function setPnlAvail(short, avail) {
	var lhsrhsdoc;

	if ((short == "Detail") || (short == "APar")) lhsrhsdoc = lhsdoc;
	else lhsrhsdoc = rhsdoc;

	var oldAvail = (lhsrhsdoc.getElementById("tr" + short).getAttribute("class") == "show");

	var height;

	if (avail != oldAvail) {
		if (avail) {
			height = 30;

			lhsrhsdoc.getElementById("spc" + short).setAttribute("class", "show");
			lhsrhsdoc.getElementById("tr" + short).setAttribute("class", "show");

		} else {
			height = -13;

			lhsrhsdoc.getElementById(short).contentWindow.minimize(false);
			
			lhsrhsdoc.getElementById("spc" + short).setAttribute("class", "hide");
			lhsrhsdoc.getElementById("tr" + short).setAttribute("class", "hide");
		};

		if (short == "Headbar") heightHeadbar = height;
		else if (short == "List") heightList = height;
		else if (short == "Rec") heightRec = height;
		else if (short == "Detail") heightDetail = height;
		else if (short == "APar") heightAPar = height;
		else if (short == "Ref1NFile") heightRef1NFile = height;
	};

	return(avail != oldAvail);
};

// --- expand state management
function minimize() {
	resetInitdones();

	getCrdwnd().changeHeight("Rec", 45);
	doc.getElementById("tdSide").setAttribute("height", "45");
	doc.getElementById("Rec_side").setAttribute("height", "45");
	doc.getElementById("Rec_cont").setAttribute("height", "45");

	doc.getElementById("Rec_side").src = "./PnlMsdcDatRec_aside.html";
	doc.getElementById("Rec_cont").src = "./PnlMsdcDatRec_a.html";
};

function regularize() {
	resetHeights();

	getCrdwnd().changeHeight("Rec", 137);
	doc.getElementById("tdSide").setAttribute("height", "137");
	doc.getElementById("Rec_side").setAttribute("height", "137");
	doc.getElementById("Rec_cont").setAttribute("height", "137");

	doc.getElementById("Rec_side").src = "./PnlMsdcDatRec_bside.html";
	doc.getElementById("Rec_cont").src = "./PnlMsdcDatRec_b.html";
};

function changeHeight(pnlshort, height, update) {
	var lhsrhsdoc;

	if ((pnlshort == "Detail") || (pnlshort == "APar")) lhsrhsdoc = lhsdoc;
	else lhsrhsdoc = rhsdoc;

	lhsrhsdoc.getElementById("td" + pnlshort).setAttribute("height", "" + height);
	lhsrhsdoc.getElementById(pnlshort).setAttribute("height", "" + height);

	if (pnlshort == "Headbar") heightHeadbar = height;
	else if (pnlshort == "List") heightList = height;
	else if (pnlshort == "Rec") heightRec = height;
	else if (pnlshort == "Detail") heightDetail = height;
	else if (pnlshort == "APar") heightAPar = height;
	else if (pnlshort == "Ref1NFile") heightRef1NFile = height;

	if (update) updateHeight();
};

function updateHeight() {
	var heightLhs, heightRhs, heightGt;

	heightLhs = heightDetail+13 + heightAPar+13 + 5;
	heightRhs = heightRef1NFile+13 + 5;

	if (heightLhs > heightRhs) {
		lhsdoc.getElementById("tdFill").setAttribute("height", "5");
		rhsdoc.getElementById("tdFill").setAttribute("height", "" + (heightLhs-heightRhs+5));

		heightGt = heightLhs;

	} else {
		lhsdoc.getElementById("tdFill").setAttribute("height", "" + (heightRhs-heightLhs+5));
		rhsdoc.getElementById("tdFill").setAttribute("height", "5");

		heightGt = heightRhs;
	};

	getCrdwnd().changeHeight("Rec", 45+heightGt+1);

	doc.getElementById("tdSide").setAttribute("height", "" + (45+heightGt+1));
	doc.getElementById("Rec_side").setAttribute("height", "" + (45+heightGt+1));
	doc.getElementById("Rec_cont").setAttribute("height", "" + (45+heightGt+1));

	sidedoc.getElementById("tdFlex").setAttribute("height", "" + (heightGt+1));

	contdoc.getElementById("tdLhs").setAttribute("height", "" + heightGt);
	contdoc.getElementById("Rec_lhs").setAttribute("height", "" + heightGt);
	contdoc.getElementById("tdRhs").setAttribute("height", "" + heightGt);
	contdoc.getElementById("Rec_rhs").setAttribute("height", "" + heightGt);
};

// --- view initialization and refresh
function initAside() {
	if (!doc) return;

	sidedoc = doc.getElementById("Rec_side").contentDocument;

	refreshAside();
};

function initA() {
	if (!doc) return;

	contdoc = doc.getElementById("Rec_cont").contentDocument;
	hdrdoc = null;
	lhsdoc = null;
	rhsdoc = null;

	setTextContent(contdoc, contdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagMsdcDatRec", "Cpt"));

	refreshA();
};

function initB() {
	if (!doc) return;

	sidedoc = doc.getElementById("Rec_side").contentDocument;
	contdoc = doc.getElementById("Rec_cont").contentDocument;
	hdrdoc = contdoc.getElementById("Rec_hdr").contentDocument;
	lhsdoc = contdoc.getElementById("Rec_lhs").contentDocument;
	rhsdoc = contdoc.getElementById("Rec_rhs").contentDocument;

	setTextContent(hdrdoc, hdrdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagMsdcDatRec", "Cpt"));

	checkInitdone();
};

function init() {
	var srefIxMsdcVExpstate = retrieveSi(srcdoc, "StatShrMsdcDatRec", "srefIxMsdcVExpstate");

	if (srefIxMsdcVExpstate == "mind") {
		minimize();
	} else if (srefIxMsdcVExpstate == "regd") {
		regularize();
	};
};

function refreshAside() {
	var ButRegularizeActive;

	ButRegularizeActive = (retrieveSi(srcdoc, "StatShrMsdcDatRec", "ButRegularizeActive") == "true");

	if (ButRegularizeActive) {
		sidedoc.getElementById("ButRegularize").src = "../icon/regularize.png";
		sidedoc.getElementById("ButRegularize").setAttribute("class", "side_pm");
		sidedoc.getElementById("ButRegularize").setAttribute("onmouseover", "src='../icon/regularize_hlt.png'");
		sidedoc.getElementById("ButRegularize").setAttribute("onmouseout", "src='../icon/regularize.png'");
		sidedoc.getElementById("ButRegularize").setAttribute("onclick", "handleButRegularizeClick()");
	} else {
		sidedoc.getElementById("ButRegularize").src = "../icon/regularize_inact.png";
		sidedoc.getElementById("ButRegularize").setAttribute("class", "side_pmdis");
		sidedoc.getElementById("ButRegularize").setAttribute("onmouseover", "");
		sidedoc.getElementById("ButRegularize").setAttribute("onmouseout", "");
		sidedoc.getElementById("ButRegularize").setAttribute("onclick", "");
	};
};

function refreshA() {
	setTextContent(contdoc, contdoc.getElementById("TxtRef"), retrieveCi(srcdoc, "ContInfMsdcDatRec", "TxtRef"));
};

function refreshB() {

	setTextContent(hdrdoc, hdrdoc.getElementById("TxtRef"), retrieveCi(srcdoc, "ContInfMsdcDatRec", "TxtRef"));

};

function refresh() {
	var srefIxMsdcVExpstate = retrieveSi(srcdoc, "StatShrMsdcDatRec", "srefIxMsdcVExpstate");

	if (srefIxMsdcVExpstate == "mind") {
		refreshAside();
		refreshA();
	} else if (srefIxMsdcVExpstate == "regd") {
		refreshB();
	};
};

// --- event handlers
function handleLoad() {
	scrJref = location.search.substr(location.search.indexOf("scrJref=")+8);

	doc = document;
	srcdoc = doc.getElementById("Rec_src").contentDocument;

	var str = serializeDpchApp("DpchAppMsdcInit", scrJref);
	sendReq(str, doc, handleDpchAppInitReply, true);
};

// --- specific event handlers for app controls

// --- generalized event handlers for app controls

// --- generalized event handlers for shared controls

function handleButClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppMsdcDatRecDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngMsdcDatRecData", "ContInfMsdcDatRec", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngMsdcDatRecData", "StatAppMsdcDatRec", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngMsdcDatRecData", "StatShrMsdcDatRec", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngMsdcDatRecData", "TagMsdcDatRec", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (!srcdoc) return;

	var _scrJref, mask;
	var srefIxMsdcVExpstate, newSrefIxMsdcVExpstate;

	_scrJref = retrieveValue(dom, "//msdc:*/msdc:scrJref");
	srefIxMsdcVExpstate = retrieveSi(srcdoc, "StatShrMsdcDatRec", "srefIxMsdcVExpstate");

	if (_scrJref == scrJref) {
		if (dpch == "DpchEngMsdcDatRecData") {
			mask = mergeDpchEngData(dom);

			if (mask.indexOf("statshr") != -1) {
				newSrefIxMsdcVExpstate = retrieveSi(srcdoc, "StatShrMsdcDatRec", "srefIxMsdcVExpstate");

				if (newSrefIxMsdcVExpstate != srefIxMsdcVExpstate) {
					updateScrJrefs();
					
					if (newSrefIxMsdcVExpstate == "mind") {
						minimize();
					} else if (newSrefIxMsdcVExpstate == "regd") {
						regularize();
					};

				} else {
					refresh();
				};

			} else {
				refresh();
			};
		};

	} else {
		if (srefIxMsdcVExpstate != "mind") {
			if (!lhsdoc) return;
			if (!rhsdoc) return;

			if (_scrJref == scrJrefDetail) {
				if (getInitdone("Detail")) lhsdoc.getElementById("Detail").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefAPar) {
				if (getInitdone("APar")) lhsdoc.getElementById("APar").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefRef1NFile) {
				if (getInitdone("Ref1NFile")) rhsdoc.getElementById("Ref1NFile").contentWindow.handleDpchEng(dom, dpch);
			} else {
				// alert("got a '" + dpch + "' from job with scrJref " + _scrJref);
			};

		} else {
			// alert("got a '" + dpch + "' from job with scrJref " + _scrJref);
		};
	};
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//msdc:*");
		if (blk) {
			if (blk.nodeName == "DpchEngMsdcDatRecData") {
				mergeDpchEngData(dom);

				updateScrJrefs();
				init();

				getCrdwnd().setInitdone("Rec");
			};
		};
	};
};

function handleDpchAppDataDoReply() {
	var dom, blk, mask;
	var srefIxMsdcVExpstate, newSrefIxMsdcVExpstate;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		// check dispatch type
		blk = retrieveBlock(dom, "//msdc:*");

		if (blk) {
			if (blk.nodeName == "DpchEngMsdcConfirm") {
				// do nothing

			} else if (blk.nodeName == "DpchEngMsdcDatRecData") {
				srefIxMsdcVExpstate = retrieveSi(srcdoc, "StatShrMsdcDatRec", "srefIxMsdcVExpstate");

				mask = mergeDpchEngData(dom);

				if (mask.indexOf("statshr") != -1) {
					newSrefIxMsdcVExpstate = retrieveSi(srcdoc, "StatShrMsdcDatRec", "srefIxMsdcVExpstate");

					if (newSrefIxMsdcVExpstate != srefIxMsdcVExpstate) {
						updateScrJrefs();

						if (newSrefIxMsdcVExpstate == "mind") {
							minimize();
						} else if (newSrefIxMsdcVExpstate == "regd") {
							regularize();
						};
					};

				} else {
					refresh();
				};
			};
		};
	};
};

