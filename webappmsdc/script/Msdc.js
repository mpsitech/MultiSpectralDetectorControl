/**
  * \file Msdc.js
  * web client global functionality for Msdc
  * \author Alexander Wirthmueller
  * \date created: 29 Aug 2018
  * \date modified: 29 Aug 2018
  */

MSDC_VERSION = "0.1.49";
MSDC_VERSION_MAJOR = 0;
MSDC_VERSION_MINOR = 1;
MSDC_VERSION_SUB = 49;

function getCrdwnd() {
	if (window.name == "Crd") return window;
	if (parent.window.name == "Crd") return parent.window;
	if (parent.parent.window.name == "Crd") return parent.parent.window;
	if (parent.parent.parent.window.name == "Crd") return parent.parent.parent.window;
	if (parent.parent.parent.parent.window.name == "Crd") return parent.parent.parent.parent.window;
	if (parent.parent.parent.parent.parent.parent.window.name == "Crd") return parent.parent.parent.parent.parent.parent.window;
};

function getRecwnd() {
	if (window.name == "Rec") return window;
	if (parent.window.name == "Rec") return parent.window;
	if (parent.parent.window.name == "Rec") return parent.parent.window;
	if (parent.parent.parent.window.name == "Rec") return parent.parent.parent.window;
	if (parent.parent.parent.parent.window.name == "Rec") return parent.parent.parent.parent.window;
};

function getDlgwnd() {
	if (window.name == "Dlg") return window;
	if (parent.window.name == "Dlg") return parent.window;
	if (parent.parent.window.name == "Dlg") return parent.parent.window;
	if (parent.parent.parent.window.name == "Dlg") return parent.parent.parent.window;
};

function serializeDpchApp(sref, scrJref) {
	var dpch, elem, txt;
	var ser;
	var str;

	dpch = document.createElement(sref);
	elem = document.createElement("scrJref");
	txt = document.createTextNode(scrJref);
	elem.appendChild(txt);
	dpch.appendChild(elem);

	ser = new XMLSerializer();

	str = ser.serializeToString(dpch);

	return(str);
};

function serializeDpchAppAlert(scrJref, numFMcb) {
	var elem, txt;
	var ser;
	var str;

	dpch = doc.createElement("DpchAppMsdcAlert");

	elem = doc.createElement("scrJref");
	txt = doc.createTextNode(scrJref);
	elem.appendChild(txt);
	dpch.appendChild(elem);

	elem = doc.createElement("numFMcb");
	txt = doc.createTextNode("" + numFMcb);
	elem.appendChild(txt);
	dpch.appendChild(elem);

	ser = new XMLSerializer();

	str = ser.serializeToString(dpch);

	return(str);
};

function serializeDpchAppData(srcdoc, sref, scrJref, blk) {
	var dpch, elem, txt;
	var ser;
	var str;

	dpch = document.createElement(sref);
	elem = document.createElement("scrJref");
	txt = document.createTextNode(scrJref);
	elem.appendChild(txt);
	dpch.appendChild(elem);

	elem = retrieveBlock(srcdoc, "//msdc:" + blk);
	if (elem) {
		elem = elem.cloneNode(true);
		dpch.appendChild(elem);
	};

	ser = new XMLSerializer();

	str = ser.serializeToString(dpch);

	return(str);
};

function serializeDpchAppDo(srcdoc, sref, scrJref, srefIxVDo) {
	var dpch, elem, txt;
	var ser;
	var str;
	dpch = document.createElement(sref);

	elem = document.createElement("scrJref");
	txt = document.createTextNode(scrJref);
	elem.appendChild(txt);
	dpch.appendChild(elem);

	elem = document.createElement("srefIxVDo");
	txt = document.createTextNode(srefIxVDo);
	elem.appendChild(txt);
	dpch.appendChild(elem);

	ser = new XMLSerializer();

	str = ser.serializeToString(dpch);

	return(str);
};

function serializeDpchAppDoDlg(srcdoc, sref, scrJref, shortDit, srefIxVDo) {
	var dpch, elem, txt;
	var ser;
	var str;
	dpch = document.createElement(sref);

	elem = document.createElement("scrJref");
	txt = document.createTextNode(scrJref);
	elem.appendChild(txt);
	dpch.appendChild(elem);

	elem = document.createElement("srefIxVDo" + shortDit);
	txt = document.createTextNode(srefIxVDo);
	elem.appendChild(txt);
	dpch.appendChild(elem);

	ser = new XMLSerializer();

	str = ser.serializeToString(dpch);

	return(str);
};

function sendReq(str, doc, callback, async) {
	str = "xml=" + str;

	if (!doc.req) doc.req = new XMLHttpRequest();
	doc.req.open("POST", "/dpch", (async == true));
	doc.req.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
//	doc.req.setRequestHeader("Content-length", str.length);
//	doc.req.setRequestHeader("Connection", "close");

	doc.req.onreadystatechange = callback;
	doc.req.send(str);
};

function getNode(srcdoc, xp) {
	var res, resnode;

	res = srcdoc.evaluate(xp, srcdoc, nsResolver, XPathResult.ANY_TYPE, null);
	if (res) {
		resnode = res.iterateNext();
		return resnode;
	} else {
		return false;
	};
};

function retrieveBlock(srcdoc, xp) {
	return getNode(srcdoc, xp);
};

function retrieveValue(srcdoc, xp) {
	var resnode;

	resnode = getNode(srcdoc, xp);

	if (resnode) return resnode.textContent;
	else return "";
};

function retrieveSi(srcdoc, blk, tag) {
	return(retrieveValue(srcdoc, "//msdc:" + blk + "/msdc:Si[@sref='" + tag + "']"));
};

function retrieveTi(srcdoc, blk, tag) {
	return(retrieveValue(srcdoc, "//msdc:" + blk + "/msdc:Ti[@sref='" + tag + "']"));
};

function retrieveCi(srcdoc, blk, tag) {
	return(retrieveValue(srcdoc, "//msdc:" + blk + "/msdc:Ci[@sref='" + tag + "']"));
};

function setSi(srcdoc, blk, tag, val) {
	var resnode;
	var txt;

	resnode = getNode(srcdoc, "//msdc:" + blk + "/msdc:Si[@sref='" + tag + "']");
	if (resnode) {
		txt = srcdoc.createTextNode(val);

		if (resnode.firstChild) resnode.replaceChild(txt, resnode.firstChild);
		else resnode.appendChild(txt);
	};
};

function setCi(srcdoc, blk, tag, val) {
	var resnode;
	var txt;

	resnode = getNode(srcdoc, "//msdc:" + blk + "/msdc:Ci[@sref='" + tag + "']");
	if (resnode) {
		txt = srcdoc.createTextNode(val);

		if (resnode.firstChild) resnode.replaceChild(txt, resnode.firstChild);
		else resnode.appendChild(txt);
	};
};

function replaceSrcblock(blk, blksref, srcdoc) {
	var blkold;
	var resnode;

	if (blk) {
		resnode = getNode(srcdoc, "//msdc:src");

		blkold = getNode(srcdoc, "//msdc:" + blksref);

		if (blkold) resnode.replaceChild(srcdoc.importNode(blk, true), blkold);
		else resnode.appendChild(srcdoc.importNode(blk, true));

		return true;
	} else {
		return false;
	};
};

function updateSrcblock(dpchdom, dpchsref, blksref, srcdoc) {
	var blk;

	blk = getNode(dpchdom, "//msdc:" + dpchsref + "/msdc:" + blksref);

	if (blk) return replaceSrcblock(blk, blksref, srcdoc);
	else return false;
};

function removeSrcblock(blksref, srcdoc) {
	var blkold;
	var resnode;

	resnode = getNode(srcdoc, "//msdc:src");

	blkold = getNode(srcdoc, "//msdc:" + blksref);

	if (blkold) resnode.removeChild(blkold);
};

function nsResolver(prefix) {
	return "http://www.mpsitech.com/msdc";
};

function getFeedSize(srcdoc, blk) {
	return(srcdoc.evaluate("count(//msdc:" + blk + "/msdc:Fi)", srcdoc, nsResolver, XPathResult.NUMBER_TYPE, null).numberValue);
};

function retrieveFeedNumBySref(srcdoc, blk, sref) {
	return(parseInt(retrieveValue(srcdoc, "//msdc:" + blk + "/msdc:Fi[msdc:sref='" + sref + "']/@num")));
};

function retrieveFeedSelByNum(srcdoc, blk, num) {
	return(retrieveValue(srcdoc, "//msdc:" + blk + "/msdc:Fi[@num='" + num + "']/msdc:sel") == "true");
};

function retrieveFeedSrefByNum(srcdoc, blk, num) {
	return(retrieveValue(srcdoc, "//msdc:" + blk + "/msdc:Fi[@num='" + num + "']/msdc:sref"));
};

function retrieveFeedTitleByNumI(srcdoc, blk, num, i) {
	if (i) {
		if (i == 2) return(retrieveValue(srcdoc, "//msdc:" + blk + "/msdc:Fi[@num='" + num + "']/msdc:tit2"));
		else if (i == 3) return(retrieveValue(srcdoc, "//msdc:" + blk + "/msdc:Fi[@num='" + num + "']/msdc:tit3"));
	};
	return(retrieveValue(srcdoc, "//msdc:" + blk + "/msdc:Fi[@num='" + num + "']/msdc:tit1"));
};

function retrieveFiSub(srcdoc, finode, sref) {
	var res, resnode;

	if (sref == "num") res = srcdoc.evaluate("@num", finode, nsResolver, XPathResult.ANY_TYPE, null);
	else res = srcdoc.evaluate("msdc:" + sref, finode, nsResolver, XPathResult.ANY_TYPE, null);

	resnode = res.iterateNext();

	if (resnode) return resnode.textContent;
	else return "";
};

function getRownode(srcdoc, blk, jnum) {
	return(getNode(srcdoc, "//msdc:" + blk + "/msdc:row[@jnum='" + jnum + "']"));
};

function retrieveRowField(srcdoc, rownode, sref) {
	var res, resnode;

	res = srcdoc.evaluate("msdc:" + sref, rownode, nsResolver, XPathResult.ANY_TYPE, null);
	resnode = res.iterateNext();

	if (resnode) return resnode.textContent;
	else return "";
};

function clearElem(elem) {
	while (elem.firstChild) elem.removeChild(elem.firstChild);
};

function replaceUesc(str) {
	var str2 = str;
	var ss = str.split("\\u");

	if (ss.length > 0) {
		str2 = ss[0];

		for (var i=1;i<ss.length;i++)
					if (ss[i].length >= 4)
								str2 = str2 + String.fromCharCode(256*parseInt(ss[i].substr(0,2), 16) + parseInt(ss[i].substr(2,2), 16)) + ss[i].substr(4);
	};

	return str2;
};

function setTextContent(contdoc, elem, text) {
	clearElem(elem);
	elem.appendChild(contdoc.createTextNode(replaceUesc(text)));
};

