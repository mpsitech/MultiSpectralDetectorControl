// IP file --- KEEP
/**
  * \file PnlMsdcLivVideo.js
  * web client functionality for panel PnlMsdcLivVideo
  * \author Alexander Wirthmueller
  * \date created: 8 May 2018
  * \date modified: 8 May 2018
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

		mult = Math.round(Math.sqrt((w*h) / doc.gray.length));

		var dv = new DataView(doc.gray.buffer);

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
	if (retrieveSi(srcdoc, "StatAppMsdcLivVideo", "srefIxMsdcVExpstate") == "mind") return;

	setSi(srcdoc, "StatAppMsdcLivVideo", "srefIxMsdcVExpstate", "mind");

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
	if (retrieveSi(srcdoc, "StatAppMsdcLivVideo", "srefIxMsdcVExpstate") == "regd") return;

	setSi(srcdoc, "StatAppMsdcLivVideo", "srefIxMsdcVExpstate", "regd");

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
	refreshPup(contcontdoc, srcdoc, "PupRes", "", "FeedFPupRes", retrieveCi(srcdoc, "ContIacMsdcLivVideo", "numFPupRes"), true, false);

	doc.imgdat = contcontdoc.getElementById("cvs").getContext("2d").createImageData(640, 480);
	// IP initBD --- REND

	refreshBD(bNotD);
};

function init() {
	var srefIxMsdcVExpstate = retrieveSi(srcdoc, "StatAppMsdcLivVideo", "srefIxMsdcVExpstate");

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
	var height = 515; // full cont height

	// IP refreshBD.vars --- BEGIN

	// IP refreshBD.vars --- END

	// IP refreshBD --- BEGIN
	refreshButicon(hdrdoc, "ButMaster", "icon/master", true, retrieveCi(srcdoc, "ContInfMsdcLivVideo", "ButMasterOn") == "true");
	contcontdoc.getElementById("PupSrc").value = retrieveCi(srcdoc, "ContIacMsdcLivVideo", "numFPupSrc");

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
	var srefIxMsdcVExpstate = retrieveSi(srcdoc, "StatAppMsdcLivVideo", "srefIxMsdcVExpstate");

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

function handleButRegularizeClick() {
	regularize(true);
};

function handleButMinimizeClick() {
	minimize(true);
};

// --- generalized event handlers for app controls

// --- generalized event handlers for shared controls

function handleButClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppMsdcLivVideoDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handlePupChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "pup" + size + "mod");
	setCi(srcdoc, "ContIacMsdcLivVideo", "numF" + ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppMsdcLivVideoData", scrJref, "ContIacMsdcLivVideo");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngMsdcLivVideoData", "ContIacMsdcLivVideo", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngMsdcLivVideoData", "ContInfMsdcLivVideo", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngMsdcLivVideoData", "FeedFPupSrc", srcdoc)) mask.push("feedFPupSrc");
	if (updateSrcblock(dom, "DpchEngMsdcLivVideoData", "StatAppMsdcLivVideo", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngMsdcLivVideoData", "TagMsdcLivVideo", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngMsdcLivVideoData") {
		mergeDpchEngData(dom);
		refresh();
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

	var srefIxMsdcVExpstate = retrieveSi(srcdoc, "StatAppMsdcLivVideo", "srefIxMsdcVExpstate");
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
				mergeDpchEngData(dom);
				refresh();
			};
		};
	};
};

