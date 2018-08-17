/**
  * \file DlgMsdcFilDownload.js
  * web client functionality for dialog DlgMsdcFilDownload
  * \author Alexander Wirthmueller
  * \date created: 15 Aug 2018
  * \date modified: 15 Aug 2018
  */

// IP cust --- INSERT

// --- view initialization and refresh
function init() {
	hdrdoc = doc.getElementById("_hdr").contentDocument;
	contdoc = doc.getElementById("_cont").contentDocument;
	ftrdoc = doc.getElementById("_ftr").contentDocument;

	setTextContent(hdrdoc, hdrdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagDlgMsdcFilDownload", "Cpt"));

	setTextContent(contdoc, contdoc.getElementById("Dld"), retrieveTi(srcdoc, "TagDlgMsdcFilDownload", "Dld"));

	setTextContent(ftrdoc, ftrdoc.getElementById("ButDne"), retrieveTi(srcdoc, "TagDlgMsdcFilDownload", "ButDne"));

	refresh();
};

function refresh() {
	// IP refresh.vars --- BEGIN

	// IP refresh.vars --- END

	// IP refresh --- BEGIN
	refreshDld(contdoc, "Dld", scrJref, retrieveCi(srcdoc, "ContInfDlgMsdcFilDownload", "Dld"), true);

	// IP refresh --- END
};

// --- event handlers
function handleLoad() {
	scrJref = location.search.substr(location.search.indexOf("scrJref=")+8);

	doc = document;
	srcdoc = doc.getElementById("_src").contentDocument;

	var str = serializeDpchApp("DpchAppMsdcInit", scrJref);
	sendReq(str, doc, handleDpchAppInitReply, true);
};

// --- specific event handlers for app controls

// --- generalized event handlers for app controls

// --- generalized event handlers for shared controls

function handleButClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppDlgMsdcFilDownloadDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngDlgMsdcFilDownloadData", "ContInfDlgMsdcFilDownload", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngDlgMsdcFilDownloadData", "StatAppDlgMsdcFilDownload", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngDlgMsdcFilDownloadData", "TagDlgMsdcFilDownload", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngDlgMsdcFilDownloadData") {
		mergeDpchEngData(dom);
		refresh();
	} else if (dpch == "DpchEngDlgMsdcFilDownloadData") {
		handleDpchEngDlgMsdcFilDownloadData(dom);
	};
};

function handleDpchEngDlgMsdcFilDownloadData(dom) {
	// IP handleDpchEngDlgMsdcFilDownloadData --- INSERT
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//msdc:*");
		if (blk) {
			if (blk.nodeName == "DpchEngDlgMsdcFilDownloadData") {
				mergeDpchEngData(dom);
				init();
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

			} else if (blk.nodeName == "DpchEngMsdcAlert") {
				getCrdwnd().showAlr(retrieveValue(dom, "//msdc:DpchEngMsdcAlert/msdc:scrJref"),
							retrieveBlock(dom, "//msdc:DpchEngMsdcAlert/msdc:ContInfMsdcAlert"),
							retrieveBlock(dom, "//msdc:DpchEngMsdcAlert/msdc:FeedFMcbAlert"));;

			} else if (blk.nodeName == "DpchEngDlgMsdcFilDownloadData") {
				mergeDpchEngData(dom);
				refresh();
			};
		};
	};
};

