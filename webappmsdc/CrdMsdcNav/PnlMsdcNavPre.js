/**
  * \file PnlMsdcNavPre.js
  * web client functionality for panel PnlMsdcNavPre
  * \author Alexander Wirthmueller
  * \date created: 15 Aug 2018
  * \date modified: 15 Aug 2018
  */

// --- expand state management
function minimize() {
};

function regularize() {
};

// --- view initialization and refresh
function init() {
	if (!doc) return;

	contdoc = doc.getElementById("Pre_cont").contentDocument;

// IP init --- INSERT

	refresh();
};

function refresh() {
	var line;

	var n = 0;

	var TxtDatAvail = (retrieveSi(srcdoc, "StatShrMsdcNavPre", "TxtDatAvail") == "true"); if (TxtDatAvail) n++;
	var TxtPrdAvail = (retrieveSi(srcdoc, "StatShrMsdcNavPre", "TxtPrdAvail") == "true"); if (TxtPrdAvail) n++;

	line = contdoc.getElementById("line");
	while (line.firstChild) line.removeChild(line.firstChild);

	var i = 0;

	if (TxtDatAvail) {
		i++;

		line.appendChild(makeImgBut("ButDatRemove", "icon/close"));
		if (i == n) line.appendChild(makeSpanCpt("\u00a0" + retrieveTi(srcdoc,  "TagMsdcNavPre", "CptDat") + ": " + retrieveCi(srcdoc, "ContInfMsdcNavPre", "TxtDat")));
		else line.appendChild(makeSpanCpt("\u00a0" + retrieveTi(srcdoc, "TagMsdcNavPre", "CptDat") + ": " + retrieveCi(srcdoc, "ContInfMsdcNavPre", "TxtDat") + ",\u00a0\u00a0"));
	};

	if (TxtPrdAvail) {
		i++;

		line.appendChild(makeImgBut("ButPrdRemove", "icon/close"));
		if (i == n) line.appendChild(makeSpanCpt("\u00a0" + retrieveTi(srcdoc,  "TagMsdcNavPre", "CptPrd") + ": " + retrieveCi(srcdoc, "ContInfMsdcNavPre", "TxtPrd")));
		else line.appendChild(makeSpanCpt("\u00a0" + retrieveTi(srcdoc, "TagMsdcNavPre", "CptPrd") + ": " + retrieveCi(srcdoc, "ContInfMsdcNavPre", "TxtPrd") + ",\u00a0\u00a0"));
	};

};

// --- event handlers
function handleLoad() {
	scrJref = location.search.substr(location.search.indexOf("scrJref=")+8);

	doc = document;
	srcdoc = doc.getElementById("Pre_src").contentDocument;

	var str = serializeDpchApp("DpchAppMsdcInit", scrJref);
	sendReq(str, doc, handleDpchAppInitReply, true);
};

function handleButClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppMsdcNavPreDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngMsdcNavPreData", "ContInfMsdcNavPre", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngMsdcNavPreData", "StatShrMsdcNavPre", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngMsdcNavPreData", "TagMsdcNavPre", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngMsdcNavPreData") {
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
			if (blk.nodeName == "DpchEngMsdcNavPreData") {
				mergeDpchEngData(dom);
				init();

				getCrdwnd().setInitdone("Pre");
			};
		};
	};
};

function handleDpchAppDoReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		// check dispatch type
		blk = retrieveBlock(dom, "//msdc:*");

		if (blk) {
			if (blk.nodeName == "DpchEngMsdcConfirm") {
				// do nothing

			} else if (blk.nodeName == "DpchEngMsdcNavPreData") {
				mergeDpchEngData(dom);
				refresh();
			};
		};
	};
};

