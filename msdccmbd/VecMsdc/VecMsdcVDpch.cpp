/**
  * \file VecMsdcVDpch.cpp
  * vector VecMsdcVDpch (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Oct 2018
  * \date modified: 4 Oct 2018
  */

#include "VecMsdcVDpch.h"

/******************************************************************************
 namespace VecMsdcVDpch
 ******************************************************************************/

uint VecMsdcVDpch::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "dpchappdlgmsdcfildownloaddo") return DPCHAPPDLGMSDCFILDOWNLOADDO;
	if (s == "dpchappdlgmsdcnavloainidata") return DPCHAPPDLGMSDCNAVLOAINIDATA;
	if (s == "dpchappdlgmsdcnavloainido") return DPCHAPPDLGMSDCNAVLOAINIDO;
	if (s == "dpchappmsdcalert") return DPCHAPPMSDCALERT;
	if (s == "dpchappmsdcdatapardata") return DPCHAPPMSDCDATAPARDATA;
	if (s == "dpchappmsdcdatapardo") return DPCHAPPMSDCDATAPARDO;
	if (s == "dpchappmsdcdatdetaildata") return DPCHAPPMSDCDATDETAILDATA;
	if (s == "dpchappmsdcdatdetaildo") return DPCHAPPMSDCDATDETAILDO;
	if (s == "dpchappmsdcdatdo") return DPCHAPPMSDCDATDO;
	if (s == "dpchappmsdcdatlistdata") return DPCHAPPMSDCDATLISTDATA;
	if (s == "dpchappmsdcdatlistdo") return DPCHAPPMSDCDATLISTDO;
	if (s == "dpchappmsdcdatrecdo") return DPCHAPPMSDCDATRECDO;
	if (s == "dpchappmsdcdatref1nfiledata") return DPCHAPPMSDCDATREF1NFILEDATA;
	if (s == "dpchappmsdcdatref1nfiledo") return DPCHAPPMSDCDATREF1NFILEDO;
	if (s == "dpchappmsdcfildetaildata") return DPCHAPPMSDCFILDETAILDATA;
	if (s == "dpchappmsdcfildetaildo") return DPCHAPPMSDCFILDETAILDO;
	if (s == "dpchappmsdcfildo") return DPCHAPPMSDCFILDO;
	if (s == "dpchappmsdcfillistdata") return DPCHAPPMSDCFILLISTDATA;
	if (s == "dpchappmsdcfillistdo") return DPCHAPPMSDCFILLISTDO;
	if (s == "dpchappmsdcfilrecdo") return DPCHAPPMSDCFILRECDO;
	if (s == "dpchappmsdcinit") return DPCHAPPMSDCINIT;
	if (s == "dpchappmsdclivaligndata") return DPCHAPPMSDCLIVALIGNDATA;
	if (s == "dpchappmsdclivaligndo") return DPCHAPPMSDCLIVALIGNDO;
	if (s == "dpchappmsdclivdo") return DPCHAPPMSDCLIVDO;
	if (s == "dpchappmsdclivscilldata") return DPCHAPPMSDCLIVSCILLDATA;
	if (s == "dpchappmsdclivscilldo") return DPCHAPPMSDCLIVSCILLDO;
	if (s == "dpchappmsdclivtrackdo") return DPCHAPPMSDCLIVTRACKDO;
	if (s == "dpchappmsdclivvideodata") return DPCHAPPMSDCLIVVIDEODATA;
	if (s == "dpchappmsdclivvideodo") return DPCHAPPMSDCLIVVIDEODO;
	if (s == "dpchappmsdcnavadmindata") return DPCHAPPMSDCNAVADMINDATA;
	if (s == "dpchappmsdcnavadmindo") return DPCHAPPMSDCNAVADMINDO;
	if (s == "dpchappmsdcnavdo") return DPCHAPPMSDCNAVDO;
	if (s == "dpchappmsdcnavoprdata") return DPCHAPPMSDCNAVOPRDATA;
	if (s == "dpchappmsdcnavoprdo") return DPCHAPPMSDCNAVOPRDO;
	if (s == "dpchappmsdcnavpredo") return DPCHAPPMSDCNAVPREDO;
	if (s == "dpchappmsdcprd1ndatadata") return DPCHAPPMSDCPRD1NDATADATA;
	if (s == "dpchappmsdcprd1ndatado") return DPCHAPPMSDCPRD1NDATADO;
	if (s == "dpchappmsdcprddetaildata") return DPCHAPPMSDCPRDDETAILDATA;
	if (s == "dpchappmsdcprddetaildo") return DPCHAPPMSDCPRDDETAILDO;
	if (s == "dpchappmsdcprddo") return DPCHAPPMSDCPRDDO;
	if (s == "dpchappmsdcprdlistdata") return DPCHAPPMSDCPRDLISTDATA;
	if (s == "dpchappmsdcprdlistdo") return DPCHAPPMSDCPRDLISTDO;
	if (s == "dpchappmsdcprdrecdo") return DPCHAPPMSDCPRDRECDO;
	if (s == "dpchappmsdcprsdetaildata") return DPCHAPPMSDCPRSDETAILDATA;
	if (s == "dpchappmsdcprsdetaildo") return DPCHAPPMSDCPRSDETAILDO;
	if (s == "dpchappmsdcprsdo") return DPCHAPPMSDCPRSDO;
	if (s == "dpchappmsdcprslistdata") return DPCHAPPMSDCPRSLISTDATA;
	if (s == "dpchappmsdcprslistdo") return DPCHAPPMSDCPRSLISTDO;
	if (s == "dpchappmsdcprsrecdo") return DPCHAPPMSDCPRSRECDO;
	if (s == "dpchappmsdcresume") return DPCHAPPMSDCRESUME;
	if (s == "dpchappmsdcscfacquisdata") return DPCHAPPMSDCSCFACQUISDATA;
	if (s == "dpchappmsdcscfacquisdo") return DPCHAPPMSDCSCFACQUISDO;
	if (s == "dpchappmsdcscfactudata") return DPCHAPPMSDCSCFACTUDATA;
	if (s == "dpchappmsdcscfactudo") return DPCHAPPMSDCSCFACTUDO;
	if (s == "dpchappmsdcscfdo") return DPCHAPPMSDCSCFDO;
	if (s == "dpchappmsdcscfprcctldo") return DPCHAPPMSDCSCFPRCCTLDO;
	if (s == "dpchappmsdcscfsourcedata") return DPCHAPPMSDCSCFSOURCEDATA;
	if (s == "dpchappmsdcscfsourcedo") return DPCHAPPMSDCSCFSOURCEDO;
	if (s == "dpchappmsdcusgaaccessdata") return DPCHAPPMSDCUSGAACCESSDATA;
	if (s == "dpchappmsdcusgaaccessdo") return DPCHAPPMSDCUSGAACCESSDO;
	if (s == "dpchappmsdcusgdetaildata") return DPCHAPPMSDCUSGDETAILDATA;
	if (s == "dpchappmsdcusgdetaildo") return DPCHAPPMSDCUSGDETAILDO;
	if (s == "dpchappmsdcusgdo") return DPCHAPPMSDCUSGDO;
	if (s == "dpchappmsdcusglistdata") return DPCHAPPMSDCUSGLISTDATA;
	if (s == "dpchappmsdcusglistdo") return DPCHAPPMSDCUSGLISTDO;
	if (s == "dpchappmsdcusgmnuserdata") return DPCHAPPMSDCUSGMNUSERDATA;
	if (s == "dpchappmsdcusgmnuserdo") return DPCHAPPMSDCUSGMNUSERDO;
	if (s == "dpchappmsdcusgrecdo") return DPCHAPPMSDCUSGRECDO;
	if (s == "dpchappmsdcusr1nsessiondata") return DPCHAPPMSDCUSR1NSESSIONDATA;
	if (s == "dpchappmsdcusr1nsessiondo") return DPCHAPPMSDCUSR1NSESSIONDO;
	if (s == "dpchappmsdcusraaccessdata") return DPCHAPPMSDCUSRAACCESSDATA;
	if (s == "dpchappmsdcusraaccessdo") return DPCHAPPMSDCUSRAACCESSDO;
	if (s == "dpchappmsdcusrdetaildata") return DPCHAPPMSDCUSRDETAILDATA;
	if (s == "dpchappmsdcusrdetaildo") return DPCHAPPMSDCUSRDETAILDO;
	if (s == "dpchappmsdcusrdo") return DPCHAPPMSDCUSRDO;
	if (s == "dpchappmsdcusrlistdata") return DPCHAPPMSDCUSRLISTDATA;
	if (s == "dpchappmsdcusrlistdo") return DPCHAPPMSDCUSRLISTDO;
	if (s == "dpchappmsdcusrmnusergroupdata") return DPCHAPPMSDCUSRMNUSERGROUPDATA;
	if (s == "dpchappmsdcusrmnusergroupdo") return DPCHAPPMSDCUSRMNUSERGROUPDO;
	if (s == "dpchappmsdcusrrecdo") return DPCHAPPMSDCUSRRECDO;
	if (s == "dpchapprootmsdclogin") return DPCHAPPROOTMSDCLOGIN;
	if (s == "dpchengdlgmsdcfildownloaddata") return DPCHENGDLGMSDCFILDOWNLOADDATA;
	if (s == "dpchengdlgmsdcnavloainidata") return DPCHENGDLGMSDCNAVLOAINIDATA;
	if (s == "dpchengm2msessmsdcdata") return DPCHENGM2MSESSMSDCDATA;
	if (s == "dpchengmsdcack") return DPCHENGMSDCACK;
	if (s == "dpchengmsdcalert") return DPCHENGMSDCALERT;
	if (s == "dpchengmsdcconfirm") return DPCHENGMSDCCONFIRM;
	if (s == "dpchengmsdcdatapardata") return DPCHENGMSDCDATAPARDATA;
	if (s == "dpchengmsdcdatdata") return DPCHENGMSDCDATDATA;
	if (s == "dpchengmsdcdatdetaildata") return DPCHENGMSDCDATDETAILDATA;
	if (s == "dpchengmsdcdatheadbardata") return DPCHENGMSDCDATHEADBARDATA;
	if (s == "dpchengmsdcdatlistdata") return DPCHENGMSDCDATLISTDATA;
	if (s == "dpchengmsdcdatrecdata") return DPCHENGMSDCDATRECDATA;
	if (s == "dpchengmsdcdatref1nfiledata") return DPCHENGMSDCDATREF1NFILEDATA;
	if (s == "dpchengmsdcfildata") return DPCHENGMSDCFILDATA;
	if (s == "dpchengmsdcfildetaildata") return DPCHENGMSDCFILDETAILDATA;
	if (s == "dpchengmsdcfilheadbardata") return DPCHENGMSDCFILHEADBARDATA;
	if (s == "dpchengmsdcfillistdata") return DPCHENGMSDCFILLISTDATA;
	if (s == "dpchengmsdcfilrecdata") return DPCHENGMSDCFILRECDATA;
	if (s == "dpchengmsdclivaligndata") return DPCHENGMSDCLIVALIGNDATA;
	if (s == "dpchengmsdclivdata") return DPCHENGMSDCLIVDATA;
	if (s == "dpchengmsdclivheadbardata") return DPCHENGMSDCLIVHEADBARDATA;
	if (s == "dpchengmsdclivscilldata") return DPCHENGMSDCLIVSCILLDATA;
	if (s == "dpchengmsdclivtrackdata") return DPCHENGMSDCLIVTRACKDATA;
	if (s == "dpchengmsdclivvideodata") return DPCHENGMSDCLIVVIDEODATA;
	if (s == "dpchengmsdclivvideolive") return DPCHENGMSDCLIVVIDEOLIVE;
	if (s == "dpchengmsdcnavadmindata") return DPCHENGMSDCNAVADMINDATA;
	if (s == "dpchengmsdcnavdata") return DPCHENGMSDCNAVDATA;
	if (s == "dpchengmsdcnavheadbardata") return DPCHENGMSDCNAVHEADBARDATA;
	if (s == "dpchengmsdcnavoprdata") return DPCHENGMSDCNAVOPRDATA;
	if (s == "dpchengmsdcnavpredata") return DPCHENGMSDCNAVPREDATA;
	if (s == "dpchengmsdcprd1ndatadata") return DPCHENGMSDCPRD1NDATADATA;
	if (s == "dpchengmsdcprddata") return DPCHENGMSDCPRDDATA;
	if (s == "dpchengmsdcprddetaildata") return DPCHENGMSDCPRDDETAILDATA;
	if (s == "dpchengmsdcprdheadbardata") return DPCHENGMSDCPRDHEADBARDATA;
	if (s == "dpchengmsdcprdlistdata") return DPCHENGMSDCPRDLISTDATA;
	if (s == "dpchengmsdcprdrecdata") return DPCHENGMSDCPRDRECDATA;
	if (s == "dpchengmsdcprsdata") return DPCHENGMSDCPRSDATA;
	if (s == "dpchengmsdcprsdetaildata") return DPCHENGMSDCPRSDETAILDATA;
	if (s == "dpchengmsdcprsheadbardata") return DPCHENGMSDCPRSHEADBARDATA;
	if (s == "dpchengmsdcprslistdata") return DPCHENGMSDCPRSLISTDATA;
	if (s == "dpchengmsdcprsrecdata") return DPCHENGMSDCPRSRECDATA;
	if (s == "dpchengmsdcscfacquisdata") return DPCHENGMSDCSCFACQUISDATA;
	if (s == "dpchengmsdcscfactudata") return DPCHENGMSDCSCFACTUDATA;
	if (s == "dpchengmsdcscfdata") return DPCHENGMSDCSCFDATA;
	if (s == "dpchengmsdcscfheadbardata") return DPCHENGMSDCSCFHEADBARDATA;
	if (s == "dpchengmsdcscfprcctldata") return DPCHENGMSDCSCFPRCCTLDATA;
	if (s == "dpchengmsdcscfsourcedata") return DPCHENGMSDCSCFSOURCEDATA;
	if (s == "dpchengmsdcsuspend") return DPCHENGMSDCSUSPEND;
	if (s == "dpchengmsdcusgaaccessdata") return DPCHENGMSDCUSGAACCESSDATA;
	if (s == "dpchengmsdcusgdata") return DPCHENGMSDCUSGDATA;
	if (s == "dpchengmsdcusgdetaildata") return DPCHENGMSDCUSGDETAILDATA;
	if (s == "dpchengmsdcusgheadbardata") return DPCHENGMSDCUSGHEADBARDATA;
	if (s == "dpchengmsdcusglistdata") return DPCHENGMSDCUSGLISTDATA;
	if (s == "dpchengmsdcusgmnuserdata") return DPCHENGMSDCUSGMNUSERDATA;
	if (s == "dpchengmsdcusgrecdata") return DPCHENGMSDCUSGRECDATA;
	if (s == "dpchengmsdcusr1nsessiondata") return DPCHENGMSDCUSR1NSESSIONDATA;
	if (s == "dpchengmsdcusraaccessdata") return DPCHENGMSDCUSRAACCESSDATA;
	if (s == "dpchengmsdcusrdata") return DPCHENGMSDCUSRDATA;
	if (s == "dpchengmsdcusrdetaildata") return DPCHENGMSDCUSRDETAILDATA;
	if (s == "dpchengmsdcusrheadbardata") return DPCHENGMSDCUSRHEADBARDATA;
	if (s == "dpchengmsdcusrlistdata") return DPCHENGMSDCUSRLISTDATA;
	if (s == "dpchengmsdcusrmnusergroupdata") return DPCHENGMSDCUSRMNUSERGROUPDATA;
	if (s == "dpchengmsdcusrrecdata") return DPCHENGMSDCUSRRECDATA;
	if (s == "dpchengrootmsdcdata") return DPCHENGROOTMSDCDATA;
	if (s == "dpchengsessmsdcdata") return DPCHENGSESSMSDCDATA;
	if (s == "dpchinvmsdc") return DPCHINVMSDC;
	if (s == "dpchmsdcdack") return DPCHMSDCDACK;
	if (s == "dpchmsdcdquit") return DPCHMSDCDQUIT;
	if (s == "dpchmsdcdreg") return DPCHMSDCDREG;
	if (s == "dpchmsdcopdreg") return DPCHMSDCOPDREG;
	if (s == "dpchmsdcopdunreg") return DPCHMSDCOPDUNREG;
	if (s == "dpchretmsdc") return DPCHRETMSDC;

	return(0);
};

string VecMsdcVDpch::getSref(
			const uint ix
		) {
	if (ix == DPCHAPPDLGMSDCFILDOWNLOADDO) return("DpchAppDlgMsdcFilDownloadDo");
	if (ix == DPCHAPPDLGMSDCNAVLOAINIDATA) return("DpchAppDlgMsdcNavLoainiData");
	if (ix == DPCHAPPDLGMSDCNAVLOAINIDO) return("DpchAppDlgMsdcNavLoainiDo");
	if (ix == DPCHAPPMSDCALERT) return("DpchAppMsdcAlert");
	if (ix == DPCHAPPMSDCDATAPARDATA) return("DpchAppMsdcDatAParData");
	if (ix == DPCHAPPMSDCDATAPARDO) return("DpchAppMsdcDatAParDo");
	if (ix == DPCHAPPMSDCDATDETAILDATA) return("DpchAppMsdcDatDetailData");
	if (ix == DPCHAPPMSDCDATDETAILDO) return("DpchAppMsdcDatDetailDo");
	if (ix == DPCHAPPMSDCDATDO) return("DpchAppMsdcDatDo");
	if (ix == DPCHAPPMSDCDATLISTDATA) return("DpchAppMsdcDatListData");
	if (ix == DPCHAPPMSDCDATLISTDO) return("DpchAppMsdcDatListDo");
	if (ix == DPCHAPPMSDCDATRECDO) return("DpchAppMsdcDatRecDo");
	if (ix == DPCHAPPMSDCDATREF1NFILEDATA) return("DpchAppMsdcDatRef1NFileData");
	if (ix == DPCHAPPMSDCDATREF1NFILEDO) return("DpchAppMsdcDatRef1NFileDo");
	if (ix == DPCHAPPMSDCFILDETAILDATA) return("DpchAppMsdcFilDetailData");
	if (ix == DPCHAPPMSDCFILDETAILDO) return("DpchAppMsdcFilDetailDo");
	if (ix == DPCHAPPMSDCFILDO) return("DpchAppMsdcFilDo");
	if (ix == DPCHAPPMSDCFILLISTDATA) return("DpchAppMsdcFilListData");
	if (ix == DPCHAPPMSDCFILLISTDO) return("DpchAppMsdcFilListDo");
	if (ix == DPCHAPPMSDCFILRECDO) return("DpchAppMsdcFilRecDo");
	if (ix == DPCHAPPMSDCINIT) return("DpchAppMsdcInit");
	if (ix == DPCHAPPMSDCLIVALIGNDATA) return("DpchAppMsdcLivAlignData");
	if (ix == DPCHAPPMSDCLIVALIGNDO) return("DpchAppMsdcLivAlignDo");
	if (ix == DPCHAPPMSDCLIVDO) return("DpchAppMsdcLivDo");
	if (ix == DPCHAPPMSDCLIVSCILLDATA) return("DpchAppMsdcLivScillData");
	if (ix == DPCHAPPMSDCLIVSCILLDO) return("DpchAppMsdcLivScillDo");
	if (ix == DPCHAPPMSDCLIVTRACKDO) return("DpchAppMsdcLivTrackDo");
	if (ix == DPCHAPPMSDCLIVVIDEODATA) return("DpchAppMsdcLivVideoData");
	if (ix == DPCHAPPMSDCLIVVIDEODO) return("DpchAppMsdcLivVideoDo");
	if (ix == DPCHAPPMSDCNAVADMINDATA) return("DpchAppMsdcNavAdminData");
	if (ix == DPCHAPPMSDCNAVADMINDO) return("DpchAppMsdcNavAdminDo");
	if (ix == DPCHAPPMSDCNAVDO) return("DpchAppMsdcNavDo");
	if (ix == DPCHAPPMSDCNAVOPRDATA) return("DpchAppMsdcNavOprData");
	if (ix == DPCHAPPMSDCNAVOPRDO) return("DpchAppMsdcNavOprDo");
	if (ix == DPCHAPPMSDCNAVPREDO) return("DpchAppMsdcNavPreDo");
	if (ix == DPCHAPPMSDCPRD1NDATADATA) return("DpchAppMsdcPrd1NDataData");
	if (ix == DPCHAPPMSDCPRD1NDATADO) return("DpchAppMsdcPrd1NDataDo");
	if (ix == DPCHAPPMSDCPRDDETAILDATA) return("DpchAppMsdcPrdDetailData");
	if (ix == DPCHAPPMSDCPRDDETAILDO) return("DpchAppMsdcPrdDetailDo");
	if (ix == DPCHAPPMSDCPRDDO) return("DpchAppMsdcPrdDo");
	if (ix == DPCHAPPMSDCPRDLISTDATA) return("DpchAppMsdcPrdListData");
	if (ix == DPCHAPPMSDCPRDLISTDO) return("DpchAppMsdcPrdListDo");
	if (ix == DPCHAPPMSDCPRDRECDO) return("DpchAppMsdcPrdRecDo");
	if (ix == DPCHAPPMSDCPRSDETAILDATA) return("DpchAppMsdcPrsDetailData");
	if (ix == DPCHAPPMSDCPRSDETAILDO) return("DpchAppMsdcPrsDetailDo");
	if (ix == DPCHAPPMSDCPRSDO) return("DpchAppMsdcPrsDo");
	if (ix == DPCHAPPMSDCPRSLISTDATA) return("DpchAppMsdcPrsListData");
	if (ix == DPCHAPPMSDCPRSLISTDO) return("DpchAppMsdcPrsListDo");
	if (ix == DPCHAPPMSDCPRSRECDO) return("DpchAppMsdcPrsRecDo");
	if (ix == DPCHAPPMSDCRESUME) return("DpchAppMsdcResume");
	if (ix == DPCHAPPMSDCSCFACQUISDATA) return("DpchAppMsdcScfAcquisData");
	if (ix == DPCHAPPMSDCSCFACQUISDO) return("DpchAppMsdcScfAcquisDo");
	if (ix == DPCHAPPMSDCSCFACTUDATA) return("DpchAppMsdcScfActuData");
	if (ix == DPCHAPPMSDCSCFACTUDO) return("DpchAppMsdcScfActuDo");
	if (ix == DPCHAPPMSDCSCFDO) return("DpchAppMsdcScfDo");
	if (ix == DPCHAPPMSDCSCFPRCCTLDO) return("DpchAppMsdcScfPrcctlDo");
	if (ix == DPCHAPPMSDCSCFSOURCEDATA) return("DpchAppMsdcScfSourceData");
	if (ix == DPCHAPPMSDCSCFSOURCEDO) return("DpchAppMsdcScfSourceDo");
	if (ix == DPCHAPPMSDCUSGAACCESSDATA) return("DpchAppMsdcUsgAAccessData");
	if (ix == DPCHAPPMSDCUSGAACCESSDO) return("DpchAppMsdcUsgAAccessDo");
	if (ix == DPCHAPPMSDCUSGDETAILDATA) return("DpchAppMsdcUsgDetailData");
	if (ix == DPCHAPPMSDCUSGDETAILDO) return("DpchAppMsdcUsgDetailDo");
	if (ix == DPCHAPPMSDCUSGDO) return("DpchAppMsdcUsgDo");
	if (ix == DPCHAPPMSDCUSGLISTDATA) return("DpchAppMsdcUsgListData");
	if (ix == DPCHAPPMSDCUSGLISTDO) return("DpchAppMsdcUsgListDo");
	if (ix == DPCHAPPMSDCUSGMNUSERDATA) return("DpchAppMsdcUsgMNUserData");
	if (ix == DPCHAPPMSDCUSGMNUSERDO) return("DpchAppMsdcUsgMNUserDo");
	if (ix == DPCHAPPMSDCUSGRECDO) return("DpchAppMsdcUsgRecDo");
	if (ix == DPCHAPPMSDCUSR1NSESSIONDATA) return("DpchAppMsdcUsr1NSessionData");
	if (ix == DPCHAPPMSDCUSR1NSESSIONDO) return("DpchAppMsdcUsr1NSessionDo");
	if (ix == DPCHAPPMSDCUSRAACCESSDATA) return("DpchAppMsdcUsrAAccessData");
	if (ix == DPCHAPPMSDCUSRAACCESSDO) return("DpchAppMsdcUsrAAccessDo");
	if (ix == DPCHAPPMSDCUSRDETAILDATA) return("DpchAppMsdcUsrDetailData");
	if (ix == DPCHAPPMSDCUSRDETAILDO) return("DpchAppMsdcUsrDetailDo");
	if (ix == DPCHAPPMSDCUSRDO) return("DpchAppMsdcUsrDo");
	if (ix == DPCHAPPMSDCUSRLISTDATA) return("DpchAppMsdcUsrListData");
	if (ix == DPCHAPPMSDCUSRLISTDO) return("DpchAppMsdcUsrListDo");
	if (ix == DPCHAPPMSDCUSRMNUSERGROUPDATA) return("DpchAppMsdcUsrMNUsergroupData");
	if (ix == DPCHAPPMSDCUSRMNUSERGROUPDO) return("DpchAppMsdcUsrMNUsergroupDo");
	if (ix == DPCHAPPMSDCUSRRECDO) return("DpchAppMsdcUsrRecDo");
	if (ix == DPCHAPPROOTMSDCLOGIN) return("DpchAppRootMsdcLogin");
	if (ix == DPCHENGDLGMSDCFILDOWNLOADDATA) return("DpchEngDlgMsdcFilDownloadData");
	if (ix == DPCHENGDLGMSDCNAVLOAINIDATA) return("DpchEngDlgMsdcNavLoainiData");
	if (ix == DPCHENGM2MSESSMSDCDATA) return("DpchEngM2msessMsdcData");
	if (ix == DPCHENGMSDCACK) return("DpchEngMsdcAck");
	if (ix == DPCHENGMSDCALERT) return("DpchEngMsdcAlert");
	if (ix == DPCHENGMSDCCONFIRM) return("DpchEngMsdcConfirm");
	if (ix == DPCHENGMSDCDATAPARDATA) return("DpchEngMsdcDatAParData");
	if (ix == DPCHENGMSDCDATDATA) return("DpchEngMsdcDatData");
	if (ix == DPCHENGMSDCDATDETAILDATA) return("DpchEngMsdcDatDetailData");
	if (ix == DPCHENGMSDCDATHEADBARDATA) return("DpchEngMsdcDatHeadbarData");
	if (ix == DPCHENGMSDCDATLISTDATA) return("DpchEngMsdcDatListData");
	if (ix == DPCHENGMSDCDATRECDATA) return("DpchEngMsdcDatRecData");
	if (ix == DPCHENGMSDCDATREF1NFILEDATA) return("DpchEngMsdcDatRef1NFileData");
	if (ix == DPCHENGMSDCFILDATA) return("DpchEngMsdcFilData");
	if (ix == DPCHENGMSDCFILDETAILDATA) return("DpchEngMsdcFilDetailData");
	if (ix == DPCHENGMSDCFILHEADBARDATA) return("DpchEngMsdcFilHeadbarData");
	if (ix == DPCHENGMSDCFILLISTDATA) return("DpchEngMsdcFilListData");
	if (ix == DPCHENGMSDCFILRECDATA) return("DpchEngMsdcFilRecData");
	if (ix == DPCHENGMSDCLIVALIGNDATA) return("DpchEngMsdcLivAlignData");
	if (ix == DPCHENGMSDCLIVDATA) return("DpchEngMsdcLivData");
	if (ix == DPCHENGMSDCLIVHEADBARDATA) return("DpchEngMsdcLivHeadbarData");
	if (ix == DPCHENGMSDCLIVSCILLDATA) return("DpchEngMsdcLivScillData");
	if (ix == DPCHENGMSDCLIVTRACKDATA) return("DpchEngMsdcLivTrackData");
	if (ix == DPCHENGMSDCLIVVIDEODATA) return("DpchEngMsdcLivVideoData");
	if (ix == DPCHENGMSDCLIVVIDEOLIVE) return("DpchEngMsdcLivVideoLive");
	if (ix == DPCHENGMSDCNAVADMINDATA) return("DpchEngMsdcNavAdminData");
	if (ix == DPCHENGMSDCNAVDATA) return("DpchEngMsdcNavData");
	if (ix == DPCHENGMSDCNAVHEADBARDATA) return("DpchEngMsdcNavHeadbarData");
	if (ix == DPCHENGMSDCNAVOPRDATA) return("DpchEngMsdcNavOprData");
	if (ix == DPCHENGMSDCNAVPREDATA) return("DpchEngMsdcNavPreData");
	if (ix == DPCHENGMSDCPRD1NDATADATA) return("DpchEngMsdcPrd1NDataData");
	if (ix == DPCHENGMSDCPRDDATA) return("DpchEngMsdcPrdData");
	if (ix == DPCHENGMSDCPRDDETAILDATA) return("DpchEngMsdcPrdDetailData");
	if (ix == DPCHENGMSDCPRDHEADBARDATA) return("DpchEngMsdcPrdHeadbarData");
	if (ix == DPCHENGMSDCPRDLISTDATA) return("DpchEngMsdcPrdListData");
	if (ix == DPCHENGMSDCPRDRECDATA) return("DpchEngMsdcPrdRecData");
	if (ix == DPCHENGMSDCPRSDATA) return("DpchEngMsdcPrsData");
	if (ix == DPCHENGMSDCPRSDETAILDATA) return("DpchEngMsdcPrsDetailData");
	if (ix == DPCHENGMSDCPRSHEADBARDATA) return("DpchEngMsdcPrsHeadbarData");
	if (ix == DPCHENGMSDCPRSLISTDATA) return("DpchEngMsdcPrsListData");
	if (ix == DPCHENGMSDCPRSRECDATA) return("DpchEngMsdcPrsRecData");
	if (ix == DPCHENGMSDCSCFACQUISDATA) return("DpchEngMsdcScfAcquisData");
	if (ix == DPCHENGMSDCSCFACTUDATA) return("DpchEngMsdcScfActuData");
	if (ix == DPCHENGMSDCSCFDATA) return("DpchEngMsdcScfData");
	if (ix == DPCHENGMSDCSCFHEADBARDATA) return("DpchEngMsdcScfHeadbarData");
	if (ix == DPCHENGMSDCSCFPRCCTLDATA) return("DpchEngMsdcScfPrcctlData");
	if (ix == DPCHENGMSDCSCFSOURCEDATA) return("DpchEngMsdcScfSourceData");
	if (ix == DPCHENGMSDCSUSPEND) return("DpchEngMsdcSuspend");
	if (ix == DPCHENGMSDCUSGAACCESSDATA) return("DpchEngMsdcUsgAAccessData");
	if (ix == DPCHENGMSDCUSGDATA) return("DpchEngMsdcUsgData");
	if (ix == DPCHENGMSDCUSGDETAILDATA) return("DpchEngMsdcUsgDetailData");
	if (ix == DPCHENGMSDCUSGHEADBARDATA) return("DpchEngMsdcUsgHeadbarData");
	if (ix == DPCHENGMSDCUSGLISTDATA) return("DpchEngMsdcUsgListData");
	if (ix == DPCHENGMSDCUSGMNUSERDATA) return("DpchEngMsdcUsgMNUserData");
	if (ix == DPCHENGMSDCUSGRECDATA) return("DpchEngMsdcUsgRecData");
	if (ix == DPCHENGMSDCUSR1NSESSIONDATA) return("DpchEngMsdcUsr1NSessionData");
	if (ix == DPCHENGMSDCUSRAACCESSDATA) return("DpchEngMsdcUsrAAccessData");
	if (ix == DPCHENGMSDCUSRDATA) return("DpchEngMsdcUsrData");
	if (ix == DPCHENGMSDCUSRDETAILDATA) return("DpchEngMsdcUsrDetailData");
	if (ix == DPCHENGMSDCUSRHEADBARDATA) return("DpchEngMsdcUsrHeadbarData");
	if (ix == DPCHENGMSDCUSRLISTDATA) return("DpchEngMsdcUsrListData");
	if (ix == DPCHENGMSDCUSRMNUSERGROUPDATA) return("DpchEngMsdcUsrMNUsergroupData");
	if (ix == DPCHENGMSDCUSRRECDATA) return("DpchEngMsdcUsrRecData");
	if (ix == DPCHENGROOTMSDCDATA) return("DpchEngRootMsdcData");
	if (ix == DPCHENGSESSMSDCDATA) return("DpchEngSessMsdcData");
	if (ix == DPCHINVMSDC) return("DpchInvMsdc");
	if (ix == DPCHMSDCDACK) return("DpchMsdcdAck");
	if (ix == DPCHMSDCDQUIT) return("DpchMsdcdQuit");
	if (ix == DPCHMSDCDREG) return("DpchMsdcdReg");
	if (ix == DPCHMSDCOPDREG) return("DpchMsdcopdReg");
	if (ix == DPCHMSDCOPDUNREG) return("DpchMsdcopdUnreg");
	if (ix == DPCHRETMSDC) return("DpchRetMsdc");

	return("");
};

