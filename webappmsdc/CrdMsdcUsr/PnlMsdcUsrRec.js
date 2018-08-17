/**
  * \file PnlMsdcUsrRec.js
  * web client functionality for panel PnlMsdcUsrRec
  * \author Alexander Wirthmueller
  * \date created: 15 Aug 2018
  * \date modified: 15 Aug 2018
  */

function updateScrJrefs() {
	scrJrefDetail = retrieveSi(srcdoc, "StatShrMsdcUsrRec", "scrJrefDetail");
	scrJrefAAccess = retrieveSi(srcdoc, "StatShrMsdcUsrRec", "scrJrefAAccess");
	scrJref1NSession = retrieveSi(srcdoc, "StatShrMsdcUsrRec", "scrJref1NSession");
	scrJrefMNUsergroup = retrieveSi(srcdoc, "StatShrMsdcUsrRec", "scrJrefMNUsergroup");
};

function resetInitdones() {
	setSi(srcdoc, "StatAppMsdcUsrRec", "initdoneDetail", "false");
	setSi(srcdoc, "StatAppMsdcUsrRec", "initdoneAAccess", "false");
	setSi(srcdoc, "StatAppMsdcUsrRec", "initdone1NSession", "false");
	setSi(srcdoc, "StatAppMsdcUsrRec", "initdoneMNUsergroup", "false");
};

function resetHeights() {
	heightDetail = 30;
	heightAAccess = 30;
	height1NSession = 30;
	heightMNUsergroup = 30;
};

function getInitdone(pnlshort) {
	return(retrieveSi(srcdoc, "StatAppMsdcUsrRec", "initdone" + pnlshort) == "true");
};

function setInitdone(pnlshort) {
	setSi(srcdoc, "StatAppMsdcUsrRec", "initdone" + pnlshort, "true");

	checkInitdone();
};

function checkInitdone() {
	var initdoneDetail = (retrieveSi(srcdoc, "StatAppMsdcUsrRec", "initdoneDetail") == "true");
	var initdoneAPar = (retrieveSi(srcdoc, "StatAppMsdcUsrRec", "initdoneAPar") == "true");
	var initdone1NRelease = (retrieveSi(srcdoc, "StatAppMsdcUsrRec", "initdone1NRelease") == "true");

	var initdoneDetail = (retrieveSi(srcdoc, "StatAppMsdcUsrRec", "initdoneDetail") == "true");
	var initdoneAAccess = (retrieveSi(srcdoc, "StatAppMsdcUsrRec", "initdoneAAccess") == "true");
	var initdone1NSession = (retrieveSi(srcdoc, "StatAppMsdcUsrRec", "initdone1NSession") == "true");
	var initdoneMNUsergroup = (retrieveSi(srcdoc, "StatAppMsdcUsrRec", "initdoneMNUsergroup") == "true");

	if (!initdoneDetail) {
		lhsdoc.getElementById("Detail").src = "./PnlMsdcUsrDetail.html?scrJref=" + scrJrefDetail;
	} else if (!initdoneAAccess) {
		lhsdoc.getElementById("AAccess").src = "./PnlMsdcUsrAAccess.html?scrJref=" + scrJrefAAccess;
	} else if (!initdone1NSession) {
		rhsdoc.getElementById("1NSession").src = "./PnlMsdcUsr1NSession.html?scrJref=" + scrJref1NSession;
	} else if (!initdoneMNUsergroup) {
		rhsdoc.getElementById("MNUsergroup").src = "./PnlMsdcUsrMNUsergroup.html?scrJref=" + scrJrefMNUsergroup;

	} else {
		refreshB();
	};
};

function reinitPnl(scrJrefPnl) {
};

function setPnlAvail(short, avail) {
	var lhsrhsdoc;

	if ((short == "Detail") || (short == "AAccess")) lhsrhsdoc = lhsdoc;
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
		else if (short == "AAccess") heightAAccess = height;
		else if (short == "1NSession") height1NSession = height;
		else if (short == "MNUsergroup") heightMNUsergroup = height;
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

	doc.getElementById("Rec_side").src = "./PnlMsdcUsrRec_aside.html";
	doc.getElementById("Rec_cont").src = "./PnlMsdcUsrRec_a.html";
};

function regularize() {
	resetHeights();

	getCrdwnd().changeHeight("Rec", 137);
	doc.getElementById("tdSide").setAttribute("height", "137");
	doc.getElementById("Rec_side").setAttribute("height", "137");
	doc.getElementById("Rec_cont").setAttribute("height", "137");

	doc.getElementById("Rec_side").src = "./PnlMsdcUsrRec_bside.html";
	doc.getElementById("Rec_cont").src = "./PnlMsdcUsrRec_b.html";
};

function changeHeight(pnlshort, height, update) {
	var lhsrhsdoc;

	if ((pnlshort == "Detail") || (pnlshort == "AAccess")) lhsrhsdoc = lhsdoc;
	else lhsrhsdoc = rhsdoc;

	lhsrhsdoc.getElementById("td" + pnlshort).setAttribute("height", "" + height);
	lhsrhsdoc.getElementById(pnlshort).setAttribute("height", "" + height);

	if (pnlshort == "Headbar") heightHeadbar = height;
	else if (pnlshort == "List") heightList = height;
	else if (pnlshort == "Rec") heightRec = height;
	else if (pnlshort == "Detail") heightDetail = height;
	else if (pnlshort == "AAccess") heightAAccess = height;
	else if (pnlshort == "1NSession") height1NSession = height;
	else if (pnlshort == "MNUsergroup") heightMNUsergroup = height;

	if (update) updateHeight();
};

function updateHeight() {
	var heightLhs, heightRhs, heightGt;

	heightLhs = heightDetail+13 + heightAAccess+13 + 5;
	heightRhs = height1NSession+13 + heightMNUsergroup+13 + 5;

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

	setTextContent(contdoc, contdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagMsdcUsrRec", "Cpt"));

	refreshA();
};

function initB() {
	if (!doc) return;

	sidedoc = doc.getElementById("Rec_side").contentDocument;
	contdoc = doc.getElementById("Rec_cont").contentDocument;
	hdrdoc = contdoc.getElementById("Rec_hdr").contentDocument;
	lhsdoc = contdoc.getElementById("Rec_lhs").contentDocument;
	rhsdoc = contdoc.getElementById("Rec_rhs").contentDocument;

	setTextContent(hdrdoc, hdrdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagMsdcUsrRec", "Cpt"));

	checkInitdone();
};

function init() {
	var srefIxMsdcVExpstate = retrieveSi(srcdoc, "StatShrMsdcUsrRec", "srefIxMsdcVExpstate");

	if (srefIxMsdcVExpstate == "mind") {
		minimize();
	} else if (srefIxMsdcVExpstate == "regd") {
		regularize();
	};
};

function refreshAside() {
	var ButRegularizeActive;

	ButRegularizeActive = (retrieveSi(srcdoc, "StatShrMsdcUsrRec", "ButRegularizeActive") == "true");

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
	setTextContent(contdoc, contdoc.getElementById("TxtRef"), retrieveCi(srcdoc, "ContInfMsdcUsrRec", "TxtRef"));
};

function refreshB() {

	setTextContent(hdrdoc, hdrdoc.getElementById("TxtRef"), retrieveCi(srcdoc, "ContInfMsdcUsrRec", "TxtRef"));

};

function refresh() {
	var srefIxMsdcVExpstate = retrieveSi(srcdoc, "StatShrMsdcUsrRec", "srefIxMsdcVExpstate");

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
	var str = serializeDpchAppDo(srcdoc, "DpchAppMsdcUsrRecDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngMsdcUsrRecData", "ContInfMsdcUsrRec", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngMsdcUsrRecData", "StatAppMsdcUsrRec", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngMsdcUsrRecData", "StatShrMsdcUsrRec", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngMsdcUsrRecData", "TagMsdcUsrRec", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (!srcdoc) return;

	var _scrJref, mask;
	var srefIxMsdcVExpstate, newSrefIxMsdcVExpstate;

	_scrJref = retrieveValue(dom, "//msdc:*/msdc:scrJref");
	srefIxMsdcVExpstate = retrieveSi(srcdoc, "StatShrMsdcUsrRec", "srefIxMsdcVExpstate");

	if (_scrJref == scrJref) {
		if (dpch == "DpchEngMsdcUsrRecData") {
			mask = mergeDpchEngData(dom);

			if (mask.indexOf("statshr") != -1) {
				newSrefIxMsdcVExpstate = retrieveSi(srcdoc, "StatShrMsdcUsrRec", "srefIxMsdcVExpstate");

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
			} else if (_scrJref == scrJrefAAccess) {
				if (getInitdone("AAccess")) lhsdoc.getElementById("AAccess").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJref1NSession) {
				if (getInitdone("1NSession")) rhsdoc.getElementById("1NSession").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefMNUsergroup) {
				if (getInitdone("MNUsergroup")) rhsdoc.getElementById("MNUsergroup").contentWindow.handleDpchEng(dom, dpch);
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
			if (blk.nodeName == "DpchEngMsdcUsrRecData") {
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

			} else if (blk.nodeName == "DpchEngMsdcUsrRecData") {
				srefIxMsdcVExpstate = retrieveSi(srcdoc, "StatShrMsdcUsrRec", "srefIxMsdcVExpstate");

				mask = mergeDpchEngData(dom);

				if (mask.indexOf("statshr") != -1) {
					newSrefIxMsdcVExpstate = retrieveSi(srcdoc, "StatShrMsdcUsrRec", "srefIxMsdcVExpstate");

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

