/**
  * \file PnlMsdcNavHeadbar.js
  * web client functionality for panel PnlMsdcNavHeadbar
  * \author Alexander Wirthmueller
  * \date created: 29 Aug 2018
  * \date modified: 29 Aug 2018
  */

// --- view initialization
function init() {
	contdoc = doc.getElementById("Headbar_cont").contentDocument;

	var width = 995;

	var appw = parseInt(retrieveSi(srcdoc, "StgInfMsdcNavHeadbar", "MenAppCptwidth"));
	contdoc.getElementById("colMenApp").setAttribute("width", "" + appw);
	width -= appw+1;

	var sesw = parseInt(retrieveSi(srcdoc, "StgInfMsdcNavHeadbar", "MenSesCptwidth"));
	contdoc.getElementById("colMenSes").setAttribute("width", "" + sesw);
	width -= sesw+1;

	var crdw = parseInt(retrieveSi(srcdoc, "StgInfMsdcNavHeadbar", "MenCrdCptwidth"));
	contdoc.getElementById("colMenCrd").setAttribute("width", "" + crdw);
	width -= crdw+1;

	contdoc.getElementById("colFill").setAttribute("width", "" + width);

	var MenCrdAvail = (retrieveSi(srcdoc, "StatShrMsdcNavHeadbar", "MenCrdAvail") == "true");
	if (!MenCrdAvail) contdoc.getElementById("tdMenCrd").setAttribute("class", "hide");

	// captions
	setTextContent(contdoc, contdoc.getElementById("MenApp"), retrieveTi(srcdoc, "TagMsdcNavHeadbar", "MenApp") + "\\u00a0");
	setTextContent(contdoc, contdoc.getElementById("MenSes"), "\\u00a0" + retrieveTi(srcdoc, "TagMsdcNavHeadbar", "MenSes") + "\\u00a0");
	setTextContent(contdoc, contdoc.getElementById("MenCrd"), "\\u00a0" + retrieveTi(srcdoc, "TagMsdcNavHeadbar", "MenCrd") + "\\u00a0");
};

// --- event handlers
function handleLoad() {
	scrJref = location.search.substr(location.search.indexOf("scrJref=")+8);

	doc = document;
	srcdoc = doc.getElementById("Headbar_src").contentDocument;

	var str = serializeDpchApp("DpchAppMsdcInit", scrJref);
	sendReq(str, doc, handleDpchAppInitReply, true);
};

function handleMenAppClick() {
	var width;
	width = parseInt(retrieveSi(srcdoc, "StgInfMsdcNavHeadbar", "MenAppWidth"));

	getCrdwnd().toggleMenu("App", 3, width, 63);
};

function handleMenSesClick() {
	var appw;
	var width;

	appw = parseInt(retrieveSi(srcdoc, "StgInfMsdcNavHeadbar", "MenAppCptwidth"));
	width = parseInt(retrieveSi(srcdoc, "StgInfMsdcNavHeadbar", "MenSesWidth"));

	getCrdwnd().toggleMenu("Ses", 3+appw+1, width, 103);
};

function handleMenCrdClick() {
	var appw, sesw;
	var width;

	appw = parseInt(retrieveSi(srcdoc, "StgInfMsdcNavHeadbar", "MenAppCptwidth"));
	sesw = parseInt(retrieveSi(srcdoc, "StgInfMsdcNavHeadbar", "MenSesCptwidth"));
	width = parseInt(retrieveSi(srcdoc, "StgInfMsdcNavHeadbar", "MenCrdWidth"));

	getCrdwnd().toggleMenu("Crd", 3+appw+1+sesw+1, width, 163);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngMsdcNavHeadbarData", "StatShrMsdcNavHeadbar", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngMsdcNavHeadbarData", "StgInfMsdcNavHeadbar", srcdoc)) mask.push("stginf");
	if (updateSrcblock(dom, "DpchEngMsdcNavHeadbarData", "TagMsdcNavHeadbar", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//msdc:*");
		if (blk) {
			if (blk.nodeName == "DpchEngMsdcNavHeadbarData") {
				mergeDpchEngData(dom);
				init();

				getCrdwnd().setInitdone("Headbar");
			};
		};
	};
};

