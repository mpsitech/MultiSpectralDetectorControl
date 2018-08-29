/**
  * \file CrdMsdcStart.js
  * web client functionality for Msdc start page
  * \author Alexander Wirthmueller
  * \date created: 29 Aug 2018
  * \date modified: 29 Aug 2018
  */

function initLogin() {
	doc.getElementById("tdCont").setAttribute("height", "128");
	doc.getElementById("Cont").setAttribute("height", "120");

	contdoc = doc.getElementById("Cont").contentDocument;

	var srefIxMsdcVLocale = retrieveFeedSrefByNum(srcdoc, "FeedFPupLoginLocale.enus", parseInt(retrieveCi(srcdoc, "Cont", "numFPupLoginLocale")));

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "Tag." + srefIxMsdcVLocale, "CptLogin"));
	refreshPup(contdoc, srcdoc, "PupLocale", "", "FeedFPupLoginLocale." + srefIxMsdcVLocale, retrieveCi(srcdoc, "Cont", "numFPupLoginLocale"), true, false);
	initCpt(contdoc, "CptUsername", retrieveTi(srcdoc, "Tag." + srefIxMsdcVLocale, "CptLoginUsername"));
	initCpt(contdoc, "CptPassword", retrieveTi(srcdoc, "Tag." + srefIxMsdcVLocale, "CptLoginPassword"));
	initBut(contdoc, "ButReset", retrieveTi(srcdoc, "Tag." + srefIxMsdcVLocale, "ButLoginReset"));
	initBut(contdoc, "ButLogin", retrieveTi(srcdoc, "Tag." + srefIxMsdcVLocale, "ButLoginLogin"));

	refreshLogin();
};

function initSuccess() {
	doc.getElementById("tdCont").setAttribute("height", "172");
	doc.getElementById("Cont").setAttribute("height", "164");

	contdoc = doc.getElementById("Cont").contentDocument;

	var srefIxMsdcVLocale = retrieveFeedSrefByNum(srcdoc, "FeedFPupLoginLocale.enus", parseInt(retrieveCi(srcdoc, "Cont", "numFPupLoginLocale")));

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "Tag." + srefIxMsdcVLocale, "CptSuccess"));
	initCpt(contdoc, "CptSuspsess", retrieveTi(srcdoc, "Tag." + srefIxMsdcVLocale, "CptSuccessSuspsess"));
	initBut(contdoc, "ButSuspsessResume", retrieveTi(srcdoc, "Tag." + srefIxMsdcVLocale, "ButSuccessSuspsessResume"));
	initBut(contdoc, "ButBack", retrieveTi(srcdoc, "Tag." + srefIxMsdcVLocale, "ButSuccessBack"));
	initBut(contdoc, "ButNewsess", retrieveTi(srcdoc, "Tag." + srefIxMsdcVLocale, "ButSuccessNewsess"));

	refreshSuccess();
};

function initFailure() {
	doc.getElementById("tdCont").setAttribute("height", "103");
	doc.getElementById("Cont").setAttribute("height", "95");

	contdoc = doc.getElementById("Cont").contentDocument;

	var srefIxMsdcVLocale = retrieveFeedSrefByNum(srcdoc, "FeedFPupLoginLocale.enus", parseInt(retrieveCi(srcdoc, "Cont", "numFPupLoginLocale")));

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "Tag." + srefIxMsdcVLocale, "CptFailure"));
	initCpt(contdoc, "CptMessage", retrieveTi(srcdoc, "Tag." + srefIxMsdcVLocale, "CptFailureMessage"));
	initBut(contdoc, "ButBack", retrieveTi(srcdoc, "Tag." + srefIxMsdcVLocale, "ButFailureBack"));
};

function initLogout() {
	doc.getElementById("tdCont").setAttribute("height", "103");
	doc.getElementById("Cont").setAttribute("height", "95");

	contdoc = doc.getElementById("Cont").contentDocument;

	var srefIxMsdcVLocale = retrieveFeedSrefByNum(srcdoc, "FeedFPupLoginLocale.enus", parseInt(retrieveCi(srcdoc, "Cont", "numFPupLoginLocale")));

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "Tag." + srefIxMsdcVLocale, "CptLogout"));
	initCpt(contdoc, "CptMessage", retrieveTi(srcdoc, "Tag." + srefIxMsdcVLocale, "CptLogoutMessage"));
	initBut(contdoc, "ButLogin", retrieveTi(srcdoc, "Tag." + srefIxMsdcVLocale, "ButLogoutLogin"));
};

function refreshLogin() {
	var username = retrieveCi(srcdoc, "Cont", "TxfLoginUsername");
	var password = retrieveCi(srcdoc, "Cont", "TxfLoginPassword");

	refreshTxf(contdoc, "TxfUsername", "", username, true, false, true);
	refreshTxf(contdoc, "TxfPassword", "", password, true, false, true);

	refreshBut(contdoc, "ButReset", (username != "") || (password != ""), false);
	refreshBut(contdoc, "ButLogin", (username != "") && (password != ""), false);
};

function refreshSuccess() {
	var numFLstSuccessSuspsess = parseInt(retrieveCi(srcdoc, "Cont", "numFLstSuccessSuspsess"));

	refreshLst(contdoc.getElementById("LstSuspsess").contentWindow.document, srcdoc, 1, false, false, "FeedFEnsSps", parseInt(retrieveSi(srcdoc, "Stat", "LstSuccessSuspsessNumFirstdisp")), [numFLstSuccessSuspsess]);

	refreshBut(contdoc, "ButSuspsessResume", (numFLstSuccessSuspsess != 0), false);
};

function handleLoad() {
	doc = document;
	srcdoc = doc.getElementById("_src").contentDocument;

	if (doc.cookie) {
		var ss = doc.cookie.split(";");

		for (var i=0;i<ss.length;i++) {
			if (ss[i].search("srefIxMsdcVLocale=") == 0) {
				var numFPupLoginLocale = retrieveFeedNumBySref(srcdoc, "FeedFPupLoginLocale.enus", ss[i].substr(18));
				if (!isNaN(numFPupLoginLocale)) setCi(srcdoc, "Cont", "numFPupLoginLocale", "" + numFPupLoginLocale);
				break;
			};
		};
	};

	// determine panel to display from URL
	doc.pnlshort = "Login";
	if (window.location.search.indexOf("do=") != -1) {
		doc.pnlshort = window.location.search.substr(window.location.search.indexOf("do=")+3);
		if ( (doc.pnlshort != "Success") && (doc.pnlshort != "Failure") && (doc.pnlshort != "Logout") ) doc.pnlshort = "Login";
	};

	setCont();
};

function setCont() {
	var resnode;

	if (doc.pnlshort == "Login") {
		setCi(srcdoc, "Cont", "numFLstSuccessSuspsess", "0");
		setCi(srcdoc, "Cont", "TxfLoginUsername", "");
		setCi(srcdoc, "Cont", "TxfLoginPassword", "");

		setSi(srcdoc, "Stat", "LstSuccessSuspsessNumFirstdisp", "1");

		resnode = getNode(srcdoc, "//msdc:src/msdc:FeedFEnsSps");
		if (resnode) clearElem(resnode);

		resnode = getNode(srcdoc, "//msdc:src/msdc:FeedFEnsSec");
		if (resnode) clearElem(resnode);
	};

	doc.getElementById("Cont").src = "./PnlMsdcStart" + doc.pnlshort + ".xml";
};

function setLocale() {
	// store locale to cookie
	var expdate = new Date();
	var exptime = expdate.getTime() + (30*24*3600*1000);
	expdate.setTime(exptime);

	var srefIxMsdcVLocale = retrieveFeedSrefByNum(srcdoc, "FeedFPupLoginLocale.enus", parseInt(retrieveCi(srcdoc, "Cont", "numFPupLoginLocale")));

	doc.cookie = "srefIxMsdcVLocale=" + srefIxMsdcVLocale + ";expires=" + expdate.toGMTString();
};

// control handlers for Login
function handlePupLoginLocaleChange() {
	setCi(srcdoc, "Cont", "numFPupLoginLocale", "" + contdoc.getElementById("PupLocale").value);

	setLocale();

	initLogin();
};

function handleTxfLoginUsernameKey(evt) {
	return true;
};

function handleTxfLoginUsernameChange() {
	setCi(srcdoc, "Cont", "TxfLoginUsername", contdoc.getElementById("TxfUsername").value);
	refreshLogin();
};

function handleTxfLoginPasswordKey(evt) {
	if (evt.keyCode == 13) {
		setCi(srcdoc, "Cont", "TxfLoginPassword", contdoc.getElementById("TxfPassword").value);
		handleButLoginLoginClick();

		return false;
	};

	return true;
};

function handleTxfLoginPasswordChange() {
	setCi(srcdoc, "Cont", "TxfLoginPassword", contdoc.getElementById("TxfPassword").value);
	refreshLogin();
};

function handleButLoginResetClick() {
	setCi(srcdoc, "Cont", "TxfLoginUsername", "");
	setCi(srcdoc, "Cont", "TxfLoginPassword", "");

	refreshLogin();
};

function handleButLoginLoginClick() {
	var str = serializeDpchAppLogin(true);
	sendReq(str, doc, handleDpchAppLoginReply);
};

// control handlers for Success
function setLsbSuccessSuspsessPos(lstdoc, pos) {
	var vpos = (16 + Math.round(pos * (90-2*16)));

	lstdoc.getElementById("LsbJpupr").setAttribute("height", "" + (vpos-10));
	lstdoc.getElementById("LsbJpupl").setAttribute("y2", "" + vpos);

	lstdoc.getElementById("LsbJpdownr").setAttribute("y", "" + vpos);
	lstdoc.getElementById("LsbJpdownr").setAttribute("height", "" + (90-vpos-10));
	lstdoc.getElementById("LsbJpdownl").setAttribute("y1", "" + vpos);

	lstdoc.getElementById("Lsb").setAttribute("transform", "translate(0 " + vpos + ")");
};

function handleLstSuccessSuspsessLoad(lstdoc) {
	refreshLst(lstdoc, srcdoc, 1, false, false, "FeedFEnsSps", parseInt(retrieveSi(srcdoc, "Stat", "LstSuccessSuspsessNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "Cont", "numFLstSuccessSuspsess"))]);
};

function handleLstSuccessSuspsessSelect(num) {
	var found, oldNumFLst, numsFLst, oldNumsFLst;

	oldNumFLst = parseInt(retrieveCi(srcdoc, "Cont", "numFLstSuccessSuspsess"));
	if (num == oldNumFLst) num = 0;

	setCi(srcdoc, "Cont", "numFLstSuccessSuspsess", num);

	refreshSuccess();
};

function changeLstSuccessSuspsessNumFirstdisp(lstdoc, numFirstdisp, dNumFirstdisp) {
	var oldNumFirstdisp = parseInt(retrieveSi(srcdoc, "Stat", "LstSuccessSuspsessNumFirstdisp"));
	if (dNumFirstdisp != 0) numFirstdisp = oldNumFirstdisp + dNumFirstdisp;

	var cnt = getFeedSize(srcdoc, "FeedFEnsSps");

	if (numFirstdisp > (cnt-5+1)) numFirstdisp = cnt-5+1;
	if (numFirstdisp < 1) numFirstdisp = 1;

	if (numFirstdisp != oldNumFirstdisp) {
		setSi(srcdoc, "Stat", "LstSuccessSuspsessNumFirstdisp", "" + numFirstdisp);

		refreshLst(lstdoc, srcdoc, 1, false, false, "FeedFEnsSps", parseInt(retrieveSi(srcdoc, "Stat", "LstSuccessSuspsessNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "Cont", "numFLstSuccessSuspsess"))]);
	};
};

function handleLsbSuccessSuspsessUpClick(lstdoc) {
	changeLstSuccessSuspsessNumFirstdisp(lstdoc, 0, -1);
};

function handleLsbSuccessSuspsessJpupClick(lstdoc) {
	changeLstSuccessSuspsessNumFirstdisp(lstdoc, 0, -4);
};

function handleLsbSuccessSuspsessJpdownClick(lstdoc) {
	changeLstSuccessSuspsessNumFirstdisp(lstdoc, 0, 4);
};

function handleLsbSuccessSuspsessDownClick(lstdoc) {
	changeLstSuccessSuspsessNumFirstdisp(lstdoc, 0, 1);
};

function handleLsbSuccessSuspsessMdn(lstdoc) {
	lstdoc.getElementById("tdLsb").onmousemove = contdoc.getElementById("LstSuspsess").contentWindow.handleLsbMove;
	lstdoc.getElementById("tdLsb").onmouseup = contdoc.getElementById("LstSuspsess").contentWindow.handleLsbMup;
};

function handleLsbSuccessSuspsessMove(lstdoc, evt) {
	if ((evt.clientY >= 16) && (evt.clientY <= (90-16))) {
		var pos = (evt.clientY-16)/(90-2*16);
		setLsbSuccessSuspsessPos(lstdoc, pos);
	};
};

function handleLsbSuccessSuspsessMup(lstdoc, evt) {
	lstdoc.getElementById("tdLsb").removeAttribute("onmousemove");
	lstdoc.getElementById("tdLsb").removeAttribute("onmouseup");

	var cnt = getFeedSize(srcdoc, "FeedFEnsSps");

	var pos = (evt.clientY-16)/(90-2*16);
	changeLstSuccessSuspsessNumFirstdisp(lstdoc, Math.round(pos*(cnt-5))+1, 0);
};

function handleButSuccessSuspsessResumeClick() {
	var scrJref = retrieveFeedSrefByNum(srcdoc, "FeedFEnsSps", parseInt(retrieveCi(srcdoc, "Cont", "numFLstSuccessSuspsess")));

	var str = serializeDpchApp("DpchAppMsdcInit", scrJref);
	sendReq(str, doc, handleDpchAppInitReply);
};

function handleButSuccessBackClick() {
	doc.pnlshort = "Login";
	setCont();
};

function handleButSuccessNewsessClick() {
	var str = serializeDpchAppLogin(false);
	sendReq(str, doc, handleDpchAppLoginReply);
};

// control handlers for Failure
function handleButFailureBackClick() {
	doc.pnlshort = "Login";
	setCont();
};

// control handlers for Logout
function handleButLogoutLoginClick() {
	doc.pnlshort = "Login";
	setCont();
};

// server interaction
function serializeDpchAppLogin(chksuspsess) {
	var dpch, elem, txt;
	var ser;
	var str;

	dpch = doc.createElement("DpchAppRootMsdcLogin");

	elem = doc.createElement("username");
	txt = doc.createTextNode(retrieveCi(srcdoc, "Cont", "TxfLoginUsername"));
	elem.appendChild(txt);
	dpch.appendChild(elem);

	elem = doc.createElement("password");
	txt = doc.createTextNode(retrieveCi(srcdoc, "Cont", "TxfLoginPassword"));
	elem.appendChild(txt);
	dpch.appendChild(elem);

	elem = doc.createElement("chksuspsess");
	if (chksuspsess) txt = doc.createTextNode("true");
	else txt = doc.createTextNode("false");
	elem.appendChild(txt);
	dpch.appendChild(elem);	

	ser = new XMLSerializer();

	str = ser.serializeToString(dpch);

	return(str);
};

function handleDpchAppLoginReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//msdc:*");

		if (blk) {
			if (blk.nodeName == "DpchEngMsdcConfirm") {
				var accepted = retrieveValue(dom, "//msdc:DpchEngMsdcConfirm/msdc:accepted");
				if (accepted == "true") {
					var scrJref = retrieveValue(dom, "//msdc:DpchEngMsdcConfirm/msdc:scrJref");

					var str = serializeDpchApp("DpchAppMsdcInit", scrJref);
					sendReq(str, doc, handleDpchAppInitReply);

				} else {
					doc.pnlshort = "Failure";
					setCont();
				};

			} else if (blk.nodeName == "DpchEngRootMsdcData") {
				// chksuspsess = true and login accepted, suspended sessions exist
				updateSrcblock(dom, "DpchEngRootMsdcData", "FeedFEnsSps", srcdoc);

				doc.pnlshort = "Success";
				setCont();
			};
		};
	};
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//msdc:*");
		if (blk) {
			if (blk.nodeName == "DpchEngSessMsdcData") {
				var scrJrefCrdnav = retrieveValue(dom, "//msdc:DpchEngSessMsdcData/msdc:StatShrSessMsdc/msdc:Si[@sref='scrJrefCrdnav']");

				if (scrJrefCrdnav == "") {
					doc.pnlshort = "Failure";
					setCont();

				} else {
					if (updateSrcblock(dom, "DpchEngSessMsdcData", "FeedFEnsSec", srcdoc)) {
						// additional cards may be present for resumed sessions
						var cnt = getFeedSize(srcdoc, "FeedFEnsSec");
						var sref, scrJref;

						for (var i=1;i<=cnt;i++) {
							sref = retrieveFeedTitleByNumI(srcdoc, "FeedFEnsSec", i, 1);
							scrJref = retrieveFeedSrefByNum(srcdoc, "FeedFEnsSec", i);

							window.open("/web/" + sref + "/" + sref + ".html?scrJref=" + scrJref, "_blank");
						};
					};

					window.open("/web/CrdMsdcNav/CrdMsdcNav.html?scrJref=" + scrJrefCrdnav, "_parent");
				};
			};
		};
	};
};

