/**
  * \file IexMsdcIni_blks.cpp
  * import/export handler for database DbsMsdc (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 12 Sep 2018
  * \date modified: 12 Sep 2018
  */

/******************************************************************************
 class IexMsdcIni::VecVIme
 ******************************************************************************/

uint IexMsdcIni::VecVIme::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "imeiavcontrolpar") return IMEIAVCONTROLPAR;
	if (s == "imeiavkeylistkey") return IMEIAVKEYLISTKEY;
	if (s == "imeiavvaluelistval") return IMEIAVVALUELISTVAL;
	if (s == "imeimfile") return IMEIMFILE;
	if (s == "imeimusergroup") return IMEIMUSERGROUP;
	if (s == "imeiamusergroupaccess") return IMEIAMUSERGROUPACCESS;
	if (s == "imeijavkeylistkey") return IMEIJAVKEYLISTKEY;
	if (s == "imeimuser") return IMEIMUSER;
	if (s == "imeiamuseraccess") return IMEIAMUSERACCESS;
	if (s == "imeijmuserstate") return IMEIJMUSERSTATE;
	if (s == "imeimperson") return IMEIMPERSON;
	if (s == "imeijmpersonlastname") return IMEIJMPERSONLASTNAME;

	return(0);
};

string IexMsdcIni::VecVIme::getSref(
			const uint ix
		) {
	if (ix == IMEIAVCONTROLPAR) return("ImeIAVControlPar");
	if (ix == IMEIAVKEYLISTKEY) return("ImeIAVKeylistKey");
	if (ix == IMEIAVVALUELISTVAL) return("ImeIAVValuelistVal");
	if (ix == IMEIMFILE) return("ImeIMFile");
	if (ix == IMEIMUSERGROUP) return("ImeIMUsergroup");
	if (ix == IMEIAMUSERGROUPACCESS) return("ImeIAMUsergroupAccess");
	if (ix == IMEIJAVKEYLISTKEY) return("ImeIJAVKeylistKey");
	if (ix == IMEIMUSER) return("ImeIMUser");
	if (ix == IMEIAMUSERACCESS) return("ImeIAMUserAccess");
	if (ix == IMEIJMUSERSTATE) return("ImeIJMUserState");
	if (ix == IMEIMPERSON) return("ImeIMPerson");
	if (ix == IMEIJMPERSONLASTNAME) return("ImeIJMPersonLastname");

	return("");
};

/******************************************************************************
 class IexMsdcIni::ImeitemIAVControlPar
 ******************************************************************************/

IexMsdcIni::ImeitemIAVControlPar::ImeitemIAVControlPar(
			const uint ixMsdcVControl
			, const string& Par
			, const string& Val
		) : MsdcAVControlPar() {
	lineno = 0;
	ixWIelValid = 0;

	this->ixMsdcVControl = ixMsdcVControl;
	this->Par = Par;
	this->Val = Val;
};

IexMsdcIni::ImeitemIAVControlPar::ImeitemIAVControlPar(
			DbsMsdc* dbsmsdc
			, const ubigint ref
		) :
			ImeitemIAVControlPar()
		{
	MsdcAVControlPar* rec = NULL;

	this->ref = ref;

	if (dbsmsdc->tblmsdcavcontrolpar->loadRecByRef(ref, &rec)) {
		ixMsdcVControl = rec->ixMsdcVControl;
		Par = rec->Par;
		Val = rec->Val;

		delete rec;
	};
};

bool IexMsdcIni::ImeitemIAVControlPar::readTxt(
			Txtrd& txtrd
		) {
	this->lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) ixMsdcVControl = VecMsdcVControl::getIx(txtrd.fields[0]);
	if (txtrd.fields.size() > 1) Par = txtrd.fields[1];
	if (txtrd.fields.size() > 2) Val = txtrd.fields[2];

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || txtrd.data) {
			txtrd.skip = true;
			break;

		} else {
			return false;
		};
	};

	return true;
};

void IexMsdcIni::ImeitemIAVControlPar::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	string srefIxMsdcVControl;

	ixWIelValid = 0;

	if (checkXPath(docctx, basexpath)) {
		if (extractStringUclc(docctx, basexpath, "srefIxMsdcVControl", "ctl", srefIxMsdcVControl)) {
			ixMsdcVControl = VecMsdcVControl::getIx(srefIxMsdcVControl);
			ixWIelValid += ImeIAVControlPar::VecWIel::SREFIXMSDCVCONTROL;
		};
		if (extractStringUclc(docctx, basexpath, "Par", "par", Par)) ixWIelValid += ImeIAVControlPar::VecWIel::PAR;
		if (extractStringUclc(docctx, basexpath, "Val", "val", Val)) ixWIelValid += ImeIAVControlPar::VecWIel::VAL;
	};
};

void IexMsdcIni::ImeitemIAVControlPar::writeTxt(
			fstream& outfile
		) {
	outfile << VecMsdcVControl::getSref(ixMsdcVControl) << "\t" << Par << "\t" << Val << endl;
};

void IexMsdcIni::ImeitemIAVControlPar::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","ctl","par","val"};
	else tags = {"ImeitemIAVControlPar","srefIxMsdcVControl","Par","Val"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecMsdcVControl::getSref(ixMsdcVControl));
		writeString(wr, tags[2], Par);
		writeString(wr, tags[3], Val);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexMsdcIni::ImeIAVControlPar::VecWIel
 ******************************************************************************/

uint IexMsdcIni::ImeIAVControlPar::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i=0;i<ss.size();i++) {
		if (ss[i] == "srefixmsdcvcontrol") ix |= SREFIXMSDCVCONTROL;
		else if (ss[i] == "par") ix |= PAR;
		else if (ss[i] == "val") ix |= VAL;
	};

	return(ix);
};

void IexMsdcIni::ImeIAVControlPar::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*VAL);i*=2) if (ix & i) ics.insert(i);
};

string IexMsdcIni::ImeIAVControlPar::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFIXMSDCVCONTROL) ss.push_back("srefIxMsdcVControl");
	if (ix & PAR) ss.push_back("Par");
	if (ix & VAL) ss.push_back("Val");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexMsdcIni::ImeIAVControlPar
 ******************************************************************************/

IexMsdcIni::ImeIAVControlPar::ImeIAVControlPar() {
};

IexMsdcIni::ImeIAVControlPar::~ImeIAVControlPar() {
	clear();
};

void IexMsdcIni::ImeIAVControlPar::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool IexMsdcIni::ImeIAVControlPar::readTxt(
			Txtrd& txtrd
		) {
	IexMsdcIni::ImeitemIAVControlPar* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header) {
			txtrd.skip = true;
			break;

		} else if (txtrd.data && (txtrd.il == 0)) {
			ii = new IexMsdcIni::ImeitemIAVControlPar();

			if (ii->readTxt(txtrd)) {
				nodes.push_back(ii);
			} else {
				delete ii;
				return false;
			};

		} else {
			return false;
		};
	};

	return true;
};

void IexMsdcIni::ImeIAVControlPar::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexMsdcIni::ImeitemIAVControlPar* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIAVControlPar");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIAVControlPar", "Ii", "num", nums, _shorttags);

		for (unsigned int i=0;i<nums.size();i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIAVControlPar";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexMsdcIni::ImeitemIAVControlPar();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexMsdcIni::ImeIAVControlPar::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "ImeIAVControlPar." << StrMod::replaceChar(ImeIAVControlPar::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeTxt(outfile);
	};
};

void IexMsdcIni::ImeIAVControlPar::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIAVControlPar");
			for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexMsdcIni::ImeitemIJAVKeylistKey
 ******************************************************************************/

IexMsdcIni::ImeitemIJAVKeylistKey::ImeitemIJAVKeylistKey(
			const uint x1IxMsdcVLocale
			, const string& Title
			, const string& Comment
		) : MsdcJAVKeylistKey() {
	lineno = 0;
	ixWIelValid = 0;

	this->x1IxMsdcVLocale = x1IxMsdcVLocale;
	this->Title = Title;
	this->Comment = Comment;
};

IexMsdcIni::ImeitemIJAVKeylistKey::ImeitemIJAVKeylistKey(
			DbsMsdc* dbsmsdc
			, const ubigint ref
		) :
			ImeitemIJAVKeylistKey()
		{
	MsdcJAVKeylistKey* rec = NULL;

	this->ref = ref;

	if (dbsmsdc->tblmsdcjavkeylistkey->loadRecByRef(ref, &rec)) {
		refMsdcAVKeylistKey = rec->refMsdcAVKeylistKey;
		x1IxMsdcVLocale = rec->x1IxMsdcVLocale;
		Title = rec->Title;
		Comment = rec->Comment;

		delete rec;
	};
};

bool IexMsdcIni::ImeitemIJAVKeylistKey::readTxt(
			Txtrd& txtrd
		) {
	this->lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) x1IxMsdcVLocale = VecMsdcVLocale::getIx(txtrd.fields[0]);
	if (txtrd.fields.size() > 1) Title = txtrd.fields[1];
	if (txtrd.fields.size() > 2) Comment = txtrd.fields[2];

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || txtrd.data) {
			txtrd.skip = true;
			break;

		} else {
			return false;
		};
	};

	return true;
};

void IexMsdcIni::ImeitemIJAVKeylistKey::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	string srefX1IxMsdcVLocale;

	ixWIelValid = 0;

	if (checkXPath(docctx, basexpath)) {
		if (extractStringUclc(docctx, basexpath, "srefX1IxMsdcVLocale", "lcl", srefX1IxMsdcVLocale)) {
			x1IxMsdcVLocale = VecMsdcVLocale::getIx(srefX1IxMsdcVLocale);
			ixWIelValid += ImeIJAVKeylistKey::VecWIel::SREFX1IXMSDCVLOCALE;
		};
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIJAVKeylistKey::VecWIel::TITLE;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIJAVKeylistKey::VecWIel::COMMENT;
	};
};

void IexMsdcIni::ImeitemIJAVKeylistKey::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << VecMsdcVLocale::getSref(x1IxMsdcVLocale) << "\t" << Title << "\t" << Comment << endl;
};

void IexMsdcIni::ImeitemIJAVKeylistKey::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","lcl","tit","cmt"};
	else tags = {"ImeitemIJAVKeylistKey","srefX1IxMsdcVLocale","Title","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecMsdcVLocale::getSref(x1IxMsdcVLocale));
		writeString(wr, tags[2], Title);
		writeString(wr, tags[3], Comment);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexMsdcIni::ImeIJAVKeylistKey::VecWIel
 ******************************************************************************/

uint IexMsdcIni::ImeIJAVKeylistKey::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i=0;i<ss.size();i++) {
		if (ss[i] == "srefx1ixmsdcvlocale") ix |= SREFX1IXMSDCVLOCALE;
		else if (ss[i] == "title") ix |= TITLE;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexMsdcIni::ImeIJAVKeylistKey::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*COMMENT);i*=2) if (ix & i) ics.insert(i);
};

string IexMsdcIni::ImeIJAVKeylistKey::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFX1IXMSDCVLOCALE) ss.push_back("srefX1IxMsdcVLocale");
	if (ix & TITLE) ss.push_back("Title");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexMsdcIni::ImeIJAVKeylistKey
 ******************************************************************************/

IexMsdcIni::ImeIJAVKeylistKey::ImeIJAVKeylistKey() {
};

IexMsdcIni::ImeIJAVKeylistKey::~ImeIJAVKeylistKey() {
	clear();
};

void IexMsdcIni::ImeIJAVKeylistKey::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool IexMsdcIni::ImeIJAVKeylistKey::readTxt(
			Txtrd& txtrd
		) {
	IexMsdcIni::ImeitemIJAVKeylistKey* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || (txtrd.il < 1)) {
			txtrd.skip = true;
			break;

		} else if (txtrd.data && (txtrd.il == 1)) {
			ii = new IexMsdcIni::ImeitemIJAVKeylistKey();

			if (ii->readTxt(txtrd)) {
				nodes.push_back(ii);
			} else {
				delete ii;
				return false;
			};

		} else {
			return false;
		};
	};

	return true;
};

void IexMsdcIni::ImeIJAVKeylistKey::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexMsdcIni::ImeitemIJAVKeylistKey* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIJAVKeylistKey");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIJAVKeylistKey", "Ii", "num", nums, _shorttags);

		for (unsigned int i=0;i<nums.size();i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIJAVKeylistKey";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexMsdcIni::ImeitemIJAVKeylistKey();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexMsdcIni::ImeIJAVKeylistKey::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIJAVKeylistKey." << StrMod::replaceChar(ImeIJAVKeylistKey::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeTxt(outfile);
	};
};

void IexMsdcIni::ImeIJAVKeylistKey::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIJAVKeylistKey");
			for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexMsdcIni::ImeitemIAVKeylistKey
 ******************************************************************************/

IexMsdcIni::ImeitemIAVKeylistKey::ImeitemIAVKeylistKey(
			const uint klsIxMsdcVKeylist
			, const string& sref
			, const string& Avail
			, const string& Implied
		) : MsdcAVKeylistKey() {
	lineno = 0;
	ixWIelValid = 0;

	this->klsIxMsdcVKeylist = klsIxMsdcVKeylist;
	this->sref = sref;
	this->Avail = Avail;
	this->Implied = Implied;
};

IexMsdcIni::ImeitemIAVKeylistKey::ImeitemIAVKeylistKey(
			DbsMsdc* dbsmsdc
			, const ubigint ref
		) :
			ImeitemIAVKeylistKey()
		{
	MsdcAVKeylistKey* rec = NULL;

	this->ref = ref;

	if (dbsmsdc->tblmsdcavkeylistkey->loadRecByRef(ref, &rec)) {
		klsIxMsdcVKeylist = rec->klsIxMsdcVKeylist;
		klsNum = rec->klsNum;
		x1IxMsdcVMaintable = rec->x1IxMsdcVMaintable;
		Fixed = rec->Fixed;
		sref = rec->sref;
		Avail = rec->Avail;
		Implied = rec->Implied;
		refJ = rec->refJ;

		delete rec;
	};
};

bool IexMsdcIni::ImeitemIAVKeylistKey::readTxt(
			Txtrd& txtrd
		) {
	this->lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) klsIxMsdcVKeylist = VecMsdcVKeylist::getIx(txtrd.fields[0]);
	if (txtrd.fields.size() > 1) sref = txtrd.fields[1];
	if (txtrd.fields.size() > 2) Avail = txtrd.fields[2];
	if (txtrd.fields.size() > 3) Implied = txtrd.fields[3];

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header && (txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIJAVKEYLISTKEY)) {
			if (!imeijavkeylistkey.readTxt(txtrd)) return false;

		} else if (txtrd.header || txtrd.data) {
			txtrd.skip = true;
			break;

		} else {
			return false;
		};
	};

	return true;
};

void IexMsdcIni::ImeitemIAVKeylistKey::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	string srefKlsIxMsdcVKeylist;

	ixWIelValid = 0;

	if (checkXPath(docctx, basexpath)) {
		if (extractStringUclc(docctx, basexpath, "srefKlsIxMsdcVKeylist", "kls", srefKlsIxMsdcVKeylist)) {
			klsIxMsdcVKeylist = VecMsdcVKeylist::getIx(srefKlsIxMsdcVKeylist);
			ixWIelValid += ImeIAVKeylistKey::VecWIel::SREFKLSIXMSDCVKEYLIST;
		};
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIAVKeylistKey::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "Avail", "avl", Avail)) ixWIelValid += ImeIAVKeylistKey::VecWIel::AVAIL;
		if (extractStringUclc(docctx, basexpath, "Implied", "imp", Implied)) ixWIelValid += ImeIAVKeylistKey::VecWIel::IMPLIED;
		imeijavkeylistkey.readXML(docctx, basexpath);
	};
};

void IexMsdcIni::ImeitemIAVKeylistKey::writeTxt(
			fstream& outfile
		) {
	outfile << VecMsdcVKeylist::getSref(klsIxMsdcVKeylist) << "\t" << sref << "\t" << Avail << "\t" << Implied << endl;
	imeijavkeylistkey.writeTxt(outfile);
};

void IexMsdcIni::ImeitemIAVKeylistKey::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","kls","srf","avl","imp"};
	else tags = {"ImeitemIAVKeylistKey","srefKlsIxMsdcVKeylist","sref","Avail","Implied"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecMsdcVKeylist::getSref(klsIxMsdcVKeylist));
		writeString(wr, tags[2], sref);
		writeString(wr, tags[3], Avail);
		writeString(wr, tags[4], Implied);
		imeijavkeylistkey.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexMsdcIni::ImeIAVKeylistKey::VecWIel
 ******************************************************************************/

uint IexMsdcIni::ImeIAVKeylistKey::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i=0;i<ss.size();i++) {
		if (ss[i] == "srefklsixmsdcvkeylist") ix |= SREFKLSIXMSDCVKEYLIST;
		else if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "avail") ix |= AVAIL;
		else if (ss[i] == "implied") ix |= IMPLIED;
	};

	return(ix);
};

void IexMsdcIni::ImeIAVKeylistKey::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*IMPLIED);i*=2) if (ix & i) ics.insert(i);
};

string IexMsdcIni::ImeIAVKeylistKey::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFKLSIXMSDCVKEYLIST) ss.push_back("srefKlsIxMsdcVKeylist");
	if (ix & SREF) ss.push_back("sref");
	if (ix & AVAIL) ss.push_back("Avail");
	if (ix & IMPLIED) ss.push_back("Implied");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexMsdcIni::ImeIAVKeylistKey
 ******************************************************************************/

IexMsdcIni::ImeIAVKeylistKey::ImeIAVKeylistKey() {
};

IexMsdcIni::ImeIAVKeylistKey::~ImeIAVKeylistKey() {
	clear();
};

void IexMsdcIni::ImeIAVKeylistKey::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool IexMsdcIni::ImeIAVKeylistKey::readTxt(
			Txtrd& txtrd
		) {
	IexMsdcIni::ImeitemIAVKeylistKey* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header) {
			txtrd.skip = true;
			break;

		} else if (txtrd.data && (txtrd.il == 0)) {
			ii = new IexMsdcIni::ImeitemIAVKeylistKey();

			if (ii->readTxt(txtrd)) {
				nodes.push_back(ii);
			} else {
				delete ii;
				return false;
			};

		} else {
			return false;
		};
	};

	return true;
};

void IexMsdcIni::ImeIAVKeylistKey::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexMsdcIni::ImeitemIAVKeylistKey* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIAVKeylistKey");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIAVKeylistKey", "Ii", "num", nums, _shorttags);

		for (unsigned int i=0;i<nums.size();i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIAVKeylistKey";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexMsdcIni::ImeitemIAVKeylistKey();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexMsdcIni::ImeIAVKeylistKey::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "ImeIAVKeylistKey." << StrMod::replaceChar(ImeIAVKeylistKey::VecWIel::getSrefs(15), ';', '\t') << endl;
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeTxt(outfile);
	};
};

void IexMsdcIni::ImeIAVKeylistKey::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIAVKeylistKey");
			for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexMsdcIni::ImeitemIAVValuelistVal
 ******************************************************************************/

IexMsdcIni::ImeitemIAVValuelistVal::ImeitemIAVValuelistVal(
			const uint vlsIxMsdcVValuelist
			, const uint x1IxMsdcVLocale
			, const string& Val
		) : MsdcAVValuelistVal() {
	lineno = 0;
	ixWIelValid = 0;

	this->vlsIxMsdcVValuelist = vlsIxMsdcVValuelist;
	this->x1IxMsdcVLocale = x1IxMsdcVLocale;
	this->Val = Val;
};

IexMsdcIni::ImeitemIAVValuelistVal::ImeitemIAVValuelistVal(
			DbsMsdc* dbsmsdc
			, const ubigint ref
		) :
			ImeitemIAVValuelistVal()
		{
	MsdcAVValuelistVal* rec = NULL;

	this->ref = ref;

	if (dbsmsdc->tblmsdcavvaluelistval->loadRecByRef(ref, &rec)) {
		vlsIxMsdcVValuelist = rec->vlsIxMsdcVValuelist;
		vlsNum = rec->vlsNum;
		x1IxMsdcVLocale = rec->x1IxMsdcVLocale;
		Val = rec->Val;

		delete rec;
	};
};

bool IexMsdcIni::ImeitemIAVValuelistVal::readTxt(
			Txtrd& txtrd
		) {
	this->lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) vlsIxMsdcVValuelist = VecMsdcVValuelist::getIx(txtrd.fields[0]);
	if (txtrd.fields.size() > 1) x1IxMsdcVLocale = VecMsdcVLocale::getIx(txtrd.fields[1]);
	if (txtrd.fields.size() > 2) Val = txtrd.fields[2];

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || txtrd.data) {
			txtrd.skip = true;
			break;

		} else {
			return false;
		};
	};

	return true;
};

void IexMsdcIni::ImeitemIAVValuelistVal::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	string srefVlsIxMsdcVValuelist;
	string srefX1IxMsdcVLocale;

	ixWIelValid = 0;

	if (checkXPath(docctx, basexpath)) {
		if (extractStringUclc(docctx, basexpath, "srefVlsIxMsdcVValuelist", "vls", srefVlsIxMsdcVValuelist)) {
			vlsIxMsdcVValuelist = VecMsdcVValuelist::getIx(srefVlsIxMsdcVValuelist);
			ixWIelValid += ImeIAVValuelistVal::VecWIel::SREFVLSIXMSDCVVALUELIST;
		};
		if (extractStringUclc(docctx, basexpath, "srefX1IxMsdcVLocale", "lcl", srefX1IxMsdcVLocale)) {
			x1IxMsdcVLocale = VecMsdcVLocale::getIx(srefX1IxMsdcVLocale);
			ixWIelValid += ImeIAVValuelistVal::VecWIel::SREFX1IXMSDCVLOCALE;
		};
		if (extractStringUclc(docctx, basexpath, "Val", "val", Val)) ixWIelValid += ImeIAVValuelistVal::VecWIel::VAL;
	};
};

void IexMsdcIni::ImeitemIAVValuelistVal::writeTxt(
			fstream& outfile
		) {
	outfile << VecMsdcVValuelist::getSref(vlsIxMsdcVValuelist) << "\t" << VecMsdcVLocale::getSref(x1IxMsdcVLocale) << "\t" << Val << endl;
};

void IexMsdcIni::ImeitemIAVValuelistVal::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","vls","lcl","val"};
	else tags = {"ImeitemIAVValuelistVal","srefVlsIxMsdcVValuelist","srefX1IxMsdcVLocale","Val"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecMsdcVValuelist::getSref(vlsIxMsdcVValuelist));
		writeString(wr, tags[2], VecMsdcVLocale::getSref(x1IxMsdcVLocale));
		writeString(wr, tags[3], Val);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexMsdcIni::ImeIAVValuelistVal::VecWIel
 ******************************************************************************/

uint IexMsdcIni::ImeIAVValuelistVal::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i=0;i<ss.size();i++) {
		if (ss[i] == "srefvlsixmsdcvvaluelist") ix |= SREFVLSIXMSDCVVALUELIST;
		else if (ss[i] == "srefx1ixmsdcvlocale") ix |= SREFX1IXMSDCVLOCALE;
		else if (ss[i] == "val") ix |= VAL;
	};

	return(ix);
};

void IexMsdcIni::ImeIAVValuelistVal::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*VAL);i*=2) if (ix & i) ics.insert(i);
};

string IexMsdcIni::ImeIAVValuelistVal::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFVLSIXMSDCVVALUELIST) ss.push_back("srefVlsIxMsdcVValuelist");
	if (ix & SREFX1IXMSDCVLOCALE) ss.push_back("srefX1IxMsdcVLocale");
	if (ix & VAL) ss.push_back("Val");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexMsdcIni::ImeIAVValuelistVal
 ******************************************************************************/

IexMsdcIni::ImeIAVValuelistVal::ImeIAVValuelistVal() {
};

IexMsdcIni::ImeIAVValuelistVal::~ImeIAVValuelistVal() {
	clear();
};

void IexMsdcIni::ImeIAVValuelistVal::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool IexMsdcIni::ImeIAVValuelistVal::readTxt(
			Txtrd& txtrd
		) {
	IexMsdcIni::ImeitemIAVValuelistVal* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header) {
			txtrd.skip = true;
			break;

		} else if (txtrd.data && (txtrd.il == 0)) {
			ii = new IexMsdcIni::ImeitemIAVValuelistVal();

			if (ii->readTxt(txtrd)) {
				nodes.push_back(ii);
			} else {
				delete ii;
				return false;
			};

		} else {
			return false;
		};
	};

	return true;
};

void IexMsdcIni::ImeIAVValuelistVal::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexMsdcIni::ImeitemIAVValuelistVal* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIAVValuelistVal");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIAVValuelistVal", "Ii", "num", nums, _shorttags);

		for (unsigned int i=0;i<nums.size();i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIAVValuelistVal";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexMsdcIni::ImeitemIAVValuelistVal();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexMsdcIni::ImeIAVValuelistVal::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "ImeIAVValuelistVal." << StrMod::replaceChar(ImeIAVValuelistVal::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeTxt(outfile);
	};
};

void IexMsdcIni::ImeIAVValuelistVal::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIAVValuelistVal");
			for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexMsdcIni::ImeitemIMFile
 ******************************************************************************/

IexMsdcIni::ImeitemIMFile::ImeitemIMFile(
			const string& osrefKContent
			, const string& Filename
			, const string& srefKMimetype
			, const string& Comment
		) : MsdcMFile() {
	lineno = 0;
	ixWIelValid = 0;

	this->osrefKContent = osrefKContent;
	this->Filename = Filename;
	this->srefKMimetype = srefKMimetype;
	this->Comment = Comment;
};

IexMsdcIni::ImeitemIMFile::ImeitemIMFile(
			DbsMsdc* dbsmsdc
			, const ubigint ref
		) :
			ImeitemIMFile()
		{
	MsdcMFile* rec = NULL;

	this->ref = ref;

	if (dbsmsdc->tblmsdcmfile->loadRecByRef(ref, &rec)) {
		refIxVTbl = rec->refIxVTbl;
		osrefKContent = rec->osrefKContent;
		Filename = rec->Filename;
		srefKMimetype = rec->srefKMimetype;
		Comment = rec->Comment;

		delete rec;
	};
};

bool IexMsdcIni::ImeitemIMFile::readTxt(
			Txtrd& txtrd
		) {
	this->lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) osrefKContent = txtrd.fields[0];
	if (txtrd.fields.size() > 1) Filename = txtrd.fields[1];
	if (txtrd.fields.size() > 2) srefKMimetype = txtrd.fields[2];
	if (txtrd.fields.size() > 3) Comment = txtrd.fields[3];

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || txtrd.data) {
			txtrd.skip = true;
			break;

		} else {
			return false;
		};
	};

	return true;
};

void IexMsdcIni::ImeitemIMFile::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	ixWIelValid = 0;

	if (checkXPath(docctx, basexpath)) {
		if (extractStringUclc(docctx, basexpath, "osrefKContent", "cnt", osrefKContent)) ixWIelValid += ImeIMFile::VecWIel::OSREFKCONTENT;
		if (extractStringUclc(docctx, basexpath, "Filename", "fnm", Filename)) ixWIelValid += ImeIMFile::VecWIel::FILENAME;
		if (extractStringUclc(docctx, basexpath, "srefKMimetype", "mim", srefKMimetype)) ixWIelValid += ImeIMFile::VecWIel::SREFKMIMETYPE;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMFile::VecWIel::COMMENT;
	};
};

void IexMsdcIni::ImeitemIMFile::writeTxt(
			fstream& outfile
		) {
	outfile << osrefKContent << "\t" << Filename << "\t" << srefKMimetype << "\t" << Comment << endl;
};

void IexMsdcIni::ImeitemIMFile::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","cnt","fnm","mim","cmt"};
	else tags = {"ImeitemIMFile","osrefKContent","Filename","srefKMimetype","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], osrefKContent);
		writeString(wr, tags[2], Filename);
		writeString(wr, tags[3], srefKMimetype);
		writeString(wr, tags[4], Comment);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexMsdcIni::ImeIMFile::VecWIel
 ******************************************************************************/

uint IexMsdcIni::ImeIMFile::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i=0;i<ss.size();i++) {
		if (ss[i] == "osrefkcontent") ix |= OSREFKCONTENT;
		else if (ss[i] == "filename") ix |= FILENAME;
		else if (ss[i] == "srefkmimetype") ix |= SREFKMIMETYPE;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexMsdcIni::ImeIMFile::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*COMMENT);i*=2) if (ix & i) ics.insert(i);
};

string IexMsdcIni::ImeIMFile::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & OSREFKCONTENT) ss.push_back("osrefKContent");
	if (ix & FILENAME) ss.push_back("Filename");
	if (ix & SREFKMIMETYPE) ss.push_back("srefKMimetype");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexMsdcIni::ImeIMFile
 ******************************************************************************/

IexMsdcIni::ImeIMFile::ImeIMFile() {
};

IexMsdcIni::ImeIMFile::~ImeIMFile() {
	clear();
};

void IexMsdcIni::ImeIMFile::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool IexMsdcIni::ImeIMFile::readTxt(
			Txtrd& txtrd
		) {
	IexMsdcIni::ImeitemIMFile* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header) {
			txtrd.skip = true;
			break;

		} else if (txtrd.data && (txtrd.il == 0)) {
			ii = new IexMsdcIni::ImeitemIMFile();

			if (ii->readTxt(txtrd)) {
				nodes.push_back(ii);
			} else {
				delete ii;
				return false;
			};

		} else {
			return false;
		};
	};

	return true;
};

void IexMsdcIni::ImeIMFile::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexMsdcIni::ImeitemIMFile* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMFile");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMFile", "Ii", "num", nums, _shorttags);

		for (unsigned int i=0;i<nums.size();i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMFile";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexMsdcIni::ImeitemIMFile();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexMsdcIni::ImeIMFile::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "ImeIMFile." << StrMod::replaceChar(ImeIMFile::VecWIel::getSrefs(15), ';', '\t') << endl;
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeTxt(outfile);
	};
};

void IexMsdcIni::ImeIMFile::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMFile");
			for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexMsdcIni::ImeitemIAMUsergroupAccess
 ******************************************************************************/

IexMsdcIni::ImeitemIAMUsergroupAccess::ImeitemIAMUsergroupAccess(
			const uint x1IxMsdcVFeatgroup
			, const string& x2FeaSrefUix
			, const uint ixMsdcWAccess
		) : MsdcAMUsergroupAccess() {
	lineno = 0;
	ixWIelValid = 0;

	this->x1IxMsdcVFeatgroup = x1IxMsdcVFeatgroup;
	this->x2FeaSrefUix = x2FeaSrefUix;
	this->ixMsdcWAccess = ixMsdcWAccess;
};

IexMsdcIni::ImeitemIAMUsergroupAccess::ImeitemIAMUsergroupAccess(
			DbsMsdc* dbsmsdc
			, const ubigint ref
		) :
			ImeitemIAMUsergroupAccess()
		{
	MsdcAMUsergroupAccess* rec = NULL;

	this->ref = ref;

	if (dbsmsdc->tblmsdcamusergroupaccess->loadRecByRef(ref, &rec)) {
		refMsdcMUsergroup = rec->refMsdcMUsergroup;
		x1IxMsdcVFeatgroup = rec->x1IxMsdcVFeatgroup;
		x2FeaSrefUix = rec->x2FeaSrefUix;
		ixMsdcWAccess = rec->ixMsdcWAccess;

		delete rec;
	};
};

bool IexMsdcIni::ImeitemIAMUsergroupAccess::readTxt(
			Txtrd& txtrd
		) {
	this->lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) x1IxMsdcVFeatgroup = VecMsdcVFeatgroup::getIx(txtrd.fields[0]);
	if (txtrd.fields.size() > 1) x2FeaSrefUix = txtrd.fields[1];
	if (txtrd.fields.size() > 2) ixMsdcWAccess = VecMsdcWAccess::getIx(txtrd.fields[2]);

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || txtrd.data) {
			txtrd.skip = true;
			break;

		} else {
			return false;
		};
	};

	return true;
};

void IexMsdcIni::ImeitemIAMUsergroupAccess::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	string srefX1IxMsdcVFeatgroup;
	string srefsIxMsdcWAccess;

	ixWIelValid = 0;

	if (checkXPath(docctx, basexpath)) {
		if (extractStringUclc(docctx, basexpath, "srefX1IxMsdcVFeatgroup", "feg", srefX1IxMsdcVFeatgroup)) {
			x1IxMsdcVFeatgroup = VecMsdcVFeatgroup::getIx(srefX1IxMsdcVFeatgroup);
			ixWIelValid += ImeIAMUsergroupAccess::VecWIel::SREFX1IXMSDCVFEATGROUP;
		};
		if (extractStringUclc(docctx, basexpath, "x2FeaSrefUix", "fea", x2FeaSrefUix)) ixWIelValid += ImeIAMUsergroupAccess::VecWIel::X2FEASREFUIX;
		if (extractStringUclc(docctx, basexpath, "srefsIxMsdcWAccess", "acc", srefsIxMsdcWAccess)) {
			ixMsdcWAccess = VecMsdcWAccess::getIx(srefsIxMsdcWAccess);
			ixWIelValid += ImeIAMUsergroupAccess::VecWIel::SREFSIXMSDCWACCESS;
		};
	};
};

void IexMsdcIni::ImeitemIAMUsergroupAccess::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << VecMsdcVFeatgroup::getSref(x1IxMsdcVFeatgroup) << "\t" << x2FeaSrefUix << "\t" << VecMsdcWAccess::getSrefs(ixMsdcWAccess) << endl;
};

void IexMsdcIni::ImeitemIAMUsergroupAccess::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","feg","fea","acc"};
	else tags = {"ImeitemIAMUsergroupAccess","srefX1IxMsdcVFeatgroup","x2FeaSrefUix","srefsIxMsdcWAccess"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecMsdcVFeatgroup::getSref(x1IxMsdcVFeatgroup));
		writeString(wr, tags[2], x2FeaSrefUix);
		writeString(wr, tags[3], VecMsdcWAccess::getSrefs(ixMsdcWAccess));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexMsdcIni::ImeIAMUsergroupAccess::VecWIel
 ******************************************************************************/

uint IexMsdcIni::ImeIAMUsergroupAccess::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i=0;i<ss.size();i++) {
		if (ss[i] == "srefx1ixmsdcvfeatgroup") ix |= SREFX1IXMSDCVFEATGROUP;
		else if (ss[i] == "x2feasrefuix") ix |= X2FEASREFUIX;
		else if (ss[i] == "srefsixmsdcwaccess") ix |= SREFSIXMSDCWACCESS;
	};

	return(ix);
};

void IexMsdcIni::ImeIAMUsergroupAccess::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*SREFSIXMSDCWACCESS);i*=2) if (ix & i) ics.insert(i);
};

string IexMsdcIni::ImeIAMUsergroupAccess::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFX1IXMSDCVFEATGROUP) ss.push_back("srefX1IxMsdcVFeatgroup");
	if (ix & X2FEASREFUIX) ss.push_back("x2FeaSrefUix");
	if (ix & SREFSIXMSDCWACCESS) ss.push_back("srefsIxMsdcWAccess");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexMsdcIni::ImeIAMUsergroupAccess
 ******************************************************************************/

IexMsdcIni::ImeIAMUsergroupAccess::ImeIAMUsergroupAccess() {
};

IexMsdcIni::ImeIAMUsergroupAccess::~ImeIAMUsergroupAccess() {
	clear();
};

void IexMsdcIni::ImeIAMUsergroupAccess::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool IexMsdcIni::ImeIAMUsergroupAccess::readTxt(
			Txtrd& txtrd
		) {
	IexMsdcIni::ImeitemIAMUsergroupAccess* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || (txtrd.il < 1)) {
			txtrd.skip = true;
			break;

		} else if (txtrd.data && (txtrd.il == 1)) {
			ii = new IexMsdcIni::ImeitemIAMUsergroupAccess();

			if (ii->readTxt(txtrd)) {
				nodes.push_back(ii);
			} else {
				delete ii;
				return false;
			};

		} else {
			return false;
		};
	};

	return true;
};

void IexMsdcIni::ImeIAMUsergroupAccess::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexMsdcIni::ImeitemIAMUsergroupAccess* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIAMUsergroupAccess");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIAMUsergroupAccess", "Ii", "num", nums, _shorttags);

		for (unsigned int i=0;i<nums.size();i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIAMUsergroupAccess";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexMsdcIni::ImeitemIAMUsergroupAccess();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexMsdcIni::ImeIAMUsergroupAccess::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIAMUsergroupAccess." << StrMod::replaceChar(ImeIAMUsergroupAccess::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeTxt(outfile);
	};
};

void IexMsdcIni::ImeIAMUsergroupAccess::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIAMUsergroupAccess");
			for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexMsdcIni::ImeitemIAMUserAccess
 ******************************************************************************/

IexMsdcIni::ImeitemIAMUserAccess::ImeitemIAMUserAccess(
			const uint x1IxMsdcVFeatgroup
			, const string& x2FeaSrefUix
			, const uint ixMsdcWAccess
		) : MsdcAMUserAccess() {
	lineno = 0;
	ixWIelValid = 0;

	this->x1IxMsdcVFeatgroup = x1IxMsdcVFeatgroup;
	this->x2FeaSrefUix = x2FeaSrefUix;
	this->ixMsdcWAccess = ixMsdcWAccess;
};

IexMsdcIni::ImeitemIAMUserAccess::ImeitemIAMUserAccess(
			DbsMsdc* dbsmsdc
			, const ubigint ref
		) :
			ImeitemIAMUserAccess()
		{
	MsdcAMUserAccess* rec = NULL;

	this->ref = ref;

	if (dbsmsdc->tblmsdcamuseraccess->loadRecByRef(ref, &rec)) {
		refMsdcMUser = rec->refMsdcMUser;
		x1IxMsdcVFeatgroup = rec->x1IxMsdcVFeatgroup;
		x2FeaSrefUix = rec->x2FeaSrefUix;
		ixMsdcWAccess = rec->ixMsdcWAccess;

		delete rec;
	};
};

bool IexMsdcIni::ImeitemIAMUserAccess::readTxt(
			Txtrd& txtrd
		) {
	this->lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) x1IxMsdcVFeatgroup = VecMsdcVFeatgroup::getIx(txtrd.fields[0]);
	if (txtrd.fields.size() > 1) x2FeaSrefUix = txtrd.fields[1];
	if (txtrd.fields.size() > 2) ixMsdcWAccess = VecMsdcWAccess::getIx(txtrd.fields[2]);

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || txtrd.data) {
			txtrd.skip = true;
			break;

		} else {
			return false;
		};
	};

	return true;
};

void IexMsdcIni::ImeitemIAMUserAccess::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	string srefX1IxMsdcVFeatgroup;
	string srefsIxMsdcWAccess;

	ixWIelValid = 0;

	if (checkXPath(docctx, basexpath)) {
		if (extractStringUclc(docctx, basexpath, "srefX1IxMsdcVFeatgroup", "feg", srefX1IxMsdcVFeatgroup)) {
			x1IxMsdcVFeatgroup = VecMsdcVFeatgroup::getIx(srefX1IxMsdcVFeatgroup);
			ixWIelValid += ImeIAMUserAccess::VecWIel::SREFX1IXMSDCVFEATGROUP;
		};
		if (extractStringUclc(docctx, basexpath, "x2FeaSrefUix", "fea", x2FeaSrefUix)) ixWIelValid += ImeIAMUserAccess::VecWIel::X2FEASREFUIX;
		if (extractStringUclc(docctx, basexpath, "srefsIxMsdcWAccess", "acc", srefsIxMsdcWAccess)) {
			ixMsdcWAccess = VecMsdcWAccess::getIx(srefsIxMsdcWAccess);
			ixWIelValid += ImeIAMUserAccess::VecWIel::SREFSIXMSDCWACCESS;
		};
	};
};

void IexMsdcIni::ImeitemIAMUserAccess::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << VecMsdcVFeatgroup::getSref(x1IxMsdcVFeatgroup) << "\t" << x2FeaSrefUix << "\t" << VecMsdcWAccess::getSrefs(ixMsdcWAccess) << endl;
};

void IexMsdcIni::ImeitemIAMUserAccess::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","feg","fea","acc"};
	else tags = {"ImeitemIAMUserAccess","srefX1IxMsdcVFeatgroup","x2FeaSrefUix","srefsIxMsdcWAccess"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecMsdcVFeatgroup::getSref(x1IxMsdcVFeatgroup));
		writeString(wr, tags[2], x2FeaSrefUix);
		writeString(wr, tags[3], VecMsdcWAccess::getSrefs(ixMsdcWAccess));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexMsdcIni::ImeIAMUserAccess::VecWIel
 ******************************************************************************/

uint IexMsdcIni::ImeIAMUserAccess::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i=0;i<ss.size();i++) {
		if (ss[i] == "srefx1ixmsdcvfeatgroup") ix |= SREFX1IXMSDCVFEATGROUP;
		else if (ss[i] == "x2feasrefuix") ix |= X2FEASREFUIX;
		else if (ss[i] == "srefsixmsdcwaccess") ix |= SREFSIXMSDCWACCESS;
	};

	return(ix);
};

void IexMsdcIni::ImeIAMUserAccess::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*SREFSIXMSDCWACCESS);i*=2) if (ix & i) ics.insert(i);
};

string IexMsdcIni::ImeIAMUserAccess::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFX1IXMSDCVFEATGROUP) ss.push_back("srefX1IxMsdcVFeatgroup");
	if (ix & X2FEASREFUIX) ss.push_back("x2FeaSrefUix");
	if (ix & SREFSIXMSDCWACCESS) ss.push_back("srefsIxMsdcWAccess");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexMsdcIni::ImeIAMUserAccess
 ******************************************************************************/

IexMsdcIni::ImeIAMUserAccess::ImeIAMUserAccess() {
};

IexMsdcIni::ImeIAMUserAccess::~ImeIAMUserAccess() {
	clear();
};

void IexMsdcIni::ImeIAMUserAccess::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool IexMsdcIni::ImeIAMUserAccess::readTxt(
			Txtrd& txtrd
		) {
	IexMsdcIni::ImeitemIAMUserAccess* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || (txtrd.il < 2)) {
			txtrd.skip = true;
			break;

		} else if (txtrd.data && (txtrd.il == 2)) {
			ii = new IexMsdcIni::ImeitemIAMUserAccess();

			if (ii->readTxt(txtrd)) {
				nodes.push_back(ii);
			} else {
				delete ii;
				return false;
			};

		} else {
			return false;
		};
	};

	return true;
};

void IexMsdcIni::ImeIAMUserAccess::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexMsdcIni::ImeitemIAMUserAccess* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIAMUserAccess");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIAMUserAccess", "Ii", "num", nums, _shorttags);

		for (unsigned int i=0;i<nums.size();i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIAMUserAccess";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexMsdcIni::ImeitemIAMUserAccess();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexMsdcIni::ImeIAMUserAccess::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIAMUserAccess." << StrMod::replaceChar(ImeIAMUserAccess::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeTxt(outfile);
	};
};

void IexMsdcIni::ImeIAMUserAccess::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIAMUserAccess");
			for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexMsdcIni::ImeitemIJMUserState
 ******************************************************************************/

IexMsdcIni::ImeitemIJMUserState::ImeitemIJMUserState(
			const uint ixVState
		) : MsdcJMUserState() {
	lineno = 0;
	ixWIelValid = 0;

	this->ixVState = ixVState;
};

IexMsdcIni::ImeitemIJMUserState::ImeitemIJMUserState(
			DbsMsdc* dbsmsdc
			, const ubigint ref
		) :
			ImeitemIJMUserState()
		{
	MsdcJMUserState* rec = NULL;

	this->ref = ref;

	if (dbsmsdc->tblmsdcjmuserstate->loadRecByRef(ref, &rec)) {
		refMsdcMUser = rec->refMsdcMUser;
		ixVState = rec->ixVState;

		delete rec;
	};
};

bool IexMsdcIni::ImeitemIJMUserState::readTxt(
			Txtrd& txtrd
		) {
	this->lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) ixVState = VecMsdcVMUserState::getIx(txtrd.fields[0]);

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || txtrd.data) {
			txtrd.skip = true;
			break;

		} else {
			return false;
		};
	};

	return true;
};

void IexMsdcIni::ImeitemIJMUserState::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	string srefIxVState;

	ixWIelValid = 0;

	if (checkXPath(docctx, basexpath)) {
		if (extractStringUclc(docctx, basexpath, "srefIxVState", "ste", srefIxVState)) {
			ixVState = VecMsdcVMUserState::getIx(srefIxVState);
			ixWIelValid += ImeIJMUserState::VecWIel::SREFIXVSTATE;
		};
	};
};

void IexMsdcIni::ImeitemIJMUserState::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << VecMsdcVMUserState::getSref(ixVState) << endl;
};

void IexMsdcIni::ImeitemIJMUserState::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","ste"};
	else tags = {"ImeitemIJMUserState","srefIxVState"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecMsdcVMUserState::getSref(ixVState));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexMsdcIni::ImeIJMUserState::VecWIel
 ******************************************************************************/

uint IexMsdcIni::ImeIJMUserState::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i=0;i<ss.size();i++) {
		if (ss[i] == "srefixvstate") ix |= SREFIXVSTATE;
	};

	return(ix);
};

void IexMsdcIni::ImeIJMUserState::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*SREFIXVSTATE);i*=2) if (ix & i) ics.insert(i);
};

string IexMsdcIni::ImeIJMUserState::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFIXVSTATE) ss.push_back("srefIxVState");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexMsdcIni::ImeIJMUserState
 ******************************************************************************/

IexMsdcIni::ImeIJMUserState::ImeIJMUserState() {
};

IexMsdcIni::ImeIJMUserState::~ImeIJMUserState() {
	clear();
};

void IexMsdcIni::ImeIJMUserState::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool IexMsdcIni::ImeIJMUserState::readTxt(
			Txtrd& txtrd
		) {
	IexMsdcIni::ImeitemIJMUserState* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || (txtrd.il < 2)) {
			txtrd.skip = true;
			break;

		} else if (txtrd.data && (txtrd.il == 2)) {
			ii = new IexMsdcIni::ImeitemIJMUserState();

			if (ii->readTxt(txtrd)) {
				nodes.push_back(ii);
			} else {
				delete ii;
				return false;
			};

		} else {
			return false;
		};
	};

	return true;
};

void IexMsdcIni::ImeIJMUserState::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexMsdcIni::ImeitemIJMUserState* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIJMUserState");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIJMUserState", "Ii", "num", nums, _shorttags);

		for (unsigned int i=0;i<nums.size();i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIJMUserState";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexMsdcIni::ImeitemIJMUserState();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexMsdcIni::ImeIJMUserState::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIJMUserState." << StrMod::replaceChar(ImeIJMUserState::VecWIel::getSrefs(1), ';', '\t') << endl;
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeTxt(outfile);
	};
};

void IexMsdcIni::ImeIJMUserState::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIJMUserState");
			for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexMsdcIni::ImeitemIJMPersonLastname
 ******************************************************************************/

IexMsdcIni::ImeitemIJMPersonLastname::ImeitemIJMPersonLastname(
			const string& Lastname
		) : MsdcJMPersonLastname() {
	lineno = 0;
	ixWIelValid = 0;

	this->Lastname = Lastname;
};

IexMsdcIni::ImeitemIJMPersonLastname::ImeitemIJMPersonLastname(
			DbsMsdc* dbsmsdc
			, const ubigint ref
		) :
			ImeitemIJMPersonLastname()
		{
	MsdcJMPersonLastname* rec = NULL;

	this->ref = ref;

	if (dbsmsdc->tblmsdcjmpersonlastname->loadRecByRef(ref, &rec)) {
		refMsdcMPerson = rec->refMsdcMPerson;
		Lastname = rec->Lastname;

		delete rec;
	};
};

bool IexMsdcIni::ImeitemIJMPersonLastname::readTxt(
			Txtrd& txtrd
		) {
	this->lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) Lastname = txtrd.fields[0];

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || txtrd.data) {
			txtrd.skip = true;
			break;

		} else {
			return false;
		};
	};

	return true;
};

void IexMsdcIni::ImeitemIJMPersonLastname::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	ixWIelValid = 0;

	if (checkXPath(docctx, basexpath)) {
		if (extractStringUclc(docctx, basexpath, "Lastname", "lnm", Lastname)) ixWIelValid += ImeIJMPersonLastname::VecWIel::LASTNAME;
	};
};

void IexMsdcIni::ImeitemIJMPersonLastname::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t\t" << Lastname << endl;
};

void IexMsdcIni::ImeitemIJMPersonLastname::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","lnm"};
	else tags = {"ImeitemIJMPersonLastname","Lastname"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], Lastname);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexMsdcIni::ImeIJMPersonLastname::VecWIel
 ******************************************************************************/

uint IexMsdcIni::ImeIJMPersonLastname::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i=0;i<ss.size();i++) {
		if (ss[i] == "lastname") ix |= LASTNAME;
	};

	return(ix);
};

void IexMsdcIni::ImeIJMPersonLastname::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*LASTNAME);i*=2) if (ix & i) ics.insert(i);
};

string IexMsdcIni::ImeIJMPersonLastname::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & LASTNAME) ss.push_back("Lastname");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexMsdcIni::ImeIJMPersonLastname
 ******************************************************************************/

IexMsdcIni::ImeIJMPersonLastname::ImeIJMPersonLastname() {
};

IexMsdcIni::ImeIJMPersonLastname::~ImeIJMPersonLastname() {
	clear();
};

void IexMsdcIni::ImeIJMPersonLastname::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool IexMsdcIni::ImeIJMPersonLastname::readTxt(
			Txtrd& txtrd
		) {
	IexMsdcIni::ImeitemIJMPersonLastname* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || (txtrd.il < 3)) {
			txtrd.skip = true;
			break;

		} else if (txtrd.data && (txtrd.il == 3)) {
			ii = new IexMsdcIni::ImeitemIJMPersonLastname();

			if (ii->readTxt(txtrd)) {
				nodes.push_back(ii);
			} else {
				delete ii;
				return false;
			};

		} else {
			return false;
		};
	};

	return true;
};

void IexMsdcIni::ImeIJMPersonLastname::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexMsdcIni::ImeitemIJMPersonLastname* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIJMPersonLastname");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIJMPersonLastname", "Ii", "num", nums, _shorttags);

		for (unsigned int i=0;i<nums.size();i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIJMPersonLastname";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexMsdcIni::ImeitemIJMPersonLastname();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexMsdcIni::ImeIJMPersonLastname::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\t\tImeIJMPersonLastname." << StrMod::replaceChar(ImeIJMPersonLastname::VecWIel::getSrefs(1), ';', '\t') << endl;
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeTxt(outfile);
	};
};

void IexMsdcIni::ImeIJMPersonLastname::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIJMPersonLastname");
			for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexMsdcIni::ImeitemIMPerson
 ******************************************************************************/

IexMsdcIni::ImeitemIMPerson::ImeitemIMPerson(
			const uint ixVSex
			, const string& Title
			, const string& Firstname
		) : MsdcMPerson() {
	lineno = 0;
	ixWIelValid = 0;

	this->ixVSex = ixVSex;
	this->Title = Title;
	this->Firstname = Firstname;
};

IexMsdcIni::ImeitemIMPerson::ImeitemIMPerson(
			DbsMsdc* dbsmsdc
			, const ubigint ref
		) :
			ImeitemIMPerson()
		{
	MsdcMPerson* rec = NULL;

	this->ref = ref;

	if (dbsmsdc->tblmsdcmperson->loadRecByRef(ref, &rec)) {
		ixWDerivate = rec->ixWDerivate;
		ixVSex = rec->ixVSex;
		Title = rec->Title;
		Firstname = rec->Firstname;
		refJLastname = rec->refJLastname;

		delete rec;
	};
};

bool IexMsdcIni::ImeitemIMPerson::readTxt(
			Txtrd& txtrd
		) {
	this->lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) ixVSex = VecMsdcVMPersonSex::getIx(txtrd.fields[0]);
	if (txtrd.fields.size() > 1) Title = txtrd.fields[1];
	if (txtrd.fields.size() > 2) Firstname = txtrd.fields[2];

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header && (txtrd.il == 3) && (txtrd.ixVToken == VecVIme::IMEIJMPERSONLASTNAME)) {
			if (!imeijmpersonlastname.readTxt(txtrd)) return false;

		} else if (txtrd.header || txtrd.data) {
			txtrd.skip = true;
			break;

		} else {
			return false;
		};
	};

	return true;
};

void IexMsdcIni::ImeitemIMPerson::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	string srefIxVSex;

	ixWIelValid = 0;

	if (checkXPath(docctx, basexpath)) {
		if (extractStringUclc(docctx, basexpath, "srefIxVSex", "sex", srefIxVSex)) {
			ixVSex = VecMsdcVMPersonSex::getIx(srefIxVSex);
			ixWIelValid += ImeIMPerson::VecWIel::SREFIXVSEX;
		};
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIMPerson::VecWIel::TITLE;
		if (extractStringUclc(docctx, basexpath, "Firstname", "fnm", Firstname)) ixWIelValid += ImeIMPerson::VecWIel::FIRSTNAME;
		imeijmpersonlastname.readXML(docctx, basexpath);
	};
};

void IexMsdcIni::ImeitemIMPerson::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << VecMsdcVMPersonSex::getSref(ixVSex) << "\t" << Title << "\t" << Firstname << endl;
	imeijmpersonlastname.writeTxt(outfile);
};

void IexMsdcIni::ImeitemIMPerson::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","sex","tit","fnm"};
	else tags = {"ImeitemIMPerson","srefIxVSex","Title","Firstname"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecMsdcVMPersonSex::getSref(ixVSex));
		writeString(wr, tags[2], Title);
		writeString(wr, tags[3], Firstname);
		imeijmpersonlastname.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexMsdcIni::ImeIMPerson::VecWIel
 ******************************************************************************/

uint IexMsdcIni::ImeIMPerson::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i=0;i<ss.size();i++) {
		if (ss[i] == "srefixvsex") ix |= SREFIXVSEX;
		else if (ss[i] == "title") ix |= TITLE;
		else if (ss[i] == "firstname") ix |= FIRSTNAME;
	};

	return(ix);
};

void IexMsdcIni::ImeIMPerson::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*FIRSTNAME);i*=2) if (ix & i) ics.insert(i);
};

string IexMsdcIni::ImeIMPerson::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFIXVSEX) ss.push_back("srefIxVSex");
	if (ix & TITLE) ss.push_back("Title");
	if (ix & FIRSTNAME) ss.push_back("Firstname");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexMsdcIni::ImeIMPerson
 ******************************************************************************/

IexMsdcIni::ImeIMPerson::ImeIMPerson() {
};

IexMsdcIni::ImeIMPerson::~ImeIMPerson() {
	clear();
};

void IexMsdcIni::ImeIMPerson::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool IexMsdcIni::ImeIMPerson::readTxt(
			Txtrd& txtrd
		) {
	IexMsdcIni::ImeitemIMPerson* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || (txtrd.il < 2)) {
			txtrd.skip = true;
			break;

		} else if (txtrd.data && (txtrd.il == 2)) {
			ii = new IexMsdcIni::ImeitemIMPerson();

			if (ii->readTxt(txtrd)) {
				nodes.push_back(ii);
			} else {
				delete ii;
				return false;
			};

		} else {
			return false;
		};
	};

	return true;
};

void IexMsdcIni::ImeIMPerson::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexMsdcIni::ImeitemIMPerson* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMPerson");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMPerson", "Ii", "num", nums, _shorttags);

		for (unsigned int i=0;i<nums.size();i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMPerson";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexMsdcIni::ImeitemIMPerson();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexMsdcIni::ImeIMPerson::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIMPerson." << StrMod::replaceChar(ImeIMPerson::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeTxt(outfile);
	};
};

void IexMsdcIni::ImeIMPerson::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMPerson");
			for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexMsdcIni::ImeitemIMUser
 ******************************************************************************/

IexMsdcIni::ImeitemIMUser::ImeitemIMUser(
			const string& sref
			, const uint ixMsdcVLocale
			, const uint ixMsdcVUserlevel
			, const string& Password
			, const string& Fullkey
			, const string& Comment
		) : MsdcMUser() {
	lineno = 0;
	ixWIelValid = 0;

	this->sref = sref;
	this->ixMsdcVLocale = ixMsdcVLocale;
	this->ixMsdcVUserlevel = ixMsdcVUserlevel;
	this->Password = Password;
	this->Fullkey = Fullkey;
	this->Comment = Comment;
};

IexMsdcIni::ImeitemIMUser::ImeitemIMUser(
			DbsMsdc* dbsmsdc
			, const ubigint ref
		) :
			ImeitemIMUser()
		{
	MsdcMUser* rec = NULL;

	this->ref = ref;

	if (dbsmsdc->tblmsdcmuser->loadRecByRef(ref, &rec)) {
		refRUsergroup = rec->refRUsergroup;
		refMsdcMUsergroup = rec->refMsdcMUsergroup;
		refMsdcMPerson = rec->refMsdcMPerson;
		sref = rec->sref;
		refJState = rec->refJState;
		ixMsdcVLocale = rec->ixMsdcVLocale;
		ixMsdcVUserlevel = rec->ixMsdcVUserlevel;
		Password = rec->Password;
		Fullkey = rec->Fullkey;
		Comment = rec->Comment;

		delete rec;
	};
};

bool IexMsdcIni::ImeitemIMUser::readTxt(
			Txtrd& txtrd
		) {
	this->lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) sref = txtrd.fields[0];
	if (txtrd.fields.size() > 1) ixMsdcVLocale = VecMsdcVLocale::getIx(txtrd.fields[1]);
	if (txtrd.fields.size() > 2) ixMsdcVUserlevel = VecMsdcVUserlevel::getIx(txtrd.fields[2]);
	if (txtrd.fields.size() > 3) Password = txtrd.fields[3];
	if (txtrd.fields.size() > 4) Fullkey = txtrd.fields[4];
	if (txtrd.fields.size() > 5) Comment = txtrd.fields[5];

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header && (txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIAMUSERACCESS)) {
			if (!imeiamuseraccess.readTxt(txtrd)) return false;

		} else if (txtrd.header && (txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIJMUSERSTATE)) {
			if (!imeijmuserstate.readTxt(txtrd)) return false;

		} else if (txtrd.header && (txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIMPERSON)) {
			if (!imeimperson.readTxt(txtrd)) return false;

		} else if (txtrd.header || txtrd.data) {
			txtrd.skip = true;
			break;

		} else {
			return false;
		};
	};

	return true;
};

void IexMsdcIni::ImeitemIMUser::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	string srefIxMsdcVLocale;
	string srefIxMsdcVUserlevel;

	ixWIelValid = 0;

	if (checkXPath(docctx, basexpath)) {
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMUser::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "srefIxMsdcVLocale", "lcl", srefIxMsdcVLocale)) {
			ixMsdcVLocale = VecMsdcVLocale::getIx(srefIxMsdcVLocale);
			ixWIelValid += ImeIMUser::VecWIel::SREFIXMSDCVLOCALE;
		};
		if (extractStringUclc(docctx, basexpath, "srefIxMsdcVUserlevel", "ulv", srefIxMsdcVUserlevel)) {
			ixMsdcVUserlevel = VecMsdcVUserlevel::getIx(srefIxMsdcVUserlevel);
			ixWIelValid += ImeIMUser::VecWIel::SREFIXMSDCVUSERLEVEL;
		};
		if (extractStringUclc(docctx, basexpath, "Password", "pwd", Password)) ixWIelValid += ImeIMUser::VecWIel::PASSWORD;
		if (extractStringUclc(docctx, basexpath, "Fullkey", "fky", Fullkey)) ixWIelValid += ImeIMUser::VecWIel::FULLKEY;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMUser::VecWIel::COMMENT;
		imeiamuseraccess.readXML(docctx, basexpath);
		imeijmuserstate.readXML(docctx, basexpath);
		imeimperson.readXML(docctx, basexpath);
	};
};

void IexMsdcIni::ImeitemIMUser::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << sref << "\t" << VecMsdcVLocale::getSref(ixMsdcVLocale) << "\t" << VecMsdcVUserlevel::getSref(ixMsdcVUserlevel) << "\t" << Password << "\t" << Fullkey << "\t" << Comment << endl;
	imeiamuseraccess.writeTxt(outfile);
	imeijmuserstate.writeTxt(outfile);
	imeimperson.writeTxt(outfile);
};

void IexMsdcIni::ImeitemIMUser::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","srf","lcl","ulv","pwd","fky","cmt"};
	else tags = {"ImeitemIMUser","sref","srefIxMsdcVLocale","srefIxMsdcVUserlevel","Password","Fullkey","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], sref);
		writeString(wr, tags[2], VecMsdcVLocale::getSref(ixMsdcVLocale));
		writeString(wr, tags[3], VecMsdcVUserlevel::getSref(ixMsdcVUserlevel));
		writeString(wr, tags[4], Password);
		writeString(wr, tags[5], Fullkey);
		writeString(wr, tags[6], Comment);
		imeiamuseraccess.writeXML(wr, shorttags);
		imeijmuserstate.writeXML(wr, shorttags);
		imeimperson.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexMsdcIni::ImeIMUser::VecWIel
 ******************************************************************************/

uint IexMsdcIni::ImeIMUser::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i=0;i<ss.size();i++) {
		if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "srefixmsdcvlocale") ix |= SREFIXMSDCVLOCALE;
		else if (ss[i] == "srefixmsdcvuserlevel") ix |= SREFIXMSDCVUSERLEVEL;
		else if (ss[i] == "password") ix |= PASSWORD;
		else if (ss[i] == "fullkey") ix |= FULLKEY;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexMsdcIni::ImeIMUser::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*COMMENT);i*=2) if (ix & i) ics.insert(i);
};

string IexMsdcIni::ImeIMUser::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREF) ss.push_back("sref");
	if (ix & SREFIXMSDCVLOCALE) ss.push_back("srefIxMsdcVLocale");
	if (ix & SREFIXMSDCVUSERLEVEL) ss.push_back("srefIxMsdcVUserlevel");
	if (ix & PASSWORD) ss.push_back("Password");
	if (ix & FULLKEY) ss.push_back("Fullkey");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexMsdcIni::ImeIMUser
 ******************************************************************************/

IexMsdcIni::ImeIMUser::ImeIMUser() {
};

IexMsdcIni::ImeIMUser::~ImeIMUser() {
	clear();
};

void IexMsdcIni::ImeIMUser::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool IexMsdcIni::ImeIMUser::readTxt(
			Txtrd& txtrd
		) {
	IexMsdcIni::ImeitemIMUser* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || (txtrd.il < 1)) {
			txtrd.skip = true;
			break;

		} else if (txtrd.data && (txtrd.il == 1)) {
			ii = new IexMsdcIni::ImeitemIMUser();

			if (ii->readTxt(txtrd)) {
				nodes.push_back(ii);
			} else {
				delete ii;
				return false;
			};

		} else {
			return false;
		};
	};

	return true;
};

void IexMsdcIni::ImeIMUser::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexMsdcIni::ImeitemIMUser* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMUser");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMUser", "Ii", "num", nums, _shorttags);

		for (unsigned int i=0;i<nums.size();i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMUser";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexMsdcIni::ImeitemIMUser();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexMsdcIni::ImeIMUser::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIMUser." << StrMod::replaceChar(ImeIMUser::VecWIel::getSrefs(63), ';', '\t') << endl;
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeTxt(outfile);
	};
};

void IexMsdcIni::ImeIMUser::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMUser");
			for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexMsdcIni::ImeitemIMUsergroup
 ******************************************************************************/

IexMsdcIni::ImeitemIMUsergroup::ImeitemIMUsergroup(
			const string& sref
			, const string& Comment
		) : MsdcMUsergroup() {
	lineno = 0;
	ixWIelValid = 0;

	this->sref = sref;
	this->Comment = Comment;
};

IexMsdcIni::ImeitemIMUsergroup::ImeitemIMUsergroup(
			DbsMsdc* dbsmsdc
			, const ubigint ref
		) :
			ImeitemIMUsergroup()
		{
	MsdcMUsergroup* rec = NULL;

	this->ref = ref;

	if (dbsmsdc->tblmsdcmusergroup->loadRecByRef(ref, &rec)) {
		sref = rec->sref;
		Comment = rec->Comment;

		delete rec;
	};
};

bool IexMsdcIni::ImeitemIMUsergroup::readTxt(
			Txtrd& txtrd
		) {
	this->lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) sref = txtrd.fields[0];
	if (txtrd.fields.size() > 1) Comment = txtrd.fields[1];

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header && (txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIAMUSERGROUPACCESS)) {
			if (!imeiamusergroupaccess.readTxt(txtrd)) return false;

		} else if (txtrd.header && (txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIMUSER)) {
			if (!imeimuser.readTxt(txtrd)) return false;

		} else if (txtrd.header || txtrd.data) {
			txtrd.skip = true;
			break;

		} else {
			return false;
		};
	};

	return true;
};

void IexMsdcIni::ImeitemIMUsergroup::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	ixWIelValid = 0;

	if (checkXPath(docctx, basexpath)) {
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMUsergroup::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMUsergroup::VecWIel::COMMENT;
		imeiamusergroupaccess.readXML(docctx, basexpath);
		imeimuser.readXML(docctx, basexpath);
	};
};

void IexMsdcIni::ImeitemIMUsergroup::writeTxt(
			fstream& outfile
		) {
	outfile << sref << "\t" << Comment << endl;
	imeiamusergroupaccess.writeTxt(outfile);
	imeimuser.writeTxt(outfile);
};

void IexMsdcIni::ImeitemIMUsergroup::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","srf","cmt"};
	else tags = {"ImeitemIMUsergroup","sref","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], sref);
		writeString(wr, tags[2], Comment);
		imeiamusergroupaccess.writeXML(wr, shorttags);
		imeimuser.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexMsdcIni::ImeIMUsergroup::VecWIel
 ******************************************************************************/

uint IexMsdcIni::ImeIMUsergroup::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i=0;i<ss.size();i++) {
		if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexMsdcIni::ImeIMUsergroup::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*COMMENT);i*=2) if (ix & i) ics.insert(i);
};

string IexMsdcIni::ImeIMUsergroup::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREF) ss.push_back("sref");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexMsdcIni::ImeIMUsergroup
 ******************************************************************************/

IexMsdcIni::ImeIMUsergroup::ImeIMUsergroup() {
};

IexMsdcIni::ImeIMUsergroup::~ImeIMUsergroup() {
	clear();
};

void IexMsdcIni::ImeIMUsergroup::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool IexMsdcIni::ImeIMUsergroup::readTxt(
			Txtrd& txtrd
		) {
	IexMsdcIni::ImeitemIMUsergroup* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header) {
			txtrd.skip = true;
			break;

		} else if (txtrd.data && (txtrd.il == 0)) {
			ii = new IexMsdcIni::ImeitemIMUsergroup();

			if (ii->readTxt(txtrd)) {
				nodes.push_back(ii);
			} else {
				delete ii;
				return false;
			};

		} else {
			return false;
		};
	};

	return true;
};

void IexMsdcIni::ImeIMUsergroup::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexMsdcIni::ImeitemIMUsergroup* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMUsergroup");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMUsergroup", "Ii", "num", nums, _shorttags);

		for (unsigned int i=0;i<nums.size();i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMUsergroup";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexMsdcIni::ImeitemIMUsergroup();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexMsdcIni::ImeIMUsergroup::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "ImeIMUsergroup." << StrMod::replaceChar(ImeIMUsergroup::VecWIel::getSrefs(3), ';', '\t') << endl;
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeTxt(outfile);
	};
};

void IexMsdcIni::ImeIMUsergroup::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMUsergroup");
			for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

