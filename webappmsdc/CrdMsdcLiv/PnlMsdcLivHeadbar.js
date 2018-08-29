/**
  * \file PnlMsdcLivHeadbar.js
  * web client functionality for panel PnlMsdcLivHeadbar
  * \author Alexander Wirthmueller
  * \date created: 29 Aug 2018
  * \date modified: 29 Aug 2018
  */

// --- view initialization
function init() {
	contdoc = doc.getElementById("Headbar_cont").contentDocument;

	var width = 995;

	var appw = parseInt(retrieveSi(srcdoc, "StgInfMsdcLivHeadbar", "MenAppCptwidth"));
	contdoc.getElementById("colMenApp").setAttribute("width", "" + appw);
	width -= appw+1;

	var crdw = parseInt(retrieveSi(srcdoc, "StgInfMsdcLivHeadbar", "MenCrdCptwidth"));
	contdoc.getElementById("colMenCrd").setAttribute("width", "" + crdw);
	width -= crdw+1;

	contdoc.getElementById("colFill").setAttribute("width", "" + width);

	// captions
	setTextContent(contdoc, contdoc.getElementById("MenApp"), retrieveTi(srcdoc, "TagMsdcLivHeadbar", "MenApp") + "\\u00a0");
	setTextContent(contdoc, contdoc.getElementById("MenCrd"), "\\u00a0" + retrieveTi(srcdoc, "TagMsdcLivHeadbar", "MenCrd") + "\\u00a0");
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
	width = parseInt(retrieveSi(srcdoc, "StgInfMsdcLivHeadbar", "MenAppWidth"));

	getCrdwnd().toggleMenu("App", 3, width, 42);
};

function handleMenCrdClick() {
	var appw;
	var width;

	appw = parseInt(retrieveSi(srcdoc, "StgInfMsdcLivHeadbar", "MenAppCptwidth"));
	width = parseInt(retrieveSi(srcdoc, "StgInfMsdcLivHeadbar", "MenCrdWidth"));

	getCrdwnd().toggleMenu("Crd", 3+appw+1, width, 0);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngMsdcLivHeadbarData", "StgInfMsdcLivHeadbar", srcdoc)) mask.push("stginf");
	if (updateSrcblock(dom, "DpchEngMsdcLivHeadbarData", "TagMsdcLivHeadbar", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//msdc:*");
		if (blk) {
			if (blk.nodeName == "DpchEngMsdcLivHeadbarData") {
				mergeDpchEngData(dom);
				init();

				getCrdwnd().setInitdone("Headbar");
			};
		};
	};
};

