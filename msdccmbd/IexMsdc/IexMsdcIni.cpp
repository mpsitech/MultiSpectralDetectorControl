/**
  * \file IexMsdcIni.cpp
  * import/export handler for database DbsMsdc (implementation)
  * \author Alexander Wirthmueller
  * \date created: 29 Aug 2018
  * \date modified: 29 Aug 2018
  */

#ifdef MSDCCMBD
	#include <Msdccmbd.h>
#else
	#include <Msdcd.h>
#endif

#include "IexMsdcIni.h"

#include "IexMsdcIni_blks.cpp"

/******************************************************************************
 class IexMsdcIni
 ******************************************************************************/

IexMsdcIni::IexMsdcIni(
			XchgMsdc* xchg
			, DbsMsdc* dbsmsdc
			, const ubigint jrefSup
			, const uint ixMsdcVLocale
		) :
			JobMsdc(xchg, VecMsdcVJob::IEXMSDCINI, jrefSup, ixMsdcVLocale)
		{

	jref = xchg->addJob(this);
};

IexMsdcIni::~IexMsdcIni() {
	// remove job reference from job list
	if (jref != 0) xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void IexMsdcIni::reset() {
	imeiavcontrolpar.clear();
	imeiavkeylistkey.clear();
	imeiavvaluelistval.clear();
	imeimfile.clear();
	imeimusergroup.clear();

	lineno = 0;
	impcnt = 0;
};

void IexMsdcIni::import(
			DbsMsdc* dbsmsdc
		) {
	ImeitemIAVControlPar* ctlApar = NULL;
	ImeitemIAVKeylistKey* klsAkey = NULL;
	ImeitemIAVValuelistVal* vlsAval = NULL;
	ImeitemIMFile* fil = NULL;
	ImeitemIMUsergroup* usg = NULL;
	ImeitemIAMUsergroupAccess* usgAacc = NULL;
	ImeitemIJAVKeylistKey* kakJkey = NULL;
	ImeitemIMUser* usr = NULL;
	ImeitemIAMUserAccess* usrAacc = NULL;
	ImeitemIJMUserState* usrJste = NULL;
	ImeitemIMPerson* prs = NULL;
	ImeitemIJMPersonLastname* prsJlnm = NULL;

	uint num0;

	// IP import --- IBEGIN
	MsdcRMUserMUsergroup uru;
	// IP import --- IEND

	// IP import.traverse --- RBEGIN

	// -- ImeIAVControlPar
	for (unsigned int ix0=0;ix0<imeiavcontrolpar.nodes.size();ix0++) {
		ctlApar = imeiavcontrolpar.nodes[ix0];

		//ctlApar->ixMsdcVControl: IXSREF
		//ctlApar->Par: TBL
		//ctlApar->Val: TBL

		dbsmsdc->tblmsdcavcontrolpar->insertRec(ctlApar);
		impcnt++;
	};

	// -- ImeIAVKeylistKey
	for (unsigned int ix0=0;ix0<imeiavkeylistkey.nodes.size();ix0++) {
		klsAkey = imeiavkeylistkey.nodes[ix0];

		//klsAkey->klsIxMsdcVKeylist: IXSREF
		klsAkey->klsNum = (ix0+1); // TBD
		klsAkey->x1IxMsdcVMaintable = VecMsdcVMaintable::VOID;
		klsAkey->Fixed = true;
		//klsAkey->sref: TBL
		//klsAkey->Avail: TBL
		//klsAkey->Implied: TBL
		//klsAkey->refJ: SUB

		dbsmsdc->tblmsdcavkeylistkey->insertRec(klsAkey);
		impcnt++;

		for (unsigned int ix1=0;ix1<klsAkey->imeijavkeylistkey.nodes.size();ix1++) {
			kakJkey = klsAkey->imeijavkeylistkey.nodes[ix1];

			kakJkey->refMsdcAVKeylistKey = klsAkey->ref;
			//kakJkey->x1IxMsdcVLocale: IXSREF
			//kakJkey->Title: TBL
			//kakJkey->Comment: TBL

			dbsmsdc->tblmsdcjavkeylistkey->insertRec(kakJkey);
			impcnt++;
		};

		if (klsAkey->imeijavkeylistkey.nodes.size() > 0) {
			kakJkey = klsAkey->imeijavkeylistkey.nodes[0];

			klsAkey->refJ = kakJkey->ref;
			klsAkey->Title = kakJkey->Title;
			klsAkey->Comment = kakJkey->Comment;
			
			dbsmsdc->tblmsdcavkeylistkey->updateRec(klsAkey);
		};
	};

	// -- ImeIAVValuelistVal
	for (unsigned int ix0=0;ix0<imeiavvaluelistval.nodes.size();ix0++) {
		vlsAval = imeiavvaluelistval.nodes[ix0];

		//vlsAval->vlsIxMsdcVValuelist: IXSREF
		vlsAval->vlsNum = (ix0+1); // TBD
		//vlsAval->x1IxMsdcVLocale: IXSREF
		//vlsAval->Val: TBL

		dbsmsdc->tblmsdcavvaluelistval->insertRec(vlsAval);
		impcnt++;
	};

	// -- ImeIMUsergroup
	for (unsigned int ix0=0;ix0<imeimusergroup.nodes.size();ix0++) {
		usg = imeimusergroup.nodes[ix0];

		//usg->sref: TBL
		//usg->Comment: TBL

		dbsmsdc->tblmsdcmusergroup->insertRec(usg);
		impcnt++;

		for (unsigned int ix1=0;ix1<usg->imeiamusergroupaccess.nodes.size();ix1++) {
			usgAacc = usg->imeiamusergroupaccess.nodes[ix1];

			usgAacc->refMsdcMUsergroup = usg->ref;
			//usgAacc->x1IxMsdcVFeatgroup: IXSREF
			//usgAacc->x2FeaSrefUix: TBL
			//usgAacc->ixMsdcWAccess: IXSREF

			dbsmsdc->tblmsdcamusergroupaccess->insertRec(usgAacc);
			impcnt++;
		};

		for (unsigned int ix1=0;ix1<usg->imeimuser.nodes.size();ix1++) {
			usr = usg->imeimuser.nodes[ix1];

			//usr->refRUsergroup: IMPPP
			usr->refMsdcMUsergroup = usg->ref;
			//usr->refMsdcMPerson: IMPPP
			//usr->sref: TBL
			//usr->refJState: SUB
			//usr->ixMsdcVLocale: IXSREF
			//usr->ixMsdcVUserlevel: IXSREF
			//usr->Password: TBL
			//usr->Fullkey: TBL
			//usr->Comment: TBL

			dbsmsdc->tblmsdcmuser->insertRec(usr);
			impcnt++;

			for (unsigned int ix2=0;ix2<usr->imeiamuseraccess.nodes.size();ix2++) {
				usrAacc = usr->imeiamuseraccess.nodes[ix2];

				usrAacc->refMsdcMUser = usr->ref;
				//usrAacc->x1IxMsdcVFeatgroup: IXSREF
				//usrAacc->x2FeaSrefUix: TBL
				//usrAacc->ixMsdcWAccess: IXSREF

				dbsmsdc->tblmsdcamuseraccess->insertRec(usrAacc);
				impcnt++;
			};

			for (unsigned int ix2=0;ix2<usr->imeijmuserstate.nodes.size();ix2++) {
				usrJste = usr->imeijmuserstate.nodes[ix2];

				usrJste->refMsdcMUser = usr->ref;
				//usrJste->ixVState: IXSREF

				dbsmsdc->tblmsdcjmuserstate->insertRec(usrJste);
				impcnt++;
			};

			if (usr->imeijmuserstate.nodes.size() > 0) {
				usrJste = usr->imeijmuserstate.nodes[0];

				usr->refJState = usrJste->ref;
				usr->ixVState = usrJste->ixVState;
			
				dbsmsdc->tblmsdcmuser->updateRec(usr);
			};

			for (unsigned int ix2=0;ix2<usr->imeimperson.nodes.size();ix2++) {
				prs = usr->imeimperson.nodes[ix2];

				prs->ixWDerivate = VecMsdcWMPersonDerivate::USR;
				//prs->ixVSex: IXSREF
				//prs->Title: TBL
				//prs->Firstname: TBL
				//prs->refJLastname: SUB

				dbsmsdc->tblmsdcmperson->insertRec(prs);
				impcnt++;

				for (unsigned int ix3=0;ix3<prs->imeijmpersonlastname.nodes.size();ix3++) {
					prsJlnm = prs->imeijmpersonlastname.nodes[ix3];

					prsJlnm->refMsdcMPerson = prs->ref;
					//prsJlnm->Lastname: TBL

					dbsmsdc->tblmsdcjmpersonlastname->insertRec(prsJlnm);
					impcnt++;
				};

				if (prs->imeijmpersonlastname.nodes.size() > 0) {
					prsJlnm = prs->imeijmpersonlastname.nodes[0];

					prs->refJLastname = prsJlnm->ref;
					prs->Lastname = prsJlnm->Lastname;
					
					dbsmsdc->tblmsdcmperson->updateRec(prs);
				};
			};

			if (usr->imeimperson.nodes.size() > 0) {
				prs = usr->imeimperson.nodes[0];

				usr->refMsdcMPerson = prs->ref;

				dbsmsdc->tblmsdcmuser->updateRec(usr);
			};

			uru.refMsdcMUser = usr->ref;
			uru.refMsdcMUsergroup = usg->ref;
			uru.ixMsdcVUserlevel = usr->ixMsdcVUserlevel;
			dbsmsdc->tblmsdcrmusermusergroup->insertRec(&uru);

			usr->refRUsergroup = uru.ref;
			dbsmsdc->tblmsdcmuser->updateRec(usr);
		};
	};
	// IP import.traverse --- REND

	// IP import.ppr --- INSERT
};

void IexMsdcIni::collect(
			DbsMsdc* dbsmsdc
			, const map<uint,uint>& icsMsdcVIop
		) {
	ImeitemIAVControlPar* ctlApar = NULL;
	ImeitemIAVKeylistKey* klsAkey = NULL;
	ImeitemIAVValuelistVal* vlsAval = NULL;
	ImeitemIMFile* fil = NULL;
	ImeitemIMUsergroup* usg = NULL;
	ImeitemIAMUsergroupAccess* usgAacc = NULL;
	ImeitemIJAVKeylistKey* kakJkey = NULL;
	ImeitemIMUser* usr = NULL;
	ImeitemIAMUserAccess* usrAacc = NULL;
	ImeitemIJMUserState* usrJste = NULL;
	ImeitemIMPerson* prs = NULL;
	ImeitemIJMPersonLastname* prsJlnm = NULL;

	uint ixMsdcVIop;

	vector<ubigint> refs;

	Stcch* stcch = new Stcch(false);

	// IP collect.traverse --- BEGIN

	// -- ImeIAVControlPar
	for (unsigned int ix0=0;ix0<imeiavcontrolpar.nodes.size();ix0++) {
		ctlApar = imeiavcontrolpar.nodes[ix0];

		if (ctlApar->ref != 0) {
		};
	};

	// -- ImeIAVKeylistKey
	for (unsigned int ix0=0;ix0<imeiavkeylistkey.nodes.size();ix0++) {
		klsAkey = imeiavkeylistkey.nodes[ix0];

		if (klsAkey->ref != 0) {
		};

		if (getIxMsdcVIop(icsMsdcVIop, VecVIme::IMEIJAVKEYLISTKEY, ixMsdcVIop)) {
			dbsmsdc->tblmsdcjavkeylistkey->loadRefsByKlk(klsAkey->ref, false, refs);
			for (unsigned int i=0;i<refs.size();i++) if (refs[i] == klsAkey->refJ) {refs[i] = refs[0]; refs[0] = klsAkey->refJ; break;};
			for (unsigned int i=0;i<refs.size();i++) klsAkey->imeijavkeylistkey.nodes.push_back(new ImeitemIJAVKeylistKey(dbsmsdc, refs[i]));
		};

		for (unsigned int ix1=0;ix1<klsAkey->imeijavkeylistkey.nodes.size();ix1++) {
			kakJkey = klsAkey->imeijavkeylistkey.nodes[ix1];

			if (kakJkey->ref != 0) {
			};
		};
	};

	// -- ImeIAVValuelistVal
	for (unsigned int ix0=0;ix0<imeiavvaluelistval.nodes.size();ix0++) {
		vlsAval = imeiavvaluelistval.nodes[ix0];

		if (vlsAval->ref != 0) {
		};
	};

	// -- ImeIMFile
	for (unsigned int ix0=0;ix0<imeimfile.nodes.size();ix0++) {
		fil = imeimfile.nodes[ix0];

		if (fil->ref != 0) {
		};
	};

	// -- ImeIMUsergroup
	for (unsigned int ix0=0;ix0<imeimusergroup.nodes.size();ix0++) {
		usg = imeimusergroup.nodes[ix0];

		if (usg->ref != 0) {
		};

		if (getIxMsdcVIop(icsMsdcVIop, VecVIme::IMEIAMUSERGROUPACCESS, ixMsdcVIop)) {
			dbsmsdc->tblmsdcamusergroupaccess->loadRefsByUsg(usg->ref, false, refs);
			for (unsigned int i=0;i<refs.size();i++) usg->imeiamusergroupaccess.nodes.push_back(new ImeitemIAMUsergroupAccess(dbsmsdc, refs[i]));
		};

		for (unsigned int ix1=0;ix1<usg->imeiamusergroupaccess.nodes.size();ix1++) {
			usgAacc = usg->imeiamusergroupaccess.nodes[ix1];

			if (usgAacc->ref != 0) {
			};
		};

		if (getIxMsdcVIop(icsMsdcVIop, VecVIme::IMEIMUSER, ixMsdcVIop)) {
			dbsmsdc->tblmsdcmuser->loadRefsByUsg(usg->ref, false, refs);
			for (unsigned int i=0;i<refs.size();i++) usg->imeimuser.nodes.push_back(new ImeitemIMUser(dbsmsdc, refs[i]));
		};

		for (unsigned int ix1=0;ix1<usg->imeimuser.nodes.size();ix1++) {
			usr = usg->imeimuser.nodes[ix1];

			if (usr->ref != 0) {
			};

			if (getIxMsdcVIop(icsMsdcVIop, VecVIme::IMEIAMUSERACCESS, ixMsdcVIop)) {
				dbsmsdc->tblmsdcamuseraccess->loadRefsByUsr(usr->ref, false, refs);
				for (unsigned int i=0;i<refs.size();i++) usr->imeiamuseraccess.nodes.push_back(new ImeitemIAMUserAccess(dbsmsdc, refs[i]));
			};

			for (unsigned int ix2=0;ix2<usr->imeiamuseraccess.nodes.size();ix2++) {
				usrAacc = usr->imeiamuseraccess.nodes[ix2];

				if (usrAacc->ref != 0) {
				};
			};

			if (getIxMsdcVIop(icsMsdcVIop, VecVIme::IMEIJMUSERSTATE, ixMsdcVIop)) {
				dbsmsdc->tblmsdcjmuserstate->loadRefsByUsr(usr->ref, false, refs);
				for (unsigned int i=0;i<refs.size();i++) if (refs[i] == usr->refJState) {refs[i] = refs[0]; refs[0] = usr->refJState; break;};
				for (unsigned int i=0;i<refs.size();i++) usr->imeijmuserstate.nodes.push_back(new ImeitemIJMUserState(dbsmsdc, refs[i]));
			};

			for (unsigned int ix2=0;ix2<usr->imeijmuserstate.nodes.size();ix2++) {
				usrJste = usr->imeijmuserstate.nodes[ix2];

				if (usrJste->ref != 0) {
				};
			};

			for (unsigned int ix2=0;ix2<usr->imeimperson.nodes.size();ix2++) {
				prs = usr->imeimperson.nodes[ix2];

				if (prs->ref != 0) {
				};

				if (getIxMsdcVIop(icsMsdcVIop, VecVIme::IMEIJMPERSONLASTNAME, ixMsdcVIop)) {
					dbsmsdc->tblmsdcjmpersonlastname->loadRefsByPrs(prs->ref, false, refs);
					for (unsigned int i=0;i<refs.size();i++) if (refs[i] == prs->refJLastname) {refs[i] = refs[0]; refs[0] = prs->refJLastname; break;};
					for (unsigned int i=0;i<refs.size();i++) prs->imeijmpersonlastname.nodes.push_back(new ImeitemIJMPersonLastname(dbsmsdc, refs[i]));
				};

				for (unsigned int ix3=0;ix3<prs->imeijmpersonlastname.nodes.size();ix3++) {
					prsJlnm = prs->imeijmpersonlastname.nodes[ix3];

					if (prsJlnm->ref != 0) {
					};
				};
			};
		};
	};
	// IP collect.traverse --- END

	// IP collect.ppr --- INSERT

	delete stcch;
};

bool IexMsdcIni::readTxt(
			Txtrd& txtrd
		) {
	bool parseok = true;

	while (txtrd.readLine()) {
		if (txtrd.comment) {
		} else if (txtrd.header && (txtrd.il == 0)) {
			if (txtrd.ixVToken == VecVIme::IMEIAVCONTROLPAR) {
				parseok = imeiavcontrolpar.readTxt(txtrd); if (!parseok) break;
			} else if (txtrd.ixVToken == VecVIme::IMEIAVKEYLISTKEY) {
				parseok = imeiavkeylistkey.readTxt(txtrd); if (!parseok) break;
			} else if (txtrd.ixVToken == VecVIme::IMEIAVVALUELISTVAL) {
				parseok = imeiavvaluelistval.readTxt(txtrd); if (!parseok) break;
			} else if (txtrd.ixVToken == VecVIme::IMEIMFILE) {
				parseok = imeimfile.readTxt(txtrd); if (!parseok) break;
			} else if (txtrd.ixVToken == VecVIme::IMEIMUSERGROUP) {
				parseok = imeimusergroup.readTxt(txtrd); if (!parseok) break;
			} else {
				parseok = false; break;
			};
		} else {
			parseok = false; break;
		};
	};

	lineno = txtrd.linecnt;

	return parseok;
};

void IexMsdcIni::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	bool basefound;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "IexMsdcIni");

	if (basefound) {
		// look for XML sub-blocks
		imeiavcontrolpar.readXML(docctx, basexpath);
		imeiavkeylistkey.readXML(docctx, basexpath);
		imeiavvaluelistval.readXML(docctx, basexpath);
		imeimfile.readXML(docctx, basexpath);
		imeimusergroup.readXML(docctx, basexpath);
	} else {
		imeiavcontrolpar = ImeIAVControlPar();
		imeiavkeylistkey = ImeIAVKeylistKey();
		imeiavvaluelistval = ImeIAVValuelistVal();
		imeimfile = ImeIMFile();
		imeimusergroup = ImeIMUsergroup();
	};
};

bool IexMsdcIni::readTxtFile(
			const string& fullpath
		) {
	bool retval;

	Txtrd rd(VecVIme::getIx);

	rd.openFile(fullpath);

	retval = readTxt(rd);

	rd.closeFile();

	return retval;
};

bool IexMsdcIni::readXMLFile(
			const string& fullpath
		) {
	xmlDoc* doc = NULL;
	xmlXPathContext* docctx = NULL;

	parseFile(fullpath, &doc, &docctx);
	readXML(docctx, "/");

	closeParsed(doc, docctx);

	return true;
};

void IexMsdcIni::writeTxt(
			fstream& outfile
		) {
	imeiavcontrolpar.writeTxt(outfile);
	imeiavkeylistkey.writeTxt(outfile);
	imeiavvaluelistval.writeTxt(outfile);
	imeimfile.writeTxt(outfile);
	imeimusergroup.writeTxt(outfile);
};

void IexMsdcIni::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "IexMsdcIni");
		imeiavcontrolpar.writeXML(wr, shorttags);
		imeiavkeylistkey.writeXML(wr, shorttags);
		imeiavvaluelistval.writeXML(wr, shorttags);
		imeimfile.writeXML(wr, shorttags);
		imeimusergroup.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

void IexMsdcIni::writeTxtFile(
			const string& fullpath
		) {
	fstream txtfile;

	txtfile.open(fullpath.c_str(), ios::out);

	writeTxt(txtfile);
	
	txtfile.close();
};

void IexMsdcIni::writeXMLFile(
			const string& fullpath
			, const bool shorttags
		) {
	xmlTextWriter* wr = NULL;

	startwriteFile(fullpath, &wr);
		writeXML(wr, shorttags);
	closewriteFile(wr);
};

map<uint,uint> IexMsdcIni::icsMsdcVIopInsAll() {
	return {{(uint)VecVIme::IMEIAVCONTROLPAR,VecMsdcVIop::INS},{(uint)VecVIme::IMEIAVKEYLISTKEY,VecMsdcVIop::INS},{(uint)VecVIme::IMEIAVVALUELISTVAL,VecMsdcVIop::INS},{(uint)VecVIme::IMEIMFILE,VecMsdcVIop::INS},{(uint)VecVIme::IMEIMUSERGROUP,VecMsdcVIop::INS},{(uint)VecVIme::IMEIAMUSERGROUPACCESS,VecMsdcVIop::INS},{(uint)VecVIme::IMEIJAVKEYLISTKEY,VecMsdcVIop::INS},{(uint)VecVIme::IMEIMUSER,VecMsdcVIop::INS},{(uint)VecVIme::IMEIAMUSERACCESS,VecMsdcVIop::INS},{(uint)VecVIme::IMEIJMUSERSTATE,VecMsdcVIop::INS},{(uint)VecVIme::IMEIMPERSON,VecMsdcVIop::INS},{(uint)VecVIme::IMEIJMPERSONLASTNAME,VecMsdcVIop::INS}};
};

uint IexMsdcIni::getIxMsdcVIop(
			const map<uint,uint>& icsMsdcVIop
			, const uint ixVIme
			, uint& ixMsdcVIop
		) {
	ixMsdcVIop = 0;

	auto it = icsMsdcVIop.find(ixVIme);
	if (it != icsMsdcVIop.end()) ixMsdcVIop = it->second;

	return ixMsdcVIop;
};

void IexMsdcIni::handleRequest(
			DbsMsdc* dbsmsdc
			, ReqMsdc* req
		) {
	if (req->ixVBasetype == ReqMsdc::VecVBasetype::CMD) {
		if (req->cmd == "cmdset") {

		} else {
			cout << "\tinvalid command!" << endl;
		};
	};
};

void IexMsdcIni::handleCall(
			DbsMsdc* dbsmsdc
			, Call* call
		) {
};




